#!/usr/bin/env python3

import re

def get_instruction(line):
        if '*/' in line:
            crap,goodstuff = line.split('*/')
            return goodstuff.split()[0]
        
def find_highest_compare(switchlines):
    maxcomp = 0
    for i,line in enumerate(switchlines):
        instruction = get_instruction(line)
        if instruction == 'slti':
            #compval is the last segment, do 2: to ditch the 0x
            compval = int(line.split()[-1][2:],16)
            maxcomp = max(maxcomp,compval)
        if instruction == 'beq':
            compvar = line.split()[-2][1:-1]
            prevline = switchlines[i-1]
            match = re.search(f'\s+addiu\s+\${compvar},\s\$zero,\s(.*)\n',prevline)
            if match:
                compval = int(match.group(1)[2:],16)
                maxcomp = max(maxcomp,compval)
    return maxcomp

def run_instruction(line,registers):
    if line[0] == 'addiu' and line[2] == "zero":
        registers[line[1]] = int(line[3][2:],16)
        return
    if line[0] == 'beq':
        if registers[line[1]] == registers[line[2]]:
            return int(line[3][2:],16)
        return
    if line[0] == 'slti':
        compare_reg = line[2]
        compare_val = int(line[3][2:],16)
        if registers[compare_reg] < compare_val:
            registers[line[1]] = 1
        else:
            registers[line[1]] = 0
        return
    if line[0] == 'beqz':
        if registers[line[1]] == 0:
            return int(line[2][2:],16)
        return
    if line[0] == 'bnez':
        if registers[line[1]] != 0:
            return int(line[2][2:],16)
        return
    if line[0] == 'bnel' and line[2] == "zero":
        if registers[line[1]] != 0:
            return int(line[3][2:],16)
        return -1
    if line[0] == 'j':
        return int(line[1][2:],16)
    #Nop of course does nothing
    if line[0] == 'nop':
        return
    #I haven't seen sll contribute to switch logic so we will assume it's in a delay slot and irrelevant
    if line[0] == 'sll':
        return
    #Same with addu
    if line[0] == 'addu':
        return
    print("Unknown line")
    print(line)
    exit()
def run_switch(switchval,switchlines):
    #take all the lines and build a dictionary so we can get any line from the program counter
    instructions = {}
    for line in switchlines:
        line = line.replace("$",'').replace(',','')
        if len(line) > 15:
            instructions[int(line.split()[2],16)] = line.split()[5:]
    registers = {switchvar:switchval}
    program_counter = min(instructions.keys())
    while(True):
        instruction = instructions[program_counter]
        new_pc = run_instruction(instruction,registers)
        if new_pc == None:
            program_counter += 4
        elif new_pc == -1: #likely branch
            program_counter += 8
        else:
            #Do the delay slot first
            instruction = instructions[program_counter+4]
            #delay slot should never have a destination
            better_be_none = run_instruction(instruction,registers)
            assert(better_be_none == None)
            program_counter = new_pc
            if program_counter > max(instructions.keys()):
                final_destination = program_counter - func_start
                if final_destination != default_address:
                    print(f"{hex(switchval)};{hex(final_destination)};{final_destination}")
                return

with open('nonmatchings/src/code0/41940/func_800539A8.s') as f:
    switchlines = f.readlines()

#The register which holds the value we're switching on
switchvar = 'a0'

#The register we compare against
compvar = 'v0'

#The starting address of the function (makes for easier switch labels)
#Can set to zero if you just want to see raw addresses
func_start = 0x800539A8
#Whatever is the default, could be after the switch. Set to 0 if unknown.
default_address = 0

highest_compare = find_highest_compare(switchlines)

# Run through all the values, with 5 more on top for good measure
for i in range(highest_compare+5):
    run_switch(i,switchlines)

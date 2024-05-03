#!/usr/bin/env python3

from multiprocessing import Pool
from functools import partial
import tqdm
import re

def get_instruction(line):
        if '*/' in line:
            crap,goodstuff = line.split('*/')
            return goodstuff.split()[0]
        
#TODO: This Could miss some cases due to delay slot not being handled
def find_highest_compare(switchlines, compvar):
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
                continue

            match = re.search(f'\s+ori\s+\${compvar},\s\${compvar},\s(.*)\n',prevline)
            if match:
                assert('& 0xFFFF' in match.group(1))
                compval = int(match.group(1).split('&')[0].split('(')[1],16)
                maxcomp = max(maxcomp,compval)
                continue

    return maxcomp

def run_instruction(line,registers):
    if line[0] == 'lui':
        assert(line[3] == '>>')
        assert(line[4] == '16)')
        registers[line[1]] = int(line[2][1:],16)
        return
    if line[0] == 'ori':
        assert(line[4] == '&')
        assert(line[5] == '0xFFFF)')
        assert(line[1] == line[2])
        assert((registers[line[1]] >> 16) == (int(line[3][1:],16) >> 16)) #From previous lui
        registers[line[1]] = int(line[3][1:],16)
        return
    if line[0] == 'sltu':
        compare_reg = line[2]
        compare_reg2 = line[3]
        if registers[compare_reg] < registers[compare_reg2]:
            registers[line[1]] = 1
        else:
            registers[line[1]] = 0
        return
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
    if line[0] == 'sll' or line[0] == 'sra':
        return
    #Same with addu
    if line[0] == 'addu':
        return
    #Same with sw/lw
    if line[0] == 'sw' or line[0] == 'lw':
        return
    print("Unknown line")
    print(line)
    exit()

def run_switch(switchval,instructions,switchvar,func_start,default_address):
    registers = {switchvar:switchval}
    program_counter = min(instructions.keys())
    max_pc = max(instructions.keys())
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
            if program_counter > max_pc:
                final_destination = program_counter - func_start
                if final_destination != default_address:
                    return switchval, final_destination
                return None

if __name__ == '__main__':
    with open('target.s') as f:
        switchlines = f.readlines()

    #The register which holds the value we're switching on
    switchvar = 's0'

    #The register we compare against
    compvar = 'v0'

    #The starting address of the function (makes for easier switch labels)
    #Can set to zero if you just want to see raw addresses
    func_start = 0x8006C948
    #Whatever is the default, could be after the switch. Set to 0 if unknown.
    default_address = 2256

    highest_compare = find_highest_compare(switchlines, compvar)

    #take all the lines and build a dictionary so we can get any line from the program counter
    instructions = {}
    for line in switchlines:
        line = line.replace("$",'').replace(',','')
        if len(line) > 15:
            instructions[int(line.split()[2],16)] = line.split()[5:]
    
    # Run through all the values, with 5 more on top for good measure
    analyse = []
    with Pool() as pool:
        for l in tqdm.tqdm(pool.imap_unordered(partial(run_switch, instructions=instructions, \
                                                         switchvar=switchvar, \
                                                         func_start=func_start, \
                                                         default_address=default_address), \
                                     range(highest_compare+5), chunksize=200), total=highest_compare+5):
            if l:
                analyse.append(l)

    analyse.sort(key = lambda x: x[1])
    f = open('analysis.csv', 'w')
    for l in analyse:
        f.write(f"{hex(l[0])};{hex(l[1])};{l[1]}\n")
    f.close()
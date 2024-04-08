#!/usr/bin/env python3

import os
import sys
import operator
import subprocess
from splat.scripts import split
from dataclasses import dataclass

@dataclass
class Instruction():
    opcode: int
    inst: str
    regs: list
    desc: str
    rlabel: str
    rtype: str
    label: str

@dataclass
class Symbol():
    splat: split.symbols.Symbol
    ignore: bool
    visibility: str
    source: str
    section: str

def parse_objdump_output(text):
    lines = text.splitlines()
    inst = []
    symtab = {}
    symtab['.text'] = {}
    symtab['.data'] = {}
    symtab['.rodata'] = {}
    symtab['.bss'] = {}
    for i in range(0,65536):
        inst.append(Instruction(opcode=None, inst=None, regs=None, desc=None, rlabel=None, rtype=None, label=None))
    sym = False
    disas = False
    max = 0
    for line in lines:
        if 'SYMBOL TABLE:' in line:
            sym = True
            disas = False
            continue
        if 'Disassembly of section .text:' in line:
            disas = True
            sym = False
            continue
        
        #TODO stop if other sections after

        if line != '' and sym:
            # Symbol table
            l = line.split()
            assert(len(l) >= 4)
            if l[3] == '.text' or l[3] == '.data' or l[3] == '.rodata' or l[3] == '.bss':
                assert(len(l) == 6)
                size = int(l[4], 16)
                if size == 0: continue
                offset = int(l[0], 16)
                assert(symtab[l[3]].get(offset) == None)
                symtab[l[3]][offset] = (l[5], size)

        elif line != '' and disas:
            # Disassembly of text section
            if '>:' in line:
                l = line.split()
                i = int(int(l[0], 16) / 4)
                assert(i < 65536)
                if i > max: max = i
                label = l[1].split('<')[1].split('>')[0]
                inst[i].label = label
            else:
                l = line.split()
                i = int(int(l[0].split(':')[0], 16) / 4)
                assert(i < 65536)
                if i > max: max = i
                if l[1].startswith('R_MIPS'):
                    assert(len(l) == 3)
                    inst[i].rtype = l[1]
                    inst[i].rlabel = l[2]
                else:
                    inst[i].opcode = int(l[1], 16)
                    inst[i].inst = l[2]
                    inst[i].desc = ' '.join(l[2:])
                    if len(l) >= 4:
                        inst[i].regs = l[3].split(',')
    return inst[0:max+1], symtab

def parse_symbols_from_config(file: str) -> None:
    global name_max_size

    f = open(file, 'r')
    lines = f.readlines()
    f.close()

    symbols = {}

    for line in lines:
        s = line.split('=')
        if 'ignore:true' in line:
            name = s[0].strip()
            addr = int(s[1].strip().split(';')[0], 16)
            size = 0
            if 'size:' in line:
                size = int(s[1].strip().split('size:')[1].split()[0], 16)
            if len(name) > name_max_size: name_max_size = len(name)
            splat=split.symbols.Symbol(given_name=name, given_size=size, vram_start=addr)
            symbols[name] = Symbol(splat=splat, visibility=None, section=None, source=None, ignore=True)
        else:
            addr = int(s[1].strip().split(';')[0], 16)
            splat = split.symbols.all_symbols_dict[addr][0]
            if not 'size:' in s[1]:
                splat.given_size = 0
            visibility = None
            section = None
            source = None
            if '(' in line:
                info = s[1].split('(')[1].split(')')[0].split(',')
                visibility = info[0].strip()
                section = info[1].strip()
                source = info[2].strip()
            if len(splat.given_name) > name_max_size: name_max_size = len(splat.given_name)
            symbols[splat.given_name] = Symbol(splat=splat, visibility=visibility, section=section, source=source, ignore=False)
    
    return symbols

if __name__ == "__main__":
    VERSION = 'fr'
    name_max_size = 0
    source_file=sys.argv[1]

    # Get list of symbols from config file
    yaml = 'versions/'+VERSION+'/dukenukemzerohour.yaml'
    symbol_addrs = 'versions/'+VERSION+'/symbol_addrs.txt'
    with open(yaml) as f:
        config = split.yaml.load(f.read(), Loader=split.yaml.SafeLoader)
    config['options']['base_path'] = '.'
    split.options.initialize(config, yaml, None, None)
    all_segments = split.initialize_segments(config["segments"])
    split.disassembler_instance.create_disassembler_instance(skip_version_check=True, splat_version='')
    split.symbols.initialize(all_segments)

    symbols = parse_symbols_from_config(symbol_addrs)

    # Build and disassemble source file
    name1 = 'build/'+VERSION+'/'+source_file+'.o'
    name2 = 'build/'+VERSION+'/asm/'+VERSION+'/'+source_file.replace('.c','.s')+'.o'

    try:
        os.remove(name1)
        os.remove(name2)
    except OSError:
        pass

    subprocess.run(['make', 'VERBOSE=1', 'VERSION='+VERSION, name1])
    subprocess.run(['make', 'VERBOSE=1', 'VERSION='+VERSION, 'AS=mips-linux-gnu-as', name2])

    #TODO: dump .data/.rodata/.bss sections, diff them?
    o1 = subprocess.check_output(['mips-linux-gnu-objdump', '-m', 'mips:4300' ,'-drzt', name1], encoding="utf-8")
    o2 = subprocess.check_output(['mips-linux-gnu-objdump', '-m', 'mips:4300' ,'-drzt', name2], encoding="utf-8")

    with open('a.txt', 'w') as f:
        f.write(o1)

    with open('b.txt', 'w') as f:
        f.write(o2)

    l1, symtab1 = parse_objdump_output(o1)
    l2, symtab2 = parse_objdump_output(o2)
    assert(len(l1) == len(l2))

    hi = -1
    for i in range(0, len(l1)):
        assert(l1[i].inst == l2[i].inst)

        # Functions
        if l1[i].label != None:
            assert(l2[i].label)
            assert(l1[i].label[0] != '.')
            if l1[i].label != l2[i].label:
                assert(l2[i].label.startswith('func_'))
                addr = int(l2[i].label.split('_')[1], 16)
                d = symbols.get(l1[i].label)
                if d != None:
                    assert(d.splat.vram_start == addr)
                else:
                    if len(l1[i].label) > name_max_size: name_max_size = len(l1[i].label)
                    splat = split.symbols.Symbol(given_name=l1[i].label, given_size=0, vram_start=addr, type='func')
                    symbols[l1[i].label] = Symbol(splat=splat, visibility=None, section=None, source=None, ignore=False)
            else:
                assert(symbols.get(l1[i].label))
        
        if l2[i].label and l2[i].label[0] != '.': assert(l1[i].label)

        # Relocations
        if l1[i].rtype != None:
            # Missing reloc in asm
            if(l1[i].rtype != l2[i].rtype):
                assert(l2[i].rtype == None)
                #TODO
                continue

            if l1[i].rtype == 'R_MIPS_26' and l1[i].inst != 'jal':
                continue

            # Already defined
            if l1[i].rlabel == l2[i].rlabel:
                assert(symbols.get(l1[i].rlabel))
                continue

            # mips-as should not emit those
            assert(l2[i].rlabel != '.text' and l2[i].rlabel != '.data' and l2[i].rlabel != '.rodata' and l2[i].rlabel != '.bss')
            
            d = symbols.get(l2[i].rlabel)
            if d:
                addr = d.splat.vram_start
            elif (l2[i].rlabel.startswith('func_') or l2[i].rlabel.startswith('D_')) and len(l2[i].rlabel.split('_')) == 3:
                # Format $VRAM_$ROM
                addr = int(l2[i].rlabel.split('_')[1], 16)
            elif l2[i].rlabel.startswith('jtbl_'):
                continue
            else:
                print('Label mismatch ' + l1[i].rlabel + ' <-> ' + l2[i].rlabel + ' at ' + hex(i*4))
                continue

            if l1[i].rtype == 'R_MIPS_26':
                assert(l1[i].inst == 'jal')
                assert(l1[i].rlabel != '.data' and l1[i].rlabel != '.rodata' and l1[i].rlabel != '.bss')
                if l1[i].rlabel == '.text':
                    # Get symbol name from symtab
                    assert(int(l2[i].desc.split()[1],16) == 0)
                    l = l1[i].desc.split()
                    name1 = l[2].split('<')[1].split('>')[0]
                    d = symtab1['.text'].get(int(l[1],16))
                    assert(d)
                    name2, size = d
                    assert(name1 == name2)
                    l1[i].rlabel = name2
                    
                d = symbols.get(l1[i].rlabel)
                if d != None:
                    assert(d.splat.vram_start == addr)
                else:
                    if len(l1[i].rlabel) > name_max_size: name_max_size = len(l1[i].rlabel)
                    splat = split.symbols.Symbol(given_name=l1[i].rlabel, given_size=0, vram_start=addr, type='func')
                    symbols[l1[i].rlabel] = Symbol(splat=splat, visibility=None, section=None, source=None, ignore=False)
            elif l1[i].rtype == 'R_MIPS_HI16':
                hi = i
            elif l1[i].rtype == 'R_MIPS_LO16':
                if(hi < 0):
                    print('multiple R_MIPS_LO16 for the same R_MIPS_HI16 at ' + hex(i*4) + '?')
                    continue

                assert(l1[hi].inst == 'lui')
                assert(l1[hi].rtype == 'R_MIPS_HI16')
                assert(l2[hi].rlabel == l2[i].rlabel)
                assert(l1[i].inst == 'addiu' or '(' in l1[i].regs[1])

                if l1[i].rlabel == '.text' or l1[i].rlabel == '.data' or l1[i].rlabel == '.rodata' or l1[i].rlabel == '.bss':
                    addr = addr+(int(l2[hi].regs[1], 16) << 16)
                    offset = (int(l1[hi].regs[1], 16) << 16)
                    if l1[i].inst == 'addiu':
                        addr = addr+int(l2[i].regs[2])
                        offset = offset+int(l1[i].regs[2])
                    else:
                        addr = addr+int(l2[i].regs[1].split('(')[0])
                        offset = offset+int(l1[i].regs[1].split('(')[0])

                    d = symtab1[l1[i].rlabel].get(offset)
                    if d == None:
                        hi = -1
                        continue
                    name, size = d
                    l1[i].rlabel = name
                else:
                    if(l1[hi].opcode != l2[hi].opcode):
                        addr = addr-(int(l1[hi].regs[1], 16) << 16)
                        addr = addr+(int(l2[hi].regs[1], 16) << 16)

                    if (l1[i].opcode != l2[i].opcode):
                        if l1[i].inst == 'addiu':
                            addr = addr+int(l2[i].regs[2])
                            addr = addr-int(l1[i].regs[2])
                        else:
                            addr = addr+int(l2[i].regs[1].split('(')[0])
                            addr = addr-int(l1[i].regs[1].split('(')[0])

                if '.' in l1[i].rlabel:
                    print('Skipping name' + name + ' at ' + hex(i*4))
                else:
                    d = symbols.get(l1[i].rlabel)
                    if d != None:
                        assert(d.splat.vram_start == addr)
                    else:
                        if len(l1[i].rlabel) > name_max_size: name_max_size = len(l1[i].rlabel)
                        splat = split.symbols.Symbol(given_name=l1[i].rlabel, given_size=0, vram_start=addr)
                        symbols[l1[i].rlabel] = Symbol(splat=splat, visibility=None, section=None, source=None, ignore=False)
                hi = -1
        else:
            assert(l1[i].rlabel == None)

    sorted_symbols = sorted(symbols.values(), key=operator.attrgetter('splat.vram_start'))

    # Write symbols to files
    f = open(symbol_addrs+'.new', 'w')
    try:
        for i in range(0, len(sorted_symbols)):
            line = (f'{sorted_symbols[i].splat.name:<{name_max_size}}')
            line += f' = 0x{sorted_symbols[i].splat.vram_start:08X};'
            
            if sorted_symbols[i].splat.name.endswith('_START') or \
               sorted_symbols[i].splat.name.endswith('_END') or \
               sorted_symbols[i].splat.name.endswith('_VRAM') or \
               sorted_symbols[i].splat.name.endswith('TextEnd') or \
               sorted_symbols[i].splat.name.endswith('DataEnd'):
                print('Skipped label ' + line)
                continue

            if sorted_symbols[i].ignore:
                line += (' //')
                line += (f"{' ignore:true':<14}")
                if sorted_symbols[i].splat.size > 0:
                    size = f' size:0x{sorted_symbols[i].splat.size:X}'
                    line += (f"{size:<14}")
            elif (sorted_symbols[i].splat.type != None) or \
                 (sorted_symbols[i].splat.size != 0) or \
                 (sorted_symbols[i].splat.dont_allow_addend != False) or \
                 (sorted_symbols[i].splat.force_not_migration != False) or \
                 (sorted_symbols[i].splat.force_migration != False) or \
                 (sorted_symbols[i].source != None):
                line += (' //')
                if sorted_symbols[i].splat.type != None:
                    type = ' type:' + sorted_symbols[i].splat.type
                    line += (f"{type:<14}")
                else:
                    line += (f"{'':<14}")
                if sorted_symbols[i].splat.size > 0:
                    size = f' size:0x{sorted_symbols[i].splat.size:X}'
                    line += (f"{size:<14}")
                else:
                    line += (f"{'':<14}")
                if sorted_symbols[i].splat.dont_allow_addend == True:
                    line += (f"{' dont_allow_addend:true':<25}")
                elif sorted_symbols[i].splat.force_not_migration == True:
                    line += (f"{' force_not_migration:true':<25}")
                elif sorted_symbols[i].splat.force_migration == True:
                    line += (f"{' force_migration:true':<25}")
                else:
                    line += (f"{'':<25}")
                if sorted_symbols[i].source != None and sorted_symbols[i].section != None:
                    if sorted_symbols[i].visibility != None:
                        visibility = sorted_symbols[i].visibility + ', '
                    else:
                        visibility = 'global, '
                    section = sorted_symbols[i].section + ', '
                    line += ' (' + f"{visibility:<8}"
                    line += f"{section:<9}"
                    line += sorted_symbols[i].source + ')'

            f.write(line.strip())
            f.write('\n')
        f.close()
        os.remove(symbol_addrs)
        os.rename(symbol_addrs+'.new', symbol_addrs)
    except:
        f.close()
        os.remove(symbol_addrs+'.new')

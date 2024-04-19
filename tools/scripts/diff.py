#!/usr/bin/env python3

import os
import re
import sys
import shutil
import operator
import subprocess
from splat.scripts import split
from dataclasses import dataclass

@dataclass
class Instruction():
    data: int
    inst: str
    regs: list
    desc: str
    rlabel: str
    rtype: str
    rsize: int
    label: str
    lsize: int

@dataclass
class Symbol():
    splat: split.symbols.Symbol
    ignore: bool
    visibility: str
    source: str
    section: str

def parse_objdump_output(text):
    lines = text.splitlines()
    sections = ['.text', '.data', '.rodata', '.bss', '*COM*']
    
    inst = []
    relocs = {}
    symtab = {}
    symsize = {}
    for section in sections:
        symtab[section] = {}

    assert(lines[-1] != '')
    l = lines[-1].split()
    if ':' in l[0]:
        max = int((int(l[0].split(':')[0], 16)+4) / 4)
    else:
        m = re.findall('[0-9A-Fa-f]{8}', lines[-1])
        max = int(l[0], 16) + 4*len(m)

    for i in range(0, max):
        inst.append(Instruction(data=None, inst=None, regs=None, desc=None, rlabel=None, rtype=None, rsize=0, label=None, lsize=0))

    sym = False
    disas = False
    content = False
    reloc = False
    section = None

    for line in lines:
        if 'SYMBOL TABLE:' in line:
            sym = True
            disas = False
            content = False
            reloc = False
            continue
        if 'RELOCATION RECORDS' in line:
            sym = False
            disas = False
            content = False
            reloc = True
            continue
        if 'Disassembly of section .text' in line:
            disas = True
            sym = False
            content = False
            reloc = False
            section = '.text'
            continue
        if 'Contents of section' in line:
            disas = False
            sym = False
            content = True
            reloc = False
            section = line.split()[-1].split(':')[0]
            continue
        if line.startswith('OFFSET'):
            continue

        # Symbol table
        if line != '' and sym:
            l = line.split()
            if l[-3] in sections:
                if l[-3] == '*COM*':
                    size = int(l[0], 16)
                else:
                    size = int(l[-2], 16)
                    if '.' in l[-1]: continue
                    offset = int(l[0], 16)
                    assert(symtab[l[-3]].get(offset) == None)
                    symtab[l[-3]][offset] = (l[-1], size)
                    
                symsize[l[-1]] = size

        # Relocations
        if line != '' and reloc:
            l = line.split()
            assert(int(l[0], 16) % 4 == 0)
            relocs[int(l[0], 16)] = l[1],l[2]

        # Section content
        elif line != '' and content:
            l = re.findall('[0-9A-Fa-f]{8}', line)
            i = int(line.split()[0], 16)
            for j in range(0, len(l)):
                assert(len(l[j]) == 8)
                val = int(l[j], 16)
                for k in range(0,4):
                    off = (k^3)*8
                    inst[i+k].data = (val >> off) & 0xFF
                    s = symtab[section].get(i+k)
                    if s:
                        inst[i+k].label = s[0]
                        inst[i+k].lsize = s[1]
                    r = relocs.get(i)
                    if r:
                        inst[i+k].rtype = r[0]
                        inst[i+k].rlabel = r[1]
                i=i+4

        # Disassembly
        elif line != '' and disas:
            if '>:' in line:
                l = line.split()
                i = int(int(l[0], 16) / 4)
                assert(i < 65536)
                label = l[1].split('<')[1].split('>')[0]
                inst[i].label = label
                s = symsize.get(label)
                if s:
                    inst[i].lsize = s
                assert(label not in sections)
            else:
                l = line.split()
                i = int(int(l[0].split(':')[0], 16) / 4)
                assert(i < 65536)
                if l[1].startswith('R_MIPS'):
                    assert(len(l) == 3)
                    inst[i].rtype = l[1]
                    inst[i].rlabel = l[2]
                    s = symsize.get(l[2])
                    if s:
                        inst[i].rsize = s
                else:
                    inst[i].data = int(l[1], 16)
                    inst[i].inst = l[2]
                    inst[i].desc = ' '.join(l[2:])
                    if len(l) >= 4:
                        inst[i].regs = l[3].split(',')

    return inst, symtab

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

def objdump(file, section):
    file = 'build/'+VERSION+'/'+file+'.o'
    try:
        os.remove(file)
    except OSError:
        pass
    if section == '.text':
        cmd = ['mips-linux-gnu-objdump', '-m', 'mips:4300', '-drzt']
    else:
        cmd = ['mips-linux-gnu-objdump', '-m', 'mips:4300', '-srzt', '--section='+section]
    subprocess.run(['make', 'VERBOSE=1', 'VERSION='+VERSION, 'AS=mips-linux-gnu-as', file])
    o1 = subprocess.check_output(cmd+[src], encoding="utf-8")
    o2 = subprocess.check_output(cmd+[file], encoding="utf-8")
    with open('objdump/c/'+section+'.txt', 'w') as f:
        f.write(o1)
    with open('objdump/s/'+section+'.txt', 'w') as f:
        f.write(o2)
    
    return o1,o2

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

    asm = 'asm/'+VERSION+'/'+source_file.split('.')[0] + '.s'
    data = 'asm/'+VERSION+'/data/'+source_file.split('.')[0] + '.data.s'
    rodata = 'asm/'+VERSION+'/data/'+source_file.split('.')[0] + '.rodata.s'

    # Build and disassemble source file
    src = 'build/'+VERSION+'/'+source_file+'.o'
    try:
        os.remove(src)
    except OSError:
        pass

    if os.path.exists('objdump'):
        shutil.rmtree('objdump')
    os.makedirs('objdump/c/', exist_ok=True)
    os.makedirs('objdump/s/', exist_ok=True)

    subprocess.run(['make', 'VERBOSE=1', 'VERSION='+VERSION, 'AS=mips-linux-gnu-as', src])

    sections = []
    if os.path.exists(asm):
        sections.append((asm,'.text'))
    if os.path.exists(data):
        sections.append((data,'.data'))
    if os.path.exists(rodata):
        sections.append((rodata,'.rodata'))

    hi = -1
    match = True
    for section in sections:
        file, sec = section
        o1,o2 = objdump(file, sec)
        l1, symtab1 = parse_objdump_output(o1)
        l2, symtab2 = parse_objdump_output(o2)

        if(len(l1) != len(l2)):
            print('\033[91m'+'Section size mismatch ' + sec + '\033[0m')
            match = False

        i = 0
        for ll in l1:
            if i >= len(l2):
                break

            if l1[i].label == 'gcc2_compiled.':
                i += 1
                continue

            if sec == '.text' and l1[i].inst != l2[i].inst:
                print('\033[91m'+'Diff at ' + hex(i*4) + ' in .text ' + l1[i].desc + ' vs ' + l2[i].desc + '\033[0m')
                match = False
                break

            # Labels
            if l1[i].label != None and l1[i].label not in sections and l2[i].label != None:
                assert(l1[i].label[0] != '.')
                if l1[i].label != l2[i].label:
                    if l2[i].label.startswith('jtbl_'):
                        i += 1
                        continue
                    assert(l2[i].label.startswith('func_') or l2[i].label.startswith('D_'))
                    if len(l2[i].label.split('_')) != 3:
                        print('Label mismatch ' + l1[i].label + ' <-> ' + l2[i].label + ' at ' + hex(i*4) + ' ' + sec)
                        i += 1
                        continue
                    addr = int(l2[i].label.split('_')[1], 16)
                    d = symbols.get(l1[i].label)
                    if d != None:
                        assert(d.splat.vram_start == addr)
                    else:
                        if len(l1[i].label) > name_max_size: name_max_size = len(l1[i].label)
                        if l2[i].label.startswith('func_'):
                            splat = split.symbols.Symbol(given_name=l1[i].label, given_size=l1[i].lsize, vram_start=addr, type='func')
                        else:
                            splat = split.symbols.Symbol(given_name=l1[i].label, given_size=l1[i].lsize, vram_start=addr)
                        symbols[l1[i].label] = Symbol(splat=splat, visibility=None, section=None, source=None, ignore=False)
                else:
                    # Update size
                    s = symbols.get(l1[i].label)
                    assert(s)
                    if s.splat.given_size == 0:
                        s.splat.given_size = l1[i].lsize

            # Relocations
            if l1[i].rtype != None:
                # Missing reloc in asm
                if(l1[i].rtype != l2[i].rtype):
                    assert(l2[i].rtype == None)
                    i += 1
                    continue

                if l1[i].rtype == 'R_MIPS_26' and l1[i].inst != 'jal':
                    i += 1
                    continue

                # Already defined
                if l1[i].rlabel == l2[i].rlabel:
                    s = symbols.get(l1[i].rlabel)
                    assert(s)
                    if s.splat.given_size == 0:
                        s.splat.given_size = l1[i].rsize
                    i += 1
                    continue

                # mips-as should not emit those
                assert(l2[i].rlabel != '.text' and l2[i].rlabel != '.data' and l2[i].rlabel != '.rodata' and l2[i].rlabel != '.bss')
                
                d = symbols.get(l2[i].rlabel)
                if d:
                    addr = d.splat.vram_start
                elif (l2[i].rlabel.startswith('func_') or l2[i].rlabel.startswith('D_')) and len(l2[i].rlabel.split('_')) == 3:
                    # Format $VRAM_$ROM
                    addr = int(l2[i].rlabel.split('_')[1], 16)
                elif l2[i].rlabel.startswith('jtbl_') or l2[i].rlabel.startswith('.'):
                    i += 1
                    continue
                else:
                    print('Label mismatch ' + l1[i].rlabel + ' <-> ' + l2[i].rlabel + ' at ' + hex(i*4) + ' ' + sec)
                    i += 1
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
                        l1[i].rlabel, l1[i].rsize = d
                        assert(name1 == l1[i].rlabel)
                        
                    d = symbols.get(l1[i].rlabel)
                    if d != None:
                        assert(d.splat.vram_start == addr)
                    else:
                        if len(l1[i].rlabel) > name_max_size: name_max_size = len(l1[i].rlabel)
                        splat = split.symbols.Symbol(given_name=l1[i].rlabel, given_size=l1[i].rsize, vram_start=addr, type='func')
                        symbols[l1[i].rlabel] = Symbol(splat=splat, visibility=None, section=None, source=None, ignore=False)
                elif l1[i].rtype == 'R_MIPS_HI16':
                    hi = i
                elif l1[i].rtype == 'R_MIPS_LO16':
                    if(hi < 0):
                        print('multiple R_MIPS_LO16 for the same R_MIPS_HI16 at ' + hex(i*4) + '?')
                        i += 1
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
                            i += 1
                            continue
                        l1[i].rlabel, l1[i].rsize = d
                    else:
                        if(l1[hi].data != l2[hi].data):
                            addr = addr-(int(l1[hi].regs[1], 16) << 16)
                            addr = addr+(int(l2[hi].regs[1], 16) << 16)

                        if (l1[i].data != l2[i].data):
                            if l1[i].inst == 'addiu':
                                addr = addr+int(l2[i].regs[2])
                                addr = addr-int(l1[i].regs[2])
                            else:
                                addr = addr+int(l2[i].regs[1].split('(')[0])
                                addr = addr-int(l1[i].regs[1].split('(')[0])

                    if '.' in l1[i].rlabel:
                        print('Skipping name' + l1[i].rlabel + ' at ' + hex(i*4) + ' ' + sec)
                    else:
                        d = symbols.get(l1[i].rlabel)
                        if d != None:
                            assert(d.splat.vram_start == addr)
                        else:
                            if len(l1[i].rlabel) > name_max_size: name_max_size = len(l1[i].rlabel)
                            splat = split.symbols.Symbol(given_name=l1[i].rlabel, given_size=l1[i].rsize, vram_start=addr)
                            symbols[l1[i].rlabel] = Symbol(splat=splat, visibility=None, section=None, source=None, ignore=False)
                    hi = -1
                elif l1[i].rtype == 'R_MIPS_32':
                    value1 = l1[i].data << 24 | l1[i+1].data << 16 | l1[i+2].data << 8 | l1[i+3].data
                    value2 = l2[i].data << 24 | l2[i+1].data << 16 | l2[i+2].data << 8 | l2[i+3].data

                    if(value2 != 0):
                        #TODO?
                        i += 4
                        continue

                    if l1[i].rlabel == '.text' or l1[i].rlabel == '.data' or l1[i].rlabel == '.rodata' or l1[i].rlabel == '.bss':
                        i += 4
                        #TODO get offset from 32bits data
                        continue
                    
                    addr = addr - value1
                    d = symbols.get(l1[i].rlabel)
                    if d != None:
                        assert(d.splat.vram_start == addr)
                    else:
                        if len(l1[i].rlabel) > name_max_size: name_max_size = len(l1[i].rlabel)
                        if l2[i].rlabel.startswith('func_'):
                            splat = split.symbols.Symbol(given_name=l1[i].rlabel, given_size=l1[i].rsize, vram_start=addr, type='func')
                        else:
                            splat = split.symbols.Symbol(given_name=l1[i].rlabel, given_size=l1[i].rsize, vram_start=addr)
                        symbols[l1[i].rlabel] = Symbol(splat=splat, visibility=None, section=None, source=None, ignore=False)
                    i += 4
                    continue
            else:
                # If no reloc, make sure data matches
                if l2[i].rtype == None:
                    if(l1[i].data != l2[i].data):
                        if sec == '.text':
                            print('\033[91m''Diff at ' + hex(i*4) + ' in .text ' + l1[i].desc + ' vs ' + l2[i].desc + '\033[0m')
                        else:
                            print('\033[91m''Diff at ' + hex(i) + ' in ' + sec + ' ' + hex(l1[i].data) + ' vs ' + hex(l2[i].data) + '\033[0m')
                        match  = False
                        break
                assert(l1[i].rlabel == None)
            i += 1

    if not match: sys.exit()
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

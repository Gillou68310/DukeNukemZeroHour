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
    for i in range(0,65536):
        inst.append(Instruction(opcode=None, inst=None, regs=None, desc=None, rlabel=None, rtype=None, label=None))
    first = True
    max = 0
    for line in lines:
        if '>:' in line:
            l = line.split()
            i = int(int(l[0], 16) / 4)
            assert(i < 65536)
            if i > max: max = i
            label = l[1].split('<')[1].split('>')[0]
            inst[i].label = label
            first = False
            continue
        if line != '' and not first:
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
    return inst[0:max+1]

def parse_symbols_from_config(file: str, symbols) -> None:
    global name_max_size

    f = open(file, 'r')
    lines = f.readlines()
    f.close()

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

if __name__ == "__main__":
    name_max_size = 0
    VERSION = 'fr'
    source_file=sys.argv[1]

    # Get list of symbols from config file
    yaml = 'versions/'+VERSION+'/dukenukemzerohour.yaml'
    symbol_addrs = 'versions/'+VERSION+'/symbol_addrs.txt'
    static_offsets = 'versions/'+VERSION+'/static_offsets.txt'
    with open(yaml) as f:
        config = split.yaml.load(f.read(), Loader=split.yaml.SafeLoader)
    config['options']['base_path'] = '.'
    split.options.initialize(config, yaml, None, None)
    all_segments = split.initialize_segments(config["segments"])
    split.symbols.initialize(all_segments)

    symbols = {}
    parse_symbols_from_config(symbol_addrs, symbols)
    parse_symbols_from_config(static_offsets, symbols)

    # Build and disassemble source file
    name1 = 'build/'+VERSION+'/'+source_file+'.o'
    name2 = 'build/'+VERSION+'/asm/'+VERSION+'/'+source_file.replace('.c','.s')+'.o'

    try:
        os.remove(name1)
        os.remove(name2)
    except OSError:
        pass

    subprocess.run(['make', 'VERBOSE=1', 'VERSION=fr', name1])
    subprocess.run(['make', 'VERBOSE=1', 'VERSION=fr', 'AS=mips-linux-gnu-as', name2])
    o1 = subprocess.check_output(['mips-linux-gnu-objdump', '-m', 'mips:4300' ,'-drz', name1], encoding="utf-8")
    o2 = subprocess.check_output(['mips-linux-gnu-objdump', '-m', 'mips:4300' ,'-drz', name2], encoding="utf-8")

    with open('a.txt', 'w') as f:
        f.write(o1)

    with open('b.txt', 'w') as f:
        f.write(o2)

    l1 = parse_objdump_output(o1)
    l2 = parse_objdump_output(o2)
    assert(len(l1) == len(l2))

    hi = 0
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

            # Static symbols
            if l1[i].rlabel == '.text' or l1[i].rlabel == '.data' or l1[i].rlabel == '.bss' or l1[i].rlabel == '.rodata':
                #TODO
                continue

            # Already defined
            if l1[i].rlabel == l2[i].rlabel:
                assert(symbols.get(l1[i].rlabel))
                continue
            
            # Linker addr (same addr != labels)
            if not l2[i].rlabel.startswith('func_') and not l2[i].rlabel.startswith('D_'):
                print('Label mismatch ' + l1[i].rlabel + ' - ' + l2[i].rlabel + ' at ' + hex(i*4))
                continue

            addr = int(l2[i].rlabel.split('_')[1], 16)

            if l1[i].rtype == 'R_MIPS_26':
                assert(l1[i].inst == 'jal')
                if(l1[i].opcode == l2[i].opcode):
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
                assert(hi != 0)
                assert(l1[hi].rtype == 'R_MIPS_HI16')
                assert(l2[hi].rlabel == l2[i].rlabel)
                assert(l1[i].inst == 'addiu' or '(' in l1[i].regs[1])

                if(l1[hi].opcode != l2[hi].opcode):
                    assert(l1[hi].inst == 'lui')
                    assert(int(l2[hi].regs[1], 16) == 0)
                    addr = addr-(int(l1[hi].regs[1], 16) << 16)

                if (l1[i].opcode != l2[i].opcode):
                    if l1[i].inst == 'addiu':
                        assert(int(l2[i].regs[2]) == 0) #TODO
                        addr = addr-int(l1[i].regs[2])
                    else:
                        assert(int(l2[i].regs[1].split('(')[0]) == 0) #TODO
                        addr = addr-int(l1[i].regs[1].split('(')[0])

                d = symbols.get(l1[i].rlabel)
                if d != None:
                    assert(d.splat.vram_start == addr)
                else:
                    if len(l1[i].rlabel) > name_max_size: name_max_size = len(l1[i].rlabel)
                    splat = split.symbols.Symbol(given_name=l1[i].rlabel, given_size=0, vram_start=addr)
                    symbols[l1[i].rlabel] = Symbol(splat=splat, visibility=None, section=None, source=None, ignore=False)
                hi = 0
        else:
            assert(l1[i].rlabel == None)

    sorted_symbols = sorted(symbols.values(), key=operator.attrgetter('splat.vram_start'))

    # Write symbols to files
    f = open(symbol_addrs+'.new', 'w')
    f1 = open(static_offsets+'.new', 'w')
    try:
        for i in range(0, len(sorted_symbols)):
            line = (f'{sorted_symbols[i].splat.name:<{name_max_size}}')
            line += f' = 0x{sorted_symbols[i].splat.vram_start:08X};'

            if sorted_symbols[i].splat.name.endswith('_STATIC_START'):
                f1.write(line.strip())
                f1.write('\n')
                continue
            
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
        f1.close()
        os.remove(symbol_addrs)
        os.rename(symbol_addrs+'.new', symbol_addrs)
        os.remove(static_offsets)
        os.rename(static_offsets+'.new', static_offsets)
    except:
        f.close()
        os.remove(symbol_addrs+'.new')
        os.remove(static_offsets+'.new')
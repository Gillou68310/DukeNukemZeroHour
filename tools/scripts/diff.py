from dataclasses import dataclass

@dataclass
class Instruction():
    opcode: int
    inst: str
    desc: str
    rlabel: str
    rtype: str

@dataclass
class Symbol():
    addr: int
    type: str

def parse_objdump_output(path):
    f = open(path, 'r')
    lines = f.readlines()
    f.close()

    inst = []
    for i in range(0,65536):
        inst.append(Instruction(opcode=None, inst=None, desc=None, rlabel=None, rtype=None))
    first = True
    max = 0
    for line in lines:
        if '>:' in line:
            l = line.split()
            i = int(int(l[0], 16) / 4)
            assert(i < 65536)
            if i > max: max = i
            label = l[1].split('<')[1].split('>')[0]
            inst[i].rlabel = label
            inst[i].rtype = 'LABEL'
            first = False
            continue
        if line != '\n' and not first:
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
    return inst[0:max+1]

#TODO
#rm -f build/fr/asm/fr/src/code0/main.s.*
#rm -f build/fr/src/code0/main.c.*
#
#make VERBOSE=1 VERSION=fr AS=mips-linux-gnu-as build/fr/asm/fr/src/code0/main.s.o
#make VERBOSE=1 VERSION=fr build/fr/src/code0/main.c.o
#
#mips-linux-gnu-objdump -m mips:4300 -drz build/fr/src/code0/main.c.o > a.txt
#mips-linux-gnu-objdump -m mips:4300 -drz build/fr/asm/fr/src/code0/main.s.o > b.txt

#TODO: static vars/funcs?

#TODO: parse symbol_addrs.txt first and merge new symbols

l1 = parse_objdump_output('a.txt')
l2 = parse_objdump_output('b.txt')
assert(len(l1) == len(l2))

dico = {}
hi = 0
for i in range(0, len(l1)):
    assert(l1[i].inst == l2[i].inst)

    if l1[i].rtype != None:
        if(l1[i].rtype != l2[i].rtype):
            continue

        if l1[i].rlabel == '.text' or l1[i].rlabel == '.data' or l1[i].rlabel == '.bss' or l1[i].rlabel == '.rodata':
            continue

        if l1[i].rlabel == l2[i].rlabel:
            continue
        
        assert(l2[i].rlabel.startswith('func_') or l2[i].rlabel.startswith('D_'))
        addr = int(l2[i].rlabel.split('_')[1], 16)
        
        if l1[i].rtype == 'LABEL':
            assert(l1[i].opcode == l2[i].opcode)
            d = dico.get(l1[i].rlabel)
            if d != None:
                assert(d.addr == addr)
            else:
                dico[l1[i].rlabel] = Symbol(addr=addr, type='func')
        elif l1[i].rtype == 'R_MIPS_26':
            assert(l1[i].inst == 'jal')
            if(l1[i].opcode == l2[i].opcode):
                d = dico.get(l1[i].rlabel)
                if d != None:
                    assert(d.addr == addr)
                else:
                    dico[l1[i].rlabel] = Symbol(addr=addr, type='func')
        elif l1[i].rtype == 'R_MIPS_HI16':
            hi = i
        elif l1[i].rtype == 'R_MIPS_LO16':
            assert(hi != 0)
            assert(l1[hi].rtype == 'R_MIPS_HI16')
            assert(l2[hi].rlabel == l2[i].rlabel)
            if(l1[hi].opcode == l2[hi].opcode) and (l1[i].opcode == l2[i].opcode):
                d = dico.get(l1[i].rlabel)
                if d != None:
                    assert(d.addr == addr)
                else:
                    dico[l1[i].rlabel] = Symbol(addr=addr, type='data')
            hi = 0
    else:
        assert(l1[i].rlabel == None)
        if(l2[i].rlabel != None and l2[i].rlabel[0] != '.'):
            print('Incorrect label ' + l2[i].rlabel)

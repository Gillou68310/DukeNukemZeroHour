#!/usr/bin/env python3

from dataclasses import dataclass
import operator
import shutil
import glob
import os

@dataclass
class Function():
    name: str
    size: int
    addr: int

def get_size(path):
    f = open(path, 'r')
    lines = f.readlines()
    f.close()
    name = os.path.basename(file).split('.')[0]
    inst = 0
    for line in lines:
        if ('glabel ' + name) in line:
            inst = 0
        if line.startswith('/*'):
            inst += 1
    return inst

def parse_symbol_addrs(file):
    f = open(file, 'r')
    lines = f.readlines()
    f.close() 

    symbols = {}
    for line in lines:
        s = line.split('=')
        if len(s) == 2:
            name = s[0].strip()
            addr = int(s[1].strip().split(';')[0], 16)
            symbols[name] = addr

    return symbols

dirs = glob.glob("nonmatchings/src/code0/*")
dirs += glob.glob("nonmatchings/src/code1/*")

shutil.rmtree('stats', ignore_errors=True)
os.mkdir('stats')
os.mkdir('stats/code0')
os.mkdir('stats/code1')

symbols = parse_symbol_addrs('symbol_addrs.txt')

all_func = []
for dir in dirs:
    func = []
    asm_files = [y for x in os.walk(dir) for y in glob.glob(os.path.join(x[0], '*.s'))]
    for file in asm_files:
        name = os.path.basename(file).split('.')[0]
        if name.startswith('D_'):
            continue
        addr = symbols.get(name)
        assert(addr != None)
        func.append(Function(name, get_size(file), addr))

    all_func += func
    sorted_size = sorted(all_func, key=operator.attrgetter('size'))

    parent1 = os.path.split(dir)
    parent2 = os.path.split(parent1[0])
    path = os.path.join('stats', parent2[1], parent1[1]) + '.csv'

    f = open(path, 'w')
    for fu in sorted_size:
        f.write(fu.name+';'+str(fu.size)+'\n')
    f.close()

sorted_size = sorted(all_func, key=operator.attrgetter('size'))
f = open(os.path.join('stats', 'size.csv'), 'w')
for fu in sorted_size:
    f.write(fu.name+';'+str(fu.size)+'\n')
f.close()

sorted_size = sorted(all_func, key=operator.attrgetter('addr'))
f = open(os.path.join('stats', 'list.csv'), 'w')
for fu in sorted_size:
    f.write(fu.name+';'+str(fu.size)+'\n')
f.close()
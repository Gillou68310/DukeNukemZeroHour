#!/usr/bin/env python3

from dataclasses import dataclass
import shutil
import glob
import os

@dataclass
class Function():
    name: str
    size: int

    def __lt__(self, other):
        return self.size < other.size

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

dirs = glob.glob("nonmatchings/src/code0/*")
dirs += glob.glob("nonmatchings/src/code1/*")
dirs += glob.glob("nonmatchings/gen/code0/*")

shutil.rmtree('stats', ignore_errors=True)
os.mkdir('stats')
os.mkdir('stats/code0')
os.mkdir('stats/code1')

all_func = []
for dir in dirs:
    func = []
    asm_files = [y for x in os.walk(dir) for y in glob.glob(os.path.join(x[0], '*.s'))]
    for file in asm_files:
        name = os.path.basename(file).split('.')[0]
        if name.startswith('D_'):
            continue
        func.append(Function(name, get_size(file)))

    all_func += func
    func.sort()

    parent1 = os.path.split(dir)
    parent2 = os.path.split(parent1[0])
    path = os.path.join('stats', parent2[1], parent1[1]) + '.csv'

    f = open(path, 'w')
    for fu in func:
        f.write(fu.name+';'+str(fu.size)+'\n')
    f.close()

all_func.sort()
f = open(os.path.join('stats', 'all.csv'), 'w')
for fu in all_func:
    f.write(fu.name+';'+str(fu.size)+'\n')
f.close()
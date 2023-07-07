#!/usr/bin/env python3

from dataclasses import dataclass
import operator
import shutil
import glob
import os
import upload

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

def parse_source_file(file):
    f = open(file, 'r')
    lines = f.readlines()
    f.close() 

    s = set()
    for i in range(0, len(lines)):
        if '#ifdef NON_MATCHING' in lines[i]:
            # Look for symbol addrs
            addr = 0
            elmts = lines[i+1].split('/*')
            for elmt in elmts:
                try:
                    addr = int(elmt.split('*/')[0], 16)
                except:
                    continue

            if addr < 0x01000000:
                continue

            s.add(addr)
    return s

def write_output_file(path, funcs, scratches):
    f = open(path, 'w')
    for fu in funcs:
        s = scratches.get(fu.name)
        if s == None:
           s = scratches.get(f"func_{fu.addr:08X}")

        if fu.addr in non_matching:
            f.write('non_matching')
        f.write(';'+fu.name+';'+str(fu.size))
        if s != None:
            percent = 100.0 - ((s['score'] * 100) / s['max_score'])
            f.write(f";{percent:.1f}")
            f.write(f";https://decomp.me/scratch/{s['slug']}")
        else:
            f.write(';0.0;') 
        f.write('\n')
    f.close()

if __name__ == "__main__":
    dirs = glob.glob("nonmatchings/src/code0/*")
    dirs += glob.glob("nonmatchings/src/code1/*")

    shutil.rmtree('stats', ignore_errors=True)
    os.mkdir('stats')
    os.mkdir('stats/code0')
    os.mkdir('stats/code1')

    symbols = parse_symbol_addrs('symbol_addrs.txt')

    #Get NON_MATCHING funcs
    c_files = [y for x in os.walk('src') for y in glob.glob(os.path.join(x[0], '*.c'))]
    non_matching = set()
    for file in c_files:
        non_matching.update(parse_source_file(file))

    scrathes = {}
    if os.path.exists('sessionid'):
        f = open('sessionid', 'r')
        lines = f.readlines()
        f.close()
        assert(len(lines) == 1)
        scrathes = upload.get_scratches_decompme(lines[0])

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
        sorted_size = sorted(func, key=operator.attrgetter('size'))

        parent1 = os.path.split(dir)
        parent2 = os.path.split(parent1[0])
        path = os.path.join('stats', parent2[1], parent1[1]) + '.csv'

        write_output_file(path, sorted_size, scrathes)

    sorted_size = sorted(all_func, key=operator.attrgetter('size'))
    path = os.path.join('stats', 'size.csv')
    write_output_file(path, sorted_size, scrathes)

    sorted_addr = sorted(all_func, key=operator.attrgetter('addr'))
    path = os.path.join('stats', 'list.csv')
    write_output_file(path, sorted_addr, scrathes)
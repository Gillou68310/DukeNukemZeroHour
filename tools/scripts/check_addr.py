#!/usr/bin/env python3
import subprocess
import argparse

#TODO: rename to compare_data_obj
#build both src and data file and compare data offset and size
class SYMBOL:
    def __init__(self, name: str = None, addr: int = 0, size: int = 0):
         self.name: str = name
         self.addr: int = addr
         self.size: int = size

def parse_object_file(file: str) -> list:
    symbols = []
    result = subprocess.run(['mips-linux-gnu-nm', '--defined-only', '--print-size', file], \
                            capture_output=True, text=True)
    syms = result.stdout.split('\n')
    for sym in syms:
        sp = sym.split()
        if len(sp) == 0:
            continue
        elif len(sp) > 3:
            addr = int(sp[0], 16)
            size = int(sp[1], 16)
            type = sp[2]
            name = sp[3]

        if type == 'd' or type == 'D':
            sym = SYMBOL(name=name, addr=addr, size=size)
            symbols.append(sym)

    return symbols

parser = argparse.ArgumentParser()
parser.add_argument('file_path', help='object file', nargs='?', default=None)
args = parser.parse_args()

symbols = parse_object_file(args.file_path)

if symbols[0].addr == 0 and symbols[0].name.startswith('D_'):
    base_addr = int(symbols[0].name[2:], 16)
    for sym in symbols:
        if sym.name.startswith('D_'):
            addr = int(sym.name[2:], 16)
            diff = addr - base_addr
            if sym.addr != diff:
                print(sym.name + ' at ' + hex(sym.addr) + ' instead of ' + hex(diff))
                break
else:
    print('Error: Cannot determine base adresse')
#!/usr/bin/env python3

class SYMBOL:
    def __init__(self, addr: int = 0, type: str = None, size: int = 0, string: str = None,):
         self.addr: int = addr
         self.size: int = size
         self.type: str = type
         self.string: str = string

def parse_symbols_from_config(file: str) -> None:
    f = open(file, 'r')
    lines = f.readlines()
    f.close()

    symbols = []

    for line in lines:
        s = line.split('\t')
        addr = int(s[0].strip(), 16)
        size = int(s[1].strip(), 16)
        type = s[2].strip()
        string = s[3].strip()
            
        sym = SYMBOL(addr=addr, type=type, size=size, string=string)
        symbols.append(sym)

    return symbols

symbols = parse_symbols_from_config('text.txt')

f = open('out.txt', 'r')
text = f.read()
f.close()

for sym in symbols:
    new = '\"' + sym.string + '\"'

    old = '&D_' + f'{sym.addr:08X}'
    text = text.replace(old, new)

    old = '&D_' + f'{sym.addr:X}'
    text = text.replace(old, new)

    old = '0x' + f'{sym.addr:08X}'
    text = text.replace(old, new)

    old = '0x' + f'{sym.addr:X}'
    text = text.replace(old, new)

f = open('new_out.txt', 'w')
f.write(text)
f.close()
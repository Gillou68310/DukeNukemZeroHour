#!/usr/bin/env python3

import re

with open('baserom.us.z64', 'rb') as f:
    data = f.read()

sounds_addr = []
curpos = 0
pattern = re.compile(br'N64 WaveTables|N64 PtrTablesV2')

while(True):
    m = pattern.search(data[curpos:])  
    if m is None: break
    sounds_addr.append(curpos + m.start())
    curpos += m.end()

sounds_addr.sort()

for addr in sounds_addr:
    a = f'{addr:0X}'
    if data[addr:addr+5] == b'N64 W':
        print('- [0x' + a + ', bin,        sounds/' + a + '.wbk]')
    else:
        print('- [0x' + a + ', bin,        sounds/' + a + '.ptr]')
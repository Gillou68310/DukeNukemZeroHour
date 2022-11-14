#!/usr/bin/env python3

import re

with open('baserom.us.z64', 'rb') as f:
    data = f.read()

sounds_addr = []
curpos = 0
pattern = re.compile(br'EDL')

while(True):
    m = pattern.search(data[curpos:])  
    if m is None: break
    sounds_addr.append(curpos + m.start())
    curpos += m.end()

sounds_addr.sort()

f = open('files.txt', 'w')
for addr in sounds_addr:
    a = f'{addr:0X}'
    f.write('- [0x' + a + ', bin,        files/' + a + '.edl]\n')
f.close()
#!/usr/bin/env python3

f = open('src/static/tileinfo.c', 'r')
lines = f.readlines()
f.close()

f = open('tileinfo.c', 'w')
for line in lines:
    if '{' in line and '}' in line:
        elmt = line.split('{')[1].split('}')[0].split(',')
        offset = int(elmt[0].strip(), 16)
        id = int(elmt[9].strip(), 16)

        addr = '(s32)tile_' + str(id) + '_START,'

        f.write('{' + f"{addr:<21}" + elmt[1] + ', 0x' + f"{int(elmt[2],16):08X}" + ', 0x' + f"{int(elmt[3],16):04X}" + \
                ', 0x' + f"{int(elmt[4],16):04X}" + ', 0x' + f"{int(elmt[5],16):04X}" + ', 0x' + f"{int(elmt[6],16):04X}" + \
                ', 0x' + f"{int(elmt[7],16):04X}" + ', 0x' + f"{int(elmt[8],16):02X}" + ', ' + f"{str(id):<4}" + '},\n')
    else:
        f.write(line)
f.close()

f = open('tileinfo.ld', 'w')
for line in lines:
    if '{' in line and '}' in line:
        elmt = line.split('{')[1].split('}')[0].split(',')
        id = int(elmt[9].strip(), 16)
        f.write('tile_' + str(id) + '_START = tiles_tile_' + str(id) + '_ROM_START - tiles_tile_0_ROM_START;\n')
f.close()

f = open('tileinfo.h', 'w')
for line in lines:
    if '{' in line and '}' in line:
        elmt = line.split('{')[1].split('}')[0].split(',')
        id = int(elmt[9].strip(), 16)
        f.write('extern u8 tile_' + str(id) + '_START[];\n')
f.close()
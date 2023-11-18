#!/usr/bin/env python3

from n64img.image import CI4
import shutil
import struct
import tqdm
import edl
import os

import sys
sys.path.insert(1, 'tools/splat')
import split

def get_segment(segname, segments):
    for segment in segments:
        if segment.name == segname:
            return segment
        
def get_symbols_from_subsegment(subsegname, type, segment):
    symbols = []
    for subsegment in segment.subsegments:
        t = subsegment.type
        if t[0] == '.':
            t = t[1:]

        if subsegname in subsegment.name and t == type:
            for syms in split.symbols.all_symbols:
                if syms.vram_start >= subsegment.vram_start and \
                   syms.vram_end <= subsegment.vram_end and syms.given_size:
                    syms.rom = subsegment.rom_start + \
                               (syms.vram_start - subsegment.vram_start)
                    symbols.append(syms)
            break
    return symbols

class TileInfo:
    def __init__(self, data, num):
        self.num = num
        self.fileoff, self.ramaddr, self.picanm, self.sizex, \
        self.sizey, self.filesize, self.dimx, self.dimy, \
        self.flags, self.tileid \
            = struct.unpack('>iIihhHHHBxHxx', data)

class ModelInfo:
    def __init__(self, data, vram):
        self.vram = vram
        self.fileoff, self.ramaddr, self.unk8, self.unkA, \
        self.tileinfo, self.unkE, self.unk10, self.unk12, \
        self.unk18, self.lock, self.unk24, self.unk26, \
        self.unk28, self.unk2A, self.unk2C, self.unk2E, \
            = struct.unpack('>iiHHHHHHxxxxIxxxxbxxxhhhhhh', data)
    
class ModelTileInfo:
    def __init__(self, data):
        self.dimx, self.dimy, self.offset = struct.unpack('>hhi', data)

def extract_models(rom):
    # Get models list
    segment = get_segment('code0', all_segments)
    symbols = get_symbols_from_subsegment('modelinfo', 'data', segment)

    models = []
    for symbol in symbols:
        if symbol.vram_start < 0x800D52E0 and symbol.size == 0x30:
            models.append(ModelInfo(rom[symbol.rom:symbol.rom_end], \
                                    symbol.vram_start))
    
    # Get models data
    model_segment = get_segment('files/models', all_segments)
    models_data = rom[model_segment.rom_start:model_segment.rom_end]

    # Create models folder
    models_dir = os.path.join('extracted', 'models')
    os.mkdir(models_dir)

    # Extract models
    bar = tqdm.tqdm(models, total=len(models))
    for model in bar:
        bar.set_description("Extracting models")
        if model.unk18 == 0:
            assert(model.fileoff == 0)
            continue

        # Create model folder
        model_dir = os.path.join('extracted', 'models', f'obj_{model.vram:08X}')
        os.mkdir(model_dir)
        model_data = models_data[model.fileoff:] #TODO: size?

        # Get model tiles list
        tiles = []
        tiles_table = model_data[model.tileinfo:model.unkE]
        for i in range(0, len(tiles_table), 8):
            tiles.append(ModelTileInfo(tiles_table[i:i+8]))
        
        # Extract model tiles
        i = 0
        for i in range(len(tiles)):
            if i < len(tiles)-1:
                tile_data = model_data[tiles[i].offset:tiles[i+1].offset]
            else:
                tile_data = model_data[tiles[i].offset:model.tileinfo]

            if(len(tile_data) == int(((tiles[i].dimx * tiles[i].dimy) / 2) + 32)):
                # CI4
                path = os.path.join(model_dir, f'{i:d}.{tiles[i].dimx:d}x{tiles[i].dimy:d}.ci4.png')
                img = CI4(tile_data[32:], tiles[i].dimx, tiles[i].dimy)
                #TODO: if (pal[i] == 0xF83F) pal[i] = 0x8420?
                img.set_palette(tile_data[0:32], 'big')
                img.write(path)
            else:
                # CI4 tiles with non matching size
                path = os.path.join(model_dir, f'{i:d}.{tiles[i].dimx:d}x{tiles[i].dimy:d}.ci4.bin')
                f = open(path, 'wb')
                f.write(tile_data)
                f.close()

        #TODO: Extract vtx

def extract_tiles(rom):
    # Get tiles list
    segment = get_segment('static', all_segments)
    symbols = get_symbols_from_subsegment('tileinfo', 'data', segment)
    assert(symbols[0].name == 'gTileInfo')

    tiles = []
    tiles_table = rom[symbols[0].rom:symbols[0].rom_end]
    j = 0
    for i in range(0, len(tiles_table), 0x1C):
        tiles.append(TileInfo(tiles_table[i:i+0x1C],j))
        j += 1

    # Get tiles data
    tile_segment = get_segment('files/tiles', all_segments)
    tiles_data = rom[tile_segment.rom_start:tile_segment.rom_end]

    # Create tiles folder
    tiles_dir = os.path.join('extracted', 'tiles')
    os.mkdir(tiles_dir)

    # Extract tiles
    bar = tqdm.tqdm(tiles, total=len(tiles))

    _edl = edl.EDL()
    for tile in bar:
        bar.set_description("Extracting tiles")
        d = _edl.decompress_libEDL(tiles_data[tile.fileoff:tile.fileoff+tile.filesize])
        d1 = _edl.decompress_pyEDL(tiles_data[tile.fileoff:tile.fileoff+tile.filesize])

        if d != d1:
            print("EDL decompress mismatch for tileid: " + str(tile.tileid) + " tilenum: " +  str(tile.num) + " offset: " +  str(tile.fileoff))

        if len(d) == 32:
            # CI4 Palettes
            assert(tile.filesize==32)
            assert(tile.flags==0)

            # TODO: Swap?
            palette = bytearray(32)
            palette[0::2] = d[1::2]
            palette[1::2] = d[0::2]

            path = os.path.join(tiles_dir, f'{tile.tileid:04d}.pal.ci4')
            f = open(path, 'wb')
            f.write(palette)
            f.close()
        elif tile.flags & 0x80 or ((tile.dimx * tile.dimy) == len(d)):
            # CI8 tiles with external palette
            assert(((tile.dimx * tile.dimy) == len(d)))
            path = os.path.join(tiles_dir, f'{tile.tileid:04d}.{tile.dimx:d}x{tile.dimy:d}.ci8.bin')
            f = open(path, 'wb')
            f.write(d)
            f.close()
        elif ((tile.dimx * tile.dimy) == (len(d)-32)):
            # CI4 tiles with missing half height?
            path = os.path.join(tiles_dir, f'{tile.tileid:04d}.{tile.dimx:d}x{tile.dimy:d}.ci4.png')
            img = CI4(d[32:], tile.dimx, tile.dimy*2)
            img.set_palette(d[0:32], 'little')
            img.write(path)
        elif (((tile.dimx * tile.dimy) / 2) == (len(d)-32)):
            # CI4 tiles
            path = os.path.join(tiles_dir, f'{tile.tileid:04d}.{tile.dimx:d}x{tile.dimy:d}.ci4.png')
            img = CI4(d[32:], tile.dimx, tile.dimy)
            img.set_palette(d[0:32], 'little')
            img.write(path)
        elif((tile.dimx * tile.dimy) / 2) > (len(d)-32):
            # CI4 tiles with non matching size
            assert(tile.flags==0)
            data = d[0:32]
            palette = bytearray(32)
            palette[0::2] = data[1::2]
            palette[1::2] = data[0::2]
            path = os.path.join(tiles_dir, f'{tile.tileid:04d}.{tile.dimx:d}x{tile.dimy:d}.ci4.bin')
            f = open(path, 'wb')
            f.write(palette)
            f.write(d[32:])
            f.close()
        else:
            assert(0)

if __name__ == '__main__':
    with open('dukenukemzerohour.yaml') as f:
        config = split.yaml.load(f.read(), Loader=split.yaml.SafeLoader)
    split.options.initialize(config, 'dukenukemzerohour.yaml', None, None)
    all_segments = split.initialize_segments(config["segments"])
    split.symbols.initialize(all_segments)

    f = open('baserom.us.z64', 'rb')
    rom_data = f.read()
    f.close()

    shutil.rmtree('extracted', ignore_errors=True)
    os.mkdir('extracted')

    extract_tiles(rom_data)
    extract_models(rom_data)

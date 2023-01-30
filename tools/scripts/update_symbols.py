#!/usr/bin/env python3
from pycparser import c_parser, c_ast
import subprocess
import argparse
import glob
import sys
import os
import m2ctx
import sys
sys.path.insert(1, 'tools/splat')
import split

class SYMBOL:
    def __init__(self, splat: split.symbols.Symbol = None, ignore: bool = False, \
                 visibility: str = None, source: str = None, section: str = None):
         self.splat: split.symbols.Symbol = splat
         self.ignore: bool = ignore
         self.visibility: str = visibility
         self.source: str = source
         self.section: str = section
    def __lt__(self, other):
         return self.splat.vram_start < other.splat.vram_start

class SYMBOLS:
    def __init__(self):
        self.addrs = {}
        self.names = {}
        self.symbols: list[SYMBOL] = []
        self.name_max_size = 0
    
    def add(self, symbol: SYMBOL, verbose: bool) -> None:
        # Already existing name
        index = self.names.get(symbol.splat.name)
        if index != None:
            if symbol.splat.vram_start != self.symbols[index].splat.vram_start:
                print('Error: trying to add ' + symbol.splat.name + ' with different address')
            return
            
        # Already existing addr
        index = self.addrs.get(symbol.splat.vram_start)
        if index != None:
            if symbol.splat.name != self.symbols[index].splat.name:
                self.rename(self.symbols[index].splat.name, symbol.splat.name)
            return
        
        #TODO: check symbol colision (new symbol between start/end of existing symbol)

        self.symbols.append(symbol)
        self.names[symbol.splat.name] = len(self.symbols)-1
        self.addrs[symbol.splat.vram_start] = len(self.symbols)-1

        if len(symbol.splat.name) > self.name_max_size:
            self.name_max_size = len(symbol.splat.name)

        if verbose:
            print('Adding symbol ' + symbol.splat.name)

    def rename(self, old: str, new: str) -> None:
        index = self.names.get(old)
        if index != None:
            self.symbols[index].splat.given_name = new
            del self.names[old]
            self.names[new] = index

            if len(new) > self.name_max_size:
                self.name_max_size = len(new)

            print('Renaming symbol ' + old + ' to ' + new)

    def remove(self, symbol: SYMBOL) -> None:
        index = self.names.get(symbol.splat.name)
        if index != None:
            del self.names[symbol.splat.name]
            del self.addrs[symbol.splat.vram_start]
            del self.symbols[index]
            print('Deleting symbol ' + symbol.splat.name)

    def update(self, symbol: SYMBOL) -> None:
        index = self.names.get(symbol.splat.name)
        if index != None:
            if symbol.splat.size != 0:
                self.symbols[index].splat.given_size = symbol.splat.size
            if symbol.splat.type != None:
                self.symbols[index].splat.type = symbol.splat.type
            if symbol.visibility != None:  
                self.symbols[index].visibility = symbol.visibility
            if symbol.section != None:
                self.symbols[index].section = symbol.section
            if symbol.source != None:
                self.symbols[index].source = symbol.source

def parse_symbols_from_config(file: str, symbols: SYMBOLS) -> None:
    f = open(file, 'r')
    lines = f.readlines()
    f.close() 

    for line in lines:
        s = line.split('=')
        if 'ignore:true' in line:
            name = s[0].strip()
            addr = int(s[1].strip().split(';')[0], 16)
            size = 0
            if 'size:' in line:
                size = int(s[1].strip().split('size:')[1].split()[0], 16)
            sym = SYMBOL(splat=split.symbols.Symbol(given_name=name, given_size=size, vram_start=addr), ignore=True)
            symbols.add(sym, False)
        else:
            addr = int(s[1].strip().split(';')[0], 16)
            splat = split.symbols.all_symbols_dict[addr][0]
            if not 'size:' in s[1]:
                splat.given_size = 0
            visibility = None
            section = None
            source = None
            if '(' in line:
                info = s[1].split('(')[1].split(')')[0].split(',')
                visibility = info[0].strip()
                section = info[1].strip()
                source = info[2].strip()
                
            sym = SYMBOL(splat=splat, visibility=visibility, section=section, source=source)
            symbols.add(sym, False)

def parse_addrs_from_source(file: str, coord: dict, symbols: SYMBOLS, forced: list) -> None:
    f = open(file, 'r')
    lines = f.readlines()
    f.close() 

    for i in range(0, len(lines)):
        if '/*' in lines[i]:
            # Look for symbol addrs
            addr = 0
            elmts = lines[i].split('/*')
            for elmt in elmts:
                try:
                    addr = int(elmt.split('*/')[0], 16)
                except:
                    continue

            if addr < 0x01000000:
                continue

            name = coord.get(i+1)
            # Is symbol on next line?
            if name == None:
                name = coord.get(i+2)
            if name == None and lines[i+1].startswith('INCLUDE_ASM'):
                name = lines[i+1].split(',')[1].split(')')[0].strip()
            if name == None:
                continue

            sym = SYMBOL(splat=split.symbols.Symbol(given_name=name, given_size=0, vram_start=addr))
            symbols.add(sym, True)
        if lines[i].startswith('INCLUDE_ASM'):
            name = lines[i].split(',')[1].split(')')[0].strip()
            sym = SYMBOL(splat=split.symbols.Symbol(given_name=name, given_size=0, vram_start=0, type='function'), \
                         source=file, section='.text')
            forced.append(sym)
        if 'EXTERN_DATA' in lines[i]:
            name = coord.get(i+1)
            sym = SYMBOL(splat=split.symbols.Symbol(given_name=name, given_size=0, vram_start=0), \
                         section='.data')
            forced.append(sym)
        if 'EXTERN_BSS' in lines[i]:
            name = coord.get(i+1)
            sym = SYMBOL(splat=split.symbols.Symbol(given_name=name, given_size=0, vram_start=0), \
                         section='.bss')
            forced.append(sym)
        if 'STATIC' in lines[i]:
            name = coord.get(i+1)
            sym = SYMBOL(splat=split.symbols.Symbol(given_name=name, given_size=0, vram_start=0), \
                         visibility='local')
            forced.append(sym)

def parse_object_file(file: str, symbols: SYMBOLS) -> None:
    result = subprocess.run(['mips-linux-gnu-nm', '--defined-only', '--print-size', '--print-file-name', file], \
                            capture_output=True, text=True)
    syms = result.stdout.split('\n')
    for sym in syms:
        sp = sym.split()
        if len(sp) == 0:
            continue
        elif len(sp) > 3:
            size = int(sp[1], 16)
            type = sp[2]
            name = sp[3]
        else:
            size = 0
            type = sp[1]
            name = sp[2]
        src = sp[0].split(':')[0]
        src = src.split((BUILD_DIR + '/'))[1]
        src = src.split('.o')[0]

        if type >= 'a' and type <= 'z':
            visibility = 'local'
        else:
            visibility = 'global'
        if type == 't' or type == 'T':
            t = 'function'
        else:
            t = 'data'

        if type == 'b' or type == 'B':
            section = '.bss'
        elif type == 'd' or type == 'D':
            section = '.data'
        elif type == 'c' or type == 'C':
            section = '.comm'
        elif type == 'r' or type == 'R':
            section = '.rodata'
        elif type == 't' or type == 'T':
            section = '.text'
        else:
            section = None
        
        sym = SYMBOL(splat=split.symbols.Symbol(given_name=name, given_size=size, vram_start=0, type=t), \
                     visibility=visibility, source=src, section=section)
        symbols.update(sym)

class Visitor(c_ast.NodeVisitor):
    def __init__(self, file) -> None:
        self.file = file
        self.coord = {}
    def visit_TypeDecl(self, node):
        if node.coord != None and self.file == node.coord.file:
            self.coord[node.coord.line] = node.declname

def parse_source_file(file: str, symbols: SYMBOLS, forced: list) -> None:            
    out_text = m2ctx.import_c_file(file, False, True)
    parser = c_parser.CParser()
    try:
        ast = parser.parse(out_text, filename='<stdin>')
    except:
        e = sys.exc_info()[1]
        print("Parse error:" + str(e) + ' from ' + file)
        return None

    v = Visitor(file)
    v.visit(ast)
    parse_addrs_from_source(file, v.coord, symbols, forced)

parser = argparse.ArgumentParser()
parser.add_argument('Path', nargs='*', default=[], help='source files')
parser.add_argument('-p', '--prefix_static', action='store_true', help='Prefix static variables')
args = parser.parse_args()

symbols = SYMBOLS()
forced = []
BUILD_DIR = 'tmp'

# Initialize splat symbols
with open('dukenukemzerohour.yaml') as f:
    config = split.yaml.load(f.read(), Loader=split.yaml.SafeLoader)
split.options.initialize(config, 'dukenukemzerohour.yaml', None, None)
all_segments = split.initialize_segments(config["segments"])
split.symbols.initialize(all_segments)

# Parse symbols from config file
parse_symbols_from_config('symbol_addrs.txt', symbols)

# Parse symbols from source files
h_files = [y for x in os.walk('include') for y in glob.glob(os.path.join(x[0], '*.h'))]

if len(args.Path) == 0:
    c_files = [y for x in os.walk('src') for y in glob.glob(os.path.join(x[0], '*.c'))]
else:
    c_files = args.Path

files = c_files + h_files

for file in files:
    parse_source_file(file, symbols, forced)

# Build source files
if len(args.Path) == 0:
    subprocess.run(['make', 'objects', '-j12', ('BUILD_DIR=' + BUILD_DIR), 'EXTERN=0'])
    o_files = [y for x in os.walk((BUILD_DIR + '/src')) for y in glob.glob(os.path.join(x[0], '*.o'))]
    o_files += [y for x in os.walk((BUILD_DIR + '/libs')) for y in glob.glob(os.path.join(x[0], '*.o'))]
else:
    o_files = []
    for file in args.Path:
        if '.c' in file:
            obj = os.path.join(BUILD_DIR, (file + '.o'))
            o_files.append(obj)
            subprocess.run(['make', obj, ('BUILD_DIR=' + BUILD_DIR), 'EXTERN=0'])

# Parse symbols from object files
for file in o_files:
    parse_object_file(file, symbols)

for sym in forced:
    symbols.update(sym)

#subprocess.run(['make', 'clean', ('BUILD_DIR=' + BUILD_DIR), 'EXTERN=0'])

# Sort symbols
symbols.symbols.sort()

# Prefix static symbols
if args.prefix_static == True:
    for file in files:
        for symbol in symbols.symbols:
            if (symbol.visibility == 'local') \
                and (not symbol.splat.name.startswith('_')) \
                and (not symbol.splat.name.startswith('D_')) \
                and (not symbol.splat.name.startswith('func_')) \
                and (file == symbol.source):
                prefix = '_' + os.path.basename(symbol.source).split('.')[0] + '_'
                symbols.rename(symbol.splat.name, (prefix + symbol.splat.name))
                
# Write symbols to files
f = open('symbol_addrs.txt.new', 'w')
try:
    for i in range(0, len(symbols.symbols)):
        line = ''
        line += (f'{symbols.symbols[i].splat.name:<{symbols.name_max_size}}')
        addr = f'{symbols.symbols[i].splat.vram_start:08X}'
        line += (' = 0x' + addr + ';')

        if symbols.symbols[i].ignore:
            line += (' //')
            line += (f"{' ignore:true':<14}")
            if symbols.symbols[i].splat.size > 0:
                size = f'{symbols.symbols[i].splat.size:X}'
                size = ' size:0x' + size
                line += (f"{size:<14}")
        elif (symbols.symbols[i].splat.type != None) or \
             (symbols.symbols[i].splat.size != 0) or \
             (symbols.symbols[i].splat.dont_allow_addend != False) or \
             (symbols.symbols[i].splat.force_not_migration != False) or \
             (symbols.symbols[i].splat.force_migration != False) or \
             (symbols.symbols[i].source != None):
            line += (' //')
            if symbols.symbols[i].splat.type != None:
                type = ' type:' + symbols.symbols[i].splat.type
                line += (f"{type:<14}")
            else:
                line += (f"{'':<14}")
            if symbols.symbols[i].splat.size > 0:
                size = f'{symbols.symbols[i].splat.size:X}'
                size = ' size:0x' + size
                line += (f"{size:<14}")
            else:
                line += (f"{'':<14}")
            if symbols.symbols[i].splat.dont_allow_addend == True:
                line += (f"{' dont_allow_addend:true':<25}")
            elif symbols.symbols[i].splat.force_not_migration == True:
                line += (f"{' force_not_migration:true':<25}")
            elif symbols.symbols[i].splat.force_migration == True:
                line += (f"{' force_migration:true':<25}")
            else:
                line += (f"{'':<25}")
            if symbols.symbols[i].source != None and symbols.symbols[i].section != None:
                if symbols.symbols[i].visibility != None:
                    visibility = symbols.symbols[i].visibility + ', '
                else:
                    visibility = 'global, '
                section = symbols.symbols[i].section + ', '
                line += ' (' + f"{visibility:<8}"
                line += f"{section:<9}"
                line += symbols.symbols[i].source + ')'

        f.write(line.strip())
        f.write('\n')
    f.close()
    os.remove('symbol_addrs.txt')
    os.rename('symbol_addrs.txt.new', 'symbol_addrs.txt')
except:
    f.close()
    os.remove('symbol_addrs.txt.new')
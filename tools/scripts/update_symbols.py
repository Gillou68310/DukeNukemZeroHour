#!/usr/bin/env python3
from pycparser import c_parser, c_ast
import subprocess
import argparse
import glob
import sys
import os
import m2ctx

class SYMBOL:
    def __init__(self, name: str = None, addr: int = 0, type: str = None, \
                 size: int = 0, static: bool = False, source: str = None, \
                 section: str = None, exclude: bool = False, ignore: bool = False):
         self.name: str = name
         self.addr: int = addr
         self.type: str = type
         self.size: int = size
         self.static: bool = static
         self.source: str = source
         self.section: str = section
         self.exclude: bool = exclude
         self.ignore: bool = ignore
    def __lt__(self, other):
         return self.addr < other.addr

class SYMBOLS:
    def __init__(self):
        self.addrs = {}
        self.names = {}
        self.symbols: list[SYMBOL] = []
        self.name_max_size = 0
    
    def add(self, symbol: SYMBOL, verbose: bool) -> None:
        # Already existing name
        index = self.names.get(symbol.name)
        if index != None:
            if symbol.addr != self.symbols[index].addr:
                print('Error: trying to add ' + symbol.name + ' with different address')
            return
            
        # Already existing addr
        index = self.addrs.get(symbol.addr)
        if index != None:
            if symbol.name != self.symbols[index].name:
                self.rename(self.symbols[index].name, symbol.name)
            return
        
        self.symbols.append(symbol)
        self.names[symbol.name] = len(self.symbols)-1
        self.addrs[symbol.addr] = len(self.symbols)-1

        if len(symbol.name) > self.name_max_size:
            self.name_max_size = len(symbol.name)

        if verbose:
            print('Adding symbol ' + symbol.name)

    def rename(self, old: str, new: str) -> None:
        index = self.names.get(old)
        if index != None:
            self.symbols[index].name = new
            del self.names[old]
            self.names[new] = index

            if len(new) > self.name_max_size:
                self.name_max_size = len(new)

            print('Renaming symbol ' + old + ' to ' + new)

    def remove(self, symbol: SYMBOL) -> None:
        index = self.names.get(symbol.name)
        if index != None:
            del self.names[symbol.name]
            del self.addrs[symbol.addr]
            del self.symbols[index]
            print('Deleting symbol ' + symbol.name)

    def update(self, symbol: SYMBOL) -> None:
        index = self.names.get(symbol.name)
        if index != None and not self.symbols[index].exclude:
            if symbol.size != 0:
                self.symbols[index].size = symbol.size
            if symbol.type != None:
                self.symbols[index].type = symbol.type
            self.symbols[index].static = symbol.static
            if symbol.section != None:
                self.symbols[index].section = symbol.section
            if symbol.source != None:
                self.symbols[index].source = symbol.source
            self.symbols[index].exclude = symbol.exclude

def parse_symbols_from_config(file: str, symbols: SYMBOLS) -> None:
    f = open(file, 'r')
    lines = f.readlines()
    f.close() 

    for line in lines:
        s = line.split('=')
        if len(s) == 2:
            name = s[0].strip()
            addr = int(s[1].strip().split(';')[0], 16)
            info = s[1].strip().split(';')[1].split()
            size = 0
            type = None
            static = False
            section = None
            src = None
            ignore = False
            for i in info:
                if 'size:' in i:
                    size = int(i.strip().split('size:')[1], 16)
                elif 'type:' in i:
                    type = i.strip().split('type:')[1]
                elif 'ignore:' in i:
                    if 'true' in i.strip().split('ignore:')[1]:
                        ignore = True
                elif '(static)' in i:
                    static = True
                elif '(.' in i:
                    section = i.strip().split('(.')[1].split(')')[0]
                elif '(' in i:
                    src = i.strip().split('(')[1].split(')')[0]
                
            sym = SYMBOL(name=name, addr=addr, type=type, size=size, static=static, section=section, source=src, ignore=ignore)
            symbols.add(sym, False)

def parse_addrs_from_source(file: str, coord: dict, symbols: SYMBOLS) -> None:
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
            if name == None:
                continue

            sym = SYMBOL(name=name, addr=addr)
            symbols.add(sym, True)
        elif lines[i].startswith('INCLUDE_ASM'):
             name = lines[i].split(',')[2].split(')')[0].strip()
             sym = SYMBOL(name=name, exclude=True)
             symbols.update(sym)

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
        src = src.split('build/')[1]
        src = src.split('.o')[0]

        if type >= 'a' and type <= 'z':
            static = True
        else:
            static = False
        if type == 't' or type == 'T':
            t = 'function'
        else:
            t = 'data'

        if type == 'b' or type == 'B':
            section = 'bss'
        elif type == 'd' or type == 'D':
            section = 'data'
        elif type == 'c' or type == 'C':
            section = 'comm'
        elif type == 'r' or type == 'R':
            section = 'rodata'
        elif type == 't' or type == 'T':
            section = 'text'
        else:
            section = None
        
        sym = SYMBOL(name=name, type=t, size=size, static=static, source=src, section=section)
        symbols.update(sym)

class Visitor(c_ast.NodeVisitor):
    def __init__(self, file) -> None:
        self.file = file
        self.coord = {}
    def visit_TypeDecl(self, node):
        if node.coord != None and self.file == node.coord.file:
            self.coord[node.coord.line] = node.declname

def parse_source_file(file: str, symbols: SYMBOLS) -> None:            
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
    parse_addrs_from_source(file, v.coord, symbols)

parser = argparse.ArgumentParser()
parser.add_argument('Path', nargs='*', default=[], help='source files')
parser.add_argument('-p', '--prefix_static', action='store_true', help='Prefix static variables')
args = parser.parse_args()

symbols = SYMBOLS()

# Parse symbols from config file
parse_symbols_from_config('symbol_addrs.txt', symbols)

# Parse symbols from source files
if len(args.Path) == 0:
    c_files = [y for x in os.walk('src') for y in glob.glob(os.path.join(x[0], '*.c'))]
    h_files = [y for x in os.walk('include') for y in glob.glob(os.path.join(x[0], '*.h'))]
    files = c_files + h_files
else:
    h_files = []
    files = args.Path
    for file in files:
        if '.c' in file:
            h = file.replace('src/', 'include/').replace('.c', '.h')
            h_files.append(h)
    files += h_files

for file in files:
    parse_source_file(file, symbols)

# Build source files
if len(args.Path) == 0:
    subprocess.run(['make', '-j12'])
    o_files = [y for x in os.walk('build/src') for y in glob.glob(os.path.join(x[0], '*.o'))]
    o_files += [y for x in os.walk('build/libs') for y in glob.glob(os.path.join(x[0], '*.o'))]
else:
    o_files = []
    for file in args.Path:
        if '.c' in file:
            obj = os.path.join('build', (file + '.o'))
            o_files.append(obj)
            subprocess.run(['make', obj])

# Parse symbols from object files
for file in o_files:
    parse_object_file(file, symbols)

# Sort symbols
symbols.symbols.sort()

# Prefix static symbols
if args.prefix_static == True:
    for file in files:
        for symbol in symbols.symbols:
            if (symbol.static == True) \
                and (not symbol.name.startswith('_')) \
                and (not symbol.name.startswith('D_')) \
                and (not symbol.name.startswith('func_')) \
                and (file == symbol.source):
                prefix = '_' + os.path.basename(symbol.source).split('.')[0] + '_'
                symbols.rename(symbol.name, (prefix + symbol.name))
                
# Write symbols to files
f = open('symbol_addrs.txt', 'w')
for i in range(0, len(symbols.symbols)):
    line = ''
    line += (f'{symbols.symbols[i].name:<{symbols.name_max_size}}')
    addr = f'{symbols.symbols[i].addr:08X}'
    line += (' = 0x' + addr + ';')

    if symbols.symbols[i].ignore:
        line += (' //')
        line += (f"{' ignore:true':<14}")
        if symbols.symbols[i].size != 0:
            size = f'{symbols.symbols[i].size:X}'
            size = ' size:0x' + size
            line += (f"{size:<14}")
    elif (symbols.symbols[i].type != None) or (symbols.symbols[i].size != 0) \
        or (symbols.symbols[i].static == True) or (symbols.symbols[i].source != None) \
        or (symbols.symbols[i].section != None):
        line += (' //')
        if symbols.symbols[i].type != None:
            type = ' type:' + symbols.symbols[i].type
            line += (f"{type:<14}")
        else:
            line += (f"{'':<14}")
        if symbols.symbols[i].size != 0:
            size = f'{symbols.symbols[i].size:X}'
            size = ' size:0x' + size
            line += (f"{size:<14}")
        else:
            line += (f"{'':<14}")
        if symbols.symbols[i].static == True:
            line += (' (static)')
        else:
            line += (f"{'':<9}")
        if symbols.symbols[i].section != None:
            section = ' (.' + symbols.symbols[i].section + ')'
            line += (f"{section:<10}")
        else:
            line += (f"{'':<10}")
        if symbols.symbols[i].source != None:
            line += ( ' (' + symbols.symbols[i].source + ')')
    
    f.write(line.strip())
    f.write('\n')
f.close()

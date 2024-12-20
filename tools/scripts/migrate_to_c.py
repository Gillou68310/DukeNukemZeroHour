#!/usr/bin/env python3
from pycparser import c_parser, c_ast
from dataclasses import dataclass
import subprocess
import argparse
import m2ctx
import sys
import os

@dataclass
class SYMBOLS():
    name: str
    addr: int
    local: bool

def parse_addrs_from_source(file: str, coord: dict, symbols: SYMBOLS, includes) -> None:
    f = open(file, 'r')
    lines = f.readlines()
    f.close() 

    for i in range(0, len(lines)):
        if '#include' in lines[i]:
            includes.append(lines[i])
        elif '/*' in lines[i] and 'EXTERN_DATA' in lines[i]:
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
            if name == None:
                continue

            sym = SYMBOLS(name=name, addr=addr, local='STATIC' in lines[i])
            symbols[name] = sym

class Visitor(c_ast.NodeVisitor):
    def __init__(self, file) -> None:
        self.file = file
        self.coord = {}
    def visit_TypeDecl(self, node):
        if node.coord != None and self.file == node.coord.file:
            self.coord[node.coord.line] = node.declname

def parse_source_file(file: str, version: str) -> None:            
    out_text = m2ctx.import_c_file(file, False, True, version)
    parser = c_parser.CParser()
    try:
        ast = parser.parse(out_text, filename='<stdin>')
    except:
        e = sys.exc_info()[1]
        print("Parse error:" + str(e) + ' from ' + file)
        return None

    v = Visitor(file)
    v.visit(ast)
    return (v, out_text)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("c_file")
    parser.add_argument('-v', '--version', type=str, default='us', help='game version')
    args = parser.parse_args()
    asm = args.c_file
    c_file = asm.replace('asm/'+args.version+'/data/', '', 1).replace('.data.s', '.c')
    rodata = asm.replace('.data.s', '.rodata.s')

    if os.path.isfile(rodata):
        # Merge data + rodata
        filenames = [rodata, asm]
        f = open('data.s', 'w')
        for fname in filenames:
            with open(fname) as infile:
                for line in infile:
                    f.write(line)
            f.write('\n\n')
        f.close()
        asm = 'data.s'

    symbols = {}
    includes = []

    # Parse C file
    v, ctx = parse_source_file(c_file, args.version)
    parse_addrs_from_source(c_file, v.coord, symbols, includes)

    # Write m2c context
    f = open('data.c', 'w')
    f.write(ctx)
    f.close()

    # Decompile data
    decomp = subprocess.check_output(['tools/m2c/m2c.py', '--globals', 'all', '--context', 'data.c', asm], encoding="utf-8")

    #TODO: check for 'unable to generate initializer'?

    # Add original headers
    decomp = ''.join(includes) + decomp
    lines = decomp.splitlines()

    # Write decompiled data
    f = open('data.c', 'w')
    for line in lines:
        if 'extern' in line and '+' in line or '?' in line:
            f.write('//'+line+'\n')
        else:
            f.write(line+'\n')
    f.close()

    # Parse decompiled data
    v, ctx = parse_source_file('data.c', args.version)

    # Add infos from C file to decompiled data
    insert = {}
    for line, name in v.coord.items():
        sym = symbols.get(name)
        if sym != None:
            if ';' in lines[line-1]:
                l = '/*' + f'{sym.addr:08X}' + '*/ ' 
                if sym.local:
                    l += 'static '
                lines[line-1] = l + lines[line-1]
            else:
                if sym.local:
                    lines[line-1] = 'static ' + lines[line-1]
                insert[line-1] = '/*' + f'{sym.addr:08X}' + '*/'
        else:
            print('Error: ' + name + ' not declared')

    # Write decompiled data with additional infos
    f = open('data.c', 'w')
    for i in range(0, len(lines)):
        l = insert.get(i)
        if l != None:
            f.write('\n' + l + '\n')
        f.write(lines[i] + '\n')
        if lines[i] == '};':
            f.write('\n')
    f.close()
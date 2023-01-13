#!/usr/bin/env python3
import argparse
import glob
import sys
import os
sys.path.insert(1, 'tools/scripts')
import m2ctx
from pycparser import c_parser, c_ast, c_generator

def parse_source_file(file: str) -> None:            
    source = m2ctx.import_c_file(file, macro=False, linemarker=False)
    parser = c_parser.CParser()
    try:
        ast = parser.parse(source, filename='<stdin>')
    except:
        e = sys.exc_info()[1]
        print("Parse error:" + str(e) + ' from ' + file)
        sys.exit()

    #prune function def and variable init
    for i, node in enumerate(ast.ext):
        if isinstance(node, c_ast.FuncDef):
            ast.ext[i] = node.decl
        elif isinstance(node, c_ast.Decl):
            ast.ext[i].init = None

    return c_generator.CGenerator().visit(ast)

parser = argparse.ArgumentParser()
parser.add_argument('Path', nargs='*', default=[], help='source files')
args = parser.parse_args()

h_files = [y for x in os.walk('include') for y in glob.glob(os.path.join(x[0], '*.h'))]

if len(args.Path) == 0:
    c_files = [y for x in os.walk('src') for y in glob.glob(os.path.join(x[0], '*.c'))]
else:
    c_files = args.Path

files = h_files + c_files
f = open('ida_ctx.c', 'w')

for file in files:
    source = parse_source_file(file)
    if source != None:
        f.write(source)

f.close()
#!/usr/bin/env python3
from functools import partial
import argparse
import glob
import tqdm
import sys
import os
sys.path.insert(1, 'tools/scripts')
import m2ctx
from pycparser import c_parser, c_ast, c_generator
from multiprocessing import Pool

def parse_source_file(file: str, version: str) -> None:            
    source = m2ctx.import_c_file(file, macro=False, linemarker=False, version=version)
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

    return c_generator.CGenerator().visit(ast), file

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('Path', nargs='*', default=[], help='source files')
    parser.add_argument('-v', '--version', type=str, default='us', help='game version')
    args = parser.parse_args()

    h_files = [y for x in os.walk('include') for y in glob.glob(os.path.join(x[0], '*.h'))]

    if len(args.Path) == 0:
        c_files = [y for x in os.walk('src') for y in glob.glob(os.path.join(x[0], '*.c'))]
    else:
        c_files = args.Path

    files = h_files + c_files
    f = open('ida_ctx.c', 'w')

    with Pool() as pool:
        sources = list(tqdm.tqdm(pool.imap(partial(parse_source_file, version=args.version), files), total=len(files)))

    for src, file in sources:
        #prefix unused variables to avoid multiple definitions
        prefix = os.path.basename(file).split('.')[0]
        src = src.replace("_unused", "_"+prefix+"_unused")
        f.write(src)

    f.close()
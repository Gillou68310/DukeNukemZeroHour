#!/usr/bin/env python3
from pycparser import c_parser, c_ast, c_generator
from pathlib import Path
from typing import Dict
import urllib.request
import urllib.parse
import tempfile
import argparse
import m2ctx
import json
import glob
import sys
import os
        
def get_scratches_decompme(api_base, sessionid):
    scratches = []
    url = f"{api_base}/api/user/scratches?page_size=100" 
    while(1):
        try:
            request = urllib.request.Request(url)
            request.add_header("Cookie", "sessionid=" + sessionid)
            data = urllib.request.urlopen(request).read()
            json_object = json.loads(data)
            scratches += json_object["results"]
            if json_object["next"]:
                url = json_object["next"]
            else:
                break
        except Exception:
            print(f"Failed to get scratches from {api_base}")
            break

    dico = {}
    for s in scratches:
        dico[s['name']] = s
    return dico

def generate_context(file: str, prune: False, version: str) -> None:
    source = m2ctx.import_c_file(file, macro=True, linemarker=False, version=version)
    if not prune:
        return source
    
    lines = source.splitlines()
    macro = ""
    source = ""
    for line in lines:
        if line.startswith('#define'):
            macro += line + '\n'
        else:
            source += line + '\n'

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

    return macro + c_generator.CGenerator().visit(ast)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("c_file")
    parser.add_argument('-p', '--prune', action='store_true', help='Prune context')
    parser.add_argument('-d', '--dump', action='store_true', help='Dump context')
    parser.add_argument('-v', '--version', type=str, default='us', help='game version')
    args = parser.parse_args()

    api_base = os.environ.get("DECOMPME_API_BASE", "https://decomp.me")

    path = list(Path('asm/'+args.version+'/nonmatchings/').rglob(args.c_file + '*'))
    
    if len(path) == 0:
        print('Cannot find function ' + args.c_file)
        sys.exit(1)
    
    assert(len(path) == 1)
    path = path[0]
    print('Found function at ' + str(path))
    
    src_file = Path(*path.parts[3:-1])
    src_file = src_file.with_suffix('.c')
    h_files = [y for x in os.walk('include') for y in glob.glob(os.path.join(x[0], '*.h'))]
    
    fd, temp = tempfile.mkstemp(suffix=".c")
    f = open(temp, 'w')
    src = open(src_file, 'r')
    lines = src.readlines()
    src.close()
    
    for h in h_files:
        f.write('#include \"' + h.replace('include/', '') + '\"\n')
    
    f.write('\n')
    
    for line in lines:
        f.write(line)
    
    f.close()
    
    print("Generating context...")
    context = generate_context(temp, args.prune, args.version)
    os.remove(temp)

    if args.dump:
        f = open("ctx.c", 'w')
        f.write(context)
        f.close()
        sys.exit(1)
    
    f = open(path, 'r')
    asm_cont = f.read()
    f.close()
    
    # Check if function is already on decompme
    if os.path.exists('sessionid'):
        f = open('sessionid', 'r')
        lines = f.readlines()
        f.close()
        assert(len(lines) == 1)
        scrathes = get_scratches_decompme(api_base, lines[0])
        s = scrathes.get(args.c_file)
        if s != None:
            print("Already existing function at")
            print(f"{api_base}/scratch/{s['slug']}")
            sys.exit(1)

    func_name = os.path.basename(path).split('.')[0]
    print("Uploading...")
    try:
        post_data = urllib.parse.urlencode(
            {
                "temp": func_name,
                "target_asm": asm_cont,
                "context": context,
                "source_code": "",
                "compiler": "gcc2.7.2kmc",
                "compiler_flags": "-O2 -g2 -mips3 -funsigned-char",
                "diff_label": func_name,
            }
        ).encode("ascii")
        with urllib.request.urlopen(f"{api_base}/api/scratch", post_data) as f:
            resp = f.read()
            json_data: Dict[str, str] = json.loads(resp)
            if "slug" in json_data:
                slug = json_data["slug"]
                token = json_data.get("claim_token")
                if token:
                    print(f"{api_base}/scratch/{slug}/claim?token={token}")
                else:
                    print(f"{api_base}/scratch/{slug}")
            else:
                error = json_data.get("error", resp)
                print(f"Server error: {error}")
    except Exception as e:
        print(e)
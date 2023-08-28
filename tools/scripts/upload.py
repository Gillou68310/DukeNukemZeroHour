#!/usr/bin/env python3

from pathlib import Path
from typing import Dict
import urllib.request
import urllib.parse
import tempfile
import m2ctx
import json
import glob
import sys
import os
        
def get_scratches_decompme(sessionid):
    scratches = []
    url = "{api_base}/api/user/scratches?page_size=100" 
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
            print("Failed to get scratches from decomp.me")
            break

    dico = {}
    for s in scratches:
        dico[s['name']] = s
    return dico

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print('upload.py [function]')
        sys.exit(1)

    api_base = os.environ.get("DECOMPME_API_BASE", "https://decomp.me")
    
    # Check if function is already on decompme
    if os.path.exists('sessionid'):
        f = open('sessionid', 'r')
        lines = f.readlines()
        f.close()
        assert(len(lines) == 1)
        scrathes = get_scratches_decompme(lines[0])
        s = scrathes.get(sys.argv[1])
        if s != None:
            print("Already existing function at")
            print(f"https://decomp.me/scratch/{s['slug']}")
            sys.exit(1)
    
    path = list(Path('nonmatchings/').rglob(sys.argv[1] + '*'))
    
    if len(path) == 0:
        print('Cannot find function ' + sys.argv[1])
        sys.exit(1)
    
    assert(len(path) == 1)
    path = path[0]
    print('Found function at ' + str(path))
    
    src_file = Path(*path.parts[1:-1])
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
    context = m2ctx.import_c_file(temp, True, False)
    os.remove(temp)
    
    f = open(path, 'r')
    asm_cont = f.read()
    f.close()
    
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
                print(f"{api_base}/scratch/{slug}")
            else:
                error = json_data.get("error", resp)
                print(f"Server error: {error}")
    except Exception as e:
        print(e)
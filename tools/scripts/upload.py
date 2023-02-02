#!/usr/bin/env python3

from typing import Dict
import urllib.request
import urllib.parse
import tempfile
import m2ctx
import json
import glob
import sys
import os

if len(sys.argv) < 2:
    print('upload.py [function path]')
    sys.exit(1)

path = sys.argv[1]
s = path.split('/')
del s[0]
del s[-1]
src_file = os.path.join(*s) + '.c'
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

context = m2ctx.import_c_file(temp, True, False)
os.remove(temp)

f = open(path, 'r')
asm_cont = f.read()
f.close()

func_name = os.path.basename(path).split('.')[0]
api_base = os.environ.get("DECOMPME_API_BASE", "https://decomp.me")
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
            print(f"https://decomp.me/scratch/{slug}")
        else:
            error = json_data.get("error", resp)
            print(f"Server error: {error}")
except Exception as e:
    print(e)
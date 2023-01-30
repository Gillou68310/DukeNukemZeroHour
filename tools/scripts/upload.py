#!/usr/bin/env python3
import subprocess
import tempfile
import m2ctx
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

fd, name = tempfile.mkstemp(suffix=".c")
f = open(name, 'w')
src = open(src_file, 'r')
lines = src.readlines()
src.close()

for h in h_files:
    f.write('#include \"' + h.replace('include/', '') + '\"\n')

f.write('\n')

for line in lines:
    f.write(line)

f.close()

out_text = m2ctx.import_c_file(name, True, False)

f = open('ctx.c', 'w')
f.write(out_text)
f.close()
os.remove(name)

subprocess.run(['tools/decomp-permuter/import.py', '--decompme', 'ctx.c', path])
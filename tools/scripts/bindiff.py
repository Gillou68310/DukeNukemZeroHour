#!/usr/bin/env python3

import subprocess
import tempfile
import sys
import os

if len(sys.argv) < 2:
    print('bindiff START END')
    sys.exit(1)

start = int(sys.argv[1], 16)
end = int(sys.argv[2], 16)
len = end - start

fd1, path1 = tempfile.mkstemp()
fd2, path2 = tempfile.mkstemp()

target = subprocess.run(('hexdump', '-C', '-v', '-s', str(start), '-n', str(len), 'baserom.us.z64'), capture_output=True)
current = subprocess.run(('hexdump', '-C', '-v', '-s', str(start), '-n', str(len), 'build/dukenukemzerohour.z64'), capture_output=True)

os.write(fd1, target.stdout)
os.write(fd2, current.stdout)
os.close(fd1)
os.close(fd2)

out = subprocess.run(('diff', '-u', path1, path2), capture_output=True, text=True)
if out.stdout == '':
    print('Identical')
else:
    print(out.stdout)

os.remove(path1)
os.remove(path2)
#!/usr/bin/env python3

import urllib.request
import urllib.parse
from io import BytesIO

import subprocess
import tempfile
import zipfile
import sys
import os

def download_decompme(url_str, dir):
    try:
        parsed_url = urllib.parse.urlparse(url_str)
        slug = parsed_url.path[1:].split("/")[1]
    except Exception:
        print(
            f"Failed to parse decomp.me url, it should look like:{api_base}/scratch/<id>"
        )
        sys.exit(1)

    print(f"Downloading scratch with ID {slug}...")
    try:
        response_str = urllib.request.urlopen(f"{api_base}/api/scratch/{slug}")

        content = urllib.request.urlopen(
            f"{api_base}/api/scratch/{slug}/export"
        )
        zip = zipfile.ZipFile(BytesIO(content.read()))
        zip.extractall(dir)
    except Exception:
        print("Failed to download scratch from decomp.me")
        sys.exit(1)

def get_function_name(path):
    f = open(path, 'r')
    lines = f.readlines()
    f.close()
    for line in reversed(lines):
        if 'glabel' in line:
            return line.split()[1]
    return None

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print('permute.py [url]')
        sys.exit(1)

    api_base = os.environ.get("DECOMPME_API_BASE", "https://decomp.me")
    
    tempdir = tempfile.TemporaryDirectory(dir='./')
    download_decompme(sys.argv[1], tempdir.name)
    
    # Merge context + code
    filenames = [os.path.join(tempdir.name, 'ctx.c'), os.path.join(tempdir.name, 'code.c')]
    f =  open(os.path.join(tempdir.name, 'func.c'), 'w')
    for fname in filenames:
        with open(fname) as infile:
            for line in infile:
                f.write(line)
        f.write('\n\n')
    f.close()
    
    code = os.path.join(tempdir.name, 'func.c')
    target = os.path.join(tempdir.name, 'target.s')
    nonmatching = os.path.join('nonmatchings', get_function_name(target))
    
    subprocess.run(['tools/decomp-permuter/import.py', code, target])
    tempdir.cleanup()
    subprocess.run(['tools/decomp-permuter/permuter.py', '--best-only', '--stop-on-zero', '-j12', nonmatching])

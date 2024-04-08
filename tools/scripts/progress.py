#!/usr/bin/env python3

import argparse
import git
import os
import subprocess
import sys
from colour import Color

VERSION='us'
script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.join(script_dir, "../..")
asm_dir = os.path.join(root_dir, "asm/"+VERSION+"/nonmatchings")
build_dir = os.path.join(root_dir, "build/"+VERSION)
elf_path = os.path.join(build_dir, "dukenukemzerohour.elf")

def parse_source_file(file, addrs):
    f = open(file, 'r')
    lines = f.readlines()
    f.close() 

    s = set()
    for i in range(0, len(lines)):
        if '#ifdef NON_MATCHING' in lines[i]:
            # Look for symbol addrs
            addr = 0
            name = None
            elmts = lines[i+1].split('/*')
            for elmt in elmts:
                try:
                    addr = int(elmt.split('*/')[0], 16)
                except:
                    continue

            if addr < 0x01000000:
                continue

            s.add(addrs[addr])
    return s

def get_func_sizes():
    try:
        result = subprocess.run(['objdump', '-x', elf_path], stdout=subprocess.PIPE)
        nm_lines = result.stdout.decode().split("\n")
    except:
        print(f"Error: Could not run objdump on {elf_path} - make sure that the project is built")
        sys.exit(1)

    sizes = {}
    addrs = {}
    total = 0

    for line in nm_lines:
        if " F " in line:
            components = line.split()
            size = int(components[4], 16)
            addr = int(components[0], 16)
            name = components[5]
            total += size
            sizes[name] = size
            addrs[addr] = name

    return sizes, total, addrs

def get_nonmatching_funcs(addrs):
    funcs = set()
    equivalent = set()

    for root, dirs, files in os.walk(asm_dir):
        if len(files) != 0:
            equivalent.update(parse_source_file(os.path.relpath(root, asm_dir)+'.c', addrs))
        for f in files:
            if f.endswith(".s"):
                funcs.add(f[:-2])

    return funcs, equivalent

def get_funcs_sizes(sizes, matchings, nonmatchings):
    msize = 0
    nmsize = 0

    for func in matchings:
        msize += sizes[func]

    for func in nonmatchings:
        if func not in sizes:
            pass
            # print(func)
        else:
            nmsize += sizes[func]

    return msize, nmsize

def lerp(a, b, alpha):
    return a + (b - a) * alpha

def getProgressData(nonmatching_equivalent = False) -> list:
    func_sizes, total_size, addrs = get_func_sizes()
    all_funcs = set(func_sizes.keys())

    nonmatching_funcs, nonmatching_equivalent_funcs = get_nonmatching_funcs(addrs)
    if nonmatching_equivalent:
        nonmatching_funcs -= nonmatching_equivalent_funcs

    matching_funcs = all_funcs - nonmatching_funcs

    matching_size, nonmatching_size = get_funcs_sizes(func_sizes, matching_funcs, nonmatching_funcs)

    if len(all_funcs) == 0:
        funcs_matching_ratio = 0.0
        matching_ratio = 0.0
    else:
        funcs_matching_ratio = (len(matching_funcs) / len(all_funcs)) * 100
        matching_ratio = (matching_size / total_size) * 100

    if matching_size + nonmatching_size != total_size:
        print("Warning: category/total size mismatch!\n")

    return len(matching_funcs), len(all_funcs), funcs_matching_ratio, matching_size, total_size, matching_ratio

def main(args):
    matching,total,funcs_matching_ratio, \
    matching_size,total_size,matching_ratio = getProgressData(args.equivalent)

    if args.csv:
        version = 1
        git_object = git.Repo().head.object
        timestamp = str(git_object.committed_date)
        git_hash = git_object.hexsha
        csv_list = [str(version), timestamp, git_hash, str(total),
                    str(matching), str(total_size), str(matching_size)]
        print(",".join(csv_list))
    elif args.shield_json:
        import json

        # https://shields.io/endpoint
        color = Color("#50ca22", hue=lerp(0, 105/255, matching_ratio / 100))
        print(json.dumps({
            "schemaVersion": 1,
            "label": f"progress ({args.version})",
            "message": f"{matching_ratio:.2f}%",
            "color": color.hex,
        }))
    else:
        print(f"{matching} matched functions / {total} total ({funcs_matching_ratio:.2f}%)")
        print(f"{matching_size} matching bytes / {total_size} total ({matching_ratio:.2f}%)")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Reports progress for the project")
    parser.add_argument("--csv", action="store_true")
    parser.add_argument("--shield-json", action="store_true")
    parser.add_argument("--equivalent", action="store_true")
    args = parser.parse_args()

    main(args)

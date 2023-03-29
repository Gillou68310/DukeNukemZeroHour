#!/usr/bin/env python3

import argparse
import os
import sys
import subprocess
import tempfile

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, "../.."))
src_dir = root_dir + "src/"

# Project-specific
CFLAGS = [
    "-G0",
    "-mips3",
    "-mgp32",
    "-mfp32",
]

CPP_FLAGS = [
    "-Iinclude",
    "-Ilibs/libultra/include/2.0I",
    "-Ilibs/libmus/include",
    "-Ilibs/libkmc/include",
    "-D_LANGUAGE_C",
    "-DF3DEX_GBI_2",
    "-D_MIPS_SZLONG=32",
    "-D_FINALROM",
    "-DTARGET_N64",
    "-DEXTERN_DATA=extern",
    "-DEXTERN_BSS=extern",
    "-DSTATIC=",
    "-D__attribute__(A)=",
    "-U__mips",
    "-D__CTX__",
]

def import_c_file(in_file, macro, linemarker) -> str:
    
    cpp_command = ["mips-linux-gnu-cpp", "-P", "-dM", *CFLAGS, *CPP_FLAGS, in_file]

    if linemarker:
        cpp_command2 = ["mips-linux-gnu-cpp", *CFLAGS, *CPP_FLAGS, in_file]
    else:
        cpp_command2 = ["mips-linux-gnu-cpp", "-P", *CFLAGS, *CPP_FLAGS, in_file]

    if macro:
        with tempfile.NamedTemporaryFile(suffix=".c") as tmp:
            stock_macros = subprocess.check_output(["mips-linux-gnu-cpp", "-P", "-dM", tmp.name], cwd=root_dir, encoding="utf-8")

    out_text = ""
    try:
        if macro:
            out_text += subprocess.check_output(cpp_command, cwd=root_dir, encoding="utf-8")
        out_text += subprocess.check_output(cpp_command2, cwd=root_dir, encoding="utf-8")
    except subprocess.CalledProcessError:
        print(
            "Failed to preprocess input file, when running command:\n"
            + ' '.join(cpp_command),
            file=sys.stderr,
            )
        sys.exit(1)

    if macro:
        for line in stock_macros.strip().splitlines():
            out_text = out_text.replace(line + "\n", "")

    out_text_ = ""
    for line in out_text.strip().splitlines():
        if "#ident" in line:
            out_text_ += "\n"
            continue
        if "#define va_end" in line:
            out_text_ += "\n"
            continue
        if "while(1)" in line:
            out_text_ += "\n"
            continue
        if line.startswith(";"):
            out_text_ += "\n"
            continue
        if "sizeof(long)" in line:
            line = line.replace("sizeof(long)", "4")

        out_text_ += line + "\n"
            
    return out_text_

def main():
    parser = argparse.ArgumentParser(
        description="""Create a context file which can be used for mips_to_c"""
    )
    parser.add_argument(
        "c_file",
        help="""File from which to create context""",
    )
    args = parser.parse_args()
    output = import_c_file(os.path.relpath(args.c_file, root_dir), True, False)

    with open(os.path.join(root_dir, "ctx.c"), "w", encoding="UTF-8") as f:
        f.write(output)

if __name__ == "__main__":
    main()
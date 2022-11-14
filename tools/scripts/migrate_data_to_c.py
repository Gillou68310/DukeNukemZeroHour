#!/usr/bin/python3

import os
import argparse
import subprocess

def asm_to_c(name: str, type: str, data, section: str) -> str:
    output = ''
    if section == 'bss':
        output += 'static '
    elif section == 'rodata':
        output += 'const '

    if type == '.word':
        output += 's32 '
    elif type == '.dword':
        output += 's64 '
    elif type == '.byte':
        output += 's8 '
    elif type == '.short':
        output += 's16 '
    elif type == '.space':
        output += 'u8 '
    elif type == '.float':
        output += 'f32 '
    elif type == '.double':
        output += 'f64 '
    elif type == '.asciz':
        output += 'char '
    else:
        output = '?'

    output += name
    if type == '.space':
        output += '[' + data[0] + '];'
    elif type == '.asciz':
        output += '[] = \"' + data[0]
        for i in range (0, len(data)-1):
            output += '\\0\\0\\0\\0'
        output += '\";'
    else:
        if len(data) > 1:
            output += '[' + str(len(data)) + '] = {\n'
            for d in data:
                if name.startswith('jtbl_'):
                    output += '    ' + d.replace('L', '0x') + ',\n' 
                else:
                    output += '    ' + d.replace('D_', '/*D_*/0x').replace('func_', '/*func_*/0x') + ',\n' 
            output += '};'
        else:
            output += ' = ' + data[0].replace('D_', '/*D_*/0x').replace('func_', '/*func_*/0x') + ';'

    return output

def get_src_path(file_path):
    output_dir = os.path.dirname(file_path).replace('data/', 'src/')
    if not os.path.exists(output_dir):
        return None

    filename = os.path.basename(file_path).split('.')[0] + '.c'
    return os.path.join(output_dir, filename)

def get_decl(name, m2c_decl):
    d = None
    for decl in m2c_decl:
        if d != None:
            if ';' in d:
                return d
            else:
                d += decl + '\n'
        elif d == None and name in decl:
            if '?' in decl:
                return None
            else:
                d = decl + '\n'
    return None

def data_to_c(file_path):
    name = None
    type = None
    data = []
    section = os.path.basename(file_path).split('.')[1]
    if 'common' in file_path:
        section = 'comm'
    output = '/*.' + section + '*/\n'

    subprocess.run(['tools/m2ctx.py', get_src_path(file_path)])
    result = subprocess.run(['tools/m2c/m2c.py', '--context', 'ctx.c', '--globals=all', file_path], \
                            capture_output=True, text=True)

    #TODO: split on ';' than split on '\n' and only check tab[0] for sym name
    m2c_decl = result.stdout.split('\n')

    file = open(file_path)
    lines = file.readlines()
    file.close()

    #TODO: Add addr from comment for m2c_decl?
    #TODO: Add comment in front of generated data?
    #TODO: Add static specifier if declaration comes from src not from header
    for line in lines:
        if line.startswith('glabel'):
            name = line.split()[1]
            res = get_decl(name, m2c_decl)
            if res != None:
                output += res
                name = None
        elif (name != None) and (line.startswith('\n')):
            output += asm_to_c(name, type, data, section)
            output += '\n'
            name = None
            type = None
            data = []
        elif (name != None) and ('.balign' not in line):
            s = line.split('*/ ')[1].split()
            type = s[0]
            if type == '.asciz':
                data.append(line.split('\"')[1])
            else:
                data.append(s[1])

    if (name != None):
        output += asm_to_c(name, type, data, section)
        output += '\n'

    return output

def out_to_file(output, file_path):
    srcfile = get_src_path(file_path)
    file = open(srcfile, 'r')
    lines = file.readlines()
    file.close()

    first = True
    file = open(srcfile, 'w')
    for line in lines:
        if first and line.startswith('/*.text*/'):
            file.write(output)
            file.write('\n')
            first = False
        file.write(line)
    file.close()

def get_all(section):
    for root, dirs, files in os.walk('./data/'):
        for f in files:
            file_path = os.fspath(os.path.join(root, f))
            if section == None or file_path.endswith('.' + section + '.s'):
                out_to_file(data_to_c(file_path), file_path)

parser = argparse.ArgumentParser(description='Tool to translate data files to data arrays')
parser.add_argument('file_path', help='data file', nargs='?', default=None)
parser.add_argument('--all', help='translate all data files at once and output them into /src', action='store_true', required=False)
parser.add_argument('--to-file', help='redirect the output into a file. Can not be used in combination with --all', action='store_true', required=False)
parser.add_argument('--section', help='data/rodata/bss', type=str, default=None, required=False)
args = parser.parse_args()

if args.file_path is None and args.all is False and args.to_file is False:
    parser.print_help()
    exit()

if args.section != None and args.section != 'data' and args.section != 'rodata' and args.section != 'bss':
    parser.print_help()
    exit()

if args.all is False:
    output = data_to_c(args.file_path)
    if args.to_file is True:
        out_to_file(output, args.file_path)
    else:
        print(output)
else:
    get_all(args.section)

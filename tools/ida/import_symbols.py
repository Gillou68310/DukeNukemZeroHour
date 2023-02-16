import os
import shutil
import subprocess

import idc
import ida_ua
import ida_name
import ida_funcs
import ida_bytes
import ida_idaapi
import ida_diskio
import ida_typeinf

class SYMBOL:
    def __init__(self, name, addr, type, size, ignore):
         self.name = name
         self.addr = addr
         self.type = type
         self.size = size
         self.ignore = ignore

def get_type_size(type):
    tp = idc.parse_decl(type, idc.PT_SIL)

    if tp != None:
        return ida_typeinf.calc_type_size(None, tp[1])
    else:
        return 0

def parse_symbol_addrs(file):
    f = open(file, 'r')
    lines = f.readlines()
    f.close() 

    symbols = []
    for line in lines:
        s = line.split('=')
        if len(s) == 2:
            name = s[0].strip()
            addr = int(s[1].strip().split(';')[0], 16)
            info = s[1].strip().split(';')[1].split()
            size = 0
            type = None
            ignore = False
            for i in info:
                if 'size:' in i:
                    size = int(i.strip().split('size:')[1], 16)
                if 'type:' in i:
                    type = i.strip().split('type:')[1]
                elif 'ignore:' in i:
                    if 'true' in i.strip().split('ignore:')[1]:
                        ignore = True
            symbols.append(SYMBOL(name, addr, type, size, ignore))

    return symbols

# Add symbols
symbols = parse_symbol_addrs('symbol_addrs.txt')
for symbol in symbols:
    if symbol.ignore:
        continue
    
    ea = ida_name.get_name_ea(ida_idaapi.BADADDR, symbol.name)
    if ea != None:
        ida_name.del_global_name(ea)
    ida_name.set_name(symbol.addr, symbol.name)

# Create type library from context file
tilib = os.path.join(ida_diskio.idadir(''), 'tilib.exe')
if os.path.isfile(tilib) and os.path.isfile('ida_ctx.c'):

    try:
        os.remove('dukezh.til')
    except OSError:
        pass

    result = subprocess.run([tilib, '-Cags40444248u3n', '-Gn', '-u+', '-c', '-v', '-hida_ctx.c', 'dukezh.til'], capture_output=True, text=True)

    if os.path.isfile('dukezh.til'):
        print('Importing type library...')
        tildir = ida_diskio.idadir(os.path.join('til', 'mips'))
        os.makedirs(tildir, exist_ok=True)
        shutil.copy('dukezh.til', tildir)
        ida_typeinf.del_til('dukezh.til')
        ida_typeinf.add_til('dukezh.til', ida_typeinf.ADDTIL_DEFAULT)

        # Compare symbol size between type library and symbol_addrs.txt
        for symbol in symbols:
            type = ida_typeinf.idc_get_type(symbol.addr)
            size = ida_bytes.get_item_size(symbol.addr)

            if symbol.type == 'data' and type != None and symbol.size != 0 and size != symbol.size:
                print(type + ' ' + symbol.name + ' size mismatch: ' + str(size) + ' vs ' + str(symbol.size))
                
                #TODO: Deal with pointer type?
                if '[' in type:
                    etype = type.split('[')[0]
                    esize = get_type_size(etype)
                    if esize > 0:
                        if (symbol.size % esize) == 0:
                            count = int(symbol.size/esize)
                            print('Applying new size: ' + etype + ' ' + symbol.name + '[' + str(count) + ']')
                            ida_bytes.del_items(symbol.addr, 0, symbol.size, None)
                            idc.SetType(symbol.addr, etype + '[' + str(count) + ']')
                            idc.make_array(symbol.addr, count)
                        else:
                            print('Failed to apply new size (size error)')
                    else:
                        print('Failed to apply new size (type not found: + ' + etype + ')')
                else:
                    esize = get_type_size(type)
                    if esize > 0:
                        if esize == symbol.size:
                            print('Applying new size: ' + type + ' ' + str(symbol.size))
                            ida_bytes.del_items(symbol.addr, 0, symbol.size, None)
                            idc.SetType(symbol.addr, type)
                        else:
                            print('Failed to apply new size (size error)')
                    else:
                        print('Failed to apply new size (type not found: + ' + type + ')')

            elif symbol.type == 'function':
                ret = ida_funcs.add_func(symbol.addr, ida_idaapi.BADADDR)
                for i in range(0, symbol.size, 4):
                    ida_ua.create_insn(symbol.addr + i)
    else:
        print('Failed to generate type library')
        print(result.stdout)
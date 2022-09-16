import ida_name
import ida_idaapi

#import ptvsd
#ptvsd.enable_attach()
#ptvsd.wait_for_attach()

def parse_symbol_addrs(file):
    f = open(file, 'r')
    lines = f.readlines()
    f.close() 

    symbols = {}
    for line in lines:
        s = line.split('=')
        if len(s) == 2:
            func = s[0].strip()
            addr = s[1].strip().split(';')[0]
            symbols[func] = int(addr, 16)

    return symbols

symbols = parse_symbol_addrs('symbol_addrs.txt')
for func, addr in symbols.items():
    ea = ida_name.get_name_ea(ida_idaapi.BADADDR, func)
    if ea != None:
        ida_name.del_global_name(ea)
    ida_name.set_name(addr, func)
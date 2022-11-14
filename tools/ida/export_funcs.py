import ida_funcs
import idautils

import ptvsd
ptvsd.enable_attach()
ptvsd.wait_for_attach()

f = open("funcs.txt", "w+")
for funcea in idautils.Functions():
    name = ida_funcs.get_func_name(funcea)
    if not (name.startswith('sub_') or name.startswith('nullsub_')):
        f.write(name + ' = ' + hex(funcea) + ';\n')
f.close()

#count = 0
#for funcea in idautils.Functions():
#    name = ida_funcs.get_func_name(funcea)
#    func = ida_funcs.get_fchunk(funcea)
#    size = ida_funcs.calc_func_size(func)
#    if (size / 4) > 500:
#        count += 1
#        print(name, size/4)
#print(str(count))
import ida_segment
import ida_name
import idautils
from splat.scripts import split

def xrefs(segment, section):
    name = '.' + segment.name + '.' + section
    f = open((name + '.txt'), 'w')
    s = ida_segment.get_segm_by_name(name)
    if s == None:
        return
    ea = s.start_ea
    while ea < s.end_ea:
        name = ida_name.get_ea_name(ea)
        if name != '' and not name.startswith('loc_') and not name.startswith('locret_'):
            f.write(name + ';')
            f.write(f'{ea:08X}' + ';')
            rom_addr = ea - segment.vram_start + segment.rom_start
            f.write(hex(rom_addr) + ';')
            min = 0x8FFFFFFF
            max = 0x80000000
            for xref in idautils.XrefsTo(ea):
                if xref.frm < min:
                    min = xref.frm
                if xref.frm > max:
                    max = xref.frm
            if min != 0x8FFFFFFF and max != 0x80000000:
                f.write(f'{min:08X}' + ';')
                f.write(f'{max:08X}' + ';')
                for subsegment in segment.subsegments:
                    if subsegment.type == 'c' or subsegment.type == 'hasm':
                        if min >= subsegment.vram_start and max < subsegment.vram_end:
                            f.write(subsegment.name)
            f.write('\n')
        ea += 1
    f.close()

# Load config
VERSION = 'us'
yaml = 'versions/'+VERSION+'/dukenukemzerohour.yaml'
with open(yaml) as f:
    config = split.yaml.load(f.read(), Loader=split.yaml.SafeLoader)
config['options']['base_path'] = '.'
split.options.initialize(config, yaml, None, None)
split.disassembler_instance.create_disassembler_instance(skip_version_check=True, splat_version='')
all_segments = split.initialize_segments(config["segments"])
for segment in all_segments:
    if segment.name == 'code0' or segment.name == 'code1':
        xrefs(segment, 'text')
        xrefs(segment, 'data')
        xrefs(segment, 'rodata')
        xrefs(segment, 'bss')
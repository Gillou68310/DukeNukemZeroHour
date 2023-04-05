import idaapi
import ida_auto
import ida_name
import ida_bytes
import ida_segment

def nameRegisterLocation(name, ea):
    ida_bytes.create_dword(ea, 1)
    ida_name.set_name(ea, name, 0)

def accept_file(fd, fname):
    ret = 0

    if type(fname) == str:
        fd.seek(0x20)
        name = fd.read(20)

        if name == b'DUKE NUKEM ZERO HOUR':
            ret = {"format" : "DUKE NUKEM ZERO HOUR", "processor" : "mipsr"}

    return ret

def load_file(fd, neflags, format):
    idaapi.set_processor_type("mipsr", idaapi.SETPROC_LOADER)

    fd.seek(0, idaapi.SEEK_END)
    romsize = fd.tell()
    fd.seek(0)

    # Create Segments
    ida_segment.add_segm(0, 0xA3F00000, 0xA3F00028, '.rdreg', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4000000, 0xA4001000, '.sp.dmem', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4001000, 0xA4002000, '.sp.imem', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4040000, 0xA4080008, '.spreg', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4100000, 0xA4100020, '.dpcreg', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4200000, 0xA4200010, '.dpsreg', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4300000, 0xA4300010, '.mireg', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4400000, 0xA4400038, '.vireg', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4500000, 0xA4500018, '.aireg', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4600000, 0xA4600034, '.pireg', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4700000, 0xA4700020, '.rireg', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA4800000, 0xA480001C, '.sireg', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA5000000, 0xA6000000, '.cartdom2addr1', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA6000000, 0xA8000000, '.cartdom1addr1', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xA8000000, 0xB0000000, '.cartdom2addr2', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xB0000000, 0xB0000000 + romsize, '.cartdom1addr2', 'DATA', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xBFC00000, 0xBFC007C0, '.pifrom', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0xBFC007C0, 0xBFC00800, '.pifram', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0x80000000, 0x80000400, '.ivt', 'CODE', ida_segment.ADDSEG_SPARSE)

    # Create Code Segment 0
    ida_segment.add_segm(0, 0x80000400, 0x800BD3D0, '.code0.text', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0x800BD3D0, 0x800E4400, '.code0.data', 'DATA', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0x800E4400, 0x800EA700, '.code0.rodata', 'CONST', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0x800EA700, 0x801C0D80, '.code0.bss', 'BSS', ida_segment.ADDSEG_SPARSE)

    # Create Code Segment 1
    ida_segment.add_segm(0, 0x801C0D80, 0x801CA140, '.code1.text', 'CODE', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0x801CA140, 0x801CBD20, '.code1.data', 'DATA', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0x801CBD20, 0x801CC7F0, '.code1.rodata', 'CONST', ida_segment.ADDSEG_SPARSE)
    ida_segment.add_segm(0, 0x801CC7F0, 0x801CF720, '.code1.bss', 'BSS', ida_segment.ADDSEG_SPARSE)

    # Create SP Segment 1
    ida_segment.add_segm(0, 0x01000000, 0x01000000+0x28F10, '.static.data', 'DATA', ida_segment.ADDSEG_SPARSE)

    # Update Segments permissions
    for n in range(ida_segment.get_segm_qty()):
        seg = ida_segment.getnseg(n)
        kind = ida_segment.get_segm_class(seg)
        if kind == 'CONST':
            seg.perm = idaapi.SEGPERM_READ
        elif kind == 'CODE':
            seg.perm = idaapi.SEGPERM_READ | idaapi.SEGPERM_EXEC
        elif kind == 'DATA':
            seg.perm = idaapi.SEGPERM_READ | idaapi.SEGPERM_WRITE
        elif kind == 'BSS':
            seg.perm = idaapi.SEGPERM_READ | idaapi.SEGPERM_WRITE
        ida_segment.update_segm(seg)
        
    # Load ROM to .cartdom1addr2
    fd.file2base(0, 0xB0000000, 0xB0000000+romsize, False)

    # Load IPL3 to sp.dmem
    fd.file2base(0, 0xA4000000, 0xA4000000+0x1000, False)

    # Load Code Segment 0
    fd.file2base(0x1000, 0x80000400, 0x80000400+0xEA300, False)
    idaapi.add_entry(0x80000400, 0x80000400, 'start', 1)
    ida_auto.auto_make_proc(0x80000400)

    # Load Code Segment 1
    fd.file2base(0xEB300, 0x801C0D80, 0x801C0D80+0xBA70, False)
    ida_auto.auto_make_proc(0x801C0D80)

    # Load SP Segment 1
    fd.file2base(0xF6D70, 0x01000000, 0x01000000+0x28F10, False)

    # Create DATA and Structures
    nameRegisterLocation('RDRAM_CONFIG_REG', 0xA3F00000)
    nameRegisterLocation('RDRAM_DEVICE_ID_REG', 0xA3F00004)
    nameRegisterLocation('RDRAM_DELAY_REG', 0xA3F00008)
    nameRegisterLocation('RDRAM_MODE_REG', 0xA3F0000C)
    nameRegisterLocation('RDRAM_REF_INTERVAL_REG', 0xA3F00010)
    nameRegisterLocation('RDRAM_REF_ROW_REG', 0xA3F00014)
    nameRegisterLocation('RDRAM_RAS_INTERVAL_REG', 0xA3F00018)
    nameRegisterLocation('RDRAM_MIN_INTERVAL_REG', 0xA3F0001C)
    nameRegisterLocation('RDRAM_ADDR_SELECT_REG', 0xA3F00020)
    nameRegisterLocation('RDRAM_DEVICE_MANUF_REG', 0xA3F00024)

    nameRegisterLocation('SP_MEM_ADDR_REG', 0xA4040000)
    nameRegisterLocation('SP_DRAM_ADDR_REG', 0xA4040004)
    nameRegisterLocation('SP_RD_LEN_REG', 0xA4040008)
    nameRegisterLocation('SP_WR_LEN_REG', 0xA404000C)
    nameRegisterLocation('SP_STATUS_REG', 0xA4040010)
    nameRegisterLocation('SP_DMA_FULL_REG', 0xA4040014)
    nameRegisterLocation('SP_DMA_BUSY_REG', 0xA4040018)
    nameRegisterLocation('SP_SEMAPHORE_REG', 0xA404001C)
    nameRegisterLocation('SP_PC_REG', 0xA4080000)
    nameRegisterLocation('SP_IBIST_REG', 0xA4080004)

    nameRegisterLocation('DPC_START_REG', 0xA4100000)
    nameRegisterLocation('DPC_END_REG', 0xA4100004)
    nameRegisterLocation('DPC_CURRENT_REG', 0xA4100008)
    nameRegisterLocation('DPC_STATUS_REG', 0xA410000C)
    nameRegisterLocation('DPC_CLOCK_REG', 0xA4100010)
    nameRegisterLocation('DPC_BUFBUSY_REG', 0xA4100014)
    nameRegisterLocation('DPC_PIPEBUSY_REG', 0xA4100018)
    nameRegisterLocation('DPC_TMEM_REG', 0xA410001C)

    nameRegisterLocation('DPS_TBIST_REG', 0xA4200000)
    nameRegisterLocation('DPS_TEST_MODE_REG', 0xA4200004)
    nameRegisterLocation('DPS_BUFTEST_ADDR_REG', 0xA4200008)
    nameRegisterLocation('DPS_BUFTEST_DATA_REG', 0xA420000C)

    nameRegisterLocation('MI_INIT_MODE_REG', 0xA4300000)
    nameRegisterLocation('MI_VERSION_REG', 0xA4300004)
    nameRegisterLocation('MI_INTR_REG', 0xA4300008)
    nameRegisterLocation('MI_INTR_MASK_REG', 0xA430000C)

    nameRegisterLocation('VI_STATUS_REG', 0xA4400000)
    nameRegisterLocation('VI_ORIGIN_REG', 0xA4400004)
    nameRegisterLocation('VI_WIDTH_REG', 0xA4400008)
    nameRegisterLocation('VI_INTR_REG', 0xA440000C)
    nameRegisterLocation('VI_CURRENT_REG', 0xA4400010)
    nameRegisterLocation('VI_BURST_REG', 0xA4400014)
    nameRegisterLocation('VI_V_SYNC_REG', 0xA4400018)
    nameRegisterLocation('VI_H_SYNC_REG', 0xA440001C)
    nameRegisterLocation('VI_LEAP_REG', 0xA4400020)
    nameRegisterLocation('VI_H_START_REG', 0xA4400024)
    nameRegisterLocation('VI_V_START_REG', 0xA4400028)
    nameRegisterLocation('VI_V_BURST_REG', 0xA440002C)
    nameRegisterLocation('VI_X_SCALE_REG', 0xA4400030)
    nameRegisterLocation('VI_Y_SCALE_REG', 0xA4400034)

    nameRegisterLocation('AI_DRAM_ADDR_REG', 0xA4500000)
    nameRegisterLocation('AI_LEN_REG', 0xA4500004)
    nameRegisterLocation('AI_CONTROL_REG', 0xA4500008)
    nameRegisterLocation('AI_STATUS_REG', 0xA450000C)
    nameRegisterLocation('AI_DACRATE_REG', 0xA4500010)
    nameRegisterLocation('AI_BITRATE_REG', 0xA4500014)

    nameRegisterLocation('PI_DRAM_ADDR_REG', 0xA4600000)
    nameRegisterLocation('PI_CART_ADDR_REG', 0xA4600004)
    nameRegisterLocation('PI_RD_LEN_REG', 0xA4600008)
    nameRegisterLocation('PI_WR_LEN_REG', 0xA460000C)
    nameRegisterLocation('PI_STATUS_REG', 0xA4600010)
    nameRegisterLocation('PI_BSD_DOM1_LAT_REG', 0xA4600014)
    nameRegisterLocation('PI_BSD_DOM1_PWD_REG', 0xA4600018)
    nameRegisterLocation('PI_BSD_DOM1_PGS_REG', 0xA460001C)
    nameRegisterLocation('PI_BSD_DOM1_RLS_REG', 0xA4600020)
    nameRegisterLocation('PI_BSD_DOM2_LAT_REG', 0xA4600024)
    nameRegisterLocation('PI_BSD_DOM2_PWD_REG', 0xA4600028)
    nameRegisterLocation('PI_BSD_DOM2_PGS_REG', 0xA460002C)
    nameRegisterLocation('PI_BSD_DOM2_RLS_REG', 0xA4600030)

    nameRegisterLocation('RI_MODE_REG', 0xA4700000)
    nameRegisterLocation('RI_CONFIG_REG', 0xA4700004)
    nameRegisterLocation('RI_CURRENT_LOAD_REG', 0xA4700008)
    nameRegisterLocation('RI_SELECT_REG', 0xA470000C)
    nameRegisterLocation('RI_REFRESH_REG', 0xA4700010)
    nameRegisterLocation('RI_LATENCY_REG', 0xA4700014)
    nameRegisterLocation('RI_RERROR_REG', 0xA4700018)
    nameRegisterLocation('RI_WERROR_REG', 0xA470001C)

    nameRegisterLocation('SI_DRAM_ADDR_REG', 0xA4800000)
    nameRegisterLocation('SI_PIF_ADDR_RD64B_REG', 0xA4800004)
    nameRegisterLocation('SI_PIF_ADDR_WR64B_REG', 0xA4800010)
    nameRegisterLocation('SI_STATUS_REG', 0xA4800018)

    return 1
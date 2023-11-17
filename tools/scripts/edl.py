import struct
from ctypes import cdll, pointer, create_string_buffer

class EDL:
    def __init__(self, debug=False):
        self.tablenum = 0
        self.debug = debug

        self._libc = cdll.LoadLibrary("tools/libEDL/build/libEDL.so")
        self._p_buffer = pointer(create_string_buffer(1048576))

        self._tbl1 = [0,1,2,3,4,5,6,7,8,0xA,0xC,0xE,0x10,0x14,0x18,0x1C,0x20,0x28,0x30,0x38,0x40,0x50,0x60,0x70,0x80,0xA0,0xC0,0xE0,0xFF,0,0,0]
        self._tbl2 = [0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,0,0,0,0]
        self._tbl3 = [0,1,2,3,4,6,8,0xC,0x10,0x18,0x20,0x30,0x40,0x60,0x80,0xC0,0x100,0x180,0x200,0x300,0x400,0x600,0x800,0xC00,0x1000,0x1800,0x2000,0x3000,0x4000,0x6000]
        self._tbl4 = [0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0xA,0xA,0xB,0xB,0xC,0xC,0xD,0xD,0,0]

    def _grab(self, data, bits=0, mode='read', order='big'):
        """Iterates stream data using either 'big' or 'little' endian order.
        The mode can be either 'read' or 'peek'.
        By default, n bits are read off of the stream and the stream is advanced.
        In 'peek' mode, the bits are read but the stream is not advanced."""
        i, c, b = 0, 0, 0
        while i<len(data):
            v = int.from_bytes(data[i:i+4], byteorder=order)
            v<<=c
            b|=v     # bitfield | new bits<<count
            c+=32    # count+=32
            i+=4
            while c>=bits or (i == len(data) and mode =='peek'):
                m = (1<<bits)-1 # mask
                v = b&m         # value = bitfield & mask
                if mode!='peek':
                    c-= bits        # count-= #bits
                    b>>=bits        # bitfield without said bits
                bits, mode = yield v  # yield the value, retrieving next #bits

    def _fillBuffer(self, buffer, num, count, size):
        """Returns a buffer filled with bitdata.
        Original entry format:
            000F    bitcount
            FF80    data

            When bitcount == 0, entry is a backtrack.
            0070    backtrack bitcount
            FF80    data
            """
        self.tablenum += 1
        self._dump_table("what", buffer, num , 4)

        # initialize buffers
        when = list(bytes(count))
        samp = list(bytes(count))
        b    = list(bytes(1<<size))
        n    = list(bytes(16))
        table= list(bytes(0x600))
##        when, samp, n, b, table = [], [], [], [], []
##        for i in range(count):
##            when.append(0)
##            samp.append(0)
##        for i in range(1<<size):
##            b.append(0)
##        for i in range(16):
##            n.append(0)
##        for i in range(0x600):
##            table.append(0)

        # build occurance table, sorted by bits
        i=0
        for y in range(1,16):
            for x in range(num):
                if buffer[x]==y:
                    when[i]=x
                    i+=1
                    n[y]+=1
        
        self._dump_table("when", when, count, 4)

        # set counts in the buffer
        i=0
        for y in range(1,16):
            for x in range(n[y]):
                buffer[i]=y
                i+=1
        del n

        self._dump_table("order", buffer, count, 4)

        # generate bitsample table
        z, back = buffer[0], 0
        for x in range(count):
            y = buffer[x]
            if y!=z:
                z = y-z
                back*=(1<<z)
                z=y
            y = (1<<y) | back
            back+=1
            while True:
                samp[x]<<=1
                samp[x]+=(y&1)
                # Enforce short value.
                samp[x]&=0xFFFF
                y>>=1
                if y==1:
                    break

        self._dump_table("samples", samp, count, 4)

        # fills temp buffer with formatted bitsamples
        for x in range(count):
            back = buffer[x]
            if back<size:
                y = 1<<back
                z = samp[x]
                while True:
                    table[z] = (when[x]<<7) + buffer[x]
                    z+=y
                    if (z>>size):
                        break
            else:
                y = (1<<size)-1
                z = samp[x]&y
                b[z] = buffer[x]

        self._dump_table("table1", table, 1<<size, 2)
        self._dump_table("buf", b, 1<<size, 1)

        # Read coded types > size
        z, x = 0, 0
        while not (x>>size):
            y = b[x]
            if y:
                y-=size
                if y>8:
                    return None
                back = (z<<7) + (y<<4)
                table[x] = back
                z+=(1<<y)
            x+=1
        del b
        if z>0x1FF:
            return None

        self._dump_table("table2", table, 1<<size, 2)

        # Aliased entries
        back = 1<<size
        for x in range(count):
            if buffer[x]<size:
                continue
            z = samp[x] & (back-1)
            z = table[z]
            y = samp[x]>>size
            while True:
                i = y + (z>>7) + (1<<size)
                table[i] = (when[x]<<7) + buffer[x]
                i = buffer[x]-size
                y+= (1<<i)
                i = (z>>4)&7
                if (y>>i):
                    break

        self._dump_table("table3", table, (1<<size)+0x200, 2)
        del samp
        del when
        return table

    def _header(self, data):
        """Retrieves format and swapping from header.
        Returns type(0-2), endianness (str), compressed size, decompressed size"""
        name = data[0:3].decode(errors='ignore')
        if name!="EDL":
            return -1, None, 0, 0
        ## work out byte order and format
        data_t = data[3]
        endian = "big" if data_t&0x80 else "little"
        data_t&=0xF
        if data_t>1:
            print("\tError: compression type {} not supported!\n".format(data_t), ('warning'))
            return -1, None, 0, 0
        ## grab compressed and decompressed sizes
        cmp_s = int.from_bytes(data[4:8], byteorder=endian)
        dec_s = int.from_bytes(data[8:12],byteorder=endian)
        return data_t, endian, cmp_s, dec_s

    def _decEDL0(self, data, cmp_s, dec_s, *args):
        """Store: copy data to output.
        Data should be actual start of compressed data."""
        sz = dec_s if cmp_s>dec_s else cmp_s
        return data[0:sz]

    def _decEDL1(self, data, cmp_s, dec_s, endian, *args):
        """LZW variant: generate bittables and decompress."""
        output = bytearray()
        # initialize the data stream
        d = self._grab(data, order=endian)
        next(d)
        stack = 0

        #alternates between raw and compressed output
        small, large = [], []
        while len(output)<dec_s:
            if d.send((1, 'read')):
                # yeah, should probably use a subroutine...
                # large table
                x = d.send((9, 'read'))
                if x:
                    # build an empty buffer
                    buf = list(bytes(x))
                    # iterate to grab entries
                    c = 0
                    for i in range(x):
                        if d.send((1, 'read')):
                            stack = d.send((4, 'read'))
                        buf[i] = stack
                        # count nonzero entries
                        if stack:
                            c+=1
                    large = self._fillBuffer(buf,x,c,10)
                # small table
                x = d.send((9, 'read'))
                if x:
                    # build an empty buffer
                    buf = list(bytes(x))
                    # iterate to grab entries
                    c = 0
                    for i in range(x):
                        if d.send((1, 'read')):
                            stack = d.send((4, 'read'))
                        buf[i] = stack
                        # count nonzero entries
                        if stack:
                            c+=1
                    small = self._fillBuffer(buf,x,c,8)
                # write data using tables
                x = 0
                while x!=0x100:
                    x = large[d.send((10, 'peek'))]
                    if not (x&0xF):
                        # grab reference
                        m = (x>>4)&7
                        x>>=7
                        v = d.send((10+m, 'peek'))
                        v>>=10
                        x = large[x + v +0x400]
                    # Advance the stream the appropriate bitcount
                    b = x&0xF
                    d.send((b, 'read'))
                    x>>=7
                    if x<0x100:     # Write byte to output
                        output.append(x)
                    elif x>0x100:   # Copy previous
                        # Determine length
                        l = 0
                        z = self._tbl2[x-0x101]
                        if z:
                            l = d.send((z, 'read'))
                        l+= self._tbl1[x-0x101] + 3
                        # Determine backtrack
                        x = small[d.send((8, 'peek'))]
                        if not (x&0xF):
                            # grab reference
                            m = (x&0x70)>>4
                            x>>=7
                            v = d.send((8+m, 'peek'))
                            v>>=8
                            x = small[x + v +0x100]
                        # Advance the stream the appropriate bits.
                        b = x&0xF
                        d.send((b, 'read'))
                        # Position from next sample
                        p = 0
                        x>>=7
                        z = self._tbl4[x]
                        if z:
                            p = d.send((z, 'read'))
                        p+= self._tbl3[x] + 1
                        # Copy and append l bytes from cur-p
                        p = len(output)-p
                        for i in range(l):
                            v = output[p+i] if (0<=(p+i)<len(output)) else 0
                            output.append(v)
            else:
                # direct write
                num = d.send((15, 'read'))
                for i in range(num):
                    output.append(d.send((8, 'read')))

            # EOF mark is a set bit
            if d.send((1, 'read')):
                break

        return output
    
    def decompress_libEDL(self, data):
        data_t, endian, cmp_s, dec_s = self._header(data)
        if data_t == -1:
            return data
        ret = self._libc.decompressEDL(data, self._p_buffer)
        assert(ret == 0)
        return self._p_buffer.contents[0:dec_s]

    def decompress_pyEDL(self, data):
        data_t, endian, cmp_s, dec_s = self._header(data)
        if data_t == 0:
            d = self._decEDL0(data[12:12+cmp_s], cmp_s, dec_s, endian)
        if data_t == 1:
            d = self._decEDL1(data[12:12+cmp_s], cmp_s, dec_s, endian)
            assert(len(d) == dec_s)
        elif data_t == -1:
            return data
        else:
            print("This feature not yet implemented!")
            return
        return d
    
    def _dump_table(self, name, data, size, bytecount):
        if not self.debug:
            return
        f = open(name+f"{self.tablenum:04x}"+".bin", 'wb')
        for i in range(0, size):
            if bytecount == 1:
                d = struct.pack('>B', data[i])
            elif bytecount == 2:
                d = struct.pack('>H', data[i])
            elif bytecount == 4:
                d = struct.pack('>I', data[i])
            f.write(d)
        f.close()

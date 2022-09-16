#ifndef _TYPES_H_
#define _TYPES_H_

typedef f32 Matrix4f[4][4];

/// Linker symbol address, as in `ld_addrs.h`.
typedef u8 Addr[];

#define va_arg(AP,TYPE) (AP = (__gnuc_va_list) ((char *) (AP) + __va_rounded_size (TYPE)), *((TYPE *) (void *) ((char *) (AP) - ((sizeof (TYPE) < __va_rounded_size (char) ? sizeof (TYPE) : __va_rounded_size (TYPE))))))

#endif

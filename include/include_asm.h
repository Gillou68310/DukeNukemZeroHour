#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#if !defined(SPLAT) && !defined(__CTX__) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
#define __INCLUDE_ASM__(FOLDER, NAME) \
   __asm__( \
        ".section .text\n" \
        "\t.set noat\n" \
        "\t.set noreorder\n" \
        "\t.align\t2\n" \
        "\t.globl\t"#NAME"\n" \
        "\t.type "#NAME", @function\n" \
        "\t.ent\t"#NAME"\n" \
        #NAME ":\n" \
        "\t.include \""FOLDER"/"#NAME".s\"\n" \
        "\t.set reorder\n" \
        "\t.set at\n" \
        "\t.end\t"#NAME"\n" \
        ".end"#NAME":\n" \
        "\t.size\t"#NAME",.end"#NAME"-"#NAME \
    )
#if VERSION_US
#define INCLUDE_ASM(FOLDER, NAME) __INCLUDE_ASM__("asm/us/nonmatchings/"FOLDER, NAME)
#elif VERSION_FR
#define INCLUDE_ASM(FOLDER, NAME) __INCLUDE_ASM__("asm/fr/nonmatchings/"FOLDER, NAME)
#elif VERSION_EU
#define INCLUDE_ASM(FOLDER, NAME) __INCLUDE_ASM__("asm/eu/nonmatchings/"FOLDER, NAME)
#endif
#endif
#ifndef INCLUDE_RODATA
#define __INCLUDE_RODATA__(FOLDER, NAME) \
   __asm__( \
        ".section .rodata\n" \
        "\t.include \""FOLDER"/"#NAME".s\"\n" \
        ".section .text" \
    )
#if VERSION_US
#define INCLUDE_RODATA(FOLDER, NAME) __INCLUDE_RODATA__("asm/us/nonmatchings/"FOLDER, NAME)
#elif VERSION_FR
#define INCLUDE_RODATA(FOLDER, NAME) __INCLUDE_RODATA__("asm/fr/nonmatchings/"FOLDER, NAME)
#elif VERSION_EU
#define INCLUDE_RODATA(FOLDER, NAME) __INCLUDE_RODATA__("asm/eu/nonmatchings/"FOLDER, NAME)
#endif
#endif
#ifndef FORCE_ASM
#define FORCE_ASM(A) __asm__(A)
#endif
__asm__(".include \"include/macro.inc\"\n");
#else
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
#define FORCE_ASM(A)
#endif


#endif

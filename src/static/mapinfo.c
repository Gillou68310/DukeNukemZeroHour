#include "common.h"
#include "ld_symbols.h"
#include "static/mapinfo.h"

/*.data*/

/*01025D00*/
MapInfo gMapInfo[MAP_NUM] = {
    {
        maps_map1_ROM_START,
        maps_map1_ROM_END,
        (s32)maps_map1_sectors_bin,
        (s32)maps_map1_walls_bin,
        (s32)maps_map1_sprites_bin,
        0x280,
        0x486,
        0xDF7,
        -0x2890,
        -0x289E,
        0x40,
        0x476,
        178.0f,
        211.0f,
        255.0f,
        51.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map2_ROM_START,
        maps_map2_ROM_END,
        (s32)maps_map2_sectors_bin,
        (s32)maps_map2_walls_bin,
        (s32)maps_map2_sprites_bin,
        0x236,
        0x4F1,
        0xDC3,
        0x21DC,
        0x414B,
        0xA20,
        0x5FF,
        132.0f,
        204.0f,
        255.0f,
        122.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map3_ROM_START,
        maps_map3_ROM_END,
        (s32)maps_map3_sectors_bin,
        (s32)maps_map3_walls_bin,
        (s32)maps_map3_sprites_bin,
        0x262,
        0x4E9,
        0xE80,
        0x2BCD,
        -0x57E8,
        0x3C00,
        0x7C0,
        79.0f,
        142.0f,
        255.0f,
        155.0f,
        28.0f,
        112.0f,
    },
    {
        maps_map4_ROM_START,
        maps_map4_ROM_END,
        (s32)maps_map4_sectors_bin,
        (s32)maps_map4_walls_bin,
        (s32)maps_map4_sprites_bin,
        0x185,
        0x26B,
        0xAAD,
        -0x2392,
        -0x35AA,
        0x20,
        0x30B,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map5_ROM_START,
        maps_map5_ROM_END,
        (s32)maps_map5_sectors_bin,
        (s32)maps_map5_walls_bin,
        (s32)maps_map5_sprites_bin,
        0x20E,
        0x3CA,
        0xBDA,
        0x11BB,
        0x741C,
        -0xA90,
        0x62D,
        79.0f,
        96.0f,
        255.0f,
        232.0f,
        33.0f,
        211.0f,
    },
    {
        maps_map6_ROM_START,
        maps_map6_ROM_END,
        (s32)maps_map6_sectors_bin,
        (s32)maps_map6_walls_bin,
        (s32)maps_map6_sprites_bin,
        0x22C,
        0x476,
        0xD28,
        -0x3927,
        0x15BC,
        -0x1817,
        0x3F2,
        79.0f,
        114.0f,
        249.0f,
        232.0f,
        107.0f,
        249.0f,
    },
    {
        maps_map7_ROM_START,
        maps_map7_ROM_END,
        (s32)maps_map7_sectors_bin,
        (s32)maps_map7_walls_bin,
        (s32)maps_map7_sprites_bin,
        0x5F,
        0x122,
        0x265,
        0x4C26,
        -0x13E0,
        -0x3573,
        0x6AF,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map8_ROM_START,
        maps_map8_ROM_END,
        (s32)maps_map8_sectors_bin,
        (s32)maps_map8_walls_bin,
        (s32)maps_map8_sprites_bin,
        0x218,
        0x4D0,
        0xE67,
        -0x5074,
        -0x2017,
        -0x2C,
        0x1F4,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map9_ROM_START,
        maps_map9_ROM_END,
        (s32)maps_map9_sectors_bin,
        (s32)maps_map9_walls_bin,
        (s32)maps_map9_sprites_bin,
        0x271,
        0x530,
        0xD91,
        -0x7BE,
        -0x33EA,
        -0x2C0,
        0x649,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map10_ROM_START,
        maps_map10_ROM_END,
        (s32)maps_map10_sectors_bin,
        (s32)maps_map10_walls_bin,
        (s32)maps_map10_sprites_bin,
        0x252,
        0x3EB,
        0xE80,
        0x47E7,
        0x4A79,
        0x500,
        0x188,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map11_ROM_START,
        maps_map11_ROM_END,
        (s32)maps_map11_sectors_bin,
        (s32)maps_map11_walls_bin,
        (s32)maps_map11_sprites_bin,
        0x230,
        0x44F,
        0xE76,
        0x3983,
        0x476F,
        0x356,
        0x2E9,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map12_ROM_START,
        maps_map12_ROM_END,
        (s32)maps_map12_sectors_bin,
        (s32)maps_map12_walls_bin,
        (s32)maps_map12_sprites_bin,
        0x236,
        0x44D,
        0xE7E,
        -0x350E,
        0x589A,
        0x19CA,
        0x1DD,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map13_ROM_START,
        maps_map13_ROM_END,
        (s32)maps_map13_sectors_bin,
        (s32)maps_map13_walls_bin,
        (s32)maps_map13_sprites_bin,
        0x3C,
        0xC2,
        0x262,
        0x962,
        0x46B7,
        0x2F3,
        0x5E1,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map14_ROM_START,
        maps_map14_ROM_END,
        (s32)maps_map14_sectors_bin,
        (s32)maps_map14_walls_bin,
        (s32)maps_map14_sprites_bin,
        0x26F,
        0x504,
        0xF2F,
        0x379D,
        -0xC5,
        0x20,
        0x77C,
        0.0f,
        0.0f,
        255.0f,
        219.0f,
        255.0f,
        255.0f,
    },
    {
        maps_map15_ROM_START,
        maps_map15_ROM_END,
        (s32)maps_map15_sectors_bin,
        (s32)maps_map15_walls_bin,
        (s32)maps_map15_sprites_bin,
        0x270,
        0x48D,
        0xE83,
        -0x3D5D,
        -0x1F1B,
        -0x400,
        0x596,
        35.0f,
        96.0f,
        255.0f,
        219.0f,
        247.0f,
        255.0f,
    },
    {
        maps_map16_ROM_START,
        maps_map16_ROM_END,
        (s32)maps_map16_sectors_bin,
        (s32)maps_map16_walls_bin,
        (s32)maps_map16_sprites_bin,
        0x1B4,
        0x2C9,
        0xB3C,
        -0xF12,
        0x9C0,
        0x1720,
        4,
        56.0f,
        96.0f,
        249.0f,
        219.0f,
        247.0f,
        255.0f,
    },
    {
        maps_map17_ROM_START,
        maps_map17_ROM_END,
        (s32)maps_map17_sectors_bin,
        (s32)maps_map17_walls_bin,
        (s32)maps_map17_sprites_bin,
        0x1FD,
        0x2C2,
        0xDCC,
        0x2058,
        -0x356A,
        0x440,
        0x5F8,
        79.0f,
        114.0f,
        249.0f,
        232.0f,
        107.0f,
        249.0f,
    },
    {
        maps_map18_ROM_START,
        maps_map18_ROM_END,
        (s32)maps_map18_sectors_bin,
        (s32)maps_map18_walls_bin,
        (s32)maps_map18_sprites_bin,
        0x20B,
        0x37A,
        0xDB4,
        -0x2A4A,
        0x463F,
        -0x1A20,
        0x5F5,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map19_ROM_START,
        maps_map19_ROM_END,
        (s32)maps_map19_sectors_bin,
        (s32)maps_map19_walls_bin,
        (s32)maps_map19_sprites_bin,
        0xDE,
        0x1A0,
        0x608,
        0x9A8,
        -0x44F,
        -0x9C0,
        0x3F4,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map20_ROM_START,
        maps_map20_ROM_END,
        (s32)maps_map20_sectors_bin,
        (s32)maps_map20_walls_bin,
        (s32)maps_map20_sprites_bin,
        0x1BE,
        0x398,
        0xAD1,
        -0x3E6D,
        0x65EC,
        0xF1,
        0x612,
        132.0f,
        204.0f,
        255.0f,
        122.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map21_ROM_START,
        maps_map21_ROM_END,
        (s32)maps_map21_sectors_bin,
        (s32)maps_map21_walls_bin,
        (s32)maps_map21_sprites_bin,
        0x242,
        0x3DD,
        0xE73,
        -0xCE,
        -0x29A3,
        -0x3220,
        0x731,
        255.0f,
        204.0f,
        132.0f,
        122.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map22_ROM_START,
        maps_map22_ROM_END,
        (s32)maps_map22_sectors_bin,
        (s32)maps_map22_walls_bin,
        (s32)maps_map22_sprites_bin,
        0x6A,
        0x147,
        0x33F,
        -0xDC8,
        0x3F90,
        -0x9AF,
        0x6DC,
        255.0f,
        204.0f,
        132.0f,
        122.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map23_ROM_START,
        maps_map23_ROM_END,
        (s32)maps_map23_sectors_bin,
        (s32)maps_map23_walls_bin,
        (s32)maps_map23_sprites_bin,
        0x46,
        0xA5,
        0x160,
        -0x816,
        -0x1553,
        0x82C,
        0x5AA,
        255.0f,
        204.0f,
        132.0f,
        122.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map24_ROM_START,
        maps_map24_ROM_END,
        (s32)maps_map24_sectors_bin,
        (s32)maps_map24_walls_bin,
        (s32)maps_map24_sprites_bin,
        0x147,
        0x263,
        0x752,
        -0x15C1,
        0x30E,
        -0x2E40,
        0x300,
        178.0f,
        211.0f,
        255.0f,
        51.0f,
        0.0f,
        0.0f,
    },
    {
        maps_map25_ROM_START,
        maps_map25_ROM_END,
        (s32)maps_map25_sectors_bin,
        (s32)maps_map25_walls_bin,
        (s32)maps_map25_sprites_bin,
        0x2A,
        0x5A,
        0xCE,
        0x33FE,
        0x3814,
        0x2024,
        0x5FD,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map26_ROM_START,
        maps_map26_ROM_END,
        (s32)maps_map26_sectors_bin,
        (s32)maps_map26_walls_bin,
        (s32)maps_map26_sprites_bin,
        0x77,
        0x8D,
        0x2C2,
        -0x391C,
        0x47B,
        -0xD,
        0x5F4,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map27_ROM_START,
        maps_map27_ROM_END,
        (s32)maps_map27_sectors_bin,
        (s32)maps_map27_walls_bin,
        (s32)maps_map27_sprites_bin,
        0x36,
        0x43,
        0x166,
        0x312F,
        0x54E0,
        0x40,
        0x48C,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map28_ROM_START,
        maps_map28_ROM_END,
        (s32)maps_map28_sectors_bin,
        (s32)maps_map28_walls_bin,
        (s32)maps_map28_sprites_bin,
        0x45,
        0x9C,
        0x221,
        0x26FA,
        -0x2C11,
        0x40,
        0x3FE,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map29_ROM_START,
        maps_map29_ROM_END,
        (s32)maps_map29_sectors_bin,
        (s32)maps_map29_walls_bin,
        (s32)maps_map29_sprites_bin,
        0x2B,
        0x48,
        0x131,
        0x422F,
        0x30F5,
        -0x2E0,
        0x401,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map30_ROM_START,
        maps_map30_ROM_END,
        (s32)maps_map30_sectors_bin,
        (s32)maps_map30_walls_bin,
        (s32)maps_map30_sprites_bin,
        0xA8,
        0x85,
        0x45F,
        0x4A55,
        0x32AB,
        0x18A,
        0x4FF,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map31_ROM_START,
        maps_map31_ROM_END,
        (s32)maps_map31_sectors_bin,
        (s32)maps_map31_walls_bin,
        (s32)maps_map31_sprites_bin,
        0x7A,
        0x41,
        0x2FF,
        0x4BF6,
        0x3927,
        -0x11B0,
        0x3ED,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map32_ROM_START,
        maps_map32_ROM_END,
        (s32)maps_map32_sectors_bin,
        (s32)maps_map32_walls_bin,
        (s32)maps_map32_sprites_bin,
        0x30,
        0x31,
        0x164,
        0x24,
        0x120A,
        0x1E5,
        0x41D,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map33_ROM_START,
        maps_map33_ROM_END,
        (s32)maps_map33_sectors_bin,
        (s32)maps_map33_walls_bin,
        (s32)maps_map33_sprites_bin,
        0xA2,
        0x22,
        0x2B8,
        -0x2A0B,
        -0x1FE2,
        -0x5E0,
        0x4CA,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map34_ROM_START,
        maps_map34_ROM_END,
        (s32)maps_map34_sectors_bin,
        (s32)maps_map34_walls_bin,
        (s32)maps_map34_sprites_bin,
        0xC1,
        0x3B,
        0x3C3,
        0x341F,
        0x4AB0,
        0x680,
        0x55B,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map35_ROM_START,
        maps_map35_ROM_END,
        (s32)maps_map35_sectors_bin,
        (s32)maps_map35_walls_bin,
        (s32)maps_map35_sprites_bin,
        0x3A,
        0x62,
        0x1BC,
        0x475B,
        0x2F6D,
        0x40,
        0x5E0,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map36_ROM_START,
        maps_map36_ROM_END,
        (s32)maps_map36_sectors_bin,
        (s32)maps_map36_walls_bin,
        (s32)maps_map36_sprites_bin,
        0x4F,
        0x5A,
        0x288,
        0x4C88,
        0x47D1,
        0x359,
        0x603,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map37_ROM_START,
        maps_map37_ROM_END,
        (s32)maps_map37_sectors_bin,
        (s32)maps_map37_walls_bin,
        (s32)maps_map37_sprites_bin,
        0x37,
        0x72,
        0x191,
        0x56BE,
        0x469E,
        0x1C8,
        0x5DB,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        maps_map38_ROM_START,
        maps_map38_ROM_END,
        (s32)maps_map38_sectors_bin,
        (s32)maps_map38_walls_bin,
        (s32)maps_map38_sprites_bin,
        0x25,
        0x2B,
        0x108,
        -0x16F4,
        0x18F9,
        0x843,
        0x5F6,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
};

/*.text*/

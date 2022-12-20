#include "common.h"
#include "static/mapinfo.h"

/*.data*/

/*01025D00*/
MapInfo gMapInfo[MAPNUM] = {
    {
        (u8 *)0xDEB7C0,
        (u8 *)0xE04350,
        0x13010,
        0x7CA0,
        0x15454,
        0x280,
        0x486,
        0xDF7,
        -0x2890,
        -0x289E,
        0x40,
        0,
        0x476,
        178.0f,
        211.0f,
        255.0f,
        51.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xE04350,
        (u8 *)0xE1E280,
        0x143C8,
        0xA2C0,
        0x16500,
        0x236,
        0x4F1,
        0xDC3,
        0x21DC,
        0x414B,
        0xA20,
        0,
        0x5FF,
        132.0f,
        204.0f,
        255.0f,
        122.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xE1E280,
        (u8 *)0xE39630,
        0x15314,
        0x9850,
        0x17858,
        0x262,
        0x4E9,
        0xE80,
        0x2BCD,
        -0x57E8,
        0x3C00,
        0,
        0x7C0,
        79.0f,
        142.0f,
        255.0f,
        155.0f,
        28.0f,
        112.0f,
    },
    {
        (u8 *)0xE6D430,
        (u8 *)0xE7FF40,
        0xF5EC,
        0x7A60,
        0x10D30,
        0x185,
        0x26B,
        0xAAD,
        -0x2392,
        -0x35AA,
        0x20,
        0,
        0x30B,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xE39630,
        (u8 *)0xE50950,
        0x124A4,
        0x9320,
        0x14398,
        0x20E,
        0x3CA,
        0xBDA,
        0x11BB,
        0x741C,
        -0xA90,
        0,
        0x62D,
        79.0f,
        96.0f,
        255.0f,
        232.0f,
        33.0f,
        211.0f,
    },
    {
        (u8 *)0xE50950,
        (u8 *)0xE68CE0,
        0x12CD8,
        0x8FF0,
        0x14C58,
        0x22C,
        0x476,
        0xD28,
        -0x3927,
        0x15BC,
        -0x1817,
        0,
        0x3F2,
        79.0f,
        114.0f,
        249.0f,
        232.0f,
        107.0f,
        249.0f,
    },
    {
        (u8 *)0xE68CE0,
        (u8 *)0xE6D430,
        0x3548,
        0x1A40,
        0x3AB0,
        0x5F,
        0x122,
        0x265,
        0x4C26,
        -0x13E0,
        -0x3573,
        0,
        0x6AF,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xE7FF40,
        (u8 *)0xE9A200,
        0x14784,
        0x9260,
        0x16790,
        0x218,
        0x4D0,
        0xE67,
        -0x5074,
        -0x2017,
        -0x2C,
        0,
        0x1F4,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xE9A200,
        (u8 *)0xEB2140,
        0x12864,
        0x8A30,
        0x148B4,
        0x271,
        0x530,
        0xD91,
        -0x7BE,
        -0x33EA,
        -0x2C0,
        0,
        0x649,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xEB2140,
        (u8 *)0xECBB60,
        0x14C24,
        0x9870,
        0x16E30,
        0x252,
        0x3EB,
        0xE80,
        0x47E7,
        0x4A79,
        0x500,
        0,
        0x188,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xEEAC50,
        (u8 *)0xF041A0,
        0x14460,
        0x8820,
        0x16438,
        0x230,
        0x44F,
        0xE76,
        0x3983,
        0x476F,
        0x356,
        0,
        0x2E9,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xECBB60,
        (u8 *)0xEEAC50,
        0x19CCC,
        0xE5F0,
        0x1BD00,
        0x236,
        0x44D,
        0xE7E,
        -0x350E,
        0x589A,
        0x19CA,
        0,
        0x1DD,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xF041A0,
        (u8 *)0xF091C0,
        0x4284,
        0x26A0,
        0x46EC,
        0x3C,
        0xC2,
        0x262,
        0x962,
        0x46B7,
        0x2F3,
        0,
        0x5E1,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xF091C0,
        (u8 *)0xF251C0,
        0x15C78,
        0xA580,
        0x17F7C,
        0x26F,
        0x504,
        0xF2F,
        0x379D,
        -0xC5,
        0x20,
        0,
        0x77C,
        0.0f,
        0.0f,
        255.0f,
        219.0f,
        255.0f,
        255.0f,
    },
    {
        (u8 *)0xF251C0,
        (u8 *)0xF3D490,
        0x12B2C,
        0x78F0,
        0x14C74,
        0x270,
        0x48D,
        0xE83,
        -0x3D5D,
        -0x1F1B,
        -0x400,
        0,
        0x596,
        35.0f,
        96.0f,
        255.0f,
        219.0f,
        247.0f,
        255.0f,
    },
    {
        (u8 *)0xF3D490,
        (u8 *)0xF50DD0,
        0xF9B0,
        0x77A0,
        0x11410,
        0x1B4,
        0x2C9,
        0xB3C,
        -0xF12,
        0x9C0,
        0x1720,
        0,
        4,
        56.0f,
        96.0f,
        249.0f,
        219.0f,
        247.0f,
        255.0f,
    },
    {
        (u8 *)0xF691C0,
        (u8 *)0xF81640,
        0x14284,
        0x9C90,
        0x16004,
        0x1FD,
        0x2C2,
        0xDCC,
        0x2058,
        -0x356A,
        0x440,
        0,
        0x5F8,
        79.0f,
        114.0f,
        249.0f,
        232.0f,
        107.0f,
        249.0f,
    },
    {
        (u8 *)0xF50DD0,
        (u8 *)0xF691C0,
        0x13B7C,
        0x9B00,
        0x15924,
        0x20B,
        0x37A,
        0xDB4,
        -0x2A4A,
        0x463F,
        -0x1A20,
        0,
        0x5F5,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xF81640,
        (u8 *)0xF8D4D0,
        0x9EAC,
        0x57E0,
        0xAB14,
        0xDE,
        0x1A0,
        0x608,
        0x9A8,
        -0x44F,
        -0x9C0,
        0,
        0x3F4,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xF8D4D0,
        (u8 *)0xFA0070,
        0xE954,
        0x6740,
        0x10348,
        0x1BE,
        0x398,
        0xAD1,
        -0x3E6D,
        0x65EC,
        0xF1,
        0,
        0x612,
        132.0f,
        204.0f,
        255.0f,
        122.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xFA0070,
        (u8 *)0xFBAAB0,
        0x15818,
        0xB120,
        0x17B08,
        0x242,
        0x3DD,
        0xE73,
        -0xCE,
        -0x29A3,
        -0x3220,
        0,
        0x731,
        255.0f,
        204.0f,
        132.0f,
        122.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xFBAAB0,
        (u8 *)0xFBFF20,
        0x4070,
        0x1C00,
        0x46BC,
        0x6A,
        0x147,
        0x33F,
        -0xDC8,
        0x3F90,
        -0x9AF,
        0,
        0x6DC,
        255.0f,
        204.0f,
        132.0f,
        122.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xFBFF20,
        (u8 *)0xFC2790,
        0x1DD8,
        0xE80,
        0x2148,
        0x46,
        0xA5,
        0x160,
        -0x816,
        -0x1553,
        0x82C,
        0,
        0x5AA,
        255.0f,
        204.0f,
        132.0f,
        122.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xFF6B20,
        (u8 *)0x01003A60,
        0xA510,
        0x4EC0,
        0xB574,
        0x147,
        0x263,
        0x752,
        -0x15C1,
        0x30E,
        -0x2E40,
        0,
        0x300,
        178.0f,
        211.0f,
        255.0f,
        51.0f,
        0.0f,
        0.0f,
    },
    {
        (u8 *)0xFC2790,
        (u8 *)0xFC3F00,
        0x11F8,
        0x8D0,
        0x1414,
        0x2A,
        0x5A,
        0xCE,
        0x33FE,
        0x3814,
        0x2024,
        0,
        0x5FD,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFC3F00,
        (u8 *)0xFC9C10,
        0x4F0C,
        0x2BD0,
        0x5658,
        0x77,
        0x8D,
        0x2C2,
        -0x391C,
        0x47B,
        -0xD,
        0,
        0x5F4,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFC9C10,
        (u8 *)0xFCBFB0,
        0x1DA0,
        0xEF0,
        0x20B0,
        0x36,
        0x43,
        0x166,
        0x312F,
        0x54E0,
        0x40,
        0,
        0x48C,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFCBFB0,
        (u8 *)0xFCECC0,
        0x2310,
        0xDC0,
        0x26E4,
        0x45,
        0x9C,
        0x221,
        0x26FA,
        -0x2C11,
        0x40,
        0,
        0x3FE,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFCECC0,
        (u8 *)0xFD11F0,
        0x1F64,
        0x11A0,
        0x21E4,
        0x2B,
        0x48,
        0x131,
        0x422F,
        0x30F5,
        -0x2E0,
        0,
        0x401,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFD11F0,
        (u8 *)0xFD7CB0,
        0x5A30,
        0x2680,
        0x6450,
        0xA8,
        0x85,
        0x45F,
        0x4A55,
        0x32AB,
        0x18A,
        0,
        0x4FF,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFD7CB0,
        (u8 *)0xFDCC10,
        0x4534,
        0x2380,
        0x4C1C,
        0x7A,
        0x41,
        0x2FF,
        0x4BF6,
        0x3927,
        -0x11B0,
        0,
        0x3ED,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFDCC10,
        (u8 *)0xFDF5A0,
        0x24B4,
        0x1540,
        0x2748,
        0x30,
        0x31,
        0x164,
        0x24,
        0x120A,
        0x1E5,
        0,
        0x41D,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFDF5A0,
        (u8 *)0xFE3A60,
        0x3B48,
        0x1D00,
        0x4300,
        0xA2,
        0x22,
        0x2B8,
        -0x2A0B,
        -0x1FE2,
        -0x5E0,
        0,
        0x4CA,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFE3A60,
        (u8 *)0xFE9C20,
        0x56AC,
        0x2960,
        0x5F38,
        0xC1,
        0x3B,
        0x3C3,
        0x341F,
        0x4AB0,
        0x680,
        0,
        0x55B,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFE9C20,
        (u8 *)0xFECB90,
        0x2714,
        0x1510,
        0x2B14,
        0x3A,
        0x62,
        0x1BC,
        0x475B,
        0x2F6D,
        0x40,
        0,
        0x5E0,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFECB90,
        (u8 *)0xFF1C00,
        0x4738,
        0x2B70,
        0x4C74,
        0x4F,
        0x5A,
        0x288,
        0x4C88,
        0x47D1,
        0x359,
        0,
        0x603,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFF1C00,
        (u8 *)0xFF5210,
        0x2E9C,
        0x1B90,
        0x3180,
        0x37,
        0x72,
        0x191,
        0x56BE,
        0x469E,
        0x1C8,
        0,
        0x5DB,
        56.0f,
        96.0f,
        249.0f,
        186.0f,
        183.0f,
        255.0f,
    },
    {
        (u8 *)0xFF5210,
        (u8 *)0xFF6B20,
        0x14C4,
        0x9A0,
        0x16F8,
        0x25,
        0x2B,
        0x108,
        -0x16F4,
        0x18F9,
        0x843,
        0,
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
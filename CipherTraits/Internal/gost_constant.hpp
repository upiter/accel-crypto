#pragma once
#include <stdint.h>

namespace accel::CipherTraits::Internal {

    class GOST2814789_CONSTANT {
    protected:
        /*  SBox is generated by the following python3 script

#!/usr/bin/env python3

def PrintU32Array(tab, p, x, s):
    assert(len(x) % 8 == 0)
    print(' ' * tab + p)
    for i in range(len(x) // 8):
        print(' ' * tab + ', '.join([ '0x%.8x' % x[8 * i + j] for j in range(0, 8) ]) + ('' if i == 31 else ','))
    print(' ' * tab + s)

sbox = [
    [4, 10, 9, 2, 13, 8, 0, 14, 6, 11, 1, 12, 7, 15, 5, 3],
    [14, 11, 4, 12, 6, 13, 15, 10, 2, 3, 8, 1, 0, 7, 5, 9],
    [5, 8, 1, 13, 10, 3, 4, 2, 14, 15, 12, 7, 6, 0, 9, 11],
    [7, 13, 10, 1, 0, 8, 9, 15, 14, 4, 6, 12, 11, 2, 5, 3],
    [6, 12, 7, 1, 5, 15, 13, 8, 4, 10, 9, 14, 0, 3, 11, 2],
    [4, 11, 10, 0, 7, 2, 1, 13, 3, 6, 8, 5, 9, 12, 15, 14],
    [13, 11, 4, 1, 3, 15, 5, 9, 0, 10, 14, 7, 6, 8, 2, 12],
    [1, 15, 13, 0, 5, 7, 10, 4, 9, 2, 3, 14, 6, 11, 8, 12]
]


SBOX1 = [ (sbox[0][i & 0x0f] + sbox[1][i >> 4] * 0x10) * 0x00000001 for i in range(256) ]
SBOX2 = [ (sbox[2][i & 0x0f] + sbox[3][i >> 4] * 0x10) * 0x00000100 for i in range(256) ]
SBOX3 = [ (sbox[4][i & 0x0f] + sbox[5][i >> 4] * 0x10) * 0x00010000 for i in range(256) ]
SBOX4 = [ (sbox[6][i & 0x0f] + sbox[7][i >> 4] * 0x10) * 0x01000000 for i in range(256) ]

SBOX1 = [ ((SBOX1[i] << 11) | (SBOX1[i] >> (32 - 11))) & 0xffffffff for i in range(256) ]
SBOX2 = [ ((SBOX2[i] << 11) | (SBOX2[i] >> (32 - 11))) & 0xffffffff for i in range(256) ]
SBOX3 = [ ((SBOX3[i] << 11) | (SBOX3[i] >> (32 - 11))) & 0xffffffff for i in range(256) ]
SBOX4 = [ ((SBOX4[i] << 11) | (SBOX4[i] >> (32 - 11))) & 0xffffffff for i in range(256) ]


print('static inline const uint32_t SBoxAfterR[4][256] = {')
PrintU32Array(4, '{', SBOX1, '},')
PrintU32Array(4, '{', SBOX2, '},')
PrintU32Array(4, '{', SBOX3, '},')
PrintU32Array(4, '{', SBOX4, '}')
print('};')

         */
        static inline const uint32_t SBoxAfterR[4][256] = {
            {
            0x00072000, 0x00075000, 0x00074800, 0x00071000, 0x00076800, 0x00074000, 0x00070000, 0x00077000,
            0x00073000, 0x00075800, 0x00070800, 0x00076000, 0x00073800, 0x00077800, 0x00072800, 0x00071800,
            0x0005a000, 0x0005d000, 0x0005c800, 0x00059000, 0x0005e800, 0x0005c000, 0x00058000, 0x0005f000,
            0x0005b000, 0x0005d800, 0x00058800, 0x0005e000, 0x0005b800, 0x0005f800, 0x0005a800, 0x00059800,
            0x00022000, 0x00025000, 0x00024800, 0x00021000, 0x00026800, 0x00024000, 0x00020000, 0x00027000,
            0x00023000, 0x00025800, 0x00020800, 0x00026000, 0x00023800, 0x00027800, 0x00022800, 0x00021800,
            0x00062000, 0x00065000, 0x00064800, 0x00061000, 0x00066800, 0x00064000, 0x00060000, 0x00067000,
            0x00063000, 0x00065800, 0x00060800, 0x00066000, 0x00063800, 0x00067800, 0x00062800, 0x00061800,
            0x00032000, 0x00035000, 0x00034800, 0x00031000, 0x00036800, 0x00034000, 0x00030000, 0x00037000,
            0x00033000, 0x00035800, 0x00030800, 0x00036000, 0x00033800, 0x00037800, 0x00032800, 0x00031800,
            0x0006a000, 0x0006d000, 0x0006c800, 0x00069000, 0x0006e800, 0x0006c000, 0x00068000, 0x0006f000,
            0x0006b000, 0x0006d800, 0x00068800, 0x0006e000, 0x0006b800, 0x0006f800, 0x0006a800, 0x00069800,
            0x0007a000, 0x0007d000, 0x0007c800, 0x00079000, 0x0007e800, 0x0007c000, 0x00078000, 0x0007f000,
            0x0007b000, 0x0007d800, 0x00078800, 0x0007e000, 0x0007b800, 0x0007f800, 0x0007a800, 0x00079800,
            0x00052000, 0x00055000, 0x00054800, 0x00051000, 0x00056800, 0x00054000, 0x00050000, 0x00057000,
            0x00053000, 0x00055800, 0x00050800, 0x00056000, 0x00053800, 0x00057800, 0x00052800, 0x00051800,
            0x00012000, 0x00015000, 0x00014800, 0x00011000, 0x00016800, 0x00014000, 0x00010000, 0x00017000,
            0x00013000, 0x00015800, 0x00010800, 0x00016000, 0x00013800, 0x00017800, 0x00012800, 0x00011800,
            0x0001a000, 0x0001d000, 0x0001c800, 0x00019000, 0x0001e800, 0x0001c000, 0x00018000, 0x0001f000,
            0x0001b000, 0x0001d800, 0x00018800, 0x0001e000, 0x0001b800, 0x0001f800, 0x0001a800, 0x00019800,
            0x00042000, 0x00045000, 0x00044800, 0x00041000, 0x00046800, 0x00044000, 0x00040000, 0x00047000,
            0x00043000, 0x00045800, 0x00040800, 0x00046000, 0x00043800, 0x00047800, 0x00042800, 0x00041800,
            0x0000a000, 0x0000d000, 0x0000c800, 0x00009000, 0x0000e800, 0x0000c000, 0x00008000, 0x0000f000,
            0x0000b000, 0x0000d800, 0x00008800, 0x0000e000, 0x0000b800, 0x0000f800, 0x0000a800, 0x00009800,
            0x00002000, 0x00005000, 0x00004800, 0x00001000, 0x00006800, 0x00004000, 0x00000000, 0x00007000,
            0x00003000, 0x00005800, 0x00000800, 0x00006000, 0x00003800, 0x00007800, 0x00002800, 0x00001800,
            0x0003a000, 0x0003d000, 0x0003c800, 0x00039000, 0x0003e800, 0x0003c000, 0x00038000, 0x0003f000,
            0x0003b000, 0x0003d800, 0x00038800, 0x0003e000, 0x0003b800, 0x0003f800, 0x0003a800, 0x00039800,
            0x0002a000, 0x0002d000, 0x0002c800, 0x00029000, 0x0002e800, 0x0002c000, 0x00028000, 0x0002f000,
            0x0002b000, 0x0002d800, 0x00028800, 0x0002e000, 0x0002b800, 0x0002f800, 0x0002a800, 0x00029800,
            0x0004a000, 0x0004d000, 0x0004c800, 0x00049000, 0x0004e800, 0x0004c000, 0x00048000, 0x0004f000,
            0x0004b000, 0x0004d800, 0x00048800, 0x0004e000, 0x0004b800, 0x0004f800, 0x0004a800, 0x00049800
            },
            {
            0x03a80000, 0x03c00000, 0x03880000, 0x03e80000, 0x03d00000, 0x03980000, 0x03a00000, 0x03900000,
            0x03f00000, 0x03f80000, 0x03e00000, 0x03b80000, 0x03b00000, 0x03800000, 0x03c80000, 0x03d80000,
            0x06a80000, 0x06c00000, 0x06880000, 0x06e80000, 0x06d00000, 0x06980000, 0x06a00000, 0x06900000,
            0x06f00000, 0x06f80000, 0x06e00000, 0x06b80000, 0x06b00000, 0x06800000, 0x06c80000, 0x06d80000,
            0x05280000, 0x05400000, 0x05080000, 0x05680000, 0x05500000, 0x05180000, 0x05200000, 0x05100000,
            0x05700000, 0x05780000, 0x05600000, 0x05380000, 0x05300000, 0x05000000, 0x05480000, 0x05580000,
            0x00a80000, 0x00c00000, 0x00880000, 0x00e80000, 0x00d00000, 0x00980000, 0x00a00000, 0x00900000,
            0x00f00000, 0x00f80000, 0x00e00000, 0x00b80000, 0x00b00000, 0x00800000, 0x00c80000, 0x00d80000,
            0x00280000, 0x00400000, 0x00080000, 0x00680000, 0x00500000, 0x00180000, 0x00200000, 0x00100000,
            0x00700000, 0x00780000, 0x00600000, 0x00380000, 0x00300000, 0x00000000, 0x00480000, 0x00580000,
            0x04280000, 0x04400000, 0x04080000, 0x04680000, 0x04500000, 0x04180000, 0x04200000, 0x04100000,
            0x04700000, 0x04780000, 0x04600000, 0x04380000, 0x04300000, 0x04000000, 0x04480000, 0x04580000,
            0x04a80000, 0x04c00000, 0x04880000, 0x04e80000, 0x04d00000, 0x04980000, 0x04a00000, 0x04900000,
            0x04f00000, 0x04f80000, 0x04e00000, 0x04b80000, 0x04b00000, 0x04800000, 0x04c80000, 0x04d80000,
            0x07a80000, 0x07c00000, 0x07880000, 0x07e80000, 0x07d00000, 0x07980000, 0x07a00000, 0x07900000,
            0x07f00000, 0x07f80000, 0x07e00000, 0x07b80000, 0x07b00000, 0x07800000, 0x07c80000, 0x07d80000,
            0x07280000, 0x07400000, 0x07080000, 0x07680000, 0x07500000, 0x07180000, 0x07200000, 0x07100000,
            0x07700000, 0x07780000, 0x07600000, 0x07380000, 0x07300000, 0x07000000, 0x07480000, 0x07580000,
            0x02280000, 0x02400000, 0x02080000, 0x02680000, 0x02500000, 0x02180000, 0x02200000, 0x02100000,
            0x02700000, 0x02780000, 0x02600000, 0x02380000, 0x02300000, 0x02000000, 0x02480000, 0x02580000,
            0x03280000, 0x03400000, 0x03080000, 0x03680000, 0x03500000, 0x03180000, 0x03200000, 0x03100000,
            0x03700000, 0x03780000, 0x03600000, 0x03380000, 0x03300000, 0x03000000, 0x03480000, 0x03580000,
            0x06280000, 0x06400000, 0x06080000, 0x06680000, 0x06500000, 0x06180000, 0x06200000, 0x06100000,
            0x06700000, 0x06780000, 0x06600000, 0x06380000, 0x06300000, 0x06000000, 0x06480000, 0x06580000,
            0x05a80000, 0x05c00000, 0x05880000, 0x05e80000, 0x05d00000, 0x05980000, 0x05a00000, 0x05900000,
            0x05f00000, 0x05f80000, 0x05e00000, 0x05b80000, 0x05b00000, 0x05800000, 0x05c80000, 0x05d80000,
            0x01280000, 0x01400000, 0x01080000, 0x01680000, 0x01500000, 0x01180000, 0x01200000, 0x01100000,
            0x01700000, 0x01780000, 0x01600000, 0x01380000, 0x01300000, 0x01000000, 0x01480000, 0x01580000,
            0x02a80000, 0x02c00000, 0x02880000, 0x02e80000, 0x02d00000, 0x02980000, 0x02a00000, 0x02900000,
            0x02f00000, 0x02f80000, 0x02e00000, 0x02b80000, 0x02b00000, 0x02800000, 0x02c80000, 0x02d80000,
            0x01a80000, 0x01c00000, 0x01880000, 0x01e80000, 0x01d00000, 0x01980000, 0x01a00000, 0x01900000,
            0x01f00000, 0x01f80000, 0x01e00000, 0x01b80000, 0x01b00000, 0x01800000, 0x01c80000, 0x01d80000
            },
            {
            0x30000002, 0x60000002, 0x38000002, 0x08000002, 0x28000002, 0x78000002, 0x68000002, 0x40000002,
            0x20000002, 0x50000002, 0x48000002, 0x70000002, 0x00000002, 0x18000002, 0x58000002, 0x10000002,
            0xb0000005, 0xe0000005, 0xb8000005, 0x88000005, 0xa8000005, 0xf8000005, 0xe8000005, 0xc0000005,
            0xa0000005, 0xd0000005, 0xc8000005, 0xf0000005, 0x80000005, 0x98000005, 0xd8000005, 0x90000005,
            0x30000005, 0x60000005, 0x38000005, 0x08000005, 0x28000005, 0x78000005, 0x68000005, 0x40000005,
            0x20000005, 0x50000005, 0x48000005, 0x70000005, 0x00000005, 0x18000005, 0x58000005, 0x10000005,
            0x30000000, 0x60000000, 0x38000000, 0x08000000, 0x28000000, 0x78000000, 0x68000000, 0x40000000,
            0x20000000, 0x50000000, 0x48000000, 0x70000000, 0x00000000, 0x18000000, 0x58000000, 0x10000000,
            0xb0000003, 0xe0000003, 0xb8000003, 0x88000003, 0xa8000003, 0xf8000003, 0xe8000003, 0xc0000003,
            0xa0000003, 0xd0000003, 0xc8000003, 0xf0000003, 0x80000003, 0x98000003, 0xd8000003, 0x90000003,
            0x30000001, 0x60000001, 0x38000001, 0x08000001, 0x28000001, 0x78000001, 0x68000001, 0x40000001,
            0x20000001, 0x50000001, 0x48000001, 0x70000001, 0x00000001, 0x18000001, 0x58000001, 0x10000001,
            0xb0000000, 0xe0000000, 0xb8000000, 0x88000000, 0xa8000000, 0xf8000000, 0xe8000000, 0xc0000000,
            0xa0000000, 0xd0000000, 0xc8000000, 0xf0000000, 0x80000000, 0x98000000, 0xd8000000, 0x90000000,
            0xb0000006, 0xe0000006, 0xb8000006, 0x88000006, 0xa8000006, 0xf8000006, 0xe8000006, 0xc0000006,
            0xa0000006, 0xd0000006, 0xc8000006, 0xf0000006, 0x80000006, 0x98000006, 0xd8000006, 0x90000006,
            0xb0000001, 0xe0000001, 0xb8000001, 0x88000001, 0xa8000001, 0xf8000001, 0xe8000001, 0xc0000001,
            0xa0000001, 0xd0000001, 0xc8000001, 0xf0000001, 0x80000001, 0x98000001, 0xd8000001, 0x90000001,
            0x30000003, 0x60000003, 0x38000003, 0x08000003, 0x28000003, 0x78000003, 0x68000003, 0x40000003,
            0x20000003, 0x50000003, 0x48000003, 0x70000003, 0x00000003, 0x18000003, 0x58000003, 0x10000003,
            0x30000004, 0x60000004, 0x38000004, 0x08000004, 0x28000004, 0x78000004, 0x68000004, 0x40000004,
            0x20000004, 0x50000004, 0x48000004, 0x70000004, 0x00000004, 0x18000004, 0x58000004, 0x10000004,
            0xb0000002, 0xe0000002, 0xb8000002, 0x88000002, 0xa8000002, 0xf8000002, 0xe8000002, 0xc0000002,
            0xa0000002, 0xd0000002, 0xc8000002, 0xf0000002, 0x80000002, 0x98000002, 0xd8000002, 0x90000002,
            0xb0000004, 0xe0000004, 0xb8000004, 0x88000004, 0xa8000004, 0xf8000004, 0xe8000004, 0xc0000004,
            0xa0000004, 0xd0000004, 0xc8000004, 0xf0000004, 0x80000004, 0x98000004, 0xd8000004, 0x90000004,
            0x30000006, 0x60000006, 0x38000006, 0x08000006, 0x28000006, 0x78000006, 0x68000006, 0x40000006,
            0x20000006, 0x50000006, 0x48000006, 0x70000006, 0x00000006, 0x18000006, 0x58000006, 0x10000006,
            0xb0000007, 0xe0000007, 0xb8000007, 0x88000007, 0xa8000007, 0xf8000007, 0xe8000007, 0xc0000007,
            0xa0000007, 0xd0000007, 0xc8000007, 0xf0000007, 0x80000007, 0x98000007, 0xd8000007, 0x90000007,
            0x30000007, 0x60000007, 0x38000007, 0x08000007, 0x28000007, 0x78000007, 0x68000007, 0x40000007,
            0x20000007, 0x50000007, 0x48000007, 0x70000007, 0x00000007, 0x18000007, 0x58000007, 0x10000007
            },
            {
            0x000000e8, 0x000000d8, 0x000000a0, 0x00000088, 0x00000098, 0x000000f8, 0x000000a8, 0x000000c8,
            0x00000080, 0x000000d0, 0x000000f0, 0x000000b8, 0x000000b0, 0x000000c0, 0x00000090, 0x000000e0,
            0x000007e8, 0x000007d8, 0x000007a0, 0x00000788, 0x00000798, 0x000007f8, 0x000007a8, 0x000007c8,
            0x00000780, 0x000007d0, 0x000007f0, 0x000007b8, 0x000007b0, 0x000007c0, 0x00000790, 0x000007e0,
            0x000006e8, 0x000006d8, 0x000006a0, 0x00000688, 0x00000698, 0x000006f8, 0x000006a8, 0x000006c8,
            0x00000680, 0x000006d0, 0x000006f0, 0x000006b8, 0x000006b0, 0x000006c0, 0x00000690, 0x000006e0,
            0x00000068, 0x00000058, 0x00000020, 0x00000008, 0x00000018, 0x00000078, 0x00000028, 0x00000048,
            0x00000000, 0x00000050, 0x00000070, 0x00000038, 0x00000030, 0x00000040, 0x00000010, 0x00000060,
            0x000002e8, 0x000002d8, 0x000002a0, 0x00000288, 0x00000298, 0x000002f8, 0x000002a8, 0x000002c8,
            0x00000280, 0x000002d0, 0x000002f0, 0x000002b8, 0x000002b0, 0x000002c0, 0x00000290, 0x000002e0,
            0x000003e8, 0x000003d8, 0x000003a0, 0x00000388, 0x00000398, 0x000003f8, 0x000003a8, 0x000003c8,
            0x00000380, 0x000003d0, 0x000003f0, 0x000003b8, 0x000003b0, 0x000003c0, 0x00000390, 0x000003e0,
            0x00000568, 0x00000558, 0x00000520, 0x00000508, 0x00000518, 0x00000578, 0x00000528, 0x00000548,
            0x00000500, 0x00000550, 0x00000570, 0x00000538, 0x00000530, 0x00000540, 0x00000510, 0x00000560,
            0x00000268, 0x00000258, 0x00000220, 0x00000208, 0x00000218, 0x00000278, 0x00000228, 0x00000248,
            0x00000200, 0x00000250, 0x00000270, 0x00000238, 0x00000230, 0x00000240, 0x00000210, 0x00000260,
            0x000004e8, 0x000004d8, 0x000004a0, 0x00000488, 0x00000498, 0x000004f8, 0x000004a8, 0x000004c8,
            0x00000480, 0x000004d0, 0x000004f0, 0x000004b8, 0x000004b0, 0x000004c0, 0x00000490, 0x000004e0,
            0x00000168, 0x00000158, 0x00000120, 0x00000108, 0x00000118, 0x00000178, 0x00000128, 0x00000148,
            0x00000100, 0x00000150, 0x00000170, 0x00000138, 0x00000130, 0x00000140, 0x00000110, 0x00000160,
            0x000001e8, 0x000001d8, 0x000001a0, 0x00000188, 0x00000198, 0x000001f8, 0x000001a8, 0x000001c8,
            0x00000180, 0x000001d0, 0x000001f0, 0x000001b8, 0x000001b0, 0x000001c0, 0x00000190, 0x000001e0,
            0x00000768, 0x00000758, 0x00000720, 0x00000708, 0x00000718, 0x00000778, 0x00000728, 0x00000748,
            0x00000700, 0x00000750, 0x00000770, 0x00000738, 0x00000730, 0x00000740, 0x00000710, 0x00000760,
            0x00000368, 0x00000358, 0x00000320, 0x00000308, 0x00000318, 0x00000378, 0x00000328, 0x00000348,
            0x00000300, 0x00000350, 0x00000370, 0x00000338, 0x00000330, 0x00000340, 0x00000310, 0x00000360,
            0x000005e8, 0x000005d8, 0x000005a0, 0x00000588, 0x00000598, 0x000005f8, 0x000005a8, 0x000005c8,
            0x00000580, 0x000005d0, 0x000005f0, 0x000005b8, 0x000005b0, 0x000005c0, 0x00000590, 0x000005e0,
            0x00000468, 0x00000458, 0x00000420, 0x00000408, 0x00000418, 0x00000478, 0x00000428, 0x00000448,
            0x00000400, 0x00000450, 0x00000470, 0x00000438, 0x00000430, 0x00000440, 0x00000410, 0x00000460,
            0x00000668, 0x00000658, 0x00000620, 0x00000608, 0x00000618, 0x00000678, 0x00000628, 0x00000648,
            0x00000600, 0x00000650, 0x00000670, 0x00000638, 0x00000630, 0x00000640, 0x00000610, 0x00000660
            }
        };

    };

}


/*
 * Copyright (C) 2020 fleroviux
 *
 * Licensed under GPLv3 or any later version.
 * Refer to the included LICENSE file.
 */

#pragma once

#include <cstdint>

constexpr std::uint32_t DISPCNT = 0x04000000;
constexpr std::uint32_t DISPSTAT = 0x04000004;
constexpr std::uint32_t VCOUNT = 0x04000006;
constexpr std::uint32_t BG0CNT = 0x04000008;
constexpr std::uint32_t BG1CNT = 0x0400000A;
constexpr std::uint32_t BG2CNT = 0x0400000C;
constexpr std::uint32_t BG3CNT = 0x0400000E;
constexpr std::uint32_t BG0HOFS = 0x04000010;
constexpr std::uint32_t BG0VOFS = 0x04000012;
constexpr std::uint32_t BG1HOFS = 0x04000014;
constexpr std::uint32_t BG1VOFS = 0x04000016;
constexpr std::uint32_t BG2HOFS = 0x04000018;
constexpr std::uint32_t BG2VOFS = 0x0400001A;
constexpr std::uint32_t BG3HOFS = 0x0400001C;
constexpr std::uint32_t BG3VOFS = 0x0400001E;
constexpr std::uint32_t BG2PA = 0x04000020;
constexpr std::uint32_t BG2PB = 0x04000022;
constexpr std::uint32_t BG2PC = 0x04000024;
constexpr std::uint32_t BG2PD = 0x04000026;
constexpr std::uint32_t BG2X = 0x04000028;
constexpr std::uint32_t BG2Y = 0x0400002C;
constexpr std::uint32_t BG3PA = 0x04000030;
constexpr std::uint32_t BG3PB = 0x04000032;
constexpr std::uint32_t BG3PC = 0x04000034;
constexpr std::uint32_t BG3PD = 0x04000036;
constexpr std::uint32_t BG3X = 0x04000038;
constexpr std::uint32_t BG3Y = 0x0400003C;
constexpr std::uint32_t WIN0H = 0x04000040;
constexpr std::uint32_t WIN1H = 0x04000042;
constexpr std::uint32_t WIN0V = 0x04000044;
constexpr std::uint32_t WIN1V = 0x04000046;
constexpr std::uint32_t WININ = 0x04000048;
constexpr std::uint32_t WINOUT = 0x0400004A;
constexpr std::uint32_t MOSAIC = 0x0400004C;
constexpr std::uint32_t BLDCNT = 0x04000050;
constexpr std::uint32_t BLDALPHA = 0x04000052;
constexpr std::uint32_t BLDY = 0x04000054;
constexpr std::uint32_t SOUND1CNT_L = 0x04000060;
constexpr std::uint32_t SOUND1CNT_H = 0x04000062;
constexpr std::uint32_t SOUND1CNT_X = 0x04000064;
constexpr std::uint32_t SOUND2CNT_L = 0x04000068;
constexpr std::uint32_t SOUND2CNT_H = 0x0400006C;
constexpr std::uint32_t SOUND3CNT_L = 0x04000070;
constexpr std::uint32_t SOUND3CNT_H = 0x04000072;
constexpr std::uint32_t SOUND3CNT_X = 0x04000074;
constexpr std::uint32_t SOUND4CNT_L = 0x04000078;
constexpr std::uint32_t SOUND4CNT_H = 0x0400007C;
constexpr std::uint32_t SOUNDCNT_L = 0x04000080;
constexpr std::uint32_t SOUNDCNT_H = 0x04000082;
constexpr std::uint32_t SOUNDCNT_X = 0x04000084;
constexpr std::uint32_t SOUNDBIAS = 0x04000088;
constexpr std::uint32_t WAVE_RAM = 0x04000090;
constexpr std::uint32_t FIFO_A = 0x040000A0;
constexpr std::uint32_t FIFO_B = 0x040000A4;
constexpr std::uint32_t DMA0SAD = 0x040000B0;
constexpr std::uint32_t DMA0DAD = 0x040000B4;
constexpr std::uint32_t DMA0CNT_L = 0x040000B8;
constexpr std::uint32_t DMA0CNT_H = 0x040000BA;
constexpr std::uint32_t DMA1SAD = 0x040000BC;
constexpr std::uint32_t DMA1DAD = 0x040000C0;
constexpr std::uint32_t DMA1CNT_L = 0x040000C4;
constexpr std::uint32_t DMA1CNT_H = 0x040000C6;
constexpr std::uint32_t DMA2SAD = 0x040000C8;
constexpr std::uint32_t DMA2DAD = 0x040000CC;
constexpr std::uint32_t DMA2CNT_L = 0x040000D0;
constexpr std::uint32_t DMA2CNT_H = 0x040000D2;
constexpr std::uint32_t DMA3SAD = 0x040000D4;
constexpr std::uint32_t DMA3DAD = 0x040000D8;
constexpr std::uint32_t DMA3CNT_L = 0x040000DC;
constexpr std::uint32_t DMA3CNT_H = 0x040000DE;
constexpr std::uint32_t TM0CNT_L = 0x04000100;
constexpr std::uint32_t TM0CNT_H = 0x04000102;
constexpr std::uint32_t TM1CNT_L = 0x04000104;
constexpr std::uint32_t TM1CNT_H = 0x04000106;
constexpr std::uint32_t TM2CNT_L = 0x04000108;
constexpr std::uint32_t TM2CNT_H = 0x0400010A;
constexpr std::uint32_t TM3CNT_L = 0x0400010C;
constexpr std::uint32_t TM3CNT_H = 0x0400010E;
constexpr std::uint32_t KEYINPUT = 0x04000130;
constexpr std::uint32_t KEYCNT = 0x04000132;
constexpr std::uint32_t RCNT = 0x04000134;
constexpr std::uint32_t IE = 0x04000200;
constexpr std::uint32_t IF = 0x04000202;
constexpr std::uint32_t WAITCNT = 0x04000204;
constexpr std::uint32_t IME = 0x04000208;
constexpr std::uint32_t POSTFLG = 0x04000300;
constexpr std::uint32_t HALTCNT = 0x04000301;

/**
  * Copyright (C) 2017 flerovium^-^ (Frederic Meyer)
  *
  * This file is part of NanoboyAdvance.
  *
  * NanoboyAdvance is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * NanoboyAdvance is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with NanoboyAdvance. If not, see <http://www.gnu.org/licenses/>.
  */

#include "regs.hpp"

namespace Core {

    void DMA::reset() {
        enable    = false;
        repeat    = false;
        interrupt = false;
        gamepak   = false;

        length   = 0;
        dst_addr = 0;
        src_addr = 0;
        internal.length   = 0;
        internal.dst_addr = 0;
        internal.src_addr = 0;

        size     = DMA_HWORD;
        time     = DMA_IMMEDIATE;
        dst_cntl = DMA_INCREMENT;
        src_cntl = DMA_INCREMENT;
    }

    auto DMA::read(int offset) -> u8 {
        // TODO: are SAD/DAD/CNT_L readable?
        switch (offset) {
            // DMAXCNT_H
            case 10: {
                return (dst_cntl << 5) |
                       (src_cntl << 7);
            }
            case 11: {
                return (src_cntl >> 1) |
                       (size     << 2) |
                       (time     << 4) |
                       (repeat    ? 2   : 0) |
                       (gamepak   ? 8   : 0) |
                       (interrupt ? 64  : 0) |
                       (enable    ? 128 : 0);
            }
        }
    }

    void DMA::write(int offset, u8 value) {
        switch (offset) {
            // DMAXSAD
            case 0: src_addr = (src_addr & 0xFFFFFF00) | value; break;
            case 1: src_addr = (src_addr & 0xFFFF00FF) | (value<<8); break;
            case 2: src_addr = (src_addr & 0xFF00FFFF) | (value<<16); break;
            case 3: src_addr = (src_addr & 0x00FFFFFF) | (value<<24); break;

            // DMAXDAD
            case 4: dst_addr = (dst_addr & 0xFFFFFF00) | value; break;
            case 5: dst_addr = (dst_addr & 0xFFFF00FF) | (value<<8); break;
            case 6: dst_addr = (dst_addr & 0xFF00FFFF) | (value<<16); break;
            case 7: dst_addr = (dst_addr & 0x00FFFFFF) | (value<<24); break;

            // DMAXCNT_L
            case 8: length = (length & 0xFF00) | value; break;
            case 9: length = (length & 0x00FF) | (value<<8); break;

            // DMAXCNT_H
            case 10:
                dst_cntl = static_cast<DMAControl>((value >> 5) & 3);
                src_cntl = static_cast<DMAControl>((src_cntl & 0b10) | (value>>7));
                break;
            case 11: {
                bool enable_previous = enable;

                src_cntl  = static_cast<DMAControl>((src_cntl & 0b01) | ((value & 1)<<1));
                size      = static_cast<DMASize>((value>>2) & 1);
                time      = static_cast<DMATime>((value>>4) & 3);
                repeat    = value & 2;
                gamepak   = value & 8;
                interrupt = value & 64;
                enable    = value & 128;

                if (!enable_previous && enable) {
                    // TODO(accuracy): length must be masked.
                    internal.length = length;
                    internal.dst_addr = dst_addr;
                    internal.src_addr = src_addr;

                    // mask internal address registers
                    internal.dst_addr &= (id != 3) ? 0x07FFFFFF : 0x0FFFFFFF;
                    internal.src_addr &= (id == 0) ? 0x07FFFFFF : 0x0FFFFFFF;

                    // mask length
                    if (id == 3) {
                        internal.length &= 0xFFFF;
                        if (internal.length == 0) {
                            internal.length = 0x10000;
                        }
                    } else {
                        internal.length &= 0x3FFF;
                        if (internal.length == 0) {
                            internal.length = 0x4000;
                        }
                    }

                    if (time == DMA_IMMEDIATE) {
                        // !!hacked!! sad flerovium :(
                        *dma_active  = true;
                        *current_dma = id;
                    }
                }
                break;
            }
        }
    }
}
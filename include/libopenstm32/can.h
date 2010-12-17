/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENSTM32_CAN_H
#define LIBOPENSTM32_CAN_H

#include <libopenstm32/memorymap.h>
#include <libopenstm32/common.h>

/* --- Convenience macros -------------------------------------------------- */

/* CAN register base adresses (for convenience) */
#define CAN1                            BX_CAN1_BASE
#define CAN2                            BX_CAN2_BASE

/* --- CAN registers ------------------------------------------------------- */

/* CAN master control register (CAN_MCR) */
#define CAN_MCR(can_base)               MMIO32(can_base + 0x000)
/* CAN master status register (CAN_MSR) */
#define CAN_MSR(can_base)               MMIO32(can_base + 0x004)
/* CAN transmit status register (CAN_TSR) */
#define CAN_TSR(can_base)               MMIO32(can_base + 0x008)

/* CAN receive FIFO 0 register (CAN_RF0R) */
#define CAN_RF0R(can_base)              MMIO32(can_base + 0x00C)
/* CAN receive FIFO 1 register (CAN_RF1R) */
#define CAN_RF1R(can_base)              MMIO32(can_base + 0x010)

/* CAN interrupt enable register (CAN_IER) */
#define CAN_IER(can_base)               MMIO32(can_base + 0x014)
/* CAN error status register (CAN_ESR) */
#define CAN_ESR(can_base)               MMIO32(can_base + 0x018)
/* CAN bit timing register (CAN_BTR) */
#define CAN_BTR(can_base)               MMIO32(can_base + 0x01C)

/* Registers in the offset range 0x020 to 0x17F are reserved */

/* --- CAN mailbox registers ----------------------------------------------- */

/* CAN mailbox / fifo register offsets */
#define CAN_MBOX0                       0x180
#define CAN_MBOX1                       0x190
#define CAN_MBOX2                       0x1A0
#define CAN_FIFO0                       0x1B0
#define CAN_FIFO1                       0x1C0

/* CAN TX mailbox identifier register (CAN_TIxR) */
#define CAN_TIxR(can_base, mbox)        MMIO32(can_base + mbox + 0x0)
#define CAN_TI0R(can_base)              CAN_TIxR(can_base, CAN_MBOX0)
#define CAN_TI1R(can_base)              CAN_TIxR(can_base, CAN_MBOX1)
#define CAN_TI2R(can_base)              CAN_TIxR(can_base, CAN_MBOX2)

/* CAN mailbox data length control and time stamp register (CAN_TDTxR) */
#define CAN_TDTxR(can_base, mbox)       MMIO32(can_base + mbox + 0x4)
#define CAN_TDT0R(can_base)             CAN_TDTxR(can_base, CAN_MBOX0)
#define CAN_TDT1R(can_base)             CAN_TDTxR(can_base, CAN_MBOX1)
#define CAN_TDT2R(can_base)             CAN_TDTxR(can_base, CAN_MBOX2)

/* CAN mailbox data low register (CAN_TDLxR) */
#define CAN_TDLxR(can_base, mbox)       MMIO32(can_base + mbox + 0x8)
#define CAN_TDL0R(can_base)             CAN_TDLxR(can_base, CAN_MBOX0)
#define CAN_TDL1R(can_base)             CAN_TDLxR(can_base, CAN_MBOX1)
#define CAN_TDL2R(can_base)             CAN_TDLxR(can_base, CAN_MBOX2)

/* CAN mailbox data high register (CAN_TDHxR) */
#define CAN_TDHxR(can_base, mbox)       MMIO32(can_base + mbox + 0xC)
#define CAN_TDH0R(can_base)             CAN_TDHxR(can_base, CAN_MBOX0)
#define CAN_TDH1R(can_base)             CAN_TDHxR(can_base, CAN_MBOX1)
#define CAN_TDH2R(can_base)             CAN_TDHxR(can_base, CAN_MBOX2)

/* CAN RX FIFO identifier register (CAN_RIxR) */
#define CAN_RIxR(can_base, fifo)        MMIO32(can_base + fifo + 0x0)
#define CAN_RI0R(can_base)              CAN_RIxR(can_base, CAN_FIFO0)
#define CAN_RI1R(can_base)              CAN_RIxR(can_base, CAN_FIFO1)

/* CAN RX FIFO mailbox data length control and time stamp register (CAN_RDTxR) */
#define CAN_RDTxR(can_base, fifo)        MMIO32(can_base + fifo + 0x4)
#define CAN_RDT0R(can_base)              CAN_RDTxR(can_base, CAN_FIFO0)
#define CAN_RDT1R(can_base)              CAN_RDTxR(can_base, CAN_FIFO1)

/* CAN RX FIFO mailbox data low register (CAN_RDLxR) */
#define CAN_RDLxR(can_base, fifo)        MMIO32(can_base + fifo + 0x8)
#define CAN_RDL0R(can_base)              CAN_RDLxR(can_base, CAN_FIFO0)
#define CAN_RDL1R(can_base)              CAN_RDLxR(can_base, CAN_FIFO1)

/* CAN RX FIFO mailbox data high register (CAN_RDHxR) */
#define CAN_RDHxR(can_base, fifo)        MMIO32(can_base + fifo + 0xC)
#define CAN_RDH0R(can_base)              CAN_RDHxR(can_base, CAN_FIFO0)
#define CAN_RDH1R(can_base)              CAN_RDHxR(can_base, CAN_FIFO1)

/* --- CAN filter registers ------------------------------------------------ */

/* CAN filter master register (CAN_FMR) */
#define CAN_FMR(can_base)               MMIO32(can_base + 0x200)

/* CAN filter mode register (CAN_FM1R) */
#define CAN_FM1R(can_base)              MMIO32(can_base + 0x204)

/* Register offset 0x208 reserved */

/* CAN filter scale register (CAN_FS1R) */
#define CAN_FS1R(can_base)              MMIO32(can_base + 0x20C)

/* Register offset 0x210 reserved */

/* CAN filter FIFO assignement register (CAN_FFA1R) */
#define CAN_FFA1R(can_base)             MMIO32(can_base + 0x214)

/* Register offset 0x218 reserved */

/* CAN filter activation register (CAN_FA1R) */
#define CAN_FA1R(can_base)              MMIO32(can_base + 0x21C)

/* Register offset 0x220 reserved */

/* Registers with offset 0x224 to 0x23F reserved */

/* CAN filter bank registers (CAN_FiRx) */
/* Connectivity line devices have 28 banks so the bank id spans 0..27
 * all other devices have 14 banks so the bank id spans 0..13
 */
#define CAN_FiR1(can_base, bank)        MMIO32(can_base + 0x240 + (bank * 0x8) + 0x0)
#define CAN_FiR2(can_base, bank)        MMIO32(can_base + 0x240 + (bank * 0x8) + 0x4)

#endif /* LIBOPENSTM32_CAN_H */

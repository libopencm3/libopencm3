/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LPC43XX_GPDMA_H
#define LPC43XX_GPDMA_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* GPDMA channel base addresses */
#define GPDMA_CHANNEL0                  (GPDMA_PORT_BASE + 0x100)
#define GPDMA_CHANNEL1                  (GPDMA_PORT_BASE + 0x120)
#define GPDMA_CHANNEL2                  (GPDMA_PORT_BASE + 0x140)
#define GPDMA_CHANNEL3                  (GPDMA_PORT_BASE + 0x160)
#define GPDMA_CHANNEL4                  (GPDMA_PORT_BASE + 0x180)
#define GPDMA_CHANNEL5                  (GPDMA_PORT_BASE + 0x1A0)
#define GPDMA_CHANNEL6                  (GPDMA_PORT_BASE + 0x1C0)
#define GPDMA_CHANNEL7                  (GPDMA_PORT_BASE + 0x1E0)


/* --- GPDMA registers ----------------------------------------------------- */

/* General registers */

/* DMA Interrupt Status Register */
#define GPDMA_NTSTAT                    MMIO32(GPDMA_BASE + 0x000)

/* DMA Interrupt Terminal Count Request Status Register */
#define GPDMA_INTTCSTAT                 MMIO32(GPDMA_BASE + 0x004)

/* DMA Interrupt Terminal Count Request Clear Register */
#define GPDMA_INTTCCLEAR                MMIO32(GPDMA_BASE + 0x008)

/* DMA Interrupt Error Status Register */
#define GPDMA_INTERRSTAT                MMIO32(GPDMA_BASE + 0x00C)

/* DMA Interrupt Error Clear Register */
#define GPDMA_INTERRCLR                 MMIO32(GPDMA_BASE + 0x010)

/* DMA Raw Interrupt Terminal Count Status Register */
#define GPDMA_RAWINTTCSTAT              MMIO32(GPDMA_BASE + 0x014)

/* DMA Raw Error Interrupt Status Register */
#define GPDMA_RAWINTERRSTAT             MMIO32(GPDMA_BASE + 0x018)

/* DMA Enabled Channel Register */
#define GPDMA_ENBLDCHNS                 MMIO32(GPDMA_BASE + 0x01C)

/* DMA Software Burst Request Register */
#define GPDMA_SOFTBREQ                  MMIO32(GPDMA_BASE + 0x020)

/* DMA Software Single Request Register */
#define GPDMA_SOFTSREQ                  MMIO32(GPDMA_BASE + 0x024)

/* DMA Software Last Burst Request Register */
#define GPDMA_SOFTLBREQ                 MMIO32(GPDMA_BASE + 0x028)

/* DMA Software Last Single Request Register */
#define GPDMA_SOFTLSREQ                 MMIO32(GPDMA_BASE + 0x02C)

/* DMA Configuration Register */
#define GPDMA_CONFIG                    MMIO32(GPDMA_BASE + 0x030)

/* DMA Synchronization Register */
#define GPDMA_SYNC                      MMIO32(GPDMA_BASE + 0x034)


/* Channel registers */

/* Source Address Register */
#define GPDMA_SRCADDR(channel)          MMIO32(channel + 0x000)
#define GPDMA_C0SRCADDR                 GPDMA_SRCADDR(GPDMA_CHANNEL0)
#define GPDMA_C1SRCADDR                 GPDMA_SRCADDR(GPDMA_CHANNEL1)
#define GPDMA_C2SRCADDR                 GPDMA_SRCADDR(GPDMA_CHANNEL2)
#define GPDMA_C3SRCADDR                 GPDMA_SRCADDR(GPDMA_CHANNEL3)
#define GPDMA_C4SRCADDR                 GPDMA_SRCADDR(GPDMA_CHANNEL4)
#define GPDMA_C5SRCADDR                 GPDMA_SRCADDR(GPDMA_CHANNEL5)
#define GPDMA_C6SRCADDR                 GPDMA_SRCADDR(GPDMA_CHANNEL6)
#define GPDMA_C7SRCADDR                 GPDMA_SRCADDR(GPDMA_CHANNEL7)

/* Destination Address Register */
#define GPDMA_DESTADDR(channel)         MMIO32(channel + 0x004)
#define GPDMA_C0DESTADDR                GPDMA_DESTADDR(GPDMA_CHANNEL0)
#define GPDMA_C1DESTADDR                GPDMA_DESTADDR(GPDMA_CHANNEL1)
#define GPDMA_C2DESTADDR                GPDMA_DESTADDR(GPDMA_CHANNEL2)
#define GPDMA_C3DESTADDR                GPDMA_DESTADDR(GPDMA_CHANNEL3)
#define GPDMA_C4DESTADDR                GPDMA_DESTADDR(GPDMA_CHANNEL4)
#define GPDMA_C5DESTADDR                GPDMA_DESTADDR(GPDMA_CHANNEL5)
#define GPDMA_C6DESTADDR                GPDMA_DESTADDR(GPDMA_CHANNEL6)
#define GPDMA_C7DESTADDR                GPDMA_DESTADDR(GPDMA_CHANNEL7)

/* Linked List Item Register */
#define GPDMA_LLI(channel)              MMIO32(channel + 0x008)
#define GPDMA_C0LLI                     GPDMA_LLI(GPDMA_CHANNEL0)
#define GPDMA_C1LLI                     GPDMA_LLI(GPDMA_CHANNEL1)
#define GPDMA_C2LLI                     GPDMA_LLI(GPDMA_CHANNEL2)
#define GPDMA_C3LLI                     GPDMA_LLI(GPDMA_CHANNEL3)
#define GPDMA_C4LLI                     GPDMA_LLI(GPDMA_CHANNEL4)
#define GPDMA_C5LLI                     GPDMA_LLI(GPDMA_CHANNEL5)
#define GPDMA_C6LLI                     GPDMA_LLI(GPDMA_CHANNEL6)
#define GPDMA_C7LLI                     GPDMA_LLI(GPDMA_CHANNEL7)

/* Control Register */
#define GPDMA_CONTROL(channel)          MMIO32(channel + 0x00C)
#define GPDMA_C0CONTROL                 GPDMA_CONTROL(GPDMA_CHANNEL0)
#define GPDMA_C1CONTROL                 GPDMA_CONTROL(GPDMA_CHANNEL1)
#define GPDMA_C2CONTROL                 GPDMA_CONTROL(GPDMA_CHANNEL2)
#define GPDMA_C3CONTROL                 GPDMA_CONTROL(GPDMA_CHANNEL3)
#define GPDMA_C4CONTROL                 GPDMA_CONTROL(GPDMA_CHANNEL4)
#define GPDMA_C5CONTROL                 GPDMA_CONTROL(GPDMA_CHANNEL5)
#define GPDMA_C6CONTROL                 GPDMA_CONTROL(GPDMA_CHANNEL6)
#define GPDMA_C7CONTROL                 GPDMA_CONTROL(GPDMA_CHANNEL7)

/* Configuration Register */
#define GPDMA_CONFIG(channel)           MMIO32(channel + 0x010)
#define GPDMA_C0CONFIG                  GPDMA_CONFIG(GPDMA_CHANNEL0)
#define GPDMA_C1CONFIG                  GPDMA_CONFIG(GPDMA_CHANNEL1)
#define GPDMA_C2CONFIG                  GPDMA_CONFIG(GPDMA_CHANNEL2)
#define GPDMA_C3CONFIG                  GPDMA_CONFIG(GPDMA_CHANNEL3)
#define GPDMA_C4CONFIG                  GPDMA_CONFIG(GPDMA_CHANNEL4)
#define GPDMA_C5CONFIG                  GPDMA_CONFIG(GPDMA_CHANNEL5)
#define GPDMA_C6CONFIG                  GPDMA_CONFIG(GPDMA_CHANNEL6)
#define GPDMA_C7CONFIG                  GPDMA_CONFIG(GPDMA_CHANNEL7)

#endif

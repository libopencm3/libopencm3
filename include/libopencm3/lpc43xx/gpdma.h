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
#define C0SRCADDR                       GPDMA_SRCADDR(GPDMA_CHANNEL0)
#define C1SRCADDR                       GPDMA_SRCADDR(GPDMA_CHANNEL1)
#define C2SRCADDR                       GPDMA_SRCADDR(GPDMA_CHANNEL2)
#define C3SRCADDR                       GPDMA_SRCADDR(GPDMA_CHANNEL3)
#define C4SRCADDR                       GPDMA_SRCADDR(GPDMA_CHANNEL4)
#define C5SRCADDR                       GPDMA_SRCADDR(GPDMA_CHANNEL5)
#define C6SRCADDR                       GPDMA_SRCADDR(GPDMA_CHANNEL6)
#define C7SRCADDR                       GPDMA_SRCADDR(GPDMA_CHANNEL7)

/* Destination Address Register */
#define GPDMA_DESTADDR(channel)         MMIO32(channel + 0x004)
#define C0DESTADDR                      GPDMA_DESTADDR(GPDMA_CHANNEL0)
#define C1DESTADDR                      GPDMA_DESTADDR(GPDMA_CHANNEL1)
#define C2DESTADDR                      GPDMA_DESTADDR(GPDMA_CHANNEL2)
#define C3DESTADDR                      GPDMA_DESTADDR(GPDMA_CHANNEL3)
#define C4DESTADDR                      GPDMA_DESTADDR(GPDMA_CHANNEL4)
#define C5DESTADDR                      GPDMA_DESTADDR(GPDMA_CHANNEL5)
#define C6DESTADDR                      GPDMA_DESTADDR(GPDMA_CHANNEL6)
#define C7DESTADDR                      GPDMA_DESTADDR(GPDMA_CHANNEL7)

/* Linked List Item Register */
#define GPDMA_LLI(channel)              MMIO32(channel + 0x008)
#define C0LLI                           GPDMA_LLI(GPDMA_CHANNEL0)
#define C1LLI                           GPDMA_LLI(GPDMA_CHANNEL1)
#define C2LLI                           GPDMA_LLI(GPDMA_CHANNEL2)
#define C3LLI                           GPDMA_LLI(GPDMA_CHANNEL3)
#define C4LLI                           GPDMA_LLI(GPDMA_CHANNEL4)
#define C5LLI                           GPDMA_LLI(GPDMA_CHANNEL5)
#define C6LLI                           GPDMA_LLI(GPDMA_CHANNEL6)
#define C7LLI                           GPDMA_LLI(GPDMA_CHANNEL7)

/* Control Register */
#define GPDMA_CONTROL(channel)          MMIO32(channel + 0x00C)
#define C0CONTROL                       GPDMA_CONTROL(GPDMA_CHANNEL0)
#define C1CONTROL                       GPDMA_CONTROL(GPDMA_CHANNEL1)
#define C2CONTROL                       GPDMA_CONTROL(GPDMA_CHANNEL2)
#define C3CONTROL                       GPDMA_CONTROL(GPDMA_CHANNEL3)
#define C4CONTROL                       GPDMA_CONTROL(GPDMA_CHANNEL4)
#define C5CONTROL                       GPDMA_CONTROL(GPDMA_CHANNEL5)
#define C6CONTROL                       GPDMA_CONTROL(GPDMA_CHANNEL6)
#define C7CONTROL                       GPDMA_CONTROL(GPDMA_CHANNEL7)

/* Configuration Register */
#define GPDMA_CONFIG(channel)           MMIO32(channel + 0x010)
#define C0CONFIG                        GPDMA_CONFIG(GPDMA_CHANNEL0)
#define C1CONFIG                        GPDMA_CONFIG(GPDMA_CHANNEL1)
#define C2CONFIG                        GPDMA_CONFIG(GPDMA_CHANNEL2)
#define C3CONFIG                        GPDMA_CONFIG(GPDMA_CHANNEL3)
#define C4CONFIG                        GPDMA_CONFIG(GPDMA_CHANNEL4)
#define C5CONFIG                        GPDMA_CONFIG(GPDMA_CHANNEL5)
#define C6CONFIG                        GPDMA_CONFIG(GPDMA_CHANNEL6)
#define C7CONFIG                        GPDMA_CONFIG(GPDMA_CHANNEL7)

#endif

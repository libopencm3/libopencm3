/** @defgroup sdio_defines SDIO

@brief <b>Defined Constants and Types for the LPC43xx SDIO</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
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

#ifndef LPC43XX_SDIO_H
#define LPC43XX_SDIO_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- SDIO registers ----------------------------------------------------- */

/* Control Register */
#define SDIO_CTRL                       MMIO32(SDIO_BASE + 0x000)

/* Power Enable Register */
#define SDIO_PWREN                      MMIO32(SDIO_BASE + 0x004)

/* Clock Divider Register */
#define SDIO_CLKDIV                     MMIO32(SDIO_BASE + 0x008)

/* SD Clock Source Register */
#define SDIO_CLKSRC                     MMIO32(SDIO_BASE + 0x00C)

/* Clock Enable Register */
#define SDIO_CLKENA                     MMIO32(SDIO_BASE + 0x010)

/* Time-out Register */
#define SDIO_TMOUT                      MMIO32(SDIO_BASE + 0x014)

/* Card Type Register */
#define SDIO_CTYPE                      MMIO32(SDIO_BASE + 0x018)

/* Block Size Register */
#define SDIO_BLKSIZ                     MMIO32(SDIO_BASE + 0x01C)

/* Byte Count Register */
#define SDIO_BYTCNT                     MMIO32(SDIO_BASE + 0x020)

/* Interrupt Mask Register */
#define SDIO_INTMASK                    MMIO32(SDIO_BASE + 0x024)

/* Command Argument Register */
#define SDIO_CMDARG                     MMIO32(SDIO_BASE + 0x028)

/* Command Register */
#define SDIO_CMD                        MMIO32(SDIO_BASE + 0x02C)

/* Response Register 0 */
#define SDIO_RESP0                      MMIO32(SDIO_BASE + 0x030)

/* Response Register 1 */
#define SDIO_RESP1                      MMIO32(SDIO_BASE + 0x034)

/* Response Register 2 */
#define SDIO_RESP2                      MMIO32(SDIO_BASE + 0x038)

/* Response Register 3 */
#define SDIO_RESP3                      MMIO32(SDIO_BASE + 0x03C)

/* Masked Interrupt Status Register */
#define SDIO_MINTSTS                    MMIO32(SDIO_BASE + 0x040)

/* Raw Interrupt Status Register */
#define SDIO_RINTSTS                    MMIO32(SDIO_BASE + 0x044)

/* Status Register */
#define SDIO_STATUS                     MMIO32(SDIO_BASE + 0x048)

/* FIFO Threshold Watermark Register */
#define SDIO_FIFOTH                     MMIO32(SDIO_BASE + 0x04C)

/* Card Detect Register */
#define SDIO_CDETECT                    MMIO32(SDIO_BASE + 0x050)

/* Write Protect Register */
#define SDIO_WRTPRT                     MMIO32(SDIO_BASE + 0x054)

/* Transferred CIU Card Byte Count Register */
#define SDIO_TCBCNT                     MMIO32(SDIO_BASE + 0x05C)

/* Transferred Host to BIU-FIFO Byte Count Register */
#define SDIO_TBBCNT                     MMIO32(SDIO_BASE + 0x060)

/* Debounce Count Register */
#define SDIO_DEBNCE                     MMIO32(SDIO_BASE + 0x064)

/* UHS-1 Register */
#define SDIO_UHS_REG                    MMIO32(SDIO_BASE + 0x074)

/* Hardware Reset */
#define SDIO_RST_N                      MMIO32(SDIO_BASE + 0x078)

/* Bus Mode Register */
#define SDIO_BMOD                       MMIO32(SDIO_BASE + 0x080)

/* Poll Demand Register */
#define SDIO_PLDMND                     MMIO32(SDIO_BASE + 0x084)

/* Descriptor List Base Address Register */
#define SDIO_DBADDR                     MMIO32(SDIO_BASE + 0x088)

/* Internal DMAC Status Register */
#define SDIO_IDSTS                      MMIO32(SDIO_BASE + 0x08C)

/* Internal DMAC Interrupt Enable Register */
#define SDIO_IDINTEN                    MMIO32(SDIO_BASE + 0x090)

/* Current Host Descriptor Address Register */
#define SDIO_DSCADDR                    MMIO32(SDIO_BASE + 0x094)

/* Current Buffer Descriptor Address Register */
#define SDIO_BUFADDR                    MMIO32(SDIO_BASE + 0x098)

/* Data FIFO read/write */
#define SDIO_DATA                       MMIO32(SDIO_BASE + 0x100)

/**@}*/

#endif

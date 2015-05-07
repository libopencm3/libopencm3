/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Owen Kirby <osk@exegin.com>
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

#ifndef SAM3X_USB_H
#define SAM3X_USB_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* --- USB Device Port registers ------------------------------------------ */

#define UDP_FRM_NUM			MMIO32(UDP_BASE + 0x00)
#define UDP_GLB_STAT		MMIO32(UDP_BASE + 0x04)
#define UDP_FADDR			MMIO32(UDP_BASE + 0x08)
/* 0x0C reserved */
#define UDP_IER				MMIO32(UDP_BASE + 0x10)
#define UDP_IDR				MMIO32(UDP_BASE + 0x14)
#define UDP_IMR				MMIO32(UDP_BASE + 0x18)
#define UDP_ISR				MMIO32(UDP_BASE + 0x1C)
#define UDP_ICR				MMIO32(UDP_BASE + 0x20)
/* 0x24 reserved */
#define UDP_RST				MMIO32(UDP_BASE + 0x28)
/* 0x2C reserved */
#define UDP_CSR(x)			MMIO32(UDP_BASE + 0x30 + 0x4*(x))
#define UDP_FDR(x)			MMIO32(UDP_BASE + 0x50 + 0x4*(x))
/* 0x70 reserved */
#define UDP_TXVC			MMIO32(UDP_BASE + 0x74)
/* 0x78:0xFC reserved */

/* UDP Frame Number Register (UDP_FRM_NUM) */
/* Bits [31:18] - Reserved */
#define UDP_FRM_NUM_OK			(0x01 << 17)
#define UDP_FRM_NUM_ERR			(0x01 << 16)
/* Bits [15:11] - Reserved */
#define UDP_FRM_NUM_MASK		(0x7FF << 0)

/* UDP Global State Register (UDP_GLB_STAT) */
/* Bits [31:5] - Reserved */
#define UDP_GLB_STAT_RMWUPE		(0x01 << 4)
#define UDP_GLB_STAT_RSMINPR	(0x01 << 3)
#define UDP_GLB_STAT_ESR		(0x01 << 2)
#define UDP_GLB_STAT_CONFG		(0x01 << 1)
#define UDP_GLB_STAT_FADDEN		(0x01 << 0)

/* UDP Function Address Register (UDP_FADDR) */
/* Bits [31:9] - Reserved */
#define UDP_FADDR_FEN			(0x01 << 8)
/* Bit 7 -  Reserved */
#define UDP_FADDR_MASK			(0x7F << 0)

/* UDP Interrupt Registers (UDP_IER, UDP_IDR, UDP_IMR, UDP_ISR, and UDP_ICR) */
/* Bits [31:14] - Reserved */
#define UDP_INT_WAKEUP			(0x01 << 13)
#define UDP_INT_ENDBUSRES		(0x01 << 12)
#define UDP_INT_SOFINT			(0x01 << 11)
#define UDP_INT_EXTRSM			(0x01 << 10)
#define UDP_INT_RXRSM			(0x01 << 9)
#define UDP_INT_RXSUSP			(0x01 << 8)
#define UDP_INT_EP(x)			(0x01 << (x))

/* UDP Reset Endpoint Register (UDP_RST) */
/* Bits [31:8] - Reserved */
#define UDP_RST_EP(x)			(0x01 << (x))
#define UDP_RST_ALL				(0xFF << 0)

/* UDP Endpoint Control and Stauts Register (UDP_CSR(x)) */
/* Bits [31:27] - Reserved */
#define UDP_CSR_RXBYTECNT_MASK		(0x7FF << 16)
#define UDP_CSR_GET_RXBYTECNT(x)	(((x) >> 16) & 0x7FF)
#define UDP_CSR_EPEDS				(0x01 << 15)
/* Bits [14:12] - Reserved */
#define UDP_CSR_DTGLE				(0x01 << 11)
#define UDP_CSR_EPTYPE_MASK			(0x07 << 8)
#define UDP_CSR_EPTYPE_IN   	    (0x04 << 8)
#define UDP_CSR_EPTYPE_CTRL			(0x00 << 8)
#define UDP_CSR_EPTYPE_ISO			(0x01 << 8)
#define UDP_CSR_EPTYPE_BULK			(0x02 << 8)
#define UDP_CSR_EPTYPE_INT			(0x03 << 8)
#define UDP_CSR_EPTYPE_ISO_OUT		(UDP_CSR_EPTYPE_ISO)
#define UDP_CSR_EPTYPE_ISO_IN		(UDP_CSR_EPTYPE_ISO | UDP_CSR_EPTYPE_IN)
#define UDP_CSR_EPTYPE_BULK_OUT		(UDP_CSR_EPTYPE_BULK)
#define UDP_CSR_EPTYPE_BULK_IN		(UDP_CSR_EPTYPE_BULK | UDP_CSR_EPTYPE_IN)
#define UDP_CSR_EPTYPE_INT_OUT		(UDP_CSR_EPTYPE_INT)
#define UDP_CSR_EPTYPE_INT_IN		(UDP_CSR_EPTYPE_INT | UDP_CSR_EPTYPE_IN)
#define UDP_CSR_DIR					(0x01 << 7)
#define UDP_CSR_RX_DATA_BK1			(0x01 << 6)
#define UDP_CSR_FORCESTALL			(0x01 << 5)
#define UDP_CSR_TXPKTRDY			(0x01 << 4)
#define UDP_CSR_STALLSENT			(0x01 << 3)
#define UDP_CSR_ISOERROR			(0x01 << 3)
#define UDP_CSR_RXSETUP				(0x01 << 2)
#define UDP_CSR_RX_DATA_BK0			(0x01 << 1)
#define UDP_CSR_TXCOMP				(0x01 << 0)
/* UDP_CSRx bits that must be set high for a no-op. */
#define UDP_CSR_WRITE_NOP		 	(UDP_CSR_TXCOMP | UDP_CSR_RX_DATA_BK0 | \
									UDP_CSR_RXSETUP | UDP_CSR_STALLSENT | \
									UDP_CSR_ISOERROR | UDP_CSR_RX_DATA_BK1)

/* UDP FIFO Data Register (UDP_FDR(x)) */
/* Bits [31:8] - Reserved */
#define UDP_FDR_MASK			(0xFF << 0)

/* UDP Transceiver Control Register (UDP_TXVC) */
/* Bits [31:10] - Reserved */
#define UDP_TXVC_PUON			(0x01 << 9)
#define UDP_TXVC_TXVDIS			(0x01 << 8)
/* Bits [7:0] - Reserved */

/* USB Endpoint description */
#define UDP_EP_COUNT			8
#define UDP_EP_DUAL_BANK(x)		((x != 0) && (x != 3))
#define UDP_EP_MAX_SIZE(x)		( ((x == 4) || (x == 5)) ? 512 : 64)
#define UDP_EP_SUPPORT_CTRL(x)	(!UDP_EP_DUAL_BANK(x))
#define UDP_EP_SUPPORT_ISO(x)	UDP_EP_DUAL_BANK(x)
/* All endpoint support bulk and interrupt transfers */

#endif


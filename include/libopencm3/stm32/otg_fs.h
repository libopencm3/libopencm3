/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010  Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef LIBOPENCM3_OTG_FS_H
#define LIBOPENCM3_OTG_FS_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* Core Global Control and Status Registers */
#define OTG_FS_OTGCTL			MMIO32(USB_OTG_FS_BASE + 0x000)
#define OTG_FS_GOTGINT			MMIO32(USB_OTG_FS_BASE + 0x004)
#define OTG_FS_GAHBCFG			MMIO32(USB_OTG_FS_BASE + 0x008)
#define OTG_FS_GUSBCFG			MMIO32(USB_OTG_FS_BASE + 0x00C)
#define OTG_FS_GRSTCTL			MMIO32(USB_OTG_FS_BASE + 0x010)
#define OTG_FS_GINTSTS			MMIO32(USB_OTG_FS_BASE + 0x014)
#define OTG_FS_GINTMSK			MMIO32(USB_OTG_FS_BASE + 0x018)
#define OTG_FS_GRXSTSR			MMIO32(USB_OTG_FS_BASE + 0x01C)
#define OTG_FS_GRXSTSP			MMIO32(USB_OTG_FS_BASE + 0x020)
#define OTG_FS_GRXFSIZ			MMIO32(USB_OTG_FS_BASE + 0x024)
#define OTG_FS_GNPTXFSIZ		MMIO32(USB_OTG_FS_BASE + 0x028)
#define OTG_FS_GNPTXSTS			MMIO32(USB_OTG_FS_BASE + 0x02C)
#define OTG_FS_GCCFG			MMIO32(USB_OTG_FS_BASE + 0x038)
#define OTG_FS_CID			MMIO32(USB_OTG_FS_BASE + 0x03C)
#define OTG_FS_HPTXFSIZ			MMIO32(USB_OTG_FS_BASE + 0x100)
#define OTG_FS_DIEPTXF(x)		MMIO32(USB_OTG_FS_BASE + 0x104 + 4*(x))

/* Host-mode Control and Status Registers */
#define OTG_FS_HCFG 			MMIO32(USB_OTG_FS_BASE + 0x400)
#define OTG_FS_HFIR 			MMIO32(USB_OTG_FS_BASE + 0x404)
#define OTG_FS_HFNUM 			MMIO32(USB_OTG_FS_BASE + 0x408)
#define OTG_FS_HPTXSTS 			MMIO32(USB_OTG_FS_BASE + 0x410)
#define OTG_FS_HAINT 			MMIO32(USB_OTG_FS_BASE + 0x414)
#define OTG_FS_HAINTMSK 		MMIO32(USB_OTG_FS_BASE + 0x418)
#define OTG_FS_HPRT 			MMIO32(USB_OTG_FS_BASE + 0x440)
#define OTG_FS_HCCHARx 			MMIO32(USB_OTG_FS_BASE + 0x500)
#define OTG_FS_HCINTx 			MMIO32(USB_OTG_FS_BASE + 0x508)
#define OTG_FS_HCINTMSKx 		MMIO32(USB_OTG_FS_BASE + 0x50C)
#define OTG_FS_HCTSIZx 			MMIO32(USB_OTG_FS_BASE + 0x510)

/* Device-mode Control and Status Registers */
#define OTG_FS_DCFG 			MMIO32(USB_OTG_FS_BASE + 0x800)
#define OTG_FS_DCTL 			MMIO32(USB_OTG_FS_BASE + 0x804)
#define OTG_FS_DSTS 			MMIO32(USB_OTG_FS_BASE + 0x808)
#define OTG_FS_DIEPMSK 			MMIO32(USB_OTG_FS_BASE + 0x810)
#define OTG_FS_DOEPMSK 			MMIO32(USB_OTG_FS_BASE + 0x814)
#define OTG_FS_DAINT 			MMIO32(USB_OTG_FS_BASE + 0x818)
#define OTG_FS_DAINTMSK 		MMIO32(USB_OTG_FS_BASE + 0x81C)
#define OTG_FS_DVBUSDIS 		MMIO32(USB_OTG_FS_BASE + 0x828)
#define OTG_FS_DVBUSPULSE 		MMIO32(USB_OTG_FS_BASE + 0x82C)
#define OTG_FS_DIEPEMPMSK 		MMIO32(USB_OTG_FS_BASE + 0x834)
#define OTG_FS_DIEPCTL0 		MMIO32(USB_OTG_FS_BASE + 0x900)
#define OTG_FS_DIEPCTL(x) 		MMIO32(USB_OTG_FS_BASE + 0x900 + 0x20*(x))
#define OTG_FS_DOEPCTL0 		MMIO32(USB_OTG_FS_BASE + 0xB00)
#define OTG_FS_DOEPCTL(x) 		MMIO32(USB_OTG_FS_BASE + 0xB00 + 0x20*(x))
#define OTG_FS_DIEPINT(x) 		MMIO32(USB_OTG_FS_BASE + 0x908 + 0x20*(x))
#define OTG_FS_DOEPINT(x) 		MMIO32(USB_OTG_FS_BASE + 0xB08 + 0x20*(x))
#define OTG_FS_DIEPTSIZ0 		MMIO32(USB_OTG_FS_BASE + 0x910)
#define OTG_FS_DOEPTSIZ0 		MMIO32(USB_OTG_FS_BASE + 0xB10)
#define OTG_FS_DIEPTSIZ(x) 		MMIO32(USB_OTG_FS_BASE + 0x910 + 0x20*(x))
#define OTG_FS_DTXFSTS(x) 		MMIO32(USB_OTG_FS_BASE + 0x918 + 0x20*(x))
#define OTG_FS_DOEPTSIZ(x) 		MMIO32(USB_OTG_FS_BASE + 0xB10 + 0x20*(x))

/* Power and clock gating control and status register */
#define OTH_FS_PCGCR			MMIO32(USB_OTG_FS_BASE + 0xE00)


/* Global CSRs */
/* OTG_FS AHB configuration register (OTG_FS_GAHBCFG) */
#define OTG_FS_GAHBCFG_GINT		0x0001
#define OTG_FS_GAHBCFG_TXFELVL		0x0080
#define OTG_FS_GAHBCFG_PTXFELVL		0x0100

/* OTG_FS USB configuration register (OTG_FS_GUSBCFG) */
#define OTG_FS_GUSBCFG_TOCAL		0x00000003
#define OTG_FS_GUSBCFG_SRPCAP		0x00000100
#define OTG_FS_GUSBCFG_HNPCAP		0x00000200
#define OTG_FS_GUSBCFG_TRDT		0x00003C00
#define OTG_FS_GUSBCFG_NPTXRWEN		0x00004000
#define OTG_FS_GUSBCFG_FHMOD		0x20000000
#define OTG_FS_GUSBCFG_FDMOD		0x40000000
#define OTG_FS_GUSBCFG_CTXPKT		0x80000000

/* OTG_FS interrupt mask register (OTG_FS_GINTMSK) */
#define OTG_FS_GINTMSK_MMISM		0x00000002
#define OTG_FS_GINTMSK_OTGINT		0x00000004
#define OTG_FS_GINTMSK_SOFM		0x00000008
#define OTG_FS_GINTMSK_RXFLVLM		0x00000010
#define OTG_FS_GINTMSK_NPTXFEM		0x00000020
#define OTG_FS_GINTMSK_GINAKEFFM	0x00000040
#define OTG_FS_GINTMSK_GONAKEFFM	0x00000080
#define OTG_FS_GINTMSK_ESUSPM		0x00000400
#define OTG_FS_GINTMSK_USBSUSPM		0x00000800
#define OTG_FS_GINTMSK_USBRST		0x00001000
#define OTG_FS_GINTMSK_ENUMDNEM		0x00002000
#define OTG_FS_GINTMSK_ISOODRPM		0x00004000
#define OTG_FS_GINTMSK_EOPFM		0x00008000
#define OTG_FS_GINTMSK_EPMISM		0x00020000
#define OTG_FS_GINTMSK_IEPINT		0x00040000
#define OTG_FS_GINTMSK_OEPINT		0x00080000
#define OTG_FS_GINTMSK_IISOIXFRM	0x00100000
#define OTG_FS_GINTMSK_IISOOXFRM	0x00200000
#define OTG_FS_GINTMSK_IPXFRM		0x00200000
#define OTG_FS_GINTMSK_PRTIM		0x01000000
#define OTG_FS_GINTMSK_HCIM		0x02000000
#define OTG_FS_GINTMSK_PTXFEM		0x04000000
#define OTG_FS_GINTMSK_CIDSCHGM		0x10000000
#define OTG_FS_GINTMSK_DISCINT		0x20000000
#define OTG_FS_GINTMSK_SRQIM		0x40000000
#define OTG_FS_GINTMSK_WUIM		0x80000000


/* Device-mode CSRs */
/* OTG_FS device configuration register (OTG_FS_DCFG) */
#define OTG_FS_DCFG_DSPD		0x0003
#define OTG_FS_DCFG_NZLSOHSK		0x0004
#define OTG_FS_DCFG_DAD			0x07F0
#define OTG_FS_DCFG_PFIVL		0x1800



#endif


/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef LIBOPENCM3_OTG_HS_H
#define LIBOPENCM3_OTG_HS_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* Core Global Control and Status Registers */
#define OTG_GOTGCTL			0x000
#define OTG_GOTGIN			0x004
#define OTG_GAHBCFG			0x008
#define OTG_GUSBCFG			0x00C
#define OTG_GRSTCTL			0x010
#define OTG_GINTSTS			0x014
#define OTG_GINTMSK			0x018
#define OTG_GRXSTSR			0x01C
#define OTG_GRXSTSP			0x020
#define OTG_GRXFSIZ			0x024
#define OTG_GNPTXFSIZ			0x028
#define OTG_GNPTXSTS			0x02C
#define OTG_GCCFG			0x038
#define OTG_CID				0x03C
#define OTG_HPTXFSIZ			0x100
#define OTG_DIEPTXF(x)			(0x104 + 4*(x-1))

/* Host-mode Control and Status Registers */
#define OTG_HCFG			0x400
#define OTG_HFIR			0x404
#define OTG_HFNUM			0x408
#define OTG_HPTXSTS			0x410
#define OTG_HAINT			0x414
#define OTG_HAINTMSK			0x418
#define OTG_HPRT			0x440
#define OTG_HCCHARx			0x500
#define OTG_HCINTx			0x508
#define OTG_HCINTMSKx			0x50C
#define OTG_HCTSIZx			0x510

/* Device-mode Control and Status Registers */
#define OTG_DCFG			0x800
#define OTG_DCTL			0x804
#define OTG_DSTS			0x808
#define OTG_DIEPMSK			0x810
#define OTG_DOEPMSK			0x814
#define OTG_DAINT			0x818
#define OTG_DAINTMSK			0x81C
#define OTG_DVBUSDIS			0x828
#define OTG_DVBUSPULSE			0x82C
#define OTG_DIEPEMPMSK			0x834
#define OTG_DIEPCTL0			0x900
#define OTG_DIEPCTL(x)			(0x900 + 0x20*(x))
#define OTG_DOEPCTL0			0xB00
#define OTG_DOEPCTL(x)			(0xB00 + 0x20*(x))
#define OTG_DIEPINT(x)			(0x908 + 0x20*(x))
#define OTG_DOEPINT(x)			(0xB08 + 0x20*(x))
#define OTG_DIEPTSIZ0			0x910
#define OTG_DOEPTSIZ0			0xB10
#define OTG_DIEPTSIZ(x)			(0x910 + 0x20*(x))
#define OTG_DTXFSTS(x)			(0x918 + 0x20*(x))
#define OTG_DOEPTSIZ(x)			(0xB10 + 0x20*(x))

/* Power and clock gating control and status register */
#define OTG_PCGCCTL			0xE00

/* Data FIFO */
#define OTG_FIFO(x)			(((x) + 1) << 12)

/***********************************************************************/

/* Core Global Control and Status Registers */
#define OTG_HS_GOTGCTL			MMIO32(USB_OTG_HS_BASE + OTG_GOTGCTL)
#define OTG_HS_GOTGINT			MMIO32(USB_OTG_HS_BASE + OTG_GOTGINT)
#define OTG_HS_GAHBCFG			MMIO32(USB_OTG_HS_BASE + OTG_GAHBCFG)
#define OTG_HS_GUSBCFG			MMIO32(USB_OTG_HS_BASE + OTG_GUSBCFG)
#define OTG_HS_GRSTCTL			MMIO32(USB_OTG_HS_BASE + OTG_GRSTCTL)
#define OTG_HS_GINTSTS			MMIO32(USB_OTG_HS_BASE + OTG_GINTSTS)
#define OTG_HS_GINTMSK			MMIO32(USB_OTG_HS_BASE + OTG_GINTMSK)
#define OTG_HS_GRXSTSR			MMIO32(USB_OTG_HS_BASE + OTG_GRXSTSR)
#define OTG_HS_GRXSTSP			MMIO32(USB_OTG_HS_BASE + OTG_GRXSTSP)
#define OTG_HS_GRXFSIZ			MMIO32(USB_OTG_HS_BASE + OTG_GRXFSIZ)
#define OTG_HS_GNPTXFSIZ		MMIO32(USB_OTG_HS_BASE + OTG_GNPTXFSIZ)
#define OTG_HS_GNPTXSTS			MMIO32(USB_OTG_HS_BASE + OTG_GNPTXSTS)
#define OTG_HS_GCCFG			MMIO32(USB_OTG_HS_BASE + OTG_GCCFG)
#define OTG_HS_CID			MMIO32(USB_OTG_HS_BASE + OTG_CID)
#define OTG_HS_HPTXFSIZ			MMIO32(USB_OTG_HS_BASE + OTG_HPTXFSIZ)
#define OTG_HS_DIEPTXF(x)		MMIO32(USB_OTG_HS_BASE + OTG_DIEPTXF(x))

/* Host-mode Control and Status Registers */
#define OTG_HS_HCFG			MMIO32(USB_OTG_HS_BASE + OTG_HCFG)
#define OTG_HS_HFIR			MMIO32(USB_OTG_HS_BASE + OTG_HFIR)
#define OTG_HS_HFNUM			MMIO32(USB_OTG_HS_BASE + OTG_HFNUM)
#define OTG_HS_HPTXSTS			MMIO32(USB_OTG_HS_BASE + OTG_HPTXSTS)
#define OTG_HS_HAINT			MMIO32(USB_OTG_HS_BASE + OTG_HAINT)
#define OTG_HS_HAINTMSK			MMIO32(USB_OTG_HS_BASE + OTG_HAINTMSK)
#define OTG_HS_HPRT			MMIO32(USB_OTG_HS_BASE + OTG_HPRT)
#define OTG_HS_HCCHARx			MMIO32(USB_OTG_HS_BASE + OTG_HCCHARx)
#define OTG_HS_HCINTx			MMIO32(USB_OTG_HS_BASE + OTG_HCINTx)
#define OTG_HS_HCINTMSKx		MMIO32(USB_OTG_HS_BASE + OTG_HCINTMSKx)
#define OTG_HS_HCTSIZx			MMIO32(USB_OTG_HS_BASE + OTG_HCTSIZx)

/* Device-mode Control and Status Registers */
#define OTG_HS_DCFG			MMIO32(USB_OTG_HS_BASE + OTG_DCFG)
#define OTG_HS_DCTL			MMIO32(USB_OTG_HS_BASE + OTG_DCTL)
#define OTG_HS_DSTS			MMIO32(USB_OTG_HS_BASE + OTG_DSTS)
#define OTG_HS_DIEPMSK			MMIO32(USB_OTG_HS_BASE + OTG_DIEPMSK)
#define OTG_HS_DOEPMSK			MMIO32(USB_OTG_HS_BASE + OTG_DOEPMSK)
#define OTG_HS_DAINT			MMIO32(USB_OTG_HS_BASE + OTG_DAINT)
#define OTG_HS_DAINTMSK			MMIO32(USB_OTG_HS_BASE + OTG_DAINTMSK)
#define OTG_HS_DVBUSDIS			MMIO32(USB_OTG_HS_BASE + OTG_DVBUSDIS)
#define OTG_HS_DVBUSPULSE		MMIO32(USB_OTG_HS_BASE + OTG_DVBUSPULSE)
#define OTG_HS_DIEPEMPMSK		MMIO32(USB_OTG_HS_BASE + OTG_DIEPEMPMSK)
#define OTG_HS_DIEPCTL0			MMIO32(USB_OTG_HS_BASE + OTG_DIEPCTL0)
#define OTG_HS_DIEPCTL(x)		MMIO32(USB_OTG_HS_BASE + OTG_DIEPCTL(x))
#define OTG_HS_DOEPCTL0			MMIO32(USB_OTG_HS_BASE + OTG_DOEPCTL0)
#define OTG_HS_DOEPCTL(x)		MMIO32(USB_OTG_HS_BASE + OTG_DOEPCTL(x))
#define OTG_HS_DIEPINT(x)		MMIO32(USB_OTG_HS_BASE + OTG_DIEPINT(x))
#define OTG_HS_DOEPINT(x)		MMIO32(USB_OTG_HS_BASE + OTG_DOEPINT(x))
#define OTG_HS_DIEPTSIZ0		MMIO32(USB_OTG_HS_BASE + OTG_DIEPTSIZ0)
#define OTG_HS_DOEPTSIZ0		MMIO32(USB_OTG_HS_BASE + OTG_DOEPTSIZ0)
#define OTG_HS_DIEPTSIZ(x)		MMIO32(USB_OTG_HS_BASE + OTG_DIEPTSIZ(x)))
#define OTG_HS_DTXFSTS(x)		MMIO32(USB_OTG_HS_BASE + OTG_DTXFSTS(x))
#define OTG_HS_DOEPTSIZ(x)		MMIO32(USB_OTG_HS_BASE + OTG_DOEPTSIZ(x))

/* Power and clock gating control and status register */
#define OTG_HS_PCGCCTL			MMIO32(USB_OTG_HS_BASE + OTG_PCGCCTL)

/* Data FIFO */
#define OTG_HS_FIFO(x)			((volatile u32*)(USB_OTG_HS_BASE + OTG_FIFO(x)))

/* Global CSRs */
/* OTG_HS USB control registers (OTG_FS_GOTGCTL) */
#define OTG_HS_GOTGCTL_BSVLD		(1 << 19)
#define OTG_HS_GOTGCTL_ASVLD		(1 << 18)
#define OTG_HS_GOTGCTL_DBCT 		(1 << 17)
#define OTG_HS_GOTGCTL_CIDSTS		(1 << 16)
#define OTG_HS_GOTGCTL_DHNPEN		(1 << 11)
#define OTG_HS_GOTGCTL_HSHNPEN		(1 << 10)
#define OTG_HS_GOTGCTL_HNPRQ		(1 << 9)
#define OTG_HS_GOTGCTL_HNGSCS		(1 << 8)
#define OTG_HS_GOTGCTL_SRQ		(1 << 1)
#define OTG_HS_GOTGCTL_SRQSCS		(1 << 0)

/* OTG_FS AHB configuration register (OTG_HS_GAHBCFG) */
#define OTG_HS_GAHBCFG_GINT		0x0001
#define OTG_HS_GAHBCFG_TXFELVL		0x0080
#define OTG_HS_GAHBCFG_PTXFELVL		0x0100

/* OTG_FS USB configuration register (OTG_HS_GUSBCFG) */
#define OTG_HS_GUSBCFG_TOCAL		0x00000003
#define OTG_HS_GUSBCFG_SRPCAP		0x00000100
#define OTG_HS_GUSBCFG_HNPCAP		0x00000200
#define OTG_HS_GUSBCFG_TRDT_MASK	(0xf << 10)
#define OTG_HS_GUSBCFG_TRDT_16BIT	(0x5 << 10)
#define OTG_HS_GUSBCFG_TRDT_8BIT	(0x9 << 10)
#define OTG_HS_GUSBCFG_NPTXRWEN		0x00004000
#define OTG_HS_GUSBCFG_FHMOD		0x20000000
#define OTG_HS_GUSBCFG_FDMOD		0x40000000
#define OTG_HS_GUSBCFG_CTXPKT		0x80000000
#define OTG_HS_GUSBCFG_PHYSEL		(1 << 6)

/* OTG_FS reset register (OTG_HS_GRSTCTL) */
#define OTG_HS_GRSTCTL_AHBIDL		(1 << 31)
/* Bits 30:11 - Reserved */
#define OTG_HS_GRSTCTL_TXFNUM_MASK	(0x1f << 6)
#define OTG_HS_GRSTCTL_TXFFLSH		(1 << 5)
#define OTG_HS_GRSTCTL_RXFFLSH		(1 << 4)
/* Bit 3 - Reserved */
#define OTG_HS_GRSTCTL_FCRST		(1 << 2)
#define OTG_HS_GRSTCTL_HSRST		(1 << 1)
#define OTG_HS_GRSTCTL_CSRST		(1 << 0)

/* OTG_FS interrupt status register (OTG_HS_GINTSTS) */
#define OTG_HS_GINTSTS_WKUPINT		(1 << 31)
#define OTG_HS_GINTSTS_SRQINT		(1 << 30)
#define OTG_HS_GINTSTS_DISCINT		(1 << 29)
#define OTG_HS_GINTSTS_CIDSCHG		(1 << 28)
/* Bit 27 - Reserved */
#define OTG_HS_GINTSTS_PTXFE		(1 << 26)
#define OTG_HS_GINTSTS_HCINT		(1 << 25)
#define OTG_HS_GINTSTS_HPRTINT		(1 << 24)
/* Bits 23:22 - Reserved */
#define OTG_HS_GINTSTS_IPXFR		(1 << 21)
#define OTG_HS_GINTSTS_INCOMPISOOUT	(1 << 21)
#define OTG_HS_GINTSTS_IISOIXFR		(1 << 20)
#define OTG_HS_GINTSTS_OEPINT		(1 << 19)
#define OTG_HS_GINTSTS_IEPINT		(1 << 18)
/* Bits 17:16 - Reserved */
#define OTG_HS_GINTSTS_EOPF		(1 << 15)
#define OTG_HS_GINTSTS_ISOODRP		(1 << 14)
#define OTG_HS_GINTSTS_ENUMDNE		(1 << 13)
#define OTG_HS_GINTSTS_USBRST		(1 << 12)
#define OTG_HS_GINTSTS_USBSUSP		(1 << 11)
#define OTG_HS_GINTSTS_ESUSP		(1 << 10)
/* Bits 9:8 - Reserved */
#define OTG_HS_GINTSTS_GONAKEFF		(1 << 7)
#define OTG_HS_GINTSTS_GINAKEFF		(1 << 6)
#define OTG_HS_GINTSTS_NPTXFE		(1 << 5)
#define OTG_HS_GINTSTS_RXFLVL		(1 << 4)
#define OTG_HS_GINTSTS_SOF		(1 << 3)
#define OTG_HS_GINTSTS_OTGINT		(1 << 2)
#define OTG_HS_GINTSTS_MMIS		(1 << 1)
#define OTG_HS_GINTSTS_CMOD		(1 << 0)

/* OTG_FS interrupt mask register (OTG_HS_GINTMSK) */
#define OTG_HS_GINTMSK_MMISM		0x00000002
#define OTG_HS_GINTMSK_OTGINT		0x00000004
#define OTG_HS_GINTMSK_SOFM		0x00000008
#define OTG_HS_GINTMSK_RXFLVLM		0x00000010
#define OTG_HS_GINTMSK_NPTXFEM		0x00000020
#define OTG_HS_GINTMSK_GINAKEFFM	0x00000040
#define OTG_HS_GINTMSK_GONAKEFFM	0x00000080
#define OTG_HS_GINTMSK_ESUSPM		0x00000400
#define OTG_HS_GINTMSK_USBSUSPM		0x00000800
#define OTG_HS_GINTMSK_USBRST		0x00001000
#define OTG_HS_GINTMSK_ENUMDNEM		0x00002000
#define OTG_HS_GINTMSK_ISOODRPM		0x00004000
#define OTG_HS_GINTMSK_EOPFM		0x00008000
#define OTG_HS_GINTMSK_EPMISM		0x00020000
#define OTG_HS_GINTMSK_IEPINT		0x00040000
#define OTG_HS_GINTMSK_OEPINT		0x00080000
#define OTG_HS_GINTMSK_IISOIXFRM	0x00100000
#define OTG_HS_GINTMSK_IISOOXFRM	0x00200000
#define OTG_HS_GINTMSK_IPXFRM		0x00200000
#define OTG_HS_GINTMSK_PRTIM		0x01000000
#define OTG_HS_GINTMSK_HCIM		0x02000000
#define OTG_HS_GINTMSK_PTXFEM		0x04000000
#define OTG_HS_GINTMSK_CIDSCHGM		0x10000000
#define OTG_HS_GINTMSK_DISCINT		0x20000000
#define OTG_HS_GINTMSK_SRQIM		0x40000000
#define OTG_HS_GINTMSK_WUIM		0x80000000

/* OTG_FS Receive Status Pop Register (OTG_HS_GRXSTSP) */
/* Bits 31:25 - Reserved */
#define OTG_HS_GRXSTSP_FRMNUM_MASK		(0xf << 21)
#define OTG_HS_GRXSTSP_PKTSTS_MASK		(0xf << 17)
#define OTG_HS_GRXSTSP_PKTSTS_GOUTNAK		(0x1 << 17)
#define OTG_HS_GRXSTSP_PKTSTS_OUT		(0x2 << 17)
#define OTG_HS_GRXSTSP_PKTSTS_OUT_COMP		(0x3 << 17)
#define OTG_HS_GRXSTSP_PKTSTS_SETUP_COMP	(0x4 << 17)
#define OTG_HS_GRXSTSP_PKTSTS_SETUP		(0x6 << 17)
#define OTG_HS_GRXSTSP_DPID_MASK		(0x3 << 15)
#define OTG_HS_GRXSTSP_DPID_DATA0		(0x0 << 15)
#define OTG_HS_GRXSTSP_DPID_DATA1		(0x2 << 15)
#define OTG_HS_GRXSTSP_DPID_DATA2		(0x1 << 15)
#define OTG_HS_GRXSTSP_DPID_MDATA		(0x3 << 15)
#define OTG_HS_GRXSTSP_BCNT_MASK		(0x7ff << 4)
#define OTG_HS_GRXSTSP_EPNUM_MASK		(0xf << 0)

/* OTG_FS general core configuration register (OTG_HS_GCCFG) */
/* Bits 31:21 - Reserved */
#define OTG_HS_GCCFG_SOFOUTEN		(1 << 20)
#define OTG_HS_GCCFG_VBUSBSEN		(1 << 19)
#define OTG_HS_GCCFG_VBUSASEN		(1 << 18)
/* Bit 17 - Reserved */
#define OTG_HS_GCCFG_PWRDWN		(1 << 16)
/* Bits 15:0 - Reserved */


/* Device-mode CSRs */
/* OTG_FS device control register (OTG_HS_DCTL) */
/* Bits 31:12 - Reserved */
#define OTG_HS_DCTL_POPRGDNE		(1 << 11)
#define OTG_HS_DCTL_CGONAK		(1 << 10)
#define OTG_HS_DCTL_SGONAK		(1 << 9)
#define OTG_HS_DCTL_SGINAK		(1 << 8)
#define OTG_HS_DCTL_TCTL_MASK		(7 << 4)
#define OTG_HS_DCTL_GONSTS		(1 << 3)
#define OTG_HS_DCTL_GINSTS		(1 << 2)
#define OTG_HS_DCTL_SDIS		(1 << 1)
#define OTG_HS_DCTL_RWUSIG		(1 << 0)

/* OTG_FS device configuration register (OTG_HS_DCFG) */
#define OTG_HS_DCFG_DSPD		0x0003
#define OTG_HS_DCFG_NZLSOHSK		0x0004
#define OTG_HS_DCFG_DAD			0x07F0
#define OTG_HS_DCFG_PFIVL		0x1800

/* OTG_FS Device IN Endpoint Common Interrupt Mask Register (OTG_HS_DIEPMSK) */
/* Bits 31:10 - Reserved */
#define OTG_HS_DIEPMSK_BIM		(1 << 9)
#define OTG_HS_DIEPMSK_TXFURM		(1 << 8)
/* Bit 7 - Reserved */
#define OTG_HS_DIEPMSK_INEPNEM		(1 << 6)
#define OTG_HS_DIEPMSK_INEPNMM		(1 << 5)
#define OTG_HS_DIEPMSK_ITTXFEMSK	(1 << 4)
#define OTG_HS_DIEPMSK_TOM		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_HS_DIEPMSK_EPDM		(1 << 1)
#define OTG_HS_DIEPMSK_XFRCM		(1 << 0)

/* OTG_FS Device OUT Endpoint Common Interrupt Mask Register (OTG_HS_DOEPMSK) */
/* Bits 31:10 - Reserved */
#define OTG_HS_DOEPMSK_BOIM		(1 << 9)
#define OTG_HS_DOEPMSK_OPEM		(1 << 8)
/* Bit 7 - Reserved */
#define OTG_HS_DOEPMSK_B2BSTUP		(1 << 6)
/* Bit 5 - Reserved */
#define OTG_HS_DOEPMSK_OTEPDM		(1 << 4)
#define OTG_HS_DOEPMSK_STUPM		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_HS_DOEPMSK_EPDM		(1 << 1)
#define OTG_HS_DOEPMSK_XFRCM		(1 << 0)

/* OTG_FS Device Control IN Endpoint 0 Control Register (OTG_HS_DIEPCTL0) */
#define OTG_HS_DIEPCTL0_EPENA		(1 << 31)
#define OTG_HS_DIEPCTL0_EPDIS		(1 << 30)
/* Bits 29:28 - Reserved */
#define OTG_HS_DIEPCTLX_SD0PID		(1 << 28)
#define OTG_HS_DIEPCTL0_SNAK		(1 << 27)
#define OTG_HS_DIEPCTL0_CNAK		(1 << 26)
#define OTG_HS_DIEPCTL0_TXFNUM_MASK	(0xf << 22)
#define OTG_HS_DIEPCTL0_STALL		(1 << 21)
/* Bit 20 - Reserved */
#define OTG_HS_DIEPCTL0_EPTYP_MASK	(0x3 << 18)
#define OTG_HS_DIEPCTL0_NAKSTS		(1 << 17)
/* Bit 16 - Reserved */
#define OTG_HS_DIEPCTL0_USBAEP		(1 << 15)
/* Bits 14:2 - Reserved */
#define OTG_HS_DIEPCTL0_MPSIZ_MASK	(0x3 << 0)
#define OTG_HS_DIEPCTL0_MPSIZ_64	(0x0 << 0)
#define OTG_HS_DIEPCTL0_MPSIZ_32	(0x1 << 0)
#define OTG_HS_DIEPCTL0_MPSIZ_16	(0x2 << 0)
#define OTG_HS_DIEPCTL0_MPSIZ_8		(0x3 << 0)

/* OTG_FS Device Control OUT Endpoint 0 Control Register (OTG_HS_DOEPCTL0) */
#define OTG_HS_DOEPCTL0_EPENA		(1 << 31)
#define OTG_HS_DOEPCTL0_EPDIS		(1 << 30)
/* Bits 29:28 - Reserved */
#define OTG_HS_DOEPCTLX_SD0PID		(1 << 28)
#define OTG_HS_DOEPCTL0_SNAK		(1 << 27)
#define OTG_HS_DOEPCTL0_CNAK		(1 << 26)
/* Bits 25:22 - Reserved */
#define OTG_HS_DOEPCTL0_STALL		(1 << 21)
#define OTG_HS_DOEPCTL0_SNPM		(1 << 20)
#define OTG_HS_DOEPCTL0_EPTYP_MASK	(0x3 << 18)
#define OTG_HS_DOEPCTL0_NAKSTS		(1 << 17)
/* Bit 16 - Reserved */
#define OTG_HS_DOEPCTL0_USBAEP		(1 << 15)
/* Bits 14:2 - Reserved */
#define OTG_HS_DOEPCTL0_MPSIZ_MASK	(0x3 << 0)
#define OTG_HS_DOEPCTL0_MPSIZ_64	(0x0 << 0)
#define OTG_HS_DOEPCTL0_MPSIZ_32	(0x1 << 0)
#define OTG_HS_DOEPCTL0_MPSIZ_16	(0x2 << 0)
#define OTG_HS_DOEPCTL0_MPSIZ_8		(0x3 << 0)

/* OTG_FS Device IN Endpoint Interrupt Register (OTG_HS_DIEPINTx) */
/* Bits 31:8 - Reserved */
#define OTG_HS_DIEPINTX_TXFE		(1 << 7)
#define OTG_HS_DIEPINTX_INEPNE		(1 << 6)
/* Bit 5 - Reserved */
#define OTG_HS_DIEPINTX_ITTXFE		(1 << 4)
#define OTG_HS_DIEPINTX_TOC		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_HS_DIEPINTX_EPDISD		(1 << 1)
#define OTG_HS_DIEPINTX_XFRC		(1 << 0)

/* OTG_FS Device IN Endpoint Interrupt Register (OTG_HS_DOEPINTx) */
/* Bits 31:7 - Reserved */
#define OTG_HS_DOEPINTX_B2BSTUP		(1 << 6)
/* Bit 5 - Reserved */
#define OTG_HS_DOEPINTX_OTEPDIS		(1 << 4)
#define OTG_HS_DOEPINTX_STUP		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_HS_DOEPINTX_EPDISD		(1 << 1)
#define OTG_HS_DOEPINTX_XFRC		(1 << 0)

/* OTG_FS Device OUT Endpoint 0 Transfer Size Regsiter (OTG_HS_DOEPTSIZ0) */
/* Bit 31 - Reserved */
#define OTG_HS_DIEPSIZ0_STUPCNT_1	(0x1 << 29)
#define OTG_HS_DIEPSIZ0_STUPCNT_2	(0x2 << 29)
#define OTG_HS_DIEPSIZ0_STUPCNT_3	(0x3 << 29)
#define OTG_HS_DIEPSIZ0_STUPCNT_MASK	(0x3 << 29)
/* Bits 28:20 - Reserved */
#define OTG_HS_DIEPSIZ0_PKTCNT		(1 << 19)
/* Bits 18:7 - Reserved */
#define OTG_HS_DIEPSIZ0_XFRSIZ_MASK	(0x7f << 0)

#endif

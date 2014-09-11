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

/*
 * This file covers definitions for the USB OTG FS peripheral.
 * This is the USB core included in the F105, F107, F2, F4 devices
 */

#ifndef LIBOPENCM3_OTG_FS_H
#define LIBOPENCM3_OTG_FS_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/stm32/otg_common.h>

/***********************************************************************/

/* Core Global Control and Status Registers */
#define OTG_FS_GOTGCTL			MMIO32(USB_OTG_FS_BASE + OTG_GOTGCTL)
#define OTG_FS_GOTGINT			MMIO32(USB_OTG_FS_BASE + OTG_GOTGINT)
#define OTG_FS_GAHBCFG			MMIO32(USB_OTG_FS_BASE + OTG_GAHBCFG)
#define OTG_FS_GUSBCFG			MMIO32(USB_OTG_FS_BASE + OTG_GUSBCFG)
#define OTG_FS_GRSTCTL			MMIO32(USB_OTG_FS_BASE + OTG_GRSTCTL)
#define OTG_FS_GINTSTS			MMIO32(USB_OTG_FS_BASE + OTG_GINTSTS)
#define OTG_FS_GINTMSK			MMIO32(USB_OTG_FS_BASE + OTG_GINTMSK)
#define OTG_FS_GRXSTSR			MMIO32(USB_OTG_FS_BASE + OTG_GRXSTSR)
#define OTG_FS_GRXSTSP			MMIO32(USB_OTG_FS_BASE + OTG_GRXSTSP)
#define OTG_FS_GRXFSIZ			MMIO32(USB_OTG_FS_BASE + OTG_GRXFSIZ)
#define OTG_FS_GNPTXFSIZ		MMIO32(USB_OTG_FS_BASE + OTG_GNPTXFSIZ)
#define OTG_FS_GNPTXSTS			MMIO32(USB_OTG_FS_BASE + OTG_GNPTXSTS)
#define OTG_FS_GCCFG			MMIO32(USB_OTG_FS_BASE + OTG_GCCFG)
#define OTG_FS_CID			MMIO32(USB_OTG_FS_BASE + OTG_CID)
#define OTG_FS_HPTXFSIZ			MMIO32(USB_OTG_FS_BASE + OTG_HPTXFSIZ)
#define OTG_FS_DIEPTXF(x)		MMIO32(USB_OTG_FS_BASE + OTG_DIEPTXF(x))


/* Host-mode Control and Status Registers */
#define OTG_FS_HCFG			MMIO32(USB_OTG_FS_BASE + OTG_HCFG)
#define OTG_FS_HFIR			MMIO32(USB_OTG_FS_BASE + OTG_HFIR)
#define OTG_FS_HFNUM			MMIO32(USB_OTG_FS_BASE + OTG_HFNUM)
#define OTG_FS_HPTXSTS			MMIO32(USB_OTG_FS_BASE + OTG_HPTXSTS)
#define OTG_FS_HAINT			MMIO32(USB_OTG_FS_BASE + OTG_HAINT)
#define OTG_FS_HAINTMSK			MMIO32(USB_OTG_FS_BASE + OTG_HAINTMSK)
#define OTG_FS_HPRT			MMIO32(USB_OTG_FS_BASE + OTG_HPRT)
#define OTG_FS_HCCHAR(x)		MMIO32(USB_OTG_FS_BASE + OTG_HCCHAR(x))
#define OTG_FS_HCINT(x)			MMIO32(USB_OTG_FS_BASE + OTG_HCINT(x))
#define OTG_FS_HCINTMSK(x)		MMIO32(USB_OTG_FS_BASE + OTG_HCINTMSK(x))
#define OTG_FS_HCTSIZ(x)		MMIO32(USB_OTG_FS_BASE + OTG_HCTSIZ(x))

/* Device-mode Control and Status Registers */
#define OTG_FS_DCFG			MMIO32(USB_OTG_FS_BASE + OTG_DCFG)
#define OTG_FS_DCTL			MMIO32(USB_OTG_FS_BASE + OTG_DCTL)
#define OTG_FS_DSTS			MMIO32(USB_OTG_FS_BASE + OTG_DSTS)
#define OTG_FS_DIEPMSK			MMIO32(USB_OTG_FS_BASE + OTG_DIEPMSK)
#define OTG_FS_DOEPMSK			MMIO32(USB_OTG_FS_BASE + OTG_DOEPMSK)
#define OTG_FS_DAINT			MMIO32(USB_OTG_FS_BASE + OTG_DAINT)
#define OTG_FS_DAINTMSK			MMIO32(USB_OTG_FS_BASE + OTG_DAINTMSK)
#define OTG_FS_DVBUSDIS			MMIO32(USB_OTG_FS_BASE + OTG_DVBUSDIS)
#define OTG_FS_DVBUSPULSE		MMIO32(USB_OTG_FS_BASE + OTG_DVBUSPULSE)
#define OTG_FS_DIEPEMPMSK		MMIO32(USB_OTG_FS_BASE + OTG_DIEPEMPMSK)
#define OTG_FS_DIEPCTL0			MMIO32(USB_OTG_FS_BASE + OTG_DIEPCTL0)
#define OTG_FS_DIEPCTL(x)		MMIO32(USB_OTG_FS_BASE + OTG_DIEPCTL(x))
#define OTG_FS_DOEPCTL0			MMIO32(USB_OTG_FS_BASE + OTG_DOEPCTL0)
#define OTG_FS_DOEPCTL(x)		MMIO32(USB_OTG_FS_BASE + OTG_DOEPCTL(x))
#define OTG_FS_DIEPINT(x)		MMIO32(USB_OTG_FS_BASE + OTG_DIEPINT(x))
#define OTG_FS_DOEPINT(x)		MMIO32(USB_OTG_FS_BASE + OTG_DOEPINT(x))
#define OTG_FS_DIEPTSIZ0		MMIO32(USB_OTG_FS_BASE + OTG_DIEPTSIZ0)
#define OTG_FS_DOEPTSIZ0		MMIO32(USB_OTG_FS_BASE + OTG_DOEPTSIZ0)
#define OTG_FS_DIEPTSIZ(x)		MMIO32(USB_OTG_FS_BASE + OTG_DIEPTSIZ(x))
#define OTG_FS_DTXFSTS(x)		MMIO32(USB_OTG_FS_BASE + OTG_DTXFSTS(x))
#define OTG_FS_DOEPTSIZ(x)		MMIO32(USB_OTG_FS_BASE + OTG_DOEPTSIZ(x))

/* Power and clock gating control and status register */
#define OTG_FS_PCGCCTL			MMIO32(USB_OTG_FS_BASE + OTG_PCGCCTL)

/* Data FIFO */
#define OTG_FS_FIFO(x)			(&MMIO32(USB_OTG_FS_BASE \
							      + (((x) + 1) \
								 << 12)))

/* Global CSRs */
/* OTG_FS USB control registers (OTG_FS_GOTGCTL) */
#define OTG_FS_GOTGCTL_BSVLD		(1 << 19)
#define OTG_FS_GOTGCTL_ASVLD		(1 << 18)
#define OTG_FS_GOTGCTL_DBCT		(1 << 17)
#define OTG_FS_GOTGCTL_CIDSTS		(1 << 16)
#define OTG_FS_GOTGCTL_DHNPEN		(1 << 11)
#define OTG_FS_GOTGCTL_HSHNPEN		(1 << 10)
#define OTG_FS_GOTGCTL_HNPRQ		(1 << 9)
#define OTG_FS_GOTGCTL_HNGSCS		(1 << 8)
#define OTG_FS_GOTGCTL_SRQ		(1 << 1)
#define OTG_FS_GOTGCTL_SRQSCS		(1 << 0)

/* OTG_FS AHB configuration register (OTG_FS_GAHBCFG) */
#define OTG_FS_GAHBCFG_GINT		0x0001
#define OTG_FS_GAHBCFG_TXFELVL		0x0080
#define OTG_FS_GAHBCFG_PTXFELVL		0x0100

/* OTG_FS USB configuration register (OTG_FS_GUSBCFG) */
#define OTG_FS_GUSBCFG_TOCAL		0x00000003
#define OTG_FS_GUSBCFG_SRPCAP		0x00000100
#define OTG_FS_GUSBCFG_HNPCAP		0x00000200
#define OTG_FS_GUSBCFG_TRDT_MASK	(0xf << 10)
#define OTG_FS_GUSBCFG_TRDT_16BIT	(0x5 << 10)
#define OTG_FS_GUSBCFG_TRDT_8BIT	(0x9 << 10)
#define OTG_FS_GUSBCFG_NPTXRWEN		0x00004000
#define OTG_FS_GUSBCFG_FHMOD		0x20000000
#define OTG_FS_GUSBCFG_FDMOD		0x40000000
#define OTG_FS_GUSBCFG_CTXPKT		0x80000000
#define OTG_FS_GUSBCFG_PHYSEL		(1 << 7)

/* OTG_FS reset register (OTG_FS_GRSTCTL) */
#define OTG_FS_GRSTCTL_AHBIDL		(1 << 31)
/* Bits 30:11 - Reserved */
#define OTG_FS_GRSTCTL_TXFNUM_MASK	(0x1f << 6)
#define OTG_FS_GRSTCTL_TXFFLSH		(1 << 5)
#define OTG_FS_GRSTCTL_RXFFLSH		(1 << 4)
/* Bit 3 - Reserved */
#define OTG_FS_GRSTCTL_FCRST		(1 << 2)
#define OTG_FS_GRSTCTL_HSRST		(1 << 1)
#define OTG_FS_GRSTCTL_CSRST		(1 << 0)

/* OTG_FS interrupt status register (OTG_FS_GINTSTS) */
#define OTG_FS_GINTSTS_WKUPINT		(1 << 31)
#define OTG_FS_GINTSTS_SRQINT		(1 << 30)
#define OTG_FS_GINTSTS_DISCINT		(1 << 29)
#define OTG_FS_GINTSTS_CIDSCHG		(1 << 28)
/* Bit 27 - Reserved */
#define OTG_FS_GINTSTS_PTXFE		(1 << 26)
#define OTG_FS_GINTSTS_HCINT		(1 << 25)
#define OTG_FS_GINTSTS_HPRTINT		(1 << 24)
/* Bits 23:22 - Reserved */
#define OTG_FS_GINTSTS_IPXFR		(1 << 21)
#define OTG_FS_GINTSTS_INCOMPISOOUT	(1 << 21)
#define OTG_FS_GINTSTS_IISOIXFR		(1 << 20)
#define OTG_FS_GINTSTS_OEPINT		(1 << 19)
#define OTG_FS_GINTSTS_IEPINT		(1 << 18)
/* Bits 17:16 - Reserved */
#define OTG_FS_GINTSTS_EOPF		(1 << 15)
#define OTG_FS_GINTSTS_ISOODRP		(1 << 14)
#define OTG_FS_GINTSTS_ENUMDNE		(1 << 13)
#define OTG_FS_GINTSTS_USBRST		(1 << 12)
#define OTG_FS_GINTSTS_USBSUSP		(1 << 11)
#define OTG_FS_GINTSTS_ESUSP		(1 << 10)
/* Bits 9:8 - Reserved */
#define OTG_FS_GINTSTS_GONAKEFF		(1 << 7)
#define OTG_FS_GINTSTS_GINAKEFF		(1 << 6)
#define OTG_FS_GINTSTS_NPTXFE		(1 << 5)
#define OTG_FS_GINTSTS_RXFLVL		(1 << 4)
#define OTG_FS_GINTSTS_SOF		(1 << 3)
#define OTG_FS_GINTSTS_OTGINT		(1 << 2)
#define OTG_FS_GINTSTS_MMIS		(1 << 1)
#define OTG_FS_GINTSTS_CMOD		(1 << 0)

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

/* OTG_FS Receive Status Pop Register (OTG_FS_GRXSTSP) */
/* Bits 31:25 - Reserved */
#define OTG_FS_GRXSTSP_FRMNUM_MASK		(0xf << 21)
#define OTG_FS_GRXSTSP_PKTSTS_MASK		(0xf << 17)
#define OTG_FS_GRXSTSP_PKTSTS_GOUTNAK		(0x1 << 17)
#define OTG_FS_GRXSTSP_PKTSTS_OUT		(0x2 << 17)
#define OTG_FS_GRXSTSP_PKTSTS_IN		(0x2 << 17)
#define OTG_FS_GRXSTSP_PKTSTS_OUT_COMP		(0x3 << 17)
#define OTG_FS_GRXSTSP_PKTSTS_IN_COMP		(0x3 << 17)
#define OTG_FS_GRXSTSP_PKTSTS_SETUP_COMP	(0x4 << 17)
#define OTG_FS_GRXSTSP_PKTSTS_DTERR		(0x5 << 17)
#define OTG_FS_GRXSTSP_PKTSTS_SETUP		(0x6 << 17)
#define OTG_FS_GRXSTSP_PKTSTS_CHH		(0x7 << 17)
#define OTG_FS_GRXSTSP_DPID_MASK		(0x3 << 15)
#define OTG_FS_GRXSTSP_DPID_DATA0		(0x0 << 15)
#define OTG_FS_GRXSTSP_DPID_DATA1		(0x2 << 15)
#define OTG_FS_GRXSTSP_DPID_DATA2		(0x1 << 15)
#define OTG_FS_GRXSTSP_DPID_MDATA		(0x3 << 15)
#define OTG_FS_GRXSTSP_BCNT_MASK		(0x7ff << 4)
#define OTG_FS_GRXSTSP_EPNUM_MASK		(0xf << 0)

/* OTG_FS general core configuration register (OTG_FS_GCCFG) */
/* Bits 31:22 - Reserved */
#define OTG_FS_GCCFG_NOVBUSSENS		(1 << 21)
#define OTG_FS_GCCFG_SOFOUTEN		(1 << 20)
#define OTG_FS_GCCFG_VBUSBSEN		(1 << 19)
#define OTG_FS_GCCFG_VBUSASEN		(1 << 18)
/* Bit 17 - Reserved */
#define OTG_FS_GCCFG_PWRDWN		(1 << 16)
/* Bits 15:0 - Reserved */


/* Device-mode CSRs */
/* OTG_FS device control register (OTG_FS_DCTL) */
/* Bits 31:12 - Reserved */
#define OTG_FS_DCTL_POPRGDNE		(1 << 11)
#define OTG_FS_DCTL_CGONAK		(1 << 10)
#define OTG_FS_DCTL_SGONAK		(1 << 9)
#define OTG_FS_DCTL_SGINAK		(1 << 8)
#define OTG_FS_DCTL_TCTL_MASK		(7 << 4)
#define OTG_FS_DCTL_GONSTS		(1 << 3)
#define OTG_FS_DCTL_GINSTS		(1 << 2)
#define OTG_FS_DCTL_SDIS		(1 << 1)
#define OTG_FS_DCTL_RWUSIG		(1 << 0)

/* OTG_FS device configuration register (OTG_FS_DCFG) */
#define OTG_FS_DCFG_DSPD		0x0003
#define OTG_FS_DCFG_NZLSOHSK		0x0004
#define OTG_FS_DCFG_DAD			0x07F0
#define OTG_FS_DCFG_PFIVL		0x1800

/* OTG_FS Device IN Endpoint Common Interrupt Mask Register (OTG_FS_DIEPMSK) */
/* Bits 31:10 - Reserved */
#define OTG_FS_DIEPMSK_BIM		(1 << 9)
#define OTG_FS_DIEPMSK_TXFURM		(1 << 8)
/* Bit 7 - Reserved */
#define OTG_FS_DIEPMSK_INEPNEM		(1 << 6)
#define OTG_FS_DIEPMSK_INEPNMM		(1 << 5)
#define OTG_FS_DIEPMSK_ITTXFEMSK	(1 << 4)
#define OTG_FS_DIEPMSK_TOM		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_FS_DIEPMSK_EPDM		(1 << 1)
#define OTG_FS_DIEPMSK_XFRCM		(1 << 0)

/* OTG_FS Device OUT Endpoint Common Interrupt Mask Register (OTG_FS_DOEPMSK) */
/* Bits 31:10 - Reserved */
#define OTG_FS_DOEPMSK_BOIM		(1 << 9)
#define OTG_FS_DOEPMSK_OPEM		(1 << 8)
/* Bit 7 - Reserved */
#define OTG_FS_DOEPMSK_B2BSTUP		(1 << 6)
/* Bit 5 - Reserved */
#define OTG_FS_DOEPMSK_OTEPDM		(1 << 4)
#define OTG_FS_DOEPMSK_STUPM		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_FS_DOEPMSK_EPDM		(1 << 1)
#define OTG_FS_DOEPMSK_XFRCM		(1 << 0)

/* OTG_FS Device Control IN Endpoint 0 Control Register (OTG_FS_DIEPCTL0) */
#define OTG_FS_DIEPCTL0_EPENA		(1 << 31)
#define OTG_FS_DIEPCTL0_EPDIS		(1 << 30)
/* Bits 29:28 - Reserved */
#define OTG_FS_DIEPCTLX_SD0PID		(1 << 28)
#define OTG_FS_DIEPCTL0_SNAK		(1 << 27)
#define OTG_FS_DIEPCTL0_CNAK		(1 << 26)
#define OTG_FS_DIEPCTL0_TXFNUM_MASK	(0xf << 22)
#define OTG_FS_DIEPCTL0_STALL		(1 << 21)
/* Bit 20 - Reserved */
#define OTG_FS_DIEPCTL0_EPTYP_MASK	(0x3 << 18)
#define OTG_FS_DIEPCTL0_NAKSTS		(1 << 17)
/* Bit 16 - Reserved */
#define OTG_FS_DIEPCTL0_USBAEP		(1 << 15)
/* Bits 14:2 - Reserved */
#define OTG_FS_DIEPCTL0_MPSIZ_MASK	(0x3 << 0)
#define OTG_FS_DIEPCTL0_MPSIZ_64	(0x0 << 0)
#define OTG_FS_DIEPCTL0_MPSIZ_32	(0x1 << 0)
#define OTG_FS_DIEPCTL0_MPSIZ_16	(0x2 << 0)
#define OTG_FS_DIEPCTL0_MPSIZ_8		(0x3 << 0)

/* OTG_FS Device Control OUT Endpoint 0 Control Register (OTG_FS_DOEPCTL0) */
#define OTG_FS_DOEPCTL0_EPENA		(1 << 31)
#define OTG_FS_DOEPCTL0_EPDIS		(1 << 30)
/* Bits 29:28 - Reserved */
#define OTG_FS_DOEPCTLX_SD0PID		(1 << 28)
#define OTG_FS_DOEPCTL0_SNAK		(1 << 27)
#define OTG_FS_DOEPCTL0_CNAK		(1 << 26)
/* Bits 25:22 - Reserved */
#define OTG_FS_DOEPCTL0_STALL		(1 << 21)
#define OTG_FS_DOEPCTL0_SNPM		(1 << 20)
#define OTG_FS_DOEPCTL0_EPTYP_MASK	(0x3 << 18)
#define OTG_FS_DOEPCTL0_NAKSTS		(1 << 17)
/* Bit 16 - Reserved */
#define OTG_FS_DOEPCTL0_USBAEP		(1 << 15)
/* Bits 14:2 - Reserved */
#define OTG_FS_DOEPCTL0_MPSIZ_MASK	(0x3 << 0)
#define OTG_FS_DOEPCTL0_MPSIZ_64	(0x0 << 0)
#define OTG_FS_DOEPCTL0_MPSIZ_32	(0x1 << 0)
#define OTG_FS_DOEPCTL0_MPSIZ_16	(0x2 << 0)
#define OTG_FS_DOEPCTL0_MPSIZ_8		(0x3 << 0)

/* OTG_FS Device IN Endpoint Interrupt Register (OTG_FS_DIEPINTx) */
/* Bits 31:8 - Reserved */
#define OTG_FS_DIEPINTX_TXFE		(1 << 7)
#define OTG_FS_DIEPINTX_INEPNE		(1 << 6)
/* Bit 5 - Reserved */
#define OTG_FS_DIEPINTX_ITTXFE		(1 << 4)
#define OTG_FS_DIEPINTX_TOC		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_FS_DIEPINTX_EPDISD		(1 << 1)
#define OTG_FS_DIEPINTX_XFRC		(1 << 0)

/* OTG_FS Device IN Endpoint Interrupt Register (OTG_FS_DOEPINTx) */
/* Bits 31:7 - Reserved */
#define OTG_FS_DOEPINTX_B2BSTUP		(1 << 6)
/* Bit 5 - Reserved */
#define OTG_FS_DOEPINTX_OTEPDIS		(1 << 4)
#define OTG_FS_DOEPINTX_STUP		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_FS_DOEPINTX_EPDISD		(1 << 1)
#define OTG_FS_DOEPINTX_XFRC		(1 << 0)

/* OTG_FS Device OUT Endpoint 0 Transfer Size Register (OTG_FS_DOEPTSIZ0) */
/* Bit 31 - Reserved */
#define OTG_FS_DIEPSIZ0_STUPCNT_1	(0x1 << 29)
#define OTG_FS_DIEPSIZ0_STUPCNT_2	(0x2 << 29)
#define OTG_FS_DIEPSIZ0_STUPCNT_3	(0x3 << 29)
#define OTG_FS_DIEPSIZ0_STUPCNT_MASK	(0x3 << 29)
/* Bits 28:20 - Reserved */
#define OTG_FS_DIEPSIZ0_PKTCNT		(1 << 19)
/* Bits 18:7 - Reserved */
#define OTG_FS_DIEPSIZ0_XFRSIZ_MASK	(0x7f << 0)



/* Host-mode CSRs */
/* OTG_FS Host non-periodic transmit FIFO size register
(OTG_FS_HNPTXFSIZ)/Endpoint 0 Transmit FIFO size (OTG_FS_DIEPTXF0) */
#define OTG_FS_HNPTXFSIZ_PTXFD_MASK	(0xffff0000)
#define OTG_FS_HNPTXFSIZ_PTXSA_MASK	(0x0000ffff)

/* OTG_FS Host periodic transmit FIFO size register (OTG_FS_HPTXFSIZ) */
#define OTG_FS_HPTXFSIZ_PTXFD_MASK	(0xffff0000)
#define OTG_FS_HPTXFSIZ_PTXSA_MASK	(0x0000ffff)

/* OTG_FS Host Configuration Register (OTG_FS_HCFG) */
/* Bits 31:3 - Reserved */
#define OTG_FS_HCFG_FSLSS		(1 << 2)
#define OTG_FS_HCFG_FSLSPCS_48MHz	(0x1 << 0)
#define OTG_FS_HCFG_FSLSPCS_6MHz	(0x2 << 0)
#define OTG_FS_HCFG_FSLSPCS_MASK	(0x3 << 0)

/* OTG_FS Host Frame Interval Register (OTG_FS_HFIR) */
/* Bits 31:16 - Reserved */
#define OTG_FS_HFIR_FRIVL_MASK		(0x0000ffff)

/* OTG_FS Host frame number/frame time remaining register (OTG_FS_HFNUM) */
#define OTG_FS_HFNUM_FTREM_MASK		(0xffff0000)
#define OTG_FS_HFNUM_FRNUM_MASK		(0x0000ffff)

/* OTG_FS Host periodic transmit FIFO/queue status register (OTG_FS_HPTXSTS) */
#define OTG_FS_HPTXSTS_PTXQTOP_MASK			(0xff000000)
#define OTG_FS_HPTXSTS_PTXQTOP_ODDFRM			(1<<31)
#define OTG_FS_HPTXSTS_PTXQTOP_EVENFRM			(0<<31)
#define OTG_FS_HPTXSTS_PTXQTOP_CHANNEL_NUMBER_MASK	(0xf<<27)
#define OTG_FS_HPTXSTS_PTXQTOP_ENDPOINT_NUMBER_MASK	(0xf<<27)
#define OTG_FS_HPTXSTS_PTXQTOP_TYPE_INOUT		(0x00<<25)
#define OTG_FS_HPTXSTS_PTXQTOP_TYPE_ZEROLENGTH		(0x01<<25)
#define OTG_FS_HPTXSTS_PTXQTOP_TYPE_DISABLECMD		(0x11<<25)
#define OTG_FS_HPTXSTS_PTXQTOP_TERMINATE		(1<<24)
#define OTG_FS_HPTXSTS_PTXQSAV_MASK			(0x00ff0000)
#define OTG_FS_HPTXSTS_PTXFSAVL_MASK			(0x0000ffff)

/* OTG_FS Host all channels interrupt mask register (OTG_FS_HAINT) */
/* Bits 31:16 - Reserved */
#define OTG_FS_HAINTMSK_HAINT_MASK	(0x0000ffff)

/* OTG_FS Host all channels interrupt mask register (OTG_FS_HAINTMSK) */
/* Bits 31:16 - Reserved */
#define OTG_FS_HAINTMSK_HAINTM_MASK	(0x0000ffff)

/* OTG_FS Host port control and status register (OTG_FS_HPRT) */
/* Bits 31:19 - Reserved */
#define OTG_FS_HPRT_PSPD_FULL		(0x1 << 17)
#define OTG_FS_HPRT_PSPD_LOW		(0x2 << 17)
#define OTG_FS_HPRT_PSPD_MASK		(0x3 << 17)
#define OTG_FS_HPRT_PTCTL_DISABLED	(0x0 << 13)
#define OTG_FS_HPRT_PTCTL_J		(0x1 << 13)
#define OTG_FS_HPRT_PTCTL_K		(0x2 << 13)
#define OTG_FS_HPRT_PTCTL_SE0_NAK	(0x3 << 13)
#define OTG_FS_HPRT_PTCTL_PACKET	(0x4 << 13)
#define OTG_FS_HPRT_PTCTL_FORCE_ENABLE	(0x5 << 13)
#define OTG_FS_HPRT_PPWR		(1 << 12)
#define OTG_FS_HPRT_PLSTS_DM		(1 << 11)
#define OTG_FS_HPRT_PLSTS_DP		(1 << 10)
/* Bit 9 - Reserved */
#define OTG_FS_HPRT_PRST		(1 << 8)
#define OTG_FS_HPRT_PSUSP		(1 << 7)
#define OTG_FS_HPRT_PRES		(1 << 6)
#define OTG_FS_HPRT_POCCHNG		(1 << 5)
#define OTG_FS_HPRT_POCA		(1 << 4)
#define OTG_FS_HPRT_PENCHNG		(1 << 3)
#define OTG_FS_HPRT_PENA		(1 << 2)
#define OTG_FS_HPRT_PCDET		(1 << 1)
#define OTG_FS_HPRT_PCSTS		(1 << 0)

/* OTG_FS Host channel-x characteristics register (OTG_FS_HCCHARx) */
#define OTG_FS_HCCHAR_CHENA		(1 << 31)
#define OTG_FS_HCCHAR_CHDIS		(1 << 30)
#define OTG_FS_HCCHAR_ODDFRM		(1 << 29)
#define OTG_FS_HCCHAR_DAD_MASK		(0x7f << 22)
#define OTG_FS_HCCHAR_MCNT_1		(0x1 << 20)
#define OTG_FS_HCCHAR_MCNT_2		(0x2 << 20)
#define OTG_FS_HCCHAR_MCNT_3		(0x3 << 20)
#define OTG_FS_HCCHAR_MCNT_MASK		(0x3 << 20)
#define OTG_FS_HCCHAR_EPTYP_CONTROL	(0 << 18)
#define OTG_FS_HCCHAR_EPTYP_ISOCHRONOUS	(1 << 18)
#define OTG_FS_HCCHAR_EPTYP_BULK	(2 << 18)
#define OTG_FS_HCCHAR_EPTYP_INTERRUPT	(3 << 18)
#define OTG_FS_HCCHAR_EPTYP_MASK	(3 << 18)
#define OTG_FS_HCCHAR_LSDEV		(1 << 17)
/* Bit 16 - Reserved */
#define OTG_FS_HCCHAR_EPDIR_OUT		(0 << 15)
#define OTG_FS_HCCHAR_EPDIR_IN		(1 << 15)
#define OTG_FS_HCCHAR_EPDIR_MASK	(1 << 15)
#define OTG_FS_HCCHAR_EPNUM_MASK	(0xf << 11)
#define OTG_FS_HCCHAR_MPSIZ_MASK	(0x7ff << 0)

/* OTG_FS Host channel-x interrupt register (OTG_FS_HCINTx) */
/* Bits 31:11 - Reserved */
#define OTG_FS_HCINT_DTERR		(1 << 10)
#define OTG_FS_HCINT_FRMOR		(1 << 9)
#define OTG_FS_HCINT_BBERR		(1 << 8)
#define OTG_FS_HCINT_TXERR		(1 << 7)
/* Bit 6 - Reserved */
#define OTG_FS_HCINT_ACK		(1 << 5)
#define OTG_FS_HCINT_NAK		(1 << 4)
#define OTG_FS_HCINT_STALL		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_FS_HCINT_CHH		(1 << 1)
#define OTG_FS_HCINT_XFRC		(1 << 0)

/* OTG_FS Host channel-x interrupt mask register (OTG_FS_HCINTMSKx) */
/* Bits 31:11 - Reserved */
#define OTG_FS_HCINTMSK_DTERRM		(1 << 10)
#define OTG_FS_HCINTMSK_FRMORM		(1 << 9)
#define OTG_FS_HCINTMSK_BBERRM		(1 << 8)
#define OTG_FS_HCINTMSK_TXERRM		(1 << 7)
/* Bit 6 - Reserved */
#define OTG_FS_HCINTMSK_ACKM		(1 << 5)
#define OTG_FS_HCINTMSK_NAKM		(1 << 4)
#define OTG_FS_HCINTMSK_STALLM		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_FS_HCINTMSK_CHHM		(1 << 1)
#define OTG_FS_HCINTMSK_XFRCM		(1 << 0)

/* OTG_FS Host channel-x transfer size register (OTG_FS_HCTSIZx) */
/* Bit 31 - Reserved */
#define OTG_FS_HCTSIZ_DPID_DATA0	(0x0 << 29)
#define OTG_FS_HCTSIZ_DPID_DATA1	(0x2 << 29)
#define OTG_FS_HCTSIZ_DPID_DATA2	(0x1 << 29)
#define OTG_FS_HCTSIZ_DPID_MDATA	(0x3 << 29)
#define OTG_FS_HCTSIZ_DPID_MASK		(0x3 << 29)
#define OTG_FS_HCTSIZ_PKTCNT_MASK	(0x3ff << 19)
#define OTG_FS_HCTSIZ_XFRSIZ_MASK	(0x7ffff << 0)

#endif

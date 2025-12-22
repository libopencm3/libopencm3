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
 * This file is intended to be included by either otg_hs.h or otg_fs.h
 * It contains register definitions common to chips using DesignWare
 * USB OTG controllers, including STM32 and EFM32
 */

#ifndef LIBOPENCM3_USB_DWC_OTG_COMMON_H
#define LIBOPENCM3_USB_DWC_OTG_COMMON_H

/* Core Global Control and Status Registers */
#define OTG_GOTGCTL			0x000U
#define OTG_GOTGINT			0x004U
#define OTG_GAHBCFG			0x008U
#define OTG_GUSBCFG			0x00CU
#define OTG_GRSTCTL			0x010U
#define OTG_GINTSTS			0x014U
#define OTG_GINTMSK			0x018U
#define OTG_GRXSTSR			0x01CU
#define OTG_GRXSTSP			0x020U
#define OTG_GRXFSIZ			0x024U
#define OTG_GNPTXFSIZ			0x028U
#define OTG_GNPTXSTS			0x02CU
#define OTG_GCCFG			0x038U
#define OTG_CID				0x03CU
#define OTG_HPTXFSIZ			0x100U
#define OTG_DIEPTXF(x)			(0x104U + 4*((x)-1))

/* Host-mode Control and Status Registers */
#define OTG_HCFG			0x400U
#define OTG_HFIR			0x404U
#define OTG_HFNUM			0x408U
#define OTG_HPTXSTS			0x410U
#define OTG_HAINT			0x414U
#define OTG_HAINTMSK			0x418U
#define OTG_HPRT			0x440U
#define OTG_HCCHAR(x)			(0x500U + 0x20*(x))
#define OTG_HCINT(x)			(0x508U + 0x20*(x))
#define OTG_HCINTMSK(x)			(0x50CU + 0x20*(x))
#define OTG_HCTSIZ(x)			(0x510U + 0x20*(x))


/* Device-mode Control and Status Registers */
#define OTG_DCFG			0x800U
#define OTG_DCTL			0x804U
#define OTG_DSTS			0x808U
#define OTG_DIEPMSK			0x810U
#define OTG_DOEPMSK			0x814U
#define OTG_DAINT			0x818U
#define OTG_DAINTMSK			0x81CU
#define OTG_DVBUSDIS			0x828U
#define OTG_DVBUSPULSE			0x82CU
#define OTG_DIEPEMPMSK			0x834U

#define OTG_DIEPCTL0			0x900U
#define OTG_DIEPCTL(x)			(0x900U + 0x20*(x))
#define OTG_DOEPCTL0			0xB00U
#define OTG_DOEPCTL(x)			(0xB00U + 0x20*(x))
#define OTG_DIEPINT(x)			(0x908U + 0x20*(x))
#define OTG_DOEPINT(x)			(0xB08U + 0x20*(x))
#define OTG_DIEPTSIZ0			0x910U
#define OTG_DIEPTSIZ(x)			(0x910U + 0x20*(x))
#define OTG_DOEPTSIZ0			0xB10U
#define OTG_DOEPTSIZ(x)			(0xB10U + 0x20*(x))
#define OTG_DTXFSTS(x)			(0x918U + 0x20*(x))

/* Power and clock gating control and status register */
#define OTG_PCGCCTL			0xE00U

/* Data FIFO */
#if defined(STM32H7)
#define OTG_FIFO(x)			(0x1000U * (x + 1U))
#else
#define OTG_FIFO(x)			(((x) + 1U) << 12U)
#endif


/* Global CSRs */
/* OTG USB control registers (OTG_GOTGCTL) */
#define OTG_GOTGCTL_BSVLD		(1U << 19U)
#define OTG_GOTGCTL_ASVLD		(1U << 18U)
#define OTG_GOTGCTL_DBCT		(1U << 17U)
#define OTG_GOTGCTL_CIDSTS		(1U << 16U)
#define OTG_GOTGCTL_DHNPEN		(1U << 11U)
#define OTG_GOTGCTL_HSHNPEN		(1U << 10U)
#define OTG_GOTGCTL_HNPRQ		(1U << 9U)
#define OTG_GOTGCTL_HNGSCS		(1U << 8U)
#define OTG_GOTGCTL_SRQ			(1U << 1U)
#define OTG_GOTGCTL_SRQSCS		(1U << 0U)

/* OTG USB control registers (OTG_GOTGINT) */
#define OTG_GOTGINT_DBCDNE		(1U << 19U)
#define OTG_GOTGINT_ADTOCHG		(1U << 18U)
#define OTG_GOTGINT_HNGDET		(1U << 17U)
#define OTG_GOTGINT_HNSSCHG		(1U << 9U)
#define OTG_GOTGINT_SRSSCHG		(1U << 8U)
#define OTG_GOTGINT_SEDET		(1U << 2U)

/* OTG AHB configuration register (OTG_GAHBCFG) */
#define OTG_GAHBCFG_GINT		(1U << 0U)
#define OTG_GAHBCFG_TXFELVL		(1U << 7U)
#define OTG_GAHBCFG_PTXFELVL		(1U << 8U)

/* OTG USB configuration register (OTG_GUSBCFG) */
#define OTG_GUSBCFG_TOCAL		0x00000003U
#define OTG_GUSBCFG_SRPCAP		(1U << 8U)
#define OTG_GUSBCFG_HNPCAP		(1U << 9U)
#define OTG_GUSBCFG_TRDT_MASK		(0xfU << 10U)
#define OTG_GUSBCFG_NPTXRWEN		(1U << 15U)
#define OTG_GUSBCFG_FHMOD		(1U << 29U)
#define OTG_GUSBCFG_FDMOD		(1U << 30U)
#define OTG_GUSBCFG_CTXPKT		(1U << 31U)
#define OTG_GUSBCFG_PHYSEL		(1U << 6U)

/* OTG reset register (OTG_GRSTCTL) */
#define OTG_GRSTCTL_AHBIDL		(1U << 31U)
/* Bits 30:11 - Reserved */
#define OTG_GRSTCTL_TXFNUM_MASK		(0x1fU << 6U)
#define OTG_GRSTCTL_TXFNUM_ALL		(0x10U << 6U)
#define OTG_GRSTCTL_TXFFLSH		(1U << 5U)
#define OTG_GRSTCTL_RXFFLSH		(1U << 4U)
/* Bit 3 - Reserved */
#define OTG_GRSTCTL_FCRST		(1U << 2U)
#define OTG_GRSTCTL_HSRST		(1U << 1U)
#define OTG_GRSTCTL_CSRST		(1U << 0U)

/* OTG interrupt status register (OTG_GINTSTS) */
#define OTG_GINTSTS_WKUPINT		(1U << 31U)
#define OTG_GINTSTS_SRQINT		(1U << 30U)
#define OTG_GINTSTS_DISCINT		(1U << 29U)
#define OTG_GINTSTS_CIDSCHG		(1U << 28U)
/* Bit 27 - Reserved */
#define OTG_GINTSTS_PTXFE		(1U << 26U)
#define OTG_GINTSTS_HCINT		(1U << 25U)
#define OTG_GINTSTS_HPRTINT		(1U << 24U)
#define OTG_GINTSTS_RSTDET		(1U << 23U)
/* Bit 22 - Reserved */
#define OTG_GINTSTS_IPXFR		(1U << 21U)
#define OTG_GINTSTS_INCOMPISOOUT	(1U << 21U)
#define OTG_GINTSTS_IISOIXFR		(1U << 20U)
#define OTG_GINTSTS_OEPINT		(1U << 19U)
#define OTG_GINTSTS_IEPINT		(1U << 18U)
/* Bits 17:16 - Reserved */
#define OTG_GINTSTS_EOPF		(1U << 15U)
#define OTG_GINTSTS_ISOODRP		(1U << 14U)
#define OTG_GINTSTS_ENUMDNE		(1U << 13U)
#define OTG_GINTSTS_USBRST		(1U << 12U)
#define OTG_GINTSTS_USBSUSP		(1U << 11U)
#define OTG_GINTSTS_ESUSP		(1U << 10U)
/* Bits 9:8 - Reserved */
#define OTG_GINTSTS_GONAKEFF		(1U << 7U)
#define OTG_GINTSTS_GINAKEFF		(1U << 6U)
#define OTG_GINTSTS_NPTXFE		(1U << 5U)
#define OTG_GINTSTS_RXFLVL		(1U << 4U)
#define OTG_GINTSTS_SOF			(1U << 3U)
#define OTG_GINTSTS_OTGINT		(1U << 2U)
#define OTG_GINTSTS_MMIS		(1U << 1U)
#define OTG_GINTSTS_CMOD		(1U << 0U)

/* OTG interrupt mask register (OTG_GINTMSK) */
#define OTG_GINTMSK_MMISM		(1U << 1U)
#define OTG_GINTMSK_OTGINT		(1U << 2U)
#define OTG_GINTMSK_SOFM		(1U << 3U)
#define OTG_GINTMSK_RXFLVLM		(1U << 4U)
#define OTG_GINTMSK_NPTXFEM		(1U << 5U)
#define OTG_GINTMSK_GINAKEFFM		(1U << 6U)
#define OTG_GINTMSK_GONAKEFFM		(1U << 7U)
#define OTG_GINTMSK_ESUSPM		(1U << 10U)
#define OTG_GINTMSK_USBSUSPM		(1U << 11U)
#define OTG_GINTMSK_USBRST		(1U << 12U)
#define OTG_GINTMSK_ENUMDNEM		(1U << 13U)
#define OTG_GINTMSK_ISOODRPM		(1U << 14U)
#define OTG_GINTMSK_EOPFM		(1U << 15U)
#define OTG_GINTMSK_EPMISM		(1U << 17U)
#define OTG_GINTMSK_IEPINT		(1U << 18U)
#define OTG_GINTMSK_OEPINT		(1U << 19U)
#define OTG_GINTMSK_IISOIXFRM		(1U << 20U)
#define OTG_GINTMSK_IISOOXFRM		(1U << 21U)
#define OTG_GINTMSK_IPXFRM		(1U << 21U)
#define OTG_GINTMSK_PRTIM		(1U << 24U)
#define OTG_GINTMSK_HCIM		(1U << 25U)
#define OTG_GINTMSK_PTXFEM		(1U << 26U)
#define OTG_GINTMSK_CIDSCHGM		(1U << 28U)
#define OTG_GINTMSK_DISCINT		(1U << 29U)
#define OTG_GINTMSK_SRQIM		(1U << 30U)
#define OTG_GINTMSK_WUIM		(1U << 31U)

/* OTG Receive Status Pop Register (OTG_GRXSTSP) */
/* Bits 31:25 - Reserved */
#define OTG_GRXSTSP_FRMNUM_MASK		(0xfU << 21U)
#define OTG_GRXSTSP_PKTSTS_MASK		(0xfU << 17U)
#define OTG_GRXSTSP_PKTSTS_GOUTNAK	(0x1U << 17U)
#define OTG_GRXSTSP_PKTSTS_OUT		(0x2U << 17U)
#define OTG_GRXSTSP_PKTSTS_IN		(0x2U << 17U)
#define OTG_GRXSTSP_PKTSTS_OUT_COMP	(0x3U << 17U)
#define OTG_GRXSTSP_PKTSTS_IN_COMP	(0x3U << 17U)
#define OTG_GRXSTSP_PKTSTS_SETUP_COMP	(0x4U << 17U)
#define OTG_GRXSTSP_PKTSTS_DTERR	(0x5U << 17U)
#define OTG_GRXSTSP_PKTSTS_SETUP	(0x6U << 17U)
#define OTG_GRXSTSP_PKTSTS_CHH		(0x7U << 17U)
#define OTG_GRXSTSP_DPID_MASK		(0x3U << 15U)
#define OTG_GRXSTSP_DPID_DATA0		(0x0U << 15U)
#define OTG_GRXSTSP_DPID_DATA1		(0x2U << 15U)
#define OTG_GRXSTSP_DPID_DATA2		(0x1U << 15U)
#define OTG_GRXSTSP_DPID_MDATA		(0x3U << 15U)
#define OTG_GRXSTSP_BCNT_MASK		(0x7ffU << 4U)
#define OTG_GRXSTSP_EPNUM_MASK		(0xfU << 0U)

/* Bits 31:22 - Reserved */
/** Only on cores < 0x2000 */
#define OTG_GCCFG_NOVBUSSENS	(1U << 21U)
/** Only on cores >= 0x2000 */
#define OTG_GCCFG_VBDEN			(1U << 21U)
#define OTG_GCCFG_SOFOUTEN		(1U << 20U)
#define OTG_GCCFG_VBUSBSEN		(1U << 19U)
#define OTG_GCCFG_VBUSASEN		(1U << 18U)
/** Only on cores >= 0x2300 */
#define OTG_GCCFG_SDEN          (1U << 20U)
#define OTG_GCCFG_PDEN          (1U << 19U)
#define OTG_GCCFG_DCDEN         (1U << 18U)
#define OTG_GCCFG_BCDEN         (1U << 17U)
/* Bit 17 - Reserved */
#define OTG_GCCFG_PWRDWN		(1U << 16U)
/* Bits 15:0 - Reserved */

/* OTG FS Product ID register (OTG_CID) */
#define OTG_CID_HAS_VBDEN	0x00002000U

/* Device-mode CSRs */
/* OTG device control register (OTG_DCTL) */
/* Bits 31:12 - Reserved */
#define OTG_DCTL_POPRGDNE	(1U << 11U)
#define OTG_DCTL_CGONAK		(1U << 10U)
#define OTG_DCTL_SGONAK		(1U << 9U)
#define OTG_DCTL_SGINAK		(1U << 8U)
#define OTG_DCTL_TCTL_MASK	(7U << 4U)
#define OTG_DCTL_GONSTS		(1U << 3U)
#define OTG_DCTL_GINSTS		(1U << 2U)
#define OTG_DCTL_SDIS		(1U << 1U)
#define OTG_DCTL_RWUSIG		(1U << 0U)

/* OTG device configuration register (OTG_DCFG) */
#define OTG_DCFG_DSPD		0x00000003U
#define OTG_DCFG_NZLSOHSK	0x00000004U
#define OTG_DCFG_DAD		0x000007F0U
#define OTG_DCFG_PFIVL		0x00001800U

/* OTG device status register (OTG_DSTS) */
#define OTG_DSTS_SUSPSTS	(1U << 0U)

/* OTG Device IN Endpoint Common Interrupt Mask Register (OTG_DIEPMSK) */
/* Bits 31:10 - Reserved */
#define OTG_DIEPMSK_BIM		(1U << 9U)
#define OTG_DIEPMSK_TXFURM	(1U << 8U)
/* Bit 7 - Reserved */
#define OTG_DIEPMSK_INEPNEM	(1U << 6U)
#define OTG_DIEPMSK_INEPNMM	(1U << 5U)
#define OTG_DIEPMSK_ITTXFEMSK	(1U << 4U)
#define OTG_DIEPMSK_TOM		(1U << 3U)
/* Bit 2 - Reserved */
#define OTG_DIEPMSK_EPDM	(1U << 1U)
#define OTG_DIEPMSK_XFRCM	(1U << 0U)

/* OTG Device OUT Endpoint Common Interrupt Mask Register (OTG_DOEPMSK) */
/* Bits 31:10 - Reserved */
#define OTG_DOEPMSK_BOIM	(1U << 9U)
#define OTG_DOEPMSK_OPEM	(1U << 8U)
/* Bit 7 - Reserved */
#define OTG_DOEPMSK_B2BSTUP	(1U << 6U)
#define OTG_DOEPMSK_STSPHSRXM (1U << 5U)
#define OTG_DOEPMSK_OTEPDM	(1U << 4U)
#define OTG_DOEPMSK_STUPM	(1U << 3U)
/* Bit 2 - Reserved */
#define OTG_DOEPMSK_EPDM	(1U << 1U)
#define OTG_DOEPMSK_XFRCM	(1U << 0U)

/* OTG Device IN Endpoint 0 Control Register (OTG_DIEPCTL0) */
#define OTG_DIEPCTL0_EPENA			(1U << 31U)
#define OTG_DIEPCTL0_EPDIS			(1U << 30U)
/* Bits 29:28 - Reserved */
#define OTG_DIEPCTLX_SD0PID			(1U << 28U)
#define OTG_DIEPCTL0_SNAK			(1U << 27U)
#define OTG_DIEPCTL0_CNAK			(1U << 26U)
#define OTG_DIEPCTL0_TXFNUM_MASK	(0xfU << 22U)
#define OTG_DIEPCTL0_STALL			(1U << 21U)
/* Bit 20 - Reserved */
#define OTG_DIEPCTL0_EPTYP_MASK		(0x3U << 18U)
#define OTG_DIEPCTL0_NAKSTS			(1U << 17U)
/* Bit 16 - Reserved */
#define OTG_DIEPCTL0_USBAEP			(1U << 15U)
/* Bits 14:2 - Reserved */
#define OTG_DIEPCTL0_MPSIZ_MASK		(0x3U << 0U)
#define OTG_DIEPCTL0_MPSIZ_64		(0x0U << 0U)
#define OTG_DIEPCTL0_MPSIZ_32		(0x1U << 0U)
#define OTG_DIEPCTL0_MPSIZ_16		(0x2U << 0U)
#define OTG_DIEPCTL0_MPSIZ_8		(0x3U << 0U)

/* OTG Device IN Endpoint X Control Register (OTG_DIEPCTLX) */
#define OTG_DIEPCTLX_EPTYP_SHIFT	18U
#define OTG_DIEPCTLX_TXFNUM_SHIFT	22U
#define OTG_DIEPCTLX_MPSIZ_MASK     (0x000007ffU)

/* OTG Device OUT Endpoint 0 Control Register (OTG_DOEPCTL0) */
#define OTG_DOEPCTL0_EPENA			(1U << 31U)
#define OTG_DOEPCTL0_EPDIS			(1U << 30U)
/* Bits 29:28 - Reserved */
#define OTG_DOEPCTL0_SNAK			(1U << 27U)
#define OTG_DOEPCTL0_CNAK			(1U << 26U)
/* Bits 25:22 - Reserved */
#define OTG_DOEPCTL0_STALL			(1U << 21U)
#define OTG_DOEPCTL0_SNPM			(1U << 20U)
#define OTG_DOEPCTL0_EPTYP_MASK		(0x3U << 18U)
#define OTG_DOEPCTL0_NAKSTS			(1U << 17U)
/* Bit 16 - Reserved */
#define OTG_DOEPCTL0_USBAEP			(1U << 15U)
/* Bits 14:2 - Reserved */
#define OTG_DOEPCTL0_MPSIZ_MASK		(0x3U << 0U)
#define OTG_DOEPCTL0_MPSIZ_64		(0x0U << 0U)
#define OTG_DOEPCTL0_MPSIZ_32		(0x1U << 0U)
#define OTG_DOEPCTL0_MPSIZ_16		(0x2U << 0U)
#define OTG_DOEPCTL0_MPSIZ_8		(0x3U << 0U)

/* OTG Device OUT Endpoint X Control Register (OTG_DOEPCTLX) */
#define OTG_DOEPCTLX_SD1PID			(1U << 29U)
#define OTG_DOEPCTLX_SD0PID			(1U << 28U)
#define OTG_DIEPCTLX_EPTYP_SHIFT	18U
#define OTG_DOEPCTLX_MPSIZ_MASK		(0x000007ffU)

/* OTG Device IN Endpoint Interrupt Register (OTG_DIEPINTx) */
/* Bits 31:8 - Reserved */
#define OTG_DIEPINTX_TXFE			(1U << 7U)
#define OTG_DIEPINTX_INEPNE			(1U << 6U)
/* Bit 5 - Reserved */
#define OTG_DIEPINTX_ITTXFE			(1U << 4U)
#define OTG_DIEPINTX_TOC			(1U << 3U)
/* Bit 2 - Reserved */
#define OTG_DIEPINTX_EPDISD			(1U << 1U)
#define OTG_DIEPINTX_XFRC			(1U << 0U)

/* OTG Device IN Endpoint Interrupt Register (OTG_DOEPINTx) */
/* Bits 31:7 - Reserved */
#define OTG_DOEPINTX_B2BSTUP		(1U << 6U)
/* Bit 5 - Reserved */
#define OTG_DOEPINTX_OTEPDIS		(1U << 4U)
#define OTG_DOEPINTX_STUP			(1U << 3U)
/* Bit 2 - Reserved */
#define OTG_DOEPINTX_EPDISD			(1U << 1U)
#define OTG_DOEPINTX_XFRC			(1U << 0U)

/* OTG Device IN Endpoint 0 Transfer Size Register (OTG_DIEPTSIZ0) */
/* Bits 31:21 - Reserved */
#define OTG_DIEPSIZ0_PKTCNT			(1U << 19U)
/* Bits 18:7 - Reserved */
#define OTG_DIEPSIZ0_XFRSIZ_MASK	(0x0000007fU)

/* OTG Device IN Endpoint X Transfer Size Register (OTG_DIEPTSIZX) */
/* Bit 31 - Reserved */
#define OTG_DIEPSIZX_MCNT_1			(0x1U << 29U)
#define OTG_DIEPSIZX_MCNT_2			(0x2U << 29U)
#define OTG_DIEPSIZX_MCNT_3			(0x3U << 29U)
#define OTG_DIEPSIZX_MCNT_MASK		(0x3U << 29U)
#define OTG_DIEPSIZX_PKTCNT_MASK	(0x1ff80000U)
#define OTG_DIEPSIZX_PKTCNT_SHIFT	(19U)
#define OTG_DIEPSIZX_PKTCNT(x)		(((x) << OTG_DIEPSIZX_PKTCNT_SHIFT) & OTG_DIEPSIZX_PKTCNT_MASK)
#define OTG_DIEPSIZX_XFRSIZ_MASK	(0x0007ffffU)

/* OTG Device OUT Endpoint 0 Transfer Size Register (OTG_DOEPTSIZ0) */
/* Bit 31 - Reserved */
#define OTG_DOEPSIZ0_STUPCNT_1		(0x1U << 29U)
#define OTG_DOEPSIZ0_STUPCNT_2		(0x2U << 29U)
#define OTG_DOEPSIZ0_STUPCNT_3		(0x3U << 29U)
#define OTG_DOEPSIZ0_STUPCNT_MASK	(0x3U << 29U)
/* Bits 28:20 - Reserved */
#define OTG_DOEPSIZ0_PKTCNT			(1U << 19U)
/* Bits 18:7 - Reserved */
#define OTG_DOEPSIZ0_XFRSIZ_MASK	(0x0000007fU)

/* OTG Device OUT Endpoint X Transfer Size Register (OTG_DOEPTSIZX) */
/* Bit 31 - Reserved */
/* Bit 30:29 - RXDPID */
#define OTG_DOEPSIZX_PKTCNT_MASK	(0x1ff80000U)
#define OTG_DOEPSIZX_PKTCNT_SHIFT	(19U)
#define OTG_DOEPSIZX_PKTCNT(x)		(((x) << OTG_DIEPSIZX_PKTCNT_SHIFT) & OTG_DIEPSIZX_PKTCNT_MASK)
#define OTG_DOEPSIZX_XFRSIZ_MASK	(0x0007ffffU)


/* Host-mode CSRs */
/* OTG Host non-periodic transmit FIFO size register
(OTG_HNPTXFSIZ)/Endpoint 0 Transmit FIFO size (OTG_DIEPTXF0) */
#define OTG_HNPTXFSIZ_PTXFD_MASK	(0xffff0000U)
#define OTG_HNPTXFSIZ_PTXSA_MASK	(0x0000ffffU)

/* OTG Host periodic transmit FIFO size register (OTG_HPTXFSIZ) */
#define OTG_HPTXFSIZ_PTXFD_MASK		(0xffff0000U)
#define OTG_HPTXFSIZ_PTXSA_MASK		(0x0000ffffU)

/* OTG Host Configuration Register (OTG_HCFG) */
/* Bits 31:3 - Reserved */
#define OTG_HCFG_FSLSS		(1U << 2U)
#define OTG_HCFG_FSLSPCS_48MHz	(0x1U << 0U)
#define OTG_HCFG_FSLSPCS_6MHz	(0x2U << 0U)
#define OTG_HCFG_FSLSPCS_MASK	(0x3U << 0U)

/* OTG Host Frame Interval Register (OTG_HFIR) */
/* Bits 31:16 - Reserved */
#define OTG_HFIR_FRIVL_MASK		(0x0000ffffU)

/* OTG Host frame number/frame time remaining register (OTG_HFNUM) */
#define OTG_HFNUM_FTREM_MASK		(0xffff0000U)
#define OTG_HFNUM_FRNUM_MASK		(0x0000ffffU)

/* OTG Host periodic transmit FIFO/queue status register (OTG_HPTXSTS) */
#define OTG_HPTXSTS_PTXQTOP_MASK			(0xff000000U)
#define OTG_HPTXSTS_PTXQTOP_ODDFRM			(1U << 31U)
#define OTG_HPTXSTS_PTXQTOP_EVENFRM			(0U << 31U)
#define OTG_HPTXSTS_PTXQTOP_CHANNEL_NUMBER_MASK		(0xfU << 27U)
#define OTG_HPTXSTS_PTXQTOP_ENDPOINT_NUMBER_MASK	(0xfU << 27U)
#define OTG_HPTXSTS_PTXQTOP_TYPE_INOUT			(0x00U << 25U)
#define OTG_HPTXSTS_PTXQTOP_TYPE_ZEROLENGTH		(0x01U << 25U)
#define OTG_HPTXSTS_PTXQTOP_TYPE_DISABLECMD		(0x11U << 25U)
#define OTG_HPTXSTS_PTXQTOP_TERMINATE			(1U << 24U)
#define OTG_HPTXSTS_PTXQSAV_MASK			(0x00ff0000U)
#define OTG_HPTXSTS_PTXFSAVL_MASK			(0x0000ffffU)

/* OTG Host all channels interrupt mask register (OTG_HAINT) */
/* Bits 31:16 - Reserved */
#define OTG_HAINTMSK_HAINT_MASK		(0x0000ffffU)

/* OTG Host all channels interrupt mask register (OTG_HAINTMSK) */
/* Bits 31:16 - Reserved */
#define OTG_HAINTMSK_HAINTM_MASK	(0x0000ffffU)

/* OTG Host port control and status register (OTG_HPRT) */
/* Bits 31:19 - Reserved */
#define OTG_HPRT_PSPD_HIGH		(0x0U << 17U)
#define OTG_HPRT_PSPD_FULL		(0x1U << 17U)
#define OTG_HPRT_PSPD_LOW		(0x2U << 17U)
#define OTG_HPRT_PSPD_MASK		(0x3U << 17U)
#define OTG_HPRT_PTCTL_DISABLED		(0x0U << 13U)
#define OTG_HPRT_PTCTL_J		(0x1U << 13U)
#define OTG_HPRT_PTCTL_K		(0x2U << 13U)
#define OTG_HPRT_PTCTL_SE0_NAK		(0x3U << 13U)
#define OTG_HPRT_PTCTL_PACKET		(0x4U << 13U)
#define OTG_HPRT_PTCTL_FORCE_ENABLE	(0x5U << 13U)
#define OTG_HPRT_PPWR			(1U << 12U)
#define OTG_HPRT_PLSTS_DM		(1U << 11U)
#define OTG_HPRT_PLSTS_DP		(1U << 10U)
/* Bit 9 - Reserved */
#define OTG_HPRT_PRST		(1U << 8U)
#define OTG_HPRT_PSUSP		(1U << 7U)
#define OTG_HPRT_PRES		(1U << 6U)
#define OTG_HPRT_POCCHNG	(1U << 5U)
#define OTG_HPRT_POCA		(1U << 4U)
#define OTG_HPRT_PENCHNG	(1U << 3U)
#define OTG_HPRT_PENA		(1U << 2U)
#define OTG_HPRT_PCDET		(1U << 1U)
#define OTG_HPRT_PCSTS		(1U << 0U)

/* OTG Host channel-x characteristics register (OTG_HCCHARx) */
#define OTG_HCCHAR_CHENA		(1U << 31U)
#define OTG_HCCHAR_CHDIS		(1U << 30U)
#define OTG_HCCHAR_ODDFRM		(1U << 29U)
#define OTG_HCCHAR_DAD_MASK		(0x7fU << 22U)
#define OTG_HCCHAR_MCNT_1		(0x1U << 20U)
#define OTG_HCCHAR_MCNT_2		(0x2U << 20U)
#define OTG_HCCHAR_MCNT_3		(0x3U << 20U)
#define OTG_HCCHAR_MCNT_MASK		(0x3U << 20U)
#define OTG_HCCHAR_EPTYP_CONTROL	(0U << 18U)
#define OTG_HCCHAR_EPTYP_ISOCHRONOUS	(1U << 18U)
#define OTG_HCCHAR_EPTYP_BULK		(2U << 18U)
#define OTG_HCCHAR_EPTYP_INTERRUPT	(3U << 18U)
#define OTG_HCCHAR_EPTYP_MASK		(3U << 18U)
#define OTG_HCCHAR_LSDEV		(1U << 17U)
/* Bit 16 - Reserved */
#define OTG_HCCHAR_EPDIR_OUT		(0U << 15U)
#define OTG_HCCHAR_EPDIR_IN		(1U << 15U)
#define OTG_HCCHAR_EPDIR_MASK		(1U << 15U)
#define OTG_HCCHAR_EPNUM_MASK		(0xfU << 11U)
#define OTG_HCCHAR_MPSIZ_MASK		(0x000007ffU)

/* OTG Host channel-x interrupt register (OTG_HCINTx) */
/* Bits 31:11 - Reserved */
#define OTG_HCINT_DTERR		(1U << 10U)
#define OTG_HCINT_FRMOR		(1U << 9U)
#define OTG_HCINT_BBERR		(1U << 8U)
#define OTG_HCINT_TXERR		(1U << 7U)
/* Note: OTG_HCINT_NYET: Only in OTG_HS */
#define OTG_HCINT_NYET		(1U << 6U)
#define OTG_HCINT_ACK		(1U << 5U)
#define OTG_HCINT_NAK		(1U << 4U)
#define OTG_HCINT_STALL		(1U << 3U)
/* Note: OTG_HCINT_AHBERR: Only in OTG_HS */
#define OTG_HCINT_AHBERR	(1U << 2U)
#define OTG_HCINT_CHH		(1U << 1U)
#define OTG_HCINT_XFRC		(1U << 0U)

/* OTG Host channel-x interrupt mask register (OTG_HCINTMSKx) */
/* Bits 31:11 - Reserved */
#define OTG_HCINTMSK_DTERRM		(1U << 10U)
#define OTG_HCINTMSK_FRMORM		(1U << 9U)
#define OTG_HCINTMSK_BBERRM		(1U << 8U)
#define OTG_HCINTMSK_TXERRM		(1U << 7U)
/* Note: OTG_HCINTMSK_NYET: Only in OTG_HS */
#define OTG_HCINTMSK_NYET		(1U << 6U)
#define OTG_HCINTMSK_ACKM		(1U << 5U)
#define OTG_HCINTMSK_NAKM		(1U << 4U)
#define OTG_HCINTMSK_STALLM		(1U << 3U)
/* Note: OTG_HCINTMSK_AHBERR: Only in OTG_HS */
#define OTG_HCINTMSK_AHBERR		(1U << 2U)
#define OTG_HCINTMSK_CHHM		(1U << 1U)
#define OTG_HCINTMSK_XFRCM		(1U << 0U)

/* OTG Host channel-x transfer size register (OTG_HCTSIZx) */
/* Note: OTG_HCTSIZ_DOPING: Only in OTG_HS */
#define OTG_HCTSIZ_DOPING	(1U << 31U)
#define OTG_HCTSIZ_DPID_DATA0	(0x0U << 29U)
#define OTG_HCTSIZ_DPID_DATA1	(0x2U << 29U)
#define OTG_HCTSIZ_DPID_DATA2	(0x1U << 29U)
#define OTG_HCTSIZ_DPID_MDATA	(0x3U << 29U)
#define OTG_HCTSIZ_DPID_MASK	(0x3U << 29U)
#define OTG_HCTSIZ_PKTCNT_MASK	(0x3ffU << 19U)
#define OTG_HCTSIZ_XFRSIZ_MASK	(0x0007ffffU)



#endif

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

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/stm32/otg_common.h>

/* OTG_HS specific registers */

/* Host-mode Control and Status Registers */
#define OTG_HCSPLT(x)		(0x504 + 0x20*(x))
#define OTG_HCDMA(x)		(0x514 + 0x20*(x))

/* Device-mode Control and Status Registers */
#define OTG_DEACHHINT		0x838
#define OTG_DEACHHINTMSK	0x83C
#define OTG_DIEPEACHMSK1	0x844
#define OTG_DOEPEACHMSK1	0x884
#define OTG_DIEPDMA(x)		(0x914 + 0x20*(x))
#define OTG_DOEPDMA(x)		(0xB14 + 0x20*(x))



/***********************************************************************/

/* Core Global Control and Status Registers */
#define OTG_HS_GOTGCTL		MMIO32(USB_OTG_HS_BASE + OTG_GOTGCTL)
#define OTG_HS_GOTGINT		MMIO32(USB_OTG_HS_BASE + OTG_GOTGINT)
#define OTG_HS_GAHBCFG		MMIO32(USB_OTG_HS_BASE + OTG_GAHBCFG)
#define OTG_HS_GUSBCFG		MMIO32(USB_OTG_HS_BASE + OTG_GUSBCFG)
#define OTG_HS_GRSTCTL		MMIO32(USB_OTG_HS_BASE + OTG_GRSTCTL)
#define OTG_HS_GINTSTS		MMIO32(USB_OTG_HS_BASE + OTG_GINTSTS)
#define OTG_HS_GINTMSK		MMIO32(USB_OTG_HS_BASE + OTG_GINTMSK)
#define OTG_HS_GRXSTSR		MMIO32(USB_OTG_HS_BASE + OTG_GRXSTSR)
#define OTG_HS_GRXSTSP		MMIO32(USB_OTG_HS_BASE + OTG_GRXSTSP)
#define OTG_HS_GRXFSIZ		MMIO32(USB_OTG_HS_BASE + OTG_GRXFSIZ)
#define OTG_HS_GNPTXFSIZ	MMIO32(USB_OTG_HS_BASE + OTG_GNPTXFSIZ)
#define OTG_HS_GNPTXSTS		MMIO32(USB_OTG_HS_BASE + OTG_GNPTXSTS)
#define OTG_HS_GCCFG		MMIO32(USB_OTG_HS_BASE + OTG_GCCFG)
#define OTG_HS_CID		MMIO32(USB_OTG_HS_BASE + OTG_CID)
#define OTG_HS_HPTXFSIZ		MMIO32(USB_OTG_HS_BASE + OTG_HPTXFSIZ)
#define OTG_HS_DIEPTXF(x)	MMIO32(USB_OTG_HS_BASE + OTG_DIEPTXF(x))

/* Host-mode Control and Status Registers */
#define OTG_HS_HCFG		MMIO32(USB_OTG_HS_BASE + OTG_HCFG)
#define OTG_HS_HFIR		MMIO32(USB_OTG_HS_BASE + OTG_HFIR)
#define OTG_HS_HFNUM		MMIO32(USB_OTG_HS_BASE + OTG_HFNUM)
#define OTG_HS_HPTXSTS		MMIO32(USB_OTG_HS_BASE + OTG_HPTXSTS)
#define OTG_HS_HAINT		MMIO32(USB_OTG_HS_BASE + OTG_HAINT)
#define OTG_HS_HAINTMSK		MMIO32(USB_OTG_HS_BASE + OTG_HAINTMSK)
#define OTG_HS_HPRT		MMIO32(USB_OTG_HS_BASE + OTG_HPRT)
#define OTG_HS_HCCHAR(x)	MMIO32(USB_OTG_HS_BASE + OTG_HCCHAR(x))
#define OTG_HS_HCSPLT(x)	MMIO32(USB_OTG_HS_BASE + OTG_HCSPLT(x))
#define OTG_HS_HCINT(x)		MMIO32(USB_OTG_HS_BASE + OTG_HCINT(x))
#define OTG_HS_HCINTMSK(x)	MMIO32(USB_OTG_HS_BASE + OTG_HCINTMSK(x))
#define OTG_HS_HCTSIZ(x)	MMIO32(USB_OTG_HS_BASE + OTG_HCTSIZ(x))
#define OTG_HS_HCDMA(x)		MMIO32(USB_OTG_HS_BASE + OTG_HCDMA(x))

/* Device-mode Control and Status Registers */
#define OTG_HS_DCFG		MMIO32(USB_OTG_HS_BASE + OTG_DCFG)
#define OTG_HS_DCTL		MMIO32(USB_OTG_HS_BASE + OTG_DCTL)
#define OTG_HS_DSTS		MMIO32(USB_OTG_HS_BASE + OTG_DSTS)
#define OTG_HS_DIEPMSK		MMIO32(USB_OTG_HS_BASE + OTG_DIEPMSK)
#define OTG_HS_DOEPMSK		MMIO32(USB_OTG_HS_BASE + OTG_DOEPMSK)
#define OTG_HS_DAINT		MMIO32(USB_OTG_HS_BASE + OTG_DAINT)
#define OTG_HS_DAINTMSK		MMIO32(USB_OTG_HS_BASE + OTG_DAINTMSK)
#define OTG_HS_DVBUSDIS		MMIO32(USB_OTG_HS_BASE + OTG_DVBUSDIS)
#define OTG_HS_DVBUSPULSE	MMIO32(USB_OTG_HS_BASE + OTG_DVBUSPULSE)
#define OTG_HS_DIEPEMPMSK	MMIO32(USB_OTG_HS_BASE + OTG_DIEPEMPMSK)
#define OTG_HS_DIEPCTL0		MMIO32(USB_OTG_HS_BASE + OTG_DIEPCTL0)
#define OTG_HS_DIEPCTL(x)	MMIO32(USB_OTG_HS_BASE + OTG_DIEPCTL(x))
#define OTG_HS_DOEPCTL0		MMIO32(USB_OTG_HS_BASE + OTG_DOEPCTL0)
#define OTG_HS_DOEPCTL(x)	MMIO32(USB_OTG_HS_BASE + OTG_DOEPCTL(x))
#define OTG_HS_DIEPINT(x)	MMIO32(USB_OTG_HS_BASE + OTG_DIEPINT(x))
#define OTG_HS_DOEPINT(x)	MMIO32(USB_OTG_HS_BASE + OTG_DOEPINT(x))
#define OTG_HS_DIEPTSIZ0	MMIO32(USB_OTG_HS_BASE + OTG_DIEPTSIZ0)
#define OTG_HS_DOEPTSIZ0	MMIO32(USB_OTG_HS_BASE + OTG_DOEPTSIZ0)
#define OTG_HS_DIEPTSIZ(x)	MMIO32(USB_OTG_HS_BASE + \
					OTG_DIEPTSIZ(x))
#define OTG_HS_DTXFSTS(x)	MMIO32(USB_OTG_HS_BASE + OTG_DTXFSTS(x))
#define OTG_HS_DOEPTSIZ(x)	MMIO32(USB_OTG_HS_BASE + \
					OTG_DOEPTSIZ(x))
#define OTG_HS_DEACHHINT	MMIO32(USB_OTG_HS_BASE + OTG_DEACHHINT)
#define OTG_HS_DEACHHINTMSK	MMIO32(USB_OTG_HS_BASE + OTG_DEACHHINTMSK)
#define OTG_HS_DIEPEACHMSK	MMIO32(USB_OTG_HS_BASE + OTG_DIEPEACHMSK1)
#define OTG_HS_DOEPEACHMSK	MMIO32(USB_OTG_HS_BASE + OTG_DOEPEACHMSK1)
#define OTG_HS_DIEPDMA(x)	MMIO32(USB_OTG_HS_BASE + OTG_DIEPDMA(x))
#define OTG_HS_DOEPDMA(x)	MMIO32(USB_OTG_HS_BASE + OTG_DOEPDMA(x))

/* Power and clock gating control and status register */
#define OTG_HS_PCGCCTL			MMIO32(USB_OTG_HS_BASE + OTG_PCGCCTL)

/* Data FIFO */
#define OTG_HS_FIFO(x)			(&MMIO32(USB_OTG_HS_BASE + OTG_FIFO(x)))

/* Device-mode CSRs*/
/* OTG device each endpoint interrupt register (OTG_DEACHINT) */
/* Bits 31:18 - Reserved */
#define OTG_DEACHHINT_OEP1INT		(1 << 17)
/* Bits 16:2 - Reserved */
#define OTG_DEACHHINT_IEP1INT		(1 << 1)
/* Bit 0 - Reserved */

/* OTG device each in endpoint-1 interrupt register (OTG_DIEPEACHMSK1) */
/* Bits 31:14 - Reserved */
#define OTG_DIEPEACHMSK1_NAKM		(1 << 13)
/* Bits 12:10 - Reserved */
#define OTG_DIEPEACHMSK1_BIM		(1 << 9)
#define OTG_DIEPEACHMSK1_TXFURM		(1 << 8)
/* Bit 7 - Reserved */
#define OTG_DIEPEACHMSK1_INEPNEM	(1 << 6)
#define OTG_DIEPEACHMSK1_INEPNMM	(1 << 5)
#define OTG_DIEPEACHMSK1_ITTXFEMSK	(1 << 4)
#define OTG_DIEPEACHMSK1_TOM		(1 << 3)
/* Bit 2 - Reserved */
#define OTG_DIEPEACHMSK1_EPDM		(1 << 1)
#define OTG_DIEPEACHMSK1_XFRCM		(1 << 0)

/* OTG device each OUT endpoint-1 interrupt register (OTG_DOEPEACHMSK1) */
/* Bits 31:15 - Reserved */
#define OTG_DOEPEACHMSK1_NYETM		(1 << 14)
#define OTG_DOEPEACHMSK1_NAKM		(1 << 13)
#define OTG_DOEPEACHMSK1_BERRM		(1 << 12)
/* Bits 11:10 - Reserved */
#define OTG_DOEPEACHMSK1_BIM		(1 << 9)
#define OTG_DOEPEACHMSK1_OPEM		(1 << 8)
/* Bits 7:3 - Reserved */
#define OTG_DOEPEACHMSK1_AHBERRM	(1 << 2)
#define OTG_DOEPEACHMSK1_EPDM		(1 << 1)
#define OTG_DOEPEACHMSK1_XFRCM		(1 << 0)

/* Host-mode CSRs */
/* OTG host channel-x split control register (OTG_HCSPLTx) */
#define OTG_HCSPLT_SPLITEN		(1 << 31)
/* Bits 30:17 - Reserved */
#define OTG_HCSPLT_COMPLSPLT		(1 << 16)
#define OTG_HCSPLT_XACTPOS_ALL		(0x3 << 14)
#define OTG_HCSPLT_XACTPOS_BEGIN	(0x2 << 14)
#define OTG_HCSPLT_XACTPOS_MID		(0x0 << 14)
#define OTG_HCSPLT_XACTPOS_END		(0x1 << 14)
#define OTG_HCSPLT_HUBADDR_MASK		(0x7f << 7)
#define OTG_HCSPLT_PORTADDR_MASK	(0x7f << 0)

#endif

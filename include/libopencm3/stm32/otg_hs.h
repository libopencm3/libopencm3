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
#include <libopencm3/stm32/common/otg_common_all.h>

/* Core Global Control and Status Registers */
#define OTG_HS_GOTGCTL			OTG_GOTGCTL(USB_OTG_HS_BASE)
#define OTG_HS_GOTGINT			OTG_GOTGINT(USB_OTG_HS_BASE)
#define OTG_HS_GAHBCFG			OTG_GAHBCFG(USB_OTG_HS_BASE)
#define OTG_HS_GUSBCFG			OTG_GUSBCFG(USB_OTG_HS_BASE)
#define OTG_HS_GRSTCTL			OTG_GRSTCTL(USB_OTG_HS_BASE)
#define OTG_HS_GINTSTS			OTG_GINTSTS(USB_OTG_HS_BASE)
#define OTG_HS_GINTMSK			OTG_GINTMSK(USB_OTG_HS_BASE)
#define OTG_HS_GRXSTSR			OTG_GRXSTSR(USB_OTG_HS_BASE)
#define OTG_HS_GRXSTSP			OTG_GRXSTSP(USB_OTG_HS_BASE)
#define OTG_HS_GRXFSIZ			OTG_GRXFSIZ(USB_OTG_HS_BASE)
#define OTG_HS_GNPTXFSIZ		OTG_GNPTXFSIZ(USB_OTG_HS_BASE)
#define OTG_HS_GNPTXSTS			OTG_GNPTXSTS(USB_OTG_HS_BASE)
#define OTG_HS_GCCFG			OTG_GCCFG(USB_OTG_HS_BASE)
#define OTG_HS_CID				OTG_CID(USB_OTG_HS_BASE)
#define OTG_HS_HPTXFSIZ			OTG_HPTXFSIZ(USB_OTG_HS_BASE)
#define OTG_HS_DIEPTXF(x)		OTG_DIEPTXF(USB_OTG_HS_BASE, x)

/* Host-mode Control and Status Registers */
#define OTG_HS_HCFG			OTG_HCFG(USB_OTG_HS_BASE)
#define OTG_HS_HFIR			OTG_HFIR(USB_OTG_HS_BASE)
#define OTG_HS_HFNUM		OTG_HFNUM(USB_OTG_HS_BASE)
#define OTG_HS_HPTXSTS		OTG_HPTXSTS(USB_OTG_HS_BASE)
#define OTG_HS_HAINT		OTG_HAINT(USB_OTG_HS_BASE)
#define OTG_HS_HAINTMSK		OTG_HAINTMSK(USB_OTG_HS_BASE)
#define OTG_HS_HPRT			OTG_HPRT(USB_OTG_HS_BASE)
#define OTG_HS_HCCHARx(x)	OTG_HCCHARx(USB_OTG_HS_BASE, x)
#define OTG_HS_HCINTx(x)	OTG_HCINTx(USB_OTG_HS_BASE, x)
#define OTG_HS_HCINTMSKx(x)	OTG_HCINTMSKx(USB_OTG_HS_BASE, x)
#define OTG_HS_HCTSIZx(x)	OTG_HCTSIZx(USB_OTG_HS_BASE, x)

/* Device-mode Control and Status Registers */
#define OTG_HS_DCFG				OTG_DCFG(USB_OTG_HS_BASE)
#define OTG_HS_DCTL				OTG_DCTL(USB_OTG_HS_BASE)
#define OTG_HS_DSTS				OTG_DSTS(USB_OTG_HS_BASE)
#define OTG_HS_DIEPMSK			OTG_DIEPMSK(USB_OTG_HS_BASE)
#define OTG_HS_DOEPMSK			OTG_DOEPMSK(USB_OTG_HS_BASE)
#define OTG_HS_DAINT			OTG_DAINT(USB_OTG_HS_BASE)
#define OTG_HS_DAINTMSK			OTG_DAINTMSK(USB_OTG_HS_BASE)
#define OTG_HS_DVBUSDIS			OTG_DVBUSDIS(USB_OTG_HS_BASE)
#define OTG_HS_DVBUSPULSE		OTG_DVBUSPULSE(USB_OTG_HS_BASE)
#define OTG_HS_DIEPEMPMSK		OTG_DIEPEMPMSK(USB_OTG_HS_BASE)
#define OTG_HS_DIEPCTL0			OTG_DIEPCTL0(USB_OTG_HS_BASE)
#define OTG_HS_DIEPCTL(x)		OTG_DIEPCTL(USB_OTG_HS_BASE, x)
#define OTG_HS_DOEPCTL0			OTG_DOEPCTL0(USB_OTG_HS_BASE, x)
#define OTG_HS_DOEPCTL(x)		OTG_DOEPCTL(USB_OTG_HS_BASE, x)
#define OTG_HS_DIEPINT(x)		OTG_DIEPINT(USB_OTG_HS_BASE, x)
#define OTG_HS_DOEPINT(x)		OTG_DOEPINT(USB_OTG_HS_BASE , x)
#define OTG_HS_DIEPTSIZ0		OTG_DIEPTSIZ0(USB_OTG_HS_BASE)
#define OTG_HS_DOEPTSIZ0		OTG_DOEPTSIZ0(USB_OTG_HS_BASE)
#define OTG_HS_DIEPTSIZ(x)		OTG_DIEPTSIZ(USB_OTG_HS_BASE, x)
#define OTG_HS_DTXFSTS(x)		OTG_DTXFSTS(USB_OTG_HS_BASE, x)
#define OTG_HS_DOEPTSIZ(x)		OTG_DOEPTSIZ(USB_OTG_HS_BASE, x)

/* Power and clock gating control and status register */
#define OTG_HS_PCGCCTL			OTG_PCGCCTL(USB_OTG_HS_BASE)

/* Data FIFO */
#define OTG_HS_FIFO(x)			OTG_FIFO(USB_OTG_HS_BASE, x)

#endif

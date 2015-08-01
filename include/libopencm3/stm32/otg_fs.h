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
#include <libopencm3/stm32/common/otg_common_all.h>

/* Core Global Control and Status Registers */
#define OTG_FS_GOTGCTL			OTG_GOTGCTL(USB_OTG_FS_BASE)
#define OTG_FS_GOTGINT			OTG_GOTGINT(USB_OTG_FS_BASE)
#define OTG_FS_GAHBCFG			OTG_GAHBCFG(USB_OTG_FS_BASE)
#define OTG_FS_GUSBCFG			OTG_GUSBCFG(USB_OTG_FS_BASE)
#define OTG_FS_GRSTCTL			OTG_GRSTCTL(USB_OTG_FS_BASE)
#define OTG_FS_GINTSTS			OTG_GINTSTS(USB_OTG_FS_BASE)
#define OTG_FS_GINTMSK			OTG_GINTMSK(USB_OTG_FS_BASE)
#define OTG_FS_GRXSTSR			OTG_GRXSTSR(USB_OTG_FS_BASE)
#define OTG_FS_GRXSTSP			OTG_GRXSTSP(USB_OTG_FS_BASE)
#define OTG_FS_GRXFSIZ			OTG_GRXFSIZ(USB_OTG_FS_BASE)
#define OTG_FS_GNPTXFSIZ		OTG_GNPTXFSIZ(USB_OTG_FS_BASE)
#define OTG_FS_GNPTXSTS			OTG_GNPTXSTS(USB_OTG_FS_BASE)
#define OTG_FS_GCCFG			OTG_GCCFG(USB_OTG_FS_BASE)
#define OTG_FS_CID				OTG_CID(USB_OTG_FS_BASE)
#define OTG_FS_HPTXFSIZ			OTG_HPTXFSIZ(USB_OTG_FS_BASE)
#define OTG_FS_DIEPTXF(x)		OTG_DIEPTXF(USB_OTG_FS_BASE, x)

/* Host-mode Control and Status Registers */
#define OTG_FS_HCFG			OTG_HCFG(USB_OTG_FS_BASE)
#define OTG_FS_HFIR			OTG_HFIR(USB_OTG_FS_BASE)
#define OTG_FS_HFNUM		OTG_HFNUM(USB_OTG_FS_BASE)
#define OTG_FS_HPTXSTS		OTG_HPTXSTS(USB_OTG_FS_BASE)
#define OTG_FS_HAINT		OTG_HAINT(USB_OTG_FS_BASE)
#define OTG_FS_HAINTMSK		OTG_HAINTMSK(USB_OTG_FS_BASE)
#define OTG_FS_HPRT			OTG_HPRT(USB_OTG_FS_BASE)
#define OTG_FS_HCCHARx(x)	OTG_HCCHARx(USB_OTG_FS_BASE, x)
#define OTG_FS_HCINTx(x)	OTG_HCINTx(USB_OTG_FS_BASE, x)
#define OTG_FS_HCINTMSKx(x)	OTG_HCINTMSKx(USB_OTG_FS_BASE, x)
#define OTG_FS_HCTSIZx(x)	OTG_HCTSIZx(USB_OTG_FS_BASE, x)

/* Device-mode Control and Status Registers */
#define OTG_FS_DCFG				OTG_DCFG(USB_OTG_FS_BASE)
#define OTG_FS_DCTL				OTG_DCTL(USB_OTG_FS_BASE)
#define OTG_FS_DSTS				OTG_DSTS(USB_OTG_FS_BASE)
#define OTG_FS_DIEPMSK			OTG_DIEPMSK(USB_OTG_FS_BASE)
#define OTG_FS_DOEPMSK			OTG_DOEPMSK(USB_OTG_FS_BASE)
#define OTG_FS_DAINT			OTG_DAINT(USB_OTG_FS_BASE)
#define OTG_FS_DAINTMSK			OTG_DAINTMSK(USB_OTG_FS_BASE)
#define OTG_FS_DVBUSDIS			OTG_DVBUSDIS(USB_OTG_FS_BASE)
#define OTG_FS_DVBUSPULSE		OTG_DVBUSPULSE(USB_OTG_FS_BASE)
#define OTG_FS_DIEPEMPMSK		OTG_DIEPEMPMSK(USB_OTG_FS_BASE)
#define OTG_FS_DIEPCTL0			OTG_DIEPCTL0(USB_OTG_FS_BASE)
#define OTG_FS_DIEPCTL(x)		OTG_DIEPCTL(USB_OTG_FS_BASE, x)
#define OTG_FS_DOEPCTL0			OTG_DOEPCTL0(USB_OTG_FS_BASE, x)
#define OTG_FS_DOEPCTL(x)		OTG_DOEPCTL(USB_OTG_FS_BASE, x)
#define OTG_FS_DIEPINT(x)		OTG_DIEPINT(USB_OTG_FS_BASE, x)
#define OTG_FS_DOEPINT(x)		OTG_DOEPINT(USB_OTG_FS_BASE , x)
#define OTG_FS_DIEPTSIZ0		OTG_DIEPTSIZ0(USB_OTG_FS_BASE)
#define OTG_FS_DOEPTSIZ0		OTG_DOEPTSIZ0(USB_OTG_FS_BASE)
#define OTG_FS_DIEPTSIZ(x)		OTG_DIEPTSIZ(USB_OTG_FS_BASE, x)
#define OTG_FS_DTXFSTS(x)		OTG_DTXFSTS(USB_OTG_FS_BASE, x)
#define OTG_FS_DOEPTSIZ(x)		OTG_DOEPTSIZ(USB_OTG_FS_BASE, x)

/* Power and clock gating control and status register */
#define OTG_FS_PCGCCTL			OTG_PCGCCTL(USB_OTG_FS_BASE)

/* Data FIFO */
#define OTG_FS_FIFO(x)			OTG_FIFO(USB_OTG_FS_BASE, x)

#endif

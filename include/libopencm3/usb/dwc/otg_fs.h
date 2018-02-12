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
 * This file covers definitions for DesignWare USB OTG HS peripherals.
 */

#ifndef LIBOPENCM3_USB_DWC_OTG_FS_H
#define LIBOPENCM3_USB_DWC_OTG_FS_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/usb/dwc/otg_common.h>

/* Memory map is required for USB_OTG_FS_BASE address */
#if defined(STM32F1) || defined(STM32F2) || defined(STM32F4)
#	include <libopencm3/stm32/memorymap.h>
#elif defined(EFM32HG)
#	include <libopencm3/efm32/memorymap.h>
#else
#	error "device family not supported by dwc/otg_fs."
#endif

/***********************************************************************/

/* Core Global Control and Status Registers */
#define OTG_FS_GOTGCTL		MMIO32(USB_OTG_FS_BASE + OTG_GOTGCTL)
#define OTG_FS_GOTGINT		MMIO32(USB_OTG_FS_BASE + OTG_GOTGINT)
#define OTG_FS_GAHBCFG		MMIO32(USB_OTG_FS_BASE + OTG_GAHBCFG)
#define OTG_FS_GUSBCFG		MMIO32(USB_OTG_FS_BASE + OTG_GUSBCFG)
#define OTG_FS_GRSTCTL		MMIO32(USB_OTG_FS_BASE + OTG_GRSTCTL)
#define OTG_FS_GINTSTS		MMIO32(USB_OTG_FS_BASE + OTG_GINTSTS)
#define OTG_FS_GINTMSK		MMIO32(USB_OTG_FS_BASE + OTG_GINTMSK)
#define OTG_FS_GRXSTSR		MMIO32(USB_OTG_FS_BASE + OTG_GRXSTSR)
#define OTG_FS_GRXSTSP		MMIO32(USB_OTG_FS_BASE + OTG_GRXSTSP)
#define OTG_FS_GRXFSIZ		MMIO32(USB_OTG_FS_BASE + OTG_GRXFSIZ)
#define OTG_FS_GNPTXFSIZ	MMIO32(USB_OTG_FS_BASE + OTG_GNPTXFSIZ)
#define OTG_FS_GNPTXSTS		MMIO32(USB_OTG_FS_BASE + OTG_GNPTXSTS)
#define OTG_FS_GCCFG		MMIO32(USB_OTG_FS_BASE + OTG_GCCFG)
#define OTG_FS_CID		MMIO32(USB_OTG_FS_BASE + OTG_CID)
#define OTG_FS_HPTXFSIZ		MMIO32(USB_OTG_FS_BASE + OTG_HPTXFSIZ)
#define OTG_FS_DIEPTXF(x)	MMIO32(USB_OTG_FS_BASE + OTG_DIEPTXF(x))


/* Host-mode Control and Status Registers */
#define OTG_FS_HCFG		MMIO32(USB_OTG_FS_BASE + OTG_HCFG)
#define OTG_FS_HFIR		MMIO32(USB_OTG_FS_BASE + OTG_HFIR)
#define OTG_FS_HFNUM		MMIO32(USB_OTG_FS_BASE + OTG_HFNUM)
#define OTG_FS_HPTXSTS		MMIO32(USB_OTG_FS_BASE + OTG_HPTXSTS)
#define OTG_FS_HAINT		MMIO32(USB_OTG_FS_BASE + OTG_HAINT)
#define OTG_FS_HAINTMSK		MMIO32(USB_OTG_FS_BASE + OTG_HAINTMSK)
#define OTG_FS_HPRT		MMIO32(USB_OTG_FS_BASE + OTG_HPRT)
#define OTG_FS_HCCHAR(x)	MMIO32(USB_OTG_FS_BASE + OTG_HCCHAR(x))
#define OTG_FS_HCINT(x)		MMIO32(USB_OTG_FS_BASE + OTG_HCINT(x))
#define OTG_FS_HCINTMSK(x)	MMIO32(USB_OTG_FS_BASE + OTG_HCINTMSK(x))
#define OTG_FS_HCTSIZ(x)	MMIO32(USB_OTG_FS_BASE + OTG_HCTSIZ(x))

/* Device-mode Control and Status Registers */
#define OTG_FS_DCFG		MMIO32(USB_OTG_FS_BASE + OTG_DCFG)
#define OTG_FS_DCTL		MMIO32(USB_OTG_FS_BASE + OTG_DCTL)
#define OTG_FS_DSTS		MMIO32(USB_OTG_FS_BASE + OTG_DSTS)
#define OTG_FS_DIEPMSK		MMIO32(USB_OTG_FS_BASE + OTG_DIEPMSK)
#define OTG_FS_DOEPMSK		MMIO32(USB_OTG_FS_BASE + OTG_DOEPMSK)
#define OTG_FS_DAINT		MMIO32(USB_OTG_FS_BASE + OTG_DAINT)
#define OTG_FS_DAINTMSK		MMIO32(USB_OTG_FS_BASE + OTG_DAINTMSK)
#define OTG_FS_DVBUSDIS		MMIO32(USB_OTG_FS_BASE + OTG_DVBUSDIS)
#define OTG_FS_DVBUSPULSE	MMIO32(USB_OTG_FS_BASE + OTG_DVBUSPULSE)
#define OTG_FS_DIEPEMPMSK	MMIO32(USB_OTG_FS_BASE + OTG_DIEPEMPMSK)
#define OTG_FS_DIEPCTL0		MMIO32(USB_OTG_FS_BASE + OTG_DIEPCTL0)
#define OTG_FS_DIEPCTL(x)	MMIO32(USB_OTG_FS_BASE + OTG_DIEPCTL(x))
#define OTG_FS_DOEPCTL0		MMIO32(USB_OTG_FS_BASE + OTG_DOEPCTL0)
#define OTG_FS_DOEPCTL(x)	MMIO32(USB_OTG_FS_BASE + OTG_DOEPCTL(x))
#define OTG_FS_DIEPINT(x)	MMIO32(USB_OTG_FS_BASE + OTG_DIEPINT(x))
#define OTG_FS_DOEPINT(x)	MMIO32(USB_OTG_FS_BASE + OTG_DOEPINT(x))
#define OTG_FS_DIEPTSIZ0	MMIO32(USB_OTG_FS_BASE + OTG_DIEPTSIZ0)
#define OTG_FS_DOEPTSIZ0	MMIO32(USB_OTG_FS_BASE + OTG_DOEPTSIZ0)
#define OTG_FS_DIEPTSIZ(x)	MMIO32(USB_OTG_FS_BASE + OTG_DIEPTSIZ(x))
#define OTG_FS_DTXFSTS(x)	MMIO32(USB_OTG_FS_BASE + OTG_DTXFSTS(x))
#define OTG_FS_DOEPTSIZ(x)	MMIO32(USB_OTG_FS_BASE + OTG_DOEPTSIZ(x))

/* Power and clock gating control and status register */
#define OTG_FS_PCGCCTL		MMIO32(USB_OTG_FS_BASE + OTG_PCGCCTL)

/* Data FIFO */
#define OTG_FS_FIFO(x)		(&MMIO32(USB_OTG_FS_BASE \
						      + (((x) + 1) \
							 << 12)))


#endif

/** @addtogroup usb_file USB peripheral API
 * @ingroup peripheral_apis
 *
 * @brief USB Peripheral for Happy Gecko
 *
 * The Happy Gecko uses the "standard" usb_dwc_otg core.
 *
 * @sa usb_defines
 * @copyright See @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2018 Seb Holzapfel <schnommus@gmail.com>
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

#include <string.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/efm32/cmu.h>
#include <libopencm3/efm32/usb.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/dwc/otg_fs.h>
#include "usb_private.h"
#include "usb_dwc_common.h"

/**@{*/

/* Receive FIFO size in 32-bit words. */
#define RX_FIFO_SIZE 256

/* FIXME: EFM32HG has 6 bidirectional endpoints.
 *  problem is "uint32_t doeptsiz[4];" in usb_private.h */

#define ENDPOINT_COUNT 4

static struct _usbd_device _usbd_dev;

/** Initialize the USB device controller hardware of the EFM32HG. */
static usbd_device *efm32hg_usbd_init(void)
{
	/* Enable peripheral clocks required for USB */
	cmu_periph_clock_enable(CMU_USB);
	cmu_periph_clock_enable(CMU_USBC);
	cmu_periph_clock_enable(CMU_LE);

	/* Select LFRCO as LFCCLK clock */
	CMU_LFCLKSEL = CMU_LFCLKSEL_LFC_LFRCO;

	/* Enable the USBLE peripheral clock (sits on LFCCLK) */
	cmu_periph_clock_enable(CMU_USBLE);

	/* Calibrate USB based on communications */
	CMU_USHFRCOCONF = CMU_USHFRCOCONF_BAND_48MHZ;

	/* Enable USHFRCO Clock Recovery mode. */
	CMU_USBCRCTRL |= CMU_USBCRCTRL_EN;

	/* Select USHFRCO as clock source for USB */
	cmu_osc_on(USHFRCO);
	cmu_wait_for_osc_ready(USHFRCO);

	/* Set up the USB clock source */
	cmu_set_usbclk_source(USHFRCO);
	cmu_wait_for_usbclk_selected(USHFRCO);

	/* Turn off all Low Energy Mode (LEM) features. */
	USB_CTRL = 0;

	/* Initialize USB core */
	USB_ROUTE = USB_ROUTE_PHYPEN; /* Enable PHY pins. */

	/* Wait for AHB idle. */
	while (!(OTG_FS_GRSTCTL & OTG_GRSTCTL_AHBIDL));
	/* Do core soft reset. */
	OTG_FS_GRSTCTL |= OTG_GRSTCTL_CSRST;
	while (OTG_FS_GRSTCTL & OTG_GRSTCTL_CSRST);

	/* Explicitly enable DP pullup (not all cores do this by default) */
	OTG_FS_DCTL &= ~OTG_DCTL_SDIS;

	/* Force peripheral only mode. */
	OTG_FS_GUSBCFG |= OTG_GUSBCFG_FDMOD | OTG_GUSBCFG_TRDT_MASK;

	OTG_FS_GINTSTS = OTG_GINTSTS_MMIS;

	/* Full speed device. */
	OTG_FS_DCFG |= OTG_DCFG_DSPD;

	/* Restart the PHY clock. */
	OTG_FS_PCGCCTL = 0;

	OTG_FS_GRXFSIZ = efm32hg_usb_driver.rx_fifo_size;
	_usbd_dev.fifo_mem_top = efm32hg_usb_driver.rx_fifo_size;

	/* Unmask interrupts for TX and RX. */
	OTG_FS_GAHBCFG |= OTG_GAHBCFG_GINT;
	OTG_FS_GINTMSK = OTG_GINTMSK_ENUMDNEM |
			 OTG_GINTMSK_RXFLVLM |
			 OTG_GINTMSK_IEPINT |
			 OTG_GINTMSK_USBSUSPM |
			 OTG_GINTMSK_WUIM;
	OTG_FS_DAINTMSK = 0xF;
	OTG_FS_DIEPMSK = OTG_DIEPMSK_XFRCM;

	return &_usbd_dev;
}

const struct _usbd_driver efm32hg_usb_driver = {
	.init = efm32hg_usbd_init,
	.set_address = dwc_set_address,
	.ep_setup = dwc_ep_setup,
	.ep_reset = dwc_endpoints_reset,
	.ep_stall_set = dwc_ep_stall_set,
	.ep_stall_get = dwc_ep_stall_get,
	.ep_nak_set = dwc_ep_nak_set,
	.ep_write_packet = dwc_ep_write_packet,
	.ep_read_packet = dwc_ep_read_packet,
	.poll = dwc_poll,
	.disconnect = dwc_disconnect,
	.base_address = USB_OTG_FS_BASE,
	.set_address_before_status = 1,
	.rx_fifo_size = RX_FIFO_SIZE,
};

/**@}*/
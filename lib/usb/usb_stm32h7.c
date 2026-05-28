/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2025 Rachel Mant <git@dragonmux.network>
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
#include <libopencm3/stm32/tools.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/bos.h>
#include <libopencm3/usb/dwc/otg_hs.h>
#include "usb_private.h"
#include "usb_dwc_common.h"

/* Receive FIFO size in 32-bit words. */
#define RX_FIFO_SIZE 512U

static usbd_device *stm32h7_usbd_init(void);

static struct _usbd_device usbd_dev;

const struct _usbd_driver stm32h7_usb_driver = {
	.init = stm32h7_usbd_init,
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
	.base_address = USB_OTG_HS_BASE,
	.set_address_before_status = true,
	.rx_fifo_size = RX_FIFO_SIZE,
};

/** Initialize the USB device controller hardware of the STM32. */
static usbd_device *stm32h7_usbd_init(void)
{
	rcc_periph_clock_enable(RCC_OTGHS);
	OTG_HS_GINTSTS = OTG_GINTSTS_MMIS;

	OTG_HS_GUSBCFG |= OTG_GUSBCFG_PHYSEL;
	/* Enable VBUS sensing in device mode, data connection detection and power up the FS PHY */
	OTG_HS_GCCFG &= ~OTG_GCCFG_PDEN;
	OTG_HS_GCCFG |= OTG_GCCFG_VBDEN | OTG_GCCFG_DCDEN | OTG_GCCFG_PWRDWN;

	/* Wait for AHB idle. */
	while (!(OTG_HS_GRSTCTL & OTG_GRSTCTL_AHBIDL))
		continue;
	/* Do core soft reset. */
	OTG_HS_GRSTCTL |= OTG_GRSTCTL_CSRST;
	while (OTG_HS_GRSTCTL & OTG_GRSTCTL_CSRST)
		continue;

	/* Explicitly enable DP pullup (not all cores do this by default) */
	OTG_HS_DCTL &= ~OTG_DCTL_SDIS;

	/* Force peripheral only mode. */
	OTG_HS_GUSBCFG |= OTG_GUSBCFG_FDMOD | OTG_GUSBCFG_TRDT_MASK;

	/* Full speed device. */
	OTG_HS_DCFG |= OTG_DCFG_DSPD;

	/* Restart the PHY clock. */
	OTG_HS_PCGCCTL = 0;

	OTG_HS_GRXFSIZ = stm32h7_usb_driver.rx_fifo_size;
	usbd_dev.fifo_mem_top = stm32h7_usb_driver.rx_fifo_size;

	/* Unmask interrupts for TX and RX. */
	OTG_HS_GAHBCFG |= OTG_GAHBCFG_GINT;
	OTG_HS_GINTMSK = OTG_GINTMSK_ENUMDNEM | OTG_GINTMSK_RXFLVLM | OTG_GINTMSK_IEPINT | OTG_GINTMSK_USBSUSPM |
		OTG_GINTMSK_WUIM | OTG_GINTMSK_SOFM;
	OTG_HS_DAINTMSK = 0x00ff00ffU;
	OTG_HS_DIEPMSK = OTG_DIEPMSK_XFRCM;
	OTG_HS_DOEPMSK = OTG_DOEPMSK_STUPM | OTG_DOEPMSK_XFRCM;

	return &usbd_dev;
}

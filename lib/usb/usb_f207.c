/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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
#include <libopencm3/stm32/otg_hs.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"
#include "usb_fx07_common.h"

/* Receive FIFO size in 32-bit words. */
#define RX_FIFO_SIZE 512

static usbd_device *stm32f207_usbd_init(void);

static struct _usbd_device usbd_dev;

const struct _usbd_driver stm32f207_usb_driver = {
	.init = stm32f207_usbd_init,
	.set_address = stm32fx07_set_address,
	.ep_setup = stm32fx07_ep_setup,
	.ep_reset = stm32fx07_endpoints_reset,
	.ep_stall_set = stm32fx07_ep_stall_set,
	.ep_stall_get = stm32fx07_ep_stall_get,
	.ep_nak_set = stm32fx07_ep_nak_set,
	.ep_write_packet = stm32fx07_ep_write_packet,
	.ep_read_packet = stm32fx07_ep_read_packet,
	.poll = stm32fx07_poll,
	.disconnect = stm32fx07_disconnect,
	.base_address = USB_OTG_HS_BASE,
	.set_address_before_status = 1,
	.rx_fifo_size = RX_FIFO_SIZE,
};

/** Initialize the USB device controller hardware of the STM32. */
static usbd_device *stm32f207_usbd_init(void)
{
	OTG_HS_GINTSTS = OTG_HS_GINTSTS_MMIS;

	OTG_HS_GUSBCFG |= OTG_HS_GUSBCFG_PHYSEL;
	/* Enable VBUS sensing in device mode and power down the PHY. */
	OTG_HS_GCCFG |= OTG_HS_GCCFG_VBUSBSEN | OTG_HS_GCCFG_PWRDWN;

	/* Wait for AHB idle. */
	while (!(OTG_HS_GRSTCTL & OTG_HS_GRSTCTL_AHBIDL));
	/* Do core soft reset. */
	OTG_HS_GRSTCTL |= OTG_HS_GRSTCTL_CSRST;
	while (OTG_HS_GRSTCTL & OTG_HS_GRSTCTL_CSRST);

	/* Force peripheral only mode. */
	OTG_HS_GUSBCFG |= OTG_HS_GUSBCFG_FDMOD | OTG_HS_GUSBCFG_TRDT_MASK;

	/* Full speed device. */
	OTG_HS_DCFG |= OTG_HS_DCFG_DSPD;

	/* Restart the PHY clock. */
	OTG_HS_PCGCCTL = 0;

	OTG_HS_GRXFSIZ = stm32f207_usb_driver.rx_fifo_size;
	usbd_dev.fifo_mem_top = stm32f207_usb_driver.rx_fifo_size;

	/* Unmask interrupts for TX and RX. */
	OTG_HS_GAHBCFG |= OTG_HS_GAHBCFG_GINT;
	OTG_HS_GINTMSK = OTG_HS_GINTMSK_ENUMDNEM |
			 OTG_HS_GINTMSK_RXFLVLM |
			 OTG_HS_GINTMSK_IEPINT |
			 OTG_HS_GINTMSK_USBSUSPM |
			 OTG_HS_GINTMSK_WUIM |
			 OTG_HS_GINTMSK_SOFM;
	OTG_HS_DAINTMSK = 0xF;
	OTG_HS_DIEPMSK = OTG_HS_DIEPMSK_XFRCM;

	return &usbd_dev;
}

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
#include <libopencm3/stm32/otg_fs.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"
#include "usb_fx07_common.h"

/* Receive FIFO size in 32-bit words. */
#define RX_FIFO_SIZE 128

static usbd_device *stm32f107_usbd_init(void);

static struct _usbd_device usbd_dev;

const struct _usbd_driver stm32f107_usb_driver = {
	.init = stm32f107_usbd_init,
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
	.base_address = USB_OTG_FS_BASE,
	.set_address_before_status = 1,
	.rx_fifo_size = RX_FIFO_SIZE,
};

/** Initialize the USB device controller hardware of the STM32. */
static usbd_device *stm32f107_usbd_init(void)
{
	OTG_FS_GINTSTS = OTG_FS_GINTSTS_MMIS;

	OTG_FS_GUSBCFG |= OTG_FS_GUSBCFG_PHYSEL;
	/* Enable VBUS sensing in device mode and power down the PHY. */
	OTG_FS_GCCFG |= OTG_FS_GCCFG_VBUSBSEN | OTG_FS_GCCFG_PWRDWN;

	/* Wait for AHB idle. */
	while (!(OTG_FS_GRSTCTL & OTG_FS_GRSTCTL_AHBIDL));
	/* Do core soft reset. */
	OTG_FS_GRSTCTL |= OTG_FS_GRSTCTL_CSRST;
	while (OTG_FS_GRSTCTL & OTG_FS_GRSTCTL_CSRST);

	/* Force peripheral only mode. */
	OTG_FS_GUSBCFG |= OTG_FS_GUSBCFG_FDMOD | OTG_FS_GUSBCFG_TRDT_MASK;

	/* Full speed device. */
	OTG_FS_DCFG |= OTG_FS_DCFG_DSPD;

	/* Restart the PHY clock. */
	OTG_FS_PCGCCTL = 0;

	OTG_FS_GRXFSIZ = stm32f107_usb_driver.rx_fifo_size;
	usbd_dev.fifo_mem_top = stm32f107_usb_driver.rx_fifo_size;

	/* Unmask interrupts for TX and RX. */
	OTG_FS_GAHBCFG |= OTG_FS_GAHBCFG_GINT;
	OTG_FS_GINTMSK = OTG_FS_GINTMSK_ENUMDNEM |
			 OTG_FS_GINTMSK_RXFLVLM |
			 OTG_FS_GINTMSK_IEPINT |
			 OTG_FS_GINTMSK_USBSUSPM |
			 OTG_FS_GINTMSK_WUIM |
			 OTG_FS_GINTMSK_SOFM;
	OTG_FS_DAINTMSK = 0xF;
	OTG_FS_DIEPMSK = OTG_FS_DIEPMSK_XFRCM;

	return &usbd_dev;
}

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
#include <libopencm3/usb/dwc/otg_fs.h>
#include "usb_private.h"
#include "usb_dwc_common.h"

/*
 * Receive FIFO size in 32-bit words.
 * We reserve first 4*n + 6 u32's for SETUP packets, where n is the number of endpoints total (6).
 * Next, we reserve our max packet size (64) / 4 + 1 for general packet storage, and an additional
 * one slot for the completion notification. This gives (4 * 6) + (64 / 4) + 8 = 24 + 16 + 8 = 48
 */
#define RX_FIFO_SIZE 48U /* 192 bytes */

static usbd_device *stm32u5_usbd_init(void);

static usbd_device usbd_dev;

const struct _usbd_driver stm32u5_usb_driver = {
	.init = stm32u5_usbd_init,
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
	.set_address_before_status = true,
	.rx_fifo_size = RX_FIFO_SIZE,
};

/** Initialize the USB device controller hardware of the STM32. */
static usbd_device *stm32u5_usbd_init(void)
{
	rcc_periph_clock_enable(RCC_OTGFS);
	/* Wait for AHB idle */
	while ((OTG_FS_GRSTCTL & OTG_GRSTCTL_AHBIDL) == 0U)
		continue;
	/* Do a soft reset of the core */
	OTG_FS_GRSTCTL = OTG_GRSTCTL_CSRST;
	while ((OTG_FS_GRSTCTL & OTG_GRSTCTL_CSRST) != 0U)
		continue;

	/* Set the TX FIFO interrupt to work on empty, and disable global interrupts for the moment */
	OTG_FS_GAHBCFG = OTG_GAHBCFG_TXFELVL;
	/* Enable VBUS sensing in device mode, and power up the FS PHY */
	OTG_FS_GCCFG &= ~(OTG_GCCFG_PDEN | OTG_GCCFG_SDEN | OTG_GCCFG_DCDEN | OTG_GCCFG_BCDEN);
	OTG_FS_GCCFG |= OTG_GCCFG_VBDEN | OTG_GCCFG_PWRDWN;
	/* Set up for USB operation on a 160MHz AHB, don't enable HNP, or SRP and force device mode */
	OTG_FS_GUSBCFG = OTG_GUSBCFG_FDMOD | (6U << 10U);
	/* Clear all outstanding interrupts so we're in a clean state */
	OTG_FS_GINTSTS = UINT32_MAX;
	/*
	 * Unmask interrupts for core events - SOF, RX FIFO non-empty, USB suspend, USB reset,
	 * enumeration done, IN endpoint interrupts, amd wake-up detected
	 */
	OTG_FS_GINTMSK = OTG_GINTMSK_SOFM | OTG_GINTMSK_RXFLVLM | OTG_GINTMSK_USBSUSPM | OTG_GINTMSK_USBRST |
		OTG_GINTMSK_ENUMDNEM | OTG_GINTMSK_IEPINT | OTG_GINTMSK_OEPINT | OTG_GINTMSK_WUIM;

	/* Set up to operate as a USB FS device, resetting any other bits including device address */
	OTG_FS_DCFG &= ~(OTG_DCFG_ERRATIM | OTG_DCFG_PFIVL | OTG_DCFG_DAD | OTG_DCFG_NZLSOHSK);
	OTG_FS_DCFG |= OTG_DCFG_DSPD;
	OTG_FS_PCGCCTL = 0U;

	/* Set up endpoint interrupts */
	OTG_FS_DAINTMSK = 0x003f003fU;
	/* Interrupt when IN transfer has completed */
	OTG_FS_DIEPMSK = OTG_DIEPMSK_XFRCM;
	/* Interrupt when OUT transfer has completed SETUP phase or a transfer complets */
	OTG_FS_DOEPMSK = OTG_DOEPMSK_STUPM | OTG_DOEPMSK_XFRCM;

	/* Enable global interrupts now we're all set */
	OTG_FS_GAHBCFG |= OTG_GAHBCFG_GINT;
	/* Ask the core to connect to USB */
	OTG_FS_DCTL &= ~OTG_DCTL_SDIS;
	return &usbd_dev;
}

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

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/tools.h>
#include <libopencm3/stm32/usb.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"
#include "stm32_usbfs_common.h"

static usbd_device *stm32f103_usbd_init(void);

const struct _usbd_driver stm32f103_usb_driver = {
	.init = stm32f103_usbd_init,
	.set_address = stm32_usbfs_set_address,
	.ep_setup = stm32_usbfs_ep_setup,
	.ep_reset = stm32_usbfs_endpoints_reset,
	.ep_stall_set = stm32_usbfs_ep_stall_set,
	.ep_stall_get = stm32_usbfs_ep_stall_get,
	.ep_nak_set = stm32_usbfs_ep_nak_set,
	.ep_write_packet = stm32_usbfs_ep_write_packet,
	.ep_read_packet = stm32_usbfs_ep_read_packet,
	.poll = stm32_usbfs_poll,
};

/** Initialize the USB device controller hardware of the STM32. */
static usbd_device *stm32f103_usbd_init(void)
{
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USBEN);
	SET_REG(USB_CNTR_REG, 0);
	SET_REG(USB_BTABLE_REG, 0);
	SET_REG(USB_ISTR_REG, 0);

	/* Enable RESET, SUSPEND, RESUME and CTR interrupts. */
	SET_REG(USB_CNTR_REG, USB_CNTR_RESETM | USB_CNTR_CTRM |
		USB_CNTR_SUSPM | USB_CNTR_WKUPM);
	return &stm32_usbfs_dev;
}

/**
 * Copy a data buffer to packet memory.
 *
 * @param vPM Destination pointer into packet memory.
 * @param buf Source pointer to data buffer.
 * @param len Number of bytes to copy.
 */
void stm32_usbfs_copy_to_pm(volatile void *vPM, const void *buf, uint16_t len)
{
	const uint16_t *lbuf = buf;
	volatile uint16_t *PM = vPM;

	for (len = (len + 1) >> 1; len; PM += 2, lbuf++, len--) {
		*PM = *lbuf;
	}
}

/**
 * Copy a data buffer from packet memory.
 *
 * @param buf Source pointer to data buffer.
 * @param vPM Destination pointer into packet memory.
 * @param len Number of bytes to copy.
 */
void stm32_usbfs_copy_from_pm(void *buf, const volatile void *vPM, uint16_t len)
{
	uint16_t *lbuf = buf;
	const volatile uint16_t *PM = vPM;
	uint8_t odd = len & 1;

	for (len >>= 1; len; PM += 2, lbuf++, len--) {
		*lbuf = *PM;
	}

	if (odd) {
		*(uint8_t *) lbuf = *(uint8_t *) PM;
	}
}

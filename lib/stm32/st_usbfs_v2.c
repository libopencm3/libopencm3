/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2014 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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
#include <libopencm3/stm32/st_usbfs.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/bos.h>
#include "../usb/usb_private.h"
#include "common/st_usbfs_core.h"

/** Initialize the USB device controller hardware of the STM32. */
static usbd_device *st_usbfs_v2_usbd_init(void)
{
	rcc_periph_clock_enable(RCC_USB);
	SET_REG(USB_CNTR_REG, 0);
	SET_REG(USB_BTABLE_REG, 0);
	SET_REG(USB_ISTR_REG, 0);

	/* Enable RESET, SUSPEND, RESUME and CTR interrupts. */
	SET_REG(USB_CNTR_REG, USB_CNTR_RESETM | USB_CNTR_CTRM | USB_CNTR_SUSPM | USB_CNTR_WKUPM);
	SET_REG(USB_BCDR_REG, USB_BCDR_DPPU);
	return &st_usbfs_dev;
}

void st_usbfs_copy_to_pm(volatile void *const vPM, const void *const buf, const uint16_t len)
{
	/*
	 * This is a bytewise copy, so it always works, even on CM0(+)
	 * that don't support unaligned accesses.
	 */
	const uint8_t *const src = buf;
	volatile uint16_t *const packet_memory = vPM;
	for (size_t idx = 0; idx < len; idx += 2) {
		packet_memory[idx >> 1U] = ((uint16_t)src[idx + 1U] << 8U) | src[idx];
	}
}

/**
 * Copy a data buffer from packet memory.
 *
 * @param buf Destination pointer for data buffer.
 * @param vPM Source pointer into packet memory.
 * @param len Number of bytes to copy.
 */
void st_usbfs_copy_from_pm(void *const buf, const volatile void *const vPM, const uint16_t len)
{
	const volatile uint16_t *const packet_memory = vPM;
	const size_t blocks = len >> 1U;

	/* If the buffer to write into is at an unaligned address for uint16_t access */
	if (((uintptr_t)buf) & 0x01U) {
		uint8_t *const dest = (uint8_t *)buf;
		for (size_t idx = 0U; idx < blocks; ++idx) {
			/* Extract the next data block from packet memory */
			const uint16_t value = packet_memory[idx];
			/* Copy it into the output buffer byte at a time to handle the misalignment */
			dest[(idx << 1U) + 0U] = value;
			dest[(idx << 1U) + 1U] = value >> 8;
		}
	} else {
		/* The buffer to write into is aligned, so do things the easy way */
		uint16_t *const dest = (uint16_t *)buf;
		for (size_t idx = 0U; idx < blocks; ++idx) {
			/* Extract the next data block from packet memory and stuff it into the output buffer */
			dest[idx] = packet_memory[idx];
		}
	}

	/* If the number of bytes needed is not a full number of packet memory blocks, handle the odd byte out */
	if (len & 1U) {
		uint8_t *const dest = (uint8_t *)buf;
		dest[blocks << 1U] = packet_memory[blocks];
	}
}

static void st_usbfs_v2_disconnect(usbd_device *usbd_dev, bool disconnected)
{
	(void)usbd_dev;
	uint16_t reg = GET_REG(USB_BCDR_REG);
	if (disconnected) {
		SET_REG(USB_BCDR_REG, reg & ~USB_BCDR_DPPU);
	} else {
		SET_REG(USB_BCDR_REG, reg | USB_BCDR_DPPU);
	}
}

const struct _usbd_driver st_usbfs_v2_usb_driver = {
	.init = st_usbfs_v2_usbd_init,
	.set_address = st_usbfs_set_address,
	.ep_setup = st_usbfs_ep_setup,
	.ep_reset = st_usbfs_endpoints_reset,
	.ep_stall_set = st_usbfs_ep_stall_set,
	.ep_stall_get = st_usbfs_ep_stall_get,
	.ep_nak_set = st_usbfs_ep_nak_set,
	.ep_write_packet = st_usbfs_ep_write_packet,
	.ep_read_packet = st_usbfs_ep_read_packet,
	.disconnect = st_usbfs_v2_disconnect,
	.poll = st_usbfs_poll,
};

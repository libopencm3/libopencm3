/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/tools.h>
#include <libopencm3/stm32/otg_fs.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"

static void stm32f107_usbd_init(void);
static void stm32f107_set_address(u8 addr);
static void stm32f107_ep_setup(u8 addr, u8 type, u16 max_size,
				void (*callback) (u8 ep));
static void stm32f107_endpoints_reset(void);
static void stm32f107_ep_stall_set(u8 addr, u8 stall);
static u8 stm32f107_ep_stall_get(u8 addr);
static u16 stm32f107_ep_write_packet(u8 addr, const void *buf, u16 len);
static u16 stm32f107_ep_read_packet(u8 addr, void *buf, u16 len);
static void stm32f107_poll(void);

const struct _usbd_driver stm32f107_usb_driver = {
	.init = stm32f107_usbd_init,
	.set_address = stm32f107_set_address,
	.ep_setup = stm32f107_ep_setup,
	.ep_reset = stm32f107_endpoints_reset,
	.ep_stall_set = stm32f107_ep_stall_set,
	.ep_stall_get = stm32f107_ep_stall_get,
	.ep_write_packet = stm32f107_ep_write_packet,
	.ep_read_packet = stm32f107_ep_read_packet,
	.poll = stm32f107_poll,
};

/** Initialize the USB device controller hardware of the STM32. */
static void stm32f107_usbd_init(void)
{
	/* TODO: Enable interrupts on Reset, Transfer, Suspend and Resume */
}

static void stm32f107_set_address(u8 addr)
{
	(void)addr;
	/* TODO: Set device address and enable. */
}

static void stm32f107_ep_setup(u8 addr, u8 type, u16 max_size, 
				void (*callback) (u8 ep))
{
	/* TODO: Configure endpoint address and type.
	 * Allocate FIFO memory for endpoint.
	 * Install callback funciton.
	 */
	(void)type; (void)max_size;

	u8 dir = addr & 0x80;
	addr &= 0x7f;

	if (dir || (addr == 0)) {
		if (callback) {
			_usbd_device.
			    user_callback_ctr[addr][USB_TRANSACTION_IN] =
			    (void *)callback;
		}
	}

	if (!dir) {
		if (callback) {
			_usbd_device.
			    user_callback_ctr[addr][USB_TRANSACTION_OUT] =
			    (void *)callback;
		}
	}
}

static void stm32f107_endpoints_reset(void)
{
	/* TODO: Reset all endpoints. */
}

static void stm32f107_ep_stall_set(u8 addr, u8 stall)
{
	/* TODO: set or clear stall condition */
	(void)addr; (void)stall;
}

static u8 stm32f107_ep_stall_get(u8 addr)
{
	/* TODO: return 1 if STALL set. */
	(void)addr;

	return 0;
}

static u16 stm32f107_ep_write_packet(u8 addr, const void *buf, u16 len)
{
	addr &= 0x7F;

	/* TODO: Send packet on endpoint */
	(void)buf;

	return len;
}

static u16 stm32f107_ep_read_packet(u8 addr, void *buf, u16 len)
{
	/* TODO: Read packet from endpoint */
	(void)addr; (void)buf; (void)len;

	return len;
}

static void stm32f107_poll(void)
{
	/* TODO: Read interrupt status register */

	/* TODO: Handle USB RESET condition */
	if (0) {
		_usbd_reset();
		return;
	}

	/* TODO: Handle transfer complete condition */
	if (0) {
		u8 ep;
		u8 type;

		if (_usbd_device.user_callback_ctr[ep][type])
			_usbd_device.user_callback_ctr[ep][type] (ep);
		/* TODO: clear any interrupt flag */
	}

	/* TODO: Handle suspend condition */
	if (0) {
		/* TODO: Clear suspend interrupt flag */
		if (_usbd_device.user_callback_suspend)
			_usbd_device.user_callback_suspend();
	}

	/* TODO: Handle wakeup condition */
	if (0) {
		/* TODO: Clear wakeup interrupt flag */
		if (_usbd_device.user_callback_resume)
			_usbd_device.user_callback_resume();
	}

	/* TODO: Handle SOF condition */
}


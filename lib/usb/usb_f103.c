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

#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/tools.h>
#include <libopencm3/stm32/f1/usb.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"

static void stm32f103_usbd_init(void);
static void stm32f103_set_address(u8 addr);
static void stm32f103_ep_setup(u8 addr, u8 type, u16 max_size,
			       void (*callback) (u8 ep));
static void stm32f103_endpoints_reset(void);
static void stm32f103_ep_stall_set(u8 addr, u8 stall);
static u8 stm32f103_ep_stall_get(u8 addr);
static void stm32f103_ep_nak_set(u8 addr, u8 nak);
static u16 stm32f103_ep_write_packet(u8 addr, const void *buf, u16 len);
static u16 stm32f103_ep_read_packet(u8 addr, void *buf, u16 len);
static void stm32f103_poll(void);

static u8 force_nak[8];

const struct _usbd_driver stm32f103_usb_driver = {
	.init = stm32f103_usbd_init,
	.set_address = stm32f103_set_address,
	.ep_setup = stm32f103_ep_setup,
	.ep_reset = stm32f103_endpoints_reset,
	.ep_stall_set = stm32f103_ep_stall_set,
	.ep_stall_get = stm32f103_ep_stall_get,
	.ep_nak_set = stm32f103_ep_nak_set,
	.ep_write_packet = stm32f103_ep_write_packet,
	.ep_read_packet = stm32f103_ep_read_packet,
	.poll = stm32f103_poll,
};

/** Initialize the USB device controller hardware of the STM32. */
static void stm32f103_usbd_init(void)
{
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USBEN);
	SET_REG(USB_CNTR_REG, 0);
	SET_REG(USB_BTABLE_REG, 0);
	SET_REG(USB_ISTR_REG, 0);

	/* Enable RESET, SUSPEND, RESUME and CTR interrupts. */
	SET_REG(USB_CNTR_REG, USB_CNTR_RESETM | USB_CNTR_CTRM |
		USB_CNTR_SUSPM | USB_CNTR_WKUPM);
}

static void stm32f103_set_address(u8 addr)
{
	/* Set device address and enable. */
	SET_REG(USB_DADDR_REG, (addr & USB_DADDR_ADDR) | USB_DADDR_ENABLE);
}

/**
 * Set the receive buffer size for a given USB endpoint.
 *
 * @param ep Index of endpoint to configure.
 * @param size Size in bytes of the RX buffer.
 */
static void usb_set_ep_rx_bufsize(u8 ep, u32 size)
{
	if (size > 62) {
		if (size & 0x1f)
			size -= 32;
		USB_SET_EP_RX_COUNT(ep, (size << 5) | 0x8000);
	} else {
		if (size & 1)
			size++;
		USB_SET_EP_RX_COUNT(ep, size << 10);
	}
}

static void stm32f103_ep_setup(u8 addr, u8 type, u16 max_size,
			       void (*callback) (u8 ep))
{
	/* Translate USB standard type codes to STM32. */
	const u16 typelookup[] = {
		[USB_ENDPOINT_ATTR_CONTROL] = USB_EP_TYPE_CONTROL,
		[USB_ENDPOINT_ATTR_ISOCHRONOUS] = USB_EP_TYPE_ISO,
		[USB_ENDPOINT_ATTR_BULK] = USB_EP_TYPE_BULK,
		[USB_ENDPOINT_ATTR_INTERRUPT] = USB_EP_TYPE_INTERRUPT,
	};
	u8 dir = addr & 0x80;
	addr &= 0x7f;

	/* Assign address. */
	USB_SET_EP_ADDR(addr, addr);
	USB_SET_EP_TYPE(addr, typelookup[type]);

	if (dir || (addr == 0)) {
		USB_SET_EP_TX_ADDR(addr, _usbd_device.pm_top);
		if (callback) {
			_usbd_device.
			    user_callback_ctr[addr][USB_TRANSACTION_IN] =
			    (void *)callback;
		}
		USB_CLR_EP_TX_DTOG(addr);
		USB_SET_EP_TX_STAT(addr, USB_EP_TX_STAT_NAK);
		_usbd_device.pm_top += max_size;
	}

	if (!dir) {
		USB_SET_EP_RX_ADDR(addr, _usbd_device.pm_top);
		usb_set_ep_rx_bufsize(addr, max_size);
		if (callback) {
			_usbd_device.
			    user_callback_ctr[addr][USB_TRANSACTION_OUT] =
			    (void *)callback;
		}
		USB_CLR_EP_RX_DTOG(addr);
		USB_SET_EP_RX_STAT(addr, USB_EP_RX_STAT_VALID);
		_usbd_device.pm_top += max_size;
	}
}

static void stm32f103_endpoints_reset(void)
{
	int i;

	/* Reset all endpoints. */
	for (i = 1; i < 8; i++) {
		USB_SET_EP_TX_STAT(i, USB_EP_TX_STAT_DISABLED);
		USB_SET_EP_RX_STAT(i, USB_EP_RX_STAT_DISABLED);
	}
	_usbd_device.pm_top = 0x40 + (2 * _usbd_device.desc->bMaxPacketSize0);
}

static void stm32f103_ep_stall_set(u8 addr, u8 stall)
{
	if (addr == 0)
		USB_SET_EP_TX_STAT(addr, stall ? USB_EP_TX_STAT_STALL :
				   USB_EP_TX_STAT_NAK);

	if (addr & 0x80) {
		addr &= 0x7F;

		USB_SET_EP_TX_STAT(addr, stall ? USB_EP_TX_STAT_STALL :
				   USB_EP_TX_STAT_NAK);

		/* Reset to DATA0 if clearing stall condition. */
		if (!stall)
			USB_CLR_EP_TX_DTOG(addr);
	} else {
		/* Reset to DATA0 if clearing stall condition. */
		if (!stall)
			USB_CLR_EP_RX_DTOG(addr);

		USB_SET_EP_RX_STAT(addr, stall ? USB_EP_RX_STAT_STALL :
				   USB_EP_RX_STAT_VALID);
	}
}

static u8 stm32f103_ep_stall_get(u8 addr)
{
	if (addr & 0x80) {
		if ((*USB_EP_REG(addr & 0x7F) & USB_EP_TX_STAT) ==
		    USB_EP_TX_STAT_STALL)
			return 1;
	} else {
		if ((*USB_EP_REG(addr) & USB_EP_RX_STAT) ==
		    USB_EP_RX_STAT_STALL)
			return 1;
	}
	return 0;
}

static void stm32f103_ep_nak_set(u8 addr, u8 nak)
{
	/* It does not make sence to force NAK on IN endpoints. */
	if (addr & 0x80)
		return;

	force_nak[addr] = nak;

	if (nak)
		USB_SET_EP_RX_STAT(addr, USB_EP_RX_STAT_NAK);
	else
		USB_SET_EP_RX_STAT(addr, USB_EP_RX_STAT_VALID);
}

/**
 * Copy a data buffer to packet memory.
 *
 * @param vPM Destination pointer into packet memory.
 * @param buf Source pointer to data buffer.
 * @param len Number of bytes to copy.
 */
static void usb_copy_to_pm(volatile void *vPM, const void *buf, u16 len)
{
	const u16 *lbuf = buf;
	volatile u16 *PM = vPM;

	for (len = (len + 1) >> 1; len; PM += 2, lbuf++, len--)
		*PM = *lbuf;
}

static u16 stm32f103_ep_write_packet(u8 addr, const void *buf, u16 len)
{
	addr &= 0x7F;

	if ((*USB_EP_REG(addr) & USB_EP_TX_STAT) == USB_EP_TX_STAT_VALID)
		return 0;

	usb_copy_to_pm(USB_GET_EP_TX_BUFF(addr), buf, len);
	USB_SET_EP_TX_COUNT(addr, len);
	USB_SET_EP_TX_STAT(addr, USB_EP_TX_STAT_VALID);

	return len;
}

/**
 * Copy a data buffer from packet memory.
 *
 * @param buf Source pointer to data buffer.
 * @param vPM Destination pointer into packet memory.
 * @param len Number of bytes to copy.
 */
static void usb_copy_from_pm(void *buf, const volatile void *vPM, u16 len)
{
	u16 *lbuf = buf;
	const volatile u16 *PM = vPM;
	u8 odd = len & 1;

	for (len >>= 1; len; PM += 2, lbuf++, len--)
		*lbuf = *PM;

	if (odd)
		*(u8 *) lbuf = *(u8 *) PM;
}

static u16 stm32f103_ep_read_packet(u8 addr, void *buf, u16 len)
{
	if ((*USB_EP_REG(addr) & USB_EP_RX_STAT) == USB_EP_RX_STAT_VALID)
		return 0;

	len = MIN(USB_GET_EP_RX_COUNT(addr) & 0x3ff, len);
	usb_copy_from_pm(buf, USB_GET_EP_RX_BUFF(addr), len);
	USB_CLR_EP_RX_CTR(addr);

	if (!force_nak[addr])
		USB_SET_EP_RX_STAT(addr, USB_EP_RX_STAT_VALID);

	return len;
}

static void stm32f103_poll(void)
{
	u16 istr = *USB_ISTR_REG;

	if (istr & USB_ISTR_RESET) {
		_usbd_device.pm_top = 0x40;
		_usbd_reset();
		USB_CLR_ISTR_RESET();
		return;
	}

	if (istr & USB_ISTR_CTR) {
		u8 ep = istr & USB_ISTR_EP_ID;
		u8 type = (istr & USB_ISTR_DIR) ? 1 : 0;

		if (type) /* OUT or SETUP transaction */
			type += (*USB_EP_REG(ep) & USB_EP_SETUP) ? 1 : 0;
		else /* IN transaction */
			USB_CLR_EP_TX_CTR(ep);

		if (_usbd_device.user_callback_ctr[ep][type])
			_usbd_device.user_callback_ctr[ep][type] (ep);
		else
			USB_CLR_EP_RX_CTR(ep);
	}

	if (istr & USB_ISTR_SUSP) {
		USB_CLR_ISTR_SUSP();
		if (_usbd_device.user_callback_suspend)
			_usbd_device.user_callback_suspend();
	}

	if (istr & USB_ISTR_WKUP) {
		USB_CLR_ISTR_WKUP();
		if (_usbd_device.user_callback_resume)
			_usbd_device.user_callback_resume();
	}

	if (istr & USB_ISTR_SOF) {
		if (_usbd_device.user_callback_sof)
			_usbd_device.user_callback_sof();
		USB_CLR_ISTR_SOF();
	}
}

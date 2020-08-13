/*
 * This file is part of the libopencm3 project.
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
#include <libopencm3/stm32/st_usbfs.h>
#include <libopencm3/stm32/tools.h>
#include <libopencm3/usb/usbd.h>
#include "../usb/usb_private.h"
#include "common/st_usbfs_core.h"
#include "common/st_usbfs_v2.h"

/*
 * Double buffering flow control only kicks in after the first transaction
 * following double buffering configuration. If the endpoint described in
 * register set n has not completed its first double buffering transmission, then
 * the n'th most significnt bit in this byte will be 1. The bit isn't needed for
 * reception.
 */
static uint8_t first_double_run;

static uint16_t st_usbfs_double_ep_write_packet(usbd_device *dev, uint8_t addr,
		const void *buf, uint16_t len)
{
	addr &= 0x7F;

	/* only bulk endpoints can be double buffered. Otherwise fall back to
	   the single buffered implementation */
	if (USB_GET_EP_TYPE(addr) != USB_EP_TYPE_BULK) {
		return st_usbfs_ep_write_packet(dev, addr, buf, len);
	}

	if (USB_GET_EP_SW_BUF_TX(addr)) {
		/* buffer 1 */
		st_usbfs_copy_to_pm(USB_GET_EP_TX_BUFF_1(addr), buf, len);
		USB_SET_EP_TX_COUNT_1(addr, len);

		USB_TGL_EP_TX_SW_BUF(addr);

		/*
		 * Block until hardware is done sending the previous buffer.
		 * If we don't wait then this function could be called again
		 * and will st_usbfs_copy_to_pm into that buffer before it is
		 * all sent.
		 */
		while(!USB_GET_EP_HW_BUF_TX(addr));
	} else {
		/* buffer 0 */
		st_usbfs_copy_to_pm(USB_GET_EP_TX_BUFF_0(addr), buf, len);
		USB_SET_EP_TX_COUNT_0(addr, len);

		USB_TGL_EP_TX_SW_BUF(addr);

		/* block until hardware is done sending the previous buffer */
		while(USB_GET_EP_HW_BUF_TX(addr));
	}

	/* the double buffering flow control only kicks in after the first send */
	if (first_double_run & (1 << addr)) {
		USB_SET_EP_TX_STAT(addr, USB_EP_TX_STAT_VALID);
		USB_TGL_EP_TX_HW_BUF(addr);
		first_double_run &= ~(1 << addr);
	}

	return len;
}

static uint16_t st_usbfs_double_ep_read_packet(usbd_device *dev, uint8_t addr,
					 void *buf, uint16_t len)
{
	/* only bulk endpoints can be double buffered. Otherwise fall back to
	   the single buffered implementation */
	if (USB_GET_EP_TYPE(addr) != USB_EP_TYPE_BULK) {
		return st_usbfs_ep_read_packet(dev, addr, buf, len);
	}

	if (USB_GET_EP_SW_BUF_RX(addr)) {
		/* buffer 1 */
		len = MIN(USB_GET_EP_RX_COUNT_1(addr) & 0x3ff, len);
		st_usbfs_copy_from_pm(buf, USB_GET_EP_RX_BUFF_1(addr), len);
	} else {
		/* buffer 0 */
		len = MIN(USB_GET_EP_RX_COUNT_0(addr) & 0x3ff, len);
		st_usbfs_copy_from_pm(buf, USB_GET_EP_RX_BUFF_0(addr), len);
	}

	/* There's no need for flow control because the hardware will
	   automatically NAK while HW_BUF == SW_BUF */

	USB_TGL_EP_RX_SW_BUF(addr);

	USB_CLR_EP_RX_CTR(addr);
	return len;
}

static void st_usbfs_double_ep_setup(usbd_device *usb_dev, uint8_t addr,
		uint8_t type,
		uint16_t max_size,
		void (*callback) (usbd_device *usbd_dev,
		uint8_t ep))
{
	/* only bulk endpoints can be double buffered. Otherwise fall back to
	   the single buffered implementation */
	if (type != USB_ENDPOINT_ATTR_BULK) {
		return st_usbfs_ep_setup(usb_dev, addr, type, max_size, callback);
	}

	uint8_t dir = addr & 0x80;
	addr &= 0x7f;

	/* Assign address. */
	USB_SET_EP_ADDR(addr, addr);
	USB_SET_EP_TYPE(addr, USB_EP_TYPE_BULK);
	USB_SET_EP_KIND(addr); /* double buffered mode */

	first_double_run |= (1 << addr);

	if (dir || (addr == 0)) {
		USB_SET_EP_TX_ADDR_0(addr, usb_dev->pm_top);
		if (callback) {
			usb_dev->user_callback_ctr[addr][USB_TRANSACTION_IN] =
				(void *)callback;
		}
		USB_SET_EP_TX_STAT(addr, USB_EP_TX_STAT_NAK);
		usb_dev->pm_top += max_size;

		/* second buffer */
		USB_SET_EP_TX_ADDR_1(addr, usb_dev->pm_top);
		USB_SET_EP_RX_STAT(addr, USB_EP_RX_STAT_DISABLED);
		usb_dev->pm_top += max_size;
	}

	if (!dir) {
		uint16_t realsize;
		uint32_t reg_size;
		realsize = st_usbfs_calc_ep_rx_bufsize(usb_dev, max_size,
				&reg_size);

		USB_SET_EP_RX_ADDR_0(addr, usb_dev->pm_top);
		USB_SET_EP_RX_COUNT_0(addr, reg_size);
		if (callback) {
			usb_dev->user_callback_ctr[addr][USB_TRANSACTION_OUT] =
				(void *)callback;
		}
		USB_SET_EP_RX_STAT(addr, USB_EP_RX_STAT_VALID);
		usb_dev->pm_top += realsize;

		/* second buffer */
		USB_SET_EP_RX_ADDR_1(addr, usb_dev->pm_top);
		USB_SET_EP_RX_COUNT_1(addr, reg_size);
		USB_SET_EP_TX_STAT(addr, USB_EP_TX_STAT_DISABLED);
		usb_dev->pm_top += realsize;
	}
}

const struct _usbd_driver st_usbfs_double_usb_driver = {
	.init = st_usbfs_v2_usbd_init,
	.set_address = st_usbfs_set_address,
	.ep_setup = st_usbfs_double_ep_setup,
	.ep_reset = st_usbfs_endpoints_reset,
	.ep_stall_set = st_usbfs_ep_stall_set,
	.ep_stall_get = st_usbfs_ep_stall_get,
	.ep_nak_set = st_usbfs_ep_nak_set,
	.ep_write_packet = st_usbfs_double_ep_write_packet,
	.ep_read_packet = st_usbfs_double_ep_read_packet,
	.disconnect = st_usbfs_v2_disconnect,
	.poll = st_usbfs_poll,
};

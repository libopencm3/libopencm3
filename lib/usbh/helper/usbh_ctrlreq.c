/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#include <libopencm3/usbh/helper/ctrlreq.h>

#define CONTROL_TIMEOUT 500

usbh_urb_id usbh_ctrlreq_ep0(usbh_device *dev, uint8_t bmRequestType,
	uint8_t bRequest, uint16_t wValue, uint16_t wIndex,
	void *data, uint16_t wLength, usbh_transfer_callback callback)
{
	usbh_transfer transfer = {
		.device = dev,
		.ep_type = USBH_EP_CONTROL,
		.ep_addr = 0,
		.ep_size = usbh_device_ep0_size(dev),
		.data = data,
		.length = wLength,
		.flags = USBH_FLAG_NONE,
		.timeout = CONTROL_TIMEOUT,
		.callback = callback,
		.setup = {
			.bmRequestType = bmRequestType,
			.bRequest = bRequest,
			.wValue = wValue,
			.wIndex = wIndex,
			.wLength = wLength
		}
	};

	return usbh_transfer_submit(&transfer);
}

usbh_urb_id usbh_ctrlreq_read_desc(usbh_device *dev, uint8_t type,
	uint8_t index, void *buf, uint16_t len, usbh_transfer_callback callback)
{
	return usbh_ctrlreq_ep0(dev, USB_REQ_TYPE_IN, USB_REQ_GET_DESCRIPTOR,
		(type << 8) | index, 0x0000, buf, len, callback);
}

usbh_urb_id usbh_ctrlreq_read_dev_desc(usbh_device *dev, void *desc,
	uint16_t len, usbh_transfer_callback callback)
{
	return usbh_ctrlreq_read_desc(dev, USB_DT_DEVICE, 0, desc, len, callback);
}

usbh_urb_id usbh_ctrlreq_read_config_desc(usbh_device *dev, uint8_t index,
	void *desc, uint16_t len, usbh_transfer_callback callback)
{
	return usbh_ctrlreq_read_desc(dev, USB_DT_CONFIGURATION, index, desc, len,
		callback);
}

usbh_urb_id usbh_ctrlreq_read_string_desc(usbh_device *dev, uint8_t index,
	void *desc, uint16_t len, usbh_transfer_callback callback)
{
	return usbh_ctrlreq_read_desc(dev, USB_DT_STRING, index, desc, len, callback);
}

usbh_urb_id usbh_ctrlreq_set_address(usbh_device *dev, uint8_t addr,
	usbh_transfer_callback callback)
{
	return usbh_ctrlreq_ep0(dev, 0x00, USB_REQ_SET_ADDRESS, addr, 0x0000,
		NULL, 0x0000, callback);
}

usbh_urb_id usbh_ctrlreq_set_config(usbh_device *dev, uint8_t bConfigurationValue,
	usbh_transfer_callback callback)
{
	return usbh_ctrlreq_ep0(dev, 0x00, USB_REQ_SET_CONFIGURATION,
		bConfigurationValue, 0x0000, NULL, 0x0000, callback);
}

usbh_urb_id usbh_ctrlreq_set_interface(usbh_device *dev, uint8_t bInterface,
	uint8_t bAlternateSetting, usbh_transfer_callback callback)
{
	return usbh_ctrlreq_ep0(dev, USB_REQ_TYPE_INTERFACE, USB_REQ_SET_INTERFACE,
		bAlternateSetting, bInterface, NULL, 0x0000, callback);
}

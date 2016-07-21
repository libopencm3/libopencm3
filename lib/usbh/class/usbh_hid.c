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

#include <libopencm3/usbh/class/hid.h>
#include <libopencm3/usbh/helper/ctrlreq.h>

usbh_urb_id usbh_hid_set_protocol(usbh_device *dev, uint8_t protocol,
	uint8_t interface, usbh_transfer_callback callback)
{
	return usbh_ctrlreq_ep0(dev, USB_REQ_TYPE_CLASS | USB_REQ_TYPE_INTERFACE,
		USB_REQ_HID_SET_PROTOCOL, protocol, interface, NULL, 0, callback);
}

usbh_urb_id usbh_hid_get_report(usbh_device *dev, uint16_t type,
	uint8_t report_id, uint8_t interface, void *data, uint16_t len,
	usbh_transfer_callback callback)
{
	return usbh_ctrlreq_ep0(dev,
		USB_REQ_TYPE_IN | USB_REQ_TYPE_CLASS | USB_REQ_TYPE_INTERFACE,
		USB_REQ_HID_GET_REPORT, (type << 8) | report_id, interface, data, len,
		callback);
}

usbh_urb_id usbh_hid_set_idle(usbh_device *dev, uint8_t duration,
	uint8_t report_id, uint8_t interface, usbh_transfer_callback callback)
{
	return usbh_ctrlreq_ep0(dev,
		USB_REQ_TYPE_CLASS | USB_REQ_TYPE_INTERFACE,
		USB_REQ_HID_SET_IDLE, (duration << 8) | report_id, interface, NULL, 0,
		callback);
}

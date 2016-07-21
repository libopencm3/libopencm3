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

#ifndef LIBOPENCM3_USBH_CLASS_HID_H
#define LIBOPENCM3_USBH_CLASS_HID_H

#include <libopencm3/usbh/usbh.h>
#include <libopencm3/usb/hid.h>

/**
 * Perform a SET_PROTOCOL @a protcol to @a dev on @a interface
 * @param dev USB Device
 * @param protocol HID Protocol
 * @param interface Interface to set on
 * @param callback Callback when done
 * @return URB ID
 */
usbh_urb_id usbh_hid_set_protocol(usbh_device *dev, uint8_t protocol,
	uint8_t interface, usbh_transfer_callback callback);

/**
 * Perform a GET_REPORT @a type and @a id on @a interface
 * @param dev USB Device
 * @param type Report Type
 * @param report_id Report ID
 * @param interface HID Interface
 * @param data Store report data to
 * @param len Number of bytes of report length to read
 * @param callback Callback when done
 * @return URB ID
 */
usbh_urb_id usbh_hid_get_report(usbh_device *dev, uint16_t type,
	uint8_t report_id, uint8_t interface, void *data, uint16_t len,
	usbh_transfer_callback callback);

/**
 * Perform SET_IDLE on @a id with @a duration for @a interface
 * @param dev USB Device
 * @param duration Duration
 * @param report_id Report ID
 * @param interface HID Interface
 * @param callback Callback when done
 * @return URB ID
 */
usbh_urb_id usbh_hid_set_idle(usbh_device *dev, uint8_t duration,
	uint8_t report_id, uint8_t interface, usbh_transfer_callback callback);

#endif

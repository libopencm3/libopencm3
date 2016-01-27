/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
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

#ifndef USB_GADGET0_H
#define USB_GADGET0_H

#include <libopencm3/usb/usbd.h>

/**
 * Start up the gadget0 framework.
 * @param driver which usbd hardware driver to use.
 * @param userserial if non-null, will become the serial number.
 *	You should provide this to help the test code find something particular
 *	to the hardware.
 * @return the usbd_device created.
*/
usbd_device *gadget0_init(const usbd_driver *driver, const char *userserial);

#endif

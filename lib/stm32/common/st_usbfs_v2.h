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

#ifndef __ST_USBFS_V2_H
#define __ST_USBFS_V2_H

#include <libopencm3/usb/usbd.h>

BEGIN_DECLS

/**
 * Initialize the USB device controller hardware of the STM32.
 */
usbd_device *st_usbfs_v2_usbd_init(void);

/**
 * Controll the embedded pull-up on the DP line.
 *
 * @param usbd_dev usb device to operate upon
 * @param disconnected The value to set the embedded DP pull-up. Setting this to
 *                     false can be used to signalize disconnect to the host.
 */
void st_usbfs_v2_disconnect(usbd_device *usbd_dev, bool disconnected);

END_DECLS

#endif

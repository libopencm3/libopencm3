/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
 * Copyright (C) 2018 Seb Holzapfel <schnommus@gmail.com>
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

#ifndef LIBOPENCM3_EFM32_USB_H
#define LIBOPENCM3_EFM32_USB_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/usb/dwc/otg_fs.h>

#define USB_CTRL			MMIO32(USB_BASE + 0x000)
#define USB_STATUS			MMIO32(USB_BASE + 0x004)
#define USB_IF				MMIO32(USB_BASE + 0x008)
#define USB_IFS				MMIO32(USB_BASE + 0x00C)
#define USB_IFC				MMIO32(USB_BASE + 0x010)
#define USB_IEN				MMIO32(USB_BASE + 0x014)
#define USB_ROUTE			MMIO32(USB_BASE + 0x018)

/* USB_CTRL */
/* Bits 31:26 - Reserved */
#define USB_CTRL_BIASPROGEM23_MASK	(0x3 << 24)
/* Bits 23:22 - Reserved */
#define USB_CTRL_BIASPROGEM01_MASK	(0x3 << 20)
/* Bits 19:18 - Reserved */
#define USB_CTRL_VREGOSEN		(1 << 17)
#define USB_CTRL_VREGDIS		(1 << 16)
/* Bits 15:10 - Reserved */
#define USB_CTRL_LEMIDLEEN		(1 << 9)
/* Bit 8 - Reserved */
#define USB_CTRL_LEMPHYCTRL		(1 << 7)
/* Bit 6 - Reserved */
#define USB_CTRL_LEMOSCCTRL_MASK	(0x3 << 4)
#define USB_CTRL_LEMOSCCTRL_NONE	(0x0 << 4)
#define USB_CTRL_LEMOSCCTRL_GATE	(0x1 << 4)
/* Bits 3:2 - Reserved */
#define USB_CTRL_DMPUAP			(1 << 1)
/* Bit 0 - Reserved */

/* USB_ROUTE */
/* Bits 31:3 - Reserved */
#define USB_ROUTE_DMPUPEN		(1 << 2)
/* Bit 1 - Reserved */
#define USB_ROUTE_PHYPEN		(1 << 0)

#endif

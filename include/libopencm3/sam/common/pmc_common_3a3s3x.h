/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2015 Felix Held <felix-libopencm3@felixheld.de>
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

#if defined(LIBOPENCM3_PMC_H)

#ifndef LIBOPENCM3_PMC_COMMON_3A3S3X_H
#define LIBOPENCM3_PMC_COMMON_3A3S3X_H


/* --- Power Management Controller (PMC) registers ----------------------- */

/* Peripheral Clock Enable Register 0 */
#define PMC_PCER0			MMIO32(PMC_BASE + 0x0010)

/* Peripheral Clock Disable Register 0 */
#define PMC_PCDR0			MMIO32(PMC_BASE + 0x0014)

/* Peripheral Clock Status Register 0 */
#define PMC_PCSR0			MMIO32(PMC_BASE + 0x0018)

/* USB Clock Register */
#define PMC_USB				MMIO32(PMC_BASE + 0x0038)

/* Peripheral Clock Enable Register 1 */
#define PMC_PCER1			MMIO32(PMC_BASE + 0x0100)

/* Peripheral Clock Disable Register 1 */
#define PMC_PCDR1			MMIO32(PMC_BASE + 0x0104)

/* Peripheral Clock Status Register 1 */
#define PMC_PCSR1			MMIO32(PMC_BASE + 0x0108)


/* --- Register contents --------------------------------------------------- */


/* --- PMC USB Clock Register (PMC_USB) ------------------------------------ */

/* Divider for USB Clock */
#define PMC_USB_USBDIV_SHIFT		8
#define PMC_USB_USBDIV_MASK		(0x0F << PMC_USB_USBDIV_SHIFT)

/* USB Input Clock Selection */
#define PMC_USB_USBS			(0x01 << 0)


#endif

#else
#warning "pmc_common_3a3s3x.h should not be included explicitly, only via pmc.h"
#endif

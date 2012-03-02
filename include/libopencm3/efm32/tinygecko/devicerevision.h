/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

/* FIXME: proper documentation, see where this fits, if we need this at all
 * etc. this was just a first attempt at implementing something easy with
 * MMIO32. */

/* this implements d0034_efm32tg_reference_manual.pdf's 7.3.4 "Device Revision"
 * section */

#ifndef LIBOPENCM3_EFM32_TINYGECKO_DEVICEREVISION_H
#define LIBOPENCM3_EFM32_TINYGECKO_DEVICEREVISION_H

#include <libopencm3/cm3/common.h>

#define DEVICEREVISION_PID2 MMIO32(0xE00FFFE8)
#define DEVICEREVISION_PID3 MMIO32(0xE00FFFEC)

/* devicerevision_revision_get has a comment that would make these definitions
 * obsolete; i'm not sure how far it is reasonable to parameterize everythin
 * g*/
#define DEVICEREVISION_REVISION_LENGTH 4
#define DEVICEREVISION_REVISION_SHIFT 4
#define DEVICEREVISION_REVISION_MASK (~(~0<<DEVICEREVISION_REVISION_LENGTH)<<DEVICEREVISION_REVISION_SHIFT) /* 0x000000f0, bits 7:4 */

#define DEVICEREVISION_REVISION_A 0x00

/* Read the device's hardcoded Revision. Return values can be compared against
 * the DEVICEREVISION_REVISION_A constant, the only value given in the current
 * specification. */
extern u8 devicerevision_revision_get(void);

#endif

/** @defgroup gima_defines Global Input Multiplexer Array Defines

@brief <b>Defined Constants and Types for the LPC43xx Global Input Multiplexer
Array</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_GIMA_H
#define LPC43XX_GIMA_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- GIMA registers ----------------------------------------------------- */

/* Timer 0 CAP0_0 capture input multiplexer (GIMA output 0) */
#define GIMA_CAP0_0_IN                  MMIO32(GIMA_BASE + 0x000)

/* Timer 0 CAP0_1 capture input multiplexer (GIMA output 1) */
#define GIMA_CAP0_1_IN                  MMIO32(GIMA_BASE + 0x004)

/* Timer 0 CAP0_2 capture input multiplexer (GIMA output 2) */
#define GIMA_CAP0_2_IN                  MMIO32(GIMA_BASE + 0x008)

/* Timer 0 CAP0_3 capture input multiplexer (GIMA output 3) */
#define GIMA_CAP0_3_IN                  MMIO32(GIMA_BASE + 0x00C)

/* Timer 1 CAP1_0 capture input multiplexer (GIMA output 4) */
#define GIMA_CAP1_0_IN                  MMIO32(GIMA_BASE + 0x010)

/* Timer 1 CAP1_1 capture input multiplexer (GIMA output 5) */
#define GIMA_CAP1_1_IN                  MMIO32(GIMA_BASE + 0x014)

/* Timer 1 CAP1_2 capture input multiplexer (GIMA output 6) */
#define GIMA_CAP1_2_IN                  MMIO32(GIMA_BASE + 0x018)

/* Timer 1 CAP1_3 capture input multiplexer (GIMA output 7) */
#define GIMA_CAP1_3_IN                  MMIO32(GIMA_BASE + 0x01C)

/* Timer 2 CAP2_0 capture input multiplexer (GIMA output 8) */
#define GIMA_CAP2_0_IN                  MMIO32(GIMA_BASE + 0x020)

/* Timer 2 CAP2_1 capture input multiplexer (GIMA output 9) */
#define GIMA_CAP2_1_IN                  MMIO32(GIMA_BASE + 0x024)

/* Timer 2 CAP2_2 capture input multiplexer (GIMA output 10) */
#define GIMA_CAP2_2_IN                  MMIO32(GIMA_BASE + 0x028)

/* Timer 2 CAP2_3 capture input multiplexer (GIMA output 11) */
#define GIMA_CAP2_3_IN                  MMIO32(GIMA_BASE + 0x02C)

/* Timer 3 CAP3_0 capture input multiplexer (GIMA output 12) */
#define GIMA_CAP3_0_IN                  MMIO32(GIMA_BASE + 0x030)

/* Timer 3 CAP3_1 capture input multiplexer (GIMA output 13) */
#define GIMA_CAP3_1_IN                  MMIO32(GIMA_BASE + 0x034)

/* Timer 3 CAP3_2 capture input multiplexer (GIMA output 14) */
#define GIMA_CAP3_2_IN                  MMIO32(GIMA_BASE + 0x038)

/* Timer 3 CAP3_3 capture input multiplexer (GIMA output 15) */
#define GIMA_CAP3_3_IN                  MMIO32(GIMA_BASE + 0x03C)

/* SCT CTIN_0 capture input multiplexer (GIMA output 16) */
#define GIMA_CTIN_0_IN                  MMIO32(GIMA_BASE + 0x040)

/* SCT CTIN_1 capture input multiplexer (GIMA output 17) */
#define GIMA_CTIN_1_IN                  MMIO32(GIMA_BASE + 0x044)

/* SCT CTIN_2 capture input multiplexer (GIMA output 18) */
#define GIMA_CTIN_2_IN                  MMIO32(GIMA_BASE + 0x048)

/* SCT CTIN_3 capture input multiplexer (GIMA output 19) */
#define GIMA_CTIN_3_IN                  MMIO32(GIMA_BASE + 0x04C)

/* SCT CTIN_4 capture input multiplexer (GIMA output 20) */
#define GIMA_CTIN_4_IN                  MMIO32(GIMA_BASE + 0x050)

/* SCT CTIN_5 capture input multiplexer (GIMA output 21) */
#define GIMA_CTIN_5_IN                  MMIO32(GIMA_BASE + 0x054)

/* SCT CTIN_6 capture input multiplexer (GIMA output 22) */
#define GIMA_CTIN_6_IN                  MMIO32(GIMA_BASE + 0x058)

/* SCT CTIN_7 capture input multiplexer (GIMA output 23) */
#define GIMA_CTIN_7_IN                  MMIO32(GIMA_BASE + 0x05C)

/* VADC trigger input multiplexer (GIMA output 24) */
#define GIMA_VADC_TRIGGER_IN            MMIO32(GIMA_BASE + 0x060)

/* Event router input 13 multiplexer (GIMA output 25) */
#define GIMA_EVENTROUTER_13_IN          MMIO32(GIMA_BASE + 0x064)

/* Event router input 14 multiplexer (GIMA output 26) */
#define GIMA_EVENTROUTER_14_IN          MMIO32(GIMA_BASE + 0x068)

/* Event router input 16 multiplexer (GIMA output 27) */
#define GIMA_EVENTROUTER_16_IN          MMIO32(GIMA_BASE + 0x06C)

/* ADC start0 input multiplexer (GIMA output 28) */
#define GIMA_ADCSTART0_IN               MMIO32(GIMA_BASE + 0x070)

/* ADC start1 input multiplexer (GIMA output 29) */
#define GIMA_ADCSTART1_IN               MMIO32(GIMA_BASE + 0x074)

/**@}*/

#endif

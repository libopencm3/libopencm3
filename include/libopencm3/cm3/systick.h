/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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
/** @defgroup CM3_systick_defines SysTick Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the Cortex SysTick </b>
 *
 * @ingroup CM3_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>
 *
 * @date 19 August 2012
 *
 * LGPL License Terms @ref lgpl_license
 */

/**
 * @note this file has been not following the register naming scheme, the
 * correct names defined, and the old ones stay there for compatibility with
 * old software (will be deprecated in the future)
 */

/**@{*/

#ifndef LIBOPENCM3_SYSTICK_H
#define LIBOPENCM3_SYSTICK_H

#include <libopencm3/cm3/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- SYSTICK registers --------------------------------------------------- */

/* Control and status register (STK_CTRL) */
#define STK_CSR				MMIO32(SYS_TICK_BASE + 0x00)

/* reload value register (STK_LOAD) */
#define STK_RVR				MMIO32(SYS_TICK_BASE + 0x04)

/* current value register (STK_VAL) */
#define STK_CVR				MMIO32(SYS_TICK_BASE + 0x08)

/* calibration value register (STK_CALIB) */
#define STK_CALIB			MMIO32(SYS_TICK_BASE + 0x0C)

/* --- STK_CSR values ------------------------------------------------------ */
/* Bits [31:17] Reserved, must be kept cleared. */
/* COUNTFLAG: */
#define STK_CSR_COUNTFLAG		(1 << 16)

/* Bits [15:3] Reserved, must be kept cleared. */
/* CLKSOURCE: Clock source selection */
#define STK_CSR_CLKSOURCE_LSB		2
#define STK_CSR_CLKSOURCE		(1 << STK_CSR_CLKSOURCE_LSB)

/** @defgroup systick_clksource Clock source selection
@ingroup CM3_systick_defines

@{*/
#if defined(__ARM_ARCH_6M__)
#define STK_CSR_CLKSOURCE_EXT		(0 << STK_CSR_CLKSOURCE_LSB)
#define STK_CSR_CLKSOURCE_AHB		(1 << STK_CSR_CLKSOURCE_LSB)
#else
#define STK_CSR_CLKSOURCE_AHB_DIV8	(0 << STK_CSR_CLKSOURCE_LSB)
#define STK_CSR_CLKSOURCE_AHB		(1 << STK_CSR_CLKSOURCE_LSB)
#endif
/**@}*/

/* TICKINT: SysTick exception request enable */
#define STK_CSR_TICKINT			(1 << 1)
/* ENABLE: Counter enable */
#define STK_CSR_ENABLE			(1 << 0)

/* --- STK_RVR values ------------------------------------------------------ */
/* Bits [31:24] Reserved, must be kept cleared. */
/* RELOAD[23:0]: RELOAD value */
#define STK_RVR_RELOAD			0x00FFFFFF


/* --- STK_CVR values ------------------------------------------------------ */
/* Bits [31:24] Reserved, must be kept cleared. */
/* CURRENT[23:0]: Current counter value */
#define STK_CVR_CURRENT			0x00FFFFFF


/* --- STK_CALIB values ---------------------------------------------------- */
/* NOREF: NOREF flag */
#define STK_CALIB_NOREF			(1 << 31)
/* SKEW: SKEW flag */
#define STK_CALIB_SKEW			(1 << 30)
/* Bits [29:24] Reserved, must be kept cleared. */
/* TENMS[23:0]: Calibration value */
#define STK_CALIB_TENMS			0x00FFFFFF

/* --- Function Prototypes ------------------------------------------------- */

BEGIN_DECLS

void systick_set_reload(uint32_t value);
bool systick_set_frequency(uint32_t freq, uint32_t ahb);
uint32_t systick_get_reload(void);
uint32_t systick_get_value(void);
void systick_set_clocksource(uint8_t clocksource);
void systick_interrupt_enable(void);
void systick_interrupt_disable(void);
void systick_counter_enable(void);
void systick_counter_disable(void);
uint8_t systick_get_countflag(void);
void systick_clear(void);

uint32_t systick_get_calib(void);

END_DECLS

#endif
/**@}*/


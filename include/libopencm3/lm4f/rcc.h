/** @defgroup rcc_defines Reset and Clock Control

@brief <b>Defined Constants and Types for the LM4F Reset and Clock Control</b>

@ingroup LM4Fxx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012
Alexandru Gagniuc <mr.nuke.me@gmail.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

#ifndef LM4F_RCC_H
#define LM4F_RCC_H

/**@{*/

#include <libopencm3/lm4f/systemcontrol.h>

/**
 * \brief Oscillator source values
 *
 * Possible values of the oscillator source.
 */
enum osc_src {
	OSCSRC_MOSC		= SYSCTL_RCC2_OSCSRC2_MOSC,
	OSCSRC_PIOSC		= SYSCTL_RCC2_OSCSRC2_PIOSC,
	OSCSRC_PIOSC_D4		= SYSCTL_RCC2_OSCSRC2_PIOSC_D4,
	OSCSRC_30K_INT		= SYSCTL_RCC2_OSCSRC2_30K,
	OSCSRC_32K_EXT		= SYSCTL_RCC2_OSCSRC2_32K768,
};

/**
 * \brief PWM clock divisor values
 *
 * Possible values of the binary divisor used to predivide the system clock down
 * for use as the timing reference for the PWM module.
 */
enum pwm_clkdiv {
	PWMDIV_2		= SYSCTL_RCC_PWMDIV_2,
	PWMDIV_4		= SYSCTL_RCC_PWMDIV_4,
	PWMDIV_8		= SYSCTL_RCC_PWMDIV_8,
	PWMDIV_16		= SYSCTL_RCC_PWMDIV_16,
	PWMDIV_32		= SYSCTL_RCC_PWMDIV_32,
	PWMDIV_64		= SYSCTL_RCC_PWMDIV_64,
};

/**
 * \brief Predefined crystal values
 *
 * Predefined crystal values for the XTAL field in SYSCTL_RCC.
 * Using these predefined values in the XTAL field, the SYSCTL_PLLFREQ0 and
 * SYSCTL_PLLFREQ1 are automatically adjusted in hardware to provide a PLL clock
 * of 400MHz.
 */
enum xtal_t {
	XTAL_4M			= SYSCTL_RCC_XTAL_4M,
	XTAL_4M_096		= SYSCTL_RCC_XTAL_4M_096,
	XTAL_4M_9152		= SYSCTL_RCC_XTAL_4M_9152,
	XTAL_5M			= SYSCTL_RCC_XTAL_5M,
	XTAL_5M_12		= SYSCTL_RCC_XTAL_5M_12,
	XTAL_6M			= SYSCTL_RCC_XTAL_6M,
	XTAL_6M_144		= SYSCTL_RCC_XTAL_6M_144,
	XTAL_7M_3728		= SYSCTL_RCC_XTAL_7M_3728,
	XTAL_8M			= SYSCTL_RCC_XTAL_8M,
	XTAL_8M_192		= SYSCTL_RCC_XTAL_8M_192,
	XTAL_10M		= SYSCTL_RCC_XTAL_10M,
	XTAL_12M		= SYSCTL_RCC_XTAL_12M,
	XTAL_12M_288		= SYSCTL_RCC_XTAL_12M_288,
	XTAL_13M_56		= SYSCTL_RCC_XTAL_13M_56,
	XTAL_14M_31818		= SYSCTL_RCC_XTAL_14M_31818,
	XTAL_16M		= SYSCTL_RCC_XTAL_16M,
	XTAL_16M_384		= SYSCTL_RCC_XTAL_16M_384,
	XTAL_18M		= SYSCTL_RCC_XTAL_18M,
	XTAL_20M		= SYSCTL_RCC_XTAL_20M,
	XTAL_24M		= SYSCTL_RCC_XTAL_24M,
	XTAL_25M		= SYSCTL_RCC_XTAL_25M,
};

/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS
/* Low-level clock API */
void rcc_configure_xtal(enum xtal_t xtal);
void rcc_disable_main_osc(void);
void rcc_disable_interal_osc(void);
void rcc_enable_main_osc(void);
void rcc_enable_interal_osc(void);
void rcc_enable_rcc2(void);
void rcc_pll_off(void);
void rcc_pll_on(void);
void rcc_set_osc_source(enum osc_src src);
void rcc_pll_bypass_disable(void);
void rcc_pll_bypass_enable(void);
void rcc_set_pll_divisor(uint8_t div400);
void rcc_set_pwm_divisor(enum pwm_clkdiv div);
void rcc_usb_pll_off(void);
void rcc_usb_pll_on(void);
void rcc_wait_for_pll_ready(void);
/* High-level clock API */
void rcc_change_pll_divisor(uint8_t plldiv400);
uint32_t rcc_get_system_clock_frequency(void);
void rcc_sysclk_config(enum osc_src src, enum xtal_t xtal, uint8_t pll_div400);

END_DECLS

/**@}*/

#endif /* LM4F_RCC_H */

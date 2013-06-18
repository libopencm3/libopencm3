/** @addtogroup rcc_file
 *
 * @subsection rcc_common_api_ex Common Peripheral API.
 * @brief   <b>libopencm3 STM32F4xx Reset and Clock Control</b>
 * @author  @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran at seznam.cz>
 * @date    18 Jun 2013
 *
 * This library supports the Reset and Clock Control System for the peripherals
 * in the STM32 series F2 and F4 of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * <b>Example 1</b>: Enable clocks for the peripherals ADC1, GPIOA and USART1
 *
 * @code
 * rcc_periph_clock_enable(RCC_ADC1);
 * rcc_periph_clock_enable(RCC_GPIOA);
 * rcc_periph_clock_enable(RCC_USART1);
 * @endcode
 *
 * <b>Example 2</b>: Reset the ADC converter peripheral
 *
 * @code
 * rcc_periph_reset_pulse(RCC_ADC1);
 * @endcode
 *
 * @note Some of the chips supports disabling sleep modes. To control clocks of the
 * peripheral in the low power mode, use
 * @code rcc_periph_clock_lp_enable(RCC_USART1); @endcode
 *
 * For the list of available peripheral names, see #periph_t enumeration
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Edward Cheeseman <evbuilder@users.sourceforge.org>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
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

#include <libopencm3/stm32/rcc.h>

/**@{*/

/**
 * @name Common Peripheral API
 */
/**@{*/
/*---------------------------------------------------------------------------*/
/** @brief Enable Peripheral Clock in running mode.
 *
 * Enable the clock on particular peripheral.
 *
 * @param[in] periph periph_t Peripheral Name
 *
 * For available constants, see #periph_t (RCC_UART1 for example)
 */

void rcc_periph_clock_enable(periph_t periph)
{
	MMIO32(RCC_BASE + 0x30 + (periph >> 5)) |= 1 << (periph & 0x1f);
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Peripheral Clock in running mode.
 * Disable the clock on particular peripheral.
 *
 * @param[in] periph periph_t Peripheral Name
 *
 * For available constants, see #periph_t (RCC_UART1 for example)
 */

void rcc_periph_clock_disable(periph_t periph)
{
	MMIO32(RCC_BASE + 0x30 + (periph >> 5)) &= ~(1 << (periph & 0x1f));
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Peripheral Clock in low power mode.
 *
 * Enable the clock on particular peripheral.
 *
 * @param[in] periph periph_t Peripheral Name
 *
 * For available constants, see #periph_t (RCC_UART1 for example)
 */

void rcc_periph_clock_lp_enable(periph_t periph)
{
	MMIO32(RCC_BASE + 0x50 + (periph >> 5)) |= 1 << (periph & 0x1f);
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Peripheral Clock in low power mode.
 *
 * Disable the clock on particular peripheral.
 *
 * @param[in] periph periph_t Peripheral Name
 *
 * For available constants, see #periph_t (RCC_UART1 for example)
 */

void rcc_periph_clock_lp_disable(periph_t periph)
{
	MMIO32(RCC_BASE + 0x50 + (periph >> 5)) &= ~(1 << (periph & 0x1f));
}

/*---------------------------------------------------------------------------*/
/** @brief Reset Peripheral, pulsed
 *
 * Reset particular peripheral, and restore to working state.
 *
 * @param[in] periph periph_t Peripheral name
 *
 * For available constants, see #periph_t (RCC_UART1 for example)
 */

void rcc_periph_reset_pulse(periph_t periph)
{
	MMIO32(RCC_BASE + 0x10 + (periph >> 5)) |= (1 << (periph & 0x1f));
	MMIO32(RCC_BASE + 0x10 + (periph >> 5)) &= ~(1 << (periph & 0x1f));
}

/*---------------------------------------------------------------------------*/
/** @brief Reset Peripheral, hold
 *
 * Reset particular peripheral, and hold in reset state.
 *
 * @param[in] periph periph_t Peripheral name
 *
 * For available constants, see #periph_t  (RCC_UART1 for example)
 */

void rcc_periph_reset_hold(periph_t periph)
{
	MMIO32(RCC_BASE + 0x10 + (periph >> 5)) |= (1 << (periph & 0x1f));
}

/*---------------------------------------------------------------------------*/
/** @brief Reset Peripheral, release
 *
 * Restore peripheral from reset state to working state.
 *
 * @param[in] periph periph_t Peripheral name
 *
 * For available constants, see #periph_t (RCC_UART1 for example)
 */

void rcc_periph_reset_release(periph_t periph)
{
	MMIO32(RCC_BASE + 0x10 + (periph >> 5)) &= ~(1 << (periph & 0x1f));
}

/**@}*/

/**@}*/


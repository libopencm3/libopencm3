/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <bufran@seznam.cz>
 * .. file is merged from many other copyrighted files of stm32 family
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
/**@{*/

#include <libopencm3/stm32/rcc.h>

/*---------------------------------------------------------------------------*/
/** @brief RCC Enable Peripheral Clocks.
 *
 * Enable the clock on particular peripherals. There are three registers
 * involved, each one controlling the enabling of clocks associated with the
 * AHB, APB1 and APB2 respectively. Several peripherals could be enabled
 * simultaneously <em>only if they are controlled by the same register</em>.
 *
 * @param[in] *reg Unsigned int32. Pointer to a Clock Enable Register
 *			 (either RCC_AHBENR, RCC_APB1ENR or RCC_APB2ENR)
 *
 * @param[in] en Unsigned int32. Logical OR of all enables to be set
 * @li If register is RCC_AHBER, from @ref rcc_ahbenr_en
 * @li If register is RCC_APB1ENR, from @ref rcc_apb1enr_en
 * @li If register is RCC_APB2ENR, from @ref rcc_apb2enr_en
 */

void rcc_peripheral_enable_clock(volatile uint32_t *reg, uint32_t en)
{
	*reg |= en;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Disable Peripheral Clocks.
 *
 * Enable the clock on particular peripherals. There are three registers
 * involved, each one controlling the enabling of clocks associated with
 * the AHB, APB1 and APB2 respectively. Several peripherals could be disabled
 * simultaneously <em>only if they are controlled by the same register</em>.
 *
 * @param[in] *reg Unsigned int32. Pointer to a Clock Enable Register
 *			 (either RCC_AHBENR, RCC_APB1ENR or RCC_APB2ENR)
 * @param[in] en Unsigned int32. Logical OR of all enables to be used for
 * disabling.
 * @li If register is RCC_AHBER, from @ref rcc_ahbenr_en
 * @li If register is RCC_APB1ENR, from @ref rcc_apb1enr_en
 * @li If register is RCC_APB2ENR, from @ref rcc_apb2enr_en
 */
void rcc_peripheral_disable_clock(volatile uint32_t *reg, uint32_t en)
{
	*reg &= ~en;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Reset Peripherals.
 *
 * Reset particular peripherals. There are three registers involved, each one
 * controlling reset of peripherals associated with the AHB, APB1 and APB2
 * respectively. Several peripherals could be reset simultaneously <em>only if
 * they are controlled by the same register</em>.
 *
 * @param[in] *reg Unsigned int32. Pointer to a Reset Register
 *			 (either RCC_AHBENR, RCC_APB1ENR or RCC_APB2ENR)
 * @param[in] reset Unsigned int32. Logical OR of all resets.
 * @li If register is RCC_AHBRSTR, from @ref rcc_ahbrstr_rst
 * @li If register is RCC_APB1RSTR, from @ref rcc_apb1rstr_rst
 * @li If register is RCC_APB2RSTR, from @ref rcc_apb2rstr_rst
 */
void rcc_peripheral_reset(volatile uint32_t *reg, uint32_t reset)
{
	*reg |= reset;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Remove Reset on Peripherals.
 *
 * Remove the reset on particular peripherals. There are three registers
 * involved, each one controlling reset of peripherals associated with the AHB,
 * APB1 and APB2 respectively. Several peripherals could have the reset removed
 * simultaneously <em>only if they are controlled by the same register</em>.
 *
 * @param[in] *reg Unsigned int32. Pointer to a Reset Register
 *			 (either RCC_AHBENR, RCC_APB1ENR or RCC_APB2ENR)
 * @param[in] clear_reset Unsigned int32. Logical OR of all resets to be
 * removed:
 * @li If register is RCC_AHBRSTR, from @ref rcc_ahbrstr_rst
 * @li If register is RCC_APB1RSTR, from @ref rcc_apb1rstr_rst
 * @li If register is RCC_APB2RSTR, from @ref rcc_apb2rstr_rst
 */
void rcc_peripheral_clear_reset(volatile uint32_t *reg, uint32_t clear_reset)
{
	*reg &= ~clear_reset;
}

#define _RCC_REG(i)		MMIO32(RCC_BASE + ((i) >> 5))
#define _RCC_BIT(i)		(1 << ((i) & 0x1f))

/*---------------------------------------------------------------------------*/
/** @brief Enable Peripheral Clock in running mode.
 *
 * Enable the clock on particular peripheral.
 *
 * @param[in] periph periph_t Peripheral Name
 *
 * For available constants, see #periph_t (RCC_UART1 for example)
 */

void rcc_periph_clock_enable(enum rcc_periph_clken clken)
{
	_RCC_REG(clken) |= _RCC_BIT(clken);
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Peripheral Clock in running mode.
 * Disable the clock on particular peripheral.
 *
 * @param[in] periph periph_t Peripheral Name
 *
 * For available constants, see #periph_t (RCC_UART1 for example)
 */

void rcc_periph_clock_disable(enum rcc_periph_clken clken)
{
	_RCC_REG(clken) &= ~_RCC_BIT(clken);
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

void rcc_periph_reset_pulse(enum rcc_periph_rst rst)
{
	_RCC_REG(rst) |= _RCC_BIT(rst);
	_RCC_REG(rst) &= ~_RCC_BIT(rst);
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

void rcc_periph_reset_hold(enum rcc_periph_rst rst)
{
	_RCC_REG(rst) |= _RCC_BIT(rst);
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

void rcc_periph_reset_release(enum rcc_periph_rst rst)
{
	_RCC_REG(rst) &= ~_RCC_BIT(rst);
}
/**@}*/

#undef _RCC_REG
#undef _RCC_BIT

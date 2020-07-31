/** @addtogroup lptimer_file LPTIM peripheral API
 * @ingroup peripheral_apis
 *
 * @author @htmlonly &copy; @endhtmlonly 2019 Guillaume Revaillot <g.revaillot@gmail.com>
 *
 * @date 2 July 2019
 *
 * LGPL License Terms @ref lgpl_license
 *
 * @section lptim_api_ex Basic LPTIMER handling API.
 *
 * Example: LPTIM1 with 2x clock prescaler, from internal clock (LSE), irq on match and reload.
 *
 * @code
 *
 *	rcc_set_peripheral_clk_sel(LPTIM1, RCC_CCIPR_LPTIM1SEL_LSE);
 *
 *	rcc_periph_clock_enable(RCC_LPTIM1);
 *
 *	lptimer_set_internal_clock_source(LPTIM1);
 *	lptimer_enable_trigger(LPTIM1, LPTIM_CFGR_TRIGEN_SW);
 *	lptimer_set_prescaler(LPTIM1, LPTIM_CFGR_PRESC_2);
 *
 *	lptimer_enable(LPTIM1);
 *
 *	lptimer_set_period(LPTIM1, 0xffff);
 *	lptimer_set_compare(LPTIM1, 1234);
 *
 *	lptimer_enable_irq(LPTIM1, LPTIM_IER_ARRMIE | LPTIM_IER_CMPMIE);
 *	nvic_enable_irq(NVIC_LPTIM1_IRQ);
 *
 *	lptimer_start_counter(LPTIM1, LPTIM_CR_CNTSTRT);
 *
 * @endcode
 *
 * Note: LPTIM internal clock source selection is device specific, see clock tree
 * and rcc section of reference manual.
 *
 */
/*
 * This file is part of the libopencm3 project.
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

#include <libopencm3/stm32/lptimer.h>

/** @brief Set lptimer Counter
 *
 * Set the value of a lptimer counter.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] count Counter value.
*/
void lptimer_set_counter(uint32_t lptimer_peripheral, uint16_t count)
{
	LPTIM_CNT(lptimer_peripheral) = count;
}

/** @brief Read lptimer Counter
 *
 * Read back the value of lptimer counter.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @returns Counter value.
 */
uint16_t lptimer_get_counter(uint32_t lptimer_peripheral)
{
	return LPTIM_CNT(lptimer_peripheral);
}

/** @brief Clear lptimer Status Flag.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] flag Status Register clear flag (@ref lptim_icr)
 */
void lptimer_clear_flag(uint32_t lptimer_peripheral, uint32_t flag)
{
	LPTIM_ICR(lptimer_peripheral) = flag;
}

/** @brief Read lptimer Status Flag.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] flag Status Register flag (@ref lptim_isr)
 * @returns flag set.
 */
bool lptimer_get_flag(uint32_t lptimer_peripheral, uint32_t flag)
{
	return (LPTIM_ISR(lptimer_peripheral) & flag);
}

/*---------------------------------------------------------------------------*/
/** @brief Enable lptimer interrupts.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] irq Logical or of all interrupt enable bits to be set (@ref lptim_ier)
 */
void lptimer_enable_irq(uint32_t lptimer_peripheral, uint32_t irq)
{
	LPTIM_IER(lptimer_peripheral) |= irq;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable lptimer Interrupts.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] irq Logical or of all interrupt enable bits to be cleared (@ref lptim_ier)
 */
void lptimer_disable_irq(uint32_t lptimer_peripheral, uint32_t irq)
{
	LPTIM_IER(lptimer_peripheral) &= ~irq;
}

/** @brief Enable lptimer.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 */
void lptimer_enable(uint32_t lptimer_peripheral)
{
	LPTIM_CR(lptimer_peripheral) |= LPTIM_CR_ENABLE;
}

/** @brief Disable lptimer.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 */
void lptimer_disable(uint32_t lptimer_peripheral)
{
	LPTIM_CR(lptimer_peripheral) &= ~LPTIM_CR_ENABLE;
}

/** @brief Start lptimer in a given mode.
 *
 * Starts the timer in specified mode - Either Single (@ref LPTIM_CR_SNGSTRT) or
 * Continuous mode (@ref LPTIM_CR_CNTSTRT). In Single mode, the timer will stop at
 * next match on compare or period value.
 * If LPTIM_CR_SNGSTRT is set while timer is started in countious mode, it
 * will stop at next match on compare or period value.
 * If Software trigger is disabled, start will be delayed until programmed
 * triggers is detected.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] mode lptimer start mode (@ref LPTIM_CR_SNGSTRT or @ref LPTIM_CR_CNTSTRT)
 */
void lptimer_start_counter(uint32_t lptimer_peripheral, uint32_t mode)
{
	LPTIM_CR(lptimer_peripheral) |= mode;
}

/** @brief Set lptimer clock prescaler.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] prescaler Clock prescaler (@ref lptim_cfgr_presc)
 */
void lptimer_set_prescaler(uint32_t lptimer_peripheral, uint32_t prescaler)
{
	uint32_t reg32 = LPTIM_CFGR(lptimer_peripheral);
	reg32 &= ~(LPTIM_CFGR_PRESC_MASK << LPTIM_CFGR_PRESC_SHIFT);
	LPTIM_CFGR(lptimer_peripheral) = reg32 | prescaler;
}

/** @brief Enable lptimer External Trigger
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] trigen Enable Trigger
 */
void lptimer_enable_trigger(uint32_t lptimer_peripheral, uint32_t trigen)
{
	uint32_t reg32 = LPTIM_CFGR(lptimer_peripheral);
	reg32 &= ~(LPTIM_CFGR_TRIGEN_MASK << LPTIM_CFGR_TRIGEN_SHIFT);
	LPTIM_CFGR(lptimer_peripheral) = reg32 | trigen;
}

/** @brief Select lptimer Trigger Source
 *
 * Select timer external trigger source.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] trigger_source Trigger selector (@ref lptim_cfgr_trigsel)
 */
void lptimer_select_trigger_source(uint32_t lptimer_peripheral, uint32_t trigger_source)
{
	uint32_t reg32 = LPTIM_CFGR(lptimer_peripheral);
	reg32 &= ~(LPTIM_CFGR_TRIGSEL_MASK << LPTIM_CFGR_TRIGSEL_SHIFT);
	LPTIM_CFGR(lptimer_peripheral) = reg32 | trigger_source;
}

/** @brief Set lptimer counter Compare Value
 *
 * Set the timer compare value. Must only be set with timer enabled.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] compare_value Compare value.
 */
void lptimer_set_compare(uint32_t lptimer_peripheral, uint16_t compare_value)
{
	LPTIM_CMP(lptimer_peripheral) = compare_value;
}

/** @brief Set lptimer period
 *
 * Set the timer period in the auto-reload register. Must only be set with timer
 * enabled.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 * @param[in] period_value Autoreload value. Must be greater that CMP value.
 */
void lptimer_set_period(uint32_t lptimer_peripheral, uint16_t period_value)
{
	LPTIM_ARR(lptimer_peripheral) = period_value;
}

/** @brief Enable lptimer Preload mode.
 *
 * Enable lptimer preload mode, delaying update of period and compare registers
 * to the end of current period.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 */
void lptimer_enable_preload(uint32_t lptimer_peripheral)
{
	LPTIM_CFGR(lptimer_peripheral) |= LPTIM_CFGR_PRELOAD;
}

/** @brief Disable lptimer Preload mode.
 *
 * Disable lptimer preload mode, ensureing updated period and compare registers
 * values are taken in account immediatly.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 */
void lptimer_disable_preload(uint32_t lptimer_peripheral)
{
	LPTIM_CFGR(lptimer_peripheral) &= ~LPTIM_CFGR_PRELOAD;
}


/** @brief Set lptimer Internal Clock source
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 */
void lptimer_set_internal_clock_source(uint32_t lptimer_peripheral)
{
	LPTIM_CFGR(lptimer_peripheral) &= ~LPTIM_CFGR_CKSEL;
}

/** @brief Set lptimer External Clock source
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 */
void lptimer_set_external_clock_source(uint32_t lptimer_peripheral)
{
	LPTIM_CFGR(lptimer_peripheral) |= LPTIM_CFGR_CKSEL;
}

/** @brief Set lptimer Waveform Output Polarity High
 *
 * Set lptimer waveform output to reflect compare result between LPTIN_CNT
 * and LPTIM_CMP.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 */
void lptimer_set_waveform_polarity_high(uint32_t lptimer_peripheral)
{
	LPTIM_CFGR(lptimer_peripheral) |= LPTIM_CFGR_WAVPOL;
}

/** @brief Set lptimer Waveform Output Polarity Low
 *
 * Set lptimer waveform output to reflect the inverse of the compare result
 * between LPTIN_CNT and LPTIM_CMP.
 *
 * @param[in] lptimer_peripheral lptimer base address (@ref lptim_reg_base)
 */
void lptimer_set_waveform_polarity_low(uint32_t lptimer_peripheral)
{
	LPTIM_CFGR(lptimer_peripheral) &= ~LPTIM_CFGR_WAVPOL;
}

/**@}*/

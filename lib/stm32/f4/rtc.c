/** @defgroup rtc_file RTC
 *
 * @ingroup STM32F4xx
 *
 * @brief <b>libopencm3 STM32F4xx RTC</b>
 *
 * @version 1.0.0
 *
 * @date 4 March 2013
 *
 * LGPL License Terms @ref lgpl_license
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

#include <libopencm3/stm32/exti.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/rtc.h>


/*---------------------------------------------------------------------------*/
/** @brief Enable the wakeup timer
    @warning You must unlock the registers before using this function

*/
void rtc_enable_wakeup_timer(void)
{
	RTC_CR |= RTC_CR_WUTE | (RTC_CR_OSEL_WAKEUP << RTC_CR_OSEL_SHIFT);
	rtc_enable_wakeup_timer_interrupt();
}

/*---------------------------------------------------------------------------*/
/** @brief Disable the wakeup timer
    @warning You must unlock the registers before using this function

*/
void rtc_disable_wakeup_timer(void)
{
	RTC_CR &= ~RTC_CR_WUTE;
	rtc_disable_wakeup_timer_interrupt();
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the wakeup timer interrupt
    @warning You must unlock the registers before using this function

*/
void rtc_enable_wakeup_timer_interrupt(void)
{
	/* FTFM:
	 * To enable the RTC Wakeup interrupt, the following sequence is
	 * required:
	 * 1. Configure and enable the EXTI Line 22 in interrupt mode and
	 *    select the rising edge sensitivity.
	 */
	exti_enable_request(EXTI22);
	exti_set_trigger(EXTI22, EXTI_TRIGGER_RISING);

	/* 2. Configure and enable the RTC_WKUP IRQ channel in the NVIC. */
	nvic_enable_irq(NVIC_RTC_WKUP_IRQ);
	nvic_set_priority(NVIC_RTC_WKUP_IRQ, 1);

	/* 3. Configure the RTC to generate the RTC wakeup timer event. */
	RTC_CR |= RTC_CR_WUTIE;   /* Enable the interrupt */
}

/*---------------------------------------------------------------------------*/
/** @brief Disable the wakeup timer interrupt
    @warning You must unlock the registers before using this function

*/
void rtc_disable_wakeup_timer_interrupt(void)
{
	/* 1. Disable EXTI Line 22 */
	exti_disable_request(EXTI22);

	/* 2. Disable RTC_WKUP IRQ channel in the NVIC. */
	nvic_disable_irq(NVIC_RTC_WKUP_IRQ);

	/* 3. Disable RTC wakeup timer event. */
	RTC_CR &= ~RTC_CR_WUTIE;
}

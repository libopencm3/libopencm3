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
/** @brief Setup the RTC timing regs
    @warning Blocking.  Checks the RTC_INIT bit via a while loop.  Hardware should guarantee this bit becoming active within a handful of clock cycles.
    @param async this 7 bit value has a one added, then divides RTCCLK
    @param sync this 13 bit value has a one added, then divides the result from async
    @param date BCD encoded date to start RTC
    @param time BCD encoded time to start RTC

Sets the clock divider components and loads the current time and date into the RTC regs.  References Table 2 from AN3371 app note on RTCs for STM32 F0, F2, F3, F4 and L1
*/

void rtc_initialize(uint32_t sync, uint32_t async, uint32_t date, uint32_t time)
{
    /* unlock the rtc domain */
    rtc_unlock();

    /* set the INIT bit to freeze the RTC and allow for editing */
    RTC_ISR |= RTC_ISR_INIT;
    /* wait for previous to take effect */
    while (!(RTC_ISR & RTC_ISR_INITF));

    /* set the LSE raw prescaler and synchronous prescaler */
    rtc_set_prescaler(sync, async);

    /* load date and time registers */
    RTC_DR = date;
    RTC_TR = time;
    /* set 24h time */
    RTC_CR &= ~(RTC_CR_FMT);

    /* end setup by clearing the init bit */
    RTC_ISR &= ~(RTC_ISR_INIT);

    /* lock it back up */
    rtc_lock();
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

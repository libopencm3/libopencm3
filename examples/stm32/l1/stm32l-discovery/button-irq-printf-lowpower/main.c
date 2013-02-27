/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/scb.h>
#include <libopencm3/stm32/dbgmcu.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/rtc.h>
#include <libopencm3/stm32/l1/rcc.h>
#include <libopencm3/stm32/l1/flash.h>

#include "syscfg.h"

static volatile struct state_t state;

int _write(int file, char *ptr, int len);

__attribute__((always_inline)) static inline void __WFI(void)
{
	__asm volatile ("wfi");
}

static void gpio_setup(void)
{
	/* green led for ticking, blue for button feedback */
	gpio_mode_setup(LED_DISCO_GREEN_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_DISCO_GREEN_PIN);
	gpio_mode_setup(LED_DISCO_BLUE_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_DISCO_BLUE_PIN);

	/* Setup GPIO pins for USART2 transmit. */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);

	/* Setup USART2 TX pin as alternate function. */
	gpio_set_af(GPIOA, GPIO_AF7, GPIO2);
}

void BUTTON_DISCO_USER_isr(void)
{
	exti_reset_request(BUTTON_DISCO_USER_EXTI);
	state.pressed = true;
	if (state.falling) {
		state.falling = false;
		exti_set_trigger(BUTTON_DISCO_USER_EXTI, EXTI_TRIGGER_RISING);
		state.hold_time = TIM_CNT(TIMER_BUTTON_PRESS);
	} else {
		state.falling = true;
		exti_set_trigger(BUTTON_DISCO_USER_EXTI, EXTI_TRIGGER_FALLING);
		state.hold_time = TIM_CNT(TIMER_BUTTON_PRESS) = 0;
	}
}

static void setup_buttons(void)
{
	/* Enable EXTI0 interrupt. */
	nvic_enable_irq(BUTTON_DISCO_USER_NVIC);

	gpio_mode_setup(BUTTON_DISCO_USER_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, BUTTON_DISCO_USER_PIN);

	/* Configure the EXTI subsystem. */
	exti_select_source(BUTTON_DISCO_USER_EXTI, BUTTON_DISCO_USER_PORT);
	state.falling = false;
	exti_set_trigger(BUTTON_DISCO_USER_EXTI, EXTI_TRIGGER_RISING);
	exti_enable_request(BUTTON_DISCO_USER_EXTI);
}

static void usart_setup(void)
{
	usart_set_baudrate(USART_CONSOLE, 115200);
	usart_set_databits(USART_CONSOLE, 8);
	usart_set_stopbits(USART_CONSOLE, USART_STOPBITS_1);
	usart_set_mode(USART_CONSOLE, USART_MODE_TX);
	usart_set_parity(USART_CONSOLE, USART_PARITY_NONE);
	usart_set_flow_control(USART_CONSOLE, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART_CONSOLE);
}

/**
 * Use USART_CONSOLE as a console.
 * @param file
 * @param ptr
 * @param len
 * @return
 */
int _write(int file, char *ptr, int len)
{
	int i;

	if (file == STDOUT_FILENO || file == STDERR_FILENO) {
		for (i = 0; i < len; i++) {
			if (ptr[i] == '\n') {
				usart_send_blocking(USART_CONSOLE, '\r');
			}
			usart_send_blocking(USART_CONSOLE, ptr[i]);
		}
		return i;
	}
	errno = EIO;
	return -1;
}

/*
 * Free running ms timer.
 */
static void setup_button_press_timer(void)
{
	timer_reset(TIMER_BUTTON_PRESS);
	timer_set_prescaler(TIMER_BUTTON_PRESS, 3999); // 4Mhz/1000hz - 1
	timer_set_period(TIMER_BUTTON_PRESS, 0xffff);
	timer_enable_counter(TIMER_BUTTON_PRESS);
}

static int setup_rtc(void)
{
	/* turn on power block to enable unlocking */
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_PWREN);
	pwr_disable_backup_domain_write_protect();

	/* reset rtc */
	RCC_CSR |= RCC_CSR_RTCRST;
	RCC_CSR &= ~RCC_CSR_RTCRST;

	/* We want to use the LSE fitted on the discovery board */
	rcc_osc_on(LSE);
	rcc_wait_for_osc_ready(LSE);

	/* Select the LSE as rtc clock */
	rcc_rtc_select_clock(RCC_CSR_RTCSEL_LSE);

	/* ?! Stdperiph examples don't turn this on until _afterwards_ which
	 * simply doesn't work.  It must be on at least to be able to configure it */
	RCC_CSR |= RCC_CSR_RTCEN;

	rtc_unlock();

	/* enter init mode */
	RTC_ISR |= RTC_ISR_INIT;
	while ((RTC_ISR & RTC_ISR_INITF) == 0)
		;

	/* set synch prescaler, using defaults for 1Hz out */
	u32 sync = 255;
	u32 async = 127;
	rtc_set_prescaler(sync, async);

	/* load time and date here if desired, and hour format */

	/* exit init mode */
	RTC_ISR &= ~(RTC_ISR_INIT);

	/* and write protect again */
	rtc_lock();

	/* and finally enable the clock */
	RCC_CSR |= RCC_CSR_RTCEN;

	/* And wait for synchro.. */
	rtc_wait_for_synchro();
	return 0;
}

static int setup_rtc_wakeup(int period)
{
	rtc_unlock();

	/* ensure wakeup timer is off */
	RTC_CR &= ~RTC_CR_WUTE;

	/* Wait until we can write */
	while ((RTC_ISR & RTC_ISR_WUTWF) == 0)
		;

	RTC_WUTR = period - 1;

	/* Use the 1Hz clock as source */
	RTC_CR &= ~(RTC_CR_WUCLKSEL_MASK << RTC_CR_WUCLKSEL_SHIFT);
	RTC_CR |= (RTC_CR_WUCLKSEL_SPRE << RTC_CR_WUCLKSEL_SHIFT);

	/* Restart WakeUp unit */
	RTC_CR |= RTC_CR_WUTE;

	/* interrupt configuration */

	/* also, let's have an interrupt */
	RTC_CR |= RTC_CR_WUTIE;

	/* done with rtc registers, lock them again */
	rtc_lock();


	nvic_enable_irq(NVIC_RTC_WKUP_IRQ);

	// EXTI configuration
	/* Configure the EXTI subsystem. */
	// not needed, this chooses ports exti_select_source(EXTI20, BUTTON_DISCO_USER_PORT);
	exti_set_trigger(EXTI20, EXTI_TRIGGER_RISING);
	exti_enable_request(EXTI20);
	return 0;
}

void rtc_wkup_isr(void)
{
	/* clear flag, not write protected */
	RTC_ISR &= ~(RTC_ISR_WUTF);
	exti_reset_request(EXTI20);
	state.rtc_ticked = true;
}

static int process_state(volatile struct state_t *st)
{
	if (st->rtc_ticked) {
		st->rtc_ticked = 0;
		printf("Tick: %x\n", (unsigned int) RTC_TR);
#if defined(FULL_USER_EXPERIENCE)
		gpio_toggle(LED_DISCO_GREEN_PORT, LED_DISCO_GREEN_PIN);
#else
		gpio_clear(LED_DISCO_GREEN_PORT, LED_DISCO_GREEN_PIN);
#endif
	}
	if (st->pressed) {
		st->pressed = false;
		if (st->falling) {
			gpio_set(LED_DISCO_BLUE_PORT, LED_DISCO_BLUE_PIN);
			printf("Pushed down!\n");
		} else {
			gpio_clear(LED_DISCO_BLUE_PORT, LED_DISCO_BLUE_PIN);
			printf("held: %u ms\n", st->hold_time);
		}
	}
	return 0;
}

static void reset_clocks(void)
{
	/* 4MHz MSI raw range 2*/
	clock_scale_t myclock_config = {
		.hpre = RCC_CFGR_HPRE_SYSCLK_NODIV,
		.ppre1 = RCC_CFGR_PPRE1_HCLK_NODIV,
		.ppre2 = RCC_CFGR_PPRE2_HCLK_NODIV,
		.voltage_scale = RANGE2,
		.flash_config = FLASH_ACR_LATENCY_0WS,
		.apb1_frequency = 4194000,
		.apb2_frequency = 4194000,
		.msi_range = RCC_ICSCR_MSIRANGE_4MHZ,
	};
	rcc_clock_setup_msi(&myclock_config);

	/* buttons and uarts */
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_GPIOAEN);
	/* user feedback leds */
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_GPIOBEN);
	/* Enable clocks for USART2. */
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);
	/* And a timers for button presses */
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_TIM7EN);
}

int main(void)
{
	reset_clocks();
	gpio_setup();
	usart_setup();
	setup_buttons();
	setup_button_press_timer();
	printf("we're awake!\n");

	setup_rtc();
	setup_rtc_wakeup(1);

	while (1) {
		PWR_CR |= PWR_CR_LPSDSR;
		pwr_set_stop_mode();
		__WFI();
		reset_clocks();
		process_state(&state);
	}

	return 0;
}

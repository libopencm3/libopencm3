/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Piotr Esden-Tempski <piotr@esden.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/nvic.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

void clock_setup(void)
{
	rcc_clock_setup_in_hse_8mhz_out_72mhz();

	/* Enable TIM1 clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_TIM1EN);

	/* Enable GPIOA, GPIOB and Alternate Function clocks. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR,
				    RCC_APB2ENR_IOPAEN |
				    RCC_APB2ENR_IOPBEN |
				    RCC_APB2ENR_AFIOEN);
}

void gpio_setup(void)
{
	/*
	 * Set GPIO12 (PORTC) (led) to
	 * 'output alternate function push-pull'.
	 */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);

	/*
	 * Set TIM1 chanel output pins to
	 * 'output alternate function push-pull'.
	 */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
		      GPIO_TIM1_CH1 |
		      GPIO_TIM1_CH2 |
		      GPIO_TIM1_CH3);

	/*
	 * Set TIM1 complementary chanel output pins to
	 * 'output alternate function push-pull'.
	 */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
		      GPIO_TIM1_CH1N |
		      GPIO_TIM1_CH2N |
		      GPIO_TIM1_CH3N);

}

void tim_setup(void)
{

	/* Enable TIM1 commutation interrupt. */
	nvic_enable_irq(NVIC_TIM1_TRG_COM_IRQ);

	/* Clock division. */
	timer_set_clock_division(TIM1, TIM_CR1_CKD_CK_INT);

	/* Timer global mode:
	 * - No divider
	 * - alignment edge
	 * - direction up
	 */
	timer_set_mode(TIM1, TIM_CR1_CKD_CK_INT,
		       TIM_CR1_CMS_EDGE,
		       TIM_CR1_DIR_UP);

	/* Enable preload. */
	timer_enable_preload(TIM1);

	/* Continous mode. */
	timer_continuous_mode(TIM1);

	/* Period (32kHz) */
	timer_set_period(TIM1, 72000000 / 32000);

	/* -- OC1 and OC1N configuration -- */

	/* Disable outputs. */
	timer_disable_oc_output(TIM1, TIM_OC1);
	timer_disable_oc_output(TIM1, TIM_OC1N);

	/* Configure global mode of line 1. */
	timer_disable_oc_clear(TIM1, TIM_OC1);
	timer_enable_oc_preload(TIM1, TIM_OC1);
	timer_set_oc_slow_mode(TIM1, TIM_OC1);
	timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_PWM1);

	/* Configure OC1. */
	timer_set_oc_polarity_high(TIM1, TIM_OC1);
	timer_set_oc_idle_state_set(TIM1, TIM_OC1);

	/* Configure OC1N. */
	timer_set_oc_polarity_high(TIM1, TIM_OC1N);
	timer_set_oc_idle_state_set(TIM1, TIM_OC1N);

	/* Set the capture compare value for OC1. */
	timer_set_oc_value(TIM1, TIM_OC1, 100);

	/* Reenable outputs. */
	timer_enable_oc_output(TIM1, TIM_OC1);
	timer_enable_oc_output(TIM1, TIM_OC1N);

	/* -- OC2 and OC2N configuration -- */

	/* Disable outputs. */
	timer_disable_oc_output(TIM1, TIM_OC2);
	timer_disable_oc_output(TIM1, TIM_OC2N);

	/* Configure global mode of line 2. */
	timer_disable_oc_clear(TIM1, TIM_OC2);
	timer_enable_oc_preload(TIM1, TIM_OC2);
	timer_set_oc_slow_mode(TIM1, TIM_OC2);
	timer_set_oc_mode(TIM1, TIM_OC2, TIM_OCM_PWM1);

	/* Configure OC2. */
	timer_set_oc_polarity_high(TIM1, TIM_OC2);
	timer_set_oc_idle_state_set(TIM1, TIM_OC2);

	/* Configure OC2N. */
	timer_set_oc_polarity_high(TIM1, TIM_OC2N);
	timer_set_oc_idle_state_set(TIM1, TIM_OC2N);

	/* Set the capture compare value for OC1. */
	timer_set_oc_value(TIM1, TIM_OC2, 200);

	/* Reenable outputs. */
	timer_enable_oc_output(TIM1, TIM_OC2);
	timer_enable_oc_output(TIM1, TIM_OC2N);

	/* -- OC3 and OC3N configuration -- */

	/* Disable outputs. */
	timer_disable_oc_output(TIM1, TIM_OC3);
	timer_disable_oc_output(TIM1, TIM_OC3N);

	/* Configure global mode of line 3. */
	timer_disable_oc_clear(TIM1, TIM_OC3);
	timer_enable_oc_preload(TIM1, TIM_OC3);
	timer_set_oc_slow_mode(TIM1, TIM_OC3);
	timer_set_oc_mode(TIM1, TIM_OC3, TIM_OCM_PWM1);

	/* Configure OC3. */
	timer_set_oc_polarity_high(TIM1, TIM_OC3);
	timer_set_oc_idle_state_set(TIM1, TIM_OC3);

	/* Configure OC3N. */
	timer_set_oc_polarity_high(TIM1, TIM_OC3N);
	timer_set_oc_idle_state_set(TIM1, TIM_OC3N);

	/* Set the capture compare value for OC3. */
	timer_set_oc_value(TIM1, TIM_OC3, 300);

	/* Reenable outputs. */
	timer_enable_oc_output(TIM1, TIM_OC3);
	timer_enable_oc_output(TIM1, TIM_OC3N);

	/* ---- */
	/* ARR reload enable */
	timer_enable_preload(TIM1);

	/* Enable outputs in the break subsystem */
	TIM1_BDTR |= TIM_BDTR_MOE;

	/* Counter enable */
	timer_enable_counter(TIM1);
}

int main(void)
{
	clock_setup();
	gpio_setup();
	tim_setup();

	while (1) {
		__asm("nop");
	}

	return 0;
}

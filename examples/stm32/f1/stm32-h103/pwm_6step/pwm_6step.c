/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Piotr Esden-Tempski <piotr@esden.net>
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

#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/f1/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/exti.h>

#define FALLING 0
#define RISING 1

u16 exti_direction = FALLING;

void clock_setup(void)
{
	rcc_clock_setup_in_hse_8mhz_out_72mhz();
}

void gpio_setup(void)
{
	/* Enable GPIOC clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);

	/* Set GPIO12 (in GPIO port C) to 'output push-pull'. */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);
}

void exti_setup(void)
{
	/* Enable GPIOA clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);

	/* Enable AFIO clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_AFIOEN);

	/* Enable EXTI0 interrupt. */
	nvic_enable_irq(NVIC_EXTI0_IRQ);

	/* Set GPIO0 (in GPIO port A) to 'input open-drain'. */
	gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_FLOAT, GPIO0);

	/* Configure the EXTI subsystem. */
	exti_select_source(EXTI0, GPIOA);
	exti_direction = FALLING;
	exti_set_trigger(EXTI0, EXTI_TRIGGER_FALLING);
	exti_enable_request(EXTI0);
}

void exti0_isr(void)
{
	exti_reset_request(EXTI0);

	if (exti_direction == FALLING) {
		// gpio_toggle(GPIOA, GPIO12);
		exti_direction = RISING;
		exti_set_trigger(EXTI0, EXTI_TRIGGER_RISING);
	} else {
		// gpio_toggle(GPIOA, GPIO12);
		timer_generate_event(TIM1, TIM_EGR_COMG);
		exti_direction = FALLING;
		exti_set_trigger(EXTI0, EXTI_TRIGGER_FALLING);
	}
}

void tim_setup(void)
{
	/* Enable TIM1 clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_TIM1EN);

	/* Enable GPIOA, GPIOB and Alternate Function clocks. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR,
				    RCC_APB2ENR_IOPAEN |
				    RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN);

	/*
	 * Set TIM1 channel output pins to
	 * 'output alternate function push-pull'.
	 */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
		      GPIO_TIM1_CH1 | GPIO_TIM1_CH2 | GPIO_TIM1_CH3);

	/*
	 * Set TIM1 complementary channel output pins to
	 * 'output alternate function push-pull'.
	 */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
		      GPIO_TIM1_CH1N | GPIO_TIM1_CH2N | GPIO_TIM1_CH3N);

	/* Enable TIM1 commutation interrupt. */
	nvic_enable_irq(NVIC_TIM1_TRG_COM_IRQ);

	/* Reset TIM1 peripheral. */
	timer_reset(TIM1);

	/* Timer global mode:
	 * - No divider
	 * - Alignment edge
	 * - Direction up
	 */
	timer_set_mode(TIM1, TIM_CR1_CKD_CK_INT,
		       TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);

	/* Reset prescaler value. */
	timer_set_prescaler(TIM1, 0);

	/* Reset repetition counter value. */
	timer_set_repetition_counter(TIM1, 0);

	/* Enable preload. */
	timer_enable_preload(TIM1);

	/* Continuous mode. */
	timer_continuous_mode(TIM1);

	/* Period (32kHz). */
	timer_set_period(TIM1, 72000000 / 32000);

	/* Configure break and deadtime. */
	timer_set_deadtime(TIM1, 10);
	timer_set_enabled_off_state_in_idle_mode(TIM1);
	timer_set_enabled_off_state_in_run_mode(TIM1);
	timer_disable_break(TIM1);
	timer_set_break_polarity_high(TIM1);
	timer_disable_break_automatic_output(TIM1);
	timer_set_break_lock(TIM1, TIM_BDTR_LOCK_OFF);

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
	timer_set_oc_value(TIM1, TIM_OC2, 100);

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
	timer_set_oc_value(TIM1, TIM_OC3, 100);

	/* Reenable outputs. */
	timer_enable_oc_output(TIM1, TIM_OC3);
	timer_enable_oc_output(TIM1, TIM_OC3N);

	/* ---- */

	/* ARR reload enable. */
	timer_enable_preload(TIM1);

	/*
	 * Enable preload of complementary channel configurations and
	 * update on COM event.
	 */
	timer_enable_preload_complementry_enable_bits(TIM1);

	/* Enable outputs in the break subsystem. */
	timer_enable_break_main_output(TIM1);

	/* Counter enable. */
	timer_enable_counter(TIM1);

	/* Enable commutation interrupt. */
	timer_enable_irq(TIM1, TIM_DIER_COMIE);
}

void tim1_trg_com_isr(void)
{
	static int step = 0;

	/* Clear the COM trigger interrupt flag. */
	timer_clear_flag(TIM1, TIM_SR_COMIF);

	/*
	 * A simplified and inefficient implementation of PWM On
	 * scheme. Look at the implementation in Open-BLDC on
	 * http://open-bldc.org for the proper implementation. This
	 * one only serves as an example.
	 *
	 * Table of the PWM scheme zone configurations when driving:
	 * @verbatim
	 *  | 1| 2| 3| 4| 5| 6|
	 * -+--+--+--+--+--+--+
	 * A|p+|++|  |p-|--|  |
	 * -+--+--+--+--+--+--+
	 * B|  |p-|--|  |p+|++|
	 * -+--+--+--+--+--+--+
	 * C|--|  |p+|++|  |p-|
	 * -+--+--+--+--+--+--+
	 *  |  |  |  |  |  |  '- 360 Deg
	 *  |  |  |  |  |  '---- 300 Deg
	 *  |  |  |  |  '------- 240 Deg
	 *  |  |  |  '---------- 180 Deg
	 *  |  |  '------------- 120 Deg
	 *  |  '----------------  60 Deg
	 *  '-------------------   0 Deg
	 *
	 * Legend:
	 * p+: PWM on the high side
	 * p-: PWM on the low side
	 * --: Low side on
	 * ++: High side on
	 *   : Floating/NC
	 * @endverbatim
	 */
	switch (step) {
	case 0: /* A PWM HIGH, B OFF, C LOW */
		timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_PWM1);
		timer_set_oc_mode(TIM1, TIM_OC2, TIM_OCM_FROZEN);
		timer_set_oc_mode(TIM1, TIM_OC3, TIM_OCM_FORCE_LOW);

		timer_enable_oc_output(TIM1, TIM_OC1);
		timer_disable_oc_output(TIM1, TIM_OC1N);

		timer_disable_oc_output(TIM1, TIM_OC2);
		timer_disable_oc_output(TIM1, TIM_OC2N);

		timer_enable_oc_output(TIM1, TIM_OC3);
		timer_enable_oc_output(TIM1, TIM_OC3N);

		step++;
		break;
	case 1: /* A HIGH, B PWM LOW, C OFF */
		timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_FORCE_HIGH);
		timer_set_oc_mode(TIM1, TIM_OC2, TIM_OCM_PWM1);
		timer_set_oc_mode(TIM1, TIM_OC3, TIM_OCM_FROZEN);

		timer_enable_oc_output(TIM1, TIM_OC1);
		timer_enable_oc_output(TIM1, TIM_OC1N);

		timer_disable_oc_output(TIM1, TIM_OC2);
		timer_enable_oc_output(TIM1, TIM_OC2N);

		timer_disable_oc_output(TIM1, TIM_OC3);
		timer_disable_oc_output(TIM1, TIM_OC3N);

		step++;
		break;
	case 2: /* A OFF, B LOW, C PWM HIGH */
		timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_FROZEN);
		timer_set_oc_mode(TIM1, TIM_OC2, TIM_OCM_FORCE_LOW);
		timer_set_oc_mode(TIM1, TIM_OC3, TIM_OCM_PWM1);

		timer_disable_oc_output(TIM1, TIM_OC1);
		timer_disable_oc_output(TIM1, TIM_OC1N);

		timer_enable_oc_output(TIM1, TIM_OC2);
		timer_enable_oc_output(TIM1, TIM_OC2N);

		timer_enable_oc_output(TIM1, TIM_OC3);
		timer_disable_oc_output(TIM1, TIM_OC3N);

		step++;
		break;
	case 3: /* A PWM LOW, B OFF, C HIGH */
		timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_PWM1);
		timer_set_oc_mode(TIM1, TIM_OC2, TIM_OCM_FROZEN);
		timer_set_oc_mode(TIM1, TIM_OC3, TIM_OCM_FORCE_HIGH);

		timer_disable_oc_output(TIM1, TIM_OC1);
		timer_enable_oc_output(TIM1, TIM_OC1N);

		timer_disable_oc_output(TIM1, TIM_OC2);
		timer_disable_oc_output(TIM1, TIM_OC2N);

		timer_enable_oc_output(TIM1, TIM_OC3);
		timer_enable_oc_output(TIM1, TIM_OC3N);

		step++;
		break;
	case 4: /* A LOW, B PWM HIGH, C OFF */
		timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_FORCE_LOW);
		timer_set_oc_mode(TIM1, TIM_OC2, TIM_OCM_PWM1);
		timer_set_oc_mode(TIM1, TIM_OC3, TIM_OCM_FROZEN);

		timer_enable_oc_output(TIM1, TIM_OC1);
		timer_enable_oc_output(TIM1, TIM_OC1N);

		timer_enable_oc_output(TIM1, TIM_OC2);
		timer_disable_oc_output(TIM1, TIM_OC2N);

		timer_disable_oc_output(TIM1, TIM_OC3);
		timer_disable_oc_output(TIM1, TIM_OC3N);

		step++;
		break;
	case 5: /* A OFF, B HIGH, C PWM LOW */
		timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_FROZEN);
		timer_set_oc_mode(TIM1, TIM_OC2, TIM_OCM_FORCE_HIGH);
		timer_set_oc_mode(TIM1, TIM_OC3, TIM_OCM_PWM1);

		timer_disable_oc_output(TIM1, TIM_OC1);
		timer_disable_oc_output(TIM1, TIM_OC1N);

		timer_enable_oc_output(TIM1, TIM_OC2);
		timer_enable_oc_output(TIM1, TIM_OC2N);

		timer_disable_oc_output(TIM1, TIM_OC3);
		timer_enable_oc_output(TIM1, TIM_OC3N);

		step = 0;
		break;
	}
	gpio_toggle(GPIOC, GPIO12);
}

int main(void)
{
	clock_setup();
	gpio_setup();
	tim_setup();
	exti_setup();

	while (1)
		__asm("nop");

	return 0;
}

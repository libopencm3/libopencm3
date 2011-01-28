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
	//timer_disable_preload(TIM1);

	/* Continous mode. */
	timer_continuous_mode(TIM1);

	/* Period (32kHz) */
	TIM1_ARR = 72000000 / 32000;

	/* -- OC1 and OC1N configuration -- */
	{
		u16 tmp_ccmr1 = 0, tmp_ccer = 0, tmp_cr2 = 0;

		/** Disable OC1. **/
		TIM1_CCER &= ~TIM_CCER_CC1E;

		/** Disable OC1N. **/
		TIM1_CCER &= ~TIM_CCER_CC1NE;

		/** Get registers. **/
		tmp_ccmr1 = TIM1_CCMR1;
		tmp_ccer = TIM1_CCER;
		tmp_cr2 = TIM1_CR2;

		/** Configure global mode of line 1 **/

		/* Disable OC1 clear. (esden: What is that?) */
		tmp_ccmr1 &= ~TIM_CCMR1_OC1CE;

		/* Set CC1 to output mode. */
		tmp_ccmr1 &= ~TIM_CCMR1_CC1S_MASK;
		tmp_ccmr1 |= TIM_CCMR1_CC1S_OUT;

		/* Enable OC1 preload enable. */
		//tmp_ccmr1 |= TIM_CCMR1_OC1PE;
		tmp_ccmr1 &= ~TIM_CCMR1_OC1PE;

		/* Disable OC1 fast mode. */
		tmp_ccmr1 &= ~TIM_CCMR1_OC1FE;

		/* Set OC1 mode to PWM1. */
		tmp_ccmr1 &= ~TIM_CCMR1_OC1M_MASK;
		tmp_ccmr1 |= TIM_CCMR1_OC1M_PWM1;

		/** Configure OC1. **/

		/* Set output polarity level, high. */
		tmp_ccer &= ~TIM_CCER_CC1P;

		/* Enable OC1 output */
		tmp_ccer |= TIM_CCER_CC1E;

		/* Set OC1 idle state to "set". (TIM1 and TIM8 only) */
		tmp_cr2 |= TIM_CR2_OIS1;

		/** Configure OC1N. **/

		/* Set output polarity level, high. (TIM1 and TIM8 only) */
		tmp_ccer &= ~TIM_CCER_CC1NP;

		/* Enable OC1N output. (TIM1 and TIM8 only) */
		tmp_ccer |= TIM_CCER_CC1NE;

		/* Set OC1N idle state to "set". (TIM1 and TIM8 only) */
		tmp_cr2 |= TIM_CR2_OIS1N;

		/** Set the capture compare value for OC1 **/
		TIM1_CCR1 = 100;

		/** Write register values **/
		TIM1_CR2 = tmp_cr2;
		TIM1_CCMR1 = tmp_ccmr1;
		TIM1_CCER = tmp_ccer;

	}

	/* -- OC2 and OC2N configuration -- */
	{
		u16 tmp_ccmr1 = 0, tmp_ccer = 0, tmp_cr2 = 0;

		/** Disable OC2. **/
		TIM1_CCER &= ~TIM_CCER_CC2E;

		/** Disable OC2N. **/
		TIM1_CCER &= ~TIM_CCER_CC2NE;

		/** Get registers. **/
		tmp_ccmr1 = TIM1_CCMR1;
		tmp_ccer = TIM1_CCER;
		tmp_cr2 = TIM1_CR2;

		/** Configure global mode of line 1 **/

		/* Disable OC2 clear. (esden: What is that?) */
		tmp_ccmr1 &= ~TIM_CCMR1_OC2CE;

		/* Set CC2 to output mode. */
		tmp_ccmr1 &= ~TIM_CCMR1_CC2S_MASK;
		tmp_ccmr1 |= TIM_CCMR1_CC2S_OUT;

		/* Enable OC2 preload enable. */
		tmp_ccmr1 |= TIM_CCMR1_OC2PE;

		/* Disable OC2 fast mode. */
		tmp_ccmr1 &= ~TIM_CCMR1_OC2FE;

		/* Set OC2 mode to PWM1. */
		tmp_ccmr1 &= ~TIM_CCMR1_OC2M_MASK;
		tmp_ccmr1 |= TIM_CCMR1_OC2M_PWM1;

		/** Configure OC2. **/

		/* Set output polarity level, high. */
		tmp_ccer &= ~TIM_CCER_CC2P;

		/* Enable OC2 output */
		tmp_ccer |= TIM_CCER_CC2E;

		/* Set OC2 idle state to "set". (TIM1 and TIM8 only) */
		tmp_cr2 |= TIM_CR2_OIS2;

		/** Configure OC2N. **/

		/* Set output polarity level, high. (TIM1 and TIM8 only) */
		tmp_ccer &= ~TIM_CCER_CC2NP;

		/* Enable OC2N output. (TIM1 and TIM8 only) */
		tmp_ccer |= TIM_CCER_CC2NE;

		/* Set OC2N idle state to "set". (TIM1 and TIM8 only) */
		tmp_cr2 |= TIM_CR2_OIS2N;

		/** Set the capture compare value for OC2 **/
		TIM1_CCR2 = 200;

		/** Write register values **/
		TIM1_CR2 = tmp_cr2;
		TIM1_CCMR1 = tmp_ccmr1;
		TIM1_CCER = tmp_ccer;

	}

	/* -- OC3 and OC3N configuration -- */
	{
		u16 tmp_ccmr2 = 0, tmp_ccer = 0, tmp_cr2 = 0;

		/** Disable OC3. **/
		TIM1_CCER &= ~TIM_CCER_CC3E;

		/** Disable OC3N. **/
		TIM1_CCER &= ~TIM_CCER_CC3NE;

		/** Get registers. **/
		tmp_ccmr2 = TIM1_CCMR2;
		tmp_ccer = TIM1_CCER;
		tmp_cr2 = TIM1_CR2;

		/** Configure global mode of line 1 **/

		/* Disable OC3 clear. (esden: What is that?) */
		tmp_ccmr2 &= ~TIM_CCMR2_OC3CE;

		/* Set CC3 to output mode. */
		tmp_ccmr2 &= ~TIM_CCMR2_CC3S_MASK;
		tmp_ccmr2 |= TIM_CCMR2_CC3S_OUT;

		/* Enable OC3 preload enable. */
		tmp_ccmr2 |= TIM_CCMR2_OC3PE;

		/* Disable OC3 fast mode. */
		tmp_ccmr2 &= ~TIM_CCMR2_OC3FE;

		/* Set OC3 mode to PWM1. */
		tmp_ccmr2 &= ~TIM_CCMR2_OC3M_MASK;
		tmp_ccmr2 |= TIM_CCMR2_OC3M_PWM1;

		/** Configure OC3. **/

		/* Set output polarity level, high. */
		tmp_ccer &= ~TIM_CCER_CC3P;

		/* Enable OC3 output */
		tmp_ccer |= TIM_CCER_CC3E;

		/* Set OC3 idle state to "set". (TIM1 and TIM8 only) */
		tmp_cr2 |= TIM_CR2_OIS3;

		/** Configure OC3N. **/

		/* Set output polarity level, high. (TIM1 and TIM8 only) */
		tmp_ccer &= ~TIM_CCER_CC3NP;

		/* Enable OC3N output. (TIM1 and TIM8 only) */
		tmp_ccer |= TIM_CCER_CC3NE;

		/* Set OC3N idle state to "set". (TIM1 and TIM8 only) */
		tmp_cr2 |= TIM_CR2_OIS3N;

		/** Set the capture compare value for OC3 **/
		TIM1_CCR3 = 300;

		/** Write register values **/
		TIM1_CR2 = tmp_cr2;
		TIM1_CCMR2 = tmp_ccmr2;
		TIM1_CCER = tmp_ccer;

	}

	/* ---- */
	/* ARR reload enable */
	TIM1_CR1 |= TIM_CR1_ARPE;

	/* Enable outputs in the break subsystem */
	TIM1_BDTR |= TIM_BDTR_MOE;

	/* Counter enable */
	TIM1_CR1 |= TIM_CR1_CEN;
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

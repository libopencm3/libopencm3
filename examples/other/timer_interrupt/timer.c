/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#include <libopenstm32/rcc.h>
#include <libopenstm32/flash.h>
#include <libopenstm32/gpio.h>
#include <libopenstm32/timer.h>
#include <libopenstm32/nvic.h>

void gpio_setup(void)
{
	/* Enable GPIOB clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, IOPBEN);

	/* Set GPIO6/7 (in GPIO port B) to 'output push-pull' for the LEDs. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO6);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO7);
}

void nvic_setup()
{
	/* without this the timer interrupt routine will never be called */
	nvic_enable_irq(NVIC_TIM2_IRQ);
	nvic_set_priority(NVIC_TIM2_IRQ, 1);	
}

void tim2_isr()
{
	/* LED2 on/off */
	gpio_toggle(GPIOB, GPIO6);

	/* clear interrrupt flag */
	TIM_SR(TIM2) &= ~TIM_SR_UIF;
}

int main(void)
{
        rcc_clock_setup_in_hse_16mhz_out_72mhz();
	gpio_setup();
	nvic_setup();

	gpio_clear(GPIOB, GPIO7);	/* LED1 on */
	gpio_set(GPIOB, GPIO6);		/* LED2 off */
	
	rcc_peripheral_enable_clock(&RCC_APB1ENR, TIM2EN);

	/* the goal is to let the LED2 glow for a second and then be off for a second */	

	/* Set timer start value */
	TIM_CNT(TIM2) = 1;

	/* Set timer prescaler. 72MHz/1440 => 50000 counts per second */
	TIM_PSC(TIM2) = 1440;

	/* End timer value. If this value is reached an interrupt is generated */
	TIM_ARR(TIM2) = 50000;

	/* Update interrupt enable */
	TIM_DIER(TIM2) |= TIM_DIER_UIE;

	/* Start timer */
	TIM_CR1(TIM2) |= TIM_CR1_CEN;

	while(1); /* Halt. */

	return 0;
}

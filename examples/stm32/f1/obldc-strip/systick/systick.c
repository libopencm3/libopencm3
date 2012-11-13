/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Piotr Esden-Tempski <piotr@esden.net>
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
#include <libopencm3/stm32/f1/flash.h>
#include <libopencm3/stm32/f1/gpio.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>

u32 temp32;

void gpio_setup(void)
{
	/* Enable alternate function peripheral clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_AFIOEN);

	/* Enable GPIOB clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);

	gpio_clear(GPIOB, GPIO4); /* LED green on */
	gpio_set(GPIOB, GPIO5);   /* LED red off */

	/* Set GPIO4/5 (in GPIO port B) to 'output push-pull' for the LEDs. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO4);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO5);

	AFIO_MAPR |= AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_JNTRST;
}

void sys_tick_handler(void)
{
	temp32++;

	/* We call this handler every 1ms so 1000ms = 1s on/off. */
	if (temp32 == 1000) {
		gpio_toggle(GPIOB, GPIO4); /* LED green on/off */
		gpio_toggle(GPIOB, GPIO5); /* LED red on/off */
		temp32 = 0;
	}
}

int main(void)
{
	rcc_clock_setup_in_hsi_out_64mhz();
	gpio_setup();

	temp32 = 0;

	/* 64MHz / 8 => 8000000 counts per second */
	systick_set_clocksource(STK_CTRL_CLKSOURCE_AHB_DIV8);

	/* 8000000/8000 = 1000 overflows per second - every 1ms one interrupt */
	systick_set_reload(8000);

	systick_interrupt_enable();

	/* Start counting. */
	systick_counter_enable();

	while (1); /* Halt. */

	return 0;
}

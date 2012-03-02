/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

/* Set STM32 to 72 MHz. */
void clock_setup(void)
{
	rcc_clock_setup_in_hse_12mhz_out_72mhz();

	/* Enable GPIOA, GPIOB, GPIOC, and AFIO clocks. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_AFIOEN);
}

void gpio_setup(void)
{
	/* LED1 */
	/* Set GPIO8 (in GPIO port A) to 'output push-pull'. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);

	/* LED2 */
	/* Set GPIO15 (in GPIO port C) to 'output push-pull'. */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO15);

	/* JTAG_TRST */
	/* Set GPIO4 (in GPIO port B) to 'output push-pull'. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO4);

	AFIO_MAPR |= AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_JNTRST;

	/* ADC4 */
	/* Set GPIO5 (in GPIO port C) to 'output push-pull'. */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO5);

	/* ADC6 */
	/* Set GPIO2 (in GPIO port C) to 'output push-pull'. */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO2);

	/* Preconfigure the LEDs. */
	gpio_set(GPIOA, GPIO8);
	gpio_set(GPIOC, GPIO15);
	gpio_set(GPIOB, GPIO4);
	gpio_set(GPIOC, GPIO5);
	gpio_set(GPIOC, GPIO2);
}

void led_set(int id, int on)
{
	if (on) {
		switch (id) {
			case 0:
				gpio_clear(GPIOA, GPIO8); /* LED1 On */
				break;
			case 1:
				gpio_clear(GPIOB, GPIO4); /* JTAG_TRST On */
				break;
			case 2:
				gpio_clear(GPIOC, GPIO2); /* ADC6 On */
				break;
			case 3:
				gpio_clear(GPIOC, GPIO5); /* ADC4 On */
				break;
			case 4:
				gpio_clear(GPIOC, GPIO15); /* LED2 On */
				break;
		}
	} else {
		switch (id) {
			case 0:
				gpio_set(GPIOA, GPIO8); /* LED1 On */
				break;
			case 1:
				gpio_set(GPIOB, GPIO4); /* JTAG_TRST On */
				break;
			case 2:
				gpio_set(GPIOC, GPIO2); /* ADC6 On */
				break;
			case 3:
				gpio_set(GPIOC, GPIO5); /* ADC4 On */
				break;
			case 4:
				gpio_set(GPIOC, GPIO15); /* LED2 On */
				break;
		}
	}
}

void led_advance(void)
{
	static int state = 0;

	if (state < 5) {
		led_set(state, 1);
	} else if (state < 10) {
		led_set(state - 5, 0);
	} else if (state < 15) {
		led_set(14 - state, 1);
	} else if (state < 20) {
		led_set(19 - state, 0);
	}

	state++;
	if(state == 20) state = 0;

}

int main(void)
{
	int i;

	clock_setup();
	gpio_setup();

	/* Blink the LEDs (PC13 and PB4) on the board. */
	while (1) {
		led_advance();
		for (i = 0; i < 800000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}

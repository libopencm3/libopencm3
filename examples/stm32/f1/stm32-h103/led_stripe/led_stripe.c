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

/*
 * This example is implementing the protocol of ZJ168 addressable LED
 * strips. These strips use the LPD6803 controller. You may be able to
 * find the datasheet here:
 * http://www.adafruit.com/datasheets/LPD6803.pdf
 */

#include <stdlib.h>
#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/f1/gpio.h>

#define SPI_BANK GPIOB
#define SCLK_PIN GPIO13
#define MOSI_PIN GPIO15

#define SMALL_DELAY_VALUE 0

#define COLOR_COUNT 50

#define SCLK(VAL)				\
	if (VAL) {				\
		gpio_set(SPI_BANK, SCLK_PIN);	\
	} else {				\
		gpio_clear(SPI_BANK, SCLK_PIN);	\
	}

#define MOSI(VAL)				\
	if (VAL) {				\
		gpio_set(SPI_BANK, MOSI_PIN);	\
	} else {				\
		gpio_clear(SPI_BANK, MOSI_PIN);	\
	}

#define SMALL_DELAY() {				\
		int j;				\
		for (j = 0; j < SMALL_DELAY_VALUE; j++)	\
			__asm__("nop");		\
	}

struct color {
	u8 r;
	u8 g;
	u8 b;
};

/* Set STM32 to 72 MHz. */
void clock_setup(void)
{
	rcc_clock_setup_in_hse_8mhz_out_72mhz();

	/* Enable GPIOB and GPIOC clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);
}

void gpio_setup(void)
{
	/* Set GPIO12 (in GPIO port C) to 'output push-pull'. */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);

	/* Set GPIO13 (in GPIO port B) to 'output push-pull'. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

	/* Set GPIO15 (in GPIO port B) to 'output push-pull'. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO15);
}

void send_colors(struct color *colors, int count)
{
	int i, k;

	/* Initialize SPI pins. */
	SCLK(0);
	MOSI(0);

	/* Start frame */
	for (i = 0; i < 32; i++) {
		SCLK(1);
		SMALL_DELAY();
		SCLK(0);
		SMALL_DELAY();
	}

	/* Color cell output */
	for (k = 0; k < count; k++) {
		/* Start bit */
		MOSI(1);
		SCLK(1);
		SMALL_DELAY();
		SCLK(0);
		SMALL_DELAY();

		/* Blue */
		for (i = 0; i < 5; i++) {
			MOSI(((colors[k].b & ((1 << 4) >> i)) != 0));
			SCLK(1);
			SMALL_DELAY();
			SCLK(0);
			SMALL_DELAY();
		}
		/* Red */
		for (i = 0; i < 5; i++) {
			MOSI(((colors[k].r & ((1 << 4) >> i)) != 0));
			SCLK(1);
			SMALL_DELAY();
			SCLK(0);
			SMALL_DELAY();
		}
		/* Green */
		for (i = 0; i < 5; i++) {
			MOSI(((colors[k].g & ((1 << 4) >> i)) != 0));
			SCLK(1);
			SMALL_DELAY();
			SCLK(0);
			SMALL_DELAY();
		}
	}

	/* End frame */
	MOSI(0);
	for (k = 0; k < count; k++) {
		SCLK(1);
		SMALL_DELAY();
		SCLK(0);
		SMALL_DELAY();
	}
}

void reset_colors(struct color *colors, int count)
{
	int i;

	for (i = 0; i < count; i++) {
		colors[i].r = 0;
		colors[i].g = 0;
		colors[i].b = 0;
	}
}

void init_colors(struct color *colors, int count)
{
	colors[0].r = 0x1F;
	colors[0].g = 0;
	colors[0].b = 0;
	colors[1].r = 0;
	colors[1].g = 0x1F;
	colors[1].b = 0;
	colors[2].r = 0;
	colors[2].g = 0;
	colors[2].b = 0x1F;

	count = count;
}

void step_colors(struct color *colors, int count)
{
	int i;
	struct color tmp_color1;
	struct color tmp_color2;

#if 0
	/* Random blinking. */
	for (i = 0; i < count; i++) {
		colors[i].r = rand() & 0x01;
		colors[i].g = rand() & 0x01;
		colors[i].b = rand() & 0x01;
	}
#endif

	/* Generate next colors. */
	tmp_color1.r = colors[0].r;
	tmp_color1.g = colors[0].g;
	tmp_color1.b = colors[0].b;
	colors[0].r = colors[count - 1].r;
	colors[0].g = colors[count - 1].g;
	colors[0].b = colors[count - 1].b;
	for (i = 1; i < count; i++) {
		tmp_color2.r = colors[i].r;
		tmp_color2.g = colors[i].g;
		tmp_color2.b = colors[i].b;
		colors[i].r = tmp_color1.r;
		colors[i].g = tmp_color1.g;
		colors[i].b = tmp_color1.b;
		tmp_color1.r = tmp_color2.r;
		tmp_color1.g = tmp_color2.g;
		tmp_color1.b = tmp_color2.b;
	}
}

int main(void)
{
	int i;

	struct color colors[COLOR_COUNT];

	clock_setup();
	gpio_setup();

	reset_colors(colors, COLOR_COUNT);
	init_colors(colors, COLOR_COUNT);

	while (1) {
		gpio_toggle(GPIOC, GPIO12);	/* LED on/off */

		send_colors(colors, COLOR_COUNT);

		step_colors(colors, COLOR_COUNT);

		for (i = 0; i < 1000000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}

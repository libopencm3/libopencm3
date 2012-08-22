/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Copyright (C) 2012 Daniel Serpell <daniel.serpell@gmail.com>
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

#include <libopencm3/stm32/f4/rcc.h>
#include <libopencm3/stm32/f4/gpio.h>
#include <libopencm3/stm32/usart.h>

void clock_setup(void)
{
	/* Enable high-speed clock at 120MHz */
	rcc_clock_setup_hse_3v3(&hse_8mhz_3v3[CLOCK_3V3_120MHZ]);

	/* Enable GPIOD clock for LED & USARTs. */
	rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPDEN);
	rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPAEN);

	/* Enable clocks for USART2. */
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);
}

void usart_setup(void)
{
	/* Setup USART2 parameters. */
	usart_set_baudrate(USART2, 38400);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART2);
}

void gpio_setup(void)
{
	/* Setup GPIO pin GPIO12 on GPIO port D for LED. */
	gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12);

	/* Setup GPIO pins for USART2 transmit. */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);

	/* Setup USART2 TX pin as alternate function. */
	gpio_set_af(GPIOA, GPIO_AF7, GPIO2);
}

/* Maximum number of iterations for the escape-time calculation */
#define maxIter 32
/* This array converts the iteration count to a character representation. */
static char color[maxIter+1] = " .:++xxXXX%%%%%%################";

/* Main mandelbrot calculation */
static int iterate(float px, float py)
{
	int it=0;
	float x=0,y=0;
	while(it<maxIter)
	{
		float nx = x*x;
		float ny = y*y;
		if( (nx + ny) > 4 )
			return it;
		// Zn+1 = Zn^2 + P
		y = 2*x*y + py;
		x = nx - ny + px;
		it++;
	}
	return 0;
}

static void mandel(float cX, float cY, float scale)
{
	int x,y;
	for(x=-60;x<60;x++)
	{
		for(y=-50;y<50;y++)
		{
			int i = iterate(cX+x*scale, cY+y*scale);
			usart_send_blocking(USART2, color[i]);
		}
		usart_send_blocking(USART2, '\r');
		usart_send_blocking(USART2, '\n');
	}
}

int main(void)
{
	float scale = 0.25f, centerX = -0.5f, centerY = 0.0f;

	clock_setup();
	gpio_setup();
	usart_setup();

	while (1) {
		/* Blink the LED (PD12) on the board with each fractal drawn. */
		gpio_toggle(GPIOD, GPIO12);	/* LED on/off */
		mandel(centerX,centerY,scale);	/* draw mandelbrot */

		/* Change scale and center */
		centerX += 0.175f * scale;
		centerY += 0.522f * scale;
		scale	*= 0.875f;

		usart_send_blocking(USART2, '\r');
		usart_send_blocking(USART2, '\n');
	}

	return 0;
}

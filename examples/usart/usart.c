/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <libopenstm32.h>

void clock_setup(void)
{
	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(SW_SYSCLKSEL_HSICLK);

	/* Set the PLL multiplication factor to 9. */
	rcc_set_pll_multiplication_factor(PLLMUL_PLL_CLK_MUL9);

	/* Select HSI/2 as PLL source. */
	rcc_set_pll_source(PLLSRC_HSI_CLK_DIV2);

	rcc_set_pllxtpre(PLLXTPRE_HSE_CLK_DIV2);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(SW_SYSCLKSEL_PLLCLK);
}

void usart_setup(void)
{
	/* Enable clocks for GPIO port B (for GPIO_USART3_TX) and USART3. */
	rcc_enable_peripheral_clock(&RCC_APB2ENR, IOPBEN);
	rcc_enable_peripheral_clock(&RCC_APB1ENR, USART3EN);

	/* Setup GPIO pin GPIO_USART3_TX/GPIO10 on GPIO port B for transmit. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
                      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART3_TX);

	/* Setup UART parameters. */
	usart_set_baudrate(USART3, 38400);
	usart_set_databits(USART3, 8);
	usart_set_stopbits(USART3, STOPBITS_1);
	usart_set_mode(USART3, MODE_TX);
	usart_set_parity(USART3, PARITY_NONE);
	usart_set_flow_control(USART3, FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART3);
}

void gpio_setup(void)
{
	/* Enable GPIOC clock. */
	rcc_enable_peripheral_clock(&RCC_APB2ENR, IOPCEN);

	/* Set GPIO12 (in GPIO port C) to 'output push-pull'. */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);
}

int main(void)
{
	int i, j = 0, c = 0;

	clock_setup();
	gpio_setup();
	usart_setup();

	/* Blink the LED (PC12) on the board with every transmitted byte. */
	while (1) {
		gpio_toggle(GPIOC, GPIO12);	/* LED on/off */
		usart_send(USART3, c + '0');	/* Send one byte on USART3. */
		c = (c == 9) ? 0 : c + 1;	/* Increment c. */
		if ((j++ % 80) == 0) {		/* Newline after line full. */
			usart_send(USART3, '\r');
			usart_send(USART3, '\n');
		}
		for (i = 0; i < 80000; i++);	/* Wait (needs -O0 CFLAGS). */
	}

	return 0;
}

u32 *vector_table[2] __attribute__ ((section(".vectors"))) = {
	(u32 *)0x20000800,	/* Use 2 KB stack (0x800 bytes). */
	(u32 *)main,		/* Use main() as reset vector for now. */
};

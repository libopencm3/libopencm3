/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <libopencm3/stm32/l1/rcc.h>
#include <libopencm3/stm32/l1/gpio.h>
#include <libopencm3/stm32/usart.h>

void clock_setup(void) {
    /* We are running on MSI after boot. */
    /* Enable GPIOD clock for LED & USARTs. */
    rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_GPIOAEN);
    rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_GPIOBEN);

    /* Enable clocks for USART2. */
    rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);
}

void usart_setup(void) {
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

void gpio_setup(void) {
    /* Setup GPIO pin GPIO7 on GPIO port B for Green LED. */
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO7);

    /* Setup GPIO pins for USART2 transmit. */
    gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);

    /* Setup USART2 TX pin as alternate function. */
    gpio_set_af(GPIOA, GPIO_AF7, GPIO2);
}

int main(void) {
    int i, j = 0, c = 0;

    clock_setup();
    gpio_setup();
    usart_setup();

    /* Blink the LED (PD12) on the board with every transmitted byte. */
    while (1) {
        gpio_toggle(GPIOB, GPIO7); /* LED on/off */
        usart_send_blocking(USART2, c + '0'); /* USART2: Send byte. */
        c = (c == 9) ? 0 : c + 1; /* Increment c. */
        if ((j++ % 80) == 0) { /* Newline after line full. */
            usart_send_blocking(USART2, '\r');
            usart_send_blocking(USART2, '\n');
        }
        for (i = 0; i < 100000; i++) /* Wait a bit. */
            __asm__("NOP");
    }

    return 0;
}

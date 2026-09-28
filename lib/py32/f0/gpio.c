/*
 * This file is part of the libopencm3 project.
 *
 * PY32F0xx GPIO implementation. Register layout matches STM32F0, so the
 * code follows the same pattern used by libopencm3 for STM32F0/L0/G0.
 *
 * Licensed under the GNU LGPL v3 or later.
 */

#include <libopencm3/py32/gpio.h>

void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
		     uint16_t gpios)
{
	uint16_t i;
	uint32_t moder = GPIO_MODER(gpioport);
	uint32_t pupdr = GPIO_PUPDR(gpioport);

	for (i = 0; i < 16; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}
		moder &= ~(0x3U << (i * 2));
		moder |=  ((uint32_t)(mode & 0x3) << (i * 2));
		pupdr &= ~(0x3U << (i * 2));
		pupdr |=  ((uint32_t)(pull_up_down & 0x3) << (i * 2));
	}
	GPIO_MODER(gpioport) = moder;
	GPIO_PUPDR(gpioport) = pupdr;
}

void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
			     uint16_t gpios)
{
	uint16_t i;
	uint32_t ospeedr;
	uint32_t otyper;

	if (otype == GPIO_OTYPE_OD) {
		GPIO_OTYPER(gpioport) |= gpios;
	} else {
		otyper = GPIO_OTYPER(gpioport);
		otyper &= ~gpios;
		GPIO_OTYPER(gpioport) = otyper;
	}

	ospeedr = GPIO_OSPEEDR(gpioport);
	for (i = 0; i < 16; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}
		ospeedr &= ~(0x3U << (i * 2));
		ospeedr |=  ((uint32_t)(speed & 0x3) << (i * 2));
	}
	GPIO_OSPEEDR(gpioport) = ospeedr;
}

void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios)
{
	uint16_t i;
	uint32_t afrl = GPIO_AFRL(gpioport);
	uint32_t afrh = GPIO_AFRH(gpioport);

	for (i = 0; i < 8; i++) {
		if ((1 << i) & gpios) {
			afrl &= ~(0xFU << (i * 4));
			afrl |=  ((uint32_t)(alt_func_num & 0xF) << (i * 4));
		}
	}
	for (i = 8; i < 16; i++) {
		if ((1 << i) & gpios) {
			afrh &= ~(0xFU << ((i - 8) * 4));
			afrh |=  ((uint32_t)(alt_func_num & 0xF) << ((i - 8) * 4));
		}
	}
	GPIO_AFRL(gpioport) = afrl;
	GPIO_AFRH(gpioport) = afrh;
}

void gpio_set(uint32_t gpioport, uint16_t gpios)
{
	GPIO_BSRR(gpioport) = gpios;
}

void gpio_clear(uint32_t gpioport, uint16_t gpios)
{
	GPIO_BSRR(gpioport) = ((uint32_t)gpios) << 16;
}

uint16_t gpio_get(uint32_t gpioport, uint16_t gpios)
{
	return (uint16_t)(gpio_port_read(gpioport) & gpios);
}

void gpio_toggle(uint32_t gpioport, uint16_t gpios)
{
	uint32_t odr = GPIO_ODR(gpioport);
	/* Atomic toggle via BSRR: set bits that are 0, clear bits that are 1. */
	GPIO_BSRR(gpioport) = ((odr & gpios) << 16) | (~odr & gpios);
}

uint16_t gpio_port_read(uint32_t gpioport)
{
	return (uint16_t)GPIO_IDR(gpioport);
}

void gpio_port_write(uint32_t gpioport, uint16_t data)
{
	GPIO_ODR(gpioport) = data;
}

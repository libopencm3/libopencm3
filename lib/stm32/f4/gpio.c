/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#include <libopencm3/stm32/f4/gpio.h>

void gpio_mode_setup(u32 gpioport, u8 mode, u8 pull_up_down, u16 gpios)
{
	u16 i;
	u32 moder, pupd;

	/*
	 * We want to set the config only for the pins mentioned in gpios,
	 * but keeping the others, so read out the actual config first.
	 */
	moder = GPIO_MODER(gpioport);
	pupd = GPIO_PUPDR(gpioport);

	for (i = 0; i < 16; i++) {
		if (!((1 << i) & gpios))
			continue;

		moder &= ~GPIO_MODE_MASK(i);
		moder |= GPIO_MODE(i, mode);
		pupd &= ~GPIO_PUPD_MASK(i);
		pupd |= GPIO_PUPD(i, pull_up_down);
	}

	/* Set mode and pull up/down control registers. */
	GPIO_MODER(gpioport) = moder;
	GPIO_PUPDR(gpioport) = pupd;
}

void gpio_set_output_options(u32 gpioport, u8 otype, u8 speed, u16 gpios)
{
	u16 i;
	u32 ospeedr;

	if (otype == 0x1)
		GPIO_OTYPER(gpioport) |= gpios;
	else
		GPIO_OTYPER(gpioport) &= ~gpios;

	ospeedr = GPIO_OSPEEDR(gpioport);

	for (i = 0; i < 16; i++) {
		if (!((1 << i) & gpios))
			continue;
		ospeedr &= ~GPIO_OSPEED_MASK(i);
		ospeedr |= GPIO_OSPEED(i, speed);
	}

	GPIO_OSPEEDR(gpioport) = ospeedr;
}

void gpio_set_af(u32 gpioport, u8 alt_func_num, u16 gpios)
{
	u16 i;
	u32 afrl, afrh;

	afrl = GPIO_AFRL(gpioport);
	afrh = GPIO_AFRH(gpioport);

	for (i = 0; i < 8; i++) {
		if (!((1 << i) & gpios))
			continue;
		afrl &= ~GPIO_AFR_MASK(i);
		afrl |= GPIO_AFR(i, alt_func_num);
	}

	for (i = 8; i < 16; i++) {
		if (!((1 << i) & gpios))
			continue;
		afrl &= ~GPIO_AFR_MASK(i - 8);
		afrh |= GPIO_AFR(i - 8, alt_func_num);
	}

	GPIO_AFRL(gpioport) = afrl;
	GPIO_AFRH(gpioport) = afrh;
}

void gpio_set(u32 gpioport, u16 gpios)
{
	GPIO_BSRR(gpioport) = gpios;
}

void gpio_clear(u32 gpioport, u16 gpios)
{
	GPIO_BSRR(gpioport) = gpios << 16;
}

u16 gpio_get(u32 gpioport, u16 gpios)
{
	return gpio_port_read(gpioport) & gpios;
}

void gpio_toggle(u32 gpioport, u16 gpios)
{
	GPIO_ODR(gpioport) = GPIO_IDR(gpioport) ^ gpios;
}

u16 gpio_port_read(u32 gpioport)
{
	return (u16)GPIO_IDR(gpioport);
}

void gpio_port_write(u32 gpioport, u16 data)
{
	GPIO_ODR(gpioport) = data;
}

void gpio_port_config_lock(u32 gpioport, u16 gpios)
{
	u32 reg32;

	/* Special "Lock Key Writing Sequence", see datasheet. */
	GPIO_LCKR(gpioport) = GPIO_LCKK | gpios;	/* Set LCKK. */
	GPIO_LCKR(gpioport) = ~GPIO_LCKK & gpios;	/* Clear LCKK. */
	GPIO_LCKR(gpioport) = GPIO_LCKK | gpios;	/* Set LCKK. */
	reg32 = GPIO_LCKR(gpioport);			/* Read LCKK. */
	reg32 = GPIO_LCKR(gpioport);			/* Read LCKK again. */

	/* Tell the compiler the variable is actually used. It will get optimized out anyways. */
	reg32 = reg32; 

	/* If (reg32 & GPIO_LCKK) is true, the lock is now active. */
}

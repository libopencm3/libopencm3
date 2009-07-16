/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef LIBOPENSTM32_GPIO_H
#define LIBOPENSTM32_GPIO_H

#include "libopenstm32.h"

/* GPIO port base addresses */
#define GPIO_BASE_A			(PERIPH_BASE_APB2 + 0x0800)
#define GPIO_BASE_B			(PERIPH_BASE_APB2 + 0x0c00)
#define GPIO_BASE_C			(PERIPH_BASE_APB2 + 0x1000)
#define GPIO_BASE_D			(PERIPH_BASE_APB2 + 0x1400)
#define GPIO_BASE_E			(PERIPH_BASE_APB2 + 0x1800)
#define GPIO_BASE_F			(PERIPH_BASE_APB2 + 0x1c00)
#define GPIO_BASE_G			(PERIPH_BASE_APB2 + 0x2000)

/* Register offsets */
#define GPIO_CTRL_LO			0x00	/* 32 bit */
#define GPIO_CTRL_HI			0x04	/* 32 bit */
#define GPIO_INPUT_DATA			0x08	/* 32 bit, only 15:0 used */
#define GPIO_OUTPUT_DATA		0x0c	/* 32 bit, only 15:0 used */
#define GPIO_BIT_SET_RESET		0x10	/* 32 bit */
#define GPIO_BIT_RESET			0x14	/* 16 bit */
#define GPIO_LOCK			0x18	/* 32 bit */

/* Output mode (MODE[1:0]) values */
#define GPIO_MODE_INPUT			0x00	/* Default */
#define GPIO_MODE_OUTPUT_10_MHZ		0x01
#define GPIO_MODE_OUTPUT_2_MHZ		0x02
#define GPIO_MODE_OUTPUT_50_MHZ		0x03

/* CNF[1:0] values when MODE[1:0] is 00 (input mode). */
#define GPIO_CNF_INPUT_ANALOG		0x00
#define GPIO_CNF_INPUT_FLOAT		0x01	/* Default */
#define GPIO_CNF_INPUT_PULL_UPDOWN	0x02

/* CNF[1:0] values when MODE[1:0] is != 00 (one of the output modes). */
#define GPIO_CNF_OUTPUT_PUSHPULL	0x00
#define GPIO_CNF_OUTPUT_OPENDRAIN	0x01
#define GPIO_CNF_OUTPUT_ALTFN_PUSHPULL	0x02
#define GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN	0x03

void gpio_set(unsigned int gpio);
void gpio_clear(unsigned int gpio);
void gpio_toggle(unsigned int gpio);

#endif

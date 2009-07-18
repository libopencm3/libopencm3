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

/* GPIO port base addresses (for convenience) */
#define GPIOA				GPIO_PORT_A_BASE
#define GPIOB				GPIO_PORT_B_BASE
#define GPIOC				GPIO_PORT_C_BASE
#define GPIOD				GPIO_PORT_D_BASE
#define GPIOE				GPIO_PORT_E_BASE
#define GPIOF				GPIO_PORT_F_BASE
#define GPIOG				GPIO_PORT_G_BASE

/* Port configuration register low (GPIOx_CRL) */
#define GPIO_CRL(port)			MMIO32(port + 0x00)
#define GPIOA_CRL			GPIO_CRL(GPIOA)
#define GPIOB_CRL			GPIO_CRL(GPIOB)
#define GPIOC_CRL			GPIO_CRL(GPIOC)
#define GPIOD_CRL			GPIO_CRL(GPIOD)
#define GPIOE_CRL			GPIO_CRL(GPIOE)
#define GPIOF_CRL			GPIO_CRL(GPIOF)
#define GPIOG_CRL			GPIO_CRL(GPIOG)

/* Port configuration register low (GPIOx_CRH) */
#define GPIO_CRH(port)			MMIO32(port + 0x04)
#define GPIOA_CRH			GPIO_CRH(GPIOA)
#define GPIOB_CRH			GPIO_CRH(GPIOB)
#define GPIOC_CRH			GPIO_CRH(GPIOC)
#define GPIOD_CRH			GPIO_CRH(GPIOD)
#define GPIOE_CRH			GPIO_CRH(GPIOE)
#define GPIOF_CRH			GPIO_CRH(GPIOF)
#define GPIOG_CRH			GPIO_CRH(GPIOG)

/* Port input data register (GPIOx_IDR) */
#define GPIO_IDR(port)			MMIO32(port + 0x08)
#define GPIOA_IDR			GPIO_IDR(GPIOA)
#define GPIOB_IDR			GPIO_IDR(GPIOB)
#define GPIOC_IDR			GPIO_IDR(GPIOC)
#define GPIOD_IDR			GPIO_IDR(GPIOD)
#define GPIOE_IDR			GPIO_IDR(GPIOE)
#define GPIOF_IDR			GPIO_IDR(GPIOF)
#define GPIOG_IDR			GPIO_IDR(GPIOG)

/* Port output data register (GPIOx_ODR) */
#define GPIO_ODR(port)			MMIO32(port + 0x0c)
#define GPIOA_ODR			GPIO_ODR(GPIOA)
#define GPIOB_ODR			GPIO_ODR(GPIOB)
#define GPIOC_ODR			GPIO_ODR(GPIOC)
#define GPIOD_ODR			GPIO_ODR(GPIOD)
#define GPIOE_ODR			GPIO_ODR(GPIOE)
#define GPIOF_ODR			GPIO_ODR(GPIOF)
#define GPIOG_ODR			GPIO_ODR(GPIOG)

/* Port bit set/reset register (GPIOx_BSRR) */
#define GPIO_BSRR(port)			MMIO32(port + 0x10)
#define GPIOA_BSRR			GPIO_BSRR(GPIOA)
#define GPIOB_BSRR			GPIO_BSRR(GPIOB)
#define GPIOC_BSRR			GPIO_BSRR(GPIOC)
#define GPIOD_BSRR			GPIO_BSRR(GPIOD)
#define GPIOE_BSRR			GPIO_BSRR(GPIOE)
#define GPIOF_BSRR			GPIO_BSRR(GPIOF)
#define GPIOG_BSRR			GPIO_BSRR(GPIOG)

/* Port bit reset register (GPIOx_BRR) */
#define GPIO_BRR(port)			MMIO16(port + 0x14)
#define GPIOA_BRR			GPIO_BRR(GPIOA)
#define GPIOB_BRR			GPIO_BRR(GPIOB)
#define GPIOC_BRR			GPIO_BRR(GPIOC)
#define GPIOD_BRR			GPIO_BRR(GPIOD)
#define GPIOE_BRR			GPIO_BRR(GPIOE)
#define GPIOF_BRR			GPIO_BRR(GPIOF)
#define GPIOG_BRR			GPIO_BRR(GPIOG)

/* Port configuration lock register (GPIOx_LCKR) */
#define GPIO_LCKR(port)			MMIO32(port + 0x18)
#define GPIOA_LCKR			GPIO_LCKR(GPIOA)
#define GPIOB_LCKR			GPIO_LCKR(GPIOB)
#define GPIOC_LCKR			GPIO_LCKR(GPIOC)
#define GPIOD_LCKR			GPIO_LCKR(GPIOD)
#define GPIOE_LCKR			GPIO_LCKR(GPIOE)
#define GPIOF_LCKR			GPIO_LCKR(GPIOF)
#define GPIOG_LCKR			GPIO_LCKR(GPIOG)

/* Output mode (MODE[1:0]) values */
#define GPIO_MODE_INPUT			0x00	/* Default */
#define GPIO_MODE_OUTPUT_10_MHZ		0x01
#define GPIO_MODE_OUTPUT_2_MHZ		0x02
#define GPIO_MODE_OUTPUT_50_MHZ		0x03

/* CNF[1:0] values when MODE[1:0] is 00 (input mode) */
#define GPIO_CNF_INPUT_ANALOG		0x00
#define GPIO_CNF_INPUT_FLOAT		0x01	/* Default */
#define GPIO_CNF_INPUT_PULL_UPDOWN	0x02

/* CNF[1:0] values when MODE[1:0] is != 00 (one of the output modes) */
#define GPIO_CNF_OUTPUT_PUSHPULL	0x00
#define GPIO_CNF_OUTPUT_OPENDRAIN	0x01
#define GPIO_CNF_OUTPUT_ALTFN_PUSHPULL	0x02
#define GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN	0x03

/* GPIO number definitions (just for convenience) */
#define GPIO0				(1 << 0)
#define GPIO1				(1 << 1)
#define GPIO2				(1 << 2)
#define GPIO3				(1 << 3)
#define GPIO4				(1 << 4)
#define GPIO5				(1 << 5)
#define GPIO6				(1 << 6)
#define GPIO7				(1 << 7)
#define GPIO8				(1 << 8)
#define GPIO9				(1 << 9)
#define GPIO10				(1 << 10)
#define GPIO11				(1 << 11)
#define GPIO12				(1 << 12)
#define GPIO13				(1 << 13)
#define GPIO14				(1 << 14)
#define GPIO15				(1 << 15)

void gpio_set(unsigned int gpio);
void gpio_clear(unsigned int gpio);
void gpio_toggle(unsigned int gpio);

#endif

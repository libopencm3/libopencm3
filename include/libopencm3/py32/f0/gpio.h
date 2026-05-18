/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2026 libopencm3 project
 *
 * PY32F0xx GPIO definitions.
 *
 * Register layout (MODER, OTYPER, OSPEEDR, PUPDR, IDR, ODR, BSRR, LCKR,
 * AFRL/AFRH, BRR) is identical to STM32F0; alternate-function mapping is
 * device-specific (see PY32F0xx reference manual).
 *
 * Licensed under the GNU LGPL v3 or later.
 */

#ifndef LIBOPENCM3_PY32F0_GPIO_H
#define LIBOPENCM3_PY32F0_GPIO_H

#include <libopencm3/py32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- GPIO port base addresses ------------------------------------------- */
#define GPIOA				GPIOA_BASE
#define GPIOB				GPIOB_BASE
#define GPIOF				GPIOF_BASE

/* --- GPIO registers ----------------------------------------------------- */
#define GPIO_MODER(port)		MMIO32((port) + 0x00)
#define GPIO_OTYPER(port)		MMIO32((port) + 0x04)
#define GPIO_OSPEEDR(port)		MMIO32((port) + 0x08)
#define GPIO_PUPDR(port)		MMIO32((port) + 0x0C)
#define GPIO_IDR(port)			MMIO32((port) + 0x10)
#define GPIO_ODR(port)			MMIO32((port) + 0x14)
#define GPIO_BSRR(port)			MMIO32((port) + 0x18)
#define GPIO_LCKR(port)			MMIO32((port) + 0x1C)
#define GPIO_AFRL(port)			MMIO32((port) + 0x20)
#define GPIO_AFRH(port)			MMIO32((port) + 0x24)
#define GPIO_BRR(port)			MMIO32((port) + 0x28)

/* --- GPIO pin identifiers (mask, 1-bit per pin) ------------------------- */
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
#define GPIO_ALL			0xFFFF

/* --- GPIO mode (MODER, 2 bits per pin) ---------------------------------- */
#define GPIO_MODE_INPUT			0x0
#define GPIO_MODE_OUTPUT		0x1
#define GPIO_MODE_AF			0x2
#define GPIO_MODE_ANALOG		0x3

/* --- GPIO output type (OTYPER, 1 bit per pin) --------------------------- */
#define GPIO_OTYPE_PP			0x0
#define GPIO_OTYPE_OD			0x1

/* --- GPIO output speed (OSPEEDR, 2 bits per pin) ------------------------ */
#define GPIO_OSPEED_LOW			0x0
#define GPIO_OSPEED_MED			0x1
#define GPIO_OSPEED_HIGH		0x3

/* --- GPIO pull-up/pull-down (PUPDR, 2 bits per pin) --------------------- */
#define GPIO_PUPD_NONE			0x0
#define GPIO_PUPD_PULLUP		0x1
#define GPIO_PUPD_PULLDOWN		0x2

/* --- GPIO alternate function numbers ------------------------------------ */
#define GPIO_AF0			0x0
#define GPIO_AF1			0x1
#define GPIO_AF2			0x2
#define GPIO_AF3			0x3
#define GPIO_AF4			0x4
#define GPIO_AF5			0x5
#define GPIO_AF6			0x6
#define GPIO_AF7			0x7
#define GPIO_AF8			0x8
#define GPIO_AF9			0x9
#define GPIO_AF10			0xA
#define GPIO_AF11			0xB
#define GPIO_AF12			0xC
#define GPIO_AF13			0xD
#define GPIO_AF14			0xE
#define GPIO_AF15			0xF

/* --- Function prototypes ------------------------------------------------ */
BEGIN_DECLS

void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
		     uint16_t gpios);
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
			     uint16_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios);

void gpio_set(uint32_t gpioport, uint16_t gpios);
void gpio_clear(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_get(uint32_t gpioport, uint16_t gpios);
void gpio_toggle(uint32_t gpioport, uint16_t gpios);
uint16_t gpio_port_read(uint32_t gpioport);
void gpio_port_write(uint32_t gpioport, uint16_t data);

END_DECLS

#endif

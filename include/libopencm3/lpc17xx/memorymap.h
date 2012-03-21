/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#ifndef LPC17XX_MEMORYMAP_H
#define LPC17XX_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- LPC17XX specific peripheral definitions ----------------------------- */

/* Memory map for all busses */
#define PERIPH_BASE_APB0		0x40000000
#define PERIPH_BASE_APB1		0x40080000
#define PERIPH_BASE_AHB			0x20000000

/* Register boundary addresses */

/* APB0 */
#define WDT_BASE			(PERIPH_BASE_APB0 + 0x00000)
#define TIMER0_BASE			(PERIPH_BASE_APB0 + 0x04000) 
#define TIMER1_BASE			(PERIPH_BASE_APB0 + 0x08000)
#define UART0_BASE      		(PERIPH_BASE_APB0 + 0x0c000)
#define UART1_BASE      		(PERIPH_BASE_APB0 + 0x10000)
/* PERIPH_BASE_APB0 + 0X14000 (0x4001 4000 - 0x4001 7FFF): Reserved */
#define PWM1_BASE       		(PERIPH_BASE_APB0 + 0x18000)
#define I2C0_BASE			(PERIPH_BASE_APB0 + 0x1c000)
#define SPI_BASE			(PERIPH_BASE_APB0 + 0x20000)
#define RTC_BASE			(PERIPH_BASE_APB0 + 0x24000)
#define GPIOINTERRPUT_BASE		(PERIPH_BASE_APB0 + 0x28000)
#define PINCONNECT_BASE			(PERIPH_BASE_APB0 + 0x2c000)
#define SSP1_BASE			(PERIPH_BASE_APB0 + 0x30000)
#define ADC_BASE			(PERIPH_BASE_APB0 + 0x34000)
#define CANAFRAM_BASE              	(PERIPH_BASE_APB0 + 0x38000)
#define CANAFREG_BASE              	(PERIPH_BASE_APB0 + 0x3C000)
#define CANCOMMONREG_BASE              	(PERIPH_BASE_APB0 + 0x40000)
#define CAN1_BASE                     	(PERIPH_BASE_APB0 + 0x44000)
#define CAN2_BASE                     	(PERIPH_BASE_APB0 + 0x48000)
/* PERIPH_BASE_APB0 + 0X4C000 (0x4004 C000 - 0x4005 BFFF): Reserved */
#define I2C1_BASE                     	(PERIPH_BASE_APB0 + 0x5C000)
/* PERIPH_BASE_APB0 + 0X60000 (0x6000 0000 - 0x4007 BFFF): Reserved */

/* AHB */
#define GPIO_PIO0_BASE			(PERIPH_BASE_AHB + 0x9c000)
#define GPIO_PIO1_BASE			(PERIPH_BASE_AHB + 0x9c020)
#define GPIO_PIO2_BASE			(PERIPH_BASE_AHB + 0x9c040)
#define GPIO_PIO3_BASE			(PERIPH_BASE_AHB + 0x9c060)
#define GPIO_PIO4_BASE			(PERIPH_BASE_AHB + 0x9c080)

#endif

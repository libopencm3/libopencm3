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

#ifndef LPC13XX_MEMORYMAP_H
#define LPC13XX_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- LPC13XX specific peripheral definitions ----------------------------- */

/* Memory map for all busses */
#define PERIPH_BASE_APB			(0x40000000U)
#define PERIPH_BASE_AHB			(0x50000000U)

/* Register boundary addresses */

/* APB */
#define I2C_BASE			(PERIPH_BASE_APB + 0x00000)
#define WDT_BASE			(PERIPH_BASE_APB + 0x04000)
#define UART_BASE			(PERIPH_BASE_APB + 0x08000)
#define TIMER0_16BIT_BASE		(PERIPH_BASE_APB + 0x0c000)
#define TIMER1_16BIT_BASE		(PERIPH_BASE_APB + 0x10000)
#define TIMER0_32BIT_BASE		(PERIPH_BASE_APB + 0x14000)
#define TIMER1_32BIT_BASE		(PERIPH_BASE_APB + 0x18000)
#define ADC_BASE			(PERIPH_BASE_APB + 0x1c000)
#define USB_BASE			(PERIPH_BASE_APB + 0x20000)
/* PERIPH_BASE_APB + 0x28000 (0x4002 8000 - 0x4003 7FFF): Reserved */
#define PMU_BASE			(PERIPH_BASE_APB + 0x38000)
#define FLASH_BASE			(PERIPH_BASE_APB + 0x3c000)
#define SSP_BASE			(PERIPH_BASE_APB + 0x40000)
#define IOCONFIG_BASE			(PERIPH_BASE_APB + 0x44000)
#define SYSCTRL_BASE			(PERIPH_BASE_APB + 0x48000)
/* PERIPH_BASE_APB + 0x4c000 (0x4004 c000 - 0x4007 FFFF): Reserved */

/* AHB */
#define GPIO_PIO0_BASE			(PERIPH_BASE_AHB + 0x00000)
#define GPIO_PIO1_BASE			(PERIPH_BASE_AHB + 0x10000)
#define GPIO_PIO2_BASE			(PERIPH_BASE_AHB + 0x20000)
#define GPIO_PIO3_BASE			(PERIPH_BASE_AHB + 0x30000)
/* PERIPH_BASE_AHB + 0x40000 (0x5004 0000 - 0x501F FFFF): Reserved */

#endif

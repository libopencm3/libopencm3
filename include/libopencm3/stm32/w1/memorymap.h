/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

#ifndef LIBOPENCM3_MEMORYMAP_H
#define LIBOPENCM3_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

/* --- STM32 specific peripheral definitions ------------------------------- */

/* Memory map for all buses */
#define FLASH_BASE			((uint32_t)0x08000000)
#define PERIPH_BASE			((uint32_t)0x40000000)
#define INFO_BASE			((uint32_t)0x08040000)
#define PERIPH_BASE_APB			(PERIPH_BASE + 0x00000)

/* Register boundary addresses */

/* APB */
#define PWR_BASE			(PERIPH_BASE_APB + 0x000000)
#define MACTMR_BASE			(PERIPH_BASE_APB + 0x002000)
#define CLK_BASE			(PERIPH_BASE_APB + 0x004000)
#define MEM_BASE			(PERIPH_BASE_APB + 0x005000)
#define WDG_BASE			(PERIPH_BASE_APB + 0x006000)
#define SLPTMR_BASE			(PERIPH_BASE_APB + 0x00600C)
#define MGMT_BASE			(PERIPH_BASE_APB + 0x00A000)
#define GPIO_BASE			(PERIPH_BASE_APB + 0x00B000)
#define SC2_BASE			(PERIPH_BASE_APB + 0x00C000)
#define SC1_BASE			(PERIPH_BASE_APB + 0x00C800)
#define ADC_BASE			(PERIPH_BASE_APB + 0x00D000)
#define TIM1_BASE			(PERIPH_BASE_APB + 0x00E000)
#define TIM2_BASE			(PERIPH_BASE_APB + 0x00F000)

#endif

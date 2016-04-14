/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Karl Palsson <karlp@tweak.net.au>
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

#ifndef SAMD_MEMORYMAP_H
#define SAMD_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- SAMD AHB-APB bridge A -------------------------------------------- */
#define PM_BASE				(0x40000400U)
#define SYSCTRL_BASE			(0x40000800U)
#define GCLK_BASE			(0x40000c00U)
#define WDT_BASE			(0x40001000U)
#define RTC_BASE			(0x40001400U)
#define EIC_BASE			(0x40001800U)
/* --- SAMD AHB-APB bridge B -------------------------------------------- */
#define DSU_BASE			(0x41002000U)
#define NVMCTRL_BASE			(0x41004000U)
#define PORT_BASE			(0x41004400U)
#define DMAC_BASE			(0x41004800U)
#define MTB_BASE			(0x41006000U)
/* --- SAMD AHB-APB bridge C -------------------------------------------- */
#define EVSYS_BASE			(0x42000400U)
#define SERCOM0_BASE			(0x42000800U)
#define SERCOM1_BASE			(0x42000c00U)
#define SERCOM2_BASE			(0x42001000U)
#define TCC0_BASE			(0x42001400U)
#define TC1_BASE			(0x42001800U)
#define TC2_BASE			(0x42001c00U)
#define ADC_BASE			(0x42002000U)
#define AC_BASE				(0x42002400U)
#define DAC_BASE			(0x42002800U)
#define PTC_BASE			(0x42002c00U)

#endif

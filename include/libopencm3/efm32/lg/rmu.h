/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#ifndef LIBOPENCM3_EFM32_RMU_H
#define LIBOPENCM3_EFM32_RMU_H

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/cm3/common.h>

#define RMU_CTRL		MMIO32(RMU_BASE + 0x00)
#define RMU_RSTCAUSE	MMIO32(RMU_BASE + 0x04)
#define RMU_CMD			MMIO32(RMU_BASE + 0x08)

/* RMU_CTRL */
#define RMU_CTRL_BURSTEN	(1 << 1)
#define RMU_CTRL_LOCKUPRDIS	(1 << 0)

/* RMU_RSTCAUSE */
#define RMU_RSTCAUSE_BUMODERST		(1 << 15)
#define RMU_RSTCAUSE_BUBODREG		(1 << 14)
#define RMU_RSTCAUSE_BUBODUNREG		(1 << 13)
#define RMU_RSTCAUSE_BUBODBUVIN		(1 << 12)
#define RMU_RSTCAUSE_BUBODVDDDREG	(1 << 11)
#define RMU_RSTCAUSE_BODAVDD1		(1 << 10)
#define RMU_RSTCAUSE_BODAVDD0		(1 << 9)
#define RMU_RSTCAUSE_EM4WURST		(1 << 8)
#define RMU_RSTCAUSE_EM4RST			(1 << 7)
#define RMU_RSTCAUSE_SYSREQRST		(1 << 6)
#define RMU_RSTCAUSE_LOCKUPRST		(1 << 5)
#define RMU_RSTCAUSE_WDOGRST		(1 << 4)
#define RMU_RSTCAUSE_EXTRST			(1 << 3)
#define RMU_RSTCAUSE_BODREGRST		(1 << 2)
#define RMU_RSTCAUSE_BODUNREGRST	(1 << 1)
#define RMU_RSTCAUSE_PORST			(1 << 0)

/* RMU_CMD */
#define RMU_CMD_RCCLR	(1 << 0)

#endif


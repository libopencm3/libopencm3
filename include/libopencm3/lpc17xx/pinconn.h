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

#ifndef LPC17XX_PINCONN_H
#define LPC17XX_PINCONN_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc17xx/memorymap.h>

#define PINSEL0     MMIO32(PINCONNECT_BASE + 0x00)
#define PINSEL1     MMIO32(PINCONNECT_BASE + 0x04)
#define PINSEL2     MMIO32(PINCONNECT_BASE + 0x08)
#define PINSEL3     MMIO32(PINCONNECT_BASE + 0x0C)
#define PINSEL4     MMIO32(PINCONNECT_BASE + 0x10)
#define PINSEL5     MMIO32(PINCONNECT_BASE + 0x14)
#define PINSEL6     MMIO32(PINCONNECT_BASE + 0x18)
#define PINSEL7     MMIO32(PINCONNECT_BASE + 0x1C)
#define PINSEL8     MMIO32(PINCONNECT_BASE + 0x20)
#define PINSEL9     MMIO32(PINCONNECT_BASE + 0x24)
#define PINSEL10   MMIO32(PINCONNECT_BASE + 0x28)

#define PINSEL_MASK 0x03

#define PINMODE0 MMIO32(PINCONNECT_BASE + 0x40)
#define PINMODE1 MMIO32(PINCONNECT_BASE + 0x44)
#define PINMODE2 MMIO32(PINCONNECT_BASE + 0x48)
#define PINMODE3 MMIO32(PINCONNECT_BASE + 0x4C)
#define PINMODE4 MMIO32(PINCONNECT_BASE + 0x50)
#define PINMODE5 MMIO32(PINCONNECT_BASE + 0x54)
#define PINMODE6 MMIO32(PINCONNECT_BASE + 0x58)
#define PINMODE7 MMIO32(PINCONNECT_BASE + 0x5C)
#define PINMODE8 MMIO32(PINCONNECT_BASE + 0x60)
#define PINMODE9 MMIO32(PINCONNECT_BASE + 0x64)

#define PINMODE_MASK 0x03

#define PINMODE_OD0 MMIO32(PINCONNECT_BASE + 0x68)
#define PINMODE_OD1 MMIO32(PINCONNECT_BASE + 0x6C)
#define PINMODE_OD2 MMIO32(PINCONNECT_BASE + 0x70)
#define PINMODE_OD3 MMIO32(PINCONNECT_BASE + 0x74)
#define PINMODE_OD4 MMIO32(PINCONNECT_BASE + 0x78)

#define I2CPADCFG MMIO32(PINCONNECT_BASE + 0x7C)

#endif


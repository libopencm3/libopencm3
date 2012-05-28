/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_CREG_H
#define LPC43XX_CREG_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- CREG registers ----------------------------------------------------- */

/*
 * Chip configuration register 32 kHz oscillator output and BOD control
 * register
 */
#define CREG0                           (CREG_BASE + 0x004)

/* ARM Cortex-M4 memory mapping */
#define M4MEMMAP                        (CREG_BASE + 0x100)

/* Chip configuration register 1 */
#define CREG1                           (CREG_BASE + 0x108)

/* Chip configuration register 2 */
#define CREG2                           (CREG_BASE + 0x10C)

/* Chip configuration register 3 */
#define CREG3                           (CREG_BASE + 0x110)

/* Chip configuration register 4 */
#define CREG4                           (CREG_BASE + 0x114)

/* Chip configuration register 5 */
#define CREG5                           (CREG_BASE + 0x118)

/* DMA muxing control */
#define DMAMUX                          (CREG_BASE + 0x11C)

/* ETB RAM configuration */
#define ETBCFG                          (CREG_BASE + 0x128)

/*
 * Chip configuration register 6. Controls multiple functions: Ethernet
 * interface, SCT output, I2S0/1 inputs, EMC clock.
 */
#define CREG6                           (CREG_BASE + 0x12C)

/* Cortex-M4 TXEV event clear */
#define M4TXEVENT                       (CREG_BASE + 0x130)

/* Part ID */
#define CHIPID                          (CREG_BASE + 0x200)

/* Cortex-M0 TXEV event clear */
#define M0TXEVENT                       (CREG_BASE + 0x400)

/* ARM Cortex-M0 memory mapping */
#define M0APPMEMMAP                     (CREG_BASE + 0x404)

#endif

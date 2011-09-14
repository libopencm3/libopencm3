/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_IWDG_H
#define LIBOPENCM3_IWDG_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- IWDG registers ------------------------------------------------------ */

/* Key Register (IWDG_KR) */
#define IWDG_KR				MMIO32(IWDG_BASE + 0x00)

/* Prescaler register (IWDG_PR) */
#define IWDG_PR				MMIO32(IWDG_BASE + 0x04)

/* Reload register (IWDG_RLR) */
#define IWDG_RLR			MMIO32(IWDG_BASE + 0x08)

/* Status register (IWDG_SR) */
#define IWDG_SR				MMIO32(IWDG_BASE + 0x0C)

/* --- IWDG_KR values ------------------------------------------------------ */

/* KEY[15:0]: Key value */
#define IWDG_KR_RESET			0xAAAA
#define IWDG_KR_UNLOCK			0x5555
#define IWDG_KR_START			0xCCCC

/* --- IWDG_PR values ------------------------------------------------------ */

/* PR[2:0]: Prescaler divider */
#define IWDG_PR_LSB			0
#define IWDG_PR_DIV4			0x0
#define IWDG_PR_DIV8			0x1
#define IWDG_PR_DIV16			0x2
#define IWDG_PR_DIV32			0x3
#define IWDG_PR_DIV64			0x4
#define IWDG_PR_DIV128			0x5
#define IWDG_PR_DIV256			0x6
/* Double definition: 0x06 and 0x07 both mean DIV256 as per datasheet. */
/* #define IWDG_PR_DIV256			0x7 */

/* --- IWDG_RLR values ----------------------------------------------------- */

/* RL[11:0]: Watchdog counter reload value */

/* --- IWDG_SR values ------------------------------------------------------ */

/* RVU: Watchdog counter reload value update */
#define IWDG_SR_RVU			(1 << 1)

/* PVU: Watchdog prescaler value update */
#define IWDG_SR_PVU			(1 << 0)

/* --- IWDG funtion prototypes---------------------------------------------- */

#endif

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

#ifndef LPC43XX_TIMER_H
#define LPC43XX_TIMER_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* Timer base addresses */
#define TIMER0                          TIMER0_BASE
#define TIMER1                          TIMER1_BASE
#define TIMER2                          TIMER2_BASE
#define TIMER3                          TIMER3_BASE


/* --- Timer registers ----------------------------------------------------- */

/* Interrupt Register */
#define TIMER_IR(timer)                 MMIO32(timer + 0x000)
#define TIMER0_IR                       TIMER_IR(TIMER0)
#define TIMER1_IR                       TIMER_IR(TIMER1)
#define TIMER2_IR                       TIMER_IR(TIMER2)
#define TIMER3_IR                       TIMER_IR(TIMER3)

/* Timer Control Register */
#define TIMER_TCR(timer)                MMIO32(timer + 0x004)
#define TIMER0_TCR                      TIMER_TCR(TIMER0)
#define TIMER1_TCR                      TIMER_TCR(TIMER1)
#define TIMER2_TCR                      TIMER_TCR(TIMER2)
#define TIMER3_TCR                      TIMER_TCR(TIMER3)

/* Timer Counter */
#define TIMER_TC(timer)                 MMIO32(timer + 0x008)
#define TIMER0_TC                       TIMER_TC(TIMER0)
#define TIMER1_TC                       TIMER_TC(TIMER1)
#define TIMER2_TC                       TIMER_TC(TIMER2)
#define TIMER3_TC                       TIMER_TC(TIMER3)

/* Prescale Register */
#define TIMER_PR(timer)                 MMIO32(timer + 0x00C)
#define TIMER0_PR                       TIMER_PR(TIMER0)
#define TIMER1_PR                       TIMER_PR(TIMER1)
#define TIMER2_PR                       TIMER_PR(TIMER2)
#define TIMER3_PR                       TIMER_PR(TIMER3)

/* Prescale Counter */
#define TIMER_PC(timer)                 MMIO32(timer + 0x010)
#define TIMER0_PC                       TIMER_PC(TIMER0)
#define TIMER1_PC                       TIMER_PC(TIMER1)
#define TIMER2_PC                       TIMER_PC(TIMER2)
#define TIMER3_PC                       TIMER_PC(TIMER3)

/* Match Control Register */
#define TIMER_MCR(timer)                MMIO32(timer + 0x014)
#define TIMER0_MCR                      TIMER_MCR(TIMER0)
#define TIMER1_MCR                      TIMER_MCR(TIMER1)
#define TIMER2_MCR                      TIMER_MCR(TIMER2)
#define TIMER3_MCR                      TIMER_MCR(TIMER3)

/* Match Register 0 */
#define TIMER_MR0(timer)                MMIO32(timer + 0x018)
#define TIMER0_MR0                      TIMER_MR0(TIMER0)
#define TIMER1_MR0                      TIMER_MR0(TIMER1)
#define TIMER2_MR0                      TIMER_MR0(TIMER2)
#define TIMER3_MR0                      TIMER_MR0(TIMER3)

/* Match Register 1 */
#define TIMER_MR1(timer)                MMIO32(timer + 0x01C)
#define TIMER0_MR1                      TIMER_MR1(TIMER0)
#define TIMER1_MR1                      TIMER_MR1(TIMER1)
#define TIMER2_MR1                      TIMER_MR1(TIMER2)
#define TIMER3_MR1                      TIMER_MR1(TIMER3)

/* Match Register 2 */
#define TIMER_MR2(timer)                MMIO32(timer + 0x020)
#define TIMER0_MR2                      TIMER_MR2(TIMER0)
#define TIMER1_MR2                      TIMER_MR2(TIMER1)
#define TIMER2_MR2                      TIMER_MR2(TIMER2)
#define TIMER3_MR2                      TIMER_MR2(TIMER3)

/* Match Register 3 */
#define TIMER_MR3(timer)                MMIO32(timer + 0x024)
#define TIMER0_MR3                      TIMER_MR3(TIMER0)
#define TIMER1_MR3                      TIMER_MR3(TIMER1)
#define TIMER2_MR3                      TIMER_MR3(TIMER2)
#define TIMER3_MR3                      TIMER_MR3(TIMER3)

/* Capture Control Register */
#define TIMER_CCR(timer)                MMIO32(timer + 0x028)
#define TIMER0_CCR                      TIMER_CCR(TIMER0)
#define TIMER1_CCR                      TIMER_CCR(TIMER1)
#define TIMER2_CCR                      TIMER_CCR(TIMER2)
#define TIMER3_CCR                      TIMER_CCR(TIMER3)

/* Capture Register 0 */
#define TIMER_CR0(timer)                MMIO32(timer + 0x02C)
#define TIMER0_CR0                      TIMER_CR0(TIMER0)
#define TIMER1_CR0                      TIMER_CR0(TIMER1)
#define TIMER2_CR0                      TIMER_CR0(TIMER2)
#define TIMER3_CR0                      TIMER_CR0(TIMER3)

/* Capture Register 1 */
#define TIMER_CR1(timer)                MMIO32(timer + 0x030)
#define TIMER0_CR1                      TIMER_CR1(TIMER0)
#define TIMER1_CR1                      TIMER_CR1(TIMER1)
#define TIMER2_CR1                      TIMER_CR1(TIMER2)
#define TIMER3_CR1                      TIMER_CR1(TIMER3)

/* Capture Register 2 */
#define TIMER_CR2(timer)                MMIO32(timer + 0x034)
#define TIMER0_CR2                      TIMER_CR2(TIMER0)
#define TIMER1_CR2                      TIMER_CR2(TIMER1)
#define TIMER2_CR2                      TIMER_CR2(TIMER2)
#define TIMER3_CR2                      TIMER_CR2(TIMER3)

/* Capture Register 3 */
#define TIMER_CR3(timer)                MMIO32(timer + 0x038)
#define TIMER0_CR3                      TIMER_CR3(TIMER0)
#define TIMER1_CR3                      TIMER_CR3(TIMER1)
#define TIMER2_CR3                      TIMER_CR3(TIMER2)
#define TIMER3_CR3                      TIMER_CR3(TIMER3)

/* External Match Register */
#define TIMER_EMR(timer)                MMIO32(timer + 0x03C)
#define TIMER0_EMR                      TIMER_EMR(TIMER0)
#define TIMER1_EMR                      TIMER_EMR(TIMER1)
#define TIMER2_EMR                      TIMER_EMR(TIMER2)
#define TIMER3_EMR                      TIMER_EMR(TIMER3)

/* Count Control Register */
#define TIMER_CTCR(timer)               MMIO32(timer + 0x070)
#define TIMER0_CTCR                     TIMER_CTCR(TIMER0)
#define TIMER1_CTCR                     TIMER_CTCR(TIMER1)
#define TIMER2_CTCR                     TIMER_CTCR(TIMER2)
#define TIMER3_CTCR                     TIMER_CTCR(TIMER3)

#endif

/** @defgroup timer_defines Timer

@brief <b>Defined Constants and Types for the LPC43xx timer</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
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

/**@{*/

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
#define TIMER_IR(timer)                 MMIO32((timer) + 0x000)
#define TIMER0_IR                       TIMER_IR(TIMER0)
#define TIMER1_IR                       TIMER_IR(TIMER1)
#define TIMER2_IR                       TIMER_IR(TIMER2)
#define TIMER3_IR                       TIMER_IR(TIMER3)

/* Timer Control Register */
#define TIMER_TCR(timer)                MMIO32((timer) + 0x004)
#define TIMER0_TCR                      TIMER_TCR(TIMER0)
#define TIMER1_TCR                      TIMER_TCR(TIMER1)
#define TIMER2_TCR                      TIMER_TCR(TIMER2)
#define TIMER3_TCR                      TIMER_TCR(TIMER3)

/* Timer Counter */
#define TIMER_TC(timer)                 MMIO32((timer) + 0x008)
#define TIMER0_TC                       TIMER_TC(TIMER0)
#define TIMER1_TC                       TIMER_TC(TIMER1)
#define TIMER2_TC                       TIMER_TC(TIMER2)
#define TIMER3_TC                       TIMER_TC(TIMER3)

/* Prescale Register */
#define TIMER_PR(timer)                 MMIO32((timer) + 0x00C)
#define TIMER0_PR                       TIMER_PR(TIMER0)
#define TIMER1_PR                       TIMER_PR(TIMER1)
#define TIMER2_PR                       TIMER_PR(TIMER2)
#define TIMER3_PR                       TIMER_PR(TIMER3)

/* Prescale Counter */
#define TIMER_PC(timer)                 MMIO32((timer) + 0x010)
#define TIMER0_PC                       TIMER_PC(TIMER0)
#define TIMER1_PC                       TIMER_PC(TIMER1)
#define TIMER2_PC                       TIMER_PC(TIMER2)
#define TIMER3_PC                       TIMER_PC(TIMER3)

/* Match Control Register */
#define TIMER_MCR(timer)                MMIO32((timer) + 0x014)
#define TIMER0_MCR                      TIMER_MCR(TIMER0)
#define TIMER1_MCR                      TIMER_MCR(TIMER1)
#define TIMER2_MCR                      TIMER_MCR(TIMER2)
#define TIMER3_MCR                      TIMER_MCR(TIMER3)

/* Match Register 0 */
#define TIMER_MR0(timer)                MMIO32((timer) + 0x018)
#define TIMER0_MR0                      TIMER_MR0(TIMER0)
#define TIMER1_MR0                      TIMER_MR0(TIMER1)
#define TIMER2_MR0                      TIMER_MR0(TIMER2)
#define TIMER3_MR0                      TIMER_MR0(TIMER3)

/* Match Register 1 */
#define TIMER_MR1(timer)                MMIO32((timer) + 0x01C)
#define TIMER0_MR1                      TIMER_MR1(TIMER0)
#define TIMER1_MR1                      TIMER_MR1(TIMER1)
#define TIMER2_MR1                      TIMER_MR1(TIMER2)
#define TIMER3_MR1                      TIMER_MR1(TIMER3)

/* Match Register 2 */
#define TIMER_MR2(timer)                MMIO32((timer) + 0x020)
#define TIMER0_MR2                      TIMER_MR2(TIMER0)
#define TIMER1_MR2                      TIMER_MR2(TIMER1)
#define TIMER2_MR2                      TIMER_MR2(TIMER2)
#define TIMER3_MR2                      TIMER_MR2(TIMER3)

/* Match Register 3 */
#define TIMER_MR3(timer)                MMIO32((timer) + 0x024)
#define TIMER0_MR3                      TIMER_MR3(TIMER0)
#define TIMER1_MR3                      TIMER_MR3(TIMER1)
#define TIMER2_MR3                      TIMER_MR3(TIMER2)
#define TIMER3_MR3                      TIMER_MR3(TIMER3)

/* Capture Control Register */
#define TIMER_CCR(timer)                MMIO32((timer) + 0x028)
#define TIMER0_CCR                      TIMER_CCR(TIMER0)
#define TIMER1_CCR                      TIMER_CCR(TIMER1)
#define TIMER2_CCR                      TIMER_CCR(TIMER2)
#define TIMER3_CCR                      TIMER_CCR(TIMER3)

/* Capture Register 0 */
#define TIMER_CR0(timer)                MMIO32((timer) + 0x02C)
#define TIMER0_CR0                      TIMER_CR0(TIMER0)
#define TIMER1_CR0                      TIMER_CR0(TIMER1)
#define TIMER2_CR0                      TIMER_CR0(TIMER2)
#define TIMER3_CR0                      TIMER_CR0(TIMER3)

/* Capture Register 1 */
#define TIMER_CR1(timer)                MMIO32((timer) + 0x030)
#define TIMER0_CR1                      TIMER_CR1(TIMER0)
#define TIMER1_CR1                      TIMER_CR1(TIMER1)
#define TIMER2_CR1                      TIMER_CR1(TIMER2)
#define TIMER3_CR1                      TIMER_CR1(TIMER3)

/* Capture Register 2 */
#define TIMER_CR2(timer)                MMIO32((timer) + 0x034)
#define TIMER0_CR2                      TIMER_CR2(TIMER0)
#define TIMER1_CR2                      TIMER_CR2(TIMER1)
#define TIMER2_CR2                      TIMER_CR2(TIMER2)
#define TIMER3_CR2                      TIMER_CR2(TIMER3)

/* Capture Register 3 */
#define TIMER_CR3(timer)                MMIO32((timer) + 0x038)
#define TIMER0_CR3                      TIMER_CR3(TIMER0)
#define TIMER1_CR3                      TIMER_CR3(TIMER1)
#define TIMER2_CR3                      TIMER_CR3(TIMER2)
#define TIMER3_CR3                      TIMER_CR3(TIMER3)

/* External Match Register */
#define TIMER_EMR(timer)                MMIO32((timer) + 0x03C)
#define TIMER0_EMR                      TIMER_EMR(TIMER0)
#define TIMER1_EMR                      TIMER_EMR(TIMER1)
#define TIMER2_EMR                      TIMER_EMR(TIMER2)
#define TIMER3_EMR                      TIMER_EMR(TIMER3)

/* Count Control Register */
#define TIMER_CTCR(timer)               MMIO32((timer) + 0x070)
#define TIMER0_CTCR                     TIMER_CTCR(TIMER0)
#define TIMER1_CTCR                     TIMER_CTCR(TIMER1)
#define TIMER2_CTCR                     TIMER_CTCR(TIMER2)
#define TIMER3_CTCR                     TIMER_CTCR(TIMER3)

/* --- TIMERx_IR values ----------------------------------------------------- */

#define TIMER_IR_MR0INT                 (1 << 0)
#define TIMER_IR_MR1INT                 (1 << 1)
#define TIMER_IR_MR2INT                 (1 << 2)
#define TIMER_IR_MR3INT                 (1 << 3)
#define TIMER_IR_CR0INT                 (1 << 4)
#define TIMER_IR_CR1INT                 (1 << 5)
#define TIMER_IR_CR2INT                 (1 << 6)
#define TIMER_IR_CR3INT                 (1 << 7)

/* --- TIMERx_TCR values --------------------------------------------------- */

#define TIMER_TCR_CEN                   (1 << 0)
#define TIMER_TCR_CRST                  (1 << 1)

/* --- TIMERx_MCR values --------------------------------------------------- */

#define TIMER_MCR_MR0I                  (1 << 0)
#define TIMER_MCR_MR0R                  (1 << 1)
#define TIMER_MCR_MR0S                  (1 << 2)
#define TIMER_MCR_MR1I                  (1 << 3)
#define TIMER_MCR_MR1R                  (1 << 4)
#define TIMER_MCR_MR1S                  (1 << 5)
#define TIMER_MCR_MR2I                  (1 << 6)
#define TIMER_MCR_MR2R                  (1 << 7)
#define TIMER_MCR_MR2S                  (1 << 8)
#define TIMER_MCR_MR3I                  (1 << 9)
#define TIMER_MCR_MR3R                  (1 << 10)
#define TIMER_MCR_MR3S                  (1 << 11)

/* --- TIMERx_MCR values --------------------------------------------------- */

#define TIMER_CCR_CAP0RE                (1 << 0)
#define TIMER_CCR_CAP0FE                (1 << 1)
#define TIMER_CCR_CAP0I                 (1 << 2)
#define TIMER_CCR_CAP1RE                (1 << 3)
#define TIMER_CCR_CAP1FE                (1 << 4)
#define TIMER_CCR_CAP1I                 (1 << 5)
#define TIMER_CCR_CAP2RE                (1 << 6)
#define TIMER_CCR_CAP2FE                (1 << 7)
#define TIMER_CCR_CAP2I                 (1 << 8)
#define TIMER_CCR_CAP3RE                (1 << 9)
#define TIMER_CCR_CAP3FE                (1 << 10)
#define TIMER_CCR_CAP3I                 (1 << 11)

/* --- TIMERx_EMR values --------------------------------------------------- */

#define TIMER_EMR_EM0                   (1 << 0)
#define TIMER_EMR_EM1                   (1 << 1)
#define TIMER_EMR_EM2                   (1 << 2)
#define TIMER_EMR_EM3                   (1 << 3)
#define TIMER_EMR_EMC0_SHIFT            4
#define TIMER_EMR_EMC0_MASK             (0x3 << TIMER_EMR_EMC0_SHIFT)
#define TIMER_EMR_EMC1_SHIFT            6
#define TIMER_EMR_EMC1_MASK             (0x3 << TIMER_EMR_EMC1_SHIFT)
#define TIMER_EMR_EMC2_SHIFT            8
#define TIMER_EMR_EMC2_MASK             (0x3 << TIMER_EMR_EMC2_SHIFT)
#define TIMER_EMR_EMC3_SHIFT            10
#define TIMER_EMR_EMC3_MASK             (0x3 << TIMER_EMR_EMC3_SHIFT)

#define TIMER_EMR_EMC_NOTHING           0x0
#define TIMER_EMR_EMC_CLEAR             0x1
#define TIMER_EMR_EMC_SET               0x2
#define TIMER_EMR_EMC_TOGGLE            0x3

/* --- TIMERx_CTCR values -------------------------------------------------- */

#define TIMER_CTCR_MODE_TIMER           (0x0 << 0)
#define TIMER_CTCR_MODE_COUNTER_RISING  (0x1 << 0)
#define TIMER_CTCR_MODE_COUNTER_FALLING (0x2 << 0)
#define TIMER_CTCR_MODE_COUNTER_BOTH    (0x3 << 0)
#define TIMER_CTCR_MODE_MASK            (0x3 << 0)

#define TIMER_CTCR_CINSEL_CAPN_0        (0x0 << 2)
#define TIMER_CTCR_CINSEL_CAPN_1        (0x1 << 2)
#define TIMER_CTCR_CINSEL_CAPN_2        (0x2 << 2)
#define TIMER_CTCR_CINSEL_CAPN_3        (0x3 << 2)
#define TIMER_CTCR_CINSEL_MASK          (0x3 << 2)

/* --- TIMER function prototypes ------------------------------------------- */

BEGIN_DECLS

void timer_reset(uint32_t timer_peripheral);
void timer_enable_counter(uint32_t timer_peripheral);
void timer_disable_counter(uint32_t timer_peripheral);
uint32_t timer_get_counter(uint32_t timer_peripheral);
void timer_set_counter(uint32_t timer_peripheral, uint32_t count);
uint32_t timer_get_prescaler(uint32_t timer_peripheral);
void timer_set_prescaler(uint32_t timer_peripheral, uint32_t prescaler);
void timer_set_mode(uint32_t timer_peripheral, uint32_t mode);
void timer_set_count_input(uint32_t timer_peripheral, uint32_t input);

END_DECLS

/**@}*/

#endif

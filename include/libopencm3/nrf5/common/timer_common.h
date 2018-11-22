/** @addtogroup timer_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2018 
 * Gerrit Maus <funk@maus.xyz>, Luong Le <novercy@live.com>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2018 Gerrit Maus <funk@maus.xyz>, Luong Le <novercy@live.com>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA TIMER.H
The order of header inclusion is important. timer.h includes the device
specific memorymap.h header before including this header file.
*/

/** @cond */
#if defined(LIBOPENCM3_TIMER_H)
/** @endcond */
#ifndef LIBOPENCM3_TIMER_COMMON_H
#define LIBOPENCM3_TIMER_COMMON_H

/**@{*/
/** @defgroup timer_reg_base Timer register base addresses
 * @ingroup timer_defines
 * @{
 */
#define TIMER0                     TIMER0_BASE
#define TIMER1                     TIMER1_BASE
#define TIMER2                     TIMER2_BASE
#define TIMER3                     TIMER3_BASE
#define TIMER4                     TIMER4_BASE
/**@}*/

/** @defgroup timer_registers Timer Registers
 * @ingroup timer_defines
 * @brief Timer Registers
@{*/
/* --------------------- TIMER registers for NRF52 ------------------------- */

/* Tasks Registers */
#define TIMER_TASKS_START(timer_base)            MMIO32((timer_base) + 0x000)
#define TIMER0_TASKS_START                       MMIO32((TIMER0) + 0x000)
#define TIMER1_TASKS_START                       MMIO32((TIMER1) + 0x000)
#define TIMER2_TASKS_START                       MMIO32((TIMER2) + 0x000)
#define TIMER3_TASKS_START                       MMIO32((TIMER3) + 0x000)
#define TIMER4_TASKS_START                       MMIO32((TIMER4) + 0x000)

#define TIMER_TASKS_STOP(timer_base)             MMIO32((timer_base) + 0x004)
#define TIMER0_TASKS_STOP                        MMIO32((TIMER0) + 0x004)
#define TIMER1_TASKS_STOP                        MMIO32((TIMER1) + 0x004)
#define TIMER2_TASKS_STOP                        MMIO32((TIMER2) + 0x004)
#define TIMER3_TASKS_STOP                        MMIO32((TIMER3) + 0x004)
#define TIMER4_TASKS_STOP                        MMIO32((TIMER4) + 0x004)

#define TIMER_TASKS_COUNT(timer_base)            MMIO32((timer_base) + 0x008)
#define TIMER0_TASKS_COUNT                       MMIO32((TIMER0) + 0x008)
#define TIMER1_TASKS_COUNT                       MMIO32((TIMER1) + 0x008)
#define TIMER2_TASKS_COUNT                       MMIO32((TIMER2) + 0x008)
#define TIMER3_TASKS_COUNT                       MMIO32((TIMER3) + 0x008)
#define TIMER4_TASKS_COUNT                       MMIO32((TIMER4) + 0x008)

#define TIMER_TASKS_CLEAR(timer_base)            MMIO32((timer_base) + 0x00C)
#define TIMER0_TASKS_CLEAR                       MMIO32((TIMER0) + 0x00C)
#define TIMER1_TASKS_CLEAR                       MMIO32((TIMER1) + 0x00C)
#define TIMER2_TASKS_CLEAR                       MMIO32((TIMER2) + 0x00C)
#define TIMER3_TASKS_CLEAR                       MMIO32((TIMER3) + 0x00C)
#define TIMER4_TASKS_CLEAR                       MMIO32((TIMER4) + 0x00C)

#define TIMER_TASKS_SHUTDOWN(timer_base)         MMIO32((timer_base) + 0x010)
#define TIMER0_TASKS_SHUTDOWN                    MMIO32((TIMER0) + 0x010)
#define TIMER1_TASKS_SHUTDOWN                    MMIO32((TIMER1) + 0x010)
#define TIMER2_TASKS_SHUTDOWN                    MMIO32((TIMER2) + 0x010)
#define TIMER3_TASKS_SHUTDOWN                    MMIO32((TIMER3) + 0x010)
#define TIMER4_TASKS_SHUTDOWN                    MMIO32((TIMER4) + 0x010)

/* Tasks Capture Registers */
#define TIMER_TASKS_CAPTURE(timer_base)          PTRIO32((timer_base) + 0x040)
#define TIMER0_TASKS_CAPTURE                     PTRIO32((TIMER0) + 0x040)
#define TIMER1_TASKS_CAPTURE                     PTRIO32((TIMER1) + 0x040)
#define TIMER2_TASKS_CAPTURE                     PTRIO32((TIMER2) + 0x040)
#define TIMER3_TASKS_CAPTURE                     PTRIO32((TIMER3) + 0x040)
#define TIMER4_TASKS_CAPTURE                     PTRIO32((TIMER4) + 0x040)


/* Events Compare Registers */
#define TIMER_EVENTS_COMPARE(timer_base)         PTRIO32((timer_base) + 0x140)
#define TIMER0_EVENTS_COMPARE                    PTRIO32((TIMER0) + 0x140)
#define TIMER1_EVENTS_COMPARE                    PTRIO32((TIMER1) + 0x140)
#define TIMER2_EVENTS_COMPARE                    PTRIO32((TIMER2) + 0x140)
#define TIMER3_EVENTS_COMPARE                    PTRIO32((TIMER3) + 0x140)
#define TIMER4_EVENTS_COMPARE                    PTRIO32((TIMER4) + 0x140)


/* Registers */
#define TIMER_SHORTS(timer_base)                 MMIO32((timer_base) + 0x200)
#define TIMER0_SHORTS                            MMIO32((TIMER0) + 0x200)
#define TIMER1_SHORTS                            MMIO32((TIMER1) + 0x200)
#define TIMER2_SHORTS                            MMIO32((TIMER2) + 0x200)
#define TIMER3_SHORTS                            MMIO32((TIMER3) + 0x200)
#define TIMER4_SHORTS                            MMIO32((TIMER4) + 0x200)

#define TIMER_INTENSET(timer_base)               MMIO32((timer_base) + 0x304)
#define TIMER0_INTENSET                          MMIO32((TIMER0) + 0x304)
#define TIMER1_INTENSET                          MMIO32((TIMER1) + 0x304)
#define TIMER2_INTENSET                          MMIO32((TIMER2) + 0x304)
#define TIMER3_INTENSET                          MMIO32((TIMER3) + 0x304)
#define TIMER4_INTENSET                          MMIO32((TIMER4) + 0x304)

#define TIMER_INTENCLR(timer_base)               MMIO32((timer_base) + 0x308)
#define TIMER0_INTENCLR                          MMIO32((TIMER0) + 0x308)
#define TIMER1_INTENCLR                          MMIO32((TIMER1) + 0x308)
#define TIMER2_INTENCLR                          MMIO32((TIMER2) + 0x308)
#define TIMER3_INTENCLR                          MMIO32((TIMER3) + 0x308)
#define TIMER4_INTENCLR                          MMIO32((TIMER4) + 0x308)

#define TIMER_MODE(timer_base)                   MMIO32((timer_base) + 0x504)
#define TIMER0_MODE                              MMIO32((TIMER0) + 0x504)
#define TIMER1_MODE                              MMIO32((TIMER1) + 0x504)
#define TIMER2_MODE                              MMIO32((TIMER2) + 0x504)
#define TIMER3_MODE                              MMIO32((TIMER3) + 0x504)
#define TIMER4_MODE                              MMIO32((TIMER4) + 0x504)

#define TIMER_BITMODE(timer_base)                MMIO32((timer_base) + 0x508)
#define TIMER0_BITMODE                           MMIO32((TIMER0) + 0x508)
#define TIMER1_BITMODE                           MMIO32((TIMER1) + 0x508)
#define TIMER2_BITMODE                           MMIO32((TIMER2) + 0x508)
#define TIMER3_BITMODE                           MMIO32((TIMER3) + 0x508)
#define TIMER4_BITMODE                           MMIO32((TIMER4) + 0x508)

#define TIMER_PRESCALER(timer_base)              MMIO32((timer_base) + 0x510)
#define TIMER0_PRESCALER                         MMIO32((TIMER0) + 0x510)
#define TIMER1_PRESCALER                         MMIO32((TIMER1) + 0x510)
#define TIMER2_PRESCALER                         MMIO32((TIMER2) + 0x510)
#define TIMER3_PRESCALER                         MMIO32((TIMER3) + 0x510)
#define TIMER4_PRESCALER                         MMIO32((TIMER4) + 0x510)

#define TIMER_CC(timer_base)                     PTRIO32((timer_base) + 0x540)
#define TIMER0_CC                                PTRIO32((TIMER0) + 0x540)
#define TIMER1_CC                                PTRIO32((TIMER1) + 0x540)
#define TIMER2_CC                                PTRIO32((TIMER2) + 0x540)
#define TIMER3_CC                                PTRIO32((TIMER3) + 0x540)
#define TIMER4_CC                                PTRIO32((TIMER4) + 0x540)
/**@}*/

/* ------------------------------------------------------------------------- */
/* Capture/Compare definitions (for convenience) */
/** @defgroup timer_cc_id Capture/Compare Identifiers
@ingroup timer_defines
@{*/
#define CC0                        0
#define CC1                        1
#define CC2                        2
#define CC3                        3
#define CC4                        4
#define CC5                        5
/**@}*/

/* --- TIMER_SHORTS values ------------------------------------------------- */
/** @defgroup timer_shorts Set shortcut between COMPARE-CLEAR and COMPARE-STOP
@ingroup timer_defines
@{*/
#define TIMER_SHORTS_COMPARE0_CLEAR_ENABLED           (1 << 0)
#define TIMER_SHORTS_COMPARE0_CLEAR_Enabled           (1 << 0)
#define TIMER_SHORTS_COMPARE1_CLEAR_ENABLED           (1 << 1)
#define TIMER_SHORTS_COMPARE1_CLEAR_Enabled           (1 << 1)
#define TIMER_SHORTS_COMPARE2_CLEAR_ENABLED           (1 << 2)
#define TIMER_SHORTS_COMPARE2_CLEAR_Enabled           (1 << 2)
#define TIMER_SHORTS_COMPARE3_CLEAR_ENABLED           (1 << 3)
#define TIMER_SHORTS_COMPARE3_CLEAR_Enabled           (1 << 3)
#define TIMER_SHORTS_COMPARE4_CLEAR_ENABLED           (1 << 4)
#define TIMER_SHORTS_COMPARE4_CLEAR_Enabled           (1 << 4)
#define TIMER_SHORTS_COMPARE5_CLEAR_ENABLED           (1 << 5)
#define TIMER_SHORTS_COMPARE5_CLEAR_Enabled           (1 << 5)
#define TIMER_SHORTS_COMPARE0_STOP_ENABLED            (1 << 8)
#define TIMER_SHORTS_COMPARE0_STOP_Enabled            (1 << 8)
#define TIMER_SHORTS_COMPARE1_STOP_ENABLED            (1 << 9)
#define TIMER_SHORTS_COMPARE1_STOP_Enabled            (1 << 9)
#define TIMER_SHORTS_COMPARE2_STOP_ENABLED            (1 << 10)
#define TIMER_SHORTS_COMPARE2_STOP_Enabled            (1 << 10)
#define TIMER_SHORTS_COMPARE3_STOP_ENABLED            (1 << 11)
#define TIMER_SHORTS_COMPARE3_STOP_Enabled            (1 << 11)
#define TIMER_SHORTS_COMPARE4_STOP_ENABLED            (1 << 12)
#define TIMER_SHORTS_COMPARE4_STOP_Enabled            (1 << 12)
#define TIMER_SHORTS_COMPARE5_STOP_ENABLED            (1 << 13)
#define TIMER_SHORTS_COMPARE5_STOP_Enabled            (1 << 13)
/**@}*/

/* --- TIMER_INTENSET values ----------------------------------------------- */
/** @defgroup timer_intenset Enable interrupt
@ingroup timer_defines
@{*/
#define TIMER_INTENSET_COMPARE0_ENABLED               (1 << 16)
#define TIMER_INTENSET_COMPARE0_Enabled               (1 << 16)
#define TIMER_INTENSET_COMPARE0_SET                   (1 << 16)
#define TIMER_INTENSET_COMPARE0_Set                   (1 << 16)
#define TIMER_INTENSET_COMPARE1_ENABLED               (1 << 17)
#define TIMER_INTENSET_COMPARE1_Enabled               (1 << 17)
#define TIMER_INTENSET_COMPARE1_SET                   (1 << 17)
#define TIMER_INTENSET_COMPARE1_Set                   (1 << 17)
#define TIMER_INTENSET_COMPARE2_ENABLED               (1 << 18)
#define TIMER_INTENSET_COMPARE2_Enabled               (1 << 18)
#define TIMER_INTENSET_COMPARE2_SET                   (1 << 18)
#define TIMER_INTENSET_COMPARE2_Set                   (1 << 18)
#define TIMER_INTENSET_COMPARE3_ENABLED               (1 << 19)
#define TIMER_INTENSET_COMPARE3_Enabled               (1 << 19)
#define TIMER_INTENSET_COMPARE3_SET                   (1 << 19)
#define TIMER_INTENSET_COMPARE3_Set                   (1 << 19)
#define TIMER_INTENSET_COMPARE4_ENABLED               (1 << 20)
#define TIMER_INTENSET_COMPARE4_Enabled               (1 << 20)
#define TIMER_INTENSET_COMPARE4_SET                   (1 << 20)
#define TIMER_INTENSET_COMPARE4_Set                   (1 << 20)
#define TIMER_INTENSET_COMPARE5_ENABLED               (1 << 21)
#define TIMER_INTENSET_COMPARE5_Enabled               (1 << 21)
#define TIMER_INTENSET_COMPARE5_SET                   (1 << 21)
#define TIMER_INTENSET_COMPARE5_Set                   (1 << 21)
/**@}*/

/* --- TIMER_INTENCLR values ----------------------------------------------- */
/** @defgroup timer_intenclr Disable interrupt
@ingroup timer_defines
@{*/
#define TIMER_INTENCLR_COMPARE0_ENABLED               (1 << 16)
#define TIMER_INTENCLR_COMPARE0_Enabled               (1 << 16)
#define TIMER_INTENCLR_COMPARE0_CLEAR                 (1 << 16)
#define TIMER_INTENCLR_COMPARE0_Clear                 (1 << 16)
#define TIMER_INTENCLR_COMPARE1_ENABLED               (1 << 17)
#define TIMER_INTENCLR_COMPARE1_Enabled               (1 << 17)
#define TIMER_INTENCLR_COMPARE1_CLEAR                 (1 << 17)
#define TIMER_INTENCLR_COMPARE1_Clear                 (1 << 17)
#define TIMER_INTENCLR_COMPARE2_ENABLED               (1 << 18)
#define TIMER_INTENCLR_COMPARE2_Enabled               (1 << 18)
#define TIMER_INTENCLR_COMPARE2_CLEAR                 (1 << 18)
#define TIMER_INTENCLR_COMPARE2_Clear                 (1 << 18)
#define TIMER_INTENCLR_COMPARE3_ENABLED               (1 << 19)
#define TIMER_INTENCLR_COMPARE3_Enabled               (1 << 19)
#define TIMER_INTENCLR_COMPARE3_CLEAR                 (1 << 19)
#define TIMER_INTENCLR_COMPARE3_Clear                 (1 << 19)
#define TIMER_INTENCLR_COMPARE4_ENABLED               (1 << 20)
#define TIMER_INTENCLR_COMPARE4_Enabled               (1 << 20)
#define TIMER_INTENCLR_COMPARE4_CLEAR                 (1 << 20)
#define TIMER_INTENCLR_COMPARE4_Clear                 (1 << 20)
#define TIMER_INTENCLR_COMPARE5_ENABLED               (1 << 21)
#define TIMER_INTENCLR_COMPARE5_Enabled               (1 << 21)
#define TIMER_INTENCLR_COMPARE5_CLEAR                 (1 << 21)
#define TIMER_INTENCLR_COMPARE5_Clear                 (1 << 21)
/**@}*/

/* --- TIMER_MODE values --------------------------------------------------- */
/** @defgroup timer_mode Select Timer mode
@ingroup timer_defines
@{*/
#define MODE_TIMER                                   (0)
#define TIMER_MODE_MODE_TIMER                        (0)
#define MODE_COUNTER                                 (1)
#define TIMER_MODE_MODE_COUNTER                      (1)
#define MODE_LPC                                     (2)
#define TIMER_MODE_MODE_LPC                          (2) /*Low Power Counter*/
/**@}*/

/* --- TIMER_BITMODE values ------------------------------------------------ */
/** @defgroup timer_bitmode Set number of bits used by the Timer
@ingroup timer_defines
@{*/
#define BITMODE_8                               (1)
#define TIMER_BITMODE_BITMODE_8                 (1)
#define TIMER_BITMODE_BITMODE_8BIT              (1)
#define TIMER_BITMODE_BITMODE_8Bit              (1)
#define TIMER_BITMODE_BITMODE_08BIT             (1)
#define TIMER_BITMODE_BITMODE_08Bit             (1)
#define BITMODE_16                              (0)
#define TIMER_BITMODE_BITMODE_16                (0)
#define TIMER_BITMODE_BITMODE_16BIT             (0)
#define TIMER_BITMODE_BITMODE_16Bit             (0)
#define BITMODE_24                              (2)
#define TIMER_BITMODE_BITMODE_24                (2)
#define TIMER_BITMODE_BITMODE_24BIT             (2)
#define TIMER_BITMODE_BITMODE_24Bit             (2)
#define BITMODE_32                              (3)
#define TIMER_BITMODE_BITMODE_32                (3)
#define TIMER_BITMODE_BITMODE_32BIT             (3)
#define TIMER_BITMODE_BITMODE_32Bit             (3)
/**@}*/

/* --- TIMER_PRESCALER values ---------------------------------------------- */
/** @defgroup timer_prescaler Set prescaler
@ingroup timer_defines
@{*/
#define TIMER_PRESCALER_PRESCALER(n)                ((n)&0x0f) // Value 0..9
/**@}*/


/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void timer_start(uint32_t timer);
void timer_stop(uint32_t timer);
void timer_clear(uint32_t timer);
void timer_shutdown(uint32_t timer);
void timer_capture_enable(uint32_t timer, size_t cc);
uint32_t timer_compare_matched(uint32_t timer, size_t cc);
void timer_compare_reset(uint32_t timer, size_t cc);
void timer_mode(uint32_t timer, uint32_t mode);
void timer_bitmode(uint32_t timer, uint32_t bitmode);
void timer_prescaler(uint32_t timer, uint8_t prescaler);
void timer_cc_set(uint32_t timer, size_t cc, uint32_t value);
void timer_interrupt_enable(uint32_t timer, size_t cc);
void timer_interrupt_disable(uint32_t timer, size_t cc);
int timer_get_frequency(uint32_t timer);

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "timer_common.h should not be included explicitly, only via timer.h"
#endif
/** @endcond */


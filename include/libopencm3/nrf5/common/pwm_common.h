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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA PWM.H
The order of header inclusion is important. pwm.h includes the device
specific memorymap.h header before including this header file.
*/

/** @cond */
#if defined(LIBOPENCM3_PWM_H)
/** @endcond */
#ifndef LIBOPENCM3_PWM_COMMON_H
#define LIBOPENCM3_PWM_COMMON_H


/**@{*/
/** @defgroup pwm_reg_base PWM register base addresses
 * @ingroup pwm_defines
 * @{
 */
#define PWM0                            PWM0_BASE
#define PWM1                            PWM1_BASE
#define PWM2                            PWM2_BASE
/**@}*/

/** @defgroup pwm_registers PWM Registers
 * @ingroup pwm_defines
 * @brief PWM Registers
@{*/
/* --------------------- PWM registers for NRF52 ------------------------- */

/* Tasks Registers */
#define PWM_TASKS_STOP(pwm_base)                 MMIO32((pwm_base) + 0x004)
#define PWM0_TASKS_STOP                          MMIO32((PWM0) + 0x004)
#define PWM1_TASKS_STOP                          MMIO32((PWM1) + 0x004)
#define PWM2_TASKS_STOP                          MMIO32((PWM2) + 0x004)

#define PWM_TASKS_SEQSTART(pwm_base)             PTRIO32((pwm_base) + 0x008)
#define PWM0_TASKS_SEQSTART                      PTRIO32((PWM0) + 0x008)
#define PWM1_TASKS_SEQSTART                      PTRIO32((PWM1) + 0x008)
#define PWM2_TASKS_SEQSTART                      PTRIO32((PWM2) + 0x008)

#define PWM_TASKS_NEXTSTEP(pwm_base)             MMIO32((pwm_base) + 0x010)
#define PWM0_TASKS_NEXTSTEP                      MMIO32((PWM0) + 0x010)
#define PWM1_TASKS_NEXTSTEP                      MMIO32((PWM1) + 0x010)
#define PWM2_TASKS_NEXTSTEP                      MMIO32((PWM2) + 0x010)

/* Events registers */
#define PWM_EVENTS_STOPPED(pwm_base)             MMIO32((pwm_base) + 0x104)
#define PWM0_EVENTS_STOPPED                      MMIO32((PWM0) + 0x104)
#define PWM1_EVENTS_STOPPED                      MMIO32((PWM1) + 0x104)
#define PWM2_EVENTS_STOPPED                      MMIO32((PWM2) + 0x104)

#define PWM_EVENTS_SEQSTARTED(pwm_base)          PTRIO32((pwm_base) + 0x108)
#define PWM0_EVENTS_SEQSTARTED                   PTRIO32((PWM0) + 0x108)
#define PWM1_EVENTS_SEQSTARTED                   PTRIO32((PWM1) + 0x108)
#define PWM2_EVENTS_SEQSTARTED                   PTRIO32((PWM2) + 0x108)

#define PWM_EVENTS_SEQEND(pwm_base)              PTRIO32((pwm_base) + 0x110)
#define PWM0_EVENTS_SEQEND                       PTRIO32((PWM0) + 0x110)
#define PWM1_EVENTS_SEQEND                       PTRIO32((PWM1) + 0x110)
#define PWM2_EVENTS_SEQEND                       PTRIO32((PWM2) + 0x110)

#define PWM_EVENTS_PWMPERIODEN(pwm_base)         MMIO32((pwm_base) + 0x118)
#define PWM0_EVENTS_PWMPERIODEN                  MMIO32((PWM0) + 0x118)
#define PWM1_EVENTS_PWMPERIODEN                  MMIO32((PWM1) + 0x118)
#define PWM2_EVENTS_PWMPERIODEN                  MMIO32((PWM2) + 0x118)

#define PWM_EVENTS_LOOPSDONE(pwm_base)           MMIO32((pwm_base) + 0x11C)
#define PWM0_EVENTS_LOOPSDONE                    MMIO32((PWM0) + 0x11C)
#define PWM1_EVENTS_LOOPSDONE                    MMIO32((PWM1) + 0x11C)
#define PWM2_EVENTS_LOOPSDONE                    MMIO32((PWM2) + 0x11C)

/* Registers */
#define PWM_SHORTS(pwm_base)                     MMIO32((pwm_base) + 0x200)
#define PWM0_SHORTS                              MMIO32((PWM0) + 0x200)
#define PWM1_SHORTS                              MMIO32((PWM1) + 0x200)
#define PWM2_SHORTS                              MMIO32((PWM2) + 0x200)

#define PWM_INTEN(pwm_base)                      MMIO32((pwm_base) + 0x300)
#define PWM0_INTEN                               MMIO32((PWM0) + 0x300)
#define PWM1_INTEN                               MMIO32((PWM1) + 0x300)
#define PWM2_INTEN                               MMIO32((PWM2) + 0x300)

#define PWM_INTENSET(pwm_base)                   MMIO32((pwm_base) + 0x304)
#define PWM0_INTENSET                            MMIO32((PWM0) + 0x304)
#define PWM1_INTENSET                            MMIO32((PWM1) + 0x304)
#define PWM2_INTENSET                            MMIO32((PWM2) + 0x304)

#define PWM_INTENCLR(pwm_base)                   MMIO32((pwm_base) + 0x308)
#define PWM0_INTENCLR                            MMIO32((PWM0) + 0x308)
#define PWM1_INTENCLR                            MMIO32((PWM1) + 0x308)
#define PWM2_INTENCLR                            MMIO32((PWM2) + 0x308)

#define PWM_ENABLE(pwm_base)                     MMIO32((pwm_base) + 0x500)
#define PWM0_ENABLE                              MMIO32((PWM0) + 0x500)
#define PWM1_ENABLE                              MMIO32((PWM1) + 0x500)
#define PWM2_ENABLE                              MMIO32((PWM2) + 0x500)

#define PWM_MODE(pwm_base)                       MMIO32((pwm_base) + 0x504)
#define PWM0_MODE                                MMIO32((PWM0) + 0x504)
#define PWM1_MODE                                MMIO32((PWM1) + 0x504)
#define PWM2_MODE                                MMIO32((PWM2) + 0x504)

#define PWM_COUNTERTOP(pwm_base)                 MMIO32((pwm_base) + 0x508)
#define PWM0_COUNTERTOP                          MMIO32((PWM0) + 0x508)
#define PWM1_COUNTERTOP                          MMIO32((PWM1) + 0x508)
#define PWM2_COUNTERTOP                          MMIO32((PWM2) + 0x508)

#define PWM_PRESCALER(pwm_base)                  MMIO32((pwm_base) + 0x50C)
#define PWM0_PRESCALER                           MMIO32((PWM0) + 0x50C)
#define PWM1_PRESCALER                           MMIO32((PWM1) + 0x50C)
#define PWM2_PRESCALER                           MMIO32((PWM2) + 0x50C)

#define PWM_DECODER(pwm_base)                    MMIO32((pwm_base) + 0x510)
#define PWM0_DECODER                             MMIO32((PWM0) + 0x510)
#define PWM1_DECODER                             MMIO32((PWM1) + 0x510)
#define PWM2_DECODER                             MMIO32((PWM2) + 0x510)

#define PWM_LOOP(pwm_base)                       MMIO32((pwm_base) + 0x514)
#define PWM0_LOOP                                MMIO32((PWM0) + 0x514)
#define PWM1_LOOP                                MMIO32((PWM1) + 0x514)
#define PWM2_LOOP                                MMIO32((PWM2) + 0x514)

struct PWM_SEQ_TYPE{
	uint32_t PTR;
	uint32_t CNT;
	uint32_t REFRESH;
	uint32_t ENDDELAY;
};
#define PWM_SEQ(pwm_base)   ((volatile struct PWM_SEQ_TYPE*)((pwm_base) + 0x520))

#define PWM_SEQ0_PTR(pwm_base)                   MMIO32((pwm_base) + 0x520)
#define PWM_SEQ0_CNT(pwm_base)                   MMIO32((pwm_base) + 0x524)
#define PWM_SEQ0_REFRESH(pwm_base)               MMIO32((pwm_base) + 0x528)
#define PWM_SEQ0_ENDDELAY(pwm_base)              MMIO32((pwm_base) + 0x52C)
#define PWM_SEQ1_PTR(pwm_base)                   MMIO32((pwm_base) + 0x540)
#define PWM_SEQ1_CNT(pwm_base)                   MMIO32((pwm_base) + 0x544)
#define PWM_SEQ1_REFRESH(pwm_base)               MMIO32((pwm_base) + 0x548)
#define PWM_SEQ1_ENDDELAY(pwm_base)              MMIO32((pwm_base) + 0x54C)

struct PWM_PSEL_TYPE{
	uint32_t OUT[4];
};
#define PWM_PSEL(pwm_base)  (*(volatile struct PWM_PSEL_TYPE*)((pwm_base) + 0x560))

#define PWM_PSEL_OUT(pwm_base)                   PTRIO32((pwm_base) + 0x560)
#define PWM_PSEL_OUT0(pwm_base)                  MMIO32((pwm_base) + 0x560)
#define PWM_PSEL_OUT1(pwm_base)                  MMIO32((pwm_base) + 0x564)
#define PWM_PSEL_OUT2(pwm_base)                  MMIO32((pwm_base) + 0x568)

#define PWM0_PSEL_OUT                            PTRIO32((PWM0) + 0x560)
#define PWM0_PSEL_OUT0                           MMIO32((PWM0) + 0x560)
#define PWM0_PSEL_OUT1                           MMIO32((PWM0) + 0x564)
#define PWM0_PSEL_OUT2                           MMIO32((PWM0) + 0x568)
#define PWM0_PSEL_OUT3                           MMIO32((PWM0) + 0x56C)
#define PWM1_PSEL_OUT                            PTRIO32((PWM1) + 0x560)
#define PWM1_PSEL_OUT0                           MMIO32((PWM1) + 0x560)
#define PWM1_PSEL_OUT1                           MMIO32((PWM1) + 0x564)
#define PWM1_PSEL_OUT2                           MMIO32((PWM1) + 0x568)
#define PWM1_PSEL_OUT3                           MMIO32((PWM1) + 0x56C)
#define PWM2_PSEL_OUT                            PTRIO32((PWM2) + 0x560)
#define PWM2_PSEL_OUT0                           MMIO32((PWM2) + 0x560)
#define PWM2_PSEL_OUT1                           MMIO32((PWM2) + 0x564)
#define PWM2_PSEL_OUT2                           MMIO32((PWM2) + 0x568)
#define PWM2_PSEL_OUT3                           MMIO32((PWM2) + 0x56C)
/**@}*/

/* ------------------------------------------------------------------------- */
/* Sequence definitions (for convenience) */
/** @defgroup pwm_seq_id Sequence Identifiers
@ingroup pwm_defines
@{*/
#define SEQ0                                     0
#define SEQ1                                     1
/**@}*/

/* ------------------------------------------------------------------------- */
/* Output definitions (for convenience) */
/** @defgroup pwm_output_id Output number Identifiers
@ingroup pwm_defines
@{*/
#define OUTPUT0                                  0
#define OUTPUT1                                  1
#define OUTPUT2                                  2
#define OUTPUT3                                  3
/**@}*/

/* --- PWM_SHORTS values --------------------------------------------------- */
/** @defgroup pwm_shorts Enable shortcut between Tasks and Events
@ingroup pwm_defines
@{*/
#define PWM_SHORTS_SEQEND0_STOP_ENABLE               (1 << 0)
#define PWM_SHORTS_SEQEND1_STOP_ENABLE               (1 << 1)
#define PWM_SHORTS_LOOPSDONE_SEQSTART0_ENABLE        (1 << 2)
#define PWM_SHORTS_LOOPSDONE_SEQSTART1_ENABLE        (1 << 3)
#define PWM_SHORTS_LOOPSDONE_STOP_ENABLE             (1 << 4)
/**@}*/

/* ------------------------------------------------------------------------- */
/* Events interrupt definitions (for convenience) */
/** @defgroup pwm_events_interrupt PWM Events Identifiers for interrupt
@ingroup pwm_defines
@{*/
#define STOPPED                     (1 << 1)
#define SEQSTARTED0                 (1 << 2)
#define SEQSTARTED1                 (1 << 3)
#define SEQEND0                     (1 << 4)
#define SEQEND1                     (1 << 5)
#define PWMPERIODEND                (1 << 6)
#define LOOPSDONE                   (1 << 7)
/**@}*/

/* --- PWM_INTEN values ---------------------------------------------------- */
/** @defgroup pwm_inten Enable/Disable interrupts
@ingroup pwm_defines
@{*/
#define PWM_INTEN_STOPPED_DISABLED                   (0 << 1)
#define PWM_INTEN_STOPPED_Disabled                   (0 << 1)
#define PWM_INTEN_STOPPED_ENABLED                    (1 << 1)
#define PWM_INTEN_STOPPED_Enabled                    (1 << 1)
#define PWM_INTEN_SEQSTARTED0_DISABLED               (0 << 2)
#define PWM_INTEN_SEQSTARTED0_Disabled               (0 << 2)
#define PWM_INTEN_SEQSTARTED0_ENABLED                (1 << 2)
#define PWM_INTEN_SEQSTARTED1_Enabled                (1 << 2)
#define PWM_INTEN_SEQSTARTED1_DISABLED               (0 << 3)
#define PWM_INTEN_SEQSTARTED1_Disabled               (0 << 3)
#define PWM_INTEN_SEQSTARTED1_ENABLED                (1 << 3)
#define PWM_INTEN_SEQSTARTED0_Enabled                (1 << 3)
#define PWM_INTEN_SEQEND0_DISABLED                   (0 << 4)
#define PWM_INTEN_SEQEND0_Disabled                   (0 << 4)
#define PWM_INTEN_SEQEND0_ENABLED                    (1 << 4)
#define PWM_INTEN_SEQEND0_Enabled                    (1 << 4)
#define PWM_INTEN_SEQEND1_DISABLED                   (0 << 5)
#define PWM_INTEN_SEQEND1_Disabled                   (0 << 5)
#define PWM_INTEN_SEQEND1_ENABLED                    (1 << 5)
#define PWM_INTEN_SEQEND1_Enabled                    (1 << 5)
#define PWM_INTEN_PWMPERIODEND_DISABLED              (0 << 6)
#define PWM_INTEN_PWMPERIODEND_Disabled              (0 << 6)
#define PWM_INTEN_PWMPERIODEND_ENABLED               (1 << 6)
#define PWM_INTEN_PWMPERIODEND_Enabled               (1 << 6)
#define PWM_INTEN_LOOPSDONE_DISABLED                 (0 << 7)
#define PWM_INTEN_LOOPSDONE_Disabled                 (0 << 7)
#define PWM_INTEN_LOOPSDONE_ENABLED                  (1 << 7)
#define PWM_INTEN_LOOPSDONE_Enabled                  (1 << 7)
/**@}*/

/* --- PWM_INTENSET values ------------------------------------------------- */
/** @defgroup pwm_intenset Enable interrupt
@ingroup pwm_defines
@{*/
#define PWM_INTENSET_STOPPED_SET                     (1 << 1)
#define PWM_INTENSET_STOPPED_Set                     (1 << 1)
#define PWM_INTENSET_STOPPED_ENABLED                 (1 << 1)
#define PWM_INTENSET_STOPPED_Enabled                 (1 << 1)
#define PWM_INTENSET_SEQSTARTED0_SET                 (1 << 2)
#define PWM_INTENSET_SEQSTARTED0_Set                 (1 << 2)
#define PWM_INTENSET_SEQSTARTED0_ENABLED             (1 << 2)
#define PWM_INTENSET_SEQSTARTED1_Enabled             (1 << 2)
#define PWM_INTENSET_SEQSTARTED1_SET                 (1 << 3)
#define PWM_INTENSET_SEQSTARTED1_Set                 (1 << 3)
#define PWM_INTENSET_SEQSTARTED1_ENABLED             (1 << 3)
#define PWM_INTENSET_SEQSTARTED0_Enabled             (1 << 3)
#define PWM_INTENSET_SEQEND0_SET                     (1 << 4)
#define PWM_INTENSET_SEQEND0_Set                     (1 << 4)
#define PWM_INTENSET_SEQEND0_ENABLED                 (1 << 4)
#define PWM_INTENSET_SEQEND0_Enabled                 (1 << 4)
#define PWM_INTENSET_SEQEND1_SET                     (1 << 5)
#define PWM_INTENSET_SEQEND1_Set                     (1 << 5)
#define PWM_INTENSET_SEQEND1_ENABLED                 (1 << 5)
#define PWM_INTENSET_SEQEND1_Enabled                 (1 << 5)
#define PWM_INTENSET_PWMPERIODEND_SET                (1 << 6)
#define PWM_INTENSET_PWMPERIODEND_Set                (1 << 6)
#define PWM_INTENSET_PWMPERIODEND_ENABLED            (1 << 6)
#define PWM_INTENSET_PWMPERIODEND_Enabled            (1 << 6)
#define PWM_INTENSET_LOOPSDONE_SET                   (1 << 7)
#define PWM_INTENSET_LOOPSDONE_Set                   (1 << 7)
#define PWM_INTENSET_LOOPSDONE_ENABLED               (1 << 7)
#define PWM_INTENSET_LOOPSDONE_Enabled               (1 << 7)
/**@}*/

/* --- PWM_INTENCLR values ------------------------------------------------- */
/** @defgroup pwm_intenclr Disable interrupt
@ingroup pwm_defines
@{*/
#define PWM_INTENCLR_STOPPED_CLEAR                   (1 << 1)
#define PWM_INTENCLR_STOPPED_Clear                   (1 << 1)
#define PWM_INTENCLR_STOPPED_ENABLED                 (1 << 1)
#define PWM_INTENCLR_STOPPED_Enabled                 (1 << 1)
#define PWM_INTENCLR_SEQSTARTED0_CLEAR               (1 << 2)
#define PWM_INTENCLR_SEQSTARTED0_Clear               (1 << 2)
#define PWM_INTENCLR_SEQSTARTED0_ENABLED             (1 << 2)
#define PWM_INTENCLR_SEQSTARTED1_Enabled             (1 << 2)
#define PWM_INTENCLR_SEQSTARTED1_CLEAR               (1 << 3)
#define PWM_INTENCLR_SEQSTARTED1_Clear               (1 << 3)
#define PWM_INTENCLR_SEQSTARTED1_ENABLED             (1 << 3)
#define PWM_INTENCLR_SEQSTARTED0_Enabled             (1 << 3)
#define PWM_INTENCLR_SEQEND0_CLEAR                   (1 << 4)
#define PWM_INTENCLR_SEQEND0_Clear                   (1 << 4)
#define PWM_INTENCLR_SEQEND0_ENABLED                 (1 << 4)
#define PWM_INTENCLR_SEQEND0_Enabled                 (1 << 4)
#define PWM_INTENCLR_SEQEND1_CLEAR                   (1 << 5)
#define PWM_INTENCLR_SEQEND1_Clear                   (1 << 5)
#define PWM_INTENCLR_SEQEND1_ENABLED                 (1 << 5)
#define PWM_INTENCLR_SEQEND1_Enabled                 (1 << 5)
#define PWM_INTENCLR_PWMPERIODEND_CLEAR              (1 << 6)
#define PWM_INTENCLR_PWMPERIODEND_Clear              (1 << 6)
#define PWM_INTENCLR_PWMPERIODEND_ENABLED            (1 << 6)
#define PWM_INTENCLR_PWMPERIODEND_Enabled            (1 << 6)
#define PWM_INTENCLR_LOOPSDONE_CLEAR                 (1 << 7)
#define PWM_INTENCLR_LOOPSDONE_Clear                 (1 << 7)
#define PWM_INTENCLR_LOOPSDONE_ENABLED               (1 << 7)
#define PWM_INTENCLR_LOOPSDONE_Enabled               (1 << 7)
/**@}*/

/* --- PWM_ENABLE values --------------------------------------------------- */
/** @defgroup pwm_enable Enable PWM
@ingroup pwm_defines
@{*/
#define PWM_ENABLE_ENABLE_DISABLED                   (0)
#define PWM_ENABLE_ENABLE_Disabled                   (0)
#define PWM_ENABLE_ENABLE_ENABLED                    (1)
#define PWM_ENABLE_ENABLE_Enabled                    (1)
/**@}*/

/* --- PWM_MODE values --------------------------------------------------- */
/** @defgroup pwm_mode Select operating mode of the wave counter
@ingroup pwm_defines
@{*/
#define MODE_UP                                      (0)
#define PWM_MODE_UPDOWN_UP                           (0)
#define PWM_MODE_UPDOWN_Up                           (0)
#define MODE_UPANDDOWN                               (1)
#define PWM_MODE_UPDOWN_UPANDDOWN                    (1)
#define PWM_MODE_UPDOWN_UpAndDown                    (1)
/**@}*/

/* --- PWM_COUNTERTOP values ----------------------------------------------- */
/** @defgroup pwm_countertop Set countertop
@ingroup pwm_defines
@{*/
#define PWM_COUNTERTOP_COUNTERTOP(n)                 (n&0x7fff)
/**@}*/

/* --- PWM_PRESCALER values ------------------------------------------------ */
/** @defgroup pwm_prescaler Set prescaler
@ingroup pwm_defines
@{*/
#define DIV_1                                        (0)
#define PWM_PRESCALER_PRESCALER_DIV_1                (0)
#define DIV_2                                        (1)
#define PWM_PRESCALER_PRESCALER_DIV_2                (1)
#define DIV_4                                        (2)
#define PWM_PRESCALER_PRESCALER_DIV_4                (2)
#define DIV_8                                        (3)
#define PWM_PRESCALER_PRESCALER_DIV_8                (3)
#define DIV_16                                       (4)
#define PWM_PRESCALER_PRESCALER_DIV_16               (4)
#define DIV_32                                       (5)
#define PWM_PRESCALER_PRESCALER_DIV_32               (5)
#define DIV_64                                       (6)
#define PWM_PRESCALER_PRESCALER_DIV_64               (6)
#define DIV_128                                      (7)
#define PWM_PRESCALER_PRESCALER_DIV_128              (7)
/**@}*/

/* --- PWM_DECODER values -------------------------------------------------- */
/** @defgroup pwm_decoder Decoder configuration
@ingroup pwm_defines
@{*/
#define LOAD_COMMON                                  (0)
#define PWM_DECODER_LOAD_COMMON                      (0)
#define PWM_DECODER_LOAD_Common                      (0)
#define LOAD_GROUPED                                 (1)
#define PWM_DECODER_LOAD_GROUPED                     (1)
#define PWM_DECODER_LOAD_Grouped                     (1)
#define LOAD_INDIVIDUAL                              (2)
#define PWM_DECODER_LOAD_INDIVIDUAL                  (2)
#define PWM_DECODER_LOAD_Individual                  (2)
#define LOAD_WAVEFORM                                (3)
#define PWM_DECODER_LOAD_WAVEFORM                    (3)
#define PWM_DECODER_LOAD_WaveForm                    (3)
#define MODE_REFRESHCOUNT                            (0 << 8)
#define PWM_DECODER_MODE_REFRESHCOUNT                (0 << 8)
#define PWM_DECODER_MODE_RefreshCount                (0 << 8)
#define MODE_NEXTSTEP                                (1 << 8)
#define PWM_DECODER_MODE_NEXTSTEP                    (1 << 8)
#define PWM_DECODER_MODE_NextStep                    (1 << 8)
/**@}*/

/* --- PWM_LOOP values ----------------------------------------------------- */
/** @defgroup pwm_loop Set amount of playback of a loop
@ingroup pwm_defines
@{*/
#define PWM_LOOP_CNT(n)                              (n)
#define PWM_LOOP_CNT_DISABLED                        (0)
#define PWM_LOOP_CNT_Disabled                        (0)
/**@}*/

/* --- PWM_SEQ[x].CNT values ----------------------------------------------- */
/** @defgroup pwm_seq_cnt Set amount of duty cycles in a sequence
@ingroup pwm_defines
@{*/
#define PWM_SEQ_CNT_CNT(n)                           (n)
#define PWM_SEQ_CNT_CNT_DISABLED                     (0)
#define PWM_SEQ_CNT_CNT_Disabled                     (0)
#define PWM_SEQ0_CNT_CNT_DISABLED                    (0)
#define PWM_SEQ0_CNT_CNT_Disabled                    (0)
#define PWM_SEQ1_CNT_CNT_DISABLED                    (0)
#define PWM_SEQ1_CNT_CNT_Disabled                    (0)
/**@}*/

/* --- PWM_SEQ[x].REFRESH values ------------------------------------------- */
/** @defgroup pwm_seq_refresh Set amount of additional PWM periodes between 
samples
@ingroup pwm_defines
@{*/
#define PWM_SEQ_REFRESH_CNT(n)                       (n)
#define REFRESH_CONTINUOUS                           (0)
#define PWM_SEQ_REFRESH_CNT_CONTINUOUS               (0)
#define PWM_SEQ_REFRESH_CNT_Continuous               (0)
#define PWM_SEQ0_REFRESH_CNT_CONTINUOUS              (0)
#define PWM_SEQ0_REFRESH_CNT_Continuous              (0)
#define PWM_SEQ1_REFRESH_CNT_CONTINUOUS              (0)
#define PWM_SEQ1_REFRESH_CNT_Continuous              (0)
/**@}*/

/* --- PWM_SEQ[x].ENDDELAY values ------------------------------------------ */
/** @defgroup pwm_seq_enddelay Set time added after the sequence
@ingroup pwm_defines
@{*/
#define PWM_SEQ_ENDDELAY_CNT(n)                       (n)

/**@}*/

/* --- PWM_PSEL.OUT[x] values ---------------------------------------------- */
/** @defgroup pwm_psel Output pin configuration for PWM channel
@ingroup pwm_defines
@{*/
#define PWM_PSEL_OUT_PIN(n)                          (n)
#define PWM_PSEL_OUT0_PIN(n)                         (n)
#define PWM_PSEL_OUT1_PIN(n)                         (n)
#define PWM_PSEL_OUT2_PIN(n)                         (n)
#define PWM_PSEL_OUT3_PIN(n)                         (n)
#define CONNECT_DISCONNECTED                         (1 << 31)
#define CONNECT_CONNECTED                            (0 << 31)
#define PWM_PSEL_OUT_CONNECT_DISCONNECTED            (1 << 31)
#define PWM_PSEL_OUT_CONNECT_Disconnected            (1 << 31)
#define PWM_PSEL_OUT_CONNECT_CONNECTED               (0 << 31)
#define PWM_PSEL_OUT_CONNECT_Connected               (0 << 31)
#define PWM_PSEL_OUT0_CONNECT_DISCONNECTED           (1 << 31)
#define PWM_PSEL_OUT0_CONNECT_Disconnected           (1 << 31)
#define PWM_PSEL_OUT0_CONNECT_CONNECTED              (0 << 31)
#define PWM_PSEL_OUT0_CONNECT_Connected              (0 << 31)
#define PWM_PSEL_OUT1_CONNECT_DISCONNECTED           (1 << 31)
#define PWM_PSEL_OUT1_CONNECT_Disconnected           (1 << 31)
#define PWM_PSEL_OUT1_CONNECT_CONNECTED              (0 << 31)
#define PWM_PSEL_OUT1_CONNECT_Connected              (0 << 31)
#define PWM_PSEL_OUT2_CONNECT_DISCONNECTED           (1 << 31)
#define PWM_PSEL_OUT2_CONNECT_Disconnected           (1 << 31)
#define PWM_PSEL_OUT2_CONNECT_CONNECTED              (0 << 31)
#define PWM_PSEL_OUT2_CONNECT_Connected              (0 << 31)
#define PWM_PSEL_OUT3_CONNECT_DISCONNECTED           (1 << 31)
#define PWM_PSEL_OUT3_CONNECT_Disconnected           (1 << 31)
#define PWM_PSEL_OUT3_CONNECT_CONNECTED              (0 << 31)
#define PWM_PSEL_OUT3_CONNECT_Connected              (0 << 31)
/**@}*/


/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void pwm_stop(uint32_t pwm);
void pwm_start_seq(uint32_t pwm, bool seq);
void pwm_nextstep(uint32_t pwm);
void pwm_prescaler(uint32_t pwm, uint32_t prescaler);
void pwm_counter_top(uint32_t pwm, uint16_t countertop);
void pwm_counter_mode(uint32_t pwm, uint32_t mode);
void pwm_decoder(uint32_t pwm, uint32_t load, uint32_t mode);
void pwm_loop(uint32_t pwm, uint16_t loop);
void pwm_sequence_config(uint32_t pwm, bool sequence, uint16_t *ptr, 
	uint16_t cnt, uint32_t refresh, uint32_t enddelay);
void pwm_output_pin(uint32_t pwm, uint8_t output, uint8_t pin, 
	uint32_t connect);
void pwm_enable(uint32_t pwm);
void pwm_disable(uint32_t pwm);
void pwm_interrupt_enable(uint32_t pwm, uint32_t events);
void pwm_interrupt_disable(uint32_t pwm, uint32_t events);
uint32_t pwm_sequence_end(uint32_t pwm, bool seq);
void pwm_sequence_end_reset(uint32_t pwm, bool seq);
uint32_t pwm_loop_done(uint32_t pwm);
void pwm_loop_done_reset(uint32_t pwm);

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "pwm_common.h should not be included explicitly, only via pwm.h"
#endif
/** @endcond */


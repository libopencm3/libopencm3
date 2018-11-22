/** @addtogroup saadc_defines SAADC Defines
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA SAADC.H
The order of header inclusion is important. saadc.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#if defined(LIBOPENCM3_SAADC_H)
/** @endcond */
#ifndef LIBOPENCM3_SAADC_COMMON_H
#define LIBOPENCM3_SAADC_COMMON_H

/** @defgroup saadc_registers SAADC Registers
 * @ingroup saadc_defines
 * @brief SAADC Registers
@{*/
/* --------------------- SAADC registers for NRF52 ------------------------- */

/* Tasks Registers */
#define SAADC_TASKS_START                     MMIO32((SAADC_BASE) + 0x000)
#define SAADC_TASKS_SAMPLE                    MMIO32((SAADC_BASE) + 0x004)
#define SAADC_TASKS_STOP                      MMIO32((SAADC_BASE) + 0x008)
#define SAADC_TASKS_CALIBRATEOFFSE            MMIO32((SAADC_BASE) + 0x00C)

/* Events Registers */
#define SAADC_EVENTS_STARTED                  MMIO32((SAADC_BASE) + 0x100)
#define SAADC_EVENTS_END                      MMIO32((SAADC_BASE) + 0x104)
#define SAADC_EVENTS_DONE                     MMIO32((SAADC_BASE) + 0x108)
#define SAADC_EVENTS_RESULTDONE               MMIO32((SAADC_BASE) + 0x10C)
#define SAADC_EVENTS_CALIBRATEDON             MMIO32((SAADC_BASE) + 0x110)
#define SAADC_EVENTS_STOPPED                  MMIO32((SAADC_BASE) + 0x114)

typedef struct {

        uint32_t LIMITH;
        uint32_t LIMITL;

} SAADC_EVENTS_CH_Type;

#define SAADC_EVENTS_CH   ((volatile SAADC_EVENTS_CH_Type *)((SAADC_BASE) + 0x118))

#define SAADC_EVENTS_CH_LIMITH                PTRIO64((SAADC_BASE) + 0x118)
#define SAADC_EVENTS_CH_LIMITL                PTRIO64((SAADC_BASE) + 0x11C)
#define SAADC_EVENTS_CH0_LIMITH               MMIO32((SAADC_BASE) + 0x118)
#define SAADC_EVENTS_CH0_LIMITL               MMIO32((SAADC_BASE) + 0x11C)
#define SAADC_EVENTS_CH1_LIMITH               MMIO32((SAADC_BASE) + 0x120)
#define SAADC_EVENTS_CH1_LIMITL               MMIO32((SAADC_BASE) + 0x124)
#define SAADC_EVENTS_CH2_LIMITH               MMIO32((SAADC_BASE) + 0x128)
#define SAADC_EVENTS_CH2_LIMITL               MMIO32((SAADC_BASE) + 0x12C)
#define SAADC_EVENTS_CH3_LIMITH               MMIO32((SAADC_BASE) + 0x130)
#define SAADC_EVENTS_CH3_LIMITL               MMIO32((SAADC_BASE) + 0x134)
#define SAADC_EVENTS_CH4_LIMITH               MMIO32((SAADC_BASE) + 0x138)
#define SAADC_EVENTS_CH4_LIMITL               MMIO32((SAADC_BASE) + 0x13C)
#define SAADC_EVENTS_CH5_LIMITH               MMIO32((SAADC_BASE) + 0x140)
#define SAADC_EVENTS_CH5_LIMITL               MMIO32((SAADC_BASE) + 0x144)
#define SAADC_EVENTS_CH6_LIMITH               MMIO32((SAADC_BASE) + 0x148)
#define SAADC_EVENTS_CH6_LIMITL               MMIO32((SAADC_BASE) + 0x14C)
#define SAADC_EVENTS_CH7_LIMITH               MMIO32((SAADC_BASE) + 0x150)
#define SAADC_EVENTS_CH7_LIMITL               MMIO32((SAADC_BASE) + 0x154)

/* Registers */
#define SAADC_INTEN                           MMIO32((SAADC_BASE) + 0x300)
#define SAADC_INTENSET                        MMIO32((SAADC_BASE) + 0x304)
#define SAADC_INTENCLR                        MMIO32((SAADC_BASE) + 0x308)
#define SAADC_STATUS                          MMIO32((SAADC_BASE) + 0x400)
#define SAADC_ENABLE                          MMIO32((SAADC_BASE) + 0x500)

struct SAADC_CH_TYPE{
	uint32_t PSELP;
	uint32_t PSELN;
	uint32_t CONFIG;
	uint32_t LIMIT;
};
#define SAADC_CH    ((volatile struct SAADC_CH_TYPE*)((SAADC_BASE) + 0x510))

#define SAADC_CH_PSELP(n)                  MMIO32((SAADC_BASE) + 0x510 + 4*n)
#define SAADC_CH_PSELN(n)                  MMIO32((SAADC_BASE) + 0x514 + 4*n)
#define SAADC_CH_CONFIG(n)                 MMIO32((SAADC_BASE) + 0x518 + 4*n)
#define SAADC_CH_LIMIT(n)                  MMIO32((SAADC_BASE) + 0x51C + 4*n)
#define SAADC_CH0_PSELP                    MMIO32((SAADC_BASE) + 0x510)
#define SAADC_CH0_PSELN                    MMIO32((SAADC_BASE) + 0x514)
#define SAADC_CH0_CONFIG                   MMIO32((SAADC_BASE) + 0x518)
#define SAADC_CH0_LIMIT                    MMIO32((SAADC_BASE) + 0x51C)
#define SAADC_CH1_PSELP                    MMIO32((SAADC_BASE) + 0x520)
#define SAADC_CH1_PSELN                    MMIO32((SAADC_BASE) + 0x524)
#define SAADC_CH1_CONFIG                   MMIO32((SAADC_BASE) + 0x528)
#define SAADC_CH1_LIMIT                    MMIO32((SAADC_BASE) + 0x52C)
#define SAADC_CH2_PSELP                    MMIO32((SAADC_BASE) + 0x530)
#define SAADC_CH2_PSELN                    MMIO32((SAADC_BASE) + 0x534)
#define SAADC_CH2_CONFIG                   MMIO32((SAADC_BASE) + 0x538)
#define SAADC_CH2_LIMIT                    MMIO32((SAADC_BASE) + 0x53C)
#define SAADC_CH3_PSELP                    MMIO32((SAADC_BASE) + 0x540)
#define SAADC_CH3_PSELN                    MMIO32((SAADC_BASE) + 0x544)
#define SAADC_CH3_CONFIG                   MMIO32((SAADC_BASE) + 0x548)
#define SAADC_CH3_LIMIT                    MMIO32((SAADC_BASE) + 0x54C)
#define SAADC_CH4_PSELP                    MMIO32((SAADC_BASE) + 0x550)
#define SAADC_CH4_PSELN                    MMIO32((SAADC_BASE) + 0x554)
#define SAADC_CH4_CONFIG                   MMIO32((SAADC_BASE) + 0x558)
#define SAADC_CH4_LIMIT                    MMIO32((SAADC_BASE) + 0x55C)
#define SAADC_CH5_PSELP                    MMIO32((SAADC_BASE) + 0x560)
#define SAADC_CH5_PSELN                    MMIO32((SAADC_BASE) + 0x564)
#define SAADC_CH5_CONFIG                   MMIO32((SAADC_BASE) + 0x568)
#define SAADC_CH5_LIMIT                    MMIO32((SAADC_BASE) + 0x56C)
#define SAADC_CH6_PSELP                    MMIO32((SAADC_BASE) + 0x570)
#define SAADC_CH6_PSELN                    MMIO32((SAADC_BASE) + 0x574)
#define SAADC_CH6_CONFIG                   MMIO32((SAADC_BASE) + 0x578)
#define SAADC_CH6_LIMIT                    MMIO32((SAADC_BASE) + 0x57C)
#define SAADC_CH7_PSELP                    MMIO32((SAADC_BASE) + 0x580)
#define SAADC_CH7_PSELN                    MMIO32((SAADC_BASE) + 0x584)
#define SAADC_CH7_CONFIG                   MMIO32((SAADC_BASE) + 0x588)
#define SAADC_CH7_LIMIT                    MMIO32((SAADC_BASE) + 0x58C)
#define SAADC_RESOLUTION                   MMIO32((SAADC_BASE) + 0x5F0)
#define SAADC_OVERSAMPLE                   MMIO32((SAADC_BASE) + 0x5F4)
#define SAADC_SAMPLERATE                   MMIO32((SAADC_BASE) + 0x5F8)

struct SAADC_RESULT_TYPE{
	uint32_t PTR;
	uint32_t MAXCNT;
	uint32_t AMOUNT;
};
#define SAADC_RESULT   (*(volatile struct SAADC_RESULT_TYPE*)((SAADC_BASE) + 0x62C))
#define SAADC_RESULT_PTR                   MMIO32((SAADC_BASE) + 0x62C)
#define SAADC_RESULT_MAXCNT                MMIO32((SAADC_BASE) + 0x630)
#define SAADC_RESULT_AMOUNT                MMIO32((SAADC_BASE) + 0x634)
/**@}*/

/* --- SAADC_INTEN values -------------------------------------------------- */
/** @defgroup saadc_inten Enable or disable interrupt
@ingroup saadc_defines
@{*/
#define SAADC_INTEN_STARTED_DISABLED                   (0 << 0)
#define SAADC_INTEN_STARTED_Disabled                   (0 << 0)
#define SAADC_INTEN_STARTED_ENABLED                    (1 << 0)
#define SAADC_INTEN_STARTED_Enabled                    (1 << 0)
#define SAADC_INTEN_END_DISABLED                       (0 << 1)
#define SAADC_INTEN_END_Disabled                       (0 << 1)
#define SAADC_INTEN_END_ENABLED                        (1 << 1)
#define SAADC_INTEN_END_Enabled                        (1 << 1)
#define SAADC_INTEN_DONE_DISABLED                      (0 << 2)
#define SAADC_INTEN_DONE_Disabled                      (0 << 2)
#define SAADC_INTEN_DONE_ENABLED                       (1 << 2)
#define SAADC_INTEN_DONE_Enabled                       (1 << 2)
#define SAADC_INTEN_RESULTDONE_DISABLED                (0 << 3)
#define SAADC_INTEN_RESULTDONE_Disabled                (0 << 3)
#define SAADC_INTEN_RESULTDONE_ENABLED                 (1 << 3)
#define SAADC_INTEN_RESULTDONE_Enabled                 (1 << 3)
#define SAADC_INTEN_CALIBRATEDONE_DISABLED             (0 << 4)
#define SAADC_INTEN_CALIBRATEDONE_Disabled             (0 << 4)
#define SAADC_INTEN_CALIBRATEDONE_ENABLED              (1 << 4)
#define SAADC_INTEN_CALIBRATEDONE_Enabled              (1 << 4)
#define SAADC_INTEN_STOPPED_DISABLED                   (0 << 5)
#define SAADC_INTEN_STOPPED_Disabled                   (0 << 5)
#define SAADC_INTEN_STOPPED_ENABLED                    (1 << 5)
#define SAADC_INTEN_STOPPED_Enabled                    (1 << 5)
#define SAADC_INTEN_CHLIMITH_DISABLED(n)               (0 << (6+2*n))
#define SAADC_INTEN_CHLIMITH_Disabled(n)               (0 << (6+2*n))
#define SAADC_INTEN_CHLIMITH_ENABLED(n)                (1 << (6+2*n))
#define SAADC_INTEN_CHLIMITH_Enabled(n)                (1 << (6+2*n))
#define SAADC_INTEN_CHLIMITL_DISABLED(n)               (0 << (7+2*n))
#define SAADC_INTEN_CHLIMITL_Disabled(n)               (0 << (7+2*n))
#define SAADC_INTEN_CHLIMITL_ENABLED(n)                (1 << (7+2*n))
#define SAADC_INTEN_CHLIMITL_Enabled(n)                (1 << (7+2*n))
#define SAADC_INTEN_CH0LIMITH_DISABLED                 (0 << 6)
#define SAADC_INTEN_CH0LIMITH_Disabled                 (0 << 6)
#define SAADC_INTEN_CH0LIMITH_ENABLED                  (1 << 6)
#define SAADC_INTEN_CH0LIMITH_Enabled                  (1 << 6)
#define SAADC_INTEN_CH0LIMITL_DISABLED                 (0 << 7)
#define SAADC_INTEN_CH0LIMITL_Disabled                 (0 << 7)
#define SAADC_INTEN_CH0LIMITL_ENABLED                  (1 << 7)
#define SAADC_INTEN_CH0LIMITL_Enabled                  (1 << 7)
#define SAADC_INTEN_CH1LIMITH_DISABLED                 (0 << 8)
#define SAADC_INTEN_CH1LIMITH_Disabled                 (0 << 8)
#define SAADC_INTEN_CH1LIMITH_ENABLED                  (1 << 8)
#define SAADC_INTEN_CH1LIMITH_Enabled                  (1 << 8)
#define SAADC_INTEN_CH1LIMITL_DISABLED                 (0 << 9)
#define SAADC_INTEN_CH1LIMITL_Disabled                 (0 << 9)
#define SAADC_INTEN_CH1LIMITL_ENABLED                  (1 << 9)
#define SAADC_INTEN_CH1LIMITL_Enabled                  (1 << 9)
#define SAADC_INTEN_CH2LIMITH_DISABLED                 (0 << 10)
#define SAADC_INTEN_CH2LIMITH_Disabled                 (0 << 10)
#define SAADC_INTEN_CH2LIMITH_ENABLED                  (1 << 10)
#define SAADC_INTEN_CH2LIMITH_Enabled                  (1 << 10)
#define SAADC_INTEN_CH2LIMITL_DISABLED                 (0 << 11)
#define SAADC_INTEN_CH2LIMITL_Disabled                 (0 << 11)
#define SAADC_INTEN_CH2LIMITL_ENABLED                  (1 << 11)
#define SAADC_INTEN_CH2LIMITL_Enabled                  (1 << 11)
#define SAADC_INTEN_CH3LIMITH_DISABLED                 (0 << 12)
#define SAADC_INTEN_CH3LIMITH_Disabled                 (0 << 12)
#define SAADC_INTEN_CH3LIMITH_ENABLED                  (1 << 12)
#define SAADC_INTEN_CH3LIMITH_Enabled                  (1 << 12)
#define SAADC_INTEN_CH3LIMITL_DISABLED                 (0 << 13)
#define SAADC_INTEN_CH3LIMITL_Disabled                 (0 << 13)
#define SAADC_INTEN_CH3LIMITL_ENABLED                  (1 << 13)
#define SAADC_INTEN_CH3LIMITL_Enabled                  (1 << 13)
#define SAADC_INTEN_CH4LIMITH_DISABLED                 (0 << 14)
#define SAADC_INTEN_CH4LIMITH_Disabled                 (0 << 14)
#define SAADC_INTEN_CH4LIMITH_ENABLED                  (1 << 14)
#define SAADC_INTEN_CH4LIMITH_Enabled                  (1 << 14)
#define SAADC_INTEN_CH4LIMITL_DISABLED                 (0 << 15)
#define SAADC_INTEN_CH4LIMITL_Disabled                 (0 << 15)
#define SAADC_INTEN_CH4LIMITL_ENABLED                  (1 << 15)
#define SAADC_INTEN_CH4LIMITL_Enabled                  (1 << 15)
#define SAADC_INTEN_CH5LIMITH_DISABLED                 (0 << 16)
#define SAADC_INTEN_CH5LIMITH_Disabled                 (0 << 16)
#define SAADC_INTEN_CH5LIMITH_ENABLED                  (1 << 16)
#define SAADC_INTEN_CH5LIMITH_Enabled                  (1 << 16)
#define SAADC_INTEN_CH5LIMITL_DISABLED                 (0 << 17)
#define SAADC_INTEN_CH5LIMITL_Disabled                 (0 << 17)
#define SAADC_INTEN_CH5LIMITL_ENABLED                  (1 << 17)
#define SAADC_INTEN_CH5LIMITL_Enabled                  (1 << 17)
#define SAADC_INTEN_CH6LIMITH_DISABLED                 (0 << 18)
#define SAADC_INTEN_CH6LIMITH_Disabled                 (0 << 18)
#define SAADC_INTEN_CH6LIMITH_ENABLED                  (1 << 18)
#define SAADC_INTEN_CH6LIMITH_Enabled                  (1 << 18)
#define SAADC_INTEN_CH6LIMITL_DISABLED                 (0 << 19)
#define SAADC_INTEN_CH6LIMITL_Disabled                 (0 << 19)
#define SAADC_INTEN_CH6LIMITL_ENABLED                  (1 << 19)
#define SAADC_INTEN_CH6LIMITL_Enabled                  (1 << 19)
#define SAADC_INTEN_CH7LIMITH_DISABLED                 (0 << 20)
#define SAADC_INTEN_CH7LIMITH_Disabled                 (0 << 20)
#define SAADC_INTEN_CH7LIMITH_ENABLED                  (1 << 20)
#define SAADC_INTEN_CH7LIMITH_Enabled                  (1 << 20)
#define SAADC_INTEN_CH7LIMITL_DISABLED                 (0 << 21)
#define SAADC_INTEN_CH7LIMITL_Disabled                 (0 << 21)
#define SAADC_INTEN_CH7LIMITL_ENABLED                  (1 << 21)
#define SAADC_INTEN_CH7LIMITL_Enabled                  (1 << 21)
/**@}*/

/* --- SAADC_INTENSET values ----------------------------------------------- */
/** @defgroup saadc_intenset Enable interrupt
@ingroup saadc_defines
@{*/
#define SAADC_INTENSET_STARTED_SET                     (1 << 0)
#define SAADC_INTENSET_STARTED_Set                     (1 << 0)
#define SAADC_INTENSET_STARTED_ENABLED                 (1 << 0)
#define SAADC_INTENSET_STARTED_Enabled                 (1 << 0)
#define SAADC_INTENSET_END_SET                         (1 << 1)
#define SAADC_INTENSET_END_Set                         (1 << 1)
#define SAADC_INTENSET_END_ENABLED                     (1 << 1)
#define SAADC_INTENSET_END_Enabled                     (1 << 1)
#define SAADC_INTENSET_DONE_SET                        (1 << 2)
#define SAADC_INTENSET_DONE_Set                        (1 << 2)
#define SAADC_INTENSET_DONE_ENABLED                    (1 << 2)
#define SAADC_INTENSET_DONE_Enabled                    (1 << 2)
#define SAADC_INTENSET_RESULTDONE_SET                  (1 << 3)
#define SAADC_INTENSET_RESULTDONE_Set                  (1 << 3)
#define SAADC_INTENSET_RESULTDONE_ENABLED              (1 << 3)
#define SAADC_INTENSET_RESULTDONE_Enabled              (1 << 3)
#define SAADC_INTENSET_CALIBRATEDONE_SET               (1 << 4)
#define SAADC_INTENSET_CALIBRATEDONE_Set               (1 << 4)
#define SAADC_INTENSET_CALIBRATEDONE_ENABLED           (1 << 4)
#define SAADC_INTENSET_CALIBRATEDONE_Enabled           (1 << 4)
#define SAADC_INTENSET_STOPPED_SET                     (1 << 5)
#define SAADC_INTENSET_STOPPED_Set                     (1 << 5)
#define SAADC_INTENSET_STOPPED_ENABLED                 (1 << 5)
#define SAADC_INTENSET_STOPPED_Enabled                 (1 << 5)
#define SAADC_INTENSET_CHLIMITH_SET(n)                 (1 << (6+2*n))
#define SAADC_INTENSET_CHLIMITH_Set(n)                 (1 << (6+2*n))
#define SAADC_INTENSET_CHLIMITH_ENABLED(n)             (1 << (6+2*n))
#define SAADC_INTENSET_CHLIMITH_Enabled(n)             (1 << (6+2*n))
#define SAADC_INTENSET_CHLIMITL_SET(n)                 (1 << (7+2*n))
#define SAADC_INTENSET_CHLIMITL_Set(n)                 (1 << (7+2*n))
#define SAADC_INTENSET_CHLIMITL_ENABLED(n)             (1 << (7+2*n))
#define SAADC_INTENSET_CHLIMITL_Enabled(n)             (1 << (7+2*n))
#define SAADC_INTENSET_CH0LIMITH_SET                   (1 << 6)
#define SAADC_INTENSET_CH0LIMITH_Set                   (1 << 6)
#define SAADC_INTENSET_CH0LIMITH_ENABLED               (1 << 6)
#define SAADC_INTENSET_CH0LIMITH_Enabled               (1 << 6)
#define SAADC_INTENSET_CH0LIMITL_SET                   (1 << 7)
#define SAADC_INTENSET_CH0LIMITL_Set                   (1 << 7)
#define SAADC_INTENSET_CH0LIMITL_ENABLED               (1 << 7)
#define SAADC_INTENSET_CH0LIMITL_Enabled               (1 << 7)
#define SAADC_INTENSET_CH1LIMITH_SET                   (1 << 8)
#define SAADC_INTENSET_CH1LIMITH_Set                   (1 << 8)
#define SAADC_INTENSET_CH1LIMITH_ENABLED               (1 << 8)
#define SAADC_INTENSET_CH1LIMITH_Enabled               (1 << 8)
#define SAADC_INTENSET_CH1LIMITL_SET                   (1 << 9)
#define SAADC_INTENSET_CH1LIMITL_Set                   (1 << 9)
#define SAADC_INTENSET_CH1LIMITL_ENABLED               (1 << 9)
#define SAADC_INTENSET_CH1LIMITL_Enabled               (1 << 9)
#define SAADC_INTENSET_CH2LIMITH_SET                   (1 << 10)
#define SAADC_INTENSET_CH2LIMITH_Set                   (1 << 10)
#define SAADC_INTENSET_CH2LIMITH_ENABLED               (1 << 10)
#define SAADC_INTENSET_CH2LIMITH_Enabled               (1 << 10)
#define SAADC_INTENSET_CH2LIMITL_SET                   (1 << 11)
#define SAADC_INTENSET_CH2LIMITL_Set                   (1 << 11)
#define SAADC_INTENSET_CH2LIMITL_ENABLED               (1 << 11)
#define SAADC_INTENSET_CH2LIMITL_Enabled               (1 << 11)
#define SAADC_INTENSET_CH3LIMITH_SET                   (1 << 12)
#define SAADC_INTENSET_CH3LIMITH_Set                   (1 << 12)
#define SAADC_INTENSET_CH3LIMITH_ENABLED               (1 << 12)
#define SAADC_INTENSET_CH3LIMITH_Enabled               (1 << 12)
#define SAADC_INTENSET_CH3LIMITL_SET                   (1 << 13)
#define SAADC_INTENSET_CH3LIMITL_Set                   (1 << 13)
#define SAADC_INTENSET_CH3LIMITL_ENABLED               (1 << 13)
#define SAADC_INTENSET_CH3LIMITL_Enabled               (1 << 13)
#define SAADC_INTENSET_CH4LIMITH_SET                   (1 << 14)
#define SAADC_INTENSET_CH4LIMITH_Set                   (1 << 14)
#define SAADC_INTENSET_CH4LIMITH_ENABLED               (1 << 14)
#define SAADC_INTENSET_CH4LIMITH_Enabled               (1 << 14)
#define SAADC_INTENSET_CH4LIMITL_SET                   (1 << 15)
#define SAADC_INTENSET_CH4LIMITL_Set                   (1 << 15)
#define SAADC_INTENSET_CH4LIMITL_ENABLED               (1 << 15)
#define SAADC_INTENSET_CH4LIMITL_Enabled               (1 << 15)
#define SAADC_INTENSET_CH5LIMITH_SET                   (1 << 16)
#define SAADC_INTENSET_CH5LIMITH_Set                   (1 << 16)
#define SAADC_INTENSET_CH5LIMITH_ENABLED               (1 << 16)
#define SAADC_INTENSET_CH5LIMITH_Enabled               (1 << 16)
#define SAADC_INTENSET_CH5LIMITL_SET                   (1 << 17)
#define SAADC_INTENSET_CH5LIMITL_Set                   (1 << 17)
#define SAADC_INTENSET_CH5LIMITL_ENABLED               (1 << 17)
#define SAADC_INTENSET_CH5LIMITL_Enabled               (1 << 17)
#define SAADC_INTENSET_CH6LIMITH_SET                   (1 << 18)
#define SAADC_INTENSET_CH6LIMITH_Set                   (1 << 18)
#define SAADC_INTENSET_CH6LIMITH_ENABLED               (1 << 18)
#define SAADC_INTENSET_CH6LIMITH_Enabled               (1 << 18)
#define SAADC_INTENSET_CH6LIMITL_SET                   (1 << 19)
#define SAADC_INTENSET_CH6LIMITL_Set                   (1 << 19)
#define SAADC_INTENSET_CH6LIMITL_ENABLED               (1 << 19)
#define SAADC_INTENSET_CH6LIMITL_Enabled               (1 << 19)
#define SAADC_INTENSET_CH7LIMITH_SET                   (1 << 20)
#define SAADC_INTENSET_CH7LIMITH_Set                   (1 << 20)
#define SAADC_INTENSET_CH7LIMITH_ENABLED               (1 << 20)
#define SAADC_INTENSET_CH7LIMITH_Enabled               (1 << 20)
#define SAADC_INTENSET_CH7LIMITL_SET                   (1 << 21)
#define SAADC_INTENSET_CH7LIMITL_Set                   (1 << 21)
#define SAADC_INTENSET_CH7LIMITL_ENABLED               (1 << 21)
#define SAADC_INTENSET_CH7LIMITL_Enabled               (1 << 21)
/**@}*/

/* --- SAADC_INTENCLR values ----------------------------------------------- */
/** @defgroup saadc_intenclr Disable interrupt
@ingroup saadc_defines
@{*/
#define SAADC_INTENCLR_STARTED_CLEAR                   (1 << 0)
#define SAADC_INTENCLR_STARTED_Clear                   (1 << 0)
#define SAADC_INTENCLR_STARTED_ENABLED                 (1 << 0)
#define SAADC_INTENCLR_STARTED_Enabled                 (1 << 0)
#define SAADC_INTENCLR_END_CLEAR                       (1 << 1)
#define SAADC_INTENCLR_END_Clear                       (1 << 1)
#define SAADC_INTENCLR_END_ENABLED                     (1 << 1)
#define SAADC_INTENCLR_END_Enabled                     (1 << 1)
#define SAADC_INTENCLR_DONE_CLEAR                      (1 << 2)
#define SAADC_INTENCLR_DONE_Clear                      (1 << 2)
#define SAADC_INTENCLR_DONE_ENABLED                    (1 << 2)
#define SAADC_INTENCLR_DONE_Enabled                    (1 << 2)
#define SAADC_INTENCLR_RESULTDONE_CLEAR                (1 << 3)
#define SAADC_INTENCLR_RESULTDONE_Clear                (1 << 3)
#define SAADC_INTENCLR_RESULTDONE_ENABLED              (1 << 3)
#define SAADC_INTENCLR_RESULTDONE_Enabled              (1 << 3)
#define SAADC_INTENCLR_CALIBRATEDONE_CLEAR             (1 << 4)
#define SAADC_INTENCLR_CALIBRATEDONE_Clear             (1 << 4)
#define SAADC_INTENCLR_CALIBRATEDONE_ENABLED           (1 << 4)
#define SAADC_INTENCLR_CALIBRATEDONE_Enabled           (1 << 4)
#define SAADC_INTENCLR_STOPPED_CLEAR                   (1 << 5)
#define SAADC_INTENCLR_STOPPED_Clear                   (1 << 5)
#define SAADC_INTENCLR_STOPPED_ENABLED                 (1 << 5)
#define SAADC_INTENCLR_STOPPED_Enabled                 (1 << 5)
#define SAADC_INTENCLR_CHLIMITH_CLEAR(n)               (1 << (6+2*n))
#define SAADC_INTENCLR_CHLIMITH_Clear(n)               (1 << (6+2*n))
#define SAADC_INTENCLR_CHLIMITH_ENABLED(n)             (1 << (6+2*n))
#define SAADC_INTENCLR_CHLIMITH_Enabled(n)             (1 << (6+2*n))
#define SAADC_INTENCLR_CHLIMITL_CLEAR(n)               (1 << (7+2*n))
#define SAADC_INTENCLR_CHLIMITL_Clear(n)               (1 << (7+2*n))
#define SAADC_INTENCLR_CHLIMITL_ENABLED(n)             (1 << (7+2*n))
#define SAADC_INTENCLR_CHLIMITL_Enabled(n)             (1 << (7+2*n))
#define SAADC_INTENCLR_CH0LIMITH_CLEAR                 (1 << 6)
#define SAADC_INTENCLR_CH0LIMITH_Clear                 (1 << 6)
#define SAADC_INTENCLR_CH0LIMITH_ENABLED               (1 << 6)
#define SAADC_INTENCLR_CH0LIMITH_Enabled               (1 << 6)
#define SAADC_INTENCLR_CH0LIMITL_CLEAR                 (1 << 7)
#define SAADC_INTENCLR_CH0LIMITL_Clear                 (1 << 7)
#define SAADC_INTENCLR_CH0LIMITL_ENABLED               (1 << 7)
#define SAADC_INTENCLR_CH0LIMITL_Enabled               (1 << 7)
#define SAADC_INTENCLR_CH1LIMITH_CLEAR                 (1 << 8)
#define SAADC_INTENCLR_CH1LIMITH_Clear                 (1 << 8)
#define SAADC_INTENCLR_CH1LIMITH_ENABLED               (1 << 8)
#define SAADC_INTENCLR_CH1LIMITH_Enabled               (1 << 8)
#define SAADC_INTENCLR_CH1LIMITL_CLEAR                 (1 << 9)
#define SAADC_INTENCLR_CH1LIMITL_Clear                 (1 << 9)
#define SAADC_INTENCLR_CH1LIMITL_ENABLED               (1 << 9)
#define SAADC_INTENCLR_CH1LIMITL_Enabled               (1 << 9)
#define SAADC_INTENCLR_CH2LIMITH_CLEAR                 (1 << 10)
#define SAADC_INTENCLR_CH2LIMITH_Clear                 (1 << 10)
#define SAADC_INTENCLR_CH2LIMITH_ENABLED               (1 << 10)
#define SAADC_INTENCLR_CH2LIMITH_Enabled               (1 << 10)
#define SAADC_INTENCLR_CH2LIMITL_CLEAR                 (1 << 11)
#define SAADC_INTENCLR_CH2LIMITL_Clear                 (1 << 11)
#define SAADC_INTENCLR_CH2LIMITL_ENABLED               (1 << 11)
#define SAADC_INTENCLR_CH2LIMITL_Enabled               (1 << 11)
#define SAADC_INTENCLR_CH3LIMITH_CLEAR                 (1 << 12)
#define SAADC_INTENCLR_CH3LIMITH_Clear                 (1 << 12)
#define SAADC_INTENCLR_CH3LIMITH_ENABLED               (1 << 12)
#define SAADC_INTENCLR_CH3LIMITH_Enabled               (1 << 12)
#define SAADC_INTENCLR_CH3LIMITL_CLEAR                 (1 << 13)
#define SAADC_INTENCLR_CH3LIMITL_Clear                 (1 << 13)
#define SAADC_INTENCLR_CH3LIMITL_ENABLED               (1 << 13)
#define SAADC_INTENCLR_CH3LIMITL_Enabled               (1 << 13)
#define SAADC_INTENCLR_CH4LIMITH_CLEAR                 (1 << 14)
#define SAADC_INTENCLR_CH4LIMITH_Clear                 (1 << 14)
#define SAADC_INTENCLR_CH4LIMITH_ENABLED               (1 << 14)
#define SAADC_INTENCLR_CH4LIMITH_Enabled               (1 << 14)
#define SAADC_INTENCLR_CH4LIMITL_CLEAR                 (1 << 15)
#define SAADC_INTENCLR_CH4LIMITL_Clear                 (1 << 15)
#define SAADC_INTENCLR_CH4LIMITL_ENABLED               (1 << 15)
#define SAADC_INTENCLR_CH4LIMITL_Enabled               (1 << 15)
#define SAADC_INTENCLR_CH5LIMITH_CLEAR                 (1 << 16)
#define SAADC_INTENCLR_CH5LIMITH_Clear                 (1 << 16)
#define SAADC_INTENCLR_CH5LIMITH_ENABLED               (1 << 16)
#define SAADC_INTENCLR_CH5LIMITH_Enabled               (1 << 16)
#define SAADC_INTENCLR_CH5LIMITL_CLEAR                 (1 << 17)
#define SAADC_INTENCLR_CH5LIMITL_Clear                 (1 << 17)
#define SAADC_INTENCLR_CH5LIMITL_ENABLED               (1 << 17)
#define SAADC_INTENCLR_CH5LIMITL_Enabled               (1 << 17)
#define SAADC_INTENCLR_CH6LIMITH_CLEAR                 (1 << 18)
#define SAADC_INTENCLR_CH6LIMITH_Clear                 (1 << 18)
#define SAADC_INTENCLR_CH6LIMITH_ENABLED               (1 << 18)
#define SAADC_INTENCLR_CH6LIMITH_Enabled               (1 << 18)
#define SAADC_INTENCLR_CH6LIMITL_CLEAR                 (1 << 19)
#define SAADC_INTENCLR_CH6LIMITL_Clear                 (1 << 19)
#define SAADC_INTENCLR_CH6LIMITL_ENABLED               (1 << 19)
#define SAADC_INTENCLR_CH6LIMITL_Enabled               (1 << 19)
#define SAADC_INTENCLR_CH7LIMITH_CLEAR                 (1 << 20)
#define SAADC_INTENCLR_CH7LIMITH_Clear                 (1 << 20)
#define SAADC_INTENCLR_CH7LIMITH_ENABLED               (1 << 20)
#define SAADC_INTENCLR_CH7LIMITH_Enabled               (1 << 20)
#define SAADC_INTENCLR_CH7LIMITL_CLEAR                 (1 << 21)
#define SAADC_INTENCLR_CH7LIMITL_Clear                 (1 << 21)
#define SAADC_INTENCLR_CH7LIMITL_ENABLED               (1 << 21)
#define SAADC_INTENCLR_CH7LIMITL_Enabled               (1 << 21)
/**@}*/

/* --- SAADC_STATUS values ------------------------------------------------- */
/** @defgroup saadc_status ADC Status
@ingroup saadc_defines
@{*/
#define SAADC_STATUS_STATUS_READY                      (0)
#define SAADC_STATUS_STATUS_Ready                      (0)
#define SAADC_STATUS_STATUS_BUSY                       (1)
#define SAADC_STATUS_STATUS_Busy                       (1)
/**@}*/

/* --- SAADC_ENABLE values ------------------------------------------------- */
/** @defgroup saadc_enable Enable SAADC
@ingroup saadc_defines
@{*/
#define SAADC_ENABLE_ENABLE_DISABLED                   (0)
#define SAADC_ENABLE_ENABLE_Disabled                   (0)
#define SAADC_ENABLE_ENABLE_ENABLED                    (1)
#define SAADC_ENABLE_ENABLE_Enabled                    (1)
/**@}*/

/* ------------------------------------------------------------------------- */
/* SAADC Pin definitions (for convenience) */
/** @defgroup saadc_pin_id SAADC Pin Identifiers
@ingroup saadc_defines
@{*/
#define NC                                            (0)
#define AIN0                                          (1)
#define AIN1                                          (2)
#define AIN2                                          (3)
#define AIN3                                          (4)
#define AIN4                                          (5)
#define AIN5                                          (6)
#define AIN6                                          (7)
#define AIN7                                          (8)
#define VDD                                           (9)
/**@}*/

/* --- SAADC_CH[x].PSELP values -------------------------------------------- */
/** @defgroup saadc_ch_pselp Select positive pin
@ingroup saadc_defines
@{*/
#define SAADC_CH_PSELP_PSELP_NC                       (0)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT0             (1)
#define SAADC_CH_PSELP_PSELP_AnalogInput0             (1)
#define SAADC_CH_PSELP_PSELP_AIN0                     (1)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT1             (2)
#define SAADC_CH_PSELP_PSELP_AnalogInput1             (2)
#define SAADC_CH_PSELP_PSELP_AIN1                     (2)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT2             (3)
#define SAADC_CH_PSELP_PSELP_AnalogInput2             (3)
#define SAADC_CH_PSELP_PSELP_AIN2                     (3)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT3             (4)
#define SAADC_CH_PSELP_PSELP_AnalogInput3             (4)
#define SAADC_CH_PSELP_PSELP_AIN3                     (4)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT4             (5)
#define SAADC_CH_PSELP_PSELP_AnalogInput4             (5)
#define SAADC_CH_PSELP_PSELP_AIN4                     (5)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT5             (6)
#define SAADC_CH_PSELP_PSELP_AnalogInput5             (6)
#define SAADC_CH_PSELP_PSELP_AIN5                     (6)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT6             (7)
#define SAADC_CH_PSELP_PSELP_AnalogInput6             (7)
#define SAADC_CH_PSELP_PSELP_AIN6                     (7)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT7             (8)
#define SAADC_CH_PSELP_PSELP_AnalogInput7             (8)
#define SAADC_CH_PSELP_PSELP_AIN7                     (8)
#define SAADC_CH_PSELP_PSELP_VDD                      (9)
/**@}*/

/* --- SAADC_CH[x].PSELN values -------------------------------------------- */
/** @defgroup saadc_ch_pseln Select negative pin
@ingroup saadc_defines
@{*/
#define SAADC_CH_PSELN_PSELN_NC                       (0)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT0             (1)
#define SAADC_CH_PSELN_PSELN_AnalogInput0             (1)
#define SAADC_CH_PSELN_PSELN_AIN0                     (1)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT1             (2)
#define SAADC_CH_PSELN_PSELN_AnalogInput1             (2)
#define SAADC_CH_PSELN_PSELN_AIN1                     (2)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT2             (3)
#define SAADC_CH_PSELN_PSELN_AnalogInput2             (3)
#define SAADC_CH_PSELN_PSELN_AIN2                     (3)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT3             (4)
#define SAADC_CH_PSELN_PSELN_AnalogInput3             (4)
#define SAADC_CH_PSELN_PSELN_AIN3                     (4)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT4             (5)
#define SAADC_CH_PSELN_PSELN_AnalogInput4             (5)
#define SAADC_CH_PSELN_PSELN_AIN4                     (5)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT5             (6)
#define SAADC_CH_PSELN_PSELN_AnalogInput5             (6)
#define SAADC_CH_PSELN_PSELN_AIN5                     (6)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT6             (7)
#define SAADC_CH_PSELN_PSELN_AnalogInput6             (7)
#define SAADC_CH_PSELN_PSELN_AIN6                     (7)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT7             (8)
#define SAADC_CH_PSELN_PSELN_AnalogInput7             (8)
#define SAADC_CH_PSELN_PSELN_AIN7                     (8)
#define SAADC_CH_PSELN_PSELN_VDD                      (9)
/**@}*/

/* --- SAADC_CH[x].CONFIG values ------------------------------------------- */
/** @defgroup saadc_ch_config Pin configuration
@ingroup saadc_defines
@{*/
#define RESP_BYPASS                                   (0 << 0)
#define SAADC_CH_CONFIG_RESP_BYPASS                   (0 << 0)
#define SAADC_CH_CONFIG_RESP_Bypass                   (0 << 0)
#define RESP_PULLDOWN                                 (1 << 0)
#define SAADC_CH_CONFIG_RESP_PULLDOWN                 (1 << 0)
#define SAADC_CH_CONFIG_RESP_Pulldown                 (1 << 0)
#define RESP_PULLUP                                   (0x2 << 0)
#define SAADC_CH_CONFIG_RESP_PULLUP                   (0x2 << 0)
#define SAADC_CH_CONFIG_RESP_Pullup                   (0x2 << 0)
#define RESP_VDD1_2                                   (0x3 << 0)
#define SAADC_CH_CONFIG_RESP_VDD1_2                   (0x3 << 0)
#define RESN_BYPASS                                   (0 << 4)
#define SAADC_CH_CONFIG_RESN_BYPASS                   (0 << 4)
#define SAADC_CH_CONFIG_RESN_Bypass                   (0 << 4)
#define RESN_PULLDOWN                                 (1 << 4)
#define SAADC_CH_CONFIG_RESN_PULLDOWN                 (1 << 4)
#define SAADC_CH_CONFIG_RESN_Pulldown                 (1 << 4)
#define RESN_PULLUP                                   (0x2 << 4)
#define SAADC_CH_CONFIG_RESN_PULLUP                   (0x2 << 4)
#define SAADC_CH_CONFIG_RESN_Pullup                   (0x2 << 4)
#define RESN_VDD1_2                                   (0x3 << 4)
#define SAADC_CH_CONFIG_RESN_VDD1_2                   (0x3 << 4)
#define GAIN1_6                                       (0 << 8)
#define SAADC_CH_CONFIG_GAIN_GAIN1_6                  (0 << 8)
#define SAADC_CH_CONFIG_GAIN_Gain1_6                  (0 << 8)
#define GAIN1_5                                       (1 << 8)
#define SAADC_CH_CONFIG_GAIN_GAIN1_5                  (1 << 8)
#define SAADC_CH_CONFIG_GAIN_Gain1_5                  (1 << 8)
#define GAIN1_4                                       (0x2 << 8)
#define SAADC_CH_CONFIG_GAIN_GAIN1_4                  (0x2 << 8)
#define SAADC_CH_CONFIG_GAIN_Gain1_4                  (0x2 << 8)
#define GAIN1_3                                       (0x3 << 8)
#define SAADC_CH_CONFIG_GAIN_GAIN1_3                  (0x3 << 8)
#define SAADC_CH_CONFIG_GAIN_Gain1_3                  (0x3 << 8)
#define GAIN1_2                                       (0x4 << 8)
#define SAADC_CH_CONFIG_GAIN_GAIN1_2                  (0x4 << 8)
#define SAADC_CH_CONFIG_GAIN_Gain1_2                  (0x4 << 8)
#define GAIN1                                         (0x5 << 8)
#define SAADC_CH_CONFIG_GAIN_GAIN1                    (0x5 << 8)
#define SAADC_CH_CONFIG_GAIN_Gain1                    (0x5 << 8)
#define GAIN2                                         (0x6 << 8)
#define SAADC_CH_CONFIG_GAIN_GAIN2                    (0x6 << 8)
#define SAADC_CH_CONFIG_GAIN_Gain2                    (0x6 << 8)
#define GAIN4                                         (0x7 << 8)
#define SAADC_CH_CONFIG_GAIN_GAIN4                    (0x7 << 8)
#define SAADC_CH_CONFIG_GAIN_Gain4                    (0x7 << 8)
#define REFSEL_INTERNAL                               (0 << 12)
#define SAADC_CH_CONFIG_REFSEL_INTERNAL               (0 << 12)
#define SAADC_CH_CONFIG_REFSEL_Internal               (0 << 12)
#define REFSEL_VDD1_4                                 (1 << 12)
#define SAADC_CH_CONFIG_REFSEL_VDD1_4                 (1 << 12)
#define TACQ_3US                                      (0 << 16)
#define SAADC_CH_CONFIG_TACQ_3US                      (0 << 16)
#define SAADC_CH_CONFIG_TACQ_3us                      (0 << 16)
#define TACQ_5US                                      (1 << 16)
#define SAADC_CH_CONFIG_TACQ_5US                      (1 << 16)
#define SAADC_CH_CONFIG_TACQ_5us                      (1 << 16)
#define TACQ_10US                                     (0x2 << 16)
#define SAADC_CH_CONFIG_TACQ_10US                     (0x2 << 16)
#define SAADC_CH_CONFIG_TACQ_10us                     (0x2 << 16)
#define TACQ_15US                                     (0x3 << 16)
#define SAADC_CH_CONFIG_TACQ_15US                     (0x3 << 16)
#define SAADC_CH_CONFIG_TACQ_15us                     (0x3 << 16)
#define TACQ_20US                                     (0x4 << 16)
#define SAADC_CH_CONFIG_TACQ_20US                     (0x4 << 16)
#define SAADC_CH_CONFIG_TACQ_20us                     (0x4 << 16)
#define TACQ_40US                                     (0x5 << 16)
#define SAADC_CH_CONFIG_TACQ_40US                     (0x5 << 16)
#define SAADC_CH_CONFIG_TACQ_40us                     (0x5 << 16)
#define MODE_SE                                       (0 << 16)
#define SAADC_CH_CONFIG_MODE_SE                       (0 << 20)
#define MODE_DIFF                                     (1 << 20)
#define SAADC_CH_CONFIG_MODE_DIFF                     (1 << 20)
#define SAADC_CH_CONFIG_MODE_Diff                     (1 << 20)
#define SAADC_CH_CONFIG_BURST_DISABLED                (0 << 24)
#define SAADC_CH_CONFIG_BURST_Disabled                (0 << 24)
#define SAADC_CH_CONFIG_BURST_ENABLED                 (1 << 24)
#define SAADC_CH_CONFIG_BURST_Enabled                 (1 << 24)
/**@}*/

/* --- SAADC_CH[x].LIMIT values -------------------------------------------- */
/** @defgroup saadc_ch_limit Set limits
@ingroup saadc_defines
@{*/
#define SAADC_CH_LIMIT_LOW(n)                         ((uint16_t)(n) << 0)
#define SAADC_CH_LIMIT_HIGH(n)                        ((uint16_t)(n) << 16)
/**@}*/

/* --- SAADC_CH[0].PSELP values -------------------------------------------- */
/** @defgroup saadc_ch0_pselp Select positive pin
@ingroup saadc_defines
@{*/
#define SAADC_CH0_PSELP_PSELP_NC                       (0) 
#define SAADC_CH0_PSELP_PSELP_ANALOGINPUT0             (1) 
#define SAADC_CH0_PSELP_PSELP_AnalogInput0             (1)
#define SAADC_CH0_PSELP_PSELP_AIN0                     (1)
#define SAADC_CH0_PSELP_PSELP_ANALOGINPUT1             (2)
#define SAADC_CH0_PSELP_PSELP_AnalogInput1             (2)
#define SAADC_CH0_PSELP_PSELP_AIN1                     (2)
#define SAADC_CH0_PSELP_PSELP_ANALOGINPUT2             (3)
#define SAADC_CH0_PSELP_PSELP_AnalogInput2             (3)
#define SAADC_CH0_PSELP_PSELP_AIN2                     (3)
#define SAADC_CH0_PSELP_PSELP_ANALOGINPUT3             (4)
#define SAADC_CH0_PSELP_PSELP_AnalogInput3             (4)
#define SAADC_CH0_PSELP_PSELP_AIN3                     (4)
#define SAADC_CH0_PSELP_PSELP_ANALOGINPUT4             (5)
#define SAADC_CH0_PSELP_PSELP_AnalogInput4             (5)
#define SAADC_CH0_PSELP_PSELP_AIN4                     (5)
#define SAADC_CH0_PSELP_PSELP_ANALOGINPUT5             (6)
#define SAADC_CH0_PSELP_PSELP_AnalogInput5             (6)
#define SAADC_CH0_PSELP_PSELP_AIN5                     (6)
#define SAADC_CH0_PSELP_PSELP_ANALOGINPUT6             (7)
#define SAADC_CH0_PSELP_PSELP_AnalogInput6             (7)
#define SAADC_CH0_PSELP_PSELP_AIN6                     (7)
#define SAADC_CH0_PSELP_PSELP_ANALOGINPUT7             (8)
#define SAADC_CH0_PSELP_PSELP_AnalogInput7             (8)
#define SAADC_CH0_PSELP_PSELP_AIN7                     (8)
#define SAADC_CH0_PSELP_PSELP_VDD                      (9)
/**@}*/

/* --- SAADC_CH[0].PSELN values -------------------------------------------- */
/** @defgroup saadc_ch0_pseln Select negative pin
@ingroup saadc_defines
@{*/
#define SAADC_CH0_PSELN_PSELN_NC                       (0)
#define SAADC_CH0_PSELN_PSELN_ANALOGINPUT0             (1)
#define SAADC_CH0_PSELN_PSELN_AnalogInput0             (1)
#define SAADC_CH0_PSELN_PSELN_AIN0                     (1)
#define SAADC_CH0_PSELN_PSELN_ANALOGINPUT1             (2)
#define SAADC_CH0_PSELN_PSELN_AnalogInput1             (2)
#define SAADC_CH0_PSELN_PSELN_AIN1                     (2)
#define SAADC_CH0_PSELN_PSELN_ANALOGINPUT2             (3)
#define SAADC_CH0_PSELN_PSELN_AnalogInput2             (3)
#define SAADC_CH0_PSELN_PSELN_AIN2                     (3)
#define SAADC_CH0_PSELN_PSELN_ANALOGINPUT3             (4)
#define SAADC_CH0_PSELN_PSELN_AnalogInput3             (4)
#define SAADC_CH0_PSELN_PSELN_AIN3                     (4)
#define SAADC_CH0_PSELN_PSELN_ANALOGINPUT4             (5)
#define SAADC_CH0_PSELN_PSELN_AnalogInput4             (5)
#define SAADC_CH0_PSELN_PSELN_AIN4                     (5)
#define SAADC_CH0_PSELN_PSELN_ANALOGINPUT5             (6)
#define SAADC_CH0_PSELN_PSELN_AnalogInput5             (6)
#define SAADC_CH0_PSELN_PSELN_AIN5                     (6)
#define SAADC_CH0_PSELN_PSELN_ANALOGINPUT6             (7)
#define SAADC_CH0_PSELN_PSELN_AnalogInput6             (7)
#define SAADC_CH0_PSELN_PSELN_AIN6                     (7)
#define SAADC_CH0_PSELN_PSELN_ANALOGINPUT7             (8)
#define SAADC_CH0_PSELN_PSELN_AnalogInput7             (8)
#define SAADC_CH0_PSELN_PSELN_AIN7                     (8)
#define SAADC_CH0_PSELN_PSELN_VDD                      (9)
/**@}*/

/* --- SAADC_CH[0].CONFIG values ------------------------------------------- */
/** @defgroup saadc_ch0_config Pin configuration
@ingroup saadc_defines
@{*/
#define SAADC_CH0_CONFIG_RESP_BYPASS                   (0 << 0)
#define SAADC_CH0_CONFIG_RESP_Bypass                   (0 << 0)
#define SAADC_CH0_CONFIG_RESP_PULLDOWN                 (1 << 0)
#define SAADC_CH0_CONFIG_RESP_Pulldown                 (1 << 0)
#define SAADC_CH0_CONFIG_RESP_PULLUP                   (0x2 << 0)
#define SAADC_CH0_CONFIG_RESP_Pullup                   (0x2 << 0)
#define SAADC_CH0_CONFIG_RESP_VDD1_2                   (0x3 << 0)
#define SAADC_CH0_CONFIG_RESN_BYPASS                   (0 << 4)
#define SAADC_CH0_CONFIG_RESN_Bypass                   (0 << 4)
#define SAADC_CH0_CONFIG_RESN_PULLDOWN                 (1 << 4)
#define SAADC_CH0_CONFIG_RESN_Pulldown                 (1 << 4)
#define SAADC_CH0_CONFIG_RESN_PULLUP                   (0x2 << 4)
#define SAADC_CH0_CONFIG_RESN_Pullup                   (0x2 << 4)
#define SAADC_CH0_CONFIG_RESN_VDD1_2                   (0x3 << 4)
#define SAADC_CH0_CONFIG_GAIN_GAIN1_6                  (0 << 8)
#define SAADC_CH0_CONFIG_GAIN_Gain1_6                  (0 << 8)
#define SAADC_CH0_CONFIG_GAIN_GAIN1_5                  (1 << 8)
#define SAADC_CH0_CONFIG_GAIN_Gain1_5                  (1 << 8)
#define SAADC_CH0_CONFIG_GAIN_GAIN1_4                  (0x2 << 8)
#define SAADC_CH0_CONFIG_GAIN_Gain1_4                  (0x2 << 8)
#define SAADC_CH0_CONFIG_GAIN_GAIN1_3                  (0x3 << 8)
#define SAADC_CH0_CONFIG_GAIN_Gain1_3                  (0x3 << 8)
#define SAADC_CH0_CONFIG_GAIN_GAIN1_2                  (0x4 << 8)
#define SAADC_CH0_CONFIG_GAIN_Gain1_2                  (0x4 << 8)
#define SAADC_CH0_CONFIG_GAIN_GAIN1                    (0x5 << 8)
#define SAADC_CH0_CONFIG_GAIN_Gain1                    (0x5 << 8)
#define SAADC_CH0_CONFIG_GAIN_GAIN2                    (0x6 << 8)
#define SAADC_CH0_CONFIG_GAIN_Gain2                    (0x6 << 8)
#define SAADC_CH0_CONFIG_GAIN_GAIN4                    (0x7 << 8)
#define SAADC_CH0_CONFIG_GAIN_Gain4                    (0x7 << 8)
#define SAADC_CH0_CONFIG_REFSEL_INTERNAL               (0 << 12)
#define SAADC_CH0_CONFIG_REFSEL_Internal               (0 << 12)
#define SAADC_CH0_CONFIG_REFSEL_VDD1_4                 (1 << 12)
#define SAADC_CH0_CONFIG_TACQ_3US                      (0 << 16)
#define SAADC_CH0_CONFIG_TACQ_3us                      (0 << 16)
#define SAADC_CH0_CONFIG_TACQ_5US                      (1 << 16)
#define SAADC_CH0_CONFIG_TACQ_5us                      (1 << 16)
#define SAADC_CH0_CONFIG_TACQ_10US                     (0x2 << 16)
#define SAADC_CH0_CONFIG_TACQ_10us                     (0x2 << 16)
#define SAADC_CH0_CONFIG_TACQ_15US                     (0x3 << 16)
#define SAADC_CH0_CONFIG_TACQ_15us                     (0x3 << 16)
#define SAADC_CH0_CONFIG_TACQ_20US                     (0x4 << 16)
#define SAADC_CH0_CONFIG_TACQ_20us                     (0x4 << 16)
#define SAADC_CH0_CONFIG_TACQ_40US                     (0x5 << 16)
#define SAADC_CH0_CONFIG_TACQ_40us                     (0x5 << 16)
#define SAADC_CH0_CONFIG_MODE_SE                       (0 << 20)
#define SAADC_CH0_CONFIG_MODE_DIFF                     (1 << 20)
#define SAADC_CH0_CONFIG_MODE_Diff                     (1 << 20)
#define SAADC_CH0_CONFIG_BURST_DISABLED                (0 << 24)
#define SAADC_CH0_CONFIG_BURST_Disabled                (0 << 24)
#define SAADC_CH0_CONFIG_BURST_ENABLED                 (1 << 24)
#define SAADC_CH0_CONFIG_BURST_Enabled                 (1 << 24)
/**@}*/

/* --- SAADC_CH[0].LIMIT values -------------------------------------------- */
/** @defgroup saadc_ch0_limit Set limits
@ingroup saadc_defines
@{*/
#define SAADC_CH0_LIMIT_LOW(n)                         ((uint16_t)(n) << 0)
#define SAADC_CH0_LIMIT_HIGH(n)                        ((uint16_t)(n) << 16)
/**@}*/

/* --- SAADC_CH[1].PSELP values -------------------------------------------- */
/** @defgroup saadc_ch1_pselp Select positive pin
@ingroup saadc_defines
@{*/
#define SAADC_CH1_PSELP_PSELP_NC                       (0) 
#define SAADC_CH1_PSELP_PSELP_ANALOGINPUT0             (1) 
#define SAADC_CH1_PSELP_PSELP_AnalogInput0             (1)
#define SAADC_CH1_PSELP_PSELP_AIN0                     (1)
#define SAADC_CH1_PSELP_PSELP_ANALOGINPUT1             (2)
#define SAADC_CH1_PSELP_PSELP_AnalogInput1             (2)
#define SAADC_CH1_PSELP_PSELP_AIN1                     (2)
#define SAADC_CH1_PSELP_PSELP_ANALOGINPUT2             (3)
#define SAADC_CH1_PSELP_PSELP_AnalogInput2             (3)
#define SAADC_CH1_PSELP_PSELP_AIN2                     (3)
#define SAADC_CH1_PSELP_PSELP_ANALOGINPUT3             (4)
#define SAADC_CH1_PSELP_PSELP_AnalogInput3             (4)
#define SAADC_CH1_PSELP_PSELP_AIN3                     (4)
#define SAADC_CH1_PSELP_PSELP_ANALOGINPUT4             (5)
#define SAADC_CH1_PSELP_PSELP_AnalogInput4             (5)
#define SAADC_CH1_PSELP_PSELP_AIN4                     (5)
#define SAADC_CH1_PSELP_PSELP_ANALOGINPUT5             (6)
#define SAADC_CH1_PSELP_PSELP_AnalogInput5             (6)
#define SAADC_CH1_PSELP_PSELP_AIN5                     (6)
#define SAADC_CH1_PSELP_PSELP_ANALOGINPUT6             (7)
#define SAADC_CH1_PSELP_PSELP_AnalogInput6             (7)
#define SAADC_CH1_PSELP_PSELP_AIN6                     (7)
#define SAADC_CH1_PSELP_PSELP_ANALOGINPUT7             (8)
#define SAADC_CH1_PSELP_PSELP_AnalogInput7             (8)
#define SAADC_CH1_PSELP_PSELP_AIN7                     (8)
#define SAADC_CH1_PSELP_PSELP_VDD                      (9)
/**@}*/

/* --- SAADC_CH[1].PSELN values -------------------------------------------- */
/** @defgroup saadc_ch1_pseln Select negative pin
@ingroup saadc_defines
@{*/
#define SAADC_CH1_PSELN_PSELN_NC                       (0)
#define SAADC_CH1_PSELN_PSELN_ANALOGINPUT0             (1)
#define SAADC_CH1_PSELN_PSELN_AnalogInput0             (1)
#define SAADC_CH1_PSELN_PSELN_AIN0                     (1)
#define SAADC_CH1_PSELN_PSELN_ANALOGINPUT1             (2)
#define SAADC_CH1_PSELN_PSELN_AnalogInput1             (2)
#define SAADC_CH1_PSELN_PSELN_AIN1                     (2)
#define SAADC_CH1_PSELN_PSELN_ANALOGINPUT2             (3)
#define SAADC_CH1_PSELN_PSELN_AnalogInput2             (3)
#define SAADC_CH1_PSELN_PSELN_AIN2                     (3)
#define SAADC_CH1_PSELN_PSELN_ANALOGINPUT3             (4)
#define SAADC_CH1_PSELN_PSELN_AnalogInput3             (4)
#define SAADC_CH1_PSELN_PSELN_AIN3                     (4)
#define SAADC_CH1_PSELN_PSELN_ANALOGINPUT4             (5)
#define SAADC_CH1_PSELN_PSELN_AnalogInput4             (5)
#define SAADC_CH1_PSELN_PSELN_AIN4                     (5)
#define SAADC_CH1_PSELN_PSELN_ANALOGINPUT5             (6)
#define SAADC_CH1_PSELN_PSELN_AnalogInput5             (6)
#define SAADC_CH1_PSELN_PSELN_AIN5                     (6)
#define SAADC_CH1_PSELN_PSELN_ANALOGINPUT6             (7)
#define SAADC_CH1_PSELN_PSELN_AnalogInput6             (7)
#define SAADC_CH1_PSELN_PSELN_AIN6                     (7)
#define SAADC_CH1_PSELN_PSELN_ANALOGINPUT7             (8)
#define SAADC_CH1_PSELN_PSELN_AnalogInput7             (8)
#define SAADC_CH1_PSELN_PSELN_AIN7                     (8)
#define SAADC_CH1_PSELN_PSELN_VDD                      (9)
/**@}*/

/* --- SAADC_CH[1].CONFIG values ------------------------------------------- */
/** @defgroup saadc_ch1_config Pin configuration
@ingroup saadc_defines
@{*/
#define SAADC_CH1_CONFIG_RESP_BYPASS                   (0 << 0)
#define SAADC_CH1_CONFIG_RESP_Bypass                   (0 << 0)
#define SAADC_CH1_CONFIG_RESP_PULLDOWN                 (1 << 0)
#define SAADC_CH1_CONFIG_RESP_Pulldown                 (1 << 0)
#define SAADC_CH1_CONFIG_RESP_PULLUP                   (0x2 << 0)
#define SAADC_CH1_CONFIG_RESP_Pullup                   (0x2 << 0)
#define SAADC_CH1_CONFIG_RESP_VDD1_2                   (0x3 << 0)
#define SAADC_CH1_CONFIG_RESN_BYPASS                   (0 << 4)
#define SAADC_CH1_CONFIG_RESN_Bypass                   (0 << 4)
#define SAADC_CH1_CONFIG_RESN_PULLDOWN                 (1 << 4)
#define SAADC_CH1_CONFIG_RESN_Pulldown                 (1 << 4)
#define SAADC_CH1_CONFIG_RESN_PULLUP                   (0x2 << 4)
#define SAADC_CH1_CONFIG_RESN_Pullup                   (0x2 << 4)
#define SAADC_CH1_CONFIG_RESN_VDD1_2                   (0x3 << 4)
#define SAADC_CH1_CONFIG_GAIN_GAIN1_6                  (0 << 8)
#define SAADC_CH1_CONFIG_GAIN_Gain1_6                  (0 << 8)
#define SAADC_CH1_CONFIG_GAIN_GAIN1_5                  (1 << 8)
#define SAADC_CH1_CONFIG_GAIN_Gain1_5                  (1 << 8)
#define SAADC_CH1_CONFIG_GAIN_GAIN1_4                  (0x2 << 8)
#define SAADC_CH1_CONFIG_GAIN_Gain1_4                  (0x2 << 8)
#define SAADC_CH1_CONFIG_GAIN_GAIN1_3                  (0x3 << 8)
#define SAADC_CH1_CONFIG_GAIN_Gain1_3                  (0x3 << 8)
#define SAADC_CH1_CONFIG_GAIN_GAIN1_2                  (0x4 << 8)
#define SAADC_CH1_CONFIG_GAIN_Gain1_2                  (0x4 << 8)
#define SAADC_CH1_CONFIG_GAIN_GAIN1                    (0x5 << 8)
#define SAADC_CH1_CONFIG_GAIN_Gain1                    (0x5 << 8)
#define SAADC_CH1_CONFIG_GAIN_GAIN2                    (0x6 << 8)
#define SAADC_CH1_CONFIG_GAIN_Gain2                    (0x6 << 8)
#define SAADC_CH1_CONFIG_GAIN_GAIN4                    (0x7 << 8)
#define SAADC_CH1_CONFIG_GAIN_Gain4                    (0x7 << 8)
#define SAADC_CH1_CONFIG_REFSEL_INTERNAL               (0 << 12)
#define SAADC_CH1_CONFIG_REFSEL_Internal               (0 << 12)
#define SAADC_CH1_CONFIG_REFSEL_VDD1_4                 (1 << 12)
#define SAADC_CH1_CONFIG_TACQ_3US                      (0 << 16)
#define SAADC_CH1_CONFIG_TACQ_3us                      (0 << 16)
#define SAADC_CH1_CONFIG_TACQ_5US                      (1 << 16)
#define SAADC_CH1_CONFIG_TACQ_5us                      (1 << 16)
#define SAADC_CH1_CONFIG_TACQ_10US                     (0x2 << 16)
#define SAADC_CH1_CONFIG_TACQ_10us                     (0x2 << 16)
#define SAADC_CH1_CONFIG_TACQ_15US                     (0x3 << 16)
#define SAADC_CH1_CONFIG_TACQ_15us                     (0x3 << 16)
#define SAADC_CH1_CONFIG_TACQ_20US                     (0x4 << 16)
#define SAADC_CH1_CONFIG_TACQ_20us                     (0x4 << 16)
#define SAADC_CH1_CONFIG_TACQ_40US                     (0x5 << 16)
#define SAADC_CH1_CONFIG_TACQ_40us                     (0x5 << 16)
#define SAADC_CH1_CONFIG_MODE_SE                       (0 << 20)
#define SAADC_CH1_CONFIG_MODE_DIFF                     (1 << 20)
#define SAADC_CH1_CONFIG_MODE_Diff                     (1 << 20)
#define SAADC_CH1_CONFIG_BURST_DISABLED                (0 << 24)
#define SAADC_CH1_CONFIG_BURST_Disabled                (0 << 24)
#define SAADC_CH1_CONFIG_BURST_ENABLED                 (1 << 24)
#define SAADC_CH1_CONFIG_BURST_Enabled                 (1 << 24)
/**@}*/

/* --- SAADC_CH[1].LIMIT values -------------------------------------------- */
/** @defgroup saadc_ch1_limit Set limits
@ingroup saadc_defines
@{*/
#define SAADC_CH1_LIMIT_LOW(n)                         ((uint16_t)(n) << 0)
#define SAADC_CH1_LIMIT_HIGH(n)                        ((uint16_t)(n) << 16)
/**@}*/

/* --- SAADC_CH[2].PSELP values -------------------------------------------- */
/** @defgroup saadc_ch2_pselp Select positive pin
@ingroup saadc_defines
@{*/
#define SAADC_CH2_PSELP_PSELP_NC                       (0) 
#define SAADC_CH2_PSELP_PSELP_ANALOGINPUT0             (1) 
#define SAADC_CH2_PSELP_PSELP_AnalogInput0             (1)
#define SAADC_CH2_PSELP_PSELP_AIN0                     (1)
#define SAADC_CH2_PSELP_PSELP_ANALOGINPUT1             (2)
#define SAADC_CH2_PSELP_PSELP_AnalogInput1             (2)
#define SAADC_CH2_PSELP_PSELP_AIN1                     (2)
#define SAADC_CH2_PSELP_PSELP_ANALOGINPUT2             (3)
#define SAADC_CH2_PSELP_PSELP_AnalogInput2             (3)
#define SAADC_CH2_PSELP_PSELP_AIN2                     (3)
#define SAADC_CH2_PSELP_PSELP_ANALOGINPUT3             (4)
#define SAADC_CH2_PSELP_PSELP_AnalogInput3             (4)
#define SAADC_CH2_PSELP_PSELP_AIN3                     (4)
#define SAADC_CH2_PSELP_PSELP_ANALOGINPUT4             (5)
#define SAADC_CH2_PSELP_PSELP_AnalogInput4             (5)
#define SAADC_CH2_PSELP_PSELP_AIN4                     (5)
#define SAADC_CH2_PSELP_PSELP_ANALOGINPUT5             (6)
#define SAADC_CH2_PSELP_PSELP_AnalogInput5             (6)
#define SAADC_CH2_PSELP_PSELP_AIN5                     (6)
#define SAADC_CH2_PSELP_PSELP_ANALOGINPUT6             (7)
#define SAADC_CH2_PSELP_PSELP_AnalogInput6             (7)
#define SAADC_CH2_PSELP_PSELP_AIN6                     (7)
#define SAADC_CH2_PSELP_PSELP_ANALOGINPUT7             (8)
#define SAADC_CH2_PSELP_PSELP_AnalogInput7             (8)
#define SAADC_CH2_PSELP_PSELP_AIN7                     (8)
#define SAADC_CH2_PSELP_PSELP_VDD                      (9)
/**@}*/

/* --- SAADC_CH[2].PSELN values -------------------------------------------- */
/** @defgroup saadc_ch2_pseln Select negative pin
@ingroup saadc_defines
@{*/
#define SAADC_CH2_PSELN_PSELN_NC                       (0)
#define SAADC_CH2_PSELN_PSELN_ANALOGINPUT0             (1)
#define SAADC_CH2_PSELN_PSELN_AnalogInput0             (1)
#define SAADC_CH2_PSELN_PSELN_AIN0                     (1)
#define SAADC_CH2_PSELN_PSELN_ANALOGINPUT1             (2)
#define SAADC_CH2_PSELN_PSELN_AnalogInput1             (2)
#define SAADC_CH2_PSELN_PSELN_AIN1                     (2)
#define SAADC_CH2_PSELN_PSELN_ANALOGINPUT2             (3)
#define SAADC_CH2_PSELN_PSELN_AnalogInput2             (3)
#define SAADC_CH2_PSELN_PSELN_AIN2                     (3)
#define SAADC_CH2_PSELN_PSELN_ANALOGINPUT3             (4)
#define SAADC_CH2_PSELN_PSELN_AnalogInput3             (4)
#define SAADC_CH2_PSELN_PSELN_AIN3                     (4)
#define SAADC_CH2_PSELN_PSELN_ANALOGINPUT4             (5)
#define SAADC_CH2_PSELN_PSELN_AnalogInput4             (5)
#define SAADC_CH2_PSELN_PSELN_AIN4                     (5)
#define SAADC_CH2_PSELN_PSELN_ANALOGINPUT5             (6)
#define SAADC_CH2_PSELN_PSELN_AnalogInput5             (6)
#define SAADC_CH2_PSELN_PSELN_AIN5                     (6)
#define SAADC_CH2_PSELN_PSELN_ANALOGINPUT6             (7)
#define SAADC_CH2_PSELN_PSELN_AnalogInput6             (7)
#define SAADC_CH2_PSELN_PSELN_AIN6                     (7)
#define SAADC_CH2_PSELN_PSELN_ANALOGINPUT7             (8)
#define SAADC_CH2_PSELN_PSELN_AnalogInput7             (8)
#define SAADC_CH2_PSELN_PSELN_AIN7                     (8)
#define SAADC_CH2_PSELN_PSELN_VDD                      (9)
/**@}*/

/* --- SAADC_CH[2].CONFIG values ------------------------------------------- */
/** @defgroup saadc_ch2_config Pin configuration
@ingroup saadc_defines
@{*/
#define SAADC_CH2_CONFIG_RESP_BYPASS                   (0 << 0)
#define SAADC_CH2_CONFIG_RESP_Bypass                   (0 << 0)
#define SAADC_CH2_CONFIG_RESP_PULLDOWN                 (1 << 0)
#define SAADC_CH2_CONFIG_RESP_Pulldown                 (1 << 0)
#define SAADC_CH2_CONFIG_RESP_PULLUP                   (0x2 << 0)
#define SAADC_CH2_CONFIG_RESP_Pullup                   (0x2 << 0)
#define SAADC_CH2_CONFIG_RESP_VDD1_2                   (0x3 << 0)
#define SAADC_CH2_CONFIG_RESN_BYPASS                   (0 << 4)
#define SAADC_CH2_CONFIG_RESN_Bypass                   (0 << 4)
#define SAADC_CH2_CONFIG_RESN_PULLDOWN                 (1 << 4)
#define SAADC_CH2_CONFIG_RESN_Pulldown                 (1 << 4)
#define SAADC_CH2_CONFIG_RESN_PULLUP                   (0x2 << 4)
#define SAADC_CH2_CONFIG_RESN_Pullup                   (0x2 << 4)
#define SAADC_CH2_CONFIG_RESN_VDD1_2                   (0x3 << 4)
#define SAADC_CH2_CONFIG_GAIN_GAIN1_6                  (0 << 8)
#define SAADC_CH2_CONFIG_GAIN_Gain1_6                  (0 << 8)
#define SAADC_CH2_CONFIG_GAIN_GAIN1_5                  (1 << 8)
#define SAADC_CH2_CONFIG_GAIN_Gain1_5                  (1 << 8)
#define SAADC_CH2_CONFIG_GAIN_GAIN1_4                  (0x2 << 8)
#define SAADC_CH2_CONFIG_GAIN_Gain1_4                  (0x2 << 8)
#define SAADC_CH2_CONFIG_GAIN_GAIN1_3                  (0x3 << 8)
#define SAADC_CH2_CONFIG_GAIN_Gain1_3                  (0x3 << 8)
#define SAADC_CH2_CONFIG_GAIN_GAIN1_2                  (0x4 << 8)
#define SAADC_CH2_CONFIG_GAIN_Gain1_2                  (0x4 << 8)
#define SAADC_CH2_CONFIG_GAIN_GAIN1                    (0x5 << 8)
#define SAADC_CH2_CONFIG_GAIN_Gain1                    (0x5 << 8)
#define SAADC_CH2_CONFIG_GAIN_GAIN2                    (0x6 << 8)
#define SAADC_CH2_CONFIG_GAIN_Gain2                    (0x6 << 8)
#define SAADC_CH2_CONFIG_GAIN_GAIN4                    (0x7 << 8)
#define SAADC_CH2_CONFIG_GAIN_Gain4                    (0x7 << 8)
#define SAADC_CH2_CONFIG_REFSEL_INTERNAL               (0 << 12)
#define SAADC_CH2_CONFIG_REFSEL_Internal               (0 << 12)
#define SAADC_CH2_CONFIG_REFSEL_VDD1_4                 (1 << 12)
#define SAADC_CH2_CONFIG_TACQ_3US                      (0 << 16)
#define SAADC_CH2_CONFIG_TACQ_3us                      (0 << 16)
#define SAADC_CH2_CONFIG_TACQ_5US                      (1 << 16)
#define SAADC_CH2_CONFIG_TACQ_5us                      (1 << 16)
#define SAADC_CH2_CONFIG_TACQ_10US                     (0x2 << 16)
#define SAADC_CH2_CONFIG_TACQ_10us                     (0x2 << 16)
#define SAADC_CH2_CONFIG_TACQ_15US                     (0x3 << 16)
#define SAADC_CH2_CONFIG_TACQ_15us                     (0x3 << 16)
#define SAADC_CH2_CONFIG_TACQ_20US                     (0x4 << 16)
#define SAADC_CH2_CONFIG_TACQ_20us                     (0x4 << 16)
#define SAADC_CH2_CONFIG_TACQ_40US                     (0x5 << 16)
#define SAADC_CH2_CONFIG_TACQ_40us                     (0x5 << 16)
#define SAADC_CH2_CONFIG_MODE_SE                       (0 << 20)
#define SAADC_CH2_CONFIG_MODE_DIFF                     (1 << 20)
#define SAADC_CH2_CONFIG_MODE_Diff                     (1 << 20)
#define SAADC_CH2_CONFIG_BURST_DISABLED                (0 << 24)
#define SAADC_CH2_CONFIG_BURST_Disabled                (0 << 24)
#define SAADC_CH2_CONFIG_BURST_ENABLED                 (1 << 24)
#define SAADC_CH2_CONFIG_BURST_Enabled                 (1 << 24)
/**@}*/

/* --- SAADC_CH[2].LIMIT values -------------------------------------------- */
/** @defgroup saadc_ch2_limit Set limits
@ingroup saadc_defines
@{*/
#define SAADC_CH2_LIMIT_LOW(n)                         ((uint16_t)(n) << 0)
#define SAADC_CH2_LIMIT_HIGH(n)                        ((uint16_t)(n) << 16)
/**@}*/

/* --- SAADC_CH[3].PSELP values -------------------------------------------- */
/** @defgroup saadc_ch3_pselp Select positive pin
@ingroup saadc_defines
@{*/
#define SAADC_CH3_PSELP_PSELP_NC                       (0) 
#define SAADC_CH3_PSELP_PSELP_ANALOGINPUT0             (1) 
#define SAADC_CH3_PSELP_PSELP_AnalogInput0             (1)
#define SAADC_CH3_PSELP_PSELP_AIN0                     (1)
#define SAADC_CH3_PSELP_PSELP_ANALOGINPUT1             (2)
#define SAADC_CH3_PSELP_PSELP_AnalogInput1             (2)
#define SAADC_CH3_PSELP_PSELP_AIN1                     (2)
#define SAADC_CH3_PSELP_PSELP_ANALOGINPUT2             (3)
#define SAADC_CH3_PSELP_PSELP_AnalogInput2             (3)
#define SAADC_CH3_PSELP_PSELP_AIN2                     (3)
#define SAADC_CH3_PSELP_PSELP_ANALOGINPUT3             (4)
#define SAADC_CH3_PSELP_PSELP_AnalogInput3             (4)
#define SAADC_CH3_PSELP_PSELP_AIN3                     (4)
#define SAADC_CH3_PSELP_PSELP_ANALOGINPUT4             (5)
#define SAADC_CH3_PSELP_PSELP_AnalogInput4             (5)
#define SAADC_CH3_PSELP_PSELP_AIN4                     (5)
#define SAADC_CH3_PSELP_PSELP_ANALOGINPUT5             (6)
#define SAADC_CH3_PSELP_PSELP_AnalogInput5             (6)
#define SAADC_CH3_PSELP_PSELP_AIN5                     (6)
#define SAADC_CH3_PSELP_PSELP_ANALOGINPUT6             (7)
#define SAADC_CH3_PSELP_PSELP_AnalogInput6             (7)
#define SAADC_CH3_PSELP_PSELP_AIN6                     (7)
#define SAADC_CH3_PSELP_PSELP_ANALOGINPUT7             (8)
#define SAADC_CH3_PSELP_PSELP_AnalogInput7             (8)
#define SAADC_CH3_PSELP_PSELP_AIN7                     (8)
#define SAADC_CH3_PSELP_PSELP_VDD                      (9)
/**@}*/

/* --- SAADC_CH[3].PSELN values -------------------------------------------- */
/** @defgroup saadc_ch3_pseln Select negative pin
@ingroup saadc_defines
@{*/
#define SAADC_CH3_PSELN_PSELN_NC                       (0)
#define SAADC_CH3_PSELN_PSELN_ANALOGINPUT0             (1)
#define SAADC_CH3_PSELN_PSELN_AnalogInput0             (1)
#define SAADC_CH3_PSELN_PSELN_AIN0                     (1)
#define SAADC_CH3_PSELN_PSELN_ANALOGINPUT1             (2)
#define SAADC_CH3_PSELN_PSELN_AnalogInput1             (2)
#define SAADC_CH3_PSELN_PSELN_AIN1                     (2)
#define SAADC_CH3_PSELN_PSELN_ANALOGINPUT2             (3)
#define SAADC_CH3_PSELN_PSELN_AnalogInput2             (3)
#define SAADC_CH3_PSELN_PSELN_AIN2                     (3)
#define SAADC_CH3_PSELN_PSELN_ANALOGINPUT3             (4)
#define SAADC_CH3_PSELN_PSELN_AnalogInput3             (4)
#define SAADC_CH3_PSELN_PSELN_AIN3                     (4)
#define SAADC_CH3_PSELN_PSELN_ANALOGINPUT4             (5)
#define SAADC_CH3_PSELN_PSELN_AnalogInput4             (5)
#define SAADC_CH3_PSELN_PSELN_AIN4                     (5)
#define SAADC_CH3_PSELN_PSELN_ANALOGINPUT5             (6)
#define SAADC_CH3_PSELN_PSELN_AnalogInput5             (6)
#define SAADC_CH3_PSELN_PSELN_AIN5                     (6)
#define SAADC_CH3_PSELN_PSELN_ANALOGINPUT6             (7)
#define SAADC_CH3_PSELN_PSELN_AnalogInput6             (7)
#define SAADC_CH3_PSELN_PSELN_AIN6                     (7)
#define SAADC_CH3_PSELN_PSELN_ANALOGINPUT7             (8)
#define SAADC_CH3_PSELN_PSELN_AnalogInput7             (8)
#define SAADC_CH3_PSELN_PSELN_AIN7                     (8)
#define SAADC_CH3_PSELN_PSELN_VDD                      (9)
/**@}*/

/* --- SAADC_CH[3].CONFIG values ------------------------------------------- */
/** @defgroup saadc_ch3_config Pin configuration
@ingroup saadc_defines
@{*/
#define SAADC_CH3_CONFIG_RESP_BYPASS                   (0 << 0)
#define SAADC_CH3_CONFIG_RESP_Bypass                   (0 << 0)
#define SAADC_CH3_CONFIG_RESP_PULLDOWN                 (1 << 0)
#define SAADC_CH3_CONFIG_RESP_Pulldown                 (1 << 0)
#define SAADC_CH3_CONFIG_RESP_PULLUP                   (0x2 << 0)
#define SAADC_CH3_CONFIG_RESP_Pullup                   (0x2 << 0)
#define SAADC_CH3_CONFIG_RESP_VDD1_2                   (0x3 << 0)
#define SAADC_CH3_CONFIG_RESN_BYPASS                   (0 << 4)
#define SAADC_CH3_CONFIG_RESN_Bypass                   (0 << 4)
#define SAADC_CH3_CONFIG_RESN_PULLDOWN                 (1 << 4)
#define SAADC_CH3_CONFIG_RESN_Pulldown                 (1 << 4)
#define SAADC_CH3_CONFIG_RESN_PULLUP                   (0x2 << 4)
#define SAADC_CH3_CONFIG_RESN_Pullup                   (0x2 << 4)
#define SAADC_CH3_CONFIG_RESN_VDD1_2                   (0x3 << 4)
#define SAADC_CH3_CONFIG_GAIN_GAIN1_6                  (0 << 8)
#define SAADC_CH3_CONFIG_GAIN_Gain1_6                  (0 << 8)
#define SAADC_CH3_CONFIG_GAIN_GAIN1_5                  (1 << 8)
#define SAADC_CH3_CONFIG_GAIN_Gain1_5                  (1 << 8)
#define SAADC_CH3_CONFIG_GAIN_GAIN1_4                  (0x2 << 8)
#define SAADC_CH3_CONFIG_GAIN_Gain1_4                  (0x2 << 8)
#define SAADC_CH3_CONFIG_GAIN_GAIN1_3                  (0x3 << 8)
#define SAADC_CH3_CONFIG_GAIN_Gain1_3                  (0x3 << 8)
#define SAADC_CH3_CONFIG_GAIN_GAIN1_2                  (0x4 << 8)
#define SAADC_CH3_CONFIG_GAIN_Gain1_2                  (0x4 << 8)
#define SAADC_CH3_CONFIG_GAIN_GAIN1                    (0x5 << 8)
#define SAADC_CH3_CONFIG_GAIN_Gain1                    (0x5 << 8)
#define SAADC_CH3_CONFIG_GAIN_GAIN2                    (0x6 << 8)
#define SAADC_CH3_CONFIG_GAIN_Gain2                    (0x6 << 8)
#define SAADC_CH3_CONFIG_GAIN_GAIN4                    (0x7 << 8)
#define SAADC_CH3_CONFIG_GAIN_Gain4                    (0x7 << 8)
#define SAADC_CH3_CONFIG_REFSEL_INTERNAL               (0 << 12)
#define SAADC_CH3_CONFIG_REFSEL_Internal               (0 << 12)
#define SAADC_CH3_CONFIG_REFSEL_VDD1_4                 (1 << 12)
#define SAADC_CH3_CONFIG_TACQ_3US                      (0 << 16)
#define SAADC_CH3_CONFIG_TACQ_3us                      (0 << 16)
#define SAADC_CH3_CONFIG_TACQ_5US                      (1 << 16)
#define SAADC_CH3_CONFIG_TACQ_5us                      (1 << 16)
#define SAADC_CH3_CONFIG_TACQ_10US                     (0x2 << 16)
#define SAADC_CH3_CONFIG_TACQ_10us                     (0x2 << 16)
#define SAADC_CH3_CONFIG_TACQ_15US                     (0x3 << 16)
#define SAADC_CH3_CONFIG_TACQ_15us                     (0x3 << 16)
#define SAADC_CH3_CONFIG_TACQ_20US                     (0x4 << 16)
#define SAADC_CH3_CONFIG_TACQ_20us                     (0x4 << 16)
#define SAADC_CH3_CONFIG_TACQ_40US                     (0x5 << 16)
#define SAADC_CH3_CONFIG_TACQ_40us                     (0x5 << 16)
#define SAADC_CH3_CONFIG_MODE_SE                       (0 << 20)
#define SAADC_CH3_CONFIG_MODE_DIFF                     (1 << 20)
#define SAADC_CH3_CONFIG_MODE_Diff                     (1 << 20)
#define SAADC_CH3_CONFIG_BURST_DISABLED                (0 << 24)
#define SAADC_CH3_CONFIG_BURST_Disabled                (0 << 24)
#define SAADC_CH3_CONFIG_BURST_ENABLED                 (1 << 24)
#define SAADC_CH3_CONFIG_BURST_Enabled                 (1 << 24)
/**@}*/

/* --- SAADC_CH[3].LIMIT values -------------------------------------------- */
/** @defgroup saadc_ch3_limit Set limits
@ingroup saadc_defines
@{*/
#define SAADC_CH3_LIMIT_LOW(n)                         ((uint16_t)(n) << 0)
#define SAADC_CH3_LIMIT_HIGH(n)                        ((uint16_t)(n) << 16)
/**@}*/

/* --- SAADC_CH[4].PSELP values -------------------------------------------- */
/** @defgroup saadc_ch4_pselp Select positive pin
@ingroup saadc_defines
@{*/
#define SAADC_CH4_PSELP_PSELP_NC                       (0) 
#define SAADC_CH4_PSELP_PSELP_ANALOGINPUT0             (1) 
#define SAADC_CH4_PSELP_PSELP_AnalogInput0             (1)
#define SAADC_CH4_PSELP_PSELP_AIN0                     (1)
#define SAADC_CH4_PSELP_PSELP_ANALOGINPUT1             (2)
#define SAADC_CH4_PSELP_PSELP_AnalogInput1             (2)
#define SAADC_CH4_PSELP_PSELP_AIN1                     (2)
#define SAADC_CH4_PSELP_PSELP_ANALOGINPUT2             (3)
#define SAADC_CH4_PSELP_PSELP_AnalogInput2             (3)
#define SAADC_CH4_PSELP_PSELP_AIN2                     (3)
#define SAADC_CH4_PSELP_PSELP_ANALOGINPUT3             (4)
#define SAADC_CH4_PSELP_PSELP_AnalogInput3             (4)
#define SAADC_CH4_PSELP_PSELP_AIN3                     (4)
#define SAADC_CH4_PSELP_PSELP_ANALOGINPUT4             (5)
#define SAADC_CH4_PSELP_PSELP_AnalogInput4             (5)
#define SAADC_CH4_PSELP_PSELP_AIN4                     (5)
#define SAADC_CH4_PSELP_PSELP_ANALOGINPUT5             (6)
#define SAADC_CH4_PSELP_PSELP_AnalogInput5             (6)
#define SAADC_CH4_PSELP_PSELP_AIN5                     (6)
#define SAADC_CH4_PSELP_PSELP_ANALOGINPUT6             (7)
#define SAADC_CH4_PSELP_PSELP_AnalogInput6             (7)
#define SAADC_CH4_PSELP_PSELP_AIN6                     (7)
#define SAADC_CH4_PSELP_PSELP_ANALOGINPUT7             (8)
#define SAADC_CH4_PSELP_PSELP_AnalogInput7             (8)
#define SAADC_CH4_PSELP_PSELP_AIN7                     (8)
#define SAADC_CH4_PSELP_PSELP_VDD                      (9)
/**@}*/

/* --- SAADC_CH[4].PSELN values -------------------------------------------- */
/** @defgroup saadc_ch4_pseln Select negative pin
@ingroup saadc_defines
@{*/
#define SAADC_CH4_PSELN_PSELN_NC                       (0)
#define SAADC_CH4_PSELN_PSELN_ANALOGINPUT0             (1)
#define SAADC_CH4_PSELN_PSELN_AnalogInput0             (1)
#define SAADC_CH4_PSELN_PSELN_AIN0                     (1)
#define SAADC_CH4_PSELN_PSELN_ANALOGINPUT1             (2)
#define SAADC_CH4_PSELN_PSELN_AnalogInput1             (2)
#define SAADC_CH4_PSELN_PSELN_AIN1                     (2)
#define SAADC_CH4_PSELN_PSELN_ANALOGINPUT2             (3)
#define SAADC_CH4_PSELN_PSELN_AnalogInput2             (3)
#define SAADC_CH4_PSELN_PSELN_AIN2                     (3)
#define SAADC_CH4_PSELN_PSELN_ANALOGINPUT3             (4)
#define SAADC_CH4_PSELN_PSELN_AnalogInput3             (4)
#define SAADC_CH4_PSELN_PSELN_AIN3                     (4)
#define SAADC_CH4_PSELN_PSELN_ANALOGINPUT4             (5)
#define SAADC_CH4_PSELN_PSELN_AnalogInput4             (5)
#define SAADC_CH4_PSELN_PSELN_AIN4                     (5)
#define SAADC_CH4_PSELN_PSELN_ANALOGINPUT5             (6)
#define SAADC_CH4_PSELN_PSELN_AnalogInput5             (6)
#define SAADC_CH4_PSELN_PSELN_AIN5                     (6)
#define SAADC_CH4_PSELN_PSELN_ANALOGINPUT6             (7)
#define SAADC_CH4_PSELN_PSELN_AnalogInput6             (7)
#define SAADC_CH4_PSELN_PSELN_AIN6                     (7)
#define SAADC_CH4_PSELN_PSELN_ANALOGINPUT7             (8)
#define SAADC_CH4_PSELN_PSELN_AnalogInput7             (8)
#define SAADC_CH4_PSELN_PSELN_AIN7                     (8)
#define SAADC_CH4_PSELN_PSELN_VDD                      (9)
/**@}*/

/* --- SAADC_CH[4].CONFIG values ------------------------------------------- */
/** @defgroup saadc_ch4_config Pin configuration
@ingroup saadc_defines
@{*/
#define SAADC_CH4_CONFIG_RESP_BYPASS                   (0 << 0)
#define SAADC_CH4_CONFIG_RESP_Bypass                   (0 << 0)
#define SAADC_CH4_CONFIG_RESP_PULLDOWN                 (1 << 0)
#define SAADC_CH4_CONFIG_RESP_Pulldown                 (1 << 0)
#define SAADC_CH4_CONFIG_RESP_PULLUP                   (0x2 << 0)
#define SAADC_CH4_CONFIG_RESP_Pullup                   (0x2 << 0)
#define SAADC_CH4_CONFIG_RESP_VDD1_2                   (0x3 << 0)
#define SAADC_CH4_CONFIG_RESN_BYPASS                   (0 << 4)
#define SAADC_CH4_CONFIG_RESN_Bypass                   (0 << 4)
#define SAADC_CH4_CONFIG_RESN_PULLDOWN                 (1 << 4)
#define SAADC_CH4_CONFIG_RESN_Pulldown                 (1 << 4)
#define SAADC_CH4_CONFIG_RESN_PULLUP                   (0x2 << 4)
#define SAADC_CH4_CONFIG_RESN_Pullup                   (0x2 << 4)
#define SAADC_CH4_CONFIG_RESN_VDD1_2                   (0x3 << 4)
#define SAADC_CH4_CONFIG_GAIN_GAIN1_6                  (0 << 8)
#define SAADC_CH4_CONFIG_GAIN_Gain1_6                  (0 << 8)
#define SAADC_CH4_CONFIG_GAIN_GAIN1_5                  (1 << 8)
#define SAADC_CH4_CONFIG_GAIN_Gain1_5                  (1 << 8)
#define SAADC_CH4_CONFIG_GAIN_GAIN1_4                  (0x2 << 8)
#define SAADC_CH4_CONFIG_GAIN_Gain1_4                  (0x2 << 8)
#define SAADC_CH4_CONFIG_GAIN_GAIN1_3                  (0x3 << 8)
#define SAADC_CH4_CONFIG_GAIN_Gain1_3                  (0x3 << 8)
#define SAADC_CH4_CONFIG_GAIN_GAIN1_2                  (0x4 << 8)
#define SAADC_CH4_CONFIG_GAIN_Gain1_2                  (0x4 << 8)
#define SAADC_CH4_CONFIG_GAIN_GAIN1                    (0x5 << 8)
#define SAADC_CH4_CONFIG_GAIN_Gain1                    (0x5 << 8)
#define SAADC_CH4_CONFIG_GAIN_GAIN2                    (0x6 << 8)
#define SAADC_CH4_CONFIG_GAIN_Gain2                    (0x6 << 8)
#define SAADC_CH4_CONFIG_GAIN_GAIN4                    (0x7 << 8)
#define SAADC_CH4_CONFIG_GAIN_Gain4                    (0x7 << 8)
#define SAADC_CH4_CONFIG_REFSEL_INTERNAL               (0 << 12)
#define SAADC_CH4_CONFIG_REFSEL_Internal               (0 << 12)
#define SAADC_CH4_CONFIG_REFSEL_VDD1_4                 (1 << 12)
#define SAADC_CH4_CONFIG_TACQ_3US                      (0 << 16)
#define SAADC_CH4_CONFIG_TACQ_3us                      (0 << 16)
#define SAADC_CH4_CONFIG_TACQ_5US                      (1 << 16)
#define SAADC_CH4_CONFIG_TACQ_5us                      (1 << 16)
#define SAADC_CH4_CONFIG_TACQ_10US                     (0x2 << 16)
#define SAADC_CH4_CONFIG_TACQ_10us                     (0x2 << 16)
#define SAADC_CH4_CONFIG_TACQ_15US                     (0x3 << 16)
#define SAADC_CH4_CONFIG_TACQ_15us                     (0x3 << 16)
#define SAADC_CH4_CONFIG_TACQ_20US                     (0x4 << 16)
#define SAADC_CH4_CONFIG_TACQ_20us                     (0x4 << 16)
#define SAADC_CH4_CONFIG_TACQ_40US                     (0x5 << 16)
#define SAADC_CH4_CONFIG_TACQ_40us                     (0x5 << 16)
#define SAADC_CH4_CONFIG_MODE_SE                       (0 << 20)
#define SAADC_CH4_CONFIG_MODE_DIFF                     (1 << 20)
#define SAADC_CH4_CONFIG_MODE_Diff                     (1 << 20)
#define SAADC_CH4_CONFIG_BURST_DISABLED                (0 << 24)
#define SAADC_CH4_CONFIG_BURST_Disabled                (0 << 24)
#define SAADC_CH4_CONFIG_BURST_ENABLED                 (1 << 24)
#define SAADC_CH4_CONFIG_BURST_Enabled                 (1 << 24)
/**@}*/

/* --- SAADC_CH[4].LIMIT values -------------------------------------------- */
/** @defgroup saadc_ch4_limit Set limits
@ingroup saadc_defines
@{*/
#define SAADC_CH4_LIMIT_LOW(n)                         ((uint16_t)(n) << 0)
#define SAADC_CH4_LIMIT_HIGH(n)                        ((uint16_t)(n) << 16)
/**@}*/

/* --- SAADC_CH[5].PSELP values -------------------------------------------- */
/** @defgroup saadc_ch5_pselp Select positive pin
@ingroup saadc_defines
@{*/
#define SAADC_CH5_PSELP_PSELP_NC                       (0) 
#define SAADC_CH5_PSELP_PSELP_ANALOGINPUT0             (1) 
#define SAADC_CH5_PSELP_PSELP_AnalogInput0             (1)
#define SAADC_CH5_PSELP_PSELP_AIN0                     (1)
#define SAADC_CH5_PSELP_PSELP_ANALOGINPUT1             (2)
#define SAADC_CH5_PSELP_PSELP_AnalogInput1             (2)
#define SAADC_CH5_PSELP_PSELP_AIN1                     (2)
#define SAADC_CH5_PSELP_PSELP_ANALOGINPUT2             (3)
#define SAADC_CH5_PSELP_PSELP_AnalogInput2             (3)
#define SAADC_CH5_PSELP_PSELP_AIN2                     (3)
#define SAADC_CH5_PSELP_PSELP_ANALOGINPUT3             (4)
#define SAADC_CH5_PSELP_PSELP_AnalogInput3             (4)
#define SAADC_CH5_PSELP_PSELP_AIN3                     (4)
#define SAADC_CH5_PSELP_PSELP_ANALOGINPUT4             (5)
#define SAADC_CH5_PSELP_PSELP_AnalogInput4             (5)
#define SAADC_CH5_PSELP_PSELP_AIN4                     (5)
#define SAADC_CH5_PSELP_PSELP_ANALOGINPUT5             (6)
#define SAADC_CH5_PSELP_PSELP_AnalogInput5             (6)
#define SAADC_CH5_PSELP_PSELP_AIN5                     (6)
#define SAADC_CH5_PSELP_PSELP_ANALOGINPUT6             (7)
#define SAADC_CH5_PSELP_PSELP_AnalogInput6             (7)
#define SAADC_CH5_PSELP_PSELP_AIN6                     (7)
#define SAADC_CH5_PSELP_PSELP_ANALOGINPUT7             (8)
#define SAADC_CH5_PSELP_PSELP_AnalogInput7             (8)
#define SAADC_CH5_PSELP_PSELP_AIN7                     (8)
#define SAADC_CH5_PSELP_PSELP_VDD                      (9)
/**@}*/

/* --- SAADC_CH[5].PSELN values -------------------------------------------- */
/** @defgroup saadc_ch5_pseln Select negative pin
@ingroup saadc_defines
@{*/
#define SAADC_CH5_PSELN_PSELN_NC                       (0)
#define SAADC_CH5_PSELN_PSELN_ANALOGINPUT0             (1)
#define SAADC_CH5_PSELN_PSELN_AnalogInput0             (1)
#define SAADC_CH5_PSELN_PSELN_AIN0                     (1)
#define SAADC_CH5_PSELN_PSELN_ANALOGINPUT1             (2)
#define SAADC_CH5_PSELN_PSELN_AnalogInput1             (2)
#define SAADC_CH5_PSELN_PSELN_AIN1                     (2)
#define SAADC_CH5_PSELN_PSELN_ANALOGINPUT2             (3)
#define SAADC_CH5_PSELN_PSELN_AnalogInput2             (3)
#define SAADC_CH5_PSELN_PSELN_AIN2                     (3)
#define SAADC_CH5_PSELN_PSELN_ANALOGINPUT3             (4)
#define SAADC_CH5_PSELN_PSELN_AnalogInput3             (4)
#define SAADC_CH5_PSELN_PSELN_AIN3                     (4)
#define SAADC_CH5_PSELN_PSELN_ANALOGINPUT4             (5)
#define SAADC_CH5_PSELN_PSELN_AnalogInput4             (5)
#define SAADC_CH5_PSELN_PSELN_AIN4                     (5)
#define SAADC_CH5_PSELN_PSELN_ANALOGINPUT5             (6)
#define SAADC_CH5_PSELN_PSELN_AnalogInput5             (6)
#define SAADC_CH5_PSELN_PSELN_AIN5                     (6)
#define SAADC_CH5_PSELN_PSELN_ANALOGINPUT6             (7)
#define SAADC_CH5_PSELN_PSELN_AnalogInput6             (7)
#define SAADC_CH5_PSELN_PSELN_AIN6                     (7)
#define SAADC_CH5_PSELN_PSELN_ANALOGINPUT7             (8)
#define SAADC_CH5_PSELN_PSELN_AnalogInput7             (8)
#define SAADC_CH5_PSELN_PSELN_AIN7                     (8)
#define SAADC_CH5_PSELN_PSELN_VDD                      (9)
/**@}*/

/* --- SAADC_CH[5].CONFIG values ------------------------------------------- */
/** @defgroup saadc_ch5_config Pin configuration
@ingroup saadc_defines
@{*/
#define SAADC_CH5_CONFIG_RESP_BYPASS                   (0 << 0)
#define SAADC_CH5_CONFIG_RESP_Bypass                   (0 << 0)
#define SAADC_CH5_CONFIG_RESP_PULLDOWN                 (1 << 0)
#define SAADC_CH5_CONFIG_RESP_Pulldown                 (1 << 0)
#define SAADC_CH5_CONFIG_RESP_PULLUP                   (0x2 << 0)
#define SAADC_CH5_CONFIG_RESP_Pullup                   (0x2 << 0)
#define SAADC_CH5_CONFIG_RESP_VDD1_2                   (0x3 << 0)
#define SAADC_CH5_CONFIG_RESN_BYPASS                   (0 << 4)
#define SAADC_CH5_CONFIG_RESN_Bypass                   (0 << 4)
#define SAADC_CH5_CONFIG_RESN_PULLDOWN                 (1 << 4)
#define SAADC_CH5_CONFIG_RESN_Pulldown                 (1 << 4)
#define SAADC_CH5_CONFIG_RESN_PULLUP                   (0x2 << 4)
#define SAADC_CH5_CONFIG_RESN_Pullup                   (0x2 << 4)
#define SAADC_CH5_CONFIG_RESN_VDD1_2                   (0x3 << 4)
#define SAADC_CH5_CONFIG_GAIN_GAIN1_6                  (0 << 8)
#define SAADC_CH5_CONFIG_GAIN_Gain1_6                  (0 << 8)
#define SAADC_CH5_CONFIG_GAIN_GAIN1_5                  (1 << 8)
#define SAADC_CH5_CONFIG_GAIN_Gain1_5                  (1 << 8)
#define SAADC_CH5_CONFIG_GAIN_GAIN1_4                  (0x2 << 8)
#define SAADC_CH5_CONFIG_GAIN_Gain1_4                  (0x2 << 8)
#define SAADC_CH5_CONFIG_GAIN_GAIN1_3                  (0x3 << 8)
#define SAADC_CH5_CONFIG_GAIN_Gain1_3                  (0x3 << 8)
#define SAADC_CH5_CONFIG_GAIN_GAIN1_2                  (0x4 << 8)
#define SAADC_CH5_CONFIG_GAIN_Gain1_2                  (0x4 << 8)
#define SAADC_CH5_CONFIG_GAIN_GAIN1                    (0x5 << 8)
#define SAADC_CH5_CONFIG_GAIN_Gain1                    (0x5 << 8)
#define SAADC_CH5_CONFIG_GAIN_GAIN2                    (0x6 << 8)
#define SAADC_CH5_CONFIG_GAIN_Gain2                    (0x6 << 8)
#define SAADC_CH5_CONFIG_GAIN_GAIN4                    (0x7 << 8)
#define SAADC_CH5_CONFIG_GAIN_Gain4                    (0x7 << 8)
#define SAADC_CH5_CONFIG_REFSEL_INTERNAL               (0 << 12)
#define SAADC_CH5_CONFIG_REFSEL_Internal               (0 << 12)
#define SAADC_CH5_CONFIG_REFSEL_VDD1_4                 (1 << 12)
#define SAADC_CH5_CONFIG_TACQ_3US                      (0 << 16)
#define SAADC_CH5_CONFIG_TACQ_3us                      (0 << 16)
#define SAADC_CH5_CONFIG_TACQ_5US                      (1 << 16)
#define SAADC_CH5_CONFIG_TACQ_5us                      (1 << 16)
#define SAADC_CH5_CONFIG_TACQ_10US                     (0x2 << 16)
#define SAADC_CH5_CONFIG_TACQ_10us                     (0x2 << 16)
#define SAADC_CH5_CONFIG_TACQ_15US                     (0x3 << 16)
#define SAADC_CH5_CONFIG_TACQ_15us                     (0x3 << 16)
#define SAADC_CH5_CONFIG_TACQ_20US                     (0x4 << 16)
#define SAADC_CH5_CONFIG_TACQ_20us                     (0x4 << 16)
#define SAADC_CH5_CONFIG_TACQ_40US                     (0x5 << 16)
#define SAADC_CH5_CONFIG_TACQ_40us                     (0x5 << 16)
#define SAADC_CH5_CONFIG_MODE_SE                       (0 << 20)
#define SAADC_CH5_CONFIG_MODE_DIFF                     (1 << 20)
#define SAADC_CH5_CONFIG_MODE_Diff                     (1 << 20)
#define SAADC_CH5_CONFIG_BURST_DISABLED                (0 << 24)
#define SAADC_CH5_CONFIG_BURST_Disabled                (0 << 24)
#define SAADC_CH5_CONFIG_BURST_ENABLED                 (1 << 24)
#define SAADC_CH5_CONFIG_BURST_Enabled                 (1 << 24)
/**@}*/

/* --- SAADC_CH[5].LIMIT values -------------------------------------------- */
/** @defgroup saadc_ch5_limit Set limits
@ingroup saadc_defines
@{*/
#define SAADC_CH5_LIMIT_LOW(n)                         ((uint16_t)(n) << 0)
#define SAADC_CH5_LIMIT_HIGH(n)                        ((uint16_t)(n) << 16)
/**@}*/

/* --- SAADC_CH[6].PSELP values -------------------------------------------- */
/** @defgroup saadc_ch6_pselp Select positive pin
@ingroup saadc_defines
@{*/
#define SAADC_CH6_PSELP_PSELP_NC                       (0) 
#define SAADC_CH6_PSELP_PSELP_ANALOGINPUT0             (1) 
#define SAADC_CH6_PSELP_PSELP_AnalogInput0             (1)
#define SAADC_CH6_PSELP_PSELP_AIN0                     (1)
#define SAADC_CH6_PSELP_PSELP_ANALOGINPUT1             (2)
#define SAADC_CH6_PSELP_PSELP_AnalogInput1             (2)
#define SAADC_CH6_PSELP_PSELP_AIN1                     (2)
#define SAADC_CH6_PSELP_PSELP_ANALOGINPUT2             (3)
#define SAADC_CH6_PSELP_PSELP_AnalogInput2             (3)
#define SAADC_CH6_PSELP_PSELP_AIN2                     (3)
#define SAADC_CH6_PSELP_PSELP_ANALOGINPUT3             (4)
#define SAADC_CH6_PSELP_PSELP_AnalogInput3             (4)
#define SAADC_CH6_PSELP_PSELP_AIN3                     (4)
#define SAADC_CH6_PSELP_PSELP_ANALOGINPUT4             (5)
#define SAADC_CH6_PSELP_PSELP_AnalogInput4             (5)
#define SAADC_CH6_PSELP_PSELP_AIN4                     (5)
#define SAADC_CH6_PSELP_PSELP_ANALOGINPUT5             (6)
#define SAADC_CH6_PSELP_PSELP_AnalogInput5             (6)
#define SAADC_CH6_PSELP_PSELP_AIN5                     (6)
#define SAADC_CH6_PSELP_PSELP_ANALOGINPUT6             (7)
#define SAADC_CH6_PSELP_PSELP_AnalogInput6             (7)
#define SAADC_CH6_PSELP_PSELP_AIN6                     (7)
#define SAADC_CH6_PSELP_PSELP_ANALOGINPUT7             (8)
#define SAADC_CH6_PSELP_PSELP_AnalogInput7             (8)
#define SAADC_CH6_PSELP_PSELP_AIN7                     (8)
#define SAADC_CH6_PSELP_PSELP_VDD                      (9)
/**@}*/

/* --- SAADC_CH[6].PSELN values -------------------------------------------- */
/** @defgroup saadc_ch6_pseln Select negative pin
@ingroup saadc_defines
@{*/
#define SAADC_CH6_PSELN_PSELN_NC                       (0)
#define SAADC_CH6_PSELN_PSELN_ANALOGINPUT0             (1)
#define SAADC_CH6_PSELN_PSELN_AnalogInput0             (1)
#define SAADC_CH6_PSELN_PSELN_AIN0                     (1)
#define SAADC_CH6_PSELN_PSELN_ANALOGINPUT1             (2)
#define SAADC_CH6_PSELN_PSELN_AnalogInput1             (2)
#define SAADC_CH6_PSELN_PSELN_AIN1                     (2)
#define SAADC_CH6_PSELN_PSELN_ANALOGINPUT2             (3)
#define SAADC_CH6_PSELN_PSELN_AnalogInput2             (3)
#define SAADC_CH6_PSELN_PSELN_AIN2                     (3)
#define SAADC_CH6_PSELN_PSELN_ANALOGINPUT3             (4)
#define SAADC_CH6_PSELN_PSELN_AnalogInput3             (4)
#define SAADC_CH6_PSELN_PSELN_AIN3                     (4)
#define SAADC_CH6_PSELN_PSELN_ANALOGINPUT4             (5)
#define SAADC_CH6_PSELN_PSELN_AnalogInput4             (5)
#define SAADC_CH6_PSELN_PSELN_AIN4                     (5)
#define SAADC_CH6_PSELN_PSELN_ANALOGINPUT5             (6)
#define SAADC_CH6_PSELN_PSELN_AnalogInput5             (6)
#define SAADC_CH6_PSELN_PSELN_AIN5                     (6)
#define SAADC_CH6_PSELN_PSELN_ANALOGINPUT6             (7)
#define SAADC_CH6_PSELN_PSELN_AnalogInput6             (7)
#define SAADC_CH6_PSELN_PSELN_AIN6                     (7)
#define SAADC_CH6_PSELN_PSELN_ANALOGINPUT7             (8)
#define SAADC_CH6_PSELN_PSELN_AnalogInput7             (8)
#define SAADC_CH6_PSELN_PSELN_AIN7                     (8)
#define SAADC_CH6_PSELN_PSELN_VDD                      (9)
/**@}*/

/* --- SAADC_CH[6].CONFIG values ------------------------------------------- */
/** @defgroup saadc_ch6_config Pin configuration
@ingroup saadc_defines
@{*/
#define SAADC_CH6_CONFIG_RESP_BYPASS                   (0 << 0)
#define SAADC_CH6_CONFIG_RESP_Bypass                   (0 << 0)
#define SAADC_CH6_CONFIG_RESP_PULLDOWN                 (1 << 0)
#define SAADC_CH6_CONFIG_RESP_Pulldown                 (1 << 0)
#define SAADC_CH6_CONFIG_RESP_PULLUP                   (0x2 << 0)
#define SAADC_CH6_CONFIG_RESP_Pullup                   (0x2 << 0)
#define SAADC_CH6_CONFIG_RESP_VDD1_2                   (0x3 << 0)
#define SAADC_CH6_CONFIG_RESN_BYPASS                   (0 << 4)
#define SAADC_CH6_CONFIG_RESN_Bypass                   (0 << 4)
#define SAADC_CH6_CONFIG_RESN_PULLDOWN                 (1 << 4)
#define SAADC_CH6_CONFIG_RESN_Pulldown                 (1 << 4)
#define SAADC_CH6_CONFIG_RESN_PULLUP                   (0x2 << 4)
#define SAADC_CH6_CONFIG_RESN_Pullup                   (0x2 << 4)
#define SAADC_CH6_CONFIG_RESN_VDD1_2                   (0x3 << 4)
#define SAADC_CH6_CONFIG_GAIN_GAIN1_6                  (0 << 8)
#define SAADC_CH6_CONFIG_GAIN_Gain1_6                  (0 << 8)
#define SAADC_CH6_CONFIG_GAIN_GAIN1_5                  (1 << 8)
#define SAADC_CH6_CONFIG_GAIN_Gain1_5                  (1 << 8)
#define SAADC_CH6_CONFIG_GAIN_GAIN1_4                  (0x2 << 8)
#define SAADC_CH6_CONFIG_GAIN_Gain1_4                  (0x2 << 8)
#define SAADC_CH6_CONFIG_GAIN_GAIN1_3                  (0x3 << 8)
#define SAADC_CH6_CONFIG_GAIN_Gain1_3                  (0x3 << 8)
#define SAADC_CH6_CONFIG_GAIN_GAIN1_2                  (0x4 << 8)
#define SAADC_CH6_CONFIG_GAIN_Gain1_2                  (0x4 << 8)
#define SAADC_CH6_CONFIG_GAIN_GAIN1                    (0x5 << 8)
#define SAADC_CH6_CONFIG_GAIN_Gain1                    (0x5 << 8)
#define SAADC_CH6_CONFIG_GAIN_GAIN2                    (0x6 << 8)
#define SAADC_CH6_CONFIG_GAIN_Gain2                    (0x6 << 8)
#define SAADC_CH6_CONFIG_GAIN_GAIN4                    (0x7 << 8)
#define SAADC_CH6_CONFIG_GAIN_Gain4                    (0x7 << 8)
#define SAADC_CH6_CONFIG_REFSEL_INTERNAL               (0 << 12)
#define SAADC_CH6_CONFIG_REFSEL_Internal               (0 << 12)
#define SAADC_CH6_CONFIG_REFSEL_VDD1_4                 (1 << 12)
#define SAADC_CH6_CONFIG_TACQ_3US                      (0 << 16)
#define SAADC_CH6_CONFIG_TACQ_3us                      (0 << 16)
#define SAADC_CH6_CONFIG_TACQ_5US                      (1 << 16)
#define SAADC_CH6_CONFIG_TACQ_5us                      (1 << 16)
#define SAADC_CH6_CONFIG_TACQ_10US                     (0x2 << 16)
#define SAADC_CH6_CONFIG_TACQ_10us                     (0x2 << 16)
#define SAADC_CH6_CONFIG_TACQ_15US                     (0x3 << 16)
#define SAADC_CH6_CONFIG_TACQ_15us                     (0x3 << 16)
#define SAADC_CH6_CONFIG_TACQ_20US                     (0x4 << 16)
#define SAADC_CH6_CONFIG_TACQ_20us                     (0x4 << 16)
#define SAADC_CH6_CONFIG_TACQ_40US                     (0x5 << 16)
#define SAADC_CH6_CONFIG_TACQ_40us                     (0x5 << 16)
#define SAADC_CH6_CONFIG_MODE_SE                       (0 << 20)
#define SAADC_CH6_CONFIG_MODE_DIFF                     (1 << 20)
#define SAADC_CH6_CONFIG_MODE_Diff                     (1 << 20)
#define SAADC_CH6_CONFIG_BURST_DISABLED                (0 << 24)
#define SAADC_CH6_CONFIG_BURST_Disabled                (0 << 24)
#define SAADC_CH6_CONFIG_BURST_ENABLED                 (1 << 24)
#define SAADC_CH6_CONFIG_BURST_Enabled                 (1 << 24)
/**@}*/

/* --- SAADC_CH[6].LIMIT values -------------------------------------------- */
/** @defgroup saadc_ch6_limit Set limits
@ingroup saadc_defines
@{*/
#define SAADC_CH6_LIMIT_LOW(n)                         ((uint16_t)(n) << 0)
#define SAADC_CH6_LIMIT_HIGH(n)                        ((uint16_t)(n) << 16)
/**@}*/

/* --- SAADC_CH[7].PSELP values -------------------------------------------- */
/** @defgroup saadc_ch7_pselp Select positive pin
@ingroup saadc_defines
@{*/
#define SAADC_CH7_PSELP_PSELP_NC                       (0) 
#define SAADC_CH7_PSELP_PSELP_ANALOGINPUT0             (1) 
#define SAADC_CH7_PSELP_PSELP_AnalogInput0             (1)
#define SAADC_CH7_PSELP_PSELP_AIN0                     (1)
#define SAADC_CH7_PSELP_PSELP_ANALOGINPUT1             (2)
#define SAADC_CH7_PSELP_PSELP_AnalogInput1             (2)
#define SAADC_CH7_PSELP_PSELP_AIN1                     (2)
#define SAADC_CH7_PSELP_PSELP_ANALOGINPUT2             (3)
#define SAADC_CH7_PSELP_PSELP_AnalogInput2             (3)
#define SAADC_CH7_PSELP_PSELP_AIN2                     (3)
#define SAADC_CH7_PSELP_PSELP_ANALOGINPUT3             (4)
#define SAADC_CH7_PSELP_PSELP_AnalogInput3             (4)
#define SAADC_CH7_PSELP_PSELP_AIN3                     (4)
#define SAADC_CH7_PSELP_PSELP_ANALOGINPUT4             (5)
#define SAADC_CH7_PSELP_PSELP_AnalogInput4             (5)
#define SAADC_CH7_PSELP_PSELP_AIN4                     (5)
#define SAADC_CH7_PSELP_PSELP_ANALOGINPUT5             (6)
#define SAADC_CH7_PSELP_PSELP_AnalogInput5             (6)
#define SAADC_CH7_PSELP_PSELP_AIN5                     (6)
#define SAADC_CH7_PSELP_PSELP_ANALOGINPUT6             (7)
#define SAADC_CH7_PSELP_PSELP_AnalogInput6             (7)
#define SAADC_CH7_PSELP_PSELP_AIN6                     (7)
#define SAADC_CH7_PSELP_PSELP_ANALOGINPUT7             (8)
#define SAADC_CH7_PSELP_PSELP_AnalogInput7             (8)
#define SAADC_CH7_PSELP_PSELP_AIN7                     (8)
#define SAADC_CH7_PSELP_PSELP_VDD                      (9)
/**@}*/

/* --- SAADC_CH[7].PSELN values -------------------------------------------- */
/** @defgroup saadc_ch7_pseln Select negative pin
@ingroup saadc_defines
@{*/
#define SAADC_CH7_PSELN_PSELN_NC                       (0)
#define SAADC_CH7_PSELN_PSELN_ANALOGINPUT0             (1)
#define SAADC_CH7_PSELN_PSELN_AnalogInput0             (1)
#define SAADC_CH7_PSELN_PSELN_AIN0                     (1)
#define SAADC_CH7_PSELN_PSELN_ANALOGINPUT1             (2)
#define SAADC_CH7_PSELN_PSELN_AnalogInput1             (2)
#define SAADC_CH7_PSELN_PSELN_AIN1                     (2)
#define SAADC_CH7_PSELN_PSELN_ANALOGINPUT2             (3)
#define SAADC_CH7_PSELN_PSELN_AnalogInput2             (3)
#define SAADC_CH7_PSELN_PSELN_AIN2                     (3)
#define SAADC_CH7_PSELN_PSELN_ANALOGINPUT3             (4)
#define SAADC_CH7_PSELN_PSELN_AnalogInput3             (4)
#define SAADC_CH7_PSELN_PSELN_AIN3                     (4)
#define SAADC_CH7_PSELN_PSELN_ANALOGINPUT4             (5)
#define SAADC_CH7_PSELN_PSELN_AnalogInput4             (5)
#define SAADC_CH7_PSELN_PSELN_AIN4                     (5)
#define SAADC_CH7_PSELN_PSELN_ANALOGINPUT5             (6)
#define SAADC_CH7_PSELN_PSELN_AnalogInput5             (6)
#define SAADC_CH7_PSELN_PSELN_AIN5                     (6)
#define SAADC_CH7_PSELN_PSELN_ANALOGINPUT6             (7)
#define SAADC_CH7_PSELN_PSELN_AnalogInput6             (7)
#define SAADC_CH7_PSELN_PSELN_AIN6                     (7)
#define SAADC_CH7_PSELN_PSELN_ANALOGINPUT7             (8)
#define SAADC_CH7_PSELN_PSELN_AnalogInput7             (8)
#define SAADC_CH7_PSELN_PSELN_AIN7                     (8)
#define SAADC_CH7_PSELN_PSELN_VDD                      (9)
/**@}*/

/* --- SAADC_CH[7].CONFIG values ------------------------------------------- */
/** @defgroup saadc_ch7_config Pin configuration
@ingroup saadc_defines
@{*/
#define SAADC_CH7_CONFIG_RESP_BYPASS                   (0 << 0)
#define SAADC_CH7_CONFIG_RESP_Bypass                   (0 << 0)
#define SAADC_CH7_CONFIG_RESP_PULLDOWN                 (1 << 0)
#define SAADC_CH7_CONFIG_RESP_Pulldown                 (1 << 0)
#define SAADC_CH7_CONFIG_RESP_PULLUP                   (0x2 << 0)
#define SAADC_CH7_CONFIG_RESP_Pullup                   (0x2 << 0)
#define SAADC_CH7_CONFIG_RESP_VDD1_2                   (0x3 << 0)
#define SAADC_CH7_CONFIG_RESN_BYPASS                   (0 << 4)
#define SAADC_CH7_CONFIG_RESN_Bypass                   (0 << 4)
#define SAADC_CH7_CONFIG_RESN_PULLDOWN                 (1 << 4)
#define SAADC_CH7_CONFIG_RESN_Pulldown                 (1 << 4)
#define SAADC_CH7_CONFIG_RESN_PULLUP                   (0x2 << 4)
#define SAADC_CH7_CONFIG_RESN_Pullup                   (0x2 << 4)
#define SAADC_CH7_CONFIG_RESN_VDD1_2                   (0x3 << 4)
#define SAADC_CH7_CONFIG_GAIN_GAIN1_6                  (0 << 8)
#define SAADC_CH7_CONFIG_GAIN_Gain1_6                  (0 << 8)
#define SAADC_CH7_CONFIG_GAIN_GAIN1_5                  (1 << 8)
#define SAADC_CH7_CONFIG_GAIN_Gain1_5                  (1 << 8)
#define SAADC_CH7_CONFIG_GAIN_GAIN1_4                  (0x2 << 8)
#define SAADC_CH7_CONFIG_GAIN_Gain1_4                  (0x2 << 8)
#define SAADC_CH7_CONFIG_GAIN_GAIN1_3                  (0x3 << 8)
#define SAADC_CH7_CONFIG_GAIN_Gain1_3                  (0x3 << 8)
#define SAADC_CH7_CONFIG_GAIN_GAIN1_2                  (0x4 << 8)
#define SAADC_CH7_CONFIG_GAIN_Gain1_2                  (0x4 << 8)
#define SAADC_CH7_CONFIG_GAIN_GAIN1                    (0x5 << 8)
#define SAADC_CH7_CONFIG_GAIN_Gain1                    (0x5 << 8)
#define SAADC_CH7_CONFIG_GAIN_GAIN2                    (0x6 << 8)
#define SAADC_CH7_CONFIG_GAIN_Gain2                    (0x6 << 8)
#define SAADC_CH7_CONFIG_GAIN_GAIN4                    (0x7 << 8)
#define SAADC_CH7_CONFIG_GAIN_Gain4                    (0x7 << 8)
#define SAADC_CH7_CONFIG_REFSEL_INTERNAL               (0 << 12)
#define SAADC_CH7_CONFIG_REFSEL_Internal               (0 << 12)
#define SAADC_CH7_CONFIG_REFSEL_VDD1_4                 (1 << 12)
#define SAADC_CH7_CONFIG_TACQ_3US                      (0 << 16)
#define SAADC_CH7_CONFIG_TACQ_3us                      (0 << 16)
#define SAADC_CH7_CONFIG_TACQ_5US                      (1 << 16)
#define SAADC_CH7_CONFIG_TACQ_5us                      (1 << 16)
#define SAADC_CH7_CONFIG_TACQ_10US                     (0x2 << 16)
#define SAADC_CH7_CONFIG_TACQ_10us                     (0x2 << 16)
#define SAADC_CH7_CONFIG_TACQ_15US                     (0x3 << 16)
#define SAADC_CH7_CONFIG_TACQ_15us                     (0x3 << 16)
#define SAADC_CH7_CONFIG_TACQ_20US                     (0x4 << 16)
#define SAADC_CH7_CONFIG_TACQ_20us                     (0x4 << 16)
#define SAADC_CH7_CONFIG_TACQ_40US                     (0x5 << 16)
#define SAADC_CH7_CONFIG_TACQ_40us                     (0x5 << 16)
#define SAADC_CH7_CONFIG_MODE_SE                       (0 << 20)
#define SAADC_CH7_CONFIG_MODE_DIFF                     (1 << 20)
#define SAADC_CH7_CONFIG_MODE_Diff                     (1 << 20)
#define SAADC_CH7_CONFIG_BURST_DISABLED                (0 << 24)
#define SAADC_CH7_CONFIG_BURST_Disabled                (0 << 24)
#define SAADC_CH7_CONFIG_BURST_ENABLED                 (1 << 24)
#define SAADC_CH7_CONFIG_BURST_Enabled                 (1 << 24)
/**@}*/

/* --- SAADC_CH[7].LIMIT values -------------------------------------------- */
/** @defgroup saadc_ch7_limit Set limits
@ingroup saadc_defines
@{*/
#define SAADC_CH7_LIMIT_LOW(n)                         ((uint16_t)(n) << 0)
#define SAADC_CH7_LIMIT_HIGH(n)                        ((uint16_t)(n) << 16)
/**@}*/

/* --- SAADC_RESOLUTION values --------------------------------------------- */
/** @defgroup saadc_resolution Set resolution
@ingroup saadc_defines
@{*/
#define SAADC_RESOLUTION_VAL(n)                        ((n-8)/2)
#define VAL_8BIT                                       (0)
#define SAADC_RESOLUTION_VAL_8BIT                      (0)
#define SAADC_RESOLUTION_VAL_8bit                      (0)
#define VAL_10BIT                                      (1)
#define SAADC_RESOLUTION_VAL_10BIT                     (1)
#define SAADC_RESOLUTION_VAL_10bit                     (1)
#define VAL_12BIT                                      (2)
#define SAADC_RESOLUTION_VAL_12BIT                     (2)
#define SAADC_RESOLUTION_VAL_12bit                     (2)
#define VAL_14BIT                                      (3)
#define SAADC_RESOLUTION_VAL_14BIT                     (3)
#define SAADC_RESOLUTION_VAL_14bit                     (3)
/**@}*/

/* --- SAADC_OVERSAMPLE values --------------------------------------------- */
/** @defgroup saadc_oversample Oversampling configuration
@ingroup saadc_defines
@{*/
#define BYPASS                                         (0)
#define SAADC_OVERSAMPLE_OVERSAMPLE_BYPASS             (0)
#define SAADC_OVERSAMPLE_OVERSAMPLE_Bypass             (0)
#define OVER2X                                         (1)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER2X             (1)
#define SAADC_OVERSAMPLE_OVERSAMPLE_Over2x             (1)
#define OVER4X                                         (2)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER4X             (2)
#define SAADC_OVERSAMPLE_OVERSAMPLE_Over4x             (2)
#define OVER8X                                         (3)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER8X             (3)
#define SAADC_OVERSAMPLE_OVERSAMPLE_Over8x             (3)
#define OVER16X                                        (4)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER16X            (4)
#define SAADC_OVERSAMPLE_OVERSAMPLE_Over16x            (4)
#define OVER32X                                        (5)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER32X            (5)
#define SAADC_OVERSAMPLE_OVERSAMPLE_Over32x            (5)
#define OVER64X                                        (6)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER64X            (6)
#define SAADC_OVERSAMPLE_OVERSAMPLE_Over64x            (6)
#define OVER128X                                       (7)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER128X           (7)
#define SAADC_OVERSAMPLE_OVERSAMPLE_Over128x           (7)
#define OVER256X                                       (8)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER256X           (8)
#define SAADC_OVERSAMPLE_OVERSAMPLE_Over256x           (8)
/**@}*/

/* --- SAADC_SAMPLERATE values --------------------------------------------- */
/** @defgroup saadc_samplerate Set sample rate and select mode
@ingroup saadc_defines
@{*/
#define SAADC_SAMPLERATE_CC(n)                         (((n)&0x7ff) << 0)
#define MODE_TASK                                      (0 << 12)
#define SAADC_SAMPLERATE_MODE_TASK                     (0 << 12)
#define SAADC_SAMPLERATE_MODE_Task                     (0 << 12)
#define MODE_TIMERS                                    (1 << 12)
#define SAADC_SAMPLERATE_MODE_TIMERS                   (1 << 12)
#define SAADC_SAMPLERATE_MODE_Timers                   (1 << 12)
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void saadc_pin_pos(uint8_t channel, uint32_t pselp);
void saadc_pin_neg(uint8_t channel, uint32_t pseln);
void saadc_resistor_pos(uint8_t channel, uint32_t resp);
void saadc_resistor_neg(uint8_t channel, uint32_t resn);
void saadc_gain(uint8_t channel, uint32_t gain);
void saadc_set_reference(uint8_t channel, uint32_t refsel);
void saadc_acquisition_time(uint8_t channel, uint32_t tacq);
void saadc_differential_mode(uint8_t channel, uint32_t mode);
void saadc_burst_enable(uint8_t channel);
void saadc_limit(uint8_t channel, int16_t low, int16_t high);
void saadc_resolution(uint8_t res);
void saadc_oversample(uint32_t oversample);
void saadc_samplerate(uint16_t cc, uint32_t mode);
void saadc_result_buffer(uint32_t *ptr, uint16_t maxcnt);
void saadc_enable(void);
void saadc_disable(void);
void saadc_sample_start(void);
void saadc_start(void);
void saadc_stop(void);
uint32_t saadc_limit_high(uint8_t channel);
uint32_t saadc_limit_low(uint8_t channel);
void saadc_limit_reset(uint8_t channel);
uint32_t saadc_sample_end(void);
uint32_t saadc_status(void);

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "saadc_common.h should not be included explicitly, only via saadc.h"
#endif
/** @endcond */


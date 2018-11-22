/** @addtogroup uarte_defines TEMP Defines
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA TEMP.H
The order of header inclusion is important. temp.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#if defined(LIBOPENCM3_TEMP_H)
/** @endcond */
#ifndef LIBOPENCM3_TEMP_COMMON_H
#define LIBOPENCM3_TEMP_COMMON_H

/**@{*/

/** @defgroup temp_registers TEMP Registers
 * @ingroup temp_defines
 * @brief TEMP Registers
@{*/
/* --------------------- TEMP registers for NRF52 -------------------------- */

/* Tasks Registers */
#define TEMP_TASKS_START                 MMIO32((TEMP_BASE) + 0x000)
#define TEMP_TASKS_STOP                  MMIO32((TEMP_BASE) + 0x004)
/* Events Registers */
#define TEMP_EVENTS_DATARDY              MMIO32((TEMP_BASE) + 0x100)
/* Registers */
#define TEMP_INTENSET                    MMIO32((TEMP_BASE) + 0x304)
#define TEMP_INTENCLR                    MMIO32((TEMP_BASE) + 0x308)
#define TEMP_TEMP                        MMIO32((TEMP_BASE) + 0x508)
#define TEMP_A                           PTRIO32((TEMP_BASE) + 0x520)
#define TEMP_A0                          MMIO32((TEMP_BASE) + 0x520)
#define TEMP_A1                          MMIO32((TEMP_BASE) + 0x524)
#define TEMP_A2                          MMIO32((TEMP_BASE) + 0x528)
#define TEMP_A3                          MMIO32((TEMP_BASE) + 0x52C)
#define TEMP_A4                          MMIO32((TEMP_BASE) + 0x530)
#define TEMP_A5                          MMIO32((TEMP_BASE) + 0x534)
#define TEMP_B                           PTRIO32((TEMP_BASE) + 0x540)
#define TEMP_B0                          MMIO32((TEMP_BASE) + 0x540)
#define TEMP_B1                          MMIO32((TEMP_BASE) + 0x544)
#define TEMP_B2                          MMIO32((TEMP_BASE) + 0x548)
#define TEMP_B3                          MMIO32((TEMP_BASE) + 0x54C)
#define TEMP_B4                          MMIO32((TEMP_BASE) + 0x550)
#define TEMP_B5                          MMIO32((TEMP_BASE) + 0x554)
#define TEMP_T                           PTRIO32((TEMP_BASE) + 0x560)
#define TEMP_T0                          MMIO32((TEMP_BASE) + 0x560)
#define TEMP_T1                          MMIO32((TEMP_BASE) + 0x564)
#define TEMP_T2                          MMIO32((TEMP_BASE) + 0x568)
#define TEMP_T3                          MMIO32((TEMP_BASE) + 0x56C)
#define TEMP_T4                          MMIO32((TEMP_BASE) + 0x570)
/**@}*/

/* --- TEMP_INTENSET values ------------------------------------------------ */
/** @defgroup temp_intenset Enable interrupt
@ingroup temp_defines
@{*/
#define TEMP_INTENSET_DATARDY_ENABLED             (1)
#define TEMP_INTENSET_DATARDY_Enabled             (1)
#define TEMP_INTENSET_DATARDY_SET                 (1)
#define TEMP_INTENSET_DATARDY_Set                 (1)
/**@}*/

/* --- TEMP_INTENCLR values ------------------------------------------------ */
/** @defgroup temp_intenclr Disable interrupt
@ingroup temp_defines
@{*/
#define TEMP_INTENCLR_DATARDY_ENABLED             (1)
#define TEMP_INTENCLR_DATARDY_Enabled             (1)
#define TEMP_INTENCLR_DATARDY_CLEAR               (1)
#define TEMP_INTENCLR_DATARDY_Clear               (1)
/**@}*/

/* --- TEMP_A[x] values ------------------------------------------------------- */
/** @defgroup temp_a Slope of (x+1).piece wise linear function (x is ranging 
from 0 to 5)
@ingroup temp_defines
@{*/
#define TEMP_A_A(n)                             (n&0xfff)
/**@}*/

/* --- TEMP_B[x] values ------------------------------------------------------- */
/** @defgroup temp_b y-intercept of (x+1).piece wise linear function (x is 
ranging from 0 to 5)
@ingroup temp_defines
@{*/
#define TEMP_B_B(n)                             (n&0x3fff)
/**@}*/

/* --- TEMP_T[x] values ------------------------------------------------------- */
/** @defgroup temp_t End point of (x+1).piece wise linear function (x is 
ranging from 0 to 4)
@ingroup temp_defines
@{*/
#define TEMP_T0_T0(n)                             (n&0xff)
#define TEMP_T1_T1(n)                             (n&0xff)
#define TEMP_T2_T2(n)                             (n&0xff)
#define TEMP_T3_T3(n)                             (n&0xff)
#define TEMP_T4_T4(n)                             (n&0xff)
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

//funktion();
//funktion();
//funktion();
//funktion();

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "temp_common.h should not be included explicitly, only via temp.h"
#endif
/** @endcond */


/** @addtogroup clock_defines
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA CLOCK.H
The order of header inclusion is important. clock.h includes the device
specific memorymap.h header before including this header file.
*/

/** @cond */
#ifdef LIBOPENCM3_CLOCK_H
/** @endcond */

#ifndef LIBOPENCM3_CLOCK_COMMON_H
#define LIBOPENCM3_CLOCK_COMMON_H

/**@{*/

/** @defgroup clock_registers Clock Control Registers
 * @ingroup clock_defines
 * @brief Clock Control Registers
@{*/

/* --------------------- CLOCK registers for NRF52 ------------------------- */
/** Tasks Registers */
#define CLOCK_TASKS_HFCLKSTART                  MMIO32(CLOCK_BASE + 0x000)
#define CLOCK_TASKS_HFCLKSTOP                   MMIO32(CLOCK_BASE + 0x004)
#define CLOCK_TASKS_LFCLKSTART                  MMIO32(CLOCK_BASE + 0x008)
#define CLOCK_TASKS_LFCLKSTOP                   MMIO32(CLOCK_BASE + 0x00C)
#define CLOCK_TASKS_CAL                         MMIO32(CLOCK_BASE + 0x010)
#define CLOCK_TASKS_CTSTART                     MMIO32(CLOCK_BASE + 0x014)
#define CLOCK_TASKS_CTSTOP                      MMIO32(CLOCK_BASE + 0x018)

/** Events Registers */
#define CLOCK_EVENTS_HFCLKSTARTED               MMIO32(CLOCK_BASE + 0x100)
#define CLOCK_EVENTS_LFCLKSTARTED               MMIO32(CLOCK_BASE + 0x104)
#define CLOCK_EVENTS_DONE                       MMIO32(CLOCK_BASE + 0x10C)
#define CLOCK_EVENTS_CTTO                       MMIO32(CLOCK_BASE + 0x110)

/** Registers */
#define CLOCK_INTENSET                          MMIO32(CLOCK_BASE + 0x304)
#define CLOCK_INTENCLR                          MMIO32(CLOCK_BASE + 0x308)
#define CLOCK_HFCLKRUN                          MMIO32(CLOCK_BASE + 0x408)
#define CLOCK_HFCLKSTAT                         MMIO32(CLOCK_BASE + 0x40C)
#define CLOCK_LFCLKRUN                          MMIO32(CLOCK_BASE + 0x414)
#define CLOCK_LFCLKSTAT                         MMIO32(CLOCK_BASE + 0x418)
#define CLOCK_LFCLKSRCCOPY                      MMIO32(CLOCK_BASE + 0x41C)
#define CLOCK_LFCLKSRC                          MMIO32(CLOCK_BASE + 0x518)
#define CLOCK_CTIV                              MMIO32(CLOCK_BASE + 0x538)
#define CLOCK_TRACECONFIG                       MMIO32(CLOCK_BASE + 0x55C)
/**@}*/

/* --- CLOCK_INTENSET values ----------------------------------------------- */
/** @defgroup clock_intenset Enable interrupt
@ingroup clock_defines
@{*/
#define CLOCK_INTENSET_HFCLKSTARTED                (1 << 0)
#define CLOCK_INTENSET_LFCLKSTARTED                (1 << 1)
#define CLOCK_INTENSET_DONE                        (1 << 3)
#define CLOCK_INTENSET_CTTO                        (1 << 4)
/**@}*/

/* --- CLOCK_INTENCLR values ----------------------------------------------- */
/** @defgroup clock_intenset Disable interrupt
@ingroup clock_defines
@{*/
#define CLOCK_INTENCLR_HFCLKSTARTED                (1 << 0)
#define CLOCK_INTENCLR_LFCLKSTARTED                (1 << 1)
#define CLOCK_INTENCLR_DONE                        (1 << 3)
#define CLOCK_INTENCLR_CTTO                        (1 << 4)
/**@}*/

/* --- CLOCK_HFCLKRUN values ----------------------------------------------- */
/** @defgroup clock_hfclkrun Status indicating that HFCLKSTART task has been
triggered
@ingroup clock_defines
@{*/
#define CLOCK_HFCLKRUN_STATUS_TRIGGERED            (1 << 0)
#define CLOCK_HFCLKRUN_STATUS_NOTTRIGGERED         (0 << 0)
/**@}*/

/* --- CLOCK_HFCLKSTAT values ---------------------------------------------- */
/** @defgroup clock_hfclkstat HFCLK Status
@ingroup clock_defines
@{*/
#define CLOCK_HFCLKSTAT_SRC_RC                     (0 << 0)
#define CLOCK_HFCLKSTAT_SRC_XTAL                   (1 << 0)
#define CLOCK_HFCLKSTAT_STATE_NOTRUNNING           (0 << 16)
#define CLOCK_HFCLKSTAT_STATE_RUNNING              (1 << 16)
/**@}*/

/* --- CLOCK_LFCLKRUN values ----------------------------------------------- */
/** @defgroup clock_lfclkrun Status indicating that LFCLKRUN task has been
triggered
@ingroup clock_defines
@{*/
#define CLOCK_LFCLKRUN_STATUS_TRIGGERED            (1)
#define CLOCK_LFCLKRUN_STATUS_NOTTRIGGERED         (0)
/**@}*/

/* --- CLOCK_LFCLKSTAT values ---------------------------------------------- */
/** @defgroup clock_lfclkstat LFCLK Status
@ingroup clock_defines
@{*/
#define CLOCK_LFCLKSTAT_SRC_RC                     (0 << 0)
#define CLOCK_LFCLKSTAT_SRC_XTAL                   (1 << 0)
#define CLOCK_LFCLKSTAT_SRC_Xtal                   (1 << 0)
#define CLOCK_LFCLKSTAT_SRC_SYNTH                  (0x2 << 0)
#define CLOCK_LFCLKSTAT_SRC_Synth                  (0x2 << 0)
#define CLOCK_LFCLKSTAT_STATE_NOTRUNNING           (0 << 16)
#define CLOCK_LFCLKSTAT_STATE_NotRunning           (0 << 16)
#define CLOCK_LFCLKSTAT_STATE_RUNNING              (1 << 16)
#define CLOCK_LFCLKSTAT_STATE_Running              (1 << 16)
/**@}*/

/* --- CLOCK_LFCLKSRCCOPY values ------------------------------------------- */
/** @defgroup clock_lfclksrccopy Copy of LFCLKSRC register, set when 
LFCLKSTART task was triggered
@ingroup clock_defines
@{*/
#define CLOCK_LFCLKSRCCOPY_SRC_RC                  (0)
#define CLOCK_LFCLKSRCCOPY_SRC_XTAL                (1)
#define CLOCK_LFCLKSRCCOPY_SRC_SYNTH               (2)
/**@}*/

/* --- CLOCK_LFCLKSRC values ----------------------------------------------- */
/** @defgroup clock_lfclksrc Clock source for the LFCLK
@ingroup clock_defines
@{*/
#define RC                                         (0 << 0)
#define CLOCK_LFCLKSRC_SRC_RC                      (0 << 0)
#define XTAL                                       (1 << 0)
#define CLOCK_LFCLKSRC_SRC_XTAL                    (1 << 0)
#define SYNTH                                      (0x2 << 0)
#define CLOCK_LFCLKSRC_SRC_SYNTH                   (0x2 << 0)
#define CLOCK_LFCLKSRC_BYPASS_ENABLED              (1 << 16)
#define CLOCK_LFCLKSRC_BYPASS_Enabled              (1 << 16)
#define CLOCK_LFCLKSRC_EXTERNAL_ENABLED            (1 << 17)
#define CLOCK_LFCLKSRC_EXTERNAL_Enabled            (1 << 17)
/**@}*/

/* --- CLOCK_CTIV values --------------------------------------------------- */
/** @defgroup clock_ctiv Retained register. Calibration timer interval
@ingroup clock_defines
@{*/
#define CLOCK_CTIV_CTIV(n)                         (n*4)
/**@}*/

/* --- CLOCK_TRACECONFIG values -------------------------------------------- */
/** @defgroup clock_traceconfig Retained register. Clocking options for the 
Trace Port debug interface
@ingroup clock_defines
@{*/
#define CLOCK_TRACECONFIG_TRACEPORTSPEED_32MHZ        (0 << 0) //TRACECLK = 16 MHz
#define CLOCK_TRACECONFIG_TRACEPORTSPEED_16MHZ        (1 << 0) //TRACECLK = 8 MHz
#define CLOCK_TRACECONFIG_TRACEPORTSPEED_8MHZ         (0x2 << 0) //TRACECLK = 4 MHz
#define CLOCK_TRACECONFIG_TRACEPORTSPEED_4MHZ         (0x3 << 0) //TRACECLK = 2 MHz
//gpio: GPIOs multiplexed onto all trace-pins
#define CLOCK_TRACECONFIG_TRACEMUX_GPIO               (0 << 16) 
//Serial: SWO multiplexed onto P0.18, GPIO multiplexed onto other trace-pins
#define CLOCK_TRACECONFIG_TRACEMUX_SERIAL             (1 << 16) 
//Parallel: TRACECLK and TRACEDATA multiplexed onto P0.20, P0.18, P0.16, P0.15, P0.14
#define CLOCK_TRACECONFIG_TRACEMUX_PARALLEL           (0x2 << 16)
/**@}*/


/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void clock_hfclk_start(void);
void clock_hfclk_stop(void);
void clock_lfclk_start(void);
void clock_lfclk_stop(void);
void clock_cal_start(void);
uint32_t clock_cal_done(void);
void clock_cal_reset(void);
void clock_cal_interval(uint8_t interval);
void clock_ct_start(void);
void clock_ct_stop(void);
uint32_t clock_ct_timeout(void);
void clock_ct_timeout_reset(void);
uint32_t clock_hfclk_trigger_status(void);
uint32_t clock_lfclk_trigger_status(void);
uint16_t clock_hfclk_run_status(void);
uint16_t clock_lfclk_run_status(void);
void clock_lfclk_source(char source);
void clock_lfclk_extsource_bypass(void);
void clock_lfclk_extsource_enable(void);


END_DECLS


/**@}*/

#endif
/** @cond */
#else
#warning "clock_common.h should not be included explicitly, only via clock.h"
#endif
/** @endcond */


/** @addtogroup pwr_defines

@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA PWR.H
The order of header inclusion is important. pwr.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_PWR_H
/** @endcond */
#ifndef LIBOPENCM3_PWR_COMMON_V1_H
#define LIBOPENCM3_PWR_COMMON_V1_H

/**@{*/

/* --- PWR registers ------------------------------------------------------- */

/** Power control register (PWR_CR) */
#define PWR_CR				MMIO32(POWER_CONTROL_BASE + 0x00)

/** Power control/status register (PWR_CSR) */
#define PWR_CSR				MMIO32(POWER_CONTROL_BASE + 0x04)

/* --- PWR_CR values ------------------------------------------------------- */

/* Bits [31:9]: Reserved, must be kept at reset value. */

/** DBP: Disable backup domain write protection */
#define PWR_CR_DBP			(1 << 8)

/* PLS[7:5]: PVD level selection */
#define PWR_CR_PLS_LSB			5
/** @defgroup pwr_pls PVD level selection
@ingroup STM32F_pwr_defines

@{*/
#define PWR_CR_PLS_2V2			(0x0 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V3			(0x1 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V4			(0x2 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V5			(0x3 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V6			(0x4 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V7			(0x5 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V8			(0x6 << PWR_CR_PLS_LSB)
#define PWR_CR_PLS_2V9			(0x7 << PWR_CR_PLS_LSB)
/**@}*/
#define PWR_CR_PLS_MASK			(0x7 << PWR_CR_PLS_LSB)

/** PVDE: Power voltage detector enable */
#define PWR_CR_PVDE			(1 << 4)

/** CSBF: Clear standby flag */
#define PWR_CR_CSBF			(1 << 3)

/** CWUF: Clear wakeup flag */
#define PWR_CR_CWUF			(1 << 2)

/** PDDS: Power down deepsleep */
#define PWR_CR_PDDS			(1 << 1)

/** LPDS: Low-power deepsleep */
#define PWR_CR_LPDS			(1 << 0)

/* --- PWR_CSR values ------------------------------------------------------ */

/* Bits [31:9]: Reserved, must be kept at reset value. */

/** EWUP: Enable WKUP pin */
#define PWR_CSR_EWUP			(1 << 8)

/* Bits [7:3]: Reserved, must be kept at reset value. */

/** PVDO: PVD output */
#define PWR_CSR_PVDO			(1 << 2)

/** SBF: Standby flag */
#define PWR_CSR_SBF			(1 << 1)

/** WUF: Wakeup flag */
#define PWR_CSR_WUF			(1 << 0)

/* --- PWR function prototypes ------------------------------------------- */

BEGIN_DECLS

void pwr_disable_backup_domain_write_protect(void);
void pwr_enable_backup_domain_write_protect(void);
void pwr_enable_power_voltage_detect(uint32_t pvd_level);
void pwr_disable_power_voltage_detect(void);
void pwr_clear_standby_flag(void);
void pwr_clear_wakeup_flag(void);
void pwr_set_standby_mode(void);
void pwr_set_stop_mode(void);
void pwr_voltage_regulator_on_in_stop(void);
void pwr_voltage_regulator_low_power_in_stop(void);
void pwr_enable_wakeup_pin(void);
void pwr_disable_wakeup_pin(void);
bool pwr_voltage_high(void);
bool pwr_get_standby_flag(void);
bool pwr_get_wakeup_flag(void);

END_DECLS

/**@}*/
#endif
/** @cond */
#else
#warning "pwr_common_v1.h should not be included explicitly, only via pwr.h"
#endif
/** @endcond */


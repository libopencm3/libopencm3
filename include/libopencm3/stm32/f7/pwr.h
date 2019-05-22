/** @defgroup pwr_defines PWR Defines

@brief <b>Defined Constants and Types for the STM32F7xx Power Control</b>

@ingroup STM32F7xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2017 Matthew Lai <m@matthewlai.ca>

@date 12 March 2017

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017 Matthew Lai <m@matthewlai.ca>
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

#ifndef LIBOPENCM3_PWR_H
#define LIBOPENCM3_PWR_H

/**@{*/

/** @defgroup pwr_registers PWR Registers
 * @ingroup STM32F_pwr_defines
@{*/
/** Power control register (PWR_CR1) */
#define PWR_CR1				MMIO32(POWER_CONTROL_BASE + 0x00)

/** Power control/status register (PWR_CSR1) */
#define PWR_CSR1			MMIO32(POWER_CONTROL_BASE + 0x04)

/** Power control register 2 (PWR_CR2) */
#define PWR_CR2				MMIO32(POWER_CONTROL_BASE + 0x08)

/** Power control/status register 2 (PWR_CSR2) */
#define PWR_CSR2			MMIO32(POWER_CONTROL_BASE + 0x0c)
/*@}*/

/** @defgroup pwr_cr1_defines PWR_CR1 values
 * @ingroup STM32F_pwr_defines
@{*/

/* Bits [31:20]: Reserved, must be kept at reset value. */

/** UDEN[19:18]: Under-drive enable in stop mode */
#define PWR_CR1_UDEN_LSB		18
/** @defgroup pwr_uden Under-drive enable in stop mode
@ingroup STM32F_pwr_defines

@{*/
#define PWR_CR1_UDEN_DISABLED		(0x0 << PWR_CR1_UDEN_LSB)
#define PWR_CR1_UDEN_ENABLED		(0x3 << PWR_CR1_UDEN_LSB)
/**@}*/
#define PWR_CR1_UDEN_MASK		(0x3 << PWR_CR1_UDEN_LSB)

/** ODSWEN: Over-drive switching enabled */
#define PWR_CR1_ODSWEN			(1 << 17)

/** ODEN: Over-drive enable */
#define PWR_CR1_ODEN			(1 << 16)

/* VOS[15:14]: Regulator voltage scaling output selection */
#define PWR_CR1_VOS_LSB			14
/** @defgroup pwr_vos Regulator voltage scaling output selection
@ingroup STM32F_pwr_defines

@{*/
#define PWR_CR1_VOS_SCALE_3		(0x1 << PWR_CR1_VOS_LSB)
#define PWR_CR1_VOS_SCALE_2		(0x2 << PWR_CR1_VOS_LSB)
#define PWR_CR1_VOS_SCALE_1		(0x3 << PWR_CR1_VOS_LSB)
/**@}*/
#define PWR_CR1_VOS_MASK		(0x3 << PWR_CR1_VOS_LSB)

/** ADCDC1: Masks extra flash accesses by prefetch (see AN4073) */
#define PWR_CR1_ADCDC1			(1 << 13)

/* Bit 12: Reserved, must be kept at reset value. */

/** MRUDS: Main regulator in deepsleep under-drive mode */
#define PWR_CR1_MRUDS			(1 << 11)

/** LPUDS: Low-power regulator in deepsleep under-drive mode */
#define PWR_CR1_LPUDS			(1 << 10)

/** FPDS: Flash power-down in Stop mode */
#define PWR_CR1_FPDS			(1 << 9)

/** DBP: Disable backup domain write protection */
#define PWR_CR1_DBP			(1 << 8)

/* PLS[7:5]: PVD level selection */
#define PWR_CR1_PLS_LSB			5
/** @defgroup pwr_pls PVD level selection
@ingroup STM32F_pwr_defines

@{*/
#define PWR_CR1_PLS_2V0			(0x0 << PWR_CR_PLS_LSB)
#define PWR_CR1_PLS_2V1			(0x1 << PWR_CR_PLS_LSB)
#define PWR_CR1_PLS_2V3			(0x2 << PWR_CR_PLS_LSB)
#define PWR_CR1_PLS_2V5			(0x3 << PWR_CR_PLS_LSB)
#define PWR_CR1_PLS_2V6			(0x4 << PWR_CR_PLS_LSB)
#define PWR_CR1_PLS_2V7			(0x5 << PWR_CR_PLS_LSB)
#define PWR_CR1_PLS_2V8			(0x6 << PWR_CR_PLS_LSB)
#define PWR_CR1_PLS_2V9			(0x7 << PWR_CR_PLS_LSB)
/**@}*/
#define PWR_CR1_PLS_MASK		(0x7 << PWR_CR_PLS_LSB)

/** PVDE: Power voltage detector enable */
#define PWR_CR1_PVDE			(1 << 4)

/** CSBF: Clear standby flag */
#define PWR_CR1_CSBF			(1 << 3)

/* Bit 2: Reserved, must be kept at reset value. */

/** PDDS: Power down deepsleep */
#define PWR_CR1_PDDS			(1 << 1)

/** LPDS: Low-power deepsleep */
#define PWR_CR1_LPDS			(1 << 0)
/*@}*/

/** @defgroup pwr_csr1_defines PWR_CSR1 values
 * @ingroup STM32F_pwr_defines
@{*/

/* Bits [31:20]: Reserved, must be kept at reset value. */

/* UDRDY[19:18]: Under-drive ready flag */
#define PWR_CSR1_UDRDY_LSB		18
/** @defgroup pwr_udrdy Under-drive ready flag
@ingroup STM32F_pwr_defines

@{*/
#define PWR_CSR1_UDRDY_DISABLED		(0x0 << PWR_CSR1_UDRDY_LSB)
#define PWR_CSR1_UDRDY_ACTIVATED	(0x3 << PWR_CSR1_UDRDY_LSB)
/**@}*/
#define PWR_CSR1_UDRDY_MASK		(0x3 << PWR_CSR1_UDRDY_LSB)

/** ODSWRDY: Over-drive mode switching ready */
#define PWR_CSR1_ODSWRDY		(1 << 17)

/** ODRDY: Over-drive mode ready */
#define PWR_CSR1_ODRDY			(1 << 16)

/* Bit 15: Reserved, must be kept at reset value. */

/** VOSRDY: Regulator voltage scaling output selection ready bit */
#define PWR_CSR1_VOSRDY			(1 << 14)

/* Bits [13:10]: Reserved, must be kept at reset value. */

/** BRE: Backup regulator enable */
#define PWR_CSR1_BRE			(1 << 9)

/** EIWUP: Enable internal wakeup */
#define PWR_CSR1_EIWUP			(1 << 8)

/* Bits [7:4]: Reserved, must be kept at reset value. */

/** BRR: Backup regulator ready */
#define PWR_CSR1_BRR			(1 << 3)

/** PVDO: PVD output */
#define PWR_CSR1_PVDO			(1 << 2)

/** SBF: Standby flag */
#define PWR_CSR1_SBF			(1 << 1)

/** WUIF: Wakeup internal flag */
#define PWR_CSR1_WUIF			(1 << 0)
/*@}*/

/** @defgroup pwr_cr2_defines PWR_CR2 values
 * @ingroup STM32F_pwr_defines
@{*/

/* Bits [31:14]: Reserved, must be kept at reset value. */

/** WUPP6: Wakeup pin polarity bit for PI11 */
#define PWR_CR2_WUPP6			(1 << 13)

/** WUPP5: Wakeup pin polarity bit for PI8 */
#define PWR_CR2_WUPP5			(1 << 12)

/** WUPP4: Wakeup pin polarity bit for PC13 */
#define PWR_CR2_WUPP4			(1 << 11)

/** WUPP3: Wakeup pin polarity bit for PC1 */
#define PWR_CR2_WUPP3			(1 << 10)

/** WUPP2: Wakeup pin polarity bit for PA2 */
#define PWR_CR2_WUPP2			(1 << 9)

/** WUPP1: Wakeup pin polarity bit for PA0 */
#define PWR_CR2_WUPP1			(1 << 8)

/* Bits [7:6]: Reserved, must be kept at reset value. */

/** CWUPF6: Clear Wakeup Pin flag for PI11 */
#define PWR_CR2_CWUPF6			(1 << 5)

/** CWUPF5: Clear Wakeup Pin flag for PI8 */
#define PWR_CR2_CWUPF5			(1 << 4)

/** CWUPF4: Clear Wakeup Pin flag for PC13 */
#define PWR_CR2_CWUPF4			(1 << 3)

/** CWUPF3: Clear Wakeup Pin flag for PC1 */
#define PWR_CR2_CWUPF3			(1 << 2)

/** CWUPF2: Clear Wakeup Pin flag for PA2 */
#define PWR_CR2_CWUPF2			(1 << 1)

/** CWUPF1: Clear Wakeup Pin flag for PA0 */
#define PWR_CR2_CWUPF1			(1 << 0)
/*@}*/

/** @defgroup pwr_csr2_defines PWR_CSR2 values
 * @ingroup STM32F_pwr_defines
@{*/

/* Bits [31:14]: Reserved, must be kept at reset value. */

/** EWUP6: Enable Wakeup pin for PI11 */
#define PWR_CSR2_EWUP6			(1 << 13)

/** EWUP5: Enable Wakeup pin for PI8 */
#define PWR_CSR2_EWUP5			(1 << 12)

/** EWUP4: Enable Wakeup pin for PC13 */
#define PWR_CSR2_EWUP4			(1 << 11)

/** EWUP3: Enable Wakeup pin for PC1 */
#define PWR_CSR2_EWUP3			(1 << 10)

/** EWUP2: Enable Wakeup pin for PA2 */
#define PWR_CSR2_EWUP2			(1 << 19)

/** EWUP1: Enable Wakeup pin for PA0 */
#define PWR_CSR2_EWUP1			(1 << 18)

/* Bits [7:6]: Reserved, must be kept at reset value. */

/** WUPF6: Wakeup Pin flag for PI11 */
#define PWR_CSR2_WUPF6			(1 << 5)

/** WUPF5: Wakeup Pin flag for PI8 */
#define PWR_CSR2_WUPF5			(1 << 4)

/** WUPF4: Wakeup Pin flag for PC13 */
#define PWR_CSR2_WUPF4			(1 << 3)

/** WUPF3: Wakeup Pin flag for PC1 */
#define PWR_CSR2_WUPF3			(1 << 2)

/** WUPF2: Wakeup Pin flag for PA2 */
#define PWR_CSR2_WUPF2			(1 << 1)

/** WUPF1: Wakeup Pin flag for PA0 */
#define PWR_CSR2_WUPF1			(1 << 0)
/*@}*/
/* --- Function prototypes ------------------------------------------------- */

enum pwr_vos_scale {
	PWR_SCALE1, /** <= 180MHz w/o overdrive, <= 216MHz w/ overdrive */
	PWR_SCALE2, /** <= 168MHz w/o overdrive, <= 180MHz w/ overdrive */
	PWR_SCALE3, /** <= 144MHz */
};

BEGIN_DECLS

void pwr_set_vos_scale(enum pwr_vos_scale scale);
void pwr_enable_overdrive(void);
void pwr_disable_overdrive(void);

END_DECLS

/**@}*/

#endif

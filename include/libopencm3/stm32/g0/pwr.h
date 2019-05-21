/** @defgroup pwr_defines PWR Defines
 *
 * @brief <b>Defined Constants and Types for the STM32G0xx PWR Control</b>
 *
 * @ingroup STM32G0xx_defines
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
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
@{*/
/** Power control register 1 (PWR_CR1) */
#define PWR_CR1				MMIO32(POWER_CONTROL_BASE + 0x00)

/** Power control register 2 (PWR_CR2) */
#define PWR_CR2				MMIO32(POWER_CONTROL_BASE + 0x04)

/** Power control register 3 (PWR_CR3) */
#define PWR_CR3				MMIO32(POWER_CONTROL_BASE + 0x08)

/** Power control register 4 (PWR_CR4) */
#define PWR_CR4				MMIO32(POWER_CONTROL_BASE + 0x0c)

/** Power status register 1 (PWR_SR1) */
#define PWR_SR1				MMIO32(POWER_CONTROL_BASE + 0x10)

/** Power status registery 2 (PWR_SR2) */
#define PWR_SR2				MMIO32(POWER_CONTROL_BASE + 0x14)

/** Power status clear register (PWR_SCR) */
#define PWR_SCR				MMIO32(POWER_CONTROL_BASE + 0x18)

#define PWR_PORT_A		MMIO32(POWER_CONTROL_BASE + 0x20)
#define PWR_PORT_B		MMIO32(POWER_CONTROL_BASE + 0x28)
#define PWR_PORT_C		MMIO32(POWER_CONTROL_BASE + 0x30)
#define PWR_PORT_D		MMIO32(POWER_CONTROL_BASE + 0x38)
#define PWR_PORT_E		MMIO32(POWER_CONTROL_BASE + 0x40)
#define PWR_PORT_F		MMIO32(POWER_CONTROL_BASE + 0x48)

#define PWR_PUCR(pwr_port)	MMIO32((pwr_port) + 0x00)
#define PWR_PDCR(pwr_port)	MMIO32((pwr_port) + 0x04)
/**@}*/

/* --- PWR_CR1 values ------------------------------------------------------- */

#define PWR_CR1_LPR				(1 << 14)

#define PWR_CR1_VOS_SHIFT		9
#define PWR_CR1_VOS_MASK		0x3
/** @defgroup pwr_cr1_vos VOS
 * @brief Voltage scaling range selection.
@{*/
#define PWR_CR1_VOS_RANGE_1		1
#define PWR_CR1_VOS_RANGE_2		2
/**@}*/

#define PWR_CR1_DBP				(1 << 8)

#define PWR_CR1_FPD_LPSLP		(1 << 5)
#define PWR_CR1_FPD_LPRUN		(1 << 4)
#define PWR_CR1_FPD_STOP		(1 << 3)

#define PWR_CR1_LPMS_SHIFT		0
#define PWR_CR1_LPMS_MASK		0x07
/** @defgroup pwr_cr1_lpms LPMS
 * @ingroup STM32G0xx_pwr_defines
 * @brief Low-power mode selection
@{*/
#define PWR_CR1_LPMS_STOP_0		0
#define PWR_CR1_LPMS_STOP_1		1
#define PWR_CR1_LPMS_STANDBY	3
#define PWR_CR1_LPMS_SHUTDOWN	4
/**@}*/

/* --- PWR_CR2 values ------------------------------------------------------- */

#define PWR_CR2_PVDRT_SHIFT	4
#define PWR_CR2_PVDRT_MASK	0x07
/** @defgroup pwr_cr2_pvdrt PVDRT
 * @brief Power voltage detector rising threshold selection
@{*/
#define PWR_CR2_PVDRT_2V1	0x00
#define PWR_CR2_PVDRT_2V2	0x01
#define PWR_CR2_PVDRT_2V5	0x02
#define PWR_CR2_PVDRT_2V6	0x03
#define PWR_CR2_PVDRT_2V7	0x04
#define PWR_CR2_PVDRT_2V9	0x05
#define PWR_CR2_PVDRT_3V0	0x06
#define PWR_CR2_PVDRT_PVD_IN	0x07
/**@}*/

#define PWR_CR2_PVDFT_SHIFT	1
#define PWR_CR2_PVDFT_MASK	0x07
/** @defgroup pwr_cr2_pvdft PVDFT
 * @brief Power voltage detector falling threshold selection
@{*/
#define PWR_CR2_PVDFT_2V0	0x00
#define PWR_CR2_PVDFT_2V2	0x01
#define PWR_CR2_PVDFT_2V4	0x02
#define PWR_CR2_PVDFT_2V5	0x03
#define PWR_CR2_PVDFT_2V6	0x04
#define PWR_CR2_PVDFT_2V8	0x05
#define PWR_CR2_PVDFT_2V9	0x06
/**@}*/

#define PWR_CR2_PVDE		(1 << 0)

/* --- PWR_CR3 values ------------------------------------------------------- */

#define PWR_CR3_EIWUL		(1 << 15)
#define PWR_CR3_APC			(1 << 10)
#define PWR_CR3_ULPEN		(1 << 9)
#define PWR_CR3_RRS			(1 << 8)
#define PWR_CR3_EWUP6		(1 << 5)
#define PWR_CR3_EWUP5		(1 << 4)
#define PWR_CR3_EWUP4		(1 << 3)
#define PWR_CR3_EWUP2		(1 << 1)
#define PWR_CR3_EWUP1		(1 << 0)

/* --- PWR_CR4 values ------------------------------------------------------- */

#define PWR_CR4_VBRS		(1 << 9)
#define PWR_CR4_VBE			(1 << 8)
#define PWR_CR4_WP6			(1 << 5)
#define PWR_CR4_WP5			(1 << 4)
#define PWR_CR4_WP4			(1 << 3)
#define PWR_CR4_WP2			(1 << 1)
#define PWR_CR4_WP1			(1 << 0)

/* --- PWR_SR1 values ------------------------------------------------------- */

#define PWR_SR1_WUFI		(1 << 15)
#define PWR_SR1_SBF			(1 << 8)
#define PWR_SR1_WUF6		(1 << 5)
#define PWR_SR1_WUF5		(1 << 4)
#define PWR_SR1_WUF4		(1 << 3)
#define PWR_SR1_WUF2		(1 << 1)
#define PWR_SR1_WUF1		(1 << 0)

/* --- PWR_SR2 values ------------------------------------------------------- */

#define PWR_SR2_PVDO		(1 << 11)
#define PWR_SR2_VOSF		(1 << 10)
#define PWR_SR2_REGLPF		(1 << 9)
#define PWR_SR2_REGLPS		(1 << 8)
#define PWR_SR2_FLASHRDY	(1 << 8)

/* --- PWR_SCR values ------------------------------------------------------- */

#define PWR_SCR_CSBF		(1 << 8)
#define PWR_SCR_CWUF6		(1 << 5)
#define PWR_SCR_CWUF5		(1 << 4)
#define PWR_SCR_CWUF4		(1 << 3)
#define PWR_SCR_CWUF2		(1 << 1)
#define PWR_SCR_CWUF1		(1 << 0)

/* --- Function prototypes ------------------------------------------------- */

enum pwr_vos_scale {
	PWR_SCALE1 = PWR_CR1_VOS_RANGE_1,
	PWR_SCALE2 = PWR_CR1_VOS_RANGE_2,
};

BEGIN_DECLS

void pwr_set_vos_scale(enum pwr_vos_scale scale);

void pwr_disable_backup_domain_write_protect(void);
void pwr_enable_backup_domain_write_protect(void);

void pwr_set_low_power_mode_selection(uint32_t lpms);

void pwr_enable_power_voltage_detect(uint32_t pvdr_level, uint32_t pvdf_level);
void pwr_disable_power_voltage_detect(void);

END_DECLS

/**@}*/
#endif


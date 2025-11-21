/** @defgroup pwr_defines PWR Defines

@brief <b>Defined Constants and Types for the STM32U5xx Power Control</b>

@ingroup STM32U5xx_defines

@version 1.0.0

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2025 ALTracer <11005378+ALTracer@users.noreply.github.com>
 * Copyright (C) 2025 Rachel Mant <git@dragonmux.network>
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

#pragma once
/**@{*/

/** @defgroup pwr_registers PWR Registers
@{*/
/** Power control register 1 */
#define PWR_CR1 MMIO32(PWR_BASE + 0x00U)

/** Power control register 2 */
#define PWR_CR2 MMIO32(PWR_BASE + 0x04U)

/** Power control register 3 */
#define PWR_CR3 MMIO32(PWR_BASE + 0x08U)

/** Power voltage scaling register */
#define PWR_VOSR MMIO32(PWR_BASE + 0x0cU)

/** Power Supply Voltage Monitoring control register */
#define PWR_SVMCR MMIO32(PWR_BASE + 0x10U)

/** Power wake-up control register 1 */
#define PWR_WUCR1 MMIO32(PWR_BASE + 0x14U)

/** Power wake-up control register 2 */
#define PWR_WUCR2 MMIO32(PWR_BASE + 0x18U)

/** Power wake-up control register 3 */
#define PWR_WUCR3 MMIO32(PWR_BASE + 0x1cU)

/** Power backup domain control register 1 */
#define PWR_BDCR1 MMIO32(PWR_BASE + 0x20U)

/** Power backup domain control register 2 */
#define PWR_BDCR2 MMIO32(PWR_BASE + 0x24U)

/** Power disable backup domain register */
#define PWR_DBPR MMIO32(PWR_BASE + 0x28U)

/** Power USB-C power delivery register */
#define PWR_UCPDR MMIO32(PWR_BASE + 0x2cU)

/** Power security config register */
#define PWR_SECCFGR MMIO32(PWR_BASE + 0x30U)

/** Power privacy config register */
#define PWR_PRIVCFGR MMIO32(PWR_BASE + 0x34U)

/** Power status register */
#define PWR_SR MMIO32(PWR_BASE + 0x38U)

/** Power Supply Voltage Monitoring status register */
#define PWR_SVMSR MMIO32(PWR_BASE + 0x3cU)

/** Power backup domain status register */
#define PWR_BDSR MMIO32(PWR_BASE + 0x40U)

/** Power wake-up status register */
#define PWR_WUSR MMIO32(PWR_BASE + 0x44U)

/** Power wake-up status clear register */
#define PWR_WUSCR MMIO32(PWR_BASE + 0x48U)

/** Power apply pull configuration register */
#define PWR_APCR MMIO32(PWR_BASE + 0x4cU)

/** Power port A pull-up control register */
#define PWR_PUCRA MMIO32(PWR_BASE + 0x50U)

/** Power port A pull-down control register */
#define PWR_PDCRA MMIO32(PWR_BASE + 0x54U)

/** Power port B pull-up control register */
#define PWR_PUCRB MMIO32(PWR_BASE + 0x58U)

/** Power port B pull-down control register */
#define PWR_PDCRB MMIO32(PWR_BASE + 0x5cU)

/** Power port C pull-up control register */
#define PWR_PUCRC MMIO32(PWR_BASE + 0x60U)

/** Power port C pull-down control register */
#define PWR_PDCRC MMIO32(PWR_BASE + 0x64U)

/** Power port D pull-up control register */
#define PWR_PUCRD MMIO32(PWR_BASE + 0x68U)

/** Power port D pull-down control register */
#define PWR_PDCRD MMIO32(PWR_BASE + 0x6cU)

/** Power port E pull-up control register */
#define PWR_PUCRE MMIO32(PWR_BASE + 0x70U)

/** Power port E pull-down control register */
#define PWR_PDCRE MMIO32(PWR_BASE + 0x74U)

/** Power port F pull-up control register */
#define PWR_PUCRF MMIO32(PWR_BASE + 0x78U)

/** Power port F pull-down control register */
#define PWR_PDCRF MMIO32(PWR_BASE + 0x7cU)

/** Power port G pull-up control register */
#define PWR_PUCRG MMIO32(PWR_BASE + 0x80U)

/** Power port G pull-down control register */
#define PWR_PDCRG MMIO32(PWR_BASE + 0x84U)

/** Power port H pull-up control register */
#define PWR_PUCRH MMIO32(PWR_BASE + 0x88U)

/** Power port H pull-down control register */
#define PWR_PDCRH MMIO32(PWR_BASE + 0x8cU)

/** Power port I pull-up control register */
#define PWR_PUCRI MMIO32(PWR_BASE + 0x90U)

/** Power port I pull-down control register */
#define PWR_PDCRI MMIO32(PWR_BASE + 0x94U)

/** Power port J pull-up control register */
#define PWR_PUCRJ MMIO32(PWR_BASE + 0x98U)

/** Power port J pull-down control register */
#define PWR_PDCRJ MMIO32(PWR_BASE + 0x9cU)

/** Power control register 4 */
#define PWR_CR4 MMIO32(PWR_BASE + 0xa8U)

/** Power control register 5 */
#define PWR_CR5 MMIO32(PWR_BASE + 0xacU)

/**@}*/

/** SVMC Register Bits */
/** V_DDUSB independent USB supply valid */
#define PWR_SVMCR_USV (1U << 28U)
/** V_DDUSB independent USB voltage monitor enable */
#define PWR_SVMCR_UVMEN (1U << 24U)

/** SVMS Register Bits */
#define PWR_SVMSR_VDDUSBRDY (1U << 24U)

BEGIN_DECLS

/** @defgroup pwr_peripheral_api PWR Peripheral API
 * @ingroup peripheral_apis
@{*/

/** Remove isolation of power/logic to USB transceivers once the VDDUSB supply is present. */
void pwr_enable_vddusb(void);
/**@}*/

END_DECLS

/**@}*/

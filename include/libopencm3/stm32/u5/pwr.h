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
#define PWR_CR1		MMIO32(PWR_BASE + 0x00)

/** Power control register 2 */
#define PWR_CR2		MMIO32(PWR_BASE + 0x04)

/** Power control register 3 */
#define PWR_CR3		MMIO32(PWR_BASE + 0x08)

/** PWR voltage scaling register */
#define PWR_VOSR	MMIO32(PWR_BASE + 0x0C)

/** PWR Supply Voltage Monitoring control register */
#define PWR_SVMCR	MMIO32(PWR_BASE + 0x10)

/** PWR Supply Voltage Monitoring status register */
#define PWR_SVMSR	MMIO32(PWR_BASE + 0x3C)

/**@}*/

/** SVMC Register Bits */
/** V_DDUSB independent USB supply valid */
#define PWR_SVMCR_USV		(1U << 28U)
/** V_DDUSB independent USB voltage monitor enable */
#define PWR_SVMCR_UVMEN		(1U << 24U)

/** SVMS Register Bits */
#define PWR_SVMSR_VDDUSBRDY	(1U << 24U)

BEGIN_DECLS

/** @defgroup pwr_peripheral_api PWR Peripheral API
 * @ingroup peripheral_apis
@{*/

/** Remove isolation of power/logic to USB transceivers once the VDDUSB supply is present. */
void pwr_enable_vddusb(void);
/**@}*/

END_DECLS

/**@}*/

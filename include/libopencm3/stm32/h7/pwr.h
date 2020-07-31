/** @defgroup pwr_defines PWR Defines

@brief <b>Defined Constants and Types for the STM32H7xx Power Control</b>

@ingroup STM32H7xx_defines

@version 1.0.0

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Brian Viele <vielster@allocor.tech>
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
/** Power control register. */
#define PWR_CR1         MMIO32(POWER_CONTROL_BASE + 0x00)

/** Power control/status register. */
#define PWR_CSR1        MMIO32(POWER_CONTROL_BASE + 0x04)

/** Power control register 2. */
#define PWR_CR2         MMIO32(POWER_CONTROL_BASE + 0x08)

/** Power control register 3. */
#define PWR_CR3         MMIO32(POWER_CONTROL_BASE + 0x0C)

/** CPU Power control register 3. */
#define PWR_CPUCR       MMIO32(POWER_CONTROL_BASE + 0x10)

/** D3 Domain Power Control register. */
#define PWR_D3CR        MMIO32(POWER_CONTROL_BASE + 0x18)

/** Wakeup Domain Power Control register. */
#define PWR_WKUPCR      MMIO32(POWER_CONTROL_BASE + 0x20)

/*@}*/

/** VOS[15:14]: Regulator voltage scaling output selection */
#define PWR_CR1_SVOS_SHIFT        14
#define PWR_CR1_SVOS_SCALE_3      (0x3)
#define PWR_CR1_SVOS_SCALE_4      (0x2)
#define PWR_CR1_SVOS_SCALE_5      (0x1)

#define PWR_CR1_SVOS_MASK         (0x3)

/** DBP[8]: Disable backup domain write protection. */
#define PWR_CR1_DBP               (1 << 8)

/** CSR1 Register Bits */
#define PWR_CSR1_AVDO             BIT16
#define PWR_CSR1_ACTVOS_SHIFT     14
#define PWR_CSR1_ACTVOSRDY        BIT13
#define PWR_CSR1_PVDO             BIT4

/** CR3 Register Bits */
#define PWR_CR3_USB33RDY          BIT26
#define PWR_CR3_USBREGEN          BIT25
#define PWR_CR3_USB33DEN          BIT24
#define PWR_CR3_VBRS              BIT9
#define PWR_CR3_VBE               BIT8
#define PWR_CR3_SCUEN             BIT2
#define PWR_CR3_LDOEN             BIT1
#define PWR_CR3_BYPASS            BIT0

/** D3CR Register Bits */
#define PWR_D3CR_VOS_SHIFT        14
#define PWR_D3CR_VOSRDY           BIT13

#define PWR_D3CR_VOS_SCALE_3      (0x1)
#define PWR_D3CR_VOS_SCALE_2      (0x2)
#define PWR_D3CR_VOS_SCALE_1      (0x3)
#define PWR_D3CR_VOS_MASK         (0x03)

enum pwr_svos_scale {
  PWR_SVOS_SCALE3 = PWR_CR1_SVOS_SCALE_3 << PWR_CR1_SVOS_SHIFT,
  PWR_SVOS_SCALE4 = PWR_CR1_SVOS_SCALE_4 << PWR_CR1_SVOS_SHIFT,
  PWR_SVOS_SCALE5 = PWR_CR1_SVOS_SCALE_5 << PWR_CR1_SVOS_SHIFT,
};

enum pwr_vos_scale {
  PWR_VOS_SCALE_0 = 0,    /* Note: This state requires SYSCFG ODEN set. */
  PWR_VOS_SCALE_1 = (PWR_D3CR_VOS_SCALE_1 << PWR_D3CR_VOS_SHIFT),
  PWR_VOS_SCALE_2 = (PWR_D3CR_VOS_SCALE_2 << PWR_D3CR_VOS_SHIFT),
  PWR_VOS_SCALE_3 = (PWR_D3CR_VOS_SCALE_3 << PWR_D3CR_VOS_SHIFT)
};

BEGIN_DECLS

/** @defgroup pwr_peripheral_api PWR Peripheral API
 * @ingroup peripheral_apis
@{*/

/** Set power subsystem to utilize the LDO for CPU. */
void pwr_set_mode_ldo(void);

/** Set the voltage scaling/strength for the internal LDO when in Stop mode.
 * @param[in] scale  Voltage scale value to set.
 */
void pwr_set_svos_scale(enum pwr_svos_scale scale);

/** Set the voltage scaling/strength for the internal LDO while running.
 * @param[in] scale  Voltage scale value to set.
 */
void pwr_set_vos_scale(enum pwr_vos_scale scale);
/**@}*/


END_DECLS

/**@}*/

#endif

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

#pragma once
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

/** D3 Domain Power Control register.
  * Note: Referred to as PWR_SRDCR (SmartRun Domain Control) on LP devices.
  *       The VOS bitfield differs between the two implementations (unfortunately).
  */
#define PWR_D3CR        MMIO32(POWER_CONTROL_BASE + 0x18)
#define PWR_SRDCR       MMIO32(POWER_CONTROL_BASE + 0x18)

/** Wakeup Domain Power Control register. */
#define PWR_WKUPCR      MMIO32(POWER_CONTROL_BASE + 0x20)

/**@}*/

/** VOS[15:14]: Regulator voltage scaling output selection */
#define PWR_CR1_SVOS_SHIFT        14
#define PWR_CR1_SVOS_MASK         (0x3)
#define PWR_CR1_SVOS_SCALE_3      (0x3)
#define PWR_CR1_SVOS_SCALE_4      (0x2)
#define PWR_CR1_SVOS_SCALE_5      (0x1)

/** SmartRun domain AHB memory shut-off in DStop/DStop2 low-power mode */
#define PWR_CR1_SRDRAMSO          BIT27
/** high-speed interfaces USB and FDCAN memory shut-off in DStop/DStop2 mode */
#define PWR_CR1_HSITFSO           BIT26
/** GFXMMU and JPEG memory shut-off in DStop/DStop2 mode */
#define PWR_CR1_GFXSO             BIT25
/** instruction TCM and ETM memory shut-off in DStop/DStop2 mode */
#define PWR_CR1_ITCMSO            BIT24
/** AHB SRAM2 shut-off in DStop/DStop2 mode */
#define PWR_CR1_AHBRAM2SO         BIT23
/** AHB SRAM1 shut-off in DStop/DStop2 mode */
#define PWR_CR1_AHBRAM1SO         BIT22
/** AXI SRAM3 shut-off in DStop/DStop2 mode */
#define PWR_CR1_AXIRAM3SO         BIT21
/** AXI SRAM2 shut-off in DStop/DStop2 mode */
#define PWR_CR1_AXIRAM2SO         BIT20
/** AXI SRAM1 shut-off in DStop/DStop2 mode */
#define PWR_CR1_AXIRAM1SO         BIT19
/** voltage threshold detected by the AVD.  */
#define PWR_CR1_ALS_SHIFT         17
#define PWR_CR1_ALS_MASK          0x3
#define PWR_CR1_ALS_1P7V          0x0
#define PWR_CR1_ALS_2P1V          0x1
#define PWR_CR1_ALS_2P5V          0x2
#define PWR_CR1_ALS_2P8V          0x3
/** peripheral voltage monitor on V DDA enable  */
#define PWR_CR1_AVDEN             BIT16
/** analog voltage ready
 *  This bit is only used when the analog switch boost needs to be enabled (see BOOSTE bit).
 *  It must be set by software when the expected V DDA analog supply level is available.
 *  The correct analog supply level is indicated by the AVDO bit (PWR_CSR1 register) after
 *  setting the AVDEN bit and selecting the supply level to be monitored (ALS bits).
 */
#define PWR_CR1_AVD_READY         BIT13
/** analog switch VBoost control
 *  This bit enables the booster to guarantee the analog switch AC performance when the V DD
 *  supply voltage is below 2.7 V (reduction of the total harmonic distortion to have the same
 *  switch performance over the full supply voltage range)
 *  The V DD supply voltage can be monitored through the PVD and the PLS bits.
 */
#define PWR_CR1_BOOSTE            BIT12
/** DBP[8]: Disable backup domain write protection. */
#define PWR_CR1_DBP               BIT8

/** CSR1 Register Bits */
#define PWR_CSR1_MMCVDO           BIT17
#define PWR_CSR1_AVDO             BIT16
#define PWR_CSR1_ACTVOS_SHIFT     14
#define PWR_CSR1_ACTVOSRDY        BIT13
#define PWR_CSR1_PVDO             BIT4

/** CR2 Register Bits */
/** temperature level monitoring versus high threshold */
#define PWR_CR2_TEMPH             BIT23
/** temperature level monitoring versus low threshold */
#define PWR_CR2_TEMPL             BIT22
/** backup regulator ready */
#define PWR_CR2_BRRDY             BIT16
/** V BAT and temperature monitoring enable */
#define PWR_CR2_MONEN             BIT4
/** backup regulator enable */
#define PWR_CR2_BREN              BIT0

/** CR3 Register Bits */
#define PWR_CR3_USB33RDY          BIT26
#define PWR_CR3_USBREGEN          BIT25
#define PWR_CR3_USB33DEN          BIT24
/** SMPS step-down converter external supply ready */
#define PWR_CR3_SMPSEXTRDY        BIT16
/** V BAT charging resistor selection  */
#define PWR_CR3_VBRS              BIT9
/** V BAT charging enable */
#define PWR_CR3_VBE               BIT8

/** @defgroup pwr_cr3_smpslevel SMPS step-down converter voltage output level selection
 *  This setting is used when both the LDO and SMPS step-down converter are enabled with SMPSEN and
 *  LDOEN enabled or when SMPSEXTHP is enabled. In this case SMPSLEVEL must be written with
 *  a value different than 00 to reach the appropriate voltage, based on VOS or external supply.
 * @{
 */
#define PWR_CR3_SMPSLEVEL_VOS     0x0
#define PWR_CR3_SMPSLEVEL_1P8V    0x1
#define PWR_CR3_SMPSLEVEL_2P5V    0x2
/**@}*/
#define PWR_CR3_SMPSLEVEL_SHIFT   4
#define PWR_CR3_SMPSLEVEL_MASK    0x3

/** SMPS step-down converter external power delivery selection */
#define PWR_CR3_SMPSEXTHP         BIT3
#define PWR_CR3_SCUEN             BIT2
/* BIT2 Is overloaded on devices with SMPS as the SMPSEN bit. */
#define PWR_CR3_SMPSEN            BIT2
#define PWR_CR3_LDOEN             BIT1
#define PWR_CR3_BYPASS            BIT0

/** D3CR Register Bits */
#define PWR_D3CR_VOSRDY           BIT13
#define PWR_D3CR_VOS_SHIFT        14
#define PWR_D3CR_VOS_MASK         (0x03)
/** VOS0 is implemented on STM32H72x/3x with simple VOS setting.
 *  STM32H742/43/45/47/50/53/55/57 SCALE0 this as SCALE1 + SYSCFG.ODEN */
#define PWR_D3CR_VOS_SCALE_0      (0x0)
#define PWR_D3CR_VOS_SCALE_3      (0x1)
#define PWR_D3CR_VOS_SCALE_2      (0x2)
#define PWR_D3CR_VOS_SCALE_1      (0x3)
/** SRDCR Register Bits */
#define PWR_SRDCR_VOSRDY          BIT13
#define PWR_SRDCR_VOS_SHIFT       14
#define PWR_SRDCR_VOS_MASK        (0x03)
#define PWR_SRDCR_VOS_SCALE_3     (0x0)
#define PWR_SRDCR_VOS_SCALE_2     (0x1)
#define PWR_SRDCR_VOS_SCALE_1     (0x2)
#define PWR_SRDCR_VOS_SCALE_0     (0x3)

enum pwr_sys_mode {
  PWR_SYS_SCU_LDO = 0,      /**< STM32H742/43/50/53 has special SCUEN handling, use for LDO. */
  PWR_SYS_SCU_BYPASS,       /**< STM32H742/43/50/53 has special SCUEN handling, use for bypass. */
  PWR_SYS_LDO,              /**< Devices with SMPS use this to run from LDO only. */
  PWR_SYS_SMPS_DIRECT,      /**< Disable LDO, apply SMPS direct to CPU using VOS. */
  PWR_SYS_SMPS_LDO,         /**< SMPS supplies internal LDO. */
  PWR_SYS_EXT_SMPS_LDO,     /**< SMPS supplies external power, and CPU through LDO. */
  PWR_SYS_EXT_SMPS_LDO_BYP, /**< SMPS supplies external power, bypasses LDO (e.g. external LDO) */
  PWR_SYS_BYPASS            /**< Disable all internal power supplies. */
};

enum pwr_svos_scale {
  PWR_SVOS_SCALE3 = PWR_CR1_SVOS_SCALE_3 << PWR_CR1_SVOS_SHIFT,
  PWR_SVOS_SCALE4 = PWR_CR1_SVOS_SCALE_4 << PWR_CR1_SVOS_SHIFT,
  PWR_SVOS_SCALE5 = PWR_CR1_SVOS_SCALE_5 << PWR_CR1_SVOS_SHIFT,
};

enum pwr_vos_scale {
  PWR_VOS_SCALE_UNDEFINED = 0,
  PWR_VOS_SCALE_0,
  PWR_VOS_SCALE_1,
  PWR_VOS_SCALE_2,
  PWR_VOS_SCALE_3,
};

BEGIN_DECLS

/** @defgroup pwr_peripheral_api PWR Peripheral API
 * @ingroup peripheral_apis
@{*/
/** Set power subsystem to utilize the LDO for CPU. */
void pwr_set_mode_ldo(void);

/** Specific STM32H742/43/50/53 LDO mode setting.. */
void pwr_set_mode_scu_ldo(void);

/** Set power subsystem to utilize the SMPS run through the LDO for CPU.
 * @param[in] supply_external  Supply is powering external circuits, enable high power mode.
 * @param[in] smps_level  Voltage level from @ref pwr_cr3_smpslevel (1.8V/2.5V)
 * @param[in] use_ldo  Set this value to true if the internal LDO should be enabled.
 */
void pwr_set_mode_smps_ldo(bool supply_external, uint32_t smps_level, bool use_ldo);

/** Set power system based on "System Supply Configurations" table in reference manual.
 * @param[in] mode  Mode mapping to a mode in the system configuration. Note special SCU modes.
 * @param[in] smps_level  Optional, only needed if using an EXT_SMPS or SMPS_LDO mode.
 * Provide zero if unused, otherwise @ref pwr_cr3_smpslevel.
 */
void pwr_set_mode(enum pwr_sys_mode mode, uint8_t smps_level);

/** Set power subsystem to bypass all internal supplies. */
void pwr_set_mode_bypass(void);

/** Specific STM32H742/43/50/53 Bypsass mode setting.. */
void pwr_set_mode_scu_bypass(void);

/** Set the voltage scaling/strength for the internal SMPS/LDO when in Stop mode.
 * @param[in] scale  Voltage scale value to set.
 */
void pwr_set_svos_scale(enum pwr_svos_scale scale);

/** Set the voltage scaling/strength for the internal SMPS/LDO while running.
 * @param[in] scale  Voltage scale value to set.
 */
void pwr_set_vos_scale(enum pwr_vos_scale scale);
/**@}*/


END_DECLS

/**@}*/

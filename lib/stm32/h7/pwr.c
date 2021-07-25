/**
 * @brief <b>libopencm3 STM32H7xx Power Control</b>
 *
 * @version 1.0.0
 *
 * @date 16 December, 2019
 *
 * This library supports the power control system for the
 * STM32H7 series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Copyright (C) 2017 Matthew Lai <m@matthewlai.ca>
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
#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/dbgmcu.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/syscfg.h>

/* DBGMCU_IDC DEV ID values needed to account for variations between part types. */
#define DBGMCU_IDCODE_DEV_ID_STM32H74X_5X			0x450
#define DBGMCU_IDCODE_DEV_ID_STM32H7A3_B3_B0		0x480

void pwr_set_mode_ldo(void) {
	/* Per table in manual for SMPS, mask and set SMPSEN=0 : LDOEN=1 : BYPASS=0. */
	const uint32_t cr3_mask = (PWR_CR3_SMPSEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS);
	PWR_CR3 = (PWR_CR3 & ~cr3_mask) | (PWR_CR3_LDOEN);
}

void pwr_set_mode_scu_ldo(void) {
	const uint32_t cr3_mask = (PWR_CR3_SCUEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS);
	PWR_CR3 = (PWR_CR3 & ~cr3_mask) | (PWR_CR3_SCUEN | PWR_CR3_LDOEN);
}

void pwr_set_mode_smps_ldo(bool supply_external, uint32_t smps_level, bool use_ldo) {
	uint32_t cr3_mask, cr3_set;
	cr3_mask = (PWR_CR3_SMPSEXTHP | PWR_CR3_SMPSEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS);
	cr3_mask |= PWR_CR3_SMPSLEVEL_MASK << PWR_CR3_SMPSLEVEL_SHIFT;

	/* Default, take in unconditional settings, will OR in the rest. */
	cr3_set = PWR_CR3_SMPSEN | (smps_level << PWR_CR3_SMPSLEVEL_SHIFT);
	if (supply_external) {
		cm3_assert(smps_level != PWR_CR3_SMPSLEVEL_VOS);  	/* Unsupported setting! */
		cr3_set |= PWR_CR3_SMPSEXTHP;
	}

	if (use_ldo) {
		cr3_set |= PWR_CR3_LDOEN;
	}
	PWR_CR3 = (PWR_CR3 & ~cr3_mask) | cr3_set;
}

void pwr_set_mode_bypass(void) {
	const uint32_t cr3_mask = (PWR_CR3_SMPSEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS);
	PWR_CR3 = (PWR_CR3 & ~cr3_mask) | PWR_CR3_BYPASS;
}

void pwr_set_mode_scu_bypass(void) {
	const uint32_t cr3_mask = (PWR_CR3_SCUEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS);
	PWR_CR3 = (PWR_CR3 & ~cr3_mask) | (PWR_CR3_SCUEN | PWR_CR3_BYPASS);
}


void pwr_set_mode(enum pwr_sys_mode mode, uint8_t smps_level) {
	switch (mode) {
		case PWR_SYS_SCU_LDO:
			pwr_set_mode_scu_ldo();
			break;
		case PWR_SYS_SCU_BYPASS:
			pwr_set_mode_scu_bypass();
			break;
		case PWR_SYS_LDO:
			pwr_set_mode_ldo();
			break;
		case PWR_SYS_SMPS_DIRECT:
		case PWR_SYS_SMPS_LDO:
			pwr_set_mode_smps_ldo(false, PWR_CR3_SMPSLEVEL_VOS, mode == PWR_SYS_SMPS_LDO);
			break;
		case PWR_SYS_EXT_SMPS_LDO:
		case PWR_SYS_EXT_SMPS_LDO_BYP:
			pwr_set_mode_smps_ldo(false, smps_level, mode == PWR_SYS_EXT_SMPS_LDO);
			break;
		case PWR_SYS_BYPASS:
			pwr_set_mode_bypass();
			break;
	}
	/* Wait for power supply status to state ready. */
	while (!(PWR_CSR1 & PWR_CSR1_ACTVOSRDY));
}

void pwr_set_svos_scale(enum pwr_svos_scale scale)
{
	uint32_t pwr_cr1_reg = PWR_CR1;
	pwr_cr1_reg = (pwr_cr1_reg & ~(PWR_CR1_SVOS_MASK  << PWR_CR1_SVOS_SHIFT));
	PWR_CR1 = pwr_cr1_reg | scale;
}

void pwr_set_vos_scale(enum pwr_vos_scale scale) {
	static const uint8_t srdcr_vos_values[] = {
		PWR_SRDCR_VOS_SCALE_0,
		PWR_SRDCR_VOS_SCALE_1,
		PWR_SRDCR_VOS_SCALE_2,
		PWR_SRDCR_VOS_SCALE_3,
	};
	static const uint8_t d3cr_vos_values[] = {
		PWR_D3CR_VOS_SCALE_0,
		PWR_D3CR_VOS_SCALE_1,
		PWR_D3CR_VOS_SCALE_2,
		PWR_D3CR_VOS_SCALE_3,
	};
	cm3_assert(scale != PWR_VOS_SCALE_UNDEFINED); 	/* Make sure this has been set. */

	/* "SmartRun Domain" devices (presently only know of A3/B3/B0) have different mapping.
	 * Note: DBGMCU_IDCODE_DEV_ID_STM32H7A3 covers all three of these models.
	 */
	uint32_t devid = DBGMCU_IDCODE & DBGMCU_IDCODE_DEV_ID_MASK;
	if (devid == DBGMCU_IDCODE_DEV_ID_STM32H7A3_B3_B0) {
		const uint32_t srdcr_vos_mask = (PWR_SRDCR_VOS_MASK << PWR_SRDCR_VOS_SHIFT);
		const uint32_t vos_value = srdcr_vos_values[scale - 1] << PWR_SRDCR_VOS_SHIFT;
		PWR_SRDCR = (PWR_SRDCR & ~srdcr_vos_mask) | vos_value;
	} else {
		/* Get the VOS value for the non-smart domain types. */
		uint32_t d3cr_vos = (uint32_t)d3cr_vos_values[scale - 1] << PWR_D3CR_VOS_SHIFT;
		uint32_t d3cr_masked = PWR_D3CR & ~(PWR_D3CR_VOS_MASK << PWR_D3CR_VOS_SHIFT);
		/*  STM32H742/43/45/47/50/53/55/57 have special handling of VOS0, which is to set
		 *  VOS1, and also enable the ODEN in the SYSCFG_PWRCR.
		 *  Note: Conveniently, all devices with this setup share a devid, so pick one.
		 */
		if (devid == DBGMCU_IDCODE_DEV_ID_STM32H74X_5X) {
			rcc_periph_clock_enable(RCC_SYSCFG);  /* Ensure we can access ODEN. */
			/* Per the manual, VOS0 is implemented as VOS1 + ODEN. Handle this case. */
			if (scale == PWR_VOS_SCALE_0) {
				PWR_D3CR = d3cr_masked | (PWR_D3CR_VOS_SCALE_1 << PWR_SRDCR_VOS_SHIFT);
				SYSCFG_PWRCR |= SYSCFG_PWRCR_ODEN;
			} else {
				SYSCFG_PWRCR &= ~SYSCFG_PWRCR_ODEN;
				PWR_D3CR = d3cr_masked | d3cr_vos;
			}
		} else {
			PWR_D3CR = d3cr_masked | d3cr_vos;
		}
	}
	while (!(PWR_D3CR & PWR_D3CR_VOSRDY));	/* VOSRDY bit is same between D3CR and SRDCR. */
}

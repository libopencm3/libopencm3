/** @defgroup opamp_defines OPAMP Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the STM32G4xx
 * Operational Amplifier module</b>
 *
 * @ingroup STM32G4xx_defines
 *
 * @version 1.0.0
 *
 * @date 10 Jul 2020
 *
 *LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_OPAMP_H
#define LIBOPENCM3_OPAMP_H
/**@{*/

#include <stdbool.h>
#include <stdint.h>

#define OPAMP1				(OPAMP_BASE + 0x00)
#define OPAMP2				(OPAMP_BASE + 0x04)
#define OPAMP3				(OPAMP_BASE + 0x08)
#define OPAMP4				(OPAMP_BASE + 0x0C)
#define OPAMP5				(OPAMP_BASE + 0x10)
#define OPAMP6				(OPAMP_BASE + 0x14)

/* OpAmp registers */

/* Control and status register (OPAMPx_CSR) */
#define OPAMP_CSR(opamp_base)		MMIO32((opamp_base) + 0x00)
#define OPAMP1_CSR			OPAMP_CSR(OPAMP1)
#define OPAMP2_CSR			OPAMP_CSR(OPAMP2)
#define OPAMP3_CSR			OPAMP_CSR(OPAMP3)
#define OPAMP4_CSR			OPAMP_CSR(OPAMP4)
#define OPAMP5_CSR			OPAMP_CSR(OPAMP5)
#define OPAMP6_CSR			OPAMP_CSR(OPAMP6)

#define OPAMP_TCMR(opamp_base)		MMIO32((opamp_base) + 0x18)
#define OPAMP1_TCMR			OPAMP_TCMR(OPAMP1)
#define OPAMP2_TCMR			OPAMP_TCMR(OPAMP2)
#define OPAMP3_TCMR			OPAMP_TCMR(OPAMP3)
#define OPAMP4_TCMR			OPAMP_TCMR(OPAMP4)
#define OPAMP5_TCMR			OPAMP_TCMR(OPAMP5)
#define OPAMP6_TCMR			OPAMP_TCMR(OPAMP6)

/* OPAMPx_CSR values */

#define OPAMP_CSR_LOCK			(0x1 << 31)

#define OPAMP_CSR_CALOUT_MASK		(0x1)
#define OPAMP_CSR_CALOUT_SHIFT		(30)
#define OPAMP_CSR_CALOUT_UNSUCC		(0x0)
#define OPAMP_CSR_CALOUT_SUCC		(0x1)

#define OPAMP_CSR_TRIMOFFSETN_MASK	(0x1F)
#define OPAMP_CSR_TRIMOFFSETN_SHIFT	(24)

#define OPAMP_CSR_TRIMOFFSETP_MASK	(0x1F)
#define OPAMP_CSR_TRIMOFFSETP_SHIFT	(19)

#define OPAMP_CSR_PGA_GAIN_MASK		(0x1F)
#define OPAMP_CSR_PGA_GAIN_SHIFT	(14)

/* Non-inverting gain*/
#define OPAMP_CSR_PGA_GAIN_2					(0x00)
#define OPAMP_CSR_PGA_GAIN_4					(0x01)
#define OPAMP_CSR_PGA_GAIN_8					(0x02)
#define OPAMP_CSR_PGA_GAIN_16					(0x03)
#define OPAMP_CSR_PGA_GAIN_32					(0x04)
#define OPAMP_CSR_PGA_GAIN_64					(0x05)
/* Inverting gain -n/non-inverting gain y with VINM0 pin for input bias */
#define OPAMP_CSR_PGA_INV_GAIN_MINUS_1_GAIN_2_VM0		(0x08)
#define OPAMP_CSR_PGA_INV_GAIN_MINUS_3_GAIN_4_VM0		(0x09)
#define OPAMP_CSR_PGA_INV_GAIN_MINUS_7_GAIN_8_VM0		(0x0A)
#define OPAMP_CSR_PGA_INV_GAIN_MINUS_15_GAIN_16_VM0		(0x0B)
#define OPAMP_CSR_PGA_INV_GAIN_MINUS_31_GAIN_32_VM0		(0x0C)
#define OPAMP_CSR_PGA_INV_GAIN_MINUS_63_GAIN_64_VM0		(0x0D)
/* Non-inverting gain with filtering on VINM0 */
#define OPAMP_CSR_PGA_FILT_VM0_GAIN_2				(0x10)
#define OPAMP_CSR_PGA_FILT_VM0_GAIN_4				(0x11)
#define OPAMP_CSR_PGA_FILT_VM0_GAIN_8				(0x12)
#define OPAMP_CSR_PGA_FILT_VM0_GAIN_16				(0x13)
#define OPAMP_CSR_PGA_FILT_VM0_GAIN_32				(0x14)
#define OPAMP_CSR_PGA_FILT_VM0_GAIN_64				(0x15)
/* Inverting gain -x/non-inverting gain y with VINM0 pin for input bias
 * VINM1 for filtering*/
#define OPAMP_CSR_PGA_FILT_VM1_INV_GAIN_MINUS_1_GAIN_2_VM0	(0x18)
#define OPAMP_CSR_PGA_FILT_VM1_INV_GAIN_MINUS_3_GAIN_4_VM0	(0x19)
#define OPAMP_CSR_PGA_FILT_VM1_INV_GAIN_MINUS_7_GAIN_8_VM0	(0x1A)
#define OPAMP_CSR_PGA_FILT_VM1_INV_GAIN_MINUS_15_GAIN_16_VM0	(0x1B)
#define OPAMP_CSR_PGA_FILT_VM1_INV_GAIN_MINUS_31_GAIN_32_VM0	(0x1C)
#define OPAMP_CSR_PGA_FILT_VM1_INV_GAIN_MINUS_63_GAIN_64_VM0	(0x1D)

#define OPAMP_CSR_CALSEL_MASK		(0x3)
#define OPAMP_CSR_CALSEL_SHIFT		(12)
#define OPAMP_CSR_CALSEL_3P3_PERCENT	(0x0)
#define OPAMP_CSR_CALSEL_10_PERCENT	(0x1)
#define OPAMP_CSR_CALSEL_50_PERCENT	(0x2)
#define OPAMP_CSR_CALSEL_90_PERCENT	(0x3)

#define OPAMP_CSR_CALON			(0x1 << 11)

#define OPAMP_CSR_OPAINTOEN		(0x1 << 8)

#define OPAMP_CSR_OPAHSM		(0x1 << 7)

#define OPAMP_CSR_VM_SEL_MASK		(0x3)
#define OPAMP_CSR_VM_SEL_SHIFT		(5)
#define OPAMP_CSR_VM_SEL_VINM0_IN	(0x0)
#define OPAMP_CSR_VM_SEL_VINM1_IN	(0x1)
#define OPAMP_CSR_VM_SEL_PGA_MODE	(0x2)
#define OPAMP_CSR_VM_SEL_OUT_IN		(0x3)

#define OPAMP_CSR_USER_TRIM		(0x1 << 4)

#define OPAMP_CSR_VP_SEL_MASK		(0x3)
#define OPAMP_CSR_VP_SEL_SHIFT		(2)
#define OPAMP_CSR_VP_SEL_VINP0		(0x0)
#define OPAMP_CSR_VP_SEL_VINP1		(0x1)
#define OPAMP_CSR_VP_SEL_VINP2		(0x2)

#define OPAMP1_CSR_VP_SEL_DAC3CH1	(0x3)
#define OPAMP2_CSR_VP_SEL_VINP3		(0x3)
#define OPAMP3_CSR_VP_SEL_DAC3CH2	(0x3)
#define OPAMP4_CSR_VP_SEL_DAC4CH1	(0x3)
#define OPAMP5_CSR_VP_SEL_DAC4CH2	(0x3)
#define OPAMP6_CSR_VP_SEL_DAC3CH1	(0x3)

#define OPAMP_CSR_FORCE_VP		(0x1 << 1)

#define OPAMP_CSR_EN			(0x1 << 0)

BEGIN_DECLS

void opamp_enable(uint32_t base);
void opamp_disable(uint32_t base);
void opamp_lock(uint32_t base);

bool opamp_read_outcal(uint32_t base);
void opamp_set_calsel(uint32_t base, uint32_t calsel);
void opamp_tstref_enable(uint32_t base);
void opamp_tstref_disable(uint32_t base);
void opamp_force_vp_enable(uint32_t base);
void opamp_force_vp_disable(uint32_t base);
void opamp_cal_enable(uint32_t base);
void opamp_cal_disable(uint32_t base);

void opamp_trimoffsetn_set(uint32_t base, uint32_t trim);
void opamp_trimoffsetp_set(uint32_t base, uint32_t trim);
void opamp_user_trim_enable(uint32_t base);
void opamp_user_trim_disable(uint32_t base);

void opamp_pga_gain_select(uint32_t base, uint32_t gain);

void opamp_vp_select(uint32_t base, uint32_t vp);
void opamp_vm_select(uint32_t base, uint32_t vm);

void opamp_high_speed_mode_enable(uint32_t base);
void opamp_high_speed_mode_disable(uint32_t base);

void opamp_output_set_internal(uint32_t base);
void opamp_output_set_external(uint32_t base);

END_DECLS

/**@}*/
#endif

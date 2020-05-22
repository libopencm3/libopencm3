/** @defgroup opamp_defines OPAMP Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the STM32F3xx
 * Operational Amplifier module</b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 22 May 2020
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

#define OPAMP1				(OPAMP_BASE + 0x38)
#define OPAMP2				(OPAMP_BASE + 0x3C)
#define OPAMP3				(OPAMP_BASE + 0x40)
#define OPAMP4				(OPAMP_BASE + 0x44)

/* OpAmp registers */

/* Control and status register (OPAMPx_CSR) */
#define OPAMP_CSR(opamp_base)		MMIO32((opamp_base) + 0x00)
#define OPAMP1_CSR			OPAMP_CSR(OPAMP1)
#define OPAMP2_CSR			OPAMP_CSR(OPAMP2)
#define OPAMP3_CSR			OPAMP_CSR(OPAMP3)
#define OPAMP4_CSR			OPAMP_CSR(OPAMP4)

/* OPAMPx_CSR values */

#define OPAMP_CSR_LOCK			(0x1 << 31)

#define OPAMP_CSR_OUTCAL_MASK		(0x1)
#define OPAMP_CSR_OUTCAL_SHIFT		(30)
#define OPAMP_CSR_OUTCAL_NON_LO_INV	(0x0)
#define OPAMP_CSR_OUTCAL_NON_HI_INV	(0x1)

#define OPAMP_CSR_TSTREF		(0x1 << 29)

#define OPAMP_CSR_TRIMOFFSETN_MASK	(0x1f)
#define OPAMP_CSR_TRIMOFFSETN_SHIFT	(24)

#define OPAMP_CSR_TRIMOFFSETP_MASK	(0x1f)
#define OPAMP_CSR_TRIMOFFSETP_SHIFT	(19)

#define OPAMP_CSR_USER_TRIM		(0x1 << 18)

#define OPAMP_CSR_PGA_GAIN_MASK		(0xf)
#define OPAMP_CSR_PGA_GAIN_SHIFT	(14)
#define OPAMP_CSR_PGA_GAIN_2		(0x0)
#define OPAMP_CSR_PGA_GAIN_4		(0x1)
#define OPAMP_CSR_PGA_GAIN_8		(0x2)
#define OPAMP_CSR_PGA_GAIN_16		(0x3)
#define OPAMP_CSR_PGA_GAIN_2_MINUS_VM0	(0x8)
#define OPAMP_CSR_PGA_GAIN_4_MINUS_VM0	(0x9)
#define OPAMP_CSR_PGA_GAIN_8_MINUS_VM0	(0xa)
#define OPAMP_CSR_PGA_GAIN_16_MINUS_VM0	(0xb)
#define OPAMP_CSR_PGA_GAIN_2_MINUS_VM1	(0xc)
#define OPAMP_CSR_PGA_GAIN_4_MINUS_VM1	(0xd)
#define OPAMP_CSR_PGA_GAIN_8_MINUS_VM1	(0xe)
#define OPAMP_CSR_PGA_GAIN_16_MINUS_VM1	(0xf)

#define OPAMP_CSR_CALSEL_MASK		(0x3)
#define OPAMP_CSR_CALSEL_SHIFT		(12)
#define OPAMP_CSR_CALSEL_3P3_PERCENT	(0x0)
#define OPAMP_CSR_CALSEL_10_PERCENT	(0x1)
#define OPAMP_CSR_CALSEL_50_PERCENT	(0x2)
#define OPAMP_CSR_CALSEL_90_PERCENT	(0x3)

#define OPAMP_CSR_CALON			(0x1 << 11)

#define OPAMP_CSR_VPS_SEL_MASK		(0x3)
#define OPAMP_CSR_VPS_SEL_SHIFT		(9)
#define OPAMP1_CSR_VPS_SEL_PA7		(0x0)
#define OPAMP1_CSR_VPS_SEL_PA5		(0x1)
#define OPAMP1_CSR_VPS_SEL_PA3		(0x2)
#define OPAMP1_CSR_VPS_SEL_PA1		(0x3)
#define OPAMP2_CSR_VPS_SEL_PD14		(0x0)
#define OPAMP2_CSR_VPS_SEL_PB14		(0x1)
#define OPAMP2_CSR_VPS_SEL_PB0		(0x2)
#define OPAMP2_CSR_VPS_SEL_PA7		(0x3)
#define OPAMP3_CSR_VPS_SEL_PB13		(0x0)
#define OPAMP3_CSR_VPS_SEL_PA5		(0x1)
#define OPAMP3_CSR_VPS_SEL_PA1		(0x2)
#define OPAMP3_CSR_VPS_SEL_PB0		(0x3)
#define OPAMP4_CSR_VPS_SEL_PD11		(0x0)
#define OPAMP4_CSR_VPS_SEL_PB11		(0x1)
#define OPAMP4_CSR_VPS_SEL_PA4		(0x2)
#define OPAMP4_CSR_VPS_SEL_PB13		(0x3)

#define OPAMP_CSR_VMS_SEL_MASK		(0x1)
#define OPAMP_CSR_VMS_SEL_SHIFT		(8)
#define OPAMP1_CSR_VMS_SEL_PC5		(0x0)
#define OPAMP1_CSR_VMS_SEL_PA3		(0x1)
#define OPAMP2_CSR_VMS_SEL_PC5		(0x0)
#define OPAMP2_CSR_VMS_SEL_PA5		(0x1)
#define OPAMP3_CSR_VMS_SEL_PB10		(0x0)
#define OPAMP3_CSR_VMS_SEL_PB2		(0x1)
#define OPAMP4_CSR_VMS_SEL_PB10		(0x0)
#define OPAMP4_CSR_VMS_SEL_PD8		(0x1)

#define OPAMP_CSR_TCM_EN		(0x1 << 7)

#define OPAMP_CSR_VM_SEL_MASK		(0x3)
#define OPAMP_CSR_VM_SEL_SHIFT		(5)
#define OPAMP_CSR_VM_SEL_PGA_MODE	(0x2)
#define OPAMP_CSR_VM_SEL_FOLLOWER_MODE	(0x3)
#define OPAMP1_CSR_VM_SEL_PC5		(0x0)
#define OPAMP1_CSR_VM_SEL_PA3		(0x1)
#define OPAMP2_CSR_VM_SEL_PC5		(0x0)
#define OPAMP2_CSR_VM_SEL_PA5		(0x1)
#define OPAMP3_CSR_VM_SEL_PB10		(0x0)
#define OPAMP3_CSR_VM_SEL_PB2		(0x1)
#define OPAMP4_CSR_VM_SEL_PB10		(0x0)
#define OPAMP4_CSR_VM_SEL_PD8		(0x1)

#define OPAMP_CSR_VP_SEL_MASK		(0x3)
#define OPAMP_CSR_VP_SEL_SHIFT		(2)
#define OPAMP1_CSR_VP_SEL_PA7		(0x0)
#define OPAMP1_CSR_VP_SEL_PA5		(0x1)
#define OPAMP1_CSR_VP_SEL_PA3		(0x2)
#define OPAMP1_CSR_VP_SEL_PA1		(0x3)
#define OPAMP2_CSR_VP_SEL_PD14		(0x0)
#define OPAMP2_CSR_VP_SEL_PB14		(0x1)
#define OPAMP2_CSR_VP_SEL_PB0		(0x2)
#define OPAMP2_CSR_VP_SEL_PA7		(0x3)
#define OPAMP3_CSR_VP_SEL_PB13		(0x0)
#define OPAMP3_CSR_VP_SEL_PA5		(0x1)
#define OPAMP3_CSR_VP_SEL_PA1		(0x2)
#define OPAMP3_CSR_VP_SEL_PB0		(0x3)
#define OPAMP4_CSR_VP_SEL_PD11		(0x0)
#define OPAMP4_CSR_VP_SEL_PB11		(0x1)
#define OPAMP4_CSR_VP_SEL_PA4		(0x2)
#define OPAMP4_CSR_VP_SEL_PB13		(0x3)

#define OPAMP_CSR_FORCE_VP		(0x1 << 1)
#define OPAMP_CSR_EN			(0x1 << 0)


BEGIN_DECLS

void opamp_enable(uint32_t base);
void opamp_disable(uint32_t base);
void opamp_lock(uint32_t base);

void opamp_set_calsel(uint32_t base, uint32_t calsel);
bool opamp_read_outcal(uint32_t base);
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

void opamp_vps_select(uint32_t base, uint32_t vps);
void opamp_vms_select(uint32_t base, uint32_t vms);
void opamp_tcm_enable(uint32_t base);
void opamp_tcm_disable(uint32_t base);

END_DECLS

/**@}*/
#endif

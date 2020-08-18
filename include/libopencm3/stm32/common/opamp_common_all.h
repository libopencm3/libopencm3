/** @addtogroup opamp_defines
 *
 * @date 10 Dec 2020
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

/** @cond */
#if defined(LIBOPENCM3_OPAMP_H)
/** @endcond */
#ifndef LIBOPENCM3_OPAMP_COMMON_ALL_H
#define LIBOPENCM3_OPAMP_COMMON_ALL_H
/**@{*/

/* OpAmp registers */

/* Control and status register (OPAMPx_CSR) */
#define OPAMP_CSR(opamp_base)		MMIO32((opamp_base) + 0x00)

/* OPAMPx_CSR values */

#define OPAMP_CSR_LOCK			(0x1 << 31)

#define OPAMP_CSR_TSTREF		(0x1 << 29)

#define OPAMP_CSR_TRIMOFFSETN_MASK	(0x1f)
#define OPAMP_CSR_TRIMOFFSETN_SHIFT	(24)

#define OPAMP_CSR_TRIMOFFSETP_MASK	(0x1f)
#define OPAMP_CSR_TRIMOFFSETP_SHIFT	(19)

#define OPAMP_CSR_CALSEL_MASK		(0x3)
#define OPAMP_CSR_CALSEL_SHIFT		(12)
#define OPAMP_CSR_CALSEL_3P3_PERCENT	(0x0)
#define OPAMP_CSR_CALSEL_10_PERCENT	(0x1)
#define OPAMP_CSR_CALSEL_50_PERCENT	(0x2)
#define OPAMP_CSR_CALSEL_90_PERCENT	(0x3)

#define OPAMP_CSR_CALON			(0x1 << 11)

#define OPAMP_CSR_VM_SEL_MASK		(0x3)
#define OPAMP_CSR_VM_SEL_SHIFT		(5)

#define OPAMP_CSR_VP_SEL_MASK		(0x3)
#define OPAMP_CSR_VP_SEL_SHIFT		(2)

#define OPAMP_CSR_FORCE_VP		(0x1 << 1)
#define OPAMP_CSR_EN			(0x1 << 0)


BEGIN_DECLS

void opamp_enable(uint32_t base);
void opamp_disable(uint32_t base);
void opamp_lock(uint32_t base);

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

END_DECLS
/**@}*/

#endif
/** @cond */
#else
#warning "opamp_common_all.h should not be included directly, only via opamp.h"
#endif
/** @endcond */

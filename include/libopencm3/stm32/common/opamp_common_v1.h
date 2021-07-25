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
#ifndef LIBOPENCM3_OPAMP_COMMON_V1_H
#define LIBOPENCM3_OPAMP_COMMON_V1_H
/**@{*/

#include <libopencm3/stm32/common/opamp_common_all.h>

/* OPAMPx_CSR values */

#define OPAMP_CSR_OUTCAL_MASK		(0x1)
#define OPAMP_CSR_OUTCAL_SHIFT		(30)
#define OPAMP_CSR_OUTCAL_NON_LO_INV	(0x0)
#define OPAMP_CSR_OUTCAL_NON_HI_INV	(0x1)

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

#define OPAMP_CSR_VPS_SEL_MASK		(0x3)
#define OPAMP_CSR_VPS_SEL_SHIFT		(9)

#define OPAMP_CSR_VMS_SEL_MASK		(0x1)
#define OPAMP_CSR_VMS_SEL_SHIFT		(8)

#define OPAMP_CSR_TCM_EN		(0x1 << 7)

#define OPAMP_CSR_VM_SEL_PGA_MODE	(0x2)
#define OPAMP_CSR_VM_SEL_FOLLOWER_MODE	(0x3)


BEGIN_DECLS

bool opamp_read_outcal(uint32_t base);

void opamp_vps_select(uint32_t base, uint32_t vps);
void opamp_vms_select(uint32_t base, uint32_t vms);
void opamp_tcm_enable(uint32_t base);
void opamp_tcm_disable(uint32_t base);

END_DECLS
/**@}*/

#endif
/** @cond */
#else
#warning "opamp_common_v1.h should not be included directly, only via opamp.h"
#endif
/** @endcond */

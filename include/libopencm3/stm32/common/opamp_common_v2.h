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
#ifndef LIBOPENCM3_OPAMP_COMMON_V2_H
#define LIBOPENCM3_OPAMP_COMMON_V2_H
/**@{*/

#include <libopencm3/stm32/common/opamp_common_all.h>

/* OpAmp registers */

/* Timer controlled mode register (OPAMPx_TMCR) */
#define OPAMP_TCMR(opamp_base)		MMIO32((opamp_base) + 0x18)

/* OPAMPx_CSR values */

#define OPAMP_CSR_CALOUT_MASK		(0x1)
#define OPAMP_CSR_CALOUT_SHIFT		(30)
#define OPAMP_CSR_CALOUT_UNSUCC		(0x0)
#define OPAMP_CSR_CALOUT_SUCC		(0x1)

#define OPAMP_CSR_PGA_GAIN_MASK		(0x1f)
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
#define OPAMP_CSR_PGA_FILT_VM1_INV_GAIN_MINUS_7_GAIN_8_VM0	(0x1a)
#define OPAMP_CSR_PGA_FILT_VM1_INV_GAIN_MINUS_15_GAIN_16_VM0	(0x1B)
#define OPAMP_CSR_PGA_FILT_VM1_INV_GAIN_MINUS_31_GAIN_32_VM0	(0x1c)
#define OPAMP_CSR_PGA_FILT_VM1_INV_GAIN_MINUS_63_GAIN_64_VM0	(0x1d)

#define OPAMP_CSR_OPAINTOEN		(0x1 << 8)

#define OPAMP_CSR_OPAHSM		(0x1 << 7)

#define OPAMP_CSR_VM_SEL_VINM0_IN	(0x0)
#define OPAMP_CSR_VM_SEL_VINM1_IN	(0x1)
#define OPAMP_CSR_VM_SEL_PGA_MODE	(0x2)
#define OPAMP_CSR_VM_SEL_OUT_IN		(0x3)

#define OPAMP_CSR_USER_TRIM		(0x1 << 4)

#define OPAMP_CSR_VP_SEL_VINP0		(0x0)
#define OPAMP_CSR_VP_SEL_VINP1		(0x1)
#define OPAMP_CSR_VP_SEL_VINP2		(0x2)

BEGIN_DECLS

bool opamp_read_calout(uint32_t base);

void opamp_high_speed_mode_enable(uint32_t base);
void opamp_high_speed_mode_disable(uint32_t base);

void opamp_output_set_internal(uint32_t base);
void opamp_output_set_external(uint32_t base);

END_DECLS
/**@}*/

#endif
/** @cond */
#else
#warning "opamp_common_v2.h should not be included directly, only via opamp.h"
#endif
/** @endcond */

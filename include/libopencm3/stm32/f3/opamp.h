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

#include <libopencm3/stm32/common/opamp_common_v1.h>

#define OPAMP1				(OPAMP_BASE + 0x38)
#define OPAMP2				(OPAMP_BASE + 0x3C)
#define OPAMP3				(OPAMP_BASE + 0x40)
#define OPAMP4				(OPAMP_BASE + 0x44)

/* OpAmp registers */

/* Control and status register (OPAMPx_CSR) */
#define OPAMP1_CSR			OPAMP_CSR(OPAMP1)
#define OPAMP2_CSR			OPAMP_CSR(OPAMP2)
#define OPAMP3_CSR			OPAMP_CSR(OPAMP3)
#define OPAMP4_CSR			OPAMP_CSR(OPAMP4)

/* OPAMPx_CSR values */

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

#define OPAMP1_CSR_VMS_SEL_PC5		(0x0)
#define OPAMP1_CSR_VMS_SEL_PA3		(0x1)
#define OPAMP2_CSR_VMS_SEL_PC5		(0x0)
#define OPAMP2_CSR_VMS_SEL_PA5		(0x1)
#define OPAMP3_CSR_VMS_SEL_PB10		(0x0)
#define OPAMP3_CSR_VMS_SEL_PB2		(0x1)
#define OPAMP4_CSR_VMS_SEL_PB10		(0x0)
#define OPAMP4_CSR_VMS_SEL_PD8		(0x1)

#define OPAMP1_CSR_VM_SEL_PC5		(0x0)
#define OPAMP1_CSR_VM_SEL_PA3		(0x1)
#define OPAMP2_CSR_VM_SEL_PC5		(0x0)
#define OPAMP2_CSR_VM_SEL_PA5		(0x1)
#define OPAMP3_CSR_VM_SEL_PB10		(0x0)
#define OPAMP3_CSR_VM_SEL_PB2		(0x1)
#define OPAMP4_CSR_VM_SEL_PB10		(0x0)
#define OPAMP4_CSR_VM_SEL_PD8		(0x1)

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

/**@}*/
#endif

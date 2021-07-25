/** @defgroup opamp_defines OPAMP Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the STM32G4xx
 * Operational Amplifier module</b>
 *
 * @ingroup STM32G4xx_defines
 *
 * @version 1.0.0
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

#ifndef LIBOPENCM3_OPAMP_H
#define LIBOPENCM3_OPAMP_H
/**@{*/

#include <libopencm3/stm32/common/opamp_common_v2.h>

#define OPAMP1				(OPAMP_BASE + 0x00)
#define OPAMP2				(OPAMP_BASE + 0x04)
#define OPAMP3				(OPAMP_BASE + 0x08)
#define OPAMP4				(OPAMP_BASE + 0x0C)
#define OPAMP5				(OPAMP_BASE + 0x10)
#define OPAMP6				(OPAMP_BASE + 0x14)

/* OpAmp registers */

/* Control and status register (OPAMPx_CSR) */
#define OPAMP1_CSR			OPAMP_CSR(OPAMP1)
#define OPAMP2_CSR			OPAMP_CSR(OPAMP2)
#define OPAMP3_CSR			OPAMP_CSR(OPAMP3)
#define OPAMP4_CSR			OPAMP_CSR(OPAMP4)
#define OPAMP5_CSR			OPAMP_CSR(OPAMP5)
#define OPAMP6_CSR			OPAMP_CSR(OPAMP6)

#define OPAMP1_TCMR			OPAMP_TCMR(OPAMP1)
#define OPAMP2_TCMR			OPAMP_TCMR(OPAMP2)
#define OPAMP3_TCMR			OPAMP_TCMR(OPAMP3)
#define OPAMP4_TCMR			OPAMP_TCMR(OPAMP4)
#define OPAMP5_TCMR			OPAMP_TCMR(OPAMP5)
#define OPAMP6_TCMR			OPAMP_TCMR(OPAMP6)

/* OPAMPx_CSR values */
#define OPAMP1_CSR_VP_SEL_DAC3CH1	(0x3)
#define OPAMP2_CSR_VP_SEL_VINP3		(0x3)
#define OPAMP3_CSR_VP_SEL_DAC3CH2	(0x3)
#define OPAMP4_CSR_VP_SEL_DAC4CH1	(0x3)
#define OPAMP5_CSR_VP_SEL_DAC4CH2	(0x3)
#define OPAMP6_CSR_VP_SEL_DAC3CH1	(0x3)

/**@}*/
#endif

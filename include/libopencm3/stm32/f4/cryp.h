/** @defgroup cryp_defines CRYP Defines
 *
 * @ingroup STM32F4xx_defines
 *
 * @brief Defined Constants and Types for the STM32F4xx CRYP Controller
 *  
 * @version 1.0.0
 *
 * @date 17 Jun 2013
 *
 * LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_CRYP_H
#define LIBOPENCM3_CRYP_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/common/cryp_common_f24.h>

/* Definitions for F42xx and F43xx */

/* --- CRYP registers ------------------------------------------------------ */

/* CRYP_CSGCMCCMxR: Crypto context registers CCM mode, i=0-7*/
#define CRYP_CSGCMCCMR(i) 	MMIO32(CRYP_BASE + 0x50 + (i) * 4)

/* CRYP_CSGCMxR: Crypto context registers all modes, i=0-7*/
#define CRYP_CSGCMR(i) 		MMIO32(CRYP_BASE + 0x70 + (i) * 4)

/* --- CRYP_CR values ------------------------------------------------------ */

/* Only for part STM32F42xx and STM32F43xx: */

/* GCM_CMPH: GCM or CCM phase state */
#define CRYP_CR_GCM_CMPH_SHIFT			16
#define CRYP_CR_GCM_CMPH_INIT		0
#define CRYP_CR_GCM_CMPH_HEADER		1
#define CRYP_CR_GCM_CMPH_PAYLOAD	2
#define CRYP_CR_GCM_CMPH_FINAL		3

/* ALGOMODE3: Algorithm mode, fourth bit */
#define CRYP_CR_ALGOMODE3	(1 << 19)

#endif

/** @defgroup crypto_defines CRYPTO Defines
 *
 * @brief <b>Defined constants and Types for the STM32F4xx Crypto Coprocessor
 *
 * @ingroup STM32F4xx_defines
 *
 * @version 1.0.0
 *
 * @date 22 Jun 2013
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

#ifndef LIBOPENCM3_CRYPTO_H
#define LIBOPENCM3_CRYPTO_H

#include <libopencm3/stm32/common/crypto_common_f24.h>

/**@{*/

/* --- CRYP registers ------------------------------------------------------ */
/** @defgroup crypto_defines_registers Registers (for F42xx or F43xx only)
 *
 * @brief Register access to the CRYP controller. Registers for F42xx and 43xx
 *
 * @ingroup crypto_defines
 */
/**@{*/

/* CRYP_CSGCMCCMxR: Crypto context registers CCM mode, i=0-7*/
#define CRYP_CSGCMCCMR(i)	MMIO32(CRYP_BASE + 0x50 + (i) * 4)

/* CRYP_CSGCMxR: Crypto context registers all modes, i=0-7*/
#define CRYP_CSGCMR(i)		MMIO32(CRYP_BASE + 0x70 + (i) * 4)

/* --- CRYP_CR values ------------------------------------------------------ */

/* Only for part STM32F42xx and STM32F43xx: */

/* GCM_CMPH: GCM or CCM phase state */
#define CRYP_CR_GCM_CMPH_SHIFT		16
#define CRYP_CR_GCM_CMPH		(3 << CRYP_CR_GCM_CMPH_SHIFT)
#define CRYP_CR_GCM_CMPH_INIT		(0 << CRYP_CR_GCM_CMPH_SHIFT)
#define CRYP_CR_GCM_CMPH_HEADER		(1 << CRYP_CR_GCM_CMPH_SHIFT)
#define CRYP_CR_GCM_CMPH_PAYLOAD	(2 << CRYP_CR_GCM_CMPH_SHIFT)
#define CRYP_CR_GCM_CMPH_FINAL		(3 << CRYP_CR_GCM_CMPH_SHIFT)

/* ALGOMODE3: Algorithm mode, fourth bit */
#define CRYP_CR_ALGOMODE3	(1 << 19)

/**@}*/

/** @defgroup crypto_api API (for F42xx or F43xx only)
 *
 * @brief API for the CRYP controller.
 *
 * @warning Only for F42xx and 43xx
 *
 * @ingroup crypto_defines
 */
/**@{*/

enum crypto_mode_mac {
	ENCRYPT_GCM = CRYP_CR_ALGOMODE_TDES_ECB | CRYP_CR_ALGOMODE3,
	ENCRYPT_CCM = CRYP_CR_ALGOMODE_TDES_CBC | CRYP_CR_ALGOMODE3,
	DECRYPT_GCM = CRYP_CR_ALGOMODE_TDES_ECB | CRYP_CR_ALGOMODE3 |
		      CRYP_CR_ALGODIR,
	DECRYPT_CCM = CRYP_CR_ALGOMODE_TDES_CBC | CRYP_CR_ALGOMODE3 |
		      CRYP_CR_ALGODIR,
};

BEGIN_DECLS

void crypto_context_swap(uint32_t *buf);
void crypto_set_mac_algorithm(enum crypto_mode_mac mode);

END_DECLS
/**@}*/
/**@}*/
#endif

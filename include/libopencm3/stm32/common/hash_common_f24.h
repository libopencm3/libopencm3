/** @addtogroup hash_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Mikhail Avkhimenia <mikhail@avkhimenia.net>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Mikhail Avkhimenia <mikhail@avkhimenia.net>
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

/**@{*/

/** @cond */
#ifdef LIBOPENCM3_HASH_H
/** @endcond */
#ifndef LIBOPENCM3_HASH_COMMON_F24_H
#define LIBOPENCM3_HASH_COMMON_F24_H

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup hash_reg_base HASH register base addresses
@ingroup STM32F_hash_defines

@{*/
#define HASH_BASE	(PERIPH_BASE_AHB2 + 0x60400)
#define HASH		HASH_BASE
/**@}*/

/* --- HASH registers ------------------------------------------------------ */

/* HASH control register (HASH_CR) */
#define HASH_CR		MMIO32(HASH + 0x00)

/* HASH data input register (HASH_DIR) */
#define HASH_DIN	MMIO32(HASH + 0x04)

/* HASH start register (HASH_STR) */
#define HASH_STR	MMIO32(HASH + 0x08)

/* HASH digest registers (HASH_HR[5]) */
#define HASH_HR		(&MMIO32(HASH + 0x0C)) /* x5 */

/* HASH interrupt enable register (HASH_IMR) */
#define HASH_IMR	MMIO32(HASH + 0x20)

/* HASH status register (HASH_SR) */
#define HASH_SR		MMIO32(HASH + 0x28)

/* HASH context swap registers (HASH_CSR[51]) */
#define HASH_CSR	(&MMIO32(HASH + 0xF8)) /* x51 */

/* --- HASH_CR values ------------------------------------------------------ */

/* INIT: Initialize message digest calculation */
#define HASH_CR_INIT		(1 << 2)

/* DMAE: DMA enable */
#define HASH_CR_DMAE		(1 << 3)

/* DATATYPE: Data type selection */
/****************************************************************************/
/** @defgroup hash_data_type HASH Data Type
@ingroup hash_defines

@{*/
#define HASH_DATA_32BIT			(0 << 4)
#define HASH_DATA_16BIT			(1 << 4)
#define HASH_DATA_8BIT			(2 << 4)
#define HASH_DATA_BITSTRING		(3 << 4)
/**@}*/
#define HASH_CR_DATATYPE	(3 << 4)

/* MODE: Mode selection */
/****************************************************************************/
/** @defgroup hash_mode HASH Mode
@ingroup hash_defines

@{*/
#define HASH_MODE_HASH		(0 << 6)
#define HASH_MODE_HMAC		(1 << 6)
/**@}*/
#define HASH_CR_MODE		(1 << 6)

/* ALGO: Algorithm selection */
/****************************************************************************/
/** @defgroup hash_algorithm HASH Algorithm
@ingroup hash_defines

@{*/
#define HASH_ALGO_SHA1		(0 << 7)
#define HASH_ALGO_MD5		(1 << 7)
/**@}*/
#define HASH_CR_ALGO		(1 << 7)

/* NBW: Number of words already pushed */
#define HASH_CR_NBW			(15 << 8)

/* DINNE: DIN(Data input register) not empty */
#define HASH_CR_DINNE		(1 << 12)

/* LKEY: Long key selection */
/****************************************************************************/
/** @defgroup hash_key_length HASH Key length
@ingroup hash_defines

@{*/
#define HASH_KEY_SHORT		(0 << 16)
#define HASH_KEY_LONG		(1 << 16)
/**@}*/
#define HASH_CR_LKEY		(1 << 16)

/* --- HASH_STR values ----------------------------------------------------- */

/* NBLW: Number of valid bits in the last word of the message in the bit string
 */
#define HASH_STR_NBW		(31 << 0)

/* DCAL: Digest calculation */
#define HASH_STR_DCAL		(1 << 8)

/* --- HASH_IMR values ----------------------------------------------------- */

/* DINIE: Data input interrupt enable */
#define HASH_IMR_DINIE		(1 << 0)

/* DCIE: Digest calculation completion interrupt enable */
#define HASH_IMR_DCIE		(1 << 1)

/* --- HASH_SR values ------------------------------------------------------ */

/* DINIS: Data input interrupt status */
#define HASH_SR_DINIS		(1 << 0)

/* DCIS: Digest calculation completion interrupt status */
#define HASH_SR_DCIS		(1 << 1)

/* DMAS: DMA Status */
#define HASH_SR_DMAS		(1 << 2)

/* BUSY: Busy bit */
#define HASH_SR_BUSY		(1 << 3)

/* --- HASH function prototypes -------------------------------------------- */

BEGIN_DECLS

void hash_set_mode(uint8_t mode);
void hash_set_algorithm(uint8_t algorithm);
void hash_set_data_type(uint8_t datatype);
void hash_set_key_length(uint8_t keylength);
void hash_set_last_word_valid_bits(uint8_t validbits);
void hash_init(void);
void hash_add_data(uint32_t data);
void hash_digest(void);
void hash_get_result(uint32_t *data);

END_DECLS
/**@}*/
#endif
/** @cond */
#else
#warning "hash_common_f24.h should not be included explicitly, only via hash.h"
#endif
/** @endcond */


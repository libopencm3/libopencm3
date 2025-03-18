/** @addtogroup hash_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2020
 * Dylan Wadler <dylan@slant.tech>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Dylan Wadler <dylan@slant.tech>
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
#define HASH		HASH_BASE
/**@}*/

/* --- HASH registers ------------------------------------------------------ */

/* HASH control register (HASH_CR) */
#define HASH_CR		MMIO32(HASH + 0x00)

/* HASH data input register (HASH_DIR) */
#define HASH_DIN	MMIO32(HASH + 0x04)

/* HASH start register (HASH_STR) */
#define HASH_STR	MMIO32(HASH + 0x08)

/* HASH digest registers (HASH_HR[8]) */
#define HASH_HR		(HASH + 0x0310) /* x8 */
#define HASH_HR0	MMIO32(HASH_HR)
#define HASH_HR1	MMIO32(HASH_HR + 0x04)
#define HASH_HR2	MMIO32(HASH_HR + 0x08)
#define HASH_HR3	MMIO32(HASH_HR + 0x0c)
#define HASH_HR4	MMIO32(HASH_HR + 0x10)
#define HASH_HR5	MMIO32(HASH_HR + 0x14)
#define HASH_HR6	MMIO32(HASH_HR + 0x18)
#define HASH_HR7	MMIO32(HASH_HR + 0x1c)

/* HASH interrupt enable register (HASH_IMR) */
#define HASH_IMR	MMIO32(HASH + 0x20)

/* HASH status register (HASH_SR) */
#define HASH_SR		MMIO32(HASH + 0x28)

/* HASH context swap registers (HASH_CSR[54]) */
#define HASH_CSR	(&MMIO32(HASH + 0xF8)) /* x54 */

/* --- HASH_CR values ------------------------------------------------------ */


/* LKEY: Long key selection */
#define HASH_CR_LKEY		(1 << 16)

/* MDMAT: Multiple DMA Trasnfers */
#define HASH_CR_MDMAT		(1 << 13)

/* DINNE: DIN not empty */
#define HASH_CR_DINNE		(1 << 12)




/* DMAE: DMA enable */
#define HASH_CR_DMAE		(1 << 3)

/* INIT: Initialize message digest calculation */
#define HASH_CR_INIT		(1 << 2)



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
#define HASH_ALGO_SHA224	(1 << 18)
#define HASH_ALGO_SHA256	((1 << 18) | (1 << 7))
/**@}*/
#define HASH_CR_ALGO0		(1 << 7)
#define HASH_CR_ALGO1		(1 << 18)
#define HASH_CR_ALGO		(HASH_CR_ALGO0 | HASH_CR_ALGO1 )

/* NBW: Number of words already pushed */
#define HASH_CR_NBW_MASK	0xf
#define HASH_CR_NBW_SHIFT	8
#define HASH_CR_NBW			(1 << HASH_CR_NBW_SHIFT)


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
#define HASH_STR_NBLW		(31 << 0)

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
void hash_set_algorithm(uint32_t algorithm);
void hash_set_data_type(uint8_t datatype);
void hash_set_key_length(uint32_t keylength);
void hash_set_last_word_valid_bits(uint8_t validbits);
void hash_init(void);
void hash_add_data(uint32_t* restrict data, uint8_t len );
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


/** @addtogroup crypto_file
 *
 * @brief <b>libopencm3 STM32 Cryptographic controller</b>
 *
 * @version 1.0.0
 *
 * @date 17 Jun 2013
 *
 * This library supports the cryptographic coprocessor system for the
 * STM32 series of ARM Cortex Microcontrollers
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
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

#include <libopencm3/stm32/crypto.h>

#define CRYP_CR_ALGOMODE_MASK	((1 << 19) | CRYP_CR_ALGOMODE)

/**
 * @brief Wait, if the Controller is busy
 */
void crypto_wait_busy(void)
{
	while (CRYP_SR & CRYP_SR_BUSY);
}

/**
 * @brief Set key value to the controller
 * @param[in] keysize enum crypto_keysize Specified size of the key.
 * @param[in] key uint8_t[] Key value (array of items depending on keysize)
 */
void crypto_set_key(enum crypto_keysize keysize, uint8_t key[])
{
	uint32_t* ptr = (uint32_t*) key;

	crypto_wait_busy();

	CRYP_CR = (CRYP_CR & ~CRYP_CR_KEYSIZE) |
		  (keysize << CRYP_CR_KEYSIZE_SHIFT);

	/* stm32 cryto interprets the keys (word) in little endian,
	 * a reserve byte order is needed
	 */
	switch (keysize) {
	case CRYPTO_KEY_256BIT:
		CRYP_KR(0) = __builtin_bswap32(*ptr++);	/* K0LR */
		CRYP_KR(1) = __builtin_bswap32(*ptr++);	/* K0RR */
	/* fallthrough */
	case CRYPTO_KEY_192BIT:
		CRYP_KR(2) = __builtin_bswap32(*ptr++);	/* K1LR */
		CRYP_KR(3) = __builtin_bswap32(*ptr++);	/* K1RR */
	/* fallthrough */
	case CRYPTO_KEY_128BIT:
		CRYP_KR(4) = __builtin_bswap32(*ptr++);	/* K2LR */
		CRYP_KR(5) = __builtin_bswap32(*ptr++);	/* K2RR */
		CRYP_KR(6) = __builtin_bswap32(*ptr++);	/* K3LR */
		CRYP_KR(7) = __builtin_bswap32(*ptr);	/* K3RR */
		break;
	}
}

/**
 * @brief Set Initialization Vector
 *
 * @param[in] keysize enum crypto_keysize Specified size of the key.
 * @param[in] iv uint8_t[] Initialization vector (array of items depending on keysize)

 * @note Cryptographic controller must be in disabled state
 */
void crypto_set_iv(enum crypto_keysize keysize, uint8_t iv[])
{
	uint32_t* ptr = (uint32_t*) iv;

	crypto_wait_busy();

	/* stm32 cryto interprets the keys (word) in little endian,
	 * a reserve byte order is needed
	 */
	switch (keysize) {
	case CRYPTO_KEY_128BIT:
		CRYP_IVR(0) = __builtin_bswap32(*ptr++); /* IV0LR */
		CRYP_IVR(1) = __builtin_bswap32(*ptr++); /* IV0RR */
		CRYP_IVR(2) = __builtin_bswap32(*ptr++); /* IV1LR */
		CRYP_IVR(3) = __builtin_bswap32(*ptr);	 /* IV1RR */
		break;
	default:
		/* whatever other keysize use 64-bit */
		CRYP_IVR(0) = __builtin_bswap32(*ptr++); /* IV0LR */
		CRYP_IVR(1) = __builtin_bswap32(*ptr);	 /* IV0RR */
		break;
	}
}

/**
 * @brief Set the order of the data to be crypted
 *
 * @param[in] datatype enum crypto_datatype Specified datatype of the key.
 */
void crypto_set_datatype(enum crypto_datatype datatype)
{
	CRYP_CR = (CRYP_CR & ~CRYP_CR_DATATYPE) |
		  (datatype << CRYP_CR_DATATYPE_SHIFT);
}

/**
 * @brief Set the algorithm for Encryption/decryption
 *
 *@param[in] mode enum crypto_mode Mode of execution
 */
void crypto_set_algorithm(enum crypto_mode mode)
{
	if ((mode == DECRYPT_AES_ECB) || (mode == DECRYPT_AES_CBC)) {
		/* Unroll keys for the AES encoder for the user automatically */

		CRYP_CR = (CRYP_CR & ~CRYP_CR_ALGOMODE_MASK) |
		    CRYP_CR_ALGOMODE_AES_PREP;

		crypto_start();
		crypto_wait_busy();
		/* module switches to DISABLE automatically */
	}
	/* set algo mode and chaining */
	CRYP_CR = (CRYP_CR & ~(CRYP_CR_ALGOMODE_MASK|CRYP_CR_ALGODIR)) | mode;

	/* flush buffers */
	CRYP_CR |= CRYP_CR_FFLUSH;
}

/**
 * @brief Enable the cryptographic controller and start processing
 */
void crypto_start(void)
{
	CRYP_CR |= CRYP_CR_CRYPEN;
}

/**
 * @brief Disable the cryptographic controller and stop processing
 */

void crypto_stop(void)
{
	CRYP_CR &= ~CRYP_CR_CRYPEN;
}

/**
 * @brief Start of encryption or decryption on data buffers
 *
 * This blocking method transfers input buffer of specified length to the
 * cryptographic coprocessor, and instructs him to begin of ciphering or
 * deciphering. It waits for data to be ready, and then fills the processed
 * data to output buffer.
 *
 * @param[in] inp uint32_t* Input array to crypt/decrypt.
 * @param[in] outp uint32_t* Output array with crypted/encrypted data.
 * @param[in] length uint32_t Length of the arrays
 *
 * @returns uint32_t Number of written words
 */
uint32_t crypto_process_block(uint32_t *inp, uint32_t *outp, uint32_t length)
{
	uint32_t rd = 0, wr = 0;

	/* Transfer the data */
	while (rd != length) {
		if ((wr < length) && (CRYP_SR & CRYP_SR_IFNF)) {
			CRYP_DIN = *inp++;
			wr++;
		}

		if (CRYP_SR & CRYP_SR_OFNE) {
			*outp++ = CRYP_DOUT;
			rd++;
		}
	}

	/* Wait to finish - Not needed ? */
	crypto_wait_busy();

	return wr;
}

/**@}*/

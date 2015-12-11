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
 * @param[in] key uint64_t[] Key value (array of 4 items)
 */
void crypto_set_key(enum crypto_keysize keysize, uint64_t key[])
{
	int i;

	crypto_wait_busy();

	CRYP_CR = (CRYP_CR & ~CRYP_CR_KEYSIZE) |
		  (keysize << CRYP_CR_KEYSIZE_SHIFT);

	for (i = 0; i < 4; i++) {
		CRYP_KR(i) = key[i];
	}
}

/**
 * @brief Set Initialization Vector
 *
 * @param[in] iv uint64_t[] Initialization vector (array of 4 items)

 * @note Cryptographic controller must be in disabled state
 */
void crypto_set_iv(uint64_t iv[])
{
	int i;

	crypto_wait_busy();

	for (i = 0; i < 4; i++) {
		CRYP_IVR(i) = iv[i];
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
	mode &= ~CRYP_CR_ALGOMODE_MASK;

	if ((mode == DECRYPT_AES_ECB) || (mode == DECRYPT_AES_CBC)) {
		/* Unroll keys for the AES encoder for the user automatically */

		CRYP_CR = (CRYP_CR & ~CRYP_CR_ALGOMODE_MASK) |
		    CRYP_CR_ALGOMODE_AES_PREP;

		crypto_start();
		crypto_wait_busy();
		/* module switches to DISABLE automatically */
	}
	/* set algo mode */
	CRYP_CR = (CRYP_CR & ~CRYP_CR_ALGOMODE_MASK) | mode;

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

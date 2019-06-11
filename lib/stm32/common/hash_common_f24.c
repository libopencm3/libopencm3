/** @addtogroup hash_file HASH Peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Mikhail Avkhimenia <mikhail@avkhimenia.net>
 *
 * This library supports the HASH processor in the STM32F2 and STM32F4
 * series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 *  */

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

#include <libopencm3/stm32/hash.h>

/*---------------------------------------------------------------------------*/
/** @brief HASH Set Mode

Sets up the specified mode - either HASH or HMAC.

@param[in] mode unsigned int8. Hash processor mode: @ref hash_mode
*/

void hash_set_mode(uint8_t mode)
{
	HASH_CR &= ~HASH_CR_MODE;
	HASH_CR |= mode;
}

/*---------------------------------------------------------------------------*/
/** @brief HASH Set Algorithm

Sets up the specified algorithm - either MD5 or SHA1.

@param[in] algorithm unsigned int8. Hash algorithm: @ref hash_algorithm
*/

void hash_set_algorithm(uint8_t algorithm)
{
	HASH_CR &= ~HASH_CR_ALGO;
	HASH_CR |= algorithm;
}

/*---------------------------------------------------------------------------*/
/** @brief HASH Set Data Type

Sets up the specified data type: 32Bit, 16Bit, 8Bit, Bitstring.

@param[in] datatype unsigned int8. Hash data type: @ref hash_data_type
*/

void hash_set_data_type(uint8_t datatype)
{
	HASH_CR &= ~HASH_CR_DATATYPE;
	HASH_CR |= datatype;
}

/*---------------------------------------------------------------------------*/
/** @brief HASH Set Key Length

Sets up the specified key length: Long, Short.

@param[in] keylength unsigned int8. Hash data type: @ref hash_key_length
*/

void hash_set_key_length(uint8_t keylength)
{
	HASH_CR &= ~HASH_CR_LKEY;
	HASH_CR |= keylength;
}

/*---------------------------------------------------------------------------*/
/** @brief HASH Set Last Word Valid Bits

Specifies the number of valid bits in the last word.

@param[in] validbits unsigned int8. Number of valid bits.
*/

void hash_set_last_word_valid_bits(uint8_t validbits)
{
	HASH_STR &= ~(HASH_STR_NBW);
	HASH_STR |= validbits;
}

/*---------------------------------------------------------------------------*/
/** @brief HASH Init

Initializes the HASH processor.

*/

void hash_init()
{
	HASH_CR |= HASH_CR_INIT;
}

/*---------------------------------------------------------------------------*/
/** @brief HASH Add data

Puts data into the HASH processor's queue.

@param[in] data unsigned int32. Hash input data.
*/

void hash_add_data(uint32_t data)
{
	HASH_DIN = data;
}

/*---------------------------------------------------------------------------*/
/** @brief HASH Digest

Starts the processing of the last data block.

*/

void hash_digest()
{
	HASH_STR |= HASH_STR_DCAL;
}

/*---------------------------------------------------------------------------*/
/** @brief HASH Get Hash Result

Makes a copy of the resulting hash.

@param[out] data unsigned int32. Hash 4\5 words long depending on the algorithm.
*/

void hash_get_result(uint32_t *data)
{
	data[0] = HASH_HR[0];
	data[1] = HASH_HR[1];
	data[2] = HASH_HR[2];
	data[3] = HASH_HR[3];

	if ((HASH_CR & HASH_CR_ALGO) == HASH_ALGO_SHA1) {
		data[4] = HASH_HR[4];
	}
}
/**@}*/


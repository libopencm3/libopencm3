/** @addtogroup crc_file CRC peripheral API
@ingroup peripheral_apis

 @author @htmlonly &copy; @endhtmlonly 2016 Cem Basoglu <cem.basoglu@web.de>

 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Cem Basoglu <cem.basoglu@web.de>
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

#include <libopencm3/stm32/crc.h>

/*---------------------------------------------------------------------------*/
/** @brief Enable reverse output data.

 Enables the reversal of the bit order of the output data.

 */
void crc_reverse_output_enable()
{
	CRC_CR |= CRC_CR_REV_OUT;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable reverse output data.

 Disables the reversal of the bit order of the output data.

 */
void crc_reverse_output_disable()
{
	CRC_CR &= ~CRC_CR_REV_OUT;
}

/*---------------------------------------------------------------------------*/
/** @brief Reverse input data.

 Controls the reversal of the bit order of the input data

 @param[in] reverse_in Unsigned int32. Reversal bit order @ref crc_rev_in.
 */
void crc_set_reverse_input(uint32_t reverse_in)
{
	uint32_t reg32 = CRC_CR;
	reg32 = (reg32 & ~CRC_CR_REV_IN) | reverse_in;
	CRC_CR = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief Polynomial size

 Set the size of the polynomial.

 @param[in] polysize Unsigned int32. Size of polynomial @ref crc_polysize.
 */
void crc_set_polysize(uint32_t polysize)
{
	uint32_t reg32 = CRC_CR;
	reg32 = (reg32 & ~CRC_CR_POLYSIZE) | polysize;
	CRC_CR = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief Polynomial coefficient

 Set the coefficients of the polynomial to be used for CRC calculation.
 If the polynomial size is less than 32-bits, the least significant bits
 have to be used to program the correct value.

 @note To obtain a reliable CRC calculation, any changes to the polynomial
 value or size can not be performed during a CRC calculation.
 As a result, if a CRC calculation is ongoing, the application must either
 reset the crc unit it or perform a CRC_DR read before changing the polynomial.

 @note The default polynomial value is the CRC-32 (Ethernet) polynomial: 0x4C11DB7.

 @param[in] polynomial Unsigned int32. Polynomial coefficient.
 */
void crc_set_polynomial(uint32_t polynomial)
{
	CRC_POL = polynomial;
}

/*---------------------------------------------------------------------------*/
/** @brief CRC Initial value.

Sets the crc initial value.

 @param[in] initial Unsigned int32. CRC initial value.
 */
void crc_set_initial(uint32_t initial)
{
	CRC_INIT = initial;
}

/**@}*/


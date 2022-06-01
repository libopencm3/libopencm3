/** @addtogroup cordic_file CORDIC peripheral API
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly
2022 Oskar H. Maier <ohma@posteo.de>

This library supports the CORDIC co-processor in the STM32 series of
ARM Cortex Microcontrollers by ST Microelectronics.

The co-processor supported by this code is found in the G0 and
G4 series devices (at the time of writing)

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2022 Oskar H. Maier <ohma@posteo.de>
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

#include <libopencm3/stm32/cordic.h>


/** @brief Read CORDIC result ready flag
 *
 * This flag is set by hardware when a CORDIC operation completes. 
 * It is automatically cleared when all results have been read.
 *
 * @returns bool. Result ready flag.
 */
bool cordic_get_result_ready_flag(void) {
        return CORDIC_CSR & CORDIC_CSR_RRDY;
}

/** @brief Set CORDIC to 32 bit argument data width.
 *
 * When configured this way, argument(s) are expected with 32 bit width.
 * Two write operations are required for operations with two arguments.
 *
 */
void cordic_set_32bit_argument_data_width(void) {
        CORDIC_CSR &= ~CORDIC_CSR_ARGSIZE;
}

/** @brief Set CORDIC to 16 bit argument data width.
 *
 * When configured this way, argument(s) are expected with 16 bit width.
 * Only one 32 bit write operation is required even for operations with two arguments 
 * (in this case lower 16 bits contain argument 1, higher 16 bits contain argument 2).
 *
 */
void cordic_set_16bit_argument_data_width(void) {
        CORDIC_CSR |= CORDIC_CSR_ARGSIZE;
}

/** @brief Set CORDIC to 32 bit result data width.
 *
 * When configured this way, results(s) are written with 32 bit width.
 * Two read operations are required for operations with two results.
 *
 */
void cordic_set_32bit_result_data_width(void) {
        CORDIC_CSR &= ~CORDIC_CSR_RESSIZE;
}

/** @brief Set CORDIC to 16 bit result data width.
 *
 * When configured this way, results are written with 16 bit width.
 * Only one 32 bit read operation is required even for operations with two results 
 * (in this case lower 16 bits contain result 1, higher 16 bits contain result 2).
 *
 */
void cordic_set_16bit_result_data_width(void) {
        CORDIC_CSR |= CORDIC_CSR_RESSIZE;
}

/** @brief Set number of CORDIC arguments to one 32 bit argument or two 16 bit arguments.
 *
 * Use this option for CORDIC operations with only one argument and CORDIC operations 
 * with two 16 bit arguments. In this case the operation is triggered 
 * as soon as one 32bit write to the CORDIC_WDATA register occurred.
 *
 */
void cordic_set_number_of_arguments_1(void) {
        CORDIC_CSR &= ~CORDIC_CSR_NARGS;
}

/** @brief Set number of CORDIC arguments to two 32 bit arguments.
 *
 * Use this option for CORDIC operations with two 32 bit arguments.
 * In this case the operation is triggered as soon as two 32bit 
 * writes to the CORDIC_WDATA register occurred.
 *
 */
void cordic_set_number_of_arguments_2(void) {
        CORDIC_CSR |= CORDIC_CSR_NARGS;
}

/** @brief Set number of CORDIC results to one 32 bit result or two 16 bit results.
 *
 * Use this option for CORDIC operations with only one result and CORDIC operations 
 * with two 16 bit results. In this case the result ready flag is cleared and a new operation 
 * can be started as soon as one 32bit read from the CORDIC_RDATA register occurred.
 *
 */
void cordic_set_number_of_results_1(void) {
        CORDIC_CSR &= ~CORDIC_CSR_NRES;
}

/** @brief Set number of CORDIC results to two 32 bit results.
 *
 * Use this option for CORDIC operations with two 32 bit results. 
 * In this case the result ready flag is cleared and a new operation can be started 
 * as soon as two 32 bit reads from the CORDIC_RDATA register occurred.
 *
 */
void cordic_set_number_of_results_2(void) {
        CORDIC_CSR |= CORDIC_CSR_NRES;
}

/** @brief Enable DMA for writes to CORDIC_WDATA
 *
 * When enabled, the peripheral will continue to generate DMA requests 
 * when new arguments can be loaded into the CORDIC_WDATA register.
 *
 */
void cordic_enable_dma_write(void) {
        CORDIC_CSR |= CORDIC_CSR_DMAWEN;
}

/** @brief Enable DMA for read from CORDIC_RDATA
 *
 * When enabled, the peripheral will continue to generate DMA requests 
 * when new results can be read from the CORDIC_RDATA register.
 *
 */
void cordic_enable_dma_read(void) {
        CORDIC_CSR |= CORDIC_CSR_DMAREN;
}

/** @brief Enable interrupt when result is ready
 *
 * When enabled, the peripheral will generate an interrupt 
 * when the CORDIC_CSR_RRDY flag is set.
 *
 */
void cordic_enable_interrupt(void) {
        CORDIC_CSR |= CORDIC_CSR_IEN;
}

/** @brief Set scaling factor for CORDIC operations
 *
 * For some operations, the arguments can be multiplied by a factor of 2^-n
 * to fit in the argument range. The result must then be multiplied by 2^n.
 * @param[in] n scaling factor
 *
 */
void cordic_set_scaling_factor(uint8_t n) {
        CORDIC_CSR = (CORDIC_CSR & ~CORDIC_CSR_SCALE_MASK) | (n << CORDIC_CSR_SCALE_SHIFT);
}

/** @brief Set precision for CORDIC operations
 *
 * The speed of CORDIC operations can be increased by lowering the 
 * number of iterations. This will decrease precision.
 * @param[in] precision Precision @ref cordic_csr_precision
 *
 */
void cordic_set_precision(uint8_t precision) {
        CORDIC_CSR = (CORDIC_CSR & ~CORDIC_CSR_PRECISION_MASK) | (precision << CORDIC_CSR_PRECISION_SHIFT);
}

/** @brief Set CORDIC operation type
 *
 * Select what operation the CORDIC peripheral performs.
 * @param[in] function Function @ref cordic_csr_function
 *
 */
void cordic_set_function(uint8_t function) {
        CORDIC_CSR = (CORDIC_CSR & ~CORDIC_CSR_FUNC_MASK) | (function << CORDIC_CSR_FUNC_SHIFT);
}

/** @brief Write single 16 bit argument
 *
 * Use this function to set one single 16 bit argument. 
 * The upper 16 bit of the 32 bit result register 
 * (that is the second argument) will be set to zero.
 * @param[in] argument Unsigned int16 argument
 *
 */
void cordic_write_16bit_argument(uint16_t argument) {
        CORDIC_WDATA = argument;
}

/** @brief Write two 16 bit arguments
 *
 * Use this function to set write 16 bit arguments to the 32 bit CORDIC_WDATA register.
 * @param[in] argument1 Unsigned int16 argument1
 * @param[in] argument2 Unsigned int16 argument2
 *
 */
void cordic_write_16bit_arguments(uint16_t argument1, uint16_t argument2) {
        CORDIC_WDATA = argument2 << 16 | argument1;
}

/** @brief Write single 32 bit argument
 *
 * Use this function to write a 32 bit argument to the CORDIC_WDATA register. 
 * If the operation needs two arguments call cordic_set_number_of_arguments_2() 
 * before and then use this function twice to write both arguments.
 * @param[in] argument Unsigned int32 argument
 *
 */
void cordic_write_32bit_argument(uint32_t argument) {
        CORDIC_WDATA = argument;
}

/** @brief Read single 16 bit result
 *
 * Use this function to read one single 16 bit result contained 
 * in the lower 16 bit of the CORDIC_RDATA register.
 * @returns Unsigned int16 result.
 *
 */
uint16_t cordic_read_16bit_result(void) {
        return CORDIC_RDATA;
}

/** @brief Read two 16 bit results
 *
 * Use this function to read both 16 bit results contained
 * in the 32 bit CORDIC_RDATA register.
 * @param[out] result1 Pointer to unsigned int16. First result is written to this address
 * @param[out] result2 Pointer to unsigned int16. Second result is written to this address
 *
 */
void cordic_read_16bit_results(uint16_t *result1, uint16_t *result2) {
        uint32_t temp = CORDIC_RDATA;
        *result1 = temp;
        *result2 = temp >> 16;
}

/** @brief Read 32 bit result
 *
 * Use this function to read the 32 bit CORDIC_RDATA register.
 * @returns Unsigned int32 result.
 *
 */
uint32_t cordic_read_32bit_result(void) {
        return CORDIC_RDATA;
}

/** @brief Compute 16 bit cosine using CORDIC
 *
 * Convenience function to calculate 32767*cos(x/32767*pi).
 * This implementation can be sped up in most applications by configuring the peripheral only once
 * and then trigger subsequent operations by writing new arguments to the CORDIC_WDATA register.
 * Additionally, sine and cosine are always computed in a single operation. 
 * Read the second result to obtain the other value.
 * @param[in] x Int16 argument.
 * @returns Int16 result.
 *
 */
int16_t cordic_cos_16bit(int16_t x) {
        cordic_set_function(CORDIC_CSR_FUNC_COS);
        cordic_set_precision(CORDIC_CSR_PRECISION_20_ITER);
        cordic_set_16bit_argument_data_width();
        cordic_set_16bit_result_data_width();
        cordic_set_number_of_arguments_1();
        cordic_set_number_of_results_1();
        // scale is not applicable for cos
        cordic_write_16bit_arguments((uint16_t) x, 0x7FFF);

        // this while loop can be omitted but that will stall the 
        // processor while it waits for the CORDIC_RDATA register
        while(!cordic_get_result_ready_flag());

        return cordic_read_16bit_result();
}

/** @brief Compute 32 bit cosine using CORDIC
 *
 * Convenience function to calculate 2147483647*cos(x/2147483647*pi).
 * This implementation can be sped up in most applications by configuring the peripheral only once
 * and then trigger subsequent operations by writing new arguments to the CORDIC_WDATA register.
 * Additionally, sine and cosine are always computed in a single operation. 
 * Read the second result to obtain the other value.
 * @param[in] x Int32 argument.
 * @returns Int32 result.
 *
 */
int32_t cordic_cos_32bit(int32_t x) {
        cordic_set_function(CORDIC_CSR_FUNC_COS);
        cordic_set_precision(CORDIC_CSR_PRECISION_28_ITER);
        cordic_set_16bit_argument_data_width();
        cordic_set_16bit_result_data_width();
        cordic_set_number_of_arguments_1();
        cordic_set_number_of_results_1();
        // scale is not applicable for cos
        cordic_write_32bit_argument((uint32_t) x);

        while(!cordic_get_result_ready_flag());

        return cordic_read_32bit_result();
}

/** @brief Compute 16 bit sine using CORDIC
 *
 * Convenience function to calculate 32767*sin(x/32767*pi).
 * This implementation can be sped up in most applications by configuring the peripheral only once
 * and then trigger subsequent operations by writing new arguments to the CORDIC_WDATA register.
 * Additionally, sine and cosine are always computed in a single operation. 
 * Read the second result to obtain the other value.
 * @param[in] x Int16 argument.
 * @returns Int16 result.
 *
 */
int16_t cordic_sin_16bit(int16_t x) {
        cordic_set_function(CORDIC_CSR_FUNC_SIN);
        cordic_set_precision(CORDIC_CSR_PRECISION_20_ITER);
        cordic_set_16bit_argument_data_width();
        cordic_set_16bit_result_data_width();
        cordic_set_number_of_arguments_1();
        cordic_set_number_of_results_1();
        // scale is not applicable for sin
        cordic_write_16bit_arguments((uint16_t) x, 0x7FFF);

        // this while loop can be omitted but that will stall the 
        // processor while it waits for the CORDIC_RDATA register
        while(!cordic_get_result_ready_flag());

        return cordic_read_16bit_result();
}

/** @brief Compute 32 bit sine using CORDIC
 *
 * Convenience function to calculate 2147483647*sin(x/2147483647*pi).
 * This implementation can be sped up in most applications by configuring the peripheral only once
 * and then trigger subsequent operations by writing new arguments to the CORDIC_WDATA register.
 * Additionally, sine and cosine are always computed in a single operation. 
 * Read the second result to obtain the other value.
 * @param[in] x Int32 argument.
 * @returns Int32 result.
 *
 */
int32_t cordic_sin_32bit(int32_t x) {
        cordic_set_function(CORDIC_CSR_FUNC_SIN);
        cordic_set_precision(CORDIC_CSR_PRECISION_28_ITER);
        cordic_set_16bit_argument_data_width();
        cordic_set_16bit_result_data_width();
        cordic_set_number_of_arguments_1();
        cordic_set_number_of_results_1();
        // scale is not applicable for sin
        cordic_write_32bit_argument((uint32_t) x);

        while(!cordic_get_result_ready_flag());

        return cordic_read_32bit_result();
}

/*
// TODO: implement remaining convenience functions
int16_t cordic_atan2_16bit(int16_t x, int16_t y) {

}


int32_t cordic_atan2_32bit(int32_t x, int32_t y) {

}


uint16_t cordic_magnitude_16bit(int16_t x, int16_t y) {

}


uint32_t cordic_magnitude_32bit(int32_t x, int32_t y) {

}


int16_t cordic_atan_16bit(int16_t x, uint8_t scale) {

}


int32_t cordic_atan_32bit(int32_t x, uint8_t scale) {

}


int16_t cordic_cosh_16bit(int16_t x) {

}


int32_t cordic_cosh_32bit(int32_t x) {

}


int16_t cordic_sinh_16bit(int16_t x) {

}


int32_t cordic_sinh_32bit(int32_t x) {

}
*/
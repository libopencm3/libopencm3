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


bool cordic_get_result_ready_flag(void) {
        return CORDIC_CSR & CORDIC_CSR_RRDY;
}

void cordic_set_32bit_argument_data_width(void) {
        CORDIC_CSR &= ~CORDIC_CSR_ARGSIZE;
}

void cordic_set_16bit_argument_data_width(void) {
        CORDIC_CSR |= CORDIC_CSR_ARGSIZE;
}

void cordic_set_32bit_result_data_width(void) {
        CORDIC_CSR &= ~CORDIC_CSR_RESSIZE;
}

void cordic_set_16bit_result_data_width(void) {
        CORDIC_CSR |= CORDIC_CSR_RESSIZE;
}

void cordic_set_argument_number_1(void) {
        CORDIC_CSR &= ~CORDIC_CSR_NARGS;
}

void cordic_set_argument_number_2(void) {
        CORDIC_CSR |= CORDIC_CSR_NARGS;
}

void cordic_set_result_number_1(void) {
        CORDIC_CSR &= ~CORDIC_CSR_NRES;
}

void cordic_set_result_number_2(void) {
        CORDIC_CSR |= CORDIC_CSR_NRES;
}

void cordic_enable_dma_write(void) {
        CORDIC_CSR |= CORDIC_CSR_DMAWEN;
}

void cordic_enable_dma_read(void) {
        CORDIC_CSR |= CORDIC_CSR_DMAREN;
}

void cordic_enable_interrupt(void) {
        CORDIC_CSR |= CORDIC_CSR_IEN;
}

void cordic_set_scaling_factor(uint8_t scale) {
        CORDIC_CSR = (CORDIC_CSR & ~CORDIC_CSR_SCALE_MASK) | (scale << CORDIC_CSR_SCALE_SHIFT);
}

void cordic_set_precision(uint8_t precision) {
        CORDIC_CSR = (CORDIC_CSR & ~CORDIC_CSR_PRECISION_MASK) | (precision << CORDIC_CSR_PRECISION_SHIFT);
}

void cordic_set_function(uint8_t function) {
        CORDIC_CSR = (CORDIC_CSR & ~CORDIC_CSR_FUNC_MASK) | (function << CORDIC_CSR_FUNC_SHIFT);
}

void cordic_write_16bit_argument(uint16_t argument) {
        CORDIC_WDATA = argument;
}

void cordic_write_16bit_arguments(uint16_t argument1, uint16_t argument2) {
        CORDIC_WDATA = argument2 << 16 | argument1;
}

void cordic_write_32bit_argument(uint32_t argument) {
        CORDIC_WDATA = argument;
}

uint16_t cordic_read_16bit_result(void) {
        return CORDIC_RDATA;
}
void cordic_read_16bit_results(uint16_t *result1, uint16_t *result2) {
        uint32_t temp = CORDIC_RDATA;
        *result1 = temp;
        *result2 = temp >> 16;
}

uint32_t cordic_read_32bit_result(void) {
        return CORDIC_RDATA;
}

int16_t cordic_cos_16bit(int16_t x) {
        cordic_set_function(CORDIC_CSR_FUNC_COS);
        cordic_set_precision(CORDIC_CSR_PRECISION_20_ITER);
        cordic_set_16bit_argument_data_width();
        cordic_set_16bit_result_data_width();
        cordic_set_argument_number_1();
        cordic_set_result_number_1();
        // scale is not applicable for cos
        cordic_write_16bit_argument(x);

        while(!cordic_get_result_ready_flag());

        return cordic_read_16bit_result();
}

//int32_t cordic_cos_32bit(int32_t x);
//int16_t cordic_sin_16bit(int16_t x);
//int32_t cordic_sin_32bit(int32_t x);
//void cordic_sin_cos_16bit(int16_t x);
//void cordic_sin_cos_32bit(int32_t x);
//int16_t cordic_atan2_16bit(int16_t x, int16_t y);
//int32_t cordic_atan2_32bit(int32_t x, int32_t y);
//uint16_t cordic_magnitude_16bit(int16_t x, int16_t y);
//uint32_t cordic_magnitude_32bit(int32_t x, int32_t y);
//int16_t cordic_atan_16bit(int16_t x, uint8_t scale);
//int32_t cordic_atan_32bit(int32_t x, uint8_t scale);
//int16_t cordic_cosh_16bit(int16_t x);
//int32_t cordic_cosh_32bit(int32_t x);
//int16_t cordic_sinh_16bit(int16_t x);
//int32_t cordic_sinh_32bit(int32_t x);

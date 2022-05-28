/** @addtogroup cordic_defines

@author @htmlonly &copy; @endhtmlonly 2022 Oskar H. Maier <ohma@posteo.de>

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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA ADC.H
The order of header inclusion is important. adc.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_CORDIC_H
/** @endcond */
#ifndef LIBOPENCM3_CORDIC_COMMON_V1_H
#define LIBOPENCM3_CORDIC_COMMON_V1_H

/** @defgroup cordic_registers CORDIC registers
@{*/
/* ----- CORDIC registers ----- */
/** CORDIC control/status register */
#define CORDIC_CSR                      MMIO32(CORDIC_BASE + 0x00)
/** CORDIC argument register */
#define CORDIC_WDATA                    MMIO32(CORDIC_BASE + 0x04)
/** CORDIC result register */
#define CORDIC_RDATA                    MMIO32(CORDIC_BASE + 0x08)
/**@}*/

/* ----- Register values ----- */

/* ----- CORDIC_CSR Values ----- */
/** @defgroup cordic_csr ISR ADC interrupt status register
@{*/
#define CORDIC_CSR_RRDY                 (0x1 << 31)

#define CORDIC_CSR_ARGSIZE              (0x1 << 22)

#define CORDIC_CSR_RESSIZE              (0x1 << 21)

#define CORDIC_CSR_NARGS                (0x1 << 20)

#define CORDIC_CSR_NRES                 (0x1 << 19)

#define CORDIC_CSR_DMAWEN               (0x1 << 18)
#define CORDIC_CSR_DMAREN               (0x1 << 17)
#define CORDIC_CSR_IEN                  (0x1 << 16)

#define CORDIC_CSR_SCALE_SHIFT          (8)
#define CORDIC_CSR_SCALE_MASK           (0x7 << CORDIC_CSR_SCALE_SHIFT)
#define CORDIC_CSR_SCALE_1              (0x1)
#define CORDIC_CSR_SCALE_2              (0x2)
#define CORDIC_CSR_SCALE_4              (0x3)
#define CORDIC_CSR_SCALE_8              (0x4)
#define CORDIC_CSR_SCALE_16             (0x5)
#define CORDIC_CSR_SCALE_32             (0x6)
#define CORDIC_CSR_SCALE_64             (0x7)

#define CORDIC_CSR_PRECISION_SHIFT      (4)
#define CORDIC_CSR_PRECISION_MASK       (0xF << CORDIC_CSR_PRECISION_SHIFT)
#define CORDIC_CSR_PRECISION_04_ITER    (0x1)
#define CORDIC_CSR_PRECISION_08_ITER    (0x2)
#define CORDIC_CSR_PRECISION_12_ITER    (0x3)
#define CORDIC_CSR_PRECISION_16_ITER    (0x4)
#define CORDIC_CSR_PRECISION_20_ITER    (0x5)
#define CORDIC_CSR_PRECISION_24_ITER    (0x6)
#define CORDIC_CSR_PRECISION_28_ITER    (0x7)
#define CORDIC_CSR_PRECISION_32_ITER    (0x8)
#define CORDIC_CSR_PRECISION_36_ITER    (0x9)
#define CORDIC_CSR_PRECISION_40_ITER    (0xA)
#define CORDIC_CSR_PRECISION_44_ITER    (0xB)
#define CORDIC_CSR_PRECISION_48_ITER    (0xC)
#define CORDIC_CSR_PRECISION_52_ITER    (0xD)
#define CORDIC_CSR_PRECISION_56_ITER    (0xE)
#define CORDIC_CSR_PRECISION_60_ITER    (0xF)

#define CORDIC_CSR_FUNC_SHIFT           (0)
#define CORDIC_CSR_FUNC_MASK            (0xF << CORDIC_CSR_FUNC_SHIFT)
#define CORDIC_CSR_FUNC_COS             (0x0)
#define CORDIC_CSR_FUNC_SIN             (0x1)
#define CORDIC_CSR_FUNC_PHASE           (0x2)
#define CORDIC_CSR_FUNC_MODULUS         (0x3)
#define CORDIC_CSR_FUNC_ATAN            (0x4)
#define CORDIC_CSR_FUNC_COSH            (0x5)
#define CORDIC_CSR_FUNC_SINH            (0x6)
#define CORDIC_CSR_FUNC_ATANH           (0x7)
#define CORDIC_CSR_FUNC_COSINE          (0x8)
#define CORDIC_CSR_FUNC_SQRT            (0x9)


/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

bool cordic_get_result_ready_flag(void);
void cordic_set_32bit_argument_data_width(void);
void cordic_set_16bit_argument_data_width(void);
void cordic_set_32bit_result_data_width(void);
void cordic_set_16bit_result_data_width(void);
void cordic_set_argument_number_1(void);
void cordic_set_argument_number_2(void);
void cordic_set_result_number_1(void);
void cordic_set_result_number_2(void);
void cordic_enable_dma_write(void);
void cordic_enable_dma_read(void);
void cordic_enable_interrupt(void);
void cordic_set_scaling_factor(uint8_t scale);
void cordic_set_precision(uint8_t precision);
void cordic_set_function(uint8_t function);
void cordic_write_16bit_argument(uint16_t argument);
void cordic_write_16bit_arguments(uint16_t argument1, uint16_t argument2);
void cordic_write_32bit_argument(uint32_t argument);
uint16_t cordic_read_16bit_result(void);
void cordic_read_16bit_results(uint16_t *result1, uint16_t *result2);
uint32_t cordic_read_32bit_result(void);
int16_t cordic_cos_16bit(int16_t x);
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
END_DECLS

#endif
/** @cond */
#endif
/** @endcond */
/**@}*/

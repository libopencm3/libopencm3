/** @defgroup pka_defines Public Key Accelerator Defines
 *
 * @brief <b>Defined Constants and Types for the STM32L5xx Public Key Accelerator</b>
 *
 * @ingroup STM32L5xx_defines
 *
 * @version 1.0.0
 *
 * @date 15 June 2020
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

/**@}*/
#ifndef LIBOPENCM3_PKA_H
#define LIBOPENCM3_PKA_H

#include <stdint.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

struct pka_ecc_result {
	uint32_t xp[21];
	uint32_t yp[21];
};

struct pka_esda_sign_result {
	uint32_t r[21];
	uint32_t s[21];
	uint32_t error;
};

union pka_result {
	uint8_t boolean;
	uint32_t rsa_result[99];
	struct pka_ecc_result ecc;
	struct pka_esda_sign_result esda_sign;

};

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/


/* --- (PKA_CR) PKA Control Register --------------------------------------- */

#define PKA_CR					MMIO32(PKA_BASE)
#define PKA_CR_ADDRERRIE		(1 << 20)
#define PKA_CR_RAMERRIE			(1 << 19)
#define PKA_CR_PROCENDIE		(1 << 17)
#define PKA_CR_MODE_MASK		0x3F
#define PKA_CR_MODE_SHIFT		8
#define PKA_CR_MODE				(PKA_CR_MODE_MASK << PKA_CR_MODE_SHIFT)
#define PKA_CR_START			(1 << 1)
#define PKA_CR_EN				(1 << 0)


/* --- (PKA_SR) PKA Status Register ---------------------------------------- */

#define PKA_SR					MMIO32(PKA_BASE + 0x04)
#define PKA_SR_ADDRERR			(1 << 20)
#define PKA_SR_RAMERR			(1 << 19)
#define PKA_SR_PROCEND			(1 << 17)
#define PKA_SR_BUSY				(1 << 16)

/* --- (PKA_CLRFR) PKA Clear flag Register --------------------------------- */

#define PKA_CLRFR				MMIO32(PKA_BASE + 0x08)
#define PKA_CLRFR_ADDERR		(1 << 20)
#define PKA_CLRFR_RAMERR		(1 << 19)
#define PKA_CLRFR_PROCEND		(1 << 17)

/* --- (PKA_RAM) PKA RAM  -------------------------------------------------- */
								/* 32 bit access only!!! */
#define PKA_RAM					(&MMIO32(PKA_BASE + 0x400)) 
#define PKA_RAM_SIZE			3576 /* bytes */

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- PKA Control Register ------------------------------------------------ */
#define PKA_CR_MODE_MGPARAMCOMP_MODEXP	(0x00 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_MGPARAMCOMP			(0x01 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_MODEXP				(0x02 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_ECCMULT				(0x20 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_ECCMULT_FAST		(0x22 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_ECDSA_SIGN			(0x24 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_ECDSA_VERIFY		(0x26 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_POINTEC_CHECK		(0x28 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_RSA_CRT_EXP			(0x07 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_MODINVER			(0x08 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_ARITH_ADD			(0x09 << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_ARITH_SUB			(0x0A << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_ARITH_MULT			(0x0B << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_ARITH_COMP			(0x0C << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_MOD_REDUCTION		(0x0D << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_MOD_ADD				(0x0E << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_MOD_SUB				(0x0F << PKA_CR_MODE_SHIFT)
#define PKA_CR_MODE_MGMULT				(0x10 << PKA_CR_MODE_SHIFT)


/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/* --- Convenience macros -------------------------------------------------- */

/* While these defines are the same, the input parameters are different.
 * The values are also returned in the number of bits, NOT bytes */

/** @defgroupp pka_resultlen PKA Result Bit Length Macros 
@ingroup pka_resultlen 

@{*/

#define EOS_LEN(X)				((X >> 5) + 1) /* Divide by 32, add 1 */
#define ROS_LEN(X)				((X >> 5) + 1) /* Divide by 32, add 1 */

/**@}*/


/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void pka_get_result( uint32_t mode, void * restrict result, uint16_t bits );


uint8_t pka_montgomery_parameter(uint32_t* modval, uint32_t modlen,
					 	uint32_t* result);
uint8_t pka_modular_add(uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict modval, 
						uint32_t* restrict result);
uint8_t pka_modular_sub(uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict modval, 
						uint32_t* restrict result);

uint8_t pka_montgomery_modular_multiplication(uint32_t * restrict a, 
						uint32_t * restrict b, uint32_t len, 
						uint32_t * restrict modval, 
						uint32_t * restrict result);

uint8_t pka_modular_exp(uint32_t * restrict a, uint32_t * restrict exp,
						uint32_t oplen, uint32_t explen, 
						uint32_t * restrict modval,
						uint32_t * restrict result);

uint8_t pka_modular_exp_fast(uint32_t * restrict a, uint32_t * restrict exp,
						uint32_t oplen, uint32_t explen, 
						uint32_t * restrict modval,
						uint32_t * restrict mgparam,
						uint32_t * restrict result);

uint8_t pka_modular_inversion( uint32_t * restrict a, uint32_t len, 
						uint32_t * restrict modval, 
						uint32_t * restrict result );

uint8_t pka_modular_reduction( uint32_t * restrict a, uint32_t oplen,
						uint32_t * restrict modval, uint32_t modlen,
						uint32_t * restrict result);

uint8_t pka_arith_add( uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict result );

uint8_t pka_arith_sub( uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict result );

uint8_t pka_arith_mult( uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict result );

uint8_t pka_arith_compare( uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict result );

uint8_t pka_rsa_crt_exp( uint32_t * restrict dp, uint32_t * restrict dq,
						uint32_t * restrict qinv, uint32_t * restrict prime_p,
						uint32_t * restrict prime_q, uint32_t * restrict a,
						uint32_t len, uint32_t * restrict result);

uint8_t pka_ec_fp_check( uint32_t modlen, uint32_t asign, uint32_t * restrict a, 
						uint32_t * restrict b, uint32_t * restrict p, 
						uint32_t * restrict k, uint32_t * restrict xp, 
						uint32_t * restrict yp, uint32_t * restrict resultx,
						uint32_t * restrict resulty);

uint8_t pka_ecc_fp_mult( uint32_t klen, uint32_t plen, uint32_t asign,
						const uint32_t * restrict a, const uint32_t * restrict p, 
						uint32_t* restrict k, const uint32_t* restrict xp,
						const uint32_t* restrict yp);

uint8_t pka_ecdsa_sign( uint32_t nlen, uint32_t plen, uint32_t asign,
					const uint32_t * restrict a, const uint32_t * restrict p, 
					uint32_t* restrict k, uint32_t klen, const uint32_t* restrict gx,
					const uint32_t* restrict gy, uint32_t * restrict zhash,
					uint32_t* restrict privkey, const uint32_t* restrict n);

END_DECLS

/**@}*/
#endif
/** @endcond */


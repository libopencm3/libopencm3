/** @addtogroup pka_file Public Key Accelerator peripheral API
 * @ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2020 Dylan Wadler <dylan@slant.tech>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Dylan Wadler <dylan@slant.tech> 
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

#include <libopencm3/stm32/pka.h>

/**@{*/


static void pm_write( uint16_t addr, const uint32_t * restrict data, uint32_t len ){
	uint32_t idx_addr = (addr - 0x400) >> 2;
	uint32_t i;

	if( len == 1 ){
		PKA_RAM[idx_addr] = *data;
		/* Add required 0 at the end */
		PKA_RAM[ 1 + idx_addr ] = 0x00000000;
	}
	else{
		for( i = 0; i < (len - 1); i++){
			PKA_RAM[i + idx_addr] = data[ (len - 2) - i];		
			/* Wait for RAM operation to finish */
			while( PKA_SR & PKA_SR_BUSY );
		}
		/* Add required 0 at the end */
		PKA_RAM[ i + idx_addr ] = 0x00000000;

	}

}

static void pm_read( uint16_t addr, uint32_t * restrict data, uint32_t len ){
	uint32_t idx_addr = (addr - 0x400) >> 2;
	uint32_t i;
	for( i = 0; i < len - 1; i++){
		data[ (len - 2) - i] = PKA_RAM[i + idx_addr];
		/* Wait for RAM operation to finish */
		while( PKA_SR & PKA_SR_BUSY );
	}

}


/* Enable peripheral */
static void pka_enable(void){
	unsigned int timeout = 0;

	/* Set enable bit in control register. Need to wait for RAM to clear after
	 * reset, can take a while and the enable bit is ignored during this time */
	do{ 
		PKA_CR |= PKA_CR_EN;
		timeout++;
	}while( ((PKA_CR & PKA_CR_EN) != PKA_CR_EN) || (timeout > 1500) );

	/* Reset flags */
	PKA_CLRFR |= PKA_CLRFR_ADDERR | PKA_CLRFR_RAMERR | PKA_CLRFR_PROCEND ;

	return;
}

/* Disable peripheral */
static void pka_disable(void){
	unsigned int timeout = 0;

	/* Set enable bit in control register. Need to wait for RAM to clear after
	 * reset, can take a while and the enable bit is ignored during this time */
	do{ 
		PKA_CR &= ~PKA_CR_EN;
		timeout++;
	}while( ((PKA_CR & PKA_CR_EN) != 0) || (timeout > 1500) );

	/* Reset flags */
	PKA_CLRFR |= PKA_CLRFR_ADDERR | PKA_CLRFR_RAMERR | PKA_CLRFR_PROCEND ;

	return;
}


/* Retrieve data after operation complete */
void pka_get_result( uint32_t mode, void * restrict result, uint16_t bits ){
	/* Results are at different offsets depending on operation */
	switch ( mode ){
		case PKA_CR_MODE_ECCMULT:
			pm_read( 0x55c, ((struct pka_ecc_result *)result)->xp, EOS_LEN(bits) );
			pm_read( 0x5B0, ((struct pka_ecc_result *)result)->yp, EOS_LEN(bits) );
			break;
		case PKA_CR_MODE_ECDSA_SIGN:
			pm_read( 0x700, ((struct pka_esda_sign_result *)result)->r, EOS_LEN(bits) );
			pm_read( 0x754, ((struct pka_esda_sign_result *)result)->s, EOS_LEN(bits) );		
			pm_read( 0xEE8, &((struct pka_esda_sign_result *)result)->error, 1 );		
			break;

		/* Don't do anything if the mode isn't recognized */
		default:
			return;

	}

	/* Clear process finished flag */
	PKA_CLRFR |= PKA_CLRFR_PROCEND;

}

uint8_t pka_montgomery_parameter(uint32_t* modval, uint32_t modlen,
					 	uint32_t* result)
{
	(void)(modval);
	(void)(modlen);
	(void)(result);

	return 0;
}

uint8_t pka_modular_add(uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict modval, 
						uint32_t* restrict result)
{
	/* Unused for now */
	(void)(a);
	(void)(b);
	(void)(len);
	(void)(modval);
	(void)(result);
	return 0;
}

uint8_t pka_modular_sub(uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict modval, 
						uint32_t* restrict result)
{
	/* Unused for now */
	(void)(a);
	(void)(b);
	(void)(len);
	(void)(modval);
	(void)(result);

	return 0;
}

uint8_t pka_montgomery_modular_multiplication(uint32_t * restrict a, 
						uint32_t * restrict b, uint32_t len, 
						uint32_t * restrict modval, 
						uint32_t * restrict result)
{

	/* Unused for now */
	(void)(a);
	(void)(b);
	(void)(len);
	(void)(modval);
	(void)(result);

	return 0;
}

uint8_t pka_modular_exp(uint32_t * restrict a, uint32_t * restrict exp,
						uint32_t oplen, uint32_t explen, 
						uint32_t * restrict modval,
						uint32_t * restrict result)
{
	/* Unused for now */
	(void)(a);
	(void)(exp);
	(void)(oplen);
	(void)(explen);
	(void)(modval);
	(void)(result);

	return 0;
}

uint8_t pka_modular_exp_fast(uint32_t * restrict a, uint32_t * restrict exp,
						uint32_t oplen, uint32_t explen, 
						uint32_t * restrict modval,
						uint32_t * restrict mgparam,
						uint32_t * restrict result)
{
	/* Unused for now */
	(void)(a);
	(void)(exp);
	(void)(oplen);
	(void)(explen);
	(void)(modval);
	(void)(mgparam);
	(void)(result);
	return 0;
}

uint8_t pka_modular_inversion( uint32_t * restrict a, uint32_t len, 
						uint32_t * restrict modval, 
						uint32_t * restrict result )
{

	/* Unused for now */
	(void)(a);
	(void)(len);
	(void)(modval);
	(void)(result);

	return 0;
}

uint8_t pka_modular_reduction( uint32_t * restrict a, uint32_t oplen,
						uint32_t * restrict modval, uint32_t modlen,
						uint32_t * restrict result)
{

	/* Unused for now */
	(void)(a);
	(void)(oplen);
	(void)(modval);
	(void)(modlen);
	(void)(result);
	return 0;
}

uint8_t pka_arith_add( uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict result )
{
	(void)(a);
	(void)(b);
	(void)(len);
	(void)(result);
	return 0;
}

uint8_t pka_arith_sub( uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict result )
{
	(void)(a);
	(void)(b);
	(void)(len);
	(void)(result);
	return 0;
}

uint8_t pka_arith_mult( uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict result )
{
	(void)(a);
	(void)(b);
	(void)(len);
	(void)(result);
	return 0;
}

uint8_t pka_arith_compare( uint32_t * restrict a, uint32_t * restrict b, 
						uint32_t len, uint32_t * restrict result )
{
	(void)(a);
	(void)(b);
	(void)(len);
	(void)(result);
	return 0;
}

uint8_t pka_rsa_crt_exp( uint32_t * restrict dp, uint32_t * restrict dq,
						uint32_t * restrict qinv, uint32_t * restrict prime_p,
						uint32_t * restrict prime_q, uint32_t * restrict a,
						uint32_t len, uint32_t * restrict result)
{
	(void)(dp);
	(void)(dq);
	(void)(qinv);
	(void)(prime_p);
	(void)(prime_q);
	(void)(a);
	(void)(len);
	(void)(result);
	return 0;
}

uint8_t pka_ec_fp_check( uint32_t modlen, uint32_t asign, uint32_t * restrict a, 
						uint32_t * restrict b, uint32_t * restrict p, 
						uint32_t * restrict k, uint32_t * restrict xp, 
						uint32_t * restrict yp, uint32_t * restrict resultx,
						uint32_t * restrict resulty)
{
	(void)(modlen);
	(void)(asign);
	(void)(a);
	(void)(b);
	(void)(p);
	(void)(k);
	(void)(xp);
	(void)(yp);
	(void)(resultx);
	(void)(resulty);
	return 0;
}

uint8_t pka_ecc_fp_mult( uint32_t klen, uint32_t plen, uint32_t asign,
						const uint32_t * restrict a, const uint32_t * restrict p, 
						uint32_t* restrict k, const uint32_t* restrict xp,
						const uint32_t* restrict yp)
{
	/* EOS Length */
	uint16_t eos_len = EOS_LEN(plen);

	/* Disable peripheral, effective reset  */
	pka_disable();

	/* Write parameters to RAM */

	/* Scalar multiplier K Length */
	pm_write( 0x400, &klen, 1 );
		
	/* Modulus Length */
	pm_write( 0x404, &plen, 1 );

	/* Curve Coefficient a sign */
	pm_write( 0x408, &asign, 1 );
	
	/* Curve Coefficient |a| */
	pm_write( 0x40C, a, eos_len );

	/* Curve modulus value p */
	pm_write( 0x460, p, eos_len );

	/* Scalar multiplier k */
	pm_write( 0x508, k, eos_len );

	/* Point P coordinate x_p */
	pm_write( 0x55C, xp, eos_len );

	/* Point P coordinate y_p */
	pm_write( 0x5B0, yp, eos_len );


	/* Write mode to PKA peripheral */
	PKA_CR &= ~PKA_CR_MODE;
	PKA_CR |= (PKA_CR_MODE_ECCMULT);

	/* Enable Peripheral */
	pka_enable();

	/* Start calculation */
	PKA_CR |= PKA_CR_START;

	return 0;
}

uint8_t pka_ecdsa_sign( uint32_t nlen, uint32_t plen, uint32_t asign,
					const uint32_t * restrict a, const uint32_t * restrict p, 
					uint32_t* restrict k, uint32_t klen, const uint32_t* restrict gx,
					const uint32_t* restrict gy, uint32_t * restrict zhash,
					uint32_t* restrict privkey, const uint32_t* restrict n)
{
	/* EOS Length */
	uint16_t eos_len = EOS_LEN(plen);

	/* Disable peripheral, effective reset  */
	pka_disable();

	/* Write parameters to RAM */

	/* Curve prime order n length */
	pm_write( 0x400, &nlen, 1 );
		
	/* Modulus p Length */
	pm_write( 0x404, &plen, 1 );

	/* Curve Coefficient a sign */
	pm_write( 0x408, &asign, 1 );
	
	/* Curve Coefficient |a| */
	pm_write( 0x40C, a, eos_len );

	/* Curve modulus value p */
	pm_write( 0x460, p, eos_len );

	/* Integer k */
	pm_write( 0x508, k, EOS_LEN(klen) );	

	/* Point P coordinate x_p */
	pm_write( 0x55C, gx, eos_len );

	/* Point P coordinate y_p */
	pm_write( 0x5B0, gy, eos_len );

	/* Hash of message z */
	pm_write( 0xDE8, zhash, eos_len );

	/* Private key d */
	pm_write( 0xE3C, privkey, eos_len );

	/* Curve prime order n */
	pm_write( 0xE94, n, eos_len );


	/* Write mode to PKA peripheral, and start operation */
	PKA_CR &= ~PKA_CR_MODE;
	PKA_CR |= PKA_CR_MODE_ECDSA_SIGN;

	/* Enable Peripheral */
	pka_enable();

	/* Start calculation */
	PKA_CR |= PKA_CR_START;

	return 0;
}





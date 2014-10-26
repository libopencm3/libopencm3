/** @addtogroup crypto_defines
 *
 * @warning The CRYP subsystem is present only in a limited set of devices,
 * see next section for list of supported devices.
 *
 * @section crypto_api_supported Supported devices
 *
 * - STM32F205
 * - STM32F207
 * - STM32F215
 * - STM32F217
 * - STM32F405
 * - STM32F407
 * - STM32F415
 * - STM32F417 <i>(tested)</i>
 * - STM32F427
 * - STM32F437
 *
 * @section crypto_api_theory Theory of operation
 *
 *
 *
 * @section crypto_api_basic Basic handling API
 *
 *
 * @b Example @b 1: Blocking mode
 *
 * @code
 * //[enable-clocks]
 * crypto_set_key(CRYPTO_KEY_128BIT,key);
 * crypto_set_iv(iv);                          // only in CBC or CTR mode
 * crypto_set_datatype(CRYPTO_DATA_16BIT);
 * crypto_set_algorithm(ENCRYPT_AES_ECB);
 * crypto_start();
 * foreach(block in blocks)
 *	crypto_process_block(plaintext,ciphertext,blocksize);
 * crypto_stop();
 * @endcode
 *
 * @section crypto_api_interrupt Interrupt supported handling API
 *
 * @warning This operation mode is currently not supported.
 *
 * @b Example @b 2: Interrupt mode
 *
 * @code
 * //[enable-clocks]
 * crypto_set_key(CRYPTO_KEY_128BIT,key);
 * crypto_set_iv(iv);                          // only in CBC or CTR mode
 * crypto_set_datatype(CRYPTO_DATA_16BIT);
 * crypto_set_algorithm(ENCRYPT_AES_ECB);
 * crypto_start();
 *	[... API to be described later ...]
 * crypto_stop();
 * @endcode
 *
 * @section crypto_api_dma DMA handling API
 *
 * @warning This operation mode is currently not supported.
 *
 * @b Example @b 3: DMA mode
 *
 * @code
 * //[enable-clocks]
 * crypto_set_key(CRYPTO_KEY_128BIT,key);
 * crypto_set_iv(iv);                          // only in CBC or CTR mode
 * crypto_set_datatype(CRYPTO_DATA_16BIT);
 * crypto_set_algorithm(ENCRYPT_AES_ECB);
 * crypto_start();
 *	[... API to be described later ...]
 * crypto_stop();
 * @endcode
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA CRYP.H
The order of header inclusion is important. cryp.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_CRYPTO_H
/** @endcond */

#ifndef LIBOPENCM3_CRYPTO_COMMON_F24_H
#define LIBOPENCM3_CRYPTO_COMMON_F24_H

/**@{*/

/* --- CRYP registers ------------------------------------------------------ */
/** @defgroup crypto_registers_gen Registers (Generic)
 *
 * @brief Register access to the CRYP controller. (All chips)
 *
 * @ingroup crypto_defines
 */
/**@{*/

#define CRYP			CRYP_BASE

/* CRYP Control Register (CRYP_CR) */
#define CRYP_CR			MMIO32(CRYP_BASE + 0x00)

/* CRYP Status Register (CRYP_SR) */
#define CRYP_SR			MMIO32(CRYP_BASE + 0x04)

/* CRYP Data Input Register (CRYP_DIN) */
#define CRYP_DIN		MMIO32(CRYP_BASE + 0x08)

/** CRYP Data Output Register (CRYP_DOUT)  @see blablabla */
#define CRYP_DOUT		MMIO32(CRYP_BASE + 0x0C)

/* CRYP DMA Control Register (CRYP_DMACR) */
#define CRYP_DMACR		MMIO32(CRYP_BASE + 0x10)

/* CRYP Interrupt mask set/clear register (CRYP_IMSCR) */
#define CRYP_IMSCR		MMIO32(CRYP_BASE + 0x14)

/* CRYP Raw Interrupt status register (CRYP_RISR) */
#define CRYP_RISR		MMIO32(CRYP_BASE + 0x18)

/* CRYP Masked Interrupt status register (CRYP_MISR) */
#define CRYP_MISR		MMIO32(CRYP_BASE + 0x1C)

/* CRYP Key registers (CRYP_KxLR) x=0..3 */
#define CRYP_KR(i)		MMIO64(CRYP_BASE + 0x20 + (i) * 8)

/* CRYP Initialization Vector Registers (CRYP_IVxLR) x=0..1 */
#define CRYP_IVR(i)		MMIO32(CRYP_BASE + 0x40 + (i) * 8)

/* --- CRYP_CR values ------------------------------------------------------ */

/* ALGODIR: Algorithm direction */
#define CRYP_CR_ALGODIR		(1 << 2)

/* ALGOMODE: Algorithm mode */
#define CRYP_CR_ALGOMODE_SHIFT		3
#define CRYP_CR_ALGOMODE		(7 << CRYP_CR_ALGOMODE_SHIFT)
#define CRYP_CR_ALGOMODE_TDES_ECB	(0 << CRYP_CR_ALGOMODE_SHIFT)
#define CRYP_CR_ALGOMODE_TDES_CBC	(1 << CRYP_CR_ALGOMODE_SHIFT)
#define CRYP_CR_ALGOMODE_DES_ECB	(2 << CRYP_CR_ALGOMODE_SHIFT)
#define CRYP_CR_ALGOMODE_DES_CBC	(3 << CRYP_CR_ALGOMODE_SHIFT)
#define CRYP_CR_ALGOMODE_AES_ECB	(4 << CRYP_CR_ALGOMODE_SHIFT)
#define CRYP_CR_ALGOMODE_AES_CBC	(5 << CRYP_CR_ALGOMODE_SHIFT)
#define CRYP_CR_ALGOMODE_AES_CTR	(6 << CRYP_CR_ALGOMODE_SHIFT)
#define CRYP_CR_ALGOMODE_AES_PREP	(7 << CRYP_CR_ALGOMODE_SHIFT)

/* DATATYPE: Data type selection */
#define CRYP_CR_DATATYPE_SHIFT		6
#define CRYP_CR_DATATYPE		(3 << CRYP_CR_DATATYPE_SHIFT)
#define CRYP_CR_DATATYPE_32		(0 << CRYP_CR_DATATYPE_SHIFT)
#define CRYP_CR_DATATYPE_16		(1 << CRYP_CR_DATATYPE_SHIFT)
#define CRYP_CR_DATATYPE_8		(2 << CRYP_CR_DATATYPE_SHIFT)
#define CRYP_CR_DATATYPE_BIT		(3 << CRYP_CR_DATATYPE_SHIFT)

/* KEYSIZE: Key size selection (AES mode only)*/
#define CRYP_CR_KEYSIZE_SHIFT		8
#define CRYP_CR_KEYSIZE			(3 << CRYP_CR_KEYSIZE_SHIFT)
#define CRYP_CR_KEYSIZE_128		(0 << CRYP_CR_KEYSIZE_SHIFT)
#define CRYP_CR_KEYSIZE_192		(1 << CRYP_CR_KEYSIZE_SHIFT)
#define CRYP_CR_KEYSIZE_256		(2 << CRYP_CR_KEYSIZE_SHIFT)

/* FFLUSH: FIFO Flush */
#define CRYP_CR_FFLUSH		(1 << 14)

/* CRYPEN: Cryptographic processor enable*/
#define CRYP_CR_CRYPEN		(1 << 15)

/* --- CRYP_SR values ------------------------------------------------------ */

/* IFEM: Input FIFO empty */
#define CRYP_SR_IFEM	(1 << 0)

/* IFNF: Input FIFO not full */
#define CRYP_SR_IFNF	(1 << 1)

/* OFNE: Output FIFO not empty */
#define CRYP_SR_OFNE	(1 << 2)

/* OFFU: Output FIFO full */
#define CRYP_SR_OFFU	(1 << 3)

/* BUSY: Busy bit */
#define CRYP_SR_BUSY	(1 << 4)

/* --- CRYP_DMACR values --------------------------------------------------- */

/* DIEN: DMA input enable */
#define CRYP_DMACR_DIEN		(1 << 0)

/* DOEN: DMA output enable */
#define CRYP_DMACR_DOEN		(1 << 1)

/* --- CRYP_IMSCR values --------------------------------------------------- */

/* INIM: Input FIFO service interrupt mask */
#define CRYP_IMSCR_INIM		(1 << 0)

/* OUTIM: Output FIFO service interrupt mask */
#define CRYP_IMSCR_OUTIM	(1 << 1)

/* --- CRYP_RISR values ---------------------------------------------------- */

/* INRIS: Input FIFO service raw interrupt status */
#define CRYP_RISR_INRIS		(1 << 0)

/* OUTRIS: Output FIFO service raw data */
#define CRYP_RISR_OUTRIS	(1 << 0)

/* --- CRYP_MISR values ---------------------------------------------------- */

/* INMIS: Input FIFO service masked interrupt status */
#define CRYP_MISR_INMIS		(1 << 0)

/* OUTMIS: Output FIFO service masked interrupt status */
#define CRYP_MISR_OUTMIS	(1 << 0)

/**@}*/

/** @defgroup crypto_api_gen API (Generic)
 *
 * @brief API for the CRYP controller
 *
 * @ingroup crypto_defines
 */
/**@{*/

enum crypto_mode {
	ENCRYPT_TDES_ECB = CRYP_CR_ALGOMODE_TDES_ECB,
	ENCRYPT_TDES_CBC = CRYP_CR_ALGOMODE_TDES_CBC,
	ENCRYPT_DES_ECB = CRYP_CR_ALGOMODE_DES_ECB,
	ENCRYPT_DES_CBC = CRYP_CR_ALGOMODE_DES_CBC,
	ENCRYPT_AES_ECB = CRYP_CR_ALGOMODE_AES_ECB,
	ENCRYPT_AES_CBC = CRYP_CR_ALGOMODE_AES_CBC,
	ENCRYPT_AES_CTR = CRYP_CR_ALGOMODE_AES_CTR,
	DECRYPT_TDES_ECB = CRYP_CR_ALGOMODE_TDES_ECB | CRYP_CR_ALGODIR,
	DECRYPT_TDES_CBC = CRYP_CR_ALGOMODE_TDES_CBC | CRYP_CR_ALGODIR,
	DECRYPT_DES_ECB = CRYP_CR_ALGOMODE_DES_ECB | CRYP_CR_ALGODIR,
	DECRYPT_DES_CBC = CRYP_CR_ALGOMODE_DES_CBC | CRYP_CR_ALGODIR,
	DECRYPT_AES_ECB = CRYP_CR_ALGOMODE_AES_ECB | CRYP_CR_ALGODIR,
	DECRYPT_AES_CBC = CRYP_CR_ALGOMODE_AES_CBC | CRYP_CR_ALGODIR,
	DECRYPT_AES_CTR = CRYP_CR_ALGOMODE_AES_CTR,/* XOR is same ENC as DEC */
};
enum crypto_keysize {
	CRYPTO_KEY_128BIT = 0,
	CRYPTO_KEY_192BIT,
	CRYPTO_KEY_256BIT,
};
enum crypto_datatype {

	CRYPTO_DATA_32BIT = 0,
	CRYPTO_DATA_16BIT,
	CRYPTO_DATA_8BIT,
	CRYPTO_DATA_BIT,
};

BEGIN_DECLS
void crypto_wait_busy(void);
void crypto_set_key(enum crypto_keysize keysize, uint64_t key[]);
void crypto_set_iv(uint64_t iv[]);
void crypto_set_datatype(enum crypto_datatype datatype);
void crypto_set_algorithm(enum crypto_mode mode);
void crypto_start(void);
void crypto_stop(void);
uint32_t crypto_process_block(uint32_t *inp, uint32_t *outp, uint32_t length);
END_DECLS
/**@}*/
/**@}*/
#endif
/** @cond */
#else
#warning "crypto_common_f24.h should not be included explicitly, "
	 "only via crypto.h"
#endif
/** @endcond */

/** @defgroup cryp_defines CRYP Defines
 *
 * @brief Defined Constants and Types for the STM32F2xx and STM32F4xx 
 *  CRYP Controller
 *  
 * @version 1.0.0
 *
 * @date 17 Jun 2013
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

/** @cond */
#ifdef LIBOPENCM3_CRYP_H
/** @endcond */
#ifndef LIBOPENCM3_CRYP_COMMON_F24_H
#define LIBOPENCM3_CRYP_COMMON_F24_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

#define CRYP			CRYP_BASE

/* --- CRYP registers ------------------------------------------------------ */

/* CRYP Control Register (CRYP_CR) */
#define CRYP_CR			MMIO32(CRYP_BASE + 0x00)

/* CRYP Status Register (CRYP_SR) */
#define CRYP_SR			MMIO32(CRYP_BASE + 0x04)

/* CRYP Data Input Register (CRYP_DIN) */
#define CRYP_DIN		MMIO32(CRYP_BASE + 0x08)

/* CRYP Data Output Register (CRYP_DOUT) */
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

/* Only for part STM32F42xx and STM32F43xx */

/* CRYP_CSGCMCCMxR: Crypto context registers CCM mode, i=0-7*/
#define CRYP_CSGCMCCMR(i) 	MMIO32(CRYP_BASE + 0x50 + (i) * 4)

/* CRYP_CSGCMxR: Crypto context registers all modes, i=0-7*/
#define CRYP_CSGCMR(i) 		MMIO32(CRYP_BASE + 0x70 + (i) * 4)

/* --- CRYP_CR values ------------------------------------------------------ */

/* ALGODIR: Algorithm direction */
#define CRYP_CR_ALGODIR		(1 << 2)

/* ALGOMODE: Algorithm mode */
#define CRYP_CR_ALGOMODE_SHIFT			3
#define CRYP_CR_ALGOMODE_TDES_ECB	0
#define CRYP_CR_ALGOMODE_TDES_CBC	1
#define CRYP_CR_ALGOMODE_DES_ECB	2
#define CRYP_CR_ALGOMODE_DES_CBC	3
#define CRYP_CR_ALGOMODE_AES_ECB	4
#define CRYP_CR_ALGOMODE_AES_CBC	5
#define CRYP_CR_ALGOMODE_AES_CTR	6
#define CRYP_CR_ALGOMODE_AES_PREP	7

/* DATATYPE: Data type selection */
#define CRYP_CR_DATATYPE_SHIFT			6
#define CRYP_CR_DATATYPE_32			0
#define CRYP_CR_DATATYPE_16			1
#define CRYP_CR_DATATYPE_8			2
#define CRYP_CR_DATATYPE_BIT		3

/* KEYSIZE: Key size selection (AES mode only)*/
#define CRYP_CR_KEYSIZE_SHIFT			8
#define CRYP_CR_KEYSIZE_128			0
#define CRYP_CR_KEYSIZE_192			1
#define CRYP_CR_KEYSIZE_256			2

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

#endif
/** @cond */
#else
#warning "cryp_common_f24.h should not be included explicitly, only via cryp.h"
#endif

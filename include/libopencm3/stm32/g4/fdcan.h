/** @defgroup fdcan_defines FDCAN Defines

@ingroup STM32G4xx_defines

@author @htmlonly &copy @endhtmlonly 2021 Eduard Drusa <ventyl86 at netkosice dot sk>

LGPL License Terms @ref lgpl_license
*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2021 Eduard Drusa <ventyl86 at netkosice dot sk>
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

#pragma once

/** @{ */

/* FDCAN block base addresses. Used in functions to identify FDCAN block being manipulated. */

/** @defgroup fdcan_block FDCAN block base addresses
 * @{
 */
#define CAN1							FDCAN1_BASE
#define CAN2							FDCAN2_BASE
#define CAN3							FDCAN3_BASE
/**@}*/

#define CAN_MSG_BASE					FDCAN1_RAM_BASE

#define FDCAN_RXFIS_BASE				0x0090
#define FDCAN_RXFIA_BASE				0x0094
#define FDCAN_RXFI_OFFSET				0x0008

#define FDCAN_RXGFC(can_base)			MMIO32(can_base + 0x0080)
#define FDCAN_XIDAM(can_base)			MMIO32(can_base + 0x0084)
#define FDCAN_HPMS(can_base)			MMIO32(can_base + 0x0088)

#define FDCAN_TXBRP(can_base)			MMIO32(can_base + 0x00C8)
#define FDCAN_TXBAR(can_base)			MMIO32(can_base + 0x00CC)
#define FDCAN_TXBCR(can_base)			MMIO32(can_base + 0x00D0)
#define FDCAN_TXBTO(can_base)			MMIO32(can_base + 0x00D4)
#define FDCAN_TXBCF(can_base)			MMIO32(can_base + 0x00D8)
#define FDCAN_TXBTIE(can_base)			MMIO32(can_base + 0x00DC)
#define FDCAN_TXBCIE(can_base)			MMIO32(can_base + 0x00E0)
#define FDCAN_TXEFS(can_base)			MMIO32(can_base + 0x00E4)
#define FDCAN_TXEFA(can_base)			MMIO32(can_base + 0x00E8)

#define FDCAN_CKDIV(can_base)			MMIO32(can_base + 0x0100)

#define FDCAN_RXGFC_RRFE				(1 << 0)
#define FDCAN_RXGFC_RRFS				(1 << 1)
/** ANFE[1:0]: Accept non-matching frames w/ extended ID */
#define FDCAN_RXGFC_ANFE_SHIFT			2
#define FDCAN_RXGFC_ANFE_MASK			0x3

/** ANFS[1:0]: Accept non-matching frames w/ standard ID */
#define FDCAN_RXGFC_ANFS_SHIFT			4
#define FDCAN_RXGFC_ANFS_MASK			0x3

#define FDCAN_RXGFC_F1OM				(1 << 8)
#define FDCAN_RXGFC_F0OM				(1 << 9)
/** LSS[4:0]: List size of standard ID filters */
#define FDCAN_RXGFC_LSS_SHIFT			16
#define FDCAN_RXGFC_LSS_MASK			0x1F

/** LSE[3:0]: List size of extended ID filters */
#define FDCAN_RXGFC_LSE_SHIFT			24
#define FDCAN_RXGFC_LSE_MASK			0xF

#define FDCAN_RXFIFO_FL_MASK			0xF
#define FDCAN_RXFIFO_GI_MASK			0x3
#define FDCAN_RXFIFO_PI_MASK			0x3
#define FDCAN_RXFIFO_AI_MASK			0x3

#define FDCAN_TXFQS_TFFL_MASK			0x7
#define FDCAN_TXFQS_TFGI_MASK			0x3
#define FDCAN_TXFQS_TFQPI_MASK			0x3

#define FDCAN_TXEFS_EFFL_MASK			0x7
#define FDCAN_TXEFS_EFGI_MASK			0x3
#define FDCAN_TXEFS_EFPI_MASK			0x3

/* PDIV[3:0]: Input clock divider */
#define FDCAN_CKDIV_PDIV_SHIFT			0
#define FDCAN_CKDIV_PDIV_MASK			0xF

/** Amount of standard filters allocated in Message RAM
 * This number may vary between devices. 28 is value valid
 * for STM32G4
 **/
#define FDCAN_SFT_MAX_NR				28

/** Amount of extended filters allocated in Message RAM
 * This number may vary between devices. 8 is value valid
 * for STM32G4
 **/
#define FDCAN_EFT_MAX_NR				8

#define FDCAN_LFSSA_OFFSET(can_base)	((FDCAN_BLOCK_ID(can_base) * 0x0350) + 0x0000)
#define FDCAN_LFESA_OFFSET(can_base)	((FDCAN_BLOCK_ID(can_base) * 0x0350) + 0x0070)

#define FDCAN_RXFIFOS_OFFSET(can_base)	((FDCAN_BLOCK_ID(can_base) * 0x0350) + 0x00B0)

#define FDCAN_RXFIFO_OFFSET(can_base, fifo_id) \
	(FDCAN_RXFIFOS_OFFSET(can_base) + (0x00D8 * (fifo_id)))

#define FDCAN_TXEVT_OFFSET(can_base)	((FDCAN_BLOCK_ID(can_base) * 0x0350) + 0x0260)

#define FDCAN_TXBUF_OFFSET(can_base)	((FDCAN_BLOCK_ID(can_base) * 0x0350) + 0x0278)

BEGIN_DECLS

END_DECLS

/**@}*/
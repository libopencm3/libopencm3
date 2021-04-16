/** @defgroup fdcan_defines FDCAN Defines

@ingroup STM32H7xx_defines


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
/**@}*/

/* Size of FDCAN peripheral message RAM in bytes */
#define CAN_MSG_SIZE					0x2800

#define FDCAN_GFC(can_base)				MMIO32(can_base + 0x0080)

#define FDCAN_SIDFC(can_base)			MMIO32(can_base + 0x0084)
#define FDCAN_XIDFC(can_base)			MMIO32(can_base + 0x0088)
#define FDCAN_XIDAM(can_base)			MMIO32(can_base + 0x0090)

#define FDCAN_HPMS(can_base)			MMIO32(can_base + 0x0094)
#define FDCAN_NDAT1(can_base)			MMIO32(can_base + 0x0098)
#define FDCAN_HDAT2(can_base)			MMIO32(can_base + 0x009C)

#define FDCAN_RXFIC_BASE				0x00A0
#define FDCAN_RXFI_OFFSET				0x0010

#define FDCAN_RXFIC(can_base, fifo_id)	\
	MMIO32((can_base) + FDCAN_RXFIC_BASE + (FDCAN_RXFI_OFFSET * (fifo_id)))

#define FDCAN_RXF0C(can_base)			FDCAN_RXFIC(can_base, 0)
#define FDCAN_RXF1C(can_base)			FDCAN_RXFIC(can_base, 1)

#define FDCAN_RXFIS_BASE				0x00A4
#define FDCAN_RXFIA_BASE				0x00A8

#define FDCAN_RXBC(can_base)			MMIO32(can_base + 0x00AC)

#define FDCAN_RXESC(can_base)			MMIO32(can_base + 0x00BC)
#define FDCAN_TXESC(can_base)			MMIO32(can_base + 0x00C8)
#define FDCAN_TXBRP(can_base)			MMIO32(can_base + 0x00CC)
#define FDCAN_TXBAR(can_base)			MMIO32(can_base + 0x00D0)
#define FDCAN_TXBCR(can_base)			MMIO32(can_base + 0x00D4)
#define FDCAN_TXBTO(can_base)			MMIO32(can_base + 0x00D8)
#define FDCAN_TXBCF(can_base)			MMIO32(can_base + 0x00DC)
#define FDCAN_TXBTIE(can_base)			MMIO32(can_base + 0x00E0)
#define FDCAN_TXBCIE(can_base)			MMIO32(can_base + 0x00E4)
#define FDCAN_TXEFC(can_base)			MMIO32(can_base + 0x00F0)
#define FDCAN_TXEFS(can_base)			MMIO32(can_base + 0x00F4)
#define FDCAN_TXEFA(can_base)			MMIO32(can_base + 0x00F8)

#define FDCAN_TTTMC(can_base)			MMIO32(can_base + 0x0100)
#define FDCAN_TTRMC(can_base)			MMIO32(can_base + 0x0104)
#define FDCAN_TTOCF(can_base)			MMIO32(can_base + 0x0108)
#define FDCAN_TTMLM(can_base)			MMIO32(can_base + 0x010C)
#define FDCAN_TURCF(can_base)			MMIO32(can_base + 0x0110)
#define FDCAN_TTOCN(can_base)			MMIO32(can_base + 0x0114)
#define FDCAN_TTGTP(can_base)			MMIO32(can_base + 0x0118)
#define FDCAN_TTTMK(can_base)			MMIO32(can_base + 0x011C)
#define FDCAN_TTTIR(can_base)			MMIO32(can_base + 0x0120)
#define FDCAN_TTIE(can_base)			MMIO32(can_base + 0x0124)
#define FDCAN_TTILS(can_base)			MMIO32(can_base + 0x0128)
#define FDCAN_TTOST(can_base)			MMIO32(can_base + 0x012C)
#define FDCAN_TURNA(can_base)			MMIO32(can_base + 0x0130)
#define FDCAN_TTLGT(can_base)			MMIO32(can_base + 0x0134)
#define FDCAN_TTCTC(can_base)			MMIO32(can_base + 0x0138)
#define FDCAN_TTCPT(can_base)			MMIO32(can_base + 0x013C)
#define FDCAN_TTCSM(can_base)			MMIO32(can_base + 0x0140)
#define FDCAN_TTTS(can_base)			MMIO32(can_base + 0x0300)

#define FDCAN_CCU_CCFG					MMIO32(CAN_CCU_BASE + 0x0004)
#define FDCAN_CCU_CREL					MMIO32(CAN_CCU_BASE + 0x0000)

#define FDCAN_GFC_RRFE					(1 << 0)
#define FDCAN_GFC_RRFS					(1 << 1)

/** ANFE[1:0]: Accept non-matching frames w/ extended ID */
#define FDCAN_GFC_ANFE_SHIFT			2
#define FDCAN_GFC_ANFE_MASK				0x3

/** ANFS[1:0]: Accept non-matching frames w/ standard ID */
#define FDCAN_GFC_ANFS_SHIFT			4
#define FDCAN_GFC_ANFS_MASK				0x3

#define FDCAN_FXS_MASK					0xFF
#define FDCAN_FXS_SHIFT					16

/** Position of start address of relocatable object within register */
#define FDCAN_FXSA_MASK					0x3FFF
#define FDCAN_FXSA_SHIFT				2

/** LSS[7:0]: List size of standard ID filters */
#define FDCAN_SIDFC_LSS_MASK			FDCAN_FXS_MASK
#define FDCAN_SIDFC_LSS_SHIFT			FDCAN_FXS_SHIFT

/** LFSSA[13:0]: Filter List standard start address */
#define FDCAN_SIDFC_FLSSA_MASK			FDCAN_FXSA_MASK
#define FDCAN_SIDFC_FLSSA_SHIFT			FDCAN_FXSA_SHIFT

/** LSE[7:0]: List size of extended ID filters */
#define FDCAN_XIDFC_LSE_MASK			FDCAN_FXS_MASK
#define FDCAN_XIDFC_LSE_SHIFT			FDCAN_FXS_SHIFT

/** LFSSA[7:0]: Filter List extended start address */
#define FDCAN_XIDFC_FLESA_MASK			FDCAN_FXSA_MASK
#define FDCAN_XIDFC_FLESA_SHIFT			FDCAN_FXSA_SHIFT

/** TFQS[5:0]: Tx FIFO/Queue size */
#define FDCAN_TXBC_TFQS_MASK			0x3F
#define FDCAN_TXBC_TFQS_SHIFT			24

/** TBSA[7:0]: Transmit buffer start address */
#define FDCAN_TXBC_TBSA_MASK			FDCAN_FXSA_MASK
#define FDCAN_TXBC_TBSA_SHIFT			FDCAN_FXSA_SHIFT

#define FDCAN_TXEFC_EFS_MASK			0x3F
#define FDCAN_TXEFC_EFS_SHIFT			16

/** EFSA[7:0]: (Transmit) event FIFO start address */
#define FDCAN_TXEFC_EFSA_MASK			FDCAN_FXSA_MASK
#define FDCAN_TXEFC_EFSA_SHIFT			FDCAN_FXSA_SHIFT

#define FDCAN_RXFIC_FIOM				(1 << 31)

#define FDCAN_RXFIC_FIWM_MASK			0x7F
#define FDCAN_RXFIC_FIWM_SHIFT			24

#define FDCAN_RXFIC_FIS_MASK			0x7F
#define FDCAN_RXFIC_FIS_SHIFT			16


#define FDCAN_RXFIC_FISA_MASK			FDCAN_FXSA_MASK
#define FDCAN_RXFIC_FISA_SHIFT			FDCAN_FXSA_SHIFT

#define FDCAN_RXF0C_F0OM				FDCAN_RXFIC_FIOM

/** F0WM[6:0]: FIFO0 watermark mode */
#define FDCAN_RXF0C_F0WM_MASK			FDCAN_RXFIC_FIWM_MASK
#define FDCAN_RXF0C_F0WM_SHIFT			FDCAN_RXFIC_FIWM_SHIFT

/** F0S[6:0]: FIFO0 size */
#define FDCAN_RXF0C_F0S_MASK			FDCAN_RXFIC_FIS_MASK
#define FDCAN_RXF0C_F0S_SHIFT			FDCAN_RXFIC_FIS_SHIFT

/** F0SA[13:0]: FIFO0 start address */
#define FDCAN_RXF0C_F0SA_MASK			FDCAN_RXFIC_FISA_MASK
#define FDCAN_RXF0C_F0SA_SHIFT			FDCAN_RXFIC_FISA_SHIFT

#define FDCAN_RXF1C_F1OM				FDCAN_RXFIC_FIOM

/** F1WM[6:0]: FIFO1 watermark mode */
#define FDCAN_RXF1C_F1WM_MASK			FDCAN_RXFIC_FIWM_MASK
#define FDCAN_RXF1C_F1WM_SHIFT			FDCAN_RXFIC_FIWM_SHIFT

/** F1S[6:0]: FIFO1 size */
#define FDCAN_RXF1C_F1S_MASK			FDCAN_RXFIC_FIS_MASK
#define FDCAN_RXF1C_F1S_SHIFT			FDCAN_RXFIC_FIS_SHIFT

/** F1SA[13:0]: FIFO1 start address */
#define FDCAN_RXF1C_F1SA_MASK			FDCAN_RXFIC_FISA_MASK
#define FDCAN_RXF1C_F1SA_SHIFT			FDCAN_RXFIC_FISA_SHIFT

/** RBDS[3:0]: RX buffer data field size */
#define FDCAN_RXESC_RBDS_MASK			0x7
#define FDCAN_RXESC_RBDS_SHIFT			8

/** F0DS[3:0]: FIFO0 data field size */
#define FDCAN_RXESC_F0DS_MASK			0x7
#define FDCAN_RXESC_F0DS_SHIFT			0

/** F1DS[3:0]: FIFO1 data field size */
#define FDCAN_RXESC_F1DS_MASK			0x7
#define FDCAN_RXESC_F1DS_SHIFT			4

/** TBDS[3:0]: TX buffer data field size */
#define FDCAN_TXESC_TBDS_MASK			0x7
#define FDCAN_TXESC_TBDS_SHIFT			0

#define FDCAN_RXFIFO_FL_MASK			0x7F
#define FDCAN_RXFIFO_GI_MASK			0x3F
#define FDCAN_RXFIFO_PI_MASK			0x3F

#define FDCAN_RXFIFO_AI_MASK			0x3F

#define FDCAN_TXFQS_TFFL_MASK			0x3F
#define FDCAN_TXFQS_TFGI_MASK			0x1F
#define FDCAN_TXFQS_TFQPI_MASK			0x1F

#define FDCAN_TXEFS_EFFL_MASK			0x3F
#define FDCAN_TXEFS_EFGI_MASK			0x1F
#define FDCAN_TXEFS_EFPI_MASK			0x1F

/** CDIV[3:0]: Input clock divider */
#define FDCAN_CCU_CCFG_CDIV_SHIFT		16
#define FDCAN_CCU_CCFG_CDIV_MASK		0xF



#define FDCAN_LFSSA_OFFSET(can_base)	\
	(FDCAN_SIDFC(can_base) & (FDCAN_SIDFC_FLSSA_MASK << FDCAN_SIDFC_FLSSA_SHIFT))

#define FDCAN_LFESA_OFFSET(can_base)	\
	(FDCAN_XIDFC(can_base) & (FDCAN_XIDFC_FLESA_MASK << FDCAN_XIDFC_FLESA_SHIFT))

#define FDCAN_RXFIFO_OFFSET(can_base, fifo_id) \
	(FDCAN_RXFIC(can_base, fifo_id) & (FDCAN_FXSA_MASK << FDCAN_FXSA_SHIFT))

#define FDCAN_TXBUF_OFFSET(can_base) \
	(FDCAN_TXBC(can_base) & (FDCAN_TXBC_TBSA_MASK << FDCAN_TXBC_TBSA_SHIFT))

#define FDCAN_TXEVT_OFFSET(can_base) \
	(FDCAN_TXEFC(can_base) & (FDCAN_TXEFC_EFSA_MASK << FDCAN_TXEFC_EFSA_SHIFT))

BEGIN_DECLS

void fdcan_init_std_filter_ram(uint32_t canport, uint32_t flssa, uint8_t lss);
void fdcan_init_ext_filter_ram(uint32_t canport, uint32_t flesa, uint8_t lse);
void fdcan_init_fifo_ram(uint32_t canport, unsigned fifo_id, uint32_t fxsa, uint8_t fxs);
void fdcan_init_tx_event_ram(uint32_t canport, uint32_t tesa, uint8_t tes);
void fdcan_init_tx_buffer_ram(uint32_t canport, uint32_t tbsa, uint8_t tbs);
int fdcan_set_rx_element_size(uint32_t canport, uint8_t rxbuf, uint8_t rxfifo0, uint8_t rxfifo1);
int fdcan_set_tx_element_size(uint32_t canport, uint8_t txbuf);

END_DECLS

/**@}*/
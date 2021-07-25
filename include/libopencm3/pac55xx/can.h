/**
 * @brief CAN definitions for the Qorvo PAC55xx series of microcontrollers.
 *
 * @addtogroup PAC55xx_can CAN
 * @ingroup PAC55xx_defines
 * @author Kevin Stefanik <kevin@allocor.tech>
 * LGPL License Terms @ref lgpl_license
 * @date February 13, 2020
 *
 * Definitions in this file come from the PAC55XX Family User Guide Rev 1.23
 * by Active-Semi dated November 19, 2019.
 *
 * Note: all memory-mapped writes must be performed using 32-bit registers.
 * Any 8-bit memory-mapped registers below may only be used to read.
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Kevin Stefanik <kevin@allocor.tech>
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
#ifndef LIBOPENCM3_PAC55XX_CAN_H_
#define LIBOPENCM3_PAC55XX_CAN_H_

#include <libopencm3/pac55xx/memorymap.h>
#include <libopencm3/cm3/common.h>

/**@{*/

/**
 * @defgroup can_isr_sr_cmr_mr CAN ISR/SR/CMR/MR Registers
 * @{*/
/** This is the 32-bit memory mapped read/write accessor for:
 * - ISR - bits 31:24 - Interrupt Status/ACK Register RW, default 00h
 * - SR  - bits 23:16 - Status Register RO, default 00h
 * - CMR - bits 15:8  - Command RW, default 00h
 * - MR  - bits  7:0  - Mode RW, default 04h
 * When writing, be sure to use CAN_ISR_SR_CMR_MR_SET and CAN_ISR_SR_CMR_MR_CLEAR
 * so as to avoid inadvertently Acknowledging an ISR bit. Writing '1' to one
 * of the ISR bits when it is triggered/set will ACK/clear the bit.
 */
#define CAN_ISR_SR_CMR_MR(can_base)             MMIO32((can_base) + 0x0000)
#define CAN_ISR_SR_CMR_MR_SET(can_base, bits)   (CAN_ISR_SR_CMR_MR(can_base) = \
				(CAN_ISR_SR_CMR_MR(can_base) & 0x00FFFFFF) | (bits))
#define CAN_ISR_SR_CMR_MR_CLEAR(can_base, bits) (CAN_ISR_SR_CMR_MR(can_base) = \
				(CAN_ISR_SR_CMR_MR(can_base) & 0x00FFFFFF) & ~(bits))
/**@}*/

/**
 * @defgroup can_btr01_rmc_imr CAN BTR1/BTR0/RMC/IMR Registers
 * @{*/
/** This is the 32-bit memory mapped read/write accessor for:
 * - BTR1 - bits 31:24 - Bus Timing 1 Register RW, default 00h
 * - BTR0 - bits 23:16 - Bus Timing 0 Register RW, default 00h
 * - RMC  - bits 15:8  - Receive Message Counter RO, default 00h
 * - IMR  - bits  7:0  - Interrupt Mask Register RW, default 00h
 */
#define CAN_BTR1_BTR0_RMC_IMR(can_base)         MMIO32((can_base) + 0x0004)
/**@}*/

/** CAN Transmit Buffer Register RW, default 00000000h */
#define CAN_TXBUF(can_base)     MMIO32((can_base) + 0x0008)
/** CAN Receive Buffer Register RO, default 00000000h */
#define CAN_RXBUF(can_base)     MMIO32((can_base) + 0x000C)
/** CAN Acceptance Code Register RW, default 00000000h */
#define CAN_ACR(can_base)       MMIO32((can_base) + 0x0010)
/** CAN Acceptance Mask Register RW, default 00000000h */
#define CAN_AMR(can_base)       MMIO32((can_base) + 0x0014)

/**
 * @defgroup can_alc_txrxerr_ecc CAN ALC/TXERR/RXERR/ECC Registers
 * @{*/
#define CAN_ALC_TXERR_RXERR_ECC(can_base)   MMIO32((can_base) + 0x0018)
/** CAN Error Code Capture Register RO, default 00h */
#define CAN_ECC(can_base)       (CAN_ALC_TXERR_RXERR_ECC(can_base) & 0xFF)
/** CAN RX Error Counter Register RO, default 00h */
#define CAN_RXERR(can_base)     ((CAN_ALC_TXERR_RXERR_ECC(can_base) >> 8) & 0xFF)
/** CAN TX Error Counter Register RO, default 00h */
#define CAN_TXERR(can_base)     ((CAN_ALC_TXERR_RXERR_ECC(can_base) >> 16) & 0xFF)
/** CAN Arbitration Lost Code Capture Register RO, default 00h */
#define CAN_ALC(can_base)       ((CAN_ALC_TXERR_RXERR_ECC(can_base) >> 24) & 0xFF)
/**@}*/

/** CAN Mode Register bit definitions. This register controls high level modes of the CAN peripheral.
 * @defgroup can_mr_bits CAN Mode Register
 * @{*/
/** AFM: Acceptance Filter Mode */
#define CAN_MR_AFM      BIT0
/** LOM: Listen only mode */
#define CAN_MR_LOM      BIT1
/** RM: Reset Mode */
#define CAN_MR_RM       BIT2
/**@}*/

/** CAN Command Register. This register commands the CAN peripheral to either transmit or abort.
 * @defgroup can_cmr_bits CAN Command Register
 * @{*/
/** AT: Abort transmission */
#define CAN_CMR_AT      BIT9
/** TR: Transmit Request */
#define CAN_CMR_TR      BIT10
/**@}*/

/** CAN Status Register. This register provides read-only status of the CAN peripheral.
 * @defgroup can_sr_bits CAN Status Register
 * @{*/
/** BS: Bus Off Status */
#define CAN_SR_BS       BIT16
/** ES: Error Status */
#define CAN_SR_ES       BIT17
/** TS: Transmit Status */
#define CAN_SR_TS       BIT18
/** RS: Receive Status */
#define CAN_SR_RS       BIT19
/** TBS: Transmit Buffer Status */
#define CAN_SR_TBS      BIT21
/** DSO: Data Overrun Status */
#define CAN_SR_DSO      BIT22
/** RBS: Receive Buffer Status */
#define CAN_SR_RBS      BIT23
/**@}*/

/** CAN Interrupt Status Register bit definitions.
 * - 1: interrupt triggered
 * - 0: no interrupt
 * - Writing a 1 to a triggered interrupt clears the bit.
 * @defgroup can_isr_bits CAN Interrupt Status Register
 * @{*/
/** DOI: Data Overflow Interrupt */
#define CAN_ISR_DOI     BIT24
/** BEI: Bus Error Interrupt */
#define CAN_ISR_BEI     BIT25
/** TI: Transmit Interrupt */
#define CAN_ISR_TI      BIT26
/** RI: Receive Interrupt */
#define CAN_ISR_RI      BIT27
/** EPI: Error Passive Interrupt */
#define CAN_ISR_EPI     BIT28
/** EWI: Error Warning Interrupt */
#define CAN_ISR_EWI     BIT29
/** ALI: Arbitration Lost Interrupt */
#define CAN_ISR_ALI     BIT30
/** This is a helper to acknowledge an ISR */
#define CAN_ISR_ACKNOWLEDGE(can_base, isr)  CAN_ISR_SR_CMR_MR_SET(can_base, ((isr) & 0x7F000000))
/**@}*/

/** CAN Interrupt Mask Register bit definitions.
 * 0: disables/masks interrupt
 * 1: enables interrupt
 * @defgroup can_imr_bits CAN Mask Register
 * @{*/
/** DOIM: DOI Interrupt Mask */
#define CAN_IMR_DOIM    BIT0
/** BEIM: BEI Interrupt Mask */
#define CAN_IMR_BEIM    BIT1
/** TIM: TI Interrupt Mask */
#define CAN_IMR_TIM     BIT2
/** RIM: RI Interrupt Mask */
#define CAN_IMR_RIM     BIT3
/** EPIM: EPI Interrupt Mask */
#define CAN_IMR_EPIM    BIT4
/** EWIM: EWI Interrupt Mask */
#define CAN_IMR_EWIM    BIT5
/** ALIM: ALI Interrupt Mask */
#define CAN_IMR_ALIM    BIT6
/**@}*/

/** CAN Receive Message Counter Register bit definitions.
 * @defgroup can_rmc_bits CAN Receive Message Counter Register.
 * @{*/
#define CAN_RMC(can_base)   ((CAN_BTR1_BTR0_RMC_IMR(can_base) >> 8) & 0x1F)
/**@}*/

/** CAN Bus Timing 0 Register bit definitions.
 * @defgroup can_btr0_bits CAN Bus Timing 0 Register.
 * @{*/
#define CAN_BTR0_BRP_MASK   (0x3F)
#define CAN_BTR0_BRP_SHIFT  16
#define CAN_BTR0_BRP(val)   (((val) & CAN_BTR0_BRP_MASK) << CAN_BTR0_BRP_SHIFT)
#define CAN_BTR0_SJW_MASK   (0x03)
#define CAN_BTR0_SJW_SHIFT  22
#define CAN_BTR0_SJW(val)   (((val) & CAN_BTR0_SJW_MASK) << CAN_BTR0_SJW_SHIFT)
/**@}*/

/** CAN Bus Timing 1 Register bit definitions.
 * @defgroup can_btr1_bits CAN Bus Timing 1 Register
 * @{*/
#define CAN_BTR1_TSEG1_MASK     (0x0F)
#define CAN_BTR1_TSEG1_SHIFT    24
#define CAN_BTR1_TSEG1(val)     (((val) & CAN_BTR1_TSEG1_MASK) << CAN_BTR1_TSEG1_SHIFT)

#define CAN_BTR1_TSEG2_MASK     (0x07)
#define CAN_BTR1_TSEG2_SHIFT    28
#define CAN_BTR1_TSEG2(val)     (((val) & CAN_BTR1_TSEG2_MASK) << CAN_BTR1_TSEG2_SHIFT)
#define CAN_BTR1_SAM            BIT31
/**@}*/

/** CAN Error Code Capture Register bit definitions.
 * @defgroup can_ecc_bits CAN Error Code Capture Register
 * @{*/
/** BER: Bit error ocurred */
#define CAN_ECC_BER     BIT0
/** STFER: Stuff error occurred */
#define CAN_ECC_STFER   BIT1
/** CRCER: CRC error occurred */
#define CAN_ECC_CRCER   BIT2
/** FRMER: Form error occurred */
#define CAN_ECC_FRMER   BIT3
/** ACKER: ACK error occurred */
#define CAN_ECC_ACKER   BIT4
/** EDIR: Direction of transfer 0:TX, 1:RX */
#define CAN_ECC_EDIR    BIT5
/** TXWRN: set when CAN_TXERR >= 96 */
#define CAN_ECC_TXWRN   BIT6
/** RXWRN: set when CAN_RXERR >= 96 */
#define CAN_ECC_RXWRN   BIT7
/**@}*/

/** CAN Acceptance Code/Mask Register. This is used for filtering messages.
 * Mask value of 1 ignores the bit. Mask value of 0 checks the bit.
 * @defgroup can_acr_bits CAN Acceptance Code Register
 * @{*/
#define CAN_ACR_DUAL_DB_UPPER   0x000F0000U /* 19:16 */
#define CAN_ACR_DUAL_DB_LOWER   0x0000000FU /* 3:0 */
#define CAN_ACR_DUAL_ID1        0xFFE00000U /* 31:21 */
#define CAN_ACR_DUAL_ID2        0x0000FFE0U /* 15:5 */
#define CAN_ACR_DUAL_RTR1       0x00100000U /* 20 */
#define CAN_ACR_DUAL_RTR2       0x00000010U /* 4 */

#define CAN_ACR_SINGLE_STD_ID   0xFFE00000U /* 31:21 */
#define CAN_ACR_SINGLE_STD_RTR  0x00100000U /* 20 */
#define CAN_ACR_SINGLE_STD_DB1  0x0000FF00U /* 15:8 */
#define CAN_ACR_SINGLE_STD_DB2  0x000000FFU /* 7:0 */

#define CAN_ACR_SINGLE_EXT_ID   0xFFFFFFF8U /* 31:3 */
#define CAN_ACR_SINGLE_EXT_RTR  0x00000004U /* 2 */
/**@}*/

/**
 * @defgroup can_bit_masks CAN Miscellaneous Bit Masks
 * @{*/
#define CAN_BITS_2_0    (0x07)
#define CAN_BITS_3_0    (0x0F)
#define CAN_BITS_4_0    (0x1F)
#define CAN_BITS_7_3    (0xF8)
#define CAN_BITS_10_3   (0x07F8)
#define CAN_BITS_12_5   (0x00001FE0U)
#define CAN_BITS_20_13  (0x001FE000U)
#define CAN_BITS_28_21  (0x1FE00000U)
#define CAN_BITS_15_8   (0x0000FF00U)
#define CAN_BITS_23_16  (0x00FF0000U)
#define CAN_BITS_31_24  (0xFF000000U)
#define CAN_BITS_23_21  (0x00E00000U)
/**@}*/

/**@}*/

BEGIN_DECLS
/** CAN Application Programming Interface.
 * @addtogroup can_api CAN Peripheral API
 * @ingroup peripheral_apis
 @{*/
void can_enable(uint32_t canport);
void can_disable(uint32_t canport);
void can_init(uint32_t canport, bool listen_only, uint32_t sjw,
			uint32_t tseg1, uint32_t tseg2,
			bool sam3, uint32_t brp);
void can_filter_clear(uint32_t canport);
void can_filter_dual(uint32_t canport, uint32_t id1, uint32_t id1_mask,
			uint32_t id2, uint32_t id2_mask,
			uint8_t db, uint8_t db_mask);
void can_filter_single_std(uint32_t canport, uint32_t id, uint32_t id_mask,
			uint8_t db1, uint8_t db1_mask,
			uint8_t db2, uint8_t db2_mask);
void can_filter_single_std_rtr(uint32_t canport, uint32_t id, uint32_t id_mask,
			uint8_t db1, uint8_t db1_mask,
			uint8_t db2, uint8_t db2_mask);
void can_filter_single_ext(uint32_t canport, uint32_t id, uint32_t id_mask);
void can_filter_single_ext_rtr(uint32_t canport, uint32_t id, uint32_t id_mask);
void can_enable_irq(uint32_t canport, uint8_t imr);
void can_disable_irq(uint32_t canport, uint8_t imr);

bool can_transmit_std(uint32_t canport, uint32_t id, bool rtr, uint8_t length,
			const uint8_t *data);
bool can_transmit_ext(uint32_t canport, uint32_t id, bool rtr, uint8_t length,
			const uint8_t *data);
void can_abort_transmit(uint32_t canport);

void can_receive(uint32_t canport, uint32_t *id, bool *ext, bool *rtr, uint8_t *length,
			uint8_t *data);
/**@}*/

END_DECLS

#endif /* LIBOPENCM3_PAC55XX_CAN_H_ */

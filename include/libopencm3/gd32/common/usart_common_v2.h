/** @addtogroup usart_defines

 @author @htmlonly &copy; @endhtmlonly 2016 Cem Basoglu <cem.basoglu@web.de>

 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Cem Basoglu <cem.basoglu@web.de>
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

/** @defgroup usart_registers USART Registers
@ingroup usart_defines
@{*/

/** Control register 1 (USARTx_CTL0) */
#define USART_CTL0(usart_base)		MMIO32((usart_base) + 0x00)
#define USART0_CTL0			USART_CTL0(USART0_BASE)
#define USART1_CTL0			USART_CTL0(USART1_BASE)

/** Control register 2 (USARTx_CTL1) */
#define USART_CTL1(usart_base)		MMIO32((usart_base) + 0x04)
#define USART0_CTL1			USART_CTL1(USART0_BASE)
#define USART1_CTL1			USART_CTL1(USART1_BASE)

/** Control register 3 (USARTx_CTL2) */
#define USART_CTL2(usart_base)		MMIO32((usart_base) + 0x08)
#define USART0_CTL2			USART_CTL2(USART0_BASE)
#define USART1_CTL2			USART_CTL2(USART1_BASE)

/** Baud rate register (USARTx_BAUD) */
#define USART_BAUD(usart_base)		MMIO32((usart_base) + 0x0C)
#define USART0_BAUD			USART_BAUD(USART0_BASE)
#define USART1_BAUD			USART_BAUD(USART1_BASE)

/** Guard time and prescaler register (USARTx_GP) */
#define USART_GP(usart_base)		MMIO32((usart_base) + 0x10)
#define USART0_GP			USART_GP(USART0_BASE)
#define USART1_GP			USART_GP(USART1_BASE)

/** Receiver timeout register (USART_RT) */
#define USART_RT(usart_base)		MMIO32((usart_base) + 0x14)
#define USART0_RT			USART_RT(USART0_BASE)
#define USART1_RT			USART_RT(USART1_BASE)

/** Request register (USART_CMD) */
#define USART_CMD(usart_base)		MMIO32((usart_base) + 0x18)
#define USART0_CMD			USART_CMD(USART0_BASE)
#define USART1_CMD			USART_CMD(USART1_BASE)

/** Interrupt & status register (USART_STAT) */
#define USART_STAT(usart_base)		MMIO32((usart_base) + 0x1C)
#define USART0_STAT			USART_STAT(USART0_BASE)
#define USART1_STAT			USART_STAT(USART1_BASE)

/** Interrupt flag clear register (USART_INTC) */
#define USART_INTC(usart_base)		MMIO32((usart_base) + 0x20)
#define USART0_INTC			USART_INTC(USART0_BASE)
#define USART1_INTC			USART_INTC(USART1_BASE)

/** Receive data register (USART_RDATA) */
#define USART_RDATA(usart_base)		MMIO32((usart_base) + 0x24)
#define USART0_RDATA			USART_RDATA(USART0_BASE)
#define USART1_RDATA			USART_RDATA(USART1_BASE)

/** Transmit data register (USART_TDATA) */
#define USART_TDATA(usart_base)		MMIO32((usart_base) + 0x28)
#define USART0_TDATA			USART_TDATA(USART0_BASE)
#define USART1_TDATA			USART_TDATA(USART1_BASE)

/**@}*/

/** @defgroup usart_convenience_flags U(S)ART convenience Flags
 * @ingroup usart_defines
 * We define the "common" lower flag bits using a standard name,
 * allowing them to be used regardless of which usart peripheral
 * version you have.
 * @{
 */
#define USART_FLAG_PERR		USART_STAT_PERR
#define USART_FLAG_FERR		USART_STAT_FERR
#define USART_FLAG_NERR		USART_STAT_NERR
#define USART_FLAG_ORERR	USART_STAT_ORERR
#define USART_FLAG_IDLEF	USART_STAT_IDLEF
#define USART_FLAG_RBNE		USART_STAT_RBNE
#define USART_FLAG_TC		USART_STAT_TC
#define USART_FLAG_TBE		USART_STAT_TBE
/**@}*/


/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/** @defgroup usart_ctl0_values USART_CTL0 Values
@ingroup usart_defines
@{*/

/** EBIE: End of Block interrupt enable */
#define USART_CTL0_EBIE			(1 << 27)

/** RTIE: Receiver timeout interrupt enable */
#define USART_CTL0_RTIE			(1 << 26)

#define USART_CTL0_DEA_SHIFT		21
#define USART_CTL0_DEA			(0x1F << USART_CTL0_DEA_SHIFT)
/** DEA[4:0]: Driver Enable assertion time */
#define USART_CTL0_DEA_VAL(x)		((x) << USART_CTL0_DEA_SHIFT)

#define USART_CTL0_DED_SHIFT		16
#define USART_CTL0_DED			(0x1F << USART_CTL0_DED_SHIFT)
/** DED[4:0]: Driver Enable deassertion time */
#define USART_CTL0_DED_VAL(x)		((x) << USART_CTL0_DED_SHIFT)

/** OVSMOD: Oversampling mode */
#define USART_CTL0_OVSMOD		(1 << 15)

/** AMIE: Address match interrupt enable */
#define USART_CTL0_AMIE			(1 << 14)

/** MEN: Mute mode enable */
#define USART_CTL0_MEN			(1 << 13)

/** WL: Word length */
#define USART_CTL0_WL			(1 << 12)

/** WM: Mute mode wakeup method */
#define USART_CTL0_WM			(1 << 11)

/** PCEN: Parity control enable */
#define USART_CTL0_PCEN			(1 << 10)

/** PM: Parity selection */
#define USART_CTL0_PM			(1 << 9)

/** PERRIE: PE interrupt enable */
#define USART_CTL0_PERRIE		(1 << 8)

/** TBEIE: Interrupt enable */
#define USART_CTL0_TBEIE		(1 << 7)

/** TCIE: Transmission complete interrupt enable */
#define USART_CTL0_TCIE			(1 << 6)

/** RBNEIE: RXNE interrupt enable */
#define USART_CTL0_RBNEIE		(1 << 5)

/** IDLEIE: IDLE interrupt enable */
#define USART_CTL0_IDLEIE		(1 << 4)

/** TEN: Transmitter enable */
#define USART_CTL0_TEN			(1 << 3)

/** REN: Receiver enable */
#define USART_CTL0_REN			(1 << 2)

/** UESM: USART enable in Stop mode */
#define USART_CTL0_UESM			(1 << 1)

/** UEN: USART enable */
#define USART_CTL0_UEN			(1 << 0)
/**@}*/

/*------------------------------------------------*/
/** @defgroup usart_ctl1_values USART_CTL1 Values
@ingroup usart_defines
@{*/

/** ADD[7:0]: Address of the USART node. */
#define USART_CTL1_ADDR_SHIFT		24
#define USART_CTL1_ADDR			(0xFF << USART_CTL1_ADDR_SHIFT)
#define USART_CTL1_ADDR_VAL(x)		((x) << USART_CTL1_ADDR_SHIFT)

#define USART_CTL1_ABDM_MASK	3
#define USART_CTL1_ABDM_SHIFT	21
/** ABDM[1:0]: Auto baud rate mode
 * @defgroup usart_ctl1_abrmod Auto baud rate mode
 * @ingroup usart_defines
 * @{
 */
#define USART_CTL1_ABDM_STARTBIT	(0x0 << USART_CTL1_ABDM_SHIFT)
#define USART_CTL1_ABDM_FALL_EDGE	(0x1 << USART_CTL1_ABDM_SHIFT)
/**@}*/

/** RTEN: Receiver timeout enable */
#define USART_CTL1_RTEN			(1 << 23)

/** ABDEN: Auto baud rate enable */
#define USART_CTL1_ABDEN		(1 << 20)

/** MSBF: Most significant bit first */
#define USART_CTL1_MSBF			(1 << 19)

/** DINV: Binary data inversion */
#define USART_CTL1_DINV			(1 << 18)

/** TINV: TX pin active level inversion */
#define USART_CTL1_TINV			(1 << 17)

/** RINV: RX pin active level inversion */
#define USART_CTL1_RINV			(1 << 16)

/** STRP: Swap TX/RX pins */
#define USART_CTL1_STRP			(1 << 15)

/** LMEN: LM mode enable */
#define USART_CTL1_LMEN			(1 << 14)

/** CKEN: Clock enable */
#define USART_CTL1_CKEN			(1 << 11)

/** CPL: Clock polarity */
#define USART_CTL1_CPL			(1 << 10)

/** CPH: Clock phase */
#define USART_CTL1_CPH			(1 << 9)

/** CLEN: Last bit clock pulse */
#define USART_CTL1_CLEN			(1 << 8)

/** LBDIE: LIN break detection interrupt enable */
#define USART_CTL1_LBDIE		(1 << 6)

/** LBLEN: LIN break detection length */
#define USART_CTL1_LBLEN		(1 << 5)

/** ADDM:7-bit Address Detection/4-bit Address Detection */
#define USART_CTL1_ADDM			(1 << 4)

/**@}*/

/*------------------------------------------------*/
/** @defgroup usart_ctl2_values USART_CTL2 Values
@ingroup usart_defines
@{*/
/** WUIE: Wakeup from Deep-sleep mode interrupt enable */
#define USART_CTL2_WUIE			(1 << 22)

/** WUM[1:0]: Wakeup from Deep-sleep mode interrupt flag selection */
#define USART_CTL2_WUM_ADDRMATCH	(0x0 << 20)
#define USART_CTL2_WUM_START_BIT	(0x2 << 20)
#define USART_CTL2_WUM_RBNE		(0x3 << 20)

#define USART_CTL2_SCRTNUM_SHIFT	17
#define USART_CTL2_SCRTNUM_MASK		0x7
/** SCRTNUM[2:0]: Smartcard auto retry count */
#define USART_CTL2_SCRTNUM_DISABLE	(0 << USART_CTL2_SCRTNUM_SHIFT)
#define USART_CTL2_SCRTNUM_VAL(x)	((x) << USART_CTL2_SCRTNUM_SHIFT)

/** DEP: Driver enable polarity selection */
#define USART_CTL2_DEP			(1 << 15)

/** DEM: Driver enable mode */
#define USART_CTL2_DEM			(1 << 14)

/** DDRE: DMA Disable on Reception Error */
#define USART_CTL2_DDRE			(1 << 13)

/** OVRD: Overrun Disable */
#define USART_CTL2_OVRD			(1 << 12)

/** OSB: One sample bit method enable */
#define USART_CTL2_OSB			(1 << 11)

/** CTSIE: CTS interrupt enable. Not on UARTs */
#define USART_CTL2_CTSIE		(1 << 10)

/** CTSEN: CTS enable. Not on UARTS */
#define USART_CTL2_CTSEN		(1 << 9)

/** RTSEN: RTS enable. Not on UARTs */
#define USART_CTL2_RTSEN		(1 << 8)

/** DENT: DMA enable transmitter. Not on UARTs */
#define USART_CTL2_DENT			(1 << 7)

/** DENR: DMA enable receiver. Not on UARTS */
#define USART_CTL2_DENR			(1 << 6)

/** SCEN: Smartcard mode enable. Not on UARTs */
#define USART_CTL2_SCEN			(1 << 5)

/** NKEN: Smartcard NKEN enable. Not UARTs */
#define USART_CTL2_NKEN			(1 << 4)

/** HDEN: Half-duplex selection */
#define USART_CTL2_HDEN			(1 << 3)

/** IRLP: IrDA low-power */
#define USART_CTL2_IRLP			(1 << 2)

/** IREN: IrDA mode enable */
#define USART_CTL2_IREN			(1 << 1)

/** ERRIE: Error interrupt enable */
#define USART_CTL2_ERRIE		(1 << 0)

/**@}*/

/** @defgroup usart_gtpr_values USART_GP Values
 * @ingroup usart_defines
 * @{
 */
#define USART_GP_GUAT_SHIFT		8
#define USART_GP_GUAT			(0xFF << USART_GP_GUAT_SHIFT)
#define USART_GP_GUAT_VAL(x)		((x) << USART_GP_GUAT_SHIFT)

#define USART_GP_PSC_SHIFT		0
#define USART_GP_PSC			(0xFF << USART_GP_PSC_SHIFT)
#define USART_GP_PSC_VAL(x)		((x) << USART_GP_PSC_SHIFT)
/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_rt_values USART_RT Values
 * @ingroup usart_defines
 * @{
 */
/** BL[7:0]: Block Length */
#define USART_RT_BL_SHIFT			24
#define USART_RT_BL_MASK			(0xFF << USART_RT_BL_SHIFT)
#define USART_RT_BL_VAL(x)			((x) << USART_RT_BL_SHIFT)

/** RT[23:0]: Receiver timeout value */
#define USART_RT_RT_SHIFT			0
#define USART_RT_RT_MASK			(0xFFFFF << USART_RT_RT_SHIFT)
#define USART_RT_RT_VAL(x)			((x) << USART_RT_RT_SHIFT)

/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_cmd_values USART_CMD Values
 * @ingroup usart_defines
 * @{
 */
/** TXFCMD: Transmit data flush request */
#define USART_CMD_TXFCMD		    (1 << 4)

/** RXFCMD: Receive data flush request */
#define USART_CMD_RXFCMD		    (1 << 3)

/** MMCMD: Mute mode request */
#define USART_CMD_MMCMD		            (1 << 2)

/** SBKCMD: Send break request */
#define USART_CMD_SBKCMD		    (1 << 1)

/** ABRCMD: Auto baud rate request */
#define USART_CMD_ABRCMD		    (1 << 0)

/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_stat_values USART_STAT Values
 * @ingroup usart_defines
 * @{
 */

/** REA: Receive enable acknowledge flag */
#define USART_STAT_REA		            (1 << 22)

/** TEA: Transmit enable acknowledge flag */
#define USART_STAT_TEA		            (1 << 21)

/** WUF: Wakeup from Stop mode flag */
#define USART_STAT_WUF		            (1 << 20)

/** RWU: Receiver wakeup from Mute mode */
#define USART_STAT_RWU		            (1 << 19)

/** SBF: Send break flag */
#define USART_STAT_SBF		            (1 << 18)

/** AMF: Character match flag */
#define USART_STAT_AMF		            (1 << 17)

/** BSY: Busy flag */
#define USART_STAT_BSY		            (1 << 16)

/** ABDR: Auto baud rate flag */
#define USART_STAT_ABDR		            (1 << 15)

/** ABDE: Auto baud rate error */
#define USART_STAT_ABDE		            (1 << 14)

/** EBF: End of block flag */
#define USART_STAT_EBF		            (1 << 12)

/** RTF: Receiver timeout */
#define USART_STAT_RTF		            (1 << 11)

/** CTS: CTS flag */
#define USART_STAT_CTS		            (1 << 10)

/** CTSF: CTS interrupt flag */
#define USART_STAT_CTSF		            (1 << 9)

/** LBDF: LIN break detection flag */
#define USART_STAT_LBDF		            (1 << 8)

/** TBE: Transmit data register empty */
#define USART_STAT_TBE		            (1 << 7)

/** TC: Transmission complete */
#define USART_STAT_TC		            (1 << 6)

/** RBNE: Read data register not empty */
#define USART_STAT_RBNE		            (1 << 5)

/** IDLEF: Idle line detected */
#define USART_STAT_IDLEF		    (1 << 4)

/** ORERR: Overrun error */
#define USART_STAT_ORERR		    (1 << 3)

/** NERR: Noise detected flag */
#define USART_STAT_NERR		            (1 << 2)

/** FERR: Framing error */
#define USART_STAT_FERR		            (1 << 1)

/** PERR: Parity error */
#define USART_STAT_PERR		            (1 << 0)

/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_icr_values USART_INTC Values
 * @ingroup usart_defines
 * @{
 */

/** WUC: Wakeup from Stop mode clear flag */
#define USART_INTC_WUC			    (1 << 20)

/** AMC: Character match clear flag */
#define USART_INTC_AMC			    (1 << 17)

/** EBC: End of timeout clear flag */
#define USART_INTC_EBC			    (1 << 12)

/** RTC: Receiver timeout clear flag */
#define USART_INTC_RTC			    (1 << 11)

/** CTSC: CTS clear flag */
#define USART_INTC_CTSC			    (1 << 9)

/** LBDC: LIN break detection clear flag */
#define USART_INTC_LBDC			    (1 << 8)

/** TCC: Transmission complete clear flag */
#define USART_INTC_TCC			    (1 << 6)

/** IDLEC: Idle line detected clear flag */
#define USART_INTC_IDLEC		    (1 << 4)

/** OREC: Overrun error clear flag */
#define USART_INTC_OREC			    (1 << 3)

/** NEC: Noise detected clear flag */
#define USART_INTC_NEC			    (1 << 2)

/** FEC: Framing error clear flag */
#define USART_INTC_FEC			    (1 << 1)

/** PEC: Parity error clear flag */
#define USART_INTC_PEC			    (1 << 0)

/**@}*/

/** @defgroup usart_dr_values USART_RDATA/TDATA Values
 * @ingroup usart_defines
 * @{
 */
/** RDATA[8:0]: Receive data value */
#define USART_RDATA_MASK		    (0x1FF << 0)
/** TDATA[8:0]: Transmit data value */
#define USART_TDATA_MASK		    (0x1FF << 0)
/**@}*/


/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void usart_enable_data_inversion(uint32_t usart);
void usart_disable_data_inversion(uint32_t usart);
void usart_enable_tx_inversion(uint32_t usart);
void usart_disable_tx_inversion(uint32_t usart);
void usart_enable_rx_inversion(uint32_t usart);
void usart_disable_rx_inversion(uint32_t usart);
void usart_enable_halfduplex(uint32_t usart);
void usart_disable_halfduplex(uint32_t usart);

void usart_set_rx_timeout_value(uint32_t usart, uint32_t value);
void usart_enable_rx_timeout(uint32_t usart);
void usart_disable_rx_timeout(uint32_t usart);
void usart_enable_rx_timeout_interrupt(uint32_t usart);
void usart_disable_rx_timeout_interrupt(uint32_t usart);

END_DECLS


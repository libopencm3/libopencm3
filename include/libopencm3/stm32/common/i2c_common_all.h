/** @addtogroup i2c_defines */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA I2C.H */

#ifndef LIBOPENCM3_I2C_COMMON_ALL_H
#define LIBOPENCM3_I2C_COMMON_ALL_H

#include <libopencm3/cm3/common.h>

/**@{*/

/* --- Convenience macros -------------------------------------------------- */

/* I2C register base adresses (for convenience) */
/****************************************************************************/
/** @defgroup i2c_reg_base I2C register base address
@ingroup i2c_defines

@{*/
#define I2C1				I2C1_BASE
#define I2C2				I2C2_BASE

/* --- I2C registers ------------------------------------------------------- */

/* Control register 1 (I2Cx_CR1) */
#define I2C_CR1(i2c_base)		MMIO32(i2c_base + 0x00)
#define I2C1_CR1			I2C_CR1(I2C1)
#define I2C2_CR1			I2C_CR1(I2C2)

/* Control register 2 (I2Cx_CR2) */
#define I2C_CR2(i2c_base)		MMIO32(i2c_base + 0x04)
#define I2C1_CR2			I2C_CR2(I2C1)
#define I2C2_CR2			I2C_CR2(I2C2)

/* Own address register 1 (I2Cx_OAR1) */
#define I2C_OAR1(i2c_base)		MMIO32(i2c_base + 0x08)
#define I2C1_OAR1			I2C_OAR1(I2C1)
#define I2C2_OAR1			I2C_OAR1(I2C2)

/* Own address register 2 (I2Cx_OAR2) */
#define I2C_OAR2(i2c_base)		MMIO32(i2c_base + 0x0c)
#define I2C1_OAR2			I2C_OAR2(I2C1)
#define I2C2_OAR2			I2C_OAR2(I2C2)

/**@{*/

#if defined (STM32F3)

/**@{*/

/* Timing register (I2Cx_TIMINGR) */
#define I2C_TIMINGR(i2c_base)		MMIO32(i2c_base + 0x10)
#define I2C1_TIMINGR			I2C_TIMINGR(I2C1)
#define I2C2_TIMINGR			I2C_TIMINGR(I2C2)

/* Timeout register (I2Cx_TIMEOUTR) */
#define I2C_TIMEOUTR(i2c_base)		MMIO32(i2c_base + 0x14)
#define I2C1_TIMEOUTR			I2C_TIMEOUTR(I2C1)
#define I2C2_TIMEOUTR			I2C_TIMEOUTR(I2C2)

/* Interrupt and Status register (I2Cx_ISR) */
#define I2C_ISR(i2c_base)		MMIO32(i2c_base + 0x18)
#define I2C1_ISR			I2C_ISR(I2C1)
#define I2C2_ISR			I2C_ISR(I2C2)

/* Interrupt clear register (I2Cx_ICR) */
#define I2C_ICR(i2c_base)		MMIO32(i2c_base + 0x1C)
#define I2C1_ICR			I2C_ICR(I2C1)
#define I2C2_ICR			I2C_ICR(I2C2)

/* PEC register (I2Cx_PECR) */
#define I2C_PECR(i2c_base)		MMIO32(i2c_base + 0x20)
#define I2C1_PECR			I2C_PECR(I2C1)
#define I2C2_PECR			I2C_PECR(I2C2)

/* Receive data register (I2Cx_RXDR) */
#define I2C_RXDR(i2c_base)		MMIO32(i2c_base + 0x24)
#define I2C1_RXDR			I2C_RXDR(I2C1)
#define I2C2_RXDR			I2C_RXDR(I2C2)

/* Transmit data register (I2Cx_TXDR) */
#define I2C_TXDR(i2c_base)		MMIO32(i2c_base + 0x28)
#define I2C1_TXDR			I2C_TXDR(I2C1)
#define I2C2_TXDR			I2C_TXDR(I2C2)


/* --- I2Cx_CR1 values ----------------------------------------------------- */

/* PECEN: PEC enable */
#define I2C_CR1_PECEN			(1 << 23)

/* ALERTEN: SMBus alert enable */
#define I2C_CR1_ALERTEN			(1 << 22)

/* SMBDEN: SMBus Device Default address enable */
#define I2C_CR1_SMBDEN			(1 << 21)

/* SMBHEN: SMBus Host address enable */
#define I2C_CR1_SMBHEN			(1 << 20)

/* GCEN: General call enable */
#define I2C_CR1_GCEN			(1 << 19)

/* WUPEN: Wakeup from STOP enable */
#define I2C_CR1_WUPEN			(1 << 18)

/* NOSTRETCH: Clock stretching disable */
#define I2C_CR1_NOSTRETCH		(1 << 17)

/* SBC: Slave byte control */
#define I2C_CR1_SBC			(1 << 16)

/* RXDMAEN: DMA reception requests enable */
#define I2C_CR1_RXDMAEN			(1 << 15)

/* TXDMAEN: DMA transmission requests enable */
#define I2C_CR1_TXDMAEN			(1 << 14)

/* ANFOFF: Analog noise filter OFF */
#define I2C_CR1_ANFOFF			(1 << 12)

/* DNF[3:0]: Digital noise filter */
#define I2C_CR1_DNF_DISABLED		(0x0 << 8)
#define I2C_CR1_DNF_UP_1_TI2CCLK	(0x1 << 8)
#define I2C_CR1_DNF_UP_2_TI2CCLK	(0x2 << 8)
#define I2C_CR1_DNF_UP_3_TI2CCLK	(0x3 << 8)
#define I2C_CR1_DNF_UP_4_TI2CCLK	(0x4 << 8)
#define I2C_CR1_DNF_UP_5_TI2CCLK	(0x5 << 8)
#define I2C_CR1_DNF_UP_6_TI2CCLK	(0x6 << 8)
#define I2C_CR1_DNF_UP_7_TI2CCLK	(0x7 << 8)
#define I2C_CR1_DNF_UP_8_TI2CCLK	(0x8 << 8)
#define I2C_CR1_DNF_UP_9_TI2CCLK	(0x9 << 8)
#define I2C_CR1_DNF_UP_10_TI2CCLK	(0xA << 8)
#define I2C_CR1_DNF_UP_11_TI2CCLK	(0xB << 8)
#define I2C_CR1_DNF_UP_12_TI2CCLK	(0xC << 8)
#define I2C_CR1_DNF_UP_13_TI2CCLK	(0xD << 8)
#define I2C_CR1_DNF_UP_14_TI2CCLK	(0xE << 8)
#define I2C_CR1_DNF_UP_15_TI2CCLK	(0xF << 8)

/* ERRIE: Error interrupts enable */
#define I2C_CR1_ERRIE			(1 << 7)

/* TCIE: Transfer Complete interrupt enable */
#define I2C_CR1_TCIE			(1 << 6)

/* STOPIE: STOP detection Interrupt enable */
#define I2C_CR1_STOPIE			(1 << 5)

/* NACKIE: Not acknowledge received Interrupt enable */
#define I2C_CR1_NACKIE			(1 << 4)

/* ADDRIE: Address match Interrupt enable (slave only) */
#define I2C_CR1_DDRIE			(1 << 3)

/* RXIE: RX Interrupt enable */
#define I2C_CR1_RXIE			(1 << 2)

/* TXIE: TX Interrupt enable */
#define I2C_CR1_TXIE			(1 << 1)

/* PE: Peripheral enable */
#define I2C_CR1_PE			(1 << 0)


/* --- I2Cx_CR2 values ----------------------------------------------------- */

/* PECBYTE: Packet error checking byte */
#define I2C_CR2_PECBYTE			(1 << 26)

/* AUTOEND: Automatic end mode (master mode) */
#define I2C_CR2_AUTOEND			(1 << 25)

/* RELOAD: NBYTES reload mode */
#define I2C_CR2_RELOAD			(1 << 24)

/* NBYTES[7:0]: Number of bytes (23,16) */

/* NACK: NACK generation (slave mode) */
#define I2C_CR2_NACK			(1 << 15)

/* STOP: Stop generation (master mode) */
#define I2C_CR2_STOP			(1 << 14)

/* START: Start generation */
#define I2C_CR2_START			(1 << 13)

/* HEAD10R: 10-bit address header only read direction (master receiver mode) */
#define I2C_CR2_HEAD10R			(1 << 12)

/* ADD10: 10-bit addressing mode (master mode) */
#define I2C_CR2_ADD10			(1 << 11)

/* RD_WRN: Transfer direction (master mode) */
#define I2C_CR2_RD_WRN			(1 << 10)

//preguntar

/* SADD[9:8]: Slave address bit 9:8 (master mode) */
#define I2C_CR2_SADD1_7BIT		(0x0 << 8)
#define I2C_CR2_SADD1_10BIT		(0x1 << 8)

/* SADD[7:1]: Slave address bit 7:1 (master mode) */
#define I2C_CR2_SADD2_7BIT		(0x0 << 1)
#define I2C_CR2_SADD2_10BIT		(0x1 << 1)

/* SADD0: Slave address bit 0 (master mode) */
#define I2C_CR2_SADD0_7BIT		(0 << 0)
#define I2C_CR2_SADD0_10BIT		(1 << 0)


/* --- I2Cx_OAR1 values ---------------------------------------------------- */

/* OA1EN: Own Address 1 enable */
#define I2C_OAR1_OA1EN_DISABLE		(0x0 << 15)
#define I2C_OAR1_OA1EN_ENABLE		(0x1 <<15)

/* OA1MODE Own Address 1 10-bit mode */
#define I2C_OAR1_OA1MODE		(1 << 10)
#define I2C_OAR1_OA1MODE_7BIT		0
#define I2C_OAR1_OA1MODE_10BIT		1

//preguntar

/* OA1[9:8]: Interface address */

/* OA1[7:1]: Interface address */

/* OA1[0]: Interface address */
#define I2C_OAR1_OA1			(1 << 10)
#define I2C_OAR1_OA1_7BIT		0
#define I2C_OAR1_OA1_10BIT		1


/* --- I2Cx_OAR2 values ---------------------------------------------------- */

/* OA2EN: Own Address 2 enable */
#define I2C_OAR2_OA2EN			(1 << 15)

/* OA2MSK[2:0]: Own Address 2 masks */
#define I2C_OAR2_OA2MSK_NO_MASK		(0x0 << 8)
#define I2C_OAR2_OA2MSK_OA2_7_OA2_2	(0x1 << 8)
#define I2C_OAR2_OA2MSK_OA2_7_OA2_3	(0x2 << 8)
#define I2C_OAR2_OA2MSK_OA2_7_OA2_4	(0x3 << 8)
#define I2C_OAR2_OA2MSK_OA2_7_OA2_5	(0x4 << 8)
#define I2C_OAR2_OA2MSK_OA2_7_OA2_6	(0x5 << 8)
#define I2C_OAR2_OA2MSK_OA2_7		(0x6 << 8)
#define I2C_OAR2_OA2MSK_NO_CMP		(0x7 << 8)

/* OA2[7:1]: Interface address */


/* --- I2Cx_TIMINGR values ---------------------------------------------------- */

//PREGUNTAR
/* PRESC[3:0]: Timing prescaler (31,28) */

/* SCLDEL[3:0]: Data setup time (23,20) */

/* SDADEL[3:0]: Data hold time (19,16) */

/* SCLH[7:0]: SCL high period (master mode) (15,8) */

/* SCLL[7:0]: SCL low period (master mode) (7,0) */


/* --- I2Cx_TIEMOUTR values ---------------------------------------------------- */

/* TEXTEN: Extended clock timeout enable */
#define I2C_TIEMOUTR_TEXTEN		(1 << 31)

//PREGUNTAR
/* TIMEOUTB[11:0]: Bus timeout B */

/* TIMOUTEN: Clock timeout enable */
#define I2C_TIEMOUTR_TIMOUTEN		(1 << 15)

/* TIDLE: Idle clock timeout detection */
#define I2C_TIEMOUTR_TIDLE_SCL_LOW	(0x0 << 12)
#define I2C_TIEMOUTR_TIDLE_SCL_SDA_HIGH	(0x1 << 12)

//PREGUNTAR
/* TIMEOUTA[11:0]: Bus Timeout A */


/* --- I2Cx_ISR values ---------------------------------------------------- */

/* Bits 31:24 Reserved, must be kept at reset value */

//PREGUNTAR
/* ADDCODE[6:0]: Address match code (Slave mode) */

/* DIR: Transfer direction (Slave mode) */
#define I2C_ISR_DIR_READ		(0x1 << 16)
#define I2C_ISR_DIR_WRITE		(0x0 << 16)

/* BUSY: Bus busy */
#define I2C_ISR_BUSY			(1 << 15)

/* ALERT: SMBus alert */
#define I2C_ISR_ALERT			(1 << 13)

/* TIMEOUT: Timeout or tLOW detection flag */
#define I2C_ISR_TIMEOUT			(1 << 12)

/* PECERR: PEC Error in reception */
#define I2C_ISR_PECERR			(1 << 11)

/* OVR: Overrun/Underrun (slave mode) */
#define I2C_ISR_OVR			(1 << 10)

/* ARLO: Arbitration lost */
#define I2C_ISR_ARLO			(1 << 9)

/* BERR: Bus error */
#define I2C_ISR_BERR			(1 << 8)

/* TCR: Transfer Complete Reload */
#define I2C_ISR_TCR			(1 << 7)

/* TC: Transfer Complete (master mode) */
#define I2C_ISR_TC			(1 << 6)

/* STOPF: Stop detection flag */
#define I2C_ISR_STOPF			(1 << 5)

/* NACKF: Not Acknowledge received flag */
#define I2C_ISR_NACKF			(1 << 4)

/* ADDR: Address matched (slave mode) */
#define I2C_ISR_ADDR			(1 << 3)

/* RXNE: Receive data register not empty (receivers) */
#define I2C_ISR_RXNE			(1 << 2)

/* TXIS: Transmit interrupt status (transmitters) */
#define I2C_ISR_TXIS			(1 << 1)

/* TXE: Transmit data register empty (transmitters) */
#define I2C_ISR_TXE			(1 << 0)


/* --- I2Cx_ICR values ---------------------------------------------------- */

/* ALERTCF: Alert flag clear */
#define I2C_ICR_ALERTCF			(1 << 13)

/* TIMOUTCF: Timeout detection flag clear */
#define I2C_ICR_TIMOUTCF		(1 << 12)

/* PECCF: PEC Error flag clear */
#define I2C_ICR_PECCF			(1 << 11)

/* OVRCF: Overrun/Underrun flag clear */
#define I2C_ICR_OVRCF			(1 << 10)

/* ARLOCF: Arbitration Lost flag clear */
#define I2C_ICR_ARLOCF			(1 << 9)

/* BERRCF: Bus error flag clear */
#define I2C_ICR_BERRCF			(1 << 8)

/* STOPCF: Stop detection flag clear */
#define I2C_ICR_STOPCF			(1 << 5)

/* NACKCF: Not Acknowledge flag clear */
#define I2C_ICR_NACKCF			(1 << 4)

/* ADDRCF: Address Matched flag clear */
#define I2C_ICR_ADDRCF			(1 << 3)


/* --- I2Cx_PECR values ---------------------------------------------------- */

/* PEC[7:0] Packet error checking register  */


/* --- I2Cx_RXDR values ---------------------------------------------------- */

/* RXDATA[7:0] 8-bit receive data */


/* --- I2Cx_TXDR values ---------------------------------------------------- */

/* TXDATA[7:0] 8-bit transmit data */


/* --- I2C const definitions ----------------------------------------------- */

/****************************************************************************/
/** @defgroup i2c_rw I2C Read/Write bit
@ingroup i2c_defines

@{*/
#define I2C_WRITE			0
#define I2C_READ			1
/**@}*/

/* --- I2C funtion prototypes----------------------------------------------- */

BEGIN_DECLS

void i2c_reset(u32 i2c);
void i2c_peripheral_enable(u32 i2c);
void i2c_peripheral_disable(u32 i2c);
void i2c_send_start(u32 i2c);
void i2c_send_stop(u32 i2c);
void i2c_set_own_7bit_slave_address(u32 i2c, u8 slave);
void i2c_set_own_10bit_slave_address(u32 i2c, u16 slave);
void i2c_set_clock_frequency(u32 i2c, u8 freq);
void i2c_send_data(u32 i2c, u8 data);

END_DECLS

#endif

/**@}*/

#if !defined (STM32F3)

/**@}*/

/* Data register (I2Cx_DR) */
#define I2C_DR(i2c_base)		MMIO32(i2c_base + 0x10)
#define I2C1_DR				I2C_DR(I2C1)
#define I2C2_DR				I2C_DR(I2C2)

/* Status register 1 (I2Cx_SR1) */
#define I2C_SR1(i2c_base)		MMIO32(i2c_base + 0x14)
#define I2C1_SR1			I2C_SR1(I2C1)
#define I2C2_SR1			I2C_SR1(I2C2)

/* Status register 2 (I2Cx_SR2) */
#define I2C_SR2(i2c_base)		MMIO32(i2c_base + 0x18)
#define I2C1_SR2			I2C_SR2(I2C1)
#define I2C2_SR2			I2C_SR2(I2C2)

/* Clock control register (I2Cx_CCR) */
#define I2C_CCR(i2c_base)		MMIO32(i2c_base + 0x1c)
#define I2C1_CCR			I2C_CCR(I2C1)
#define I2C2_CCR			I2C_CCR(I2C2)

/* TRISE register (I2Cx_TRISE) */
#define I2C_TRISE(i2c_base)		MMIO32(i2c_base + 0x20)
#define I2C1_TRISE			I2C_TRISE(I2C1)
#define I2C2_TRISE			I2C_TRISE(I2C2)

/* --- I2Cx_CR1 values ----------------------------------------------------- */

/* SWRST: Software reset */
#define I2C_CR1_SWRST			(1 << 15)

/* Note: Bit 14 is reserved, and forced to 0 by hardware. */

/* ALERT: SMBus alert */
#define I2C_CR1_ALERT			(1 << 13)

/* PEC: Packet error checking */
#define I2C_CR1_PEC			(1 << 12)

/* POS: Acknowledge / PEC postition */
#define I2C_CR1_POS			(1 << 11)

/* ACK: Acknowledge enable */
#define I2C_CR1_ACK			(1 << 10)

/* STOP: STOP generation */
#define I2C_CR1_STOP			(1 << 9)

/* START: START generation */
#define I2C_CR1_START			(1 << 8)

/* NOSTRETCH: Clock stretching disable (slave mode) */
#define I2C_CR1_NOSTRETCH		(1 << 7)

/* ENGC: General call enable */
#define I2C_CR1_ENGC			(1 << 6)

/* ENPEC: Enable PEC */
#define I2C_CR1_ENPEC			(1 << 5)

/* ENARP: ARP enable */
#define I2C_CR1_ENARP			(1 << 4)

/* SMBTYPE: SMBus type */
#define I2C_CR1_SMBTYPE			(1 << 3)

/* Note: Bit 2 is reserved, and forced to 0 by hardware. */

/* SMBUS: SMBus mode */
#define I2C_CR1_SMBUS			(1 << 1)

/* PE: Peripheral enable */
#define I2C_CR1_PE			(1 << 0)

/* --- I2Cx_CR2 values ----------------------------------------------------- */

/* Note: Bits [15:13] are reserved, and forced to 0 by hardware. */

/* LAST: DMA last transfer */
#define I2C_CR2_LAST			(1 << 12)

/* DMAEN: DMA requests enable */
#define I2C_CR2_DMAEN			(1 << 11)

/* ITBUFEN: Buffer interrupt enable */
#define I2C_CR2_ITBUFEN			(1 << 10)

/* ITEVTEN: Event interrupt enable */
#define I2C_CR2_ITEVTEN			(1 << 9)

/* ITERREN: Error interrupt enable */
#define I2C_CR2_ITERREN			(1 << 8)

/* Note: Bits [7:6] are reserved, and forced to 0 by hardware. */

/* FREQ[5:0]: Peripheral clock frequency (valid values: 2-36 MHz) */
/****************************************************************************/
/** @defgroup i2c_clock I2C clock frequency settings
@ingroup i2c_defines

@{*/
#define I2C_CR2_FREQ_2MHZ		0x02
#define I2C_CR2_FREQ_3MHZ		0x03
#define I2C_CR2_FREQ_4MHZ		0x04
#define I2C_CR2_FREQ_5MHZ		0x05
#define I2C_CR2_FREQ_6MHZ		0x06
#define I2C_CR2_FREQ_7MHZ		0x07
#define I2C_CR2_FREQ_8MHZ		0x08
#define I2C_CR2_FREQ_9MHZ		0x09
#define I2C_CR2_FREQ_10MHZ		0x0a
#define I2C_CR2_FREQ_11MHZ		0x0b
#define I2C_CR2_FREQ_12MHZ		0x0c
#define I2C_CR2_FREQ_13MHZ		0x0d
#define I2C_CR2_FREQ_14MHZ		0x0e
#define I2C_CR2_FREQ_15MHZ		0x0f
#define I2C_CR2_FREQ_16MHZ		0x10
#define I2C_CR2_FREQ_17MHZ		0x11
#define I2C_CR2_FREQ_18MHZ		0x12
#define I2C_CR2_FREQ_19MHZ		0x13
#define I2C_CR2_FREQ_20MHZ		0x14
#define I2C_CR2_FREQ_21MHZ		0x15
#define I2C_CR2_FREQ_22MHZ		0x16
#define I2C_CR2_FREQ_23MHZ		0x17
#define I2C_CR2_FREQ_24MHZ		0x18
#define I2C_CR2_FREQ_25MHZ		0x19
#define I2C_CR2_FREQ_26MHZ		0x1a
#define I2C_CR2_FREQ_27MHZ		0x1b
#define I2C_CR2_FREQ_28MHZ		0x1c
#define I2C_CR2_FREQ_29MHZ		0x1d
#define I2C_CR2_FREQ_30MHZ		0x1e
#define I2C_CR2_FREQ_31MHZ		0x1f
#define I2C_CR2_FREQ_32MHZ		0x20
#define I2C_CR2_FREQ_33MHZ		0x21
#define I2C_CR2_FREQ_34MHZ		0x22
#define I2C_CR2_FREQ_35MHZ		0x23
#define I2C_CR2_FREQ_36MHZ		0x24
/**@}*/

/* --- I2Cx_OAR1 values ---------------------------------------------------- */

/* ADDMODE: Addressing mode (slave mode) */
#define I2C_OAR1_ADDMODE		(1 << 15)
#define I2C_OAR1_ADDMODE_7BIT		0
#define I2C_OAR1_ADDMODE_10BIT		1

/* Note: Bit 14 should always be kept at 1 by software! */

/* Note: Bits [13:10] are reserved, and forced to 0 by hardware. */

/* ADD: Address bits: [7:1] in 7-bit mode, bits [9:0] in 10-bit mode */

/* --- I2Cx_OAR2 values ---------------------------------------------------- */

/* Note: Bits [15:8] are reserved, and forced to 0 by hardware. */

/* ADD2[7:1]: Interface address (bits [7:1] in dual addressing mode) */

/* ENDUAL: Dual addressing mode enable */
#define I2C_OAR2_ENDUAL			(1 << 0)

/* --- I2Cx_DR values ------------------------------------------------------ */

/* Note: Bits [15:8] are reserved, and forced to 0 by hardware. */

/* DR[7:0] 8-bit data register */

/* --- I2Cx_SR1 values ----------------------------------------------------- */

/* SMBALERT: SMBus alert */
#define I2C_SR1_SMBALERT		(1 << 15)

/* TIMEOUT: Timeout or Tlow Error */
#define I2C_SR1_TIMEOUT			(1 << 14)

/* Note: Bit 13 is reserved, and forced to 0 by hardware. */

/* PECERR: PEC Error in reception */
#define I2C_SR1_PECERR			(1 << 12)

/* OVR: Overrun/Underrun */
#define I2C_SR1_OVR			(1 << 11)

/* AF: Acknowledge failure */
#define I2C_SR1_AF			(1 << 10)

/* ARLO: Arbitration lost (master mode) */
#define I2C_SR1_ARLO			(1 << 9)

/* BERR: Bus error */
#define I2C_SR1_BERR			(1 << 8)

/* TxE: Data register empty (transmitters) */
#define I2C_SR1_TxE			(1 << 7)

/* RxNE: Data register not empty (receivers) */
#define I2C_SR1_RxNE			(1 << 6)

/* Note: Bit 5 is reserved, and forced to 0 by hardware. */

/* STOPF: STOP detection (slave mode) */
#define I2C_SR1_STOPF			(1 << 4)

/* ADD10: 10-bit header sent (master mode) */
#define I2C_SR1_ADD10			(1 << 3)

/* BTF: Byte transfer finished */
#define I2C_SR1_BTF			(1 << 2)

/* ADDR: Address sent (master mode) / address matched (slave mode) */
#define I2C_SR1_ADDR			(1 << 1)

/* SB: Start bit (master mode) */
#define I2C_SR1_SB			(1 << 0)

/* --- I2Cx_SR2 values ----------------------------------------------------- */

/* Bits [15:8]: PEC[7:0]: Packet error checking register */

/* DUALF: Dual flag (slave mode) */
#define I2C_SR2_DUALF			(1 << 7)

/* SMBHOST: SMBus host header (slave mode) */
#define I2C_SR2_SMBHOST			(1 << 6)

/* SMBDEFAULT: SMBus device default address (slave mode) */
#define I2C_SR2_SMBDEFAULT		(1 << 5)

/* GENCALL: General call address (slave mode) */
#define I2C_SR2_GENCALL			(1 << 4)

/* Note: Bit 3 is reserved, and forced to 0 by hardware. */

/* TRA: Transmitter / receiver */
#define I2C_SR2_TRA			(1 << 2)

/* BUSY: Bus busy */
#define I2C_SR2_BUSY			(1 << 1)

/* MSL: Master / slave */
#define I2C_SR2_MSL			(1 << 0)

/* --- I2Cx_CCR values ----------------------------------------------------- */

/* F/S: I2C Master mode selection (fast / standard) */
#define I2C_CCR_FS			(1 << 15)

/* DUTY: Fast Mode Duty Cycle */
/** @defgroup i2c_duty_cycle I2C peripheral clock duty cycles
@ingroup i2c_defines

@{*/
#define I2C_CCR_DUTY			(1 << 14)
#define I2C_CCR_DUTY_DIV2		0
#define I2C_CCR_DUTY_16_DIV_9		1
/**@}*/

/* Note: Bits [13:12] are reserved, and forced to 0 by hardware. */

/*
 * Bits [11:0]:
 * CCR[11:0]: Clock control register in Fast/Standard mode (master mode)
 */

/* --- I2Cx_TRISE values --------------------------------------------------- */

/* Note: Bits [15:6] are reserved, and forced to 0 by hardware. */

/*
 * Bits [5:0]:
 * TRISE[5:0]: Maximum rise time in Fast/Standard mode (master mode)
 */

/* --- I2C const definitions ----------------------------------------------- */

/****************************************************************************/
/** @defgroup i2c_rw I2C Read/Write bit
@ingroup i2c_defines

@{*/
#define I2C_WRITE			0
#define I2C_READ			1
/**@}*/

/* --- I2C funtion prototypes----------------------------------------------- */

BEGIN_DECLS

void i2c_reset(u32 i2c);
void i2c_peripheral_enable(u32 i2c);
void i2c_peripheral_disable(u32 i2c);
void i2c_send_start(u32 i2c);
void i2c_send_stop(u32 i2c);
void i2c_clear_stop(u32 i2c);
void i2c_set_own_7bit_slave_address(u32 i2c, u8 slave);
void i2c_set_own_10bit_slave_address(u32 i2c, u16 slave);
void i2c_set_fast_mode(u32 i2c);
void i2c_set_standard_mode(u32 i2c);
void i2c_set_clock_frequency(u32 i2c, u8 freq);
void i2c_set_ccr(u32 i2c, u16 freq);
void i2c_set_trise(u32 i2c, u16 trise);
void i2c_send_7bit_address(u32 i2c, u8 slave, u8 readwrite);
void i2c_send_data(u32 i2c, u8 data);
uint8_t i2c_get_data(u32 i2c);
void i2c_enable_interrupt(u32 i2c, u32 interrupt);
void i2c_disable_interrupt(u32 i2c, u32 interrupt);
void i2c_enable_ack(u32 i2c);
void i2c_disable_ack(u32 i2c);
void i2c_nack_next(u32 i2c);
void i2c_nack_current(u32 i2c);
void i2c_set_dutycycle(u32 i2c, u32 dutycycle);
void i2c_enable_dma(u32 i2c);
void i2c_disable_dma(u32 i2c);
void i2c_set_dma_last_transfer(u32 i2c);
void i2c_clear_dma_last_transfer(u32 i2c);

END_DECLS

#endif
#endif
/**@}*/


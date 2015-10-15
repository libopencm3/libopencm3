/** @defgroup i2c_defines I2C Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F3xx I2C </b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 12 October 2012
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

#ifndef LIBOPENCM3_I2C_H
#define LIBOPENCM3_I2C_H

/**@{*/

/* --- Convenience macros -------------------------------------------------- */

/* I2C register base addresses (for convenience) */
/*****************************************************************************/
/** @defgroup i2c_reg_base I2C register base address
 * @ingroup i2c_defines
 * @{*/
#define I2C1				I2C1_BASE
#define I2C2				I2C2_BASE
/**@}*/

/* --- I2C registers ------------------------------------------------------- */

/* Control register 1 (I2Cx_CR1) */
#define I2C_CR1(i2c_base)		MMIO32((i2c_base) + 0x00)
#define I2C1_CR1			I2C_CR1(I2C1)
#define I2C2_CR1			I2C_CR1(I2C2)

/* Control register 2 (I2Cx_CR2) */
#define I2C_CR2(i2c_base)		MMIO32((i2c_base) + 0x04)
#define I2C1_CR2			I2C_CR2(I2C1)
#define I2C2_CR2			I2C_CR2(I2C2)

/* Own address register 1 (I2Cx_OAR1) */
#define I2C_OAR1(i2c_base)		MMIO32((i2c_base) + 0x08)
#define I2C1_OAR1			I2C_OAR1(I2C1)
#define I2C2_OAR1			I2C_OAR1(I2C2)

/* Own address register 2 (I2Cx_OAR2) */
#define I2C_OAR2(i2c_base)		MMIO32((i2c_base) + 0x0c)
#define I2C1_OAR2			I2C_OAR2(I2C1)
#define I2C2_OAR2			I2C_OAR2(I2C2)

/* Timing register (I2Cx_TIMINGR) */
#define I2C_TIMINGR(i2c_base)		MMIO32((i2c_base) + 0x10)
#define I2C1_TIMINGR			I2C_TIMINGR(I2C1)
#define I2C2_TIMINGR			I2C_TIMINGR(I2C2)

/* Timeout register (I2Cx_TIMEOUTR) */
#define I2C_TIMEOUTR(i2c_base)		MMIO32((i2c_base) + 0x14)
#define I2C1_TIMEOUTR			I2C_TIMEOUTR(I2C1)
#define I2C2_TIMEOUTR			I2C_TIMEOUTR(I2C2)

/* Interrupt and Status register (I2Cx_ISR) */
#define I2C_ISR(i2c_base)		MMIO32((i2c_base) + 0x18)
#define I2C1_ISR			I2C_ISR(I2C1)
#define I2C2_ISR			I2C_ISR(I2C2)

/* Interrupt clear register (I2Cx_ICR) */
#define I2C_ICR(i2c_base)		MMIO32((i2c_base) + 0x1C)
#define I2C1_ICR			I2C_ICR(I2C1)
#define I2C2_ICR			I2C_ICR(I2C2)

/* PEC register (I2Cx_PECR) */
#define I2C_PECR(i2c_base)		MMIO32((i2c_base) + 0x20)
#define I2C1_PECR			I2C_PECR(I2C1)
#define I2C2_PECR			I2C_PECR(I2C2)

/* Receive data register (I2Cx_RXDR) */
#define I2C_RXDR(i2c_base)		MMIO32((i2c_base) + 0x24)
#define I2C1_RXDR			I2C_RXDR(I2C1)
#define I2C2_RXDR			I2C_RXDR(I2C2)

/* Transmit data register (I2Cx_TXDR) */
#define I2C_TXDR(i2c_base)		MMIO32((i2c_base) + 0x28)
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
#define I2C_CR1_DNF_MASK                (0xF << 8)

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
#define I2C_CR2_NBYTES_SHIFT            16
#define I2C_CR2_NBYTES_MASK             (0xFF << I2C_CR2_NBYTES_SHIFT)

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

#define I2C_CR2_SADD_7BIT_SHIFT         1
#define I2C_CR2_SADD_10BIT_SHIFT        0
#define I2C_CR2_SADD_7BIT_MASK          (0x7F << I2C_CR2_SADD_7BIT_SHIFT)
#define I2C_CR2_SADD_10BIT_MASK         0x3FF

/* --- I2Cx_OAR1 values ---------------------------------------------------- */

/* OA1EN: Own Address 1 enable */
#define I2C_OAR1_OA1EN_DISABLE		(0x0 << 15)
#define I2C_OAR1_OA1EN_ENABLE		(0x1 << 15)

/* OA1MODE Own Address 1 10-bit mode */
#define I2C_OAR1_OA1MODE		(1 << 10)
#define I2C_OAR1_OA1MODE_7BIT		0
#define I2C_OAR1_OA1MODE_10BIT		1

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

/* --- I2Cx_TIMINGR values ------------------------------------------------- */

/* PRESC[3:0]: Timing prescaler (31,28) */
#define I2C_TIMINGR_PRESC_SHIFT 28
#define I2C_TIMINGR_PRESC_MASK (0xF << 28)

/* SCLDEL[3:0]: Data setup time (23,20) */
#define I2C_TIMINGR_SCLDEL_SHIFT 20
#define I2C_TIMINGR_SCLDEL_MASK (0xF << I2C_TIMINGR_SCLDEL_SHIFT)

/* SDADEL[3:0]: Data hold time (19,16) */
#define I2C_TIMINGR_SDADEL_SHIFT 16
#define I2C_TIMINGR_SDADEL_MASK (0xF << I2C_TIMINGR_SDADEL_SHIFT)

/* SCLH[7:0]: SCL high period (master mode) (15,8) */
#define I2C_TIMINGR_SCLH_SHIFT 8
#define I2C_TIMINGR_SCLH_MASK (0xFF << I2C_TIMINGR_SCLH_SHIFT)

/* SCLL[7:0]: SCL low period (master mode) (7,0) */
#define I2C_TIMINGR_SCLL_SHIFT 0
#define I2C_TIMINGR_SCLL_MASK (0xFF << I2C_TIMINGR_SCLL_SHIFT)

/* --- I2Cx_TIEMOUTR values ------------------------------------------------ */

/* TEXTEN: Extended clock timeout enable */
#define I2C_TIEMOUTR_TEXTEN		(1 << 31)

/* XXX: Not clear yet. */
/* TIMEOUTB[11:0]: Bus timeout B */

/* TIMOUTEN: Clock timeout enable */
#define I2C_TIEMOUTR_TIMOUTEN		(1 << 15)

/* TIDLE: Idle clock timeout detection */
#define I2C_TIEMOUTR_TIDLE_SCL_LOW	(0x0 << 12)
#define I2C_TIEMOUTR_TIDLE_SCL_SDA_HIGH	(0x1 << 12)

/* XXX: Not clear yet. */
/* TIMEOUTA[11:0]: Bus Timeout A */

/* --- I2Cx_ISR values ----------------------------------------------------- */

/* Bits 31:24 Reserved, must be kept at reset value */

/* XXX: Not clear yet. */
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

/* --- I2Cx_ICR values ----------------------------------------------------- */

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

/* --- I2C function prototypes---------------------------------------------- */

BEGIN_DECLS

void i2c_reset(uint32_t i2c);
void i2c_peripheral_enable(uint32_t i2c);
void i2c_peripheral_disable(uint32_t i2c);
void i2c_send_start(uint32_t i2c);
void i2c_send_stop(uint32_t i2c);
void i2c_clear_stop(uint32_t i2c);
void i2c_set_own_7bit_slave_address(uint32_t i2c, uint8_t slave);
void i2c_set_own_10bit_slave_address(uint32_t i2c, uint16_t slave);
void i2c_set_clock_frequency(uint32_t i2c, uint8_t freq);
void i2c_send_data(uint32_t i2c, uint8_t data);
uint8_t i2c_get_data(uint32_t i2c);

void i2c_enable_analog_filter(uint32_t i2c);
void i2c_disable_analog_filter(uint32_t i2c);
void i2c_set_digital_filter(uint32_t i2c, uint8_t dnf_setting);
void i2c_set_prescaler(uint32_t i2c, uint8_t presc);
void i2c_set_data_setup_time(uint32_t i2c, uint8_t s_time);
void i2c_set_data_hold_time(uint32_t i2c, uint8_t h_time);
void i2c_set_scl_high_period(uint32_t i2c, uint8_t period);
void i2c_set_scl_low_period(uint32_t i2c, uint8_t period);
void i2c_enable_stretching(uint32_t i2c);
void i2c_disable_stretching(uint32_t i2c);
void i2c_100khz_i2cclk8mhz(uint32_t i2c);
void i2c_set_7bit_addr_mode(uint32_t i2c);
void i2c_set_10bit_addr_mode(uint32_t i2c);
void i2c_set_7bit_address(uint32_t i2c, uint8_t addr);
void i2c_set_10bit_address(uint32_t i2c, uint16_t addr);
void i2c_set_write_transfer_dir(uint32_t i2c);
void i2c_set_read_transfer_dir(uint32_t i2c);
void i2c_set_bytes_to_transfer(uint32_t i2c, uint32_t n_bytes);
uint8_t i2c_is_start(uint32_t i2c);
void i2c_enable_autoend(uint32_t i2c);
void i2c_disable_autoend(uint32_t i2c);
uint8_t i2c_nack(uint32_t i2c);
uint8_t i2c_busy(uint32_t i2c);
uint8_t i2c_transmit_int_status(uint32_t i2c);
uint8_t i2c_transfer_complete(uint32_t i2c);
uint8_t i2c_received_data(uint32_t i2c);
void i2c_enable_interrupt(uint32_t i2c, uint32_t interrupt);
void i2c_disable_interrupt(uint32_t i2c, uint32_t interrupt);
void i2c_enable_rxdma(uint32_t i2c);
void i2c_disable_rxdma(uint32_t i2c);
void i2c_enable_txdma(uint32_t i2c);
void i2c_disable_txdma(uint32_t i2c);
void write_i2c(uint32_t i2c, uint8_t i2c_addr, uint8_t reg,
	       uint8_t size, uint8_t *data);
void read_i2c(uint32_t i2c, uint8_t i2c_addr, uint8_t reg,
	      uint8_t size, uint8_t *data);

END_DECLS

/**@}*/

#endif

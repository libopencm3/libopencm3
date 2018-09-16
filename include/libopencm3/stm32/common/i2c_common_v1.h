/** @addtogroup i2c_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>
 *
 */
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA I2C.H
The order of header inclusion is important. i2c.h includes the device
specific memorymap.h header before including this header file.*/

/**@{*/

/** @cond */
#ifdef LIBOPENCM3_I2C_H
/** @endcond */
#ifndef LIBOPENCM3_I2C_COMMON_V1_H
#define LIBOPENCM3_I2C_COMMON_V1_H

#include <stddef.h>
#include <stdint.h>

/* --- Convenience macros -------------------------------------------------- */

/* I2C register base addresses (for convenience) */
/****************************************************************************/
/** @defgroup i2c_reg_base I2C register base address
@ingroup i2c_defines

@{*/
#define I2C1				I2C1_BASE
#define I2C2				I2C2_BASE
#ifdef I2C3_BASE
#define I2C3				I2C3_BASE
#endif
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

/* Data register (I2Cx_DR) */
#define I2C_DR(i2c_base)		MMIO32((i2c_base) + 0x10)
#define I2C1_DR				I2C_DR(I2C1)
#define I2C2_DR				I2C_DR(I2C2)

/* Status register 1 (I2Cx_SR1) */
#define I2C_SR1(i2c_base)		MMIO32((i2c_base) + 0x14)
#define I2C1_SR1			I2C_SR1(I2C1)
#define I2C2_SR1			I2C_SR1(I2C2)

/* Status register 2 (I2Cx_SR2) */
#define I2C_SR2(i2c_base)		MMIO32((i2c_base) + 0x18)
#define I2C1_SR2			I2C_SR2(I2C1)
#define I2C2_SR2			I2C_SR2(I2C2)

/* Clock control register (I2Cx_CCR) */
#define I2C_CCR(i2c_base)		MMIO32((i2c_base) + 0x1c)
#define I2C1_CCR			I2C_CCR(I2C1)
#define I2C2_CCR			I2C_CCR(I2C2)

/* TRISE register (I2Cx_CCR) */
#define I2C_TRISE(i2c_base)		MMIO32((i2c_base) + 0x20)
#define I2C1_TRISE			I2C_TRISE(I2C1)
#define I2C2_TRISE			I2C_TRISE(I2C2)

/* Not all parts have i2c3 */
#ifdef I2C3_BASE
#define I2C3_CR1			I2C_CR1(I2C3)
#define I2C3_CR2			I2C_CR2(I2C3)
#define I2C3_OAR1			I2C_OAR1(I2C3)
#define I2C3_OAR2			I2C_OAR2(I2C3)
#define I2C3_DR				I2C_DR(I2C3)
#define I2C3_SR1			I2C_SR1(I2C3)
#define I2C3_SR2			I2C_SR2(I2C3)
#define I2C3_CCR			I2C_CCR(I2C3)
#define I2C3_TRISE			I2C_TRISE(I2C3)
#endif

/* --- I2Cx_CR1 values ----------------------------------------------------- */

/* SWRST: Software reset */
#define I2C_CR1_SWRST			(1 << 15)

/* Note: Bit 14 is reserved, and forced to 0 by hardware. */

/* ALERT: SMBus alert */
#define I2C_CR1_ALERT			(1 << 13)

/* PEC: Packet error checking */
#define I2C_CR1_PEC			(1 << 12)

/* POS: Acknowledge / PEC position */
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

/* FREQ[5:0]: Peripheral clock frequency (valid values: 2-36 MHz, 2-42 MHz for
 * STM32F4 respectively) */
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
#define I2C_CR2_FREQ_37MHZ		0x25
#define I2C_CR2_FREQ_38MHZ		0x26
#define I2C_CR2_FREQ_39MHZ		0x27
#define I2C_CR2_FREQ_40MHZ		0x28
#define I2C_CR2_FREQ_41MHZ		0x29
#define I2C_CR2_FREQ_42MHZ		0x2a
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

/* --- I2C constant definitions -------------------------------------------- */

/****************************************************************************/
/** @defgroup i2c_rw I2C Read/Write bit
@ingroup i2c_defines

@{*/
#define I2C_WRITE			0
#define I2C_READ			1
/**@}*/

/* --- I2C function prototypes---------------------------------------------- */

/**
 * I2C speed modes.
 */
enum i2c_speeds {
	i2c_speed_sm_100k,
	i2c_speed_fm_400k,
	i2c_speed_fmp_1m,
	i2c_speed_unknown
};

BEGIN_DECLS

void i2c_reset(uint32_t i2c);
void i2c_peripheral_enable(uint32_t i2c);
void i2c_peripheral_disable(uint32_t i2c);
void i2c_send_start(uint32_t i2c);
void i2c_send_stop(uint32_t i2c);
void i2c_clear_stop(uint32_t i2c);
void i2c_set_own_7bit_slave_address(uint32_t i2c, uint8_t slave);
void i2c_set_own_10bit_slave_address(uint32_t i2c, uint16_t slave);
void i2c_set_own_7bit_slave_address_two(uint32_t i2c, uint8_t slave);
void i2c_enable_dual_addressing_mode(uint32_t i2c);
void i2c_disable_dual_addressing_mode(uint32_t i2c);
void i2c_set_clock_frequency(uint32_t i2c, uint8_t freq);
void i2c_send_data(uint32_t i2c, uint8_t data);
void i2c_set_fast_mode(uint32_t i2c);
void i2c_set_standard_mode(uint32_t i2c);
void i2c_set_ccr(uint32_t i2c, uint16_t freq);
void i2c_set_trise(uint32_t i2c, uint16_t trise);
void i2c_send_7bit_address(uint32_t i2c, uint8_t slave, uint8_t readwrite);
uint8_t i2c_get_data(uint32_t i2c);
void i2c_enable_interrupt(uint32_t i2c, uint32_t interrupt);
void i2c_disable_interrupt(uint32_t i2c, uint32_t interrupt);
void i2c_enable_ack(uint32_t i2c);
void i2c_disable_ack(uint32_t i2c);
void i2c_nack_next(uint32_t i2c);
void i2c_nack_current(uint32_t i2c);
void i2c_set_dutycycle(uint32_t i2c, uint32_t dutycycle);
void i2c_enable_dma(uint32_t i2c);
void i2c_disable_dma(uint32_t i2c);
void i2c_set_dma_last_transfer(uint32_t i2c);
void i2c_clear_dma_last_transfer(uint32_t i2c);
void i2c_transfer7(uint32_t i2c, uint8_t addr, uint8_t *w, size_t wn, uint8_t *r, size_t rn);
void i2c_set_speed(uint32_t i2c, enum i2c_speeds speed, uint32_t clock_megahz);

END_DECLS

#endif
/** @cond */
#else
#warning "i2c_common_v1.h should not be included explicitly, only via i2c.h"
#endif
/** @endcond */
/**@}*/


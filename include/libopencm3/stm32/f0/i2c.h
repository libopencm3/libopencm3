/** @defgroup i2c_defines I2C Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx I2C</b>
 *
 * @ingroup STM32F0xx_defines
 *
 * @version 1.0.0
 *
 * @date 11 July 2013
 *
 * LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_I2C_H
#define LIBOPENCM3_I2C_H

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define I2C1				I2C1_BASE
#define I2C2				I2C2_BASE

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define I2C_CR1(i2c_base)		MMIO32((i2c_base) + 0x00)
#define I2C1_CR1			I2C_CR1(I2C1)
#define I2C2_CR1			I2C_CR1(I2C2)

#define I2C_CR2(i2c_base)		MMIO32((i2c_base) + 0x04)
#define I2C1_CR2			I2C_CR2(I2C1)
#define I2C2_CR2			I2C_CR2(I2C2)

#define I2C_OAR1(i2c_base)		MMIO32((i2c_base) + 0x08)
#define I2C1_OAR1			I2C_OAR1(I2C1)
#define I2C2_OAR1			I2C_OAR1(I2C2)

#define I2C_OAR2(i2c_base)		MMIO32((i2c_base) + 0x0c)
#define I2C1_OAR2			I2C_OAR2(I2C1)
#define I2C2_OAR2			I2C_OAR2(I2C2)

#define I2C_TIMINGR(i2c_base)		MMIO32((i2c_base) + 0x10)
#define I2C1_TIMINGR			I2C_TIMINGR(I2C1)
#define I2C2_TIMINGR			I2C_TIMINGR(I2C2)

#define I2C_TIMEOUTR(i2c_base)		MMIO32((i2c_base) + 0x14)
#define I2C1_TIMEOUTR			I2C_TIMEOUTR(I2C1)
#define I2C2_TIMEOUTR			I2C_TIMEOUTR(I2C2)

#define I2C_ISR(i2c_base)		MMIO32((i2c_base) + 0x18)
#define I2C1_ISR			I2C_ISR(I2C1)
#define I2C2_ISR			I2C_ISR(I2C2)

#define I2C_ICR(i2c_base)		MMIO32((i2c_base) + 0x1C)
#define I2C1_ICR			I2C_ICR(I2C1)
#define I2C2_ICR			I2C_ICR(I2C2)

#define I2C_PECR(i2c_base)		MMIO8((i2c_base) + 0x20)
#define I2C1_PECR			I2C_PECR(I2C1)
#define I2C2_PECR			I2C_PECR(I2C2)

#define I2C_RXDR(i2c_base)		MMIO8((i2c_base) + 0x24)
#define I2C1_RXDR			I2C_RXDR(I2C1)
#define I2C2_RXDR			I2C_RXDR(I2C2)

#define I2C_TXDR(i2c_base)		MMIO8((i2c_base) + 0x28)
#define I2C1_TXDR			I2C_TXDR(I2C1)
#define I2C2_TXDR			I2C_TXDR(I2C2)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* I2C_CR1 values ---------------------------------------------------------- */

#define I2C_CR1_PECEN			(1 << 23)
#define I2C_CR1_ALERTEN			(1 << 22)
#define I2C_CR1_SMBDEN			(1 << 21)
#define I2C_CR1_SMBHEN			(1 << 20)
#define I2C_CR1_GCEN			(1 << 19)
#define I2C_CR1_WUPEN			(1 << 18)
#define I2C_CR1_NOSTRETCH		(1 << 17)
#define I2C_CR1_SBC			(1 << 16)
#define I2C_CR1_RXDMAEN			(1 << 15)
#define I2C_CR1_TXDMAEN			(1 << 14)
#define I2C_CR1_ANFOFF			(1 << 12)

#define I2C_CR1_DNF_SHIFT		8
#define I2C_CR1_DNF			(0x0F << I2C_CR1_DNF_SHIFT)
#define I2C_CR1_DNF_VAL(x)		((x) << I2C_CR1_DNF_SHIFT)

#define I2C_CR1_ERRIE			(1 << 7)
#define I2C_CR1_TCIE			(1 << 6)
#define I2C_CR1_STOPIE			(1 << 5)
#define I2C_CR1_NACKIE			(1 << 4)
#define I2C_CR1_ADDRIE			(1 << 3)
#define I2C_CR1_RXIE			(1 << 2)
#define I2C_CR1_TXIE			(1 << 1)
#define I2C_CR1_PE			(1 << 0)

/* I2C_CR2 values ---------------------------------------------------------- */

#define I2C_CR2_PECBYTE			(1 << 26)
#define I2C_CR2_AUTOEND			(1 << 25)
#define I2C_CR2_RELOAD			(1 << 24)

#define I2C_CR2_NBYTES_SHIFT		16
#define I2C_CR2_NBYTES			(0xFF << I2C_CR2_NBYTES_SHIFT)
#define I2C_CR2_NBYTES_VAL(x)		((x) << I2C_CR2_NBYTES_SHIFT)

#define I2C_CR2_NACK			(1 << 15)
#define I2C_CR2_STOP			(1 << 14)
#define I2C_CR2_START			(1 << 13)
#define I2C_CR2_HEAD10R			(1 << 12)
#define I2C_CR2_ADD10			(1 << 11)
#define I2C_CR2_RD_WRN			(1 << 10)

#define I2C_CR2_SADD_SHIFT		0
#define I2C_CR2_SADD			(0x3FF << I2C_CR2_SADD_SHIFT)
#define I2C_CR2_SADD_VAL(x)		((x) << I2C_CR2_SADD_SHIFT)

/* I2C_OAR1 values --------------------------------------------------------- */

#define I2C_OAR1_OA1EN			(1 << 15)
#define I2C_OAR1_OA1MODE		(1 << 10)

#define I2C_OAR1_OA1_SHIFT		0
#define I2C_OAR1_OA1			(0x3FF << I2C_OAR1_OA1_SHIFT)
#define I2C_OAR1_OA1_VAL(x)		((x) << I2C_OAR1_OA1_SHIFT)

/* I2C_OAR2 values --------------------------------------------------------- */

#define I2C_OAR2_OA1EN			(1 << 15)

#define I2C_OAR2_OA2MSK_SHIFT		8
#define I2C_OAR2_OA2MSK			(7 << I2C_OAR2_OA2MSK_SHIFT)
#define I2C_OAR2_OA2MSK_NOMASK		(0 << I2C_OAR2_OA2MSK_SHIFT)
#define I2C_OAR2_OA2MSK_1_BIT		(1 << I2C_OAR2_OA2MSK_SHIFT)
#define I2C_OAR2_OA2MSK_2_BIT		(2 << I2C_OAR2_OA2MSK_SHIFT)
#define I2C_OAR2_OA2MSK_3_BIT		(3 << I2C_OAR2_OA2MSK_SHIFT)
#define I2C_OAR2_OA2MSK_4_BIT		(4 << I2C_OAR2_OA2MSK_SHIFT)
#define I2C_OAR2_OA2MSK_5_BIT		(5 << I2C_OAR2_OA2MSK_SHIFT)
#define I2C_OAR2_OA2MSK_6_BIT		(6 << I2C_OAR2_OA2MSK_SHIFT)
#define I2C_OAR2_OA2MSK_ALL		(7 << I2C_OAR2_OA2MSK_SHIFT)

#define I2C_OAR2_OA2_SHIFT		1
#define I2C_OAR2_OA2			(0x7F << I2C_OAR2_OA2_SHIFT)
#define I2C_OAR2_OA2_VAL(x)		((x) << I2C_OAR2_OA2_SHIFT)

/* I2C_TIMINGR values ------------------------------------------------------ */

#define I2C_TIMINGR_PRESC_SHIFT		28
#define I2C_TIMINGR_PRESC		(0x0F << I2C_TIMINGR_PRESC_SHIFT)
#define I2C_TIMINGR_PRESC_VAL(x)	((x) << I2C_TIMINGR_PRESC_SHIFT)

#define I2C_TIMINGR_SCLDEL_SHIFT	20
#define I2C_TIMINGR_SCLDEL		(0x0F << I2C_TIMINGR_SCLDEL_SHIFT)
#define I2C_TIMINGR_SCLDEL_VAL(x)	((x) << I2C_TIMINGR_SCLDEL_SHIFT)

#define I2C_TIMINGR_SDADEL_SHIFT	16
#define I2C_TIMINGR_SDADEL		(0x0F << I2C_TIMINGR_SDADEL_SHIFT)
#define I2C_TIMINGR_SDADEL_VAL(x)	((x) << I2C_TIMINGR_SDADEL_SHIFT)

#define I2C_TIMINGR_SCLH_SHIFT		8
#define I2C_TIMINGR_SCLH		(0xFF << I2C_TIMINGR_SCLH_SHIFT)
#define I2C_TIMINGR_SCLH_VAL(x)		((x) << I2C_TIMINGR_SCLH_SHIFT)

#define I2C_TIMINGR_SCLL_SHIFT		0
#define I2C_TIMINGR_SCLL		(0xFF << I2C_TIMINGR_SCLL_SHIFT)
#define I2C_TIMINGR_SCLL_VAL(x)		((x) << I2C_TIMINGR_SCLL_SHIFT)

/* I2C_TIMEOUTR values ----------------------------------------------------- */

#define I2C_TIMEOUTR_TETXEN		(1 << 31)

#define I2C_TIMEOUTR_TIMEOUTB_SHIFT	16
#define I2C_TIMEOUTR_TIMEOUTB		(0xFFF << I2C_TIMEOUTR_TIMEOUTB_SHIFT)
#define I2C_TIMEOUTR_TIMEOUTB_VAL(x)	((x) << I2C_TIMEOUTR_TIMEOUTB_SHIFT)

#define I2C_TIMEOUTR_TIMOUTEN		(1 << 15)
#define I2C_TIMEOUTR_TIDLE		(1 << 12)

#define I2C_TIMEOUTR_TIMEOUTA_SHIFT	0
#define I2C_TIMEOUTR_TIMEOUTA		(0xFFF << I2C_TIMEOUTR_TIMEOUTA_SHIFT)
#define I2C_TIMEOUTR_TIMEOUTA_VAL(x)	((x) << I2C_TIMEOUTR_TIMEOUTA_SHIFT)

/* I2C_ISR values ---------------------------------------------------------- */

#define I2C_ISR_ADDCODE_SHIFT		17
#define I2C_ISR_ADDCODE			(0x7F << I2C_ISR_ADDCODE_SHIFT)
#define I2C_ISR_ADDCODE_VAL(x)		((x) << I2C_ISR_ADDCODE_SHIFT)
#define I2C_ISR_ADDCODE_VALG(reg)	(((reg) & I2C_ISR_ADDCODE) >> \
						I2C_ISR_ADDCODE_SHIFT)

#define I2C_ISR_DIR			(1 << 16)
#define I2C_ISR_BUSY			(1 << 15)
#define I2C_ISR_ALERT			(1 << 13)
#define I2C_ISR_TIMEOUT			(1 << 12)
#define I2C_ISR_PECERR			(1 << 11)
#define I2C_ISR_OVR			(1 << 10)
#define I2C_ISR_ARLO			(1 << 9)
#define I2C_ISR_BERR			(1 << 8)
#define I2C_ISR_TCR			(1 << 7)
#define I2C_ISR_TC			(1 << 6)
#define I2C_ISR_STOPF			(1 << 5)
#define I2C_ISR_NACKF			(1 << 4)
#define I2C_ISR_ADDR			(1 << 3)
#define I2C_ISR_RXNE			(1 << 2)
#define I2C_ISR_TXIS			(1 << 1)
#define I2C_ISR_TXE			(1 << 0)

/* I2C_ICR values ---------------------------------------------------------- */

#define I2C_ICR_ALERTCF			(1 << 13)
#define I2C_ICR_TIMEOUTCF		(1 << 12)
#define I2C_ICR_PECCF			(1 << 11)
#define I2C_ICR_OVRCF			(1 << 10)
#define I2C_ICR_ARLOCF			(1 << 9)
#define I2C_ICR_BERRCF			(1 << 8)
#define I2C_ICR_STOPCF			(1 << 5)
#define I2C_ICR_NACKCF			(1 << 4)
#define I2C_ICR_ADDRCF			(1 << 3)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif

/** @defgroup syscfg_defines SYSCFG Defines
 *
 * @ingroup STM32G0xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32G0xx System Configuration controller </b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Guillaume Revaillot <g.revaillot@gmail.com>
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

#ifndef LIBOPENCM3_SYSCFG_H
#define LIBOPENCM3_SYSCFG_H

/**@{*/

/**@defgroup syscfg_registers SYSCFG Registers
￼  @{*/
#define SYSCFG_CFGR1			MMIO32(SYSCFG_BASE + 0x00)
#define SYSCFG_CFGR2			MMIO32(SYSCFG_BASE + 0x18)

#define SYSCFG_ITLINE(line)		MMIO32(SYSCFG_BASE + 0x80 + (line)*4)
/**@}*/

/** @defgroup syscfg_cfgr1 CFGR1 SYSCFG configuration register 1
@{*/


/** SYSCFG_CFGR1_I2C_PA10_FMP FM+ enable for PA10 */
#define SYSCFG_CFGR1_I2C_PA10_FMP		(1 << 23)

/** SYSCFG_CFGR1_I2C_PA9_FMP FM+ enable for PA9 */
#define SYSCFG_CFGR1_I2C_PA9_FMP		(1 << 22)

/** SYSCFG_CFGR1_I2C2_FMP FM+ driving capability activation for I2C2 */
#define SYSCFG_CFGR1_I2C2_FMP		(1 << 21)

/** SYSCFG_CFGR1_I2C1_FMP FM+ driving capability activation for I2C1 */
#define SYSCFG_CFGR1_I2C1_FMP		(1 << 20)

/** SYSCFG_CFGR1_I2C_PB9_FMP FM+ enable for PB9 */
#define SYSCFG_CFGR1_I2C_PB9_FMP		(1 << 19)

/** SYSCFG_CFGR1_I2C_PB8_FMP FM+ enable for PB8 */
#define SYSCFG_CFGR1_I2C_PB8_FMP		(1 << 18)

/** SYSCFG_CFGR1_I2C_PB7_FMP FM+ enable for PB7 */
#define SYSCFG_CFGR1_I2C_PB7_FMP		(1 << 17)

/** SYSCFG_CFGR1_I2C_PB6_FMP FM+ enable for PB6 */
#define SYSCFG_CFGR1_I2C_PB6_FMP		(1 << 16)

/** SYSCFG_CFGR1_UCPD2_STROBE Strobe signal bit for UCPD2 */
#define SYSCFG_CFGR1_UCPD2_STROBE		(1 << 10)

/** SYSCFG_CFGR1_UCPD1_STROBE Strobe signal bit for UCPD1 */
#define SYSCFG_CFGR1_UCPD1_STROBE		(1 << 9)

/** SYSCFG_CFGR1_BOOSTEN I/O analog switch voltage booster enable */
#define SYSCFG_CFGR1_BOOSTEN		(1 << 8)

#define SYSCFG_CFGR1_IR_MOD_SHIFT			6
#define SYSCFG_CFGR1_IR_MOD_MASK			0x03
/** @defgroup syscfg_cfgr1_ir_mod IR MOD
* @brief IR Modulation Envelope signal selection.
@{*/
#define SYSCFG_CFGR1_IR_MOD_TIM16			0
#define SYSCFG_CFGR1_IR_MOD_USART1			1
#define SYSCFG_CFGR1_IR_MOD_USART4			2
/**@}*/

/** SYSCFG_CFGR1_IR_POL IR output polarity selection */
#define SYSCFG_CFGR1_IR_POL		(1 << 5)

/** SYSCFG_CFGR1_PA12_RMP PA12 pin remapping */
#define SYSCFG_CFGR1_PA12_RMP		(1 << 4)

/** SYSCFG_CFGR1_PA11_RMP PA11 pin remapping */
#define SYSCFG_CFGR1_PA11_RMP		(1 << 3)

#define SYSCFG_CFGR1_MEM_MODE_SHIFT			0
#define SYSCFG_CFGR1_MEM_MODE_MASK			0x03
/** @defgroup syscfg_cfgr1_mem_mode MEM MODE
* @brief Memory mapping selection bits
@{*/
#define SYSCFG_CFGR1_MEM_MODE_FLASH			0
#define SYSCFG_CFGR1_MEM_MODE_SYSTEM		1
#define SYSCFG_CFGR1_MEM_MODE_SRAM			3
/**@}*/

/**@}*/


/** @defgroup syscfg_cfgr2 CFGR2 SYSCFG configuration register 2
@{*/

/** SYSCFG_CFGR2_SRAM_PEF SRAM parity error flag */
#define SYSCFG_CFGR2_SRAM_PEF		(1 << 8)

/** SYSCFG_CFGR2_ECC_LOCK ECC error lock bit */
#define SYSCFG_CFGR2_ECC_LOCK		(1 << 3)

/** SYSCFG_CFGR2_PVD_LOCK PVD lock enable bit */
#define SYSCFG_CFGR2_PVD_LOCK		(1 << 2)

/** SYSCFG_CFGR2_SRAM_PARITY_LOCK SRAM parity lock bit */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK		(1 << 1)

/** SYSCFG_CFGR2_LOCKUP_LOCK Cortex-M0+ LOCKUP bit enable bit */
#define SYSCFG_CFGR2_LOCKUP_LOCK			(1 << 0)

/**@}*/

/** @defgroup syscfg_itline0 ITLINE0 interrupt line 0 status register
@{*/
#define SYSCFG_ITLINE0_WWDG		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline1 ITLINE1 interrupt line 1 status register
@{*/
#define SYSCFG_ITLINE1_PVDOUT		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline2 ITLINE2 interrupt line 2 status register
@{*/
#define SYSCFG_ITLINE2_RTC		(1 << 1)
#define SYSCFG_ITLINE2_TAMP		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline3 ITLINE3 interrupt line 3 status register
@{*/
#define SYSCFG_ITLINE3_FLASH_ECC		(1 << 1)
#define SYSCFG_ITLINE3_FLASH_ITF		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline4 ITLINE4 interrupt line 4 status register
@{*/
#define SYSCFG_ITLINE4_RCC		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline5 ITLINE5 interrupt line 5 status register
@{*/
#define SYSCFG_ITLINE5_EXTI1		(1 << 1)
#define SYSCFG_ITLINE5_EXTI0		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline6 ITLINE6 interrupt line 6 status register
@{*/
#define SYSCFG_ITLINE6_EXTI3		(1 << 1)
#define SYSCFG_ITLINE6_EXTI2		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline7 ITLINE7 interrupt line 7 status register
@{*/
#define SYSCFG_ITLINE7_EXTI15		(1 << 11)
#define SYSCFG_ITLINE7_EXTI14		(1 << 10)
#define SYSCFG_ITLINE7_EXTI13		(1 << 9)
#define SYSCFG_ITLINE7_EXTI12		(1 << 8)
#define SYSCFG_ITLINE7_EXTI11		(1 << 7)
#define SYSCFG_ITLINE7_EXTI10		(1 << 6)
#define SYSCFG_ITLINE7_EXTI9		(1 << 5)
#define SYSCFG_ITLINE7_EXTI8		(1 << 4)
#define SYSCFG_ITLINE7_EXTI7		(1 << 3)
#define SYSCFG_ITLINE7_EXTI6		(1 << 2)
#define SYSCFG_ITLINE7_EXTI5		(1 << 1)
#define SYSCFG_ITLINE7_EXTI4		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline8 ITLINE8 interrupt line 8 status register
@{*/
#define SYSCFG_ITLINE8_UCPD2		(1 << 1)
#define SYSCFG_ITLINE8_UCPD1		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline9 ITLINE9 interrupt line 9 status register
@{*/
#define SYSCFG_ITLINE9_DMA1_CH1		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline10 ITLINE10 interrupt line 10 status register
@{*/
#define SYSCFG_ITLINE10_DMA1_CH3		(1 << 1)
#define SYSCFG_ITLINE10_DMA1_CH2		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline11 ITLINE11 interrupt line 11 status register
@{*/
#define SYSCFG_ITLINE11_DMA1_CH7		(1 << 4)
#define SYSCFG_ITLINE11_DMA1_CH6		(1 << 3)
#define SYSCFG_ITLINE11_DMA1_CH5		(1 << 2)
#define SYSCFG_ITLINE11_DMA1_CH4		(1 << 1)
#define SYSCFG_ITLINE11_DMAMUX		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline12 ITLINE12 interrupt line 12 status register
@{*/
#define SYSCFG_ITLINE12_COMP2		(1 << 2)
#define SYSCFG_ITLINE12_COMP1		(1 << 1)
#define SYSCFG_ITLINE12_ADC		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline13 ITLINE13 interrupt line 13 status register
@{*/
#define SYSCFG_ITLINE13_TIM1_BRK		(1 << 3)
#define SYSCFG_ITLINE13_TIM1_UPD		(1 << 2)
#define SYSCFG_ITLINE13_TIM1_TRG		(1 << 1)
#define SYSCFG_ITLINE13_TIM1_CCU		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline14 ITLINE14 interrupt line 14 status register
@{*/
#define SYSCFG_ITLINE14_TIM1_CC		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline15 ITLINE15 interrupt line 15 status register
@{*/
#define SYSCFG_ITLINE15_TIM2		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline16 ITLINE16 interrupt line 16 status register
@{*/
#define SYSCFG_ITLINE16_TIM3		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline17 ITLINE17 interrupt line 17 status register
@{*/
#define SYSCFG_ITLINE17_LPTIM1		(1 << 2)
#define SYSCFG_ITLINE17_DAC		(1 << 1)
#define SYSCFG_ITLINE17_TIM6		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline18 ITLINE18 interrupt line 18 status register
@{*/
#define SYSCFG_ITLINE18_LPTIM2		(1 << 1)
#define SYSCFG_ITLINE18_TIM7		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline19 ITLINE19 interrupt line 19 status register
@{*/
#define SYSCFG_ITLINE19_TIM14		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline20 ITLINE20 interrupt line 20 status register
@{*/
#define SYSCFG_ITLINE20_TIM15		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline21 ITLINE21 interrupt line 21 status register
@{*/
#define SYSCFG_ITLINE21_TIM16		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline22 ITLINE22 interrupt line 22 status register
@{*/
#define SYSCFG_ITLINE22_TIM17		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline23 ITLINE23 interrupt line 23 status register
@{*/
#define SYSCFG_ITLINE23_I2C1		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline24 ITLINE24 interrupt line 24 status register
@{*/
#define SYSCFG_ITLINE24_I2C2		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline25 ITLINE25 interrupt line 25 status register
@{*/
#define SYSCFG_ITLINE25_SPI1		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline26 ITLINE26 interrupt line 26 status register
@{*/
#define SYSCFG_ITLINE26_SPI2		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline27 ITLINE27 interrupt line 27 status register
@{*/
#define SYSCFG_ITLINE27_USART1		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline28 ITLINE28 interrupt line 28 status register
@{*/
#define SYSCFG_ITLINE28_USART2		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline29 ITLINE29 interrupt line 29 status register
@{*/
#define SYSCFG_ITLINE29_LPUART1		(1 << 2)
#define SYSCFG_ITLINE29_USART4		(1 << 1)
#define SYSCFG_ITLINE29_USART3		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline30 ITLINE30 interrupt line 30 status register
@{*/
#define SYSCFG_ITLINE30_CEC		(1 << 0)
/**@}*/

/** @defgroup syscfg_itline31 ITLINE31 interrupt line 31 status register
@{*/
#define SYSCFG_ITLINE31_AES		(1 << 1)
#define SYSCFG_ITLINE31_RNG		(1 << 0)
/**@}*/

#endif

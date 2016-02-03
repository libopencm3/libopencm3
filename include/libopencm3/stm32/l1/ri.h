/** @defgroup ri_defines Routing Interface registers
 *
 * @brief <b>Register definitions for the STM32L1xx Routing Interface</b>
 *
 * @ingroup STM32L1xx
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Marek Koza <qyx@krtko.org>
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
 *
 * Based on the RM0038 Reference manual
 * (STM32L100xx, STM32L151xx, STM32L152xx and STM32L162xx advanced ARM®-based
 * 32-bit MCUs)
 */
/**@{*/

/*
 * There is a mismatch in the RM0038 in the RI register offset addresses (they
 * are relative to the COMP base address instead of the RI base address for an
 * unknown reason). We are subtracting 4 in order to use them with ROUTING_BASE.
 */
#define RI_BASE                 ROUTING_BASE - 0x04

#define RI_ICR                  MMIO32(RI_BASE + 0x04)
#define RI_ASCR1                MMIO32(RI_BASE + 0x08)
#define RI_ASCR2                MMIO32(RI_BASE + 0x0c)
#define RI_HYSCR1               MMIO32(RI_BASE + 0x10)
#define RI_HYSCR2               MMIO32(RI_BASE + 0x14)
#define RI_HYSCR3               MMIO32(RI_BASE + 0x18)
#define RI_HYSCR4               MMIO32(RI_BASE + 0x1c)
#define RI_ASMR1                MMIO32(RI_BASE + 0x20)
#define RI_CMR1                 MMIO32(RI_BASE + 0x24)
#define RI_CICR1                MMIO32(RI_BASE + 0x28)
#define RI_ASMR2                MMIO32(RI_BASE + 0x2c)
#define RI_CMR2                 MMIO32(RI_BASE + 0x30)
#define RI_CICR2                MMIO32(RI_BASE + 0x34)
#define RI_ASMR3                MMIO32(RI_BASE + 0x38)
#define RI_CMR3                 MMIO32(RI_BASE + 0x3c)
#define RI_CICR3                MMIO32(RI_BASE + 0x40)
#define RI_ASMR4                MMIO32(RI_BASE + 0x44)
#define RI_CMR4                 MMIO32(RI_BASE + 0x48)
#define RI_CICR4                MMIO32(RI_BASE + 0x4c)
#define RI_ASMR5                MMIO32(RI_BASE + 0x50)
#define RI_CMR5                 MMIO32(RI_BASE + 0x54)
#define RI_CICR5                MMIO32(RI_BASE + 0x58)

/**
 * RI input capture register
 *
 * The RI_ICR register is used to select the routing of 4 full ports to the
 * input captures of TIM2, TIM3 and TIM4.
 */
#define RI_ICR_IC1IOS_SHIFT     0
#define RI_ICR_IC1IOS_MASK      0xf
#define RI_ICR_IC2IOS_SHIFT     4
#define RI_ICR_IC2IOS_MASK      0xf
#define RI_ICR_IC3IOS_SHIFT     8
#define RI_ICR_IC3IOS_MASK      0xf
#define RI_ICR_IC4IOS_SHIFT     12
#define RI_ICR_IC4IOS_MASK      0xf
#define RI_ICR_TIM_SHIFT        16
#define RI_ICR_TIM_MASK         0x3
#define RI_ICR_IC1              (1 << 18)
#define RI_ICR_IC2              (1 << 19)
#define RI_ICR_IC3              (1 << 20)
#define RI_ICR_IC4              (1 << 21)
/* bits 22-31 reserved */

/**
 * RI analog switches control register 1
 *
 * The RI_ASCR1 register is used to configure the analog switches of the I/Os
 * linked to the ADC. These I/Os are pointed to by the ADC channel number.
 */
#define RI_ASCR1_CH0_GR1_1      (1 << 0)
#define RI_ASCR1_CH1_GR1_2      (1 << 1)
#define RI_ASCR1_CH2_GR1_3      (1 << 2)
#define RI_ASCR1_CH3_GR1_4      (1 << 3)
#define RI_ASCR1_CH4            (1 << 4)
#define RI_ASCR1_CH5            (1 << 5)
#define RI_ASCR1_CH6_GR2_1      (1 << 6)
#define RI_ASCR1_CH7_GR2_2      (1 << 7)
#define RI_ASCR1_CH8_GR3_1      (1 << 8)
#define RI_ASCR1_CH9_GR3_2      (1 << 9)
#define RI_ASCR1_CH10_GR8_1     (1 << 10)
#define RI_ASCR1_CH11_GR8_2     (1 << 11)
#define RI_ASCR1_CH12_GR8_3     (1 << 12)
#define RI_ASCR1_CH13_GR8_4     (1 << 13)
#define RI_ASCR1_CH14_GR9_1     (1 << 14)
#define RI_ASCR1_CH15_GR9_2     (1 << 15)
#define RI_ASCR1_CH31_GR11_5    (1 << 16)
/* bit 17 reserved */
#define RI_ASCR1_CH18_GR7_1     (1 << 18)
#define RI_ASCR1_CH19_GR7_2     (1 << 19)
#define RI_ASCR1_CH20_GR7_3     (1 << 20)
#define RI_ASCR1_CH21_GR7_4     (1 << 21)
#define RI_ASCR1_CH22           (1 << 22)
#define RI_ASCR1_CH23           (1 << 23)
#define RI_ASCR1_CH24           (1 << 24)
#define RI_ASCR1_CH25           (1 << 25)
#define RI_ASCR1_VCOMP          (1 << 26)
#define RI_ASCR1_CH27_GR11_1    (1 << 27)
#define RI_ASCR1_CH28_GR11_2    (1 << 28)
#define RI_ASCR1_CH29_GR11_3    (1 << 29)
#define RI_ASCR1_CH30_GR11_4    (1 << 30)
#define RI_ASCR1_SCM            (1 << 31)

/**
 * RI analog switches control register 2
 *
 * The RI_ASCR2 register is used to configure the analog switches of groups of
 * I/Os not linked to the ADC. In this way, predefined groups of I/Os can be
 * connected together.
 */
#define RI_ASCR2_GR10_1         (1 << 0)
#define RI_ASCR2_GR10_2         (1 << 1)
#define RI_ASCR2_GR10_3         (1 << 2)
#define RI_ASCR2_GR10_4         (1 << 3)
#define RI_ASCR2_GR6_1          (1 << 4)
#define RI_ASCR2_GR6_2          (1 << 5)
#define RI_ASCR2_GR5_1          (1 << 6)
#define RI_ASCR2_GR5_2          (1 << 7)
#define RI_ASCR2_GR5_3          (1 << 8)
#define RI_ASCR2_GR4_1          (1 << 9)
#define RI_ASCR2_GR4_2          (1 << 10)
#define RI_ASCR2_GR4_3          (1 << 11)
/* bits 12-15 reserved */
#define RI_ASCR2_CH0B_GR3_3     (1 << 16)
#define RI_ASCR2_CH1B_GR3_4     (1 << 17)
#define RI_ASCR2_CH2B_GR3_5     (1 << 18)
#define RI_ASCR2_CH3B_GR9_3     (1 << 19)
#define RI_ASCR2_CH6B_GR9_4     (1 << 20)
#define RI_ASCR2_CH7B_GR2_3     (1 << 21)
#define RI_ASCR2_CH8B_GR2_4     (1 << 22)
#define RI_ASCR2_CH9B_GR2_5     (1 << 23)
#define RI_ASCR2_CH10B_GR7_5    (1 << 24)
#define RI_ASCR2_CH11B_GR7_6    (1 << 25)
#define RI_ASCR2_CH12B_GR7_7    (1 << 26)
#define RI_ASCR2_GR6_3          (1 << 27)
#define RI_ASCR2_GR6_4          (1 << 28)
/* bits 29-31 reserved */

/**
 * RI hysteresis control register 1
 *
 * The RI_HYSCR1 register is used to enable/disable the hysteresis of the input
 * Schmitt trigger of ports A and B.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_HYSCR1_PA(x)         (x)
#define RI_HYSCR1_PB(x)         (x << 16)

/**
 * RI hysteresis control register 2
 *
 * RI_HYSCR2 register allows to enable/disable hysteresis of input Schmitt
 * trigger of ports C and D.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_HYSCR2_PC(x)         (x)
#define RI_HYSCR2_PD(x)         (x << 16)

/**
 * RI hysteresis control register 3
 *
 * The RI_HYSCR3 register is used to enable/disable the hysteresis of the input
 * Schmitt trigger of the entire port E and F.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_HYSCR3_PE(x)         (x)
#define RI_HYSCR3_PF(x)         (x << 16)

/**
 * RI hysteresis control register 4
 *
 * The RI_HYSCR4 register is used to enable/disable the hysteresis of the input
 * Schmitt trigger of the entire port G.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_HYSCR2_PG(x)         (x)
/* bits 16-31 reserved */

/**
 * Analog switch mode register (RI_ASMR1)
 *
 * The RI_ASMR1 register is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices
 * only and is used to select if analog switches of port A are to be controlled
 * by the timer OC or through the ADC interface or RI_ASCRx registers.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_ASMR1_PA(x)          (x)
/* bits 16-31 reserved */

/**
 * Channel mask register (RI_CMR1)
 *
 * RI_CMR1 is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices only and is
 * used to mask a port A channel designated as a timer input capture (after
 * acquisition completion to avoid triggering multiple detections).
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_CMR1_PA(x)           (x)
/* bits 16-31 reserved */

/**
 * Channel identification for capture register (RI_CICR1)
 *
 * The RI_CICR1 register is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices
 * only and is used when analog switches are controlled by a timer OC. RI_CICR1
 * allows a channel to be identified for timer input capture.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_CICR1_PA(x)          (x)
/* bits 16-31 reserved */

/**
 * Analog switch mode register (RI_ASMR2)
 *
 * The RI_ASMR2 register is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices
 * only and is used to select if analog switches of port B are to be controlled
 * by the timer OC or through the ADC interface or RI_ASCRx registers.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_ASMR2_PB(x)          (x)
/* bits 16-31 reserved */

/**
 * Channel mask register (RI_CMR2)
 *
 * RI_CMR2 is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices only and is
 * used to mask a port B channel designated as a timer input capture (after
 * acquisition completion to avoid triggering multiple detections).
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_CMR2_PB(x)           (x)
/* bits 16-31 reserved */

/**
 * Channel identification for capture register (RI_CICR2)
 *
 * The RI_CICR2 register is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices
 * only and is used when analog switches are controlled by a timer OC. RI_CICR2
 * allows a channel to be identified for timer input capture.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_CICR2_PB(x)          (x)
/* bits 16-31 reserved */

/**
 * Analog switch mode register (RI_ASMR3)
 *
 * The RI_ASMR3 register is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices
 * only and is used to select if analog switches of port C are to be controlled
 * by the timer OC or through the ADC interface or RI_ASCRx registers.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_ASMR3_PC(x)          (x)
/* bits 16-31 reserved */

/**
 * Channel mask register (RI_CMR3)
 *
 * RI_CMR3 is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices only and is
 * used to mask a port C channel designated as a timer input capture (after
 * acquisition completion to avoid triggering multiple detections).
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_CMR3_PC(x)           (x)
/* bits 16-31 reserved */

/**
 * Channel identification for capture register (RI_CICR3)
 *
 * The RI_CICR3 register is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices
 * only and is used when analog switches are controlled by a timer OC. RI_CICR3
 * allows a channel to be identified for timer input capture.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_CICR3_PC(x)          (x)
/* bits 16-31 reserved */

/**
 * Analog switch mode register (RI_ASMR4)
 *
 * The RI_ASMR4 register is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices
 * only and is used to select if analog switches of port F are to be controlled
 * by the timer OC or through the ADC interface or RI_ASCRx registers.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_ASMR4_PF(x)          (x)
/* bits 16-31 reserved */

/**
 * Channel mask register (RI_CMRF)
 *
 * RI_CMR4 is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices only and is
 * used to mask a port F channel designated as a timer input capture (after
 * acquisition completion to avoid triggering multiple detections).
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_CMR4_PF(x)           (x)
/* bits 16-31 reserved */

/**
 * Channel identification for capture register (RI_CICR4)
 *
 * The RI_CICR4 register is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices
 * only and is used when analog switches are controlled by a timer OC. RI_CICR4
 * allows a channel to be identified for timer input capture.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_CICR4_PF(x)          (x)
/* bits 16-31 reserved */

/**
 * Analog switch mode register (RI_ASMR5)
 *
 * The RI_ASMR5 register is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices
 * only and is used to select if analog switches of port G are to be controlled
 * by the timer OC or through the ADC interface or RI_ASCRx registers.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_ASMR5_PG(x)          (x)
/* bits 16-31 reserved */

/**
 * Channel mask register (RI_CMR5)
 *
 * RI_CMR1 is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices only and is
 * used to mask a port G channel designated as a timer input capture (after
 * acquisition completion to avoid triggering multiple detections).
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_CMR5_PG(x)           (x)
/* bits 16-31 reserved */

/**
 * Channel identification for capture register (RI_CICR5)
 *
 * The RI_CICR5 register is available in Cat.3, Cat.4, Cat.5 and Cat.6 devices
 * only and is used when analog switches are controlled by a timer OC. RI_CICR5
 * allows a channel to be identified for timer input capture.
 *
 * GPIO0-GPIO15 defines should be used as parameters.
 */
#define RI_CICR5_PG(x)          (x)
/* bits 16-31 reserved */

/**@}*/


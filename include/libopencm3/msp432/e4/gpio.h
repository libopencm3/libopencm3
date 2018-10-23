/** @defgroup gpio_defines General Purpose I/O Defines
 *
 * @ingroup MSP432E4xx_defines
 *
 * @brief Defined Constants and Types for the MSP432E4 General Purpose I/O
 *
 * @version 1.0.0
 *
 * @date 23 September 2018
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
 * Copyright (C) 2018 Dmitry Rezvanov <dmitry.rezvanov@yandex.ru>
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

#ifndef MSP432E4_GPIO_H
#define MSP432E4_GPIO_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/msp432/e4/memorymap.h>
#include <stdbool.h>

/** @defgroup gpio_reg_base GPIO Register Base Addresses
 * @brief GPIO Register Base Addresses
@{*/
/** GPIOA Base Address */
#define GPIOA               GPIOA_BASE
/** GPIOB Base Address */
#define GPIOB               GPIOB_BASE
/** GPIOC Base Address */
#define GPIOC               GPIOC_BASE
/** GPIOD Base Address */
#define GPIOD               GPIOD_BASE
/** GPIOE Base Address */
#define GPIOE               GPIOE_BASE
/** GPIOF Base Address */
#define GPIOF               GPIOF_BASE
/** GPIOG Base Address */
#define GPIOG               GPIOG_BASE
/** GPIOH Base Address */
#define GPIOH               GPIOH_BASE
/** GPIOJ Base Address */
#define GPIOJ               GPIOJ_BASE
/** GPIOK Base Address */
#define GPIOK               GPIOK_BASE
/** GPIOL Base Address */
#define GPIOL               GPIOL_BASE
/** GPIOM Base Address */
#define GPIOM               GPIOM_BASE
/** GPION Base Address */
#define GPION               GPION_BASE
/** GPIOP Base Address */
#define GPIOP               GPIOP_BASE
/** GPIOQ Base Address */
#define GPIOQ               GPIOQ_BASE
/**@}*/

/** @defgroup gpio_pin_id GPIO Pin Identifiers
 * @brief GPIO Pin Identifiers
@{*/
/** GPIO Pin 0 Identifier */
#define GPIO0               (1 << 0)
/** GPIO Pin 1 Identifier */
#define GPIO1               (1 << 1)
/** GPIO Pin 2 Identifier */
#define GPIO2               (1 << 2)
/** GPIO Pin 3 Identifier */
#define GPIO3               (1 << 3)
/** GPIO Pin 4 Identifier */
#define GPIO4               (1 << 4)
/** GPIO Pin 5 Identifier */
#define GPIO5               (1 << 5)
/** GPIO Pin 6 Identifier */
#define GPIO6               (1 << 6)
/** GPIO Pin 7 Identifier */
#define GPIO7               (1 << 7)
/** GPIO All Pins Identifier */
#define GPIO_ALL            (0xFF)
/**@}*/

/** @defgroup gpio_af_id GPIO Alternate Functions Identifiers
 * @brief GPIO Alternate Functions Identifiers
@{*/
/** GPIO Alternate Function 1 Identifier */
#define GPIO_AF1            0x1
/** GPIO Alternate Function 2 Identifier */
#define GPIO_AF2            0x2
/** GPIO Alternate Function 3 Identifier */
#define GPIO_AF3            0x3
/** GPIO Alternate Function 4 Identifier */
#define GPIO_AF4            0x4
/** GPIO Alternate Function 5 Identifier */
#define GPIO_AF5            0x5
/** GPIO Alternate Function 6 Identifier */
#define GPIO_AF6            0x6
/** GPIO Alternate Function 7 Identifier */
#define GPIO_AF7            0x7
/** GPIO Alternate Function 8 Identifier */
#define GPIO_AF8            0x8
/** GPIO Alternate Function 11 Identifier */
#define GPIO_AF11           0xB
/** GPIO Alternate Function 13 Identifier */
#define GPIO_AF13           0xD
/** GPIO Alternate Function 14 Identifier */
#define GPIO_AF14           0xE
/** GPIO Alternate Function 15 Identifier */
#define GPIO_AF15           0xF
/** GPIO Alternate Function Disable */
#define GPIO_AF_DISABLE     0x0
/**@}*/

/** @defgroup gpio_registers GPIO Registers
 * @brief GPIO Registers
@{*/
/** GPIO Data */
#define GPIO_DATA(port)         (&MMIO32((port) + 0x000))
/** GPIO Direction */
#define GPIO_DIR(port)          MMIO32((port) + 0x400)
/** GPIO Interrupt Sense */
#define GPIO_IS(port)           MMIO32((port) + 0x404)
/** GPIO Interrupt Both Edges */
#define GPIO_IBE(port)          MMIO32((port) + 0x408)
/** GPIO Interrupt Event */
#define GPIO_IEV(port)          MMIO32((port) + 0x40C)
/** GPIO Interrupt Mask */
#define GPIO_IM(port)           MMIO32((port) + 0x410)
/** GPIO Raw Interrupt Status */
#define GPIO_RIS(port)          MMIO32((port) + 0x414)
/** GPIO Masked Interrupt Status */
#define GPIO_MIS(port)          MMIO32((port) + 0x418)
/** GPIO Interrupt Clear */
#define GPIO_ICR(port)          MMIO32((port) + 0x41C)
/** GPIO Alternate Function Select */
#define GPIO_AFSEL(port)        MMIO32((port) + 0x420)
/** GPIO 2-mA Drive Select */
#define GPIO_DR2R(port)         MMIO32((port) + 0x500)
/** GPIO 4-mA Drive Select */
#define GPIO_DR4R(port)         MMIO32((port) + 0x504)
/** GPIO 8-mA Drive Select */
#define GPIO_DR8R(port)         MMIO32((port) + 0x508)
/** GPIO Open Drain Select */
#define GPIO_ODR(port)          MMIO32((port) + 0x50C)
/** GPIO Pull-Up Select */
#define GPIO_PUR(port)          MMIO32((port) + 0x510)
/** GPIO Pull-Down Select */
#define GPIO_PDR(port)          MMIO32((port) + 0x514)
/** GPIO Slew Rate Control Select */
#define GPIO_SLR(port)          MMIO32((port) + 0x518)
/** GPIO Digital Enable */
#define GPIO_DEN(port)          MMIO32((port) + 0x51C)
/** GPIO Lock */
#define GPIO_LOCK(port)         MMIO32((port) + 0x520)
/** GPIO Commit */
#define GPIO_CR(port)           MMIO32((port) + 0x524)
/** GPIO Analog Mode Select */
#define GPIO_AMSEL(port)        MMIO32((port) + 0x528)
/** GPIO Port Control */
#define GPIO_PCTL(port)         MMIO32((port) + 0x52C)
/** GPIO ADC Control */
#define GPIO_ADCCTL(port)       MMIO32((port) + 0x530)
/** GPIO DMA Control */
#define GPIO_DMACTL(port)       MMIO32((port) + 0x534)
/** GPIO Select Interrupt */
#define GPIO_SI(port)           MMIO32((port) + 0x538)
/** GPIO 12-mA Drive Select */
#define GPIO_DR12R(port)        MMIO32((port) + 0x53C)
/** GPIO Wake Pin Enable
 * @note This register is only available on Port K */
#define GPIO_WAKEPEN(port)      MMIO32((port) + 0x540)
/** GPIO Wake Level
 * @note This register is only available on Port K */
#define GPIO_WAKELVL(port)      MMIO32((port) + 0x544)
/** GPIO Wake Status
 * @note This register is only available on Port K */
#define GPIO_WAKESTAT(port)     MMIO32((port) + 0x548)
/** GPIO Peripheral Property */
#define GPIO_PP(port)           MMIO32((port) + 0xFC0)
/** GPIO Peripheral Configuration */
#define GPIO_PC(port)           MMIO32((port) + 0xFC4)

/** GPIO Peripheral Identification 0 */
#define GPIO_PERIPH_ID0(port)   MMIO32((port) + 0xFE0)
/** GPIO Peripheral Identification 1 */
#define GPIO_PERIPH_ID1(port)   MMIO32((port) + 0xFE4)
/** GPIO Peripheral Identification 2 */
#define GPIO_PERIPH_ID2(port)   MMIO32((port) + 0xFE8)
/** GPIO Peripheral Identification 3 */
#define GPIO_PERIPH_ID3(port)   MMIO32((port) + 0xFEC)
/** GPIO Peripheral Identification 4 */
#define GPIO_PERIPH_ID4(port)   MMIO32((port) + 0xFD0)
/** GPIO Peripheral Identification 5 */
#define GPIO_PERIPH_ID5(port)   MMIO32((port) + 0xFD4)
/** GPIO Peripheral Identification 6 */
#define GPIO_PERIPH_ID6(port)   MMIO32((port) + 0xFD8)
/** GPIO Peripheral Identification 7 */
#define GPIO_PERIPH_ID7(port)   MMIO32((port) + 0xFDC)

/** GPIO PrimeCell Identification 0 */
#define GPIO_PCELL_ID0(port)    MMIO32((port) + 0xFF0)
/** GPIO PrimeCell Identification 1 */
#define GPIO_PCELL_ID1(port)    MMIO32((port) + 0xFF4)
/** GPIO PrimeCell Identification 2 */
#define GPIO_PCELL_ID2(port)    MMIO32((port) + 0xFF8)
/** GPIO PrimeCell Identification 3 */
#define GPIO_PCELL_ID3(port)    MMIO32((port) + 0xFFC)
/**@}*/

/** @defgroup gpio_im_values GPIO_IM Values
 * @brief GPIO Interrupt Mask Register Values
@{*/
/** GPIO Micro Direct Memory Access Done Interrupt Mask Enable */
#define GPIO_IM_DMAIME          (1 << 8)
/**@}*/

/** @defgroup gpio_ris_values GPIO_RIS Values
 * @brief GPIO Raw Interrupt Status Register Values
@{*/
/** GPIO Micro Direct Memory Access Done Interrupt Raw Status */
#define GPIO_RIS_DMARIS         (1 << 8)
/**@}*/

/** @defgroup gpio_mis_values GPIO_MIS Values
 * @brief GPIO Masked Interrupt Status Register Values
@{*/
/** GPIO Micro Direct Memory Access Done Masked Interrupt Status */
#define GPIO_MIS_DMAMIS         (1 << 8)
/**@}*/

/** @defgroup gpio_icr_values GPIO_RIS Values
 * @brief GPIO Interrupt Clear Register Values
@{*/
/** GPIO Micro Direct Memory Access Interrupt Clear */
#define GPIO_ICR_DMAIC          (1 << 8)
/**@}*/

/** @defgroup gpio_lock_values GPIO_LOCK Values
 * @brief GPIO Lock Register Values
@{*/
/* Value we need to write to unlock the GPIO commit register */
#define GPIO_LOCK_UNLOCK_CODE   (0x4C4F434B)
/** GPIO Lock Status */
#define GPIO_LOCK_STATUS        (1 << 0)
/**@}*/

/** @defgroup gpio_pctl_values GPIO_PCTL Values
 * @brief GPIO Port Control Register Values
@{*/
/** GPIO Port Control Set AF for Pin */
#define GPIO_PCTL_AF(pin, af)   ((af) << ((pin) * 4))
/* GPIO Port Control Mask for Pin */
#define GPIO_PCTL_MASK(pin)     GPIO_PCTL_AF((pin), 0xf)
/**@}*/

/** @defgroup gpio_si_values GPIO_SI Values
 * @brief GPIO Select Interrupt Register Values
@{*/
/** Summary Interrupt */
#define GPIO_SI_SUM             (1 << 0)
/**@}*/

/** @defgroup gpio_wakepen_values GPIO_WAKEPEN Values
 * @brief GPIO Wake Pin Enable Register Values
 * @note This register is only available on Port K
@{*/
/** PK7 Wake Enable */
#define GPIO_WAKEPEN_WAKEP7     (1 << 7)
/** PK6 Wake Enable */
#define GPIO_WAKEPEN_WAKEP6     (1 << 6)
/** PK5 Wake Enable */
#define GPIO_WAKEPEN_WAKEP5     (1 << 5)
/** PK4 Wake Enable */
#define GPIO_WAKEPEN_WAKEP4     (1 << 4)
/**@}*/

/** @defgroup gpio_wakelvl_values GPIO_WAKELVL Values
 * @brief GPIO Wake Level Register Values
@{*/
/** PK7 Wake Level */
#define GPIO_WAKELVL_WAKELVL7   (1 << 7)
/** PK6 Wake Level */
#define GPIO_WAKELVL_WAKELVL6   (1 << 6)
/** PK5 Wake Level */
#define GPIO_WAKELVL_WAKELVL5   (1 << 5)
/** PK4 Wake Level */
#define GPIO_WAKELVL_WAKELVL4   (1 << 4)
/**@}*/

/** @defgroup gpio_wakestat_values GPIO_WAKESTAT Values
 * @brief GPIO Wake Status Register Values
@{*/
/** PK7 Wake Status */
#define GPIO_WAKESTAT_STAT7     (1 << 7)
/** PK6 Wake Status */
#define GPIO_WAKESTAT_STAT6     (1 << 6)
/** PK5 Wake Status */
#define GPIO_WAKESTAT_STAT5     (1 << 5)
/** PK4 Wake Status */
#define GPIO_WAKESTAT_STAT4     (1 << 4)
/**@}*/

/** @defgroup gpio_pp_values GPIO_PP Values
 * @brief GPIO Peripheral Property Register Values
@{*/
/** Extended Drive Enable */
#define GPIO_PP_EDE             (1 << 0)
/**@}*/

/** @defgroup gpio_pc_values GPIO_PC Values
 * @brief GPIO Peripheral Configuration Register Values
@{*/
/** Extended Drive Mode Bit N */
#define GPIO_PC_EDM(n, mode)    ((mode) << (2 * (n)))
/** Extended Drive Mode Bit N Mask */
#define GPIO_PC_EDM_MASK(n)     (0x3 << (2 * (n)))
/** Normal behavior, 2, 4 and 8 mA are available */
#define GPIO_PC_EDM_NORMAL      0x0
/** An additional 6 mA option is provided.
 * Set one, clear other behavior is disabled */
#define GPIO_PC_EDM_ADD_6MA     0x1
/** Full range, 2, 4, 6, 8, 10 and 12 mA are available.
 * Set one, clear other behavior is disabled */
#define GPIO_PC_EDM_FULL_RANGE  0x3
/**@}*/

/** @defgroup gpio_af_pa0_values GPIO_AF_PA0 Values
 * @brief GPIO PA0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       33       |
 * NFBGA-212   |       V3       |
@{*/
/** UART module 0 receive */
#define GPIO_AF_PA0_U0RX        GPIO_AF1
/** I2C module 9 clock */
#define GPIO_AF_PA0_I2C9SCL     GPIO_AF2
/** 16- and 32-bit Timer 0 capture, compare, or PWM 0 */
#define GPIO_AF_PA0_T0CCP0      GPIO_AF3
/** CAN module 0 receive */
#define GPIO_AF_PA0_CAN0RX      GPIO_AF7
/**@}*/

/** @defgroup gpio_af_pa1_values GPIO_AF_PA1 Values
 * @brief GPIO PA1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       34       |
 * NFBGA-212   |       W3       |
@{*/
/** UART module 0 transmit */
#define GPIO_AF_PA1_U0TX        GPIO_AF1
/** I2C module 9 data */
#define GPIO_AF_PA1_I2C9SDA     GPIO_AF2
/** 16- and 32-bit Timer 0 capture, compare, or PWM 1 */
#define GPIO_AF_PA1_T0CCP1      GPIO_AF3
/** CAN module 0 transmit */
#define GPIO_AF_PA1_CAN0TX      GPIO_AF7
/**@}*/

/** @defgroup gpio_af_pa2_values GPIO_AF_PA2 Values
 * @brief GPIO PA2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       35       |
 * NFBGA-212   |       T6       |
@{*/
/** UART module 4 receive */
#define GPIO_AF_PA2_U4RX        GPIO_AF1
/** I2C module 8 clock */
#define GPIO_AF_PA2_I2C8SCL     GPIO_AF2
/** 16- and 32-bit Timer 1 capture, compare, or PWM 0 */
#define GPIO_AF_PA2_T1CCP0      GPIO_AF3
/** SSI module 0 clock */
#define GPIO_AF_PA2_SSI0CLK     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pa3_values GPIO_AF_PA3 Values
 * @brief GPIO PA3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       36       |
 * NFBGA-212   |       U5       |
@{*/
/** UART module 4 transmit */
#define GPIO_AF_PA3_U4TX        GPIO_AF1
/** I2C module 8 data */
#define GPIO_AF_PA3_I2C8SDA     GPIO_AF2
/** 16- and 32-bit Timer 1 capture, compare, or PWM 1 */
#define GPIO_AF_PA3_T1CCP1      GPIO_AF3
/** SSI module 0 frame signal */
#define GPIO_AF_PA3_SSI0FSS     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pa4_values GPIO_AF_PA4 Values
 * @brief GPIO PA4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       37       |
 * NFBGA-212   |       V4       |
@{*/
/** UART module 3 receive */
#define GPIO_AF_PA4_U3RX        GPIO_AF1
/** I2C module 7 clock */
#define GPIO_AF_PA4_I2C7SCL     GPIO_AF2
/** 16- and 32-bit Timer 2 capture, compare, or PWM 0 */
#define GPIO_AF_PA4_T2CCP0      GPIO_AF3
/** SSI Module 0 bidirectional data pin 0 */
#define GPIO_AF_PA4_SSI0XDAT0   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pa5_values GPIO_AF_PA5 Values
 * @brief GPIO PA5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       38       |
 * NFBGA-212   |       W4       |
@{*/
/** UART module 3 transmit */
#define GPIO_AF_PA5_U3TX        GPIO_AF1
/** I2C module 7 data */
#define GPIO_AF_PA5_I2C7SDA     GPIO_AF2
/** 16- and 32-bit Timer 2 capture, compare, or PWM 1 */
#define GPIO_AF_PA5_T2CCP1      GPIO_AF3
/** SSI Module 0 bidirectional data pin 1 */
#define GPIO_AF_PA5_SSI0XDAT1   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pa6_values GPIO_AF_PA6 Values
 * @brief GPIO PA6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       40       |
 * NFBGA-212   |       V5       |
@{*/
/** UART module 2 receive */
#define GPIO_AF_PA6_U2RX        GPIO_AF1
/** I2C module 6 clock */
#define GPIO_AF_PA6_I2C6SCL     GPIO_AF2
/** 16- and 32-bit Timer 3 capture, compare, or PWM 0 */
#define GPIO_AF_PA6_T3CCP0      GPIO_AF3
/** USB Control an external power source in host mode */
#define GPIO_AF_PA6_USB0EPEN    GPIO_AF5
/** SSI Module 0 bidirectional data pin 2 */
#define GPIO_AF_PA6_SSI0XDAT2   GPIO_AF13
/** Ethernet 0 receive clock */
#define GPIO_AF_PA6_EN0RXCK     GPIO_AF14
/** EPI module 0 signal 8 */
#define GPIO_AF_PA6_EPI0S8      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pa7_values GPIO_AF_PA7 Values
 * @brief GPIO PA7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       41       |
 * NFBGA-212   |       R7       |
@{*/
/** UART module 2 transmit */
#define GPIO_AF_PA7_U2TX        GPIO_AF1
/** I2C module 6 data */
#define GPIO_AF_PA7_I2C6SDA     GPIO_AF2
/** 16- and 32-bit Timer 3 capture, compare, or PWM 1 */
#define GPIO_AF_PA7_T3CCP1      GPIO_AF3
/** USB Power Fault input in host mode */
#define GPIO_AF_PA7_USB0PFLT    GPIO_AF5
/** USB Control an external power source in host mode */
#define GPIO_AF_PA7_USB0EPEN    GPIO_AF11
/** SSI Module 0 bidirectional data pin 3 */
#define GPIO_AF_PA7_SSI0XDAT3   GPIO_AF13
/** EPI module 0 signal 9 */
#define GPIO_AF_PA7_EPI0S9      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pb0_values GPIO_AF_PB0 Values
 * @brief GPIO PB0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       95       |
 * NFBGA-212   |      A16       |
@{*/
/** UART module 1 receive */
#define GPIO_AF_PB0_U1RX        GPIO_AF1
/** I2C module 5 clock */
#define GPIO_AF_PB0_I2C5SCL     GPIO_AF2
/** 16- and 32-bit Timer 4 capture, compare, or PWM 0 */
#define GPIO_AF_PB0_T4CCP0      GPIO_AF3
/** CAN module 1 receive */
#define GPIO_AF_PB0_CAN1RX      GPIO_AF7
/**@}*/

/** @defgroup gpio_af_pb1_values GPIO_AF_PB1 Values
 * @brief GPIO PB1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       96       |
 * NFBGA-212   |      B16       |
@{*/
/** UART module 1 transmit */
#define GPIO_AF_PB1_U1TX        GPIO_AF1
/** I2C module 5 data */
#define GPIO_AF_PB1_I2C5SDA     GPIO_AF2
/** 16- and 32-bit Timer 4 capture, compare, or PWM 1 */
#define GPIO_AF_PB1_T4CCP1      GPIO_AF3
/** CAN module 1 transmit */
#define GPIO_AF_PB1_CAN1TX      GPIO_AF7
/**@}*/

/** @defgroup gpio_af_pb2_values GPIO_AF_PB2 Values
 * @brief GPIO PB2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       91       |
 * NFBGA-212   |      A17       |
@{*/
/** I2C module 0 clock */
#define GPIO_AF_PB2_I2C0SCL     GPIO_AF2
/** 16- and 32-bit Timer 5 capture, compare, or PWM 0 */
#define GPIO_AF_PB2_T5CCP0      GPIO_AF3
/** Ethernet 0 management data clock */
#define GPIO_AF_PB2_EN0MDC      GPIO_AF5
/** USB Asserted by the USB controller to signal the end of a USB transmit
 *  packet or register write operation */
#define GPIO_AF_PB2_USB0STP     GPIO_AF14
/** EPI module 0 signal 27 */
#define GPIO_AF_PB2_EPI0S27     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pb3_values GPIO_AF_PB3 Values
 * @brief GPIO PB3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       92       |
 * NFBGA-212   |      B17       |
@{*/
/** I2C module 0 data */
#define GPIO_AF_PB3_I2C0SDA     GPIO_AF2
/** 16- and 32-bit Timer 5 capture, compare, or PWM 1 */
#define GPIO_AF_PB3_T5CCP1      GPIO_AF3
/** Ethernet 0 management data input/output signal */
#define GPIO_AF_PB3_EN0MDIO     GPIO_AF5
/** USB 60-MHz clock to the external PHY */
#define GPIO_AF_PB3_USB0CLK     GPIO_AF14
/** EPI module 0 signal 28 */
#define GPIO_AF_PB3_EPI0S28     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pb4_values GPIO_AF_PB4 Values
 * @brief GPIO PB4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      121       |
 * NFBGA-212   |       C6       |
@{*/
/** UART module 0 clear to send modem flow control input signal */
#define GPIO_AF_PB4_U0CTS       GPIO_AF1
/** I2C module 5 clock */
#define GPIO_AF_PB4_I2C5SCL     GPIO_AF2
/** SSI module 1 frame signal */
#define GPIO_AF_PB4_SSI1FSS     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pb5_values GPIO_AF_PB5 Values
 * @brief GPIO PB5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      120       |
 * NFBGA-212   |       B6       |
@{*/
/** UART module 0 request to send modem flow control output signal */
#define GPIO_AF_PB5_U0RTS       GPIO_AF1
/** I2C module 5 data */
#define GPIO_AF_PB5_I2C5SDA     GPIO_AF2
/** SSI module 1 clock */
#define GPIO_AF_PB5_SSI1CLK     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pb6_values GPIO_AF_PB6 Values
 * @brief GPIO PB6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       F2       |
@{*/
/** I2C module 6 clock */
#define GPIO_AF_PB6_I2C6SCL     GPIO_AF1
/** 16- and 32-bit Timer 6 capture, compare, or PWM 0 */
#define GPIO_AF_PB6_T6CCP0      GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pb7_values GPIO_AF_PB7 Values
 * @brief GPIO PB7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       F1       |
@{*/
/** I2C module 6 data */
#define GPIO_AF_PB7_I2C6SDA       GPIO_AF1
/** 16- and 32-bit Timer 6 capture, compare, or PWM 1 */
#define GPIO_AF_PB7_T6CCP1        GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pc0_values GPIO_AF_PC0 Values
 * @brief GPIO PC0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      100       |
 * NFBGA-212   |      B15       |
@{*/
/** JTAG and SWD clock */
#define GPIO_AF_PC0_TCK         GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pc1_values GPIO_AF_PC1 Values
 * @brief GPIO PC1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       99       |
 * NFBGA-212   |      C15       |
@{*/
/** JTAG TMS and SWDIO */
#define GPIO_AF_PC1_TMS         GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pc2_values GPIO_AF_PC2 Values
 * @brief GPIO PC2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       98       |
 * NFBGA-212   |      D14       |
@{*/
/** JTAG TDI */
#define GPIO_AF_PC2_TDI         GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pc3_values GPIO_AF_PC3 Values
 * @brief GPIO PC3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       97       |
 * NFBGA-212   |      C14       |
@{*/
/** JTAG TDO and SWO */
#define GPIO_AF_PC3_TDO         GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pc4_values GPIO_AF_PC4 Values
 * @brief GPIO PC4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       25       |
 * NFBGA-212   |       M2       |
@{*/
/** UART module 7 receive */
#define GPIO_AF_PC4_U7RX        GPIO_AF1
/** 16- and 32-bit Timer 7 capture, compare, or PWM 0 */
#define GPIO_AF_PC4_T7CCP0      GPIO_AF3
/** EPI module 0 signal 7 */
#define GPIO_AF_PC4_EPI0S7      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pc5_values GPIO_AF_PC5 Values
 * @brief GPIO PC5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       24       |
 * NFBGA-212   |       M1       |
@{*/
/** UART module 7 transmit */
#define GPIO_AF_PC5_U7TX        GPIO_AF1
/** 16- and 32-bit Timer 7 capture, compare, or PWM 1 */
#define GPIO_AF_PC5_T7CCP1      GPIO_AF3
/** Buffered version of the 32.768-kHz clock of the Hibernation module */
#define GPIO_AF_PC5_RTCCLK      GPIO_AF7
/** EPI module 0 signal 6 */
#define GPIO_AF_PC5_EPI0S6      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pc6_values GPIO_AF_PC6 Values
 * @brief GPIO PC6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       22       |
 * NFBGA-212   |       L2       |
@{*/
/** UART module 5 receive */
#define GPIO_AF_PC6_U5RX        GPIO_AF1
/** EPI module 0 signal 5 */
#define GPIO_AF_PC6_EPI0S5      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pc7_values GPIO_AF_PC7 Values
 * @brief GPIO PC7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       22       |
 * NFBGA-212   |       K3       |
@{*/
/** UART module 5 transmit */
#define GPIO_AF_PC7_U5TX        GPIO_AF1
/** EPI module 0 signal 4 */
#define GPIO_AF_PC7_EPI0S4      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd0_values GPIO_AF_PD0 Values
 * @brief GPIO PD0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       1        |
 * NFBGA-212   |       C2       |
@{*/
/** I2C module 7 clock */
#define GPIO_AF_PD0_I2C7SCL     GPIO_AF2
/** 16- and 32-bit Timer 0 capture, compare, or PWM 0 */
#define GPIO_AF_PD0_T0CCP0      GPIO_AF3
/** Analog comparator 0 output */
#define GPIO_AF_PD0_C0O         GPIO_AF5
/** SSI Module 2 bidirectional data pin 1 */
#define GPIO_AF_PD0_SSI2XDAT1   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd1_values GPIO_AF_PD1 Values
 * @brief GPIO PD1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       2        |
 * NFBGA-212   |       C1       |
@{*/
/** I2C module 7 data */
#define GPIO_AF_PD1_I2C7SDA     GPIO_AF2
/** 16- and 32-bit Timer 0 capture, compare, or PWM 1 */
#define GPIO_AF_PD1_T0CCP1      GPIO_AF3
/** Analog comparator 1 output */
#define GPIO_AF_PD1_C1O         GPIO_AF5
/** SSI Module 2 bidirectional data pin 0 */
#define GPIO_AF_PD1_SSI2XDAT0   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd2_values GPIO_AF_PD2 Values
 * @brief GPIO PD2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       3        |
 * NFBGA-212   |       D2       |
@{*/
/** I2C module 8 clock */
#define GPIO_AF_PD2_I2C8SCL     GPIO_AF2
/** 16- and 32-bit Timer 1 capture, compare, or PWM 0 */
#define GPIO_AF_PD2_T1CCP0      GPIO_AF3
/** Analog comparator 2 output */
#define GPIO_AF_PD2_C2O         GPIO_AF5
/** SSI module 2 frame signal */
#define GPIO_AF_PD2_SSI2FSS     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd3_values GPIO_AF_PD3 Values
 * @brief GPIO PD3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       4        |
 * NFBGA-212   |       D1       |
@{*/
/** I2C module 8 data */
#define GPIO_AF_PD3_I2C8SDA     GPIO_AF2
/** 16- and 32-bit Timer 1 capture, compare, or PWM 1 */
#define GPIO_AF_PD3_T1CCP1      GPIO_AF3
/** SSI module 2 clock */
#define GPIO_AF_PD3_SSI2CLK     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd4_values GPIO_AF_PD4 Values
 * @brief GPIO PD4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      125       |
 * NFBGA-212   |       A4       |
@{*/
/** UART module 2 receive */
#define GPIO_AF_PD4_U2RX        GPIO_AF1
/** 16- and 32-bit Timer 3 capture, compare, or PWM 0 */
#define GPIO_AF_PD4_T3CCP0      GPIO_AF3
/** SSI Module 1 bidirectional data pin 2 */
#define GPIO_AF_PD4_SSI1XDAT2   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd5_values GPIO_AF_PD5 Values
 * @brief GPIO PD5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      126       |
 * NFBGA-212   |       B4       |
@{*/
/** UART module 2 transmit */
#define GPIO_AF_PD5_U2TX        GPIO_AF1
/** 16- and 32-bit Timer 3 capture, compare, or PWM 1 */
#define GPIO_AF_PD5_T3CCP1      GPIO_AF3
/** SSI Module 1 bidirectional data pin 3 */
#define GPIO_AF_PD5_SSI1XDAT3   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd6_values GPIO_AF_PD6 Values
 * @brief GPIO PD6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      127       |
 * NFBGA-212   |       B3       |
@{*/
/** UART module 2 request to send modem flow control output line */
#define GPIO_AF_PD6_U2RTS       GPIO_AF1
/** 16- and 32-bit Timer 4 capture, compare, or PWM 0 */
#define GPIO_AF_PD6_T4CCP0      GPIO_AF3
/** USB Control an external power source in host mode */
#define GPIO_AF_PD6_USB0EPEN    GPIO_AF5
/** SSI Module 2 bidirectional data pin 3 */
#define GPIO_AF_PD6_SSI2XDAT3   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd7_values GPIO_AF_PD7 Values
 * @brief GPIO PD7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      128       |
 * NFBGA-212   |       B2       |
@{*/
/** UART module 2 clear to send modem flow control input signal */
#define GPIO_AF_PD7_U2CTS       GPIO_AF1
/** 16- and 32-bit Timer 4 capture, compare, or PWM 1 */
#define GPIO_AF_PD7_T4CCP1      GPIO_AF3
/** USB Power Fault input in host mode */
#define GPIO_AF_PD7_USB0PFLT    GPIO_AF5
/** Nonmaskable interrupt */
#define GPIO_AF_PD7_NMI         GPIO_AF8
/** SSI Module 2 bidirectional data pin 2 */
#define GPIO_AF_PD7_SSI2XDAT2   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pe0_values GPIO_AF_PE0 Values
 * @brief GPIO PE0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       15       |
 * NFBGA-212   |       H3       |
@{*/
/** UART module 1 request to send modem flow control output line */
#define GPIO_AF_PE0_U1RTS       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pe1_values GPIO_AF_PE1 Values
 * @brief GPIO PE1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       14       |
 * NFBGA-212   |       H2       |
@{*/
/** UART module 1 data set ready modem output control line */
#define GPIO_AF_PE1_U1DSR       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pe2_values GPIO_AF_PE2 Values
 * @brief GPIO PE2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       13       |
 * NFBGA-212   |       G1       |
@{*/
/** UART module 1 data carrier detect modem status input signal */
#define GPIO_AF_PE2_U1DCD       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pe3_values GPIO_AF_PE3 Values
 * @brief GPIO PE3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       12       |
 * NFBGA-212   |       G2       |
@{*/
/** UART module 1 data terminal ready modem status input signal */
#define GPIO_AF_PE3_U1DTR       GPIO_AF1
/** 1-Wire single bus pin */
#define GPIO_AF_PE3_OWIRE       GPIO_AF5
/**@}*/

/** @defgroup gpio_af_pe4_values GPIO_AF_PE4 Values
 * @brief GPIO PE4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      123       |
 * NFBGA-212   |       A5       |
@{*/
/** UART module 1 ring indicator modem status input signal */
#define GPIO_AF_PE4_U1RI        GPIO_AF1
/** SSI Module 1 bidirectional data pin 0 */
#define GPIO_AF_PE4_SSI1XDAT0   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pe5_values GPIO_AF_PE5 Values
 * @brief GPIO PE5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      124       |
 * NFBGA-212   |       B5       |
@{*/
/** SSI Module 1 bidirectional data pin 1 */
#define GPIO_AF_PE5_SSI1XDAT1   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pe6_values GPIO_AF_PE6 Values
 * @brief GPIO PE6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       A7       |
@{*/
/** UART module 0 clear to send modem flow control input signal */
#define GPIO_AF_PE6_U0CTS       GPIO_AF1
/** I2C module 9 clock */
#define GPIO_AF_PE6_I2C9SCL     GPIO_AF2
/**@}*/

/** @defgroup gpio_af_pe7_values GPIO_AF_PE7 Values
 * @brief GPIO PE7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       B7       |
@{*/
/** UART module 0 request to send modem flow control output signal */
#define GPIO_AF_PE7_U0RTS       GPIO_AF1
/** I2C module 9 data */
#define GPIO_AF_PE7_I2C9SDA     GPIO_AF2
/** Nonmaskable interrupt */
#define GPIO_AF_PE7_NMI         GPIO_AF8
/**@}*/

/** @defgroup gpio_af_pf0_values GPIO_AF_PF0 Values
 * @brief GPIO PF0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       42       |
 * NFBGA-212   |       U6       |
@{*/
/** Ethernet 0 LED 0 */
#define GPIO_AF_PF0_EN0LED0     GPIO_AF5
/** Motion control module 0 PWM 0 */
#define GPIO_AF_PF0_M0PWM0      GPIO_AF6
/** SSI Module 3 bidirectional data pin 1 */
#define GPIO_AF_PF0_SSI3XDAT1   GPIO_AF14
/** Trace data 2 */
#define GPIO_AF_PF0_TRD2        GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pf1_values GPIO_AF_PF1 Values
 * @brief GPIO PF1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       43       |
 * NFBGA-212   |       V6       |
@{*/
/** Ethernet 0 LED 2 */
#define GPIO_AF_PF1_EN0LED2     GPIO_AF5
/** Motion control module 0 PWM 1 */
#define GPIO_AF_PF1_M0PWM1      GPIO_AF6
/** SSI Module 3 bidirectional data pin 0 */
#define GPIO_AF_PF1_SSI3XDAT0   GPIO_AF14
/** Trace data 1 */
#define GPIO_AF_PF1_TRD1        GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pf2_values GPIO_AF_PF2 Values
 * @brief GPIO PF2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       44       |
 * NFBGA-212   |       W6       |
@{*/
/** Ethernet 0 management data clock */
#define GPIO_AF_PF2_EN0MDC      GPIO_AF5
/** Motion control module 0 PWM 2 */
#define GPIO_AF_PF2_M0PWM2      GPIO_AF6
/** SSI module 3 frame signal */
#define GPIO_AF_PF2_SSI3FSS     GPIO_AF14
/** Trace data 0 */
#define GPIO_AF_PF2_TRD0        GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pf3_values GPIO_AF_PF3 Values
 * @brief GPIO PF3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       45       |
 * NFBGA-212   |       T7       |
@{*/
/** Ethernet 0 management data input/output signal */
#define GPIO_AF_PF3_EN0MDIO     GPIO_AF5
/** Motion control module 0 PWM 3 */
#define GPIO_AF_PF3_M0PWM3      GPIO_AF6
/** SSI module 3 clock */
#define GPIO_AF_PF3_SSI3CLK     GPIO_AF14
/** Trace clock */
#define GPIO_AF_PF3_TRCLK       GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pf4_values GPIO_AF_PF4 Values
 * @brief GPIO PF4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       46       |
 * NFBGA-212   |       V7       |
@{*/
/** Ethernet 0 LED 1 */
#define GPIO_AF_PF4_EN0LED1     GPIO_AF5
/** Motion control module 0 PWM fault 0 */
#define GPIO_AF_PF4_M0FAULT0    GPIO_AF6
/** SSI Module 3 bidirectional data pin 2 */
#define GPIO_AF_PF4_SSI3XDAT2   GPIO_AF14
/** Trace data 3 */
#define GPIO_AF_PF4_TRD3        GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pf5_values GPIO_AF_PF5 Values
 * @brief GPIO PF5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       W7       |
@{*/
/** SSI Module 3 bidirectional data pin 3 */
#define GPIO_AF_PF5_SSI3XDAT3   GPIO_AF14
/**@}*/

/** @defgroup gpio_af_pf6_values GPIO_AF_PF6 Values
 * @brief GPIO PF6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       T8       |
@{*/
/** LCD memory clock, secondary chip select (CS1), or secondary enable (E1) */
#define GPIO_AF_PF6_LCDMCLK     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pf7_values GPIO_AF_PF7 Values
 * @brief GPIO PF7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       U8       |
@{*/
/** LCD data pin 2 input/output */
#define GPIO_AF_PF7_LCDDATA02   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg0_values GPIO_AF_PG0 Values
 * @brief GPIO PG0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       49       |
 * NFBGA-212   |      N15       |
@{*/
/** I2C module 1 clock */
#define GPIO_AF_PG0_I2C1SCL     GPIO_AF2
/** Ethernet 0 pulse-per-second (PPS) output */
#define GPIO_AF_PG0_EN0PPS      GPIO_AF5
/** Motion control module 0 PWM 4 */
#define GPIO_AF_PG0_M0PWM4      GPIO_AF6
/** EPI module 0 signal 11 */
#define GPIO_AF_PG0_EPI0S11     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg1_values GPIO_AF_PG1 Values
 * @brief GPIO PG1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       50       |
 * NFBGA-212   |      T14       |
@{*/
/** I2C module 1 data */
#define GPIO_AF_PG1_I2C1SDA     GPIO_AF2
/** Motion control module 0 PWM 5 */
#define GPIO_AF_PG1_M0PWM5      GPIO_AF6
/** EPI module 0 signal 10 */
#define GPIO_AF_PG1_EPI0S10     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg2_values GPIO_AF_PG2 Values
 * @brief GPIO PG2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      V11       |
@{*/
/** I2C module 2 clock */
#define GPIO_AF_PG2_I2C2SCL     GPIO_AF2
/** Ethernet 0 transmit clock */
#define GPIO_AF_PG2_EN0TXCK     GPIO_AF14
/** SSI Module 2 bidirectional data pin 3 */
#define GPIO_AF_PG2_SSI2XDAT3   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg3_values GPIO_AF_PG3 Values
 * @brief GPIO PG3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      M16       |
@{*/
/** I2C module 2 data */
#define GPIO_AF_PG3_I2C2SDA     GPIO_AF2
/** Ethernet 0 transmit enable */
#define GPIO_AF_PG3_EN0TXEN     GPIO_AF14
/** SSI Module 2 bidirectional data pin 2 */
#define GPIO_AF_PG3_SSI2XDAT2   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg4_values GPIO_AF_PG4 Values
 * @brief GPIO PG4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      K17       |
@{*/
/** UART module 0 clear to send modem flow control input signal */
#define GPIO_AF_PG4_U0CTS       GPIO_AF1
/** I2C module 3 clock */
#define GPIO_AF_PG4_I2C3SCL     GPIO_AF2
/** 1-Wire single bus pin */
#define GPIO_AF_PG4_OWIRE       GPIO_AF5
/** Ethernet 0 transmit data 0 */
#define GPIO_AF_PG4_EN0TXD0     GPIO_AF14
/** SSI Module 2 bidirectional data pin 1 */
#define GPIO_AF_PG4_SSI2XDAT1   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg5_values GPIO_AF_PG5 Values
 * @brief GPIO PG5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      K15       |
@{*/
/** UART module 0 request to send modem flow control output signal */
#define GPIO_AF_PG5_U0RTS       GPIO_AF1
/** I2C module 3 data */
#define GPIO_AF_PG5_I2C3SDA     GPIO_AF2
/** 1-Wire optional second signal to be used as output */
#define GPIO_AF_PG5_OWALT       GPIO_AF5
/** Ethernet 0 transmit data 1 */
#define GPIO_AF_PG5_EN0TXD1     GPIO_AF14
/** SSI Module 2 bidirectional data pin 0 */
#define GPIO_AF_PG5_SSI2XDAT0   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg6_values GPIO_AF_PG6 Values
 * @brief GPIO PG6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      V12       |
@{*/
/** I2C module 4 clock */
#define GPIO_AF_PG6_I2C4SCL     GPIO_AF2
/** 1-Wire single bus pin */
#define GPIO_AF_PG6_OWIRE       GPIO_AF5
/** Ethernet 0 receive error */
#define GPIO_AF_PG6_EN0RXER     GPIO_AF14
/** SSI module 2 frame signal */
#define GPIO_AF_PG6_SSI2FSS     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg7_values GPIO_AF_PG7 Values
 * @brief GPIO PG7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      U14       |
@{*/
/** I2C module 4 data */
#define GPIO_AF_PG7_I2C4SDA     GPIO_AF2
/** 1-Wire single bus pin */
#define GPIO_AF_PG7_OWIRE       GPIO_AF5
/** Ethernet 0 receive data valid */
#define GPIO_AF_PG7_EN0RXDV     GPIO_AF14
/** SSI module 2 clock */
#define GPIO_AF_PG7_SSI2CLK     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ph0_values GPIO_AF_PH0 Values
 * @brief GPIO PH0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       29       |
 * NFBGA-212   |       P4       |
@{*/
/** UART module 0 request to send modem flow control output signal */
#define GPIO_AF_PH0_U0RTS       GPIO_AF1
/** EPI module 0 signal 0 */
#define GPIO_AF_PH0_EPI0S0      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ph1_values GPIO_AF_PH1 Values
 * @brief GPIO PH1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       30       |
 * NFBGA-212   |       R2       |
@{*/
/** UART module 0 clear to send modem flow control input signal */
#define GPIO_AF_PH1_U0CTS       GPIO_AF1
/** EPI module 0 signal 1 */
#define GPIO_AF_PH1_EPI0S1      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ph2_values GPIO_AF_PH2 Values
 * @brief GPIO PH2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       31       |
 * NFBGA-212   |       R1       |
@{*/
/** UART module 0 data carrier detect modem status input signal */
#define GPIO_AF_PH2_U0DCD       GPIO_AF1
/** EPI module 0 signal 2 */
#define GPIO_AF_PH2_EPI0S2      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ph3_values GPIO_AF_PH3 Values
 * @brief GPIO PH3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       32       |
 * NFBGA-212   |       T1       |
@{*/
/** UART module 0 data set ready modem output control line */
#define GPIO_AF_PH3_U0DSR       GPIO_AF1
/** EPI module 0 signal 3 */
#define GPIO_AF_PH3_EPI0S3      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ph4_values GPIO_AF_PH4 Values
 * @brief GPIO PH4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       R3       |
@{*/
/** UART module 0 data terminal ready modem status input signal */
#define GPIO_AF_PH4_U0DTR       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_ph5_values GPIO_AF_PH5 Values
 * @brief GPIO PH5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       T2       |
@{*/
/** UART module 0 ring indicator modem status input signal */
#define GPIO_AF_PH5_U0RI        GPIO_AF1
/** Ethernet 0 pulse-per-second (PPS) output */
#define GPIO_AF_PH5_EN0PPS      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ph6_values GPIO_AF_PH6 Values
 * @brief GPIO PH6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       U2       |
@{*/
/** UART module 5 receive */
#define GPIO_AF_PH6_U5RX        GPIO_AF1
/** UART module 7 receive */
#define GPIO_AF_PH6_U7RX        GPIO_AF2
/**@}*/

/** @defgroup gpio_af_ph7_values GPIO_AF_PH7 Values
 * @brief GPIO PH7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       V2       |
@{*/
/** UART module 5 transmit */
#define GPIO_AF_PH7_U5TX        GPIO_AF1
/** UART module 7 transmit */
#define GPIO_AF_PH7_U7TX        GPIO_AF2
/**@}*/

/** @defgroup gpio_af_pj0_values GPIO_AF_PJ0 Values
 * @brief GPIO PJ0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      116       |
 * NFBGA-212   |       C8       |
@{*/
/** UART module 3 receive */
#define GPIO_AF_PJ0_U3RX        GPIO_AF1
/** Ethernet 0 pulse-per-second (PPS) output */
#define GPIO_AF_PJ0_EN0PPS      GPIO_AF5
/**@}*/

/** @defgroup gpio_af_pj1_values GPIO_AF_PJ1 Values
 * @brief GPIO PJ1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      117       |
 * NFBGA-212   |       E7       |
@{*/
/** UART module 3 transmit */
#define GPIO_AF_PJ1_U3TX        GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pj2_values GPIO_AF_PJ2 Values
 * @brief GPIO PJ2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      H17       |
@{*/
/** UART module 2 request to send modem flow control output line */
#define GPIO_AF_PJ2_U2RTS       GPIO_AF1
/** LCD data pin 14 input/output */
#define GPIO_AF_PJ2_LCDDATA14   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pj3_values GPIO_AF_PJ3 Values
 * @brief GPIO PJ3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      F16       |
@{*/
/** UART module 2 clear to send modem flow control input signal */
#define GPIO_AF_PJ3_U2CTS       GPIO_AF1
/** LCD data pin 15 input/output */
#define GPIO_AF_PJ3_LCDDATA15   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pj4_values GPIO_AF_PJ4 Values
 * @brief GPIO PJ4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      F18       |
@{*/
/** UART module 3 request to send modem flow control output line */
#define GPIO_AF_PJ4_U3RTS       GPIO_AF1
/** LCD data pin 16 output */
#define GPIO_AF_PJ4_LCDDATA16   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pj5_values GPIO_AF_PJ5 Values
 * @brief GPIO PJ5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      E17       |
@{*/
/** UART module 3 clear to send modem flow control input signal */
#define GPIO_AF_PJ5_U3CTS       GPIO_AF1
/** LCD data pin 17 output */
#define GPIO_AF_PJ5_LCDDATA17   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pj6_values GPIO_AF_PJ6 Values
 * @brief GPIO PJ6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       N1       |
@{*/
/** UART module 4 request to send modem flow control output line */
#define GPIO_AF_PJ6_U4RTS       GPIO_AF1
/** LCD AC bias or latch enable in raster mode */
#define GPIO_AF_PJ6_LCDAC       GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pj7_values GPIO_AF_PJ7 Values
 * @brief GPIO PJ7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       K5       |
@{*/
/** UART module 4 clear to send modem flow control input signal */
#define GPIO_AF_PJ7_U4CTS       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pk0_values GPIO_AF_PK0 Values
 * @brief GPIO PK0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       18       |
 * NFBGA-212   |       J1       |
@{*/
/** UART module 4 receive */
#define GPIO_AF_PK0_U4RX        GPIO_AF1
/** EPI module 0 signal 0 */
#define GPIO_AF_PK0_EPI0S0      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk1_values GPIO_AF_PK1 Values
 * @brief GPIO PK1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       19       |
 * NFBGA-212   |       J2       |
@{*/
/** UART module 4 transmit */
#define GPIO_AF_PK1_U4TX        GPIO_AF1
/** EPI module 0 signal 1 */
#define GPIO_AF_PK1_EPI0S1      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk2_values GPIO_AF_PK2 Values
 * @brief GPIO PK2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       20       |
 * NFBGA-212   |       K1       |
@{*/
/** UART module 4 request to send modem flow control output line */
#define GPIO_AF_PK2_U4RTS       GPIO_AF1
/** EPI module 0 signal 2 */
#define GPIO_AF_PK2_EPI0S2      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk3_values GPIO_AF_PK3 Values
 * @brief GPIO PK3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       21       |
 * NFBGA-212   |       K2       |
@{*/
/** UART module 4 clear to send modem flow control input signal */
#define GPIO_AF_PK3_U4CTS       GPIO_AF1
/** EPI module 0 signal 3 */
#define GPIO_AF_PK3_EPI0S3      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk4_values GPIO_AF_PK4 Values
 * @brief GPIO PK4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       63       |
 * NFBGA-212   |      U19       |
@{*/
/** I2C module 3 clock */
#define GPIO_AF_PK4_I2C3SCL     GPIO_AF2
/** Ethernet 0 LED 0 */
#define GPIO_AF_PK4_EN0LED0     GPIO_AF5
/** Motion control module 0 PWM 6 */
#define GPIO_AF_PK4_M0PWM6      GPIO_AF6
/** Ethernet 0 interrupt from the Ethernet PHY */
#define GPIO_AF_PK4_EN0INTRN    GPIO_AF7
/** Ethernet 0 receive data 3 */
#define GPIO_AF_PK4_EN0RXD3     GPIO_AF14
/** EPI module 0 signal 32 */
#define GPIO_AF_PK4_EPI0S32     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk5_values GPIO_AF_PK5 Values
 * @brief GPIO PK5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       62       |
 * NFBGA-212   |      V17       |
@{*/
/** I2C module 3 data */
#define GPIO_AF_PK5_I2C3SDA     GPIO_AF2
/** Ethernet 0 LED 2 */
#define GPIO_AF_PK5_EN0LED2     GPIO_AF5
/** Motion control module 0 PWM 7 */
#define GPIO_AF_PK5_M0PWM7      GPIO_AF6
/** Ethernet 0 receive data 2 */
#define GPIO_AF_PK5_EN0RXD2     GPIO_AF14
/** EPI module 0 signal 31 */
#define GPIO_AF_PK5_EPI0S31     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk6_values GPIO_AF_PK6 Values
 * @brief GPIO PK6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       61       |
 * NFBGA-212   |      V16       |
@{*/
/** I2C module 4 clock */
#define GPIO_AF_PK6_I2C4SCL     GPIO_AF2
/** Ethernet 0 LED 1 */
#define GPIO_AF_PK6_EN0LED1     GPIO_AF5
/** Motion control module 0 PWM fault 1 */
#define GPIO_AF_PK6_M0FAULT1    GPIO_AF6
/** Ethernet 0 transmit data 2 */
#define GPIO_AF_PK6_EN0TXD2     GPIO_AF14
/** EPI module 0 signal 25 */
#define GPIO_AF_PK6_EPI0S25     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk7_values GPIO_AF_PK7 Values
 * @brief GPIO PK7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       60       |
 * NFBGA-212   |      W16       |
@{*/
/** UART module 0 ring indicator modem status input signal */
#define GPIO_AF_PK7_U0RI        GPIO_AF1
/** I2C module 4 data */
#define GPIO_AF_PK7_I2C4SDA     GPIO_AF2
/** Buffered version of the 32.768-kHz clock of the Hibernation module */
#define GPIO_AF_PK7_RTCCLK      GPIO_AF5
/** Motion control module 0 PWM fault 2 */
#define GPIO_AF_PK7_M0FAULT2    GPIO_AF6
/** Ethernet 0 transmit data 3 */
#define GPIO_AF_PK7_EN0TXD3     GPIO_AF14
/** EPI module 0 signal 24 */
#define GPIO_AF_PK7_EPI0S24     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl0_values GPIO_AF_PL0 Values
 * @brief GPIO PL0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       81       |
 * NFBGA-212   |      G16       |
@{*/
/** I2C module 2 data */
#define GPIO_AF_PL0_I2C2SDA     GPIO_AF2
/** Motion control module 0 PWM fault 3 */
#define GPIO_AF_PL0_M0FAULT3    GPIO_AF6
/** USB data 0 */
#define GPIO_AF_PL0_USB0D0      GPIO_AF14
/** EPI module 0 signal 16 */
#define GPIO_AF_PL0_EPI0S16     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl1_values GPIO_AF_PL1 Values
 * @brief GPIO PL1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       82       |
 * NFBGA-212   |      H19       |
@{*/
/** I2C module 2 clock */
#define GPIO_AF_PL1_I2C2SCL     GPIO_AF2
/** QEI module 0 phase A */
#define GPIO_AF_PL1_PHA0        GPIO_AF6
/** USB data 1 */
#define GPIO_AF_PL1_USB0D1      GPIO_AF14
/** EPI module 0 signal 17 */
#define GPIO_AF_PL1_EPI0S17     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl2_values GPIO_AF_PL2 Values
 * @brief GPIO PL2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       83       |
 * NFBGA-212   |      G18       |
@{*/
/** Analog comparator 0 output */
#define GPIO_AF_PL2_C0O         GPIO_AF5
/** QEI module 0 phase B */
#define GPIO_AF_PL2_PHB0        GPIO_AF6
/** USB data 2 */
#define GPIO_AF_PL2_USB0D2      GPIO_AF14
/** EPI module 0 signal 18 */
#define GPIO_AF_PL2_EPI0S18     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl3_values GPIO_AF_PL3 Values
 * @brief GPIO PL3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       84       |
 * NFBGA-212   |      J18       |
@{*/
/** Analog comparator 1 output */
#define GPIO_AF_PL3_C1O         GPIO_AF5
/** QEI module 0 index */
#define GPIO_AF_PL3_IDX0        GPIO_AF6
/** USB data 3 */
#define GPIO_AF_PL3_USB0D3      GPIO_AF14
/** EPI module 0 signal 19 */
#define GPIO_AF_PL3_EPI0S19     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl4_values GPIO_AF_PL4 Values
 * @brief GPIO PL4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       85       |
 * NFBGA-212   |      H18       |
@{*/
/** 16- and 32-bit Timer 0 capture, compare, or PWM 0 */
#define GPIO_AF_PL4_T0CCP0      GPIO_AF3
/** USB data 4 */
#define GPIO_AF_PL4_USB0D4      GPIO_AF14
/** EPI module 0 signal 26 */
#define GPIO_AF_PL4_EPI0S26     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl5_values GPIO_AF_PL5 Values
 * @brief GPIO PL5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       86       |
 * NFBGA-212   |      G19       |
@{*/
/** 16- and 32-bit Timer 0 capture, compare, or PWM 1 */
#define GPIO_AF_PL5_T0CCP1      GPIO_AF3
/** USB data 5 */
#define GPIO_AF_PL5_USB0D5      GPIO_AF14
/** EPI module 0 signal 33 */
#define GPIO_AF_PL5_EPI0S33     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl6_values GPIO_AF_PL6 Values
 * @brief GPIO PL6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       94       |
 * NFBGA-212   |      C18       |
@{*/
/** 16- and 32-bit Timer 1 capture, compare, or PWM 0 */
#define GPIO_AF_PL6_T1CCP0      GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pl7_values GPIO_AF_PL7 Values
 * @brief GPIO PL7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       93       |
 * NFBGA-212   |      B18       |
@{*/
/** 16- and 32-bit Timer 1 capture, compare, or PWM 1 */
#define GPIO_AF_PL7_T1CCP1      GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pm0_values GPIO_AF_PM0 Values
 * @brief GPIO PM0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       78       |
 * NFBGA-212   |      K18       |
@{*/
/** 16- and 32-bit Timer 2 capture, compare, or PWM 0 */
#define GPIO_AF_PM0_T2CCP0      GPIO_AF3
/** EPI module 0 signal 15 */
#define GPIO_AF_PM0_EPI0S15     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pm1_values GPIO_AF_PM1 Values
 * @brief GPIO PM1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       77       |
 * NFBGA-212   |      K19       |
@{*/
/** 16- and 32-bit Timer 2 capture, compare, or PWM 1 */
#define GPIO_AF_PM1_T2CCP1      GPIO_AF3
/** EPI module 0 signal 14 */
#define GPIO_AF_PM1_EPI0S14     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pm2_values GPIO_AF_PM2 Values
 * @brief GPIO PM2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       76       |
 * NFBGA-212   |      L18       |
@{*/
/** 16- and 32-bit Timer 3 capture, compare, or PWM 0 */
#define GPIO_AF_PM2_T3CCP0      GPIO_AF3
/** EPI module 0 signal 13 */
#define GPIO_AF_PM2_EPI0S13     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pm3_values GPIO_AF_PM3 Values
 * @brief GPIO PM3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       75       |
 * NFBGA-212   |      L19       |
@{*/
/** 16- and 32-bit Timer 3 capture, compare, or PWM 1 */
#define GPIO_AF_PM3_T3CCP1      GPIO_AF3
/** EPI module 0 signal 12 */
#define GPIO_AF_PM3_EPI0S12     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pm4_values GPIO_AF_PM4 Values
 * @brief GPIO PM4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       74       |
 * NFBGA-212   |      M18       |
@{*/
/** UART module 0 clear to send modem flow control input signal */
#define GPIO_AF_PM4_U0CTS       GPIO_AF1
/** 16- and 32-bit Timer 4 capture, compare, or PWM 0 */
#define GPIO_AF_PM4_T4CCP0      GPIO_AF3
/** Ethernet 0 reference clock */
#define GPIO_AF_PM4_EN0RREF_CLK GPIO_AF14
/**@}*/

/** @defgroup gpio_af_pm5_values GPIO_AF_PM5 Values
 * @brief GPIO PM5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       73       |
 * NFBGA-212   |      G15       |
@{*/
/** UART module 0 data carrier detect modem status input signal */
#define GPIO_AF_PM5_U0DCD       GPIO_AF1
/** 16- and 32-bit Timer 4 capture, compare, or PWM 1 */
#define GPIO_AF_PM5_T4CCP1      GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pm6_values GPIO_AF_PM6 Values
 * @brief GPIO PM6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       72       |
 * NFBGA-212   |      N19       |
@{*/
/** UART module 0 data set ready modem output control line */
#define GPIO_AF_PM6_U0DSR       GPIO_AF1
/** 16- and 32-bit Timer 5 capture, compare, or PWM 0 */
#define GPIO_AF_PM6_T5CCP0      GPIO_AF3
/** Ethernet 0 carrier sense */
#define GPIO_AF_PM6_EN0CRS      GPIO_AF14
/**@}*/

/** @defgroup gpio_af_pm7_values GPIO_AF_PM7 Values
 * @brief GPIO PM7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       71       |
 * NFBGA-212   |      N18       |
@{*/
/** UART module 0 ring indicator modem status input signal */
#define GPIO_AF_PM7_U0RI        GPIO_AF1
/** 16- and 32-bit Timer 5 capture, compare, or PWM 1 */
#define GPIO_AF_PM7_T5CCP1      GPIO_AF3
/** Ethernet 0 collision detect */
#define GPIO_AF_PM7_EN0COL      GPIO_AF14
/**@}*/

/** @defgroup gpio_af_pn0_values GPIO_AF_PN0 Values
 * @brief GPIO PN0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      107       |
 * NFBGA-212   |      C10       |
@{*/
/** UART module 1 request to send modem flow control output line */
#define GPIO_AF_PN0_U1RTS       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pn1_values GPIO_AF_PN1 Values
 * @brief GPIO PN1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      108       |
 * NFBGA-212   |      B11       |
@{*/
/** UART module 1 clear to send modem flow control input signal */
#define GPIO_AF_PN1_U1CTS       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pn2_values GPIO_AF_PN2 Values
 * @brief GPIO PN2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      109       |
 * NFBGA-212   |      A11       |
@{*/
/** UART module 1 data carrier detect modem status input signal */
#define GPIO_AF_PN2_U1DCD       GPIO_AF1
/** UART module 2 request to send modem flow control output line */
#define GPIO_AF_PN2_U2RTS       GPIO_AF2
/** EPI module 0 signal 29 */
#define GPIO_AF_PN2_EPI0S29     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pn3_values GPIO_AF_PN3 Values
 * @brief GPIO PN3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      110       |
 * NFBGA-212   |      B10       |
@{*/
/** UART module 1 data set ready modem output control line */
#define GPIO_AF_PN3_U1DSR       GPIO_AF1
/** UART module 2 clear to send modem flow control input signal */
#define GPIO_AF_PN3_U2CTS       GPIO_AF2
/** EPI module 0 signal 30 */
#define GPIO_AF_PN3_EPI0S30     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pn4_values GPIO_AF_PN4 Values
 * @brief GPIO PN4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      111       |
 * NFBGA-212   |      A10       |
@{*/
/** UART module 1 data terminal ready modem status input signal */
#define GPIO_AF_PN4_U1DTR       GPIO_AF1
/** UART module 3 request to send modem flow control output line */
#define GPIO_AF_PN4_U3RTS       GPIO_AF2
/** I2C module 2 data */
#define GPIO_AF_PN4_I2C2SDA     GPIO_AF3
/** EPI module 0 signal 34 */
#define GPIO_AF_PN4_EPI0S34     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pn5_values GPIO_AF_PN5 Values
 * @brief GPIO PN5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      112       |
 * NFBGA-212   |       B9       |
@{*/
/** UART module 1 ring indicator modem status input signal */
#define GPIO_AF_PN5_U1RI        GPIO_AF1
/** UART module 3 clear to send modem flow control input signal */
#define GPIO_AF_PN5_U3CTS       GPIO_AF2
/** I2C module 2 clock */
#define GPIO_AF_PN5_I2C2SCL     GPIO_AF3
/** EPI module 0 signal 35 */
#define GPIO_AF_PN5_EPI0S35     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pn6_values GPIO_AF_PN7 Values
 * @brief GPIO PN6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      T12       |
@{*/
/** UART module 4 request to send modem flow control output line */
#define GPIO_AF_PN6_U4RTS       GPIO_AF2
/** Ethernet 0 transmit error */
#define GPIO_AF_PN6_EN0TXER     GPIO_AF14
/** LCD data pin 13 input/output */
#define GPIO_AF_PN6_LCDDATA13   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pn7_values GPIO_AF_PN7 Values
 * @brief GPIO PN7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      U12       |
@{*/
/** UART module 1 request to send modem flow control output line */
#define GPIO_AF_PN7_U1RTS       GPIO_AF1
/** UART module 4 clear to send modem flow control input signal */
#define GPIO_AF_PN7_U4CTS       GPIO_AF2
/** LCD data pin 12 input/output */
#define GPIO_AF_PN7_LCDDATA12   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pp0_values GPIO_AF_PP0 Values
 * @brief GPIO PP0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      118       |
 * NFBGA-212   |       D6       |
@{*/
/** UART module 6 receive */
#define GPIO_AF_PP0_U6RX        GPIO_AF1
/** 16- and 32-bit Timer 6 capture, compare, or PWM 0 */
#define GPIO_AF_PP0_T6CCP0      GPIO_AF5
/** Ethernet 0 interrupt from the Ethernet PHY */
#define GPIO_AF_PP0_EN0INTRN    GPIO_AF7
/** SSI Module 3 bidirectional data pin 2 */
#define GPIO_AF_PP0_SSI3XDAT2   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pp1_values GPIO_AF_PP1 Values
 * @brief GPIO PP1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      119       |
 * NFBGA-212   |       D7       |
@{*/
/** UART module 6 transmit */
#define GPIO_AF_PP1_U6TX        GPIO_AF1
/** 16- and 32-bit Timer 6 capture, compare, or PWM 1 */
#define GPIO_AF_PP1_T6CCP1      GPIO_AF5
/** SSI Module 3 bidirectional data pin 3 */
#define GPIO_AF_PP1_SSI3XDAT3   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pp2_values GPIO_AF_PP2 Values
 * @brief GPIO PP2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      103       |
 * NFBGA-212   |      B13       |
@{*/
/** UART module 0 data terminal ready modem status input signal */
#define GPIO_AF_PP2_U0DTR       GPIO_AF1
/** USB Asserted by the external PHY to throttle all data types */
#define GPIO_AF_PP2_USB0NXT     GPIO_AF14
/** EPI module 0 signal 29 */
#define GPIO_AF_PP2_EPI0S29     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pp3_values GPIO_AF_PP3 Values
 * @brief GPIO PP3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      104       |
 * NFBGA-212   |      C12       |
@{*/
/** UART module 1 clear to send modem flow control input signal */
#define GPIO_AF_PP3_U1CTS       GPIO_AF1
/** UART module 0 data carrier detect modem status input signal */
#define GPIO_AF_PP3_U0DCD       GPIO_AF2
/** Buffered version of the 32.768-kHz clock of the Hibernation module */
#define GPIO_AF_PP3_RTCCLK      GPIO_AF7
/** USB Indicates that the external PHY is able to accept data
 *  from the USB controller */
#define GPIO_AF_PP3_USB0DIR     GPIO_AF14
/** EPI module 0 signal 30 */
#define GPIO_AF_PP3_EPI0S30     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pp4_values GPIO_AF_PP4 Values
 * @brief GPIO PP4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      105       |
 * NFBGA-212   |       D8       |
@{*/
/** UART module 3 request to send modem flow control output line */
#define GPIO_AF_PP4_U3RTS       GPIO_AF1
/** UART module 0 data set ready modem output control line */
#define GPIO_AF_PP4_U0DSR       GPIO_AF2
/** 1-Wire single bus pin */
#define GPIO_AF_PP4_OWIRE       GPIO_AF4
/** USB data 7 */
#define GPIO_AF_PP4_USB0D7      GPIO_AF14
/**@}*/

/** @defgroup gpio_af_pp5_values GPIO_AF_PP5 Values
 * @brief GPIO PP5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      106       |
 * NFBGA-212   |      B12       |
@{*/
/** UART module 3 clear to send modem flow control input signal */
#define GPIO_AF_PP5_U3CTS       GPIO_AF1
/** I2C module 2 clock */
#define GPIO_AF_PP5_I2C2SCL     GPIO_AF2
/** 1-Wire optional second signal to be used as output */
#define GPIO_AF_PP5_OWALT       GPIO_AF4
/** USB data 6 */
#define GPIO_AF_PP5_USB0D6      GPIO_AF14
/**@}*/

/** @defgroup gpio_af_pp6_values GPIO_AF_PP6 Values
 * @brief GPIO PP6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       B8       |
@{*/
/** UART module 1 data carrier detect modem status input signal */
#define GPIO_AF_PP6_U1DCD       GPIO_AF1
/** I2C module 2 data */
#define GPIO_AF_PP6_I2C2SDA     GPIO_AF2
/**@}*/

/** @defgroup gpio_af_pp7_values GPIO_AF_PP7 Values
 * @brief GPIO PP7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       A8       |
@{*/
/** 1-Wire single bus pin */
#define GPIO_AF_PP7_OWIRE       GPIO_AF5
/**@}*/

/** @defgroup gpio_af_pq0_values GPIO_AF_PQ0 Values
 * @brief GPIO PQ0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       5        |
 * NFBGA-212   |       E3       |
@{*/
/** 16- and 32-bit Timer 6 capture, compare, or PWM 0 */
#define GPIO_AF_PQ0_T6CCP0      GPIO_AF3
/** SSI module 3 clock */
#define GPIO_AF_PQ0_SSI3CLK     GPIO_AF14
/** EPI module 0 signal 20 */
#define GPIO_AF_PQ0_EPI0S20     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pq1_values GPIO_AF_PQ1 Values
 * @brief GPIO PQ1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       6        |
 * NFBGA-212   |       E2       |
@{*/
/** 16- and 32-bit Timer 6 capture, compare, or PWM 1 */
#define GPIO_AF_PQ1_T6CCP1      GPIO_AF3
/** SSI module 3 frame signal */
#define GPIO_AF_PQ1_SSI3FSS     GPIO_AF14
/** EPI module 0 signal 21 */
#define GPIO_AF_PQ1_EPI0S21     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pq2_values GPIO_AF_PQ2 Values
 * @brief GPIO PQ2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       11       |
 * NFBGA-212   |       H4       |
@{*/
/** 16- and 32-bit Timer 7 capture, compare, or PWM 0 */
#define GPIO_AF_PQ2_T7CCP0      GPIO_AF3
/** SSI Module 3 bidirectional data pin 0 */
#define GPIO_AF_PQ2_SSI3XDAT0   GPIO_AF14
/** EPI module 0 signal 22 */
#define GPIO_AF_PQ2_EPI0S22     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pq3_values GPIO_AF_PQ3 Values
 * @brief GPIO PQ3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |       27       |
 * NFBGA-212   |       M4       |
@{*/
/** 16- and 32-bit Timer 7 capture, compare, or PWM 1 */
#define GPIO_AF_PQ3_T7CCP1      GPIO_AF3
/** SSI Module 3 bidirectional data pin 1 */
#define GPIO_AF_PQ3_SSI3XDAT1   GPIO_AF14
/** EPI module 0 signal 23 */
#define GPIO_AF_PQ3_EPI0S23     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pq4_values GPIO_AF_PQ4 Values
 * @brief GPIO PQ4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |      102       |
 * NFBGA-212   |      A13       |
@{*/
/** UART module 1 receive */
#define GPIO_AF_PQ4_U1RX        GPIO_AF1
/** Divided reference clock output */
#define GPIO_AF_PQ4_DIVSCLK     GPIO_AF7
/**@}*/

/** @defgroup gpio_af_pq5_values GPIO_AF_PQ5 Values
 * @brief GPIO PQ5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      W12       |
@{*/
/** UART module 1 transmit */
#define GPIO_AF_PQ5_U1TX        GPIO_AF1
/** Ethernet 0 receive data 0 */
#define GPIO_AF_PQ5_EN0RXD0     GPIO_AF14
/**@}*/

/** @defgroup gpio_af_pq6_values GPIO_AF_PQ6 Values
 * @brief GPIO PQ6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      U15       |
@{*/
/** UART module 1 data terminal ready modem status input signal */
#define GPIO_AF_PQ6_U1DTR       GPIO_AF1
/** Ethernet 0 receive data 1 */
#define GPIO_AF_PQ6_EN0RXD1     GPIO_AF14
/**@}*/

/** @defgroup gpio_af_pq7_values GPIO_AF_PQ7 Values
 * @brief GPIO PQ7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       M3       |
@{*/
/** UART module 1 ring indicator modem status input signal */
#define GPIO_AF_PQ7_U1RI        GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pr0_values GPIO_AF_PR0 Values
 * @brief GPIO PR0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       N5       |
@{*/
/** UART module 4 transmit */
#define GPIO_AF_PR0_U4TX        GPIO_AF1
/** I2C module 1 clock */
#define GPIO_AF_PR0_I2C1SCL     GPIO_AF2
/** Motion control module 0 PWM 0 */
#define GPIO_AF_PR0_M0PWM0      GPIO_AF6
/** LCD pixel clock in raster mode */
#define GPIO_AF_PR0_LCDCP       GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pr1_values GPIO_AF_PR1 Values
 * @brief GPIO PR1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       N4       |
@{*/
/** UART module 4 receive */
#define GPIO_AF_PR1_U4RX        GPIO_AF1
/** I2C module 1 data */
#define GPIO_AF_PR1_I2C1SDA     GPIO_AF2
/** Motion control module 0 PWM 1 */
#define GPIO_AF_PR1_M0PWM1      GPIO_AF6
/** LCD frame clock or VSYNC in raster mode */
#define GPIO_AF_PR1_LCDFP       GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pr2_values GPIO_AF_PR2 Values
 * @brief GPIO PR2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       N2       |
@{*/
/** I2C module 2 clock */
#define GPIO_AF_PR2_I2C2SCL     GPIO_AF2
/** Motion control module 0 PWM 2 */
#define GPIO_AF_PR2_M0PWM2      GPIO_AF6
/** LCD line clock or HSYNC in raster mode */
#define GPIO_AF_PR2_LCDLP       GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pr3_values GPIO_AF_PR3 Values
 * @brief GPIO PR3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       V8       |
@{*/
/** I2C module 2 data */
#define GPIO_AF_PR3_I2C2SDA     GPIO_AF2
/** Motion control module 0 PWM 3 */
#define GPIO_AF_PR3_M0PWM3      GPIO_AF6
/** LCD data pin 3 input/output */
#define GPIO_AF_PR3_LCDDATA03   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pr4_values GPIO_AF_PR4 Values
 * @brief GPIO PR4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       P3       |
@{*/
/** I2C module 3 clock */
#define GPIO_AF_PR4_I2C3SCL     GPIO_AF2
/** 16- and 32-bit Timer 0 capture, compare, or PWM 0 */
#define GPIO_AF_PR4_T0CCP0      GPIO_AF3
/** Motion control module 0 PWM 4 */
#define GPIO_AF_PR4_M0PWM4      GPIO_AF6
/** LCD data pin 0 input/output */
#define GPIO_AF_PR4_LCDDATA00   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pr5_values GPIO_AF_PR5 Values
 * @brief GPIO PR5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       P2       |
@{*/
/** UART module 1 receive */
#define GPIO_AF_PR5_U1RX        GPIO_AF1
/** I2C module 3 data */
#define GPIO_AF_PR5_I2C3SDA     GPIO_AF2
/** 16- and 32-bit Timer 0 capture, compare, or PWM 1 */
#define GPIO_AF_PR5_T0CCP1      GPIO_AF3
/** Motion control module 0 PWM 5 */
#define GPIO_AF_PR5_M0PWM5      GPIO_AF6
/** LCD data pin 1 input/output */
#define GPIO_AF_PR5_LCDDATA01   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pr6_values GPIO_AF_PR6 Values
 * @brief GPIO PR6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       W9       |
@{*/
/** UART module 1 transmit */
#define GPIO_AF_PR6_U1TX        GPIO_AF1
/** I2C module 4 clock */
#define GPIO_AF_PR6_I2C4SCL     GPIO_AF2
/** 16- and 32-bit Timer 1 capture, compare, or PWM 0 */
#define GPIO_AF_PR6_T1CCP0      GPIO_AF3
/** Motion control module 0 PWM 6 */
#define GPIO_AF_PR6_M0PWM6      GPIO_AF6
/** LCD data pin 4 input/output */
#define GPIO_AF_PR6_LCDDATA04   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pr7_values GPIO_AF_PR7 Values
 * @brief GPIO PR7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      R10       |
@{*/
/** I2C module 4 data */
#define GPIO_AF_PR7_I2C4SDA     GPIO_AF2
/** 16- and 32-bit Timer 1 capture, compare, or PWM 1 */
#define GPIO_AF_PR7_T1CCP1      GPIO_AF3
/** Motion control module 0 PWM 7 */
#define GPIO_AF_PR7_M0PWM7      GPIO_AF6
/** Ethernet 0 transmit enable */
#define GPIO_AF_PR7_EN0TXEN     GPIO_AF14
/** LCD data pin 5 input/output */
#define GPIO_AF_PR7_LCDDATA05   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps0_values GPIO_AF_PS0 Values
 * @brief GPIO PS0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      D12       |
@{*/
/** 16- and 32-bit Timer 2 capture, compare, or PWM 0 */
#define GPIO_AF_PS0_T2CCP0      GPIO_AF3
/** Motion control module 0 PWM fault 0 */
#define GPIO_AF_PS0_M0FAULT0    GPIO_AF6
/** LCD data pin 20 output */
#define GPIO_AF_PS0_LCDDATA20   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps1_values GPIO_AF_PS1 Values
 * @brief GPIO PS1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      D13       |
@{*/
/** 16- and 32-bit Timer 2 capture, compare, or PWM 1 */
#define GPIO_AF_PS1_T2CCP1      GPIO_AF3
/** Motion control module 0 PWM fault 1 */
#define GPIO_AF_PS1_M0FAULT1    GPIO_AF6
/** LCD data pin 21 output */
#define GPIO_AF_PS1_LCDDATA21   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps2_values GPIO_AF_PS2 Values
 * @brief GPIO PS2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      B14       |
@{*/
/** UART module 1 data set ready modem output control line */
#define GPIO_AF_PS2_U1DSR       GPIO_AF1
/** 16- and 32-bit Timer 3 capture, compare, or PWM 0 */
#define GPIO_AF_PS2_T3CCP0      GPIO_AF3
/** Motion control module 0 PWM fault 2 */
#define GPIO_AF_PS2_M0FAULT2    GPIO_AF6
/** LCD data pin 22 output */
#define GPIO_AF_PS2_LCDDATA22   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps3_values GPIO_AF_PS3 Values
 * @brief GPIO PS3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      A14       |
@{*/
/** 16- and 32-bit Timer 3 capture, compare, or PWM 1 */
#define GPIO_AF_PS3_T3CCP1        GPIO_AF3
/** Motion control module 0 PWM fault 3 */
#define GPIO_AF_PS3_M0FAULT3      GPIO_AF6
/** LCD data pin 23 output */
#define GPIO_AF_PS3_LCDDATA23     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps4_values GPIO_AF_PS4 Values
 * @brief GPIO PS4 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |       V9       |
@{*/
/** 16- and 32-bit Timer 4 capture, compare, or PWM 0 */
#define GPIO_AF_PS4_T4CCP0      GPIO_AF3
/** QEI module 0 phase A */
#define GPIO_AF_PS4_PHA0        GPIO_AF6
/** Ethernet 0 transmit data 0 */
#define GPIO_AF_PS4_EN0TXD0     GPIO_AF14
/** LCD data pin 6 input/output */
#define GPIO_AF_PS4_LCDDATA06   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps5_values GPIO_AF_PS5 Values
 * @brief GPIO PS5 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      T13       |
@{*/
/** 16- and 32-bit Timer 4 capture, compare, or PWM 1 */
#define GPIO_AF_PS5_T4CCP1      GPIO_AF3
/** QEI module 0 phase B */
#define GPIO_AF_PS5_PHB0        GPIO_AF6
/** Ethernet 0 transmit data 1 */
#define GPIO_AF_PS5_EN0TXD1     GPIO_AF14
/** LCD data pin 7 input/output */
#define GPIO_AF_PS5_LCDDATA07   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps6_values GPIO_AF_PS6 Values
 * @brief GPIO PS6 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      U10       |
@{*/
/** 16- and 32-bit Timer 5 capture, compare, or PWM 0 */
#define GPIO_AF_PS6_T5CCP0      GPIO_AF3
/** QEI module 0 index */
#define GPIO_AF_PS6_IDX0        GPIO_AF6
/** Ethernet 0 receive error */
#define GPIO_AF_PS6_EN0RXER     GPIO_AF14
/** LCD data pin 8 input/output */
#define GPIO_AF_PS6_LCDDATA08   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps7_values GPIO_AF_PS7 Values
 * @brief GPIO PS7 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      R13       |
@{*/
/** 16- and 32-bit Timer 5 capture, compare, or PWM 1 */
#define GPIO_AF_PS7_T5CCP1      GPIO_AF3
/** Ethernet 0 receive data valid */
#define GPIO_AF_PS7_EN0RXDV     GPIO_AF14
/** LCD data pin 9 input/output */
#define GPIO_AF_PS7_LCDDATA09   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pt0_values GPIO_AF_PT0 Values
 * @brief GPIO PT0 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      W10       |
@{*/
/** 16- and 32-bit Timer 6 capture, compare, or PWM 0 */
#define GPIO_AF_PT0_T6CCP0      GPIO_AF3
/** CAN module 0 receive */
#define GPIO_AF_PT0_CAN0RX      GPIO_AF7
/** Ethernet 0 receive data 0 */
#define GPIO_AF_PT0_EN0RXD0     GPIO_AF14
/** LCD data pin 10 input/output */
#define GPIO_AF_PT0_LCDDATA10   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pt1_values GPIO_AF_PT1 Values
 * @brief GPIO PT1 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      V10       |
@{*/
/** 16- and 32-bit Timer 6 capture, compare, or PWM 1 */
#define GPIO_AF_PT1_T6CCP1      GPIO_AF3
/** CAN module 0 transmit */
#define GPIO_AF_PT1_CAN0TX      GPIO_AF7
/** Ethernet 0 receive data 1 */
#define GPIO_AF_PT1_EN0RXD1     GPIO_AF14
/** LCD data pin 11 input/output */
#define GPIO_AF_PT1_LCDDATA11   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pt2_values GPIO_AF_PT2 Values
 * @brief GPIO PT2 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      E18       |
@{*/
/** 16- and 32-bit Timer 7 capture, compare, or PWM 0 */
#define GPIO_AF_PT2_T7CCP0      GPIO_AF3
/** CAN module 1 receive */
#define GPIO_AF_PT2_CAN1RX      GPIO_AF7
/** LCD data pin 18 output */
#define GPIO_AF_PT2_LCDDATA18   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pt3_values GPIO_AF_PT3 Values
 * @brief GPIO PT3 Alternate Functions Values
 * Package     |   Pin number   |
 * ----------- | -------------- |
 * TQFP-128    |  Not available |
 * NFBGA-212   |      F17       |
@{*/
/** 16- and 32-bit Timer 7 capture, compare, or PWM 1 */
#define GPIO_AF_PT3_T7CCP1      GPIO_AF3
/** CAN module 1 transmit */
#define GPIO_AF_PT3_CAN1TX      GPIO_AF7
/** LCD data pin 19 output */
#define GPIO_AF_PT3_LCDDATA19   GPIO_AF15
/**@}*/

/** @brief GPIO Mode Definitions */
enum gpio_mode {
	GPIO_MODE_OUTPUT, /**< Configure pin as output */
	GPIO_MODE_INPUT, /**< Configure pin as input */
	GPIO_MODE_ANALOG /**< Configure pin as analog function */
};

/** @brief GPIO Pull-Up/Pull-Down Definitions */
enum gpio_pull_up_down {
	GPIO_PUPD_NONE, /**< Do not pull the pin high or low */
	GPIO_PUPD_PULLUP, /**< Pull the pin high */
	GPIO_PUPD_PULLDOWN, /**< Pull the pin low */
};

/** @brief GPIO Output Type Definitions */
enum gpio_output_type {
	GPIO_OTYPE_PP, /**< Push-pull configuration */
	GPIO_OTYPE_OD, /**< Open drain configuration */
};

/** @brief GPIO Drive Strength Definitions */
enum gpio_drive_strength {
	GPIO_DRIVE_2MA, /**< 2mA drive */
	GPIO_DRIVE_4MA, /**< 4mA drive */
	GPIO_DRIVE_6MA, /**< 6mA drive */
	GPIO_DRIVE_8MA, /**< 8mA drive */
	GPIO_DRIVE_10MA, /**< 10mA drive */
	GPIO_DRIVE_12MA /**< 12mA drive */
};

/** @brief GPIO Slew Control Definitions */
enum gpio_slew_ctl {
	GPIO_SLEW_CTL_ENABLE, /**< Slew rate control enable */
	GPIO_SLEW_CTL_DISABLE /**< Slew rate control disable */
};

/** @brief GPIO Trigger Level/Edge Definitions */
enum gpio_trigger {
	GPIO_TRIG_LVL_LOW, /**< Level trigger, signal low */
	GPIO_TRIG_LVL_HIGH, /**< Level trigger, signal high */
	GPIO_TRIG_EDGE_FALL, /**< Falling edge trigger */
	GPIO_TRIG_EDGE_RISE, /**< Rising edge trigger */
	GPIO_TRIG_EDGE_BOTH /**< Both edges trigger */
};

BEGIN_DECLS

void gpio_mode_setup(uint32_t gpioport, enum gpio_mode mode,
	enum gpio_pull_up_down pull_up_down, uint8_t gpios);
void gpio_set_output_options(uint32_t gpioport, enum gpio_output_type otype,
	enum gpio_drive_strength drive,
	enum gpio_slew_ctl slewctl,
	uint8_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint8_t gpios);
void gpio_configure_trigger(uint32_t gpioport, enum gpio_trigger trigger,
	uint8_t gpios);
void gpio_set(uint32_t gpioport, uint8_t gpios);
void gpio_clear(uint32_t gpioport, uint8_t gpios);
uint8_t gpio_get(uint32_t gpioport, uint8_t gpios);
void gpio_toggle(uint32_t gpioport, uint8_t gpios);
uint8_t gpio_port_read(uint32_t gpioport);
void gpio_port_write(uint32_t gpioport, uint8_t data);
void gpio_enable_interrupts(uint32_t gpioport, uint8_t gpios);
void gpio_disable_interrupts(uint32_t gpioport, uint8_t gpios);
void gpio_unlock_commit(uint32_t gpioport, uint8_t gpios);
uint8_t gpio_is_interrupt_source(uint32_t gpioport, uint8_t gpios);
void gpio_clear_interrupt_flag(uint32_t gpioport, uint8_t gpios);

END_DECLS

/**@}*/

#endif /* MSP432E4_GPIO_H */

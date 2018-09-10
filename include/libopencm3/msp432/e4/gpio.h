/** @defgroup gpio_defines General Purpose I/O Defines
 *
 * @ingroup MSP432E4xx_defines
 *
 * @brief Defined Constants and Types for the MSP432E4 General Purpose I/O
 *
 * @version 1.0.0
 *
 * @date 22 July 2018
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

/** @defgroup gpio_reg_base GPIO register base addresses
 *@{*/
#define GPIOA               GPIOA_BASE
#define GPIOB               GPIOB_BASE
#define GPIOC               GPIOC_BASE
#define GPIOD               GPIOD_BASE
#define GPIOE               GPIOE_BASE
#define GPIOF               GPIOF_BASE
#define GPIOG               GPIOG_BASE
#define GPIOH               GPIOH_BASE
#define GPIOJ               GPIOJ_BASE
#define GPIOK               GPIOK_BASE
#define GPIOL               GPIOL_BASE
#define GPIOM               GPIOM_BASE
#define GPION               GPION_BASE
#define GPIOP               GPIOP_BASE
#define GPIOQ               GPIOQ_BASE
/**@}*/

/** @defgroup gpio_pin_id GPIO pin identifiers
 * @{*/
#define GPIO0                   (1 << 0)
#define GPIO1                   (1 << 1)
#define GPIO2                   (1 << 2)
#define GPIO3                   (1 << 3)
#define GPIO4                   (1 << 4)
#define GPIO5                   (1 << 5)
#define GPIO6                   (1 << 6)
#define GPIO7                   (1 << 7)
#define GPIO_ALL                (0xFF)
/** @} */

#define GPIO_AF1                0x1
#define GPIO_AF2                0x2
#define GPIO_AF3                0x3
#define GPIO_AF4                0x4
#define GPIO_AF5                0x5
#define GPIO_AF6                0x6
#define GPIO_AF7                0x7
#define GPIO_AF8                0x8
#define GPIO_AF11               0xB
#define GPIO_AF13               0xD
#define GPIO_AF14               0xE
#define GPIO_AF15               0xF
#define GPIO_AF_ALL             0xF

/* Остановился на PM4 (вывод M18, страница 18) */

/** @defgroup gpio_registers GPIO Registers
 *  @brief GPIO Registers
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
/** GPIO Wake Pin Enable */
#define GPIO_WAKEPEN(port)      MMIO32((port) + 0x540)
/** GPIO Wake Level */
#define GPIO_WAKELVL(port)      MMIO32((port) + 0x544)
/** GPIO Wake Status */
#define GPIO_WAKESTAT(port)     MMIO32((port) + 0x548)
/** GPIO Peripheral Property */
#define GPIO_PP(port)           MMIO32((port) + 0xFC0)
/** GPIO Peripheral Configuration */
#define GPIO_PC(port)           MMIO32((port) + 0xFC4)

/** GPIO Peripheral Identification 0 */
#define GPIO_PERIPH_ID0(port)       MMIO32((port) + 0xFE0)
/** GPIO Peripheral Identification 1 */
#define GPIO_PERIPH_ID1(port)       MMIO32((port) + 0xFE4)
/** GPIO Peripheral Identification 2 */
#define GPIO_PERIPH_ID2(port)       MMIO32((port) + 0xFE8)
/** GPIO Peripheral Identification 3 */
#define GPIO_PERIPH_ID3(port)       MMIO32((port) + 0xFEC)
/** GPIO Peripheral Identification 4 */
#define GPIO_PERIPH_ID4(port)       MMIO32((port) + 0xFD0)
/** GPIO Peripheral Identification 5 */
#define GPIO_PERIPH_ID5(port)       MMIO32((port) + 0xFD4)
/** GPIO Peripheral Identification 6 */
#define GPIO_PERIPH_ID6(port)       MMIO32((port) + 0xFD8)
/** GPIO Peripheral Identification 7 */
#define GPIO_PERIPH_ID7(port)       MMIO32((port) + 0xFDC)

/** GPIO PrimeCell Identification 0 */
#define GPIO_PCELL_ID0(port)        MMIO32((port) + 0xFF0)
/** GPIO PrimeCell Identification 1 */
#define GPIO_PCELL_ID1(port)        MMIO32((port) + 0xFF4)
/** GPIO PrimeCell Identification 2 */
#define GPIO_PCELL_ID2(port)        MMIO32((port) + 0xFF8)
/** GPIO PrimeCell Identification 3 */
#define GPIO_PCELL_ID3(port)        MMIO32((port) + 0xFFC)
/**@}*/

/** @defgroup gpio_af_pa0_values GPIO_AF_PA0 Values
 * @brief GPIO PA0 Alternate Functions Values
@{*/
#define GPIO_AF_PA0_U0RX        GPIO_AF1
#define GPIO_AF_PA0_I2C9SCL     GPIO_AF2
#define GPIO_AF_PA0_T0CCP0      GPIO_AF3
#define GPIO_AF_PA0_CAN0RX      GPIO_AF7
/**@}*/

/** @defgroup gpio_af_pa1_values GPIO_AF_PA1 Values
 * @brief GPIO PA1 Alternate Functions Values
@{*/
#define GPIO_AF_PA1_U0TX        GPIO_AF1
#define GPIO_AF_PA1_I2C9SDA     GPIO_AF2
#define GPIO_AF_PA1_T0CCP1      GPIO_AF3
#define GPIO_AF_PA1_CAN0TX      GPIO_AF7
/**@}*/

/** @defgroup gpio_af_pa2_values GPIO_AF_PA2 Values
 * @brief GPIO PA2 Alternate Functions Values
@{*/
#define GPIO_AF_PA2_U4RX        GPIO_AF1
#define GPIO_AF_PA2_I2C8SCL     GPIO_AF2
#define GPIO_AF_PA2_T1CCP0      GPIO_AF3
#define GPIO_AF_PA2_SSI0CLK     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pa3_values GPIO_AF_PA3 Values
 * @brief GPIO PA3 Alternate Functions Values
@{*/
#define GPIO_AF_PA3_U4TX        GPIO_AF1
#define GPIO_AF_PA3_I2C8SDA     GPIO_AF2
#define GPIO_AF_PA3_T1CCP1      GPIO_AF3
#define GPIO_AF_PA3_SSI0FSS     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pa4_values GPIO_AF_PA4 Values
 * @brief GPIO PA4 Alternate Functions Values
@{*/
#define GPIO_AF_PA4_U3RX        GPIO_AF1
#define GPIO_AF_PA4_I2C7SCL     GPIO_AF2
#define GPIO_AF_PA4_T2CCP0      GPIO_AF3
#define GPIO_AF_PA4_SSI0XDAT0   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pa5_values GPIO_AF_PA5 Values
 * @brief GPIO PA5 Alternate Functions Values
@{*/
#define GPIO_AF_PA5_U3TX        GPIO_AF1
#define GPIO_AF_PA5_I2C7SDA     GPIO_AF2
#define GPIO_AF_PA5_T2CCP1      GPIO_AF3
#define GPIO_AF_PA5_SSI0XDAT1   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pa6_values GPIO_AF_PA6 Values
 * @brief GPIO PA6 Alternate Functions Values
@{*/
#define GPIO_AF_PA6_U2RX        GPIO_AF1
#define GPIO_AF_PA6_I2C6SCL     GPIO_AF2
#define GPIO_AF_PA6_T3CCP0      GPIO_AF3
#define GPIO_AF_PA6_USB0EPEN    GPIO_AF5
#define GPIO_AF_PA6_SSI0XDAT2   GPIO_AF13
#define GPIO_AF_PA6_EPI0S8      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pa7_values GPIO_AF_PA7 Values
 * @brief GPIO PA7 Alternate Functions Values
@{*/
#define GPIO_AF_PA7_U2Tx        GPIO_AF1
#define GPIO_AF_PA7_I2C6SDA     GPIO_AF2
#define GPIO_AF_PA7_T3CCP1      GPIO_AF3
#define GPIO_AF_PA7_USB0PFLT    GPIO_AF5
#define GPIO_AF_PA7_USB0EPEN    GPIO_AF11
#define GPIO_AF_PA7_SSI0XDAT3   GPIO_AF13
#define GPIO_AF_PA7_EPI0S9      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pb0_values GPIO_AF_PB0 Values
 * @brief GPIO PB0 Alternate Functions Values
@{*/
#define GPIO_AF_PB0_U1RX        GPIO_AF1
#define GPIO_AF_PB0_I2C5SCL     GPIO_AF2
#define GPIO_AF_PB0_T4CCP0      GPIO_AF3
#define GPIO_AF_PB0_CAN1RX      GPIO_AF7
/**@}*/

/** @defgroup gpio_af_pb1_values GPIO_AF_PB1 Values
 * @brief GPIO PB1 Alternate Functions Values
@{*/
#define GPIO_AF_PB1_U1TX        GPIO_AF1
#define GPIO_AF_PB1_I2C5SDA     GPIO_AF2
#define GPIO_AF_PB1_T4CCP1      GPIO_AF3
#define GPIO_AF_PB1_CAN1TX      GPIO_AF7
/**@}*/

/** @defgroup gpio_af_pb2_values GPIO_AF_PB2 Values
 * @brief GPIO PB2 Alternate Functions Values
@{*/
#define GPIO_AF_PB2_I2C0SCL     GPIO_AF2
#define GPIO_AF_PB2_T5CCP0      GPIO_AF3
#define GPIO_AF_PB2_EN0MDC      GPIO_AF5
#define GPIO_AF_PB2_USB0STP     GPIO_AF14
#define GPIO_AF_PB2_EPI0S27     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pb3_values GPIO_AF_PB3 Values
 * @brief GPIO PB3 Alternate Functions Values
@{*/
#define GPIO_AF_PB3_I2C0SDA     GPIO_AF2
#define GPIO_AF_PB3_T5CCP1      GPIO_AF3
#define GPIO_AF_PB3_EN0MDIO     GPIO_AF5
#define GPIO_AF_PB3_USB0CLK     GPIO_AF14
#define GPIO_AF_PB3_EPI0S28     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pb4_values GPIO_AF_PB4 Values
 * @brief GPIO PB4 Alternate Functions Values
@{*/
#define GPIO_AF_PB4_U0CTS       GPIO_AF1
#define GPIO_AF_PB4_I2C5SCL     GPIO_AF2
#define GPIO_AF_PB4_SSI1FSS     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pb5_values GPIO_AF_PB5 Values
 * @brief GPIO PB5 Alternate Functions Values
@{*/
#define GPIO_AF_PB5_U0RTS       GPIO_AF1
#define GPIO_AF_PB5_I2C5SDA     GPIO_AF2
#define GPIO_AF_PB5_SSI1CLK     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pb7_values GPIO_AF_PB7 Values
 * @brief GPIO PB7 Alternate Functions Values
@{*/
#define GPIO_AF_PB7_I2C6SDA       GPIO_AF1
#define GPIO_AF_PB7_T6CCP1        GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pc0_values GPIO_AF_PC0 Values
 * @brief GPIO PC0 Alternate Functions Values
@{*/
#define GPIO_AF_PC0_TCK         GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pc1_values GPIO_AF_PC1 Values
 * @brief GPIO PC1 Alternate Functions Values
@{*/
#define GPIO_AF_PC1_TMS         GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pc2_values GPIO_AF_PC2 Values
 * @brief GPIO PC2 Alternate Functions Values
@{*/
#define GPIO_AF_PC2_TDI         GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pc3_values GPIO_AF_PC3 Values
 * @brief GPIO PC3 Alternate Functions Values
@{*/
#define GPIO_AF_PC3_TDO         GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pc4_values GPIO_AF_PC4 Values
 * @brief GPIO PC4 Alternate Functions Values
@{*/
#define GPIO_AF_PC4_U7RX        GPIO_AF1
#define GPIO_AF_PC4_T7CCP0      GPIO_AF3
#define GPIO_AF_PC4_EPI0S7      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pc5_values GPIO_AF_PC5 Values
 * @brief GPIO PC5 Alternate Functions Values
@{*/
#define GPIO_AF_PC5_U7TX        GPIO_AF1
#define GPIO_AF_PC5_T7CCP1      GPIO_AF3
#define GPIO_AF_PC5_RTCCLK      GPIO_AF7
#define GPIO_AF_PC5_EPI0S6      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pc6_values GPIO_AF_PC6 Values
 * @brief GPIO PC6 Alternate Functions Values
@{*/
#define GPIO_AF_PC6_U5RX        GPIO_AF1
#define GPIO_AF_PC6_EPI0S5      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pc7_values GPIO_AF_PC7 Values
 * @brief GPIO PC7 Alternate Functions Values
@{*/
#define GPIO_AF_PC7_U5TX        GPIO_AF1
#define GPIO_AF_PC7_EPI0S4      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd0_values GPIO_AF_PD0 Values
 * @brief GPIO PD0 Alternate Functions Values
@{*/
#define GPIO_AF_PD0_I2C7SCL     GPIO_AF2
#define GPIO_AF_PD0_T0CCP0      GPIO_AF3
#define GPIO_AF_PD0_C0O         GPIO_AF5
#define GPIO_AF_PD0_SSI2XDAT1   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd1_values GPIO_AF_PD1 Values
 * @brief GPIO PD1 Alternate Functions Values
@{*/
#define GPIO_AF_PD1_I2C7SDA     GPIO_AF2
#define GPIO_AF_PD1_T0CCP1      GPIO_AF3
#define GPIO_AF_PD1_C1O         GPIO_AF5
#define GPIO_AF_PD1_SSI2XDAT0   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd2_values GPIO_AF_PD2 Values
 * @brief GPIO PD2 Alternate Functions Values
@{*/
#define GPIO_AF_PD2_I2C8SCL     GPIO_AF2
#define GPIO_AF_PD2_T1CCP0      GPIO_AF3
#define GPIO_AF_PD2_C2O         GPIO_AF5
#define GPIO_AF_PD2_SSI2FSS     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd3_values GPIO_AF_PD3 Values
 * @brief GPIO PD3 Alternate Functions Values
@{*/
#define GPIO_AF_PD3_I2C8SDA     GPIO_AF2
#define GPIO_AF_PD3_T1CCP1      GPIO_AF3
#define GPIO_AF_PD3_SSI2CLK     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd4_values GPIO_AF_PD4 Values
 * @brief GPIO PD4 Alternate Functions Values
@{*/
#define GPIO_AF_PD4_U2RX        GPIO_AF1
#define GPIO_AF_PD4_T3CCP0      GPIO_AF3
#define GPIO_AF_PD4_SSI1XDAT2   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd5_values GPIO_AF_PD5 Values
 * @brief GPIO PD5 Alternate Functions Values
@{*/
#define GPIO_AF_PD5_U2TX        GPIO_AF1
#define GPIO_AF_PD5_T3CCP1      GPIO_AF3
#define GPIO_AF_PD5_SSI1XDAT3   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd6_values GPIO_AF_PD6 Values
 * @brief GPIO PD6 Alternate Functions Values
@{*/
#define GPIO_AF_PD6_U2RTS       GPIO_AF1
#define GPIO_AF_PD6_T4CCP0      GPIO_AF3
#define GPIO_AF_PD6_USB0EPEN    GPIO_AF5
#define GPIO_AF_PD6_SSI2XDAT3   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pd7_values GPIO_AF_PD7 Values
 * @brief GPIO PD7 Alternate Functions Values
@{*/
#define GPIO_AF_PD7_U2CTS       GPIO_AF1
#define GPIO_AF_PD7_T4CCP1      GPIO_AF3
#define GPIO_AF_PD7_USB0PFLT    GPIO_AF5
#define GPIO_AF_PD7_NMI         GPIO_AF8
#define GPIO_AF_PD7_SSI2XDAT2   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pe0_values GPIO_AF_PE0 Values
 * @brief GPIO PE0 Alternate Functions Values
@{*/
#define GPIO_AF_PE0_U1RTS       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pe1_values GPIO_AF_PE1 Values
 * @brief GPIO PE1 Alternate Functions Values
@{*/
#define GPIO_AF_PE1_U1DSR       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pe2_values GPIO_AF_PE2 Values
 * @brief GPIO PE2 Alternate Functions Values
@{*/
#define GPIO_AF_PE2_U1DCD       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pe3_values GPIO_AF_PE3 Values
 * @brief GPIO PE3 Alternate Functions Values
@{*/
#define GPIO_AF_PE3_U1DTR       GPIO_AF1
#define GPIO_AF_PE3_OWIRE       GPIO_AF5
/**@}*/

/** @defgroup gpio_af_pe4_values GPIO_AF_PE4 Values
 * @brief GPIO PE4 Alternate Functions Values
@{*/
#define GPIO_AF_PE4_U1RI        GPIO_AF1
#define GPIO_AF_PE4_SSI1XDAT0   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pe5_values GPIO_AF_PE5 Values
 * @brief GPIO PE5 Alternate Functions Values
@{*/
#define GPIO_AF_PE5_SSI1XDAT1   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pe6_values GPIO_AF_PE6 Values
 * @brief GPIO PE6 Alternate Functions Values
@{*/
#define GPIO_AF_PE6_U0CTS       GPIO_AF1
#define GPIO_AF_PE6_I2C9SCL     GPIO_AF2
/**@}*/

/** @defgroup gpio_af_pe7_values GPIO_AF_PE7 Values
 * @brief GPIO PE7 Alternate Functions Values
@{*/
#define GPIO_AF_PE7_U0RTS       GPIO_AF1
#define GPIO_AF_PE7_I2C9SDA     GPIO_AF2
#define GPIO_AF_PE7_NMI         GPIO_AF8
/**@}*/

/** @defgroup gpio_af_pf0_values GPIO_AF_PF0 Values
 * @brief GPIO PF0 Alternate Functions Values
@{*/
#define GPIO_AF_PF0_EN0LED      GPIO_AF5
#define GPIO_AF_PF0_M0PWM0      GPIO_AF6
#define GPIO_AF_PF0_SSI3XDAT1   GPIO_AF14
#define GPIO_AF_PF0_TRD2        GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pf1_values GPIO_AF_PF1 Values
 * @brief GPIO PF1 Alternate Functions Values
@{*/
#define GPIO_AF_PF1_EN0LED2     GPIO_AF5
#define GPIO_AF_PF1_M0PWM1      GPIO_AF6
#define GPIO_AF_PF1_SSI3XDAT0   GPIO_AF14
#define GPIO_AF_PF1_TRD1        GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pf2_values GPIO_AF_PF2 Values
 * @brief GPIO PF2 Alternate Functions Values
@{*/
#define GPIO_AF_PF2_M0PWM2      GPIO_AF6
#define GPIO_AF_PF2_SSI3FSS     GPIO_AF14
#define GPIO_AF_PF2_TRD0        GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pf3_values GPIO_AF_PF3 Values
 * @brief GPIO PF3 Alternate Functions Values
@{*/
#define GPIO_AF_PF3_M0PWM3      GPIO_AF6
#define GPIO_AF_PF3_SSI3CLK     GPIO_AF14
#define GPIO_AF_PF3_TRCLK       GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pf4_values GPIO_AF_PF4 Values
 * @brief GPIO PF4 Alternate Functions Values
@{*/
#define GPIO_AF_PF4_EN0LED1     GPIO_AF5
#define GPIO_AF_PF4_M0FAULT0    GPIO_AF6
#define GPIO_AF_PF4_SSI3XDAT2   GPIO_AF14
#define GPIO_AF_PF4_TRD3        GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg0_values GPIO_AF_PG0 Values
 * @brief GPIO PG0 Alternate Functions Values
@{*/
#define GPIO_AF_PG0_I2C1SCL     GPIO_AF2
#define GPIO_AF_PG0_EN0PPS      GPIO_AF5
#define GPIO_AF_PG0_M0PWM4      GPIO_AF6
#define GPIO_AF_PG0_EPI0S11     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg1_values GPIO_AF_PG1 Values
 * @brief GPIO PG1 Alternate Functions Values
@{*/
#define GPIO_AF_PG1_I2C1SDA     GPIO_AF2
#define GPIO_AF_PG1_M0PWM5      GPIO_AF6
#define GPIO_AF_PG1_EPI0S10     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg3_values GPIO_AF_PG3 Values
 * @brief GPIO PG3 Alternate Functions Values
@{*/
#define GPIO_AF_PG3_I2C2SDA     GPIO_AF2
#define GPIO_AF_PG3_EN0TXEN     GPIO_AF14
#define GPIO_AF_PG3_SSI2XDAT2   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg5_values GPIO_AF_PG5 Values
 * @brief GPIO PG5 Alternate Functions Values
@{*/
#define GPIO_AF_PG4_U0CTS       GPIO_AF1
#define GPIO_AF_PG4_I2C3SCL     GPIO_AF2
#define GPIO_AF_PG4_OWIRE       GPIO_AF5
#define GPIO_AF_PG4_EN0TXD0     GPIO_AF14
#define GPIO_AF_PG4_SSI2XDAT1   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pg5_values GPIO_AF_PG5 Values
 * @brief GPIO PG5 Alternate Functions Values
@{*/
#define GPIO_AF_PG5_U0RTS       GPIO_AF1
#define GPIO_AF_PG5_I2C3SDA     GPIO_AF2
#define GPIO_AF_PG5_OWALT       GPIO_AF5
#define GPIO_AF_PG5_EN0TXD1     GPIO_AF14
#define GPIO_AF_PG5_SSI2XDAT0   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ph0_values GPIO_AF_PH0 Values
 * @brief GPIO PH0 Alternate Functions Values
@{*/
#define GPIO_AF_PH0_U0RTS       GPIO_AF1
#define GPIO_AF_PH0_EPI0S0      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ph1_values GPIO_AF_PH1 Values
 * @brief GPIO PH1 Alternate Functions Values
@{*/
#define GPIO_AF_PH1_U0CTS       GPIO_AF1
#define GPIO_AF_PH1_EPI0S1      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ph2_values GPIO_AF_PH2 Values
 * @brief GPIO PH2 Alternate Functions Values
@{*/
#define GPIO_AF_PH2_U0DCD       GPIO_AF1
#define GPIO_AF_PH2_EPI0S2      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ph3_values GPIO_AF_PH3 Values
 * @brief GPIO PH3 Alternate Functions Values
@{*/
#define GPIO_AF_PH3_U0DSR       GPIO_AF1
#define GPIO_AF_PH3_EPI0S3      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pj0_values GPIO_AF_PJ0 Values
 * @brief GPIO PJ0 Alternate Functions Values
@{*/
#define GPIO_AF_PJ0_U3RX        GPIO_AF1
#define GPIO_AF_PJ0_EN0PPS      GPIO_AF5
/**@}*/

/** @defgroup gpio_af_pj1_values GPIO_AF_PJ1 Values
 * @brief GPIO PJ1 Alternate Functions Values
@{*/
#define GPIO_AF_PJ1_U3TX        GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pj2_values GPIO_AF_PJ2 Values
 * @brief GPIO PJ2 Alternate Functions Values
@{*/
#define GPIO_AF_PJ2_U2RTS       GPIO_AF1
#define GPIO_AF_PJ2_LCDDATA14   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pj3_values GPIO_AF_PJ3 Values
 * @brief GPIO PJ3 Alternate Functions Values
@{*/
#define GPIO_AF_PJ3_U2CTS       GPIO_AF1
#define GPIO_AF_PJ3_LCDDATA15   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pj4_values GPIO_AF_PJ4 Values
 * @brief GPIO PJ4 Alternate Functions Values
@{*/
#define GPIO_AF_PJ4_U3RTS       GPIO_AF1
#define GPIO_AF_PJ4_LCDDATA16   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pj5_values GPIO_AF_PJ5 Values
 * @brief GPIO PJ5 Alternate Functions Values
@{*/
#define GPIO_AF_PJ5_U3CTS       GPIO_AF1
#define GPIO_AF_PJ5_LCDDATA17   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pj7_values GPIO_AF_PJ7 Values
 * @brief GPIO PJ7 Alternate Functions Values
@{*/
#define GPIO_AF_PJ7_U4CTS       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pk0_values GPIO_AF_PK0 Values
 * @brief GPIO PK0 Alternate Functions Values
@{*/
#define GPIO_AF_PK0_U4RX        GPIO_AF1
#define GPIO_AF_PK0_EPI0S0      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk1_values GPIO_AF_PK1 Values
 * @brief GPIO PK1 Alternate Functions Values
@{*/
#define GPIO_AF_PK1_U4TX        GPIO_AF1
#define GPIO_AF_PK1_EPI0S1      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk2_values GPIO_AF_PK2 Values
 * @brief GPIO PK2 Alternate Functions Values
@{*/
#define GPIO_AF_PK2_U4RTS       GPIO_AF1
#define GPIO_AF_PK2_EPI0S2      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk3_values GPIO_AF_PK3 Values
 * @brief GPIO PK3 Alternate Functions Values
@{*/
#define GPIO_AF_PK3_U4CTS       GPIO_AF1
#define GPIO_AF_PK3_EPI0S3      GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk4_values GPIO_AF_PK4 Values
 * @brief GPIO PK4 Alternate Functions Values
@{*/
#define GPIO_AF_PK4_I2C3SCL     GPIO_AF2
#define GPIO_AF_PK4_EN0LED0     GPIO_AF5
#define GPIO_AF_PK4_M0PWM6      GPIO_AF6
#define GPIO_AF_PK4_EPI0S32     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk5_values GPIO_AF_PK5 Values
 * @brief GPIO PK5 Alternate Functions Values
@{*/
#define GPIO_AF_PK5_I2C3SDA     GPIO_AF2
#define GPIO_AF_PK5_EN0LED2     GPIO_AF5
#define GPIO_AF_PK5_M0PWM7      GPIO_AF6
#define GPIO_AF_PK5_EPI0S31     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk6_values GPIO_AF_PK6 Values
 * @brief GPIO PK6 Alternate Functions Values
@{*/
#define GPIO_AF_PK6_I2C4SCL     GPIO_AF2
#define GPIO_AF_PK6_EN0LED1     GPIO_AF5
#define GPIO_AF_PK6_M0FAULT1    GPIO_AF6
#define GPIO_AF_PK6_EPI0S25     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pk7_values GPIO_AF_PK7 Values
 * @brief GPIO PK7 Alternate Functions Values
@{*/
#define GPIO_AF_PK7_U0RI        GPIO_AF1
#define GPIO_AF_PK7_I2C4SDA     GPIO_AF2
#define GPIO_AF_PK7_RTCCLK      GPIO_AF5
#define GPIO_AF_PK7_M0FAULT2    GPIO_AF6
#define GPIO_AF_PK7_EPI0S24     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl0_values GPIO_AF_PL0 Values
 * @brief GPIO PL0 Alternate Functions Values
@{*/
#define GPIO_AF_PL0_I2C2SDA     GPIO_AF2
#define GPIO_AF_PL0_M0FAULT3    GPIO_AF6
#define GPIO_AF_PL0_USB0D0      GPIO_AF14
#define GPIO_AF_PL0_EPI0S16     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl1_values GPIO_AF_PL1 Values
 * @brief GPIO PL1 Alternate Functions Values
@{*/
#define GPIO_AF_PL1_I2C2SCL     GPIO_AF2
#define GPIO_AF_PL1_PHA0        GPIO_AF6
#define GPIO_AF_PL1_USB0D1      GPIO_AF14
#define GPIO_AF_PL1_EPI0S17     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl2_values GPIO_AF_PL2 Values
 * @brief GPIO PL2 Alternate Functions Values
@{*/
#define GPIO_AF_PL2_C0O         GPIO_AF5
#define GPIO_AF_PL2_PHB0        GPIO_AF6
#define GPIO_AF_PL2_USB0D2      GPIO_AF14
#define GPIO_AF_PL2_EPI0S18     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl3_values GPIO_AF_PL3 Values
 * @brief GPIO PL3 Alternate Functions Values
@{*/
#define GPIO_AF_PL3_C1O         GPIO_AF5
#define GPIO_AF_PL3_IDX0        GPIO_AF6
#define GPIO_AF_PL3_USB0D3      GPIO_AF14
#define GPIO_AF_PL3_EPI0S19     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl4_values GPIO_AF_PL4 Values
 * @brief GPIO PL4 Alternate Functions Values
@{*/
#define GPIO_AF_PL4_T0CCP0      GPIO_AF3
#define GPIO_AF_PL4_USB0D4      GPIO_AF14
#define GPIO_AF_PL4_EPI0S26     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl5_values GPIO_AF_PL5 Values
 * @brief GPIO PL5 Alternate Functions Values
@{*/
#define GPIO_AF_PL5_T0CCP1      GPIO_AF3
#define GPIO_AF_PL5_USB0D5      GPIO_AF14
#define GPIO_AF_PL5_EPI0S33     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pl6_values GPIO_AF_PL6 Values
 * @brief GPIO PL6 Alternate Functions Values
@{*/
#define GPIO_AF_PL6_T1CCP0      GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pl7_values GPIO_AF_PL7 Values
 * @brief GPIO PL7 Alternate Functions Values
@{*/
#define GPIO_AF_PL7_T1CCP1      GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pm0_values GPIO_AF_PM0 Values
 * @brief GPIO PM0 Alternate Functions Values
@{*/
#define GPIO_AF_PM0_T2CCP0      GPIO_AF3
#define GPIO_AF_PM0_EPI0S15     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pm1_values GPIO_AF_PM1 Values
 * @brief GPIO PM1 Alternate Functions Values
@{*/
#define GPIO_AF_PM1_T2CCP1      GPIO_AF3
#define GPIO_AF_PM1_EPI0S14     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pm2_values GPIO_AF_PM2 Values
 * @brief GPIO PM2 Alternate Functions Values
@{*/
#define GPIO_AF_PM2_T3CCP0      GPIO_AF3
#define GPIO_AF_PM2_EPI0S13     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pm3_values GPIO_AF_PM3 Values
 * @brief GPIO PM3 Alternate Functions Values
@{*/
#define GPIO_AF_PM3_T3CCP1      GPIO_AF3
#define GPIO_AF_PM3_EPI0S12     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pm4_values GPIO_AF_PM4 Values
 * @brief GPIO PM4 Alternate Functions Values
@{*/
#define GPIO_AF_PM4_U0CTS       GPIO_AF1
#define GPIO_AF_PM4_T4CCP0      GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pm5_values GPIO_AF_PM5 Values
 * @brief GPIO PM5 Alternate Functions Values
@{*/
#define GPIO_AF_PM5_U0DCD       GPIO_AF1
#define GPIO_AF_PM5_T4CCP1      GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pm6_values GPIO_AF_PM6 Values
 * @brief GPIO PM6 Alternate Functions Values
@{*/
#define GPIO_AF_PM6_U0DSR       GPIO_AF1
#define GPIO_AF_PM6_T5CCP0      GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pm7_values GPIO_AF_PM7 Values
 * @brief GPIO PM7 Alternate Functions Values
@{*/
#define GPIO_AF_PM7_U0RI        GPIO_AF1
#define GPIO_AF_PM7_T5CCP1      GPIO_AF3
/**@}*/

/** @defgroup gpio_af_pn0_values GPIO_AF_PN0 Values
 * @brief GPIO PN0 Alternate Functions Values
@{*/
#define GPIO_AF_PN0_U1RTS       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pn1_values GPIO_AF_PN1 Values
 * @brief GPIO PN1 Alternate Functions Values
@{*/
#define GPIO_AF_PN1_U1CTS       GPIO_AF1
/**@}*/

/** @defgroup gpio_af_pn2_values GPIO_AF_PN2 Values
 * @brief GPIO PN2 Alternate Functions Values
@{*/
#define GPIO_AF_PN2_U1DCD       GPIO_AF1
#define GPIO_AF_PN2_U2RTS       GPIO_AF2
#define GPIO_AF_PN2_EPI0S29     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pn3_values GPIO_AF_PN3 Values
 * @brief GPIO PN3 Alternate Functions Values
@{*/
#define GPIO_AF_PN3_U1DSR       GPIO_AF1
#define GPIO_AF_PN3_U2CTS       GPIO_AF2
#define GPIO_AF_PN3_EPI0S30     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pn4_values GPIO_AF_PN4 Values
 * @brief GPIO PN4 Alternate Functions Values
@{*/
#define GPIO_AF_PN4_U1DTR       GPIO_AF1
#define GPIO_AF_PN4_U3RTS       GPIO_AF2
#define GPIO_AF_PN4_I2C2SDA     GPIO_AF3
#define GPIO_AF_PN4_EPI0S34     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pn5_values GPIO_AF_PN5 Values
 * @brief GPIO PN5 Alternate Functions Values
@{*/
#define GPIO_AF_PN5_U1RI        GPIO_AF1
#define GPIO_AF_PN5_U3CTS       GPIO_AF2
#define GPIO_AF_PN5_I2C2SCL     GPIO_AF3
#define GPIO_AF_PN5_EPI0S35     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pp0_values GPIO_AF_PP0 Values
 * @brief GPIO PP0 Alternate Functions Values
@{*/
#define GPIO_AF_PP0_U6RX        GPIO_AF1
#define GPIO_AF_PP0_T6CCP0      GPIO_AF5
#define GPIO_AF_PP0_EN0INTRN    GPIO_AF7
#define GPIO_AF_PP0_SSI3XDAT2   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pp1_values GPIO_AF_PP1 Values
 * @brief GPIO PP1 Alternate Functions Values
@{*/
#define GPIO_AF_PP1_U6TX        GPIO_AF1
#define GPIO_AF_PP1_T6CCP1      GPIO_AF5
#define GPIO_AF_PP1_SSI3XDAT3   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pp2_values GPIO_AF_PP2 Values
 * @brief GPIO PP2 Alternate Functions Values
@{*/
#define GPIO_AF_PP2_U0DTR       GPIO_AF1
#define GPIO_AF_PP2_USB0NXT     GPIO_AF14
#define GPIO_AF_PP2_EPI0S29     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pp3_values GPIO_AF_PP3 Values
 * @brief GPIO PP3 Alternate Functions Values
@{*/
#define GPIO_AF_PP3_U1CTS       GPIO_AF1
#define GPIO_AF_PP3_U0DCD       GPIO_AF2
#define GPIO_AF_PP3_RTCCLK      GPIO_AF7
#define GPIO_AF_PP3_USB0DIR     GPIO_AF14
#define GPIO_AF_PP3_EPI0S30     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pp4_values GPIO_AF_PP4 Values
 * @brief GPIO PP4 Alternate Functions Values
@{*/
#define GPIO_AF_PP4_U3RTS       GPIO_AF1
#define GPIO_AF_PP4_U0DSR       GPIO_AF2
#define GPIO_AF_PP4_OWIRE       GPIO_AF4
#define GPIO_AF_PP4_USB0D7      GPIO_AF14
/**@}*/

/** @defgroup gpio_af_pp5_values GPIO_AF_PP5 Values
 * @brief GPIO PP5 Alternate Functions Values
@{*/
#define GPIO_AF_PP5_U3CTS       GPIO_AF1
#define GPIO_AF_PP5_I2C2SCL     GPIO_AF2
#define GPIO_AF_PP5_OWALT       GPIO_AF4
#define GPIO_AF_PP5_USB0D6      GPIO_AF14
/**@}*/

/** @defgroup gpio_af_pp6_values GPIO_AF_PP6 Values
 * @brief GPIO PP6 Alternate Functions Values
@{*/
#define GPIO_AF_PP6_U1DCD       GPIO_AF1
#define GPIO_AF_PP6_I2C2SDA     GPIO_AF2
/**@}*/

/** @defgroup gpio_af_pq0_values GPIO_AF_PQ0 Values
 * @brief GPIO PQ0 Alternate Functions Values
@{*/
#define GPIO_AF_PQ0_T6CCP0      GPIO_AF3
#define GPIO_AF_PQ0_SSI3CLK     GPIO_AF14
#define GPIO_AF_PQ0_EPI0S20     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pq1_values GPIO_AF_PQ1 Values
 * @brief GPIO PQ1 Alternate Functions Values
@{*/
#define GPIO_AF_PQ1_T6CCP1      GPIO_AF3
#define GPIO_AF_PQ1_SSI3FSS     GPIO_AF14
#define GPIO_AF_PQ1_EPI0S21     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pq2_values GPIO_AF_PQ2 Values
 * @brief GPIO PQ2 Alternate Functions Values
@{*/
#define GPIO_AF_PQ2_T7CCP0      GPIO_AF3
#define GPIO_AF_PQ2_SSI3XDAT0   GPIO_AF14
#define GPIO_AF_PQ2_EPI0S22     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pq3_values GPIO_AF_PQ3 Values
 * @brief GPIO PQ3 Alternate Functions Values
@{*/
#define GPIO_AF_PQ3_T7CCP1      GPIO_AF3
#define GPIO_AF_PQ3_SSI3XDAT1   GPIO_AF14
#define GPIO_AF_PQ3_EPI0S23     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pq4_values GPIO_AF_PQ4 Values
 * @brief GPIO PQ4 Alternate Functions Values
@{*/
#define GPIO_AF_PQ4_U1RX        GPIO_AF1
#define GPIO_AF_PQ4_DIVSCLK     GPIO_AF7
/**@}*/

/** @defgroup gpio_af_pq7_values GPIO_AF_PQ7 Values
 * @brief GPIO PQ7 Alternate Functions Values
@{*/
#define GPIO_AF_PQ7_U1RI        GPIO_AF1
/**@}*/

/** @defgroup gpio_af_ps0_values GPIO_AF_PS0 Values
 * @brief GPIO PS0 Alternate Functions Values
@{*/
#define GPIO_AF_PS0_T2CCP0      GPIO_AF3
#define GPIO_AF_PS0_M0FAULT0    GPIO_AF6
#define GPIO_AF_PS0_LCDDATA20   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps1_values GPIO_AF_PS1 Values
 * @brief GPIO PS1 Alternate Functions Values
@{*/
#define GPIO_AF_PS1_T2CCP1      GPIO_AF3
#define GPIO_AF_PS1_M0FAULT1    GPIO_AF6
#define GPIO_AF_PS1_LCDDATA21   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps2_values GPIO_AF_PS2 Values
 * @brief GPIO PS2 Alternate Functions Values
@{*/
#define GPIO_AF_PS2_U1DSR       GPIO_AF1
#define GPIO_AF_PS2_T3CCP0      GPIO_AF3
#define GPIO_AF_PS2_M0FAULT2    GPIO_AF6
#define GPIO_AF_PS2_LCDDATA22   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_ps3_values GPIO_AF_PS3 Values
 * @brief GPIO PS3 Alternate Functions Values
@{*/
#define GPIO_AF_PS3_T3CCP1        GPIO_AF3
#define GPIO_AF_PS3_M0FAULT3      GPIO_AF6
#define GPIO_AF_PS3_LCDDATA23     GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pt2_values GPIO_AF_PT2 Values
 * @brief GPIO PT2 Alternate Functions Values
@{*/
#define GPIO_AF_PT2_T7CCP0      GPIO_AF3
#define GPIO_AF_PT2_CAN1RX      GPIO_AF7
#define GPIO_AF_PT2_LCDDATA18   GPIO_AF15
/**@}*/

/** @defgroup gpio_af_pt3_values GPIO_AF_PT3 Values
 * @brief GPIO PT3 Alternate Functions Values
@{*/
#define GPIO_AF_PT3_T7CCP1      GPIO_AF3
#define GPIO_AF_PT3_CAN1TX      GPIO_AF7
#define GPIO_AF_PT3_LCDDATA19   GPIO_AF15
/**@}*/

#define GPIO_EDM(n, mode)       ((mode) << (2 * (n)))
#define GPIO_EDM_MASK(n)        (0x3 << (2 * (n)))

#define GPIO_IM_DMAIME          (1 << 8)
#define GPIO_RIS_DMARIS         (1 << 8)
#define GPIO_MIS_DMAMIS         (1 << 8)
#define GPIO_ICR_DMAIC          (1 << 8)
#define GPIO_SI_SUM             (1 << 0)
#define GPIO_WAKEPEN_WAKEP4     (1 << 4)
#define GPIO_WAKEPEN_WAKEP5     (1 << 5)
#define GPIO_WAKEPEN_WAKEP6     (1 << 6)
#define GPIO_WAKEPEN_WAKEP7     (1 << 7)
#define GPIO_WAKELVL_WAKELVL4   (1 << 4)
#define GPIO_WAKELVL_WAKELVL5   (1 << 5)
#define GPIO_WAKELVL_WAKELVL6   (1 << 6)
#define GPIO_WAKELVL_WAKELVL7   (1 << 7)
#define GPIO_WAKESTAT_STAT4     (1 << 4)
#define GPIO_WAKESTAT_STAT5     (1 << 5)
#define GPIO_WAKESTAT_STAT6     (1 << 6)
#define GPIO_WAKESTAT_STAT7     (1 << 7)
#define GPIO_PP_EDE             (1 << 0)
/* Normal behavior, 2, 4 and 8 mA are available. */
#define GPIO_EDM_NORMAL         0x0
/* Full range, 2, 4, 6, 8, 10 and 12 mA are available.
 * Set one, clear other behavior is disabled. */
#define GPIO_EDM_FULL_RANGE     0x3

/* Value we need to write to unlock the GPIO commit register */
#define GPIO_LOCK_UNLOCK_CODE       0x4C4F434B

/* =============================================================================
 * Convenience enums
 * ---------------------------------------------------------------------------*/
enum gpio_mode {
    GPIO_MODE_OUTPUT,       /**< Configure pin as output */
    GPIO_MODE_INPUT,        /**< Configure pin as input */
    GPIO_MODE_ANALOG        /**< Configure pin as analog function */
};

enum gpio_pullup {
    GPIO_PUPD_NONE,     /**< Do not pull the pin high or low */
    GPIO_PUPD_PULLUP,   /**< Pull the pin high */
    GPIO_PUPD_PULLDOWN, /**< Pull the pin low */
};

enum gpio_output_type {
    GPIO_OTYPE_PP,      /**< Push-pull configuration */
    GPIO_OTYPE_OD,      /**< Open drain configuration */
};

enum gpio_drive_strength {
    GPIO_DRIVE_2MA,          /**< 2mA drive */
    GPIO_DRIVE_4MA,          /**< 4mA drive */
    GPIO_DRIVE_6MA,          /**< 6mA drive */
    GPIO_DRIVE_8MA,          /**< 8mA drive */
    GPIO_DRIVE_10MA,         /**< 10mA drive */
    GPIO_DRIVE_12MA          /**< 12mA drive */
};

enum gpio_slew_ctl {
    GPIO_SLEW_CTL_ENABLE, /**< Slew rate control enable */
    GPIO_SLEW_CTL_DISABLE /**< Slew rate control disable */
};

enum gpio_trigger {
    GPIO_TRIG_LVL_LOW,      /**< Level trigger, signal low */
    GPIO_TRIG_LVL_HIGH,     /**< Level trigger, signal high */
    GPIO_TRIG_EDGE_FALL,    /**< Falling edge trigger */
    GPIO_TRIG_EDGE_RISE,    /**< Rising edge trigger */
    GPIO_TRIG_EDGE_BOTH,    /**< Falling and Rising edges trigger */
};
/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

void gpio_mode_setup(uint32_t gpioport, enum gpio_mode mode,
                     enum gpio_pullup pullup, uint8_t gpios);
void gpio_set_output_config(uint32_t gpioport,
                            enum gpio_output_type otype,
                            enum gpio_drive_strength drive,
                            enum gpio_slew_ctl slewctl,
                            uint8_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint8_t gpios);

void gpio_toggle(uint32_t gpioport, uint8_t gpios);
void gpio_unlock_commit(uint32_t gpioport, uint8_t gpios);

/**
 * @brief Get status of a Group of Pins (atomic)
 *
 * Reads the level of the given pins. Bit 0 of the returned data corresponds to
 * GPIO0 level, bit 1 to GPIO1 level. and so on. Bits corresponding to masked
 * pins (corresponding bit of gpios parameter set to zero) are returned as 0.
 *
 * This is an atomic operation.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 *
 * @return The level of the GPIO port. The pins not specified in gpios are
 *	   masked to zero.
 */
static inline uint8_t gpio_read(uint32_t gpioport, uint8_t gpios)
{
    return GPIO_DATA(gpioport)[gpios];
}

/**
 * @brief Set level of a Group of Pins (atomic)
 *
 * Sets the level of the given pins. Bit 0 of the data parameter corresponds to
 * GPIO0, bit 1 to GPIO1. and so on. Maskedpins (corresponding bit of gpios
 * parameter set to zero) are returned not affected.
 *
 * This is an atomic operation.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 * @param[in] data Level to set pin to. Bit 0 of data corresponds to GPIO0, bit
 *		   1 to GPIO1. and so on.
 */
static inline void gpio_write(uint32_t gpioport, uint8_t gpios, uint8_t data)
{
	/* ipaddr[9:2] mask the bits to be set, hence the array index */
    GPIO_DATA(gpioport)[gpios] = data;
}

/**
 * @brief Set a Group of Pins (atomic)
 *
 * Set one or more pins of the given GPIO port. This is an atomic operation.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 */
static inline void gpio_set(uint32_t gpioport, uint8_t gpios)
{
    gpio_write(gpioport, gpios, 0xff);
}

/**
 * @brief Clear a Group of Pins (atomic)
 *
 * Clear one or more pins of the given GPIO port. This is an atomic operation.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 */
static inline void gpio_clear(uint32_t gpioport, uint8_t gpios)
{
    gpio_write(gpioport, gpios, 0);
}

/**
 * @brief Read level of all pins from a port (atomic)
 *
 * Read the current value of the given GPIO port. This is an atomic operation.
 *
 * This is functionally identical to @ref gpio_read (gpioport, GPIO_ALL).
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 *
 * @return The level of all the pins on the GPIO port.
 */
static inline uint8_t gpio_port_read(uint32_t gpioport)
{
    return gpio_read(gpioport, GPIO_ALL);
}

/**
 * @brief Set level of of all pins from a port (atomic)
 *
 * Set the level of all pins on the given GPIO port. This is an atomic
 * operation.
 *
 * This is functionally identical to @ref gpio_write (gpioport, GPIO_ALL, data).
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 * @param[in] data Level to set pin to. Bit 0 of data corresponds to GPIO0, bit
 *		   1 to GPIO1. and so on.
 */
static inline void gpio_port_write(uint32_t gpioport, uint8_t data)
{
    gpio_write(gpioport, GPIO_ALL, data);
}

void gpio_configure_trigger(uint32_t gpioport, enum gpio_trigger trigger,
                            uint8_t gpios);
void gpio_enable_interrupts(uint32_t gpioport, uint8_t gpios);
void gpio_disable_interrupts(uint32_t gpioport, uint8_t gpios);

/** @brief Determine if interrupt is generated by the given pin
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] srcpins source pin or group of pins to check.
 */
static inline bool gpio_is_interrupt_source(uint32_t gpioport, uint8_t srcpins)
{
	return GPIO_MIS(gpioport) & srcpins;
}

/** @brief Mark interrupt as serviced
 * After an interrupt is services, its flag must be cleared. If the flag is not
 * cleared, then execution will jump back to the start of the ISR after the ISR
 * returns.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *            by OR'ing then together.
 */
static inline void gpio_clear_interrupt_flag(uint32_t gpioport, uint8_t gpios)
{
    GPIO_ICR(gpioport) |= gpios;
}

END_DECLS

#endif

/**@}*/


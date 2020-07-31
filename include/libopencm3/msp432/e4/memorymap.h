/** @defgroup msp432e4_memorymap MSP432E4xx Memory Map
 *
 * @ingroup MSP432E4xx_defines
 *
 * @brief Memory map for the MSP432E4xx devices
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

/**@{*/

#ifndef MSP432E4_MEMORYMAP_H
#define MSP432E4_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- MSP432E4xx specific peripheral definitions --------------------------- */

/** System Control Base Address */
#define SYSCTL_BASE         (0x400FE000U)

/** Hibernation Module Base Address */
#define HIB_BASE            (0x400FC000U)

/** Flash Controller Base Address */
#define FLASH_CTRL_BASE     (0x400FD000U)

/** EEPROM Controller Base Address */
#define EEPROM_BASE         (0x400AF000U)

/** Micro Direct Memory Access Base Address */
#define DMA_BASE            (0x400FF000U)

/** Advance Encryption Standard Accelerator Base Address */
#define AES_BASE            (0x44036000U)

/** Analog-to-Digital Converter Base Address */
#define ADC0_BASE           (0x40038000U)
#define ADC1_BASE           (0x40039000U)

/** Controller Area Network Base Address */
#define CAN0_BASE           (0x40040000U)
#define CAN1_BASE           (0x40041000U)

/** Analog Comparator Base Address */
#define ACMP_BASE           (0x4003C000U)

/** Cyclical Redundancy Check Base Address */
#define CRC_BASE            (0x44030000U)

/** Data Encryption Standard Accelerator Base Address */
#define DES_BASE            (0x44038000U)

/** Ethernet Controller Base Address */
#define EMAC_BASE           (0x400EC000U)

/** External Peripheral Interface Base Address */
#define EPI0_BASE           (0x400D0000U)

/** General-Purpose Input/Outputs Base Address */
#define GPIOA_APB_BASE      (0x40004000U)
#define GPIOB_APB_BASE      (0x40005000U)
#define GPIOC_APB_BASE      (0x40006000U)
#define GPIOD_APB_BASE      (0x40007000U)
#define GPIOE_APB_BASE      (0x40024000U)
#define GPIOF_APB_BASE      (0x40025000U)
#define GPIOG_APB_BASE      (0x40026000U)
#define GPIOH_APB_BASE      (0x40027000U)
#define GPIOJ_APB_BASE      (0x4003D000U)

/** General-Purpose Input/Outputs (AHB) Base Address */
#define GPIOA_BASE          (0x40058000U)
#define GPIOB_BASE          (0x40059000U)
#define GPIOC_BASE          (0x4005A000U)
#define GPIOD_BASE          (0x4005B000U)
#define GPIOE_BASE          (0x4005C000U)
#define GPIOF_BASE          (0x4005D000U)
#define GPIOG_BASE          (0x4005E000U)
#define GPIOH_BASE          (0x4005F000U)
#define GPIOJ_BASE          (0x40060000U)
#define GPIOK_BASE          (0x40061000U)
#define GPIOL_BASE          (0x40062000U)
#define GPIOM_BASE          (0x40063000U)
#define GPION_BASE          (0x40064000U)
#define GPIOP_BASE          (0x40065000U)
#define GPIOQ_BASE          (0x40066000U)

/** General-Purpose Timers Base Address */
#define TIM0_BASE           (0x40030000U)
#define TIM1_BASE           (0x40031000U)
#define TIM2_BASE           (0x40032000U)
#define TIM3_BASE           (0x40033000U)
#define TIM4_BASE           (0x40034000U)
#define TIM5_BASE           (0x40035000U)
#define TIM6_BASE           (0x400E0000U)
#define TIM7_BASE           (0x400E1000U)

/** Inter-Integrated Circuit Base Address */
#define I2C0_BASE           (0x40020000U)
#define I2C1_BASE           (0x40021000U)
#define I2C2_BASE           (0x40022000U)
#define I2C3_BASE           (0x40023000U)
#define I2C4_BASE           (0x400C0000U)
#define I2C5_BASE           (0x400C1000U)
#define I2C6_BASE           (0x400C2000U)
#define I2C7_BASE           (0x400C3000U)
#define I2C8_BASE           (0x400B8000U)
#define I2C9_BASE           (0x400B9000U)

/** LCD Controller Base Address */
#define LCD_BASE            (0x44050000U)

/** Pulse Width Modulator Base Address */
#define PWM0_BASE           (0x40028000U)

/** 1-Wire Master Module Base Address */
#define ONEWIRE_BASE        (0x400B6000U)

/** Quad Synchronous Serial Interface Base Address */
#define SSI0_BASE           (0x40008000U)
#define SSI1_BASE           (0x40009000U)
#define SSI2_BASE           (0x4000A000U)
#define SSI3_BASE           (0x4000B000U)

/** Quadrature Encoder Interface Base Address */
#define QEI0_BASE           (0x4002C000U)

/** SHA/MD5 Accelerator Base Address */
#define SHA_BASE            (0x44034000U)

/** Universal Asynchronous Receiver/Transmitter Base Address */
#define UART0_BASE          (0x4000C000U)
#define UART1_BASE          (0x4000D000U)
#define UART2_BASE          (0x4000E000U)
#define UART3_BASE          (0x4000F000U)
#define UART4_BASE          (0x40010000U)
#define UART5_BASE          (0x40011000U)
#define UART6_BASE          (0x40012000U)
#define UART7_BASE          (0x40013000U)

/** Universal Serial Bus Controller Base Address */
#define USB_BASE            (0x40050000U)

/** Watchdog Timers Base Address */
#define WDT0_BASE           (0x40000000U)
#define WDT1_BASE           (0x40001000U)

#endif /* MSP432E4_MEMORYMAP_H */

/**@}*/

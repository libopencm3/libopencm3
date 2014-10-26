/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_MEMORYMAP_H
#define LPC43XX_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- LPC43XX specific peripheral definitions ----------------------------- */

/* Memory map for all busses */
#define PERIPH_BASE_AHB                 (0x40000000U)
#define PERIPH_BASE_APB0                (0x40080000U)
#define PERIPH_BASE_APB1                (0x400A0000U)
#define PERIPH_BASE_APB2                (0x400C0000U)
#define PERIPH_BASE_APB3                (0x400E0000U)

/* Register boundary addresses */

/* AHB (0x4000 0000 - 0x4001 2000) */
#define SCT_BASE                        (PERIPH_BASE_AHB + 0x00000)
/* PERIPH_BASE_AHB + 0x01000 (0x4000 1000 - 0x4000 1FFF): Reserved */
#define GPDMA_BASE                      (PERIPH_BASE_AHB + 0x02000)
#define SPIFI_BASE                      (PERIPH_BASE_AHB + 0x03000)
#define SDIO_BASE                       (PERIPH_BASE_AHB + 0x04000)
#define EMC_BASE                        (PERIPH_BASE_AHB + 0x05000)
#define USB0_BASE                       (PERIPH_BASE_AHB + 0x06000)
#define USB1_BASE                       (PERIPH_BASE_AHB + 0x07000)
#define LCD_BASE                        (PERIPH_BASE_AHB + 0x08000)
/* PERIPH_BASE_AHB + 0x09000 (0x4000 9000 - 0x4000 FFFF): Reserved */
#define ETHERNET_BASE                   (PERIPH_BASE_AHB + 0x10000)

/* 0x4001 2000 - 0x4003 FFFF Reserved */

/* RTC domain peripherals */
#define ATIMER_BASE                     (0x40040000U)
#define BACKUP_REG_BASE                 (0x40041000U)
#define PMC_BASE                        (0x40042000U)
#define CREG_BASE                       (0x40043000U)
#define EVENTROUTER_BASE                (0x40044000U)
#define OTP_BASE                        (0x40045000U)
#define RTC_BASE                        (0x40046000U)
/* 0x4004 7000 - 0x4004 FFFF Reserved */

/* clocking/reset control peripherals */
#define CGU_BASE                        (0x40050000U)
#define CCU1_BASE                       (0x40051000U)
#define CCU2_BASE                       (0x40052000U)
#define RGU_BASE                        (0x40053000U)
/* 0x4005 4000 - 0x4005 FFFF Reserved */

/* 0x4006 0000 - 0x4007 FFFF Reserved */

/* APB0 ( 0x4008 0000 - 0x4008 FFFF) */
#define WWDT_BASE                       (PERIPH_BASE_APB0 + 0x00000)
#define USART0_BASE                     (PERIPH_BASE_APB0 + 0x01000)
#define UART1_BASE                      (PERIPH_BASE_APB0 + 0x02000)
#define SSP0_BASE                       (PERIPH_BASE_APB0 + 0x03000)
#define TIMER0_BASE                     (PERIPH_BASE_APB0 + 0x04000)
#define TIMER1_BASE                     (PERIPH_BASE_APB0 + 0x05000)
#define SCU_BASE                        (PERIPH_BASE_APB0 + 0x06000)
#define GPIO_PIN_INTERRUPT_BASE         (PERIPH_BASE_APB0 + 0x07000)
#define GPIO_GROUP0_INTERRUPT_BASE      (PERIPH_BASE_APB0 + 0x08000)
#define GPIO_GROUP1_INTERRUPT_BASE      (PERIPH_BASE_APB0 + 0x09000)
/* 0x4008 A000 - 0x4008 FFFF Reserved */

/* 0x4009 0000 - 0x4009 FFFF Reserved */

/* APB1 (0x400A 0000 - 0x400A FFFF) */
#define MCPWM_BASE                      (PERIPH_BASE_APB1 + 0x00000)
#define I2C0_BASE                       (PERIPH_BASE_APB1 + 0x01000)
#define I2S0_BASE                       (PERIPH_BASE_APB1 + 0x02000)
#define I2S1_BASE                       (PERIPH_BASE_APB1 + 0x03000)
#define C_CCAN1_BASE                    (PERIPH_BASE_APB1 + 0x04000)
/* 0x400A 5000 - 0x400A FFFF Reserved */

/* 0x400B 0000 - 0x400B FFFF Reserved */

/* APB2 (0x400C 0000 - 0x400C FFFF) */
#define RITIMER_BASE                    (PERIPH_BASE_APB2 + 0x00000)
#define USART2_BASE                     (PERIPH_BASE_APB2 + 0x01000)
#define USART3_BASE                     (PERIPH_BASE_APB2 + 0x02000)
#define TIMER2_BASE                     (PERIPH_BASE_APB2 + 0x03000)
#define TIMER3_BASE                     (PERIPH_BASE_APB2 + 0x04000)
#define SSP1_BASE                       (PERIPH_BASE_APB2 + 0x05000)
#define QEI_BASE                        (PERIPH_BASE_APB2 + 0x06000)
#define GIMA_BASE                       (PERIPH_BASE_APB2 + 0x07000)
/* 0x400C 8000 - 0x400C FFFF Reserved */

/* 0x400D 0000 - 0x400D FFFF Reserved */

/* APB3 (0x400E 0000 - 0x400E FFFF) */
#define I2C1_BASE                       (PERIPH_BASE_APB3 + 0x00000)
#define DAC_BASE                        (PERIPH_BASE_APB3 + 0x01000)
#define C_CAN0_BASE                     (PERIPH_BASE_APB3 + 0x02000)
#define ADC0_BASE                       (PERIPH_BASE_APB3 + 0x03000)
#define ADC1_BASE                       (PERIPH_BASE_APB3 + 0x04000)
/* 0x400E 5000 - 0x400E FFFF Reserved */

/* 0x400F 0000 - 0x400F 0FFF Reserved */

#define AES_BASE                        (0x400F1000U)

/* 0x400F 2000 - 0x400F 3FFF Reserved */

#define GPIO_PORT_BASE                  (0x400F4000U)

/* 0x400F 8000 - 0x400F FFFF Reserved */

#define SPI_PORT_BASE                   (0x40100000U)
#define SGPIO_PORT_BASE                 (0x40101000U)

/* 0x4010 2000 - 0x41FF FFFF Reserved */

/* 0x4200 0000 - 0x43FF FFFF peripheral bit band alias region */

/* 0x4400 0000 - 0x5FFF FFFF Reserved */

/* 0x6000 0000 - 0xFFFF FFFF external memories and ARM private bus */

#endif

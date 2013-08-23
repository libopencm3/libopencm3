/** @defgroup rgu_defines Reset Generation Unit Defines

@brief <b>Defined Constants and Types for the LPC43xx Reset Generation Unit</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
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

#ifndef LPC43XX_RGU_H
#define LPC43XX_RGU_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- RGU registers ------------------------------------------------------- */

/* Reset control register 0 */
#define RESET_CTRL0                     MMIO32(RGU_BASE + 0x100)

/* Reset control register 1 */
#define RESET_CTRL1                     MMIO32(RGU_BASE + 0x104)

/* Reset status register 0 */
#define RESET_STATUS0                   MMIO32(RGU_BASE + 0x110)

/* Reset status register 1 */
#define RESET_STATUS1                   MMIO32(RGU_BASE + 0x114)

/* Reset status register 2 */
#define RESET_STATUS2                   MMIO32(RGU_BASE + 0x118)

/* Reset status register 3 */
#define RESET_STATUS3                   MMIO32(RGU_BASE + 0x11C)

/* Reset active status register 0 */
#define RESET_ACTIVE_STATUS0            MMIO32(RGU_BASE + 0x150)

/* Reset active status register 1 */
#define RESET_ACTIVE_STATUS1            MMIO32(RGU_BASE + 0x154)

/* Reset external status register 0 for CORE_RST */
#define RESET_EXT_STAT0                 MMIO32(RGU_BASE + 0x400)

/* Reset external status register 1 for PERIPH_RST */
#define RESET_EXT_STAT1                 MMIO32(RGU_BASE + 0x404)

/* Reset external status register 2 for MASTER_RST */
#define RESET_EXT_STAT2                 MMIO32(RGU_BASE + 0x408)

/* Reserved */
#define RESET_EXT_STAT3                 MMIO32(RGU_BASE + 0x40C)

/* Reset external status register 4 for WWDT_RST */
#define RESET_EXT_STAT4                 MMIO32(RGU_BASE + 0x410)

/* Reset external status register 5 for CREG_RST */
#define RESET_EXT_STAT5                 MMIO32(RGU_BASE + 0x414)

/* Reserved */
#define RESET_EXT_STAT6                 MMIO32(RGU_BASE + 0x418)

/* Reserved */
#define RESET_EXT_STAT7                 MMIO32(RGU_BASE + 0x41C)

/* Reset external status register 8 for BUS_RST */
#define RESET_EXT_STAT8                 MMIO32(RGU_BASE + 0x420)

/* Reset external status register 9 for SCU_RST */
#define RESET_EXT_STAT9                 MMIO32(RGU_BASE + 0x424)

/* Reserved */
#define RESET_EXT_STAT10                MMIO32(RGU_BASE + 0x428)

/* Reserved */
#define RESET_EXT_STAT11                MMIO32(RGU_BASE + 0x42C)

/* Reserved */
#define RESET_EXT_STAT12                MMIO32(RGU_BASE + 0x430)

/* Reset external status register 13 for M4_RST */
#define RESET_EXT_STAT13                MMIO32(RGU_BASE + 0x434)

/* Reserved */
#define RESET_EXT_STAT14                MMIO32(RGU_BASE + 0x438)

/* Reserved */
#define RESET_EXT_STAT15                MMIO32(RGU_BASE + 0x43C)

/* Reset external status register 16 for LCD_RST */
#define RESET_EXT_STAT16                MMIO32(RGU_BASE + 0x440)

/* Reset external status register 17 for USB0_RST */
#define RESET_EXT_STAT17                MMIO32(RGU_BASE + 0x444)

/* Reset external status register 18 for USB1_RST */
#define RESET_EXT_STAT18                MMIO32(RGU_BASE + 0x448)

/* Reset external status register 19 for DMA_RST */
#define RESET_EXT_STAT19                MMIO32(RGU_BASE + 0x44C)

/* Reset external status register 20 for SDIO_RST */
#define RESET_EXT_STAT20                MMIO32(RGU_BASE + 0x450)

/* Reset external status register 21 for EMC_RST */
#define RESET_EXT_STAT21                MMIO32(RGU_BASE + 0x454)

/* Reset external status register 22 for ETHERNET_RST */
#define RESET_EXT_STAT22                MMIO32(RGU_BASE + 0x458)

/* Reserved */
#define RESET_EXT_STAT23                MMIO32(RGU_BASE + 0x45C)

/* Reserved */
#define RESET_EXT_STAT24                MMIO32(RGU_BASE + 0x460)

/* Reserved */
#define RESET_EXT_STAT25                MMIO32(RGU_BASE + 0x464)

/* Reserved */
#define RESET_EXT_STAT26                MMIO32(RGU_BASE + 0x468)

/* Reserved */
#define RESET_EXT_STAT27                MMIO32(RGU_BASE + 0x46C)

/* Reset external status register 28 for GPIO_RST */
#define RESET_EXT_STAT28                MMIO32(RGU_BASE + 0x470)

/* Reserved */
#define RESET_EXT_STAT29                MMIO32(RGU_BASE + 0x474)

/* Reserved */
#define RESET_EXT_STAT30                MMIO32(RGU_BASE + 0x478)

/* Reserved */
#define RESET_EXT_STAT31                MMIO32(RGU_BASE + 0x47C)

/* Reset external status register 32 for TIMER0_RST */
#define RESET_EXT_STAT32                MMIO32(RGU_BASE + 0x480)

/* Reset external status register 33 for TIMER1_RST */
#define RESET_EXT_STAT33                MMIO32(RGU_BASE + 0x484)

/* Reset external status register 34 for TIMER2_RST */
#define RESET_EXT_STAT34                MMIO32(RGU_BASE + 0x488)

/* Reset external status register 35 for TIMER3_RST */
#define RESET_EXT_STAT35                MMIO32(RGU_BASE + 0x48C)

/* Reset external status register 36 for RITIMER_RST */
#define RESET_EXT_STAT36                MMIO32(RGU_BASE + 0x490)

/* Reset external status register 37 for SCT_RST */
#define RESET_EXT_STAT37                MMIO32(RGU_BASE + 0x494)

/* Reset external status register 38 for MOTOCONPWM_RST */
#define RESET_EXT_STAT38                MMIO32(RGU_BASE + 0x498)

/* Reset external status register 39 for QEI_RST */
#define RESET_EXT_STAT39                MMIO32(RGU_BASE + 0x49C)

/* Reset external status register 40 for ADC0_RST */
#define RESET_EXT_STAT40                MMIO32(RGU_BASE + 0x4A0)

/* Reset external status register 41 for ADC1_RST */
#define RESET_EXT_STAT41                MMIO32(RGU_BASE + 0x4A4)

/* Reset external status register 42 for DAC_RST */
#define RESET_EXT_STAT42                MMIO32(RGU_BASE + 0x4A8)

/* Reserved */
#define RESET_EXT_STAT43                MMIO32(RGU_BASE + 0x4AC)

/* Reset external status register 44 for UART0_RST */
#define RESET_EXT_STAT44                MMIO32(RGU_BASE + 0x4B0)

/* Reset external status register 45 for UART1_RST */
#define RESET_EXT_STAT45                MMIO32(RGU_BASE + 0x4B4)

/* Reset external status register 46 for UART2_RST */
#define RESET_EXT_STAT46                MMIO32(RGU_BASE + 0x4B8)

/* Reset external status register 47 for UART3_RST */
#define RESET_EXT_STAT47                MMIO32(RGU_BASE + 0x4BC)

/* Reset external status register 48 for I2C0_RST */
#define RESET_EXT_STAT48                MMIO32(RGU_BASE + 0x4C0)

/* Reset external status register 49 for I2C1_RST */
#define RESET_EXT_STAT49                MMIO32(RGU_BASE + 0x4C4)

/* Reset external status register 50 for SSP0_RST */
#define RESET_EXT_STAT50                MMIO32(RGU_BASE + 0x4C8)

/* Reset external status register 51 for SSP1_RST */
#define RESET_EXT_STAT51                MMIO32(RGU_BASE + 0x4CC)

/* Reset external status register 52 for I2S_RST */
#define RESET_EXT_STAT52                MMIO32(RGU_BASE + 0x4D0)

/* Reset external status register 53 for SPIFI_RST */
#define RESET_EXT_STAT53                MMIO32(RGU_BASE + 0x4D4)

/* Reset external status register 54 for CAN1_RST */
#define RESET_EXT_STAT54                MMIO32(RGU_BASE + 0x4D8)

/* Reset external status register 55 for CAN0_RST */
#define RESET_EXT_STAT55                MMIO32(RGU_BASE + 0x4DC)

/* Reset external status register 56 for M0APP_RST */
#define RESET_EXT_STAT56                MMIO32(RGU_BASE + 0x4E0)

/* Reset external status register 57 for SGPIO_RST */
#define RESET_EXT_STAT57                MMIO32(RGU_BASE + 0x4E4)

/* Reset external status register 58 for SPI_RST */
#define RESET_EXT_STAT58                MMIO32(RGU_BASE + 0x4E8)

/* Reserved */
#define RESET_EXT_STAT59                MMIO32(RGU_BASE + 0x4EC)

/* Reserved */
#define RESET_EXT_STAT60                MMIO32(RGU_BASE + 0x4F0)

/* Reserved */
#define RESET_EXT_STAT61                MMIO32(RGU_BASE + 0x4F4)

/* Reserved */
#define RESET_EXT_STAT62                MMIO32(RGU_BASE + 0x4F8)

/* Reserved */
#define RESET_EXT_STAT63                MMIO32(RGU_BASE + 0x4FC)

/* --- RESET_CTRL0 values --------------------------------------- */

/* CORE_RST: Writing a one activates the reset */
#define RESET_CTRL0_CORE_RST_SHIFT (0)
#define RESET_CTRL0_CORE_RST (1 << RESET_CTRL0_CORE_RST_SHIFT)

/* PERIPH_RST: Writing a one activates the reset */
#define RESET_CTRL0_PERIPH_RST_SHIFT (1)
#define RESET_CTRL0_PERIPH_RST (1 << RESET_CTRL0_PERIPH_RST_SHIFT)

/* MASTER_RST: Writing a one activates the reset */
#define RESET_CTRL0_MASTER_RST_SHIFT (2)
#define RESET_CTRL0_MASTER_RST (1 << RESET_CTRL0_MASTER_RST_SHIFT)

/* WWDT_RST: Writing a one to this bit has no effect */
#define RESET_CTRL0_WWDT_RST_SHIFT (4)
#define RESET_CTRL0_WWDT_RST (1 << RESET_CTRL0_WWDT_RST_SHIFT)

/* CREG_RST: Writing a one to this bit has no effect */
#define RESET_CTRL0_CREG_RST_SHIFT (5)
#define RESET_CTRL0_CREG_RST (1 << RESET_CTRL0_CREG_RST_SHIFT)

/* BUS_RST: Writing a one activates the reset */
#define RESET_CTRL0_BUS_RST_SHIFT (8)
#define RESET_CTRL0_BUS_RST (1 << RESET_CTRL0_BUS_RST_SHIFT)

/* SCU_RST: Writing a one activates the reset */
#define RESET_CTRL0_SCU_RST_SHIFT (9)
#define RESET_CTRL0_SCU_RST (1 << RESET_CTRL0_SCU_RST_SHIFT)

/* M4_RST: Writing a one activates the reset */
#define RESET_CTRL0_M4_RST_SHIFT (13)
#define RESET_CTRL0_M4_RST (1 << RESET_CTRL0_M4_RST_SHIFT)

/* LCD_RST: Writing a one activates the reset */
#define RESET_CTRL0_LCD_RST_SHIFT (16)
#define RESET_CTRL0_LCD_RST (1 << RESET_CTRL0_LCD_RST_SHIFT)

/* USB0_RST: Writing a one activates the reset */
#define RESET_CTRL0_USB0_RST_SHIFT (17)
#define RESET_CTRL0_USB0_RST (1 << RESET_CTRL0_USB0_RST_SHIFT)

/* USB1_RST: Writing a one activates the reset */
#define RESET_CTRL0_USB1_RST_SHIFT (18)
#define RESET_CTRL0_USB1_RST (1 << RESET_CTRL0_USB1_RST_SHIFT)

/* DMA_RST: Writing a one activates the reset */
#define RESET_CTRL0_DMA_RST_SHIFT (19)
#define RESET_CTRL0_DMA_RST (1 << RESET_CTRL0_DMA_RST_SHIFT)

/* SDIO_RST: Writing a one activates the reset */
#define RESET_CTRL0_SDIO_RST_SHIFT (20)
#define RESET_CTRL0_SDIO_RST (1 << RESET_CTRL0_SDIO_RST_SHIFT)

/* EMC_RST: Writing a one activates the reset */
#define RESET_CTRL0_EMC_RST_SHIFT (21)
#define RESET_CTRL0_EMC_RST (1 << RESET_CTRL0_EMC_RST_SHIFT)

/* ETHERNET_RST: Writing a one activates the reset */
#define RESET_CTRL0_ETHERNET_RST_SHIFT (22)
#define RESET_CTRL0_ETHERNET_RST (1 << RESET_CTRL0_ETHERNET_RST_SHIFT)

/* FLASHA_RST: Writing a one activates the reset */
#define RESET_CTRL0_FLASHA_RST_SHIFT (25)
#define RESET_CTRL0_FLASHA_RST (1 << RESET_CTRL0_FLASHA_RST_SHIFT)

/* EEPROM_RST: Writing a one activates the reset */
#define RESET_CTRL0_EEPROM_RST_SHIFT (27)
#define RESET_CTRL0_EEPROM_RST (1 << RESET_CTRL0_EEPROM_RST_SHIFT)

/* GPIO_RST: Writing a one activates the reset */
#define RESET_CTRL0_GPIO_RST_SHIFT (28)
#define RESET_CTRL0_GPIO_RST (1 << RESET_CTRL0_GPIO_RST_SHIFT)

/* FLASHB_RST: Writing a one activates the reset */
#define RESET_CTRL0_FLASHB_RST_SHIFT (29)
#define RESET_CTRL0_FLASHB_RST (1 << RESET_CTRL0_FLASHB_RST_SHIFT)

/* --- RESET_CTRL1 values --------------------------------------- */

/* TIMER0_RST: Writing a one activates the reset */
#define RESET_CTRL1_TIMER0_RST_SHIFT (0)
#define RESET_CTRL1_TIMER0_RST (1 << RESET_CTRL1_TIMER0_RST_SHIFT)

/* TIMER1_RST: Writing a one activates the reset */
#define RESET_CTRL1_TIMER1_RST_SHIFT (1)
#define RESET_CTRL1_TIMER1_RST (1 << RESET_CTRL1_TIMER1_RST_SHIFT)

/* TIMER2_RST: Writing a one activates the reset */
#define RESET_CTRL1_TIMER2_RST_SHIFT (2)
#define RESET_CTRL1_TIMER2_RST (1 << RESET_CTRL1_TIMER2_RST_SHIFT)

/* TIMER3_RST: Writing a one activates the reset */
#define RESET_CTRL1_TIMER3_RST_SHIFT (3)
#define RESET_CTRL1_TIMER3_RST (1 << RESET_CTRL1_TIMER3_RST_SHIFT)

/* RTIMER_RST: Writing a one activates the reset */
#define RESET_CTRL1_RTIMER_RST_SHIFT (4)
#define RESET_CTRL1_RTIMER_RST (1 << RESET_CTRL1_RTIMER_RST_SHIFT)

/* SCT_RST: Writing a one activates the reset */
#define RESET_CTRL1_SCT_RST_SHIFT (5)
#define RESET_CTRL1_SCT_RST (1 << RESET_CTRL1_SCT_RST_SHIFT)

/* MOTOCONPWM_RST: Writing a one activates the reset */
#define RESET_CTRL1_MOTOCONPWM_RST_SHIFT (6)
#define RESET_CTRL1_MOTOCONPWM_RST (1 << RESET_CTRL1_MOTOCONPWM_RST_SHIFT)

/* QEI_RST: Writing a one activates the reset */
#define RESET_CTRL1_QEI_RST_SHIFT (7)
#define RESET_CTRL1_QEI_RST (1 << RESET_CTRL1_QEI_RST_SHIFT)

/* ADC0_RST: Writing a one activates the reset */
#define RESET_CTRL1_ADC0_RST_SHIFT (8)
#define RESET_CTRL1_ADC0_RST (1 << RESET_CTRL1_ADC0_RST_SHIFT)

/* ADC1_RST: Writing a one activates the reset */
#define RESET_CTRL1_ADC1_RST_SHIFT (9)
#define RESET_CTRL1_ADC1_RST (1 << RESET_CTRL1_ADC1_RST_SHIFT)

/* DAC_RST: Writing a one activates the reset */
#define RESET_CTRL1_DAC_RST_SHIFT (10)
#define RESET_CTRL1_DAC_RST (1 << RESET_CTRL1_DAC_RST_SHIFT)

/* UART0_RST: Writing a one activates the reset */
#define RESET_CTRL1_UART0_RST_SHIFT (12)
#define RESET_CTRL1_UART0_RST (1 << RESET_CTRL1_UART0_RST_SHIFT)

/* UART1_RST: Writing a one activates the reset */
#define RESET_CTRL1_UART1_RST_SHIFT (13)
#define RESET_CTRL1_UART1_RST (1 << RESET_CTRL1_UART1_RST_SHIFT)

/* UART2_RST: Writing a one activates the reset */
#define RESET_CTRL1_UART2_RST_SHIFT (14)
#define RESET_CTRL1_UART2_RST (1 << RESET_CTRL1_UART2_RST_SHIFT)

/* UART3_RST: Writing a one activates the reset */
#define RESET_CTRL1_UART3_RST_SHIFT (15)
#define RESET_CTRL1_UART3_RST (1 << RESET_CTRL1_UART3_RST_SHIFT)

/* I2C0_RST: Writing a one activates the reset */
#define RESET_CTRL1_I2C0_RST_SHIFT (16)
#define RESET_CTRL1_I2C0_RST (1 << RESET_CTRL1_I2C0_RST_SHIFT)

/* I2C1_RST: Writing a one activates the reset */
#define RESET_CTRL1_I2C1_RST_SHIFT (17)
#define RESET_CTRL1_I2C1_RST (1 << RESET_CTRL1_I2C1_RST_SHIFT)

/* SSP0_RST: Writing a one activates the reset */
#define RESET_CTRL1_SSP0_RST_SHIFT (18)
#define RESET_CTRL1_SSP0_RST (1 << RESET_CTRL1_SSP0_RST_SHIFT)

/* SSP1_RST: Writing a one activates the reset */
#define RESET_CTRL1_SSP1_RST_SHIFT (19)
#define RESET_CTRL1_SSP1_RST (1 << RESET_CTRL1_SSP1_RST_SHIFT)

/* I2S_RST: Writing a one activates the reset */
#define RESET_CTRL1_I2S_RST_SHIFT (20)
#define RESET_CTRL1_I2S_RST (1 << RESET_CTRL1_I2S_RST_SHIFT)

/* SPIFI_RST: Writing a one activates the reset */
#define RESET_CTRL1_SPIFI_RST_SHIFT (21)
#define RESET_CTRL1_SPIFI_RST (1 << RESET_CTRL1_SPIFI_RST_SHIFT)

/* CAN1_RST: Writing a one activates the reset */
#define RESET_CTRL1_CAN1_RST_SHIFT (22)
#define RESET_CTRL1_CAN1_RST (1 << RESET_CTRL1_CAN1_RST_SHIFT)

/* CAN0_RST: Writing a one activates the reset */
#define RESET_CTRL1_CAN0_RST_SHIFT (23)
#define RESET_CTRL1_CAN0_RST (1 << RESET_CTRL1_CAN0_RST_SHIFT)

/* M0APP_RST: Writing a one activates the reset */
#define RESET_CTRL1_M0APP_RST_SHIFT (24)
#define RESET_CTRL1_M0APP_RST (1 << RESET_CTRL1_M0APP_RST_SHIFT)

/* SGPIO_RST: Writing a one activates the reset */
#define RESET_CTRL1_SGPIO_RST_SHIFT (25)
#define RESET_CTRL1_SGPIO_RST (1 << RESET_CTRL1_SGPIO_RST_SHIFT)

/* SPI_RST: Writing a one activates the reset */
#define RESET_CTRL1_SPI_RST_SHIFT (26)
#define RESET_CTRL1_SPI_RST (1 << RESET_CTRL1_SPI_RST_SHIFT)

/* --- RESET_STATUS0 values ------------------------------------- */

/* CORE_RST: Status of the CORE_RST reset generator output */
#define RESET_STATUS0_CORE_RST_SHIFT (0)
#define RESET_STATUS0_CORE_RST_MASK (0x3 << RESET_STATUS0_CORE_RST_SHIFT)
#define RESET_STATUS0_CORE_RST(x) ((x) << RESET_STATUS0_CORE_RST_SHIFT)

/* PERIPH_RST: Status of the PERIPH_RST reset generator output */
#define RESET_STATUS0_PERIPH_RST_SHIFT (2)
#define RESET_STATUS0_PERIPH_RST_MASK (0x3 << RESET_STATUS0_PERIPH_RST_SHIFT)
#define RESET_STATUS0_PERIPH_RST(x) ((x) << RESET_STATUS0_PERIPH_RST_SHIFT)

/* MASTER_RST: Status of the MASTER_RST reset generator output */
#define RESET_STATUS0_MASTER_RST_SHIFT (4)
#define RESET_STATUS0_MASTER_RST_MASK (0x3 << RESET_STATUS0_MASTER_RST_SHIFT)
#define RESET_STATUS0_MASTER_RST(x) ((x) << RESET_STATUS0_MASTER_RST_SHIFT)

/* WWDT_RST: Status of the WWDT_RST reset generator output */
#define RESET_STATUS0_WWDT_RST_SHIFT (8)
#define RESET_STATUS0_WWDT_RST_MASK (0x3 << RESET_STATUS0_WWDT_RST_SHIFT)
#define RESET_STATUS0_WWDT_RST(x) ((x) << RESET_STATUS0_WWDT_RST_SHIFT)

/* CREG_RST: Status of the CREG_RST reset generator output */
#define RESET_STATUS0_CREG_RST_SHIFT (10)
#define RESET_STATUS0_CREG_RST_MASK (0x3 << RESET_STATUS0_CREG_RST_SHIFT)
#define RESET_STATUS0_CREG_RST(x) ((x) << RESET_STATUS0_CREG_RST_SHIFT)

/* BUS_RST: Status of the BUS_RST reset generator output */
#define RESET_STATUS0_BUS_RST_SHIFT (16)
#define RESET_STATUS0_BUS_RST_MASK (0x3 << RESET_STATUS0_BUS_RST_SHIFT)
#define RESET_STATUS0_BUS_RST(x) ((x) << RESET_STATUS0_BUS_RST_SHIFT)

/* SCU_RST: Status of the SCU_RST reset generator output */
#define RESET_STATUS0_SCU_RST_SHIFT (18)
#define RESET_STATUS0_SCU_RST_MASK (0x3 << RESET_STATUS0_SCU_RST_SHIFT)
#define RESET_STATUS0_SCU_RST(x) ((x) << RESET_STATUS0_SCU_RST_SHIFT)

/* M4_RST: Status of the M4_RST reset generator output */
#define RESET_STATUS0_M4_RST_SHIFT (26)
#define RESET_STATUS0_M4_RST_MASK (0x3 << RESET_STATUS0_M4_RST_SHIFT)
#define RESET_STATUS0_M4_RST(x) ((x) << RESET_STATUS0_M4_RST_SHIFT)

/* --- RESET_STATUS1 values ------------------------------------- */

/* LCD_RST: Status of the LCD_RST reset generator output */
#define RESET_STATUS1_LCD_RST_SHIFT (0)
#define RESET_STATUS1_LCD_RST_MASK (0x3 << RESET_STATUS1_LCD_RST_SHIFT)
#define RESET_STATUS1_LCD_RST(x) ((x) << RESET_STATUS1_LCD_RST_SHIFT)

/* USB0_RST: Status of the USB0_RST reset generator output */
#define RESET_STATUS1_USB0_RST_SHIFT (2)
#define RESET_STATUS1_USB0_RST_MASK (0x3 << RESET_STATUS1_USB0_RST_SHIFT)
#define RESET_STATUS1_USB0_RST(x) ((x) << RESET_STATUS1_USB0_RST_SHIFT)

/* USB1_RST: Status of the USB1_RST reset generator output */
#define RESET_STATUS1_USB1_RST_SHIFT (4)
#define RESET_STATUS1_USB1_RST_MASK (0x3 << RESET_STATUS1_USB1_RST_SHIFT)
#define RESET_STATUS1_USB1_RST(x) ((x) << RESET_STATUS1_USB1_RST_SHIFT)

/* DMA_RST: Status of the DMA_RST reset generator output */
#define RESET_STATUS1_DMA_RST_SHIFT (6)
#define RESET_STATUS1_DMA_RST_MASK (0x3 << RESET_STATUS1_DMA_RST_SHIFT)
#define RESET_STATUS1_DMA_RST(x) ((x) << RESET_STATUS1_DMA_RST_SHIFT)

/* SDIO_RST: Status of the SDIO_RST reset generator output */
#define RESET_STATUS1_SDIO_RST_SHIFT (8)
#define RESET_STATUS1_SDIO_RST_MASK (0x3 << RESET_STATUS1_SDIO_RST_SHIFT)
#define RESET_STATUS1_SDIO_RST(x) ((x) << RESET_STATUS1_SDIO_RST_SHIFT)

/* EMC_RST: Status of the EMC_RST reset generator output */
#define RESET_STATUS1_EMC_RST_SHIFT (10)
#define RESET_STATUS1_EMC_RST_MASK (0x3 << RESET_STATUS1_EMC_RST_SHIFT)
#define RESET_STATUS1_EMC_RST(x) ((x) << RESET_STATUS1_EMC_RST_SHIFT)

/* ETHERNET_RST: Status of the ETHERNET_RST reset generator output */
#define RESET_STATUS1_ETHERNET_RST_SHIFT (12)
#define RESET_STATUS1_ETHERNET_RST_MASK \
			(0x3 << RESET_STATUS1_ETHERNET_RST_SHIFT)
#define RESET_STATUS1_ETHERNET_RST(x) ((x) << RESET_STATUS1_ETHERNET_RST_SHIFT)

/* FLASHA_RST: Status of the FLASHA_RST reset generator output */
#define RESET_STATUS1_FLASHA_RST_SHIFT (18)
#define RESET_STATUS1_FLASHA_RST_MASK (0x3 << RESET_STATUS1_FLASHA_RST_SHIFT)
#define RESET_STATUS1_FLASHA_RST(x) ((x) << RESET_STATUS1_FLASHA_RST_SHIFT)

/* EEPROM_RST: Status of the EEPROM_RST reset generator output */
#define RESET_STATUS1_EEPROM_RST_SHIFT (22)
#define RESET_STATUS1_EEPROM_RST_MASK (0x3 << RESET_STATUS1_EEPROM_RST_SHIFT)
#define RESET_STATUS1_EEPROM_RST(x) ((x) << RESET_STATUS1_EEPROM_RST_SHIFT)

/* GPIO_RST: Status of the GPIO_RST reset generator output */
#define RESET_STATUS1_GPIO_RST_SHIFT (24)
#define RESET_STATUS1_GPIO_RST_MASK (0x3 << RESET_STATUS1_GPIO_RST_SHIFT)
#define RESET_STATUS1_GPIO_RST(x) ((x) << RESET_STATUS1_GPIO_RST_SHIFT)

/* FLASHB_RST: Status of the FLASHB_RST reset generator output */
#define RESET_STATUS1_FLASHB_RST_SHIFT (26)
#define RESET_STATUS1_FLASHB_RST_MASK (0x3 << RESET_STATUS1_FLASHB_RST_SHIFT)
#define RESET_STATUS1_FLASHB_RST(x) ((x) << RESET_STATUS1_FLASHB_RST_SHIFT)

/* --- RESET_STATUS2 values ------------------------------------- */

/* TIMER0_RST: Status of the TIMER0_RST reset generator output */
#define RESET_STATUS2_TIMER0_RST_SHIFT (0)
#define RESET_STATUS2_TIMER0_RST_MASK (0x3 << RESET_STATUS2_TIMER0_RST_SHIFT)
#define RESET_STATUS2_TIMER0_RST(x) ((x) << RESET_STATUS2_TIMER0_RST_SHIFT)

/* TIMER1_RST: Status of the TIMER1_RST reset generator output */
#define RESET_STATUS2_TIMER1_RST_SHIFT (2)
#define RESET_STATUS2_TIMER1_RST_MASK (0x3 << RESET_STATUS2_TIMER1_RST_SHIFT)
#define RESET_STATUS2_TIMER1_RST(x) ((x) << RESET_STATUS2_TIMER1_RST_SHIFT)

/* TIMER2_RST: Status of the TIMER2_RST reset generator output */
#define RESET_STATUS2_TIMER2_RST_SHIFT (4)
#define RESET_STATUS2_TIMER2_RST_MASK (0x3 << RESET_STATUS2_TIMER2_RST_SHIFT)
#define RESET_STATUS2_TIMER2_RST(x) ((x) << RESET_STATUS2_TIMER2_RST_SHIFT)

/* TIMER3_RST: Status of the TIMER3_RST reset generator output */
#define RESET_STATUS2_TIMER3_RST_SHIFT (6)
#define RESET_STATUS2_TIMER3_RST_MASK (0x3 << RESET_STATUS2_TIMER3_RST_SHIFT)
#define RESET_STATUS2_TIMER3_RST(x) ((x) << RESET_STATUS2_TIMER3_RST_SHIFT)

/* RITIMER_RST: Status of the RITIMER_RST reset generator output */
#define RESET_STATUS2_RITIMER_RST_SHIFT (8)
#define RESET_STATUS2_RITIMER_RST_MASK (0x3 << RESET_STATUS2_RITIMER_RST_SHIFT)
#define RESET_STATUS2_RITIMER_RST(x) ((x) << RESET_STATUS2_RITIMER_RST_SHIFT)

/* SCT_RST: Status of the SCT_RST reset generator output */
#define RESET_STATUS2_SCT_RST_SHIFT (10)
#define RESET_STATUS2_SCT_RST_MASK (0x3 << RESET_STATUS2_SCT_RST_SHIFT)
#define RESET_STATUS2_SCT_RST(x) ((x) << RESET_STATUS2_SCT_RST_SHIFT)

/* MOTOCONPWM_RST: Status of the MOTOCONPWM_RST reset generator output */
#define RESET_STATUS2_MOTOCONPWM_RST_SHIFT (12)
#define RESET_STATUS2_MOTOCONPWM_RST_MASK \
			(0x3 << RESET_STATUS2_MOTOCONPWM_RST_SHIFT)
#define RESET_STATUS2_MOTOCONPWM_RST(x) \
			((x) << RESET_STATUS2_MOTOCONPWM_RST_SHIFT)

/* QEI_RST: Status of the QEI_RST reset generator output */
#define RESET_STATUS2_QEI_RST_SHIFT (14)
#define RESET_STATUS2_QEI_RST_MASK (0x3 << RESET_STATUS2_QEI_RST_SHIFT)
#define RESET_STATUS2_QEI_RST(x) ((x) << RESET_STATUS2_QEI_RST_SHIFT)

/* ADC0_RST: Status of the ADC0_RST reset generator output */
#define RESET_STATUS2_ADC0_RST_SHIFT (16)
#define RESET_STATUS2_ADC0_RST_MASK (0x3 << RESET_STATUS2_ADC0_RST_SHIFT)
#define RESET_STATUS2_ADC0_RST(x) ((x) << RESET_STATUS2_ADC0_RST_SHIFT)

/* ADC1_RST: Status of the ADC1_RST reset generator output */
#define RESET_STATUS2_ADC1_RST_SHIFT (18)
#define RESET_STATUS2_ADC1_RST_MASK (0x3 << RESET_STATUS2_ADC1_RST_SHIFT)
#define RESET_STATUS2_ADC1_RST(x) ((x) << RESET_STATUS2_ADC1_RST_SHIFT)

/* DAC_RST: Status of the DAC_RST reset generator output */
#define RESET_STATUS2_DAC_RST_SHIFT (20)
#define RESET_STATUS2_DAC_RST_MASK (0x3 << RESET_STATUS2_DAC_RST_SHIFT)
#define RESET_STATUS2_DAC_RST(x) ((x) << RESET_STATUS2_DAC_RST_SHIFT)

/* UART0_RST: Status of the UART0_RST reset generator output */
#define RESET_STATUS2_UART0_RST_SHIFT (24)
#define RESET_STATUS2_UART0_RST_MASK (0x3 << RESET_STATUS2_UART0_RST_SHIFT)
#define RESET_STATUS2_UART0_RST(x) ((x) << RESET_STATUS2_UART0_RST_SHIFT)

/* UART1_RST: Status of the UART1_RST reset generator output */
#define RESET_STATUS2_UART1_RST_SHIFT (26)
#define RESET_STATUS2_UART1_RST_MASK (0x3 << RESET_STATUS2_UART1_RST_SHIFT)
#define RESET_STATUS2_UART1_RST(x) ((x) << RESET_STATUS2_UART1_RST_SHIFT)

/* UART2_RST: Status of the UART2_RST reset generator output */
#define RESET_STATUS2_UART2_RST_SHIFT (28)
#define RESET_STATUS2_UART2_RST_MASK (0x3 << RESET_STATUS2_UART2_RST_SHIFT)
#define RESET_STATUS2_UART2_RST(x) ((x) << RESET_STATUS2_UART2_RST_SHIFT)

/* UART3_RST: Status of the UART3_RST reset generator output */
#define RESET_STATUS2_UART3_RST_SHIFT (30)
#define RESET_STATUS2_UART3_RST_MASK (0x3 << RESET_STATUS2_UART3_RST_SHIFT)
#define RESET_STATUS2_UART3_RST(x) ((x) << RESET_STATUS2_UART3_RST_SHIFT)

/* --- RESET_STATUS3 values ------------------------------------- */

/* I2C0_RST: Status of the I2C0_RST reset generator output */
#define RESET_STATUS3_I2C0_RST_SHIFT (0)
#define RESET_STATUS3_I2C0_RST_MASK (0x3 << RESET_STATUS3_I2C0_RST_SHIFT)
#define RESET_STATUS3_I2C0_RST(x) ((x) << RESET_STATUS3_I2C0_RST_SHIFT)

/* I2C1_RST: Status of the I2C1_RST reset generator output */
#define RESET_STATUS3_I2C1_RST_SHIFT (2)
#define RESET_STATUS3_I2C1_RST_MASK (0x3 << RESET_STATUS3_I2C1_RST_SHIFT)
#define RESET_STATUS3_I2C1_RST(x) ((x) << RESET_STATUS3_I2C1_RST_SHIFT)

/* SSP0_RST: Status of the SSP0_RST reset generator output */
#define RESET_STATUS3_SSP0_RST_SHIFT (4)
#define RESET_STATUS3_SSP0_RST_MASK (0x3 << RESET_STATUS3_SSP0_RST_SHIFT)
#define RESET_STATUS3_SSP0_RST(x) ((x) << RESET_STATUS3_SSP0_RST_SHIFT)

/* SSP1_RST: Status of the SSP1_RST reset generator output */
#define RESET_STATUS3_SSP1_RST_SHIFT (6)
#define RESET_STATUS3_SSP1_RST_MASK (0x3 << RESET_STATUS3_SSP1_RST_SHIFT)
#define RESET_STATUS3_SSP1_RST(x) ((x) << RESET_STATUS3_SSP1_RST_SHIFT)

/* I2S_RST: Status of the I2S_RST reset generator output */
#define RESET_STATUS3_I2S_RST_SHIFT (8)
#define RESET_STATUS3_I2S_RST_MASK (0x3 << RESET_STATUS3_I2S_RST_SHIFT)
#define RESET_STATUS3_I2S_RST(x) ((x) << RESET_STATUS3_I2S_RST_SHIFT)

/* SPIFI_RST: Status of the SPIFI_RST reset generator output */
#define RESET_STATUS3_SPIFI_RST_SHIFT (10)
#define RESET_STATUS3_SPIFI_RST_MASK (0x3 << RESET_STATUS3_SPIFI_RST_SHIFT)
#define RESET_STATUS3_SPIFI_RST(x) ((x) << RESET_STATUS3_SPIFI_RST_SHIFT)

/* CAN1_RST: Status of the CAN1_RST reset generator output */
#define RESET_STATUS3_CAN1_RST_SHIFT (12)
#define RESET_STATUS3_CAN1_RST_MASK (0x3 << RESET_STATUS3_CAN1_RST_SHIFT)
#define RESET_STATUS3_CAN1_RST(x) ((x) << RESET_STATUS3_CAN1_RST_SHIFT)

/* CAN0_RST: Status of the CAN0_RST reset generator output */
#define RESET_STATUS3_CAN0_RST_SHIFT (14)
#define RESET_STATUS3_CAN0_RST_MASK (0x3 << RESET_STATUS3_CAN0_RST_SHIFT)
#define RESET_STATUS3_CAN0_RST(x) ((x) << RESET_STATUS3_CAN0_RST_SHIFT)

/* M0APP_RST: Status of the M0APP_RST reset generator output */
#define RESET_STATUS3_M0APP_RST_SHIFT (16)
#define RESET_STATUS3_M0APP_RST_MASK (0x3 << RESET_STATUS3_M0APP_RST_SHIFT)
#define RESET_STATUS3_M0APP_RST(x) ((x) << RESET_STATUS3_M0APP_RST_SHIFT)

/* SGPIO_RST: Status of the SGPIO_RST reset generator output */
#define RESET_STATUS3_SGPIO_RST_SHIFT (18)
#define RESET_STATUS3_SGPIO_RST_MASK (0x3 << RESET_STATUS3_SGPIO_RST_SHIFT)
#define RESET_STATUS3_SGPIO_RST(x) ((x) << RESET_STATUS3_SGPIO_RST_SHIFT)

/* SPI_RST: Status of the SPI_RST reset generator output */
#define RESET_STATUS3_SPI_RST_SHIFT (20)
#define RESET_STATUS3_SPI_RST_MASK (0x3 << RESET_STATUS3_SPI_RST_SHIFT)
#define RESET_STATUS3_SPI_RST(x) ((x) << RESET_STATUS3_SPI_RST_SHIFT)

/* --- RESET_ACTIVE_STATUS0 values ------------------------------ */

/* CORE_RST: Current status of the CORE_RST */
#define RESET_ACTIVE_STATUS0_CORE_RST_SHIFT (0)
#define RESET_ACTIVE_STATUS0_CORE_RST (1 << RESET_ACTIVE_STATUS0_CORE_RST_SHIFT)

/* PERIPH_RST: Current status of the PERIPH_RST */
#define RESET_ACTIVE_STATUS0_PERIPH_RST_SHIFT (1)
#define RESET_ACTIVE_STATUS0_PERIPH_RST \
			(1 << RESET_ACTIVE_STATUS0_PERIPH_RST_SHIFT)

/* MASTER_RST: Current status of the MASTER_RST */
#define RESET_ACTIVE_STATUS0_MASTER_RST_SHIFT (2)
#define RESET_ACTIVE_STATUS0_MASTER_RST \
			(1 << RESET_ACTIVE_STATUS0_MASTER_RST_SHIFT)

/* WWDT_RST: Current status of the WWDT_RST */
#define RESET_ACTIVE_STATUS0_WWDT_RST_SHIFT (4)
#define RESET_ACTIVE_STATUS0_WWDT_RST (1 << RESET_ACTIVE_STATUS0_WWDT_RST_SHIFT)

/* CREG_RST: Current status of the CREG_RST */
#define RESET_ACTIVE_STATUS0_CREG_RST_SHIFT (5)
#define RESET_ACTIVE_STATUS0_CREG_RST (1 << RESET_ACTIVE_STATUS0_CREG_RST_SHIFT)

/* BUS_RST: Current status of the BUS_RST */
#define RESET_ACTIVE_STATUS0_BUS_RST_SHIFT (8)
#define RESET_ACTIVE_STATUS0_BUS_RST (1 << RESET_ACTIVE_STATUS0_BUS_RST_SHIFT)

/* SCU_RST: Current status of the SCU_RST */
#define RESET_ACTIVE_STATUS0_SCU_RST_SHIFT (9)
#define RESET_ACTIVE_STATUS0_SCU_RST (1 << RESET_ACTIVE_STATUS0_SCU_RST_SHIFT)

/* M4_RST: Current status of the M4_RST */
#define RESET_ACTIVE_STATUS0_M4_RST_SHIFT (13)
#define RESET_ACTIVE_STATUS0_M4_RST (1 << RESET_ACTIVE_STATUS0_M4_RST_SHIFT)

/* LCD_RST: Current status of the LCD_RST */
#define RESET_ACTIVE_STATUS0_LCD_RST_SHIFT (16)
#define RESET_ACTIVE_STATUS0_LCD_RST (1 << RESET_ACTIVE_STATUS0_LCD_RST_SHIFT)

/* USB0_RST: Current status of the USB0_RST */
#define RESET_ACTIVE_STATUS0_USB0_RST_SHIFT (17)
#define RESET_ACTIVE_STATUS0_USB0_RST (1 << RESET_ACTIVE_STATUS0_USB0_RST_SHIFT)

/* USB1_RST: Current status of the USB1_RST */
#define RESET_ACTIVE_STATUS0_USB1_RST_SHIFT (18)
#define RESET_ACTIVE_STATUS0_USB1_RST (1 << RESET_ACTIVE_STATUS0_USB1_RST_SHIFT)

/* DMA_RST: Current status of the DMA_RST */
#define RESET_ACTIVE_STATUS0_DMA_RST_SHIFT (19)
#define RESET_ACTIVE_STATUS0_DMA_RST (1 << RESET_ACTIVE_STATUS0_DMA_RST_SHIFT)

/* SDIO_RST: Current status of the SDIO_RST */
#define RESET_ACTIVE_STATUS0_SDIO_RST_SHIFT (20)
#define RESET_ACTIVE_STATUS0_SDIO_RST (1 << RESET_ACTIVE_STATUS0_SDIO_RST_SHIFT)

/* EMC_RST: Current status of the EMC_RST */
#define RESET_ACTIVE_STATUS0_EMC_RST_SHIFT (21)
#define RESET_ACTIVE_STATUS0_EMC_RST (1 << RESET_ACTIVE_STATUS0_EMC_RST_SHIFT)

/* ETHERNET_RST: Current status of the ETHERNET_RST */
#define RESET_ACTIVE_STATUS0_ETHERNET_RST_SHIFT (22)
#define RESET_ACTIVE_STATUS0_ETHERNET_RST \
			(1 << RESET_ACTIVE_STATUS0_ETHERNET_RST_SHIFT)

/* FLASHA_RST: Current status of the FLASHA_RST */
#define RESET_ACTIVE_STATUS0_FLASHA_RST_SHIFT (25)
#define RESET_ACTIVE_STATUS0_FLASHA_RST \
			(1 << RESET_ACTIVE_STATUS0_FLASHA_RST_SHIFT)

/* EEPROM_RST: Current status of the EEPROM_RST */
#define RESET_ACTIVE_STATUS0_EEPROM_RST_SHIFT (27)
#define RESET_ACTIVE_STATUS0_EEPROM_RST \
			(1 << RESET_ACTIVE_STATUS0_EEPROM_RST_SHIFT)

/* GPIO_RST: Current status of the GPIO_RST */
#define RESET_ACTIVE_STATUS0_GPIO_RST_SHIFT (28)
#define RESET_ACTIVE_STATUS0_GPIO_RST (1 << RESET_ACTIVE_STATUS0_GPIO_RST_SHIFT)

/* FLASHB_RST: Current status of the FLASHB_RST */
#define RESET_ACTIVE_STATUS0_FLASHB_RST_SHIFT (29)
#define RESET_ACTIVE_STATUS0_FLASHB_RST \
			(1 << RESET_ACTIVE_STATUS0_FLASHB_RST_SHIFT)

/* --- RESET_ACTIVE_STATUS1 values ------------------------------ */

/* TIMER0_RST: Current status of the TIMER0_RST */
#define RESET_ACTIVE_STATUS1_TIMER0_RST_SHIFT (0)
#define RESET_ACTIVE_STATUS1_TIMER0_RST \
			(1 << RESET_ACTIVE_STATUS1_TIMER0_RST_SHIFT)

/* TIMER1_RST: Current status of the TIMER1_RST */
#define RESET_ACTIVE_STATUS1_TIMER1_RST_SHIFT (1)
#define RESET_ACTIVE_STATUS1_TIMER1_RST \
			(1 << RESET_ACTIVE_STATUS1_TIMER1_RST_SHIFT)

/* TIMER2_RST: Current status of the TIMER2_RST */
#define RESET_ACTIVE_STATUS1_TIMER2_RST_SHIFT (2)
#define RESET_ACTIVE_STATUS1_TIMER2_RST \
			(1 << RESET_ACTIVE_STATUS1_TIMER2_RST_SHIFT)

/* TIMER3_RST: Current status of the TIMER3_RST */
#define RESET_ACTIVE_STATUS1_TIMER3_RST_SHIFT (3)
#define RESET_ACTIVE_STATUS1_TIMER3_RST \
			(1 << RESET_ACTIVE_STATUS1_TIMER3_RST_SHIFT)

/* RITIMER_RST: Current status of the RITIMER_RST */
#define RESET_ACTIVE_STATUS1_RITIMER_RST_SHIFT (4)
#define RESET_ACTIVE_STATUS1_RITIMER_RST \
			(1 << RESET_ACTIVE_STATUS1_RITIMER_RST_SHIFT)

/* SCT_RST: Current status of the SCT_RST */
#define RESET_ACTIVE_STATUS1_SCT_RST_SHIFT (5)
#define RESET_ACTIVE_STATUS1_SCT_RST \
			(1 << RESET_ACTIVE_STATUS1_SCT_RST_SHIFT)

/* MOTOCONPWM_RST: Current status of the MOTOCONPWM_RST */
#define RESET_ACTIVE_STATUS1_MOTOCONPWM_RST_SHIFT (6)
#define RESET_ACTIVE_STATUS1_MOTOCONPWM_RST \
			(1 << RESET_ACTIVE_STATUS1_MOTOCONPWM_RST_SHIFT)

/* QEI_RST: Current status of the QEI_RST */
#define RESET_ACTIVE_STATUS1_QEI_RST_SHIFT (7)
#define RESET_ACTIVE_STATUS1_QEI_RST \
			(1 << RESET_ACTIVE_STATUS1_QEI_RST_SHIFT)

/* ADC0_RST: Current status of the ADC0_RST */
#define RESET_ACTIVE_STATUS1_ADC0_RST_SHIFT (8)
#define RESET_ACTIVE_STATUS1_ADC0_RST \
			(1 << RESET_ACTIVE_STATUS1_ADC0_RST_SHIFT)

/* ADC1_RST: Current status of the ADC1_RST */
#define RESET_ACTIVE_STATUS1_ADC1_RST_SHIFT (9)
#define RESET_ACTIVE_STATUS1_ADC1_RST \
			(1 << RESET_ACTIVE_STATUS1_ADC1_RST_SHIFT)

/* DAC_RST: Current status of the DAC_RST */
#define RESET_ACTIVE_STATUS1_DAC_RST_SHIFT (10)
#define RESET_ACTIVE_STATUS1_DAC_RST (1 << RESET_ACTIVE_STATUS1_DAC_RST_SHIFT)

/* UART0_RST: Current status of the UART0_RST */
#define RESET_ACTIVE_STATUS1_UART0_RST_SHIFT (12)
#define RESET_ACTIVE_STATUS1_UART0_RST \
			(1 << RESET_ACTIVE_STATUS1_UART0_RST_SHIFT)

/* UART1_RST: Current status of the UART1_RST */
#define RESET_ACTIVE_STATUS1_UART1_RST_SHIFT (13)
#define RESET_ACTIVE_STATUS1_UART1_RST \
			(1 << RESET_ACTIVE_STATUS1_UART1_RST_SHIFT)

/* UART2_RST: Current status of the UART2_RST */
#define RESET_ACTIVE_STATUS1_UART2_RST_SHIFT (14)
#define RESET_ACTIVE_STATUS1_UART2_RST \
			(1 << RESET_ACTIVE_STATUS1_UART2_RST_SHIFT)

/* UART3_RST: Current status of the UART3_RST */
#define RESET_ACTIVE_STATUS1_UART3_RST_SHIFT (15)
#define RESET_ACTIVE_STATUS1_UART3_RST \
			(1 << RESET_ACTIVE_STATUS1_UART3_RST_SHIFT)

/* I2C0_RST: Current status of the I2C0_RST */
#define RESET_ACTIVE_STATUS1_I2C0_RST_SHIFT (16)
#define RESET_ACTIVE_STATUS1_I2C0_RST \
			(1 << RESET_ACTIVE_STATUS1_I2C0_RST_SHIFT)

/* I2C1_RST: Current status of the I2C1_RST */
#define RESET_ACTIVE_STATUS1_I2C1_RST_SHIFT (17)
#define RESET_ACTIVE_STATUS1_I2C1_RST \
			(1 << RESET_ACTIVE_STATUS1_I2C1_RST_SHIFT)

/* SSP0_RST: Current status of the SSP0_RST */
#define RESET_ACTIVE_STATUS1_SSP0_RST_SHIFT (18)
#define RESET_ACTIVE_STATUS1_SSP0_RST \
			(1 << RESET_ACTIVE_STATUS1_SSP0_RST_SHIFT)

/* SSP1_RST: Current status of the SSP1_RST */
#define RESET_ACTIVE_STATUS1_SSP1_RST_SHIFT (19)
#define RESET_ACTIVE_STATUS1_SSP1_RST \
			(1 << RESET_ACTIVE_STATUS1_SSP1_RST_SHIFT)

/* I2S_RST: Current status of the I2S_RST */
#define RESET_ACTIVE_STATUS1_I2S_RST_SHIFT (20)
#define RESET_ACTIVE_STATUS1_I2S_RST (1 << RESET_ACTIVE_STATUS1_I2S_RST_SHIFT)

/* SPIFI_RST: Current status of the SPIFI_RST */
#define RESET_ACTIVE_STATUS1_SPIFI_RST_SHIFT (21)
#define RESET_ACTIVE_STATUS1_SPIFI_RST \
			(1 << RESET_ACTIVE_STATUS1_SPIFI_RST_SHIFT)

/* CAN1_RST: Current status of the CAN1_RST */
#define RESET_ACTIVE_STATUS1_CAN1_RST_SHIFT (22)
#define RESET_ACTIVE_STATUS1_CAN1_RST \
			(1 << RESET_ACTIVE_STATUS1_CAN1_RST_SHIFT)

/* CAN0_RST: Current status of the CAN0_RST */
#define RESET_ACTIVE_STATUS1_CAN0_RST_SHIFT (23)
#define RESET_ACTIVE_STATUS1_CAN0_RST \
			(1 << RESET_ACTIVE_STATUS1_CAN0_RST_SHIFT)

/* M0APP_RST: Current status of the M0APP_RST */
#define RESET_ACTIVE_STATUS1_M0APP_RST_SHIFT (24)
#define RESET_ACTIVE_STATUS1_M0APP_RST \
			(1 << RESET_ACTIVE_STATUS1_M0APP_RST_SHIFT)

/* SGPIO_RST: Current status of the SGPIO_RST */
#define RESET_ACTIVE_STATUS1_SGPIO_RST_SHIFT (25)
#define RESET_ACTIVE_STATUS1_SGPIO_RST \
			(1 << RESET_ACTIVE_STATUS1_SGPIO_RST_SHIFT)

/* SPI_RST: Current status of the SPI_RST */
#define RESET_ACTIVE_STATUS1_SPI_RST_SHIFT (26)
#define RESET_ACTIVE_STATUS1_SPI_RST (1 << RESET_ACTIVE_STATUS1_SPI_RST_SHIFT)

/* --- RESET_EXT_STAT0 values ----------------------------------- */

/* EXT_RESET: Reset activated by external reset from reset pin */
#define RESET_EXT_STAT0_EXT_RESET_SHIFT (0)
#define RESET_EXT_STAT0_EXT_RESET (1 << RESET_EXT_STAT0_EXT_RESET_SHIFT)

/* BOD_RESET: Reset activated by BOD reset */
#define RESET_EXT_STAT0_BOD_RESET_SHIFT (4)
#define RESET_EXT_STAT0_BOD_RESET (1 << RESET_EXT_STAT0_BOD_RESET_SHIFT)

/* WWDT_RESET: Reset activated by WWDT time-out */
#define RESET_EXT_STAT0_WWDT_RESET_SHIFT (5)
#define RESET_EXT_STAT0_WWDT_RESET (1 << RESET_EXT_STAT0_WWDT_RESET_SHIFT)

/* --- RESET_EXT_STAT1 values ----------------------------------- */

/* CORE_RESET: Reset activated by CORE_RST output */
#define RESET_EXT_STAT1_CORE_RESET_SHIFT (1)
#define RESET_EXT_STAT1_CORE_RESET (1 << RESET_EXT_STAT1_CORE_RESET_SHIFT)

/* --- RESET_EXT_STAT2 values ----------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT2_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT2_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT2_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT4 values ----------------------------------- */

/* CORE_RESET: Reset activated by CORE_RST output */
#define RESET_EXT_STAT4_CORE_RESET_SHIFT (1)
#define RESET_EXT_STAT4_CORE_RESET (1 << RESET_EXT_STAT4_CORE_RESET_SHIFT)

/* --- RESET_EXT_STAT5 values ----------------------------------- */

/* CORE_RESET: Reset activated by CORE_RST output */
#define RESET_EXT_STAT5_CORE_RESET_SHIFT (1)
#define RESET_EXT_STAT5_CORE_RESET (1 << RESET_EXT_STAT5_CORE_RESET_SHIFT)

/* --- RESET_EXT_STAT8 values ----------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT8_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT8_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT8_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT9 values ----------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT9_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT9_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT9_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT13 values ---------------------------------- */

/* MASTER_RESET: Reset activated by MASTER_RST output */
#define RESET_EXT_STAT13_MASTER_RESET_SHIFT (3)
#define RESET_EXT_STAT13_MASTER_RESET (1 << RESET_EXT_STAT13_MASTER_RESET_SHIFT)

/* --- RESET_EXT_STAT16 values ---------------------------------- */

/* MASTER_RESET: Reset activated by MASTER_RST output */
#define RESET_EXT_STAT16_MASTER_RESET_SHIFT (3)
#define RESET_EXT_STAT16_MASTER_RESET (1 << RESET_EXT_STAT16_MASTER_RESET_SHIFT)

/* --- RESET_EXT_STAT17 values ---------------------------------- */

/* MASTER_RESET: Reset activated by MASTER_RST output */
#define RESET_EXT_STAT17_MASTER_RESET_SHIFT (3)
#define RESET_EXT_STAT17_MASTER_RESET (1 << RESET_EXT_STAT17_MASTER_RESET_SHIFT)

/* --- RESET_EXT_STAT18 values ---------------------------------- */

/* MASTER_RESET: Reset activated by MASTER_RST output */
#define RESET_EXT_STAT18_MASTER_RESET_SHIFT (3)
#define RESET_EXT_STAT18_MASTER_RESET (1 << RESET_EXT_STAT18_MASTER_RESET_SHIFT)

/* --- RESET_EXT_STAT19 values ---------------------------------- */

/* MASTER_RESET: Reset activated by MASTER_RST output */
#define RESET_EXT_STAT19_MASTER_RESET_SHIFT (3)
#define RESET_EXT_STAT19_MASTER_RESET (1 << RESET_EXT_STAT19_MASTER_RESET_SHIFT)

/* --- RESET_EXT_STAT20 values ---------------------------------- */

/* MASTER_RESET: Reset activated by MASTER_RST output */
#define RESET_EXT_STAT20_MASTER_RESET_SHIFT (3)
#define RESET_EXT_STAT20_MASTER_RESET (1 << RESET_EXT_STAT20_MASTER_RESET_SHIFT)

/* --- RESET_EXT_STAT21 values ---------------------------------- */

/* MASTER_RESET: Reset activated by MASTER_RST output */
#define RESET_EXT_STAT21_MASTER_RESET_SHIFT (3)
#define RESET_EXT_STAT21_MASTER_RESET (1 << RESET_EXT_STAT21_MASTER_RESET_SHIFT)

/* --- RESET_EXT_STAT22 values ---------------------------------- */

/* MASTER_RESET: Reset activated by MASTER_RST output */
#define RESET_EXT_STAT22_MASTER_RESET_SHIFT (3)
#define RESET_EXT_STAT22_MASTER_RESET (1 << RESET_EXT_STAT22_MASTER_RESET_SHIFT)

/* --- RESET_EXT_STAT25 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT25_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT25_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT25_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT27 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT27_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT27_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT27_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT28 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT28_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT28_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT28_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT29 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT29_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT29_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT29_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT32 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT32_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT32_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT32_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT33 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT33_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT33_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT33_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT34 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT34_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT34_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT34_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT35 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT35_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT35_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT35_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT36 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT36_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT36_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT36_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT37 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT37_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT37_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT37_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT38 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT38_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT38_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT38_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT39 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT39_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT39_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT39_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT40 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT40_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT40_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT40_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT41 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT41_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT41_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT41_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT42 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT42_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT42_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT42_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT44 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT44_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT44_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT44_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT45 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT45_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT45_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT45_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT46 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT46_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT46_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT46_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT47 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT47_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT47_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT47_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT48 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT48_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT48_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT48_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT49 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT49_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT49_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT49_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT50 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT50_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT50_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT50_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT51 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT51_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT51_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT51_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT52 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT52_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT52_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT52_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT53 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT53_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT53_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT53_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT54 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT54_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT54_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT54_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT55 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT55_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT55_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT55_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT56 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT56_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT56_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT56_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT57 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT57_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT57_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT57_PERIPHERAL_RESET_SHIFT)

/* --- RESET_EXT_STAT58 values ---------------------------------- */

/* PERIPHERAL_RESET: Reset activated by PERIPHERAL_RST output */
#define RESET_EXT_STAT58_PERIPHERAL_RESET_SHIFT (2)
#define RESET_EXT_STAT58_PERIPHERAL_RESET \
			(1 << RESET_EXT_STAT58_PERIPHERAL_RESET_SHIFT)

/**@}*/

#endif

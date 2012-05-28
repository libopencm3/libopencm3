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

#endif

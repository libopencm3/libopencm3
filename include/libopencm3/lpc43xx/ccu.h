/** @defgroup ccu_defines Clock Control Unit Defines

@brief <b>Defined Constants and Types for the LPC43xx Clock Control Unit</b>

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

#ifndef LPC43XX_CCU_H
#define LPC43XX_CCU_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- CCU1 registers ------------------------------------------------------ */

/* CCU1 power mode register */
#define CCU1_PM                         MMIO32(CCU1_BASE + 0x000)

/* CCU1 base clock status register */
#define CCU1_BASE_STAT                  MMIO32(CCU1_BASE + 0x004)

/* CLK_APB3_BUS clock configuration register */
#define CCU1_CLK_APB3_BUS_CFG           MMIO32(CCU1_BASE + 0x100)

/* CLK_APB3_BUS clock status register */
#define CCU1_CLK_APB3_BUS_STAT          MMIO32(CCU1_BASE + 0x104)

/* CLK_APB3_I2C1 configuration register */
#define CCU1_CLK_APB3_I2C1_CFG          MMIO32(CCU1_BASE + 0x108)

/* CLK_APB3_I2C1 status register */
#define CCU1_CLK_APB3_I2C1_STAT         MMIO32(CCU1_BASE + 0x10C)

/* CLK_APB3_DAC configuration register */
#define CCU1_CLK_APB3_DAC_CFG           MMIO32(CCU1_BASE + 0x110)

/* CLK_APB3_DAC status register */
#define CCU1_CLK_APB3_DAC_STAT          MMIO32(CCU1_BASE + 0x114)

/* CLK_APB3_ADC0 configuration register */
#define CCU1_CLK_APB3_ADC0_CFG          MMIO32(CCU1_BASE + 0x118)

/* CLK_APB3_ADC0 status register */
#define CCU1_CLK_APB3_ADC0_STAT         MMIO32(CCU1_BASE + 0x11C)

/* CLK_APB3_ADC1 configuration register */
#define CCU1_CLK_APB3_ADC1_CFG          MMIO32(CCU1_BASE + 0x120)

/* CLK_APB3_ADC1 status register */
#define CCU1_CLK_APB3_ADC1_STAT         MMIO32(CCU1_BASE + 0x124)

/* CLK_APB3_CAN0 configuration register */
#define CCU1_CLK_APB3_CAN0_CFG          MMIO32(CCU1_BASE + 0x128)

/* CLK_APB3_CAN0 status register */
#define CCU1_CLK_APB3_CAN0_STAT         MMIO32(CCU1_BASE + 0x12C)

/* CLK_APB1_BUS configuration register */
#define CCU1_CLK_APB1_BUS_CFG           MMIO32(CCU1_BASE + 0x200)

/* CLK_APB1_BUS status register */
#define CCU1_CLK_APB1_BUS_STAT          MMIO32(CCU1_BASE + 0x204)

/* CLK_APB1_MOTOCON configuration register */
#define CCU1_CLK_APB1_MOTOCONPWM_CFG    MMIO32(CCU1_BASE + 0x208)

/* CLK_APB1_MOTOCON status register */
#define CCU1_CLK_APB1_MOTOCONPWM_STAT   MMIO32(CCU1_BASE + 0x20C)

/* CLK_APB1_I2C0 configuration register */
#define CCU1_CLK_APB1_I2C0_CFG          MMIO32(CCU1_BASE + 0x210)

/* CLK_APB1_I2C0 status register */
#define CCU1_CLK_APB1_I2C0_STAT         MMIO32(CCU1_BASE + 0x214)

/* CLK_APB1_I2S configuration register */
#define CCU1_CLK_APB1_I2S_CFG           MMIO32(CCU1_BASE + 0x218)

/* CLK_APB1_I2S status register */
#define CCU1_CLK_APB1_I2S_STAT          MMIO32(CCU1_BASE + 0x21C)

/* CLK_APB3_CAN1 configuration register */
#define CCU1_CLK_APB1_CAN1_CFG          MMIO32(CCU1_BASE + 0x220)

/* CLK_APB3_CAN1 status register */
#define CCU1_CLK_APB1_CAN1_STAT         MMIO32(CCU1_BASE + 0x224)

/* CLK_SPIFI configuration register */
#define CCU1_CLK_SPIFI_CFG              MMIO32(CCU1_BASE + 0x300)

/* CLK_SPIFI status register */
#define CCU1_CLK_SPIFI_STAT             MMIO32(CCU1_BASE + 0x304)

/* CLK_M4_BUS configuration register */
#define CCU1_CLK_M4_BUS_CFG             MMIO32(CCU1_BASE + 0x400)

/* CLK_M4_BUS status register */
#define CCU1_CLK_M4_BUS_STAT            MMIO32(CCU1_BASE + 0x404)

/* CLK_M4_SPIFI configuration register */
#define CCU1_CLK_M4_SPIFI_CFG           MMIO32(CCU1_BASE + 0x408)

/* CLK_M4_SPIFI status register */
#define CCU1_CLK_M4_SPIFI_STAT          MMIO32(CCU1_BASE + 0x40C)

/* CLK_M4_GPIO configuration register */
#define CCU1_CLK_M4_GPIO_CFG            MMIO32(CCU1_BASE + 0x410)

/* CLK_M4_GPIO status register */
#define CCU1_CLK_M4_GPIO_STAT           MMIO32(CCU1_BASE + 0x414)

/* CLK_M4_LCD configuration register */
#define CCU1_CLK_M4_LCD_CFG             MMIO32(CCU1_BASE + 0x418)

/* CLK_M4_LCD status register */
#define CCU1_CLK_M4_LCD_STAT            MMIO32(CCU1_BASE + 0x41C)

/* CLK_M4_ETHERNET configuration register */
#define CCU1_CLK_M4_ETHERNET_CFG        MMIO32(CCU1_BASE + 0x420)

/* CLK_M4_ETHERNET status register */
#define CCU1_CLK_M4_ETHERNET_STAT       MMIO32(CCU1_BASE + 0x424)

/* CLK_M4_USB0 configuration register */
#define CCU1_CLK_M4_USB0_CFG            MMIO32(CCU1_BASE + 0x428)

/* CLK_M4_USB0 status register */
#define CCU1_CLK_M4_USB0_STAT           MMIO32(CCU1_BASE + 0x42C)

/* CLK_M4_EMC configuration register */
#define CCU1_CLK_M4_EMC_CFG             MMIO32(CCU1_BASE + 0x430)

/* CLK_M4_EMC status register */
#define CCU1_CLK_M4_EMC_STAT            MMIO32(CCU1_BASE + 0x434)

/* CLK_M4_SDIO configuration register */
#define CCU1_CLK_M4_SDIO_CFG            MMIO32(CCU1_BASE + 0x438)

/* CLK_M4_SDIO status register */
#define CCU1_CLK_M4_SDIO_STAT           MMIO32(CCU1_BASE + 0x43C)

/* CLK_M4_DMA configuration register */
#define CCU1_CLK_M4_DMA_CFG             MMIO32(CCU1_BASE + 0x440)

/* CLK_M4_DMA status register */
#define CCU1_CLK_M4_DMA_STAT            MMIO32(CCU1_BASE + 0x444)

/* CLK_M4_M4CORE configuration register */
#define CCU1_CLK_M4_M4CORE_CFG          MMIO32(CCU1_BASE + 0x448)

/* CLK_M4_M4CORE status register */
#define CCU1_CLK_M4_M4CORE_STAT         MMIO32(CCU1_BASE + 0x44C)

/* CLK_M4_SCT configuration register */
#define CCU1_CLK_M4_SCT_CFG             MMIO32(CCU1_BASE + 0x468)

/* CLK_M4_SCT status register */
#define CCU1_CLK_M4_SCT_STAT            MMIO32(CCU1_BASE + 0x46C)

/* CLK_M4_USB1 configuration register */
#define CCU1_CLK_M4_USB1_CFG            MMIO32(CCU1_BASE + 0x470)

/* CLK_M4_USB1 status register */
#define CCU1_CLK_M4_USB1_STAT           MMIO32(CCU1_BASE + 0x474)

/* CLK_M4_EMCDIV configuration register */
#define CCU1_CLK_M4_EMCDIV_CFG          MMIO32(CCU1_BASE + 0x478)

/* CLK_M4_EMCDIV status register */
#define CCU1_CLK_M4_EMCDIV_STAT         MMIO32(CCU1_BASE + 0x47C)

/* CLK_M4_M0_CFG configuration register */
#define CCU1_CLK_M4_M0APP_CFG           MMIO32(CCU1_BASE + 0x490)

/* CLK_M4_M0_STAT status register */
#define CCU1_CLK_M4_M0APP_STAT          MMIO32(CCU1_BASE + 0x494)

/* CLK_M4_VADC_CFG configuration register */
#define CCU1_CLK_M4_VADC_CFG            MMIO32(CCU1_BASE + 0x498)

/* CLK_M4_VADC_STAT configuration register */
#define CCU1_CLK_M4_VADC_STAT           MMIO32(CCU1_BASE + 0x49C)

/* CLK_M4_WWDT configuration register */
#define CCU1_CLK_M4_WWDT_CFG            MMIO32(CCU1_BASE + 0x500)

/* CLK_M4_WWDT status register */
#define CCU1_CLK_M4_WWDT_STAT           MMIO32(CCU1_BASE + 0x504)

/* CLK_M4_UART0 configuration register */
#define CCU1_CLK_M4_USART0_CFG          MMIO32(CCU1_BASE + 0x508)

/* CLK_M4_UART0 status register */
#define CCU1_CLK_M4_USART0_STAT         MMIO32(CCU1_BASE + 0x50C)

/* CLK_M4_UART1 configuration register */
#define CCU1_CLK_M4_UART1_CFG           MMIO32(CCU1_BASE + 0x510)

/* CLK_M4_UART1 status register */
#define CCU1_CLK_M4_UART1_STAT          MMIO32(CCU1_BASE + 0x514)

/* CLK_M4_SSP0 configuration register */
#define CCU1_CLK_M4_SSP0_CFG            MMIO32(CCU1_BASE + 0x518)

/* CLK_M4_SSP0 status register */
#define CCU1_CLK_M4_SSP0_STAT           MMIO32(CCU1_BASE + 0x51C)

/* CLK_M4_TIMER0 configuration register */
#define CCU1_CLK_M4_TIMER0_CFG          MMIO32(CCU1_BASE + 0x520)

/* CLK_M4_TIMER0 status register */
#define CCU1_CLK_M4_TIMER0_STAT         MMIO32(CCU1_BASE + 0x524)

/* CLK_M4_TIMER1 configuration register */
#define CCU1_CLK_M4_TIMER1_CFG          MMIO32(CCU1_BASE + 0x528)

/* CLK_M4_TIMER1 status register */
#define CCU1_CLK_M4_TIMER1_STAT         MMIO32(CCU1_BASE + 0x52C)

/* CLK_M4_SCU configuration register */
#define CCU1_CLK_M4_SCU_CFG             MMIO32(CCU1_BASE + 0x530)

/* CLK_M4_SCU status register */
#define CCU1_CLK_M4_SCU_STAT            MMIO32(CCU1_BASE + 0x534)

/* CLK_M4_CREG configuration register */
#define CCU1_CLK_M4_CREG_CFG            MMIO32(CCU1_BASE + 0x538)

/* CLK_M4_CREG status register */
#define CCU1_CLK_M4_CREG_STAT           MMIO32(CCU1_BASE + 0x53C)

/* CLK_M4_RITIMER configuration register */
#define CCU1_CLK_M4_RITIMER_CFG         MMIO32(CCU1_BASE + 0x600)

/* CLK_M4_RITIMER status register */
#define CCU1_CLK_M4_RITIMER_STAT        MMIO32(CCU1_BASE + 0x604)

/* CLK_M4_UART2 configuration register */
#define CCU1_CLK_M4_USART2_CFG          MMIO32(CCU1_BASE + 0x608)

/* CLK_M4_UART2 status register */
#define CCU1_CLK_M4_USART2_STAT         MMIO32(CCU1_BASE + 0x60C)

/* CLK_M4_UART3 configuration register */
#define CCU1_CLK_M4_USART3_CFG          MMIO32(CCU1_BASE + 0x610)

/* CLK_M4_UART3 status register */
#define CCU1_CLK_M4_USART3_STAT         MMIO32(CCU1_BASE + 0x614)

/* CLK_M4_TIMER2 configuration register */
#define CCU1_CLK_M4_TIMER2_CFG          MMIO32(CCU1_BASE + 0x618)

/* CLK_M4_TIMER2 status register */
#define CCU1_CLK_M4_TIMER2_STAT         MMIO32(CCU1_BASE + 0x61C)

/* CLK_M4_TIMER3 configuration register */
#define CCU1_CLK_M4_TIMER3_CFG          MMIO32(CCU1_BASE + 0x620)

/* CLK_M4_TIMER3 status register */
#define CCU1_CLK_M4_TIMER3_STAT         MMIO32(CCU1_BASE + 0x624)

/* CLK_M4_SSP1 configuration register */
#define CCU1_CLK_M4_SSP1_CFG            MMIO32(CCU1_BASE + 0x628)

/* CLK_M4_SSP1 status register */
#define CCU1_CLK_M4_SSP1_STAT           MMIO32(CCU1_BASE + 0x62C)

/* CLK_M4_QEI configuration register */
#define CCU1_CLK_M4_QEI_CFG             MMIO32(CCU1_BASE + 0x630)

/* CLK_M4_QEI status register */
#define CCU1_CLK_M4_QEI_STAT            MMIO32(CCU1_BASE + 0x634)

/* CLK_PERIPH_BUS configuration register */
#define CCU1_CLK_PERIPH_BUS_CFG         MMIO32(CCU1_BASE + 0x700)

/* CLK_PERIPH_BUS status register */
#define CCU1_CLK_PERIPH_BUS_STAT        MMIO32(CCU1_BASE + 0x704)

/* CLK_PERIPH_CORE configuration register */
#define CCU1_CLK_PERIPH_CORE_CFG        MMIO32(CCU1_BASE + 0x710)

/* CLK_PERIPH_CORE status register */
#define CCU1_CLK_PERIPH_CORE_STAT       MMIO32(CCU1_BASE + 0x714)

/* CLK_PERIPH_SGPIO configuration register */
#define CCU1_CLK_PERIPH_SGPIO_CFG       MMIO32(CCU1_BASE + 0x718)

/* CLK_PERIPH_SGPIO status register */
#define CCU1_CLK_PERIPH_SGPIO_STAT      MMIO32(CCU1_BASE + 0x71C)

/* CLK_USB0 configuration register */
#define CCU1_CLK_USB0_CFG               MMIO32(CCU1_BASE + 0x800)

/* CLK_USB0 status register */
#define CCU1_CLK_USB0_STAT              MMIO32(CCU1_BASE + 0x804)

/* CLK_USB1 configuration register */
#define CCU1_CLK_USB1_CFG               MMIO32(CCU1_BASE + 0x900)

/* CLK_USB1 status register */
#define CCU1_CLK_USB1_STAT              MMIO32(CCU1_BASE + 0x904)

/* CLK_SPI configuration register */
#define CCU1_CLK_SPI_CFG                MMIO32(CCU1_BASE + 0xA00)

/* CLK_SPI status register */
#define CCU1_CLK_SPI_STAT               MMIO32(CCU1_BASE + 0xA04)

/* CLK_VADC configuration register */
#define CCU1_CLK_VADC_CFG               MMIO32(CCU1_BASE + 0xB00)

/* CLK_VADC status register */
#define CCU1_CLK_VADC_STAT              MMIO32(CCU1_BASE + 0xB04)

/* --- CCU2 registers ------------------------------------------------------ */

/* CCU2 power mode register */
#define CCU2_PM                         MMIO32(CCU2_BASE + 0x000)

/* CCU2 base clocks status register */
#define CCU2_BASE_STAT                  MMIO32(CCU2_BASE + 0x004)

/* CLK_APLL configuration register */
#define CCU2_CLK_APLL_CFG               MMIO32(CCU2_BASE + 0x100)

/* CLK_APLL status register */
#define CCU2_CLK_APLL_STAT              MMIO32(CCU2_BASE + 0x104)

/* CLK_APB2_UART3 configuration register */
#define CCU2_CLK_APB2_USART3_CFG        MMIO32(CCU2_BASE + 0x200)

/* CLK_APB2_UART3 status register */
#define CCU2_CLK_APB2_USART3_STAT       MMIO32(CCU2_BASE + 0x204)

/* CLK_APB2_UART2 configuration register */
#define CCU2_CLK_APB2_USART2_CFG        MMIO32(CCU2_BASE + 0x300)

/* CLK_APB2_UART2 status register */
#define CCU2_CLK_APB2_USART2_STAT       MMIO32(CCU2_BASE + 0x304)

/* CLK_APB0_UART1 configuration register */
#define CCU2_CLK_APB0_UART1_CFG         MMIO32(CCU2_BASE + 0x400)

/* CLK_APB0_UART1 status register */
#define CCU2_CLK_APB0_UART1_STAT        MMIO32(CCU2_BASE + 0x404)

/* CLK_APB0_UART0 configuration register */
#define CCU2_CLK_APB0_USART0_CFG        MMIO32(CCU2_BASE + 0x500)

/* CLK_APB0_UART0 status register */
#define CCU2_CLK_APB0_USART0_STAT       MMIO32(CCU2_BASE + 0x504)

/* CLK_APB2_SSP1 configuration register */
#define CCU2_CLK_APB2_SSP1_CFG          MMIO32(CCU2_BASE + 0x600)

/* CLK_APB2_SSP1 status register */
#define CCU2_CLK_APB2_SSP1_STAT         MMIO32(CCU2_BASE + 0x604)

/* CLK_APB0_SSP0 configuration register */
#define CCU2_CLK_APB0_SSP0_CFG          MMIO32(CCU2_BASE + 0x700)

/* CLK_APB0_SSP0 status register */
#define CCU2_CLK_APB0_SSP0_STAT         MMIO32(CCU2_BASE + 0x704)

/* CLK_SDIO configuration register (for SD/MMC) */
#define CCU2_CLK_SDIO_CFG               MMIO32(CCU2_BASE + 0x800)

/* CLK_SDIO status register (for SD/MMC) */
#define CCU2_CLK_SDIO_STAT              MMIO32(CCU2_BASE + 0x804)

/**@}*/

#endif

/** @defgroup pwr_defines Power Defines

@brief <b>Defined Constants and Types for the LPC17xx Power Control</b>

@ingroup LPC17xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2013 Silvio Gissi <silvio.gissi@outlook.com>

@date 17 August 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Silvio Gissi <silvio.gissi@outlook.com>
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

#ifndef LPC17XX_POWER_H
#define LPC17XX_POWER_H

#include <libopencm3/lpc17xx/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- Clock registers ----------------------------------------------------- */
/* Power Control */
#define PWR_PCON			MMIO32(SYSCON_BASE + 0x0c0)
#define PWR_PCONP			MMIO32(SYSCON_BASE + 0x0c4)

/* PWR_PCON Values */
#define PWR_PCON_MODE_SLEEP		0x00
#define PWR_PCON_MODE_POWER_DOWN	0x01
/* PWR_PCON_MODE_RESERVED		0x02*/
#define PWR_PCON_MODE_DEEPSLEEP		0x03
#define PWR_PCON_BODRPM			(1 << 2)
#define PWR_PCON_BOGD			(1 << 3)
#define PWR_PCON_BORD			(1 << 4)
/* Reserved: [7:5] */
#define PWR_PCON_SMFLAG			(1 << 8)
#define PWR_PCON_DSFLAG			(1 << 9)
#define PWR_PCON_PDFLAG			(1 << 10)
#define PWR_PCON_DPDFLAG		(1 << 11)
/* Reserved: [31:12] */

/* PWR_PCONP Values */
/* Reserved: [0] */
#define PWR_PCONP_TIMER0		(1 << 1)
#define PWR_PCONP_TIMER1		(1 << 2)
#define PWR_PCONP_UART0			(1 << 3)
#define PWR_PCONP_UART1			(1 << 4)
/* Reserved: [5] */
#define PWR_PCONP_PWM1			(1 << 6)
#define PWR_PCONP_I2C0			(1 << 7)
#define PWR_PCONP_SPI			(1 << 8)
#define PWR_PCONP_RTC			(1 << 9)
#define PWR_PCONP_SSP1			(1 << 10)
/* Reserved: [11] */
#define PWR_PCONP_ADC			(1 << 12)
#define PWR_PCONP_CAN1			(1 << 13)
#define PWR_PCONP_CAN2			(1 << 14)
#define PWR_PCONP_GPIO			(1 << 15)
#define PWR_PCONP_RIT			(1 << 16)
#define PWR_PCONP_MCPWM			(1 << 17)
#define PWR_PCONP_QEI			(1 << 18)
#define PWR_PCONP_I2C1			(1 << 19)
/* Reserved: [20] */
#define PWR_PCONP_SSP0			(1 << 21)
#define PWR_PCONP_TIMER2		(1 << 22)
#define PWR_PCONP_TIMER3		(1 << 23)
#define PWR_PCONP_UART2			(1 << 24)
#define PWR_PCONP_UART3			(1 << 25)
#define PWR_PCONP_I2C2			(1 << 26)
#define PWR_PCONP_I2S			(1 << 27)
/* Reserved: [28] */
#define PWR_PCONP_GPDMA			(1 << 29)
#define PWR_PCONP_ETHERNET		(1 << 30)
#define PWR_PCONP_USB			(1 << 31)

BEGIN_DECLS

void pwr_enable_peripherals(uint32_t peripherals);
void pwr_disable_peripherals(uint32_t peripherals);
/* TODO Sleep, Deep Sleep, Power Down and Deep Power Down modes */

END_DECLS

#endif

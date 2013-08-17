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
#define PWR_PCON_BODRPM			BIT2
#define PWR_PCON_BOGD			BIT3
#define PWR_PCON_BORD			BIT4
/* Reserved: [7:5] */
#define PWR_PCON_SMFLAG			BIT8
#define PWR_PCON_DSFLAG			BIT9
#define PWR_PCON_PDFLAG			BIT10
#define PWR_PCON_DPDFLAG		BIT11
/* Reserved: [31:12] */

/* PWR_PCONP Values */
/* Reserved: [0] */
#define PWR_PCONP_TIMER0		BIT1
#define PWR_PCONP_TIMER1		BIT2
#define PWR_PCONP_UART0			BIT3
#define PWR_PCONP_UART1			BIT4
/* Reserved: [5] */
#define PWR_PCONP_PWM1			BIT6
#define PWR_PCONP_I2C0			BIT7
#define PWR_PCONP_SPI			BIT8
#define PWR_PCONP_RTC			BIT9
#define PWR_PCONP_SSP1			BIT10
/* Reserved: [11] */
#define PWR_PCONP_ADC			BIT12
#define PWR_PCONP_CAN1			BIT13
#define PWR_PCONP_CAN2			BIT14
#define PWR_PCONP_GPIO			BIT15
#define PWR_PCONP_RIT			BIT16
#define PWR_PCONP_MCPWM			BIT17
#define PWR_PCONP_QEI			BIT18
#define PWR_PCONP_I2C1			BIT19
/* Reserved: [20] */
#define PWR_PCONP_SSP0			BIT21
#define PWR_PCONP_TIMER2		BIT22
#define PWR_PCONP_TIMER3		BIT23
#define PWR_PCONP_UART2			BIT24
#define PWR_PCONP_UART3			BIT25
#define PWR_PCONP_I2C2			BIT26
#define PWR_PCONP_I2S			BIT27
/* Reserved: [28] */
#define PWR_PCONP_GPDMA			BIT29
#define PWR_PCONP_ETHERNET		BIT30
#define PWR_PCONP_USB			BIT31

BEGIN_DECLS

void pwr_enable_peripherals(uint32_t peripherals);
void pwr_disable_peripherals(uint32_t peripherals); 
/* TODO Sleep, Deep Sleep, Power Down and Deep Power Down modes */

END_DECLS

#endif // LPC17XX_POWER_H

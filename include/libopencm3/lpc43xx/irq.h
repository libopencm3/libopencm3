/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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

#ifndef LIBOPENCM3_LPC43XX_IRQ_H
#define LIBOPENCM3_LPC43XX_IRQ_H

#define IRQ_DAC                   0
#define IRQ_M0CORE                1
#define IRQ_DMA                   2
/* reserved:                      3 */
/* reserved:                      4 */
#define IRQ_ETHERNET              5
#define IRQ_SDIO                  6
#define IRQ_LCD                   7
#define IRQ_USB0                  8
#define IRQ_USB1                  9
#define IRQ_SCT                  10
#define IRQ_RITIMER              11
#define IRQ_TIMER0               12
#define IRQ_TIMER1               13
#define IRQ_TIMER2               14
#define IRQ_TIMER3               15
#define IRQ_MCPWM                16
#define IRQ_ADC0                 17
#define IRQ_I2C0                 18
#define IRQ_I2C1                 19
#define IRQ_SPI                  20
#define IRQ_ADC1                 21
#define IRQ_SSP0                 22
#define IRQ_SSP1                 23
#define IRQ_USART0               24
#define IRQ_UART1                25
#define IRQ_USART2               26
#define IRQ_USART3               27
#define IRQ_I2S0                 28
#define IRQ_I2S1                 29
#define IRQ_SPIFI                30
#define IRQ_SGPIO                31
#define IRQ_PIN_INT0             32
#define IRQ_PIN_INT1             33
#define IRQ_PIN_INT2             34
#define IRQ_PIN_INT3             35
#define IRQ_PIN_INT4             36
#define IRQ_PIN_INT5             37
#define IRQ_PIN_INT6             38
#define IRQ_PIN_INT7             39
#define IRQ_GINT0                40
#define IRQ_GINT1                41
#define IRQ_EVENTROUTER          42
#define IRQ_C_CAN1               43
/* reserved:                     44 */
/* reserved:                     45 */
#define IRQ_ATIMER               46
#define IRQ_RTC                  47
/* reserved:                     48 */
#define IRQ_WWDT                 49
/* reserved:                     50 */
#define IRQ_C_CAN0               51
#define IRQ_QEI                  52

#define IRQ_COUNT                53

#define WEAK __attribute__ ((weak))

void WEAK dac_irqhandler(void);
void WEAK m0core_irqhandler(void);
void WEAK dma_irqhandler(void);
void WEAK ethernet_irqhandler(void);
void WEAK sdio_irqhandler(void);
void WEAK lcd_irqhandler(void);
void WEAK usb0_irqhandler(void);
void WEAK usb1_irqhandler(void);
void WEAK sct_irqhandler(void);
void WEAK ritimer_irqhandler(void);
void WEAK timer0_irqhandler(void);
void WEAK timer1_irqhandler(void);
void WEAK timer2_irqhandler(void);
void WEAK timer3_irqhandler(void);
void WEAK mcpwm_irqhandler(void);
void WEAK adc0_irqhandler(void);
void WEAK i2c0_irqhandler(void);
void WEAK i2c1_irqhandler(void);
void WEAK spi_irqhandler(void);
void WEAK adc1_irqhandler(void);
void WEAK ssp0_irqhandler(void);
void WEAK ssp1_irqhandler(void);
void WEAK usart0_irqhandler(void);
void WEAK uart1_irqhandler(void);
void WEAK usart2_irqhandler(void);
void WEAK usart3_irqhandler(void);
void WEAK i2s0_irqhandler(void);
void WEAK i2s1_irqhandler(void);
void WEAK spifi_irqhandler(void);
void WEAK sgpio_irqhandler(void);
void WEAK pin_int0_irqhandler(void);
void WEAK pin_int1_irqhandler(void);
void WEAK pin_int2_irqhandler(void);
void WEAK pin_int3_irqhandler(void);
void WEAK pin_int4_irqhandler(void);
void WEAK pin_int5_irqhandler(void);
void WEAK pin_int6_irqhandler(void);
void WEAK pin_int7_irqhandler(void);
void WEAK gint0_irqhandler(void);
void WEAK gint1_irqhandler(void);
void WEAK eventrouter_irqhandler(void);
void WEAK c_can1_irqhandler(void);
void WEAK atimer_irqhandler(void);
void WEAK rtc_irqhandler(void);
void WEAK wwdt_irqhandler(void);
void WEAK c_can0_irqhandler(void);
void WEAK qei_irqhandler(void);

#pragma weak dac_irqhandler = null_handler
#pragma weak m0core_irqhandler = null_handler
#pragma weak dma_irqhandler = null_handler
#pragma weak ethernet_irqhandler = null_handler
#pragma weak sdio_irqhandler = null_handler
#pragma weak lcd_irqhandler = null_handler
#pragma weak usb0_irqhandler = null_handler
#pragma weak usb1_irqhandler = null_handler
#pragma weak sct_irqhandler = null_handler
#pragma weak ritimer_irqhandler = null_handler
#pragma weak timer0_irqhandler = null_handler
#pragma weak timer1_irqhandler = null_handler
#pragma weak timer2_irqhandler = null_handler
#pragma weak timer3_irqhandler = null_handler
#pragma weak mcpwm_irqhandler = null_handler
#pragma weak adc0_irqhandler = null_handler
#pragma weak i2c0_irqhandler = null_handler
#pragma weak i2c1_irqhandler = null_handler
#pragma weak spi_irqhandler = null_handler
#pragma weak adc1_irqhandler = null_handler
#pragma weak ssp0_irqhandler = null_handler
#pragma weak ssp1_irqhandler = null_handler
#pragma weak usart0_irqhandler = null_handler
#pragma weak uart1_irqhandler = null_handler
#pragma weak usart2_irqhandler = null_handler
#pragma weak usart3_irqhandler = null_handler
#pragma weak i2s0_irqhandler = null_handler
#pragma weak i2s1_irqhandler = null_handler
#pragma weak spifi_irqhandler = null_handler
#pragma weak sgpio_irqhandler = null_handler
#pragma weak pin_int0_irqhandler = null_handler
#pragma weak pin_int1_irqhandler = null_handler
#pragma weak pin_int2_irqhandler = null_handler
#pragma weak pin_int3_irqhandler = null_handler
#pragma weak pin_int4_irqhandler = null_handler
#pragma weak pin_int5_irqhandler = null_handler
#pragma weak pin_int6_irqhandler = null_handler
#pragma weak pin_int7_irqhandler = null_handler
#pragma weak gint0_irqhandler = null_handler
#pragma weak gint1_irqhandler = null_handler
#pragma weak eventrouter_irqhandler = null_handler
#pragma weak c_can1_irqhandler = null_handler
#pragma weak atimer_irqhandler = null_handler
#pragma weak rtc_irqhandler = null_handler
#pragma weak wwdt_irqhandler = null_handler
#pragma weak c_can0_irqhandler = null_handler
#pragma weak qei_irqhandler = null_handler

#define IRQ_HANDLERS \
	dac_irqhandler, \
	m0core_irqhandler, \
	dma_irqhandler, \
	0, /* reserved */ \
	0, /* reserved */ \
	ethernet_irqhandler, \
	sdio_irqhandler, \
	lcd_irqhandler, \
	usb0_irqhandler, \
	usb1_irqhandler, \
	sct_irqhandler, \
	ritimer_irqhandler, \
	timer0_irqhandler, \
	timer1_irqhandler, \
	timer2_irqhandler, \
	timer3_irqhandler, \
	mcpwm_irqhandler, \
	adc0_irqhandler, \
	i2c0_irqhandler, \
	i2c1_irqhandler, \
	spi_irqhandler, \
	adc1_irqhandler, \
	ssp0_irqhandler, \
	ssp1_irqhandler, \
	usart0_irqhandler, \
	uart1_irqhandler, \
	usart2_irqhandler, \
	usart3_irqhandler, \
	i2s0_irqhandler, \
	i2s1_irqhandler, \
	spifi_irqhandler, \
	sgpio_irqhandler, \
	pin_int0_irqhandler, \
	pin_int1_irqhandler, \
	pin_int2_irqhandler, \
	pin_int3_irqhandler, \
	pin_int4_irqhandler, \
	pin_int5_irqhandler, \
	pin_int6_irqhandler, \
	pin_int7_irqhandler, \
	gint0_irqhandler, \
	gint1_irqhandler, \
	eventrouter_irqhandler, \
	c_can1_irqhandler, \
	0, /* reserved */ \
	0, /* reserved */ \
	atimer_irqhandler, \
	rtc_irqhandler, \
	0, /* reserved */ \
	wwdt_irqhandler, \
	0, /* reserved */ \
	c_can0_irqhandler, \
	qei_irqhandler,

#endif

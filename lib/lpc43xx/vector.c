/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
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

#define WEAK __attribute__ ((weak))

/* Symbols exported by the linker script(s): */
extern unsigned _data_loadaddr, _data, _edata, _ebss, _stack;
extern unsigned _etext_ram, _text_ram, _etext_rom;

void main(void);
void reset_handler(void);
void blocking_handler(void);
void null_handler(void);

void WEAK nmi_handler(void);
void WEAK hard_fault_handler(void);
void WEAK mem_manage_handler(void);
void WEAK bus_fault_handler(void);
void WEAK usage_fault_handler(void);
void WEAK sv_call_handler(void);
void WEAK debug_monitor_handler(void);
void WEAK pend_sv_handler(void);
void WEAK sys_tick_handler(void);
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

__attribute__ ((section(".vectors")))
void (*const vector_table[]) (void) = {
	/* Cortex-M4 interrupts */
	(void*)&_stack,
	reset_handler,
	nmi_handler,
	hard_fault_handler,
	mem_manage_handler,
	bus_fault_handler,
	usage_fault_handler,
	0, 0, 0, 0, /* reserved */
	sv_call_handler,
	debug_monitor_handler,
	0, /* reserved */
	pend_sv_handler,
	sys_tick_handler,

	/* LPC43xx interrupts */
	dac_irqhandler,
	m0core_irqhandler,
	dma_irqhandler,
	0, /* reserved */
	0, /* reserved */
	ethernet_irqhandler,
	sdio_irqhandler,
	lcd_irqhandler,
	usb0_irqhandler,
	usb1_irqhandler,
	sct_irqhandler,
	ritimer_irqhandler,
	timer0_irqhandler,
	timer1_irqhandler,
	timer2_irqhandler,
	timer3_irqhandler,
	mcpwm_irqhandler,
	adc0_irqhandler,
	i2c0_irqhandler,
	i2c1_irqhandler,
	spi_irqhandler,
	adc1_irqhandler,
	ssp0_irqhandler,
	ssp1_irqhandler,
	usart0_irqhandler,
	uart1_irqhandler,
	usart2_irqhandler,
	usart3_irqhandler,
	i2s0_irqhandler,
	i2s1_irqhandler,
	spifi_irqhandler,
	sgpio_irqhandler,
	pin_int0_irqhandler,
	pin_int1_irqhandler,
	pin_int2_irqhandler,
	pin_int3_irqhandler,
	pin_int4_irqhandler,
	pin_int5_irqhandler,
	pin_int6_irqhandler,
	pin_int7_irqhandler,
	gint0_irqhandler,
	gint1_irqhandler,
	eventrouter_irqhandler,
	c_can1_irqhandler,
	0, /* reserved */
	0, /* reserved */
	atimer_irqhandler,
	rtc_irqhandler,
	0, /* reserved */
	wwdt_irqhandler,
	0, /* reserved */
	c_can0_irqhandler,
	qei_irqhandler,
};

#define MMIO32(addr)    (*(volatile unsigned long*)(addr))
#define CREG_M4MEMMAP   MMIO32( (0x40043000 + 0x100) )

void reset_handler(void)
{
	volatile unsigned *src, *dest;

	__asm__("MSR msp, %0" : : "r"(&_stack));

	/* Copy the code from ROM to Real RAM (if enabled) */
	if( (&_etext_ram-&_text_ram) > 0 )
	{
		src = &_etext_rom-(&_etext_ram-&_text_ram);
		/* Change Shadow memory to ROM (for Debug Purpose in case Boot has not set correctly the M4MEMMAP because of debug) */
		CREG_M4MEMMAP = (unsigned long)src;

		for(dest = &_text_ram; dest < &_etext_ram; )
		{
			*dest++ = *src++;
		}

		/* Change Shadow memory to Real RAM */
		CREG_M4MEMMAP = (unsigned long)&_text_ram;

		/* Continue Execution in RAM */
	}

	for (src = &_data_loadaddr, dest = &_data; dest < &_edata; src++, dest++)
		*dest = *src;

	while (dest < &_ebss)
		*dest++ = 0;

	/* Call the application's entry point. */
	main();
}

void blocking_handler(void)
{
	while (1) ;
}

void null_handler(void)
{
	/* Do nothing. */
}

#pragma weak nmi_handler = null_handler
#pragma weak hard_fault_handler = blocking_handler
#pragma weak mem_manage_handler = blocking_handler
#pragma weak bus_fault_handler = blocking_handler
#pragma weak usage_fault_handler = blocking_handler
#pragma weak sv_call_handler = null_handler
#pragma weak debug_monitor_handler = null_handler
#pragma weak pend_sv_handler = null_handler
#pragma weak sys_tick_handler = null_handler
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

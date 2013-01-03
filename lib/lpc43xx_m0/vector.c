/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>,
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
 * Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#define WEAK __attribute__ ((weak))

/* Symbols exported by the linker script(s): */
extern unsigned _bss, _ebss, _stack;

void main(void);
void blocking_handler(void);
void null_handler(void);

void WEAK reset_handler(void);
void WEAK nmi_handler(void);
void WEAK hard_fault_handler(void);
void WEAK mem_manage_handler(void);
void WEAK bus_fault_handler(void);
void WEAK usage_fault_handler(void);
void WEAK sv_call_handler(void);
void WEAK debug_monitor_handler(void);
void WEAK pend_sv_handler(void);

void WEAK m0_rtc_isr(void);
void WEAK m0_m4core_isr(void);
void WEAK m0_dma_isr(void);
void WEAK m0_ethernet_isr(void);
void WEAK m0_flasheepromat_isr(void);
void WEAK m0_sdio_isr(void);
void WEAK m0_lcd_isr(void);
void WEAK m0_usb0_isr(void);
void WEAK m0_usb1_isr(void);
void WEAK m0_sct_isr(void);
void WEAK m0_ritimer_or_wwdt_isr(void);
void WEAK m0_timer0_isr(void);
void WEAK m0_gint1_isr(void);
void WEAK m0_pin_int4_isr(void);
void WEAK m0_timer3_isr(void);
void WEAK m0_mcpwm_isr(void);
void WEAK m0_adc0_isr(void);
void WEAK m0_i2c0_or_i2c1_isr(void);
void WEAK m0_sgpio_isr(void);
void WEAK m0_spi_or_dac_isr(void);
void WEAK m0_adc1_isr(void);
void WEAK m0_ssp0_or_ssp1_isr(void);
void WEAK m0_eventrouter_isr(void);
void WEAK m0_usart0_isr(void);
void WEAK m0_uart1_isr(void);
void WEAK m0_usart2_or_c_can1_isr(void);
void WEAK m0_usart3_isr(void);
void WEAK m0_i2s0_or_i2s1_isr(void);
void WEAK m0_c_can0_isr(void);

/* Initialization template for the interrupt vector table. This definition is
 * used by the startup code generator (vector.c) to set the initial values for
 * the interrupt handling routines to the chip family specific _isr weak
 * symbols. */
/* See UserManual LPC43xx rev1_4 UM10503 Table 26. Connection of interrupt sources to the Cortex-M0 NVIC */

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
	0, /* sys_tick_handler not supported on LPC4330 M0 */

	/* IrqID 0 , ExcNo 16 */ m0_rtc_isr,
	/* IrqID 1 , ExcNo 17 */ m0_m4core_isr,
	/* IrqID 2 , ExcNo 18 */ m0_dma_isr,
	/* IrqID 3 , ExcNo 19 */ 0, 
	/* IrqID 4 , ExcNo 20 */ m0_flasheepromat_isr,
	/* IrqID 5 , ExcNo 21 */ m0_ethernet_isr,
	/* IrqID 6 , ExcNo 22 */ m0_sdio_isr,
	/* IrqID 7 , ExcNo 23 */ m0_lcd_isr,
	/* IrqID 8 , ExcNo 24 */ m0_usb0_isr,
	/* IrqID 9 , ExcNo 25 */ m0_usb1_isr,
	/* IrqID 10, ExcNo 26 */ m0_sct_isr,
	/* IrqID 11, ExcNo 27 */ m0_ritimer_or_wwdt_isr,
	/* IrqID 12, ExcNo 28 */ m0_timer0_isr,
	/* IrqID 13, ExcNo 29 */ m0_gint1_isr,
	/* IrqID 14, ExcNo 30 */ m0_pin_int4_isr,
	/* IrqID 15, ExcNo 31 */ m0_timer3_isr, 
	/* IrqID 16, ExcNo 32 */ m0_mcpwm_isr,
	/* IrqID 17, ExcNo 33 */ m0_adc0_isr,
	/* IrqID 18, ExcNo 34 */ m0_i2c0_or_i2c1_isr,
	/* IrqID 19, ExcNo 35 */ m0_sgpio_isr,
	/* IrqID 20, ExcNo 36 */ m0_spi_or_dac_isr,
	/* IrqID 21, ExcNo 37 */ m0_adc1_isr,
	/* IrqID 22, ExcNo 38 */ m0_ssp0_or_ssp1_isr,
	/* IrqID 23, ExcNo 39 */ m0_eventrouter_isr,
	/* IrqID 24, ExcNo 40 */ m0_usart0_isr,
	/* IrqID 25, ExcNo 41 */ m0_uart1_isr,
	/* IrqID 26, ExcNo 42 */ m0_usart2_or_c_can1_isr,
	/* IrqID 27, ExcNo 43 */ m0_usart3_isr,
	/* IrqID 28, ExcNo 44 */ m0_i2s0_or_i2s1_isr,
	/* IrqID 29, ExcNo 45 */ m0_c_can0_isr,
	/* IrqID 30, ExcNo 46 */ 0, 
	/* IrqID 31, ExcNo 47 */ 0
};

#define MMIO32(addr)    (*(volatile unsigned long*)(addr))
#define CREG_M0APPMAP   MMIO32( (0x40043404) )

void WEAK reset_handler(void)
{
	volatile unsigned long *dest;
	volatile unsigned long *src;
	__asm__("MSR msp, %0" : : "r"(&_stack));

	src = (unsigned long*)&vector_table;
	/* Change Shadow memory to RAM (vector table) to have access to Vector Table from virtual adr 0x0 */
	CREG_M0APPMAP = (unsigned long)src;

	/* Data does not need to be copied as M4 have already copied the whole bin including code+data */

	/* Set BSS */
	for (dest = (unsigned long*)(&_bss); dest < (unsigned long*)(&_ebss); )
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

/* M0 */
#pragma weak m0_rtc_isr = blocking_handler
#pragma weak m0_m4core_isr = blocking_handler
#pragma weak m0_dma_isr = blocking_handler
#pragma weak m0_flasheepromat_isr = blocking_handler
#pragma weak m0_ethernet_isr = blocking_handler
#pragma weak m0_sdio_isr = blocking_handler
#pragma weak m0_lcd_isr = blocking_handler
#pragma weak m0_usb0_isr = blocking_handler
#pragma weak m0_usb1_isr = blocking_handler
#pragma weak m0_sct_isr = blocking_handler
#pragma weak m0_ritimer_or_wwdt_isr = blocking_handler
#pragma weak m0_timer0_isr = blocking_handler
#pragma weak m0_gint1_isr = blocking_handler
#pragma weak m0_pin_int4_isr = blocking_handler
#pragma weak m0_timer3_isr = blocking_handler
#pragma weak m0_mcpwm_isr = blocking_handler
#pragma weak m0_adc0_isr = blocking_handler
#pragma weak m0_i2c0_or_i2c1_isr = blocking_handler
#pragma weak m0_sgpio_isr = blocking_handler
#pragma weak m0_spi_or_dac_isr = blocking_handler
#pragma weak m0_adc1_isr = blocking_handler
#pragma weak m0_ssp0_or_ssp1_isr = blocking_handler
#pragma weak m0_eventrouter_isr = blocking_handler
#pragma weak m0_usart0_isr = blocking_handler
#pragma weak m0_uart1_isr = blocking_handler
#pragma weak m0_usart2_or_c_can1_isr = blocking_handler
#pragma weak m0_usart3_isr = blocking_handler
#pragma weak m0_i2s0_or_i2s1_isr = blocking_handler
#pragma weak m0_c_can0_isr = blocking_handler

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
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

/* TODO: Interrupt handler prototypes */

__attribute__ ((section(".vectors")))
void (*const vector_table[]) (void) = {
	(void*)&_stack,		/* Addr: 0x0000_0000 */
	reset_handler,		/* Addr: 0x0000_0004 */
	nmi_handler,		/* Addr: 0x0000_0008 */
	hard_fault_handler,	/* Addr: 0x0000_000C */
	mem_manage_handler,	/* Addr: 0x0000_0010 */
	bus_fault_handler,	/* Addr: 0x0000_0014 */
	usage_fault_handler,	/* Addr: 0x0000_0018 */
	0, 0, 0, 0,		/* Reserved Addr: 0x0000_001C - 0x0000_002B */
	sv_call_handler,	/* Addr: 0x0000_002C */
	debug_monitor_handler,	/* Addr: 0x0000_0030 */
	0,			/* Reserved Addr: 0x0000_00034 */
	pend_sv_handler,	/* Addr: 0x0000_0038 */
	sys_tick_handler,	/* Addr: 0x0000_003C */
};


void reset_handler(void)
{
	volatile unsigned *src, *dest;

	__asm__("MSR msp, %0" : : "r"(&_stack));

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
/* TODO: Interrupt handler weak aliases */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>,
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
 * Copyright (C) 2020 Lubomir Rintel <lkundrak@v3.sk>
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

#include <libopencm3/gd32v/vector.h>
#include <libopencm3/gd32v/eclic.h>

/* load optional platform dependent initialization routines */
#include "../dispatch/vector_chipset.c"
/* load the weak symbols for IRQ_HANDLERS */
#include "../dispatch/vector_nvic.c"

int main(void);
void reset_handler(void);
void blocking_handler(void);
void null_handler(void);

static void __attribute__((naked, noreturn)) start(void)
{
	__attribute__ ((section(".vectors")))
	static struct vector_table_t vector_table = {
		.sv_call = sv_call_handler,
		.systick = sys_tick_handler,
		.bus_fault = bus_fault_handler,
		.performance_monitor = performance_monitor_handler,
		.irq = {
			IRQ_HANDLERS
		}
	};
	unsigned *src, *dest;
	funcp_t *fp;

	/* Initialize stack pointer. Stack must not be used before this. */
	__asm__ ("add sp, sp, %0" : : "r"(_stack));

	/* Set interrupt vector table. */
	__asm__ ("csrs 0x307, %0" : : "rK"((void *)&vector_table - 0xc));

	/* Set trap handler and enable ECLIC. */
	__asm__ ("csrs mtvec, %0" : : "rK"((uint32_t)blocking_handler | 0x03));

	for (src = &_data_loadaddr, dest = &_data;
		dest < &_edata;
		src++, dest++) {
		*dest = *src;
	}

	while (dest < &_ebss) {
		*dest++ = 0;
	}

	eclic_init(NVIC_IRQ_COUNT);

	/* might be provided by platform specific vector.c */
	pre_main();

	/* Constructors. */
	for (fp = &__preinit_array_start; fp < &__preinit_array_end; fp++) {
		(*fp)();
	}
	for (fp = &__init_array_start; fp < &__init_array_end; fp++) {
		(*fp)();
	}

	/* Enable interrupts. */
	__asm__ ("csrs mstatus, %0" : : "rK"(0x00000008));

	/* Call the application's entry point. */
	(void)main();

	/* Destructors. */
	for (fp = &__fini_array_start; fp < &__fini_array_end; fp++) {
		(*fp)();
	}

	while (1);
}

void __attribute__((naked, no_instrument_function,
		    noreturn, section(".reset"))) reset_handler(void)
{
	start();
}

void __attribute__((interrupt, aligned(64))) blocking_handler(void)
{
	while (1);
}

void __attribute__((interrupt)) null_handler(void)
{
	/* Do nothing. */
}

#pragma weak sv_call_handler = null_handler
#pragma weak sys_tick_handler = null_handler
#pragma weak bus_fault_handler = blocking_handler
#pragma weak performance_monitor_handler = null_handler

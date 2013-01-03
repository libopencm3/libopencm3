/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
 * Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
 * Copyright (C) 2012 Jared Boone <jared@sharebrained.com>
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

/* Generic linker script for LPC43XX targets using libopencm3. */

/* Memory regions must be defined in the ld script which includes this one. */

/* Enforce emmition of the vector table. */
EXTERN (vector_table)

/* Define the entry point of the output file. */
ENTRY(reset_handler)

/* Define sections. */
SECTIONS
{
	. = ORIGIN(ram_ahb2);

	.text : {
		. = ALIGN(0x400);
		*(.vectors)	/* Vector table */
		*(.text*)	/* Program code */
		. = ALIGN(4);
		*(.rodata*)	/* Read-only data */
		. = ALIGN(4);
	} >ram_ahb2

	/* exception index - required due to libgcc.a issuing /0 exceptions */
	__exidx_start = .;
	.ARM.exidx : {
		*(.ARM.exidx*)
	} > ram_ahb2
	__exidx_end = .;

	_etext = .;

	. = ORIGIN(ram_ahb2);
	
	.data : {
		*(.data*)	/* Read-write initialized data */
		. = ALIGN(4);
	} >ram_ahb2

	_data = .;
	_edata = .;

	.bss : {
	   _bss = .;
		*(.bss*)	/* Read-write zero initialized data */
		*(COMMON)
		. = ALIGN(4);
	   _ebss = .;
	} >ram_ahb2

	/* exception unwind data - required due to libgcc.a issuing /0 exceptions */
	.ARM.extab : {
		*(.ARM.extab*)
	} >ram_ahb2

	/*
	 * The .eh_frame section appears to be used for C++ exception handling.
	 * You may need to fix this if you're using C++.
	 */
	/DISCARD/ : { *(.eh_frame) }

	/*
	 * Another section used by C++ stuff, appears when using newlib with
	 * 64bit (long long) printf support - discard it for now.
	 */
	/DISCARD/ : { *(.ARM.exidx) }

	end = .;

	/* Leave room above stack for IAP to run. */
	__StackTop = ORIGIN(ram_ahb2) + LENGTH(ram_ahb2) - 32;
	PROVIDE(_stack = __StackTop);
}

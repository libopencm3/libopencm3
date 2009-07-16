/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

/* Linker script for Olimex STM32-H103 (STM32F103RBT6, 128K flash, 20K RAM). */

/* Define memory regions. */
MEMORY
{
	rom (rx) : ORIGIN = 0x00000000, LENGTH = 128K
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

/* Define sections. */
SECTIONS
{
	. = ORIGIN(rom);

	.text : {
		*(.text)	/* Program code */
		*(.rodata)	/* Read-only data */
	} >rom

	. = ORIGIN(ram);

	.data : {
		*(.data)	/* Read-write initialized data */
	} >ram AT >rom

	.bss : {
		*(.bss)		/* Read-write zero initialized data */
	} >ram AT >rom

	/* Discard useless sections. */
	/DISCARD/ : {
		*(.comment)
		*(.comment.*)
		*(.note)
		*(.note.*)
	}
}

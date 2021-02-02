/*
 * This file is part of the libopencm3 project.
 *
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

/** @file
 *
 * Definitions for handling vector tables.
 *
 * This implements GD32VF103 User Manual's Table 6-1 [1].
 * [1] https://github.com/riscv-mcu/GD32VF103_DataSheets/raw/83802112/GD32VF103_User_Manual_EN_V1.0.pdf
 */

#ifndef LIBOPENCM3_VECTOR_H
#define LIBOPENCM3_VECTOR_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/gd32v/eclic.h>

/** Type of an interrupt function. Only used to avoid hard-to-read function
 * pointers in the vector_table_t struct. */
typedef void (*vector_table_entry_t)(void);

struct vector_table_t {
	/* vector_table_entry_t reserved_x0000[3];
	 * The first three unused entries are not specified and the linker
	 * script offsets the table by 0xc bytes. This is because on a GD32
	 * the execution starts at address 0x00000000 where the flash is
	 * aliased but the vector table alignment requirement (512 byte)
	 * make it a good idea to also place it at the very beginning.
	 * Therefore the unused bits are used for a jump to the actual
	 * initialization routine. */
	vector_table_entry_t sv_call;
	vector_table_entry_t reserved_x0010[3];
	vector_table_entry_t systick;
	vector_table_entry_t reserved_x0020[9];
	vector_table_entry_t bus_fault;
	vector_table_entry_t performance_monitor;
	vector_table_entry_t irq[NVIC_IRQ_COUNT];
};

/* Symbols exported by the linker script(s): */
extern unsigned _data_loadaddr, _data, _edata, _ebss, _stack;
typedef void (*funcp_t) (void);
extern funcp_t __preinit_array_start, __preinit_array_end;
extern funcp_t __init_array_start, __init_array_end;
extern funcp_t __fini_array_start, __fini_array_end;

#endif

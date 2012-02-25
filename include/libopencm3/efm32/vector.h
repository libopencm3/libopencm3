/* this implements d0002_efm32_cortex-m3_reference_manual.pdf's figure 2.2.
 *
 * the structure of the vector table is implemented independently of the vector
 * table, as it can be relocated to other memory locations too.
 *
 * don't include this file directly; rather, include the family's vector.h
 * file, which defines the number of interrupts (EFM_VECTOR_NIRQ) from table
 * 1.1 */

#ifndef LIBOPENCM3_EFM32_VECTOR_H
#define LIBOPENCM3_EFM32_VECTOR_H

#include <libopencm3/cm3/common.h>

typedef void (*efm32_vector_table_entry_t)(void);

typedef struct {
	unsigned int *initial_sp_value;
	efm32_vector_table_entry_t reset;
	efm32_vector_table_entry_t nmi;
	efm32_vector_table_entry_t hard_fault;
	efm32_vector_table_entry_t memory_manage_fault;
	efm32_vector_table_entry_t bus_fault;
	efm32_vector_table_entry_t usage_fault;
	efm32_vector_table_entry_t reserved_x001c[4];
	efm32_vector_table_entry_t sv_call;
	efm32_vector_table_entry_t reserved_debug;
	efm32_vector_table_entry_t reserved_x0034;
	efm32_vector_table_entry_t pend_sv;
	efm32_vector_table_entry_t systick;
	efm32_vector_table_entry_t irq[EFM32_VECTOR_NIRQ];
} efm32_vector_table_t;

#endif

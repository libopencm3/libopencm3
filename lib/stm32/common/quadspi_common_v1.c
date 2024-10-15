/** @addtogroup quadspi_file QUADSPI peripheral API
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2016
Chuck McManis <cmcmanis@mcmanis.com>
@author @htmlonly &copy; @endhtmlonly 2024
Roman Buchert <libopencm3@ro-bu.net>

@section  quadspi_common Notes for QUADSPI

This library supports basic access to the QUADSPI registers.

Pay attention, that some function must only be called, when the busy flag is not set.

Further improvements will be taken to provide high level functions for configuration
and data transfer.
*/

#include <libopencm3/stm32/quadspi.h>

void quadspi_enable(void)
{
	QUADSPI_CR |= QUADSPI_CR_EN;
}

void quadspi_disable(void)
{
	QUADSPI_CR &= ~QUADSPI_CR_EN;
}

bool quadspi_is_busy(void)
{
	return (QUADSPI_SR & QUADSPI_SR_BUSY) ? 1 : 0;
}

void quadspi_wait_while_busy(void)
{
	while (quadspi_is_busy()) {
		;
	}
}

void quadspi_abort(void)
{
	QUADSPI_CR |= QUADSPI_CR_ABORT;

	/* Wait for abort is finished. Descriped in Section 14.3.14 on RM0385 Rev 8*/
	while ((QUADSPI_CR & QUADSPI_CR_ABORT)) {
		;
	}
	quadspi_wait_while_busy();
}

void quadspi_set_prescaler(uint8_t prescaler)
{
	uint32_t reg_value = QUADSPI_CR;
	reg_value &= ~(QUADSPI_CR_PRESCALE_MASK << QUADSPI_CR_PRESCALE_SHIFT);
	reg_value |= ((uint32_t)prescaler << QUADSPI_CR_PRESCALE_SHIFT);
	QUADSPI_CR = reg_value;
}

void quadspi_enable_irq(uint32_t irq)
{
	QUADSPI_CR |= irq;
}

void quadspi_disable_irq(uint32_t irq)
{
	QUADSPI_CR &= ~irq;
}

bool quadspi_get_flag(uint32_t flag)
{
	return (bool)((QUADSPI_SR & flag) ? 1 : 0);
}

uint8_t quadspi_get_fifo_level(void)
{
	return (uint8_t)((QUADSPI_SR >> QUADSPI_SR_FLEVEL_SHIFT) & QUADSPI_SR_FLEVEL_MASK);
}

void quadspi_clear_flag(uint32_t flag)
{
	QUADSPI_FCR |= flag;
}

void quadspi_set_data_length(uint32_t data_length)
{
	QUADSPI_FCR = data_length;
}

void quadspi_set_double_datarate_mode(bool set)
{

	if (set == QUADSPI_CCR_DDRM_ENABLE)	{
		QUADSPI_CCR |= QUADSPI_CCR_DDRM;
	} else {
		QUADSPI_CCR &= ~QUADSPI_CCR_DDRM;
	}
}

void quadspi_set_ddr_hold(bool set)
{
	if (set == QUADSPI_CCR_DHHC_1_4_CLK) {
		QUADSPI_CCR |= QUADSPI_CCR_DHHC;
	} else {
		QUADSPI_CCR &= ~QUADSPI_CCR_DHHC;
	}
}

void quadspi_set_instruction_only_once_mode(bool set)
{
	if (set == QUADSPI_CCR_SIOO_ONCE) {
		QUADSPI_CCR |= QUADSPI_CCR_SIOO;
	} else {
		QUADSPI_CCR &= ~QUADSPI_CCR_SIOO;
	}
}

void quadspi_set_funcion_mode(uint32_t mode)
{
	uint32_t reg_val = QUADSPI_CCR;
	reg_val &= ~(QUADSPI_CCR_FMODE_MASK << QUADSPI_CCR_FMODE_SHIFT);
	reg_val |= (mode & QUADSPI_CCR_FMODE_MASK) << QUADSPI_CCR_FMODE_SHIFT;
	QUADSPI_CCR = reg_val;
}

void quadspi_set_data_mode(uint32_t mode)
{
	uint32_t reg_val = QUADSPI_CCR;
	reg_val &= ~(QUADSPI_CCR_DMODE_MASK << QUADSPI_CCR_DMODE_SHIFT);
	reg_val |= (mode & QUADSPI_CCR_DMODE_MASK) << QUADSPI_CCR_DMODE_SHIFT;
	QUADSPI_CCR = reg_val;
}

void quadspi_set_dummy_cycles(uint32_t cycles)
{
	uint32_t reg_val = QUADSPI_CCR;
	reg_val &= ~(QUADSPI_CCR_DCYC_MASK << QUADSPI_CCR_DCYC_SHIFT);
	reg_val |= (cycles & QUADSPI_CCR_DCYC_MASK) << QUADSPI_CCR_DCYC_SHIFT;
	QUADSPI_CCR = reg_val;
}

void quadspi_set_alternate_byte_size(uint32_t size)
{
	uint32_t reg_val = QUADSPI_CCR;
	reg_val &= ~(QUADSPI_CCR_ABSIZE_MASK << QUADSPI_CCR_ABSIZE_SHIFT);
	reg_val |= (size & QUADSPI_CCR_ABSIZE_MASK) << QUADSPI_CCR_ABSIZE_SHIFT;
	QUADSPI_CCR = reg_val;
}

void quadspi_set_alternate_byte_mode(uint32_t mode)
{
	uint32_t reg_val = QUADSPI_CCR;
	reg_val &= ~(QUADSPI_CCR_ABMODE_MASK << QUADSPI_CCR_ABMODE_SHIFT);
	reg_val |= (mode & QUADSPI_CCR_ABMODE_MASK) << QUADSPI_CCR_ABMODE_SHIFT;
	QUADSPI_CCR = reg_val;
}

void quadspi_set_address_size(uint32_t size)
{
	uint32_t reg_val = QUADSPI_CCR;
	reg_val &= ~(QUADSPI_CCR_ADSIZE_MASK << QUADSPI_CCR_ADSIZE_SHIFT);
	reg_val |= (size & QUADSPI_CCR_ADSIZE_MASK) << QUADSPI_CCR_ADSIZE_SHIFT;
	QUADSPI_CCR = reg_val;
}

void quadspi_set_address_mode(uint32_t mode)
{
	uint32_t reg_val = QUADSPI_CCR;
	reg_val &= ~(QUADSPI_CCR_ADMODE_MASK << QUADSPI_CCR_ADMODE_SHIFT);
	reg_val |= (mode & QUADSPI_CCR_ADMODE_MASK) << QUADSPI_CCR_ADMODE_SHIFT;
	QUADSPI_CCR = reg_val;
}

void quadspi_set_instruction_mode(uint32_t mode)
{
	uint32_t reg_val = QUADSPI_CCR;
	reg_val &= ~(QUADSPI_CCR_IMODE_MASK << QUADSPI_CCR_IMODE_SHIFT);
	reg_val |= (mode & QUADSPI_CCR_IMODE_MASK) << QUADSPI_CCR_IMODE_SHIFT;
	QUADSPI_CCR = reg_val;
}

void quadspi_send_instruction(uint8_t instruction)
{
	uint32_t reg_val = QUADSPI_CCR;
	reg_val &= ~(QUADSPI_CCR_INST_MASK << QUADSPI_CCR_INST_SHIFT);
	reg_val |= (instruction & QUADSPI_CCR_INST_MASK) << QUADSPI_CCR_INST_SHIFT;
	QUADSPI_CCR = reg_val;
}

void quadspi_set_address(uint32_t address)
{
	QUADSPI_AR = address;
}

void quadspi_set_alternate_byte(uint32_t data)
{
	QUADSPI_ABR = data;
}

void quadspi_write_byte(uint8_t data)
{
	QUADSPI_DR = data;
}

void quadspi_write_halfword(uint16_t data)
{
	QUADSPI_DR = data;
}

void quadspi_write_word(uint32_t data)
{
	QUADSPI_DR = data;
}

uint8_t quadspi_read_byte(void)
{
	return (uint8_t) QUADSPI_DR;
}

uint16_t quadspi_read_halfword(void)
{
	return (uint16_t) QUADSPI_DR;
}

uint32_t quadspi_read_word(void)
{
	return (uint32_t) QUADSPI_DR;
}


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
#include <stddef.h>

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

void quadspi_select_flash(uint32_t flash)
{
	uint32_t reg_value = QUADSPI_CR;
	reg_value &= (QUADPSI_CR_DFM_FSEL_MASK << QUADSPI_CR_DFM_FSEL_SHIFT);
	reg_value |= ((flash & QUADPSI_CR_DFM_FSEL_MASK) << QUADSPI_CR_DFM_FSEL_SHIFT);
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

void quadspi_set_alternative_bytes_size(uint32_t size)
{
	uint32_t reg_val = QUADSPI_CCR;
	reg_val &= ~(QUADSPI_CCR_ABSIZE_MASK << QUADSPI_CCR_ABSIZE_SHIFT);
	reg_val |= (size & QUADSPI_CCR_ABSIZE_MASK) << QUADSPI_CCR_ABSIZE_SHIFT;
	QUADSPI_CCR = reg_val;
}

void quadspi_set_alternative_bytes_mode(uint32_t mode)
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

void quadspi_set_alternative_bytes(uint32_t data)
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

uint32_t quadspi_set_bus_frequency(uint32_t ahb_frequency, uint32_t bus_frequency)
{
	uint32_t real_bus_frequency = -1;
	uint32_t prescaler;

	if (!quadspi_is_busy()) {
		prescaler = ahb_frequency / bus_frequency;

		/* QuadSPI bus freq = ahb_frequency / (prescaler +1) */
		if (prescaler) {
			prescaler--;
		}
		quadspi_set_prescaler(prescaler);

		prescaler = QUADSPI_CR;
		prescaler >>= QUADSPI_CR_PRESCALE_SHIFT;
		prescaler &= QUADSPI_CR_PRESCALE_MASK;
		if (prescaler < 255) {
			prescaler++;
		}

		real_bus_frequency = ahb_frequency / (prescaler);
	}
	return real_bus_frequency;
}

uint32_t quadspi_write(struct quadspi_command *command, const void *buffer, uint32_t buffer_size)
{
	uint32_t result = (uint32_t) -1;
	/* Check parameter.
		Do only something if:
		* Pointer to command is not a NULL-pointer and
		* Pointer to buffer is not NULL when buffer_size >0
	 */
	if ((command != NULL) && ((buffer != NULL) || (buffer_size == 0))) {
		while (quadspi_is_busy());
		/* 1. Step: Set QUADSPI-mode to indirect write mode */
		quadspi_set_funcion_mode(QUADSPI_CCR_FMODE_IWRITE);

		/* 2. Step: Configure modes so that the interface knows wich part to send. */
		quadspi_set_instruction_mode(command->instruction.mode);
		quadspi_set_address_mode(command->address.mode);
		quadspi_set_alternative_bytes_mode(command->alternative_bytes.mode);
		quadspi_set_dummy_cycles(command->dummy_cycles.mode);

		/* 3. Step: Load alternative bytes, dummy cycles and address, if used. */
		if (command->alternative_bytes.mode != QUADSPI_CCR_MODE_NONE) {
			quadspi_set_alternative_bytes_size(command->alternative_bytes.size);
			quadspi_set_alternative_bytes(command->alternative_bytes.value);
		}

		if (command->dummy_cycles.mode != QUADSPI_CCR_MODE_NONE) {
			quadspi_set_dummy_cycles(command->dummy_cycles.cycles);
		}

		if (command->address.mode != QUADSPI_CCR_MODE_NONE) {
			quadspi_set_address_size(command->address.size);
			quadspi_set_address(command->address.address);
		}

		/* 4. Step: Load instruction */
		if (command->instruction.mode != QUADSPI_CCR_MODE_NONE) {
			quadspi_send_instruction(command->instruction.instruction);
		}

		/* 5. Step: Send data */
		if (buffer_size) {
			for (result = 0; result < buffer_size; result++) {
				while (quadspi_is_busy());
				quadspi_write_byte((uint8_t)*((uint8_t *)buffer++));
			}
			result--;
		}
	}

	return result;
}

uint32_t quadspi_read(struct quadspi_command *command, void *buffer, uint32_t buffer_size)
{
	uint32_t result = (uint32_t) -1;
	/* Check parameter.
		Do only something if:
		* Pointer to command is not a NULL-pointer and
		* Pointer to buffer is not NULL when buffer_size >0
	 */
	if ((command != NULL) && ((buffer != NULL) || (buffer_size == 0))) {
		while (quadspi_is_busy());
		/* 1. Step: Set QUADSPI-mode to indirect read mode */
		quadspi_set_funcion_mode(QUADSPI_CCR_FMODE_IREAD);

		/* 2. Step: Configure modes so that the interface knows wich part to send. */
		quadspi_set_instruction_mode(command->instruction.mode);
		quadspi_set_address_mode(command->address.mode);
		quadspi_set_alternative_bytes_mode(command->alternative_bytes.mode);
		quadspi_set_dummy_cycles(command->dummy_cycles.mode);

		/* 3. Step: Load alternative bytes, dummy cycles and address, if used. */
		if (command->alternative_bytes.mode != QUADSPI_CCR_MODE_NONE) {
			quadspi_set_alternative_bytes_size(command->alternative_bytes.size);
			quadspi_set_alternative_bytes(command->alternative_bytes.value);
		}

		if (command->dummy_cycles.mode != QUADSPI_CCR_MODE_NONE) {
			quadspi_set_dummy_cycles(command->dummy_cycles.cycles);
		}

		if (command->address.mode != QUADSPI_CCR_MODE_NONE) {
			quadspi_set_address_size(command->address.size);
			quadspi_set_address(command->address.address);
		}

		/* 4. Step: Load instruction */
		if (command->instruction.mode != QUADSPI_CCR_MODE_NONE) {
			quadspi_send_instruction(command->instruction.instruction);
		}

		/* 5. Step: Read data */
		if (buffer_size) {
			for (result = 0; result < buffer_size; result++) {
				while (quadspi_is_busy());
				*((uint8_t *)buffer++) = quadspi_read_byte();
			}
			result--;
		}
	}

	return result;
}

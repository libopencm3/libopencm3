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
		__asm__ volatile("nop");
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

void quadspi_set_threshold_level(uint32_t level)
{
	uint32_t reg_value = QUADSPI_CR;
	reg_value &= ~(QUADSPI_CR_FTHRES_MASK << QUADSPI_CR_FTHRES_SHIFT);
	reg_value |= (level & QUADSPI_CR_FTHRES_MASK) << QUADSPI_CR_FTHRES_SHIFT;
	QUADSPI_CR = reg_value;
}

void quadspi_select_flash(uint32_t flash)
{
	uint32_t reg_value = QUADSPI_CR;
	reg_value &= ~(QUADPSI_CR_DFM_FSEL_MASK << QUADSPI_CR_DFM_FSEL_SHIFT);
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

void quadspi_set_clock_mode(uint32_t mode)
{
	uint32_t reg_val = QUADSPI_DCR;
	reg_val &= ~(QUADSPI_DCR_CKMODE);
	reg_val |= (mode & QUADSPI_DCR_CKMODE);
	QUADSPI_DCR = reg_val;
}

void quadspi_set_cs_high_time(uint32_t cycles)
{
	uint32_t reg_val = QUADSPI_DCR;
	reg_val &= ~(QUADSPI_DCR_CSHT_MASK << QUADSPI_DCR_CSHT_SHIFT);
	reg_val |= (cycles & QUADSPI_DCR_CSHT_MASK) << QUADSPI_DCR_CSHT_SHIFT;
	QUADSPI_DCR = reg_val;
}


void quadspi_set_flash_size(uint32_t flash_size)
{
	uint32_t reg_val = QUADSPI_DCR;
	reg_val &= ~(QUADSPI_DCR_FSIZE_MASK << QUADSPI_DCR_FSIZE_SHIFT);
	reg_val |= (flash_size & QUADSPI_DCR_FSIZE_MASK) << QUADSPI_DCR_FSIZE_SHIFT;
	QUADSPI_DCR = reg_val;
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
	QUADSPI_DLR = data_length;
}

uint32_t quadspi_prepare_double_datarate_mode(uint32_t ccr, bool set)
{

	if (set == QUADSPI_CCR_DDRM_ENABLE)	{
		ccr |= QUADSPI_CCR_DDRM;
	} else {
		ccr &= ~QUADSPI_CCR_DDRM;
	}
	return ccr;
}

uint32_t quadspi_prepare_ddr_hold(uint32_t ccr, bool set)
{
	if (set == QUADSPI_CCR_DHHC_1_4_CLK) {
		ccr |= QUADSPI_CCR_DHHC;
	} else {
		ccr &= ~QUADSPI_CCR_DHHC;
	}
	return ccr;
}

uint32_t quadspi_prepare_instruction_only_once_mode(uint32_t ccr, bool set)
{
	if (set == QUADSPI_CCR_SIOO_ONCE) {
		ccr |= QUADSPI_CCR_SIOO;
	} else {
		ccr &= ~QUADSPI_CCR_SIOO;
	}
	return ccr;
}

uint32_t quadspi_prepare_funcion_mode(uint32_t ccr, uint32_t mode)
{
	ccr &= ~(QUADSPI_CCR_FMODE_MASK << QUADSPI_CCR_FMODE_SHIFT);
	ccr |= (mode & QUADSPI_CCR_FMODE_MASK) << QUADSPI_CCR_FMODE_SHIFT;
	return ccr;
}

uint32_t quadspi_prepare_data_mode(uint32_t ccr, uint32_t mode)
{
	ccr &= ~(QUADSPI_CCR_DMODE_MASK << QUADSPI_CCR_DMODE_SHIFT);
	ccr |= (mode & QUADSPI_CCR_DMODE_MASK) << QUADSPI_CCR_DMODE_SHIFT;
	return ccr;
}

uint32_t quadspi_prepare_dummy_cycles(uint32_t ccr, uint32_t cycles)
{
	ccr &= ~(QUADSPI_CCR_DCYC_MASK << QUADSPI_CCR_DCYC_SHIFT);
	ccr |= (cycles & QUADSPI_CCR_DCYC_MASK) << QUADSPI_CCR_DCYC_SHIFT;
	return ccr;
}

uint32_t quadspi_prepare_alternative_bytes_size(uint32_t ccr, uint32_t size)
{
	ccr &= ~(QUADSPI_CCR_ABSIZE_MASK << QUADSPI_CCR_ABSIZE_SHIFT);
	ccr |= (size & QUADSPI_CCR_ABSIZE_MASK) << QUADSPI_CCR_ABSIZE_SHIFT;
	return ccr;
}

uint32_t quadspi_prepare_alternative_bytes_mode(uint32_t ccr, uint32_t mode)
{
	ccr &= ~(QUADSPI_CCR_ABMODE_MASK << QUADSPI_CCR_ABMODE_SHIFT);
	ccr |= (mode & QUADSPI_CCR_ABMODE_MASK) << QUADSPI_CCR_ABMODE_SHIFT;
	return ccr;
}

uint32_t quadspi_prepare_address_size(uint32_t ccr, uint32_t size)
{
	ccr &= ~(QUADSPI_CCR_ADSIZE_MASK << QUADSPI_CCR_ADSIZE_SHIFT);
	ccr |= (size & QUADSPI_CCR_ADSIZE_MASK) << QUADSPI_CCR_ADSIZE_SHIFT;
	return ccr;
}

uint32_t quadspi_prepare_address_mode(uint32_t ccr, uint32_t mode)
{
	ccr &= ~(QUADSPI_CCR_ADMODE_MASK << QUADSPI_CCR_ADMODE_SHIFT);
	ccr |= (mode & QUADSPI_CCR_ADMODE_MASK) << QUADSPI_CCR_ADMODE_SHIFT;
	return ccr;
}

uint32_t quadspi_prepare_instruction_mode(uint32_t ccr, uint32_t mode)
{
	ccr &= ~(QUADSPI_CCR_IMODE_MASK << QUADSPI_CCR_IMODE_SHIFT);
	ccr |= (mode & QUADSPI_CCR_IMODE_MASK) << QUADSPI_CCR_IMODE_SHIFT;
	return ccr;
}

uint32_t quadspi_prepare_instruction(uint32_t ccr, uint8_t instruction)
{
	ccr &= ~(QUADSPI_CCR_INST_MASK << QUADSPI_CCR_INST_SHIFT);
	ccr |= (instruction & QUADSPI_CCR_INST_MASK) << QUADSPI_CCR_INST_SHIFT;
	return ccr;
}

void quadspi_write_ccr(uint32_t value)
{
	QUADSPI_CCR = value;
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
	volatile uint32_t *data_reg = (volatile uint32_t *)&QUADSPI_DR;
	uint8_t *byte_buffer = (uint8_t *) buffer;

	/* Check parameter.
		Do only something if:
		* Pointer to command is not a NULL-pointer and
		* Pointer to buffer is not NULL when buffer_size >0
	 */
	if ((command != NULL) && ((buffer != NULL) || (buffer_size == 0))) {
		uint32_t ccr = 0;
		/* Step 1: Prepare QUADSPI_CCR-register */
		if (command->instruction.mode != QUADSPI_CCR_MODE_NONE) {
			ccr = quadspi_prepare_instruction_mode(ccr, command->instruction.mode);
			ccr = quadspi_prepare_instruction(ccr, command->instruction.instruction);
		}

		if (command->address.mode != QUADSPI_CCR_MODE_NONE) {
			ccr = quadspi_prepare_address_mode(ccr, command->address.mode);
			ccr = quadspi_prepare_address_size(ccr, command->address.size);
		}

		if (command->alternative_bytes.mode != QUADSPI_CCR_MODE_NONE) {
			ccr = quadspi_prepare_alternative_bytes_mode(
				ccr,
			command->alternative_bytes.mode);
			ccr = quadspi_prepare_alternative_bytes_size(
				ccr,
			command->alternative_bytes.size);
			quadspi_set_alternative_bytes(command->alternative_bytes.value);
		}

		if (command->dummy_cycles) {
			ccr = quadspi_prepare_dummy_cycles(ccr, command->dummy_cycles);
		}

		if ((buffer_size) && (command->data_mode != QUADSPI_CCR_MODE_NONE)) {
			ccr = quadspi_prepare_data_mode(ccr, command->data_mode);
			quadspi_set_data_length(buffer_size - 1);
		}
		ccr = quadspi_prepare_funcion_mode(ccr, QUADSPI_CCR_FMODE_IREAD);

		/* Step 2: Write QUADSPI_CCR-register */
		quadspi_write_ccr(ccr);

		/* Step 3: Write address, if necessary */
		if (command->address.mode != QUADSPI_CCR_MODE_NONE) {
			quadspi_set_address(command->address.address);
		}

		/* Step 4: Send data */
		if (buffer_size) {
			for (result = 0; result < buffer_size; result++) {
				uint32_t flags;
				do {
					flags = QUADSPI_SR & (QUADSPI_SR_FTF | QUADSPI_SR_TCF);
				} while (!flags);
				*((volatile uint8_t *) data_reg) = *(byte_buffer++);
			}
		}
	}
	return result;
}

uint32_t quadspi_read(struct quadspi_command *command, void *buffer, uint32_t buffer_size)
{
	uint32_t result = (uint32_t) -1;
	volatile uint32_t *data_reg = (volatile uint32_t *)&QUADSPI_DR;
	uint8_t *byte_buffer = (uint8_t *) buffer;

	/* Check parameter.
		Do only something if:
		* Pointer to command is not a NULL-pointer and
		* Pointer to buffer is not NULL when buffer_size >0
	 */
	if ((command != NULL) && ((buffer != NULL) || (buffer_size == 0))) {
		uint32_t ccr = 0;
		/* Step 1: Prepare QUADSPI_CCR-register */
		if (command->instruction.mode != QUADSPI_CCR_MODE_NONE) {
			ccr = quadspi_prepare_instruction_mode(ccr, command->instruction.mode);
			ccr = quadspi_prepare_instruction(ccr, command->instruction.instruction);
		}

		if (command->address.mode != QUADSPI_CCR_MODE_NONE) {
			ccr = quadspi_prepare_address_mode(ccr, command->address.mode);
			ccr = quadspi_prepare_address_size(ccr, command->address.size);
		}

		if (command->alternative_bytes.mode != QUADSPI_CCR_MODE_NONE) {
			ccr = quadspi_prepare_alternative_bytes_mode(
				ccr,
			command->alternative_bytes.mode);
			ccr = quadspi_prepare_alternative_bytes_size(
				ccr,
			command->alternative_bytes.size);
			quadspi_set_alternative_bytes(command->alternative_bytes.value);
		}

		if (command->dummy_cycles) {
			ccr = quadspi_prepare_dummy_cycles(ccr, command->dummy_cycles);
		}

		if ((buffer_size) && (command->data_mode != QUADSPI_CCR_MODE_NONE)) {
			ccr = quadspi_prepare_data_mode(ccr, command->data_mode);
			quadspi_set_data_length(buffer_size - 1);
		}
		ccr = quadspi_prepare_funcion_mode(ccr, QUADSPI_CCR_FMODE_IREAD);

		/* Step 2: Write QUADSPI_CCR-register */
		quadspi_write_ccr(ccr);

		/* Step 3: Write address, if necessary */
		if (command->address.mode != QUADSPI_CCR_MODE_NONE) {
			quadspi_set_address(command->address.address);
		}

		/* Step 4: Read data */
		if (buffer_size) {
			for (result = 0; result < buffer_size; result++) {
				uint32_t flags;
				do {
					flags = QUADSPI_SR & (QUADSPI_SR_FTF | QUADSPI_SR_TCF);
				} while (!flags);
				*(byte_buffer++) = *((volatile uint8_t *) data_reg);
			}
		}
	}
	return result;
}

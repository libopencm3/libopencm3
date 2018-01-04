#include <libopencm3/stm32/sdio.h>
#include <libopencm3/stm32/rcc.h>

void sdio_deinit()
{
	rcc_periph_reset_pulse(RST_SDIO);
}

void sdio_config(SDIO_config *config)
{
	uint32_t reg_val = SDIO_CLKCR;

	reg_val &= SDIO_CLKCR_CLEAR_MASK;

	if(config->polarity == SDIO_CK_FALLING_EDGE)
		reg_val |= SDIO_CLKCR_NEGEDGE;

	if(config->flow_control)
		reg_val |= SDIO_CLKCR_HWFC_EN;

	if(config->bypass)
		reg_val |= SDIO_CLKCR_BYPASS;

	if(config->power_save)
		reg_val |= SDIO_CLKCR_PWRSAV;

	reg_val |= (uint32_t)config->bus_wide;
	reg_val |= (uint32_t)config->clock_divider;

	SDIO_CLKCR = reg_val;
}

void sdio_ck_enable()
{
	SDIO_CLKCR |= SDIO_CLKCR_CLKEN;
}

void sdio_ck_disable()
{
	SDIO_CLKCR &= ~SDIO_CLKCR_CLKEN;
}

void sdio_enable()
{
	SDIO_POWER = SDIO_POWER_PWRCTRL_PWRON;
}

void sdio_disable()
{
	SDIO_POWER = SDIO_POWER_PWRCTRL_PWROFF;
}

void sdio_send_command(SDIO_command *cmd)
{
	SDIO_ARG = cmd->arg;

	uint32_t reg_val = SDIO_CMD;

	reg_val &= SDIO_CMD_CLEAR_MASK;

	reg_val |= cmd->index;
	reg_val |= cmd->response;

	switch(cmd->wait)
	{
		case WAIT_NO:
			break;
		case WAIT_IT:
			reg_val |= SDIO_CMD_WAITINT;
			break;
		case WAIT_PEND:
			reg_val |= SDIO_CMD_WAITPEND;
			break;
	}

	if (cmd->enable_CPSM)
		reg_val |= SDIO_CMD_CPSMEN;

	SDIO_CMD = reg_val;
}

uint8_t sdio_get_cmd_response()
{
	return (uint8_t)(SDIO_RESPCMD);
}

uint32_t sdio_get_card_status_1()
{
	return SDIO_RESP1;
}

uint32_t sdio_get_card_status_2()
{
	return SDIO_RESP2;
}

uint32_t sdio_get_card_status_3()
{
	return SDIO_RESP3;
}

uint32_t sdio_get_card_status_4()
{
	return SDIO_RESP4;
}

void sdio_data_config(SDIO_data_config *config)
{
	SDIO_DTIMER = config->period;
	SDIO_DLEN = config->length;

	uint32_t tmpreg = SDIO_DCTRL;

	tmpreg &= SDIO_DCTRL_CLEAR_MASK;

	tmpreg |= config->size;

	if (config->direction == CARD_TO_CONTROLLER)
		tmpreg |= SDIO_DCTRL_DTDIR;

	if (config->mode == STREAM_DATA_TRANSFER)
		tmpreg |= SDIO_DCTRL_DTMODE;

	if (config->enable)
		tmpreg |= SDIO_DCTRL_DTEN;

	SDIO_DCTRL = tmpreg;
}

uint32_t sdio_get_data_counter(void)
{
	return (SDIO_DCOUNT);
}

uint32_t sdio_read_fifo_data(void)
{
	return (SDIO_FIFO);
}

void sdio_write_fifo_data(uint32_t data)
{
	SDIO_FIFO = data;
}

uint32_t sdio_get_fifo_counter(void)
{
	return (SDIO_FIFOCNT);
}

void sdio_read_wait_start_enable(void)
{
	SDIO_DCTRL |= SDIO_DCTRL_RWSTART;
}

void sdio_read_wait_start_disable(void)
{
	SDIO_DCTRL &= ~SDIO_DCTRL_RWSTART;
}

void sdio_read_wait_stop_enable(void)
{
	SDIO_DCTRL |= SDIO_DCTRL_RWSTOP;
}

void sdio_read_wait_stop_disable(void)
{
	SDIO_DCTRL &= ~SDIO_DCTRL_RWSTOP;
}

void sdio_set_read_wait_mode(SDIO_ReadWaitMode mode)
{
	switch(mode)
	{
		case READ_WAIT_DATA2:
			SDIO_DCTRL &= ~SDIO_DCTRL_RWMOD;
			break;
		case READ_WAIT_CLK:
			SDIO_DCTRL |= SDIO_DCTRL_RWMOD;
			break;
	}
}

void sdio_operation_enable(void)
{
	SDIO_DCTRL |= SDIO_DCTRL_SDIOEN;
}

void sdio_operation_disable(void)
{
	SDIO_DCTRL &= ~SDIO_DCTRL_SDIOEN;
}

void sdio_suspend_cmd_enable(void)
{
	SDIO_CMD |= SDIO_CMD_SDIOSUSPEND;
}

void sdio_suspend_cmd_disable(void)
{
	SDIO_CMD &= ~SDIO_CMD_SDIOSUSPEND;
}

void sdio_completion_cmd_enable(void)
{
	SDIO_CMD |= SDIO_CMD_ENCMDCOMPL;
}

void sdio_completion_cmd_disable(void)
{
	SDIO_CMD &= ~SDIO_CMD_ENCMDCOMPL;
}

void sdio_CEATA_interrupt_enable(void)
{
	SDIO_CMD &= ~SDIO_CMD_NIEN;
}

void sdio_CEATA_interrupt_disable(void)
{
	SDIO_CMD |= SDIO_CMD_NIEN;
}

void sdio_CEATA_cmd_enable(void)
{
	SDIO_CMD |= SDIO_CMD_ATACMD;
}

void sdio_CEATA_cmd_disable(void)
{
	SDIO_CMD &= ~SDIO_CMD_ATACMD;
}

void sdio_enable_dma(void)
{
	SDIO_DCTRL |= SDIO_DCTRL_DMAEN;
}

void sdio_disable_dma(void)
{
	SDIO_DCTRL &= ~SDIO_DCTRL_DMAEN;
}

void sdio_enable_interrupt(uint32_t interrupt)
{
	SDIO_MASK |= interrupt;
}

void sdio_disable_interrupt(uint32_t interrupt)
{
	SDIO_MASK &= ~interrupt;
}

bool sdio_get_flag_status(uint32_t flag)
{
	if ((SDIO_STA & flag) != 0)
		return true;
	else
		return false;
}

void sdio_clear_flag_status(uint32_t flag)
{
	SDIO_ICR = flag;
}

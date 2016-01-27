#include <stdint.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/cm3/memorymap.h>
#include <libopencm3/cm3/itm.h>
#include "trace.h"

void trace_send_blocking8(int stimulus_port, char c)
{
	if (!(ITM_TER[0] & (1<<stimulus_port))) {
		return;
	}
	while (!(ITM_STIM8(stimulus_port) & ITM_STIM_FIFOREADY));
	ITM_STIM8(stimulus_port) = c;
}

void trace_send8(int stimulus_port, char val)
{
	if (!(ITM_TER[0] & (1<<stimulus_port))) {
		return;
	}
	ITM_STIM8(stimulus_port) = val;
}

void trace_send_blocking16(int stimulus_port, uint16_t val)
{
	if (!(ITM_TER[0] & (1<<stimulus_port))) {
		return;
	}
	while (!(ITM_STIM16(stimulus_port) & ITM_STIM_FIFOREADY));
	ITM_STIM16(stimulus_port) = val;
}

void trace_send16(int stimulus_port, uint16_t val)
{
	if (!(ITM_TER[0] & (1<<stimulus_port))) {
		return;
	}
	ITM_STIM16(stimulus_port) = val;
}


void trace_send_blocking32(int stimulus_port, uint32_t val)
{
	if (!(ITM_TER[0] & (1<<stimulus_port))) {
		return;
	}
	while (!(ITM_STIM32(stimulus_port) & ITM_STIM_FIFOREADY));
	ITM_STIM32(stimulus_port) = val;
}

void trace_send32(int stimulus_port, uint32_t val)
{
	if (!(ITM_TER[0] & (1<<stimulus_port))) {
		return;
	}
	ITM_STIM32(stimulus_port) = val;
}

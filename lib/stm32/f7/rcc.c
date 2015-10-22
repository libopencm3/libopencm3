#include <libopencm3/stm32/rcc.h>

uint32_t rcc_ahb_frequency = 16000000;
uint32_t rcc_apb1_frequency = 16000000;
uint32_t rcc_apb2_frequency = 16000000;

uint32_t rcc_system_clock_source(void) {
	return (RCC_GFGR & 0x000c) >> 2;
}

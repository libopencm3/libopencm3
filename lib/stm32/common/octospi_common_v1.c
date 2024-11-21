
#include <libopencm3/stm32/octospi.h>

void octospi_enable(void)
{
	OCTOSPI_CR |= OCTOSPI_CR_EN;
}

void octospi_disable(void)
{
	OCTOSPI_CR &= ~OCTOSPI_CR_EN;
}

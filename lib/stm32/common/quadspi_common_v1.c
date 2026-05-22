
#include <libopencm3/stm32/quadspi.h>

void quadspi_enable(uint32_t quadspi)
{
	QUADSPI_CR(quadspi) |= QUADSPI_CR_EN;
}

void quadspi_disable(uint32_t quadspi)
{
	QUADSPI_CR(quadspi) &= ~QUADSPI_CR_EN;
}

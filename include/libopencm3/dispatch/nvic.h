#if defined(STM32F1)
#	include <libopencm3/stm32/f1/nvic.h>
#elif defined(STM32F2)
#	include <libopencm3/stm32/f2/nvic.h>
#elif defined(STM32F4)
#	include <libopencm3/stm32/f4/nvic.h>

#elif defined(TINYGECKO)
#	include <libopencm3/efm32/tinygecko/nvic.h>

#elif defined(LPC43XX)
#	include <libopencm3/lpc43xx/nvic.h>

#elif defined(LM3S)
#	include <libopencm3/lm3s/nvic.h>

#else
#	warning"no interrupts defined for chipset; NVIC_IRQ_COUNT = 0"

#define NVIC_IRQ_COUNT 0

#endif

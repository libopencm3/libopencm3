#if defined(STM32F1)
#	include <libopencm3/stm32/f1/nvic.h>
#elif defined(STM32F2)
#	include <libopencm3/stm32/f2/nvic.h>
#elif defined(STM32F4)
#	include <libopencm3/stm32/f4/nvic.h>
#elif defined(STM32L1)
#	include <libopencm3/stm32/l1/nvic.h>

#elif defined(EFM32TG)
#	include <libopencm3/efm32/efm32tg/nvic.h>
#elif defined(EFM32G)
#	include <libopencm3/efm32/efm32g/nvic.h>
#elif defined(EFM32LG)
#	include <libopencm3/efm32/efm32lg/nvic.h>
#elif defined(EFM32GG)
#	include <libopencm3/efm32/efm32gg/nvic.h>

#elif defined(LPC13XX)
#	include <libopencm3/lpc13xx/nvic.h>
#elif defined(LPC17XX)
#	include <libopencm3/lpc17xx/nvic.h>
#elif defined(LPC43XX)
#	include <libopencm3/lpc43xx/nvic.h>

#elif defined(LM3S)
#	include <libopencm3/lm3s/nvic.h>

#else
#	warning"no interrupts defined for chipset; NVIC_IRQ_COUNT = 0"

#define NVIC_IRQ_COUNT 0

#endif

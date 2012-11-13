#if defined(STM32F1)
#	include "../stm32/f1/vector_nvic.c"
#elif defined(STM32F2)
#	include "../stm32/f2/vector_nvic.c"
#elif defined(STM32F4)
#	include "../stm32/f4/vector_nvic.c"
#elif defined(STM32L1)
#	include "../stm32/l1/vector_nvic.c"

#elif defined(EFM32TG)
#	include "../efm32/efm32tg/vector_nvic.c"
#elif defined(EFM32G)
#	include "../efm32/efm32g/vector_nvic.c"
#elif defined(EFM32LG)
#	include "../efm32/efm32lg/vector_nvic.c"
#elif defined(EFM32GG)
#	include "../efm32/efm32gg/vector_nvic.c"

#elif defined(LPC13XX)
#	include "../lpc13xx/vector_nvic.c"
#elif defined(LPC17XX)
#	include "../lpc17xx/vector_nvic.c"
#elif defined(LPC43XX)
#	include "../lpc43xx/vector_nvic.c"

#elif defined(LM3S)
#	include "../lm3s/vector_nvic.c"

#else
#	warning"no interrupts defined for chipset; not allocating space in the vector table"

#define IRQ_HANDLERS

#endif

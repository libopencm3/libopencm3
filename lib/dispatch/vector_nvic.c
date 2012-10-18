#if defined(STM32F1)
#	include "../stm32/f1/vector_nvic.c"
#elif defined(STM32F2)
#	include "../stm32/f2/vector_nvic.c"
#elif defined(STM32F4)
#	include "../stm32/f4/vector_nvic.c"

#elif defined(EFM32TG)
#	include "../efm32/efm32tg/vector_nvic.c"

#elif defined(LPC43XX)
#	include "../lpc43xx/vector_nvic.c"

#else
#	warning"no chipset defined; user interrupts are disabled"

#define IRQ_HANDLERS

#endif

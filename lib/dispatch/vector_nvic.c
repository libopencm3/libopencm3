#if defined(STM32F1)
#	include "../stm32/f1/vector_nvic.c"
#elif defined(STM32F2)
#	include "../stm32/f2/vector_nvic.c"
#elif defined(STM32F4)
#	include "../stm32/f4/vector_nvic.c"

#elif defined(TINYGECKO)
#	include "../efm32/tinygecko/vector_nvic.c"

#elif defined(LPC43XX)
#	include "../lpc43xx/vector_nvic.c"

#elif defined(LM3S)
#	include "../lm3s/vector_nvic.c"

#else
#	warning"no interrupts defined for chipset; not allocating space in the vector table"

#define IRQ_HANDLERS

#endif

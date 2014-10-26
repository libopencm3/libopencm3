#if defined(STM32F0)
#	include "../stm32/f0/vector_nvic.c"
#elif defined(STM32F1)
#	include "../stm32/f1/vector_nvic.c"
#elif defined(STM32F2)
#	include "../stm32/f2/vector_nvic.c"
#elif defined(STM32F3)
#	include "../stm32/f3/vector_nvic.c"
#elif defined(STM32F4)
#	include "../stm32/f4/vector_nvic.c"
#elif defined(STM32L0)
#	include "../stm32/l0/vector_nvic.c"
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
#elif defined(LPC43XX_M4)
#	include "../lpc43xx/m4/vector_nvic.c"
#elif defined(LPC43XX_M0)
#	include "../lpc43xx/m0/vector_nvic.c"

#elif defined(SAM3A)
#	include "../sam/3a/vector_nvic.c"
#elif defined(SAM3N)
#	include "../sam/3n/vector_nvic.c"
#elif defined(SAM3S)
#	include "../sam/3s/vector_nvic.c"
#elif defined(SAM3U)
#	include "../sam/3u/vector_nvic.c"
#elif defined(SAM3X)
#	include "../sam/3x/vector_nvic.c"

#elif defined(VF6XX)
#	include "../vf6xx/vector_nvic.c"

#elif defined(LM3S) || defined(LM4F)
/* Yes, we use the same interrupt table for both LM3S and LM4F */
#	include "../lm3s/vector_nvic.c"

#else
#	warning "no interrupts defined for chipset;"\
	"not allocating space in the vector table"

#define IRQ_HANDLERS

#endif

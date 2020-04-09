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
#elif defined(STM32F7)
#	include "../stm32/f7/vector_nvic.c"
#elif defined(STM32L0)
#	include "../stm32/l0/vector_nvic.c"
#elif defined(STM32L1)
#	include "../stm32/l1/vector_nvic.c"
#elif defined(STM32L4)
#	include "../stm32/l4/vector_nvic.c"
#elif defined(STM32G0)
#	include "../stm32/g0/vector_nvic.c"
#elif defined(STM32G4)
#	include "../stm32/g4/vector_nvic.c"
#elif defined(STM32H7)
#	include "../stm32/h7/vector_nvic.c"

#elif defined(GD32F1X0)
#	include "../gd32/f1x0/vector_nvic.c"

#elif defined(EFM32TG)
#	include "../efm32/tg/vector_nvic.c"
#elif defined(EFM32G)
#	include "../efm32/g/vector_nvic.c"
#elif defined(EFM32LG)
#	include "../efm32/lg/vector_nvic.c"
#elif defined(EFM32GG)
#	include "../efm32/gg/vector_nvic.c"
#elif defined(EFM32HG)
#	include "../efm32/hg/vector_nvic.c"
#elif defined(EFM32WG)
#	include "../efm32/wg/vector_nvic.c"
#elif defined(EZR32WG)
#	include "../efm32/ezr32wg/vector_nvic.c"

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
#elif defined(SAM4L)
#	include "../sam/4l/vector_nvic.c"
#elif defined(SAMD)
#	include "../sam/d/vector_nvic.c"

#elif defined(VF6XX)
#	include "../vf6xx/vector_nvic.c"

#elif defined(PAC55XX)
#       include "../pac55xx/vector_nvic.c"


#elif defined(LM3S) || defined(LM4F)
/* Yes, we use the same interrupt table for both LM3S and LM4F */
#	include "../lm3s/vector_nvic.c"

#elif defined(MSP432E4)
#       include "../msp432/e4/vector_nvic.c"

#elif defined(SWM050)
#       include "../swm050/vector_nvic.c"

#else
#	warning "no interrupts defined for chipset;"\
	"not allocating space in the vector table"

#define IRQ_HANDLERS

#endif

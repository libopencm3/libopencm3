#if defined(STM32F3)
#	include "../stm32/f3/vector_chipset.c"
#elif defined(STM32F4)
#	include "../stm32/f4/vector_chipset.c"
#elif defined(STM32F7)
#	include "../stm32/f7/vector_chipset.c"
#elif defined(STM32L4)
#	include "../stm32/l4/vector_chipset.c"
#elif defined(LM4F)
#	include "../lm4f/vector_chipset.c"
#elif defined(LPC43XX_M4)
#	include "../lpc43xx/m4/vector_chipset.c"
#elif defined(VF6XX)
#	include "../vf6xx/vector_chipset.c"

#else

static void pre_main(void) {}

#endif

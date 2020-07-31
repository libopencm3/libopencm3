#if defined(STM32F3)
#	include "../stm32/f3/vector_chipset.c"
#elif defined(STM32F4)
#	include "../stm32/f4/vector_chipset.c"
#elif defined(STM32F7)
#	include "../stm32/f7/vector_chipset.c"
#elif defined(STM32G4)
#	include "../stm32/g4/vector_chipset.c"
#elif defined(STM32L4)
#	include "../stm32/l4/vector_chipset.c"
#elif defined(LM4F)
#	include "../lm4f/vector_chipset.c"
#elif defined(LPC43XX_M4)
#	include "../lpc43xx/m4/vector_chipset.c"
#elif defined(VF6XX)
#	include "../vf6xx/vector_chipset.c"
#elif defined(EFM32WG)
#	include "../efm32/wg/vector_chipset.c"
#elif defined(EZR32WG)
#	include "../efm32/ezr32wg/vector_chipset.c"
#elif defined(PAC55XX)
#	include "../pac55xx/vector_chipset.c"
#else

static void pre_main(void) {}

#endif

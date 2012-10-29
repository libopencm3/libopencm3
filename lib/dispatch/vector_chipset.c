#if defined(STM32F4)
#	include "../stm32/f4/vector_chipset.c"

#elif defined(LPC43XX)
#	include "../lpc43xx/vector_chipset.c"

#else

static void pre_main(void) {}

#endif

#if defined(STM32F4)
#	include "../stm32/f4/vector.c"

#elif defined(LPC43XX)
#	include "../lpc43xx/vector.c"

#else

static void pre_main(void) {}

#endif

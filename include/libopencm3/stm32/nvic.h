#if defined(STM32F1)
#	include <libopencm3/stm32/f1/nvic_f1.h>
#elif defined(STM32F2)
#	include <libopencm3/stm32/f2/nvic_f2.h>
#elif defined(STM32F4)
#	include <libopencm3/stm32/f4/nvic_f4.h>
#else
#	error "stm32 family not defined."
#endif



#if defined(STM32F1)
#	include <libopencmsis/stm32/f1/irqhandlers.h>
#elif defined(STM32F2)
#	include <libopencmsis/stm32/f2/irqhandlers.h>
#elif defined(STM32F4)
#	include <libopencmsis/stm32/f4/irqhandlers.h>

#elif defined(TINYGECKO)
#	include <libopencmsis/efm32/tinygecko/irqhandlers.h>

#elif defined(LPC43XX)
#	include <libopencmsis/lpc43xx/irqhandlers.h>

#else
#	warning"no chipset defined; user interrupts are not redirected"

#endif

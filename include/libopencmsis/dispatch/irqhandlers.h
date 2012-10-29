#if defined(STM32F1)
#	include <libopencmsis/stm32/f1/irqhandlers.h>
#elif defined(STM32F2)
#	include <libopencmsis/stm32/f2/irqhandlers.h>
#elif defined(STM32F4)
#	include <libopencmsis/stm32/f4/irqhandlers.h>

#elif defined(EFM32TG)
#	include <libopencmsis/efm32/efm32tg/irqhandlers.h>
#elif defined(EFM32G)
#	include <libopencmsis/efm32/efm32g/irqhandlers.h>
#elif defined(EFM32LG)
#	include <libopencmsis/efm32/efm32lg/irqhandlers.h>
#elif defined(EFM32GG)
#	include <libopencmsis/efm32/efm32gg/irqhandlers.h>

#elif defined(LPC43XX)
#	include <libopencmsis/lpc43xx/irqhandlers.h>

#else
#	warning"no chipset defined; user interrupts are not redirected"

#endif

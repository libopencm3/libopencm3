#include <libopencm3/efm32/tinygecko/gpio.h>

void gpio_set_mode(u32 gpioport, u8 mode, u16 gpios)
{
	u8 i;
	u32 modemaskl = 0, modesetl = 0, modemaskh = 0, modeseth = 0;

	for (i = 0; i < 8; ++i)
	{
		if (gpios & (1<<i)) {
			modemaskl |= GPIO_MODE_MASK << (i*4);
			modesetl |= mode << (i*4);
		}
		if (gpios & (0x100<<i)) {
			modemaskh |= GPIO_MODE_MASK << (i*4);
			modeseth |= mode << (i*4);
		}
	}
	GPIO_Px_MODEL(gpioport) &= ~modemaskl;
	GPIO_Px_MODEL(gpioport) |= modesetl;
	GPIO_Px_MODEH(gpioport) &= ~modemaskh;
	GPIO_Px_MODEH(gpioport) |= modeseth;
}

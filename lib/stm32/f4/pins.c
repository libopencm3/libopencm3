/*
 * pins.c
 *
 * Example of a higher level GPIO api for LIBOPENCM3
 *
 * Copyright (c) 2015, Charles McManis <cmcmanis@mcmanis.com>, all rights reserved.
 */
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/pins.h>

#define GPIO_BASE(x) (GPIOA + ((((uint32_t)(x) >> 4) & 0xf) << 10))
#define GPIO_BIT(x)	(x % 16)
#define GPIO_MASK(x) (1 << ((uint32_t)(x) % 16))

/* used by uart.c to enable clocks for pins as well */
static const uint32_t __gpio_clock_constants[] = {
	RCC_AHB1ENR_IOPAEN,
	RCC_AHB1ENR_IOPBEN,
	RCC_AHB1ENR_IOPCEN,
	RCC_AHB1ENR_IOPDEN,
	RCC_AHB1ENR_IOPEEN,
	RCC_AHB1ENR_IOPFEN,
	RCC_AHB1ENR_IOPGEN,
	RCC_AHB1ENR_IOPHEN,
	RCC_AHB1ENR_IOPIEN
};

/* set the GPIO port's enable line in the clock register */
static inline void enable_gpio_clock(PIN p) {
	RCC_AHB1ENR |= __gpio_clock_constants[((int) p) >> 4];
}

uint32_t _bit_address;

/* On the -F4 we can use bit banding to read GPIO bits */
static inline int bit_value(int pin) {
	int bit = GPIO_BIT(pin);
	int addr = ((GPIO_BASE(pin) + 0x10) - 0x40000000);
	if (bit > 7) {
		addr++;
		bit -= 8;
	}
	_bit_address = (addr * 32 + bit * 4) + 0x42000000U;
	return *(int *)((addr * 32 + bit * 4) + 0x42000000U);
}


/*
 * Set the pin 'function'
 *
 * This function is used by code outside the pins library
 * to insure that the GPIO pins they are using have been
 * enabled. 
 *
 * Example pin_function(uint8_t alternate_function, PA0, PA1, PXX);
 */
void
pin_function(uint8_t af, PIN p0, ...)
{
	va_list	pins;
	PIN t;
	uint32_t *reg_addr;
	int shift;

	va_start(pins, p0);
	for (t = p0; t < PXX; t = va_arg(pins, int)) {
		enable_gpio_clock(t);
		if (GPIO_BIT(t) < 8) {
			reg_addr = (uint32_t *) (GPIO_BASE(t) + 0x20);
			shift = GPIO_BIT(t) * 4;
		} else {
			reg_addr = (uint32_t *) (GPIO_BASE(t) + 0x24);
			shift = (GPIO_BIT(t) - 8) * 4;
		}
		*reg_addr = (*reg_addr & ~(0xf << shift)) | ((af & 0xf) << shift);
		reg_addr = (uint32_t *) (GPIO_BASE(t) + 0x0);
		shift = GPIO_BIT(t) << 1;
		*reg_addr = (*reg_addr & ~(0x3 << shift)) | (0x2 << shift);
	}
	va_end(pins);
}

/*
 * Set up various controllable attributes about a pin
 */
void
pin_attributes(uint32_t attrs, PIN p0, ...)
{
	va_list	pins;
	PIN	p;
	uint32_t mask;
	uint32_t shift;

	va_start(pins, p0);
	for (p = p0; p < PXX; p = va_arg(pins, int)) {
		uint32_t *reg;
		if (attrs & (PIN_PUSHPULL | PIN_OPENDRAIN)) {
			reg = (uint32_t *)(GPIO_BASE(p) + 0x4);
			mask = GPIO_MASK(p);
			if (attrs & PIN_OPENDRAIN) {
				*reg |= mask;
			} else {
				*reg &= ~mask;
			}
		}
		if (attrs & (PIN_SLOW | PIN_MEDIUM | PIN_FAST | PIN_HS)) {
			shift = GPIO_BIT(p) * 2;
			mask = 0x3 << shift;
			reg = (uint32_t *)(GPIO_BASE(p) + 0x8);
			*reg &= ~mask; /* sets this to mode 'slow' */
			if (attrs & PIN_HS) {
				*reg |= (0x3 << shift);
			} else if (attrs & PIN_FAST) {
				*reg |= (0x2 << shift);
			} else if (attrs & PIN_MEDIUM) {
				*reg |= (0x1 << shift);
			}
		}
		if (attrs & (PIN_PULLUP | PIN_PULLDOWN | PIN_NOPULL)) {
			shift = GPIO_BIT(p) * 2;
			mask = 0x3 << shift; 
			reg = (uint32_t *)(GPIO_BASE(p) + 0xC);
			/* this is NOPULL (0x0 in bit selector) */
			*reg &= ~mask;
			if (attrs & PIN_PULLUP) {
				*reg |= (0x1 << shift);
			} else if (attrs & PIN_PULLDOWN) {
				*reg |= (0x2 << shift);
			}
		}
	}
}

/*
 * pin_input(PIN p0, ...)
 *
 * This function will set the IO pins specified to be
 * input pins. By default neither a pull up nor pull down
 * resistor is enabled for the pins. Use pin_attribute()
 * to change the attributes the pins if needed. The list 
 * of pins must be terminated with PXX.
 *
 * Example: pin_input(PC0, PC1, PC2, PC3, PXX);
 */
void
pin_input(PIN p0, ...) {
	va_list	pins;
	PIN t;
	uint32_t mask;
	uint32_t shift;

	va_start(pins, p0);
	for (t = p0; t < PXX; t = va_arg(pins, int)) {
		enable_gpio_clock(t);
		shift = GPIO_BIT(t) * 2;
		mask = ~(0x3 << shift);
		/* set it as an input */
		GPIO_MODER(GPIO_BASE(t)) &= mask;
		/* turn off pull ups and pull downs by default */
		GPIO_PUPDR(GPIO_BASE(t)) &= mask;
	}
	va_end(pins);
}

/*
 * pin_output(PIN p0, ...)
 *
 * This function will set the IO pins specified to be
 * output pins. By default they are configured to be
 * push/pull. If you need them to be open drain use the
 * attribute call to set them up that way. The list of 
 * pins must be terminated with PXX.
 *
 * Example: pin_output(PC0, PC1, PC2, PC3, PXX);
 */
void
pin_output(PIN p0, ...) {
	va_list	pins;
	PIN p;
	uint32_t mask;
	uint32_t shift;

	va_start(pins, p0);
	for (p = p0; p < PXX; p = va_arg(pins, int)) {
		enable_gpio_clock(p);
		shift = GPIO_BIT(p) * 2;
		mask = ~(0x3 << shift);
		/* set it as an output */
		GPIO_MODER(GPIO_BASE(p)) &= mask;
		GPIO_MODER(GPIO_BASE(p)) |= (0x1 << shift);
		/* make it push-pull by default */
		GPIO_OTYPER(GPIO_BASE(p)) &= ~GPIO_MASK(p);
	}
	va_end(pins);
}

/*
 * pin_set(PIN p0, ...)
 *
 * Set the selected pin(s) to a logical 1 or high state. The
 * list of pins must be terminated with PXX.
 *
 * Example: pin_set(PA0, PA1, PXX);
 */
void
pin_set(PIN p0, ...) {
	va_list	pins;
	PIN p;

	va_start(pins, p0);
	for (p = p0; p < PXX; p = va_arg(pins, int)) {
		GPIO_BSRR(GPIO_BASE(p)) = GPIO_MASK(p);
	}
	va_end(pins);
}

/*
 * pin_clear(PIN p0, ...)
 *
 * Set the selected pin(s) to a logical 0 or low state. The
 * list of pins must be terminated with PXX.
 *
 * Example: pin_clear(PB0, PC7, PXX);
 */
void
pin_clear(PIN p0, ...) {
	va_list	pins;
	PIN p;

	va_start(pins, p0);
	for (p = p0; p < PXX; p = va_arg(pins, int)) {
		GPIO_BSRR(GPIO_BASE(p)) = GPIO_MASK(p) << 16;
	}
	va_end(pins);
}

/*
 * uint32_t pin_get(PIN p0, ...)
 *
 * This reads the pins and stores their state in the result in
 * LSB to MSB order, so pin_get(PA0, PA1, PA2, PA3) will read
 * the lower four bits of the GPIO A and return as a 4 bit value
 * with PA3 in bit position 3, PA2 in bit 2, etc. It also works
 * across disjoint sets, so if you have hooked up an 8 bit I/O
 * port to pins PA0 - PA3, PB3, PB5, PC0, PC1, you can use
 *
 * 	  pin_get(PA0, PA1, PA2, PA3, PB3, PB5, PC0, PC1, PXX);
 *
 * to read those pins as an 8 bit value, again PC1 is MSB, PA0
 * the LSB of the result.
 */
uint32_t
pin_get(PIN p0, ...) {
	va_list	pins;
	PIN p;
	uint32_t res;

	va_start(pins, p0);
	p = p0;
	res = 0;
	do {
		res <<= 1; /* make space for this bit */
		res |= bit_value(p);
		p = va_arg(pins, int);
	} while (p < PXX);
	va_end(pins);
	return res;
}

void
pin_toggle(PIN p0, ...)
{
	va_list	pins;
	PIN p;

	va_start(pins, p0);
	for (p = p0; p < PXX; p = va_arg(pins, int)) {
		if (bit_value(p)) {
			GPIO_BSRR(GPIO_BASE(p)) = GPIO_MASK(p) << 16;
		} else {
			GPIO_BSRR(GPIO_BASE(p)) = GPIO_MASK(p);
		}
	}
	va_end(pins);
}


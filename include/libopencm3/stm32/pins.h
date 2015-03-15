/* pins.h 
 *
 * Example of a high level GPIO function for LIBOPENCM3 based
 * programs.
 *
 * Copyright (c) 2015, Charles McManis, all rights reserved.
 *
 * API for the pins (nee GPIO) functions in the
 * utility routines.
 */

#include <stdint.h>
#include <stdarg.h>

#ifndef _PINS_H_
#define _PINS_H_

/* 
 * Giant enum which gives a name to all of the GPIO pins on
 * the chip. Ports A - I.
 */
typedef enum gpio_pin_enum {
        PA0 = 0, PA1, PA2, PA3, PA4, PA5, PA6, PA7,
        PA8, PA9, PA10, PA11, PA12, PA13, PA14, PA15,
        PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7,
        PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,
        PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7,
        PC8, PC9, PC10, PC11, PC12, PC13, PC14, PC15,
        PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7,
        PD8, PD9, PD10, PD11, PD12, PD13, PD14, PD15,
        PE0, PE1, PE2, PE3, PE4, PE5, PE6, PE7,
        PE8, PE9, PE10, PE11, PE12, PE13, PE14, PE15,
        PF0, PF1, PF2, PF3, PF4, PF5, PF6, PF7,
        PF8, PF9, PF10, PF11, PF12, PF13, PF14, PF15,
        PG0, PG1, PG2, PG3, PG4, PG5, PG6, PG7,
        PG8, PG9, PG10, PG11, PG12, PG13, PG14, PG15,
        PH0, PH1, PH2, PH3, PH4, PH5, PH6, PH7,
        PH8, PH9, PH10, PH11, PH12, PH13, PH14, PH15,
        PI0, PI1, PI2, PI3, PI4, PI5, PI6, PI7,
        PI8, PI9, PI10, PI11, PI12, PI13, PI14, PI15,
		PXX
} PIN;

typedef enum gpio_port_enum {
	PA, PB, PC, PD, PE, PF, PG, PH, PI } PIN_PORT;

/*
 * Attributes which can be set on a 'pin' (input and
 * output are implicit by the call to pin_input or
 * pin_output.
 */
#define PIN_PULLUP		(1 << 0)
#define PIN_PULLDOWN	(1 << 1)
#define PIN_NOPULL		(1 << 2)
#define	PIN_SLOW		(1 << 3)
#define PIN_MEDIUM		(1 << 4)
#define PIN_FAST		(1 << 5)
#define PIN_HS			(1 << 6)
#define PIN_PUSHPULL	(1 << 7)
#define PIN_OPENDRAIN	(1 << 8)

/*
 * Pin Functions 
 */

void pin_function(uint8_t af, PIN, ...);
void pin_attributes(uint32_t attributes, PIN, ...);

void pin_input(PIN, ...);
void pin_output(PIN, ...);
void pin_set(PIN, ...);
uint32_t pin_get(PIN, ...);
void pin_clear(PIN, ...);
void pin_toggle(PIN, ...);

#endif /* pins.h */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#define WEAK __attribute__ ((weak))

/* Symbols exported by the linker script(s): */
extern unsigned _data_loadaddr, _data, _edata, _ebss, _stack;

void main(void);
void reset_handler(void);
void blocking_handler(void);
void null_handler(void);

void WEAK nmi_handler(void);
void WEAK hard_fault_handler(void);
void WEAK mem_manage_handler(void);
void WEAK bus_fault_handler(void);
void WEAK usage_fault_handler(void);
void WEAK sv_call_handler(void);
void WEAK debug_monitor_handler(void);
void WEAK pend_sv_handler(void);
void WEAK sys_tick_handler(void);

void WEAK gpioa_handler(void);
void WEAK gpiob_handler(void);
void WEAK gpioc_handler(void);
void WEAK gpiod_handler(void);
void WEAK gpioe_handler(void);
void WEAK uart0_handler(void);
void WEAK uart1_handler(void);
void WEAK ssi0_handler(void);
void WEAK i2c0_handler(void);
void WEAK pwm0_fault_handler(void);
void WEAK pwm0_0_handler(void);
void WEAK pwm0_1_handler(void);
void WEAK pwm0_2_handler(void);
void WEAK qei0_handler(void);
void WEAK adc0ss0_handler(void);
void WEAK adc0ss1_handler(void);
void WEAK adc0ss2_handler(void);
void WEAK adc0ss3_handler(void);
void WEAK watchdog_handler(void);
void WEAK timer0a_handler(void);
void WEAK timer0b_handler(void);
void WEAK timer1a_handler(void);
void WEAK timer1b_handler(void);
void WEAK timer2a_handler(void);
void WEAK timer2b_handler(void);
void WEAK comp0_handler(void);
void WEAK comp1_handler(void);
void WEAK comp2_handler(void);
void WEAK sysctl_handler(void);
void WEAK flash_handler(void);
void WEAK gpiof_handler(void);
void WEAK gpiog_handler(void);
void WEAK gpioh_handler(void);
void WEAK uart2_handler(void);
void WEAK ssi1_handler(void);
void WEAK timer3a_handler(void);
void WEAK timer3b_handler(void);
void WEAK i2c1_handler(void);
void WEAK qei1_handler(void);
void WEAK can0_handler(void);
void WEAK can1_handler(void);
void WEAK can2_handler(void);
void WEAK eth_handler(void);
void WEAK hibernate_handler(void);
void WEAK usb0_handler(void);
void WEAK pwm0_3_handler(void);
void WEAK udma_handler(void);
void WEAK udmaerr_handler(void);
void WEAK adc1ss0_handler(void);
void WEAK adc1ss1_handler(void);
void WEAK adc1ss2_handler(void);
void WEAK adc1ss3_handler(void);
void WEAK i2s0_handler(void);
void WEAK epi0_handler(void);
void WEAK gpioj_handler(void);
void WEAK gpiok_handler(void);
void WEAK gpiol_handler(void);
void WEAK ssi2_handler(void);
void WEAK ssi3_handler(void);
void WEAK uart3_handler(void);
void WEAK uart4_handler(void);
void WEAK uart5_handler(void);
void WEAK uart6_handler(void);
void WEAK uart7_handler(void);
void WEAK i2c2_handler(void);
void WEAK i2c3_handler(void);
void WEAK timer4a_handler(void);
void WEAK timer4b_handler(void);
void WEAK timer5a_handler(void);
void WEAK timer5b_handler(void);
void WEAK wtimer0a_handler(void);
void WEAK wtimer0b_handler(void);
void WEAK wtimer1a_handler(void);
void WEAK wtimer1b_handler(void);
void WEAK wtimer2a_handler(void);
void WEAK wtimer2b_handler(void);
void WEAK wtimer3a_handler(void);
void WEAK wtimer3b_handler(void);
void WEAK wtimer4a_handler(void);
void WEAK wtimer4b_handler(void);
void WEAK wtimer5a_handler(void);
void WEAK wtimer5b_handler(void);
void WEAK sysexc_handler(void);
void WEAK peci0_handler(void);
void WEAK lpc0_handler(void);
void WEAK i2c4_handler(void);
void WEAK i2c5_handler(void);
void WEAK gpiom_handler(void);
void WEAK gpion_handler(void);
void WEAK fan0_handler(void);
void WEAK gpiop0_handler(void);
void WEAK gpiop1_handler(void);
void WEAK gpiop2_handler(void);
void WEAK gpiop3_handler(void);
void WEAK gpiop4_handler(void);
void WEAK gpiop5_handler(void);
void WEAK gpiop6_handler(void);
void WEAK gpiop7_handler(void);
void WEAK gpioq0_handler(void);
void WEAK gpioq1_handler(void);
void WEAK gpioq2_handler(void);
void WEAK gpioq3_handler(void);
void WEAK gpioq4_handler(void);
void WEAK gpioq5_handler(void);
void WEAK gpioq6_handler(void);
void WEAK gpioq7_handler(void);
void WEAK pwm1_0_handler(void);
void WEAK pwm1_1_handler(void);
void WEAK pwm1_2_handler(void);
void WEAK pwm1_3_handler(void);
void WEAK pwm1_fault_handler(void);

__attribute__ ((section(".vectors")))
void (*const vector_table[]) (void) = {
	(void *)&_stack,
	reset_handler,
	nmi_handler,
	hard_fault_handler,
	mem_manage_handler,
	bus_fault_handler,
	usage_fault_handler,
	0, 0, 0, 0,		/* Reserved */
	sv_call_handler,
	debug_monitor_handler,
	0,			/* Reserved */
	pend_sv_handler,
	sys_tick_handler,

    gpioa_handler, /* 16 */
    gpiob_handler, /* 17 */
    gpioc_handler, /* 18 */
    gpiod_handler, /* 19 */
    gpioe_handler, /* 20 */
    uart0_handler, /* 21 */
    uart1_handler, /* 22 */
    ssi0_handler, /* 23 */
    i2c0_handler, /* 24 */
    pwm0_fault_handler, /* 25 */
    pwm0_0_handler, /* 26 */
    pwm0_1_handler, /* 27 */
    pwm0_2_handler, /* 28 */
    qei0_handler, /* 29 */
    adc0ss0_handler, /* 30 */
    adc0ss1_handler, /* 31 */
    adc0ss2_handler, /* 32 */
    adc0ss3_handler, /* 33 */
    watchdog_handler, /* 34 */
    timer0a_handler, /* 35 */
    timer0b_handler, /* 36 */
    timer1a_handler, /* 37 */
    timer1b_handler, /* 38 */
    timer2a_handler, /* 39 */
    timer2b_handler, /* 40 */
    comp0_handler, /* 41 */
    comp1_handler, /* 42 */
    comp2_handler, /* 43 */
    sysctl_handler, /* 44 */
    flash_handler, /* 45 */
    gpiof_handler, /* 46 */
    gpiog_handler, /* 47 */
    gpioh_handler, /* 48 */
    uart2_handler, /* 49 */
    ssi1_handler, /* 50 */
    timer3a_handler, /* 51 */
    timer3b_handler, /* 52 */
    i2c1_handler, /* 53 */
    qei1_handler, /* 54 */
    can0_handler, /* 55 */
    can1_handler, /* 56 */
    can2_handler, /* 57 */
    eth_handler, /* 58 */
    hibernate_handler, /* 59 */
    usb0_handler, /* 60 */
    pwm0_3_handler, /* 61 */
    udma_handler, /* 62 */
    udmaerr_handler, /* 63 */
    adc1ss0_handler, /* 64 */
    adc1ss1_handler, /* 65 */
    adc1ss2_handler, /* 66 */
    adc1ss3_handler, /* 67 */
    i2s0_handler, /* 68 */
    epi0_handler, /* 69 */
    gpioj_handler, /* 70 */
    gpiok_handler, /* 71 */
    gpiol_handler, /* 72 */
    ssi2_handler, /* 73 */
    ssi3_handler, /* 74 */
    uart3_handler, /* 75 */
    uart4_handler, /* 76 */
    uart5_handler, /* 77 */
    uart6_handler, /* 78 */
    uart7_handler, /* 79 */
    0, /* 80 */
    0, /* 81 */
    0, /* 82 */
    0, /* 83 */
    i2c2_handler, /* 84 */
    i2c3_handler, /* 85 */
    timer4a_handler, /* 86 */
    timer4b_handler, /* 87 */
    0, /* 88 */
    0, /* 89 */
    0, /* 90 */
    0, /* 91 */
    0, /* 92 */
    0, /* 93 */
    0, /* 94 */
    0, /* 95 */
    0, /* 96 */
    0, /* 97 */
    0, /* 98 */
    0, /* 99 */
    0, /* 100 */
    0, /* 101 */
    0, /* 102 */
    0, /* 103 */
    0, /* 104 */
    0, /* 105 */
    0, /* 106 */
    0, /* 107 */
    timer5a_handler, /* 108 */
    timer5b_handler, /* 109 */
    wtimer0a_handler, /* 110 */
    wtimer0b_handler, /* 111 */
    wtimer1a_handler, /* 112 */
    wtimer1b_handler, /* 113 */
    wtimer2a_handler, /* 114 */
    wtimer2b_handler, /* 115 */
    wtimer3a_handler, /* 116 */
    wtimer3b_handler, /* 117 */
    wtimer4a_handler, /* 118 */
    wtimer4b_handler, /* 119 */
    wtimer5a_handler, /* 120 */
    wtimer5b_handler, /* 121 */
    sysexc_handler, /* 122 */
    peci0_handler, /* 123 */
    lpc0_handler, /* 124 */
    i2c4_handler, /* 125 */
    i2c5_handler, /* 126 */
    gpiom_handler, /* 127 */
    gpion_handler, /* 128 */
    0, /* 129 */
    fan0_handler, /* 130 */
    0, /* 131 */
    gpiop0_handler, /* 132 */
    gpiop1_handler, /* 133 */
    gpiop2_handler, /* 134 */
    gpiop3_handler, /* 135 */
    gpiop4_handler, /* 136 */
    gpiop5_handler, /* 137 */
    gpiop6_handler, /* 138 */
    gpiop7_handler, /* 139 */
    gpioq0_handler, /* 140 */
    gpioq1_handler, /* 141 */
    gpioq2_handler, /* 142 */
    gpioq3_handler, /* 143 */
    gpioq4_handler, /* 144 */
    gpioq5_handler, /* 145 */
    gpioq6_handler, /* 146 */
    gpioq7_handler, /* 147 */
    0, /* 148 */
    0, /* 149 */
    pwm1_0_handler, /* 150 */
    pwm1_1_handler, /* 151 */
    pwm1_2_handler, /* 152 */
    pwm1_3_handler, /* 153 */
    pwm1_fault_handler, /* 154 */
};

void reset_handler(void)
{
	volatile unsigned *src, *dest;

	__asm__("MSR msp, %0" : : "r"(&_stack));

	for (src = &_data_loadaddr, dest = &_data; dest < &_edata; src++, dest++)
		*dest = *src;

	while (dest < &_ebss)
		*dest++ = 0;

	/* Call the application's entry point. */
	main();
}

void blocking_handler(void)
{
	while (1) ;
}

void null_handler(void)
{
	/* Do nothing. */
}

#pragma weak nmi_handler = null_handler
#pragma weak hard_fault_handler = blocking_handler
#pragma weak mem_manage_handler = blocking_handler
#pragma weak bus_fault_handler = blocking_handler
#pragma weak usage_fault_handler = blocking_handler
#pragma weak sv_call_handler = null_handler
#pragma weak debug_monitor_handler = null_handler
#pragma weak pend_sv_handler = null_handler
#pragma weak sys_tick_handler = null_handler
#pragma weak gpioa_handler = null_handler
#pragma weak gpiob_handler = null_handler
#pragma weak gpioc_handler = null_handler
#pragma weak gpiod_handler = null_handler
#pragma weak gpioe_handler = null_handler
#pragma weak uart0_handler = null_handler
#pragma weak uart1_handler = null_handler
#pragma weak ssi0_handler = null_handler
#pragma weak i2c0_handler = null_handler
#pragma weak pwm0_fault_handler = null_handler
#pragma weak pwm0_0_handler = null_handler
#pragma weak pwm0_1_handler = null_handler
#pragma weak pwm0_2_handler = null_handler
#pragma weak qei0_handler = null_handler
#pragma weak adc0ss0_handler = null_handler
#pragma weak adc0ss1_handler = null_handler
#pragma weak adc0ss2_handler = null_handler
#pragma weak adc0ss3_handler = null_handler
#pragma weak watchdog_handler = null_handler
#pragma weak timer0a_handler = null_handler
#pragma weak timer0b_handler = null_handler
#pragma weak timer1a_handler = null_handler
#pragma weak timer1b_handler = null_handler
#pragma weak timer2a_handler = null_handler
#pragma weak timer2b_handler = null_handler
#pragma weak comp0_handler = null_handler
#pragma weak comp1_handler = null_handler
#pragma weak comp2_handler = null_handler
#pragma weak sysctl_handler = null_handler
#pragma weak flash_handler = null_handler
#pragma weak gpiof_handler = null_handler
#pragma weak gpiog_handler = null_handler
#pragma weak gpioh_handler = null_handler
#pragma weak uart2_handler = null_handler
#pragma weak ssi1_handler = null_handler
#pragma weak timer3a_handler = null_handler
#pragma weak timer3b_handler = null_handler
#pragma weak i2c1_handler = null_handler
#pragma weak qei1_handler = null_handler
#pragma weak can0_handler = null_handler
#pragma weak can1_handler = null_handler
#pragma weak can2_handler = null_handler
#pragma weak eth_handler = null_handler
#pragma weak hibernate_handler = null_handler
#pragma weak usb0_handler = null_handler
#pragma weak pwm0_3_handler = null_handler
#pragma weak udma_handler = null_handler
#pragma weak udmaerr_handler = null_handler
#pragma weak adc1ss0_handler = null_handler
#pragma weak adc1ss1_handler = null_handler
#pragma weak adc1ss2_handler = null_handler
#pragma weak adc1ss3_handler = null_handler
#pragma weak i2s0_handler = null_handler
#pragma weak epi0_handler = null_handler
#pragma weak gpioj_handler = null_handler
#pragma weak gpiok_handler = null_handler
#pragma weak gpiol_handler = null_handler
#pragma weak ssi2_handler = null_handler
#pragma weak ssi3_handler = null_handler
#pragma weak uart3_handler = null_handler
#pragma weak uart4_handler = null_handler
#pragma weak uart5_handler = null_handler
#pragma weak uart6_handler = null_handler
#pragma weak uart7_handler = null_handler
#pragma weak i2c2_handler = null_handler
#pragma weak i2c3_handler = null_handler
#pragma weak timer4a_handler = null_handler
#pragma weak timer4b_handler = null_handler
#pragma weak timer5a_handler = null_handler
#pragma weak timer5b_handler = null_handler
#pragma weak wtimer0a_handler = null_handler
#pragma weak wtimer0b_handler = null_handler
#pragma weak wtimer1a_handler = null_handler
#pragma weak wtimer1b_handler = null_handler
#pragma weak wtimer2a_handler = null_handler
#pragma weak wtimer2b_handler = null_handler
#pragma weak wtimer3a_handler = null_handler
#pragma weak wtimer3b_handler = null_handler
#pragma weak wtimer4a_handler = null_handler
#pragma weak wtimer4b_handler = null_handler
#pragma weak wtimer5a_handler = null_handler
#pragma weak wtimer5b_handler = null_handler
#pragma weak sysexc_handler = null_handler
#pragma weak peci0_handler = null_handler
#pragma weak lpc0_handler = null_handler
#pragma weak i2c4_handler = null_handler
#pragma weak i2c5_handler = null_handler
#pragma weak gpiom_handler = null_handler
#pragma weak gpion_handler = null_handler
#pragma weak fan0_handler = null_handler
#pragma weak gpiop0_handler = null_handler
#pragma weak gpiop1_handler = null_handler
#pragma weak gpiop2_handler = null_handler
#pragma weak gpiop3_handler = null_handler
#pragma weak gpiop4_handler = null_handler
#pragma weak gpiop5_handler = null_handler
#pragma weak gpiop6_handler = null_handler
#pragma weak gpiop7_handler = null_handler
#pragma weak gpioq0_handler = null_handler
#pragma weak gpioq1_handler = null_handler
#pragma weak gpioq2_handler = null_handler
#pragma weak gpioq3_handler = null_handler
#pragma weak gpioq4_handler = null_handler
#pragma weak gpioq5_handler = null_handler
#pragma weak gpioq6_handler = null_handler
#pragma weak gpioq7_handler = null_handler
#pragma weak pwm1_0_handler = null_handler
#pragma weak pwm1_1_handler = null_handler
#pragma weak pwm1_2_handler = null_handler
#pragma weak pwm1_3_handler = null_handler
#pragma weak pwm1_fault_handler = null_handler

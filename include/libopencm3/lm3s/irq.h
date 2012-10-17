/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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

#ifndef LIBOPENCM3_LM3S_IRQ_H
#define LIBOPENCM3_LM3S_IRQ_H

#define IRQ_GPIOA               0
#define IRQ_GPIOB               1
#define IRQ_GPIOC               2
#define IRQ_GPIOD               3
#define IRQ_GPIOE               4
#define IRQ_UART0               5
#define IRQ_UART1               6
#define IRQ_SSI0                7
#define IRQ_I2C0                8
#define IRQ_PWM0_FAULT          9
#define IRQ_PWM0_0              10
#define IRQ_PWM0_1              11
#define IRQ_PWM0_2              12
#define IRQ_QEI0                13
#define IRQ_ADC0SS0             14
#define IRQ_ADC0SS1             15
#define IRQ_ADC0SS2             16
#define IRQ_ADC0SS3             17
#define IRQ_WATCHDOG            18
#define IRQ_TIMER0A             19
#define IRQ_TIMER0B             20
#define IRQ_TIMER1A             21
#define IRQ_TIMER1B             22
#define IRQ_TIMER2A             23
#define IRQ_TIMER2B             24
#define IRQ_COMP0               25
#define IRQ_COMP1               26
#define IRQ_COMP2               27
#define IRQ_SYSCTL              28
#define IRQ_FLASH               29
#define IRQ_GPIOF               30
#define IRQ_GPIOG               31
#define IRQ_GPIOH               32
#define IRQ_UART2               33
#define IRQ_SSI1                34
#define IRQ_TIMER3A             35
#define IRQ_TIMER3B             36
#define IRQ_I2C1                37
#define IRQ_QEI1                38
#define IRQ_CAN0                39
#define IRQ_CAN1                40
#define IRQ_CAN2                41
#define IRQ_ETH                 42
#define IRQ_HIBERNATE           43
#define IRQ_USB0                44
#define IRQ_PWM0_3              45
#define IRQ_UDMA                46
#define IRQ_UDMAERR             47
#define IRQ_ADC1SS0             48
#define IRQ_ADC1SS1             49
#define IRQ_ADC1SS2             50
#define IRQ_ADC1SS3             51
#define IRQ_I2S0                52
#define IRQ_EPI0                53
#define IRQ_GPIOJ               54
#define IRQ_GPIOK               55
#define IRQ_GPIOL               56
#define IRQ_SSI2                57
#define IRQ_SSI3                58
#define IRQ_UART3               59
#define IRQ_UART4               60
#define IRQ_UART5               61
#define IRQ_UART6               62
#define IRQ_UART7               63
/* undefined: slot 64 */
/* undefined: slot 65 */
/* undefined: slot 66 */
/* undefined: slot 67 */
#define IRQ_I2C2                68
#define IRQ_I2C3                69
#define IRQ_TIMER4A             70
#define IRQ_TIMER4B             71
/* undefined: slot 72 */
/* undefined: slot 73 */
/* undefined: slot 74 */
/* undefined: slot 75 */
/* undefined: slot 76 */
/* undefined: slot 77 */
/* undefined: slot 78 */
/* undefined: slot 79 */
/* undefined: slot 80 */
/* undefined: slot 81 */
/* undefined: slot 82 */
/* undefined: slot 83 */
/* undefined: slot 84 */
/* undefined: slot 85 */
/* undefined: slot 86 */
/* undefined: slot 87 */
/* undefined: slot 88 */
/* undefined: slot 89 */
/* undefined: slot 90 */
/* undefined: slot 91 */
#define IRQ_TIMER5A             92
#define IRQ_TIMER5B             93
#define IRQ_WTIMER0A            94
#define IRQ_WTIMER0B            95
#define IRQ_WTIMER1A            96
#define IRQ_WTIMER1B            97
#define IRQ_WTIMER2A            98
#define IRQ_WTIMER2B            99
#define IRQ_WTIMER3A            100
#define IRQ_WTIMER3B            101
#define IRQ_WTIMER4A            102
#define IRQ_WTIMER4B            103
#define IRQ_WTIMER5A            104
#define IRQ_WTIMER5B            105
#define IRQ_SYSEXC              106
#define IRQ_PECI0               107
#define IRQ_LPC0                108
#define IRQ_I2C4                109
#define IRQ_I2C5                110
#define IRQ_GPIOM               111
#define IRQ_GPION               112
/* undefined: slot 113 */
#define IRQ_FAN0                114
/* undefined: slot 115 */
#define IRQ_GPIOP0              116
#define IRQ_GPIOP1              117
#define IRQ_GPIOP2              118
#define IRQ_GPIOP3              119
#define IRQ_GPIOP4              120
#define IRQ_GPIOP5              121
#define IRQ_GPIOP6              122
#define IRQ_GPIOP7              123
#define IRQ_GPIOQ0              124
#define IRQ_GPIOQ1              125
#define IRQ_GPIOQ2              126
#define IRQ_GPIOQ3              127
#define IRQ_GPIOQ4              128
#define IRQ_GPIOQ5              129
#define IRQ_GPIOQ6              130
#define IRQ_GPIOQ7              131
/* undefined: slot 132 */
/* undefined: slot 133 */
#define IRQ_PWM1_0              134
#define IRQ_PWM1_1              135
#define IRQ_PWM1_2              136
#define IRQ_PWM1_3              137
#define IRQ_PWM1_FAULT          138

#define IRQ_COUNT               139

#define WEAK __attribute__ ((weak))

void WEAK gpioa_isr(void);
void WEAK gpiob_isr(void);
void WEAK gpioc_isr(void);
void WEAK gpiod_isr(void);
void WEAK gpioe_isr(void);
void WEAK uart0_isr(void);
void WEAK uart1_isr(void);
void WEAK ssi0_isr(void);
void WEAK i2c0_isr(void);
void WEAK pwm0_fault_isr(void);
void WEAK pwm0_0_isr(void);
void WEAK pwm0_1_isr(void);
void WEAK pwm0_2_isr(void);
void WEAK qei0_isr(void);
void WEAK adc0ss0_isr(void);
void WEAK adc0ss1_isr(void);
void WEAK adc0ss2_isr(void);
void WEAK adc0ss3_isr(void);
void WEAK watchdog_isr(void);
void WEAK timer0a_isr(void);
void WEAK timer0b_isr(void);
void WEAK timer1a_isr(void);
void WEAK timer1b_isr(void);
void WEAK timer2a_isr(void);
void WEAK timer2b_isr(void);
void WEAK comp0_isr(void);
void WEAK comp1_isr(void);
void WEAK comp2_isr(void);
void WEAK sysctl_isr(void);
void WEAK flash_isr(void);
void WEAK gpiof_isr(void);
void WEAK gpiog_isr(void);
void WEAK gpioh_isr(void);
void WEAK uart2_isr(void);
void WEAK ssi1_isr(void);
void WEAK timer3a_isr(void);
void WEAK timer3b_isr(void);
void WEAK i2c1_isr(void);
void WEAK qei1_isr(void);
void WEAK can0_isr(void);
void WEAK can1_isr(void);
void WEAK can2_isr(void);
void WEAK eth_isr(void);
void WEAK hibernate_isr(void);
void WEAK usb0_isr(void);
void WEAK pwm0_3_isr(void);
void WEAK udma_isr(void);
void WEAK udmaerr_isr(void);
void WEAK adc1ss0_isr(void);
void WEAK adc1ss1_isr(void);
void WEAK adc1ss2_isr(void);
void WEAK adc1ss3_isr(void);
void WEAK i2s0_isr(void);
void WEAK epi0_isr(void);
void WEAK gpioj_isr(void);
void WEAK gpiok_isr(void);
void WEAK gpiol_isr(void);
void WEAK ssi2_isr(void);
void WEAK ssi3_isr(void);
void WEAK uart3_isr(void);
void WEAK uart4_isr(void);
void WEAK uart5_isr(void);
void WEAK uart6_isr(void);
void WEAK uart7_isr(void);
void WEAK i2c2_isr(void);
void WEAK i2c3_isr(void);
void WEAK timer4a_isr(void);
void WEAK timer4b_isr(void);
void WEAK timer5a_isr(void);
void WEAK timer5b_isr(void);
void WEAK wtimer0a_isr(void);
void WEAK wtimer0b_isr(void);
void WEAK wtimer1a_isr(void);
void WEAK wtimer1b_isr(void);
void WEAK wtimer2a_isr(void);
void WEAK wtimer2b_isr(void);
void WEAK wtimer3a_isr(void);
void WEAK wtimer3b_isr(void);
void WEAK wtimer4a_isr(void);
void WEAK wtimer4b_isr(void);
void WEAK wtimer5a_isr(void);
void WEAK wtimer5b_isr(void);
void WEAK sysexc_isr(void);
void WEAK peci0_isr(void);
void WEAK lpc0_isr(void);
void WEAK i2c4_isr(void);
void WEAK i2c5_isr(void);
void WEAK gpiom_isr(void);
void WEAK gpion_isr(void);
void WEAK fan0_isr(void);
void WEAK gpiop0_isr(void);
void WEAK gpiop1_isr(void);
void WEAK gpiop2_isr(void);
void WEAK gpiop3_isr(void);
void WEAK gpiop4_isr(void);
void WEAK gpiop5_isr(void);
void WEAK gpiop6_isr(void);
void WEAK gpiop7_isr(void);
void WEAK gpioq0_isr(void);
void WEAK gpioq1_isr(void);
void WEAK gpioq2_isr(void);
void WEAK gpioq3_isr(void);
void WEAK gpioq4_isr(void);
void WEAK gpioq5_isr(void);
void WEAK gpioq6_isr(void);
void WEAK gpioq7_isr(void);
void WEAK pwm1_0_isr(void);
void WEAK pwm1_1_isr(void);
void WEAK pwm1_2_isr(void);
void WEAK pwm1_3_isr(void);
void WEAK pwm1_fault_isr(void);

#pragma weak gpioa_isr = blocking_handler
#pragma weak gpiob_isr = blocking_handler
#pragma weak gpioc_isr = blocking_handler
#pragma weak gpiod_isr = blocking_handler
#pragma weak gpioe_isr = blocking_handler
#pragma weak uart0_isr = blocking_handler
#pragma weak uart1_isr = blocking_handler
#pragma weak ssi0_isr = blocking_handler
#pragma weak i2c0_isr = blocking_handler
#pragma weak pwm0_fault_isr = blocking_handler
#pragma weak pwm0_0_isr = blocking_handler
#pragma weak pwm0_1_isr = blocking_handler
#pragma weak pwm0_2_isr = blocking_handler
#pragma weak qei0_isr = blocking_handler
#pragma weak adc0ss0_isr = blocking_handler
#pragma weak adc0ss1_isr = blocking_handler
#pragma weak adc0ss2_isr = blocking_handler
#pragma weak adc0ss3_isr = blocking_handler
#pragma weak watchdog_isr = blocking_handler
#pragma weak timer0a_isr = blocking_handler
#pragma weak timer0b_isr = blocking_handler
#pragma weak timer1a_isr = blocking_handler
#pragma weak timer1b_isr = blocking_handler
#pragma weak timer2a_isr = blocking_handler
#pragma weak timer2b_isr = blocking_handler
#pragma weak comp0_isr = blocking_handler
#pragma weak comp1_isr = blocking_handler
#pragma weak comp2_isr = blocking_handler
#pragma weak sysctl_isr = blocking_handler
#pragma weak flash_isr = blocking_handler
#pragma weak gpiof_isr = blocking_handler
#pragma weak gpiog_isr = blocking_handler
#pragma weak gpioh_isr = blocking_handler
#pragma weak uart2_isr = blocking_handler
#pragma weak ssi1_isr = blocking_handler
#pragma weak timer3a_isr = blocking_handler
#pragma weak timer3b_isr = blocking_handler
#pragma weak i2c1_isr = blocking_handler
#pragma weak qei1_isr = blocking_handler
#pragma weak can0_isr = blocking_handler
#pragma weak can1_isr = blocking_handler
#pragma weak can2_isr = blocking_handler
#pragma weak eth_isr = blocking_handler
#pragma weak hibernate_isr = blocking_handler
#pragma weak usb0_isr = blocking_handler
#pragma weak pwm0_3_isr = blocking_handler
#pragma weak udma_isr = blocking_handler
#pragma weak udmaerr_isr = blocking_handler
#pragma weak adc1ss0_isr = blocking_handler
#pragma weak adc1ss1_isr = blocking_handler
#pragma weak adc1ss2_isr = blocking_handler
#pragma weak adc1ss3_isr = blocking_handler
#pragma weak i2s0_isr = blocking_handler
#pragma weak epi0_isr = blocking_handler
#pragma weak gpioj_isr = blocking_handler
#pragma weak gpiok_isr = blocking_handler
#pragma weak gpiol_isr = blocking_handler
#pragma weak ssi2_isr = blocking_handler
#pragma weak ssi3_isr = blocking_handler
#pragma weak uart3_isr = blocking_handler
#pragma weak uart4_isr = blocking_handler
#pragma weak uart5_isr = blocking_handler
#pragma weak uart6_isr = blocking_handler
#pragma weak uart7_isr = blocking_handler
#pragma weak i2c2_isr = blocking_handler
#pragma weak i2c3_isr = blocking_handler
#pragma weak timer4a_isr = blocking_handler
#pragma weak timer4b_isr = blocking_handler
#pragma weak timer5a_isr = blocking_handler
#pragma weak timer5b_isr = blocking_handler
#pragma weak wtimer0a_isr = blocking_handler
#pragma weak wtimer0b_isr = blocking_handler
#pragma weak wtimer1a_isr = blocking_handler
#pragma weak wtimer1b_isr = blocking_handler
#pragma weak wtimer2a_isr = blocking_handler
#pragma weak wtimer2b_isr = blocking_handler
#pragma weak wtimer3a_isr = blocking_handler
#pragma weak wtimer3b_isr = blocking_handler
#pragma weak wtimer4a_isr = blocking_handler
#pragma weak wtimer4b_isr = blocking_handler
#pragma weak wtimer5a_isr = blocking_handler
#pragma weak wtimer5b_isr = blocking_handler
#pragma weak sysexc_isr = blocking_handler
#pragma weak peci0_isr = blocking_handler
#pragma weak lpc0_isr = blocking_handler
#pragma weak i2c4_isr = blocking_handler
#pragma weak i2c5_isr = blocking_handler
#pragma weak gpiom_isr = blocking_handler
#pragma weak gpion_isr = blocking_handler
#pragma weak fan0_isr = blocking_handler
#pragma weak gpiop0_isr = blocking_handler
#pragma weak gpiop1_isr = blocking_handler
#pragma weak gpiop2_isr = blocking_handler
#pragma weak gpiop3_isr = blocking_handler
#pragma weak gpiop4_isr = blocking_handler
#pragma weak gpiop5_isr = blocking_handler
#pragma weak gpiop6_isr = blocking_handler
#pragma weak gpiop7_isr = blocking_handler
#pragma weak gpioq0_isr = blocking_handler
#pragma weak gpioq1_isr = blocking_handler
#pragma weak gpioq2_isr = blocking_handler
#pragma weak gpioq3_isr = blocking_handler
#pragma weak gpioq4_isr = blocking_handler
#pragma weak gpioq5_isr = blocking_handler
#pragma weak gpioq6_isr = blocking_handler
#pragma weak gpioq7_isr = blocking_handler
#pragma weak pwm1_0_isr = blocking_handler
#pragma weak pwm1_1_isr = blocking_handler
#pragma weak pwm1_2_isr = blocking_handler
#pragma weak pwm1_3_isr = blocking_handler
#pragma weak pwm1_fault_isr = blocking_handler

#define IRQ_HANDLERS \
                [IRQ_GPIOA] = gpioa_isr, \
                [IRQ_GPIOB] = gpiob_isr, \
                [IRQ_GPIOC] = gpioc_isr, \
                [IRQ_GPIOD] = gpiod_isr, \
                [IRQ_GPIOE] = gpioe_isr, \
                [IRQ_UART0] = uart0_isr, \
                [IRQ_UART1] = uart1_isr, \
                [IRQ_SSI0] = ssi0_isr, \
                [IRQ_I2C0] = i2c0_isr, \
                [IRQ_PWM0_FAULT] = pwm0_fault_isr, \
                [IRQ_PWM0_0] = pwm0_0_isr, \
                [IRQ_PWM0_1] = pwm0_1_isr, \
                [IRQ_PWM0_2] = pwm0_2_isr, \
                [IRQ_QEI0] = qei0_isr, \
                [IRQ_ADC0SS0] = adc0ss0_isr, \
                [IRQ_ADC0SS1] = adc0ss1_isr, \
                [IRQ_ADC0SS2] = adc0ss2_isr, \
                [IRQ_ADC0SS3] = adc0ss3_isr, \
                [IRQ_WATCHDOG] = watchdog_isr, \
                [IRQ_TIMER0A] = timer0a_isr, \
                [IRQ_TIMER0B] = timer0b_isr, \
                [IRQ_TIMER1A] = timer1a_isr, \
                [IRQ_TIMER1B] = timer1b_isr, \
                [IRQ_TIMER2A] = timer2a_isr, \
                [IRQ_TIMER2B] = timer2b_isr, \
                [IRQ_COMP0] = comp0_isr, \
                [IRQ_COMP1] = comp1_isr, \
                [IRQ_COMP2] = comp2_isr, \
                [IRQ_SYSCTL] = sysctl_isr, \
                [IRQ_FLASH] = flash_isr, \
                [IRQ_GPIOF] = gpiof_isr, \
                [IRQ_GPIOG] = gpiog_isr, \
                [IRQ_GPIOH] = gpioh_isr, \
                [IRQ_UART2] = uart2_isr, \
                [IRQ_SSI1] = ssi1_isr, \
                [IRQ_TIMER3A] = timer3a_isr, \
                [IRQ_TIMER3B] = timer3b_isr, \
                [IRQ_I2C1] = i2c1_isr, \
                [IRQ_QEI1] = qei1_isr, \
                [IRQ_CAN0] = can0_isr, \
                [IRQ_CAN1] = can1_isr, \
                [IRQ_CAN2] = can2_isr, \
                [IRQ_ETH] = eth_isr, \
                [IRQ_HIBERNATE] = hibernate_isr, \
                [IRQ_USB0] = usb0_isr, \
                [IRQ_PWM0_3] = pwm0_3_isr, \
                [IRQ_UDMA] = udma_isr, \
                [IRQ_UDMAERR] = udmaerr_isr, \
                [IRQ_ADC1SS0] = adc1ss0_isr, \
                [IRQ_ADC1SS1] = adc1ss1_isr, \
                [IRQ_ADC1SS2] = adc1ss2_isr, \
                [IRQ_ADC1SS3] = adc1ss3_isr, \
                [IRQ_I2S0] = i2s0_isr, \
                [IRQ_EPI0] = epi0_isr, \
                [IRQ_GPIOJ] = gpioj_isr, \
                [IRQ_GPIOK] = gpiok_isr, \
                [IRQ_GPIOL] = gpiol_isr, \
                [IRQ_SSI2] = ssi2_isr, \
                [IRQ_SSI3] = ssi3_isr, \
                [IRQ_UART3] = uart3_isr, \
                [IRQ_UART4] = uart4_isr, \
                [IRQ_UART5] = uart5_isr, \
                [IRQ_UART6] = uart6_isr, \
                [IRQ_UART7] = uart7_isr, \
                [IRQ_I2C2] = i2c2_isr, \
                [IRQ_I2C3] = i2c3_isr, \
                [IRQ_TIMER4A] = timer4a_isr, \
                [IRQ_TIMER4B] = timer4b_isr, \
                [IRQ_TIMER5A] = timer5a_isr, \
                [IRQ_TIMER5B] = timer5b_isr, \
                [IRQ_WTIMER0A] = wtimer0a_isr, \
                [IRQ_WTIMER0B] = wtimer0b_isr, \
                [IRQ_WTIMER1A] = wtimer1a_isr, \
                [IRQ_WTIMER1B] = wtimer1b_isr, \
                [IRQ_WTIMER2A] = wtimer2a_isr, \
                [IRQ_WTIMER2B] = wtimer2b_isr, \
                [IRQ_WTIMER3A] = wtimer3a_isr, \
                [IRQ_WTIMER3B] = wtimer3b_isr, \
                [IRQ_WTIMER4A] = wtimer4a_isr, \
                [IRQ_WTIMER4B] = wtimer4b_isr, \
                [IRQ_WTIMER5A] = wtimer5a_isr, \
                [IRQ_WTIMER5B] = wtimer5b_isr, \
                [IRQ_SYSEXC] = sysexc_isr, \
                [IRQ_PECI0] = peci0_isr, \
                [IRQ_LPC0] = lpc0_isr, \
                [IRQ_I2C4] = i2c4_isr, \
                [IRQ_I2C5] = i2c5_isr, \
                [IRQ_GPIOM] = gpiom_isr, \
                [IRQ_GPION] = gpion_isr, \
                [IRQ_FAN0] = fan0_isr, \
                [IRQ_GPIOP0] = gpiop0_isr, \
                [IRQ_GPIOP1] = gpiop1_isr, \
                [IRQ_GPIOP2] = gpiop2_isr, \
                [IRQ_GPIOP3] = gpiop3_isr, \
                [IRQ_GPIOP4] = gpiop4_isr, \
                [IRQ_GPIOP5] = gpiop5_isr, \
                [IRQ_GPIOP6] = gpiop6_isr, \
                [IRQ_GPIOP7] = gpiop7_isr, \
                [IRQ_GPIOQ0] = gpioq0_isr, \
                [IRQ_GPIOQ1] = gpioq1_isr, \
                [IRQ_GPIOQ2] = gpioq2_isr, \
                [IRQ_GPIOQ3] = gpioq3_isr, \
                [IRQ_GPIOQ4] = gpioq4_isr, \
                [IRQ_GPIOQ5] = gpioq5_isr, \
                [IRQ_GPIOQ6] = gpioq6_isr, \
                [IRQ_GPIOQ7] = gpioq7_isr, \
                [IRQ_PWM1_0] = pwm1_0_isr, \
                [IRQ_PWM1_1] = pwm1_1_isr, \
                [IRQ_PWM1_2] = pwm1_2_isr, \
                [IRQ_PWM1_3] = pwm1_3_isr, \
                [IRQ_PWM1_FAULT] = pwm1_fault_isr,

#endif

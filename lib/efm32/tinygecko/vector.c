/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>,
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/efm32/tinygecko/irq.h>
#include <libopencm3/efm32/vector.h>

#define WEAK __attribute__ ((weak))

/* Symbols exported by the linker script(s). */
extern unsigned _etext, _data, _edata, _ebss, _stack;

void main(void);
void blocking_handler(void);

void WEAK reset_handler(void);
void WEAK nmi_handler(void);
void WEAK hard_fault_handler(void);
void WEAK mem_manage_handler(void);
void WEAK bus_fault_handler(void);
void WEAK usage_fault_handler(void);
void WEAK sv_call_handler(void);
void WEAK debug_monitor_handler(void);
void WEAK pend_sv_handler(void);
void WEAK sys_tick_handler(void);

void WEAK dma_isr(void);
void WEAK gpio_even_isr(void);
void WEAK timer0_isr(void);
void WEAK usart0_rx_isr(void);
void WEAK usart0_tx_isr(void);
void WEAK acmp01_isr(void);
void WEAK adc0_isr(void);
void WEAK dac0_isr(void);
void WEAK i2c0_isr(void);
void WEAK gpio_odd_isr(void);
void WEAK timer1_isr(void);
void WEAK usart1_rx_isr(void);
void WEAK usart1_tx_isr(void);
void WEAK lesense_isr(void);
void WEAK leuart0_isr(void);
void WEAK letimer0_isr(void);
void WEAK pcnt0_isr(void);
void WEAK rtc_isr(void);
void WEAK cmu_isr(void);
void WEAK vcmp_isr(void);
void WEAK lcd_isr(void);
void WEAK msc_isr(void);
void WEAK aes_isr(void);

__attribute__ ((section(".vectors")))
efm32_vector_table_t vector_table = {
	.initial_sp_value = &_stack,
	.reset = reset_handler,
	.nmi = nmi_handler,
	.hard_fault = hard_fault_handler,
	.memory_manage_fault = mem_manage_handler,
	.bus_fault = bus_fault_handler,
	.usage_fault = usage_fault_handler,
	.sv_call = sv_call_handler,
	.pend_sv = pend_sv_handler,
	.systick = sys_tick_handler,
	.irq = {
		[IRQ_DMA] = dma_isr,
		[IRQ_GPIO_EVEN] = gpio_even_isr,
		[IRQ_TIMER0] = timer0_isr,
		[IRQ_USART0_RX] = usart0_rx_isr,
		[IRQ_USART0_TX] = usart0_tx_isr,
		[IRQ_ACMP01] = acmp01_isr,
		[IRQ_ADC0] = adc0_isr,
		[IRQ_DAC0] = dac0_isr,
		[IRQ_I2C0] = i2c0_isr,
		[IRQ_GPIO_ODD] = gpio_odd_isr,
		[IRQ_TIMER1] = timer1_isr,
		[IRQ_USART1_RX] = usart1_rx_isr,
		[IRQ_USART1_TX] = usart1_tx_isr,
		[IRQ_LESENSE] = lesense_isr,
		[IRQ_LEUART0] = leuart0_isr,
		[IRQ_LETIMER0] = letimer0_isr,
		[IRQ_PCNT0] = pcnt0_isr,
		[IRQ_RTC] = rtc_isr,
		[IRQ_CMU] = cmu_isr,
		[IRQ_VCMP] = vcmp_isr,
		[IRQ_LCD] = lcd_isr,
		[IRQ_MSC] = msc_isr,
		[IRQ_AES] = aes_isr,
	}
};

void WEAK reset_handler(void)
{
	volatile unsigned *src, *dest;

	__asm__("MSR msp, %0" : : "r"(&_stack));

	for (src = &_etext, dest = &_data; dest < &_edata; src++, dest++)
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

#pragma weak nmi_handler = blocking_handler
#pragma weak hard_fault_handler = blocking_handler
#pragma weak mem_manage_handler = blocking_handler
#pragma weak bus_fault_handler = blocking_handler
#pragma weak usage_fault_handler = blocking_handler
#pragma weak sv_call_handler = blocking_handler
#pragma weak debug_monitor_handler = blocking_handler
#pragma weak pend_sv_handler = blocking_handler
#pragma weak sys_tick_handler = blocking_handler

#pragma weak dma_isr = blocking_handler
#pragma weak gpio_even_isr = blocking_handler
#pragma weak timer0_isr = blocking_handler
#pragma weak usart0_rx_isr = blocking_handler
#pragma weak usart0_tx_isr = blocking_handler
#pragma weak acmp01_isr = blocking_handler
#pragma weak adc0_isr = blocking_handler
#pragma weak dac0_isr = blocking_handler
#pragma weak i2c0_isr = blocking_handler
#pragma weak gpio_odd_isr = blocking_handler
#pragma weak timer1_isr = blocking_handler
#pragma weak usart1_rx_isr = blocking_handler
#pragma weak usart1_tx_isr = blocking_handler
#pragma weak lesense_isr = blocking_handler
#pragma weak leuart0_isr = blocking_handler
#pragma weak letimer0_isr = blocking_handler
#pragma weak pcnt0_isr = blocking_handler
#pragma weak rtc_isr = blocking_handler
#pragma weak cmu_isr = blocking_handler
#pragma weak vcmp_isr = blocking_handler
#pragma weak lcd_isr = blocking_handler
#pragma weak msc_isr = blocking_handler
#pragma weak aes_isr = blocking_handler

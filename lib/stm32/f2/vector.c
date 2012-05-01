/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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
extern unsigned __exidx_end, _data, _edata, _ebss, _stack;

void main(void);
void reset_handler(void);
void blocking_handler(void);
void null_handler(void);

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
void WEAK wwdg_isr(void);
void WEAK pvd_isr(void);
void WEAK tamp_stamp_isr(void);
void WEAK rtc_wkup_isr(void);
void WEAK flash_isr(void);
void WEAK rcc_isr(void);
void WEAK exti0_isr(void);
void WEAK exti1_isr(void);
void WEAK exti2_isr(void);
void WEAK exti3_isr(void);
void WEAK exti4_isr(void);
void WEAK dma1_stream0_isr(void);
void WEAK dma1_stream1_isr(void);
void WEAK dma1_stream2_isr(void);
void WEAK dma1_stream3_isr(void);
void WEAK dma1_stream4_isr(void);
void WEAK dma1_stream5_isr(void);
void WEAK dma1_stream6_isr(void);
void WEAK adc_isr(void);
void WEAK can1_tx_isr(void);
void WEAK can1_rx0_isr(void);
void WEAK can1_rx1_isr(void);
void WEAK can1_sce_isr(void);
void WEAK exti9_5_isr(void);
void WEAK tim1_brk_tim9_isr(void);
void WEAK tim1_up_tim10_isr(void);
void WEAK tim1_trg_com_tim11_isr(void);
void WEAK tim1_cc_isr(void);
void WEAK tim2_isr(void);
void WEAK tim3_isr(void);
void WEAK tim4_isr(void);
void WEAK i2c1_ev_isr(void);
void WEAK i2c1_er_isr(void);
void WEAK i2c2_ev_isr(void);
void WEAK i2c2_er_isr(void);
void WEAK spi1_isr(void);
void WEAK spi2_isr(void);
void WEAK usart1_isr(void);
void WEAK usart2_isr(void);
void WEAK usart3_isr(void);
void WEAK exti15_10_isr(void);
void WEAK rtc_alarm_isr(void);
void WEAK usb_fs_wkup_isr(void);
void WEAK tim8_brk_tim12_isr(void);
void WEAK tim8_up_tim13_isr(void);
void WEAK tim8_trg_com_tim14_isr(void);
void WEAK tim8_cc_isr(void);
void WEAK dma1_stream7_isr(void);
void WEAK fsmc_isr(void);
void WEAK sdio_isr(void);
void WEAK tim5_isr(void);
void WEAK spi3_isr(void);
void WEAK uart4_isr(void);
void WEAK uart5_isr(void);
void WEAK tim6_dac_isr(void);
void WEAK tim7_isr(void);
void WEAK dma2_stream0_isr(void);
void WEAK dma2_stream1_isr(void);
void WEAK dma2_stream2_isr(void);
void WEAK dma2_stream3_isr(void);
void WEAK dma2_stream4_isr(void);
void WEAK eth_isr(void);
void WEAK eth_wkup_isr(void);
void WEAK can2_tx_isr(void);
void WEAK can2_rx0_isr(void);
void WEAK can2_rx1_isr(void);
void WEAK can2_sce_isr(void);
void WEAK otg_fs_isr(void);
void WEAK dma2_stream5_isr(void);
void WEAK dma2_stream6_isr(void);
void WEAK dma2_stream7_isr(void);
void WEAK usart6_isr(void);
void WEAK i2c3_ev_isr(void);
void WEAK i2c3_er_isr(void);
void WEAK otg_hs_ep1_out_isr(void);
void WEAK otg_hs_ep1_in_isr(void);
void WEAK otg_hs_wkup_isr(void);
void WEAK otg_hs_isr(void);
void WEAK dcmi_isr(void);
void WEAK cryp_isr(void);
void WEAK hash_rng_isr(void);

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
	wwdg_isr,
	pvd_isr,
	tamp_stamp_isr,
	rtc_wkup_isr,
	flash_isr,
	rcc_isr,
	exti0_isr,
	exti1_isr,
	exti2_isr,
	exti3_isr,
	exti4_isr,
	dma1_stream0_isr,
	dma1_stream1_isr,
	dma1_stream2_isr,
	dma1_stream3_isr,
	dma1_stream4_isr,
	dma1_stream5_isr,
	dma1_stream6_isr,
	adc_isr,
	can1_tx_isr,
	can1_rx0_isr,
	can1_rx1_isr,
	can1_sce_isr,
	exti9_5_isr,
	tim1_brk_tim9_isr,
	tim1_up_tim10_isr,
	tim1_trg_com_tim11_isr,
	tim1_cc_isr,
	tim2_isr,
	tim3_isr,
	tim4_isr,
	i2c1_ev_isr,
	i2c1_er_isr,
	i2c2_ev_isr,
	i2c2_er_isr,
	spi1_isr,
	spi2_isr,
	usart1_isr,
	usart2_isr,
	usart3_isr,
	exti15_10_isr,
	rtc_alarm_isr,
	usb_fs_wkup_isr,
	tim8_brk_tim12_isr,
	tim8_up_tim13_isr,
	tim8_trg_com_tim14_isr,
	tim8_cc_isr,
	dma1_stream7_isr,
	fsmc_isr,
	sdio_isr,
	tim5_isr,
	spi3_isr,
	uart4_isr,
	uart5_isr,
	tim6_dac_isr,
	tim7_isr,
	dma2_stream0_isr,
	dma2_stream1_isr,
	dma2_stream2_isr,
	dma2_stream3_isr,
	dma2_stream4_isr,
	eth_isr,
	eth_wkup_isr,
	can2_tx_isr,
	can2_rx0_isr,
	can2_rx1_isr,
	can2_sce_isr,
	otg_fs_isr,
	dma2_stream5_isr,
	dma2_stream6_isr,
	dma2_stream7_isr,
	usart6_isr,
	i2c3_ev_isr,
	i2c3_er_isr,
	otg_hs_ep1_out_isr,
	otg_hs_ep1_in_isr,
	otg_hs_wkup_isr,
	otg_hs_isr,
	dcmi_isr,
	cryp_isr,
	hash_rng_isr,
};

void reset_handler(void)
{
	volatile unsigned *src, *dest;

	__asm__("MSR msp, %0" : : "r"(&_stack));

	for (src = &__exidx_end, dest = &_data; dest < &_edata; src++, dest++)
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
#pragma weak wwdg_isr = null_handler
#pragma weak pvd_isr = null_handler
#pragma weak tamp_stamp_isr = null_handler
#pragma weak rtc_wkup_isr = null_handler
#pragma weak flash_isr = null_handler
#pragma weak rcc_isr = null_handler
#pragma weak exti0_isr = null_handler
#pragma weak exti1_isr = null_handler
#pragma weak exti2_isr = null_handler
#pragma weak exti3_isr = null_handler
#pragma weak exti4_isr = null_handler
#pragma weak dma1_stream0_isr = null_handler
#pragma weak dma1_stream1_isr = null_handler
#pragma weak dma1_stream2_isr = null_handler
#pragma weak dma1_stream3_isr = null_handler
#pragma weak dma1_stream4_isr = null_handler
#pragma weak dma1_stream5_isr = null_handler
#pragma weak dma1_stream6_isr = null_handler
#pragma weak adc_isr = null_handler
#pragma weak can1_tx_isr = null_handler
#pragma weak can1_rx0_isr = null_handler
#pragma weak can1_rx1_isr = null_handler
#pragma weak can1_sce_isr = null_handler
#pragma weak exti9_5_isr = null_handler
#pragma weak tim1_brk_tim9_isr = null_handler
#pragma weak tim1_up_tim10_isr = null_handler
#pragma weak tim1_trg_com_tim11_isr = null_handler
#pragma weak tim1_cc_isr = null_handler
#pragma weak tim2_isr = null_handler
#pragma weak tim3_isr = null_handler
#pragma weak tim4_isr = null_handler
#pragma weak i2c1_ev_isr = null_handler
#pragma weak i2c1_er_isr = null_handler
#pragma weak i2c2_ev_isr = null_handler
#pragma weak i2c2_er_isr = null_handler
#pragma weak spi1_isr = null_handler
#pragma weak spi2_isr = null_handler
#pragma weak usart1_isr = null_handler
#pragma weak usart2_isr = null_handler
#pragma weak usart3_isr = null_handler
#pragma weak exti15_10_isr = null_handler
#pragma weak rtc_alarm_isr = null_handler
#pragma weak usb_fs_wkup_isr = null_handler
#pragma weak tim8_brk_tim12_isr = null_handler
#pragma weak tim8_up_tim13_isr = null_handler
#pragma weak tim8_trg_com_tim14_isr = null_handler
#pragma weak tim8_cc_isr = null_handler
#pragma weak dma1_stream7_isr = null_handler
#pragma weak fsmc_isr = null_handler
#pragma weak sdio_isr = null_handler
#pragma weak tim5_isr = null_handler
#pragma weak spi3_isr = null_handler
#pragma weak uart4_isr = null_handler
#pragma weak uart5_isr = null_handler
#pragma weak tim6_dac_isr = null_handler
#pragma weak tim7_isr = null_handler
#pragma weak dma2_stream0_isr = null_handler
#pragma weak dma2_stream1_isr = null_handler
#pragma weak dma2_stream2_isr = null_handler
#pragma weak dma2_stream3_isr = null_handler
#pragma weak dma2_stream4_isr = null_handler
#pragma weak eth_isr = null_handler
#pragma weak eth_wkup_isr = null_handler
#pragma weak can2_tx_isr = null_handler
#pragma weak can2_rx0_isr = null_handler
#pragma weak can2_rx1_isr = null_handler
#pragma weak can2_sce_isr = null_handler
#pragma weak otg_fs_isr = null_handler
#pragma weak dma2_stream5_isr = null_handler
#pragma weak dma2_stream6_isr = null_handler
#pragma weak dma2_stream7_isr = null_handler
#pragma weak usart6_isr = null_handler
#pragma weak i2c3_ev_isr = null_handler
#pragma weak i2c3_er_isr = null_handler
#pragma weak otg_hs_ep1_out_isr = null_handler
#pragma weak otg_hs_ep1_in_isr = null_handler
#pragma weak otg_hs_wkup_isr = null_handler
#pragma weak otg_hs_isr = null_handler
#pragma weak dcmi_isr = null_handler
#pragma weak cryp_isr = null_handler
#pragma weak hash_rng_isr = null_handler

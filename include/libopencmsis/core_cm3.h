/* big fat FIXME: this should use a consistent structure, and reference
 * functionality from libopencm3 instead of copypasting.
 *
 * particularly unimplemented features are FIXME'd extra
 * */

#ifndef OPENCMSIS_CORECM3_H
#define OPENCMSIS_CORECM3_H

/* needed in various places where we rather should include libopencm3 functionality */
#define MMIO32(addr)                    (*(volatile uint32_t *)(addr))

/* the original core_cm3.h is nonfree by arm; this provides libopencm3 variant of the symbols efm32lib needs of CMSIS. */
#include <stdint.h>

/* needed by system_efm32.h:196, guessing */
#define __INLINE inline
/* new since emlib 3.0 */
#define __STATIC_INLINE static inline

/* needed around efm32tg840f32.h:229. comparing the efm32lib definitions to the
 * libopencm3 ones, "volatile" is all that's missing. */
#define __IO volatile
#define __O volatile
#define __I volatile

/* -> style access for what is defined in libopencm3/stm32/f1/scb.h /
 * cm3/memorymap.h, as it's needed by efm32lib/inc/efm32_emu.h */

/* from stm32/f1/scb.h */
#define SCB_SCR_SLEEPDEEP_Msk  (1 << 2)
/* structure as in, for example,
 * DeviceSupport/EnergyMicro/EFM32/efm32tg840f32.h, data from
 * libopencm3/stm32/f1/scb.h. FIXME incomplete. */
typedef struct
{
	__IO uint32_t CPUID;
	__IO uint32_t ICSR;
	__IO uint32_t VTOR;
	__IO uint32_t AIRCR;
	__IO uint32_t SCR;
	__IO uint32_t CCR;
	__IO uint8_t SHPR[12]; /* FIXME: how is this properly indexed? */
	__IO uint32_t SHCSR;
} SCB_TypeDef;
#define SCB ((SCB_TypeDef *) SCB_BASE)
/* from libopencm3/cm3/memorymap.h */
#define PPBI_BASE                       0xE0000000
#define SCS_BASE                        (PPBI_BASE + 0xE000)
#define SCB_BASE                        (SCS_BASE + 0x0D00)

/* needed by efm32_emu.h, guessing and taking the implementation used in
 * lightswitch-interrupt.c */
#define __WFI() __asm__("wfi")

/* needed by efm32_cmu.h, probably it's just what gcc provides anyway */
#define __CLZ(div) __builtin_clz(div)

/* needed by efm32_aes.c. __builtin_bswap32 does the same thing as the rev instruction according to https://bugzilla.mozilla.org/show_bug.cgi?id=600106 */
#define __REV(x) __builtin_bswap32(x)

/* stubs for efm32_dbg.h */
typedef struct
{
	uint32_t DHCSR;
	uint32_t DEMCR; /* needed by efm32tg stk trace.c */
} CoreDebug_TypeDef;
/* FIXME let's just hope writes to flash are protected */
#define CoreDebug ((CoreDebug_TypeDef *) 0)
#define CoreDebug_DHCSR_C_DEBUGEN_Msk 0
#define CoreDebug_DEMCR_TRCENA_Msk 0

/* stubs for efm32_dma */

/* also used by the clock example. code taken from stm32's nvic.[hc], FIXME until
 * the generic cm3 functionality is moved out from stm32 and can be used here
 * easily (nvic_clear_pending_irq, nvic_enable_irq, nvic_disable_irq). */
#define NVIC_BASE                       (SCS_BASE + 0x0100)
#define NVIC_ISER(iser_id)		MMIO32(NVIC_BASE + 0x00 + (iser_id * 4))
#define NVIC_ICER(icer_id)		MMIO32(NVIC_BASE + 0x80 + (icer_id * 4))
#define NVIC_ICPR(icpr_id)		MMIO32(NVIC_BASE + 0x180 + (icpr_id * 4))
static inline void NVIC_ClearPendingIRQ(uint8_t irqn)
{
	NVIC_ICPR(irqn / 32) = (1 << (irqn % 32));
}
static inline void NVIC_EnableIRQ(uint8_t irqn)
{
	NVIC_ISER(irqn / 32) = (1 << (irqn % 32));
}
static inline void NVIC_DisableIRQ(uint8_t irqn)
{
	NVIC_ICER(irqn / 32) = (1 << (irqn % 32));
}

/* stubs for efm32_int. FIXME: how do they do that? nvic documentation in the
 * efm32 core manual doesn't tell anything of a global on/off switch */

#define __enable_irq() 1
#define __disable_irq() 1

/* stubs for efm32_mpu FIXME */

#define SCB_SHCSR_MEMFAULTENA_Msk 0

typedef struct
{
	uint32_t CTRL;
	uint32_t RNR;
	uint32_t RBAR;
	uint32_t RASR;
} MPU_TypeDef;
/* FIXME struct at NULL */
#define MPU ((MPU_TypeDef *) 0)
#define MPU_CTRL_ENABLE_Msk 0
#define MPU_RASR_XN_Pos 0
#define MPU_RASR_AP_Pos 0
#define MPU_RASR_TEX_Pos 0
#define MPU_RASR_S_Pos 0
#define MPU_RASR_C_Pos 0
#define MPU_RASR_B_Pos 0
#define MPU_RASR_SRD_Pos 0
#define MPU_RASR_SIZE_Pos 0
#define MPU_RASR_ENABLE_Pos 0

/* required for the blink example */

/* if if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) while (1) ;
 * configures the sys ticks to 1ms, then the argument to SysTick_Config
 * describes how many cycles to wait between two systicks.
 *
 * the endless loop part looks like an "if it returns an error condition,
 * rather loop here than continue"; every other solution would involve things
 * that are dark magic to my understanding.
 *
 * implementation more or less copypasted from lib/stm32/systick.c, FIXME until
 * the generic cm3 functionality is moved out from stm32 and can be used here
 * easily (systick_set_reload, systick_interrupt_enable, systick_counter_enable
 * and systick_set_clocksource).
 *
 * modified for CMSIS style array as the powertest example needs it.
 * */
#define SYS_TICK_BASE                   (SCS_BASE + 0x0010)

/* from d0002_efm32_cortex-m3_reference_manual.pdf section 4.4 */
typedef struct
{
	uint32_t CTRL;
	uint32_t LOAD;
	uint32_t VAL;
	uint32_t CALIB;
} SysTick_TypeDef;
#define SysTick ((SysTick_TypeDef *) SYS_TICK_BASE)

#define STK_CTRL_TICKINT		(1 << 1)
#define STK_CTRL_ENABLE			(1 << 0)

#define STK_CTRL_CLKSOURCE_LSB		2
#define STK_CTRL_CLKSOURCE_AHB		1
static inline uint32_t SysTick_Config(uint32_t n_ticks)
{
	if (n_ticks & ~0x00FFFFFF) return 1;
	SysTick->LOAD = n_ticks;

	SysTick->CTRL |= (STK_CTRL_CLKSOURCE_AHB << STK_CTRL_CLKSOURCE_LSB);

	SysTick->CTRL |= STK_CTRL_TICKINT;

	SysTick->CTRL |= STK_CTRL_ENABLE;

	return 0;
}

/* stubs for efm32tg stk trace.c */
typedef struct
{
	uint32_t LAR;
	uint32_t TCR;
} ITM_TypeDef;
/* FIXME struct at NULL */
#define ITM ((ITM_TypeDef *) 0)

/* blink.h expects the isr for systicks to be named SysTick_Handler. with this,
 * its Systick_Handler function gets renamed to the weak symbol exported by
 * vector.c */
#define SysTick_Handler sys_tick_handler

/* likewise, clock.c defines GPIO_ODD_IRQHandler and GPIO_EVEN_IRQHandler */
#define GPIO_ODD_IRQHandler gpio_odd_isr
#define GPIO_EVEN_IRQHandler gpio_even_isr
#define RTC_IRQHandler rtc_isr

/* for inttemp (i should really get a list and convert them all) */

#define ADC0_IRQHandler adc0_isr

/* for the lightsense example */

#define LESENSE_IRQHandler lesense_isr
#define PCNT0_IRQHandler pcnt0_isr

#endif

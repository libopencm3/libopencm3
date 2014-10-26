/* big fat FIXME: this should use a consistent structure, and reference
 * functionality from libopencm3 instead of copypasting.
 *
 * particularly unimplemented features are FIXME'd extra
 * */

/* the original core_cm3.h is nonfree by arm; this provides libopencm3 variant
 * of the symbols efm32lib needs of CMSIS. */

#ifndef OPENCMSIS_CORECM3_H
#define OPENCMSIS_CORECM3_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/cm3/cortex.h>
#include <libopencm3/cm3/memorymap.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/scb.h>

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

/* from cm3/scb.h */
#define SCB_SCR_SLEEPDEEP_Msk  SCB_SCR_SLEEPDEEP

/* structure as in, for example,
 * DeviceSupport/EnergyMicro/EFM32/efm32tg840f32.h, data from
 * libopencm3/cm3/scb.h. FIXME incomplete. */
typedef struct {
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

/* needed by efm32_emu.h, guessing and taking the implementation used in
 * lightswitch-interrupt.c */
#define __WFI() __asm__("wfi")

/* needed by efm32_cmu.h, probably it's just what gcc provides anyway */
#define __CLZ(div) __builtin_clz(div)

/* needed by efm32_aes.c. __builtin_bswap32 does the same thing as the rev
 * instruction according to https://bugzilla.mozilla.org/show_bug.cgi?id=600106
 */
#define __REV(x) __builtin_bswap32(x)

/* stubs for efm32_dbg.h */
typedef struct {
	uint32_t DHCSR;
	uint32_t DEMCR; /* needed by efm32tg stk trace.c */
} CoreDebug_TypeDef;
/* FIXME let's just hope writes to flash are protected */
#define CoreDebug ((CoreDebug_TypeDef *) 0)
#define CoreDebug_DHCSR_C_DEBUGEN_Msk 0
#define CoreDebug_DEMCR_TRCENA_Msk 0

/* stubs for efm32_dma */

static inline void NVIC_ClearPendingIRQ(uint8_t irqn)
{
	nvic_clear_pending_irq(irqn);
}
static inline void NVIC_EnableIRQ(uint8_t irqn)
{
	nvic_enable_irq(irqn);
}
static inline void NVIC_DisableIRQ(uint8_t irqn)
{
	nvic_disable_irq(irqn);
}

/* stubs for efm32_int */

static inline void __enable_irq(void)
{
	cm_enable_interrupts();
}
static inline void __disable_irq(void)
{
	cm_disable_interrupts();
}

/* stubs for efm32_mpu FIXME */

#define SCB_SHCSR_MEMFAULTENA_Msk 0

typedef struct {
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

/* from d0002_efm32_cortex-m3_reference_manual.pdf section 4.4 */
typedef struct {
	uint32_t CTRL;
	uint32_t LOAD;
	uint32_t VAL;
	uint32_t CALIB;
} SysTick_TypeDef;
#define SysTick ((SysTick_TypeDef *) SYS_TICK_BASE)

static inline uint32_t SysTick_Config(uint32_t n_ticks)
{
	/* constant from systick_set_reload -- as this returns something that's
	 * not void, this is the only possible error condition */
	if (n_ticks & ~0x00FFFFFF) {
		return 1;
	}

	systick_set_reload(n_ticks);
	systick_set_clocksource(true);
	systick_interrupt_enable();
	systick_counter_enable();

	return 0;
}

/* stubs for efm32tg stk trace.c */
typedef struct {
	uint32_t LAR;
	uint32_t TCR;
} ITM_TypeDef;
/* FIXME struct at NULL */
#define ITM ((ITM_TypeDef *) 0)

/* blink.h expects the isr for systicks to be named SysTick_Handler. with this,
 * its Systick_Handler function gets renamed to the weak symbol exported by
 * vector.c */

#define SysTick_Handler sys_tick_handler
/* FIXME: this needs to be done for all of the 14 hard vectors */

#include <libopencmsis/dispatch/irqhandlers.h>

#endif

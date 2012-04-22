#ifndef OPENCMSIS_CORECM3_H
#define OPENCMSIS_CORECM3_H

/* the original core_cm3.h is nonfree by arm; this provides libopencm3 variant of the symbols efm32lib needs of CMSIS. */
#include <stdint.h>

/* needed by system_efm32.h:196, guessing */
#define __INLINE inline

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
 * libopencm3/stm32/f1/scb.h. incomplete. */
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

/* stubs for efm32_cmu.c */
#define SystemCoreClockGet() 1
#define SystemHFClockGet() 1

uint32_t SystemLFRCOClockGet(void);
uint32_t SystemLFXOClockGet(void);

/* stubs for efm32_dbg.h */
typedef struct
{
	uint32_t DHCSR;
} CoreDebug_TypeDef;
#define CoreDebug ((CoreDebug_TypeDef *) 0)
#define CoreDebug_DHCSR_C_DEBUGEN_Msk 0

/* stubs for efm32_dma */

#define NVIC_ClearPendingIRQ(irq) 1
#define NVIC_EnableIRQ(irq) 1
#define NVIC_DisableIRQ(irq) 1

/* stubs for efm32_int */

#define __enable_irq() 1
#define __disable_irq() 1

/* stubs for efm32_mpu */

#define SCB_SHCSR_MEMFAULTENA_Msk 0

typedef struct
{
	uint32_t CTRL;
	uint32_t RNR;
	uint32_t RBAR;
	uint32_t RASR;
} MPU_TypeDef;
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
#define MPU_RASR_ENA_Pos 0

#endif

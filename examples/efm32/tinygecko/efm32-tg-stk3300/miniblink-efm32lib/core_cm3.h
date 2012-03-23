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

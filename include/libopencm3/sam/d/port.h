/** @defgroup port_defines IO Port Definitions
 *
 * @ingroup SAMD_defines
 *
 * @brief Defined Constants and Types for the SAMD Port controller
 *
 * @copyright SPDX: LGPL-3.0-or-later
 * @author 2016 Karl Palsson <karlp@tweak.net.au>
 * @author 2020 Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>
 */

#pragma once

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/d/memorymap.h>

/* --- Convenience macros ------------------------------------------------ */

/**@defgroup port_reg_base Port Base registers
 * @{
 */
#define PORTA				(PORT_BASE + 0)
#define PORTB				(PORT_BASE + 0x80)
/**@}*/

/* GPIO number definitions (for convenience) */
/** @defgroup gpio_pin_id GPIO Pin Identifiers
@{*/
#define GPIO0			(1 << 0)
#define GPIO1			(1 << 1)
#define GPIO2			(1 << 2)
#define GPIO3			(1 << 3)
#define GPIO4			(1 << 4)
#define GPIO5			(1 << 5)
#define GPIO6			(1 << 6)
#define GPIO7			(1 << 7)
#define GPIO8			(1 << 8)
#define GPIO9			(1 << 9)
#define GPIO10			(1 << 10)
#define GPIO11			(1 << 11)
#define GPIO12			(1 << 12)
#define GPIO13			(1 << 13)
#define GPIO14			(1 << 14)
#define GPIO15			(1 << 15)
#define GPIO16			(1 << 16)
#define GPIO17			(1 << 17)
#define GPIO18			(1 << 18)
#define GPIO19			(1 << 19)
#define GPIO20			(1 << 20)
#define GPIO21			(1 << 21)
#define GPIO22			(1 << 22)
#define GPIO23			(1 << 23)
#define GPIO24			(1 << 24)
#define GPIO25			(1 << 25)
#define GPIO26			(1 << 26)
#define GPIO27			(1 << 27)
#define GPIO28			(1 << 28)
#define GPIO29			(1 << 29)
#define GPIO30			(1 << 30)
#define GPIO31			(1 << 31)
#define GPIO_ALL		0xffff
/**@}*/

/* GPIO mux definitions (for convenience) */
/** @defgroup gpio_mux GPIO mux configuration
@{*/
enum port_mux {
	PORT_PMUX_FUN_A = 0,
	PORT_PMUX_FUN_B,
	PORT_PMUX_FUN_C,
	PORT_PMUX_FUN_D,
	PORT_PMUX_FUN_E,
	PORT_PMUX_FUN_F,
	PORT_PMUX_FUN_G,
	PORT_PMUX_FUN_H,
	PORT_PMUX_FUN_I
};
/**@}*/

/** @defgroup port_registers PORT Registers
 * @{
 */
/** Direction register */
#define PORT_DIR(port)			MMIO32((port) + 0x0000)

/** Direction clear register */
#define PORT_DIRCLR(port)		MMIO32((port) + 0x0004)

/** Direction set register */
#define PORT_DIRSET(port)		MMIO32((port) + 0x0008)

/** Direction toggle register */
#define PORT_DIRTGL(port)		MMIO32((port) + 0x000c)

/** output register */
#define PORT_OUT(port)			MMIO32((port) + 0x0010)

/** output clear register */
#define PORT_OUTCLR(port)		MMIO32((port) + 0x0014)

/** output set register */
#define PORT_OUTSET(port)		MMIO32((port) + 0x0018)

/** output toggle register */
#define PORT_OUTTGL(port)		MMIO32((port) + 0x001c)

/** input register */
#define PORT_IN(port)			MMIO32((port) + 0x0020)

/** Control register */
#define PORT_CTRL(port)			MMIO32((port) + 0x0024)

/** Write configuration register */
#define PORT_WRCONFIG(port)		MMIO32((port) + 0x0028)

/** Peripheral multiplexing registers */
#define PORT_PMUX(port, n)		MMIO8((port) + 0x0030 + (n))

/** Pin configuration registers */
#define PORT_PINCFG(port, n)		MMIO8((port) + 0x0040 + (n))
/**@}*/

/* --- PORTx_DIR values ---------------------------------------------------- */

/* PORTx_DIR[31:0]: DIRy[31:0]: Port x set bit y direction [y=0..31] */

/* --- PORTx_DIRCLR values ------------------------------------------------- */

/* PORTx_DIRCLR[31:0]: DIRCLRy[31:0]: Port x set bit y as input [y=0..31] */

/* --- PORTx_DIRSET values ------------------------------------------------- */

/* PORTx_DIRSET[31:0]: DIRSETy[31:0]: Port x set bit y as output [y=0..31] */

/* --- PORTx_DIRTGL values ------------------------------------------------- */

/* PORTx_DIRTGL[31:0]: DIRTGLy[31:0]: Port x toggle bit y direction [y=0..31] */

/* --- PORTx_OUT values ---------------------------------------------------- */

/* PORTx_OUT[31:0]: OUTy[31:0]: Port output data [y=0..31] */

/* --- PORTx_OUTCLR values ------------------------------------------------- */

/* PORTx_OUTCLR[31:0]: OUTCLRy[31:0]: Port x reset bit y [y=0..31] */

/* --- PORTx_OUTSET values ------------------------------------------------- */

/* PORTx_OUTSET[31:0]: OUTSETy[31:0]: Port x set bit y [y=0..31] */

/* --- PORTx_OUTTGL values ------------------------------------------------- */

/* PORTx_OUTTGL[31:0]: OUTTGLy[31:0]: Port x toggle bit y [y=0..31] */

/* --- PORTx_IN values ----------------------------------------------------- */

/* PORTx_IN[31:0]: INy[31:0]: Port input data [y=0..31] */

/* --- PORTx_CTRL values --------------------------------------------------- */

/* PORTx_CTRL[31:0]: CTRLy[31:0]: Port input sampling mode [y=0..31] */

/**@defgroup port_wrconfig_values PortX WRCONFIG Values
 * @{
 */
/** HWSEL: Half word select: 0 [15:0], 1 [31:16] */
#define PORT_WRCONFIG_HWSEL         (1 << 31)

/** WRPINCFG: Write PINCFG: 1 to update pins for selected by PINMASK */
#define PORT_WRCONFIG_WRPINCFG      (1 << 30)

/** WRPMUX: Write PMUX: 1 to update pins pmux for selected by PINMASK */
#define PORT_WRCONFIG_WRPMUX        (1 << 28)

/** PMUX: Peripheral Multiplexing: determine pmux for pins selected by PINMASK */
#define PORT_WRCONFIG_PMUX(mux)     ((0xf & (mux)) << 24)

/** DRVSTR: Output Driver Strength Selection: determine strength for pins in PINMASK */
#define PORT_WRCONFIG_DRVSTR        (1 << 22)

/** PULLEN: Pull Enable: enable PINCFGy.PULLEN for pins in PINMASK */
#define PORT_WRCONFIG_PULLEN        (1 << 18)

/** INEN: Input Enable: enable PINCFGy.INEN for pins in PINMASK */
#define PORT_WRCONFIG_INEN          (1 << 17)

/** PMUXEN: Peripheral Multiplexer Enable: enable PINCFGy.PMUXEN for pins in PINMASK */
#define PORT_WRCONFIG_PMUXEN        (1 << 16)

/** PINMASK: Pin Mask for Multiple Pin Configuration: select pins to be configured
 *          [31:16] if HWSET=1, [15:0] if HWSET=0
 */
#define PORT_WRCONFIG_PINMASK(pins) ((0xffff & (pins)) << 0)
/**@}*/

/* --- PORTx_PMUX values --------------------------------------------------- */

/** PMUXO: Peripheral Multiplexing for Odd-Numbered Pin: 2*x+1 pin multiplexing */
#define PORT_PMUX_PMUXO(mux)        ((0xf & (mux)) << 4)

/** PMUXE: Peripheral Multiplexing for Even-Numbered Pin: 2*x pin multiplexing */
#define PORT_PMUX_PMUXE(mux)        ((0xf & (mux)) << 0)

/* --- PORTx_PINCFGy values ------------------------------------------------ */

/* Bit 7: Reserved */

/** DRVSTR: Output Driver Strength Selection */
#define PORT_PINCFG_DRVSTR (1 << 6)

/** PULLEN: Pull Enable */
#define PORT_PINCFG_PULLEN (1 << 2)

/** INEN: Input Enable */
#define PORT_PINCFG_INEN   (1 << 1)

/** PMUXEN: Peripheral Multiplexer Enable */
#define PORT_PINCFG_PMUXEN (1 << 0)

/* --- Convenience enums --------------------------------------------------- */

/** @defgroup gpio_direction GPIO Pin direction
@{*/
#define GPIO_MODE_INPUT		0x00
#define GPIO_MODE_OUTPUT	0x01
#define GPIO_MODE_INOUT		0x02
/**@}*/

/** @defgroup gpio_cnf GPIO mode configuration
@li Float
@li PullDown
@li PullUp
@li Alternate Function
@{*/
#define GPIO_CNF_FLOAT		0x00
#define GPIO_CNF_PULLDOWN	0x01
#define GPIO_CNF_PULLUP		0x02
#define GPIO_CNF_AF			0x03
/**@}*/

BEGIN_DECLS

void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t cnf, uint32_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t af, uint32_t gpios);
void gpio_set(uint32_t gpioport, uint32_t gpios);
void gpio_clear(uint32_t gpioport, uint32_t gpios);
uint32_t gpio_get(uint32_t gpioport, uint32_t gpios);
void gpio_toggle(uint32_t gpioport, uint32_t gpios);
uint32_t port_read(uint32_t port);
void port_write(uint32_t port, uint32_t data);

END_DECLS

/**@}*/

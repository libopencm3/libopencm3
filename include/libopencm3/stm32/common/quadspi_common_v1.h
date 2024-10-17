/** @addtogroup quadspi_defines
 * @author Chuck McManis <cmcmanis@mcmanis.com> 2016
 * @author Roman Buchert <libopencm3@ro-bu.net> 2024
 * @copyright SPDX: LGPL-3.0-or-later
 * @{
 */

#pragma once

/** @addtogroup quadspi_registers QuadSPI Registers
 * @{
 */
/** QUADSPI Control register */
#define QUADSPI_CR      MMIO32(QUADSPI_BASE + 0x0U)

/** QUADSPI Device Configuration */
#define QUADSPI_DCR     MMIO32(QUADSPI_BASE + 0x4U)

/** QUADSPI Status Register */
#define QUADSPI_SR      MMIO32(QUADSPI_BASE + 0x8U)

/** QUADSPI Flag Clear Register */
#define QUADSPI_FCR     MMIO32(QUADSPI_BASE + 0xCU)

/** QUADSPI Data Length Register */
#define QUADSPI_DLR     MMIO32(QUADSPI_BASE + 0x10U)

/** QUADSPI Communication Configuration Register */
#define QUADSPI_CCR     MMIO32(QUADSPI_BASE + 0x14U)

/** QUADSPI address register */
#define QUADSPI_AR      MMIO32(QUADSPI_BASE + 0x18U)

/** QUADSPI alternate bytes register */
#define QUADSPI_ABR     MMIO32(QUADSPI_BASE + 0x1CU)

/** QUADSPI data register */
#define QUADSPI_DR      MMIO32(QUADSPI_BASE + 0x20U)
/** BYTE addressable version for fetching bytes from the interface */
#define QUADSPI_BYTE_DR     MMIO8(QUADSPI_BASE + 0x20U)

/** QUADSPI polling status */
#define QUADSPI_PSMKR     MMIO32(QUADSPI_BASE + 0x24U)

/** QUADSPI polling status match */
#define QUADSPI_PSMAR     MMIO32(QUADSPI_BASE + 0x28U)

/** QUADSPI polling interval register */
#define QUADSPI_PIR     MMIO32(QUADSPI_BASE + 0x2CU)

/** QUADSPI low power timeout */
#define QUADSPI_LPTR      MMIO32(QUADSPI_BASE + 0x30U)
/**@}*/

#define QUADSPI_CR_PRESCALE_MASK  0xff
#define QUADSPI_CR_PRESCALE_SHIFT 24
#define QUADSPI_CR_PMM      (1 << 23)
#define QUADSPI_CR_APMS     (1 << 22)
/* bit 21 is reserved */

/**
@defgroup quadspi_irq_enable QUADSPI_CR interrupt enable values
@{*/
/* TOIE:*/ /** Timeout interrupt enable */
#define QUADSPI_CR_TOIE     (1 << 20)
/* SMIE:*/ /** Status match interrupt enable */
#define QUADSPI_CR_SMIE     (1 << 19)
/* FTIE:*/ /** FIFO threshold interrupt enable */
#define QUADSPI_CR_FTIE     (1 << 18)
/* TCIE:*/ /** Transfer complete interrupt enable */
#define QUADSPI_CR_TCIE     (1 << 17)
/* TEIE*/ /** Transfer error interrupt enable */
#define QUADSPI_CR_TEIE     (1 << 16)
/**@}*/

/* bits 15:13 reserved */
#define QUADSPI_CR_FTHRES_MASK    0x1f
#define QUADSPI_CR_FTHRES_SHIFT   8
#define QUADSPI_CR_FSEL     (1 << 7)
#define QUADSPI_CR_DFM      (1 << 6)
#define QUADPSI_CR_DFM_FSEL_MASK  0x3
#define QUADSPI_CR_DFM_FSEL_SHIFT 6
/* bit 5 reserved */
#define QUADSPI_CR_SSHIFT   (1 << 4)
#define QUADSPI_CR_TCEN     (1 << 3)
/* bit 2 reserved on h7, DMAEN on f4 */
#define QUADSPI_CR_ABORT    (1 << 1)
#define QUADSPI_CR_EN     (1 << 0)

/* bits 31:21 reserved */
#define QUADSPI_DCR_FSIZE_MASK    0x1f
#define QUADSPI_DCR_FSIZE_SHIFT   16
/* bits 15:11 reserved */
#define QUADSPI_DCR_CSHT_MASK   0x7
#define QUADSPI_DCR_CSHT_SHIFT    8
/* bits 7:1 reserved */
#define QUADSPI_DCR_CKMODE    (1 << 0)

/* bits 31:14 reserved */
#define QUADSPI_SR_FLEVEL_MASK    0x3f
#define QUADSPI_SR_FLEVEL_SHIFT   8

/* bits 7:6 reserved */
/**
@defgroup quadspi_sr_values QUADSPI status register values
@{*/
/* BUSY:*/ /** Busy flag*/
#define QUADSPI_SR_BUSY     (1 << 5)
/* TOF:*/ /** Timeout flag*/
#define QUADSPI_SR_TOF      (1 << 4)
/* SMF:*/ /** Status match flag */
#define QUADSPI_SR_SMF      (1 << 3)
/* FTF:*/ /** FIFO threshold flag */
#define QUADSPI_SR_FTF      (1 << 2)
/* TCF:*/ /** Transfer complete flag */
#define QUADSPI_SR_TCF      (1 << 1)
/* TEF:*/ /** Transfer error flag */
#define QUADSPI_SR_TEF      (1 << 0)
/**@}*/

/**
@defgroup quadspi_fcr_values QUADSPI flag clear register values
@{*/
/* bits 31:5 reserved */
/* CTOF:*/ /** Clear timeout flag */
#define QUADSPI_FCR_CTOF    (1 << 4)
/* CSMF:*/ /** Clear status match flag */
#define QUADSPI_FCR_CSMF    (1 << 3)
/* bit 2 reserved */
/* CTCF:*/ /** Clear transfer complete flag */
#define QUADSPI_FCR_CTCF    (1 << 1)
/* CTEF:*/ /** Clear transfer error flag */
#define QUADSPI_FCR_CTEF    (1 << 0)
/**@}*/
#define QUADSPI_CCR_DDRM    (1 << 31)
#define QUADSPI_CCR_DHHC    (1 << 30)
/* bit 29 reserved on F4, FRCM on H7 */
#define QUADSPI_CCR_SIOO    (1 << 28)
#define QUADSPI_CCR_FMODE_MASK    0x3
#define QUADSPI_CCR_FMODE_SHIFT   26
#define QUADSPI_CCR_DMODE_MASK    0x3
#define QUADSPI_CCR_DMODE_SHIFT   24
/* bit 23 reserved */
#define QUADSPI_CCR_DCYC_MASK   0x1f
#define QUADSPI_CCR_DCYC_SHIFT    18

#define QUADSPI_CCR_ABSIZE_MASK   0x3
#define QUADSPI_CCR_ABSIZE_SHIFT  16

#define QUADSPI_CCR_ABMODE_MASK   0x3
#define QUADSPI_CCR_ABMODE_SHIFT  14

#define QUADSPI_CCR_ADSIZE_MASK   0x3
#define QUADSPI_CCR_ADSIZE_SHIFT  12

#define QUADSPI_CCR_ADMODE_MASK   0x3
#define QUADSPI_CCR_ADMODE_SHIFT  10

#define QUADSPI_CCR_IMODE_MASK    0x3
#define QUADSPI_CCR_IMODE_SHIFT   8

#define QUADSPI_CCR_INST_MASK   0xff
#define QUADSPI_CCR_INST_SHIFT    0

/* MODE values */
/**
@defgroup quadspi_ccr_mode QUADSPI_CCR_MODE values
@{*/
/** No data */
#define QUADSPI_CCR_MODE_NONE   0
/** Use one line for communication */
#define QUADSPI_CCR_MODE_1LINE    1
/** Use two lines for communication */
#define QUADSPI_CCR_MODE_2LINE    2
/** Use four lines for communication */
#define QUADSPI_CCR_MODE_4LINE    3
/**@}*/

/* SIZE values */
/**
@defgroup quadspi_ccr_size QUADSPI_CCR_SIZE values
@{*/
/** Size is 8Bit (1 Byte) */
#define QUADSPI_CCR_SIZE_8BIT   0
/** Size is 16Bit (2 Byte) */
#define QUADSPI_CCR_SIZE_16BIT  1
/** Size is 24Bit (3 Byte) */
#define QUADSPI_CCR_SIZE_24BIT  2
/** Size is 32Bit (4 Byte) */
#define QUADSPI_CCR_SIZE_32BIT  3
/**@}*/

/* FMODE values */
/**
@defgroup quadspi_ccr_fmode QUADSPI_CCR_FMODE values
@{*/
/** Indirection write mode */
#define QUADSPI_CCR_FMODE_IWRITE  0
/** Indirection read mode */
#define QUADSPI_CCR_FMODE_IREAD   1
/** Automatic polling mode */
#define QUADSPI_CCR_FMODE_APOLL   2
/** Memory-mapped mode */
#define QUADSPI_CCR_FMODE_MEMMAP  3
/**@}*/

/**
@defgroup quadspi_cr_fsel_dfm QUADSPI flash selection
@{*/
/** Use FLASH 1 */
#define QUADSPI_FLASH_SEL_1       2
/** Use FLASH 2 */
#define QUADSPI_FLASH_SEL_2       3
/** Use Dual-flash mode */
#define QUADSPI_FLASH_SEL_DUAL    1
/**@}*/

/**
@defgroup quadspi_ckmode QUADSPI_DCR_CKMODE values
@{*/
#define QUADSPI_DCR_CKMOD_MODE0    0
#define QUADSPI_DCR_CDMOD_MODE3    QUADSPI_DCR_CKMODE
/**@}*/

/**
@defgroup quadspi_ccr_ddrm QUADSPI_CCR_DDRM values
@{*/
/** Disable the double-data-rate mode */
#define QUADSPI_CCR_DDRM_DISABLE    0
/** Enable the double-data-rate mode */
#define QUADSPI_CCR_DDRM_ENABLE     1
/**@}*/

/**
@defgroup quadspi_ccr_dhhc QUADSPI_CCR_DHHC values
@{*/
/** Delay the data output using analog delay */
#define QUADSPI_CCR_DHHC_ANALOG     0
/** Delay the data output by 1/4 of a QUADSPI output clock cycle */
#define QUADSPI_CCR_DHHC_1_4_CLK    1
/**@}*/

/**
@defgroup quadspi_ccr_sioo QUADSPI_CCR_SIOO values
@{*/
/** Send instruction on every transaction */
#define QUADSPI_CCR_SIOO_EVERY      0
/** Send instruction only for the first command */
#define QUADSPI_CCR_SIOO_ONCE       1
/**@}*/
/**@}*/

/**
@defgroup quadspi_highlevel_types QuadSPI datatypes for high-level functions
@ingroup quadspi_highlevel_functions
@{*/
/**
@brief QuadSPI instruction data type.
@{*/
struct quadspi_instruction {
    /** Operation mode @see quadspi_ccr_mode */
    uint32_t mode;
    /** QuadSPI instruction to be send. */
    uint8_t instruction;
};
/**@}*/
/**
@brief QuadSPI address type

An address can be optional or one to four bytes long.
The address is send after the instruction
@{*/
struct quadspi_address {
    /** Operation mode @see quadspi_ccr_mode */
    uint32_t mode;
    /** Number of address bytes @see quadspi_ccr_size */
    uint32_t size;
    /** address to be send. */
    uint32_t address;
};
/**@}*/

/**
@brief QUADSPI alternate bytes type

The alternate bytes can be optional or one to four bytes long.
The alternate bytes are send after the address bytes
*/
struct quadspi_alternative_bytes {
    /** Operation mode @see quadspi_ccr_mode */
    uint32_t mode;
    /** Number of alternate bytes @see quadspi_ccr_size */
    uint32_t size;
    /** alternate byte(s) to be send. */
    uint32_t value;
};

/**
@brief  QUADSPI dummy cycles type

The dummy cycles can be 0..31 clocks.
The dummy cycles are send after the alternative bytes
*/
struct quadspi_dummy_cycles {
    /** Operation mode @see quadspi_ccr_mode */
    uint32_t mode;
    /** Number of dummy cycles (0..31) */
    uint8_t cycles;
};

/**
@brief QUADSPI command type

A command consists of
- a QuadSPI instruction
- an address. The address can be 0..4 bytes long and is optional.
- alternative bytes The alternative bytes can be 0..4 bytes long and are optional.
- dummy clocks The dummy clocks can be 0..31 clocks long and are optional.
- data A command does not necessarily have to send / receive data.
*/
struct quadspi_command {
    /** The configuration and instruction to be send. */
    struct quadspi_instruction instruction;
    /** The configuration and address to be send. */
    struct quadspi_address address;
    /** The configuration and alternative bytes to be send. */
    struct quadspi_alternative_bytes alternative_bytes;
    /** The configuration and number of dummy clocks to be send. */
    struct quadspi_dummy_cycles dummy_cycles;
};

/**@}*/

/**
 * @defgroup quadspi_file QuadSPI peripheral API
 * @brief APIs for the specialized SPI Flash peripheral
 * @ingroup peripheral_apis
 * @copyright SPDX: LGPL-3.0-or-later
 *
 * The QUADSPI is a specialized communication interface targeting single,
 * dual or quad SPI Flash memories
 * @{
 */

BEGIN_DECLS

/**
@defgroup quadspi_reg_functions QuadSPI functions for register manipulation.
@brief Low-level functions for register manipulation
@{*/
/**
 * Enable the quadspi peripheral.
 */
void quadspi_enable(void);

/**
Disable the quadspi peripheral.
*/
void quadspi_disable(void);

/**
@brief Test if the QUADSPI interface is busy

@return boolean: On set: Interface is busy.
*/
bool quadspi_is_busy(void);

/**
@brief Wait as long as the QUADSPI interface is busy

*/
void quadspi_wait_while_busy(void);

/**
Abort the communication.
*/
void quadspi_abort(void);

/**
@brief Set the prescaler for the QUADSPI clock.

The prescaler is derived from the AHB clock.
This function must only be called while the interface isn't busy.

As described in RM0385 the real prescaler ist the value+1.

@param[in] prescaler Unsigned int8. Clock prescaler (value+1)
*/
void quadspi_set_prescaler(uint8_t prescaler);

/**
@brief Flash memory selection

Select the FLASH 1, FLASH 2 or Dual-flash mode.

@param[in] Unsigned int32. @ref quadspi_cr_fsel_dfm
*/
void quadspi_select_flash(uint32_t flash);

/**
@brief Enable interrupts for QUADSPI

@param[in] irq Unsigned int32. @ref quadspi_irq_enable. Logical OR of all interrupt
enable bits to be set
*/
void quadspi_enable_irq(uint32_t irq);

/**
@brief Disable interrupts for QUADSPI

@param[in] irq Unsigned int32. @ref quadspi_irq_enable. Logical OR of all interrupt
enable bits to be cleared
*/
void quadspi_disable_irq(uint32_t irq);

/**
@brief Set the clockmode for QUADSPI
Valid modes are mode 0 and mode 3.

Mode 0: CLK must stay low while nCS is high.
Mode 3: CLK must stay hight while nCS is hight.

@param mode Unsigned int32. @ref quadspi_ckmode
*/
void quadspi_set_clock_mode(uint32_t mode);

/**
@brief Set the Chip select hight time.

Defines the minimum number of CLK cycles which the nCS must remain high between commands
ussued to the FLASH memory.

As in RM0385 described, the number of CLK cycles is cycles+1.

@param[in] cycles Unsigned int32. Number+1 cycles of nCS high between two FLASH memory commands.
*/
void quadspi_set_cs_high_time(uint32_t cycles);

/**
@brief Flash memory size

This defines the size of the external memory using the following formula:

Number of bytes in Flash memory = 2^(flash_size+1)

Flash_size+1 is effectivly the number of address bits required to address the FLASH memory.

If dual-flash-mode is enabled, the size indicates the total capacity
of both FLASH memories together.

@param[in] flash_size Unsigned int32. The FLASH memory size in 2^(flash_size+1)
 */
void quadspi_set_flash_size(uint32_t flash_size);


/**
@brief Read status flag.

@param[in] flag Unsigned int32. Status register flag. @ref quadspi_sr_values
@return boolean: flag set
*/
bool quadspi_get_flag(uint32_t flag);

/**
@brief Get the number of valid bytes in FIFO

Return the number of valid bytes which are beeing helod in the FIFO.

FLEVEL=[0..32]: FIFO level from empty to full.

@return uint8_t: Number of valid bytes held in FIFO.
*/
uint8_t quadspi_get_fifo_level(void);

/**
@brief Clear a status flag

@param[in] flag Unsigned int32. Flag to be cleared. @ref qspi_fcr_values
*/
void quadspi_clear_flag(uint32_t flag);


/**
@brief Set the number of bytes to be transfered.

Number of data to be retrieved (value+1) in indirection and status-polling mode.
A value no greater than 3 (inidcating 4 bytes) should be used for status-polling mode.

A value of 0xFFFFFFFF in indirect mode means undefined length, where QUADSPI will continue
until the end of memory, as defined by FSIZE.

@param[in] Unsigned int32. data_length Nuber of bytes+1 to be transfered.
*/
void quadspi_set_data_length(uint32_t data_length);

/**
@brief Set the double-data-rate mode

Set the DDR mode for the address, alternate byte and data phase.

@param[in] set Boolean. @ref quadspi_ccr_ddrm
*/
void quadspi_set_double_datarate_mode(bool set);

/**
@brief Set the double-data-rate-hold mode

Delay the data output by 1/4 of the QUADSPI output clock cycle in DDR mode.

This bit is only active in DDR mode enabled.

@param[in] set Boolean. @ref quadspi_ccr_dhhc
 */
void quadspi_set_ddr_hold(bool set);

/**
@brief Set the send instruction only once mode

Some Flash memories (e.g. Winbound) might provide a mode where an instruction must be
sent only with the first command sequence, while subsequent commands start directly with
the address. One can take advantage of such a feature using the SIOO bit

SIOO is valid for all functional modes (indirect, automatic polling, and memory-mapped). If
the SIOO bit is set, the instruction is sent only for the first command following a write to
QUADSPI_CCR. Subsequent command sequences skip the instruction phase, until there is
a write to QUADSPI_CCR.
SIOO has no effect when IMODE = 00 (no instruction).

@param[in] set Boolean. @ref quadspi_ccr_sioo
*/
void quadspi_set_instruction_only_once_mode(bool set);

/**
@brief Set the functional mode

Defines the QUADSPI functional mode of operation.

@param[in] mode Unsigned int32. Set the function mode to indirect read/write, automatic polling
or memory-mapped mode. @ref quadspi_rcc_fmode
*/
void quadspi_set_funcion_mode(uint32_t mode);


/**
@brief Set the data phase's mode

Set the QUADSPI data phase's mode of operation.

@param[in] mode Unsigned int32. Set the data phases's mode to No data, 1-line, 2-lines, 4-lines.
@ref quadspi_rcc_fmode
*/
void quadspi_set_data_mode(uint32_t mode);

/**
@brief Set the number of dummy cycles

Defines the duration of the dummy phase. In both SDR and DDR modes, it specifies
the number of CLK cycles (0..31).

@param[in] cycles Unsinged int32. Number of dummy CLK cycles (0..31).
*/
void quadspi_set_dummy_cycles(uint32_t cycles);

/**
@brief Set the alternative-bytes size

This defines the alternative bytes size

@param[in] size Unsigned int32. Number of alternative bytes to be sent. @ref quadspi_ccr_size
 */
void quadspi_set_alternative_bytes_size(uint32_t size);


/**
@brief set the alternative-bytes mode

This defines the alternative-bytes phase mode of operation.

@param[in] mode Unsigned int32. Set the alternative bytes phases mode to
No data, 1-line, 2-lines, 4-lines.
@ref quadspi_rcc_fmode
*/
void quadspi_set_alternative_bytes_mode(uint32_t mode);

/**
@brief Set the address size

This defines the address size

@param[in] size Unsigned int32. Number of address bytes to be sent. @ref quadspi_ccr_size
 */
void quadspi_set_address_size(uint32_t size);

/**
@brief set the address mode

This defines the address phase mode of operation.

@param[in] mode Unsigned int32. Set the address phases mode to No data, 1-line, 2-lines, 4-lines.
@ref quadspi_rcc_fmode
*/
void quadspi_set_address_mode(uint32_t mode);

/**
@brief set the instruction mode

This defines the instruction phase mode of operation.

@param[in] mode Unsigned int32. Set the instruction phases mode to
No data, 1-line, 2-lines, 4-lines.
@ref quadspi_rcc_fmode
*/
void quadspi_set_instruction_mode(uint32_t mode);

/**
@brief Send instruction

Instruction to be send to the external SPI device.

@param[in] instruction Unsigned int8. Instruction to be send.
*/
void quadspi_send_instruction(uint8_t instruction);

/**
@brief Set the address to be send to the external FLASH memory

@param[in] address Unsigned int32. Address to be send to the FLASH memory
*/
void quadspi_set_address(uint32_t address);

/**
@brief Set the alternative-bytes to be send.

@param[in] data Unsigned int32. Alternative-bytes value
*/
void quadspi_set_alternative_bytes(uint32_t data);

/**
@brief Write one data-byte to the data register

@param[in] data Unsigned int8. One byte to be written
*/
void quadspi_write_byte(uint8_t data);

/**
@brief Write two data-bytes to the data register

@param[in] data Unsigned int16. Two bytes to be written
*/
void quadspi_write_halfword(uint16_t data);

/**
@brief Write four data-bytes to the data register

@param[in] data Unsigned int16. Four bytes to be written
*/
void quadspi_write_word(uint32_t data);

/**
@brief Read one byte from the data register

@return uint8_t One byte of data
*/
uint8_t quadspi_read_byte(void);

/**
@brief Read two bytes from the data register

@return uint16_t Two bytes of data
*/
uint16_t quadspi_read_halfword(void);

/**
@brief Read four byte from the data register

@return uint32_t four bytes of data
*/
uint32_t quadspi_read_word(void);
/**@}*/


/**
@defgroup quadspi_highlevel_functions QuadSPI high level functions.
@brief High-level functions for QuadSPI
@{*/

/**
@brief Set the QuadSPI bus frequency.

As the QuadSPI frequency is derrived from the AHB frequency, not all frequencies can be set.
So this function returns the real frequency of the QuadSPI interface

@param[in] ahb_frequency Unsigned int32. Input clock frequency into the QuadSPI interface in Hz.
@param[in] bus_freq Unsigned int32. Desired QuadSPI clock frequenty in Hz.
@return Unsigned uint32: Read QuadSPI frequency.
*/
uint32_t quadspi_set_bus_frequency(uint32_t ahb_frequency, uint32_t bus_frequency);

/**
@brief Write data to the QuadSPI interface

@param[in] command struct quadspi_command*. Pointer to the command struct.
@param[in] buffer void*. Pointer to buffer to be send.
@param[in] buffer_size Unsigned int32. Size of buffer / Number of bytes to send.
@return uint32_t: -1: No datat could be send. !=-1: Number of bytes sent.
*/
uint32_t quadspi_write(struct quadspi_command *command, const void *buffer, uint32_t buffer_size);

/**
@brief Read data from the QuadSPI interface

@param[in] command struct quadspi_command*. Pointer to the command struct.
@param[out] buffer void*. Pointer to buffer store data.
@param[in] buffer_size Unsigned int32. Size of buffer / Number of bytes to read.
@return uint32_t: -1: No datat could be read. !=-1: Number of bytes read.
*/
uint32_t quadspi_read(struct quadspi_command *command, void *buffer, uint32_t buffer_size);

/**@}*/
END_DECLS

/**@}*/

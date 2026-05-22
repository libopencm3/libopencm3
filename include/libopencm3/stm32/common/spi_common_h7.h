/** @addtogroup spi_defines
 *
 */

/*
 * This file is part of the libopencm3 project.
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA I2C.H
The order of header inclusion is important. i2c.h includes the device
specific memorymap.h header before including this header file.*/

/**@{*/
#ifdef LIBOPENCM3_SPI_H

/** @defgroup spi_reg_base SPI Register base address
@ingroup spi_defines

@{*/
#define SPI1				SPI1_BASE
#define SPI2				SPI2_BASE
#define SPI3				SPI3_BASE
#define SPI4				SPI4_BASE
#define SPI5				SPI5_BASE
#define SPI6				SPI6_BASE
/**@}*/

/*H7 Specific SPI Registers, if it applies to any other family, feel free to copy*/
/*Control Register 1*/
#define SPI_CR1(spi_base)   MMIO32((spi_base) + 0x00)
#define SPI1_CR1            SPI_CR1(SPI1)
#define SPI2_CR1            SPI_CR1(SPI2)
#define SPI3_CR1            SPI_CR1(SPI3)
#define SPI4_CR1            SPI_CR1(SPI4)
#define SPI5_CR1            SPI_CR1(SPI5)
#define SPI6_CR1            SPI_CR1(SPI6)

/*SPI Control Register 2*/
#define SPI_CR2(spi_base)   MMIO32((spi_base) + 0x04)
#define SPI1_CR1            SPI_CR2(SPI1)
#define SPI2_CR1            SPI_CR2(SPI2)
#define SPI3_CR1            SPI_CR2(SPI3)
#define SPI4_CR1            SPI_CR2(SPI4)
#define SPI5_CR1            SPI_CR2(SPI5)
#define SPI6_CR1            SPI_CR2(SPI6)

/*SPI Config Register 1*/
#define SPI_CFG1(spi_base)  MMIO32((spi_base) + 0x08)
#define SPI1_CFG1            SPI_CFG1(SPI1)
#define SPI2_CFG1            SPI_CFG1(SPI2)
#define SPI3_CFG1            SPI_CFG1(SPI3)
#define SPI4_CFG1            SPI_CFG1(SPI4)
#define SPI5_CFG1            SPI_CFG1(SPI5)
#define SPI6_CFG1            SPI_CFG1(SPI6)

/*SPI Config Register 2*/
#define SPI_CFG2(spi_base)  MMIO32((spi_base) + 0x0C)
#define SPI1_CFG2            SPI_CFG2(SPI1)
#define SPI2_CFG2            SPI_CFG2(SPI2)
#define SPI3_CFG2            SPI_CFG2(SPI3)
#define SPI4_CFG2            SPI_CFG2(SPI4)
#define SPI5_CFG2            SPI_CFG2(SPI5)
#define SPI6_CFG2            SPI_CFG2(SPI6)

/*SPI Interrupt Enable Register*/
#define SPI_IER(spi_base)   MMIO32((spi_base) + 0x10)
#define SPI1_IER             SPI_IER(SPI1)
#define SPI2_IER             SPI_IER(SPI2)
#define SPI3_IER             SPI_IER(SPI3)
#define SPI4_IER             SPI_IER(SPI4)
#define SPI5_IER             SPI_IER(SPI5)
#define SPI6_IER             SPI_IER(SPI6)

/*SPI Status Register*/
#define SPI_SR(spi_base)    MMIO32((spi_base) + 0x14)
#define SPI1_SR              SPI_SR(SPI1)
#define SPI2_SR              SPI_SR(SPI2)
#define SPI3_SR              SPI_SR(SPI3)
#define SPI4_SR              SPI_SR(SPI4)
#define SPI5_SR              SPI_SR(SPI5)
#define SPI6_SR              SPI_SR(SPI6)

/*SPI Interrupt/Status Flag Clear Register*/
#define SPI_ICFR(spi_base)  MMIO32((spi_base) + 0x18)
#define SPI1_ICFR            SPI_ICFR(SPI1)
#define SPI2_ICFR            SPI_ICFR(SPI2)
#define SPI3_ICFR            SPI_ICFR(SPI3)
#define SPI4_ICFR            SPI_ICFR(SPI4)
#define SPI5_ICFR            SPI_ICFR(SPI5)
#define SPI5_ICFR            SPI_ICFR(SPI6)

/*SPI Transmit Data Register*/
#define SPI_TXDR(spi_base)  MMIO32((spi_base) + 0x20)
#define SPI1_TXDR            SPI_TXDR(SPI1)    
#define SPI2_TXDR            SPI_TXDR(SPI2)
#define SPI3_TXDR            SPI_TXDR(SPI3)
#define SPI4_TXDR            SPI_TXDR(SPI4)
#define SPI5_TXDR            SPI_TXDR(SPI5)
#define SPI6_TXDR            SPI_TXDR(SPI6)

/*SPI Receive Data Register*/
#define SPI_RXDR(spi_base)  MMIO32((spi_base) + 0x30)
#define SPI1_RXDR            SPI_RXDR(SPI1)
#define SPI2_RXDR            SPI_RXDR(SPI2)
#define SPI3_RXDR            SPI_RXDR(SPI3)
#define SPI4_RXDR            SPI_RXDR(SPI4)
#define SPI5_RXDR            SPI_RXDR(SPI5)
#define SPI6_RXDR            SPI_RXDR(SPI6)

/*SPI Polynomial Register*/
#define SPI_CRCPOLY(spi_base)  MMIO32((spi_base) + 0x40)
#define SPI1_CRCPOLY         SPI_CRCPOLY(SPI1)
#define SPI2_CRCPOLY         SPI_CRCPOLY(SPI2)
#define SPI3_CRCPOLY         SPI_CRCPOLY(SPI3)
#define SPI4_CRCPOLY         SPI_CRCPOLY(SPI4)
#define SPI5_CRCPOLY         SPI_CRCPOLY(SPI5)
#define SPI6_CRCPOLY         SPI_CRCPOLY(SPI6)

/*SPI Transmitter CRC Register*/
#define SPI_TXCRC(spi_base)  MMIO32((spi_base) + 0x44)
#define SPI1_TXCRC            SPI_TXCRC(SPI1)
#define SPI2_TXCRC            SPI_TXCRC(SPI2)
#define SPI3_TXCRC            SPI_TXCRC(SPI3)
#define SPI4_TXCRC            SPI_TXCRC(SPI4)
#define SPI5_TXCRC            SPI_TXCRC(SPI5)
#define SPI6_TXCRC            SPI_TXCRC(SPI6)

/*SPI Receiver CRC Register*/
#define SPI_RXCRC(spi_base)  MMIO32((spi_base) + 0x48)
#define SPI1_RXCRC               SPI_TXCRC(SPI1)
#define SPI2_RXCRC               SPI_TXCRC(SPI2)
#define SPI3_RXCRC               SPI_TXCRC(SPI3)
#define SPI4_RXCRC               SPI_TXCRC(SPI4)
#define SPI5_RXCRC               SPI_TXCRC(SPI5)
#define SPI6_RXCRC               SPI_TXCRC(SPI6)

/*SPI Underrun Data Register*/
#define SPI_UDRDR(spi_base)  MMIO32((spi_base) + 0x4C)
#define SPI1_UDRDR               SPI_UDRDR(SPI1)
#define SPI2_UDRDR               SPI_UDRDR(SPI2)
#define SPI3_UDRDR               SPI_UDRDR(SPI3)
#define SPI4_UDRDR               SPI_UDRDR(SPI4)
#define SPI5_UDRDR               SPI_UDRDR(SPI5)
#define SPI6_UDRDR               SPI_UDRDR(SPI6)

/*SPI Bit defs, masks and shifts*/
/*SPI_CR1*/

/*SPI Periph Enable*/
#define SPI_CR1_SPE_SHIFT        0x0 
#define SPI_CR1_SPE              (1U << SPI_CR1_SPE_SHIFT)
#define SPI_CR1_MASK             (0x1 << SPI_CR1_SPE_SHIFT)

//master automatic SUSP in receive mode
#define SPI_CR1_MAXRX_SHIFT      0x8
#define SPI_CR1_MAXRX            (1U << SPI_CR1_MAXRX_SHIFT)    
#define SPI_CR1_MAXRX_MASK       (0x1 << SPI_CR1_MAXRX_SHIFT)

//Master transfer start, 0=master transfer idle, 1= master transfer ongoing
#define SPI_CR1_CSTART_SHIFT     0x9
#define SPI_CR1_CSTART           (1U << SPI_CR1_CSTART_SHIFT)     
#define SPI_CR1_CSTART_MASK      (0x1 << SPI_CR1_CSTART_SHIFT)

//Master suspend request
#define SPI_CR1_CSUSP_SHIFT      0xA
#define SPI_CR1_CSUSP            (1U << SPI_CR1_CSUSP_SHIFT)    
#define SPI_CR1_CSUSP_MASK       (0x1 << SPI_CR1_CSUSP_SHIFT)

//RX/TX direction at half-duplex mode, 1 for transmitter, 0 for receiver
#define SPI_CR1_HDDIR_SHIFT      0xB
#define SPI_CR1_HDDIR            (1U << SPI_CR1_HDDIR_SHIFT)   
#define SPI_CR1_HDDIR_MASK       (0x1 << SPI_CR1_HDDIR_SHIFT)

//Internal SS Singal input level
#define SPI_CR1_SSI_SHIFT        0xC
#define SPI_CR1_SSI              (1U << SPI_CR1_SSI_SHIFT) 
#define SPI_CR1_SSI_MASK         (0x1 << SPI_CR1_SSI_SHIFT)

//32-bit CRC Polynomial configuration, if 1, full size polynomial CRC is used
#define SPI_CR1_CRC33_17_SHIFT   0xD
#define SPI_CR1_CRC33_17         (1U << SPI_CR1_CRC33_17_SHIFT) 
#define SPI_CR1_CRC33_17_MASK    (0x1 << SPI_CR1_CRC33_17_SHIFT)

//CRC calculation itialization pattern control for receiver, if 1, all ones pattern is applied, if 0, all zeroes
#define SPI_CR1_RCRCINI_SHIFT    0xE
#define SPI_CR1_RCRCINI          (1U << SPI_CR1_RCRCINI_SHIFT) 
#define SPI_CR1_RCRCINI_MASK     (0x1 << SPI_CR1_RCRCINI_SHIFT)

//CRC calculation itialization pattern control for transmitter, if 1, all ones pattern is applied, if 0, all zeroes
#define SPI_CR1_TCRCINI_SHIFT    0xF
#define SPI_CR1_TCRCINI          (1U << SPI_CR1_TCRCINI_SHIFT) 
#define SPI_CR1_TCRCINI_MASK     (0x1 << SPI_CR1_TCRCINI_SHIFT)

//When set, the SPI_CFG2 register cannot be modified
#define SPI_CR1_IOLOCK_SHIFT     0x10
#define SPI_CR1_IOLOCK           (1U << SPI_CR1_IOLOCK_SHIFT) 
#define SPI_CR1_IOLOCK_MASK      (0x1 << SPI_CR1_IOLOCK_SHIFT)

/*----------------------------------------------------------*/

/*SPI_CR2*/

//Number of data transfer extension to be reload into TSIZE just when a previus number of data stored at TSIZE is transacted
#define SPI_CR2_TSER_SHIFT       0x10
#define SPI_CR2_TSER             (1U << SPI_CR2_TSER_SHIFT) 
#define SPI_CR2_TSER_MASK        (0xFFFF << SPI_CR2_TSER_SHIFT)

//Number of data at current transfer
#define SPI_CR2_TSIZE_SHIFT      0x0
#define SPI_CR2_TSIZE            (1U << SPI_CR2_TSIZE_SHIFT)
#define SPI_CR2_TSIZE_MASK       (0xFFFF << SPI_CR2_TSIZE_SHIFT)

/*SPI_CFG1*/

//Master baud rate prescaler, 000=mck/2, 001=/4, 010=/8, 011=/16.... 111=/256
#define SPI_CFG1_MBR_SHIFT       0x1C
#define SPI_CFG1_MBR             (1U << SPI_CFG1_MBR_SHIFT)
#define SPI_CFG1_MBR_MASK        (0x7 << SPI_CFG1_MBR_SHIFT)

/*MBR Prescaler settings*/
#define SPI_CFG1_MBR_DIV2        (0x0 << SPI_CFG1_MBR_SHIFT)//spimck/2
#define SPI_CFG1_MBR_DIV4        (0x1 << SPI_CFG1_MBR_SHIFT) //spimck/4
#define SPI_CFG1_MBR_DIV8        (0x2 << SPI_CFG1_MBR_SHIFT) //spimck/8
#define SPI_CFG1_MBR_DIV16       (0x3 << SPI_CFG1_MBR_SHIFT) //spimck/16
#define SPI_CFG1_MBR_DIV32       (0x4 << SPI_CFG1_MBR_SHIFT) //spimck/32
#define SPI_CFG1_MBR_DIV64       (0x5 << SPI_CFG1_MBR_SHIFT) //spimck/64
#define SPI_CFG1_MBR_DIV128      (0x6 << SPI_CFG1_MBR_SHIFT) //spimck/128
#define SPI_CFG1_MBR_DIV256      (0x0 << SPI_CFG1_MBR_SHIFT) //spimck/256

//Hardware CRC Computation Enable
#define SPI_CFG1_CRCEN_SHIFT     0x16
#define SPI_CFG1_CRCEN           (1U << SPI_CFG1_CRCEN_SHIFT)
#define SPI_CFG1_CRCEN_MASK      (0x1 << SPI_CFG1_CRCEN_SHIFT)

//Length of CRC frame to be transacted and compared
#define SPI_CFG1_CRCSIZE_SHIFT   0x16
#define SPI_CFG1_CRCSIZE         (1U << SPI_CFG1_CRCSIZE_SHIFT) //this field must be written starting from 0x3 up to 0x1F
#define SPI_CFG1_CRCSIZE_MASK    (0x1F << SPI_CFG1_CRCSIZE_SHIFT)

//Tx DMA Stream enable
#define SPI_CFG1_TXDMAEN_SHIFT   0xF
#define SPI_CFG1_TXDMAEN         (1U << SPI_CFG1_TXDMAEN_SHIFT)
#define SPI_CFG1_TXDMAEN_MASK    (0x1 << SPI_CFG1_TXDMAEN_SHIFT)

//Rx DMA Stream enable
#define SPI_CFG1_RXDMAEN_SHIFT   0xE
#define SPI_CFG1_RXDMAEN         (1U << SPI_CFG1_TXDMAEN_SHIFT)
#define SPI_CFG1_RXDMAEN_MASK    (0x1 << SPI_CFG1_TXDMAEN_SHIFT)

//Detection of udenrrun condition at slave transmitter, see RM0433 p. 2221.
#define SPI_CFG1_UDRDET_SHIFT    0xB
#define SPI_CFG1_UDRDET          (1U << SPI_CFG1_UDRDET_SHIFT)
#define SPI_CFG1_UDRDET_MASK     (0x3 << SPI_CFG1_UDRDET_SHIFT)


//Behavior of slave transmitter at underrun condition, see RM0433 p. 2221
#define SPI_CFG1_UDRCFG_SHIFT    0x9
#define SPI_CFG1_UDRCFG          (1U << SPI_CFG1_UDRCFG_SHIFT)
#define SPI_CFG1_UDRCFG_MASK     (0x3 << SPI_CFG1_UDRCFG_SHIFT)

/*FIFO Threshold, Defines number of data frames at single data packet. The size of the packet must not exceed
1/2 of FIFO space.*/
#define SPI_CFG1_FTHLV_SHIFT     0x5
#define SPI_CFG1_FTHLV           (1U << SPI_CFG1_FTHLV_SHIFT) //write this bit linearly from 0001=0 to 1111=16.
#define SPI_CFG1_FTHLV_MASK      (0xF << SPI_CFG1_FTHLV_SHIFT)

//Number of bits in a single SPI Data Frame
#define SPI_CFG1_DSIZE_SHIFT     0x0
#define SPI_CFG1_DSIZE           (1U << SPI_CFG1_DSIZE_SHIFT)//this field must be written starting from 0x3 up to 0x1F.
#define SPI_CFG1_DSIZE_MASK      (0x1F << SPI_CFG1_DSIZE_SHIFT)

/*-----------------------------------------------------------*/

/*SPI_CFG2*/

//Alternate function GPIOs control, if set, it forces state on the associated GPIOs when SPE=0, not to be used as slave
#define SPI_CFG2_AFCNTR_SHIFT    0x1F    
#define SPI_CFG2_AFCNTR          (1U << SPI_CFG2_AFCNTR_SHIFT)
#define SPI_CFG2_AFCTNR_MASK     (0x1 << SPI_CFG2_AFCNTR_SHIFT)           
  
/*SS output management in master mode, if 1, SPI DFs are interleaved with SS non active pulses when MIDI>1
if 0, SS is kept at active level till data transfer is completed, it becomes inactive with EOT flag*/
#define SPI_CFG2_SSOM_SHIFT      0x1E
#define SPI_CFG2_SSOM            (1U << SPI_CFG2_SSOM_SHIFT)            
#define SPI_CFG2_SSOM_MASK       (0x1 << SPI_CFG2_SSOM_SHIFT)
/*SSOM Bitmasks*/
#define SPI_SSOM_SS_ACTIVE       (0x0U << SPI_CFG2_SSOM_SHIFT)
#define SPI_SSOM_SS_PULSE        (0x1U << SPI_CFG2_SSOM_SHIFT)

/*SS output enable, if 1, SS output is enabled and the SPI cannot work in multimaster environment.
if 0, the SS output is disabled and the SPI can work in multimaster mode.*/
#define SPI_CFG2_SSOE_SHIFT      0x1D
#define SPI_CFG2_SSOE            (1U << SPI_CFG2_SSOE_SHIFT)
#define SPI_CFG2_SSOE_MASK       (0x1 << SPI_CFG2_SSOE_SHIFT)
/*SS Output Bitmasks*/
#define SPI_SSOE_EN              (0x1U << SPI_CFG2_SSOE_SHIFT)


//SS input/output polarity, if if 1, active high.
#define SPI_CFG2_SSIOP_SHIFT     0x1C
#define SPI_CFG2_SSIOP           (1U << SPI_CFG2_SSIOP_SHIFT)
#define SPI_CFG2_SSIOP_MASK      (0x1 << SPI_CFG2_SSIOP_SHIFT)
/*SSIOP Bitmasks*/
#define SSIOP_HIGH               (0x1U << SPI_CFG2_SSIOP_SHIFT)
#define SSIOP_LOW                (0x0U << SPI_CFG2_SSIOP_SHIFT)

/*SW mgt of SS signal input, if 1, SS input value is determined by the SSI bit, if 0, is determined by the SS PAD,
When hardware SS output(SSM=0 | SSOE=1), the SS signal input is forced to non active state internally to prevent master mode fault error. */
#define SPI_CFG2_SSM_SHIFT       0x1A
#define SPI_CFG2_SSM             (1U << SPI_CFG2_SSM_SHIFT)
#define SPI_CFG2_SSM_MASK        (0x1 << SPI_CFG2_SSM_SHIFT)
/*Slave Select modes bitmasks*/
#define SPI_SSM_HW               (0x0U << SPI_CFG2_SSM_SHIFT)
#define SPI_SSM_SW               (0x1U << SPI_CFG2_SSM_SHIFT)

//Clock polarity, if 1, SCK signal is at 1 when idle, if 0 is at 0.
#define SPI_CFG2_CPOL_SHIFT      0x19
#define SPI_CFG2_CPOL            (1U << SPI_CFG2_CPOL_SHIFT)
#define SPI_CFG2_CPOL_MASK       (0x1 << SPI_CFG2_CPOL_SHIFT)
/*CPOL bitmasks*/
#define SPI_CPOL_HIGH            (0x1 << SPI_CFG2_CPOL_SHIFT)
#define SPI_CPOL_LOW             (0x0 << SPI_CFG2_CPOL_SHIFT)

//Clock phase, if 1, the first data capture edge is at the second clock transition, if 0, it's at the first ck transition.
#define SPI_CFG2_CPHA_SHIFT      0x18
#define SPI_CFG2_CPHA            (1U << SPI_CFG2_CPHA_SHIFT)
#define SPI_CFG2_CPHA_MASK       (0x1 << SPI_CFG2_CPHA_SHIFT)
/*CPHA bitmasks*/
#define SPI_CPHA_FRST            (0x0U << SPI_CFG2_CPHA_SHIFT)
#define SPI_CPHA_SCND            (0x1U << SPI_CFG2_CPHA_SHIFT)

//Data frame format, 1 for LSB 1st, if 0 MSB 1st.
#define SPI_CFG2_LSBFRST_SHIFT   0x17
#define SPI_CFG2_LSBFRST         (1U << SPI_CFG2_LSBFRST_SHIFT)
#define SPI_CFG2_LSBFRST_MASK    (0x1 << SPI_CFG2_LSBFRST_SHIFT)
/*LSBFRST Bitmasks*/
#define SPI_MSBSET               (0x0U << SPI_CFG2_LSBFRST_SHIFT)
#define SPI_LSBSET               (0x1U << SPI_CFG2_LSBFRST_SHIFT)

//SPI Master, 1 for Master, 0 for Slave.
#define SPI_CFG2_MASTER_SHIFT    0x16
#define SPI_CFG2_MASTER          (1U << SPI_CFG2_MASTER_SHIFT)
#define SPI_CFG2_MASTER_MASK     (0x1 << SPI_CFG2_MASTER_SHIFT)
/*SPI Master selection*/
#define SPI_SLAVE_SEL            (0x0 << SPI_CFG2_MASTER_SHIFT) //Slave mode selected
#define SPI_MASTER_SEL           (0x1 << SPI_CFG2_MASTER_SHIFT) //Master mode selected


//Serial Protocol mode, only use bit 0, 0 for Motorola, 1 for TI.
#define SPI_CFG2_SP_SHIFT        0x13
#define SPI_CFG2_SP              (1U << SPI_CFG2_SP_SHIFT)
#define SPI_CFG2_SP_MASK         (0x7 << SPI_CFG2_SP_SHIFT)
/*Protocol bit masks*/
#define SPI_PROT_MOTOROLA        (0x0 << SPI_CFG2_SP_SHIFT) //SPI Motorola procotol select
#define SPI_PROT_TEXAS           (0x1 << SPI_CFG2_SP_SHIFT) //Texas Instruments protocol select

//Communication mode, 00: full duplex, 11: half duplex, 10: simplex receiver, 01: simplex transmitter
#define SPI_CFG2_COMM_SHIFT      0x11
#define SPI_CFG2_COMM            (1U << SPI_CFG2_COMM_SHIFT)
#define SPI_CFG2_COMM_MASK       (0x3 << SPI_CFG2_COMM_SHIFT)
/*Comms mode bit masks*/
#define SPI_COMM_FULLDUPLEX      (0x0U << SPI_CFG2_COMM_SHIFT) //sets comms mode as full-duplex
#define SPI_COMM_SIMPLEXRX       (0x1U << SPI_CFG2_COMM_SHIFT) //sets comms mode as simplex transmitter
#define SPI_COMM_SIMPLEXTX       (0x2U << SPI_CFG2_COMM_SHIFT) //sets comms mode as simplex receiver
#define SPI_COMM_HALFDUPLEX      (0x3U << SPI_CFG2_COMM_SHIFT) //sets comms mode as half-duplex

//IO function swap, if 1, inverts functionality for the MOSI and MISO pins.
#define SPI_CFG2_IOSWP_SHIFT     0xF
#define SPI_CFG2_IOSWP           (1U << SPI_CFG2_IOSWP_SHIFT)
#define SPI_CFG2_IOSWP_MASK      (0x1 << SPI_CFG2_IOSWP_SHIFT)

/*Master Inter-Data Idleness, minimum time delay in SPI clock cycles inserted between two consecutive data frames.
0000 for none, 0001 for 1, ..., 0100 for 4 cycles, linear, MOTOROLA ONLY*/
#define SPI_CFG2_MIDI_SHIFT      0x4
#define SPI_CFG2_MIDI            (1U << SPI_CFG2_MIDI_SHIFT)
#define SPI_CFG2_MIDI_MASK       (0xF << SPI_CFG2_MIDI_SHIFT)

enum spi_midi_values {
    MIDI_0  = 0U  << SPI_CFG2_MIDI_SHIFT,
    MIDI_1  = 1U  << SPI_CFG2_MIDI_SHIFT,
    MIDI_2  = 2U  << SPI_CFG2_MIDI_SHIFT,
    MIDI_3  = 3U  << SPI_CFG2_MIDI_SHIFT,
    MIDI_4  = 4U  << SPI_CFG2_MIDI_SHIFT,
    MIDI_5  = 5U  << SPI_CFG2_MIDI_SHIFT,
    MIDI_6  = 6U  << SPI_CFG2_MIDI_SHIFT,
    MIDI_7  = 7U  << SPI_CFG2_MIDI_SHIFT,
    MIDI_8  = 8U  << SPI_CFG2_MIDI_SHIFT,
    MIDI_9  = 9U  << SPI_CFG2_MIDI_SHIFT,
    MIDI_10 = 10U << SPI_CFG2_MIDI_SHIFT,
    MIDI_11 = 11U << SPI_CFG2_MIDI_SHIFT,
    MIDI_12 = 12U << SPI_CFG2_MIDI_SHIFT,
    MIDI_13 = 13U << SPI_CFG2_MIDI_SHIFT,
    MIDI_14 = 14U << SPI_CFG2_MIDI_SHIFT,
    MIDI_15 = 15U << SPI_CFG2_MIDI_SHIFT
};

/*Master SS Idleness, specifies an extra delay in SPI ck cycles between active adge of SS and first data of session start in MM when SSOE=1.
0000 for none, 0001 for 1, ..., 0100 for 4 cycles, linear, MOTOROLA ONLY*/
#define SPI_CFG2_MSSI_SHIFT      0x0
#define SPI_CFG2_MSSI            (1U << SPI_CFG2_MSSI_SHIFT)
#define SPI_CFG2_MSSI_MASK       (0xF << SPI_CFG2_MSSI_SHIFT)

enum spi_mssi_values {
    MSSI_0,
    MSSI_1,
    MSSI_2,
    MSSI_3,
    MSSI_4,
    MSSI_5,
    MSSI_6,
    MSSI_7,
    MSSI_8,
    MSSI_9,
    MSSI_10,
    MSSI_11,
    MSSI_12,
    MSSI_13,
    MSSI_14,
    MSSI_15
};

/*-----------------------------------------------------------*/

/*SPI_IER*/

//TSERF int. enable
#define SPI_IER_TSERFIE_SHIFT    0xA
#define SPI_IER_TSERFIE          (1U << SPI_IER_TSERFIE_SHIFT)
#define SPI_IER_TSERFIE_MASK     (0x1 << SPI_IER_TSERFIE_SHIFT)
 
//MODF int. enable
#define SPI_IER_MODFIE_SHIFT     0x9
#define SPI_IER_MODFIE           (1U << SPI_IER_MODFIE_SHIFT)
#define SPI_IER_MODFIE_MASK      (0x1 << SPI_IER_MODFIE_SHIFT)
 
//TIFRE int. enable
#define SPI_IER_TIFRIE_SHIFT     0x8
#define SPI_IER_TIFRIE           (1U << SPI_IER_TIFRIE_SHIFT)
#define SPI_IER_TIFRIE_MASK      (0x1 << SPI_IER_TIFRIE_SHIFT)
 
//CRC int. enable
#define SPI_IER_CRCIE_SHIFT      0x7
#define SPI_IER_CRCIE            (1U << SPI_IER_CRCIE_SHIFT)
#define SPI_IER_CRCIE_MASK       (0x1 << SPI_IER_CRCIE_SHIFT)
 
//OVR int. enable
#define SPI_IER_OVRIE_SHIFT      0x6
#define SPI_IER_OVRIE            (1U << SPI_IER_OVRIE_SHIFT)
#define SPI_IER_OVRIE_MASK       (0x1 << SPI_IER_OVRIE_SHIFT)
 
//UDR int. enable
#define SPI_IER_UDRIE_SHIFT      0x5
#define SPI_IER_UDRIE            (1U << SPI_IER_UDRIE_SHIFT)
#define SPI_IER_UDRIE_MASK       (0x1 << SPI_IER_UDRIE_SHIFT)
 
//TXTF int. enable
#define SPI_IER_TXTFIE_SHIFT     0x4
#define SPI_IER_TXTFIE           (1U << SPI_IER_TXTFIE_SHIFT)
#define SPI_IER_TXTFIE_MASK      (0x1 << SPI_IER_TXTFIE_SHIFT)
 
//EOT, SUSP and TXC int. enable
#define SPI_IER_EOTIE_SHIFT      0x3
#define SPI_IER_EOTIE            (1U << SPI_IER_EOTIE_SHIFT)
#define SPI_IER_EOTIE_MASK       (0x1 << SPI_IER_EOTIE_SHIFT)
 
//DXP int. enable
#define SPI_IER_DXPIE_SHIFT      0x2
#define SPI_IER_DXPIE            (1U << SPI_IER_DXPIE_SHIFT)
#define SPI_IER_DXPIE_MASK       (0x1 << SPI_IER_DXPIE_SHIFT)
 
//TXP int. enable
#define SPI_IER_TXPIE_SHIFT      0x1
#define SPI_IER_TXPIE            (1U << SPI_IER_TXPIE_SHIFT)
#define SPI_IER_TXPIE_MASK       (0x1 << SPI_IER_TXPIE_SHIFT)
 
//RXP int. enable
#define SPI_IER_RXPIE_SHIFT      0x0
#define SPI_IER_RXPIE            (1U << SPI_IER_RXPIE_SHIFT)
#define SPI_IER_RXPIE_MASK       (0x1 << SPI_IER_RXPIE_SHIFT)
 
/*-----------------------------------------------------------*/

/*SPI_SR*/
//READ ONLY REGISTERS
//Please refer to SPI_IFCR for interrupt clear registers

//Number of data frames remaining in current TSIZE session.
#define SPI_SR_CTSIZE_SHIFT      0x0U
#define SPI_SR_CTSIZE_MASK       (0xFFFFU << SPI_SR_CTSIZE_SHIFT)
#define SPI_SR_CTSIZEGET(spi_sr) ((spi_sr & SPI_SR_CTSIZE_MASK) >> SPI_SR_CTSIZE_SHIFT)

//RX FIFO word not empty
#define SPI_SR_RXWNE_SHIFT       0x15U
#define SPI_SR_RXWNE_MASK        (0x1U << SPI_SR_RXWNE_SHIFT)
#define SPI_SR_RXWNEGET(spi_sr)  ((spi_sr & SPI_SR_RXWNE_MASK) >> SPI_SR_RXWNE_SHIFT)

//RX FIFO packing level, refer to RM0433 p.2226.
#define SPI_SR_RXPLVL_SHIFT      0x13U
#define SPI_SR_RXPLVL_MASK       (0x3U << SPI_SR_RXPLVL_SHIFT)
#define SPI_SR_RXPLVLGET(spi_sr) ((spi_sr & SPI_SR_RXPLVL_MASK) >> SPI_SR_RXPLVL_SHIFT)

//TX FIFO transmission complete. 0=Still ongoing, 1=Last TX Completed
#define SPI_SR_TXC_SHIFT         0x12U
#define SPI_SR_TXC_MASK          (0x1U << SPI_SR_TXC_SHIFT)
#define SPI_SR_TXCGET(spi_sr)    ((spi_sr & SPI_SR_TXC_MASK) >> SPI_SR_TXC_SHIFT)

//Suspension status, 0=SPI not suspended(master mode active or other mode), 1=master mode suspended(current frame completed)
#define SPI_SR_SUSP_SHIFT        0x11U
#define SPI_SR_SUSP_MASK         (0x1U << SPI_SR_SUSP_SHIFT)
#define SPI_SR_SUSPGET(spi_sr)   ((spi_sr & SPI_SR_SUSP_MASK) >> SPI_SR_SUSP_SHIFT)

//Additional SPI data accepted, 1=accepted.
#define SPI_SR_TSERF_SHIFT       0x10U
#define SPI_SR_TSERF_MASK        (0x1U << SPI_SR_TSERF_SHIFT)
#define SPI_SR_TSERFGET(spi_sr)  ((spi_sr & SPI_SR_TSERF_MASK) >> SPI_SR_SUSP_SHIFT)

//Mode fault int, 1=mode fault detected.
#define SPI_SR_MODF_SHIFT        0x9U
#define SPI_SR_MODF_MASK         (0x1U << SPI_SR_MODF_SHIFT)
#define SPI_SR_MODFGET(spi_sr)   ((spi_sr & SPI_SR_TSERF_MASK) >> SPI_SR_SUSP_SHIFT)

//TI Frame format error
#define SPI_SR_TIFRE_SHIFT       0x8U
#define SPI_SR_TIFRE_MASK        (0x1U << SPI_SR_TIFRE_SHIFT)
#define SPI_SR_TIFREGET(spi_sr)  ((spi_sr & SPI_SR_TIFRE_MASK) >> SPI_SR_TIFRE_SHIFT)

//CRC Error
#define SPI_SR_CRCE_SHIFT        0x7U
#define SPI_SR_CRCE_MASK         (0x1U << SPI_SR_CRCE_SHIFT)
#define SPI_SR_CRCEGET(spi_sr)   ((spi_sr & SPI_SR_TIFRE_MASK) >> SPI_SR_TIFRE_SHIFT)

//Overrun
#define SPI_SR_OVR_SHIFT         0x6U
#define SPI_SR_OVR_MASK          (0x1U << SPI_SR_OVR_SHIFT)
#define SPI_SR_OVRGET(spi_sr)    ((spi_sr & SPI_SR_OVR_MASK) >> SPI_SR_OVR_SHIFT)

//Underrun
#define SPI_SR_UDR_SHIFT         0x5U
#define SPI_SR_UDR_MASK          (0x1U << SPI_SR_UDR_SHIFT)
#define SPI_SR_UDRGET(spi_sr)    ((spi_sr & SPI_SR_UDR_MASK) >> SPI_SR_UDR_SHIFT)

/*Transmission transfer filled, when 1, TXFIFO upload is finished, TXTF is set by hardware as soon as all of the data packets in a transfer have been submitted
for transmission by application software or DMA, that is when TSIZE number of data have
been pushed into the TxFIFO.*/
#define SPI_SR_TXTF_SHIFT        0x4U
#define SPI_SR_TXTF_MASK         (0x1U << SPI_SR_TXTF_MASK)
#define SPI_SR_TXTFGET(spi_sr)   ((spi_sr & SPI_SR_TXTF_MASK) >> SPI_SR_TXTF_SHIFT)

/*End of transfer, EOT is set by hardware as soon as a full transfer is complete, that is when TSIZE number of
data have been transmitted and/or received on the SPI.
In master, EOT event terminates the data transaction and handles SS output optionally. When
CRC is applied, the EOT event is extended over the CRC frame transaction.*/
#define SPI_SR_EOT_SHIFT         0X3U
#define SPI_SR_EOT_MASK          (0x1U << SPI_SR_EOT_SHIFT)
#define SPI_SR_EOTGET(spi_sr)    ((spi_sr & SPI_SR_EOT_MASK) >> SPI_SR_EOT_SHIFT)

//Duplex packet, set whenever both TXP and RXP flags are set.
#define SPI_SR_DXP_SHIFT         0x2U
#define SPI_SR_DXP_MASK          (0x1U << SPI_SR_DXP_SHIFT)
#define SPI_SR_DXPGET(spi_sr)    ((spi_sr << SPI_SR_DXP_MASK) >> SPI_SR_DXP_SHIFT)

//TX Packet space available, if 1, TXFIFO has enough space to host 1 data packet.
#define SPI_SR_TXP_SHIFT         0x1U
#define SPI_SR_TXP_MASK          (0x1U << SPI_SR_TXP_SHIFT)
#define SPI_SR_TXPGET(spi_sr)      ((spi_sr << SPI_SR_TXP_MASK) >> SPI_SR_TXP_SHIFT)

//RX Packet available, if 1, RXFIFO contains at least 1 data packet.
#define SPI_SR_RXP_MASK          0x1U
#define SPI_SR_RXPGET(spi_sr)    (spi << SPI_SR_RXP_MASK)

/*-----------------------------------------------------------*/
/*SPI_IFCR*/

//SUSPend flag clear
#define SPI_IFCR_SUSPC_SHIFT     0xBU
#define SPI_IFCR_SUSPC_MASK      (0x1U << SPI_IFCR_SUSPC_SHIFT)
#define SPI_IFCR_SUSPC           (0x1U << SPI_IFCR_SUSPC_SHIFT)

//TSERF flag clear
#define SPI_IFCR_TSERFC_SHIFT    0xAU
#define SPI_IFCR_TSERFC_MASK     (0x1U << SPI_TSERFC_SHIFT)
#define SPI_IFCR_TSERFC          (0x1U << SPI_TSERFC_SHIFT)

//mode fault flag clear
#define SPI_IFCR_MODFC_SHIFT     0x9U
#define SPI_IFCR_MODFC_MASK      (0x1U << SPI_IFCR_MODFC_SHIFT) 
#define SPI_IFCR_MODFC_          (0x1U << SPI_IFCR_MODFC_SHIFT) 

//TI Frame format error flag clear
#define SPI_IFCR_TIFREC_SHIFT    0x8U
#define SPI_IFCR_TIFREC_MASK     (0x1U << SPI_IFCR_TIFREC_SHIFT)
#define SPI_IFCR_TIFREC          (0x1U << SPI_IFCR_TIFREC_SHIFT)

//CRC error flag clear
#define SPI_IFCR_CRCEC_SHIFT     0x7U
#define SPI_IFCR_CRCEC_MASK      (0x1U << SPI_IFCR_CRCEC_SHIFT)
#define SPI_IFCR_CRCEC           (0x1U << SPI_IFCR_CRCEC_SHIFT)

//Overrun flag clear
#define SPI_IFCR_OVRC_SHIFT      0x6U
#define SPI_IFCR_OVRC_MASK       (0x1U << SPI_IFCR_OVRC_SHIFT)
#define SPI_IFCR_OVRC            (0x1U << SPI_IFCR_OVRC_SHIFT)

//Underrun flag clear
#define SPI_IFCR_UDRC_SHIFT      0x5U
#define SPI_IFCR_UDRC_MASK       (0x1U << SPI_IFCR_UDRC_SHIFT)
#define SPI_IFCR_UDRC            (0x1U << SPI_IFCR_UDRC_SHIFT)

//Transmission transfer filled flag clear
#define SPI_IFCR_TXTFC_SHIFT     0x4U
#define SPI_IFCR_TXTFC_MASK      (0x1U << SPI_IFCR_TXTFC_SHIFT)
#define SPI_IFCR_TXTFC           (0x1U << SPI_IFCR_TXTFC_SHIFT)

//end of transfer flag clear
#define SPI_IFCR_EOTC_SHIFT      0x3U
#define SPI_IFCR_EOTC_MASK       (0x1U << SPI_IFCR_EOTC_SHIFT)
#define SPI_IFCR_EOTC            (0x1U << SPI_IFCR_EOTC_SHIFT)   

/*-----------------------------------------------------------*/
/*SPI_TXDR*/

//this register's bits arent written individually, but as a whole using the SPIx_TXDR register address.

/*-----------------------------------------------------------*/
/*SPI_RXDR*/

#define SPI_RXDRGET(spi)        (SPI_RXDR(spi) << 0x0U)              

/*-----------------------------------------------------------*/
/*SPI_CRCPOLY*/

//The content of this register is WP when SPI is enabled.
//leaving blank as of now, better grasp of CRC functions needed.

/*-----------------------------------------------------------*/
/*SPI_TXCRC*/
//leaving blank as of now, better grasp of CRC functions needed.

/*-----------------------------------------------------------*/
/*SPI_RXCRC*/
//leaving blank as of now, better grasp of CRC functions needed.

/*-----------------------------------------------------------*/
/*SPI_UDRDR*/
//data at slave underrun condition

/*-----------------------------------------------------------*/

/*Function prototypes*/

BEGIN_DECLS

void spi_config_ss(uint32_t spi, uint8_t ss_mgt, uint8_t ssoe, uint8_t ssom_mode, uint8_t ssiop, uint8_t mssi, uint8_t midi);
void spi_set_master_slave(uint32_t spi, uint8_t mode);
void spi_set_protocol(uint32_t spi, uint8_t prot);
void spi_set_mbr_div(uint32_t spi, uint8_t mbrdiv);
void spi_set_lsbmsb(uint32_t spi, uint8_t lsbfrst);
void spi_set_afcntr(uint32_t spi, uint8_t ctrl_mode);
void spi_cfg_polarity(uint32_t spi, uint8_t cpol);
void spi_set_ck_phase(uint32_t spi, uint8_t cpha);
void spi_set_comms_mode(uint32_t spi, uint8_t comm);
void spi_config_data_size(uint32_t spi, uint16_t dsize, uint16_t tsize);
void spi_enable(uint32_t spi);
void spi_disable(uint32_t spi);
void spi_send(uint32_t spi, const uint8_t *data, uint8_t *rx_buf, uint16_t len);

END_DECLS
#endif
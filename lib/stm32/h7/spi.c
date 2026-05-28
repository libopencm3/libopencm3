/**
 * @brief <b>libopencm3 STM32H7xx SPI Communication library</b>
 *
 * @version 1.0.0
 *
 * @date 16 December, 2019
 *
 * This library supports the SPI Peripheral for the
 * STM32H7 series of ARM Cortex Microcontrollers by ST Microelectronics.
 * All info taken from RM0433 and STM32Hxx datasheets.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2026 Frederico Tresbach Tuchtenhagen
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

#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/rcc.h>
#include <stdlib.h>

/*SPI Setup Functions*/

/** Set Slave Select mode for the given SPI.
 * @
 * Selects the Slave Select mode for the desired SPI peripheral.
 * Only applies when using Motorola protocol. 
 * These configs are taken into account only when master mode is set.
 * 
 * @attention This function also sets the Slave Select Output Management mode and Idleness periods, 
 * when SSOM=1, SPI Data frames are interleaved with SS non active pulses when MIDI>1, 
 * which basically means it pulls the SS signal high between Data frames if MIDI delay is greater than 1 clock cycle,
 * when 0, the SS signal is kept low until EOT.
 * @param [in] spi SPI base address;
 * @param [in] ss_mgt Slave Select mode, when 0,
 *                    can be configured two ways depending on the SSOE bit on SPI_CFG2;
 * @param [in] ssom_mode SS Output Management, used when SSOE=1, if set, the SPI DFs will have SS non-active pulses inbetween, if 0, SS will be active until EOT.
 * @param [in] ssoe Slave Select output enable, if 0, the NSS pin is not driven by the SPI peripheral. this setting is useful when Master, SSM=0 and single-slave
 * @param [in] mssi Master SS Idleness, this bits set the initial delay between the SS Active signal and the Clock Start. 
 * @param [in] midi Master Inter-Data Idleness, this bits set the delay between two consecutive data frames in master mode, if SSOM=1, MIDI must be >1.
 * @param [in] ssiop Slave Select polarity, 1 for active high, 0 for active low.
 */                   
void spi_config_ss(uint32_t spi, uint8_t ss_mgt, uint8_t ssoe, uint8_t ssom_mode, uint8_t ssiop, uint8_t mssi, uint8_t midi) {
    uint32_t cfg2 = SPI_CFG2(spi);
    cfg2 = (cfg2 & ~SPI_CFG2_SSM_MASK) | ss_mgt;
    cfg2 = (cfg2 & ~SPI_CFG2_SSOE_MASK) | ssoe;
    cfg2 = (cfg2 & ~SPI_CFG2_SSOM_MASK) | ssom_mode;
    cfg2 = (cfg2 & ~SPI_CFG2_MSSI_MASK) | mssi;
    cfg2 = (cfg2 & ~SPI_CFG2_MIDI_MASK) | midi;
    cfg2 = (cfg2 & ~SPI_CFG2_SSIOP_MASK) | ssiop;
    SPI_CFG2(spi) = cfg2;
}

/** Set Master/Slave mode for the given SPI.
 *
 * Selects the Master/Slave mode for the desired SPI peripheral,
 * @param [in] spi SPI base address;
 * @param [in] mode Master/Slave mode select, use the bitmasks for this setting.
 */ 
void spi_set_master_slave(uint32_t spi, uint8_t mode) {
    SPI_CFG2(spi) = (SPI_CFG2(spi) & ~SPI_CFG2_MASTER_MASK) | mode;
}

/** Sets the serial protocol for the given SPI.
 *
 * Selects the Master/Slave mode for the desired SPI peripheral,
 * Please note that when using motorola mode(mode=0), bits CPOL, CPHA, LSBFRST, SSOM, SSOE, SSIOP, MSSI, MIDI and SSM must be configured.
 * @param [in] spi SPI base address;
 * @param [in] prot Serial Protocol select, Motorola or Texas, use the bitmasks for this setting.
 */ 
void spi_set_protocol(uint32_t spi, uint8_t prot) {
    SPI_CFG2(spi) = (SPI_CFG2(spi) & ~SPI_CFG2_SP_MASK) | prot;
}

/** Sets Master Baud Rate divider.
 *
 * This function sets the baud rate divider when working in slave mode while using the TI protocol.
 * @param [in] spi SPI base address;
 * @param [in] mbrdiv Master Baud Rate divider macro.
 */ 
void spi_set_mbr_div(uint32_t spi, uint8_t mbrdiv) {
    SPI_CFG1(spi) = (SPI_CFG1(spi) & ~SPI_CFG1_MBR_MASK) | mbrdiv;
}

/** Sets MSB/LSB.
 *
 * This functions selects the SPI shift register order.
 * @param [in] spi SPI base address;
 * @param [in] lsbfrst MSB or LSB mode selection.
 */ 
void spi_set_lsbmsb(uint32_t spi, uint8_t lsbfrst) {
    SPI_CFG2(spi) = (SPI_CFG2(spi) & ~SPI_CFG2_LSBFRST_MASK) | lsbfrst;
}

/** Sets Alternate Function GPIO control.
 *
 * This function set the AF Control for the SPI, if 1, the periph keeps control of the AF even when disabled.
 * @param [in] spi SPI base address;
 * @param [in] ctrl_mode AF Control mode.
 */ 
void spi_set_afcntr(uint32_t spi, uint8_t ctrl_mode) {
    SPI_CFG2(spi) = (SPI_CFG2(spi) & ~SPI_CFG2_AFCNTR_MASK) | ctrl_mode;
}

/** Sets clock polarity.
 *
 * This function sets the clock polarity, 1 for active high, 0 for active low.
 * @param [in] spi SPI base address;
 * @param [in] cpol Clock Polarity cfg.
 */ 
void spi_cfg_polarity(uint32_t spi, uint8_t cpol) {
    SPI_CFG2(spi) = (SPI_CFG2(spi) & ~SPI_CFG2_CPOL_MASK) | cpol;
}

/** Sets data capture clock phase.
 *
 * This function sets the phase for the data capture, if 1, the second clock transition will be the first data capture edge.
 * @param [in] spi SPI base address;
 * @param [in] cpha Clock Phase cfg.
 */ 
void spi_set_ck_phase(uint32_t spi, uint8_t cpha) {
    SPI_CFG2(spi) = (SPI_CFG2(spi) & ~SPI_CFG2_CPHA_MASK) | cpha;
}

/** Sets the Comms mode for the SPI Periph.
 *
 * This function sets the comms mode for the given SPI, please use the bitmasks available for this setting.
 * @param [in] spi SPI base address;
 * @param [in] comm SPI Comms mode(full-duplex, half-duplex, siplex tx, simplex rx),
 */ 
void spi_set_comms_mode(uint32_t spi, uint8_t comm) {
    SPI_CFG2(spi) = (SPI_CFG2(spi) & ~SPI_CFG2_COMM_MASK) | comm;
}

void spi_config_data_size(uint32_t spi, uint16_t dsize, uint16_t tsize) {
    uint8_t fthlv = (dsize <= 8) ? 4 : 2;
    SPI_CFG1(spi) &= ~(SPI_CFG1_FTHLV_MASK | SPI_CFG1_DSIZE_MASK);
    SPI_CFG1(spi) |= (fthlv << SPI_CFG1_FTHLV_SHIFT) |
                     ((dsize - 1) << SPI_CFG1_DSIZE_SHIFT);
    SPI_CR2(spi) = (SPI_CR2(spi) & ~SPI_CR2_TSIZE_MASK) | tsize;
}

/**SPI Peripheral Enable
 * 
 * This function enables the SPI, please config first.
 */
void spi_enable(uint32_t spi) {
    SPI_CR1(spi) |= SPI_CR1_SPE;
}

void spi_disable(uint32_t spi) {
    SPI_CR1(spi) &= ~SPI_CR1_SPE;
}

/*SPI Communication Functions*/

void spi_send_start(uint32_t spi) {
    SPI_CR1(spi) |= SPI_CR1_CSTART;
}


/**SPI Send/Receive data function
 * 
 * This function sends 8 bit data frames stored at the data buffer, with a len size data packet, it also reads data from the rxdr register into the rx_buf register.
 * 
 */
void spi_send(uint32_t spi, const uint8_t *data, uint8_t *rx_buf, uint16_t len, uint8_t dsize) {
    if (len == 0) return;
    spi_config_data_size(spi, dsize, len);
    spi_send_start(spi);
    for (uint16_t i = 0; i < len; i++) {
        while (!SPI_SR_TXPGET(spi));
        uint8_t data_byte = data ? data[i] : 0x00;

        *(volatile uint8_t*)&SPI_TXDR(spi) = data_byte;

        while (SPI_SR_CTSIZEGET(spi));

        while (!SPI_SR_RXPGET(spi));
        uint8_t rx_byte = SPI_RXDR(spi);
        
        if (rx_buf) rx_buf[i] = rx_byte;
    
    }

    while (!SPI_SR_EOTGET(spi));
    SPI_ICFR(spi) |= SPI_IFCR_EOTC;

}


void spi_setup(const struct spi_setup_config *config) {
    spi_disable(config->spi);
    spi_config_ss(config->spi, config->ss_mgt, config->ssoe, config->ssom_mode,
                config->ssiop, config->mssi, config->midi);
    spi_set_lsbmsb(config->spi, config->lsbfrst);
    spi_set_master_slave(config->spi, config->mode);
    spi_set_protocol(config->spi, config->prot);
    spi_set_mbr_div(config->mbrdiv, config->mbrdiv);
    spi_cfg_polarity(config->spi, config->cpol);
    spi_set_ck_phase(config->spi, config->cpha);
}
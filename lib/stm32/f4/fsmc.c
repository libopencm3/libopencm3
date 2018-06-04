
/* Author, Copyright: Oleg Borodin <onborodin@gmail.com> 2018 */

/* Utility functions for the SDRAM component of the FSMC */

/*
    The code options below are equivalent:

    1)
       FSMC_BTR(0) = FSMC_BTR_ACCMODx(FSMC_BTx_ACCMOD_B) | 
       FSMC_BTR_DATLATx(0) |
       FSMC_BTR_CLKDIVx(0) |
       FSMC_BTR_BUSTURNx(0) |
       FSMC_BTR_DATASTx(5) |
       FSMC_BTR_ADDHLDx(0) |
       FSMC_BTR_ADDSETx(1);
     FSMC_BCR(0) = FSMC_BCR_WREN | FSMC_BCR_MWID | FSMC_BCR_MBKEN;

    2)
    fsmc_set_access_mode(BANK1, FSMC_BTx_ACCMOD_B);
    fsmc_set_data_latency(BANK1, 0);
    fsmc_set_clock_divide_ratio(BANK1, 0);
    fsmc_set_turnaround_phase_duration(BANK1, 0);
    fsmc_set_data_phase_duration(BANK1, 5);
    fsmc_set_address_hold_phase_duration(BANK1, 0);
    fsmc_set_address_setup_phase_duration(BANK1, 1);


    fsmc_address_data_multiplexing_disable(BANK1);
    fsmc_write_burst_disable(BANK1);
    fsmc_wrapped_burst_mode_disable(BANK1);
    fsmc_extended_mode_disable(BANK1);
    fsmc_write_enable(BANK1);

    fsmc_wait_signal_polarity_low(BANK1);
    fsmc_wait_timing_configuration_enable(BANK1);
    fsmc_wait_disable(BANK1);
    fsmc_memory_bank_enable(BANK1);
}

 */


#include <libopencm3/stm32/fsmc.h>

void fsmc_write_burst_disable(uint32_t bcr) {
    FSMC_BCR(bcr) &= ~FSMC_BCR_CBURSTRW;
}

void fsmc_write_burst_enable(uint32_t bcr) {
    FSMC_BCR(bcr) |= FSMC_BCR_CBURSTRW;
}

void fsmc_extended_mode_disable(uint32_t bcr) {
    FSMC_BCR(bcr) &= ~FSMC_BCR_EXTMOD;
}
void fsmc_extended_mode_enable(uint32_t bcr) {
    FSMC_BCR(bcr) |= FSMC_BCR_EXTMOD;
}


void fsmc_write_disable(uint32_t bcr) {
    FSMC_BCR(bcr) &= ~FSMC_BCR_WREN;
}
void fsmc_write_enable(uint32_t bcr) {
    FSMC_BCR(bcr) |= FSMC_BCR_WREN;
}

void fsmc_wait_disable(uint32_t bcr) {
    FSMC_BCR(bcr) &= ~FSMC_BCR_WAITEN;
}
void fsmc_wait_enable(uint32_t bcr) {
    FSMC_BCR(bcr) |= FSMC_BCR_WAITEN;
}


void fsmc_wait_signal_polarity_low(uint32_t bcr) {
    FSMC_BCR(bcr) &= ~FSMC_BCR_WAITPOL;
}
void fsmc_wait_signal_polarity_high(uint32_t bcr) {
    FSMC_BCR(bcr) |= FSMC_BCR_WAITPOL;
}

void fsmc_wrapped_burst_mode_disable(uint32_t bcr) {
    FSMC_BCR(bcr) &= ~FSMC_BCR_WRAPMOD;
}
void fsmc_wrapped_burst_mode_enable(uint32_t bcr) {
    FSMC_BCR(bcr) |= FSMC_BCR_WRAPMOD;
}


void fsmc_burst_disable(uint32_t bcr) {
    FSMC_BCR(bcr) &= ~FSMC_BCR_BURSTEN;
}
void fsmc_burst_enable(uint32_t bcr) {
    FSMC_BCR(bcr) |= FSMC_BCR_BURSTEN;
}


void fsmc_wait_timing_configuration_disable(uint32_t bcr) {
    FSMC_BCR(bcr) &= ~FSMC_BCR_WAITEN;
}
void fsmc_wait_timing_configuration_enable(uint32_t bcr) {
    FSMC_BCR(bcr) |= FSMC_BCR_WAITEN;
}

void fsmc_address_data_multiplexing_disable(uint32_t bcr) {
    FSMC_BCR(bcr) &= ~FSMC_BCR_MUXEN;
}
void fsmc_address_data_multiplexing_enable(uint32_t bcr) {
    FSMC_BCR(bcr) |= FSMC_BCR_MUXEN;
}

void fsmc_memory_bank_enable(uint32_t bcr) {
    FSMC_BCR(bcr) |= FSMC_BCR_MBKEN;
}

void fsmc_memory_bank_disable(uint32_t bcr) {
    FSMC_BCR(bcr) &= ~FSMC_BCR_MBKEN;
}

void fsmc_set_access_mode(uint32_t bank, uint32_t mode) {
     FSMC_BTR(bank) |= FSMC_BTR_ACCMODx(mode);
}

void fsmc_set_data_latency(uint32_t bank, uint32_t lat) {
     FSMC_BTR(bank) |= FSMC_BTR_DATLATx(lat);
}

void fsmc_set_clock_divide_ratio(uint32_t bank, uint32_t div) {
     FSMC_BTR(bank) |= FSMC_BTR_CLKDIVx(div);
}

void fsmc_set_turnaround_phase_duration(uint32_t bank, uint32_t duration) {
     FSMC_BTR(bank) |= FSMC_BTR_BUSTURNx(duration);
}

void fsmc_set_data_phase_duration(uint32_t bank, uint32_t duration) {
     FSMC_BTR(bank) |= FSMC_BTR_DATASTx(duration);
}

void fsmc_set_address_hold_phase_duration(uint32_t bank, uint32_t duration) {
     FSMC_BTR(bank) |= FSMC_BTR_ADDHLDx(duration);
}

void fsmc_set_address_setup_phase_duration(uint32_t bank, uint32_t duration) {
     FSMC_BTR(bank) |= FSMC_BTR_ADDSETx(duration);
}


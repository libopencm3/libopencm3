bool cordic_get_result_ready_flag(uint32_t cordic) {
        return CORDIC_CSR & CORDIC_CSR_RRDY;
}

void cordic_set_32bit_argument_data_width(uint32_t cordic) {
        CORDIC_CSR &= ~CORDIC_CSR_ARGSIZE;
}

void cordic_set_16bit_argument_data_width(uint32_t cordic) {
        CORDIC_CSR |= CORDIC_CSR_ARGSIZE;
}

void cordic_set_32bit_result_data_width(uint32_t cordic) {
        CORDIC_CSR &= ~CORDIC_CSR_RESSIZE;
}

void cordic_set_16bit_result_data_width(uint32_t cordic) {
        CORDIC_CSR |= CORDIC_CSR_RESSIZE;
}

void cordic_set_argument_number_1(uint32_t cordic) {
        CORDIC_CSR &= ~CORDIC_CSR_NARGS;
}

void cordic_set_argument_number_2(uint32_t cordic) {
        CORDIC_CSR |= CORDIC_CSR_NARGS;
}

void cordic_set_result_number_1(uint32_t cordic) {
        CORDIC_CSR &= ~CORDIC_CSR_NRES;
}

void cordic_set_result_number_2(uint32_t cordic) {
        CORDIC_CSR |= CORDIC_CSR_NRES;
}

void cordic_enable_dma_write(uint32_t cordic) {
        CORDIC_CSR |= CORDIC_CSR_DMAWEN;
}

void cordic_enable_dma_read(uint32_t cordic) {
        CORDIC_CSR |= CORDIC_CSR_DMAREN;
}

void cordic_enable_interrupt(uint32_t cordic) {
        CORDIC_CSR |= CORDIC_CSR_IEN;
}

void cordic_set_scaling_factor(uint32_t cordic, uint8_t scale) {
        CORDIC_CSR = CORDIC_CSR & ~CORDIC_CSR_SCALE_MASK | scale << CORDIC_CSR_SCALE_SHIFT;
}

void cordic_set_precision(uint32_t cordic, uint8_t precision) {
        CORDIC_CSR = CORDIC_CSR & ~CORDIC_CSR_PRECISION_MASK | precision << CORDIC_CSR_PRECISION_SHIFT;
}

void cordic_set_function(uint32_t cordic, uint8_t function) {
        CORDIC_CSR = CORDIC_CSR & ~CORDIC_CSR_FUNC_MASK | function << CORDIC_CSR_FUNC_SHIFT;
}

void cordic_write_16bit_argument(uint32_t cordic, uint16_t argument) {
        CORDIC_WDATA = argument;
}

void cordic_write_16bit_arguments(uint32_t cordic, uint16_t argument1, uint16_t argument2) {
        CORDIC_WDATA = argument2 << 16 | argument1;
}

void cordic_write_32bit_argument(uint32_t cordic, uint32_t argument) {
        CORDIC_WDATA = argument;
}

uint16_t cordic_read_16bit_result(uint32_t cordic) {
        return CORDIC_RDATA;
}
void cordic_read_16bit_results(uint32_t cordic, uint16_t *result1, uint16_t *result2) {
        uint32_t temp = CORDIC_RDATA;
        *result1 = CORDIC_RDATA;
        *result2 = CORDIC_RDATA >> 16;
}

uint32_t cordic_read_32bit_result(uint32_t cordic) {
        return CORDIC_RDATA;
}

int16_t cordic_cos_16bit(uint32_t cordic, int16_t x) {
        cordic_set_function(cordic, CORDIC_CSR_FUNC_COS);
        cordic_set_precision(cordic, CORDIC_CSR_PRECISION_20_ITER);
        cordic_set_16bit_argument_data_width(cordic);
        cordic_set_16bit_result_data_width(cordic);
        cordic_set_argument_number_1(cordic);
        cordic_set_result_number_1(cordic);
        // scale is not applicable for cos
        cordic_write_16bit_argument(cordic, x);

        while(!cordic_get_result_ready_flag(cordic));

        return cordic_read_16bit_result(cordic);
}

int32_t cordic_cos_32bit(int32_t x);
int16_t cordic_sin_16bit(int16_t x);
int32_t cordic_sin_32bit(int32_t x);
void cordic_sin_cos_16bit(int16_t x);
void cordic_sin_cos_32bit(int32_t x);
int16_t cordic_atan2_16bit(int16_t x, int16_t y);
int32_t cordic_atan2_32bit(int32_t x, int32_t y);
uint16_t cordic_magnitude_16bit(int16_t x, int16_t y);
uint32_t cordic_magnitude_32bit(int32_t x, int32_t y);
int16_t cordic_atan_16bit(int16_t x, uint8_t scale);
int32_t cordic_atan_32bit(int32_t x, uint8_t scale);
int16_t cordic_cosh_16bit(int16_t x);
int32_t cordic_cosh_32bit(int32_t x);
int16_t cordic_sinh_16bit(int16_t x);
int32_t cordic_sinh_32bit(int32_t x);

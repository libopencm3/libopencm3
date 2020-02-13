/**
 * @addtogroup can_api CAN Peripheral API
 * @ingroup peripheral_apis
 * @brief <b>PAC55xxxx CAN Driver</b>
 * @author @htmlonly &copy; @endhtmlonly 2020 Kevin Stefanik <kevin@allocor.tech>
 * @date January 13, 2020
 *
 * This library supports the CAN module in the PAC55xx SoC from Qorvo.
 *
 * Note: Acceptance Code Mask Register values of 1 indicate the filter is to
 * ignore the bit. However, standard CAN driver APIs use a positive logic for the
 * mask. The implementations in this file inverts masks as appropriate to
 * the mask to make this more portable/intuitive.
 *
 * LGPL License Terms @ref lgpl_license
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
#include <libopencm3/pac55xx/can.h>
#include <libopencm3/cm3/common.h>


/*---------------------------------------------------------------------------*/
/** @brief CAN Enable

Enable the CAN peripheral and its associated FIFOs/counters/interrupts.

@param[in] canport Unsigned int32. CAN block register base address.
 */
void can_enable(uint32_t canport)
{
  CAN_ISR_SR_CMR_MR_CLEAR(canport, CAN_MR_RM);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Disable

Disable the CAN peripheral and all associated FIFOs/counters/interrupts.

@param[in] canport Unsigned int32. CAN block register base address.
 */
void can_disable(uint32_t canport)
{
  CAN_ISR_SR_CMR_MR_SET(canport, CAN_MR_RM);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Init

Initialize the selected CAN peripheral block.

@param[in] canport Unsigned int32. CAN block register base address.
@param[in] listen_only bool. Enable listen only mode.
@param[in] sjw Unsigned int32. Resynchronization time quanta jump width.
@param[in] tseg1 Unsigned int32. Time segment 1 time quanta width.
@param[in] tseg2 Unsigned int32. Time segment 2 time quanta width.
@param[in] sam3 bool. Use best 2 out of 3 samples.
@param[in] brp Unsigned int32. Baud rate prescaler.
*/
void can_init(uint32_t canport, bool listen_only, uint32_t sjw, uint32_t tseg1,
              uint32_t tseg2, bool sam3, uint32_t brp)
{
  /* Put CAN module in reset and clear out ISR/SR/CMR/MR */
  CAN_ISR_SR_CMR_MR(canport) = CAN_MR_RM;
  /* Setup single filter scheme */
  CAN_ISR_SR_CMR_MR_SET(canport, CAN_MR_AFM);
  /* enable listen-only mode */
  if (listen_only) {
    CAN_ISR_SR_CMR_MR_SET(canport, CAN_MR_LOM);
  }

  /* Set Baud Rate Prescaler, sync jump width, tseg1/2 */
  CAN_BTR1_BTR0_RMC_IMR(canport) = CAN_BTR0_BRP(brp) | CAN_BTR0_SJW(sjw) |
      CAN_BTR1_TSEG1(tseg1) | CAN_BTR1_TSEG2(tseg2);
  if (sam3) {
    /* enable sample bus 3 times */
    CAN_BTR1_BTR0_RMC_IMR(canport) |= CAN_BTR1_SAM;
  }

  /* Filter: Accept incoming messages with any identifier */
  CAN_ACR(canport) = 0;
  /* Note: when mask bits are 1, the bits are ignored */
  CAN_AMR(canport) = 0xFFFFFFFFu;
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Filter Clear

Clear the message filters to receive all messages.

@param[in] canport Unsigned int32. CAN block register base address.
*/
void can_filter_clear(uint32_t canport) {
  /* Filter: Accept incoming messages with any identifier */
  CAN_ACR(canport) = 0;
  /* Note: when mask bits are 1, the bits are ignored */
  CAN_AMR(canport) = 0xFFFFFFFFu;
  /* Setup single filter scheme */
  CAN_ISR_SR_CMR_MR_SET(canport, CAN_MR_AFM);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Dual Filter Standard Frame
Note: Acceptance Code Mask Register values of 1 indicate the filter is to
ignore the bit. However, standard CAN driver APIs use a positive logic for the
mask. So this function inverts the mask to make this more portable/intuitive.

@param[in] canport Unsigned int32. CAN block register base address.
@param[in] id1 Unsigned int32. CAN ID 1. Only bits 10:0 are used.
@param[in] id1_mask Unsigned int32. CAN ID 1 mask. Only bits 10:0 are used.
@param[in] id2 Unsigned int32. CAN ID 2. Only bits 10:0 are used.
@param[in] id2_mask Unsigned int32. CAN ID 2 mask. Only bits 10:0 are used.
@param[in] db bool. CAN first data byte value.
@param[in] db_mask bool. CAN first data byte mask.
 */
void can_filter_dual(uint32_t canport, uint32_t id1, uint32_t id1_mask,
                     uint32_t id2, uint32_t id2_mask,
                     uint8_t db, uint8_t db_mask) {
  /* set value */
  uint32_t word = ((id1 << 21) & CAN_ACR_DUAL_ID1) |
      ((id2<<5) & CAN_ACR_DUAL_ID2) |
      ((db<<12) & CAN_ACR_DUAL_DB_UPPER) |
      (db & CAN_ACR_DUAL_DB_LOWER);
  CAN_ACR(canport) = __builtin_bswap32(word);
  /* set mask */
  word = ((~id1_mask << 21) & CAN_ACR_DUAL_ID1) |
      ((~id2_mask<<5) & CAN_ACR_DUAL_ID2) |
      ((~db_mask<<12) & CAN_ACR_DUAL_DB_UPPER) |
      ((~db_mask) & CAN_ACR_DUAL_DB_LOWER) |
      CAN_ACR_DUAL_RTR1 |
      CAN_ACR_DUAL_RTR2;
  CAN_AMR(canport) = __builtin_bswap32(word);
  /* 0: dual filter */
  CAN_ISR_SR_CMR_MR_CLEAR(canport, CAN_MR_AFM);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Filter Single Standard Frame
Note: Acceptance Code Mask Register values of 1 indicate the filter is to
ignore the bit. However, standard CAN driver APIs use a positive logic for the
mask. So this function inverts the mask to make this more portable/intuitive.

@param[in] canport Unsigned int32. CAN block register base address.
@param[in] id Unsigned int32. CAN ID. Only bits 10:0 are used.
@param[in] id_mask Unsigned int32. CAN ID mask. Only bits 10:0 are used.
@param[in] rtr bool. Remote Request bit value.
@param[in] rtr_mask bool. Remote Request mask value.
@param[in] db1 bool. CAN first data byte value.
@param[in] db1_mask bool. CAN first data byte mask.
@param[in] db2 bool. CAN second data byte value.
@param[in] db2_mask bool. CAN second data byte mask.
 */
void can_filter_single_std(uint32_t canport, uint32_t id, uint32_t id_mask,
                                uint8_t db1, uint8_t db1_mask,
                                uint8_t db2, uint8_t db2_mask) {
  /* set value */
  uint32_t word = ((id << 21) & CAN_ACR_SINGLE_STD_ID) |
      ((db1<<8) & CAN_ACR_SINGLE_STD_DB1) |
      ((db2<<0) & CAN_ACR_SINGLE_STD_DB2);
  CAN_ACR(canport) = __builtin_bswap32(word);
  /* set mask */
  word = ((~id_mask << 21) & CAN_ACR_SINGLE_STD_ID) |
      CAN_ACR_SINGLE_STD_RTR |
      CAN_ACR_DUAL_DB_UPPER |
      ((~db1_mask<<8) & CAN_ACR_SINGLE_STD_DB1) |
      ((~db2_mask<<0) & CAN_ACR_SINGLE_STD_DB2);
  CAN_AMR(canport) = __builtin_bswap32(word);
  /* 1: single filter */
  CAN_ISR_SR_CMR_MR_SET(canport, CAN_MR_AFM);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Filter Single Standard Frame w/RTR set
Note: Acceptance Code Mask Register values of 1 indicate the filter is to
ignore the bit. However, standard CAN driver APIs use a positive logic for the
mask. So this function inverts the mask to make this more portable/intuitive.

@param[in] canport Unsigned int32. CAN block register base address.
@param[in] id Unsigned int32. CAN ID. Only bits 10:0 are used.
@param[in] id_mask Unsigned int32. CAN ID mask. Only bits 10:0 are used.
@param[in] rtr bool. Remote Request bit value.
@param[in] rtr_mask bool. Remote Request mask value.
@param[in] db1 bool. CAN first data byte value.
@param[in] db1_mask bool. CAN first data byte mask.
@param[in] db2 bool. CAN second data byte value.
@param[in] db2_mask bool. CAN second data byte mask.
 */
void can_filter_single_std_rtr(uint32_t canport, uint32_t id, uint32_t id_mask,
                                uint8_t db1, uint8_t db1_mask,
                                uint8_t db2, uint8_t db2_mask) {
  /* set value */
  uint32_t word = ((id << 21) & CAN_ACR_SINGLE_STD_ID) |
      CAN_ACR_SINGLE_STD_RTR |
      ((db1<<8) & CAN_ACR_SINGLE_STD_DB1) |
      ((db2<<0) & CAN_ACR_SINGLE_STD_DB2);
  CAN_ACR(canport) = __builtin_bswap32(word);
   /* set mask */
  word = ((~id_mask << 21) & CAN_ACR_SINGLE_STD_ID) |
      ((~db1_mask<<8) & CAN_ACR_SINGLE_STD_DB1) |
      ((~db2_mask<<0) & CAN_ACR_SINGLE_STD_DB2);
  CAN_AMR(canport) = __builtin_bswap32(word);
  /* 1: single filter */
  CAN_ISR_SR_CMR_MR_SET(canport, CAN_MR_AFM);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Filter Single Extended Frame
Note: Acceptance Code Mask Register values of 1 indicate the filter is to
ignore the bit. However, standard CAN driver APIs use a positive logic for the
mask. So this function inverts the mask to make this more portable/intuitive.

@param[in] canport Unsigned int32. CAN block register base address.
@param[in] id Unsigned int32. CAN ID. Only bits 28:0 are used.
@param[in] id_mask Unsigned int32. CAN ID mask. Only bits 28:0 are used.
@param[in] rtr bool. Remote Request bit value.
@param[in] rtr_mask bool. Remote Request mask value.
 */
void can_filter_single_ext(uint32_t canport, uint32_t id, uint32_t id_mask) {
  /* set value */
  uint32_t word = ((id<<3) & CAN_ACR_SINGLE_EXT_ID );
  CAN_ACR(canport) = __builtin_bswap32(word);
  /* set mask */
  word = ((~id_mask<<3) & CAN_ACR_SINGLE_EXT_ID ) | CAN_ACR_SINGLE_EXT_RTR;
  CAN_AMR(canport) = __builtin_bswap32(word);
  /* 1: single filter */
  CAN_ISR_SR_CMR_MR_SET(canport, CAN_MR_AFM);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Filter Single Extended Frame w/RTR set
Note: Acceptance Code Mask Register values of 1 indicate the filter is to
ignore the bit. However, standard CAN driver APIs use a positive logic for the
mask. So this function inverts the mask to make this more portable/intuitive.

@param[in] canport Unsigned int32. CAN block register base address.
@param[in] id Unsigned int32. CAN ID. Only bits 28:0 are used.
@param[in] id_mask Unsigned int32. CAN ID mask. Only bits 28:0 are used.
@param[in] rtr bool. Remote Request bit value.
@param[in] rtr_mask bool. Remote Request mask value.
 */
void can_filter_single_ext_rtr(uint32_t canport, uint32_t id, uint32_t id_mask) {
  /* set value */
  uint32_t word = ((id<<3) & CAN_ACR_SINGLE_EXT_ID ) | CAN_ACR_SINGLE_EXT_RTR;
  CAN_ACR(canport) = __builtin_bswap32(word);
  /* set mask */
  word = ((~id_mask<<3) & CAN_ACR_SINGLE_EXT_ID );
  CAN_AMR(canport) = __builtin_bswap32(word);
  /* 1: single filter */
  CAN_ISR_SR_CMR_MR_SET(canport, CAN_MR_AFM);
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Enable IRQ

@param[in] canport Unsigned int32. CAN block register base address.
@param[in] irq Unsigned int8. IRQ bit(s).
 */
void can_enable_irq(uint32_t canport, uint8_t imr)
{
  /* set to 1 (not masked) to enable */
  CAN_BTR1_BTR0_RMC_IMR(canport) |= (uint32_t)imr;
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Disable IRQ

@param[in] canport Unsigned int32. CAN block register base address.
@param[in] irq Unsigned int8. IRQ bit(s).
 */
void can_disable_irq(uint32_t canport, uint8_t imr)
{
  /* set to 0 (masked) to disable */
  CAN_BTR1_BTR0_RMC_IMR(canport) &= ~(uint32_t)imr;
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Transmit Standard Frame

@param[in] canport Unsigned int32. CAN block register base address.
@param[in] id Unsigned int32. Message ID bits 10:0 used.
@param[in] rtr bool. Remote Request bit value.
@param[in] length Unsigned int8. Message payload length.
@param[in] data Unsigned int8[]. Message payload data.
@returns int 0 on success, or -1 on failure.
 */
int can_transmit_std(uint32_t canport, uint32_t id, bool rtr,
     uint8_t length, const uint8_t *data)
{
  if (length > 8) {
    return -1;
  }

  /* if TBS is 0, then not ready to transmit */
  if ( (CAN_ISR_SR_CMR_MR(canport) & CAN_SR_TBS) == 0 ) {
    return -1;
  }
  uint32_t word = (length) | (rtr ? BIT6 : 0) |  /* DLC/RTR/FF ==> 7:0 */
                    ((id & 0x07F8) << 5)  |   /* ID 10:3 ==> 15:8 */
                    ((id & 0x07) << 21)   |   /* ID 2:0 ==> 23:21 */
                    (((length>0) ? data[0] : 0) << 24);
  CAN_TXBUF(canport) = word;

  if (length > 1)
  {
    word = (data[1] << 0)  |
           (data[2] << 8)  |
           (data[3] << 16) |
           (data[4] << 24);
    CAN_TXBUF(canport) = word;
  }

  if (length > 5)
  {
    word = (data[5] << 0)   |
           (data[6] << 8)   |
           (data[7] << 16);
    CAN_TXBUF(canport) = word;
  }

  /* Request transmit */
  CAN_ISR_SR_CMR_MR_SET(canport, CAN_CMR_TR);
  return 0;
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Transmit Extended Frame

@param[in] canport Unsigned int32. CAN block register base address.
@param[in] id Unsigned int32. Message ID bits 28:0 used.
@param[in] rtr bool. Remote Request bit value.
@param[in] length Unsigned int8. Message payload length.
@param[in] data Unsigned int8[]. Message payload data.
@returns int 0 on success, or -1 on failure.
 */
int can_transmit_ext(uint32_t canport, uint32_t id, bool rtr,
     uint8_t length, const uint8_t *data)
{
  if (length > 8) {
    return -1;
  }

  /* if TBS is 0, then not ready to transmit */
  if ( (CAN_ISR_SR_CMR_MR(canport) & CAN_SR_TBS) == 0 ) {
    return -1;
  }
  uint32_t word = (length) | (rtr ? BIT6 : 0) | BIT7 | /* DLC/RTR/FF ==> 7:0 */
                  ((id & 0x1FE00000u) >> 13)  | /* ID 28:21 ==> 15:8 */
                  ((id & 0x001FE000u) << 3)   | /* ID 20:13 ==> 23:16 */
                  ((id & 0x00001FE0u) << 19);   /* ID 12:5 ==> 31:24 */
  CAN_TXBUF(canport) = word; /* write first 32-bit word to FIFO */

  word = ((id & 0x1F) << 3);  /* ID 4:0 ==> 7:3 */
  if (length > 0)
  {
    word |= (data[0] << 8)  |
           (data[1] << 16)  |
           (data[2] << 24);
  }
  /* for extended frame, always write second 32-bit word to FIFO */
  CAN_TXBUF(canport) = word;


  if (length > 3)
  {
    word =  (data[3] << 0)  |
            (data[4] << 8)  |
            (data[5] << 16) |
            (data[6] << 24);
    CAN_TXBUF(canport) = word;
  }

  if (length > 7) {
    word =  data[7];
    CAN_TXBUF(canport) = word;
  }

  /* Request transmit */
  CAN_ISR_SR_CMR_MR_SET(canport, CAN_CMR_TR);
  return 0;
}

/*---------------------------------------------------------------------------*/
/** @brief CAN Abort Transmit
Aborts the current transmission.

@param[in] canport Unsigned int32. CAN block register base address.
 */
void can_abort_transmit(uint32_t canport) {
  CAN_ISR_SR_CMR_MR_SET(canport, CAN_CMR_AT);
};

/*---------------------------------------------------------------------------*/
/** @brief CAN Receive Message

@param[in] canport Unsigned int32. CAN block register base address.
@param[out] id Unsigned int32 pointer. Message ID.
@param[out] ext bool pointer. The message ID is extended?
@param[out] rtr bool pointer. Remote Request bit value.
@param[out] length Unsigned int8 pointer. Length of message payload.
@param[out] data Unsigned int8[]. Message payload data.
@return 1 on success
 */
int can_receive(uint32_t canport, uint32_t *id, bool *ext, bool *rtr,
                uint8_t *length, uint8_t *can_rx_data)
{
  /* User must provide data buffer, also ensure RX interrupt bit is 0 */
  if (can_rx_data == 0)
  {
    return -1;
  }
  if ((CAN_ISR_SR_CMR_MR(canport) & CAN_ISR_RI) == 0)
  {
    return -1;
  }
  if (CAN_RMC(canport) == 0)
  {
    return -1;
  }
  uint32_t can_buffer = CAN_RXBUF(canport); /* read 32-bit word */
  uint8_t rx_length = can_buffer & 0x0F;
  bool is_extended = (can_buffer & BIT7) ? true : false;

  if (ext)
  {
    *ext = is_extended;
  }
  if (rtr)
  {
    *rtr = (can_buffer & BIT6) ? true : false;
  }
  if (length)
  {
    *length = rx_length;
  }

  uint32_t _id;
  if (is_extended)
  {
    /* Parse extended message ID from RXBUF */
    _id =  ((can_buffer & 0x0000FF00u) << 13) | /* ID 28:21 <== 15:8 */
          ((can_buffer & 0x00FF0000u) >> 3)   | /* ID 20:13 <== 23:16 */
          ((can_buffer & 0xFF000000u) >> 19);   /* ID 12:5 <== 31:24 */
    can_buffer = CAN_RXBUF(canport);
    _id |= ((can_buffer & 0x000000F8u) >> 3);    /* ID 4:0 <== 7:3 */

    /* Parse extended message data from RXBUF */
    can_rx_data[0] = can_buffer >> 8;
    can_rx_data[1] = can_buffer >> 16;
    can_rx_data[2] = can_buffer >> 24;
    if (rx_length > 3)
    {
      can_buffer = CAN_RXBUF(canport);
      can_rx_data[3] = can_buffer;
      can_rx_data[4] = can_buffer >> 8;
      can_rx_data[5] = can_buffer >> 16;
      can_rx_data[6] = can_buffer >> 24;
    }
    if (rx_length > 7) {
      can_buffer = CAN_RXBUF(canport);
      can_rx_data[7] = can_buffer;
    }
  }
  else
  {
    /* Parse standard message ID from RXBUF */
    _id = ((can_buffer & 0x0000FF00u) >> 5) | /* ID 10:3 <== 15:8 */
        ((can_buffer & 0x00E00000) >> 21);    /* ID 2:0 <== 23:21 */
    /* Parse standard message data from RXBUF */
    can_rx_data[0] = can_buffer >> 24;
    if (rx_length > 1)
    {
      can_buffer = CAN_RXBUF(canport);
      can_rx_data[1] = can_buffer;
      can_rx_data[2] = can_buffer >> 8;
      can_rx_data[3] = can_buffer >> 16;
      can_rx_data[4] = can_buffer >> 24;
      if(rx_length > 5)
      {
        /* buffer contains data5,data6,data7 */
        can_buffer = CAN_RXBUF(canport);
        can_rx_data[5] = can_buffer;
        can_rx_data[6] = can_buffer >> 8;
        can_rx_data[7] = can_buffer >> 16;
      }
    }
  }
  if ( id )
  {
    *id = _id;
  }

  /*
   * Write 1 to acknowledge/clear the interrupt
   * Note: ensure not to let the other interrupt masks be written as 1, so as
   * to avoid acknowledging them.
   * Note: CAN_ISR_RI is already high, but we still write '1' to it to clear it.
   * It does go back to 0 after writing 1.
   */
  CAN_ISR_ACKNOWLEDGE(canport, CAN_ISR_RI);
  return 1;
}

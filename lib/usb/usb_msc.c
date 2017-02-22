/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Weston Schmidt <weston_schmidt@alumni.purdue.edu>
 * Copyright (C) 2013 Pavol Rusnak <stick@gk2.sk>
 * Copyright (C) 2017 Lixing Ding <lixing@cupkee.cn>
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

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/msc.h>

#define BUF_LENGTH 512

#define HOST_2_DEV    0
#define DEV_2_HOST    1

/* Implemented SCSI Commands */
#define SCSI_TEST_UNIT_READY		0x00
#define SCSI_REQUEST_SENSE			0x03
#define SCSI_INQUIRY				0x12
#define SCSI_START_STOP_UNIT		0x1B
#define SCSI_MODE_SENSE_6			0x1A
#define SCSI_MODE_SENSE_10			0x5A
#define SCSI_READ_FORMAT_CAPACITIES	0x23
#define SCSI_READ_CAPACITY			0x25
#define SCSI_READ_10				0x28
#define SCSI_WRITE_10				0x2A

/* Required SCSI Commands */

/* Optional SCSI Commands */
#define SCSI_FORMAT_UNIT			0x04
#define SCSI_MODE_SELECT_6			0x15
#define SCSI_MODE_SELECT_10			0x55
#define SCSI_SEND_DIAGNOSTIC		0x1D
#define SCSI_REPORT_LUNS			0xA0
#define SCSI_PREVENT_ALLOW_MEDIUM_REMOVAL	0x1E
#define SCSI_MODE_SENSE_10			0x5A
#define SCSI_READ_12				0xA8
#define SCSI_READ_TOC_PMA_ATIP		0x43
#define SCSI_SYNCHRONIZE_CACHE		0x35
#define SCSI_VERIFY				    0x2F
#define SCSI_WRITE_12				0xAA

/* The sense codes */
enum sbc_sense_key {
	SBC_SENSE_KEY_NO_SENSE			= 0x00,
	SBC_SENSE_KEY_RECOVERED_ERROR	= 0x01,
	SBC_SENSE_KEY_NOT_READY			= 0x02,
	SBC_SENSE_KEY_MEDIUM_ERROR		= 0x03,
	SBC_SENSE_KEY_HARDWARE_ERROR	= 0x04,
	SBC_SENSE_KEY_ILLEGAL_REQUEST	= 0x05,
	SBC_SENSE_KEY_UNIT_ATTENTION	= 0x06,
	SBC_SENSE_KEY_DATA_PROTECT		= 0x07,
	SBC_SENSE_KEY_BLANK_CHECK		= 0x08,
	SBC_SENSE_KEY_VENDOR_SPECIFIC	= 0x09,
	SBC_SENSE_KEY_COPY_ABORTED		= 0x0A,
	SBC_SENSE_KEY_ABORTED_COMMAND	= 0x0B,
	SBC_SENSE_KEY_VOLUME_OVERFLOW	= 0x0D,
	SBC_SENSE_KEY_MISCOMPARE		= 0x0E
};

enum sbc_asc {
	SBC_ASC_NO_ADDITIONAL_SENSE_INFORMATION	= 0x00,
	SBC_ASC_PERIPHERAL_DEVICE_WRITE_FAULT	= 0x03,
	SBC_ASC_LOGICAL_UNIT_NOT_READY		    = 0x04,
	SBC_ASC_UNRECOVERED_READ_ERROR		    = 0x11,
	SBC_ASC_INVALID_COMMAND_OPERATION_CODE	= 0x20,
	SBC_ASC_LBA_OUT_OF_RANGE		        = 0x21,
	SBC_ASC_INVALID_FIELD_IN_CDB	    	= 0x24,
	SBC_ASC_WRITE_PROTECTED			        = 0x27,
	SBC_ASC_NOT_READY_TO_READY_CHANGE   	= 0x28,
	SBC_ASC_FORMAT_ERROR			        = 0x31,
	SBC_ASC_MEDIUM_NOT_PRESENT		        = 0x3A
};

enum sbc_ascq {
	SBC_ASCQ_NA				                = 0x00,
	SBC_ASCQ_FORMAT_COMMAND_FAILED		    = 0x01,
	SBC_ASCQ_INITIALIZING_COMMAND_REQUIRED	= 0x02,
	SBC_ASCQ_OPERATION_IN_PROGRESS		    = 0x07
};

enum trans_state {
    STATE_IDLE,
    STATE_IN,
    STATE_OUT,
    STATE_CSW,
    STATE_ERR
};

struct sbc_sense_info {
	uint8_t key;
	uint8_t asc;
	uint8_t ascq;
};

struct _usbd_mass_storage {
	usbd_device *usbd_dev;
	uint8_t ep_in;
	uint8_t ep_in_size;
	uint8_t ep_out;
	uint8_t ep_out_size;

	const char *vendor_id;
	const char *product_id;
	const char *product_revision_level;

	int (*read_block)(uint32_t lba, uint8_t *copy_to);
	int (*write_block)(uint32_t lba, const uint8_t *copy_from);

	uint32_t block_count;

    uint8_t state;

    /* current cbw info */
    uint8_t lun;
    uint8_t data_dir;
    uint8_t cbwcb_len;
    uint8_t cbw_tag[4];
    uint8_t cbwcb[16];
    uint32_t data_want;

    /* current IN/OUT info */
    uint32_t block_cur;
    uint32_t block_end;

    /* ms cache */
    uint16_t cache_cnt;
    uint16_t cache_pos;
    uint8_t  cache_buf[BUF_LENGTH];

    /* current sense info */
	struct sbc_sense_info sense;
};


static usbd_mass_storage _mass_storage;

/*-- SCSI Base Responses -----------------------------------------------------*/

static const uint8_t standard_inquiry_response[36] = {
	0x00,	/* Byte 0: Peripheral Qualifier = 0, Peripheral Device Type = 0 */
	0x80,	/* Byte 1: RMB = 1, Reserved = 0 */
	0x02,	/* Byte 2: Version = 0 */
	0x02,	/* Byte 3: Obsolete = 0, NormACA = 0, HiSup = 0, Response Data Format = 2 */

	36 - 4,	/* Byte 4: Additional Length (n-4) = 36 - 4 */
	0x00,	/* Byte 5: SCCS = 0, ACC = 0, TPGS = 0, 3PC = 0, Reserved = 0, Protect = 0 */
	0x00,	/* Byte 6: BQue = 0, EncServ = 0, VS = 0, MultiP = 0, MChngr = 0, Obsolete = 0, Addr16 = 0 */
	0x00,	/* Byte 7: Obsolete = 0, Wbus16 = 0, Sync = 0, Linked = 0, CmdQue = 0, VS = 0 */

		/* Byte 8 - Byte 15: Vendor Identification */
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		/* Byte 16 - Byte 31: Product Identification */
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ',
		/* Byte 32 - Byte 35: Product Revision Level */
	' ', ' ', ' ', ' '
};

static const uint8_t standard_request_sense[18] = {
	0x70,	/* Byte 0: VALID = 0, Response Code = 112 */
	0x00,	/* Byte 1: Obsolete = 0 */
	0x00,	/* Byte 2: Filemark = 0, EOM = 0, ILI = 0, Reserved = 0, Sense Key = 0 */
		/* Byte 3 - Byte 6: Information = 0 */
	0, 0, 0, 0,
	0x0a,	/* Byte 7: Additional Sense Length = 10 */
		/* Byte 8 - Byte 11: Command Specific Info = 0 */
	0, 0, 0, 0,
	0x00,	/* Byte 12: Additional Sense Code (ASC) = 0 */
	0x00,	/* Byte 13: Additional Sense Code Qualifier (ASCQ) = 0 */
	0x00,	/* Byte 14: Field Replaceable Unit Code (FRUC) = 0 */
	0x00,	/* Byte 15: SKSV = 0, SenseKeySpecific[0] = 0 */
	0x00,	/* Byte 16: SenseKeySpecific[0] = 0 */
	0x00	/* Byte 17: SenseKeySpecific[0] = 0 */
};

/*-- SCSI Layer --------------------------------------------------------------*/
static inline uint32_t msb_2_uint32(uint8_t *p)
{
    return p[0] * 0x1000000 + p[1] * 0x10000 + p[2] * 0x100 + p[3];
}

static inline uint16_t msb_2_uint16(uint8_t *p)
{
    return p[0] * 0x100 + p[1];
}

static inline void uint32_2_msb(uint8_t *p, uint32_t d)
{
    p[0] = (uint8_t) (d >> 24);
    p[1] = (uint8_t) (d >> 16);
    p[2] = (uint8_t) (d >> 8);
    p[3] = (uint8_t) (d);
}

static inline void set_sbc_status(usbd_mass_storage *ms,
			   enum sbc_sense_key key,
			   enum sbc_asc asc,
			   enum sbc_ascq ascq)
{
	ms->sense.key = (uint8_t) key;
	ms->sense.asc = (uint8_t) asc;
	ms->sense.ascq = (uint8_t) ascq;
}

static void set_sbc_status_illegal(usbd_mass_storage *ms)
{
    set_sbc_status(ms,
               SBC_SENSE_KEY_ILLEGAL_REQUEST,
               SBC_ASC_INVALID_FIELD_IN_CDB,
               SBC_ASCQ_NA);
}

static void set_sbc_status_good(usbd_mass_storage *ms)
{
	set_sbc_status(ms,
		       SBC_SENSE_KEY_NO_SENSE,
		       SBC_ASC_NO_ADDITIONAL_SENSE_INFORMATION,
		       SBC_ASCQ_NA);
}

static int scsi_format_unit(usbd_mass_storage *ms, uint8_t *buf)
{
    set_sbc_status_good(ms);

    (void) buf;

    // Todo: format code here

    return 0;
}

static int scsi_request_sense(usbd_mass_storage *ms, uint8_t *buf)
{
    uint8_t want = ms->cbwcb[4];

    memcpy(buf, standard_request_sense, want);

    buf[2] = ms->sense.key;
    buf[12] = ms->sense.asc;
    buf[13] = ms->sense.ascq;

    set_sbc_status_good(ms);

    if (want > sizeof(standard_request_sense)) {
        want = sizeof(standard_request_sense);
    }

    return want;
}

static int scsi_mode_sense_6(usbd_mass_storage *ms, uint8_t *buf)
{
    (void) ms;
    buf[0] = 3;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    set_sbc_status_good(ms);
    return 4;
}

static int scsi_inquiry(usbd_mass_storage *ms, uint8_t *buf)
{
    uint8_t evpd = ms->cbwcb[1] & 1;
    uint8_t want = ms->cbwcb[4];
    uint8_t len;

    if (evpd != 0) {
        memset(buf, 0, 5);
        len = 5;
    } else {
        int size;

        memcpy(buf, standard_inquiry_response, sizeof(standard_inquiry_response));
        len = sizeof(standard_inquiry_response);

        size = strlen(ms->vendor_id);
        size = size < 8 ? size : 8;
        memcpy(buf + 8, ms->vendor_id, size);

        size = strlen(ms->product_id);
        size = size < 16 ? size : 16;
        memcpy(buf + 16, ms->product_id, size);

        size = strlen(ms->product_revision_level);
        size = size < 4 ? size : 4;
        memcpy(buf + 32, ms->product_revision_level, size);
    }
    set_sbc_status_good(ms);
    if (len > want) {
        len = want;
    }
    return len;
}

static int scsi_read_format_capacities(usbd_mass_storage *ms, uint8_t *buf)
{
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 8; // Capacity length

    /* Block count, MSB */
    uint32_2_msb(buf + 4, ms->block_count);

    /* Block size, MSB */
    uint32_2_msb(buf + 8, 0x200);

    set_sbc_status_good(ms);
    return 12;
}

static int scsi_read_capacity(usbd_mass_storage *ms, uint8_t *buf)
{
    /* Block count, MSB */
    uint32_2_msb(buf, ms->block_count - 1);

    /* Block size, MSB */
    uint32_2_msb(buf + 4, 0x200);

    set_sbc_status_good(ms);
    return 8;
}

static int scsi_read_10(usbd_mass_storage *ms, uint8_t *buf)
{
    uint32_t start, end;
    uint16_t count;

    start = msb_2_uint32(ms->cbwcb + 2);
    count = msb_2_uint16(ms->cbwcb + 7);
    end = start + count;
    if (end > ms->block_count || count < 1) {
        set_sbc_status_illegal(ms);
        return -1;
    }

    ms->block_cur = start;
    ms->block_end = end;
    ms->read_block(start, buf);

    set_sbc_status_good(ms);
    return 512;
}

static int scsi_write_10(usbd_mass_storage *ms, uint8_t *buf)
{
    uint32_t start, end;
    uint16_t count;

    (void) buf;

    start = msb_2_uint32(ms->cbwcb + 2);
    count = msb_2_uint16(ms->cbwcb + 7);
    end = start + count;
    if (end > ms->block_count || count < 1) {
        set_sbc_status_illegal(ms);
        return -1;
    }

    ms->block_cur = start;
    ms->block_end = end;

    set_sbc_status_good(ms);
    return 0;
}

/*-- USB Mass Storage Layer --------------------------------------------------*/

static inline int msc_send(usbd_mass_storage *ms, int len, const void *data)
{
    len = len < ms->ep_in_size ? len : ms->ep_in_size;

    return usbd_ep_write_packet(ms->usbd_dev, ms->ep_in, data, len);
}

static inline void msc_cache_csw(usbd_mass_storage *ms)
{
    uint8_t *csw = ms->cache_buf;

    csw[0] = 0x55;
    csw[1] = 0x53;
    csw[2] = 0x42;
    csw[3] = 0x53;

    csw[4] = ms->cbw_tag[0];
    csw[5] = ms->cbw_tag[1];
    csw[6] = ms->cbw_tag[2];
    csw[7] = ms->cbw_tag[3];

    // Todo: set real residue
    csw[8] = 0;
    csw[9] = 0;
    csw[10] = 0;
    csw[11] = 0;

    csw[12] = ms->sense.key ? 1 : 0;

    ms->cache_pos = 0;
    ms->cache_cnt = 13;
}

static void msc_send_csw(usbd_mass_storage *ms)
{
    msc_cache_csw(ms);

    msc_send(ms, ms->cache_cnt, ms->cache_buf);
    ms->cache_cnt = 0;
}

static int msc_cbw_decode(usbd_mass_storage *ms)
{
    uint8_t *cbw = ms->cache_buf;
    uint8_t cbwcb_len;

    /* Check signature of cbw */
    if (cbw[0] != 0x55 || cbw[1] != 0x53 || cbw[2] != 0x42 || cbw[3] != 0x43) {
        return -1;
    }

    /* restore cbw tag */
    ms->cbw_tag[0] = cbw[4];
    ms->cbw_tag[1] = cbw[5];
    ms->cbw_tag[2] = cbw[6];
    ms->cbw_tag[3] = cbw[7];

    ms->data_want  = cbw[11] * 0x1000000 + cbw[10] * 0x10000 + cbw[10] * 0x100 + cbw[8];
    ms->data_dir   = (cbw[12] & 0x80) ? DEV_2_HOST : HOST_2_DEV;
    ms->lun        = cbw[13] & 0xf;
    cbwcb_len      = cbw[14] & 0x1f;

    if (cbwcb_len < 1 || cbwcb_len > 16) {
        return -1;
    }
    ms->cbwcb_len = cbwcb_len;

    memcpy(ms->cbwcb, cbw + 15, cbwcb_len);

    return 0;
}

static void msc_go_error(usbd_mass_storage *ms)
{
    ms->cache_cnt = 0;
    ms->cache_pos = 0;
    ms->block_cur = 0;
    ms->block_end = 0;

    ms->state = STATE_ERR;

    usbd_ep_stall_set(ms->usbd_dev, ms->ep_in, 1);
    usbd_ep_stall_set(ms->usbd_dev, ms->ep_out, 1);
}

static void msc_go_idle(usbd_mass_storage *ms)
{
    ms->cache_cnt = 0;
    ms->cache_pos = 0;
    ms->block_cur = 0;
    ms->block_end = 0;

    ms->state = STATE_IDLE;
}

static void msc_do_command(usbd_mass_storage *ms)
{
    int len = 0;

    if (msc_cbw_decode(ms)) {
        msc_go_error(ms);
        return;
    }

    switch (ms->cbwcb[0]) {
    case SCSI_SEND_DIAGNOSTIC:
    case SCSI_TEST_UNIT_READY:
        set_sbc_status_good(ms);
        len = 0;
        break;
    case SCSI_FORMAT_UNIT:
        len = scsi_format_unit(ms, ms->cache_buf);
        break;
    case SCSI_REQUEST_SENSE:
        len = scsi_request_sense(ms, ms->cache_buf);
        break;
    case SCSI_MODE_SENSE_6:
        len = scsi_mode_sense_6(ms, ms->cache_buf);
        break;
    case SCSI_INQUIRY:
        len = scsi_inquiry(ms, ms->cache_buf);
        break;
    case SCSI_READ_FORMAT_CAPACITIES:
        len = scsi_read_format_capacities(ms, ms->cache_buf);
        break;
    case SCSI_READ_CAPACITY:
        len = scsi_read_capacity(ms, ms->cache_buf);
        break;
    case SCSI_READ_10:
        len = scsi_read_10(ms, ms->cache_buf);
        break;
    case SCSI_WRITE_10:
        len = scsi_write_10(ms, ms->cache_buf);
        break;
    default:
        set_sbc_status_illegal(ms);
        len = -1;
        break;
    }

    if (len < 0) {
        msc_send_csw(ms);
        ms->state = STATE_CSW;
    } else {
        if (len) {
            ms->cache_pos = msc_send(ms, len, ms->cache_buf);
            ms->cache_cnt = len;
            ms->state = STATE_IN;
        } else {
            if (ms->cbwcb[0] == SCSI_WRITE_10) {
                ms->cache_pos = 0;
                ms->cache_cnt = 0;
                ms->state = STATE_OUT;
            } else {
                msc_send_csw(ms);
                ms->state = STATE_CSW;
            }
        }
    }
}

static void msc_do_recv(usbd_mass_storage *ms)
{
    if (ms->cache_cnt < BUF_LENGTH) {
        return;
    }

    ms->cache_cnt = 0;
    ms->cache_pos = 0;

    if (ms->block_cur < ms->block_end) {
        if (0 != ms->write_block(ms->block_cur, ms->cache_buf)) {
            msc_go_error(ms);
            return;
        } else {
            ms->block_cur++;
        }
    }

    if (ms->block_cur >= ms->block_end) {
        // Data phare complete
        msc_send_csw(ms);
        ms->state = STATE_CSW;
    }
}

static void msc_do_send(usbd_mass_storage *ms)
{
    if (ms->state == STATE_IN) {
        ms->block_cur++;
        if (ms->block_cur < ms->block_end) {
            if (0 == ms->read_block(ms->block_cur, ms->cache_buf)) {
                ms->cache_cnt = BUF_LENGTH;
                ms->cache_pos = 0;
            } else {
                msc_go_error(ms);
            }
        } else {
            // Data phare complete
            msc_cache_csw(ms);
            ms->state = STATE_CSW;
        }
        ms->cache_pos = msc_send(ms, ms->cache_cnt, ms->cache_buf);
    } else {
        msc_go_idle(ms);
    }
}

/* Handle the USB 'OUT' requests. */
static void msc_data_rx_cb(usbd_device *usbd_dev, uint8_t ep)
{
	usbd_mass_storage *ms = &_mass_storage;
	int len;
	void *p;

    if (ms->state != STATE_IDLE && ms->state != STATE_OUT) {
        msc_go_idle(ms);
        //msc_go_error(ms);
        return;
    }

    // Load data received from host to cache
    p = &ms->cache_buf[ms->cache_cnt];
    len = usbd_ep_read_packet(usbd_dev, ep, p, BUF_LENGTH - ms->cache_cnt);
    ms->cache_cnt += len;

    if (ms->state == STATE_IDLE) {
        msc_do_command(ms);
    } else {
        msc_do_recv(ms);
    }
}

/* Handle the USB 'IN' requests. */
static void msc_data_tx_cb(usbd_device *usbd_dev, uint8_t ep)
{
	usbd_mass_storage *ms = &_mass_storage;
	int len;

    (void) usbd_dev;
    (void) ep;

    /* Send cached data to host */
    len = ms->cache_cnt - ms->cache_pos;
    if (len > 0) {
        void *p = &ms->cache_buf[ms->cache_pos];

        len = msc_send(ms, len, p);
        ms->cache_pos += len;
    }

    if (ms->cache_pos >= ms->cache_cnt) {
        msc_do_send(ms);
    }
}

/* Handle various control requests related to the msc storage interface. */
static int msc_control_request(usbd_device *usbd_dev,
			       struct usb_setup_data *req, uint8_t **buf,
			       uint16_t *len,
			       usbd_control_complete_callback *complete)
{
	(void)complete;
	(void)usbd_dev;

	switch (req->bRequest) {
	case USB_MSC_REQ_BULK_ONLY_RESET:
		/* Do any special reset code here. */
		return USBD_REQ_HANDLED;
	case USB_MSC_REQ_GET_MAX_LUN:
		/* Return the number of LUNs.  We use 0. */
		*buf[0] = 0;
		*len = 1;
		return USBD_REQ_HANDLED;
	}

	return USBD_REQ_NOTSUPP;
}

static void msc_set_config(usbd_device *usbd_dev, uint16_t wValue)
{
	usbd_mass_storage *ms = &_mass_storage;

	(void)wValue;

	usbd_ep_setup(usbd_dev, ms->ep_in, USB_ENDPOINT_ATTR_BULK,
		      ms->ep_in_size, msc_data_tx_cb);
	usbd_ep_setup(usbd_dev, ms->ep_out, USB_ENDPOINT_ATTR_BULK,
		      ms->ep_out_size, msc_data_rx_cb);

	usbd_register_control_callback(
				usbd_dev,
				USB_REQ_TYPE_CLASS | USB_REQ_TYPE_INTERFACE,
				USB_REQ_TYPE_TYPE | USB_REQ_TYPE_RECIPIENT,
				msc_control_request);
}

usbd_mass_storage *usb_msc_init(usbd_device *usbd_dev,
				 uint8_t ep_in, uint8_t ep_in_size,
				 uint8_t ep_out, uint8_t ep_out_size,
				 const char *vendor_id,
				 const char *product_id,
				 const char *product_revision_level,
				 const uint32_t block_count,
				 int (*read_block)(uint32_t lba,
						   uint8_t *copy_to),
				 int (*write_block)(uint32_t lba,
						    const uint8_t *copy_from))
{
	_mass_storage.usbd_dev = usbd_dev;

	_mass_storage.ep_in = ep_in;
	_mass_storage.ep_in_size = ep_in_size;
	_mass_storage.ep_out = ep_out;
	_mass_storage.ep_out_size = ep_out_size;

	_mass_storage.vendor_id = vendor_id;
	_mass_storage.product_id = product_id;
	_mass_storage.product_revision_level = product_revision_level;

	_mass_storage.block_count = block_count;
	_mass_storage.read_block = read_block;
	_mass_storage.write_block = write_block;

    msc_go_idle(&_mass_storage);

	usbd_register_set_config_callback(usbd_dev, msc_set_config);

	return &_mass_storage;
}


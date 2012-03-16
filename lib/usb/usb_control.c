/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <stdlib.h>
#include <libopencm3/usb/usbd.h>
#include "usb_private.h"

static struct usb_control_state {
	enum {
		IDLE, STALLED,
		DATA_IN, LAST_DATA_IN, STATUS_IN,
		DATA_OUT, LAST_DATA_OUT, STATUS_OUT,
	} state;
	struct usb_setup_data req;
	u8 *ctrl_buf;
	u16 ctrl_len;
	void (*complete)(struct usb_setup_data *req);
} control_state;

/* Register application callback function for handling USB control requests. */
int usbd_register_control_callback(u8 type, u8 type_mask,
				   usbd_control_callback callback)
{
	int i;

	for (i = 0; i < MAX_USER_CONTROL_CALLBACK; i++) {
		if (_usbd_device.user_control_callback[i].cb)
			continue;

		_usbd_device.user_control_callback[i].type = type;
		_usbd_device.user_control_callback[i].type_mask = type_mask;
		_usbd_device.user_control_callback[i].cb = callback;
		return 0;
	}

	return -1;
}

static void usb_control_send_chunk(void)
{
	if (_usbd_device.desc->bMaxPacketSize0 < control_state.ctrl_len) {
		/* Data stage, normal transmission */
		usbd_ep_write_packet(0, control_state.ctrl_buf,
				     _usbd_device.desc->bMaxPacketSize0);
		control_state.state = DATA_IN;
		control_state.ctrl_buf += _usbd_device.desc->bMaxPacketSize0;
		control_state.ctrl_len -= _usbd_device.desc->bMaxPacketSize0;
	} else {
		/* Data stage, end of transmission */
		usbd_ep_write_packet(0, control_state.ctrl_buf,
				     control_state.ctrl_len);
		control_state.state = LAST_DATA_IN;
		control_state.ctrl_len = 0;
		control_state.ctrl_buf = NULL;
	}
}

static int usb_control_recv_chunk(void)
{
	u16 packetsize = MIN(_usbd_device.desc->bMaxPacketSize0,
			 control_state.req.wLength - control_state.ctrl_len);
	u16 size = usbd_ep_read_packet(0, control_state.ctrl_buf +
				       control_state.ctrl_len, packetsize);

	if (size != packetsize) {
		usbd_ep_stall_set(0, 1);
		return -1;
	}

	control_state.ctrl_len += size;

	return packetsize;
}

static int usb_control_request_dispatch(struct usb_setup_data *req)
{
	int i, result = 0;
	struct user_control_callback *cb = _usbd_device.user_control_callback;

	/* Call user command hook function. */
	for (i = 0; i < MAX_USER_CONTROL_CALLBACK; i++) {
		if (cb[i].cb == NULL)
			break;

		if ((req->bmRequestType & cb[i].type_mask) == cb[i].type) {
			result = cb[i].cb(req, &control_state.ctrl_buf,
					  &control_state.ctrl_len,
					  &control_state.complete);
			if (result)
				return result;
		}
	}

	/* Try standard request if not already handled. */
	return _usbd_standard_request(req, &control_state.ctrl_buf,
				      &control_state.ctrl_len);
}

/* Handle commands and read requests. */
static void usb_control_setup_read(struct usb_setup_data *req)
{
	control_state.ctrl_buf = _usbd_device.ctrl_buf;
	control_state.ctrl_len = req->wLength;

	if (usb_control_request_dispatch(req)) {
		if (control_state.ctrl_len) {
			/* Go to data out stage if handled. */
			usb_control_send_chunk();
		} else {
			/* Go to status stage if handled. */
			usbd_ep_write_packet(0, NULL, 0);
			control_state.state = STATUS_IN;
		}
	} else {
		/* Stall endpoint on failure. */
		usbd_ep_stall_set(0, 1);
	}
}

static void usb_control_setup_write(struct usb_setup_data *req)
{
	if (req->wLength > _usbd_device.ctrl_buf_len) {
		usbd_ep_stall_set(0, 1);
		return;
	}

	/* Buffer into which to write received data. */
	control_state.ctrl_buf = _usbd_device.ctrl_buf;
	control_state.ctrl_len = 0;
	/* Wait for DATA OUT stage. */
	if (req->wLength > _usbd_device.desc->bMaxPacketSize0)
		control_state.state = DATA_OUT;
	else
		control_state.state = LAST_DATA_OUT;
}

void _usbd_control_setup(u8 ea)
{
	struct usb_setup_data *req = &control_state.req;
	(void)ea;

	control_state.complete = NULL;

	if (usbd_ep_read_packet(0, req, 8) != 8) {
		usbd_ep_stall_set(0, 1);
		return;
	}

	if (req->wLength == 0) {
		usb_control_setup_read(req);
	} else if (req->bmRequestType & 0x80) {
		usb_control_setup_read(req);
	} else {
		usb_control_setup_write(req);
	}
}

void _usbd_control_out(u8 ea)
{
	(void)ea;

	switch (control_state.state) {
	case DATA_OUT:
		if (usb_control_recv_chunk() < 0)
			break;
		if ((control_state.req.wLength - control_state.ctrl_len) <=
		    _usbd_device.desc->bMaxPacketSize0)
			control_state.state = LAST_DATA_OUT;
		break;
	case LAST_DATA_OUT:
		if (usb_control_recv_chunk() < 0)
			break;
		/*
		 * We have now received the full data payload.
		 * Invoke callback to process.
		 */
		if (usb_control_request_dispatch(&control_state.req)) {
			/* Got to status stage on success. */
			usbd_ep_write_packet(0, NULL, 0);
			control_state.state = STATUS_IN;
		} else {
			usbd_ep_stall_set(0, 1);
		}
		break;
	case STATUS_OUT:
		usbd_ep_read_packet(0, NULL, 0);
		control_state.state = IDLE;
		if (control_state.complete)
			control_state.complete(&control_state.req);
		control_state.complete = NULL;
		break;
	default:
		usbd_ep_stall_set(0, 1);
	}
}

void _usbd_control_in(u8 ea)
{
	(void)ea;
	struct usb_setup_data *req = &control_state.req;

	switch (control_state.state) {
	case DATA_IN:
		usb_control_send_chunk();
		break;
	case LAST_DATA_IN:
		control_state.state = STATUS_OUT;
		break;
	case STATUS_IN:
		if (control_state.complete)
			control_state.complete(&control_state.req);

		/* Exception: Handle SET ADDRESS function here... */
		if ((req->bmRequestType == 0) &&
		    (req->bRequest == USB_REQ_SET_ADDRESS))
			_usbd_hw_set_address(req->wValue);
		control_state.state = IDLE;
		break;
	default:
		usbd_ep_stall_set(0, 1);
	}
}

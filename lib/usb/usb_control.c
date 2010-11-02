/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010  Gareth McMullin <gareth@blacksphere.co.nz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <usbd.h>
#include <stdlib.h>
#include "usb_private.h"

static struct usb_control_state {
	enum {  IDLE, STALLED,
		DATA_IN, LAST_DATA_IN, STATUS_IN, 
		DATA_OUT, LAST_DATA_OUT, STATUS_OUT
	} state;

	struct usb_setup_data req;

	uint8_t *ctrl_buf;
	uint16_t ctrl_len;

	void (*complete)(struct usb_setup_data *req);
} control_state;

/** Register application callback function for handling of usb control 
 * request with no data. */
void usbd_register_control_command_callback(
	int (*callback)(struct usb_setup_data *req,
			void (**complete)(struct usb_setup_data *req)))
{
	_usbd_device.user_callback_control_command = callback;
}

/** Register application callback function for handling of usb control 
 * request to read data. */
void usbd_register_control_read_callback(
	int (*callback)(struct usb_setup_data *req, uint8_t **buf, 
		uint16_t *len, void (**complete)(struct usb_setup_data *req)))
{
	_usbd_device.user_callback_control_read = callback;
}

/** Register application callback function for handling of usb control 
 * request with received data. */
void usbd_register_control_write_callback(
	int (*callback)(struct usb_setup_data *req, uint8_t *buf, uint16_t len,
				void (**complete)(struct usb_setup_data *req)))
{
	_usbd_device.user_callback_control_write = callback;
}

static void usb_control_send_chunk(void)
{
	if(_usbd_device.desc->bMaxPacketSize0 < control_state.ctrl_len) {
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
	uint16_t packetsize = MIN(_usbd_device.desc->bMaxPacketSize0, 
				control_state.req.wLength - 
				control_state.ctrl_len);
	uint16_t size = usbd_ep_read_packet(0, 
				control_state.ctrl_buf + control_state.ctrl_len,
				packetsize);

	if (size != packetsize) {
		usbd_ep_stall(0);
		return -1;
	}

	control_state.ctrl_len += size;

	return packetsize;
}

static void usb_control_setup_nodata(struct usb_setup_data *req)
{
	int result = 0;

	/* Call user command hook function */
	if(_usbd_device.user_callback_control_command)
		result = _usbd_device.user_callback_control_command(req,
						&control_state.complete);

	/* Try standard command if not already handled */
	if(!result) 
		result = _usbd_standard_request_command(req);
	
	if(result) {
		/* Go to status stage if handled */
		usbd_ep_write_packet(0, NULL, 0);
		control_state.state = STATUS_IN;
	} else  {
		/* Stall endpoint on failure */
		usbd_ep_stall(0);
	}
}

static void usb_control_setup_read(struct usb_setup_data *req)
{
	int result = 0;

	control_state.ctrl_buf = _usbd_device.ctrl_buf;
	control_state.ctrl_len = req->wLength;

	/* Call user command hook function */
	if(_usbd_device.user_callback_control_read)
		result = _usbd_device.user_callback_control_read(req, 
						&control_state.ctrl_buf, 
						&control_state.ctrl_len,
						&control_state.complete);

	/* Try standard request if not already handled */
	if(!result)
		result = _usbd_standard_request_read(req, 
					&control_state.ctrl_buf, 
					&control_state.ctrl_len);
	
	if(result) {
		/* Go to status stage if handled */
		usb_control_send_chunk();
	} else  {
		/* Stall endpoint on failure */
		usbd_ep_stall(0);
	}
}

static void usb_control_setup_write(struct usb_setup_data *req)
{
	if(req->wLength > _usbd_device.ctrl_buf_len) {
		usbd_ep_stall(0);
		return;
	}
	
	/* Buffer into which to write received data */
	control_state.ctrl_buf = _usbd_device.ctrl_buf;
	control_state.ctrl_len = 0;
	/* Wait for DATA OUT Stage */
	if(req->wLength > _usbd_device.desc->bMaxPacketSize0)
		control_state.state = DATA_OUT;
	else	control_state.state = LAST_DATA_OUT;
}

void _usbd_control_setup(uint8_t ea)
{
	struct usb_setup_data *req = &control_state.req;
	(void)ea;

	control_state.complete = NULL;

	if(usbd_ep_read_packet(0, req, 8) != 8) {
		usbd_ep_stall(0);
		return;
	}

	if(req->wLength == 0) {
		usb_control_setup_nodata(req);
	} else if(req->bmRequestType & 0x80) {
		usb_control_setup_read(req);
	} else {
		usb_control_setup_write(req);
	} 
}

void _usbd_control_out(uint8_t ea)
{
	(void)ea;

	switch(control_state.state) {
	    case DATA_OUT:
		if(usb_control_recv_chunk() < 0) break;
		if((control_state.req.wLength - control_state.ctrl_len) <= 
					_usbd_device.desc->bMaxPacketSize0)
			control_state.state = LAST_DATA_OUT;
		break;

	    case LAST_DATA_OUT: {
		int result = 0;

		if(usb_control_recv_chunk() < 0) break;
		/* We have now received the full data payload. 
		 * Invoke callback to process. 
		 */
		if(_usbd_device.user_callback_control_write)
			result = _usbd_device.user_callback_control_write(
						&control_state.req,
						control_state.ctrl_buf,
						control_state.ctrl_len,
						&control_state.complete);

		if(!result) 
			result = _usbd_standard_request_write(
						&control_state.req,
						control_state.ctrl_buf, 
						control_state.ctrl_len);

		if(result) {
			usbd_ep_write_packet(0, NULL, 0);
			control_state.state = STATUS_IN;
		} else {
			usbd_ep_stall(0);
		}

		break;
            }

	    case STATUS_OUT: {
		usbd_ep_read_packet(0, NULL, 0);
		control_state.state = IDLE;
		if (control_state.complete) 
			control_state.complete(&control_state.req);
		control_state.complete = NULL;
		break;
	    }

	    default:
		usbd_ep_stall(0);	
	}
}

void _usbd_control_in(uint8_t ea)
{
	(void)ea;
	switch(control_state.state) {
	    case DATA_IN:
		usb_control_send_chunk();
		break;

	    case LAST_DATA_IN:
		control_state.state = STATUS_OUT;
		break;

	    case STATUS_IN: {
		struct usb_setup_data *req = &control_state.req;

		if (control_state.complete) 
			control_state.complete(&control_state.req);

		/* Exception: Handle SET ADDRESS function here... */
		if((req->bmRequestType == 0) && 
		   (req->bRequest == USB_REQ_SET_ADDRESS)) 
			_usbd_hw_set_address(req->wValue);
		control_state.state = IDLE;
		break;
	    }

	    default:
		usbd_ep_stall(0);	
	}
}


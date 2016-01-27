/*
 * File:   trace.h
 * Author: karlp
 *
 * Created on November 21, 2013, 4:35 PM
 */

#ifndef TRACE_H
#define	TRACE_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

void trace_send_blocking8(int stimulus_port, char c);
void trace_send8(int stimulus_port, char c);

void trace_send_blocking16(int stimulus_port, uint16_t val);
void trace_send16(int stimulus_port, uint16_t val);

void trace_send_blocking32(int stimulus_port, uint32_t val);
void trace_send32(int stimulus_port, uint32_t val);


#ifdef	__cplusplus
}
#endif

#endif	/* TRACE_H */


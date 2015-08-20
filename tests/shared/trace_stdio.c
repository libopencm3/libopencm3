/*
 * support for stdio output to a trace port
 * Karl Palsson, 2014 <karlp@remake.is>
 */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#include "trace.h"

#ifndef STIMULUS_STDIO
#define STIMULUS_STDIO 0
#endif

int _write(int file, char *ptr, int len);
int _write(int file, char *ptr, int len)
{
	int i;

	if (file == STDOUT_FILENO || file == STDERR_FILENO) {
		for (i = 0; i < len; i++) {
			if (ptr[i] == '\n') {
				trace_send_blocking8(STIMULUS_STDIO, '\r');
			}
			trace_send_blocking8(STIMULUS_STDIO, ptr[i]);
		}
		return i;
	}
	errno = EIO;
	return -1;
}



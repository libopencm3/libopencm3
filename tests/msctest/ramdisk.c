/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Andrzej Surowiec <emeryth@gmail.com>
 * Copyright (C) 2013 Pavol Rusnak <stick@gk2.sk>
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

// 2021 : adapted from stm32f4discovery to use less ram, and allow OS to write sectors 0..3 (boot/fat/dir sector)

#include <string.h>
#include <stdio.h> // printf debug

#include "ramdisk.h"

#define WBVAL(x) ((x) & 0xFF), (((x) >> 8) & 0xFF)
#define QBVAL(x) ((x) & 0xFF), (((x) >> 8) & 0xFF),\
		 (((x) >> 16) & 0xFF), (((x) >> 24) & 0xFF)

// filesystem size is 512kB (1024 * SECTOR_SIZE)
#define SECTOR_COUNT		1024
#define SECTOR_SIZE		512
#define BYTES_PER_SECTOR	512
#define SECTORS_PER_CLUSTER	4
#define RESERVED_SECTORS	1
#define FAT_COPIES		2
#define ROOT_ENTRIES		512
#define ROOT_ENTRY_LENGTH	32
#define FILEDATA_START_CLUSTER	3
#define DATA_REGION_SECTOR	(RESERVED_SECTORS + FAT_COPIES + \
			(ROOT_ENTRIES * ROOT_ENTRY_LENGTH) / BYTES_PER_SECTOR)
#define FILEDATA_START_SECTOR	(DATA_REGION_SECTOR + \
			(FILEDATA_START_CLUSTER - 2) * SECTORS_PER_CLUSTER)

// filesize is 2kB (4 * SECTOR_SIZE)
#define FILEDATA_SECTOR_COUNT	4

const uint8_t BootSector[] = {
	0xEB, 0x3C, 0x90,					// code to jump to the bootstrap code
	'm', 'k', 'd', 'o', 's', 'f', 's', 0x00,		// OEM ID
	WBVAL(BYTES_PER_SECTOR),				// bytes per sector
	SECTORS_PER_CLUSTER,					// sectors per cluster
	WBVAL(RESERVED_SECTORS),				// # of reserved sectors (1 boot sector)
	FAT_COPIES,						// FAT copies (2)
	WBVAL(ROOT_ENTRIES),					// root entries (512)
	WBVAL(SECTOR_COUNT),					// total number of sectors
	0xF8,							// media descriptor (0xF8 = Fixed disk)
	0x01, 0x00,						// sectors per FAT (1)
	0x20, 0x00,						// sectors per track (32)
	0x40, 0x00,						// number of heads (64)
	0x00, 0x00, 0x00, 0x00,					// hidden sectors (0)
	0x00, 0x00, 0x00, 0x00,					// large number of sectors (0)
	0x00,							// drive number (0)
	0x00,							// reserved
	0x29,							// extended boot signature
	0x69, 0x17, 0xAD, 0x53,					// volume serial number
	'R', 'A', 'M', 'D', 'I', 'S', 'K', ' ', ' ', ' ', ' ',	// volume label
	'F', 'A', 'T', '1', '2', ' ', ' ', ' '			// filesystem type
};

const uint8_t FatSector[] = {
	0xF8, 0xFF, 0xFF, 0x00, 0x40, 0x00, 0x05, 0x60, 0x00, 0x07, 0x80, 0x00,
	0x09, 0xA0, 0x00, 0x0B, 0xC0, 0x00, 0x0D, 0xE0, 0x00, 0x0F, 0x00, 0x01,
	0x11, 0x20, 0x01, 0x13, 0x40, 0x01, 0x15, 0x60, 0x01, 0x17, 0x80, 0x01,
	0x19, 0xA0, 0x01, 0x1B, 0xC0, 0x01, 0x1D, 0xE0, 0x01, 0x1F, 0x00, 0x02,
	0x21, 0x20, 0x02, 0x23, 0x40, 0x02, 0x25, 0x60, 0x02, 0x27, 0x80, 0x02,
	0x29, 0xA0, 0x02, 0x2B, 0xC0, 0x02, 0x2D, 0xE0, 0x02, 0x2F, 0x00, 0x03,
	0x31, 0x20, 0x03, 0x33, 0x40, 0x03, 0x35, 0x60, 0x03, 0x37, 0x80, 0x03,
	0x39, 0xA0, 0x03, 0x3B, 0xC0, 0x03, 0x3D, 0xE0, 0x03, 0x3F, 0x00, 0x04,
	0x41, 0x20, 0x04, 0x43, 0x40, 0x04, 0x45, 0x60, 0x04, 0x47, 0x80, 0x04,
	0x49, 0xA0, 0x04, 0x4B, 0xC0, 0x04, 0x4D, 0xE0, 0x04, 0x4F, 0x00, 0x05,
	0x51, 0x20, 0x05, 0x53, 0x40, 0x05, 0x55, 0x60, 0x05, 0x57, 0x80, 0x05,
	0x59, 0xA0, 0x05, 0x5B, 0xC0, 0x05, 0x5D, 0xE0, 0x05, 0x5F, 0x00, 0x06,
	0x61, 0x20, 0x06, 0x63, 0x40, 0x06, 0x65, 0x60, 0x06, 0x67, 0x80, 0x06,
	0x69, 0xA0, 0x06, 0x6B, 0xC0, 0x06, 0x6D, 0xE0, 0x06, 0x6F, 0x00, 0x07,
	0x71, 0x20, 0x07, 0x73, 0x40, 0x07, 0x75, 0x60, 0x07, 0x77, 0x80, 0x07,
	0x79, 0xA0, 0x07, 0x7B, 0xC0, 0x07, 0x7D, 0xE0, 0x07, 0x7F, 0x00, 0x08,
	0x81, 0x20, 0x08, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00
};

const uint8_t DirSector[] = {
	// long filename entry
	0x41,									// sequence number
	WBVAL('r'), WBVAL('a'), WBVAL('m'), WBVAL('d'), WBVAL('i'),		// five name characters in UTF-16
	0x0F,									// attributes
	0x00,									// type
	0x00,									// checksum of DOS filename (computed in ramdisk_init)
	WBVAL('s'), WBVAL('k'), WBVAL('.'), WBVAL('d'), WBVAL('a'), WBVAL('t'),	// six name characters in UTF-16
	0x00, 0x00,								// first cluster
	WBVAL(0), WBVAL(0),							// two name characters in UTF-16
	// actual entry
	'R', 'A', 'M', 'D', 'I', 'S', 'K', ' ',					// filename
	'D', 'A', 'T',								// extension
	0x20,									// attribute byte
	0x00,									// reserved for Windows NT
	0x00,									// creation millisecond
	0xCE, 0x01,								// creation time
	0x86, 0x41,								// creation date
	0x86, 0x41,								// last access date
	0x00, 0x00,								// reserved for FAT32
	0xCE, 0x01,								// last write time
	0x86, 0x41,								// last write date
	WBVAL(FILEDATA_START_CLUSTER),						// start cluster
	QBVAL(FILEDATA_SECTOR_COUNT * SECTOR_SIZE)				// file size in bytes
};

static uint8_t bootsectors[4*SECTOR_SIZE]; // laat os schrijven
static uint8_t ramdata[FILEDATA_SECTOR_COUNT * SECTOR_SIZE];

int ramdisk_init(void)
{
	uint32_t i = 0;

	for (i=0;i<sizeof(BootSector);i++) {
		bootsectors[i] = BootSector[i];
	}
	bootsectors[SECTOR_SIZE - 2] = 0x55;
	bootsectors[SECTOR_SIZE - 1] = 0xAA;

	for (i=0;i<sizeof(FatSector);i++) {
		bootsectors[i+SECTOR_SIZE] = FatSector[i];
		bootsectors[i+2*SECTOR_SIZE] = FatSector[i];
	}
	for (i=0;i<sizeof(DirSector);i++) {
		bootsectors[i+3*SECTOR_SIZE] = DirSector[i];
	}

	// compute checksum in the directory entry
	uint8_t chk = 0;
	for (i = 32; i < 43; i++) {
		chk = (((chk & 1) << 7) | ((chk & 0xFE) >> 1)) + DirSector[i];
	}

	//DirSector[13] = chk;
	bootsectors[13+3*SECTOR_SIZE] = chk;

	// fill ramdata
	const uint8_t text[] = "USB Mass Storage Class example. ";
	i = 0;
	while (i < sizeof(ramdata)) {
		ramdata[i] = text[i % (sizeof(text) -1)];
		i++;
	}
	return 0;
}

int ramdisk_read(uint32_t lba, uint8_t *copy_to)
{
	// printf("R LBA=%ld\n",lba);

	memset(copy_to, 0, SECTOR_SIZE);
	switch (lba) {
		case 0:
		case 1:
		case 2:
		case 3:
			// read from bootsectors[]
			memcpy(copy_to, &bootsectors[lba*SECTOR_SIZE],SECTOR_SIZE);
			break;
		/*
		case 0: // sector 0 is the boot sector
			memcpy(copy_to, BootSector, sizeof(BootSector));
			copy_to[SECTOR_SIZE - 2] = 0x55;
			copy_to[SECTOR_SIZE - 1] = 0xAA;
			break;
		case 1: // sector 1 is FAT 1st copy
		case 2: // sector 2 is FAT 2nd copy
			memcpy(copy_to, FatSector, sizeof(FatSector));
			break;
		case 3: // sector 3 is the directory entry
			memcpy(copy_to, DirSector, sizeof(DirSector));
			break;
		*/
		default:
			// ignore reads outside of the data section
			if (lba >= FILEDATA_START_SECTOR && lba < FILEDATA_START_SECTOR + FILEDATA_SECTOR_COUNT) {
				memcpy(copy_to, ramdata + (lba - FILEDATA_START_SECTOR) * SECTOR_SIZE, SECTOR_SIZE);
			}
			break;
	}
	return 0;
}

int ramdisk_write(uint32_t lba, const uint8_t *copy_from)
{
	printf("W LBA=%ld\n",lba);

	switch (lba) {
		case 0:
		case 1:
		case 2:
		case 3:
			// write to bootsectors[]
			memcpy(&bootsectors[lba*SECTOR_SIZE],copy_from, SECTOR_SIZE);
			break;
		default:
			printf("not updating file data for now \n");
			break;
	}
	return 0;
}

int ramdisk_blocks(void)
{
	return SECTOR_COUNT;
}

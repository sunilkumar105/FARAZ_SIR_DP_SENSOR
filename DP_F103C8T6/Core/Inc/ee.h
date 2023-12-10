#ifndef __EEPROM_H
#define __EEPROM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "main.h"

#define   PAGE                  0
#define   SECTOR                1
#define   PAGE_NUM              2

#define   _EE_USE_FLASH_PAGE_NUM_OR_SECTOR_NUM      (5)  //PAGE OR SECTOR TO BE USED
#define   _EE_USE_RAM_BYTE                          (1024) //first we write data into the intrnal buffer, then we tell the program to commit data to the flash
#define   _EE_VOLTAGE                                FLASH_VOLTAGE_RANGE_3
#define _EE_ADDR_INUSE ((uint32_t)0x08007C00)
#define F103X8T6

	bool ee_write(uint32_t Address_To_Write, uint8_t *data, uint32_t len);
	bool ee_read(uint32_t Address_To_Read, uint8_t *data, uint32_t len);
	bool ee_format_sector();

#ifdef __cplusplus
}
#endif

#endif

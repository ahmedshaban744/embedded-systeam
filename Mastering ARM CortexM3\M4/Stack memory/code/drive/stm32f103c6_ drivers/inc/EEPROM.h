/*
 * EEPROM.h
 *
 *  Created on: Oct 4, 2023
 *      Author: Ahmed shaban
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include "stm32f103c6_I2C_drivers.h"

#define  E2PROM_salve_address 0x2A

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//                                        APIS Supported
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
void Hall_E2PROM_INIT(void);
uint8_t Hall_E2PROM_Write_NBYTE(uint32_t memory_address,uint8_t* data,uint8_t lenght);
uint8_t Hall_E2PROM_read_NBYTE(uint32_t memory_address,uint8_t* data,uint8_t lenght);
#endif /* EEPROM_H_ */

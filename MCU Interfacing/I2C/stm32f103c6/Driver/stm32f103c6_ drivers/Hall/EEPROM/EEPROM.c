/*
 * EEPROM.c
 *
 *  Created on: Oct 4, 2023
 *      Author: Ahmed shaban
 */
#include "EEPROM.h"
void Hall_E2PROM_INIT(void)
{

	I2C_config I2C_define;
	I2C_define.I2C_broadcast=I2C_broadcast_enable;
	I2C_define.clock_speed=I2C_clock_speed_SM_100KHZ;
	I2C_define.I2C_Acknowledge=I2C_Acknowledge_enable;
	I2C_define.mode=I2C_mode_I2C;
	I2C_define.clock_stretching=I2C_clock_stretching_enable;
    I2C_define.p_salve_event_callback=NULL;
    MCAL_I2C_GPIO_SET_PINS(I2C1);
    MCAL_I2C_Init(I2C1, &I2C_define);


}
uint8_t Hall_E2PROM_Write_NBYTE(uint32_t memory_address,uint8_t* data,uint8_t lenght)
{
	uint8_t bufffer[256];
	bufffer[0]=(memory_address>>8);
	bufffer[1]=(memory_address);
	for(uint8_t i =2 ;i<lenght+2 ;i++)
	{
		bufffer[i]=data[i-2];
	}

MCAL_I2C_Master_TX(I2C1, E2PROM_salve_address, bufffer, lenght+2, with_stop, start);

return 0;
}

uint8_t Hall_E2PROM_read_NBYTE(uint32_t memory_address,uint8_t* data,uint8_t lenght)
{
	uint8_t bufffer[2];
	bufffer[0]=(memory_address>>8);
	bufffer[1]=(memory_address);
	MCAL_I2C_Master_TX(I2C1, E2PROM_salve_address,bufffer, 2, with_stop, start);
	MCAL_I2C_Master_RX(I2C1, E2PROM_salve_address, data,lenght, with_stop,start);
	return 0;

}


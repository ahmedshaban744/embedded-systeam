/*
 * stm32f103c6_I2C_drivers.h
 *
 *  Created on: Sep 22, 2023
 *      Author:Ahmed Shaban
 */

#ifndef INC_STM32F103C6_I2C_DRIVERS_H_
#define INC_STM32F103C6_I2C_DRIVERS_H_

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//                                            includes
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#include "stm32f103x6.h"
#include "stm32f103c6_GPIO_drivers.h"
#include  "stm32f103c6_RCC_drivers.h"

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//                                    configration structure
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
struct I2C_SLAVE_address{
	uint16_t  Dual_addressing_mode;     //  0:Only OAR1 is recognized in 7-bit addressing mode
	                                   //   1: Both OAR1 and OAR2 are recognized in 7-bit addressing mode
    uint16_t I2C_Interface_address1 ;
    uint16_t I2C_Interface_address2 ;
    uint32_t I2C_addrssing_mode ;      //thies parameter must be set base on @I2C_addrssing_mode
};

//========================================================================================
 typedef enum
 {
	 I2C_Address_matched,
	 I2C_STOP_received,
	 I2C_bus_error,
	 I2C_Acknowledge_failure,
	 I2C_Slave_send_data,
	 I2C_Slave_resive_data
 }slave_stutus;

 typedef enum
 {
with_stop,
without_stop
 }stop_condation;

 typedef enum
 {
start,
repeted_start
 }Repeted_start;

 typedef enum
 {
	 fun_disable = 0,
     fun_enable = 1

 }fun_state;

 typedef enum
 {
reset=0,
set =1
 }flage_state;
#define I2C_Event_Master_Byte_Tramsmetting  ((uint32_t)0x00070080)
 typedef enum
 {
	 I2C_BUS_BUSY =0 ,
	 EV5          =1   ,       //EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address
	 EV6          =2   ,       // ADDR=1, cleared by reading SR1 register followed by reading SR2
	 EV8          =3   ,       // TxE=1, shift register not empty, d. ata register empty, cleared by writing DR register
	 EV8_2        =4   ,       // TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition
	 EV7          =5   ,       //Rxne =1 Cleared by reading DRregister
	 Master_Byte_Tramsmetting= ((uint32_t)0x00070080),


 }stutes;

 typedef enum
 {
I2C_Master_trensmetter=0,
I2C_Master_resever=1
 }I2C_direction;
 //========================================================================================

typedef struct
{
	uint32_t                  clock_speed;          //thies parameter must be set base on @I2C_clock_speed_define
	uint32_t                  clock_stretching;    //thies parameter must be set base on @I2C_clock_ stretching_define
	uint32_t                  mode;               //thies parameter must be set base on @I2C_mode_defin
	struct I2C_SLAVE_address  I2C_device_address;
	uint32_t                  I2C_Acknowledge;     //thies parameter must be set base on @I2C_Acknowledge_defin
	uint32_t                   I2C_broadcast;      //thies parameter must be set base on @I2C_I2C_broadcast_defin
void(*p_salve_event_callback)(slave_stutus state);
}I2C_config;
//========================================================================================





//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Refrance Macro
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//@I2C_clock_speed_define

#define  I2C_clock_speed_SM_10KHZ      (10000U)
#define  I2C_clock_speed_SM_20KHZ      (20000U)
#define  I2C_clock_speed_SM_30KHZ      (30000U)
#define  I2C_clock_speed_SM_40KHZ      (40000U)
#define  I2C_clock_speed_SM_50KHZ      (50000U)
#define  I2C_clock_speed_SM_60KHZ      (60000U)
#define  I2C_clock_speed_SM_70KHZ      (70000U)
#define  I2C_clock_speed_SM_80KHZ      (80000U)
#define  I2C_clock_speed_SM_90KHZ      (90000U)
#define  I2C_clock_speed_SM_100KHZ     (100000U)
#define  I2C_clock_speed_FM_200KHZ     (200000U)
#define  I2C_clock_speed_FM_400KHZ     (400000U)
//========================================================================================
//@I2C_clock_stretching_define
//Clock stretching disable (Slave mode)
//This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
//it is reset by software.
//0: Clock stretching enabled
//1: Clock stretching disabled
#define I2C_clock_stretching_enable     (00000000UL)
#define I2C_clock_stretching_disable     (I2C_CR1_NOSTRETCH)
//========================================================================================
//@I2C_mode_defin
//Bit 3 SMBTYPE: SMBus type
//0: SMBus Device
//1: SMBus Host
#define I2C_mode_I2C                      (00000000UL)
#define I2C_mode_SMBUS                    (I2C_CR1_SMBTYPE)
//========================================================================================
//@I2C_addrssing_mode
//Bit 15 ADDMODE Addressing mode (slave mode)
//0: 7-bit slave address (10-bit address not acknowledged)
//1: 10-bit slave address (7-bit address not acknowledged)
#define I2C_addrssing_mode7_bit                       (00000000UL)
#define I2C_addrssing_mode10_bit                      (I2C_OAR1_ADDMODE)
//========================================================================================
//@I2C_Acknowledge_defin
#define I2C_Acknowledge_enable      (I2C_CR1_ACK)
#define I2C_Acknowledge_disable     (0)
//========================================================================================
//@I2C_I2C_broadcast_defin
//Bit 6 ENGC: General call enable
//0: General call disabled. Address 00h is NACKed.
//1: General call enabled. Address 00h is ACKed.
#define I2C_broadcast_enable       (I2C_CR1_ENGC)
#define I2C_broadcast_disable       (0)
//========================================================================================


//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//                                        APIS Supported
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
void MCAL_I2C_Init(I2C_typedef* I2CX,I2C_config*I2C_define);
void MCAL_I2C_Deinit(I2C_typedef* I2CX,I2C_config*I2C_define);
void MCAL_I2C_Master_TX(I2C_typedef* I2CX , uint16_t device_address, uint8_t*biffer, uint32_t lenth, stop_condation stop, Repeted_start repet );
void MCAL_I2C_Master_RX(I2C_typedef* I2CX , uint16_t device_address, uint8_t*biffer, uint32_t lenth, stop_condation stop, Repeted_start repet );
void MCAL_I2C_GPIO_SET_PINS(I2C_typedef* I2CX) ;


//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//                                       local APIS
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-



void  I2C_generate_start(I2C_typedef* I2CX , Repeted_start repet ,fun_state new_state);
void I2C_send_address(I2C_typedef* I2CX  , uint16_t device_address ,I2C_direction );
void  I2C_generate_stop(I2C_typedef* I2CX ,fun_state state );
void  I2C_AcknowledgeConfig(I2C_typedef* I2CX ,fun_state state );
flage_state I2C_flag_state(I2C_typedef* I2CX , stutes flag);



#endif /* INC_STM32F103C6_I2C_DRIVERS_H_ */

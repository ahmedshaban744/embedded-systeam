/*
 * stm32f103c6_SPI_drivers.h
 *
 *  Created on: Sep 9, 2023
 *      Author: Ahmed shaban
 */

#ifndef INC_STM32F103C6_SPI_DRIVERS_H_
#define INC_STM32F103C6_SPI_DRIVERS_H_

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//includes
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#include "stm32f103x6.h"
#include "stm32f103c6_GPIO_drivers.h"
#include "stdint.h"

struct intrput_src
{ uint8_t RXNE:1;
uint8_t   TXE:1;
uint8_t   CHSIDE:1;
uint8_t   UDR:1;
uint8_t   CRCERR:1;
uint8_t   MODF:1;
uint8_t   OVR:1;
uint8_t   BSY:1;
	};
enum polling_MC
{SPI_enable,SPI_disable} ;
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//configration structure
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
typedef struct
{
	uint16_t direcation;              //specifies the SPI comuncation direcation
                                      //this parameter can be a value of @SPI_direcation_define

    uint16_t device_mode ;          //specifies the device mode master or slave
                                   //this parameter can be a value of @SPI_device_mode_define
    uint16_t data_size;              //specifies the data size
                                     //this parameter can be a value of @SPI_data_sizee_define
	 uint16_t fram_format;      //specifies the data shap during communcation MSB or LSB first
                               //this parameter can be a value of @SPI_fram_format_define

	uint16_t clock_polarity;    //specifies the clock shap at the idle stat
                               //this parameter can be a value of @SPI_clock_polarity_define

	uint16_t clock_phase;   //specifies the clock phase (send and resived data at rising or falling edge)
                           //this parameter can be a value of @SPI_clock_phase_define

	uint16_t IRQ_enable;             //OPEN OR CLOSE THE INTERRPUT
                             //this parameter can be a value of @SPI_IRQ_define
	uint16_t NSS;        //slave select state
                         //this parameter can be a value of @SPI_NSS_define
	uint16_t Boud_rate;     //specifies the rate of communcation the max value is Frequency/2
                           //this parameter can be a value of @SPI_Boud_rate_define
void(*p_IQR_callback)(struct intrput_src  src );
}SPI_confog_t;

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//Macros
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//@SPI_direcation_define
#define  SPI_full_duplex       (uint16_t)(0)                 //register SPI_CR1 bit 15 and bit 10
#define  SPI_half_dublex       (uint16_t) (1<<10)           //register SPI_CR1 bit 15 and bit 10
#define  SPI_simplex_send      ((uint16_t)(1<<15|1<<14))   //register SPI_CR1 bit 15 and bit 14
#define  SPI_simplex_resive    (uint16_t)(1<<15)          //register SPI_CR1 bit 15 and bit 14
//============================================================================================
//@SPI_device_mode_define
#define  SPI_Master_mode    (uint16_t)(1<<2 )   //register SPI_CR1 bit 15 and bit 2
#define  SPI_slave_mode    (uint16_t)(0 )      //register SPI_CR1 bit 15 and bit 2
//============================================================================================

//@SPI_data_sizee_define
#define   SPI_data_size_8_bit    (uint16_t)(0)              //register SPI_CR1 bit 15 and bit 11
#define   SPI_data_size_16_bit    (uint16_t)(1<<11 )       //register SPI_CR1 bit 15 and bit 11
//============================================================================================

//@SPI_fram_format_define
#define   SPI_MSB_first    (uint16_t)(0)               //register SPI_CR1 bit 15 and bit 7
#define   SPI_LSB_first    (uint16_t)(1<< 7)          //register SPI_CR1 bit 15 and bit 7
//============================================================================================

//@SPI_clock_polarity_define
#define   SPI_low_at_idil_state     (uint16_t)(0)         //register SPI_CR1 bit 15 and bit 1
#define   SPI_high_at_idil_state    (uint16_t)(1<<1)      //register SPI_CR1 bit 15 and bit 1
//============================================================================================

//@SPI_clock_phase_define
#define  SPI_first_edge_sampling     (uint16_t)(0)        //register SPI_CR1 bit 15 and bit 0
#define  SPI_second_edge_sampling    (uint16_t)(1<<0)    //register SPI_CR1 bit 15 and bit 0
//============================================================================================

// @SPI_IRQ_define
#define   SPI_interrput_enable     (uint16_t)(0)       //register SPI_CR1 bit 15 and bit 0
#define   SPI_interrput_disable    (uint16_t)(1<<0)   //register SPI_CR1 bit 15 and bit 0
//============================================================================================

//@SPI_NSS_define
//hardware
#define  SPI_NSS_hardware_slave_mode                 (uint16_t)(1<<0)  //register SPI_CR1 bit 15 and bit 9
#define  SPI_NSS_hardware_master_mode_output_enable  (uint16_t)(1<<2) //register SPI_CR1 bit 15 and bit2
#define  SPI_NSS_hardware_master_mode_output_disable (uint16_t)~(1<<2)   //register SPI_CR1 bit 15 and bit2
//software
#define  SPI_NSS_software_enable                   ((uint16_t)(1<<8|1<<9)) //register SPI_CR1 bit 9 and bit 8
#define  SPI_NSS_software_disable                   (uint16_t)(1<<9)      //register SPI_CR1 bit 9 and bit 8
//============================================================================================

//@SPI_Boud_rate_define
#define  SPI_boud_rate_prescaler2       (uint16_t)(0b000U<<3) //register SPI_CR1 bit 9 and bit 3<<5
#define  SPI_boud_rate_prescaler4       (uint16_t)(0b001U<<3) //register SPI_CR1 bit 9 and bit 3<<5
#define  SPI_boud_rate_prescaler8       (uint16_t)(0b010U<<3) //register SPI_CR1 bit 9 and bit 3<<5
#define  SPI_boud_rate_prescaler16      (uint16_t)(0b011U<<3) //register SPI_CR1 bit 9 and bit 3<<5
#define  SPI_boud_rate_prescaler32      (uint16_t)(0b100U<<3) //register SPI_CR1 bit 9 and bit 3<<5
#define  SPI_boud_rate_prescaler64      (uint16_t)(0b101U<<3) //register SPI_CR1 bit 9 and bit 3<<5
#define  SPI_boud_rate_prescaler128     (uint16_t)(0b110U<<3) //register SPI_CR1 bit 9 and bit 3<<5
#define  SPI_boud_rate_prescaler256     (uint16_t)(0b111U<<3) //register SPI_CR1 bit 9 and bit 3<<5
//============================================================================================

//@SPI_IRQ_define
#define  SPI_IRQ_none                  (uint16_t)(0)//register SPI_CR2
#define  SPI_IRQ_TXEIE_enable          (uint16_t)(1<<7)//register SPI_CR2 bit 7
#define  SPI_IRQ_RXNEIE_enable         (uint16_t)(1<<6)//register SPI_CR2 bit 6
#define  SPI_IRQ_ERRIE_enable          (uint16_t)(1<<5)//register SPI_CR2 bit 5
//============================================================================================

//============================================================================================
//======================================APIS==================================================
//============================================================================================

void MCAL_SPI_INIT(SPI_typedef *SPIX,SPI_confog_t* SPI_define);
void MCAL_SPI_DEINIT(SPI_typedef* SPIX);
void MCAL_SPI_GPIO_SET_PINS(SPI_typedef* SPIX);
void MCAL_SPI_TX(SPI_typedef *SPIX,uint16_t *buffer,enum polling_MC polling);
void  MCAL_SPI_RX(SPI_typedef *SPIX,uint16_t *buffer,enum polling_MC polling);
void  MCAL_SPI_TX_RX(SPI_typedef *SPIX,uint16_t *buffer,enum polling_MC polling);


#endif /* INC_STM32F103C6_SPI_DRIVERS_H_ */

/*
 * stm32f103c6_I2C_drivers.c
 *
 *  Created on: Sep 22, 2023
 *      Author: Ahmed Shaban
 */

#include "stm32f103c6_I2C_drivers.h"

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//                          GLOBAL VARABLE
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-

I2C_config GP_I2C[2] = {NULL , NULL};


//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//                          GLOBAL Macres
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#define  I2C_index1      0
#define  I2C_index2      1
/**================================================================
 * @Fn                   -  MCAL_I2C_Init
 * @brief                -initialize the I2C
 * @param [in]           -I2CX   to select the I2C pripher
 * @param [IN]           -I2C_define is apointer to the I2C_config struture that contains  all
                        -//configration information
 * @retval               - null
 * Note                  -in STM32F103c6 mcu has I2C1 and I2C2
 */
void MCAL_I2C_Init(I2C_typedef* I2CX,I2C_config*I2C_define)
{
	uint16_t tempreg=0;
	uint16_t frequenc=0;
	uint32_t pclk=8000000;
	uint16_t   result=0;
	if(I2CX==I2C1)
	{
		I2C1_clock_enable();
		GP_I2C[I2C_index1]=*I2C_define;
	}
	else if(I2CX==I2C2)
	{
		I2C2_clock_enable();
		GP_I2C[I2C_index2]=*I2C_define;
	}
	if(I2C_define->mode==I2C_mode_I2C)
	{
		//=================Timing init==============

		tempreg=I2CX->I2C_CR2;
		//clear frequency
		tempreg &=~(I2C_CR2_FREQ_Msk);
		//read pclok1 from RCC driver
		pclk=MCAL_RCC_Get_PClock1_clock();
		frequenc=(uint16_t)(pclk/1000000);
		tempreg |= frequenc;
		I2CX->I2C_CR2=tempreg;
		//Configure the clock control registers
		//in master mode, Bit 0 PE: Peripheral enable must not be reset before the end of the communication.
		I2CX->I2C_CR1 &=~(I2C_CR1_PE);
		tempreg =0;
		if(I2C_define->clock_speed==I2C_clock_speed_SM_10KHZ||I2C_clock_speed_SM_20KHZ||I2C_clock_speed_SM_30KHZ||I2C_clock_speed_SM_40KHZ||I2C_clock_speed_SM_50KHZ||I2C_clock_speed_SM_60KHZ||I2C_clock_speed_SM_70KHZ||I2C_clock_speed_SM_80KHZ||I2C_clock_speed_SM_90KHZ||I2C_clock_speed_SM_100KHZ)
		{
			//    	 Bit 15 F/S: I2C master mode selection
			//    	 0: Sm mode I2C
			//    	 1: Fm mode I2C
			tempreg&=~(1<<15);
			//    	 Bits 11:0 CCR[11:0]: Clock control register in Fm/Sm mode (Master mode)
			//    	 Controls the SCL clock in master mode.
			//    	 Sm mode or SMBus:
			//    	 Thigh = CCR * TPCLK1
			//    	 Tlow = CCR * TPCLK1
			//       CCR=F_PCLOK/2*I2C_F_CLOCK
			result =(uint16_t)(pclk/ (2*I2C_define->clock_speed));
			tempreg|=result;
			I2CX->I2C_CCR =tempreg;
			//RISE TIME
			I2CX->I2C_TRISE =frequenc+1;


		}
		else
		{
			//    	 Bit 15 F/S: I2C master mode selection
			//    	 0: Sm mode I2C
			//    	 1: Fm mode I2C
			tempreg|=(1<<15);
			//    	Bit 14 DUTY: Fm mode duty cycle
			//    	   	0: Fm mode tlow/thigh = 2
			//    	   	1: Fm mode tlow/thigh = 16/9 (see CCR)

			tempreg &=~(1<<14);

			//			Fm mode:
			//			If DUTY = 0:
			//			Thigh = CCR * TPCLK1
			//			Tlow = 2 * CCR * TPCLK1

			result =(uint16_t)(pclk/ (3*I2C_define->clock_speed));
			tempreg|=result;
			I2CX->I2C_CCR =tempreg;
			//RISE TIME
			I2CX->I2C_TRISE =frequenc+1;



		}
		//==============I2C_CR1==================
		tempreg=0;
		tempreg=I2CX->I2C_CR1;
		tempreg|=(I2C_define->I2C_Acknowledge|I2C_define->clock_stretching|I2C_define->I2C_broadcast|I2C_define->mode);
		I2CX->I2C_CR1 =tempreg;
		//============addressinf=g in slave mood==============
		tempreg=0;
		if(I2C_define->I2C_device_address.Dual_addressing_mode==1)
		{
			tempreg=I2C_OAR2_ENDUAL;
			tempreg|=I2C_define->I2C_device_address.I2C_Interface_address2 <<I2C_OAR2_ADD2_Pos;
			I2CX->I2C_OAR2 |=tempreg;
		}
		tempreg=0;
		tempreg|=I2C_define->I2C_device_address.I2C_Interface_address1 <<1;
		tempreg|=I2C_define->I2C_device_address.I2C_addrssing_mode;
		I2CX->I2C_OAR1 |=tempreg;
	}
	else if(I2C_define->mode==I2C_mode_SMBUS)
	{
		// to do

	}
	//Interrput mode  (slave mode ) _________ check callback pointer
	if(I2C_define->p_salve_event_callback!= NULL)
	{
		I2CX->I2C_CR2 |= (I2C_CR2_ITEVTEN);
		I2CX->I2C_CR2 |= (I2C_CR2_ITERREN);
		I2CX->I2C_CR2 |= (I2C_CR2_ITBUFEN);
	}
	if(I2CX==I2C1)
	{
		NVIC_IRQ31_I2C1_EV_enable()    ;
		NVIC_IRQ32_I2C1_ER_enable()    ;
	}
	else if(I2CX==I2C2)
	{
		NVIC_IRQ33_I2C2_EV_enable() ;
		NVIC_IRQ34_I2C2_ER_enable()  ;
	}
	I2CX->I2C_SR1=0;
	I2CX->I2C_SR2=0;

	//ensable iw=2c peripheral
	I2CX->I2C_CR1 |=I2C_CR1_PE ;
}
/**================================================================
 * @Fn                   -  MCAL_I2C_Deinit
 * @brief                -deinitialize the I2C
 * @param [in]           -I2CX   to select the I2C peripheral
 * @param [IN]           -I2C_define is apointer to the I2C_config struture that contains  all
                        -//configration information
 * @retval               - null
 * Note                  -in STM32F103c6 mcu has I2C1 and I2C2
 */
void MCAL_I2C_Deinit(I2C_typedef* I2CX,I2C_config*I2C_define)
{

	if(I2CX==I2C1)
	{
		NVIC_IRQ31_I2C1_EV_disable()    ;
		NVIC_IRQ32_I2C1_ER_disable()    ;
		I2C1_clock_RESET() ;
	}
	else if(I2CX==I2C2)
	{
		NVIC_IRQ33_I2C2_EV_disable() ;
		NVIC_IRQ34_I2C2_ER_disable()  ;
		I2C2_clock_RESET();
	}



}
/**================================================================
 * @Fn                   -  MCAL_I2C_GPIO_SET_PINS
 * @brief                -configuer  I2C pins
 * @param [in]           -I2CX   to select the I2C peripheral
 * @retval               - null
 * Note                  -in STM32F103c6 mcu has I2C1 and I2C2
 */
void MCAL_I2C_GPIO_SET_PINS(I2C_typedef* I2CX)
{
	GPIO_pinconfig_t pin_define;

	if(I2CX==I2C1)

	{
		//I2C1_SCL  PB6     Alternate function open drain
		//I2C1_SDA  PB7     Alternate function open drain

		pin_define.gpio_pin_number =GPIO_PIN_6;
		pin_define.GPIO_MODE=GPIO_MODE_OUTPUT_AF_OD;
		pin_define.GPIO_OUTPUT_SPEED= GPIO_SPEED_10MHZ;
		MCAL_GPIO_INIT(GPIOB, &pin_define);

		pin_define.gpio_pin_number =GPIO_PIN_7;
		pin_define.GPIO_MODE=GPIO_MODE_OUTPUT_AF_OD;
		pin_define.GPIO_OUTPUT_SPEED= GPIO_SPEED_10MHZ;
		MCAL_GPIO_INIT(GPIOB, &pin_define);

	}
	else if(I2CX==I2C2)
	{
		//I2C2_SCL  PB10    Alternate function open drain
		//I2C1_SDA  PB11    Alternate function open drain

		pin_define.gpio_pin_number =GPIO_PIN_10;
		pin_define.GPIO_MODE=GPIO_MODE_OUTPUT_AF_OD;
		pin_define.GPIO_OUTPUT_SPEED= GPIO_SPEED_10MHZ;
		MCAL_GPIO_INIT(GPIOB, &pin_define);

		pin_define.gpio_pin_number =GPIO_PIN_11;
		pin_define.GPIO_MODE=GPIO_MODE_OUTPUT_AF_OD;
		pin_define.GPIO_OUTPUT_SPEED= GPIO_SPEED_10MHZ;
		MCAL_GPIO_INIT(GPIOB, &pin_define);
	}







}
/**================================================================
 * @Fn                     -  MCAL_I2C_Master_TX
 * @brief                  -master send data
 * @param [in]            -I2CX   to select the I2C peripheral
 * @param [in]            -device_address   to select the slave address to send data
 * @param [in]            -biffer   the data want to send
 * @param [in]           -lenth   the data lengh
 * @param [in]           -stop   enable stop cindation after send or  not
 * @param [in]           -repet   resned anther data or not
 * @retval               - null
 * Note                  -in STM32F103c6 mcu has I2C1 and I2C2
 */
void MCAL_I2C_Master_TX(I2C_typedef* I2CX , uint16_t device_address, uint8_t*biffer, uint32_t lenth, stop_condation stop, Repeted_start repet )


{
	//1 generate start
	I2C_generate_start(I2CX, start, fun_enable);
	//2_wait until start condation set
	while(!( I2C_flag_state(I2CX, EV5)));
	//3_send slave address
	I2C_send_address(I2CX, device_address, I2C_Master_trensmetter);
	//4  wait untill EV6 set
	while(!( I2C_flag_state(I2CX, EV6)));
	//5  wait untill I2C_Event_Master_Byte_Tramsmetting  set
	while(!( I2C_flag_state(I2CX,Master_Byte_Tramsmetting)));
	//6 Send data
	for(volatile int i=0 ;i<lenth ;i++)
	{
		I2CX->I2C_DR= biffer[i];

		while(!( I2C_flag_state(I2CX,EV8)));


	}
	while(!( I2C_flag_state(I2CX,EV8_2)));
	if(stop==with_stop)
		I2C_generate_stop(I2CX,fun_enable);



}
void MCAL_I2C_Master_RX(I2C_typedef* I2CX , uint16_t device_address, uint8_t*biffer, uint32_t lenth, stop_condation stop, Repeted_start repet )

{
	uint32_t	index=0;
//1 generate start
		I2C_generate_start(I2CX, start, fun_enable);
//2 	EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
     while(!(I2C_flag_state(I2CX, EV5)));
 //3_send slave address
     	I2C_send_address(I2CX, device_address, I2C_Master_resever);
//4  wait untill EV6 set

     	while(!( I2C_flag_state(I2CX, EV6)));
     	I2C_AcknowledgeConfig(I2CX,fun_enable);
//5	//read data until lengh=0
 	if(lenth)
     	{
     	for(volatile int i=lenth ;i>=0 ;i--)
     	{
     		while(!( I2C_flag_state(I2CX, EV7)));
     		biffer[i]=I2CX->I2C_DR;

     	}
    	I2C_AcknowledgeConfig(I2CX,fun_disable);
     	}
if(stop=with_stop)
{
	I2C_generate_stop(I2CX,fun_enable)	;
}
if(I2CX==I2C1)
	index =I2C_index1;
else if  (I2CX==I2C2)
		index =I2C_index1;
if(GP_I2C[index].I2C_Acknowledge==I2C_Acknowledge_enable)

	I2C_generate_stop(I2CX,fun_enable)	;

}



//===============================================================================================================================================================================================
void  I2C_generate_start(I2C_typedef* I2CX , Repeted_start repet ,fun_state new_state)
{
	if(repet !=repeted_start)
	{
		//check if bus is idel or not
		while(I2C_flag_state(I2CX , I2C_BUS_BUSY));  // exit when be  0
		//
		//		Bit 8 START: Start generation
		//		This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
		//		In Master Mode:
		//		0: No Start generation
		//		1: Repeated start generation
		//		In Slave mode:
		//		0: No Start generation
		//		1: Start generation when the bus is free
		if(new_state != fun_disable)
		{
			I2CX->I2C_CR1 |=I2C_CR1_START;
		}
		else
		{
			I2CX->I2C_CR1 &=~(I2C_CR1_START);
		}

	}

}

void  I2C_generate_stop(I2C_typedef* I2CX ,fun_state state )
{
	if(state !=fun_disable)
		 I2CX->I2C_CR1 |= I2C_CR1_STOP;
	else
		 I2CX->I2C_CR1 &=~( I2C_CR1_STOP);



}
flage_state I2C_flag_state(I2C_typedef* I2CX , stutes flag)
{
	volatile uint32_t  read;
	flage_state state =reset;
	uint32_t flag1=0 ,flag2=0;
	uint32_t lastevent =0 ;
	switch(flag)
	{
	case I2C_BUS_BUSY:
	{
		//		Bit 1 BUSY: Bus busy
		//		0: No communication on the bus
		//		1: Communication ongoing on the bus
		//		– Set by hardware on detection of SDA or SCL low
		//		– cleared by hardware on detection of a Stop condition.
		//		It indicates a communication in progress on the bus. This information is still updated when
		//		the interface is disabled (PE=0)

		if((I2CX->I2C_SR2) & (I2C_SR2_BUSY))
			state=set;
		else
			state=reset;
		break;
	}
	case EV5 :
	{
		//		Bit 0 SB: Start bit (Master mode)
		//		0: No Start condition
		//		1: Start condition generated.
		//		– Set when a Start condition generated.
		//		– Cleared by software by reading the SR1 register followed by writing the DR register, or by
		//		hardware when PE=0

		if((I2CX->I2C_SR1) & (I2C_SR1_SB))
			state=set;
		else
			state=reset;
		break;
	}
	case EV6 :
	{
		//		Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
		//		This bit is cleared by software reading SR1 register followed reading SR2, or by hardware
		//		when PE=0.
		//		Address matched (Slave)
		//		0: Address mismatched or not received.
		//		1: Received address matched
		if((I2CX->I2C_SR1) & (I2C_SR1_ADDR))
			state=set;
		else
			state=reset;
		//ADDR=1, cleared by reading SR1 register followed by reading SR2.
		//read =I2CX->I2C_SR2;
		break;

	}
	case Master_Byte_Tramsmetting:
	{

		flag1 =	I2CX->I2C_SR1;
		flag2 =I2CX->I2C_SR2;
		flag2=flag2<<16;
		lastevent =(flag1|flag2) & ((unsigned long)0x00FFFFFF) ;
		if((lastevent &flag)==flag)
			state=set;
		else
			state=reset;
		break;

	}
	case EV8 :
	{

		//		Bit 7 TxE: Data register empty (transmitters)
		//		0: Data register not empty
		//		1: Data register empty
		//		– Set when DR is empty in transmission. TxE is not set during address phase.
		//		– Cleared by software writing to the DR register or by hardware after a start or a stop condition
		//		or when PE=0.
		if((I2CX->I2C_SR1)	&(I2C_SR1_TXE))
			state=set;
		else
			state=reset;
		break;

	}
	case EV8_2:
	{
		//	Bit 2 BTF: Byte transfer finished
		//		0: Data byte transfer not done
		//		1: Data byte transfer succeeded


		//		Bit 7 TxE: Data register empty (transmitters)
		//		0: Data register not empty
		//		1: Data register empty
		//		– Set when DR is empty in transmission. TxE is not set during address phase.
		//		– Cleared by software writing to the DR register or by hardware after a start or a stop condition
		//		or when PE=0.
		if(((I2CX->I2C_SR1)	&(I2C_SR1_TXE)) && (I2CX->I2C_SR1)&(I2C_SR1_BTF))
			state=set;
		else
				state=reset;
			break;

	}


	case EV7 :
	{
//		Bit 6 RxNE: Data register not empty (receivers)
//		0: Data register empty
//		1: Data register not empty
//		– Set when data register is not empty in receiver mode. RxNE is not set during address phase.
//		– Cleared by software reading or writing the DR register or by hardware when PE=0.
//		RxNE is not set in case of ARLO event.
//		Note: RxNE is not cleared by reading data when BTF is set, as the data register is still full
		if((I2CX->I2C_SR1) &(I2C_SR1_RXNE))
			state =set;
		else
			state=reset;
		break ;
	}
	}
	return  state;


}

void I2C_send_address(I2C_typedef* I2CX  , uint16_t device_address ,I2C_direction direction)
{
	device_address=(device_address<<1);
	if(direction !=I2C_Master_trensmetter)
	{
		//read
		device_address |=1<<0;

	}
	else
	{  //write
		device_address &=~ (1<<0);
	}

	I2CX->I2C_DR =device_address;
}
void  I2C_AcknowledgeConfig(I2C_typedef* I2CX ,fun_state state )
{
	if(state!=fun_disable)
		I2CX->I2C_CR1 |=I2C_CR1_ACK;
	else
		I2CX->I2C_CR1 &=~(I2C_CR1_ACK);
}

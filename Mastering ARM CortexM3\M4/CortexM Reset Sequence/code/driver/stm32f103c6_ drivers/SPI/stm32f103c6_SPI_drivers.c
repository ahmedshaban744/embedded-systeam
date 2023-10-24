/*
 * stm32f103c6_SPI_drivers.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Ahmed Shaban
 */
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//includes
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#include "stm32f103c6_SPI_drivers.h"

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//GLOBAL MACROS
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
#define  SPI1_index   0
#define  SPI2_index   1
#define SPI_SR_TXE  ((uint8_t)0x02)
#define SPI_SR_RXNE  ((uint8_t)0x01)

//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
//GLOBAL VARABLE
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
SPI_confog_t* GP_SPI[2]={NULL,NULL};

/**================================================================
 * @Fn                   -  MCAL_SPI_INIT
 * @brief                -initalizaion SPIX
 * @param [in]           -SPIX the spi number
 * @param [in]           -SPI_define configration parametar
 * @retval               - NULL
 * Note                  -THE STM32F103C8 has only SPI1 andd SPI2
 *
 */
void MCAL_SPI_INIT(SPI_typedef *SPIX,SPI_confog_t* SPI_define)
{
	uint16_t CR1_TEMP=0;
	uint16_t CR2_TEMP=0;

	if(SPIX==SPI1)
	{
		GP_SPI[SPI1_index]= SPI_define;
		SPI1_clock_enable();
	}
	else if(SPIX==SPI2)
	{
		GP_SPI[SPI2_index]= SPI_define;
		SPI2_clock_enable();
	}
	//enable SPI
	CR1_TEMP|=1<<6;
	//master or slave
	CR1_TEMP|=SPI_define->device_mode;
	//communcation mode
	CR1_TEMP|=SPI_define->direcation;
	//data size
	CR1_TEMP|=SPI_define->data_size;
	//clock polarity
	CR1_TEMP|=SPI_define->clock_polarity;
	//clock phase
	CR1_TEMP|=SPI_define->clock_phase;
	//frame format
	CR1_TEMP|=SPI_define->fram_format;
	//boud rate
	CR1_TEMP|=SPI_define->Boud_rate;
	//intrrput
	if(SPI_define->IRQ_enable !=SPI_IRQ_none)
	{
		CR2_TEMP|=SPI_define->IRQ_enable;
		if(SPIX==SPI1)
			NVIC_IRQ37_SPI1_enable();
		else if(SPIX==SPI2)
			NVIC_IRQ38_SPI2_enable();
	}
	if(SPI_define->NSS==SPI_NSS_hardware_master_mode_output_enable)
		CR2_TEMP|=SPI_define->NSS;
	else if (SPI_define->NSS==SPI_NSS_hardware_master_mode_output_disable)
		CR2_TEMP&=SPI_define->NSS;
	else
		CR1_TEMP|=SPI_define->NSS;


	SPIX->SPI_CR1=CR1_TEMP;
	SPIX->SPI_CR2=CR2_TEMP;
}




/**================================================================
 * @Fn                   -  MCAL_SPI_DEINIT
 * @brief                -deinitalizaion SPIX
 * @param [in]           -SPIX the spi number
 * @retval               - NULL
 * Note                  -THE STM32F103C8 has only SPI1 andd SPI2
 */
void MCAL_SPI_DEINIT(SPI_typedef* SPIX)
{
	if(SPIX==SPI1)
	{
		SPI1_clock_RESET();
		NVIC_IRQ37_SPI1_disable() ;
	}
	else if(SPIX==SPI2)
	{
		SPI2_clock_RESET();
		NVIC_IRQ38_SPI2_disable();
	}

}

/**================================================================
 * @Fn                   -  MCAL_SPI_GPIO_SET_PINS
 * @brief                -deinitalizaion SPIX pins
 * @param [in]           -SPIX the spi number
 * @retval               - NULL
 * Note                  -THE STM32F103C8 has only SPI1 andd SPI2
 */




void MCAL_SPI_GPIO_SET_PINS(SPI_typedef* SPIX)
{
	GPIO_pinconfig_t pinconfig;
	if(SPIX==SPI1)
	{
		//SPI1 NSS>>>>>>PA4
		if(GP_SPI[SPI1_index]->device_mode==SPI_Master_mode)
		{
			switch(GP_SPI[SPI1_index]->NSS)
			{
			case SPI_NSS_hardware_master_mode_output_disable :
				pinconfig.gpio_pin_number =GPIO_PIN_4;
				pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_INIT(GPIOA, &pinconfig);
				break ;
			case SPI_NSS_hardware_master_mode_output_enable :
				pinconfig.gpio_pin_number =GPIO_PIN_4;
				pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
				pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
				MCAL_GPIO_INIT(GPIOA, &pinconfig);
				break ;

			}
			//SPI1 SCLK<<<<<PA5
			pinconfig.gpio_pin_number =GPIO_PIN_5;
			pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
			MCAL_GPIO_INIT(GPIOA, &pinconfig);

			//SPI1 MISO  PA6
			pinconfig.gpio_pin_number =GPIO_PIN_6;
			pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOA, &pinconfig);
			//to do Simplex bidirectional data wire / master

			//SPI1 MOSI PA7
			pinconfig.gpio_pin_number =GPIO_PIN_7;
			pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
			MCAL_GPIO_INIT(GPIOA, &pinconfig);
			//to do Simplex bidirectional data wire / master
		}



		else if(GP_SPI[SPI1_index]->device_mode==SPI_slave_mode)
		{		//SPI1 NSS>>>>>>PA4
			if(GP_SPI[SPI1_index]->NSS==SPI_NSS_hardware_slave_mode)
			{
				pinconfig.gpio_pin_number =GPIO_PIN_4;
				pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_INIT(GPIOA, &pinconfig);
			}
			//SPI1 SCLK<<<<<PA5
			pinconfig.gpio_pin_number =GPIO_PIN_5;
			pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOA, &pinconfig);

			//SPI1 MISO  PA6
			pinconfig.gpio_pin_number =GPIO_PIN_6;
			pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
			MCAL_GPIO_INIT(GPIOA, &pinconfig);
			//to do		Full duplex / slave (multi-slave)
			//to do		Simplex bidirectional data wire/ slave (point to point)

			//SPI1 MOSI PA7
			pinconfig.gpio_pin_number =GPIO_PIN_7;
			pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOA, &pinconfig);
			//to do Simplex bidirectional data wire/ slave


		}
	}

	else if(SPIX==SPI2)
	{
		//SPI2 NSS>>>>>>PB12
		if(GP_SPI[SPI2_index]->device_mode==SPI_Master_mode)
		{
			switch(GP_SPI[SPI2_index]->NSS)
			{
			case SPI_NSS_hardware_master_mode_output_disable :
				pinconfig.gpio_pin_number =GPIO_PIN_12;
				pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_INIT(GPIOB, &pinconfig);
				break ;
			case SPI_NSS_hardware_master_mode_output_enable :
				pinconfig.gpio_pin_number =GPIO_PIN_12;
				pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
				pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
				MCAL_GPIO_INIT(GPIOB, &pinconfig);
				break ;

			}
			//SPI2 SCLK<<<<<PB13
			pinconfig.gpio_pin_number =GPIO_PIN_13;
			pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
			MCAL_GPIO_INIT(GPIOB, &pinconfig);

			//SPI2 MISO  PB14
			pinconfig.gpio_pin_number =GPIO_PIN_14;
			pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOB, &pinconfig);
			//to do Simplex bidirectional data wire / master

			//SPI2 MOSI PB15
			pinconfig.gpio_pin_number =GPIO_PIN_15;
			pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
			MCAL_GPIO_INIT(GPIOB, &pinconfig);
			//to do Simplex bidirectional data wire / master
		}



		else if(GP_SPI[SPI2_index]->device_mode==SPI_slave_mode)
		{	//SPI2 NSS>>>>>>PB12
			if(GP_SPI[SPI2_index]->NSS==SPI_NSS_hardware_slave_mode)
			{
				pinconfig.gpio_pin_number =GPIO_PIN_12;
				pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_INIT(GPIOB, &pinconfig);
			}
			//SPI2 SCLK<<<<<PB13
			pinconfig.gpio_pin_number =GPIO_PIN_13;
			pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOB, &pinconfig);

			//SPI2 MISO  PB14
			pinconfig.gpio_pin_number =GPIO_PIN_14;
			pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_AF_PP;
			pinconfig.GPIO_OUTPUT_SPEED=GPIO_SPEED_10MHZ;
			MCAL_GPIO_INIT(GPIOB, &pinconfig);
			//to do		Full duplex / slave (multi-slave)
			//to do		Simplex bidirectional data wire/ slave (point to point)

			//SPI2 MOSI PB15
			pinconfig.gpio_pin_number =GPIO_PIN_15;
			pinconfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_INIT(GPIOB, &pinconfig);
			//to do Simplex bidirectional data wire/ slave


		}
	}

}


/**================================================================
 * @Fn                   -  MCAL_SPI_TX
 * @brief                -Send data bt SPIX
 * @param [in]           -SPIX the spi number
 * @param [in]           - *buffer to stor the data
 * @param [in]           -polling  to oprn or close the polling
 * @retval               - NULL
 * Note                  -THE STM32F103C8 has only SPI1 andd SPI2
 */
void MCAL_SPI_TX(SPI_typedef *SPIX,uint16_t *buffer,enum polling_MC polling)
{
	if(polling==SPI_enable)
		while(!((SPIX)->SPI_SR &SPI_SR_TXE));
	SPIX->SPI_DR=*buffer;
}
/**================================================================
 * @Fn                   -  MCAL_SPI_RX
 * @brief                -RESIVE data by SPIX
 * @param [in]           -SPIX the spi number
 * @param [in]           - *buffer to stor the data
 * @param [in]           -polling  to oprn or close the polling
 * @retval               - NULL
 * Note                  -THE STM32F103C8 has only SPI1 andd SPI2
 */
void  MCAL_SPI_RX(SPI_typedef *SPIX,uint16_t *buffer,enum polling_MC polling)
{
	if(polling==SPI_enable)
		while(!((SPIX)->SPI_SR &SPI_SR_RXNE));
	*buffer=SPIX->SPI_DR;

}
/**================================================================
 * @Fn                   -  MCAL_SPI_TX_RX
 * @brief                -Send and RESIVE data by SPIX
 * @param [in]           -SPIX the spi number
 * @param [in]           - *buffer to stor the data
 * @param [in]           -polling  to oprn or close the polling
 * @retval               - NULL
 * Note                  -THE STM32F103C8 has only SPI1 andd SPI2
 */
void  MCAL_SPI_TX_RX(SPI_typedef *SPIX,uint16_t *buffer,enum polling_MC polling)
{
	if(polling==SPI_enable)
		while(!((SPIX)->SPI_SR &SPI_SR_TXE));
	SPIX->SPI_DR=*buffer ;
	if(polling==SPI_enable)
		while(!((SPIX)->SPI_SR &SPI_SR_RXNE));
	*buffer=SPIX->SPI_DR;
	//====================================================================
	//===================IRQ==============================================
	//====================================================================

}
void SPI1_IRQHandler(void)
{
	struct intrput_src  irq_src;
	irq_src.RXNE=  ((SPI1->SPI_SR &(1<<0)) >>0);
	irq_src.TXE=   ((SPI1->SPI_SR &(1<<1)) >>1);
	irq_src.CHSIDE=((SPI1->SPI_SR &(1<<2)) >>2);
	irq_src.UDR=   ((SPI1->SPI_SR &(1<<3)) >>3);
	irq_src.CRCERR=((SPI1->SPI_SR &(1<<4)) >>4);
	irq_src.MODF=  ((SPI1->SPI_SR &(1<<5)) >>5);
	irq_src.OVR=   ((SPI1->SPI_SR &(1<<6)) >>6);
	irq_src.BSY=   ((SPI1->SPI_SR&(1<<7)) >>7);

	GP_SPI[SPI1_index]->p_IQR_callback(irq_src);


}
void SPI2_IRQHandler(void)
{

	struct intrput_src  irq_src;
	irq_src.RXNE=  ((SPI2->SPI_SR &(1<<0)) >>0);
	irq_src.TXE=   ((SPI2->SPI_SR &(1<<1)) >>1);
	irq_src.CHSIDE=((SPI2->SPI_SR &(1<<2)) >>2);
	irq_src.UDR=   ((SPI2->SPI_SR &(1<<3)) >>3);
	irq_src.CRCERR=((SPI2->SPI_SR &(1<<4)) >>4);
	irq_src.MODF=  ((SPI2->SPI_SR &(1<<5)) >>5);
	irq_src.OVR=   ((SPI2->SPI_SR &(1<<6)) >>6);
	irq_src.BSY=   ((SPI2->SPI_SR&(1<<7)) >>7);

	GP_SPI[SPI2_index]->p_IQR_callback(irq_src);

}





















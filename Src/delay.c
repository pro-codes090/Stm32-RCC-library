/*
 * delay.c
 *
 *  Created on: 22-Jun-2022
 *      Author: pro
 */


#include <stdint.h>
#include "stm32f407xx.h"
#include "stm32f407xx_RCC.h"
#include "stm32f407xx_gpio_driver.h"

RCC_Handle_t rcchandle ;
GPIO_Handle_t GpioLed ;

void ledPinConfig(){

GpioLed.pGPIOx = GPIOD ;
GPIOA_CLOCK_ENABLE() ;

GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15 ;
GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH ;
GpioLed.GPIO_PinConfig.GPIO_PinPUPDControl = GPIO_NO_PUPD ;
GpioLed.GPIO_PinConfig.GPIO_PinAltFunMode = 0 ;
GPIO_Init(&GpioLed);

}

int main(void)
{
	/* Configuration of RCC Clocks has nothing to do with delay function */
	/* But setting " rcchandle.pRCC = RCC " is mandatory */
	rcchandle.pRCC = RCC ;		// required for delay function to work
	rcchandle.RCC_Config.AHB_ClockFreq = 64000000 ;				// user preference has no effect how delay is measured
	rcchandle.RCC_Config.APB1_ClockFreq = 32000000;				// user preference has no effect how delay is measured
	rcchandle.RCC_Config.APB2_ClockFreq = 32000000;				// user preference has no effect how delay is measured
	rcchandle.RCC_Config.clockSource = PLL_CLOCK ;				// user preference has no effect how delay is measured
	rcchandle.RCC_Config.PLLSource = HSI_CLOCK ;				// user preference has no effect how delay is measured

	RCC_Init(&rcchandle);
	ledPinConfig();
	GPIO_Init(&GpioLed) ;

	// delay given to function should be in milliseconds(ms)

	while(1){
	GPIO_WriteToOutputPin(GPIOD, 15, 1) ;
	sysTick_Delay(500, &rcchandle) ;
	GPIO_WriteToOutputPin(GPIOD, 15, 0) ;
	sysTick_Delay(500, &rcchandle) ;
	}



	for(;;);
}

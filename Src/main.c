/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f407xx.h"
#include "stm32f407xx_RCC.h"
#include "stm32f407xx_gpio_driver.h"


RCC_Handle_t rcchandle ;
GPIO_Handle_t GpioLed ;


void MCO_Config(){

GpioLed.pGPIOx = GPIOA ;
GPIOA_CLOCK_ENABLE() ;

GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8 ;
GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN ;
GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH ;
GpioLed.GPIO_PinConfig.GPIO_PinPUPDControl = GPIO_NO_PUPD ;
GpioLed.GPIO_PinConfig.GPIO_PinAltFunMode = 0 ;
GPIO_Init(&GpioLed);

}

int main(void)
{
	printf("application running \n"  ) ;

	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.clockSource = HSI_CLOCK;

	MCO_Config();

	printf("clock source is %d \n" , getClockSource(&rcchandle) );
	printf("AHB1 clock is %d \n" , getAHBClock(&rcchandle));
	printf("APB1 clock is %d \n" , getAPB1Clock(&rcchandle) );
	printf("APB2 clock is %d \n" , getAPB2Clock(&rcchandle));


for(;;);
}
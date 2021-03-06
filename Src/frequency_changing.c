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

int main(void)
{
	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.AHB_ClockFreq = 16000000 ;
	rcchandle.RCC_Config.APB1_ClockFreq = APB1_FREQ_HSI_8M ;
	rcchandle.RCC_Config.APB2_ClockFreq = APB2_FREQ_HSI_8M ;
	rcchandle.RCC_Config.clockSource = HSI_CLOCK;
	rcchandle.RCC_Config.PLLSource = HSI_CLOCK ;

	RCC_Init(&rcchandle);

	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.AHB_ClockFreq = 8000000 ;
	rcchandle.RCC_Config.APB1_ClockFreq= APB1_FREQ_HSI_4M ;
	rcchandle.RCC_Config.APB2_ClockFreq= APB2_FREQ_HSI_4M ;
	rcchandle.RCC_Config.clockSource = HSI_CLOCK ;
	RCC_Init(&rcchandle);

	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.AHB_ClockFreq = 8000000 ;
	rcchandle.RCC_Config.APB1_ClockFreq= APB1_FREQ_HSE_4M ;
	rcchandle.RCC_Config.APB2_ClockFreq= APB2_FREQ_HSE_4M ;
	rcchandle.RCC_Config.clockSource = HSE_CLOCK;
	RCC_Init(&rcchandle);

	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.AHB_ClockFreq = 4000000 ;
	rcchandle.RCC_Config.APB1_ClockFreq= APB1_FREQ_HSE_2M ;
	rcchandle.RCC_Config.APB2_ClockFreq= APB2_FREQ_HSE_2M ;
	rcchandle.RCC_Config.clockSource = HSE_CLOCK;
	RCC_Init(&rcchandle);


	//////////////////// USING PLL CLOCK with HSI as PLL Source /////////////////////////////////////

	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.AHB_ClockFreq =  64000000 ;
	rcchandle.RCC_Config.APB1_ClockFreq = 32000000 ;
	rcchandle.RCC_Config.APB2_ClockFreq = 16000000 ;
	rcchandle.RCC_Config.clockSource = PLL_CLOCK;
	rcchandle.RCC_Config.PLLSource = HSI_CLOCK ;
	RCC_Init(&rcchandle);

	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.AHB_ClockFreq =  128000000 ;
	rcchandle.RCC_Config.APB1_ClockFreq = 42000000 ;
	rcchandle.RCC_Config.APB2_ClockFreq = 42000000 ;
	rcchandle.RCC_Config.clockSource = PLL_CLOCK;
	rcchandle.RCC_Config.PLLSource = HSI_CLOCK ;
	RCC_Init(&rcchandle);

	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.AHB_ClockFreq =  168000000 ;
	rcchandle.RCC_Config.APB1_ClockFreq = 42000000 ;
	rcchandle.RCC_Config.APB2_ClockFreq = 84000000 ;
	rcchandle.RCC_Config.clockSource = PLL_CLOCK;
	rcchandle.RCC_Config.PLLSource = HSI_CLOCK ;
	RCC_Init(&rcchandle);

	//////////////////// USING PLL CLOCK with HSE as PLL Source /////////////////////////////////////

	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.AHB_ClockFreq =  64000000 ;
	rcchandle.RCC_Config.APB1_ClockFreq = 32000000 ;
	rcchandle.RCC_Config.APB2_ClockFreq = 16000000 ;
	rcchandle.RCC_Config.clockSource = PLL_CLOCK;
	rcchandle.RCC_Config.PLLSource = HSI_CLOCK ;
	RCC_Init(&rcchandle);

	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.AHB_ClockFreq =  128000000 ;
	rcchandle.RCC_Config.APB1_ClockFreq = 42000000 ;
	rcchandle.RCC_Config.APB2_ClockFreq = 42000000 ;
	rcchandle.RCC_Config.clockSource = PLL_CLOCK;
	rcchandle.RCC_Config.PLLSource = HSI_CLOCK ;
	RCC_Init(&rcchandle);

	rcchandle.pRCC = RCC ;
	rcchandle.RCC_Config.AHB_ClockFreq =  168000000 ;
	rcchandle.RCC_Config.APB1_ClockFreq = 42000000 ;
	rcchandle.RCC_Config.APB2_ClockFreq = 84000000 ;
	rcchandle.RCC_Config.clockSource = PLL_CLOCK;
	rcchandle.RCC_Config.PLLSource = HSI_CLOCK ;
	RCC_Init(&rcchandle);


	for(;;);
}

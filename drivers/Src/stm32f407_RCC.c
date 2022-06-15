/*
 * stm32f407_RCC.c
 *
 *  Created on: 12-Apr-2022
 *      Author: pro
 */

#include "stm32f407xx_RCC.h"

void RCC_Init(RCC_Handle_t* pRCCHandle ){


}

void setAHB1lock(RCC_Handle_t* pRCCHandle) {

	if (pRCCHandle->RCC_Config.AHB_ClockFreq <= 16000000) {

	if (pRCCHandle->RCC_Config.clockSource == HSI_CLOCK) {
		uint8_t i=0 ;
		uint8_t temp = SYSTEM_HSI / pRCCHandle->RCC_Config.AHB_ClockFreq ;
		uint8_t value = 0 ;
		if (temp == 1) {
			value = 0 ;
			return ;

		}else if (temp >= 64) {

			temp = temp / 2 ;

		}else if (temp >= 2){
			value =  8;
			for ( ;temp !=2 ; i++) {
				temp = temp / 2 ;
			 }
			value = value + i ;
	}
	 }else if (pRCCHandle->RCC_Config.clockSource == HSE_CLOCK) {

	 }

	}else if ((pRCCHandle->RCC_Config.AHB_ClockFreq > 16000000 )&& (pRCCHandle->RCC_Config.clockSource == PLL_CLOCK)) {

	}

}


void changeClockSource( RCC_Handle_t* pRCCHandle) {

	if (pRCCHandle->RCC_Config.clockSource == HSI_CLOCK) {
		pRCCHandle->pRCC->CR |= (1 << RCC_CR_HSION) ;
		while(!(pRCCHandle->pRCC->CR & (1 << RCC_CR_HSIRDY) )) ;
		pRCCHandle->pRCC->CFGR &= ~(3 << 0) ;

	}else if(pRCCHandle->RCC_Config.clockSource == HSE_CLOCK){
		pRCCHandle->pRCC->CR |= (1 << RCC_CR_HSEON) ;
		while(!(pRCCHandle->pRCC->CR & (1 << RCC_CR_HSERDY) )) ;
		pRCCHandle->pRCC->CFGR |= (1 << 0) ;
	}else if(pRCCHandle->RCC_Config.clockSource == PLL_CLOCK){
		pRCCHandle->pRCC->CR |= (1 << RCC_CR_PLLON) ;
		while(!(pRCCHandle->pRCC->CR & (1 << RCC_CR_PLLRDY) )) ;
		pRCCHandle->pRCC->CFGR |= (1 << 1) ;
	}
}

uint16_t getClockSource(RCC_Handle_t* pRCCHandle){

	if ((pRCCHandle->pRCC->CFGR & 0x0C ) == 0x00) {
#if RCC_DEBUG
		printf("CLK source HSI: %d \n" ,(pRCCHandle->pRCC->CFGR & 0x0C ) >> 0) ;
#endif
		return HSI_CLOCK ;
	}else if ((pRCCHandle->pRCC->CFGR & 0x0C ) == 0x04){
#if RCC_DEBUG
		printf("CLK source HSE: %d \n" ,(pRCCHandle->pRCC->CFGR & 0x0C ) >> 0) ;
#endif
		return HSE_CLOCK ;
	}else if ((pRCCHandle->pRCC->CFGR & 0x0C ) == 0x08){
#if RCC_DEBUG
		printf("CLK source PLL: %d \n" ,(pRCCHandle->pRCC->CFGR & 0x0C ) >> 0) ;
#endif
		return PLL_CLOCK ;
	}
		return 0;
}
uint32_t getAHBClock(RCC_Handle_t* pRCCHandle) {

	uint16_t temp = 0 ;
	uint8_t value = 2 ;

	if (pRCCHandle->RCC_Config.clockSource == HSI_CLOCK) {
		// default for HSI is 16MHZ
		temp  = ((pRCCHandle->pRCC->CFGR & 0xF0 ) >> 4) ;
		if (temp >=12) {
			value = 4 ;		// 8 ,16 ,32,64, 128 , 256
		}
		 if (temp > 8) {
			 temp = temp - 8 ;
		 for (uint8_t i = 0;  i < temp; i++) {
			 	 // for every loop we double the value of 2
			 value = value * 2;
	    	}
		 }else if (temp == 8){
			 	 value = 2 ;
		 }else {
			 value = 1 ;
		 }
		return (16000000 / value ) ;
	}else if (pRCCHandle->RCC_Config.clockSource == HSE_CLOCK){
		// default for HSI is 8MHZ
		temp  = ((pRCCHandle->pRCC->CFGR & 0x000000F0U ) >> 1) ;
		 temp = temp - 8 ;
		 if (temp > 8) {

		 for (uint8_t i = 0;  i < temp; i++) {
			 	 // for every loop we double the value of 2
			 value = value * 2;
	    	}
		 }else if (temp == 8){
			 	 value = 2 ;
		 }else {
			 value = 1 ;
		 }
		return (8000000/((pRCCHandle->pRCC->CFGR & 0xF0 ) >> 0) ) ;
	}else if (pRCCHandle->RCC_Config.clockSource == PLL_CLOCK){
			printf("function not supported yet returning ");
			return 0 ;		// to do

	}
	return 0 ;
}
uint32_t getAPB1Clock(RCC_Handle_t* pRCCHandle) {
	uint16_t temp = 0 ;
	uint8_t value = 2 ;

	temp  = ((pRCCHandle->pRCC->CFGR & 0x1C00 ) >> 10);

			 if (temp > 4) {
				 temp = temp - 4 ;
			 for (uint8_t i = 0;  i < temp; i++) {
				 	 // for every loop we double the value of 2
				 value = value * 2;
		    	}
			 }else if (temp == 4){
				 	 value = 2 ;
			 }else {
				 value = 1 ;
			 }

	return ( getAHBClock(pRCCHandle) / value );
}

uint32_t getAPB2Clock(RCC_Handle_t* pRCCHandle){

	uint16_t temp = 0 ;
	uint8_t value = 2 ;

	temp  = ((pRCCHandle->pRCC->CFGR & 0xE000 ) >> 13);

	 if (temp > 4) {
		 temp = temp - 4 ;
	 for (uint8_t i = 0;  i < temp; i++) {
			 // for every loop we double the value of 2
		 value = value * 2;
		}
	 }else if (temp == 4){
			 value = 2 ;
	 }else {
		 value = 1 ;
	 }

	return ( getAHBClock(pRCCHandle) / value );

}

/*
 * stm32f407xx_RCC.h
 *
 *  Created on: 12-Apr-2022
 *      Author: pro
 */

#ifndef INC_STM32F407XX_RCC_H_
#define INC_STM32F407XX_RCC_H_

#include "stm32f407xx.h"
#include <math.h>
///////////////////////// SYSTEM CLOCK INFO //////////////////////////
#define AHB_MAX_FREQ 	168000000 // MHZ
#define APB1_MAX_FREQ 	42000000	// MHZ
#define APB2_MAX_FREQ 	84000000	// MHZ
#define AHB2_MAX_FREQ 	168000000 // MHZ
#define SYSTEM_HSE		 8000000	// MHZ
#define SYSTEM_HSI 	    16000000  // MHZ
//////////////////////////////////////////////////////////////////////
#ifndef RCC_DEBUG
#define RCC_DEBUG 1
#endif
#define HSE_CLOCK 1
#define HSI_CLOCK 0
#define PLL_CLOCK 2

#define MCO_HSI 00
#define MCO_LSE 01
#define MCO_HSE 02
#define MCO_PLL 03

#define MCO_PRE_0	0x00
#define MCO_PRE_2	0x04
#define MCO_PRE_3	0x05
#define MCO_PRE_4	0x06
#define MCO_PRE_5	0x07

// Use the below options when using HSI as a clock source for setting AHB bus clock frequency
#define AHB_FREQ_HSI_16M   16000000
#define AHB_FREQ_HSI_8M    8000000
#define AHB_FREQ_HSI_4M    4000000
#define AHB_FREQ_HSI_2M    2000000
#define AHB_FREQ_HSI_1M    1000000
#define AHB_FREQ_HSI_250K  250000
#define AHB_FREQ_HSI_125K  125000
#define AHB_FREQ_HSI_62K   62500
#define AHB_FREQ_HSI_31K   31250

// Use the below options when using HSE as a clock source for setting AHB bus clock frequency
	/* Default value of HSE in most ST dev board is 8MHZ
	 * Incase if the default HSE is different in your case then add the values in the below fashion
	 *
	 * Divide the frequency of the oscillator (HSE) by 1 , 2 ,4 ,8 , 16 , 64 , 128 , 25 ,512
	 * and add/change the names of the macros accordingly
	 * */
#define AHB_FREQ_HSE_8M    8000000
#define AHB_FREQ_HSE_4M    4000000
#define AHB_FREQ_HSE_2M    2000000
#define AHB_FREQ_HSE_1M    1000000
#define AHB_FREQ_HSE_250K  250000
#define AHB_FREQ_HSE_125K  125000
#define AHB_FREQ_HSE_62K   62500
#define AHB_FREQ_HSE_31K   31250

// Use the below options when using HSI as a clock source for setting APB1 bus clock frequency
#define APB1_FREQ_HSI_16M   16000000
#define APB1_FREQ_HSI_8M    8000000
#define APB1_FREQ_HSI_4M    4000000
#define APB1_FREQ_HSI_2M    2000000
#define APB1_FREQ_HSI_1M    1000000
//#define APB1_FREQ_HSI_250K  250000
//#define APB1_FREQ_HSI_125K  125000
//#define APB1_FREQ_HSI_62K   62500
//#define APB1_FREQ_HSI_31K   31250

// Use the below options when using HSE as a clock source for setting APB1 bus clock frequency
#define APB1_FREQ_HSE_8M    8000000
#define APB1_FREQ_HSE_4M    4000000
#define APB1_FREQ_HSE_2M    2000000
#define APB1_FREQ_HSE_1M    1000000
#define APB1_FREQ_HSE_500K  500000
//#define APB1_FREQ_HSE_125K  125000
//#define APB1_FREQ_HSE_62K   62500
//#define APB1_FREQ_HSE_31K   31250

// Use the below options when using HSI as a clock source for setting APB2 bus clock frequency
#define APB2_FREQ_HSI_16M   16000000
#define APB2_FREQ_HSI_8M    8000000
#define APB2_FREQ_HSI_4M    4000000
#define APB2_FREQ_HSI_2M    2000000
#define APB2_FREQ_HSI_1M    1000000
//#define APB2_FREQ_HSI_250K  250000
//#define APB2_FREQ_HSI_125K  125000
//#define APB2_FREQ_HSI_62K   62500
//#define APB2_FREQ_HSI_31K   31250

// Use the below options when using HSE as a clock source for setting APB2 bus clock frequency
#define APB2_FREQ_HSE_8M    8000000
#define APB2_FREQ_HSE_4M    4000000
#define APB2_FREQ_HSE_2M    2000000
#define APB2_FREQ_HSE_1M    1000000
#define APB2_FREQ_HSE_500K  500000
//#define APB2_FREQ_HSE_125K  125000
//#define APB2_FREQ_HSE_62K   62500
//#define APB2_FREQ_HSE_31K   31250


#define RCC_CR_HSION 		00
#define RCC_CR_HSIRDY 		01
#define RCC_CR_HSITRIM 		03
#define RCC_CR_HSICAL 		08
#define RCC_CR_HSEON 		16
#define RCC_CR_HSERDY 		17
#define RCC_CR_HSEBYP 		18
#define RCC_CR_CSSON 		19
#define RCC_CR_PLLON 		24
#define RCC_CR_PLLRDY		25
#define RCC_CR_PLLI2SON 	26
#define RCC_CR_PLLI2SRDY	27



typedef struct{
uint8_t clockSource ;
uint32_t APB1_ClockFreq ;
uint32_t APB2_ClockFreq ;
volatile uint32_t AHB_ClockFreq  ;
uint8_t PLLSource ;
uint8_t MC01_prescaler ;
uint8_t MC02_prescaler ;
uint8_t MC01_source;
uint8_t MC02_source ;
}RCC_Configuration_t;



typedef struct{
RCC_RegDef_t *pRCC ;
RCC_Configuration_t RCC_Config ;
}RCC_Handle_t;

void RCC_Init(RCC_Handle_t* pRCCHandle );

void changeClockSource(RCC_Handle_t* pRCCHandle );
void setAHB1lock(RCC_Handle_t* pRCCHandle) ;
void setAPB1Clock(RCC_Handle_t* pRCCHandle) ;
void setAPB2Clock(RCC_Handle_t* pRCCHandle) ;

uint16_t getClockSource(RCC_Handle_t* pRCCHandle);
uint32_t getAHBClock(RCC_Handle_t* pRCCHandle) ;
uint32_t getAPB1Clock(RCC_Handle_t* pRCCHandle) ;
uint32_t getAPB2Clock(RCC_Handle_t* pRCCHandle) ;


#endif /* INC_STM32F407XX_RCC_H_ */

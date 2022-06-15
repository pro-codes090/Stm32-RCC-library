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
#define RCC_DEBUG 0
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

#define AHB_PRE_1		0x00
#define AHB_PRE_2		0x08
#define AHB_PRE_4		0x09
#define AHB_PRE_8		0x0A
#define AHB_PRE_16		0x0B
#define AHB_PRE_64		0x0C
#define AHB_PRE_128		0x0D
#define AHB_PRE_256		0x0E
#define AHB_PRE_512		0x0F

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
uint8_t AHB_Prescaler ;
uint8_t APB1_Prescaler ;
uint8_t APB2_Prescaler ;
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
void setSystemClock(RCC_Handle_t* pRCCHandle) ;
void setAPB1Clock(RCC_Handle_t* pRCCHandle) ;
void setAPB2Clock(RCC_Handle_t* pRCCHandle) ;

uint16_t getClockSource(RCC_Handle_t* pRCCHandle);
uint32_t getAHBClock(RCC_Handle_t* pRCCHandle) ;
uint32_t getAPB1Clock(RCC_Handle_t* pRCCHandle) ;
uint32_t getAPB2Clock(RCC_Handle_t* pRCCHandle) ;


#endif /* INC_STM32F407XX_RCC_H_ */

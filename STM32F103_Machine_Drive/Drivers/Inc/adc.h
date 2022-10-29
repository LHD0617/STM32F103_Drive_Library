/**
  ******************************************************************************
  * @file           : adc.h
  * @brief          : ADC驱动
	* @author					: 满心欢喜
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/1/2
  ******************************************************************************
  * @attention
  *
  * 本程序只供学习使用，未经作者许可，不得用于其它任何用途。
  *
  ******************************************************************************
  */
#ifndef _ADC_H
#define _ADC_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "common.h"
#include "gpio.h"
#include "nvic.h"

/*设置ADC枚举类型*/
typedef enum
{
	ADC_1,
	ADC_2,
}ADC_Num;


/*设置ADC引脚枚举类型*/
typedef enum
{
	ADC1_CH00_A00	= 0x0000,
	ADC1_CH01_A01	= 0x0101,
	ADC1_CH02_A02	= 0x0202,
	ADC1_CH03_A03	= 0x0303,
	ADC1_CH04_A04	= 0x0404,
	ADC1_CH05_A05	= 0x0505,
	ADC1_CH06_A06	= 0x0606,
	ADC1_CH07_A07	= 0x0707,
	ADC1_CH08_B00	= 0x0810,
	ADC1_CH09_B01	= 0x0911,
	ADC1_CH10_C00	= 0x0A20,
	ADC1_CH11_C01	= 0x0B21,
	ADC1_CH12_C02	= 0x0C22,
	ADC1_CH13_C03	= 0x0D23,
	ADC1_CH14_C04	= 0x0E24,
	ADC1_CH15_C05	= 0x0F25,
	ADC1_CH16_TEMP=	0x1000,
	ADC1_CH17_VS	= 0x1100,
	
	ADC2_CH00_A00	= 0x0000,
	ADC2_CH01_B01	= 0x0101,
	ADC2_CH02_B02	= 0x0202,
	ADC2_CH03_B03	= 0x0303,
	ADC2_CH04_A04	= 0x0404,
	ADC2_CH05_A05	= 0x0505,
	ADC2_CH06_A06	= 0x0606,
	ADC2_CH07_A07	= 0x0707,
	ADC2_CH08_B00	= 0x0810,
	ADC2_CH09_B01	= 0x0911,
	ADC2_CH10_B02	= 0x0A20,
	ADC2_CH11_C01	= 0x0B21,
	ADC2_CH12_C02	= 0x0C22,
	ADC2_CH13_C03	= 0x0D23,
	ADC2_CH14_C04	= 0x0E24,
	ADC2_CH15_C05	= 0x0F25,
}ADC_CH;


/*函数声明*/
void adc_init(ADC_Num num, ADC_CH pin);
uint16 adc_get(ADC_Num num, ADC_CH pin);

#endif


/**
  ******************************************************************************
  * @file           : adc.c
  * @brief          : ADC����
	* @author					: ���Ļ�ϲ
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/1/2
  ******************************************************************************
  * @attention
  *
  * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;��
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "adc.h"

ADC_TypeDef *adc_index[2] = {ADC1, ADC2};


/**
	* @name		adc_init
  * @brief  ADC��ʼ��
	* @param  num ADCģ��� ADC_1 ADC_2
	* @param  pin	���ź�
	* @return void
	* @Sample adc_init(ADC_1, ADC1_CH00_A00)
  */
void adc_init(ADC_Num num, ADC_CH pin)
{
	uint8 ch = pin>>8;
	gpio_init((GPIO_Num)(pin&0xff), GPI, 0, GPI_ANAOG_IN, GPIO_SPEED_50MHZ);
	RCC->APB2ENR 	|= 0x01<<(9+num);
	RCC->APB2RSTR |= 0x01<<(9+num);
	RCC->APB2RSTR &= ~(0x01<<(9+num));
	RCC->CFGR &= ~RCC_CFGR_ADCPRE;
	RCC->CFGR |= RCC_CFGR_ADCPRE_1;
	adc_index[num]->CR2 |= ADC_CR2_EXTSEL;
	adc_index[num]->CR2 |= ADC_CR2_EXTTRIG;
	if(num == 0&&ch == 16)	ADC1->CR2 |= ADC_CR2_TSVREFE;
	if(ch>10)	adc_index[num]->SMPR2 |= 0x07<<(3*ch);
	else			adc_index[num]->SMPR1 |= 0x07<<(3*(ch-10));
	adc_index[num]->CR2 |= ADC_CR2_ADON;
	adc_index[num]->CR2 |= ADC_CR2_RSTCAL;
	while(adc_index[num]->CR2 & ADC_CR2_RSTCAL);
	adc_index[num]->CR2 |= ADC_CR2_CAL;
	while(adc_index[num]->CR2 & ADC_CR2_CAL);
}

/**
	* @name		adc_get
  * @brief  ADCһ��ת��
	* @param  num ADCģ��� ADC_1 ADC_2
	* @param  pin	���ź�
	* @return ADC����
	* @Sample adc_get(ADC_1, ADC1_CH00_A00)
  */
uint16 adc_get(ADC_Num num, ADC_CH pin)
{
	uint8 ch = pin>>8;
	adc_index[num]->SQR3 &= 0XFFFFFFE0;
	adc_index[num]->SQR3 |= ch;
	adc_index[num]->CR2 |= ADC_CR2_SWSTART;
	while(!(adc_index[num]->SR&1<<1));
	return adc_index[num]->DR & 0xFFFF;
}


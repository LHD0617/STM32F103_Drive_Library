/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : 主函数
	* @author					: 满心欢喜
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/12/30
  ******************************************************************************
  * @attention
  *
  * 本程序只供学习使用，未经作者许可，不得用于其它任何用途。
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/**
	* @name		main
  * @brief  The application entry point.
	* @param  void
	* @return void
	* @Sample 
  */
int16 ad[16];
int main(void)
{
	adc_init(ADC_1, ADC1_CH00_A00);
	adc_init(ADC_1, ADC1_CH01_A01);
	adc_init(ADC_1, ADC1_CH02_A02);
	adc_init(ADC_1, ADC1_CH03_A03);
	adc_init(ADC_1, ADC1_CH04_A04);
	adc_init(ADC_2, ADC2_CH05_A05);
	adc_init(ADC_2, ADC2_CH06_A06);
	adc_init(ADC_2, ADC2_CH07_A07);
	adc_init(ADC_2, ADC2_CH08_B00);
	adc_init(ADC_2, ADC2_CH09_B01);
	while(1)
	{
		
		ad[0]	 = adc_get(ADC_1, ADC1_CH00_A00);
		ad[1]	 = adc_get(ADC_1, ADC1_CH01_A01);
		ad[2]	 = adc_get(ADC_1, ADC1_CH02_A02);
		ad[3]	 = adc_get(ADC_1, ADC1_CH03_A03);
		ad[4]	 = adc_get(ADC_1, ADC1_CH04_A04);
		ad[5]	 = adc_get(ADC_2, ADC2_CH05_A05);
		ad[6]	 = adc_get(ADC_2, ADC2_CH06_A06);
		ad[7]	 = adc_get(ADC_2, ADC2_CH07_A07);
		ad[8]	 = adc_get(ADC_2, ADC2_CH08_B00);
		ad[9]	 = adc_get(ADC_2, ADC2_CH09_B01);
		rt_thread_mdelay(20);
	}
}



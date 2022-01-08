/**
  ******************************************************************************
  * @file           : pwm.h
  * @brief          : PWM����
	* @author					: ���Ļ�ϲ
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/1/8
  ******************************************************************************
  * @attention
  *
  * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;��
  *
  ******************************************************************************
  */
#ifndef _PWM_H
#define _PWM_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "common.h"
#include "gpio.h"

/*����PWM����ö������*/
typedef enum
{
	//��ֵ���
	//λ9:8	Ϊͨ���� 0,1,2,3
	//λ7:6	ΪREMAP�Ĵ�����ӳ����ֵ
	//λ5:4 Ϊ���ŷ���	A,B,C
	//λ3:0	Ϊ���ű��	0,1,2,3,...,15
	
	TIM1_CH01_A08	= 0x0008,
	TIM1_CH02_A09	= 0x0109,
	TIM1_CH03_A10	= 0x020A,
	TIM1_CH04_A11	= 0x030B,
	
	//����A00, A01ͬʱʹ��  A14, B03ͬʱʹ��  A02, A03ͬʱʹ��  B10, B11ͬʱʹ��
	TIM2_CH01_A00	= 0x0000, TIM2_CH01_A15	= 0x004F,
	TIM2_CH02_A01	= 0x0101, TIM2_CH02_B03	= 0x0153,
	TIM2_CH03_A02	= 0x0202, TIM2_CH01_B10	= 0x029A,
	TIM2_CH04_A03	= 0x0303, TIM2_CH01_B11	= 0x039B,
	
	//����A06, A07ͬʱʹ��  B04, B05ͬʱʹ��
	TIM3_CH01_A06	= 0x0006, TIM3_CH01_B04	= 0x0094,
	TIM3_CH02_A07	= 0x0107, TIM3_CH02_B05	= 0x0195,
	TIM3_CH03_B00	= 0x0210,
	TIM3_CH04_B01	= 0x0311,
	
	TIM4_CH01_B06	= 0x0016,
	TIM4_CH02_B07	= 0x0117,
	TIM4_CH03_B08	= 0x0218,
	TIM4_CH04_B09	= 0x0319,
	
}PWM_CH;

/*����PWM��ʱ��ö������*/
typedef enum
{
	PWM_TIM1,
	PWM_TIM2,
	PWM_TIM3,
	PWM_TIM4,
}PWM_TIM_Num;



/*��������*/
void pwm_init(PWM_TIM_Num num, PWM_CH pin, uint16 freq, uint16 duty);
void pwm_duty(PWM_TIM_Num num, PWM_CH pin, uint16 duty);



#endif



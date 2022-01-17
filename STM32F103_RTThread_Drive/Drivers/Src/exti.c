/**
  ******************************************************************************
  * @file           : exti.
  * @brief          : �ⲿ�ж�����
	* @author					: ���Ļ�ϲ
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2022/1/8
  ******************************************************************************
  * @attention
  *
  * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;��
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "exti.h"

/**
	* @name		exti_init
  * @brief  The application entry point.
	* @param  pin		���ű��		(P(A,B,C)0-15)
	* @param  mode	�ж�ģʽ		EXTI_Rising, EXTI_Falling, EXTI_Reverse
	* @param  PreemptionPriority	��ռ���ȼ� (0-3)
	* @param  SubPriority					���ж����ȼ� (0-3)
	* @return void
	* @Sample 
  */
void exti_init(GPIO_Num pin, Exti_Mode mode, uint8 PreemptionPriority, uint8 SubPriority)
{
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	gpio_init(pin, GPI, 1, GPI_PULL_UD, GPIO_SPEED_50MHZ);
	AFIO->EXTICR[(pin&0x0F)>>2] &= ~(0x0F<<((pin&0x03)*4));
	AFIO->EXTICR[(pin&0x0F)>>2] = Get_Region(pin)<<((pin&0x03)*4);
	EXTI->IMR |= 0x01<<Get_Pin(pin);
	if(mode & 0x01)	EXTI->FTSR |= 0x01<<Get_Pin(pin);
	if(mode & 0x02)	EXTI->RTSR |= 0x01<<Get_Pin(pin);
	if(Get_Pin(pin) == 0x00)									nvic_init(PreemptionPriority, SubPriority, EXTI0_IRQn);
	if(Get_Pin(pin) == 0x01)									nvic_init(PreemptionPriority, SubPriority, EXTI1_IRQn);
	if(Get_Pin(pin) == 0x02)									nvic_init(PreemptionPriority, SubPriority, EXTI2_IRQn);
	if(Get_Pin(pin) == 0x03)									nvic_init(PreemptionPriority, SubPriority, EXTI3_IRQn);
	if(Get_Pin(pin) == 0x04)									nvic_init(PreemptionPriority, SubPriority, EXTI4_IRQn);
	if(5<=Get_Pin(pin)&&Get_Pin(pin)<=9)			nvic_init(PreemptionPriority, SubPriority, EXTI9_5_IRQn);
	if(10<=Get_Pin(pin)&&Get_Pin(pin)<=15)		nvic_init(PreemptionPriority, SubPriority, EXTI15_10_IRQn);
}


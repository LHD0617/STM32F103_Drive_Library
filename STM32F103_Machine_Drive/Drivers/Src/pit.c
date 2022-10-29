/**
  ******************************************************************************
  * @file           : pit.h
  * @brief          : PIT����
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

/* Includes ------------------------------------------------------------------*/
#include "pit.h"

TIM_TypeDef *pit_tim_index[4] = {TIM1, TIM2, TIM3, TIM4};
IRQn_Type tim_irq[4] = {TIM1_UP_IRQn, TIM2_IRQn, TIM3_IRQn, TIM4_IRQn};

/**
	* @name		pit_init_ms
  * @brief  PIT�жϳ�ʼ��(ms)
	* @param  num	��ʱ��(1-4)
	* @param  ms (0-65535)
	* @param  PreemptionPriority	��ռ���ȼ� (0-3)
	* @param  SubPriority					���ж����ȼ� (0-3)
	* @return void
	* @Sample pit_init_ms(PIT_TIM1, 100, 2, 2)
  */
void pit_init_ms(PIT_TIM_Num num, uint16 ms, uint8 PreemptionPriority, uint8 SubPriority)
{
	if(num == PIT_TIM1)	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	else								RCC->APB1ENR |= 0x01<<(num-1);
	pit_tim_index[num]->PSC = 7199;
	pit_tim_index[num]->ARR = 10*ms-1;
	pit_tim_index[num]->DIER |= TIM_DIER_UIE;
	pit_tim_index[num]->CR1 |= TIM_CR1_CEN;
	nvic_init(PreemptionPriority, SubPriority, tim_irq[num]);
}




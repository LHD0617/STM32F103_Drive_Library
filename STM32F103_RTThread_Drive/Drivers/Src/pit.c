/**
  ******************************************************************************
  * @file           : pit.h
  * @brief          : PIT驱动
	* @author					: 满心欢喜
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/1/8
  ******************************************************************************
  * @attention
  *
  * 本程序只供学习使用，未经作者许可，不得用于其它任何用途。
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "pit.h"

TIM_TypeDef *tim_index[4] = {TIM1, TIM2, TIM3, TIM4};
IRQn_Type tim_irq[4] = {TIM1_UP_IRQn, TIM2_IRQn, TIM3_IRQn, TIM4_IRQn};

/**
	* @name		pit_init_ms
  * @brief  PIT中断初始化(ms)
	* @param  num	定时器(1-4)
	* @param  ms (0-65535)
	* @param  PreemptionPriority	抢占优先级 (0-3)
	* @param  SubPriority					子中断优先级 (0-3)
	* @return void
	* @Sample pit_init_ms(PIT_TIM1, 100, 2, 2)
  */
void pit_init_ms(PIT_TIM_Num num, uint16 ms, uint8 PreemptionPriority, uint8 SubPriority)
{
	if(num == PIT_TIM1)	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	else								RCC->APB1ENR |= 0x01<<(num-1);
	tim_index[num]->PSC = 7199;
	tim_index[num]->ARR = 10*ms-1;
	tim_index[num]->DIER |= TIM_DIER_UIE;
	tim_index[num]->CR1 |= TIM_CR1_CEN;
	nvic_init(PreemptionPriority, SubPriority, tim_irq[num]);
}




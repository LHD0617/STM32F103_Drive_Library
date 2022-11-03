/**
  ******************************************************************************
  * @file           : pwm.c
  * @brief          : PWM驱动
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
#include "pwm.h"

TIM_TypeDef *pwm_tim_index[4] = {TIM1, TIM2, TIM3, TIM4};

/**
	* @name		pwm_init
	* @brief	PWM初始化
	* @param  num		定时器编号  (1, 2, 3, 4)
	* @param  pin		PWM输出引脚 (可在pwm.h文件中选择)
	* @param  freq	PWM频率			(0-7200)Hz 务必为7200的因素 如:7200 3600 1200......
	* @param  duty	占空比			(0-10000)
	* @return void
	* @Sample pwm_init(PWM_TIM1, TIM1_CH01_A08, 50, 100)
  */
void pwm_init(PWM_TIM_Num num, PWM_CH pin, uint16 freq, uint16 duty)
{
	if(num == PWM_TIM1)	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN, TIM1->BDTR |= TIM_BDTR_MOE;
	else								RCC->APB1ENR |= 0x01<<(num-1);
	gpio_init((GPIO_Num)(pin&0x3F), GPO, 1, GPO_AF_PUSH_PULL, GPIO_SPEED_50MHZ);
	if(pin&0xC0)
	{
		RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
		AFIO->MAPR |= (pin&0xC0)<<(num*2);
	}
	pwm_tim_index[num]->PSC = 7200/freq-1;
	pwm_tim_index[num]->ARR = 9999;
	if(pin&0x0200)
	{
		if(pin&0x0100)
		{
			pwm_tim_index[num]->CCMR2 &= ~TIM_CCMR2_CC4S;
			pwm_tim_index[num]->CCMR2 &= ~TIM_CCMR2_OC4M;
			pwm_tim_index[num]->CCMR2 |= 0x06<<12;
			pwm_tim_index[num]->CCMR2 |= TIM_CCMR2_OC4PE;
			pwm_tim_index[num]->CCR4	=  duty;
		}
		else
		{
			pwm_tim_index[num]->CCMR2 &= ~TIM_CCMR2_CC3S;
			pwm_tim_index[num]->CCMR2 &= ~TIM_CCMR2_OC3M;
			pwm_tim_index[num]->CCMR2 |= 0x06<<4;
			pwm_tim_index[num]->CCMR2 |= TIM_CCMR2_OC3PE;
			pwm_tim_index[num]->CCR3	=  duty;
		}
	}
	else
	{
		if(pin&0x0100)
		{
			pwm_tim_index[num]->CCMR1 &= ~TIM_CCMR1_CC2S;
			pwm_tim_index[num]->CCMR1 &= ~TIM_CCMR1_OC2M;
			pwm_tim_index[num]->CCMR1 |= 0x06<<12;
			pwm_tim_index[num]->CCMR1 |= TIM_CCMR1_OC2PE;
			pwm_tim_index[num]->CCR2	=  duty;
		}
		else
		{
			pwm_tim_index[num]->CCMR1 &= ~TIM_CCMR1_CC1S;
			pwm_tim_index[num]->CCMR1 &= ~TIM_CCMR1_OC1M;
			pwm_tim_index[num]->CCMR1 |= 0x06<<4;
			pwm_tim_index[num]->CCMR1 |= TIM_CCMR1_OC1PE;
			pwm_tim_index[num]->CCR1	=  duty;
		}
	}
	pwm_tim_index[num]->CCER |= 0x01<<((pin>>8)*4);
	pwm_tim_index[num]->CR1  |= TIM_CR1_ARPE;
	pwm_tim_index[num]->CR1  |= TIM_CR1_CEN;
}

/**
	* @name		pwm_duty
	* @brief	PWM设置占空比
	* @param  num		定时器编号  (1, 2, 3, 4)
	* @param  pin		PWM输出引脚 (可在pwm.h文件中选择)
	* @param  duty	占空比			(0-10000)
	* @return void
	* @Sample pwm_duty(PWM_TIM1, TIM1_CH01_A08, 100)
  */
void pwm_duty(PWM_TIM_Num num, PWM_CH pin, uint16 duty)
{
	switch(pin>>8)
	{
		case 0:	pwm_tim_index[num]->CCR1	=  duty;	break;
		case 1:	pwm_tim_index[num]->CCR1	=  duty;	break;
		case 2:	pwm_tim_index[num]->CCR1	=  duty;	break;
		case 3:	pwm_tim_index[num]->CCR1	=  duty;	break;
	}
}


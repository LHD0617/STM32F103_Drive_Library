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
int main(void)
{
	uint16 i;
	pwm_init(PWM_TIM1, TIM1_CH01_A08, 50, 100);
	pwm_init(PWM_TIM1, TIM1_CH02_A09, 50, 200);
	pwm_init(PWM_TIM1, TIM1_CH03_A10, 50, 300);
	pwm_init(PWM_TIM1, TIM1_CH04_A11, 50, 500);
	while(1)
	{
		pwm_duty(PWM_TIM1, TIM1_CH01_A08, i+=100);
		if (i>=10000) i=0;
		rt_thread_mdelay(20);
	}
}



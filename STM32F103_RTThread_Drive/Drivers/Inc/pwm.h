/**
  ******************************************************************************
  * @file           : pwm.h
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
#ifndef _PWM_H
#define _PWM_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "common.h"
#include "gpio.h"

/*设置PWM引脚枚举类型*/
typedef enum
{
	//数值组成
	//位9:8	为通道号 0,1,2,3
	//位7:6	为REMAP寄存器重映射数值
	//位5:4 为引脚分组	A,B,C
	//位3:0	为引脚编号	0,1,2,3,...,15
	
	TIM1_CH01_A08	= 0x0008,
	TIM1_CH02_A09	= 0x0109,
	TIM1_CH03_A10	= 0x020A,
	TIM1_CH04_A11	= 0x030B,
	
	//此组A00, A01同时使用  A14, B03同时使用  A02, A03同时使用  B10, B11同时使用
	TIM2_CH01_A00	= 0x0000, TIM2_CH01_A15	= 0x004F,
	TIM2_CH02_A01	= 0x0101, TIM2_CH02_B03	= 0x0153,
	TIM2_CH03_A02	= 0x0202, TIM2_CH01_B10	= 0x029A,
	TIM2_CH04_A03	= 0x0303, TIM2_CH01_B11	= 0x039B,
	
	//此组A06, A07同时使用  B04, B05同时使用
	TIM3_CH01_A06	= 0x0006, TIM3_CH01_B04	= 0x0094,
	TIM3_CH02_A07	= 0x0107, TIM3_CH02_B05	= 0x0195,
	TIM3_CH03_B00	= 0x0210,
	TIM3_CH04_B01	= 0x0311,
	
	TIM4_CH01_B06	= 0x0016,
	TIM4_CH02_B07	= 0x0117,
	TIM4_CH03_B08	= 0x0218,
	TIM4_CH04_B09	= 0x0319,
	
}PWM_CH;

/*设置PWM定时器枚举类型*/
typedef enum
{
	PWM_TIM1,
	PWM_TIM2,
	PWM_TIM3,
	PWM_TIM4,
}PWM_TIM_Num;



/*函数声明*/
void pwm_init(PWM_TIM_Num num, PWM_CH pin, uint16 freq, uint16 duty);
void pwm_duty(PWM_TIM_Num num, PWM_CH pin, uint16 duty);



#endif



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
#ifndef _PIT_H
#define _PIT_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "nvic.h"

/*设置PIT定时器枚举类型*/
typedef enum
{
	PIT_TIM1,
	PIT_TIM2,
	PIT_TIM3,
	PIT_TIM4,
}PIT_TIM_Num;

/*函数声明*/
void pit_init_ms(PIT_TIM_Num num, uint16 ms, uint8 PreemptionPriority, uint8 SubPriority);


#endif


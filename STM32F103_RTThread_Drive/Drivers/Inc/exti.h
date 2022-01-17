/**
  ******************************************************************************
  * @file           : exti.h
  * @brief          : 外部中断驱动
	* @author					: 满心欢喜
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2022/1/8
  ******************************************************************************
  * @attention
  *
  * 本程序只供学习使用，未经作者许可，不得用于其它任何用途。
  *
  ******************************************************************************
  */
#ifndef _EXTI_H
#define _EXTI_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "common.h"
#include "gpio.h"
#include "nvic.h"

/*定义中断类型枚举类型*/
typedef enum
{
  EXTI_Rising 	= 0x01,		//上升沿触发
  EXTI_Falling 	= 0x02, 	//下降沿触发 
  EXTI_Reverse 	= 0x03,		//跳变沿触发
}Exti_Mode;




/*函数声明*/
void exti_init(GPIO_Num pin, Exti_Mode mode, uint8 PreemptionPriority, uint8 SubPriority);



#endif



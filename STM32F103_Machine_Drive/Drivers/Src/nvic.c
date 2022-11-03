/**
  ******************************************************************************
  * @file           : nvic.c
  * @brief          : 中断控制器
	* @author					: 满心欢喜
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/12/31
  ******************************************************************************
  * @attention
  *
  * 本程序只供学习使用，未经作者许可，不得用于其它任何用途。
  *
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/
#include "nvic.h"

/**
	* @name		nvic_PriorityGroupConfig
	* @brief  NVIC分组函数
	* @param  PreemptionPriority			抢占中断优先级
	* @param  SubPriority							子中断优先级
						中断优先级务必设置在规定范围之内否则可能产生意想不到的错误
	* @param  Channel 								中断编号
	* @return void
	* @Sample nvic_init(3, 3, USART1_IRQn)
  */
void nvic_init(uint8 PreemptionPriority, uint8 SubPriority, uint8 Channel)
{
	uint32 temp;
	temp = PreemptionPriority<<(4-NVIC_Group);
	temp |= SubPriority&(0x0f>>NVIC_Group);
	temp &= 0xf;
	NVIC->ISER[Channel/32] |= (1<<Channel%32);
	NVIC->IP[Channel]|=temp<<4;
}


/**
	* @name		nvic_PriorityGroupConfig
	* @brief  NVIC分组函数
	* @param  nvic_Group	分组号	0-4共五组
	*					组 0： 0 位抢占优先级， 4 位响应优先级
	*					组 1： 1 位抢占优先级， 3 位响应优先级
	*					组 2： 2 位抢占优先级， 2 位响应优先级
	*					组 3： 3 位抢占优先级， 1 位响应优先级
	*					组 4： 4 位抢占优先级， 0 位响应优先级
	* @return void
	* @Sample nvic_PriorityGroupConfig(NVIC_Group)
  */
void nvic_PriorityGroupConfig(uint8 Group)
{
	uint32 temp1,temp2;
	temp1=(~Group) & 0x07;
	temp1 <<= 8;
	temp2 = SCB->AIRCR;
	temp2 &= 0X0000F8FF;
	temp2 |= 0X05FA0000;
	temp2 |= temp1;
	SCB->AIRCR = temp2;
}


/**
  ******************************************************************************
  * @file           : nvic.h
  * @brief          : 中断控制器
	* @author					: 满心欢喜
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/12/31
  ******************************************************************************
  * @attention
  *
  * 本程序只供学习使用，未经作者许可，不得用于其它任何用途。
	*	已在系统初始化中进行配置中断分组,默认分组为 NVIC_Group 宏定义,可修改NVIC_Group调整默认中断分组
  *
  ******************************************************************************
  */
#ifndef _NVIC_H
#define _NVIC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx.h"
#include "common.h"

/*默认配置中断分组为组二  2 位抢占优先级,2 位响应优先级*/
#define NVIC_Group	2

void nvic_init(uint8 PreemptionPriority, uint8 SubPriority, uint8 Channel);
void nvic_PriorityGroupConfig(uint8 nvic_Group);

#endif



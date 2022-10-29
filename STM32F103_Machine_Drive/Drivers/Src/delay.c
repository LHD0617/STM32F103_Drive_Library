/**
  ******************************************************************************
  * @file           : delay.c
  * @brief          : 主函数
	* @author					: 满心欢喜
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/01/23
  ******************************************************************************
  * @attention
  *
  * 本程序只供学习使用，未经作者许可，不得用于其它任何用途。
  *
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/
#include "delay.h"

/**
	* @name		delay_us
	* @brief  微秒延时函数
	* @param  us	延时微秒数   0 ~ 2^24
	* @return void
	* @Sample delay_us(2)
  */
void delay_us(uint32 us)
{
	us = (1<<25) <= us ? (1<<25) - 1 : us;
	//LOAD（载入数值）= t（计时时间，单位：秒） x T（频率，单位：Hz）
	SysTick->LOAD = us * (72000000 / 8000000);
	SysTick->VAL = 0;
	SysTick->CTRL = 0x01;
	while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
	SysTick->CTRL &= ~(0x01<<SysTick_CTRL_ENABLE_Pos);
}

/**
	* @name		delay_ms
	* @brief  毫秒延时函数
	* @param  ms	毫秒微秒数   0 ~ 1864
	* @return void
	* @Sample delay_ms(100)
  */
void delay_ms(uint16 ms)
{
	ms = 1864 <= ms ? 1864 : ms;
	SysTick->LOAD = ms * (72000000 / 8000);
	SysTick->VAL = 0;
	SysTick->CTRL = 0x01;
	while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
	SysTick->CTRL &= ~(0x01<<SysTick_CTRL_ENABLE_Pos);
}



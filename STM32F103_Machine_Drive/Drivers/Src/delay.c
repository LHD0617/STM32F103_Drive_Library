/**
  ******************************************************************************
  * @file           : delay.c
  * @brief          : ������
	* @author					: ���Ļ�ϲ
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/01/23
  ******************************************************************************
  * @attention
  *
  * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;��
  *
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/
#include "delay.h"

/**
	* @name		delay_us
	* @brief  ΢����ʱ����
	* @param  us	��ʱ΢����   0 ~ 2^24
	* @return void
	* @Sample delay_us(2)
  */
void delay_us(uint32 us)
{
	us = (1<<25) <= us ? (1<<25) - 1 : us;
	//LOAD��������ֵ��= t����ʱʱ�䣬��λ���룩 x T��Ƶ�ʣ���λ��Hz��
	SysTick->LOAD = us * (72000000 / 8000000);
	SysTick->VAL = 0;
	SysTick->CTRL = 0x01;
	while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
	SysTick->CTRL &= ~(0x01<<SysTick_CTRL_ENABLE_Pos);
}

/**
	* @name		delay_ms
	* @brief  ������ʱ����
	* @param  ms	����΢����   0 ~ 1864
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



/**
  ******************************************************************************
  * @file           : pit.h
  * @brief          : PIT����
	* @author					: ���Ļ�ϲ
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/1/8
  ******************************************************************************
  * @attention
  *
  * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;��
  *
  ******************************************************************************
  */
#ifndef _PIT_H
#define _PIT_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "IRQHandler.h"
#include "nvic.h"

/*����PIT��ʱ��ö������*/
typedef enum
{
	PIT_TIM1,
	PIT_TIM2,
	PIT_TIM3,
	PIT_TIM4,
}PIT_TIM_Num;

/*��������*/
void pit_init_ms(PIT_TIM_Num num, uint16 ms, uint8 PreemptionPriority, uint8 SubPriority);


#endif


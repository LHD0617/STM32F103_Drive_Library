/**
  ******************************************************************************
  * @file           : exti.h
  * @brief          : �ⲿ�ж�����
	* @author					: ���Ļ�ϲ
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2022/1/8
  ******************************************************************************
  * @attention
  *
  * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;��
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

/*�����ж�����ö������*/
typedef enum
{
  EXTI_Rising 	= 0x01,		//�����ش���
  EXTI_Falling 	= 0x02, 	//�½��ش��� 
  EXTI_Reverse 	= 0x03,		//�����ش���
}Exti_Mode;




/*��������*/
void exti_init(GPIO_Num pin, Exti_Mode mode, uint8 PreemptionPriority, uint8 SubPriority);



#endif



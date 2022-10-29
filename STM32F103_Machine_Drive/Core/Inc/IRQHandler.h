/**
  ******************************************************************************
  * @file           : IRQHandler.h
  * @brief          : �жϷ�����
	* @author					: ���Ļ�ϲ
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/12/31
  ******************************************************************************
  * @attention
  *
  * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;��
  *
  ******************************************************************************
  */

#ifndef _IRQHANDLER_H
#define _IRQHANDLER_H
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/*UART�жϱ�־λ*/
extern vuint8 UART1_Interrupt_flag;
extern vuint8 UART2_Interrupt_flag;
extern vuint8 UART3_Interrupt_flag;

/*PIT�жϱ�־λ*/
extern vuint8 PIT1_Interrupt_flag;
extern vuint8 PIT2_Interrupt_flag;
extern vuint8 PIT3_Interrupt_flag;
extern vuint8 PIT4_Interrupt_flag;


#endif

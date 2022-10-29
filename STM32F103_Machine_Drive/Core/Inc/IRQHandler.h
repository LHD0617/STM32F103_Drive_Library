/**
  ******************************************************************************
  * @file           : IRQHandler.h
  * @brief          : 中断服务函数
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

#ifndef _IRQHANDLER_H
#define _IRQHANDLER_H
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/*UART中断标志位*/
extern vuint8 UART1_Interrupt_flag;
extern vuint8 UART2_Interrupt_flag;
extern vuint8 UART3_Interrupt_flag;

/*PIT中断标志位*/
extern vuint8 PIT1_Interrupt_flag;
extern vuint8 PIT2_Interrupt_flag;
extern vuint8 PIT3_Interrupt_flag;
extern vuint8 PIT4_Interrupt_flag;


#endif

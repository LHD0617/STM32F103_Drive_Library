/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : ������
	* @author					: ���Ļ�ϲ
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/12/30
  ******************************************************************************
  * @attention
  *
  * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;��
  *
  ******************************************************************************
  */
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif


/*RT-Thread Debug	�˿ڲ���*/
#define 	Debug_UART					UART2
#define		Debug_Bound					115200
#define 	Debug_TX_Pin				UART2_TX_PA2
#define 	Debug_RX_Pin				UART2_RX_PA3
#define 	Debug_WordLength		WordLength_8b
#define		Debug_StopBits			StopBits_1
#define 	Debug_Parity				Parity_No

/* Includes ------------------------------------------------------------------*/
#include <rtthread.h>
#include "common.h"

/*Drivers*/
#include "gpio.h"
#include "uart.h"
#include "nvic.h"
#include "adc.h"
#include "pit.h"
#include "pwm.h"
#include "exti.h"



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

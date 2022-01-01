/**
  ******************************************************************************
  * @file           : uart.h
  * @brief          : UART����
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
#ifndef _UART_H
#define _UART_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "IRQHandler.h"
#include "common.h"
#include "gpio.h"
#include "nvic.h"

/*APB2������ʱ��Ƶ��Ϊ72Mhz*/
#define 	PCLK2		72000000UL
/*APB1������ʱ��Ƶ��Ϊ36Mhz*/
#define 	PCLK1		36000000UL


/*����UARTö������*/
typedef enum
{
	//UART1 ��������(����ʹ��ͬ��˿�)
	UART1_TX_PA9 ,				UART1_TX_PB6 ,
	UART1_RX_PA10,				UART1_RX_PB7 ,
	
	//UART2 ��������
	UART2_TX_PA2 ,
	UART2_RX_PA3 ,
	
	//UART2 ��������
	UART3_TX_PB10,
	UART3_RX_PB11,
	
}UART_Pin;

/*����UART����ö������*/
typedef enum
{
	UART1,
	UART2,
	UART3,
}UART_Num;

/*����UART�ֳ�ö������*/
typedef enum
{
	WordLength_8b,																	//һ����ʼλ�� 8������λ��n��ֹͣλ��
	WordLength_9b,																	//һ����ʼλ�� 9������λ��n��ֹͣλ��
}UART_WordLength;

/*����UARTֹͣλö������*/
typedef enum
{
	StopBits_1,                											//1��ֹͣλ��
	StopBits_0_5,              											//0.5��ֹͣλ��
	StopBits_2,                											//2��ֹͣλ��
	StopBits_1_5,              											//1.5��ֹͣλ��
}UART_StopBits;

/*����UARTУ��ѡ��ö������*/
typedef enum
{
	Parity_No,                 											//��У��
	Parity_Even,               											//żУ��
	Parity_Odd,                											//��У��
}UART_Parity;

/*��������*/
void uart_init(UART_Num num, uint32 bound, UART_Pin TX_Pin, UART_Pin RX_Pin, UART_WordLength length, UART_StopBits stop, UART_Parity parity);
void uart_putchar(UART_Num num, uint8 dat);
void uart_putbuff(UART_Num num, uint8* buff, uint32 len);
void uart_putstr(UART_Num num, const char *str);
uint8 uart_getchar(UART_Num num);
uint8 uart_query(UART_Num num, uint8 *dat);



#endif


/**
  ******************************************************************************
  * @file           : uart.h
  * @brief          : UART驱动
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
#ifndef _UART_H
#define _UART_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f103xb.h"
#include "stm32f1xx_it.h"
#include "stm32f1xx.h"
#include "common.h"
#include "gpio.h"
#include "nvic.h"

/*APB2外设桥时钟频率为72Mhz*/
#define 	PCLK2		72000000UL
/*APB1外设桥时钟频率为36Mhz*/
#define 	PCLK1		36000000UL


/*设置UART枚举类型*/
typedef enum
{
	//UART1 可用引脚(必须使用同组端口)
	UART1_TX_PA9 ,				UART1_TX_PB6 ,
	UART1_RX_PA10,				UART1_RX_PB7 ,
	
	//UART2 可用引脚
	UART2_TX_PA2 ,
	UART2_RX_PA3 ,
	
	//UART2 可用引脚
	UART3_TX_PB10,
	UART3_RX_PB11,
	
}UART_Pin;

/*设置UART引脚枚举类型*/
typedef enum
{
	UART1,
	UART2,
	UART3,
}UART_Num;

/*设置UART字长枚举类型*/
typedef enum
{
	WordLength_8b,																	//一个起始位， 8个数据位，n个停止位。
	WordLength_9b,																	//一个起始位， 9个数据位，n个停止位。
}UART_WordLength;

/*设置UART停止位枚举类型*/
typedef enum
{
	StopBits_1,                											//1个停止位。
	StopBits_0_5,              											//0.5个停止位。
	StopBits_2,                											//2个停止位。
	StopBits_1_5,              											//1.5个停止位。
}UART_StopBits;

/*设置UART校验选择枚举类型*/
typedef enum
{
	Parity_No,                 											//无校验
	Parity_Even,               											//偶校验
	Parity_Odd,                											//奇校验
}UART_Parity;

/*函数声明*/
void uart_init(UART_Num num, uint32 bound, UART_Pin TX_Pin, UART_Pin RX_Pin, UART_WordLength length, UART_StopBits stop, UART_Parity parity);
void uart_putchar(UART_Num num, uint8 dat);
void uart_putbuff(UART_Num num, uint8* buff, uint32 len);
void uart_putstr(UART_Num num, const char *str);
uint8 uart_getchar(UART_Num num);
uint8 uart_query(UART_Num num, uint8 *dat);



#endif


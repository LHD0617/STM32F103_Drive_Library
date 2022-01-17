/**
  ******************************************************************************
  * @file           : gpio.h
  * @brief          : GPIO驱动
	* @author					: 满心欢喜
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/12/30
  ******************************************************************************
  * @attention
  *
  * 本程序只供学习使用，未经作者许可，不得用于其它任何用途。
  *
  ******************************************************************************
  */
#ifndef _GPIO_H
#define _GPIO_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx.h"
#include "common.h"

/*设置引脚枚举类型*/
typedef enum
{
    PA0,  PA1,  PA2,  PA3,  PA4,  PA5,  PA6,  PA7,  PA8,  PA9,  PA10, PA11, PA12, PA13, PA14, PA15,
                 
    PB0,  PB1,  PB2,  PB3,  PB4,  PB5,  PB6,  PB7,  PB8,  PB9,  PB10, PB11, PB12, PB13, PB14, PB15,
                 
    PC0,  PC1,  PC2,  PC3,  PC4,  PC5,  PC6,  PC7,  PC8,  PC9,  PC10, PC11, PC12, PC13, PC14, PC15,
}GPIO_Num;

/*设置IO口方向枚举类型*/
typedef enum
{
	GPI,										// 定义管脚输入
	GPO,										// 定义管脚输出
}GPIO_Dir;

/*设置IO口模式枚举类型*/
typedef enum
{
	GPI_ANAOG_IN 				= 0x00,						// 定义管脚模拟输入
	GPI_FLOATING_IN			= 0x04,						// 定义管脚浮空输入
	GPI_PULL_UD					= 0x08,						// 定义管脚上下拉输入

	GPO_PUSH_PULL				=	0x00,						// 定义管脚推挽输出
	GPO_OPEN_DTAIN			= 0x04,						// 定义管脚开漏输出
	GPO_AF_PUSH_PULL		=	0x08,						// 定义管脚复用推挽输出
	GPO_AF_OPEN_DTAIN		= 0x0C,						// 定义管脚复用开漏输出
	
}GPIO_Mode;

/*设置IO口速度枚举类型*/
typedef enum
{
		GPIO_SPEED_2MHZ		= 0x02,
		GPIO_SPEED_10MHZ	=	0x01,
		GPIO_SPEED_50MHZ	=	0x03,
}GPIO_Speed;

/*获取引脚模块号（A,B,C）*/
#define Get_Region(pin)		(pin>>4)

/*获取引脚序号*/
#define Get_Pin(pin)			(pin&0x0f)


/*函数声明*/
void gpio_init(GPIO_Num pin, GPIO_Dir dir, uint8 dat, GPIO_Mode mode, GPIO_Speed speed);
void gpio_set(GPIO_Num pin, uint8 dat);
uint8 gpio_get(GPIO_Num pin);
void gpio_dir(GPIO_Num pin, GPIO_Dir dir, GPIO_Mode mode, GPIO_Speed speed);
void gpio_reverse(GPIO_Num pin);


#endif


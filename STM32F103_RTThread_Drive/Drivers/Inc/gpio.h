/**
  ******************************************************************************
  * @file           : gpio.h
  * @brief          : GPIO����
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
#ifndef _GPIO_H
#define _GPIO_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx.h"
#include "common.h"

/*��������ö������*/
typedef enum
{
    PA0,  PA1,  PA2,  PA3,  PA4,  PA5,  PA6,  PA7,  PA8,  PA9,  PA10, PA11, PA12, PA13, PA14, PA15,
                 
    PB0,  PB1,  PB2,  PB3,  PB4,  PB5,  PB6,  PB7,  PB8,  PB9,  PB10, PB11, PB12, PB13, PB14, PB15,
                 
    PC0,  PC1,  PC2,  PC3,  PC4,  PC5,  PC6,  PC7,  PC8,  PC9,  PC10, PC11, PC12, PC13, PC14, PC15,
}GPIO_Num;

/*����IO�ڷ���ö������*/
typedef enum
{
	GPI,										// ����ܽ�����
	GPO,										// ����ܽ����
}GPIO_Dir;

/*����IO��ģʽö������*/
typedef enum
{
	GPI_ANAOG_IN 				= 0x00,						// ����ܽ�ģ������
	GPI_FLOATING_IN			= 0x04,						// ����ܽŸ�������
	GPI_PULL_UD					= 0x08,						// ����ܽ�����������

	GPO_PUSH_PULL				=	0x00,						// ����ܽ��������
	GPO_OPEN_DTAIN			= 0x04,						// ����ܽſ�©���
	GPO_AF_PUSH_PULL		=	0x08,						// ����ܽŸ����������
	GPO_AF_OPEN_DTAIN		= 0x0C,						// ����ܽŸ��ÿ�©���
	
}GPIO_Mode;

/*����IO���ٶ�ö������*/
typedef enum
{
		GPIO_SPEED_2MHZ		= 0x02,
		GPIO_SPEED_10MHZ	=	0x01,
		GPIO_SPEED_50MHZ	=	0x03,
}GPIO_Speed;

/*��ȡ����ģ��ţ�A,B,C��*/
#define Get_Region(pin)		(pin>>4)

/*��ȡ�������*/
#define Get_Pin(pin)			(pin&0x0f)


/*��������*/
void gpio_init(GPIO_Num pin, GPIO_Dir dir, uint8 dat, GPIO_Mode mode, GPIO_Speed speed);
void gpio_set(GPIO_Num pin, uint8 dat);
uint8 gpio_get(GPIO_Num pin);
void gpio_dir(GPIO_Num pin, GPIO_Dir dir, GPIO_Mode mode, GPIO_Speed speed);
void gpio_reverse(GPIO_Num pin);


#endif


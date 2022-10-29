/**
  ******************************************************************************
  * @file           : gpio.c
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

GPIO_TypeDef *gpio_group[4] = {GPIOA, GPIOB, GPIOC, GPIOD};


/**
	* @name		gpio_init
  * @brief  GPIO��ʼ��
	* @param  pin		���ű��		(P(A,B,C)0-15)
	* @param  dir		���ŷ���		GPO���	GPI����
	* @param  dat		��ʼ����ƽ	0Ϊ�͵�ƽ	1Ϊ�ߵ�ƽ
	* @param  mode	����ģʽ		��gpio.h�ļ��п�ѡ��
	* @param  speed	�������		��gpio.h�ļ��п�ѡ��
	* @return void
	* @Sample gpio_init(PC13, GPO, 0, GPO_PUSH_PULL, GPIO_SPEED_50MHZ)
	* @Sample gpio_init(PC13, GPI, 1, GPI_PULL_UD	 , GPIO_SPEED_50MHZ)
  */
void gpio_init(GPIO_Num pin, GPIO_Dir dir, uint8 dat, GPIO_Mode mode, GPIO_Speed speed)
{
	uint8 Reg = Get_Region(pin);
	uint8 Pin = Get_Pin(pin);
	RCC->APB2ENR |= 0x01<<(2+Reg);
	if(dir == GPI)
	{
		if(Pin<8)
		{
			gpio_group[Reg]->CRL &= ~(0x0f<<Pin*4);
			gpio_group[Reg]->CRL |= mode<<Pin*4;
		}
		else
		{
			gpio_group[Reg]->CRH &= ~(0x0f<<(Pin-8)*4);
			gpio_group[Reg]->CRH |= mode<<(Pin-8)*4;
		}
	}
	if(dir == GPO)
	{
		if(Pin<8)
		{
			gpio_group[Reg]->CRL &= ~(0x0f<<Pin*4);
			gpio_group[Reg]->CRL |= mode<<Pin*4;
			gpio_group[Reg]->CRL |= speed<<Pin*4;
		}
		else
		{
			gpio_group[Reg]->CRH &= ~(0x0f<<(Pin-8)*4);
			gpio_group[Reg]->CRH |= mode<<(Pin-8)*4;
			gpio_group[Reg]->CRH |= speed<<(Pin-8)*4;
		}
	}
	if(dat)	gpio_group[Reg]->ODR |= 0x01<<Pin;
	else		gpio_group[Reg]->ODR &= ~(0x01<<Pin);
}

/**
	* @name		gpio_set
  * @brief  GPIO�������ŵ�ƽ
	* @param  pin		���ű��		(P(A,B,C)0-15)
	* @param  dat		��ʼ����ƽ	0Ϊ�͵�ƽ	1Ϊ�ߵ�ƽ
	* @return void
	* @Sample gpio_set(PC13, 0)
  */
void gpio_set(GPIO_Num pin, uint8 dat)
{
	if(dat)	gpio_group[Get_Region(pin)]->ODR |= 0x01<<Get_Pin(pin);
	else		gpio_group[Get_Region(pin)]->ODR &= ~(0x01<<Get_Pin(pin));
}

/**
	* @name		gpio_get
  * @brief  GPIO��ȡ���ŵ�ƽ
	* @param  pin		���ű��		(P(A,B,C)0-15)
	* @return ���ŵ�ƽ	0Ϊ�͵�ƽ 1Ϊ�ߵ�ƽ
	* @Sample gpio_get(PA0)
  */
uint8 gpio_get(GPIO_Num pin)
{
	if(gpio_group[Get_Region(pin)]->IDR & 0x01<<Get_Pin(pin))		return 1;
	else																												return 0;
}

/**
	* @name		gpio_dir
  * @brief  GPIO�������ŷ���
	* @param  pin		���ű��		(P(A,B,C)0-15)
	* @param  dir		���ŷ���		GPO���	GPI����
	* @param  mode	����ģʽ		��gpio.h�ļ��п�ѡ��
	* @param  speed	�������		��gpio.h�ļ��п�ѡ��
	* @return void
	* @Sample gpio_dir(PC13, GPO, GPO_PUSH_PULL, GPIO_SPEED_50MHZ)
	* @Sample	gpio_dir(PC13, GPI, GPI_PULL_UD  , GPIO_SPEED_50MHZ)
  */
void gpio_dir(GPIO_Num pin, GPIO_Dir dir, GPIO_Mode mode, GPIO_Speed speed)
{
	uint8 Reg = Get_Region(pin);
	uint8 Pin = Get_Pin(pin);
	if(dir == GPI)
	{
		if(Pin<8)
		{
			gpio_group[Reg]->CRL &= ~(0x0f<<Pin*4);
			gpio_group[Reg]->CRL |= mode<<Pin*4;
		}
		else
		{
			gpio_group[Reg]->CRH &= ~(0x0f<<(Pin-8)*4);
			gpio_group[Reg]->CRH |= mode<<(Pin-8)*4;
		}
	}
	if(dir == GPO)
	{
		if(Pin<8)
		{
			gpio_group[Reg]->CRL &= ~(0x0f<<Pin*4);
			gpio_group[Reg]->CRL |= mode<<Pin*4;
			gpio_group[Reg]->CRL |= speed<<Pin*4;
		}
		else
		{
			gpio_group[Reg]->CRH &= ~(0x0f<<(Pin-8)*4);
			gpio_group[Reg]->CRH |= mode<<(Pin-8)*4;
			gpio_group[Reg]->CRH |= speed<<(Pin-8)*4;
		}
	}
}

/**
	* @name		gpio_reverse
  * @brief  GPIO���ŷ�ת��ƽ
	* @param  pin		���ű��		(P(A,B,C)0-15)
	* @return void
	* @Sample gpio_reverse(PC13)
  */
void gpio_reverse(GPIO_Num pin)
{
	gpio_group[Get_Region(pin)]->ODR ^= 0x01<<Get_Pin(pin);
}





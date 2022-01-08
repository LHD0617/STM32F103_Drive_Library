/**
  ******************************************************************************
  * @file           : main.c
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/**
	* @name		main
  * @brief  The application entry point.
	* @param  void
	* @return void
	* @Sample 
  */
int main(void)
{
	gpio_init(PC13, GPO, 0, GPO_PUSH_PULL, GPIO_SPEED_50MHZ);
	pit_init_ms(PIT_TIM3, 100, 2, 2);
	while(1)
	{
		if(PIT3_Interrupt_flag)
		{
			PIT3_Interrupt_flag = 0;
			gpio_reverse(PC13);
		}
	}
}



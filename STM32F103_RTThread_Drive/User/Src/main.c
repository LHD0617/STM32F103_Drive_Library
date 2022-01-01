/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : 主函数
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
	while(1)
	{
		gpio_reverse(PC13);
		rt_thread_mdelay(100);
	}
}


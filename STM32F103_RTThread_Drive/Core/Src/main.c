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
int sum1=0,sum2=0;
void thread_entry1(void* parameter);
void thread_entry2(void* parameter);
	
int main(void)
{
	rt_thread_t tid1 = rt_thread_create("tid1",thread_entry1,RT_NULL,128,5,10);
	rt_thread_t tid2 = rt_thread_create("tid2",thread_entry2,RT_NULL,128,5,10);
	rt_thread_startup(tid1);
	rt_thread_startup(tid2);
}

void thread_entry1(void* parameter)
{
	while(1)
	{
		sum1 += 1;
		rt_thread_mdelay(100);
	}
}

void thread_entry2(void* parameter)
{
	while(1)
	{
		sum2 += 1;
		rt_thread_mdelay(1000);
	}
}


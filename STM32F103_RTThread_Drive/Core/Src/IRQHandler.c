/**
  ******************************************************************************
  * @file           : IRQHandler.c
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

/* Includes ------------------------------------------------------------------*/
#include "IRQHandler.h"

/*UART中断标志位*/
vuint8 UART1_Interrupt_flag = 0;
vuint8 UART2_Interrupt_flag = 0;
vuint8 UART3_Interrupt_flag = 0;

/*PIT中断标志位*/
vuint8 PIT1_Interrupt_flag = 0;
vuint8 PIT2_Interrupt_flag = 0;
vuint8 PIT3_Interrupt_flag = 0;
vuint8 PIT4_Interrupt_flag = 0;



/*Shell消息邮箱*/
extern rt_mailbox_t Shell_RX;

/**
	* @name		USART1_IRQHandler
  * @brief  UART1中断服务函数
	* @param  void
	* @return void
	* @Sample 
  */
void USART1_IRQHandler(void)
{
	rt_interrupt_enter();
	if((USART1->SR & USART_SR_RXNE) && (USART1->CR1 & USART_CR1_RXNEIE))
	{
		UART1_Interrupt_flag = 1;
		USART1->SR &= ~(USART_SR_RXNE);
	}
#if Debug_UART == UART1
		uint8 dat = (USART1->DR & 0xFF);
		rt_mb_send(Shell_RX, dat);
#endif
	rt_interrupt_leave();
}

/**
	* @name		USART2_IRQHandler
  * @brief  UART2中断服务函数
	* @param  void
	* @return void
	* @Sample 
  */
void USART2_IRQHandler(void)
{
	rt_interrupt_enter();
	if((USART2->SR & USART_SR_RXNE) && (USART2->CR1 & USART_CR1_RXNEIE))
	{
		UART2_Interrupt_flag = 1;
		USART2->SR &= ~(USART_SR_RXNE);
#if Debug_UART == UART2
		uint8 dat = (USART2->DR & 0xFF);
		rt_mb_send(Shell_RX, dat);
#endif
	}
	rt_interrupt_leave();
}

/**
	* @name		USART3_IRQHandler
  * @brief  UART3中断服务函数
	* @param  void
	* @return void
	* @Sample 
  */
void USART3_IRQHandler(void)
{
	rt_interrupt_enter();
	if((USART3->SR & USART_SR_RXNE) && (USART3->CR1 & USART_CR1_RXNEIE))
	{
		UART3_Interrupt_flag = 1;
		USART3->SR &= ~(USART_SR_RXNE);
	}
#if Debug_UART == UART3
		uint8 dat = (USART3->DR & 0xFF);
		rt_mb_send(Shell_RX, dat);
#endif
	rt_interrupt_leave();
}

/**
	* @name		TIM1_UP_IRQHandler
  * @brief  TIM1向上计数中断服务函数
	* @param  void
	* @return void
	* @Sample 
  */
void TIM1_UP_IRQHandler(void)
{
	rt_interrupt_enter();
	
	if(TIM1->SR & 0x01)
	{
		TIM1->SR &= ~TIM_SR_UIF;
		PIT1_Interrupt_flag = 1;
		
	}
	
	rt_interrupt_leave();
}

/**
	* @name		TIM2_IRQHandler
  * @brief  TIM2中断服务函数
	* @param  void
	* @return void
	* @Sample 
  */
void TIM2_IRQHandler(void)
{
	rt_interrupt_enter();
	
	if(TIM2->SR & 0x01)
	{
		TIM2->SR &= ~TIM_SR_UIF;
		PIT2_Interrupt_flag = 1;
		
	}
	
	rt_interrupt_leave();
}

/**
	* @name		TIM3_IRQHandler
  * @brief  TIM3中断服务函数
	* @param  void
	* @return void
	* @Sample 
  */
void TIM3_IRQHandler(void)
{
	rt_interrupt_enter();
	
	if(TIM3->SR & 0x01)
	{
		TIM3->SR &= ~TIM_SR_UIF;
		PIT3_Interrupt_flag = 1;
		
	}
	
	rt_interrupt_leave();
}

/**
	* @name		TIM4_IRQHandler
  * @brief  TIM4中断服务函数
	* @param  void
	* @return void
	* @Sample 
  */
void TIM4_IRQHandler(void)
{
	rt_interrupt_enter();
	
	if(TIM4->SR & 0x01)
	{
		TIM4->SR &= ~TIM_SR_UIF;
		PIT4_Interrupt_flag = 1;
		
	}
	
	rt_interrupt_leave();
}

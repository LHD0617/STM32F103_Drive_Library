/**
  ******************************************************************************
  * @file           : IRQHandler.c
  * @brief          : �жϷ�����
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

/* Includes ------------------------------------------------------------------*/
#include "IRQHandler.h"

/*UART�жϱ�־λ*/
vuint8 UART1_Interrupt_flag = 0;
vuint8 UART2_Interrupt_flag = 0;
vuint8 UART3_Interrupt_flag = 0;

/*Shell��Ϣ����*/
extern rt_mailbox_t Shell_RX;

/**
	* @name		USART1_IRQHandler
  * @brief  UART1�жϷ�����
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
  * @brief  UART2�жϷ�����
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
  * @brief  UART3�жϷ�����
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





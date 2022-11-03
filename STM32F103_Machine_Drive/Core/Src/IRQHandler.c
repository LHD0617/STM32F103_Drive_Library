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

/*PIT�жϱ�־λ*/
vuint8 PIT1_Interrupt_flag = 0;
vuint8 PIT2_Interrupt_flag = 0;
vuint8 PIT3_Interrupt_flag = 0;
vuint8 PIT4_Interrupt_flag = 0;


/**
	* @name		USART1_IRQHandler
  * @brief  UART1�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void USART1_IRQHandler(void)
{
	if((USART1->SR & USART_SR_RXNE) && (USART1->CR1 & USART_CR1_RXNEIE))
	{
		UART1_Interrupt_flag = 1;
		USART1->SR &= ~(USART_SR_RXNE);
	}
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
	if((USART2->SR & USART_SR_RXNE) && (USART2->CR1 & USART_CR1_RXNEIE))
	{
		UART2_Interrupt_flag = 1;
		USART2->SR &= ~(USART_SR_RXNE);
	}
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
	if((USART3->SR & USART_SR_RXNE) && (USART3->CR1 & USART_CR1_RXNEIE))
	{
		UART3_Interrupt_flag = 1;
		USART3->SR &= ~(USART_SR_RXNE);
	}
}

/**
	* @name		TIM1_UP_IRQHandler
  * @brief  TIM1���ϼ����жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void TIM1_UP_IRQHandler(void)
{
	if(TIM1->SR & 0x01)
	{
		TIM1->SR &= ~TIM_SR_UIF;
		PIT1_Interrupt_flag = 1;
		
	}
}

/**
	* @name		TIM2_IRQHandler
  * @brief  TIM2�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void TIM2_IRQHandler(void)
{
	if(TIM2->SR & 0x01)
	{
		TIM2->SR &= ~TIM_SR_UIF;
		PIT2_Interrupt_flag = 1;
		
	}
}

/**
	* @name		TIM3_IRQHandler
  * @brief  TIM3�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void TIM3_IRQHandler(void)
{
	if(TIM3->SR & 0x01)
	{
		TIM3->SR &= ~TIM_SR_UIF;
		PIT3_Interrupt_flag = 1;
		
	}
}

/**
	* @name		TIM4_IRQHandler
  * @brief  TIM4�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void TIM4_IRQHandler(void)
{
	if(TIM4->SR & 0x01)
	{
		TIM4->SR &= ~TIM_SR_UIF;
		PIT4_Interrupt_flag = 1;
		
	}
}

/**
	* @name		EXTI0_IRQHandler
  * @brief 	LINE0�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void EXTI0_IRQHandler(void)
{
	if((EXTI->PR & EXTI_PR_PR0) && (EXTI->IMR & EXTI_IMR_IM0))
	{
		EXTI->PR |= EXTI_PR_PR0;
		
	}
}

/**
	* @name		EXTI1_IRQHandler
  * @brief 	LINE1�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void EXTI1_IRQHandler(void)
{
	if((EXTI->PR & EXTI_PR_PR1) && (EXTI->IMR & EXTI_IMR_IM1))
	{
		EXTI->PR |= EXTI_PR_PR1;

	}
}

/**
	* @name		EXTI2_IRQHandler
  * @brief 	LINE2�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void EXTI2_IRQHandler(void)
{
	if((EXTI->PR & EXTI_PR_PR2) && (EXTI->IMR & EXTI_IMR_IM2))
	{
		EXTI->PR |= EXTI_PR_PR2;

	}
}

/**
	* @name		EXTI3_IRQHandler
  * @brief 	LINE3�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void EXTI3_IRQHandler(void)
{
	if((EXTI->PR & EXTI_PR_PR3) && (EXTI->IMR & EXTI_IMR_IM3))
	{
		EXTI->PR |= EXTI_PR_PR3;

	}
}

/**
	* @name		EXTI4_IRQHandler
  * @brief 	LINE4�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void EXTI4_IRQHandler(void)
{
	if((EXTI->PR & EXTI_PR_PR4) && (EXTI->IMR & EXTI_IMR_IM4))
	{
		EXTI->PR |= EXTI_PR_PR4;

	}
}

/**
	* @name		EXTI9_5_IRQHandler
  * @brief 	LINE9_5�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void EXTI9_5_IRQHandler(void)
{
	if((EXTI->PR & 0x03E0) && (EXTI->IMR & 0x03E0))
	{
		EXTI->PR |= 0x1F<<5;

	}
}

/**
	* @name		EXTI15_10_IRQHandler
  * @brief 	LINE15_10�жϷ�����
	* @param  void
	* @return void
	* @Sample 
  */
void EXTI15_10_IRQHandler(void)
{
	if((EXTI->PR & 0xFC00) && (EXTI->IMR & 0xFC00))
	{
		EXTI->PR |= 0x3F<<10;

	}
}



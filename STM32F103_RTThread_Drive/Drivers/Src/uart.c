/**
  ******************************************************************************
  * @file           : uart.c
  * @brief          : UART����
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
#include "uart.h"

USART_TypeDef *uart_index[3] = {USART1, USART2, USART3};
IRQn_Type uart_irq[3] = {USART1_IRQn, USART2_IRQn, USART3_IRQn};

/**
	* @name		uart_init
  * @brief  UART��ʼ��
	* @param  num				ģ���	UART1 UART2 UART3
	* @param  bound			������
	* @param  TX_Pin		TX����(��uart.h�ļ���ѡ��)
	* @param  RX_Pin		RX����(��uart.h�ļ���ѡ��)
	* @param  length		UART����λ�ֳ�	WordLength_8b,WordLength_9b
	* @param  stop			UARTֹͣλ	StopBits_1,StopBits_0_5,StopBits_2,StopBits_1_5
	* @param  parity		UARTУ��λ	Parity_No,Parity_Even,Parity_Odd
	* @return void
	* @Sample uart_init(UART1, 115200, UART1_TX_PA9, UART1_RX_PA10, WordLength_8b, StopBits_1, Parity_No)
  */
void uart_init(UART_Num num, uint32 bound, UART_Pin TX_Pin, UART_Pin RX_Pin, UART_WordLength length, UART_StopBits stop, UART_Parity parity)
{
	float temp;
	uint16 mantissa;
	uint16 fraction;
	if(num == UART1)	temp=(float)(PCLK2)/(bound*16);
	else							temp=(float)(PCLK1)/(bound*16);
	mantissa=temp;
	fraction=(temp-mantissa)*16; 
	mantissa<<=4;
	mantissa+=fraction;
	switch(num)
	{
		case UART1:
			RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
			if(TX_Pin==UART1_TX_PA9&&RX_Pin==UART1_RX_PA10)
			{
				gpio_init(PA9 , GPO, 0, GPO_AF_PUSH_PULL, GPIO_SPEED_50MHZ);
				gpio_init(PA10, GPI, 1, GPI_PULL_UD     , GPIO_SPEED_50MHZ);
			}
			else if(TX_Pin==UART1_TX_PB6&&RX_Pin==UART1_RX_PB7)
			{
				RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
				AFIO->MAPR |= AFIO_MAPR_USART1_REMAP;
				gpio_init(PB6 , GPO, 0, GPO_AF_PUSH_PULL, GPIO_SPEED_50MHZ);
				gpio_init(PB7 , GPI, 1, GPI_PULL_UD     , GPIO_SPEED_50MHZ);
			}
			RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST;
			RCC->APB2RSTR &= ~(RCC_APB2RSTR_USART1RST);
		break;
		case UART2:
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
			gpio_init(PA2 , GPO, 0, GPO_AF_PUSH_PULL, GPIO_SPEED_50MHZ);
			gpio_init(PA3 , GPI, 1, GPI_PULL_UD     , GPIO_SPEED_50MHZ);
			RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
			RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART2RST);
		break;
		case UART3:
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
			gpio_init(PB10, GPO, 0, GPO_AF_PUSH_PULL, GPIO_SPEED_50MHZ);
			gpio_init(PB11, GPI, 1, GPI_PULL_UD     , GPIO_SPEED_50MHZ);
			RCC->APB1RSTR |= RCC_APB1RSTR_USART3RST;
			RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART3RST);
		break;
	}
	uart_index[num]->BRR = mantissa;
	uart_index[num]->CR1 |= USART_CR1_M*length;
	uart_index[num]->CR2 |= stop<<USART_CR2_STOP_Pos;
	if(parity)	uart_index[num]->CR1 |= (parity+1)<<USART_CR1_PS_Pos;
	uart_index[num]->CR1 |= (USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE);
	while((uart_index[num]->SR&USART_SR_TC)==0);
	nvic_init(3, 3, uart_irq[num]);
}

/**
	* @name		uart_putchar
	* @brief  UART����һ���ֽ�
	* @param  num	ģ���	UART1 UART2 UART3
	* @param  dat	����
	* @return void
	* @Sample uart_putchar(UART1, 0xCC);
  */
void uart_putchar(UART_Num num, uint8 dat)
{
	uart_index[num]->DR = dat;
	while((uart_index[num]->SR&USART_SR_TC)==0);
}

/**
	* @name		uart_putbuff
  * @brief  UART��������
	* @param  num		ģ���	UART1 UART2 UART3
	* @param  buff	�����׵�ַ
	* @param  len		���鳤��
	* @return void
	* @Sample uart_putbuff(UART1, test, 13);
  */
void uart_putbuff(UART_Num num, uint8* buff, uint32 len)
{
	uint32 i=0;
	while(len--)	uart_putchar(num, buff[i++]);
}

/**
	* @name		uart_putstr
  * @brief  UART�����ַ���
	* @param  num		ģ���	UART1 UART2 UART3
	* @param  str		�ַ���
	* @return void
	* @Sample uart_putbuff(UART1, test, 13);
  */
void uart_putstr(UART_Num num, const char *str)
{
	while(*str)	uart_putchar(num, *str++);
}
/**
	* @name		uart_getchar
  * @brief  UART����һ���ֽ�(�������ա�������ѭ���ȴ�ֱ�����յ�����)
	* @param  num		ģ���	UART1 UART2 UART3
	* @return ���յ�������
	* @Sample 
  */
uint8 uart_getchar(UART_Num num)
{
	if(num == UART1)	while(UART1_Interrupt_flag==0);
	UART1_Interrupt_flag = 0;
	if(num == UART2)	while(UART2_Interrupt_flag==0);
	UART2_Interrupt_flag = 0;
	if(num == UART3)	while(UART3_Interrupt_flag==0);
	UART3_Interrupt_flag = 0;
	return uart_index[num]->DR & 0xFF;
}

/**
	* @name		uart_query
  * @brief  UART����һ���ֽ�(��ѯ���ա�������ѭ���ȴ�ֱ�����յ�����)
	* @param  num		ģ���	UART1 UART2 UART3
	* @param  dat		���յ��������浽��Ŀ�ĵ�ַ
	* @return �����Ƿ�ɹ�  1Ϊ���ճɹ� 0Ϊ���ɹ�
	* @Sample 
  */
uint8 uart_query(UART_Num num, uint8 *dat)
{
	if(num == UART1&&UART1_Interrupt_flag)
	{
		UART1_Interrupt_flag = 0;
		*dat = uart_index[num]->DR & 0xFF;
		return 1;
	}
	else if(num == UART2&&UART2_Interrupt_flag)
	{
		UART2_Interrupt_flag = 0;
		*dat = uart_index[num]->DR & 0xFF;
		return 1;
	}
	else if(num == UART3&&UART3_Interrupt_flag)
	{
		UART3_Interrupt_flag = 0;
		*dat = uart_index[num]->DR & 0xFF;
		return 1;
	}
	else	return 0;
}






/**
  ******************************************************************************
  * @file           : nvic.c
  * @brief          : �жϿ�����
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
#include "nvic.h"

/**
	* @name		nvic_PriorityGroupConfig
  * @brief  NVIC���麯��
	* @param  PreemptionPriority			��ռ�ж����ȼ�
	* @param  SubPriority							���ж����ȼ�
						�ж����ȼ���������ڹ涨��Χ֮�ڷ�����ܲ������벻���Ĵ���
	* @param  Channel 								�жϱ��
	* @return void
	* @Sample nvic_init(3, 3, USART1_IRQn)
  */
void nvic_init(uint8 PreemptionPriority, uint8 SubPriority, uint8 Channel)
{
	uint32 temp;
	temp = PreemptionPriority<<(4-NVIC_Group);
	temp |= SubPriority&(0x0f>>NVIC_Group);
	temp &= 0xf;
	NVIC->ISER[Channel/32] |= (1<<Channel%32);
	NVIC->IP[Channel]|=temp<<4;
}


/**
	* @name		nvic_PriorityGroupConfig
  * @brief  NVIC���麯��
	* @param  nvic_Group	�����	0-4������
	*					�� 0�� 0 λ��ռ���ȼ��� 4 λ��Ӧ���ȼ�
	*					�� 1�� 1 λ��ռ���ȼ��� 3 λ��Ӧ���ȼ�
	*					�� 2�� 2 λ��ռ���ȼ��� 2 λ��Ӧ���ȼ�
	*					�� 3�� 3 λ��ռ���ȼ��� 1 λ��Ӧ���ȼ�
	*					�� 4�� 4 λ��ռ���ȼ��� 0 λ��Ӧ���ȼ�
	* @return void
	* @Sample nvic_PriorityGroupConfig(NVIC_Group)
  */
void nvic_PriorityGroupConfig(uint8 Group)
{
	uint32 temp1,temp2;
	temp1=(~Group) & 0x07;
	temp1 <<= 8;
	temp2 = SCB->AIRCR;
	temp2 &= 0X0000F8FF;
	temp2 |= 0X05FA0000;
	temp2 |= temp1;
	SCB->AIRCR = temp2;
}


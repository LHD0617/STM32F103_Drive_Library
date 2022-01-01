/**
  ******************************************************************************
  * @file           : nvic.h
  * @brief          : �жϿ�����
	* @author					: ���Ļ�ϲ
	* @contact				: QQ:320388825 VX:LHD0617_
	* @Created				: 2021/12/31
  ******************************************************************************
  * @attention
  *
  * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;��
	*	����ϵͳ��ʼ���н��������жϷ���,Ĭ�Ϸ���Ϊ NVIC_Group �궨��,���޸�NVIC_Group����Ĭ���жϷ���
  *
  ******************************************************************************
  */
#ifndef _NVIC_H
#define _NVIC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx.h"
#include "common.h"

/*Ĭ�������жϷ���Ϊ���  2 λ��ռ���ȼ�,2 λ��Ӧ���ȼ�*/
#define NVIC_Group	2

void nvic_init(uint8 PreemptionPriority, uint8 SubPriority, uint8 Channel);
void nvic_PriorityGroupConfig(uint8 nvic_Group);

#endif



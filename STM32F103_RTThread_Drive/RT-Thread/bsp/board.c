/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-05-24                  the first version
 */

#include <rthw.h>
#include <rtthread.h>

#include "main.h"
#include "nvic.h"
#include "system_stm32f1xx.h"

/*Shell消息邮箱*/
rt_mailbox_t Shell_RX;
#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
/*
 * Please modify RT_HEAP_SIZE if you enable RT_USING_HEAP
 * the RT_HEAP_SIZE max value = (sram size - ZI size), 1024 means 1024 bytes
 */
#define RT_HEAP_SIZE (15*1024)
static rt_uint8_t rt_heap[RT_HEAP_SIZE];

RT_WEAK void *rt_heap_begin_get(void)
{
    return rt_heap;
}

RT_WEAK void *rt_heap_end_get(void)
{
    return rt_heap + RT_HEAP_SIZE;
}
#endif

void SysTick_Handler(void)
{
    rt_interrupt_enter();
    
    rt_tick_increase();

    rt_interrupt_leave();
}

/**
 * This function will initial your board.
 */
void rt_hw_board_init(void)
{
    extern void SystemClock_Config(void);
    
    SystemCoreClockUpdate();
		/* 
     * 1: OS Tick Configuration
     * Enable the hardware timer and call the rt_os_tick_callback function
     * periodically with the frequency RT_TICK_PER_SECOND. 
     */
		SysTick_Config(SystemCoreClock/RT_TICK_PER_SECOND);
		//配置中断分组为组二  2 位抢占优先级,2 位响应优先级
		nvic_PriorityGroupConfig(NVIC_Group);
    /* Call components board initial (use INIT_BOARD_EXPORT()) */
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
    rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get());
#endif
		//创建Shell邮箱
		Shell_RX = rt_mb_create("Shell_RX", 10, RT_IPC_FLAG_FIFO);
}

#ifdef RT_USING_CONSOLE

static int Debug_uart_init(void)
{
	uart_init(Debug_UART, Debug_Bound, Debug_TX_Pin, Debug_RX_Pin, Debug_WordLength, Debug_StopBits, Debug_Parity);
	return 0;
}
INIT_BOARD_EXPORT(Debug_uart_init);

void rt_hw_console_output(const char *str)
{
    rt_size_t i = 0, size = 0;
    char a = '\r';
    size = rt_strlen(str);

    for (i = 0; i < size; i++)
    {
        if (*(str + i) == '\n')
        {
            uart_putchar(Debug_UART, a);
        }
				uart_putchar(Debug_UART, *(str + i));
    }
}
#endif

#ifdef RT_USING_FINSH
char rt_hw_console_getchar(void)
{
		uint32 ch;
    rt_mb_recv(Shell_RX, &ch, RT_WAITING_FOREVER);
    return (int8)ch;
}
#endif




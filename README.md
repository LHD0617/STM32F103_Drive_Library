# STM32F103驱动库

## 关于本项目
主控：STM32F103C8T6

使用Keil 5.2.7 作为开发环境

作为一名智能车参赛选手对于STM32的HAL库使用起来并不熟悉，我就在想可不可以自己写一个类似于智能车驱动库那样的STM32驱动库。

正好放寒假在家没什么事干，顺便学习一下GitHub，所以创建了此开源驱动库，作为一个GitHub的学习项目吧。此项目永久开源，希望大家也能为此驱动库添砖加瓦，当然大家也可以使用此驱动库来进行开发项目。
大家可以自由在main分支上面进行增添，更改，但要写明更新日志。


## 2021/12/30更新
1.使用STM32CubeMX创建RT-Thread工程

2.移除官方HAL库，优化工程结构

3.改写SystemInit    配置时钟主频为72Mhz APB2:72Mhz AHB:72Mhz APB1:32Mhz

4.配置Systick心跳时钟


## 2021/12/31更新
1.添加GPIO驱动

    void gpio_init(GPIO_Num pin, GPIO_Dir dir, uint8 dat, GPIO_Mode mode, GPIO_Speed speed);

    void gpio_set(GPIO_Num pin, uint8 dat);

    uint8 gpio_get(GPIO_Num pin);

    void gpio_dir(GPIO_Num pin, GPIO_Dir dir, GPIO_Mode mode, GPIO_Speed speed);

    void gpio_reverse(GPIO_Num pin);

## 2022/1/1更新
1.添加UART驱动

    void uart_init(UART_Num num, uint32 bound, UART_Pin TX_Pin, UART_Pin RX_Pin, UART_WordLength length, UART_StopBits stop, UART_Parity parity);

    void uart_putchar(UART_Num num, uint8 dat);

    void uart_putbuff(UART_Num num, uint8* buff, uint32 len);

    void uart_putstr(UART_Num num, const char *str);

    uint8 uart_getchar(UART_Num num);

    uint8 uart_query(UART_Num num, uint8 *dat);

2.添加NVIC中断管理

    void nvic_init(uint8 PreemptionPriority, uint8 SubPriority, uint8 Channel);

    void nvic_PriorityGroupConfig(uint8 nvic_Group);

    已在rt_hw_board_init中进行配置中断分组，默认为组二2 位抢占优先级,2 位响应优先级，可在nvic.h文件中修改NVIC_Group宏定义进行配置中断分组

3.添加中断服务函数

    IRQHandler.c

4.添加RT-Thread Finsh组件（默认使用UART2为调试串口可在main.h中修改）

## 2022/1/7更新
1.添加adc驱动

    void adc_init(ADC_Num num, ADC_CH pin);
    
    uint16 adc_get(ADC_Num num, ADC_CH pin);

## 2022/1/8更新
1.关闭JTAG-DP，启用SW-DP

2.添加pit定时中断驱动

    void pit_init_ms(PIT_TIM_Num num, uint16 ms, uint8 PreemptionPriority, uint8 SubPriority);

3.添加pwm驱动

    void pwm_init(PWM_TIM_Num num, PWM_CH pin, uint16 freq, uint16 duty);
    
    void pwm_duty(PWM_TIM_Num num, PWM_CH pin, uint16 duty);

## 2022/1/17
1.添加EXTI外部中断程序

    void exti_init(GPIO_Num pin, Exti_Mode mode, uint8 PreemptionPriority, uint8 SubPriority);
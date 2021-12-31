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

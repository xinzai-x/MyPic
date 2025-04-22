#include "stm32f10x.h"                  // Device header

void Encoder_Init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_TimeBaseInitStruct.TIM_Prescaler = 1-1;       // 预分频值
    TIM_TimeBaseInitStruct.TIM_Period = 65536 - 1;        // 自动重装载值(ARR)
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数模式
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;     // 时钟分频
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);     // x为具体定时器编号
    
    TIM_ICInitTypeDef TIM_ICInitStruct;
    TIM_ICStructInit(&TIM_ICInitStruct);
    TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;   // 通道1
    TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;      // 不分频
    TIM_ICInitStruct.TIM_ICFilter = 0xF;            // 无滤波
    TIM_ICInit(TIM3, &TIM_ICInitStruct);
    TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;   // 通道1
    TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;      // 不分频
    TIM_ICInitStruct.TIM_ICFilter = 0xF;            // 无滤波
    TIM_ICInit(TIM3, &TIM_ICInitStruct);
    TIM_EncoderInterfaceConfig(TIM3,
        TIM_EncoderMode_TI12,    // 同时使用CH1和CH2
        TIM_ICPolarity_Rising,   // CH1上升沿有效
        TIM_ICPolarity_Rising );
    
    TIM_Cmd(TIM3, ENABLE);

}

int16_t Encoder_Get(void)
{
    int16_t temp;
    temp = TIM_GetCounter(TIM3);
    TIM_SetCounter(TIM3, 0);
    return temp;
}

#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//    GPIO_InitTypeDef GPIO_InitStructure;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    PWM_Init();
}

void Motor_SetAngle(int8_t Speed)
{
    
    uint16_t Speed01 = 0;
//    if(Speed >= 0)
//    {
        Speed01 = Speed *2*100;
//        GPIO_SetBits(GPIOA, GPIO_Pin_4);
//        GPIO_ResetBits(GPIOA, GPIO_Pin_5);
        PWM_SetCompare3(Speed01);
//    }
//    else
//    {
//        Speed01 = Speed *2*100;
//        GPIO_SetBits(GPIOA, GPIO_Pin_5);
//        GPIO_ResetBits(GPIOA, GPIO_Pin_4);
//        PWM_SetCompare3(-Speed01);
//    }
}

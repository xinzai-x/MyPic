#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"

#define KEY_GPIO_Num GPIOE

//初始化按键函数
void KEY_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(KEY_GPIO_Num,&GPIO_InitStructure);
}

//判断按键是否按下
uint8_t Key_Judge_Press(void)
{
    uint8_t Key_flag = 0;
    if(GPIO_ReadInputDataBit(KEY_GPIO_Num,GPIO_Pin_3) == 0)
    {
        Delay_ms(40);
        if(GPIO_ReadInputDataBit(KEY_GPIO_Num,GPIO_Pin_3) == 0)
        {
            while(GPIO_ReadInputDataBit(KEY_GPIO_Num,GPIO_Pin_3) == 0);
            Delay_ms(40);
            Key_flag = 1;
        }
    }
    if(GPIO_ReadInputDataBit(KEY_GPIO_Num,GPIO_Pin_4) == 0)
    {
        Delay_ms(40);
        if(GPIO_ReadInputDataBit(KEY_GPIO_Num,GPIO_Pin_4) == 0)
        {
            while(GPIO_ReadInputDataBit(KEY_GPIO_Num,GPIO_Pin_4) == 0);
            Delay_ms(40);
            Key_flag = 2;
        }
    }
    return Key_flag;
}



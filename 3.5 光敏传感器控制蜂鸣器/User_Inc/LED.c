#include <stdint.h>
#include "stm32f10x.h"

#define LED1_GPIO_Num GPIOB
#define LED2_GPIO_Num GPIOE
#define LED_PIN_Num GPIO_Pin_5

//初始化LED灯
void LED_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = LED_PIN_Num;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(LED1_GPIO_Num,&GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = LED_PIN_Num;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(LED2_GPIO_Num,&GPIO_InitStructure);
    GPIO_SetBits(LED1_GPIO_Num,LED_PIN_Num);
    GPIO_SetBits(LED2_GPIO_Num,LED_PIN_Num);
}

//LED1开
void LED1_ON(void)
{
    GPIO_ResetBits(LED1_GPIO_Num,LED_PIN_Num);
}

//LED1关
void LED1_OFF(void)
{
    GPIO_SetBits(LED1_GPIO_Num,LED_PIN_Num);
}

//LED2开
void LED2_ON(void)
{
    GPIO_ResetBits(LED2_GPIO_Num,LED_PIN_Num);
}

//LED2关
void LED2_OFF(void)
{
    GPIO_SetBits(LED2_GPIO_Num,LED_PIN_Num);
}

//LED1翻转
void LED1_Turn(void)
{
    if(GPIO_ReadOutputDataBit(LED1_GPIO_Num,LED_PIN_Num) == 0)
    {
        GPIO_WriteBit(LED1_GPIO_Num,LED_PIN_Num,Bit_SET);
    }
    else
    {
        GPIO_WriteBit(LED1_GPIO_Num,LED_PIN_Num,Bit_RESET);
    }
}

//LED2翻转
void LED2_Turn(void)
{
    if(GPIO_ReadOutputDataBit(LED2_GPIO_Num,LED_PIN_Num) == 0)
    {
        GPIO_WriteBit(LED2_GPIO_Num,LED_PIN_Num,Bit_SET);
    }
    else
    {
        GPIO_WriteBit(LED2_GPIO_Num,LED_PIN_Num,Bit_RESET);
    }
}

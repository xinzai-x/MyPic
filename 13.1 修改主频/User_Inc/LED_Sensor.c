#include <stdint.h>
#include "stm32f10x.h"

#define LED_Sensor_GPIO_NUM GPIOB
#define LED_Sensor_GPIO_PIN GPIO_Pin_11

void LED_Sensor_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = LED_Sensor_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_Sensor_GPIO_NUM,&GPIO_InitStructure);
}

uint8_t LED_Sensor_Get(void)
{
    return GPIO_ReadInputDataBit(LED_Sensor_GPIO_NUM, LED_Sensor_GPIO_PIN);
}


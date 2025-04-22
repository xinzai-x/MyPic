#include <stdint.h>
#include "stm32f10x.h"

#define BUZZER_GPIO_NUM GPIOB
#define BUZZER_GPIO_PIN GPIO_Pin_8

void Buzzer_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = BUZZER_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BUZZER_GPIO_NUM, &GPIO_InitStructure);
    GPIO_WriteBit(BUZZER_GPIO_NUM, BUZZER_GPIO_PIN, Bit_RESET);
}

void Buzzer_OFF(void)
{
    GPIO_WriteBit(BUZZER_GPIO_NUM, BUZZER_GPIO_PIN, Bit_RESET);
}

void Buzzer_ON(void)
{
    GPIO_WriteBit(BUZZER_GPIO_NUM, BUZZER_GPIO_PIN, Bit_SET);
}

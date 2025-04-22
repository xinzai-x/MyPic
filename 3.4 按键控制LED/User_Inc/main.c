#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "KEY.h"

int main(void)
{
    LED_Init();     //初始化LED灯
    KEY_Init();     //初始化按键
    
    while(1)
    {
        //判断是否按键PE3按下
        if(Key_Judge_Press() == 1)
        {
            LED1_Turn();    //LED1翻转
        }
        else if(Key_Judge_Press() == 2)     //判断是否按键PE4按下
        {
            LED2_Turn();    //LED2翻转
        }
    }
}

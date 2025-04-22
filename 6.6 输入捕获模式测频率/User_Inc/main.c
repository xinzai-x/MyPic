#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "LED_Sensor.h"
#include "OLED.h"
#include "Timer.h"
#include "PWM.h"
#include "IC.h"

uint8_t flag = 0;
int8_t num = 0;

int main(void)
{
    OLED_Init();
    PWM_Init();
    IC_Init();
     
    OLED_ShowString(1,1,"Freq:");
    
    PWM_SetPrescaler(7200-1);
    PWM_SetCompare3(50);
    
    while(1)
    {
       OLED_ShowNum(1,6,IC_GetFreq(),5);
    }
}

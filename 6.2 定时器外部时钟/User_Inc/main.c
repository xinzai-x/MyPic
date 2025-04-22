#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "buzzer.h"
#include "LED.h"
#include "LED_Sensor.h"
#include "OLED.h"
#include "Timer.h"

uint16_t Num = 0;

int main(void)
{
    OLED_Init();
    Timer_Init();
    OLED_ShowString(1,1,"Num:");
    OLED_ShowString(2,1,"CNT:");
    
    
    while(1)
    {
        OLED_ShowNum(1, 5, Num, 4);
        OLED_ShowNum(2, 5, (uint32_t)Timer_GetCounter(), 4);
    }
}

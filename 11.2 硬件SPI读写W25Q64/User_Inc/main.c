#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "buzzer.h"
#include "LED.h"
#include "LED_Sensor.h"
#include "OLED.h"
#include "MySPI.h"

int main(void)
{
    OLED_Init();
    OLED_ShowChar(1,1,'A');
    OLED_ShowString(1,3,"Hello World!");
    
    while(1)
    {
        
    }
}

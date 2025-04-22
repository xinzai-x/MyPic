#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "buzzer.h"
#include "LED.h"
#include "LED_Sensor.h"

int main(void)
{
    Buzzer_Init();
    LED_Init();
    LED_Sensor_Init();
    
    while(1)
    {
        //当光敏传感器灯亮LED1灭
        if(LED_Sensor_Get() == 1)
        {
            LED1_ON();
            //Buzzer_ON();
        }
        else if(LED_Sensor_Get() == 0)
        {
            LED1_OFF();
            //Buzzer_OFF();
        }
    }
}

#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "buzzer.h"
#include "LED.h"
#include "LED_Sensor.h"
#include "OLED.h"
#include "CountSensor.h"

int main(void)
{
    OLED_Init();
    LED_Init();
    CountSensor_Init();
    OLED_ShowString(1,1,"count:");
    
    while(1)
    {
        OLED_ShowNum(1,7,CountSensor_Num(),5);
    }
}

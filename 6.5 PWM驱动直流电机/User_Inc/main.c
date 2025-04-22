#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "LED_Sensor.h"
#include "OLED.h"
#include "Timer.h"
#include "PWM.h"
#include "Motor.h"

uint8_t flag = 0;
int8_t num = 0;

int main(void)
{
    OLED_Init();
    Key_Init();
    Motor_Init();
     
    OLED_ShowString(1,1,"Angle:");
    
    while(1)
    {
        if(Key_GetNum() == 1)
        {
            num += 20;
            Motor_SetAngle(num);
            if(num >= 100)
                num = 0;
        }
        OLED_ShowNum(1,7,num,3);
    }
}

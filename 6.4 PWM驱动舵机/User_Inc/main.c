#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "LED_Sensor.h"
#include "OLED.h"
#include "Timer.h"
#include "PWM.h"
#include "Servo.h"

uint8_t flag = 0;
float Angle = 0;

int main(void)
{
    OLED_Init();
    Key_Init();
    PWM_Init();
     
    OLED_ShowString(1,1,"Angle:");
    
    while(1)
    {
        flag = Key_GetNum();
        if(flag == 1)
        {
            Angle += 30;
            if(Angle > 180)
                Angle = 0;
            Servo_SetAngle(Angle);
        }
        OLED_ShowNum(1,7,Angle,3);
    }
}

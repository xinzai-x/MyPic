#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "buzzer.h"
#include "LED.h"
#include "Encoder.h"
#include "OLED.h"
#include "Timer.h"

uint16_t Num = 0;

int main(void)
{
    OLED_Init();
    Timer_Init();
    Encoder_Init();
    
    
    while(1)
    {
        OLED_ShowNum(1, 5, Num, 4);
    }
}

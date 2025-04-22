#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "buzzer.h"
#include "LED.h"
#include "LED_Sensor.h"
#include "OLED.h"

int main(void)
{
    OLED_Init();
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP, ENABLE);
    
    BKP_WriteBackupRegister(BKP_DR1, 0x1234);
    BKP_ReadBackupRegister(BKP_DR1);
    
    while(1)
    {
        
    }
}

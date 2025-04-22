#include <stdint.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "buzzer.h"
#include "LED.h"
#include "LED_Sensor.h"
#include "OLED.h"
#include "Serial.h"

int main(void)
{
    OLED_Init();
    Serial_Init();
    
    //Serial_SendByte(0x41);
    
//    uint8_t MyArray[] = {0x42,0x43,0x44,0x45};
//    Serial_SendArray(MyArray,4);
    
    
//    Serial_SendString("helloworld");
    
    //Serial_SendNumber(12334,5);
    
    
    //printf("Num=%d\r\n",66);
    
//    char String[100];					//定义字符数组
//	sprintf(String, "\r\nNum3=%d", 333);//使用sprintf，把格式化字符串打印到字符数组
//	Serial_SendString(String);
    
    Serial_Printf("你好，世界");
    
    while(1)
    {
        
    }
    
}

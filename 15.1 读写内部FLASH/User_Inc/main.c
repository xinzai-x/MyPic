#include <stdint.h>
#include "stm32f10x.h"
#include "Delay.h"
#include "MyFLASH.h"
#include "Key.h"
#include "Store.h"
#include "LED_Sensor.h"
#include "OLED.h"

int main(void)
{
    uint8_t Keynum;
    OLED_Init();
    Key_Init();
    Store_Init();

    while(1)
    {
        Keynum = Key_GetNum();

        OLED_ShowString(1, 1, "Flag:");
	    OLED_ShowString(2, 1, "Data:");

        if(Keynum == 1){
            store_Data[1] ++;
            store_Data[2] += 2;
            store_Data[3] += 3;
            store_Data[4] += 4;
            Store_Save();
        }
        else if (Keynum == 2)
        {
            Store_Clear();
        }
        
        OLED_ShowHexNum(1, 6, store_Data[0], 4);	//显示Store_Data的第一位标志位
		OLED_ShowHexNum(3, 1, store_Data[1], 4);	//显示Store_Data的有效存储数据
		OLED_ShowHexNum(3, 6, store_Data[2], 4);
		OLED_ShowHexNum(4, 1, store_Data[3], 4);
		OLED_ShowHexNum(4, 6, store_Data[4], 4);

    }
}

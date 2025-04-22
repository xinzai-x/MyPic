#include "stm32f10x.h"
#include "MyFLASH.h"

uint16_t store_Data[512];

void Store_Init(void)
{
    if (MyFLASH_ReadHalfWord(0x0800fc00) != 0xa5a5)
    {
        MyFLASH_ErasePage(0x0800fc00);
        MyFLASH_WriteHalfWord(0x0800fc00, 0xa5a5);
        for (uint16_t i = 1; i < 512; i++)
        {
            MyFLASH_WriteHalfWord(0x0800fc00 + 2 * i, 0x0000);
        }
        
    }
    for (uint16_t i = 0; i < 512; i++)
    {
        store_Data[i] = MyFLASH_ReadHalfWord(0x0800fc00 + 2 * i);
    }
    
}

void Store_Save(void)
{
    MyFLASH_ErasePage(0x0800fc00);
    for (uint16_t i = 0; i < 512; i++)
    {
        MyFLASH_WriteHalfWord(0x0800fc00 + 2 * i, store_Data[i]);
    }
    
}

void Store_Clear(void)
{
    for (int i = 1; i < 512; i++)
    {
        store_Data[i] = 0x0000;
    }
    Store_Save();
}

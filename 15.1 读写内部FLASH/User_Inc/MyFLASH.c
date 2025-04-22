#include "stm32f10x.h"

uint32_t MyFLASH_ReadWord(uint32_t address)
{
    return *(__IO uint32_t*)address;
}

uint32_t MyFLASH_ReadHalfWord(uint32_t address)
{
    return *(__IO uint16_t*)address;
}

uint32_t MyFLASH_ReadByte(uint32_t address)
{
    return *(__IO uint8_t*)address;
}

void MyFLASH_EraseAllPages(void)
{
    FLASH_Unlock();
    FLASH_EraseAllPages();
    FLASH_Lock();
}

void MyFLASH_ErasePage(uint32_t address)
{
    FLASH_Unlock();
    FLASH_ErasePage(address);
    FLASH_Lock();
}

void MyFLASH_WriteWord(uint32_t address, uint32_t data)
{
    FLASH_Unlock();
    FLASH_ProgramWord(address, data);
    FLASH_Lock();
}

void MyFLASH_WriteHalfWord(uint32_t address, uint16_t data)
{
    FLASH_Unlock();
    FLASH_ProgramHalfWord(address, data);
    FLASH_Lock();
}


#ifndef __MYFLASH_H
#define __MYFLASH_H

uint32_t MyFLASH_ReadWord(uint32_t address);
uint32_t MyFLASH_ReadHalfWord(uint32_t address);
uint32_t MyFLASH_ReadByte(uint32_t address);
void MyFLASH_EraseAllPages(void);
void MyFLASH_ErasePage(uint32_t address);
void MyFLASH_WriteWord(uint32_t address, uint32_t data);
void MyFLASH_WriteHalfWord(uint32_t address, uint16_t data);

#endif

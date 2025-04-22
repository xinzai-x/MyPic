#include "stm32f10x.h"                  // Device header


void MySPI_W_SS(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOA,GPIO_Pin_4, (BitAction)BitValue);
}

void MySPI_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
     SPI_InitTypeDef SPI_InitStruct;
    
    // 结构体参数配置
    SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex; // 全双工模式
    SPI_InitStruct.SPI_Mode = SPI_Mode_Master;                     // 主机模式
    SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;                 // 8位数据格式
    SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;                        // 时钟极性（空闲时低电平）
    SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;                      // 时钟相位（第一个边沿采样）
    SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;                         // 软件NSS管理
    SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16; // 波特率分频（72MHz/16=4.5MHz）
    SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;                // 高位先发送
    SPI_InitStruct.SPI_CRCPolynomial = 7;                          // CRC多项式
    
    // 应用配置并启用SPI
    SPI_Init(SPI1, &SPI_InitStruct);
    SPI_Cmd(SPI1, ENABLE); // 使能SPI1外设
    
    MySPI_W_SS(1);
}

void MySPI_Start(void)
{
    MySPI_W_SS(0);
}

void MySPI_Stop(void)
{
    MySPI_W_SS(1);
}


uint8_t MySPI_SwapByte(uint8_t ByteSend)
{
    while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
    SPI_I2S_SendData(SPI1,ByteSend);
    
    while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
    
    return SPI_I2S_ReceiveData(SPI1);
}


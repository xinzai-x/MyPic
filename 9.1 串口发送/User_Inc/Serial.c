#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>

void Serial_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;

    // 配置TX引脚（PA9）为复用推挽输出
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;  // 复用推挽输出
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    USART_InitTypeDef USART_InitStruct;
    USART_InitStruct.USART_BaudRate = 115200;        // 波特率
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;  // 8位数据位
    USART_InitStruct.USART_StopBits = USART_StopBits_1;       // 1位停止位
    USART_InitStruct.USART_Parity = USART_Parity_No;          // 无校验位
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  // 无硬件流控制
    USART_InitStruct.USART_Mode = USART_Mode_Tx;  // 启用发送和接收模式
    USART_Init(USART1, &USART_InitStruct);
    
    USART_Cmd(USART1, ENABLE);  // 使能USART1

}

void Serial_SendByte(uint8_t Byte)
{
    USART_SendData(USART1, Byte);
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void Serial_SendArray(uint8_t *Array, uint16_t length)
{
    uint16_t i;
    for(i= 0;i <length; i++)
    {
        Serial_SendByte(Array[i]);
    }
}

void Serial_SendString(char *String)
{
    uint16_t i;
    for(i = 0; String[i] != '\0'; i++)
    {
        Serial_SendByte(String[i]);
    }
}

uint32_t Serial_Pow(uint32_t x, uint32_t y)
{
    uint32_t Result = 1;
    while(y--)
    {
        Result *= x;
    }
    return Result;
}

void Serial_SendNumber(uint32_t Number, uint8_t Length)
{
    uint8_t i;
    for(i = 0;i < Length; i++)
    {
        Serial_SendByte(Number / Serial_Pow(10, Length -i -1) %10 + '0');
    }
}

int fputc(int ch, FILE *f)
{
	Serial_SendByte(ch);			//将printf的底层重定向到自己的发送字节函数
	return ch;
}

void Serial_Printf(char *format, ...)
{
	char String[100];				//定义字符数组
	va_list arg;					//定义可变参数列表数据类型的变量arg
	va_start(arg, format);			//从format开始，接收参数列表到arg变量
	vsprintf(String, format, arg);	//使用vsprintf打印格式化字符串和参数列表到字符数组中
	va_end(arg);					//结束变量arg
	Serial_SendString(String);		//串口发送字符数组（字符串）
}


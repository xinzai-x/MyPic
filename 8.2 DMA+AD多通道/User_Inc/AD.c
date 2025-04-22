#include "stm32f10x.h"                  // Device header

uint16_t AD_Value[4];	

void AD_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);  // 例如：APB2=72MHz时，ADCCLK=12MHz

    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;          // 选择引脚（如PA0）
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;      // 模拟输入模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;   // 速度对模拟输入无影响，可设为默认值
    GPIO_Init(GPIOA, &GPIO_InitStructure);             // 应用配置

    ADC_InitTypeDef ADC_InitStructure;
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;       // 独立模式
    ADC_InitStructure.ADC_ScanConvMode = ENABLE;            // 单通道时禁用扫描模式
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;      // 单次转换模式
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; // 软件触发
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;    // 数据右对齐
    ADC_InitStructure.ADC_NbrOfChannel = 4;                  // 规则组通道数为1
    ADC_Init(ADC1, &ADC_InitStructure);

    ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_55Cycles5);
    ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, ADC_SampleTime_55Cycles5);
    
    
    DMA_InitTypeDef DMA_InitStructure;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;  // 外设地址（串口数据寄存器）
    DMA_InitStructure.DMA_MemoryBaseAddr     = (uint32_t)AD_Value;    // 内存地址（发送缓冲区）
    DMA_InitStructure.DMA_DIR                = DMA_DIR_PeripheralSRC;  // 方向：内存→外设
    DMA_InitStructure.DMA_BufferSize         = 4;                    
    DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable; 
    DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;   // 内存地址递增
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; // 外设数据宽度：8位
    DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_HalfWord;   // 内存数据宽度：8位
    DMA_InitStructure.DMA_Mode               = DMA_Mode_Normal;        // 单次传输模式
    DMA_InitStructure.DMA_Priority           = DMA_Priority_Medium;      // 通道优先级
    DMA_InitStructure.DMA_M2M                = DMA_M2M_Disable;        

    // 4. 初始化DMA通道（USART1_TX使用DMA1通道4）
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);

    DMA_Cmd(DMA1_Channel1, ENABLE);
    ADC_DMACmd(ADC1, ENABLE);
    ADC_Cmd(ADC1, ENABLE);                    // 使能ADC
    
    ADC_ResetCalibration(ADC1);               // 复位校准寄存器
    while(ADC_GetResetCalibrationStatus(ADC1)); // 等待复位完成
    ADC_StartCalibration(ADC1);               // 启动校准
    while(ADC_GetCalibrationStatus(ADC1));     // 等待校准完成
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}


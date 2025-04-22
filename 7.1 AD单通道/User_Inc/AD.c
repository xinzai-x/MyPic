#include "stm32f10x.h"                  // Device header

void AD_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);  // 例如：APB2=72MHz时，ADCCLK=12MHz

    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;          // 选择引脚（如PA0）
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;      // 模拟输入模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;   // 速度对模拟输入无影响，可设为默认值
    GPIO_Init(GPIOA, &GPIO_InitStructure);             // 应用配置

    ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);  // 通道0为第1个转换

    ADC_InitTypeDef ADC_InitStructure;
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;       // 独立模式
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;            // 单通道时禁用扫描模式
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;      // 单次转换模式
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; // 软件触发
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;    // 数据右对齐
    ADC_InitStructure.ADC_NbrOfChannel = 1;                  // 规则组通道数为1
    ADC_Init(ADC1, &ADC_InitStructure);
    
    ADC_Cmd(ADC1, ENABLE);                    // 使能ADC
    
    ADC_ResetCalibration(ADC1);               // 复位校准寄存器
    while(ADC_GetResetCalibrationStatus(ADC1)); // 等待复位完成
    ADC_StartCalibration(ADC1);               // 启动校准
    while(ADC_GetCalibrationStatus(ADC1));     // 等待校准完成
    
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);    // 启动转换
}

uint16_t AD_GetValue(void)
{
    return ADC_GetConversionValue(ADC1); // 读取结果
}

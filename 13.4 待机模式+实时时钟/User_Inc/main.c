#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MyRTC.h"

int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	MyRTC_Init();		//RTC初始化
	
	/*显示静态字符串*/
	OLED_ShowString(1, 1, "CNT:");
	OLED_ShowString(2, 1, "ALR:");
	OLED_ShowString(3, 1, "ALRF: :");
	
	while (1)
	{
		
		
		OLED_ShowNum(1, 6, RTC_GetCounter(), 10);	//显示32位的秒计数器
	}
}

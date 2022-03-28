#include "main.h"


volatile unsigned char  LED0_value=0;

/**
  * @brief  LED指示灯初始化函数
**/
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
		LED0_OFF;
}


/**
  * @brief  分析平台下发的LED控制命令
**/
void LED_CmdCtl(void)
{
		if((NULL != strstr((const char *)usart2_cmd_buf, "LED01")))  //约定平台控制命令"LED11"为打开红色LED灯
		{
				LED0_ON;	
				LED0_value=1;
				delay_ms(500);
				LED0_OFF;	
				LED0_value=0;
			
		}
		if((NULL != strstr((const char *)usart2_cmd_buf, "LED00")))  //约定平台控制命令"LED10"为关闭红色LED灯
		{
				LED0_OFF;	
				LED0_value=0;
		}
}

/**
  * @brief  LED指示灯操作函数，点亮和熄灭指示灯
**/
void LED_Switch(const uint8_t statu,const uint8_t mode)
{
		if(statu)
		{
				LED0_OFF;
				if(mode&0x01)
				{
						LED0_ON;
				}
		}
		else
		{
				if(mode&0x01)
				{
						LED0_OFF;
				}
		}
}


/**
  * @brief  获取LED的当前状态值
**/
void LED_GetValue(void)
{
		if(!GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0))
		{
				LED0_value=1;
		}
		else
		{
				LED0_value=0;
		}
}








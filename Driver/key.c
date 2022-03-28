#include "main.h"


void mDelay(uint32_t i)
{
		uint32_t j=0;
		for(;i>0;i--)
		{
				for(j=0;j<12000;j++);
		}
}


/**
  * @brief  按键初始化函数
**/
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

		EXTI_InitTypeDef EXTI_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;	
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 			
		NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x06;	
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								
  	NVIC_Init(&NVIC_InitStructure);
		
		
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;	
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 		
		NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x06;	
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								
  	NVIC_Init(&NVIC_InitStructure);
}

/**
  * @brief  按键中断处理函数
**/
void EXTI4_IRQHandler(void)
{		
		mDelay(15);  
		if(EXTI_GetITStatus(EXTI_Line4)==SET) 
		{
				if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)	  
				{
						if(!GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_5))
						{
								LED0_OFF;
						}
						else
						{
								LED0_ON;
						}
				}		 
		}
	 	EXTI_ClearITPendingBit(EXTI_Line4);
}


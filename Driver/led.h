#ifndef LED_H_H
#define LED_H_H

#define  LED0_OFF     GPIO_SetBits(GPIOA,GPIO_Pin_0)
#define  LED0_ON      GPIO_ResetBits(GPIOA,GPIO_Pin_0)


#define  LED_0    0X01


#define  LED_OFF  0
#define  LED_ON   (!LED_OFF)

extern volatile unsigned char  LED0_value;


extern void LED_Init(void);
extern void LED_CmdCtl(void);
extern void LED_Switch(const uint8_t statu,const uint8_t mode);
extern void LED_GetValue(void);


#endif

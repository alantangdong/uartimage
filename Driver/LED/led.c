#include "led.h"
#include "stm32f10x.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStr;//GPIO_Init���� �ڶ���������ṹ��
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʼ��ʱ��GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//ʼ��ʱ��GPIOE
	
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStr);//��ʼ��GPIOB
	GPIO_SetBits(GPIOB,GPIO_Pin_5);//��ʼ��GPIOB Pin5�ߵ�ƽ
	
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStr);  //��ʼ��GPIOE
	GPIO_SetBits(GPIOE,GPIO_Pin_5);	//��ʼ��GPIOE Pin5�ߵ�ƽ

}

#include "stm32f10x.h"
#include <string.h>
#include "delay.h"
#include "led.h"
#include "OLED_I2C.h"
#include "motor.h"
#include "usart.h"
#include "../systemtime/systemtime.h"
extern const unsigned char gImage_sy[];

int main(void)
{
	int i = 0;
	u16 len;
  u8 flash = 0;
	LED_Init();
	delay_init();
	I2C_Configuration();
	OLED_Init();
	Moto_Init();
	uart_init(115200);
	SystemTimeInit();
		OLED_Fill(0xFF);//ȫ������
		delay_us(2);
		OLED_Fill(0x00);//ȫ����
		delay_us(2);
		for(i=0;i<5;i++)
		{
			OLED_ShowCN(22+i*16,0,i);//������ʾ����
		}
		delay_us(2);
		OLED_ShowStr(0,3,"HelTec Automation",1);//����6*8�ַ�
		WriteCmd(0xa7); //--set normal display
		OLED_ShowStr(0,4,"Hello Tech",1);				//����8*16�ַ�
		WriteCmd(0xa6); //--set normal display
		OLED_ShowStr(0,5,"Hello Test",1);				//����8*16�ַ�
//		while(1);
		delay_us(2);
		OLED_CLS();//����
		OLED_OFF();//����OLED����
		delay_us(2);
		OLED_ON();//����OLED���ߺ���
		OLED_DrawBMP(0,0,64,8,(unsigned char *)gImage_sy);//����BMPλͼ��ʾ
		delay_us(2);
		printf("ok\n%s,%s",__DATE__,__TIME__);
		//OLED_ShowStr(65,3,"HelTe",1);//����6*8�ַ�
	while(1)
	{
		if(systemtime.msec1flag == 1)// ---------------------------------1Ms����
		{
			systemtime.msec1flag = 0;
		}
		
		if(systemtime.msec10flag == 1)// ---------------------------------10Ms����
		{
			systemtime.msec10flag = 0;
		}
		
		if(systemtime.msec100flag == 1)// ---------------------------------100Ms����
		{
			systemtime.msec100flag = 0;
		if(USART_RX_STA&0x8000)
		{ 
			OLED_CLS();//����
			len=USART_RX_STA&0x3FFF;//�õ��˴ν��յ������ݳ���
			printf("%d",len);
			if(len<600)OLED_DrawBMP(0,0,64,8,(unsigned char *)USART_RX_BUF);//����BMPλͼ��ʾ
			else 			 OLED_DrawBMP(0,0,128,8,(unsigned char *)USART_RX_BUF);//����BMPλͼ��ʾ
	
//				while(USART_RX_BUF[i]!=';')
//				{
//					printf("[%d]=%x\n",i,USART_RX_BUF[i]);
//					i++;
//				}
				switch(USART_RX_BUF[0])
				{                                       
					case 'L':printf("\r\n��ת\r\n");Motorcw(5,256);break;
					case 'R':printf("\r\n��ת\r\n");Motorccw(5,256);break;
					case 'S':printf("\r\n��ͣ\r\n");MotorStop();break;
					default : break;
				}
        //                printf("\r\n\r\n");//���뻻��
				USART_RX_STA=0;
				memset(USART_RX_BUF,'\0',USART_REC_LEN);
		}
			if(flash<10)
			{
				if(flash<5)
				{
					GPIO_SetBits(GPIOB,GPIO_Pin_5);
					GPIO_ResetBits(GPIOE,GPIO_Pin_5);
				}
				else
				{
					GPIO_ResetBits(GPIOB,GPIO_Pin_5);
					GPIO_SetBits(GPIOE,GPIO_Pin_5);
				}
				flash++;
			}
			else flash = 0;
			
		}
		

		if(systemtime.msec1000flag == 1)// 1000Ms����
		{
				systemtime.msec1000flag = 0;
			
				
		}//	if(systemtime.msec1000flag == 1)// 1000Ms����
		
	}//while(1)

}

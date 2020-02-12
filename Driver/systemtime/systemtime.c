#include "..\systemtime\systemtime.h"

_systemtime systemtime ={
													0,10,10,10,//��ʼ��ʱ��
													0, 0, 0, 0//��ʼ����־λ
												};




void SystemTimeInit(void)
{
	  TIM3_Int_Init(99,719);//Tim2 1ms
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update))
	{
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);	
		systemtime.msec1 = 1;//1ms
		systemtime.msec1flag  = 1;//��1ms��־λ
		systemtime.msec10 -=1;
		if(systemtime.msec10==0)//10ms
		{
			systemtime.msec10 = 10;
			systemtime.msec100 -=1;
			systemtime.msec10flag = 1;//��10ms��־λ
			if(systemtime.msec100 == 0)//100ms
			{
				systemtime.msec100 = 10;
				systemtime.msec1000 -=1;
				systemtime.msec100flag = 1;//��100ms��־λ
				if(systemtime.msec1000 == 0)//1000ms
				{
					systemtime.msec1000 = 10;
					systemtime.msec1000flag = 1;//��1000ms��־λ
					
				}
			}
		}
	}
}


#ifndef __SYSTEMTIME0_H__
#define __SYSTEMTIME0_H__
#include  "stm32f10x.h"
#include 	"..\tim\tim.h"
typedef struct 
{
	unsigned int msec1;   				 //1ms
	unsigned int msec10;					 //10ms
	unsigned int msec100;					 //100ms
	unsigned int msec1000;				 //1000ms = 1s
	unsigned char msec1flag;  		 //��1ms��־λ
	unsigned char msec10flag;			 //��10ms��־λ
	unsigned char msec100flag;		 //��100ms��־λ
	unsigned char msec1000flag;		 //��1000ms = 1s��־λ
}_systemtime;

extern _systemtime systemtime;


void SystemTimeInit(void);


#endif


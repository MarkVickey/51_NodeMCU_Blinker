
#include <reg52.h>
				   
#define uchar unsigned char
#define uint unsigned int

#include <Configuration.c>
#include <IR_Remote_init.c>
#include <LCD.c>
#include <Stepper_Use_Key_Control.c>
#include <Stepper_run.c>
#include <IR_Control_logic.c>
 void Receive_Check();

void delay(uint x)  
{
	uint i,j;
	for(i=x;i>0;i--)
	for(j=114;j>0;j--);
}


void init(){
Lcd_Init();
IR_Init();
Stepper_Init();
}

void run(){

Receive_Check();
dis(); 
IR_Control_OS();
Stepper_Run();  
	 }

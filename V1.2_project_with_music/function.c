
#include <reg52.h>
#include <global_resource.c> 


void run(){
if(irreceok)
		{
			irreceok=0;
			irpros();
			if(irprosok)
			{
				irwork();
			}
		}
dis(); //disflag等于1时按需刷新LCD1602屏幕
IR_Control_OS();
Stepper_OS();
key_event_check(); //循环按键、电机旋转检测
}
	

void init(){ 
LcdInit();
int0init();
time0init();
initmusic();			//开机音乐
stepper_init();	
}
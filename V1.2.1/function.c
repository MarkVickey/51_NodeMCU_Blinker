
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
dis(); //disflag����1ʱ����ˢ��LCD1602��Ļ
IR_Control_OS();
Stepper_OS();
key_event_check(); //ѭ�������������ת���
}
	

void init(){ 
LcdInit();
int0init();
time0init();
initmusic();			//��������
stepper_init();	
}
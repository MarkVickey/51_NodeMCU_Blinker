			 
#include <lcd.h> 

/******************************************************************************************************

	           LCD��ʾ����ģ��

******************************************************************************************************/
 void Lcd1602_Delay1ms(uint c)   //��� 0us
{
    uchar a,b;
	for (; c>0; c--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
}

 #ifndef 	LCD1602_4PINS	 //��û�ж������LCD1602_4PINSʱ
void LcdWriteCom(uchar com)	  //д������
{
	LCD1602_E = 0;     //ʹ��
	LCD1602_RS = 0;	   //ѡ��������
	LCD1602_RW = 0;	   //ѡ��д��
	
	LCD1602_DATAPINS = com;     //��������
	Lcd1602_Delay1ms(1);		//�ȴ������ȶ�

	LCD1602_E = 1;	          //д��ʱ��
	Lcd1602_Delay1ms(5);	  //����ʱ��
	LCD1602_E = 0;
}
#else 
void LcdWriteCom(uchar com)	  //д������
{
	LCD1602_E = 0;	 //ʹ������
	LCD1602_RS = 0;	 //ѡ��д������
	LCD1602_RW = 0;	 //ѡ��д��

	LCD1602_DATAPINS = com;	//����4λ�Ľ����ǽӵ�P0�ڵĸ���λ�����Դ��͸���λ���ø�
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	 //д��ʱ��
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;

//	Lcd1602_Delay1ms(1);
	LCD1602_DATAPINS = com << 4; //���͵���λ
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	 //д��ʱ��
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;
}
#endif

#ifndef 	LCD1602_4PINS		   
void LcdWriteData(uchar dat)			//д������
{
	LCD1602_E = 0;	//ʹ������
	LCD1602_RS = 1;	//ѡ����������
	LCD1602_RW = 0;	//ѡ��д��

	LCD1602_DATAPINS = dat; //д������
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;   //д��ʱ��
	Lcd1602_Delay1ms(5);   //����ʱ��
	LCD1602_E = 0;
}
#else
void LcdWriteData(uchar dat)			//д������
{
	LCD1602_E = 0;	  //ʹ������
	LCD1602_RS = 1;	  //ѡ��д������
	LCD1602_RW = 0;	  //ѡ��д��

	LCD1602_DATAPINS = dat;	//����4λ�Ľ����ǽӵ�P0�ڵĸ���λ�����Դ��͸���λ���ø�
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	  //д��ʱ��
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;

	LCD1602_DATAPINS = dat << 4; //д�����λ
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	  //д��ʱ��
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;
}
#endif

#ifndef		LCD1602_4PINS
void Lcd_Init()			  //LCD��ʼ���ӳ���
{
 	LcdWriteCom(0x38);  //����ʾ
	LcdWriteCom(0x0c);  //����ʾ����ʾ���
	LcdWriteCom(0x06);  //дһ��ָ���1
	LcdWriteCom(0x01);  //����
	LcdWriteCom(0x80);  //��������ָ�����
}
#else
void Lcd_Init()			 //LCD��ʼ���ӳ���
{
	LcdWriteCom(0x32);	 //��8λ����תΪ4λ����
	LcdWriteCom(0x28);	 //����λ���µĳ�ʼ��
	LcdWriteCom(0x0c);  //����ʾ����ʾ���
	LcdWriteCom(0x06);  //дһ��ָ���1
	LcdWriteCom(0x01);  //����
	LcdWriteCom(0x80);  //��������ָ�����
}
#endif


void dis(){
uchar i;

if(dis_flag==1)//����LCDīˮ��Ļ���԰���ˢ����Ļ�����ԣ�����Ҫ����Ҫˢ����Ļʱ��dis_flag��1���ɣ���ԼLCD��Դ
{ 
if(ir_debug){
	LcdWriteCom(ir_debug_loc);

	for(i=4;i<6;i++)
	{
		LcdWriteData(num[irdisp[i]]);
	}
	} 

		LcdWriteCom(speed_loc);
	  for(i=0;i<8;i++)
	  {
	   LcdWriteData(d_speed[i]);
	}LcdWriteData(d_speedvalue[sped+1]);
		LcdWriteCom(status_loc);
		for(i=0;i<8;i++)
	  {  
	   LcdWriteData(d_turn[i]);
	}
	if(!start_flag==0&&fx_flag==0)
	for(i=0;i<6;i++)
	LcdWriteData(d_turn_R[i]);
	else if(!start_flag==0&&fx_flag==1)
	for(i=0;i<6;i++)
	LcdWriteData(d_turn_L[i]);
	else if(start_flag==0)
	for(i=0;i<6;i++)
	LcdWriteData(d_turn_P[i]);
	dis_flag=0;
		}}


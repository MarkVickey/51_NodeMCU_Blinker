//�������޹ص�ȫ�ֱ���
#define uint unsigned int
#define uchar unsigned char

uint Freq,T_cnt;//  ������ȫ�ֱ���
bit tune_flag=0;
uint code Tab_F[]={	
262,286,331,349,392,440,494,//����
523,587,659,698,784,880,988,//����
1046,1175,1318,1396,1568,1760,1975};//����

 
uchar code zhengzhuan[]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09}; //��ת����		 1000��1100��0100��0110��0010��0011��0001 ��1001
uchar code fanzhuan[]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08}; //��ת����

#ifndef	 FANGZHEN
uchar speed[]={10,9,8,7,6,5,4,3,2,1};//�ٶ�PWM���Ƹߵ�ƽռ�ձ���ʱ����(ʵ������)
#else
uchar speed[]={1,2,3,4,5,6,7,8,9,10};//�ٶ�PWM���Ƹߵ�ƽռ�ձ���ʱ����(��������)
#endif

 //IR�������ȫ�ֱ���
uchar code num[16]="0123456789ABCDEF";
uchar irtime;	  	//����ʱ��
uchar startflag;  	//��ʼ���
uchar bitnum;	  	//bitλ��
uchar irdata[33]; 	//�Ĵ�û�и�bit��ʱ��
uchar irreceok;	  	//������ɱ�־λ
uchar ircode[4];  	//�����յ��ĸ��ֽ����ݱ���
uchar irprosok;	  	//�������ݴ����־λ
uchar irdisp[8];  	//���ĸ��ֽڵ�16����ͨ��ת�����ʮ���ƴ洢
uchar dat1,dat2;
uchar keynum;
//function.c
void run();
void init();

//delay_time.c
void delay(uint);
void delay100us();
void Lcd1602_Delay1ms(uint);

//connect_module.c
void int0init();	//�ⲿ�жϳ�ʼ������
void time0init();	//��ʱ��0��ʼ������
void irpros();		//����������ݴ��� ������������0����1
void irwork(); 		//���ĸ��ֽڵ�����ת����10��������ʾ
void time0();		//��ʱ��0����
void init0();		//�ⲿ�ж�0����

//lcd.c
void LcdWriteCom(uchar);  //  LCDдCOM
void LcdWriteData(uchar);	//LCDдDATA
void LcdInit();//LCD��ʼ��

//tune.c
void tuneinit();   //��������ʼ��
void tune(uchar);  //��������������
void initmusic();  //��������
void closemusic(); //�ػ�����

//control.c
void IR_Control_OS();	 //����16���ƵĽ���Ϳ��ƺ���
void key_event_check();		//�������ƺ���

//stepper.c
void forward();
void reverse();
void Stepper_OS();

#include <intrins.h>
#include <configuration.c>
#include <delay_time.c>
#include <connect_module.c>	
#include <lcd.c>
#include <tune.c>
#include <Control_OS.c>
#include <stepper.c>
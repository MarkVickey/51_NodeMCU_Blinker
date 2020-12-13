//与设置无关的全局变量
#define uint unsigned int
#define uchar unsigned char

uint Freq,T_cnt;//  蜂鸣器全局变量
bit tune_flag=0;
uint code Tab_F[]={	
262,286,331,349,392,440,494,//低音
523,587,659,698,784,880,988,//中音
1046,1175,1318,1396,1568,1760,1975};//高音

 
uchar code zhengzhuan[]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09}; //正转脉冲		 1000，1100，0100，0110，0010，0011，0001 ，1001
uchar code fanzhuan[]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08}; //反转脉冲

#ifndef	 FANGZHEN
uchar speed[]={10,9,8,7,6,5,4,3,2,1};//速度PWM控制高电平占空比延时数据(实际数据)
#else
uchar speed[]={1,2,3,4,5,6,7,8,9,10};//速度PWM控制高电平占空比延时数据(仿真数据)
#endif

 //IR红外相关全局变量
uchar code num[16]="0123456789ABCDEF";
uchar irtime;	  	//接收时间
uchar startflag;  	//开始检测
uchar bitnum;	  	//bit位数
uchar irdata[33]; 	//寄存没有个bit的时间
uchar irreceok;	  	//接收完成标志位
uchar ircode[4];  	//将接收的四个字节数据保存
uchar irprosok;	  	//接收数据处理标志位
uchar irdisp[8];  	//将四个字节的16进制通过转换变成十进制存储
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
void int0init();	//外部中断初始化函数
void time0init();	//定时器0初始化函数
void irpros();		//红外接收数据处理 ，区分是数据0还是1
void irwork(); 		//将四个字节的数据转换成10进制数显示
void time0();		//定时器0函数
void init0();		//外部中断0函数

//lcd.c
void LcdWriteCom(uchar);  //  LCD写COM
void LcdWriteData(uchar);	//LCD写DATA
void LcdInit();//LCD初始化

//tune.c
void tuneinit();   //蜂鸣器初始化
void tune(uchar);  //蜂鸣器发出声音
void initmusic();  //开机音乐
void closemusic(); //关机音乐

//control.c
void IR_Control_OS();	 //红外16进制的解码和控制函数
void key_event_check();		//按键控制函数

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
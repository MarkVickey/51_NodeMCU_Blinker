//#define FANGZHEN	  //编译仿真环境hex文件时需要去掉前面的注释，频率控制与实际正好相反
/*这部分是屏幕显示的字符配置，除speedvalue是按需调用外全是直接显示*/				  
 uchar code d_speed[]="SPEED : ";
 uchar code d_speedvalue[]="9876543210" ;
 uchar code d_turn[]="STATUS : ";
 uchar code d_turn_R[]=" RIGHT";
 uchar code d_turn_L[]=" LEFT ";
 uchar code d_turn_P[]=" PAUSE ";

//可以通过更改接口适配更多开发板

//独立按键适配引脚参数
sbit speedup_key=P3^1; //加速
sbit speedlow_key=P3^0; //减速
//sbit start=P3^2; //开始、停止		 //P3^2与红外冲突了,功能转移为同时按下加减速
sbit turn=P3^3; //转向

//显示屏适配引脚参数
#define LCD1602_DATAPINS P0
sbit LCD1602_E=P2^7;
sbit LCD1602_RW=P2^5;
sbit LCD1602_RS=P2^6;

//红外是通过外部中断完成的，引脚固定为P3^2

//步进电机引脚
#define STEPPER_PINS P1

//蜂鸣器引脚
sbit TUNE_PIN=P1^5;

//status显示位置配置
uchar status_loc = 	 0x81;

//ir_debug显示位置配置
uchar ir_debug_loc = 0xce;

//speed显示位置配置
uchar speed_loc =  0xc3;

////////////////////////////////////////////////////////////////////
 
/*			各种需要配置的默认数据，配置后有的数据仍然可以用红外遥控更改			*/

bit start_flag=0;//步进电机开始运作flag。1开始0停止
bit fx_flag=1;	//方向flag，默认正转	1正转0反转
bit dis_flag;	//显示刷新flag，LCD不需要一直刷新（一直刷新会影响电机转动所以仅需要时候刷新即可）
bit run_flag=1;	//主循环是否运行flag，用于关闭所有功能（待机）
bit ir_debug=0;	//ir_debug=1时会默认在屏幕右下角显示红外接收到的2位16进制字符，ir_debug=0时则默认不显示。
bit music_allow=1;

char sped=0; //默认为速度0最慢，速度9为最快 (由于程序需要符号判断，所以用char)	 
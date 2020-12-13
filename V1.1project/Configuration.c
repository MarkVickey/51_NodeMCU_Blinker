



//#define simulation	 //由于仿真平台与真实存在差异，所以部分全局参数定义有差异，在使用仿真平台时请把这条注释去掉

/*这部分是屏幕显示的字符配置，除speedvalue是按需调用外全是直接显示*/				  
 uchar code d_speed[]="SPEED : ";
 uchar code d_speedvalue[]="0123456789" ;
 uchar code d_turn[]="STATUS : ";
 uchar code d_turn_R[]=" RIGHT";
 uchar code d_turn_L[]=" LEFT ";
 uchar code d_turn_P[]=" PAUSE ";

//status显示位置配置
uchar status_loc = 	 0x81;

//ir_debug显示位置配置
uchar ir_debug_loc = 0xce;

//speed显示位置配置
uchar speed_loc =  0xc3;
////////////////////////////////////////////////////////////////////
 
/*			各种需要配置的默认数据，配置后有的数据仍然可以用红外遥控更改			*/

bit start_flag=0;	//步进电机开始运作flag。1开始0停止
bit fx_flag=1;	//方向flag，默认正转	1正转0反转
bit dis_flag;	//显示刷新flag，LCD不需要一直刷新（一直刷新会影响电机转动所以仅需要时候刷新即可）
bit run_flag=1;	//主循环是否运行flag，用于关闭所有功能（待机）
bit ir_debug=0;	//ir_debug=1时会默认在屏幕右下角显示红外接收到的2位16进制字符，ir_debug=0时则默认不显示。


uchar sped=0; //默认为速度0	为最慢，速度8为最快 （屏幕显示的速度为sped+1）

sbit speedup_key=P3^1; //加速
sbit speedlow=P3^0; //减速
sbit start=P3^2; //开始、停止
sbit turn=P3^3; //转向
		
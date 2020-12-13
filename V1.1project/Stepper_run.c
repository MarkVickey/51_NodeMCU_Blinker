

uchar code zhengzhuan[]={0x08,0x04,0x02,0x01}; //正转脉冲
uchar code fanzhuan[]={0x01,0x02,0x04,0x08}; //反转脉冲


#ifndef	simulation
uchar speed[]={10,9,8,7,6,5,4,3,2};//开发板 （实际要给的数据）
#else
uchar speed[]={2,3,4,5,6,7,8,9,10};//仿真 （实际要给的数据）
#endif

void delay(uint x);

void forward_check(){		   //正转
   	uchar i,j;
	for(i=0;i<8;i++)
	{
		if(!start_flag||fx_flag)   //只有 开始=1 方向=0时 才能执行下面语句
			break;
		for(j=0;j<4;j++)
		{
		P1=zhengzhuan[j];
		delay(speed[sped]);
		}
	}
}

void reverse_check(){			 //反转
   	uchar i,j;
	for(i=0;i<8;i++)
	{
		if(!start_flag||!fx_flag) //只有 开始=1 方向=1时 才能执行下面语句
			break;
		for(j=0;j<4;j++)
		{
		P1=fanzhuan[j];
		delay(speed[sped]);
		}
	}
}


void Stepper_Init()
{

uchar j; 
for(j=0;j<4;j++)		 //	 P1电机初始化（上电转一下），否则会导致LCD供电不够 显示较暗
{
P1=fanzhuan[j];
}
dis_flag=1;		 //显示标志位置1，为方便下一步显示
dis();			 //初始化开机状态显示，没有这一步会导致开机屏幕没有显示
}

void Stepper_Run()
{

if(run_flag){
if(!dis_flag){
	forward_check();
	reverse_check();
	}

}
else
	LcdWriteCom(0x01);   //清屏
}

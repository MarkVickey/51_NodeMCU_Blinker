

void forward(){		   //正转
   	uchar i,j;
	for(i=0;i<2;i++)
	{
		if(!start_flag||fx_flag)   //只有 开始=1 方向=0时 才能执行下面语句
			break;
		for(j=0;j<8;j++)
		{
		STEPPER_PINS=zhengzhuan[j];
		delay(speed[sped]);
		}
	}
}

void reverse(){			 //反转
   	uchar i,j;
	for(i=0;i<2;i++)
	{
		if(!start_flag||!fx_flag) //只有 开始=1 方向=1时 才能执行下面语句
			break;
		for(j=0;j<8;j++)
		{
		STEPPER_PINS=fanzhuan[j];
		delay(speed[sped]);
		}
	}
}


void Stepper_OS(){
if(run_flag&&!tune_flag&&!irreceok){
if(!dis_flag){
forward();
reverse();

}else
	LcdWriteCom(0x01);  
}	}

void stepper_init(){	   
uchar j; 
for(j=0;j<4;j++)		 //	 P1电机初始化（上电转一下），否则会导致LCD供电不够 显示较暗
{
P1=fanzhuan[j];}
dis_flag=1;		 //显示标志位置1，为方便下一步显示
dis();			 //初始化开机状态显示，没有这一步会导致开机屏幕没有显示
}
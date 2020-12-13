

void forward(){		   //正转
 //  	uchar i;
	uchar j;
if(start_flag&&!fx_flag)  //只有 开始=1 方向=0时 才能执行下面语句
	
//for(i=0;i<64*4*2;i++)	  //步进电机转一圈每相需要64个脉冲 根据360度/步距角5.625度=64计算得出
					  	  //由于步进电机驱动方式为四相八拍，所以需要此处*2完成8拍操作，8拍后步进电机完成一步，也就是5.625度
						  //综上，这里需要把参数设置为64*4*2
			{
			for(j=0;j<8;j++)  //下面语句执行一次为一个脉冲，这里执行八次相当于	 
						  //八个半拍控制四个引脚pwm高低电平的时间（占空比控制）	
		{
		STEPPER_PINS=zhengzhuan[j];
		delay(speed[sped]); 
		STEPPER_PINS=0; 
		}
	}
}

void reverse(){			 //反转
 //  	uchar i;
	uchar j;
if(start_flag&&fx_flag)  //只有 开始=1 方向=1时 才能执行下面语句
	
//for(i=0;i<64*4*2;i++)	  //步进电机转一圈每相需要64个脉冲 根据360度/步距角5.625度=64计算得出
					  	  //由于步进电机驱动方式为四相八拍，所以需要此处*2完成8拍操作，8拍后步进电机完成一步，也就是5.625度
						  //综上，这里需要把参数设置为64*4*2
		{
			for(j=0;j<8;j++)  //下面语句执行一次为一个脉冲，这里执行八次相当于	 
						  //八个半拍控制四个引脚pwm高低电平的时间（占空比控制）	
		{
		STEPPER_PINS=fanzhuan[j];
		delay(speed[sped]); 
		STEPPER_PINS=0; 
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
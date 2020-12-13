		
void IR_Control_OS()	 //红外16进制的解码和控制函数
{
	if(((dat1==1)&&(dat2==5))&& !start_flag&&run_flag)  //按下第一次0x15按键开马达
	{			
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		start_flag=1;
	}
			
	if(((dat1==1)&&(dat2==5))&&start_flag&&run_flag)	//按下第二次0x15此按键时关闭马达
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		start_flag=0;
	}
									
	if(((dat1==4)&&(dat2==0)&&sped<8)&&run_flag)  //按一下加速
	{			
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
	 	sped++;
	}

			
	if(((dat1==1)&&(dat2==9))&&sped>0&&run_flag)	//按一下减速
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
	 	sped--	;
	}
	
		if(((dat1==4)&&(dat2==3))&& !fx_flag&&run_flag)  //按下第一次0x43按键正方向
	{			
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		fx_flag=1;
	}
			
	if(((dat1==4)&&(dat2==3))&&fx_flag&&run_flag)	//按下第二次0x43按键时反方向
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		fx_flag=0;
	}	
	
		if(((dat1==0)&&(dat2==9)&&run_flag))	//按一下最大速度
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
	 	sped=8	;
	}	
	
		if(((dat1==0)&&(dat2==7)&&run_flag))	//按一下最小速度
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
	 	sped=0;
	}		
	
			if(((dat1==4)&&(dat2==5))&& !run_flag)  //按下第一次0x45运行
	{			
		dat1=0;
		dat2=0;
		keynum=0;
						 		dis_flag=1;
		run_flag=1;
	}
			
	if(((dat1==4)&&(dat2==5))&&run_flag)	//按下第二次0x45停止
	{
		dat1=0;
		dat2=0;
		keynum=0;
						 	
		sped=0;
		fx_flag=1;
		start_flag=0;
		
		run_flag=0;
			dis_flag=1;
	}	
	if(((dat1==4)&&(dat2==4))&&keynum==2)
	{

	dat1=0;
	dat2=0;
	keynum=0;
	ir_debug=~ir_debug;
	
	LcdWriteCom(0x01); 
	dis_flag=1;
}}
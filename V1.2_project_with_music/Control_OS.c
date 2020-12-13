void IR_Control_OS()	 //红外16进制的解码和控制函数
{
if(((dat1==1)&&(dat2==5))&& !start_flag&&run_flag)  //按下第一次0x15按键开马达
	{			
		dat1=0;
		dat2=0;
		keynum=0;

		tune(5);
		tune(7);
		tune(6);
		tune(7);

		dis_flag=1;
		start_flag=1;

		
		
	}
			
if(((dat1==1)&&(dat2==5))&&start_flag&&run_flag)	//按下第二次0x15按键时关闭马达
	{
		dat1=0;
		dat2=0;
		keynum=0;
		tune(7);
		tune(6);
		tune(7);
		tune(5);
		dis_flag=1;
		start_flag=0;

	}
									
if(((dat1==4)&&(dat2==0))&&run_flag)  //按一下加速
	{			
		dat1=0;
		dat2=0;
		keynum=0;
	 	sped++;
		
		if(sped!=10)
		{  
		tune(8);
		dis_flag=1;}
		if(sped==10)sped=9;
	}

			
if(((dat1==1)&&(dat2==9))&&run_flag)	//按一下减速
	{
		dat1=0;
		dat2=0;
		keynum=0;
	 	sped--	;
		if(sped!=-1)
		{
		tune(5);
		dis_flag=1;
		}
		if(sped==-1)sped=0;
	}
	
if(((dat1==4)&&(dat2==3))&& !fx_flag&&run_flag&&start_flag)  //按下第一次0x43按键正方向
	{			
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		fx_flag=1;
	
		tune(8);
		
		tune(9); 

		tune(8);  
	}
			
if(((dat1==4)&&(dat2==3))&&fx_flag&&run_flag&&start_flag)	//按下第二次0x43按键时反方向
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		fx_flag=0;
		 
		tune(9); 
		
		tune(8);  

		tune(9);
	}	
	
if(((dat1==0)&&(dat2==9)&&run_flag))	//按一下最大速度
	{
		dat1=0;
		dat2=0;
		keynum=0;
	 	
		if(sped!=9){ 
		dis_flag=1;
		tune(8);
		delay(80);
		tune(8);
		 }
		sped=9;
	}	
	
if(((dat1==0)&&(dat2==7)&&run_flag))	//按一下最小速度
	{
		dat1=0;
		dat2=0;
		keynum=0;

		if(sped!=0){
		dis_flag=1;
		tune(5);
		delay(80);
		tune(5);
		 }
		 sped=0;	
	}		
	
if(((dat1==4)&&(dat2==5))&& !run_flag)  //按下第一次0x45运行
	{			
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		run_flag=1;
		initmusic();
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
		dis_flag=0;
		LcdWriteCom(0x01);  //清屏
		closemusic();
	}	
if(((dat1==4)&&(dat2==4))&&keynum==2)
	{

	dat1=0;
	dat2=0;
	keynum=0;
	
	ir_debug=~ir_debug;
	LcdWriteCom(0x01); 
	dis_flag=1;
	initmusic();
	tune(8);
	closemusic();
	}

if(((dat1==0)&&(dat2==13)&&run_flag))
	{

	dat1=0;
	dat2=0;
	keynum=0;

	music_allow	= ~music_allow;
	dis_flag=1;
	tune(1);
	tune(5);
	tune(5);
	initmusic();
	tune(8);
	closemusic();
	}
	}

	


void key_event_check(){
Stepper_OS(); //事件检测
if(run_flag){
	 if(speedup_key==1&&speedlow_key==0){if(sped==0)sped=1; //确保不会减速到负数
	 sped--	;
	 dis_flag=1;
	 }
	 while(speedup_key==1&&speedlow_key==0){Stepper_OS();} //只执行一次if，其他执行while，防止多次触发一个按钮
	 if(speedup_key==0&&speedlow_key==1)
	 {if(sped==9)sped=8;
	 sped++	;
	 dis_flag=1;
	 }
	 while(speedup_key==0&&speedlow_key==1){Stepper_OS();}
	 if(speedup_key==0&&speedlow_key==0)
	 {
	 start_flag=~start_flag;
	 dis_flag=1;}
	 while(speedup_key==0&&speedlow_key==0){Stepper_OS();}
	 if(turn==0){
	 fx_flag=~fx_flag;
	 dis_flag=1;
	 }
	 while(turn==0){Stepper_OS();}
}
}
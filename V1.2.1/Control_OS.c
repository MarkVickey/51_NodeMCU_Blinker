void IR_Control_OS()	 //����16���ƵĽ���Ϳ��ƺ���
{
if(((dat1==1)&&(dat2==5))&& !start_flag&&run_flag)  //���µ�һ��0x15���������
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
			
if(((dat1==1)&&(dat2==5))&&start_flag&&run_flag)	//���µڶ���0x15����ʱ�ر����
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
									
if(((dat1==4)&&(dat2==0))&&run_flag)  //��һ�¼���
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

			
if(((dat1==1)&&(dat2==9))&&run_flag)	//��һ�¼���
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
	
if(((dat1==4)&&(dat2==3))&& !fx_flag&&run_flag&&start_flag)  //���µ�һ��0x43����������
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
			
if(((dat1==4)&&(dat2==3))&&fx_flag&&run_flag&&start_flag)	//���µڶ���0x43����ʱ������
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
	
if(((dat1==0)&&(dat2==9)&&run_flag))	//��һ������ٶ�
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
	
if(((dat1==0)&&(dat2==7)&&run_flag))	//��һ����С�ٶ�
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
	
if(((dat1==4)&&(dat2==5))&& !run_flag)  //���µ�һ��0x45����
	{			
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		run_flag=1;
		initmusic();
	}
			
if(((dat1==4)&&(dat2==5))&&run_flag)	//���µڶ���0x45ֹͣ
	{
		dat1=0;
		dat2=0;
		keynum=0;
						 	
		sped=0;
		fx_flag=1;
		start_flag=0;
		run_flag=0;
		dis_flag=0;
		LcdWriteCom(0x01);  //����
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
Stepper_OS(); //�¼����
if(run_flag){
	 if(speedup_key==1&&speedlow_key==0){if(sped==0)sped=1; //ȷ��������ٵ�����
	 sped--	;
	 dis_flag=1;
	 }
	 while(speedup_key==1&&speedlow_key==0){Stepper_OS();} //ִֻ��һ��if������ִ��while����ֹ��δ���һ����ť
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
		
void IR_Control_OS()	 //����16���ƵĽ���Ϳ��ƺ���
{
	if(((dat1==1)&&(dat2==5))&& !start_flag&&run_flag)  //���µ�һ��0x15���������
	{			
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		start_flag=1;
	}
			
	if(((dat1==1)&&(dat2==5))&&start_flag&&run_flag)	//���µڶ���0x15�˰���ʱ�ر����
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		start_flag=0;
	}
									
	if(((dat1==4)&&(dat2==0)&&sped<8)&&run_flag)  //��һ�¼���
	{			
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
	 	sped++;
	}

			
	if(((dat1==1)&&(dat2==9))&&sped>0&&run_flag)	//��һ�¼���
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
	 	sped--	;
	}
	
		if(((dat1==4)&&(dat2==3))&& !fx_flag&&run_flag)  //���µ�һ��0x43����������
	{			
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		fx_flag=1;
	}
			
	if(((dat1==4)&&(dat2==3))&&fx_flag&&run_flag)	//���µڶ���0x43����ʱ������
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
		fx_flag=0;
	}	
	
		if(((dat1==0)&&(dat2==9)&&run_flag))	//��һ������ٶ�
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
	 	sped=8	;
	}	
	
		if(((dat1==0)&&(dat2==7)&&run_flag))	//��һ����С�ٶ�
	{
		dat1=0;
		dat2=0;
		keynum=0;
		dis_flag=1;
	 	sped=0;
	}		
	
			if(((dat1==4)&&(dat2==5))&& !run_flag)  //���µ�һ��0x45����
	{			
		dat1=0;
		dat2=0;
		keynum=0;
						 		dis_flag=1;
		run_flag=1;
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
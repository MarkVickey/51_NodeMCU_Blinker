

void forward(){		   //��ת
   	uchar i,j;
	for(i=0;i<2;i++)
	{
		if(!start_flag||fx_flag)   //ֻ�� ��ʼ=1 ����=0ʱ ����ִ���������
			break;
		for(j=0;j<8;j++)
		{
		STEPPER_PINS=zhengzhuan[j];
		delay(speed[sped]);
		}
	}
}

void reverse(){			 //��ת
   	uchar i,j;
	for(i=0;i<2;i++)
	{
		if(!start_flag||!fx_flag) //ֻ�� ��ʼ=1 ����=1ʱ ����ִ���������
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
for(j=0;j<4;j++)		 //	 P1�����ʼ�����ϵ�תһ�£�������ᵼ��LCD���粻�� ��ʾ�ϰ�
{
P1=fanzhuan[j];}
dis_flag=1;		 //��ʾ��־λ��1��Ϊ������һ����ʾ
dis();			 //��ʼ������״̬��ʾ��û����һ���ᵼ�¿�����Ļû����ʾ
}


uchar code zhengzhuan[]={0x08,0x04,0x02,0x01}; //��ת����
uchar code fanzhuan[]={0x01,0x02,0x04,0x08}; //��ת����


#ifndef	simulation
uchar speed[]={10,9,8,7,6,5,4,3,2};//������ ��ʵ��Ҫ�������ݣ�
#else
uchar speed[]={2,3,4,5,6,7,8,9,10};//���� ��ʵ��Ҫ�������ݣ�
#endif

void delay(uint x);

void forward_check(){		   //��ת
   	uchar i,j;
	for(i=0;i<8;i++)
	{
		if(!start_flag||fx_flag)   //ֻ�� ��ʼ=1 ����=0ʱ ����ִ���������
			break;
		for(j=0;j<4;j++)
		{
		P1=zhengzhuan[j];
		delay(speed[sped]);
		}
	}
}

void reverse_check(){			 //��ת
   	uchar i,j;
	for(i=0;i<8;i++)
	{
		if(!start_flag||!fx_flag) //ֻ�� ��ʼ=1 ����=1ʱ ����ִ���������
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
for(j=0;j<4;j++)		 //	 P1�����ʼ�����ϵ�תһ�£�������ᵼ��LCD���粻�� ��ʾ�ϰ�
{
P1=fanzhuan[j];
}
dis_flag=1;		 //��ʾ��־λ��1��Ϊ������һ����ʾ
dis();			 //��ʼ������״̬��ʾ��û����һ���ᵼ�¿�����Ļû����ʾ
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
	LcdWriteCom(0x01);   //����
}

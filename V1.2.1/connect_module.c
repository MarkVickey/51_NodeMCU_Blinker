	   

void int0init()
{
	EA=1;
	EX0=1;
	IT0=1;
}
void time0init()
{
	TMOD=0X02;	//���ö�ʱ��0ģʽ2.��ģʽΪ�Զ�װ��ģʽ
	TH0=0X00;
	TL0=0X00;//�趨������ֵ��ÿ��TL0������255ʱ��TH0�����Լ������ݸ�TL0�������¼���
	TR0=1;
	ET0=1;
	EA=1;	
}

void irpros() //����������ݴ��� ������������0����1
{
	uchar i,j,value;
	uchar k=1;	//������ȥ����������k=1��
	for(j=0;j<4;j++)  //ȡ����һ֡�����е��ĸ��ֽ�����
	{
		for(i=0;i<8;i++)	//ȡ����һ���ֽڵ�����		
		{
			value>>=1;
			if(irdata[k]>6)
			{
				value=value|0x80;
			}
			k++;
		}
		ircode[j]=value;
	}
	irprosok=1;
}
void irwork()  //���ĸ��ֽڵ�����ת����10��������ʾ
{
	irdisp[0]=ircode[0]/16;//��ʾ��λ
	irdisp[1]=ircode[0]%16;//��ʾ��λ  
	irdisp[2]=ircode[1]/16;
	irdisp[3]=ircode[1]%16;	 //ͬһ��ң������2���ֽڵ������������ǲ���ı�ģ��ı��ֻ�������뼰����
	irdisp[4]=ircode[2]/16;
	irdisp[5]=ircode[2]%16;
	irdisp[6]=ircode[3]/16;
	irdisp[7]=ircode[3]%16;
	dat1=irdisp[4];
	dat2=irdisp[5];


	keynum++;
}


void time0() interrupt 1
{
	irtime++;//ÿ����һ�ξ�˵����ʱʱ��Ϊ256us��
	T_cnt++	;
}
void init0() interrupt 0
{
	if(startflag)
	{
		if(irtime>32)//��������룬������������ʱ�����һ�μ���ʱ�䣬����Ҫ���ٴ�
		{
			bitnum=0;	
		}
		irdata[bitnum]=irtime;
		irtime=0;
		bitnum++;
		if(bitnum==33)
		{
			bitnum=0;
			irreceok=1;//һ֡�������ݽ�����ɱ�־
		}
	}
	else
	{
		startflag=1;//����ʼ��־λ��1���ȵ��´ν����жϼ��ɽ���if���
		irtime=0;//����ʼ֮ǰ�ļ�����ʱ�����㡣�ȵ��´ν����жϵ�ʱ�����������������ʱ��
	}
	if(ir_debug){dis_flag=1;}
}
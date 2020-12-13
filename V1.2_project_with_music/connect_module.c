	   

void int0init()
{
	EA=1;
	EX0=1;
	IT0=1;
}
void time0init()
{
	TMOD=0X02;	//设置定时器0模式2.该模式为自动装载模式
	TH0=0X00;
	TL0=0X00;//设定计数初值，每当TL0计数到255时，TH0将把自己的数据给TL0，又重新计数
	TR0=1;
	ET0=1;
	EA=1;	
}

void irpros() //红外接收数据处理 ，区分是数据0还是1
{
	uchar i,j,value;
	uchar k=1;	//引导码去掉，所以令k=1；
	for(j=0;j<4;j++)  //取出了一帧数据中的四个字节数据
	{
		for(i=0;i<8;i++)	//取出了一个字节的数据		
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
void irwork()  //将四个字节的数据转换成10进制数显示
{
	irdisp[0]=ircode[0]/16;//显示高位
	irdisp[1]=ircode[0]%16;//显示低位  
	irdisp[2]=ircode[1]/16;
	irdisp[3]=ircode[1]%16;	 //同一个遥控器此2个字节的引导码数据是不会改变的，改变的只是数据码及反码
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
	irtime++;//每进来一次就说明定时时间为256us；
	T_cnt++	;
}
void init0() interrupt 0
{
	if(startflag)
	{
		if(irtime>32)//检测引导码，求法是用引导码时间除以一次计数时间，看看要多少次
		{
			bitnum=0;	
		}
		irdata[bitnum]=irtime;
		irtime=0;
		bitnum++;
		if(bitnum==33)
		{
			bitnum=0;
			irreceok=1;//一帧红外数据接收完成标志
		}
	}
	else
	{
		startflag=1;//将开始标志位置1，等到下次进入中断即可进入if语句
		irtime=0;//将开始之前的计数器时间清零。等到下次进入中断的时候才是引导码真正的时间
	}
	if(ir_debug){dis_flag=1;}
}
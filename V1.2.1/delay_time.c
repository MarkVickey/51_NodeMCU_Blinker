
void delay(uint x)  //ÑÓÊ±º¯Êý
{
	uint i,j;
	for(i=x;i>0;i--)
	for(j=114;j>0;j--);

}

void delay100us()		//@11.0592MHz
{
	uchar i;

	_nop_();
	i = 5000-Freq;
	while (--i);
}

void Lcd1602_Delay1ms(uint c)   //Îó²î 0us
{
    uchar a,b;
	for (; c>0; c--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
}

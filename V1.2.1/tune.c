
void tuneinit()
{  
	static uint i;
	uint a=300;
   
for(a;a>0;a--){
	i++;
	if (tune_flag)	TUNE_PIN=~TUNE_PIN;
	if(i>5000/Freq)i=0;
	delay100us();
	 }	 
}

   
void tune(uchar a)
{		 
		tune_flag=1;
		if(music_allow){
			Freq=Tab_F[a-1];   //·¢Éù
			T_cnt=0;
tuneinit();
}
tune_flag=0;
}


void initmusic(){

uchar a=0;
for(a=5;a<8;a++){
tune(a);
}	 
}
void closemusic(){

uchar a=0;
for(a=7;a>4;a--){
tune(a);
}	 
}
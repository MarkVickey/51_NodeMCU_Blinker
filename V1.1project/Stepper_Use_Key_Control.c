
void Stepper_Run();

void key_check(){//�¼���⣨ȷ�����ºͷ��°�������ת��
if(speedlow==0){if(sped==0)sped=1; //ȷ��������ٵ�����
	 sped--	;
	 dis_flag=1;
	 }
while(speedlow==0){Stepper_Run();} //ִֻ��һ��if������ִ��while����ֹ��δ���һ����ť
	 if(speedup_key==0)
	 {if(sped==8)sped=7;
	 sped++	;
	 dis_flag=1;
	 }
	 while(speedup_key==0){Stepper_Run();}
	 if(start==0)
	 {
	 start_flag=~start_flag;
	 dis_flag=1;}
	 while(start==0){Stepper_Run();}
	 if(turn==0){
	 fx_flag=~fx_flag;
	 dis_flag=1;
	 }
	 while(turn==0){Stepper_Run();}
}
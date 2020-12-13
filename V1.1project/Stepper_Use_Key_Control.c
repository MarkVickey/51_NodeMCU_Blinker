
void Stepper_Run();

void key_check(){//事件检测（确保按下和放下按键都能转）
if(speedlow==0){if(sped==0)sped=1; //确保不会减速到负数
	 sped--	;
	 dis_flag=1;
	 }
while(speedlow==0){Stepper_Run();} //只执行一次if，其他执行while，防止多次触发一个按钮
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
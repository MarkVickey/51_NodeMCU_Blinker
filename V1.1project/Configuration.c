



//#define simulation	 //���ڷ���ƽ̨����ʵ���ڲ��죬���Բ���ȫ�ֲ��������в��죬��ʹ�÷���ƽ̨ʱ�������ע��ȥ��

/*�ⲿ������Ļ��ʾ���ַ����ã���speedvalue�ǰ��������ȫ��ֱ����ʾ*/				  
 uchar code d_speed[]="SPEED : ";
 uchar code d_speedvalue[]="0123456789" ;
 uchar code d_turn[]="STATUS : ";
 uchar code d_turn_R[]=" RIGHT";
 uchar code d_turn_L[]=" LEFT ";
 uchar code d_turn_P[]=" PAUSE ";

//status��ʾλ������
uchar status_loc = 	 0x81;

//ir_debug��ʾλ������
uchar ir_debug_loc = 0xce;

//speed��ʾλ������
uchar speed_loc =  0xc3;
////////////////////////////////////////////////////////////////////
 
/*			������Ҫ���õ�Ĭ�����ݣ����ú��е�������Ȼ�����ú���ң�ظ���			*/

bit start_flag=0;	//���������ʼ����flag��1��ʼ0ֹͣ
bit fx_flag=1;	//����flag��Ĭ����ת	1��ת0��ת
bit dis_flag;	//��ʾˢ��flag��LCD����Ҫһֱˢ�£�һֱˢ�»�Ӱ����ת�����Խ���Ҫʱ��ˢ�¼��ɣ�
bit run_flag=1;	//��ѭ���Ƿ�����flag�����ڹر����й��ܣ�������
bit ir_debug=0;	//ir_debug=1ʱ��Ĭ������Ļ���½���ʾ������յ���2λ16�����ַ���ir_debug=0ʱ��Ĭ�ϲ���ʾ��


uchar sped=0; //Ĭ��Ϊ�ٶ�0	Ϊ�������ٶ�8Ϊ��� ����Ļ��ʾ���ٶ�Ϊsped+1��

sbit speedup_key=P3^1; //����
sbit speedlow=P3^0; //����
sbit start=P3^2; //��ʼ��ֹͣ
sbit turn=P3^3; //ת��
		
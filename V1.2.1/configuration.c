//#define FANGZHEN	  //������滷��hex�ļ�ʱ��Ҫȥ��ǰ���ע�ͣ�Ƶ�ʿ�����ʵ�������෴
/*�ⲿ������Ļ��ʾ���ַ����ã���speedvalue�ǰ��������ȫ��ֱ����ʾ*/				  
 uchar code d_speed[]="SPEED : ";
 uchar code d_speedvalue[]="9876543210" ;
 uchar code d_turn[]="STATUS : ";
 uchar code d_turn_R[]=" RIGHT";
 uchar code d_turn_L[]=" LEFT ";
 uchar code d_turn_P[]=" PAUSE ";

//����ͨ�����Ľӿ�������࿪����

//���������������Ų���
sbit speedup_key=P3^1; //����
sbit speedlow_key=P3^0; //����
//sbit start=P3^2; //��ʼ��ֹͣ		 //P3^2������ͻ��,����ת��Ϊͬʱ���¼Ӽ���
sbit turn=P3^3; //ת��

//��ʾ���������Ų���
#define LCD1602_DATAPINS P0
sbit LCD1602_E=P2^7;
sbit LCD1602_RW=P2^5;
sbit LCD1602_RS=P2^6;

//������ͨ���ⲿ�ж���ɵģ����Ź̶�ΪP3^2

//�����������
#define STEPPER_PINS P1

//����������
sbit TUNE_PIN=P1^5;

//status��ʾλ������
uchar status_loc = 	 0x81;

//ir_debug��ʾλ������
uchar ir_debug_loc = 0xce;

//speed��ʾλ������
uchar speed_loc =  0xc3;

////////////////////////////////////////////////////////////////////
 
/*			������Ҫ���õ�Ĭ�����ݣ����ú��е�������Ȼ�����ú���ң�ظ���			*/

bit start_flag=0;//���������ʼ����flag��1��ʼ0ֹͣ
bit fx_flag=1;	//����flag��Ĭ����ת	1��ת0��ת
bit dis_flag;	//��ʾˢ��flag��LCD����Ҫһֱˢ�£�һֱˢ�»�Ӱ����ת�����Խ���Ҫʱ��ˢ�¼��ɣ�
bit run_flag=1;	//��ѭ���Ƿ�����flag�����ڹر����й��ܣ�������
bit ir_debug=0;	//ir_debug=1ʱ��Ĭ������Ļ���½���ʾ������յ���2λ16�����ַ���ir_debug=0ʱ��Ĭ�ϲ���ʾ��
bit music_allow=1;

char sped=0; //Ĭ��Ϊ�ٶ�0�������ٶ�9Ϊ��� (���ڳ�����Ҫ�����жϣ�������char)	 
#ifndef _WALKLINE_H
#define _WALKLINE_H

#include "ET2013.h"

/*����*/
/*��ʼ��ģ�鶨���ȫ�ֱ���*/
int WER_Motor_DC_L;		//���ֵ������DC�ڱ�š�
int WER_Motor_DC_R;		//���ֵ������DC�ڱ�š�
float WER_Motor_scale_L;	//���ֵ�����ϵ����ȡֵ��Χ-1.0-1.0��
float WER_Motor_scale_R;	//���ֵ�����ϵ����ȡֵ��Χ-1.0-1.0��
int WER_Floor_Quantity;		//�����˻Ҷȴ�������������5����7��
int WER_Floor_IO_1;		//������1���Ҷ�����I/O��š�
int WER_Floor_IO_2;		//������2���Ҷ�����I/O��š�
int WER_Floor_IO_3;		//������3���Ҷ�����I/O��š�
int WER_Floor_IO_4;		//������4���Ҷ�����I/O��š�
int WER_Floor_IO_5;		//������5���Ҷ�����I/O��š�
int WER_Floor_IO_6;		//������6���Ҷ�����I/O��š�
int WER_Floor_IO_7;		//������7���Ҷ�����I/O��š�
int WER_line_colour;		//�׵׺���Ϊ0���ڵװ���Ϊ1��
float WER_Floor_Coe;		//�Ҷ��ٽ�ֵƫ�������ȡֵ��Χ0~1��ԽСԽ������ɫ��Խ��Խ������ɫ��0.5ʱ���м�ֵ��
int WER_motor_sign;		//������ͣ�ȡֵΪ0ʱ��ʾ���������ȡֵΪ1ʱ��ʾ�ջ������


void WER_InitRobot_5(int DCL,float PowerL,int DCR,float PowerR,int IO0,int IO1,int IO2,int IO3,int IO4,int motorType);   //0828 ��Ҷȳ�ʼ��
void WER_next();                                                   //0828 ��ť
void WER_Set_Floorsensor();                                       //0828 �����ɼ�
void WER_SetMotor(int Lspeed,int Rspeed,float hold_time);         //0828 �������� ������ʱ��
void WER_SetMotor_L(int IO,char* operator,int reference,int Lspeed,int Rspeed);   //0828 �������������������
void WER_Around(int speed_L,int speed_R,int P);                   //0828 ת��
//void WER_LineWay_C(int speed, int  Senser);                       //0828 ·��Ѳ��
void WER_LineWay_C(int speed, int  Senser,float time);            //1010 ·��Ѳ��
void WER_LineWay_T(int speed,float time);                         //0828 ��ʱѲ��
void WER_RTurn(int speed);                                        //0828 ��ת
void WER_LTurn(int speed);                                        //0828 ��ת

#endif
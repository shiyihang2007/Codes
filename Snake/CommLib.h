#ifndef _COMMLIB_H
#define _COMMLIB_H


#include "ET2013.h"

#define AI_ADD0           				100
#define DO_ADD0             			124
#define MOTOR_ADD0         				148
#define MOTORCL_ADD0       				156
#define ENCODER_ADD0       				164
#define ENCODER_CLEAN_ADD0   			188
#define DI_ADD0             			212
#define CAM_X_ADD0    						152 
#define CAM_Y_ADD0    						168
#define CAM_HEIGHT_ADD0 					200
#define CAM_WEIGHT_ADD0  					184



int checkid(int id);

//����Զ�̿�������DO�˿�
//idΪԶ�̿�������ID�ţ�chΪͨ����0~11,stateΪ0���صƣ�����1(���ƣ�
int Client_SetDO(int id,int ch,int state);

//��ȡԶ�̿������ı������˿ڼ���ֵ
//idΪԶ�̿�������ID�ţ�chΪͨ����0~11
int Client_encoder(int id,int ch);

//����Զ�̿������ı������˿ڶ���
//idΪԶ�̿�������ID�ţ�chΪͨ����0~11
void Client_CntClear(int id,int ch);

//��ȡԶ�̿�������AI�˿�
//idΪԶ�̿�������ID�ţ�chΪͨ����0~11   
int  Client_AI(int id,int ch);

//��ȡԶ�̿�������DI�˿�
//idΪԶ�̿�������ID�ţ�chΪͨ����0~11   
int  Client_DI(int id,int ch);

//��ȡԶ�̿������ĵ���˿�
//idΪԶ�̿�������ID�ţ�chΪͨ����0~3��speedΪ�ٶ�-100~100   
int  Client_SetMoto(int id,int ch,int speed);

//��ȡԶ��ͼ��ģ����ɫ���Ϊcolor_index��0~7��������Ŀ��
int Client_Camera_weight(int id,int color_index);

//��ȡԶ��ͼ��ģ����ɫ���Ϊcolor_index��0~7��������Ķ���x����
int Client_Camera_x(int id,int color_index);

//��ȡԶ��ͼ��ģ����ɫ���Ϊcolor_index��0~7��������Ķ���y����
int Client_Camera_y(int id,int color_index);

//��ȡԶ��ͼ��ģ����ɫ���Ϊcolor_index��0~7��������ĸ߶�
int Client_Camera_height(int id,int color_index);

//��ȡ����Ƕ�
int PO16_ReadAngle(int id);

#endif
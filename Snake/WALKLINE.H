#ifndef _WALKLINE_H
#define _WALKLINE_H

#include "ET2013.h"

/*更新*/
/*初始化模块定义的全局变量*/
int WER_Motor_DC_L;		//左轮电机所接DC口编号。
int WER_Motor_DC_R;		//右轮电机所接DC口编号。
float WER_Motor_scale_L;	//左轮电机输出系数，取值范围-1.0-1.0。
float WER_Motor_scale_R;	//右轮电机输出系数，取值范围-1.0-1.0。
int WER_Floor_Quantity;		//机器人灰度传感器的数量，5或者7。
int WER_Floor_IO_1;		//左边起第1个灰度所接I/O编号。
int WER_Floor_IO_2;		//左边起第2个灰度所接I/O编号。
int WER_Floor_IO_3;		//左边起第3个灰度所接I/O编号。
int WER_Floor_IO_4;		//左边起第4个灰度所接I/O编号。
int WER_Floor_IO_5;		//左边起第5个灰度所接I/O编号。
int WER_Floor_IO_6;		//左边起第6个灰度所接I/O编号。
int WER_Floor_IO_7;		//左边起第7个灰度所接I/O编号。
int WER_line_colour;		//白底黑线为0，黑底白线为1。
float WER_Floor_Coe;		//灰度临界值偏移情况，取值范围0~1，越小越靠近白色，越大越靠近黑色，0.5时是中间值。
int WER_motor_sign;		//电机类型，取值为0时表示开环电机，取值为1时表示闭环电机。


void WER_InitRobot_5(int DCL,float PowerL,int DCR,float PowerR,int IO0,int IO1,int IO2,int IO3,int IO4,int motorType);   //0828 五灰度初始化
void WER_next();                                                   //0828 按钮
void WER_Set_Floorsensor();                                       //0828 环境采集
void WER_SetMotor(int Lspeed,int Rspeed,float hold_time);         //0828 启动马达 （带延时）
void WER_SetMotor_L(int IO,char* operator,int reference,int Lspeed,int Rspeed);   //0828 启动马达（传感器触发）
void WER_Around(int speed_L,int speed_R,int P);                   //0828 转弯
//void WER_LineWay_C(int speed, int  Senser);                       //0828 路口巡线
void WER_LineWay_C(int speed, int  Senser,float time);            //1010 路口巡线
void WER_LineWay_T(int speed,float time);                         //0828 按时巡线
void WER_RTurn(int speed);                                        //0828 右转
void WER_LTurn(int speed);                                        //0828 左转

#endif

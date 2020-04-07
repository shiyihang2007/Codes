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

//设置远程控制器的DO端口
//id为远程控制器的ID号，ch为通道号0~11,state为0（关灯）或者1(亮灯）
int Client_SetDO(int id,int ch,int state);

//读取远程控制器的编码器端口计数值
//id为远程控制器的ID号，ch为通道号0~11
int Client_encoder(int id,int ch);

//清零远程控制器的编码器端口读数
//id为远程控制器的ID号，ch为通道号0~11
void Client_CntClear(int id,int ch);

//读取远程控制器的AI端口
//id为远程控制器的ID号，ch为通道号0~11   
int  Client_AI(int id,int ch);

//读取远程控制器的DI端口
//id为远程控制器的ID号，ch为通道号0~11   
int  Client_DI(int id,int ch);

//读取远程控制器的电机端口
//id为远程控制器的ID号，ch为通道号0~3，speed为速度-100~100   
int  Client_SetMoto(int id,int ch,int speed);

//获取远程图像模块颜色标号为color_index（0~7）的物体的宽度
int Client_Camera_weight(int id,int color_index);

//获取远程图像模块颜色标号为color_index（0~7）的物体的顶点x坐标
int Client_Camera_x(int id,int color_index);

//获取远程图像模块颜色标号为color_index（0~7）的物体的顶点y坐标
int Client_Camera_y(int id,int color_index);

//获取远程图像模块颜色标号为color_index（0~7）的物体的高度
int Client_Camera_height(int id,int color_index);

//读取舵机角度
int PO16_ReadAngle(int id);

#endif
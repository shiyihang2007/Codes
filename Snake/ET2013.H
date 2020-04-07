#ifndef _ET2013_H
#define _ET2013_H
	
	#include "stm32f10x.h"
	#include "stm32f10x_adc.h"
	#include "stm32f10x_dma.h"
	#include "stm32f10x_fsmc.h"
	#include "stm32f10x_dac.h"

	#include "stdio.h"
	#include "stdarg.h"
	#include "errno.h"
	#include "math.h"
	#include "FreeRTOS.h"
	#include "task.h"
	#include "queue.h"
#include <stdlib.h>
#include <string.h>

	#define BIT0 (1<<0)
	#define BIT1 (1<<1)
	#define BIT2 (1<<2)
	#define BIT3 (1<<3)
	#define BIT4 (1<<4)
	#define BIT5 (1<<5)
	#define BIT6 (1<<6) 
	#define BIT7 (1<<7)
	#define BIT10 (1<<10)
	
	//=================================================
//编码器电机、舵机
//=================================================
#define TASKCOUNT 17
#define MAXDEVICE 20
#define MAXBUFFER_PO16 50  //lucy 0815
typedef struct 
{
	int CSLen;//
	unsigned char CS[MAXBUFFER_PO16];//
	int CRLen;//
	unsigned char CR[MAXBUFFER_PO16];//
    //unsigned char OneTime;//发送次数error
    //char OneTime;//发送次数error
    int OneTime;//发送次数
    int Occurred;//0发送过，1没发送过
}Device;//

//485通信队列
xQueueHandle xQueue485;

typedef struct Node{
	Device po16;  //485设别
	u8 bit;				//数据长度
	u8 mode;    //返回数据类型
	xTaskHandle x485Task;//线程句柄
	int result485; //返回
	struct Node * next;
}x485List;
x485List* x485Head;

void v485ListInit();
//x485List* vGet485List();
x485List* vSet485List(Device my485dev,u8 bit,u8 mode,xTaskHandle x485Task);


	void ArmRobotInit(void);
	
	//数学函数：返回浮点型变量的绝对值。
    double fabs(double x);
	
	/****************************************************************************
	* 名    称：void SetMoto(int ch,int speed)
	* 功    能：设置电机参数
	* 入口参数：
								int ch  		需要设置的电机的通道，范围0-3
								int speed， 需要设置的电机的速度，范围-100 - +100
	* 出口参数：无
	* 说    明：无
	* 调用方法：SetMoto(0,-50);	//	设置编号为0的电机口的速度为-50
	****************************************************************************/
	void SetMoto(int ch,int speed);		

	/****************************************************************************
	* 名    称：int GetEncode(int ch)
	* 功    能：获取指定电机的编码器读值
	* 入口参数：
	* 出口参数：
	* 说    明：
	* 调用方法：
	****************************************************************************/
	int GetEncode(int ch);	

	/****************************************************************************
	* 名    称：void SetDO(int Channel,int State)
	* 功    能：设置输出端口的状态
	* 入口参数：
								int Channel  		需要设置的输出的通道，每一位代表一个通道
								int State， 		需要设置的输出的状态，0或者1
	* 出口参数：无
	* 说    明：无
	* 调用方法：SetDO(0xfff,1);	//	设置所有的端口输出高电平
	****************************************************************************/
	void SetDO(int Channel,int State);
	
	
	/****************************************************************************
	* 名    称：void BEEP(int SampleRate,int WaitTime)
	* 功    能：设置蜂鸣器
	* 入口参数：
			int SampleRate  	设置蜂鸣器响的音调(0-50)
			int WaitTime 		设置节拍持续时间(1-50)单位:100mS
	* 出口参数：无
	* 说    明：无
	* 调用方法：_BEEP(1,1);	//	设置蜂鸣器响的音调和时间；
	****************************************************************************/
	void BEEP_Init(uint32_t SampleRate,uint32_t StartAddr);
	void BEEP_Stop(void);
	void BEEP(float SampleRate, float WaitTime);
	void tone(float SampleRate, float WaitTime);
	
	
	
	/****************************************************************************
	* 名    称：void wait(float sec)
	* 功    能：等待sec秒时间
	* 入口参数：float sec,需要等待的时间，单位秒，精度0.001秒
	* 出口参数：无
	* 说    明：无
	* 调用方法：wait(0.567);		//	等待0.567秒时间
	****************************************************************************/
	void wait(float sec);			
	
	/****************************************************************************
	* 名    称：float seconds(void);
	* 功    能：返回系统时间全局变量，单位为秒，精度0.001秒
	* 入口参数：无
	* 出口参数：系统时间
	* 说    明：
	* 调用方法：sec = seconds();		//	获取系统时间
	****************************************************************************/	
	float seconds(void);
	
	/****************************************************************************
	* 名    称：void resettime(void)
	* 功    能：重置系统时间
	* 入口参数：无
	* 出口参数：无
	* 说    明：
	* 调用方法：resettime();		//	重置系统时间
	****************************************************************************/
	void resettime(void);	

	/****************************************************************************
	* 名    称：int Get_Button(void)
	* 功    能：获取按键
	* 入口参数：无
	* 出口参数：0 没有按键
					1	左
					2	返回				
					3	右
					4	确认
	* 说    明：
	* 调用方法：key = Get_Button();
	****************************************************************************/
	#define KEY_PWR			1		//	POWER
	#define KEY_ESC			4		//	KEY3
	#define KEY_LF			2		//	KEY2
	#define KEY_RT			8		//	KEY1
	#define KEY_NULL		0	
	int Get_Button(void);
	
//读取左按钮的状态
int Get_BtnLeft();

//读取右按钮的状态
int Get_BtnRight();
	/****************************************************************************
	* 名    称：int AI(int Channel)
	* 功    能：获取指定端口的模拟传感器数值
	* 入口参数：int Channel  指定的端口
	* 出口参数：int，指定端口的模拟数值
	* 说    明：
	* 调用方法：val = AI(1);	// 获取通道号为1的端口的传感器数值
	****************************************************************************/
	int AI(int Channel);	

//取得电池电压
int Get_Battery(void);

//设定电池保护的阀值保护电压,默认：BatterySetup(6800,10000,0)（单位：mv，范围：7200~6500），保护延时时间（单位：ms）
void BatterySetup(int BatVal1,int BatTime1,int beepenable);

	/****************************************************************************
	* 名    称：int DI(int Channel)
	* 功    能：获取指定端口的状态
	* 入口参数：int Channel  指定的端口
	* 出口参数：int，指定端口的的状态，1 为高电平，0为低电平
	* 说    明：
	* 调用方法：val = DI(1);	// 获取通道号为1的端口的端口的数字输入
	****************************************************************************/
	int DI(int Channel);

	void Printf(char *fmt,...);

	/*******************************************************************************
	 * 函数名：	Run
	 * 描述  ：	跳转到指定目标地址运行
	 * 输入  ：	
	 * 输出  ：	
	*******************************************************************************/
	void Exit(void);
	int myputchar(int ch);//mou
	void doMyTick(); //mou
	
	void Sound_Play(int SampleRate,int LengthInByte,uint32_t ReadAddr, uint32_t NumByteToRead);

	void MainPower(int mode);

	void LCD_Backlight(int mode);
	void LCD_DrawPoint(u8 x,u8 y,u8 mode);
	void LCD_DrawPic(u8 x,u8 y,u8 length,u8 high,u8 *dat,u8 mode);
	void LCD_PutString(u8 col,u8 page,char *s,u8 mode);

	int IS_USB_CNT(void);

	void sFLASH_Init(void);

	void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);

	void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead);
	/****************************************************************************
	* 名    称：LCD_DrawLine(u8 x0, u8 y0, u8 x1, u8 y1,u8 mode)
	* 功    能：
	* 入口参数：
	* 出口参数：
	* 说    明：
	* 调用方法：
	****************************************************************************/
	void LCD_DrawLine(u8 x0, u8 y0, u8 x1, u8 y1,u8 mode);

	/****************************************************************************
	* 名    称：void LCD_DrawCircle(u8 cx,u8 cy,u8 r,u8 mode)
	* 功    能：在指定座标画圆，可填充
	* 入口参数：u8 cx 	圆心的x坐标
							u8 cy 	圆心的y坐标
							u8 r  	圆的半径
							u8 mode 圆是否填充（实心）
	* 出口参数：
	* 说    明：
	* 调用方法：
	****************************************************************************/
	void LCD_DrawCircle1(u8 cx,u8 cy,u8 r,u8 mode);	

	//*************************************************************************************
	// 函数名		:		WriteEEPROM	
	// 功能描述	：	将数据写入指定EEPROM	
	// 参数			：	名称:char addr
	//              描述:需要写入的EEPROM的地址，范围0 - 64
	// 参数			：	名称:int dat
	//              描述:需要写入的EEPROM的数据，范围0 - 65535
	// 返回值		:		void
	// 等级			:   1
	//*************************************************************************************
	void WriteEEPROM(char addr,int dat);	

	//*************************************************************************************
	// 函数名		:		ReadEEPROM	
	// 功能描述	：	读取指定EEPROM的数值		
	// 参数			：	名称:char addr
	//              描述:需要读取的EEPROM的地址，范围0 - 64
	// 返回值		:		int，指定的EEPROM的数值
	// 等级			:   1
	//*************************************************************************************
	int ReadEEPROM(char addr);

	/****************************************************************************
	* 名    称：int encoder(int index)
	* 功    能： 
	* 入口参数：
	* 出口参数：
	* 说    明：读取计数器值，index为计数器序号，取值0~11，1对应计数器1，2对应计数器
	* 调用方法：
	****************************************************************************/
	int encoder(int index);
	
	/****************************************************************************
	* 名    称：int encoder(int index)
	* 功    能： 
	* 入口参数：
	* 出口参数：
	* 说    明：读取计数器值，index为计数器序号，取值0~11，1对应计数器1，2对应计数器
	* 调用方法：
	****************************************************************************/
	int encoder(int index);

	/****************************************************************************
	* 名    称：int CntClear(int index)
	* 功    能： 
	* 入口参数：
	* 出口参数：
	* 说    明：计数器清零，index为计数器序号，取值0~11，1对应计数器1，2对应计数器2
	* 调用方法：
	****************************************************************************/
	int CntClear(int index);
	
	/****************************************************************************
	* 名    称：int CntStart(int index)
	* 功    能： 
	* 入口参数：
	* 出口参数：
	* 说    明：计数启动，index为计数器序号，取值0~11，1对应计数器1，2对应计数器
	* 调用方法：
	****************************************************************************/
	int CntStart(int index);

	/****************************************************************************
	* 名    称：int CntStop(int index)
	* 功    能： 
	* 入口参数：
	* 出口参数：
	* 说    明：计数停止，index为计数器序号，取值0~11，1对应计数器1，2对应计数器2。
	* 调用方法：
	****************************************************************************/
	void CntStop(int index);
	
	void Cntinital(void);
	
	void LCD_FastDramHline(u8 x,u8 y,u8 num,u8 dat);

	void LCD_PutHz12x12(u8 x,u8 y,u8 *s,u8 mode);
//*************************************************************************************
//函数名:		InitDevice	
// 功能描述	:	舵机通讯端口初始化		
// 参数			:	名称:int baud
//              描述:需要设定的和舵机通讯的波特率
//              范围:1200-1000000,单位bps,默认值500000
// 返回值		:		void
// ??			:   1
//*************************************************************************************
//int InitDevice(int baud);
void InitDevice(int baud);

//*************************************************************************************
// 函数名		:		PO16_ReadRegister	
// 功能描述	:	读取指定舵机的指定寄存器		
// 参数			:	名称:int id
//              描述:指定舵机ID,ID = 254时为广播地址
// 参数		:	名称:int Reg
//              描述:需要读取的寄存器,范围0-48
// 返回值		:		int,返回2012失败,其他数值成功
// ??			:   1
//*************************************************************************************
int PO16_ReadRegister(int id,int Reg);
//*************************************************************************************
// 函数名		:		PO16_WriteRegister	
// 功能描述	:	改写指定舵机的指定寄存器		
// 参数			:	名称:int id
//              描述:需要指定的舵机ID,ID = 254为广播地址
// 参数			:	名称:int Reg
//              描述:需要指定的寄存器,范围0-48
// 参数			:	名称:int dat
//              描述:需要设定的寄存器值,范围0-1023
// 返回值		:		int,0失败,1成功
// ??			:   1
//*************************************************************************************
void PO16_WriteRegister(int id,int Reg,int dat);	
// 函数名		:		PO16_Move	
// 功能描述	:启动舵机		
// 参数			:	名称:int id
//              ??:需要设定的舵机ID?,ID = 254?????
// 参数			:	名称:int iSpeed
//              ??:需要设定的舵机速度,0-1023
// 参数 		:	名称:int iPos
//              ??:需要设定的舵机位置,0-1023
// 返回值		:		int,0失败,1成功
// 等级			:   1
//*************************************************************************************
//int PO16_Move(int id ,int iSpeed,int iPos);
void PO16_Move(int id ,int iSpeed,int iPos);
void ServoPort_Init(int channel);


//设置485编码器电机的速度，返回当前实际测试的速度，iSpeed范围-1023~1023,对于280电机(-400~400),380电机（-700~700）
int SetMotor_Encoder(int id ,int iSpeed);
//*************************************************************************************
// define Name:           CLOSEMODLE			
// define Description:    设定编码器/闭环电机为闭环状态
//*************************************************************************************
#define CLOSEMODLE 0

//*************************************************************************************
// define Name:           OPENMODLE			
// define Description:    设定编码器/闭环电机为开环状态
//*************************************************************************************
#define OPENMODLE 1

//设置280电机开环闭环状态，CLOSEMODLE闭环，OPENMODLE开环
void SetMotor_Model(int id ,int model);

void SetMotoCL(int ch, int MovingSpeed);
/****************************************************************************
* 名    称：int GetPrevSpeed(int ch)
* 功    能：获取指定电机的编码器读值
* 入口参数：
* 出口参数：
* 说    明：
* 调用方法：
****************************************************************************/
int GetPrevSpeed(int ch);
//*************************************************************************************
// Function Name:		  RS485_ERRCOUNT	
// Function Description:  RS485错误计数
// Params:				  void
// Return Value:		  int
// Level:				  10
//*************************************************************************************
int RS485_ERRCOUNT(void);

//*************************************************************************************
// Function Name:		  RS485_ERRCOUNT
// Function Description:  RS485错误计数清零
// Params:				  void
// Return Value:		  int
// Level:				  10
//*************************************************************************************
void RS485_ERRCOUNTClear(void);

// //*************************************************************************************
// // Function Name:		  		Dpy8_Dis 
// // Function Description:  数码管显示控制
// // Params:				 
// //				Mode：0：显示标准字符 0-F ，Index为索引;   1: 显示自定义字符，码值按照 Index 的值解码显示
// //				Index: Mode=0时为索引值；Mode=1时为码值   MSB 7 - LSB 0 依次代表  DP-G-F-E-D-C-B-A, “0”代表显示，“1”代表不显示此段
// //				DP:小数点控制位：0表示不显示小数点，1表示显示小数点
// //				FLASH:闪烁控制，0表示关闭数码管，1表示打开数码管，2表示数码管闪烁
// // Return Value:		      void
// //*************************************************************************************
void Dpy8_DisFun(int id,int Index,u8 Flash,u8 mode);
//*************************************************************************************
// Function Name:		  		Gyro_ReadRegister 
// Function Description:  485端口读数据
// Params:				 			  id—设备id，mode-陀螺仪输出数据选择
// Return Value:		 			int
//*************************************************************************************
int Gyro_ReadRegister(int id,u8 mode);

int getGyro(int i,u8 mode);

//读取485返回值
int get485Return(x485List* tempNode );

//添加设备到队列
int DeviceAddToQueue(Device my485dev,u8 bit,u8 mode);

//随机数
int Get_Rand(int min,int max);
void Init_UART5(u32 baud);

int UART5_RecvStrig(char *ptr);

int GetHandle(void);
#endif	

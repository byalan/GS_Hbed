#include <reg52.h>
#include "Sys.h"
#include "Uart.h"
#include "stdio.h"//使用printf需要

/***************************************************
*								串口初始化子函数
*				T1工作在方式2，波特率9600，开串口中断
****************************************************/
void Uart_Init(void)
{
	TMOD |= 0x20;        // 定时器1工作在方式2
	SCON |= 0x50;        // 8位uart，允许串行接受
	TH1 = 0xFD;					//设置定时器初值
	TL1 = 0xFD;					//设置定时器初值
	TR1 = 1;						//启动定时器1
	TI=1;						//发送中断标记位必须设置
	EA=1;         	//允许总中断	
}

///***************************************************
//*								UART发送一个字节
//****************************************************/
//void UART_Send_Byte(uint8 dat)
//{
//	SBUF = dat;					//送入缓冲寄存器
//	while (TI == 0);		//等待发送完成
//	TI = 0;
//}
///***************************************************
//*								UART发送一串字符
//****************************************************/
//void UART_Send_STR(uint8 *str)
//{
//	while(*str != '\0')
//	{
//		SBUF = *str;					//送入缓冲寄存器
//		while (TI == 0);		//等待发送完成
//		TI = 0;
//		str++;								//地址加一
//	}
//}

/***************************************************
*								中断服务子函数
*				   清除RI，同时判断接到的数据
****************************************************/
//void uart(void) interrupt 4
//{
//	unsigned char Uart_Buf;	//接收数据寄存器
//	if(RI)    							//是否收到数据
//	 {
//		RI=0;   							//清中断请求
//		Uart_Buf = SBUF;
////		if(Uart_Buf == 0xaa)	//判断
////			LED = 0;
////		else if(Uart_Buf == 0x00)
////			LED = 1;
//	 }
//}
/*
 * ht162x.c
 *
 *  Created on: Jan 14, 2019
 *      Author: wj1080
 */


#include "ht162x.h"
#include "delayus.h"


/**
  * @函数功能    HT162X驱动芯片通信端口初始化.
  * @函数参数  	无.
  * @函数返回值	 无.
  */
static void ht162xCommPortsInit(void)
{
	configHT162X_CSPinOutput();
	HT162X_CSPin_OutputHigh();

	configHT162X_RDPinOutput();
	HT162X_RDPin_OutputHigh();

	configHT612X_WRPinOutput();
	HT162X_WRPin_OutputHigh();

	configHT162X_DATAPinOutput();
	HT162X_DATAPin_OutputHigh();
}

/**
  * @函数功能    向HT162X驱动芯片写入指定位长度的数据.最大位长度是8,即1字节.注意：高位在前低位在后.
  * @函数参数   wData,待发送的一字节数据;
  * @函数参数  wBitSize, 待发送的数据位长度;
  * @函数返回值	 0, 发送成功; -1, 发送失败;
  */
int ht162xWriteDataBitsMSB(uint8_t wData, uint8_t wBitSize)
{
	uint8_t i;
	if (wBitSize > 8)return (-1);

	for (i = 0; i < wBitSize; i++)
	{
		/* 先将待发送的数据在端口上准备就绪. */
		if (wData & 0x80)
		{
			HT162X_DATAPin_OutputHigh();
		}
		else
		{
			HT162X_DATAPin_OutputLow();
		}

		HT162X_WRPin_OutputLow();

		wData <<= 1;

		systemDelayUs(10);

		HT162X_WRPin_OutputHigh();

		systemDelayUs(10);
	}

	return (0);
}

/**
  * @函数功能    向HT162X驱动芯片写入指定位长度的数据.最大位长度是8,即1字节.注意：低位在前高位在后.
  * @函数参数   wData,待发送的一字节数据;
  * @函数参数  wBitSize, 待发送的数据位长度;
  * @函数返回值	 0, 发送成功; -1, 发送失败;
  */
int ht162xWriteDataBitsLSB(uint8_t wData, uint8_t wBitSize)
{
	uint8_t i;
	if (wBitSize > 8)return (-1);

	for (i = 0; i < wBitSize; i++)
	{
		/* 先将待发送的数据在端口上准备就绪. */
		if (wData & 0x01)
		{
			HT162X_DATAPin_OutputHigh();
		}
		else
		{
			HT162X_DATAPin_OutputLow();
		}

		HT162X_WRPin_OutputLow();

		wData >>= 1;

		systemDelayUs(10);

		HT162X_WRPin_OutputHigh();

		systemDelayUs(10);
	}

	return (0);
}

/**
  * @函数功能    配置HT162X驱动芯片工作在指定的命令.
  * @函数参数  	cmdData, 指定的命令.
  * @函数返回值	 无.
  */
void ht162xWriteCommand(uint8_t cmdData)
{
	ht162xWriteDataBitsMSB(cmdData, 8);

	/* 写入最后一个"无关位". */
	HT162X_DATAPin_OutputLow();
	HT162X_WRPin_OutputLow();
	systemDelayUs(10);
	HT162X_WRPin_OutputHigh();
	systemDelayUs(10);
}

/**
  * @函数功能    初始化配置HT162X驱动芯片.
  * @函数参数  	无.
  * @函数返回值	 无.
  */
void ht162xInit(void)
{
	ht162xCommPortsInit();								/* HT162X通信端口初始化. */

	HT162X_CSPin_OutputLow();							/* 拉低CS信号. */
	systemDelayUs(10);

	ht162xWriteDataBitsMSB(COMMAND_OPERATION_ID, 3);	/* 设置命令操作模式. */

	ht162xWriteCommand(SYS_EN);
	ht162xWriteCommand(LCD_ON);
	ht162xWriteCommand(TIMER_DIS);
	ht162xWriteCommand(WDT_DIS);
	ht162xWriteCommand(TONE_OFF);
	ht162xWriteCommand(RC_32K);
	ht162xWriteCommand(IRQ_DIS);
	ht162xWriteCommand(TONE_4K);
	ht162xWriteCommand(NORMAL);

	systemDelayUs(10);
	HT162X_CSPin_OutputHigh();							/* 拉高CS信号. */
}

/**
  * @函数功能    向HT162X显示内存写入半字节长度的数据.
  * @函数参数  	addr, 指定的显示内存地址.对于HT1622支持的取值范围：0~63.
  * @函数参数    wData, 要写入的段数据.实际写入的是其低半字节数据.
  * @函数返回值	 无.
  */
void ht162xWriteHalfByteData(uint8_t addr, uint8_t wData)
{
	HT162X_CSPin_OutputLow();							/* 拉低CS信号. */
	systemDelayUs(2);

	ht162xWriteDataBitsMSB(WRITE_OPERATION_ID, 3);
	ht162xWriteDataBitsMSB((addr << 2), 6);				/* 因为是调用MSB写入函数,故地址需要左移2位.写入6位地址信息. */
	ht162xWriteDataBitsLSB(wData, 4);					/* 写入4位半字节数据. */

	systemDelayUs(2);
	HT162X_CSPin_OutputHigh();							/* 拉高CS信号. */
}

/**
  * @函数功能   向HT162X显示内存写入完整的一字节长度的数据.
  * @函数参数   segAddr, 指定的段地址.对于HT1622支持的取值范围：0~31.
  * @函数参数   wtData, 待写入的一字节数据.
  * @函数返回值	 无.
  */
void ht162xWriteOneByteData(uint8_t segAddr, uint8_t wtData)
{
	uint8_t i, wtAddr;

	wtAddr = segAddr * 2;

	for (i = 0; i < 2; i++)
	{
		ht162xWriteHalfByteData(wtAddr, wtData);

		wtAddr += 1;									/* 写入低半字节数据后,地址递增. */
		wtData >>= 4;									/* 写入低半字节数据后,数据右移4位准备写入高半字节数据. */
	}
}

/**
  * @函数功能    向HT162X显示内存连续性写入指定长度的数据.注意：该函数的写入显示内存一定是连续性的地址内存.
  * @函数参数  	segAddr, 指定的段地址.对于HT1622支持的取值范围：0~31.
  * @函数参数    segCount, 要写入的段数量.
  * @函数参数    *pWdat, 待写入的数据存储缓冲区.
  * @函数返回值	 无.
  */
void ht162xWriteSuccessiveBytesData(uint8_t segAddr, uint8_t segCount, uint8_t* pWdat)
{
	uint8_t i, wtAddr;

	wtAddr = segAddr * 2;

	HT162X_CSPin_OutputLow();							/* 拉低CS信号. */
	systemDelayUs(2);

	ht162xWriteDataBitsMSB(WRITE_OPERATION_ID, 3);
	ht162xWriteDataBitsMSB((wtAddr << 2), 6);			/* 因为是调用MSB写入函数,故地址需要左移2位.写入6位地址信息. */

	for (i = 0; i < segCount; i++)
	{
		ht162xWriteDataBitsLSB(*pWdat, 4);
		ht162xWriteDataBitsLSB((*pWdat >> 4), 4);
		pWdat++;
	}

	systemDelayUs(2);
	HT162X_CSPin_OutputHigh();							/* 拉高CS信号. */
}



/*
 * delayus.c
 *
 *  Created on: Jan 16, 2019
 *      Author: wj1080
 */


#include "delayus.h"
#include "ftm.h"



/**
  * @函数功能    微秒级延时初始化.注意：本微秒级延时主要通过MCU片上FTM定时器的计时实现的.
  * @函数功能    定时中断并未使能,而是采用轮询模式等待延时时间到.
  * @函数参数  	无.
  * @函数返回值	 无.
  */
void systemDelayUsInit(void)
{
}

/**
  * @函数功能    微秒级延时.
  * @函数参数  	delayTimeUs,延时的微秒数.注意：本微秒级延时函数是使用FTM0定时器基本计数实现的.
  *         FTM0定时器计数周期是0.2us.计数器最大计数周期是(0xffff+1)*0.2us=13107.2us.
  *         所以，传入的参数不能大于这个数值.
  * @函数返回值	 无.
  */
void systemDelayUs(uint16_t delayTimeUs)
{
	/* FTM采用系统20MHZ时钟，4分频,则FTM定时器计时周期T=0.2us. */
	FTM_BasicCounterProDef_t ftmConfig;
	uint16_t mod;
	float value = (float)delayTimeUs / 0.2;
	mod = (uint16_t)value - 1;


	ftmConfig.InterruptState 	= 0;
	ftmConfig.ModVal  			= mod;
	ftmConfig.InitVal 			= 0;
	ftmConfig.ClkSrc  			= System_Clock;
	ftmConfig.ClkDiv  			= FTM_ClockDiv4;

	FTM_BasicCounterInit(HW_FTM0, &ftmConfig);
	FTM_BasicCounterWaitOverFlow(HW_FTM0);
	FTM_BasicCounterDeInit(HW_FTM0);
}

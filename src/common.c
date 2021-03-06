/*
 * common.c
 *
 *  Created on: Jan 23, 2019
 *      Author: wj1080
 */


#include "common.h"


static FlagStatus systemINTStatus = FlagRESET;


/**
  * @函数功能
  * @函数参数
  * @函数返回值
  */
void suspendSystemInterrupt(void)
{
	if (systemINTStatus == FlagRESET)
	{
		SUSPEND_INTERRUPT();

		systemINTStatus = FlagSET;
	}
}

/**
  * @函数功能
  * @函数参数
  * @函数返回值
  */
void resumeSystemInterrupt(void)
{
	if (systemINTStatus == FlagSET)
	{
		RESUME_INTERRUPT();

		systemINTStatus = FlagRESET;
	}
}


/*
 * acc.h
 *
 *  Created on: Jan 14, 2019
 *      Author: wj1080
 */

#ifndef ACC_H_
#define ACC_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "derivative.h"
#include "gpio.h"

#define  ACC_SIGNAL_GPIOPin		GPIO_PTD2
#define  ACC_SIGNAL_Read()		GPIO_PinRead(ACC_SIGNAL_GPIOPin)

#define  ACC_SIGNAL_KBIx		KBI0
#define  ACC_SIGNAL_Piny		KBI0_P26

#define  ACC_SIGNAL_FILTER_TIME		(5)				/* 滤波时间5*10ms = 50ms. */
#define  ACC_SIGNAL_COUNT			(1)

typedef enum
{
	ACC_SIGNAL_NONE = 0,							/* 无ACC信号事件.  */
	ACC_SIGNAL_VALID_ET,							/* ACC信号有效事件. */
	ACC_SIGNAL_INVALID_ET,							/* ACC信号无效事件. */
}ACCSignalEventDef_t;

typedef struct
{
	uint8_t (*IsAccSigValidFunc)(void);				/* ACC信号检测回调函数,该函数用于判断ACC信号实际电平值. */
	uint8_t validCount;								/* ACC信号有效时连续检测时间计数器. */
	uint8_t invalidCount;							/* ACC信号无效时连续检测事件计数器. */
	uint8_t eventMutex;								/* 访问ACC事件FIFO互斥信号量. */
	volatile uint8_t timScanCount;					/* 定时扫描ACC信号时间计数器. */
}ACCSignalPropertyDef_t;

#define  ACC_SIGNAL_EVENT_FIFO_SIZE	(10)			/* ACC信号事件FIFO长度. */

typedef struct
{
	uint8_t ebuffer[ACC_SIGNAL_EVENT_FIFO_SIZE];
	uint8_t writePtr;
	uint8_t readPtr;
}ACCSignalEventFIFODef_t;

typedef enum
{
	ACC_INVALID = 0,
	ACC_VALID,
}ACCSignalStateDef_t;

typedef enum
{
	ACC_INT_FALSE = 0,
	ACC_INT_TRUE,
}ACCSignalINTTriggerStateDef_t;



ACCSignalStateDef_t systemAccSignalDetect(void);
void systemAccSignalInit(void);
void systemAccSignalPutEvent(uint8_t wtCode);
uint8_t systemAccSignalGetEvent(void);

void systemAccSignalTriggerINTCallback(void);
void systemAccSignalScanCallback(void);

#ifdef __cplusplus
}
#endif
#endif /* ACC_H_ */

/*
 * inputKeys.h
 *
 *  Created on: Jan 14, 2019
 *      Author: wj1080
 */

#ifndef INPUTKEYS_H_
#define INPUTKEYS_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "derivative.h"
#include "gpio.h"


#define  GPIO_PIN_SETKEY	(GPIO_PTC0)
#define  GPIO_PIN_FLIPKEY	(GPIO_PTC1)

#define  KEY_COUNT		(2)							/* Input keys number:2 */

typedef enum
{
	KEY_NONE = 0,

	SETKEY_DOWN,
	SETKEY_UP,
	SETKEY_LONG,

	FLIPKEY_DOWN,
	FLIPKEY_UP,
	FLIPKEY_LONG,
}KEYEventDef_t;

#define  KEY_DOWN_SET		SETKEY_DOWN
#define  KEY_UP_SET			SETKEY_UP
#define  KEY_LONG_SET		SETKEY_LONG

#define  KEY_DOWN_FLIP		FLIPKEY_DOWN
#define  KEY_UP_FLIP		FLIPKEY_UP
#define  KEY_LONG_FLIP		FLIPKEY_LONG


typedef enum
{
	KID_SET = 0,
	KID_FLIP,
}KEYIdDef_t;


#define  KEY_FILTER_TIME	(5)						/* Filter time:5*10ms = 50ms. */
#define  KEY_LONG_TIME		(500)					/* Long press event time:500*10ms = 5000ms. */

typedef struct
{
	uint8_t (*IsKeyDownFunc)(void);

	uint16_t longCount;
	uint16_t longTime;

	uint8_t  count;
	uint8_t  state;
}KEYPropertyDef_t;

#define  KEY_FIFO_SIZE		(10)

typedef struct
{
	uint8_t buffer[KEY_FIFO_SIZE];
	uint8_t writePtr;
	uint8_t readPtr;
}KEYFIFOTypeDef_t;


void inputKeysInit(void);
void inputKeysPutEvent(uint8_t keyCode);
uint8_t inputKeysGetEvent(void);
void inputKeysScanning(void);


#ifdef __cplusplus
}
#endif
#endif /* INPUTKEYS_H_ */

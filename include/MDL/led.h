/*
 * led.h
 *
 *  Created on: Jan 15, 2019
 *      Author: wj1080
 */

#ifndef LED_H_
#define LED_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "derivative.h"
#include "gpio.h"


#define  LEDLIGHT_GPIO_Pin	GPIO_PTC5


void ledLightInit(void);
void ledLightOn(void);
void ledLightOff(void);
void ledLightToggle(void);

#ifdef __cplusplus
}
#endif
#endif /* MDL_LED_H_ */

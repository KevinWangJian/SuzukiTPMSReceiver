/*
 * spi.h
 *
 *  Created on: Jan 13, 2019
 *      Author: wj1080
 */

#ifndef SPI_H_
#define SPI_H_

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
* Includes
******************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include "derivative.h"
#include "assert.h"
#include "gpio.h"

#define  RF_CS_Pin		GPIO_PTB5
#define  RF_MOSI_Pin	GPIO_PTB3
#define  RF_MISO_Pin	GPIO_PTB4
#define  RF_SCK_Pin		GPIO_PTB2

#define  RF_CS_Low()	GPIO_PinClear(RF_CS_Pin)
#define  RF_CS_High()	GPIO_PinSet(RF_CS_Pin)
//#define  RF_CS_Low()	GPIOA->PCOR |= (1 << GPIO_PTB5)
//#define  RF_CS_High()	GPIOA->PSOR |= (1 << GPIO_PTB5)

#define  RF_MOSI_Low()	GPIO_PinClear(RF_MOSI_Pin)
#define  RF_MOSI_High()	GPIO_PinSet(RF_MOSI_Pin)
//#define  RF_MOSI_Low()	GPIOA->PCOR |= (1 << GPIO_PTB3)
//#define  RF_MOSI_High()	GPIOA->PSOR |= (1 << GPIO_PTB3)

#define  RF_SCK_Low()	GPIO_PinClear(RF_SCK_Pin)
#define  RF_SCK_High()	GPIO_PinSet(RF_SCK_Pin)
//#define  RF_SCK_Low()	GPIOA->PCOR |= (1 << GPIO_PTB2)
//#define  RF_SCK_High()	GPIOA->PSOR |= (1 << GPIO_PTB2)

#define  RF_MISO_Read()	GPIO_PinRead(RF_MISO_Pin)
//#define  RF_MISO_Read()	(GPIOA->PDIR & (1 << GPIO_PTB4))


void HAL_SpiCommPortsInit(void);
void HAL_SpiWriteOneByteData(uint8_t wData);
uint8_t HAL_SpiReadOneByteData(void);


#ifdef __cplusplus
}
#endif
#endif /* HAL_DRIVERS_SPI_H_ */

/*
 * assert.h
 *
 *  Created on: Jan 19, 2019
 *      Author: wj1080
 */

#ifndef ASSERT_H_
#define ASSERT_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "derivative.h"


void assert_failed(uint8_t* file, uint32_t line);


 #ifdef DEBUG_PRINT
 #define ASSERT(expr) \
     if (!(expr)) \
	 assert_failed(__FILE__, __LINE__)
 #else
 #define ASSERT(expr)
 #endif


#ifdef __cplusplus
}
#endif
#endif /* ASSERT_H_ */

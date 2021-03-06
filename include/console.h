/*
 * console.h
 *
 *  Created on: Jan 19, 2019
 *      Author: wj1080
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "ewl_misra_types.h"
#include "file_struc.h"


int_t __read_console(__file_handle handle, uchar_t * buffer, size_t * count);
int_t __write_console(__file_handle handle, uchar_t * buffer, size_t * count);
int_t __close_console(__file_handle handle);


#ifdef __cplusplus
}
#endif
#endif /* CONSOLE_H_ */

/**
* @file    data_type.h
*
* @author  Farzin Yousefian
*
* @date    10.13.2020 (date of creation)
* @ingroup EV_Group
*
* @prefix  XXX
*
* @brief   typedef data type
*
* @details Embedded hardware selection: Intel->x86-64 (Windows64)
*
*/

#ifndef INCLUDE_APP_GENERAL_STD_TYPES_H_
#define INCLUDE_APP_GENERAL_STD_TYPES_H_

#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include <string.h>

/* Logical type definitions */
#  ifndef FALSE
#   define FALSE    (0)
#  endif

#  ifndef TRUE
#   define TRUE (1)
#  endif


/* Logical Yes/No type definitions */
#  ifndef NO
#   define NO   (0U)
#  endif

#  ifndef YES
#   define YES  (1U)
#  endif
/*=======================================================================*
* Target hardware information
*   Device type: Intel->x86-64 (Windows64)
*   Number of bits:     char:   8    short:   16    int:  32
*                       long:  32
*                       native word size:  64
*   Byte ordering: LittleEndian
*   Signed integer division rounds to: Zero
*   Shift right on a signed integer as arithmetic shift: on
*=======================================================================*/

/*=======================================================================*
* Fixed width word size data types:                                     *
*   int8_t, int16_t, int32_t     - signed 8, 16, or 32 bit integers     *
*   uint8_t, uint16_t, uint32_t  - unsigned 8, 16, or 32 bit integers   *
*   float32_t, float64_t           - 32 and 64 bit floating point numbers *
*=======================================================================*/
typedef signed char int8_t;
typedef unsigned char uint8_t;
#if 0
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
#endif
typedef float float32_t;
typedef long double float64_t;
typedef unsigned char error_handler_t;
/*===========================================================================*
* Generic type definitions: boolean_t, char_t, byte_t, int_t, uint_t,       *
*                           real_t, time_t, ulong_t.                        *
*===========================================================================*/
typedef double real_t;
typedef bool boolean_t;
typedef int int_t;
typedef unsigned int uint_t;
typedef unsigned long ulong_t;
typedef char char_t;
typedef unsigned char uchar_t;
typedef char_t byte_t;
typedef struct
{
    uint32_t sec;
    uint32_t up_time_ms;
}TIME_t;

/*=======================================================================*
* Min and Max:                                                          *
*   int8_t, int16_t, int32_t     - signed 8, 16, or 32 bit integers     *
*   uint8_t, uint16_t, uint32_t  - unsigned 8, 16, or 32 bit integers   *
*=======================================================================*/
#define Null_void       ((void *)0x0)
#define MAX_int8_t      ((int8_t)(127))
#define MIN_int8_t      ((int8_t)(-128))
#define MAX_uint8_t     ((uint8_t)(255U))
#define MAX_int16_t     ((int16_t)(32767))
#define MIN_int16_t     ((int16_t)(-32768))
#define MAX_uint16_t    ((uint16_t)(65535U))
#define MAX_int32_t     ((int32_t)(2147483647))
#define MIN_int32_t     ((int32_t)(-2147483647-1))
#define MAX_uint32_t    ((uint32_t)(0xFFFFFFFFU))
#define MAX_float32_t   ((float32_t)(32767.0f))
/* Block D-Work pointer type */
typedef void * pointer_t;
/*=======================================================================*
*                                                                       *
*                                                                       *
*                                                                       *
*=======================================================================*/
#define copy_int32_to_uint32(var_uint32, var_int32)      memcpy((uint8_t*)(&(var_uint32)), (uint8_t*)(&(var_int32)), sizeof(var_int32))
#define copy_int16_to_uint16(var_uint16, var_int16)      memcpy((uint8_t*)(&(var_uint16)), (uint8_t*)(&(var_int16)), sizeof(var_int16))
#define copy_float32_to_uint32(var_uint32, var_flt32)    memcpy((uint8_t*)(&(var_uint32)), (uint8_t*)(&(var_flt32)), sizeof(var_flt32))
#define copy_uint32_to_float32(var_flt32, var_uint32)    memcpy((uint8_t*)(&(var_flt32)), (uint8_t*)(&(var_uint32)), sizeof(var_uint32))

#endif /* INCLUDE_APP_GENERAL_STD_TYPES_H_ */



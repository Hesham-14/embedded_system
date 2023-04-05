/*
 * platform_types.h
 *
 *  Created on: Feb 8, 2023
 *      Author: hesham mohamed
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/*------------ Boolean definition ------------*/
#include <stdbool.h>

#ifndef _Bool
#define _Bool	unsigned char
#endif

#ifndef TRUE
#define TRUE	(boolean)true
#endif

#ifndef FALSE
#define FALSE	(boolean)false
#endif

/*------------ Architecture ------------*/
#define CPU_TYPE_8		8
#define CPU_TYPE_16		16
#define CPU_TYPE_32		32
#define CPU_TYPE_64		64

#define MSB_FIRST		0
#define LSB_FIRST		1

#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST  1

/*------------ Architecture symbols ------------*/
#define CPU_TYPE		CPU_TYPE_32
#define CPU_BIT_ORDER	MSB_FIRST
#define CPU_BYTE_ORDER	HIGH_BYTE_FIRST


//Data types

/*------- boolean data type -------*/

typedef _Bool	boolean;

/*------- Unsigned data types -------*/

typedef unsigned char            uint8_t;
typedef unsigned short           uint16_t;
typedef unsigned int             uint32_t;
typedef unsigned long long       uint64_t;

/*------- Signed data types -------*/

typedef signed char            sint8_t;
typedef signed short           sint16_t;
typedef signed int             sint32_t;
typedef float            	   float32_t;
typedef double                 float64_t;


/*------- Volatile Unsigned data types -------*/

typedef volatile unsigned char            vuint8_t;
typedef volatile unsigned short           vuint16_t;
typedef volatile unsigned int             vuint32_t;
typedef volatile unsigned long long       vuint64_t;


/*------- Volatile Signed data types -------*/

typedef volatile signed char            vsint8_t;
typedef volatile signed short           vsint16_t;
typedef volatile signed int             vsint32_t;
typedef volatile signed long long       vsint64_t;
typedef volatile float          		vfloat32_t;
typedef volatile double         		vfloat64_t;

#endif /* PLATFORM_TYPES_H_ */

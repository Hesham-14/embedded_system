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

typedef unsigned char            uint8;
typedef unsigned short           uint16;
typedef unsigned int             uint32;
typedef unsigned float           uint32;
typedef unsigned double          uint64;
typedef unsigned long long       uint64;
typedef unsigned long double     uint80;


/*------- Signed data types -------*/

typedef signed char            sint8;
typedef signed short           sint16;
typedef signed int             sint32;


/*------- Volatile Unsigned data types -------*/

typedef volatile unsigned char            vuint8;
typedef volatile unsigned short           vuint16;
typedef volatile unsigned int             vuint32;
typedef volatile unsigned float           vuint32;
typedef volatile unsigned double          vuint64;
typedef volatile unsigned long long       vuint64;
typedef volatile unsigned long double     vuint80;


/*------- Volatile Signed data types -------*/

typedef volatile signed char            vsint8;
typedef volatile signed short           vsint16;
typedef volatile signed int             vsint32;
typedef volatile signed float           vsint32;
typedef volatile signed double          vsint64;
typedef volatile signed long long       vsint64;
typedef volatile signed long double     vsint80;

#endif /* PLATFORM_TYPES_H_ */

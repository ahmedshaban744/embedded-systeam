#ifndef PLATFORM_TYPE_H_
#define PLATFORM_TYPES_H_
#endif // PLATFORM_TYPE_H_

#include <stdbool.h>
#include <stdint.h>
#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE      CPU_TYPE_32
#define cpu_BIT_ORDED   MSB_FIRST
#define CPU_BYTE_ORDED  HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE     (boolean)false
#endif

#ifndef TRUE
#define FALSE     (boolean)true
#endif

typedef _Bool       boollean;
typedef int8_t      sint8;
typedef uint8_t      uint8;
typedef char        char_t;
typedef int16_t      sint16;
typedef uint16_t      uint16;
typedef int32_t      sint32;
typedef uint32_t      uint32;
typedef int64_t      sint64;
typedef uint64_t      uint64;

typedef volatile int8_t vint8_t;
typedef volatile uint8_t uvint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t uvint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t uvint32_t;

typedef volatile int64_t vint64_t;
typedef volatile uint64_t uvint64_t;

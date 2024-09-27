#pragma once

// typedefs
typedef unsigned char uint8;
typedef signed char int8;

typedef __int16					int16;
typedef unsigned __int16		uint16;
typedef __int32					int32;
typedef unsigned __int32		uint32;
typedef __int64					int64;
typedef unsigned __int64		uint64;

// for ghidra vtable exports
typedef uint8 uint8_t;
typedef uint16 uint16_t;
typedef uint32 uint32_t;
typedef uint64 uint64_t;

typedef void* undefined;
typedef int undefined4;
typedef uint8 undefined8;
//typedef char byte;
typedef float vec_t;

#ifdef _WIN32
typedef wchar_t ucs2; // under windows wchar_t is ucs2
#else
typedef unsigned short ucs2;
#endif
//===== Source 2 Research & Development =============================================//
// 
// Any code re-used from previous Source(TM) branches, or reverse engineered
// from Source2(TM) Binaries, are properties Copyright © 1996-202(x), Valve Corporation
// 
//===================================================================================//
#pragma once
#include <malloc.h>
#include <new>
#include <string.h>
#include <stdint.h>
#include <crtdbg.h>
#include <math.h>
#include "annotations.h"
#include "wchartypes.h"
#include "Color.h"
#include "logging.h"
#include "types.h"

// defs
#define OVERRIDE override
#define IsPC() true
#define IsLinux() false
#define IsPosix() false
#define IsX360() false

#if defined(DEBUG) || defined (_DEBUG)
#define IsDebug() true
#define IsRelease() false
#else
#define IsDebug() false
#define IsRelease() true
#endif

#define EXPORT	extern "C" _declspec( dllexport )
#define DLL_EXPORT	extern "C" _declspec( dllexport )
#define DLL_IMPORT	extern "C" _declspec( dllimport )
#define DBG_INTERFACE	extern "C" _declspec( dllimport )

// Can't use extern "C" when DLL exporting a global
#define DLL_GLOBAL_EXPORT		extern __declspec( dllexport )
#define DLL_GLOBAL_IMPORT		extern __declspec( dllimport )

#define PLATFORM_INTERFACE	DLL_IMPORT
#define PLATFORM_OVERLOAD	DLL_GLOBAL_IMPORT
#define PLATFORM_CLASS		DLL_CLASS_IMPORT

#define DLL_EXT_STRING ".dll"
#define _getcwd getcwd
#define FMTFUNCTION( a, b )

//#define Error(...) return;
#define Assert(...)
#define AssertMsg(...)
#define AssertValidReadPtr(...) 
#define AssertValidWritePtr(...) 
#define AssertValidStringPtr(...) 

//DBG_INTERFACE void Msg(PRINTF_FORMAT_STRING const tchar * pMsg, ...) FMTFUNCTION(1, 2);

// funcs
// NOTE: ThreadedLoadLibraryFunc_t needs to return the sleep time in milliseconds or TT_INFINITE
typedef int (*ThreadedLoadLibraryFunc_t)();
PLATFORM_INTERFACE void SetThreadedLoadLibraryFunc(ThreadedLoadLibraryFunc_t func);
PLATFORM_INTERFACE ThreadedLoadLibraryFunc_t GetThreadedLoadLibraryFunc();

PLATFORM_INTERFACE double			Plat_FloatTime();		// Returns time in seconds since the module was loaded.
PLATFORM_INTERFACE unsigned int		Plat_MSTime();			// Time in milliseconds.
PLATFORM_INTERFACE char*			Plat_asctime(const struct tm* tm, char* buf);
PLATFORM_INTERFACE char*			Plat_ctime(const time_t * timep, char* buf, size_t bufsize);
PLATFORM_INTERFACE struct tm*		Plat_gmtime(const time_t * timep, struct tm* result);
PLATFORM_INTERFACE time_t			Plat_timegm(struct tm* timeptr);
PLATFORM_INTERFACE struct tm*		Plat_localtime(const time_t * timep, struct tm* result);

PLATFORM_INTERFACE void Msg(const tchar * pMsg, ...);
#define Error Msg

//PLATFORM_INTERFACE void DevWarning(const char *msg, ...);

inline float FloatMakePositive(vec_t f)
{
	return fabsf(f);
}

#define _MKSTRING(arg) #arg
#define MKSTRING(arg) _MKSTRING(arg)
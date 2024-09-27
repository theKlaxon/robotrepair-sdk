//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: Memory allocation!
//
// $NoKeywords: $
//=============================================================================//

#ifndef TIER0_MEM_H
#define TIER0_MEM_H

#ifdef _WIN32
#pragma once
#endif

#include <stddef.h>
#ifdef LINUX
#undef offsetof
#define offsetof(s,m)	(size_t)&(((s *)0)->m)
#endif

#include "tier0/platform.h"

#if !defined(STATIC_TIER0) && !defined(_STATIC_LINKED)

#ifdef TIER0_DLL_EXPORT
#  define MEM_INTERFACE DLL_EXPORT
#else
#  define MEM_INTERFACE DLL_IMPORT
#endif

#else // BUILD_AS_DLL

#define MEM_INTERFACE extern

#endif // BUILD_AS_DLL

/* Define _CRTNOALIAS, _CRTRESTRICT */

#ifndef _CRTNOALIAS
#define _CRTNOALIAS __declspec(noalias)
#endif  /* _CRTNOALIAS */

//-----------------------------------------------------------------------------
// DLL-exported methods for particular kinds of memory
//-----------------------------------------------------------------------------
MEM_INTERFACE void *MemAllocScratch( int nMemSize );
MEM_INTERFACE void MemFreeScratch();

#ifdef POSIX
MEM_INTERFACE void ZeroMemory( void *mem, size_t length );
#endif

//Only works with USE_MEM_DEBUG and memory allocation call stack tracking enabled.
MEM_INTERFACE int GetAllocationCallStack( void *mem, void **pCallStackOut, int iMaxEntriesOut );


#define  stackfree( _p )			0


//-----------------------------------------------------------------------------
// Used to break into the debugger
//-----------------------------------------------------------------------------
#ifdef COMPILER_MSVC64
#define DebuggerBreak()		__debugbreak()
#elif COMPILER_MSVC32
#define DebuggerBreak()		__asm { int 3 }
#elif COMPILER_MSVCX360
#define DebuggerBreak()		DebugBreak()
#elif COMPILER_GCC
#if defined( PLATFORM_CYGWIN ) || defined( PLATFORM_POSIX )
#define DebuggerBreak()		__asm__( "int $0x3;")
#else
#define DebuggerBreak()		asm( "int3" )
#endif
#endif


#endif /* TIER0_MEM_H */

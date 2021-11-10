/***
*memory.h - declarations for buffer (memory) manipulation routines
*
*       Copyright (c) 1985-1997, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This include file contains the function declarations for the
*       buffer (memory) manipulation routines.
*       [System V]
*
****/

#ifndef _INC_MEMORY

#ifdef _WIN32_WCE
#include <windef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _CRTIMP
#ifdef _DLL
#define _CRTIMP __declspec(dllimport)
#else
#define _CRTIMP
#endif
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif

#ifdef _WIN32_WCE

/*
 * Conditional macro definition for function calling type and variable type
 * qualifiers.
 */
#if   ( (_MSC_VER >= 800) && (_M_IX86 >= 300) )

/*
 * Definitions for MS C8-32 (386/486) compiler
 */
#define _CRTAPI1 __cdecl
#define _CRTAPI2 __cdecl

#else

/*
 * Other compilers (e.g., MIPS)
 */
#define _CRTAPI1
#define _CRTAPI2

#endif

/* function prototypes */

			void * _CRTAPI1 memchr(const void *, int, size_t);
			int    _CRTAPI1 memcmp(const void *, const void *, size_t);
			void * _CRTAPI1 memcpy(void *, const void *, size_t);
			void * _CRTAPI1 memset(void *, int, size_t);
_CRTIMP	int    _CRTAPI1 _memicmp(const void *, const void *, unsigned int);
_CRTIMP	void * _CRTAPI1 _memccpy(void *, const void *, int, unsigned int);
_CRTIMP	void * _CRTAPI1 memmove(void *, const void *, size_t);


#if !defined (_SH3_) && !defined(SH3)
#pragma function(memcpy,memset,memcmp)
#endif

#else   /* !_WIN32_WCE */

/* function prototypes */

_CRTIMP	int __cdecl memcmp(const void *, const void *, size_t);
_CRTIMP	void * __cdecl memcpy(void *, const void *, size_t);
_CRTIMP int __cdecl _memicmp(const void *, const void *, unsigned int);
_CRTIMP	void * __cdecl memset(void *, int, size_t);

#if !__STDC__
/* Non-ANSI names for compatibility */
_CRTIMP void * __cdecl memccpy(void *, const void *, int, unsigned int);
_CRTIMP int __cdecl memicmp(const void *, const void *, unsigned int);
#endif	/* __STDC__ */

#endif  /* !_WIN32_WCE */

#ifdef __cplusplus
}
#endif

#define _INC_MEMORY
#endif  /* _INC_MEMORY */

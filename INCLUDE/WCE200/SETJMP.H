/***
*setjmp.h - definitions/declarations for setjmp/longjmp routines
*
*	Copyright (c) 1985-1997, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This file defines the machine-dependent buffer used by
*	setjmp/longjmp to save and restore the program state, and
*	declarations for those routines.
*	[ANSI/System V]
*
****/

#ifndef _INC_SETJMP

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


/*
 * Definitions specific to particular setjmp implementations.
 */
#ifdef	_M_IX86

#define setjmp	_setjmp
#if defined(_WIN32_WCE_EMULATION)
#define _JBLEN  16
#else
#define _JBLEN	8

#endif

#endif
 
#if defined(_M_SH) || defined(_M_MRX000)

#define setjmp        _setjmp
#define _JBLEN        0x30

#endif


#if defined(_M_PPC)

#define setjmp  _setjmp

#define _JBLEN  32  // NOTE: 32 doubles (see below)

#endif


/* define the buffer type for holding the state information */

#ifndef _JMP_BUF_DEFINED
#if defined(_M_PPC)
typedef  double jmp_buf[_JBLEN];
#else
typedef  int    jmp_buf[_JBLEN];
#endif
#define _JMP_BUF_DEFINED
#endif


/* function prototypes */

int __cdecl _setjmp(jmp_buf);
_CRTIMP void __cdecl longjmp(jmp_buf, int);

#ifdef __cplusplus
}
#endif

#define _INC_SETJMP

#endif	/* _INC_SETJMP */

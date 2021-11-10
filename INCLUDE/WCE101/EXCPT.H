/***
*excpt.h - defines exception values, types and routines
*
*	Copyright (c) 1990-1997, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This file contains the definitions and prototypes for the compiler-
*	dependent intrinsics, support functions and keywords which implement
*	the structured exception handling extensions.
*
****/

#ifndef _INC_EXCPT

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32_WCE

/* Define _CRTAPI1 (for compatibility with the NT SDK) */

#ifndef _CRTAPI1
#if	( (_MSC_VER >= 800) && (_M_IX86 >= 300) )
#define _CRTAPI1 __cdecl
#else
#define _CRTAPI1
#endif
#endif


/* Define _CRTAPI2 (for compatibility with the NT SDK) */

#ifndef _CRTAPI2
#if	( (_MSC_VER >= 800) && (_M_IX86 >= 300) )
#define _CRTAPI2 __cdecl
#else
#define _CRTAPI2
#endif
#endif


/* Define _CRTIMP */

#ifndef _CRTIMP
#ifdef	_NTSDK
/* definition compatible with NT SDK */
#define _CRTIMP
#else	/* ndef _NTSDK */
/* current definition */
#ifdef	_DLL
#define _CRTIMP __declspec(dllimport)
#else	/* ndef _DLL */
#define _CRTIMP
#endif	/* _DLL */
#endif	/* _NTSDK */
#endif	/* _CRTIMP */


/* Define __cdecl for non-Microsoft compilers */

#if	( !defined(_MSC_VER) && !defined(__cdecl) )
#define __cdecl
#endif

#endif	  /* _WIN32_WCE */


/*
 * Exception disposition return values.
 */
typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution,
    ExceptionContinueSearch,
    ExceptionNestedException,
    ExceptionCollidedUnwind

#ifdef _WIN32_WCE
    ,
    ExceptionExecuteHandler
#endif

} EXCEPTION_DISPOSITION;


/*
 * Prototype for SEH support function.
 */

#ifdef _WIN32_WCE

/*
 * Declarations to keep MIPS and ALPHA compiler happy
 */
typedef struct _EXCEPTION_POINTERS *Exception_info_ptr;
struct _EXCEPTION_RECORD;
struct _CONTEXT;
struct _RUNTIME_FUNCTION;
struct _EXCEPTION_REGISTRATION_RECORD;

typedef struct _DISPATCHER_CONTEXT {
#if ( defined( _i386_ ) || defined ( x86 ) )
    struct _EXCEPTION_REGISTRATION_RECORD *RegistrationPointer;
    ULONG ControlPc;
#else
    ULONG ControlPc;
    struct _RUNTIME_FUNCTION *FunctionEntry;
    ULONG EstablisherFrame;
    PCONTEXT ContextRecord;
#endif
} DISPATCHER_CONTEXT, *PDISPATCHER_CONTEXT;

typedef EXCEPTION_DISPOSITION EXCEPTION_ROUTINE (
	struct _EXCEPTION_RECORD *ExceptionRecord,
	void *EstablisherFrame,
	struct _CONTEXT *ContextRecord,
	struct _DISPATCHER_CONTEXT *DispatcherContext
	);
typedef EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;

#if ( defined( _i386_ ) || defined ( x86 ) )
EXCEPTION_ROUTINE _except_handler3;
#else
EXCEPTION_ROUTINE __C_specific_handler;
#endif

#else

#ifdef	_M_IX86

/*
 * Declarations to keep MS C 8 (386/486) compiler happy
 */
struct _EXCEPTION_RECORD;
struct _CONTEXT;

EXCEPTION_DISPOSITION __cdecl _except_handler (
	struct _EXCEPTION_RECORD *ExceptionRecord,
	void * EstablisherFrame,
	struct _CONTEXT *ContextRecord,
	void * DispatcherContext
	);

#endif
#endif	/* _WIN32_WCE */


/*
 * Keywords and intrinsics for SEH
 */

#ifdef	_MSC_VER

#if	!defined(__cplusplus)
#define try				__try
#define except				__except
#define finally 			__finally
#define leave				__leave
#endif

#define GetExceptionCode		_exception_code
#define exception_code			_exception_code
#define GetExceptionInformation 	(struct _EXCEPTION_POINTERS *)_exception_info
#define exception_info			(struct _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination		_abnormal_termination
#define abnormal_termination		_abnormal_termination

unsigned long __cdecl _exception_code(void);
void *	      __cdecl _exception_info(void);
int	      __cdecl _abnormal_termination(void);

#endif


/*
 * Legal values for expression in except().
 */

#define EXCEPTION_EXECUTE_HANDLER	 1
#define EXCEPTION_CONTINUE_SEARCH	 0
#define EXCEPTION_CONTINUE_EXECUTION	-1



#ifdef __cplusplus
}
#endif

#define _INC_EXCPT
#endif	/* _INC_EXCPT */

/***
*string.h - declarations for string manipulation functions
*
*	Copyright (c) 1985-1997, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	This file contains the function declarations for the string
*	manipulation functions.
*	[ANSI/System V]
*
****/

#ifndef _INC_STRING

#ifdef _WIN32_WCE
#include <windef.h>
#endif

#ifdef __cplusplus
extern "C" {
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

#endif	/* _WIN32_WCE */


#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif


/* define NULL pointer value */

#ifndef NULL
#ifdef __cplusplus
#define NULL	0
#else
#define NULL	((void *)0)
#endif
#endif


/* function prototypes */

#ifdef _WIN32_WCE

#ifndef _WSTRING_DEFINED
#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 wcscat(wchar_t *, const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 wcschr(const wchar_t *, wchar_t);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
int _CRTAPI1 wcscmp(const wchar_t *, const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 wcscpy(wchar_t *, const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
size_t _CRTAPI1 wcscspn(const wchar_t *, const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
size_t _CRTAPI1 wcslen(const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
size_t _CRTAPI1 mbstowcs(wchar_t *wcstr, const char *mbstr, size_t count);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
size_t _CRTAPI1 wcstombs(char *mbstr, const wchar_t *wcstr, size_t count);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 wcsncat(wchar_t *, const wchar_t *, size_t);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
int _CRTAPI1 wcsncmp(const wchar_t *, const wchar_t *, size_t);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 wcsncpy(wchar_t *, const wchar_t *, size_t);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 wcspbrk(const wchar_t *, const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 wcsrchr(const wchar_t *, wchar_t);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
size_t _CRTAPI1 wcsspn(const wchar_t *, const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 wcsstr(const wchar_t *, const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 wcstok(wchar_t *, const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 _wcsdup(const wchar_t *);


#ifndef COREDLL
extern __declspec(dllimport)
#endif
int _CRTAPI1 _wcsicmp(const wchar_t *, const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
int _CRTAPI1 _wcsnicmp(const wchar_t *, const wchar_t *, size_t);


#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 _wcsnset(wchar_t *, wchar_t, size_t);


#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 _wcsrev(wchar_t *);


#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 _wcsset(wchar_t *, wchar_t);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 _wcslwr(wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
wchar_t * _CRTAPI1 _wcsupr(wchar_t *);

#define _wtoi _wtol

#ifndef COREDLL
extern __declspec(dllimport)
#endif
long _CRTAPI1 _wtol(const wchar_t *);

#ifndef COREDLL
extern __declspec(dllimport)
#endif
__int64 _CRTAPI1 _wtoll(const wchar_t *);

#define _WSTRING_DEFINED
#endif

#endif	    /* _WIN32_WCE */


#ifndef _CRTIMP
#ifdef _DLL
#ifndef COREDLL
#define _CRTIMP __declspec(dllimport)
#else
#define _CRTIMP
#endif
#else
#define _CRTIMP
#endif
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif


/* function prototypes */

#ifndef _WIN32_WCE
_CRTIMP int __cdecl _strcmpi(const char *, const char *);
_CRTIMP int __cdecl _stricmp(const char *, const char *);
_CRTIMP int __cdecl strcoll(const char *, const char *);
_CRTIMP int __cdecl _stricoll(const char *, const char *);
_CRTIMP char * __cdecl _strlwr(char *);
_CRTIMP char * __cdecl _strupr(char *);
_CRTIMP size_t __cdecl strxfrm (char *, const char *, size_t);
_CRTIMP char * __cdecl _strerror(const char *);
_CRTIMP char * __cdecl strerror(int);
_CRTIMP int __cdecl _strnicmp(const char *, const char *, size_t);
_CRTIMP void * __cdecl memchr(const void *, int, size_t);
_CRTIMP char * __cdecl _strdup(const char *);
_CRTIMP char * __cdecl _strnset(char *, int, size_t);
_CRTIMP char * __cdecl _strrev(char *);
	char * __cdecl _strset(char *, int);

#endif

_CRTIMP void * __cdecl _memccpy(void *, const void *, int, unsigned int);
_CRTIMP int __cdecl _memicmp(const void *, const void *, unsigned int);
			void * _CRTAPI1 memchr(const void *, int, size_t);
			int    _CRTAPI1 memcmp(const void *, const void *, size_t);
			void * _CRTAPI1 memcpy(void *, const void *, size_t);
			void * _CRTAPI1 memset(void *, int, size_t);
_CRTIMP	void * _CRTAPI1 memmove(void *, const void *, size_t);
_CRTIMP	char * __cdecl strcat(char *, const char *);
_CRTIMP	char * __cdecl strchr(const char *, int);
_CRTIMP	int __cdecl strcmp(const char *, const char *);

_CRTIMP	char * __cdecl strcpy(char *, const char *);
_CRTIMP size_t __cdecl strcspn(const char *, const char *);
_CRTIMP	size_t __cdecl strlen(const char *);
_CRTIMP char * __cdecl strncat(char *, const char *, size_t);
_CRTIMP int __cdecl strncmp(const char *, const char *, size_t);
_CRTIMP char * __cdecl strncpy(char *, const char *, size_t);
_CRTIMP char * __cdecl strstr(const char *, const char *);
_CRTIMP char * __cdecl strtok(char *, const char *);

#ifndef _WSTRING_DEFINED
_CRTIMP wchar_t * __cdecl wcscat(wchar_t *, const wchar_t *);
_CRTIMP wchar_t * __cdecl wcschr(const wchar_t *, wchar_t);
_CRTIMP int __cdecl wcscmp(const wchar_t *, const wchar_t *);
_CRTIMP wchar_t * __cdecl wcscpy(wchar_t *, const wchar_t *);
_CRTIMP size_t __cdecl wcscspn(const wchar_t *, const wchar_t *);
_CRTIMP size_t __cdecl wcslen(const wchar_t *);
_CRTIMP wchar_t * __cdecl wcsncat(wchar_t *, const wchar_t *, size_t);
_CRTIMP int __cdecl wcsncmp(const wchar_t *, const wchar_t *, size_t);
_CRTIMP wchar_t * __cdecl wcsncpy(wchar_t *, const wchar_t *, size_t);
_CRTIMP wchar_t * __cdecl wcspbrk(const wchar_t *, const wchar_t *);
_CRTIMP wchar_t * __cdecl wcsrchr(const wchar_t *, wchar_t);
_CRTIMP size_t __cdecl wcsspn(const wchar_t *, const wchar_t *);
_CRTIMP wchar_t * __cdecl wcsstr(const wchar_t *, const wchar_t *);
_CRTIMP wchar_t * __cdecl wcstok(wchar_t *, const wchar_t *);

_CRTIMP wchar_t * __cdecl _wcsdup(const wchar_t *);
_CRTIMP int __cdecl _wcsicmp(const wchar_t *, const wchar_t *);
_CRTIMP int __cdecl _wcsnicmp(const wchar_t *, const wchar_t *, size_t);
_CRTIMP wchar_t * __cdecl _wcsnset(wchar_t *, wchar_t, size_t);
_CRTIMP wchar_t * __cdecl _wcsrev(wchar_t *);
_CRTIMP wchar_t * __cdecl _wcsset(wchar_t *, wchar_t);

#ifndef _WIN32_WCE
_CRTIMP wchar_t * __cdecl _wcslwr(wchar_t *);
_CRTIMP wchar_t * __cdecl _wcsupr(wchar_t *);
_CRTIMP size_t __cdecl wcsxfrm(wchar_t *, const wchar_t *, size_t);
_CRTIMP int __cdecl wcscoll(const wchar_t *, const wchar_t *);
_CRTIMP int __cdecl _wcsicoll(const wchar_t *, const wchar_t *);
#endif

/* old names */
#define wcswcs wcsstr

#define _WSTRING_DEFINED
#endif

#if !__STDC__

#ifndef _WIN32_WCE
_CRTIMP void * __cdecl memccpy(void *, const void *, int, unsigned int);
_CRTIMP int __cdecl memicmp(const void *, const void *, unsigned int);
_CRTIMP int __cdecl strnicmp(const char *, const char *, size_t);
_CRTIMP int __cdecl stricmp(const char *, const char *);
_CRTIMP int __cdecl strcmpi(const char *, const char *);
#endif


#define wcsdup	_wcsdup
#define wcsicmp	_wcsicmp
#define wcsnicmp _wcsnicmp
#define wcsnset	_wcsnset
#define wcsrev	_wcsrev
#define wcsset	_wcsset
#define wcslwr	_wcslwr
#define wcsupr	_wcsupr
#define wcsicoll _wcsicoll
#endif	/* !__STDC__ */


#ifdef __cplusplus
}
#endif


#define _INC_STRING
#endif	/* _INC_STRING */

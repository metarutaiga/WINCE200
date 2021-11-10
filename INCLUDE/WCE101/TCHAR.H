/***
*tchar.h - definitions for generic international functions
*
*	Copyright (c) 1991-1997, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	Definitions for generic international functions, mostly defines
*	which map string/formatted-io/ctype functions to char or wide-char
*	versions.
*
*	NOTE: it is meaningless to support multibyte/wide-char conversions
*
****/

#ifndef _TCHAR_H_
#define _TCHAR_H_

#ifdef _WIN32_WCE
#include <windef.h>
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#if ( _WIN32_WCE >= 101 )
#define	_tWinMain WinMain
#endif //WIN32_CE Ver 1.01 or above

#ifdef UNICODE

#ifdef _WIN32_WCE

#include <string.h>
typedef WCHAR TCHAR;
#define __TEXT(s) L##s

#else  /* _WIN32_WCE */

#ifndef _TCHAR_DEFINED
typedef wchar_t 	TCHAR;
#define _TCHAR_DEFINED
#endif

#define __T(x)		L ## x
#define _TEOF		WEOF

#endif /* _WIN32_WCE */

#ifndef _WIN32_WCE

#define _tprintf	wprintf
#define _ftprintf	fwprintf
#define _stprintf	swprintf
#define _sntprintf	_snwprintf
#define _vtprintf	vwprintf
#define _vftprintf	vfwprintf
#define _vstprintf	vswprintf
#define _vsntprintf	_vsnwprintf
#define _tscanf		wscanf
#define _ftscanf	fwscanf
#define _stscanf	swscanf
#define _fgettc		fgetwc
#define _fgettchar	fgetwchar
#define _fgetts		fgetws
#define _fputtc		fputwc
#define _fputtchar	fputwchar
#define _fputts		fputws
#define _gettc		getwc
#define _getts		getws
#define _puttc		putwc
#define _putts		putws
#define _ungettc	ungetwc
#define _tcsxfrm	wcsxfrm
#define _tcscoll	wcscoll
#define _tcsicoll	_wcsicoll
#endif	/* _WIN32_WCE */

#define	_ttoi		_wtoi
#define	_ttol		_wtol
#define	_ttoll		_wtoll
#define	_tcstod		wcstod
#define	_tcstol		wcstol
#define	_tcstoul	wcstoul
#define	_tcscat		wcscat
#define	_tcschr		wcschr
#define	_tcscmp		wcscmp
#define	_tcscpy		wcscpy
#define	_tcscspn	wcscspn
#define	_tcslen		wcslen
#define	_tcsncat	wcsncat
#define	_tcsncmp	wcsncmp
#define	_tcsncpy	wcsncpy
#define	_tcspbrk	wcspbrk
#define	_tcsrchr	wcsrchr
#define	_tcsspn		wcsspn
#define	_tcsstr		wcsstr
#define	_tcstok		wcstok
#define	_tcslwr		_wcslwr
#define	_tcsupr		_wcsupr
#define	_tcsdup		_wcsdup
#define	_tcsicmp	_wcsicmp
#define	_tcsnicmp	_wcsnicmp
#define	_tcsnset	_wcsnset
#define	_tcsrev		_wcsrev
#define	_tcsset		_wcsset
#define	_totupper	towupper
#define	_totlower	towlower

/* ctype functions */

#ifdef _WIN32_WCE
#define _istlegal	(1)
#endif
#define _istalpha	iswalpha
#define _istupper	iswupper
#define _istlower	iswlower
#define _istdigit	iswdigit
#define _istxdigit	iswxdigit
#define _istspace	iswspace
#define _istpunct	iswpunct
#define _istalnum	iswalnum
#define _istprint	iswprint
#define _istgraph	iswgraph
#define _istcntrl	iswcntrl
#define _istascii	iswascii

#else	/* _UNICODE */


#ifdef _WIN32_WCE

typedef char TCHAR;
#define __TEXT(s) s

#else	/* _WIN32_WCE */

#ifndef _TCHAR_DEFINED
typedef char		TCHAR;
#define _TCHAR_DEFINED
#endif

#define __T(x)		x
#define _TEOF		EOF

#endif	/* _WIN32_WCE */

#ifndef	_WIN32_WCE
#define _tprintf	printf
#define _ftprintf	fprintf
#define _stprintf	sprintf
#define _sntprintf	_snprintf
#define _vtprintf	vprintf
#define _vftprintf	vfprintf
#define _vstprintf	vsprintf
#define _vsntprintf	_vsnprintf
#define _tscanf		scanf
#define _ftscanf	fscanf
#define _stscanf	sscanf
#define _fgettc		fgetc
#define _fgettchar	fgetchar
#define _fgetts		fgets
#define _fputtc		fputc
#define _fputtchar	fputchar
#define _fputts		fputs
#define _gettc		getc
#define _getts		gets
#define _puttc		putc
#define _putts		puts
#define _ungettc	ungetc
#define _tcstod		strtod
#define _tcstol		strtol
#define _tcstoul	strtoul
#define _tcslwr		_strlwr
#define _tcsupr		_strupr
#define _tcsxfrm	strxfrm
#define _tcscoll	strcoll
#define _tcsicoll	_stricoll
#endif	/* _WIN32_WCE */


#define _tcscat		strcat
#define _tcschr		strchr
#define _tcscmp		strcmp
#define _tcscpy		strcpy
#define _tcscspn	strcspn
#define _tcslen		strlen
#define _tcsncat	strncat
#define _tcsncmp	strncmp
#define _tcsncpy	strncpy
#define _tcspbrk	strpbrk
#define _tcsrchr	strrchr
#define _tcsspn		strspn
#define _tcsstr		strstr
#define _tcstok		strtok

#define _tcsdup		_strdup
#define _tcsicmp	_stricmp
#define _tcsnicmp	_strnicmp
#define _tcsnset	_strnset
#define _tcsrev		_strrev
#define _tcsset		_strset

/* ctype functions */

#ifdef _WIN32_WCE
#define _istlegal	(1)
#endif
#define _istalpha	isalpha
#define _istupper	isupper
#define _istlower	islower
#define _istdigit	isdigit
#define _istxdigit	isxdigit
#define _istspace	isspace
#define _istpunct	ispunct
#define _istalnum	isalnum
#define _istprint	isprint
#define _istgraph	isgraph
#define _istcntrl	iscntrl
#define _istascii	isascii

#define _totupper	toupper
#define _totlower	tolower

#endif	/* _UNICODE */


#ifdef _WIN32_WCE

typedef TCHAR * PTSTR;
typedef PTSTR LPTSTR;
typedef const TCHAR * PCTSTR;
typedef PCTSTR LPCTSTR;

#else

#define _T(x)		__T(x)
#define _TEXT(x)	__T(x)

#endif	/* _WIN32_WCE */

#ifdef __cplusplus
}
#endif

#define _INC_TCHAR
#endif	/* _INC_TCHAR */

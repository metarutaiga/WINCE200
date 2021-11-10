/***
*ctype.h - character conversion macros and ctype macros
*
*	Copyright (c) 1985-1997, Microsoft Corporation. All rights reserved.
*
*Purpose:
*	Defines macros for character classification/conversion.
*	[ANSI/System V]
*
*
****/

#ifndef _INC_CTYPE

#ifdef __cplusplus
extern "C" {
#endif

#ifdef UNDER_CE

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

#else  /* UNDER_CE not defined */

#ifndef _CRTIMP
#ifdef _DLL
#define _CRTIMP __declspec(dllimport)
#else
#define _CRTIMP
#endif
#endif

#endif /* UNDER_CE */


#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef _WCTYPE_T_DEFINED
typedef wchar_t wint_t;
typedef wchar_t wctype_t;
#define _WCTYPE_T_DEFINED
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

/*
 * This declaration allows the user access to the ctype look-up
 * array _ctype defined in ctype.obj by simply including ctype.h
 */
#ifndef _CTYPE_DISABLE_MACROS

extern const unsigned short  _ctype[];
extern const unsigned short *_pctype;
extern const wctype_t *_pwctype;

#endif /* _CTYPE_DISABLE_MACROS */

/* set bit masks for the possible character types */

#define _UPPER		0x1	/* upper case letter */
#define _LOWER		0x2	/* lower case letter */
#define _DIGIT		0x4	/* digit[0-9] */
#define _SPACE		0x8	/* tab, carriage return, newline, */
				/* vertical tab or form feed */
#define _PUNCT		0x10	/* punctuation character */
#define _CONTROL	0x20	/* control character */
#define _BLANK		0x40	/* space char */
#define _HEX		0x80	/* hexadecimal digit */

#define _ALPHA		(0x0100|_UPPER|_LOWER)	/* alphabetic character */
#ifndef UNDER_CE
#define _LEADBYTE	0x8000			/* multibyte leadbyte */
#endif /* UNDER_CE */

/* character classification function prototypes */

#ifndef UNDER_CE

#ifndef _CTYPE_DEFINED
_CRTIMP int __cdecl isalpha(int);
_CRTIMP int __cdecl isupper(int);
_CRTIMP int __cdecl islower(int);
_CRTIMP int __cdecl isdigit(int);
_CRTIMP int __cdecl isxdigit(int);
_CRTIMP int __cdecl isspace(int);
_CRTIMP int __cdecl ispunct(int);
_CRTIMP int __cdecl isalnum(int);
_CRTIMP int __cdecl isprint(int);
_CRTIMP int __cdecl isgraph(int);
_CRTIMP int __cdecl iscntrl(int);
_CRTIMP int __cdecl toupper(int);
_CRTIMP int __cdecl tolower(int);
_CRTIMP int __cdecl _tolower(int);
_CRTIMP int __cdecl _toupper(int);
_CRTIMP int __cdecl __isascii(int);
_CRTIMP int __cdecl __toascii(int);
_CRTIMP int __cdecl __iscsymf(int);
_CRTIMP int __cdecl __iscsym(int);
#define _CTYPE_DEFINED
#endif

#endif /* !UNDER_CE */


#ifndef _WCTYPE_DEFINED

/* character classification function prototypes */
/* also defined in wchar.h */


#ifndef UNDER_CE

_CRTIMP int __cdecl iswalpha(wint_t);
_CRTIMP int __cdecl iswupper(wint_t);
_CRTIMP int __cdecl iswlower(wint_t);
_CRTIMP int __cdecl iswdigit(wint_t);
_CRTIMP int __cdecl iswxdigit(wint_t);
_CRTIMP int __cdecl iswspace(wint_t);
_CRTIMP int __cdecl iswpunct(wint_t);
_CRTIMP int __cdecl iswalnum(wint_t);
_CRTIMP int __cdecl iswprint(wint_t);
_CRTIMP int __cdecl iswgraph(wint_t);
_CRTIMP int __cdecl iswcntrl(wint_t);
_CRTIMP int __cdecl iswascii(wint_t);
_CRTIMP int __cdecl isleadbyte(int);

_CRTIMP int __cdecl iswctype(wint_t, wctype_t);
#define is_wctype(_c,_mask) iswctype(_c,_mask)

_CRTIMP int __cdecl _isctype(int, int);

_CRTIMP wchar_t __cdecl towupper(wchar_t);
_CRTIMP wchar_t __cdecl towlower(wchar_t);

#else  /* UNDER_CE */

/*
int _CRTAPI1 iswalpha(wint_t);
int _CRTAPI1 iswupper(wint_t);
int _CRTAPI1 iswlower(wint_t);
int _CRTAPI1 iswdigit(wint_t);
int _CRTAPI1 iswxdigit(wint_t);
int _CRTAPI1 iswspace(wint_t);
int _CRTAPI1 iswpunct(wint_t);
int _CRTAPI1 iswalnum(wint_t);
int _CRTAPI1 iswprint(wint_t);
int _CRTAPI1 iswgraph(wint_t);
int _CRTAPI1 iswcntrl(wint_t);
int _CRTAPI1 iswascii(wint_t);
int _CRTAPI1 isleadbyte(int);
*/

int iswctype(wint_t, wctype_t);
wchar_t towupper(wchar_t);
wchar_t towlower(wchar_t);

#endif /* !UNDER_CE */

#define _WCTYPE_DEFINED
#endif


/* the character classification macro definitions */

#ifndef _CTYPE_DISABLE_MACROS

#ifndef UNDER_CE

/* max mb-len for current locale */

#ifndef MB_CUR_MAX
/* also defined in stdlib.h */
#define MB_CUR_MAX __mb_cur_max
_CRTIMP extern int __mb_cur_max;
#endif /* MB_CUR_MAX */

#define isalpha(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_ALPHA) : _pctype[_c] & _ALPHA)
#define isupper(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_UPPER) : _pctype[_c] & _UPPER)
#define islower(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_LOWER) : _pctype[_c] & _LOWER)
#define isdigit(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_DIGIT) : _pctype[_c] & _DIGIT)
#define isxdigit(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_HEX)   : _pctype[_c] & _HEX)
#define isspace(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_SPACE) : _pctype[_c] & _SPACE)
#define ispunct(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_PUNCT) : _pctype[_c] & _PUNCT)
#define isalnum(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_ALPHA|_DIGIT) : _pctype[_c] & (_ALPHA|_DIGIT))
#define isprint(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT) : _pctype[_c] & (_BLANK|_PUNCT|_ALPHA|_DIGIT))
#define isgraph(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_PUNCT|_ALPHA|_DIGIT) : _pctype[_c] & (_PUNCT|_ALPHA|_DIGIT))
#define iscntrl(_c)	(MB_CUR_MAX > 1 ? _isctype(_c,_CONTROL) : _pctype[_c] & _CONTROL)

#define _tolower(_c)	( (_c)-'A'+'a' )
#define _toupper(_c)	( (_c)-'a'+'A' )

#define isascii __isascii
#define toascii __toascii
#define iscsymf __iscsymf
#define iscsym  __iscsym

#define __isascii(_c)	( (unsigned)(_c) < 0x80 )
#define __toascii(_c)	( (_c) & 0x7f )

#endif /* !UNDER_CE */

#define iswalpha(_c)	 ( iswctype(_c,_ALPHA) )
#define iswupper(_c)	 ( iswctype(_c,_UPPER) )
#define iswlower(_c)	 ( iswctype(_c,_LOWER) )
#define iswdigit(_c)	 ( iswctype(_c,_DIGIT) )
#define iswxdigit(_c)    ( iswctype(_c,_HEX) )
#define iswspace(_c)	 ( iswctype(_c,_SPACE) )
#define iswpunct(_c)	 ( iswctype(_c,_PUNCT) )
#define iswalnum(_c)	 ( iswctype(_c,_ALPHA|_DIGIT) )
#define iswprint(_c)	 ( iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT) )
#define iswgraph(_c)	 ( iswctype(_c,_PUNCT|_ALPHA|_DIGIT) )
#define iswcntrl(_c)	 ( iswctype(_c,_CONTROL) )
#define iswascii(_c)	 ( (unsigned)(_c) < 0x80 )
#define isleadbyte(_c)	 ( IsDBCSLeadByte(_c))

/* MS C version 2.0 extended ctype macros */

#define __iscsymf(_c)	(iswalpha(_c) || ((_c) == '_'))
#define __iscsym(_c)	(iswalnum(_c) || ((_c) == '_'))

#endif /* _CTYPE_DISABLE_MACROS */ 

#ifdef __cplusplus
}
#endif

#define _INC_CTYPE
#endif	/* _INC_CTYPE */


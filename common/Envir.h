// ==================================================
// envir.h
// local environment definitions, look file envdef.h
//


#ifndef envir_included
#define envir_included

// ---------------------------------------------------------------------
// mingw transliatoriui reikia raktu -fno-short-enums -funsigned-char
// ---------------------------------------------------------------------

// #define Envir MSDosCon    // 7
// #define Envir MSWin32     // 15
// #define Envir MSWin32Con  // 16
// #define Envir MSWin32Mfc  // 17
// #define Envir MSWin32ConMfc  // 18
// #define Envir Linux       // 12

// -----------
// anksciau buvo Yes/No
// #define Debug
// #define DebugStop // veikia, tik jei apibreztas Debug - isvedineja KpMsgOut pries kiekviena zingsni
// #define Logging // logina KP_TRACE pranesimus i log faila, zr. KpStdApp

// -----------
#define ENCODE_LOG

// -----------
// #define KP_USE_WXWIDGETS // ar naudoti wxWidgets

// -----------
// #define KP_XGECKO_VER 124 // "1.2.4"
#define KP_XGECKO_VER 130 // "1.3.0"

//======================================================== former envdef.h
// Envir - main environment types
#define None        0
#define Pdp11       1
#define Uk          4
#define Bk0010      5
#define MSDos       6 // MS-DOS graphic or pseudo-graphic application
#define MSDosCon    7 // MS-DOS terminal application without graphic environment
#define MSWin       8 // Windows 16 application
#define MSWinCon    9 // Windows 16 terminal application without graphical environment
#define Nd         10 // Norsk Data
#define Unix       11
#define Linux      12
#define MSWin32    15 // Windows 32 Platform SDK API application
#define MSWin32Con 16 // Windows 32 console application without any graphic environment
#define MSWin32Mfc 17 // Windows 32 MFC application
#define MSWin32ConMfc 18 // Windows 32 MFC console application

// Comp - computer
#define None        0
#define Pdp11       1
#define Uk          4
#define Bk0010      5
#define IbmPC       6
#define Nd         10 // Norsk Data
#define HP         11 // HP9000 etc.

// OsGr - operating system
#define None       0
#define RT11       1
#define MSDos      6
#define MSWin      8
#define Sintran   10
#define Unix      11

// Os - operating system, detailed
#define None       0
#define RT11       1
#define MSDos      6
#define MSWin3x    7
#define MSWin9x    8    // obsolete - use MSWin32Ver
#define MSWinNT    9    //
#define Sintran   10
#define Unix      11
#define Linux     12

// CompilerGr - compiler
#define None       0
#define Cc         1 /* Pdp11 */
#define Bc         6 /* Borland Turbo C & Co. */
#define Mc         9 /* Microsoft C */
#define Nc        10 /* Sintran (Norsk Data) */
#define Unix      11
#define Msvc      14 /* Microsoft Visual C++ */
#define Watcom    18 /* Open Watcom */
#define Mingw     19 /* Mingw */

// Compiler - compiler, detailed
#define None       0
#define Cc         1 /* Pdp11 */
#define Tc20       6 /* Turbo C v.2.0 */
#define Tcpp       7 /* Turbo C++ */
#define Bcpp       8 /* Borland C++ */
#define Mc         9 /* Microsoft C */
#define Nc        10 /* Sintran (Norsk Data) */
#define Unix      11
#define Msvc50    14 /* Microsoft Visual C++ v.5.0 */
#define Msvc60    15 /* Microsoft Visual Studio v.6.0 */
#define Watcom    18 /* Open Watcom */
#define Mingw     19 /* Mingw */

// Lang - programming language
#define None       0 // (resource compiler)
#define Stdc       1
#define AnsiC      6
#define Cpp        7 /* C++ */

// Graph - graphic
#define None       0
#define Kgd        1
#define Kcgd       2
#define Kcgdl      3
#define Uk         4
#define Bk0010     5
#define MSDos      6
#define MSWin      8
#define Unix      11
#define MSWin32   15

// MfcSupport
#define None    0
#define Yep     1

// SortSkipSpc - skip all spaces by string comparing (sort -b)
#define None    0
#define Yep     1

// ----------------------------------
// Languages for SortMode
#define KP_LNG_LIT ('l')       // lithuanian, former TV_XE_LIT, (former #define Lit 1)
#define KP_LNG_LIX ('x')       // lithuanian sorting regardless of diacrytics, i.e., è==c, ð==s, þ==z (for lzdsh.exe and main index generation)
#define KP_LNG_LIS ('s')       // lithuanian straigth sorting according to exact weights (for irregular form table generator - tvxmlecm.exe)
#define KP_LNG_ENG ('e')       // english, former TV_XE_ENG, (former #define Eng 0)
#define KP_LNG_GER ('v')       // german, former TV_XE_GER, former 'g'
#define KP_LNG_FRE ('f')       // french, former KP_LNG_FRA, TV_XE_FRA
#define KP_LNG_RUS ('r')       // russian, former TV_XE_RUS
#define KP_LNG_POL ('p')       // polish
#define KP_LNG_LAT ('n')       // latin

#define KP_LNG_NO  ('-')       // not applicable: text without any language specified, former TV_XE_NO
#define KP_LNG_UP  ('^')       // xml tags: language of the father tag should be inherited
#define KP_LNG_NA  ('@')       // not applicable: text not allowed; used for xml tags, excluded from index creation or non-text tags

// ----------------------------------
// Languages for messages
// #define MsgLang – constant defined during compilation

typedef enum
{
   KpLangNo    = -1, // -1 - neapibrëþta - iMsgLangOff nustatom á KpLangEn
#define KpLangNo_p   (-1)

   KpLangEn,         // 0 - anglø
#define KpLangEn_p   0
   KpLangLt,         // 1 - lietuviø
#define KpLangLt_p   1
   KpLangPl_1250,    // 2 - lenkø Central European
#define KpLangPl_1250_p 2
   KpLangPl_1257,    // 3 - lenkø Windows Baltic
#define KpLangPl_1257_p 3
   KpLangRu_1251,    // 4 - rusø
#define KpLangRu_1251_p 4
   KpLangRu_0,       // 5 - rusø su angliðkais mygtukø tekstais – kai regional Settings ne rusiðki
#define KpLangRu_0_p 5

   KpNumOfLangs,
#define KpNumOfLangs_p 6

   KpLangRu    = 97, // 97 - iðsitraukti ið registro Regional Setting'ø – KpLangRu_0 arba KpLangRu_1251 (jei rusiðki)
#define KpLangRu_p   97
   KpLangPl    = 98, // 98 - iðsitraukti ið registro Regional Setting'ø – KpLangPl_1250 arba KpLangPl_1257 (jei lietuviðki/Baltic)
#define KpLangPl_p   98
   KpLangSel,        // 99 - iðsitraukti ið registro Regional Setting'ø
#define KpLangSel_p  99

} KpLang;

#define KpNumOfLangs_2 KpNumOfLangs // masyvø riboms, padidinti kiekvienà kartà, pasikeitus kalbø skaièiui

extern KpLang iMsgLangOff; // variable, set by KpInitWindows() // nupjautas iki KpNumOfLangs, galima naudoti masyvø indeksams


//======================================================== former rest of envir.h
// ----------- character sorting mode - depends on language
//             (Windows regional settings) (former SortLang, SORT_MODE)
// #define SortMode KP_LNG_ENG
// #define SortMode KP_LNG_LIT
// #define SortMode KP_LNG_LIX
// #define SortMode KP_LNG_LIS

// ----------- dialog language
#define DialogLang KP_LNG_LIT
// #define DialogLang KP_LNG_ENG

// ----------- all errors treat as warnings - do not stop programm execution
// #define IGNORE_ERRORS

// ----------- test embedded chars more exact - xmlt.cpp, vlzt2, ...
//#define VL_TEST_CHARS_ALLOWED

// ----------- where to store product keys (pdfstart)
#define KP_KEY_REGISTRY          // save product key to registry
// #define KP_KEY_DISK_LABEL        // save product key to label of disk c:

// ----------- testiniai bandymai - kpsinst
// #define TEST_WATCOM

// ----------- switches on lastwordinpar() processing for TeX output
// #define PROCESS_LAST_WORD

// ---------------------------------------
// #define ExternalKphp11 // kphp11 memory in external file, otherwise statically initialized array

// ---------------------------------------
// #define CiDirect  // direct reading of comp. id, writing of comp id enabled
                     // if not defined - only reading of previously defined comp id
                     //    from file and registry

// ---------------------------------------
// Internet explorer version
// look commctrl.h of watcom
#ifndef _WIN32_IE
#define _WIN32_IE 0x0300
#endif

//======================================================== former envsupp.h
// -------------------
// default compiler for Win32... - Msvc60
// #define Compiler Msvc60
#ifndef Compiler
#ifdef _MSC_VER
#define Compiler Msvc60
#endif
#ifdef __MINGW32__
#define Compiler Mingw
// apibrėžti kompiliatoriaus opcijose
// #define MingwVer 441 // __VERSION__ "4.4.1" // Baj3
// #define MingwVer 462 // __VERSION__ "4.6.2"
// #define MingwVer 471 // __VERSION__ "4.7.1" // tdm64-1 // Baj5, baj4xp
// #define MingwVer 482 // __VERSION__ "4.8.2"
    // i686-posix-dwarf-rev3, Built by MinGW-W64 project // agxp, baj4xp_qt
#endif
#ifdef __WATCOMC__
#define Compiler Watcom
#endif
#endif

// -------------------
#if (Envir==Pdp11)
#  ifndef Comp
#     define Comp Pdp11
#  endif
#  ifndef Os
#     define Os RT11
#  endif
#  ifndef Compiler
#     define Compiler Cc
#  endif

#elif (Envir==Uk)
#  ifndef Comp
#     define Comp Uk
#  endif
#  ifndef Os
#     define Os RT11
#  endif
#  ifndef Compiler
#     define Compiler Cc
#  endif

#elif (Envir==Bk0010)
#  ifndef Comp
#     define Comp Bk0010
#  endif
#  ifndef Os
#     define Os None
#  endif
#  ifndef Compiler
#     define Compiler Cc
#  endif

#elif (Envir==Nd)
#  ifndef Comp
#     define Comp Nd
#  endif
#  ifndef Os
#     define Os Sintran
#  endif
#  ifndef Compiler
#     define Compiler Nc
#  endif

#elif (Envir==MSDos) || (Envir==MSDosStdc)
#  ifndef Comp
#     define Comp IbmPC
#  endif
#  ifndef Os
#     define Os MSDos
#  endif
#  ifndef Compiler
#     ifdef __TURBOC__
#        ifdef __cplusplus
#           define Compiler Bcpp
#        else
#           define Compiler Tc20
#        endif
#     else
#        define Compiler Mc
#     endif
#  endif

#elif (Envir==MSWin) || (Envir==MSWinStdc)
#  ifndef Comp
#     define Comp IbmPC
#  endif
#  ifndef Os
#     define Os MSWin9x
#  endif
#  ifndef Compiler
#     define Compiler Msvc50
#  endif

#elif (Envir==MSWin32) || (Envir==MSWin32Con) || (Envir==MSWin32Mfc) || (Envir==MSWin32ConMfc)
#  ifndef Comp
#     define Comp IbmPC
#  endif
#  ifndef Os
#     define Os MSWin9x
#  endif
#  ifndef Compiler
#     define Compiler Msvc60
#  endif
// #  ifndef SortMode
// #     define SortMode KP_LNG_LIT
// #  endif
#  ifndef SortSkipSpc
#     define SortSkipSpc None
#  endif

#elif (Envir==Unix)
#  ifndef Comp
#     define Comp HP
#  endif
#  ifndef Os
#     define Os Unix
#  endif
#  ifndef Compiler
#     define Compiler Unix
#  endif

#elif (Envir==Linux)
#  ifndef Comp
#     define Comp IbmPC
#  endif
#  ifndef Os
#     define Os Linux
#  endif
#  ifndef Compiler
#     define Compiler Unix
#  endif
// #  ifndef SortMode
// #     define SortMode KP_LNG_ENG
// #  endif
#  ifndef SortSkipSpc
#     define SortSkipSpc Yep
#  endif

#else
#  ifndef Comp
#     define Comp None
#  endif
#  ifndef Os
#     define Os None
#  endif
#  ifndef Compiler
#     define Compiler None
#  endif
#endif

#ifndef OsGr
#  if (Os==MSWin3x) || (Os==MSWin9x) || (Os==MSWinNT)
#     define OsGr MSWin
#  elif (Os==Unix) || (Os==Linux)
#     define OsGr Unix
#  else
#     define OsGr Os
#  endif
#endif

#ifndef CompilerGr
#  if (Compiler==Tc20) || (Compiler==Tcpp) || (Compiler==Bcpp)
#     define CompilerGr Bc
#  elif (Compiler==Msvc50) || (Compiler==Msvc60)
#     define  CompilerGr Msvc
#  else
#     define  CompilerGr Compiler
#  endif
#endif

// #ifndef SortMode
// #  define SortMode KP_LNG_LIT // KP_LNG_ENG
// #endif
#ifndef SortSkipSpc
#  define SortSkipSpc None
#endif


#ifndef Lang
#  ifdef __cplusplus
#    define Lang Cpp
#  else
#     if ((Compiler==None) || (Compiler==Cc) || (Compiler==Nc))
#        define Lang Stdc
#     elif ((CompilerGr==Bc) || (CompilerGr==Mc) || (CompilerGr==Msvc) || (Compiler==Unix))
#        define Lang AnsiC
#     else
#       define Lang None
#     endif
#  endif
#endif


#ifndef Graph
#  if ((Envir==None) || (Envir==Nd) || (Envir==Unix) || (Envir==Linux) || (Envir==MSDosStdc) || (Envir==MSWinStdc) || (Envir==MSWin32Con) || (Envir==MSWin32ConMfc))
#     define Graph None
#  elif ((Envir==Bk0010) || (Envir==Uk) || (Envir==MSDos) || (Envir==MSWin) || (Envir==MSWin32))
#    define Graph Envir
#  elif (Envir==MSWin32Mfc)
#    define Graph MSWin32
#  endif
#endif

#if (Envir==MSWin32) || (Envir==MSWin32Mfc) || (Envir==MSWin32ConMfc)
#  define MfcSupport Yep
#else
#  define MfcSupport None
#endif

#if (Envir!=MSWin32) && (Envir!=MSWin32Mfc) && (Envir!=MSWin32ConMfc)
typedef int CWnd;
#endif

// ----------------------------
#ifndef Comp
#  error "Comp undefined"
#endif
#ifndef Envir
#  if Lang != None
#     error "Envir undefined"
#  else
#     define Envir MSWin32
#  endif
#endif
#ifndef OsGr
#  error "OsGr undefined"
#endif
#ifndef Os
#  error "Os undefined"
#endif
#ifndef CompilerGr
#  error "CompilerGr undefined"
#endif
#ifndef Compiler
#  error "Compiler undefined"
#endif
#ifndef Lang
#  error "Lang undefined"
#endif
#ifndef Graph
#  error "Graph undefined"
#endif
// #ifndef SortMode
// #  error "SortMode undefined"
// #endif
#ifndef SortSkipSpc
#  error "SortSkipSpc undefined"
#endif
#ifndef MfcSupport
#  error "MfcSupport undefined"
#endif

// --------------------------------
//#if (Lang!=Cpp)
//#  error "Lang is not C++"
//#endif

// --------------------------------
// http://ml.osdir.com/web.wget.patches/2006-12/msg00026.html
//
#if (Compiler==Mingw)

#define HAVE_UINTPTR_T 1

#define HAVE_STRTOLL 1

/* MingW needs _WIN32_WINNT==0x0501 defined to pull in getaddrinfo()
 * and freeaddrinfo() etc.
 */
#if !defined(_WIN32_WINNT) || (_WIN32_WINNT < 0x0501)
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0501   // Windows XP
#endif

#endif


#if (Compiler==Watcom) && (__WATCOMC__ >= 1202)

// dël INPUT struktûros, faile winuser.h, átrauktam ið kpstap.cpp
#if !defined(_WIN32_WINNT) || (_WIN32_WINNT < 0x0500)
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500   // Windows 2000
#endif

// dël CURSORINFO struktûros, faile winuser.h, átrauktam ið kpstap.cpp
#if !defined(WINVER) || (WINVER < 0x0500)
#undef WINVER
#define WINVER 0x0500
#endif

#endif

// ----------------------------------------
// dël ATL, kai lzdsh projekto KP_USE_TextGRAB
#define _M_IX86

// ==================================================
// former order of kp environment includes:
// #include "envdef.h"
// #include "envir.h"   // local environment file
// #include "envsupp.h" // environment supplement depending on local environment settings
//
// #include <stdio.h>
// .....
//
// #include "kpstdlib.h"
// ...
//

#endif

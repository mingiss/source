// ==================================================
// kpstdlib.h
// common definitions for all Kp C++ projects
//


// ===============================================
// 2006.09.19  mp  KP_E_OBSOLETE
// 2006.09.20  mp  using namespace std;



// ===============================================
#ifndef kpstdlib_included
#define kpstdlib_included

#define KP_ALLOC_SAFE  // trinant su KP_DELETE* tikrinti, ar toks buvo sukurtas su KP_NEW*
// #define KP_ALLOC_TRACE // iðvedinëti log praneðimus kiekvienam KP_NEW* ir KP_DELETE*; tuo paèiu ir KP_ALLOC_SAFE

// #ifndef envdef_included
// #error "Error - envdef.h not included"
// #endif
#ifndef envir_included
#error "Error - envir.h not included"
#endif
// #ifndef envsupp_included
// #error "Error - envsupp.h not included"
// #endif

#if (Compiler != Watcom) || (__WATCOMC__ >= 1202)
using namespace std;
#endif

// ================================================== data types
#define cargs(arg) arg //----- compatibility with Stdc environment

//--------------------------- pointer processing
typedef int (*CompareFuncPtr)(const void *pVal1, const void *pVal2);
      // lyginimo funkcijos rodykles tipas, parametrai teksto eiluciu adresai
      // naudojama SearchTreeEntry(); pvz. – TvStrCmpStrict_(), KpCompareLong()
      // 0: *pVal1 == *pVal2
      // 1: *pVal1 > *pVal2
      // -1: *pVal1 > *pVal2
typedef int (*ComparePtrFuncPtr)(const void *ppVal1, const void *ppVal2);
      // lyginimo funkcijos rodykles tipas, parametrai - teksto eiluciu adresu adresai
      // pvz. – TvStrPtrCmpStrict(), TvStrPtrCmpStrictRev()
      // 0: **ppVal1 == **ppVal2
      // 1: **ppVal1 > **ppVal2
      // -1: **ppVal1 > **ppVal2
typedef void (*FuncPtr)(void);    /* funkcijos rodykles tipas */ // former Funpnt
#define Null ((FuncPtr)0)         /* nuline funkcijos rodykle */

typedef unsigned char * KpStrPtr;
#define null ((const KpStrPtr)NULL) // null pointer to the string

// --------------------------------------------------
extern int KpCompareLong(const void *plVal1, const void *plVal2);
      // 0: *plVal1 == *plVal2
      // 1: *plVal1 > *plVal2
      // -1: *plVal1 > *plVal2

//--------------------------- pointer processing - for compatibility with older kpx environment
#define chuge
#define PtMov(p,d) (((unsigned char *)(p))+((long)(d)))
#define PtDiff(a,b) (((unsigned char *)(a))-((unsigned char *)(b)))
#define PtInc(p) (((unsigned char *)(p))+1)
#define PtDec(p) (((unsigned char *)(p))-1)
#define PTHuge(p) (p)

extern void *StackTop; // top pointer of the stack, must be set in main   StackTop = &argc;

#if Compiler==Mingw
#define Naked
#else
#define Naked __declspec(naked)
#endif

#define cfree(pnt) free(pnt)


// ================================================== integer types and constants, math
#if ((CompilerGr!=Msvc) && (Compiler!=Watcom) && (Compiler!=Mingw))
typedef long INT32;
#define MAXLONG (0x7FFFFFFF)
#endif // #if ((CompilerGr!=Msvc) && (Compiler!=Watcom))

// for compatibility with old kp environment
#define Maxulong 0xffffffff
#define Maxlong  0x7fffffff
#define Maxuint      0xffff
#define Maxint       0x7fff
#define Maxuchar       0xff
#define Maxchar        0x7f

// #if Compiler!=Watcom
// #define INT_MAX Maxlong
// #endif

#define MAX_LONG_DIGITS 11 /* num. of decimal digits of MAXLONG */
#define MAX_64BIT_HEX_DIGITS 16 /* num. of hex digits of 64 bits integer */
#define MAX_LONG_HEX_DIGITS 8 /* num. of hex digits of MAXLONG */

#define MAX_INT_DIGITS 6 /* num. of decimal digits of MAXINT */

#define KILO_BYTE 1024

extern unsigned char lpszMathOperators[]; // "+-*/!=<>"


// ================================================== boolean definitions
#if((CompilerGr==Bc) || (Lang!=Cpp))
typedef short bool;
#endif

#if ((CompilerGr!=Msvc) && (Compiler!=Watcom) && (Compiler!=Mingw))
#define TRUE (~0)
#define FALSE 0
#endif
#define True ((bool)TRUE)
#define False ((bool)FALSE)

#define Undefined (-1)

// ================================================== character definitions
#define Clatsiz 0x80           // amount of 7-bit ANSI characters

#define KPT_Ctbsiz 0x100       // size of 8-bit charset
#define Ctbsiz KPT_Ctbsiz

#define KPT_Utbsiz 0x10000     // size of Unicode charset

/*------------------------------*/
#define CtrlFl 037   /* mask of Ctrl codes */

/*------------------------------*/
#define Nul ((unsigned char)0)
#define Soh ((unsigned char)1)
#define Stx ((unsigned char)2)
#define Etx ((unsigned char)3)
#define Eot ((unsigned char)4)
#define Enq ((unsigned char)5)
#define Ack ((unsigned char)6)
#define Bel ((unsigned char)7)
#define Bs  ((unsigned char)('\b'))
#define Ht  ((unsigned char)('\t'))
#  define Tab Ht
#if Comp==Nd
#  define Lf  ((unsigned char)012)
#else
#  define Lf  ((unsigned char)('\n'))
#endif
#define Vt ((unsigned char)('\v'))
#define Ff ((unsigned char)('\f'))
#if Comp==Nd
#  define Cr  ((unsigned char)015)
#else
#  define Cr ((unsigned char)('\r'))
#endif
#define So  ((unsigned char)016)
#define Si  ((unsigned char)017)
#define Dle ((unsigned char)020)
#define Dc1 ((unsigned char)021)
#define Dc2 ((unsigned char)022)
#define Dc3 ((unsigned char)023)
#define Dc4 ((unsigned char)024)
#define Nak ((unsigned char)025)
#define Syn ((unsigned char)026)
#define Etb ((unsigned char)027)
#define Can ((unsigned char)030)
#define Em  ((unsigned char)031) /* 0x19 */
#define Sub ((unsigned char)032)
#define Esc ((unsigned char)033)
#define Fs  ((unsigned char)034)
#define Gs  ((unsigned char)035)
#define Rs  ((unsigned char)036)
#define Us  ((unsigned char)037)
#define Spc ((unsigned char)(' '))

#define Enter Cr

#if (Envir==MSWin32Con) || (Envir==MSWin32ConMfc)
#define Hom ((unsigned char)0x24) /* Home */
#define Up  ((unsigned char)036) /* Arrow Up */
#define Dn  ((unsigned char)037) /* Arrow Down */

#define Shift     ((unsigned char)0x10)
#define Ctrl      ((unsigned char)0x11)
#define Alt       ((unsigned char)0x12)
#define CapsL     ((unsigned char)0x14)
#endif

#if (/*(Envir==MSWin) || (Envir==MSWinCon) || */ (Envir==MSWin32) /* || (Envir==MSWin32Con) */ || (Envir==MSWin32Mfc) /* || (Envir==MSWin32ConMfc) */)

// WM_KEYDOWN kodai: (raidiniai klaviðai generuoja didþiosios raidës kodà, virðutiniai skaièiai - skaièius)

#define Bot VK_END      // ((unsigned char)0x23) // former End
#define Hom VK_HOME     // ((unsigned char)0x24) /* Home */
#define Ins VK_INSERT   // ((unsigned char)0x2d)
#define Dlt VK_DELETE   // ((unsigned char)0x2e) /* Del */

#define Del ((unsigned char)0x7f)

#define Pdn VK_NEXT     // ((unsigned char)0x22) /* PgDn */ /* Page Down */
#define Pup VK_PRIOR    // ((unsigned char)0x21) /* PgUp */ /* Page Up */

#define Rt  VK_RIGHT    // ((unsigned char)0x27) /* Arrow Right */
#define Lt  VK_LEFT     // ((unsigned char)0x25) /* Arrow Left */
#define Up  VK_UP       // ((unsigned char)0x26) /* Arrow Up */
#define Dn  VK_DOWN     // ((unsigned char)0x28) /* Arrow Down */

// #define F0  ((unsigned char)0x)
#define F1  VK_F1       // ((unsigned char)0x70)
#define F2  VK_F2       // ((unsigned char)0x71)
#define F3  VK_F3       // ((unsigned char)0x72)
#define F4  VK_F4       // ((unsigned char)0x73)
#define F5  VK_F5       // ((unsigned char)0x74)
#define F6  VK_F6       // ((unsigned char)0x75)
#define F7  VK_F7       // ((unsigned char)0x76)
#define F8  VK_F8       // ((unsigned char)0x77)
#define F9  VK_F9       // ((unsigned char)0x78)

#define F10 VK_F10      // ((unsigned char)0x79)
#define F11 VK_F11      // ((unsigned char)0x7a)
#define F12 VK_F12      // ((unsigned char)0x7b)

#define Shift  VK_SHIFT    // ((unsigned char)0x10)
#define Ctrl   VK_CONTROL  // ((unsigned char)0x11)
#define Alt    VK_MENU     // ((unsigned char)0x12)   // su WM_KEYDOWN neateina
#define LWin   VK_LWIN     // ((unsigned char)0x5b)   // former Win
#define RWin   VK_RWIN     // ((unsigned char)0x5c)
#define RtKey  VK_APPS     // ((unsigned char)0x5d)   // klaviðas, simuliuojantis deðiná pelës klaviðo paspaudimà, yra prie deðiniojo Win (RWin) klaviðo
#define CapsL  VK_CAPITAL  // ((unsigned char)0x14)

// #define PrtSc     ((unsigned char)0x)
#define ScrL   VK_SCROLL   // ((unsigned char)0x91)
#define Pause  VK_PAUSE    // ((unsigned char)0x13)

#define NumLock   VK_NUMLOCK // ((unsigned char)0x90)

#define GrSlash   VK_DIVIDE   // ((unsigned char)0x6f)
#define GrAst     VK_MULTIPLY // ((unsigned char)0x6a)
#define GrMinus   VK_SUBTRACT // ((unsigned char)0x6d)
#define GrPlus    VK_ADD      // ((unsigned char)0x6b)
// #define GrEnter   ((unsigned char)0x0d)   // tas pats, kas ir Enter arba Cr

#define Gr0       VK_NUMPAD0  // ((unsigned char)0x60)
#define Gr1       VK_NUMPAD1  // ((unsigned char)0x61)
#define Gr2       VK_NUMPAD2  // ((unsigned char)0x62)
#define Gr3       VK_NUMPAD3  // ((unsigned char)0x63)
#define Gr4       VK_NUMPAD4  // ((unsigned char)0x64)
#define Gr5       VK_NUMPAD5  // ((unsigned char)0x65)
// #define Gr5       ((unsigned char)0x0c)   // ???
#define Gr6       VK_NUMPAD6  // ((unsigned char)0x66)
#define Gr7       VK_NUMPAD7  // ((unsigned char)0x67)
#define Gr8       VK_NUMPAD8  // ((unsigned char)0x68)
#define Gr9       VK_NUMPAD9  // ((unsigned char)0x69)

#define GrDot     VK_DECIMAL  // ((unsigned char)0x6e)

#define GraveKey
#define MinusKey
#define EqKey


#elif ((Envir==Pdp11) || (Envir==Uk) || (Envir==MSDos) /* || (Envir==MSDosCon) */ || (Envir==Nd) /* || (Envir==Unix) */)

#define Bot ((unsigned char)04) // former End
#define Hom ((unsigned char)05) /* Home */
#define Ins ((unsigned char)06)
#define Dlt ((unsigned char)032) /* Del */

#define Del ((unsigned char)0177)

#define Pdn ((unsigned char)01) /* PgDn */ /* Page Down */
#define Pup ((unsigned char)02) /* PgUp */ /* Page Up */

#define Rt  ((unsigned char)034) /* Arrow Right */
#define Lt  ((unsigned char)035) /* Arrow Left */
#define Up  ((unsigned char)036) /* Arrow Up */
#define Dn  ((unsigned char)037) /* Arrow Down */

#define F0  ((unsigned char)020)
#define F1  ((unsigned char)021)
#define F2  ((unsigned char)022)
#define F3  ((unsigned char)023)
#define F4  ((unsigned char)024)
#define F5  ((unsigned char)025)
#define F6  ((unsigned char)026)
#define F7  ((unsigned char)027)
#define F8  ((unsigned char)030)
#define F9  ((unsigned char)031)

#define F10 ((unsigned char)020)
#define F11 ((unsigned char)016)
#define F12 ((unsigned char)017)

#elif Envir==Bk0010

#define Del ((unsigned char)0x18)

#define Hom ((unsigned char)0x12) /* Home */
#define Dlt ((unsigned char)0x16)
#define Ins ((unsigned char)0x17)

#define Pup ((unsigned char)0x13)
#define Pdn ((unsigned char)0x14)

#define Rt  ((unsigned char)0x19)
#define Lt  ((unsigned char)0x08)
#define Up  ((unsigned char)0x1A)
#define Dn  ((unsigned char)0x1B)

#define Sbs   ((unsigned char)0x99)
#define Crsor ((unsigned char)0x9A)
#define Invs  ((unsigned char)0x9C)
#endif

#if Comp==IbmPC
#define Bsc Bs
#else
#define Bsc Del
#endif

#if Comp==Nd
#define  Exit ((unsigned char)0243)
#endif

/* Free control codes:
            003
            007
            013
            014
*/

#define Eof  (CtrlFl & 'Z') // 0x1A // Ctrl Z

#define Hyp 0x1F /* '\v' */ /* Hyphenation character */

// --------------------------
#define NBSP 0xA0


// ================================================== startup
extern HRESULT KpInit(void);
extern HRESULT KpFinit(void);

extern HRESULT TestCompilerSettings(void);
extern HRESULT TestCompilerSettingsLocal(void);
   // must be copied from kpstdlib.cpp:TestCompilerSettings() to local application file

extern HRESULT GetAppPath(unsigned char *lpszPathBuf, bool bAppendSlash);
                     // gets path of application currently running
                     // lpszPathBuf[KP_MAX_FNAME_LEN+1]
                     // if bAppendSlash == True, appends '\\' to the end, if not - only in case of root path
extern HRESULT GetAppName(unsigned char *lpszNameBuf);
                     // gets filename of application currently running
                     // lpszNameBuf[KP_MAX_FNAME_LEN+1]
extern HRESULT GetIniFname(unsigned char *lpszIniFnameBuf);
                     // gets filename of application .ini file (name of the application + .ini instead of .exe)
                     // lpszIniFnameBuf[KP_MAX_FNAME_LEN+1]
extern HRESULT GetCmdPath(unsigned char *lpszPathBuf, bool bAppendSlash);
                     // extracts path of application file path
                     // in lpszPathBuf[KP_MAX_FNAME_LEN+1] - command line


// ================================================== date/time
#if CompilerGr==Msvc

//#define timeb _timeb
//#define ftime _ftime
#endif

typedef long KpDate;             // bit positions:
#define KP_DATE_YEAR_MASK  0xFFFFFE00L // 31-9 year -4194304..4194303
#define KP_DATE_YEAR_POS   9           // first year bit
#define KP_DATE_MONTH_MASK 0x000001E0L //  8-5 month 1..12; 0 means no month
#define KP_DATE_MONTH_POS  5           // first month bit
#define KP_DATE_DAY_MASK   0x0000001FL //  4-0 day 1..31; 0 means no day
#define KP_DATE_DAY_POS    0           // first day bit
// compare "32-bit Windows Time/Date Formats" in MSDN Library

#define WND_DATE_TEXT_LENGTH 40 // 30 // Windows: "Thu Aug  3 15:55:45 2006", HTTP: "Thu, 15 Jul 2004 16:29:04 GMT"
#define KP_DATE_TEXT_LENGTH 10 // "2004-12-05"
#define KP_TIME_SHORT_TEXT_LENGTH 5 // "15:30"

#define KP_MILISECS_PER_SEC   1000
#define KP_SECS_PER_MIN       60
#define KP_MINS_PER_HOUR      60
#define KP_HOURS_PER_DAY      24
#define KP_MINS_PER_DAY       (KP_HOURS_PER_DAY * KP_MINS_PER_HOUR)

extern bool IsLeapYear(int iYear); // ar metai keliamieji
extern HRESULT CheckKpDate(KpDate lDate);
extern HRESULT ComposeRawKpDate(KpDate *plDate, int iYear, int iMonth, int iDay);
extern HRESULT ComposeKpDate(KpDate *plDate, int iYear, int iMonth, int iDay);
extern HRESULT ExtractRawKpDate(KpDate lDate, int *piYear, int *piMonth, int *piDay);
extern HRESULT ExtractKpDate(KpDate lDate, int *piYear, int *piMonth, int *piDay);
// ComposeRawKpDate() and ExtractRawKpDate() processes without checking

extern HRESULT GetWeekNumber(LPSYSTEMTIME lpSystemTime, int *piWeekOfTheYear);
extern HRESULT GetDayOfYear(LPSYSTEMTIME lpSystemTime, int *piDayOfTheYear);
extern HRESULT GetMonthsDayCount(int iYear, int iMonth, int *piNumOfDays);


// ================================================== memory allocation
// ---------------------------------------------------------------
typedef struct
{
   const void *m_pAddress;
   bool m_bArrayFl;
} KpHeapEntry;

extern HRESULT InsertHeapPtr(const void *pNewPtr, bool bArrayFl);
extern HRESULT RemoveHeapPtr(const void *pDelPtr, bool bArrayFl);

#define KP_HEAP_SIZE 10000 // vienu metu sukurtø objektø skaièius

#ifdef KP_ALLOC_TRACE // #if FALSE // #if TRUE // #ifdef Debug // DebugStartGrp //
#define KP_ALLOC_SAFE

#define KP_NEW(ptr, constr) \
{{ \
	if(SUCCEEDED(retc)) \
	{ \
		KP_ASSERT((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
		(ptr) = new constr; \
		PutLogMessage_("KpAlloc:\t%08x\tnew\t%s\t%d", ptr, __FILE__, __LINE__); \
		KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(retc)) retc = InsertHeapPtr(ptr, False); \
	} \
}}

#define KP_NEWO(ptr, constr) \
{{ \
	if(SUCCEEDED(retc)) \
	{ \
		KP_ASSERT((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
		(ptr) = new constr; \
		PutLogMessage_("KpAlloc:\t%08x\tnew\t%s\t%d", ptr, __FILE__, __LINE__); \
		KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(retc)) retc = InsertHeapPtr(ptr, False); \
      if(SUCCEEDED(retc)) retc = (ptr)->GetOpenResult(); \
      if(FAILED(retc)) KP_DELETE((ptr)); \
	} \
}}

#define KP_NEWA(ptr, constr, num) \
{{ \
	if(SUCCEEDED(retc)) \
	{ \
		KP_ASSERT((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
 		(ptr) = new constr [num]; \
		PutLogMessage_("KpAlloc:\t%08x\tnew[]\t%s\t%d", ptr, __FILE__, __LINE__); \
		KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(retc)) retc = InsertHeapPtr(ptr, True); \
	} \
}}

#  if FALSE
#define KP_NEWC(ptr, constr) \
{{ \
	if(SUCCEEDED(m_lhOpenResult)) \
	{ \
		KP_ASSERTC((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
		(ptr) = new constr; \
		PutLogMessage_("KpAlloc:\t%08x\tnew\t%s\t%d", ptr, __FILE__, __LINE__); \
		KP_ASSERTC((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(m_lhOpenResult)) m_lhOpenResult = InsertHeapPtr(ptr, False); \
	} \
}}

#define KP_NEWCO(ptr, constr) \
{{ \
	if(SUCCEEDED(m_lhOpenResult)) \
	{ \
		KP_ASSERTC((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
		(ptr) = new constr; \
		PutLogMessage_("KpAlloc:\t%08x\tnew\t%s\t%d", ptr, __FILE__, __LINE__); \
		KP_ASSERTC((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(m_lhOpenResult)) m_lhOpenResult = InsertHeapPtr(ptr, False); \
      if(SUCCEEDED(m_lhOpenResult)) m_lhOpenResult = (ptr)->GetOpenResult(); \
      if(FAILED(m_lhOpenResult)) KP_DELETE((ptr)); \
	} \
}}

#define KP_NEWCA(ptr, constr, num) \
{{ \
	if(SUCCEEDED(m_lhOpenResult)) \
	{ \
		KP_ASSERTC((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
 		(ptr) = new constr [num]; \
		PutLogMessage_("KpAlloc:\t%08x\tnew[]\t%s\t%d", ptr, __FILE__, __LINE__); \
		KP_ASSERTC((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(m_lhOpenResult)) m_lhOpenResult = InsertHeapPtr(ptr, True); \
	} \
}}
#  endif

#define KP_DELETE(ptr) \
{{ \
	if((ptr) != NULL) \
	{ \
		PutLogMessage_("KpAlloc:\t%08x\tdel\t%s\t%d", ptr, __FILE__, __LINE__); \
		if(SUCCEEDED(retc)) retc = RemoveHeapPtr(ptr, False); \
      if(SUCCEEDED(retc)) delete (ptr); \
		(ptr) = NULL; \
	} \
}}

#define KP_DELETEA(ptr) \
{{ \
	if((ptr) != NULL) \
	{ \
		PutLogMessage_("KpAlloc:\t%08x\tdel[]\t%s\t%d", ptr, __FILE__, __LINE__); \
		if(SUCCEEDED(retc)) retc = RemoveHeapPtr(ptr, True); \
      if(SUCCEEDED(retc)) delete [] (ptr); \
      (ptr) = NULL; \
	} \
}}

// ---------------------------------------------------------------
#else // #ifdef KP_ALLOC_TRACE // #ifdef DebugStartGrp // Debug
#  ifdef KP_ALLOC_SAFE

#define KP_NEW(ptr, constr) \
{{ \
	if(SUCCEEDED(retc)) \
	{ \
		KP_ASSERT((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
		(ptr) = new constr; \
		KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(retc)) retc = InsertHeapPtr(ptr, False); \
	} \
}}

#define KP_NEWO(ptr, constr) \
{{ \
	if(SUCCEEDED(retc)) \
	{ \
		KP_ASSERT((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
		(ptr) = new constr; \
		KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(retc)) retc = InsertHeapPtr(ptr, False); \
      if(SUCCEEDED(retc)) retc = (ptr)->GetOpenResult(); \
      if(FAILED(retc)) KP_DELETE((ptr)); \
	} \
}}

#define KP_NEWA(ptr, constr, num) \
{{ \
	if(SUCCEEDED(retc)) \
	{ \
		KP_ASSERT((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
 		(ptr) = new constr [num]; \
		KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(retc)) retc = InsertHeapPtr(ptr, True); \
	} \
}}

#     if FALSE
#define KP_NEWC(ptr, constr) \
{{ \
	if(SUCCEEDED(m_lhOpenResult)) \
	{ \
		KP_ASSERTC((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
		(ptr) = new constr; \
		KP_ASSERTC((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(m_lhOpenResult)) m_lhOpenResult = InsertHeapPtr(ptr, False); \
	} \
}}

#define KP_NEWCO(ptr, constr) \
{{ \
	if(SUCCEEDED(m_lhOpenResult)) \
	{ \
		KP_ASSERTC((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
		(ptr) = new constr; \
		KP_ASSERTC((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(m_lhOpenResult)) m_lhOpenResult = InsertHeapPtr(ptr, False); \
      if(SUCCEEDED(m_lhOpenResult)) m_lhOpenResult = (ptr)->GetOpenResult(); \
      if(FAILED(m_lhOpenResult)) KP_DELETE((ptr)); \
	} \
}}

#define KP_NEWCA(ptr, constr, num) \
{{ \
	if(SUCCEEDED(m_lhOpenResult)) \
	{ \
		KP_ASSERTC((ptr) == NULL, KP_E_DOUBLE_CALL, null, False); \
 		(ptr) = new constr [num]; \
		KP_ASSERTC((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
		if(SUCCEEDED(m_lhOpenResult)) m_lhOpenResult = InsertHeapPtr(ptr, True); \
	} \
}}
#     endif

#define KP_DELETE(ptr) \
{{ \
	if((ptr) != NULL) \
	{ \
		if(SUCCEEDED(RemoveHeapPtr(ptr, False))) delete (ptr); \
		(ptr) = NULL; \
	} \
}}

#define KP_DELETEA(ptr) \
{{ \
	if((ptr) != NULL) \
	{ \
		if(SUCCEEDED(RemoveHeapPtr(ptr, True))) delete [] (ptr); \
		(ptr) = NULL; \
	} \
}}

// ---------------------------------------------------------------
#  else // #ifdef KP_ALLOC_SAFE

#define KP_NEW(ptr, constr) \
{{ \
	if(SUCCEEDED(retc)) \
	{ \
		(ptr) = new constr; \
		KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
	} \
}}

#define KP_NEWO(ptr, constr) \
{{ \
	if(SUCCEEDED(retc)) \
	{ \
		(ptr) = new constr; \
		KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
      if(SUCCEEDED(retc)) retc = (ptr)->GetOpenResult(); \
      if(FAILED(retc)) KP_DELETE((ptr)); \
	} \
}}

#define KP_NEWA(ptr, constr, num) \
{{ \
	if(SUCCEEDED(retc)) \
	{ \
 		(ptr) = new constr [num]; \
		KP_ASSERT((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
	} \
}}

#     if FALSE
#define KP_NEWC(ptr, constr) \
{{ \
	if(SUCCEEDED(m_lhOpenResult)) \
	{ \
		(ptr) = new constr; \
		KP_ASSERTC((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
	} \
}}

#define KP_NEWCO(ptr, constr) \
{{ \
	if(SUCCEEDED(m_lhOpenResult)) \
	{ \
		(ptr) = new constr; \
		KP_ASSERTC((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
      if(SUCCEEDED(m_lhOpenResult)) m_lhOpenResult = (ptr)->GetOpenResult(); \
      if(FAILED(m_lhOpenResult)) KP_DELETE((ptr)); \
	} \
}}

#define KP_NEWCA(ptr, constr, num) \
{{ \
	if(SUCCEEDED(m_lhOpenResult)) \
	{ \
 		(ptr) = new constr [num]; \
		KP_ASSERTC((ptr) != NULL, KP_E_OUTOFMEM, null, True); \
	} \
}}
#     endif

#define KP_DELETE(ptr) \
{{ \
	if((ptr) != NULL) \
	{ \
		delete (ptr); \
		(ptr) = NULL; \
	} \
}}

#define KP_DELETEA(ptr) \
{{ \
	if((ptr) != NULL) \
	{ \
		delete [] (ptr); \
		(ptr) = NULL; \
	} \
}}

#  endif // #ifdef KP_ALLOC_SAFE
#endif // #ifdef KP_ALLOC_TRACE // #ifdef DebugStartGrp // Debug


// ================================================== file I/O definitions
#define KP_DOS_FNAME_LEN 12   // nnnnnnnn.ttt
// #if (CompilerGr==Msvc) || (CompilerGr==Bc) || (CompilerGr==Mc)
// #define KP_MAX_FNAME_LEN 260 // MAX_PATH // !!! must be identical in all environments // iðkeltas á kperrno.h dël kpstpl
// #else
// #define KP_MAX_FNAME_LEN 260 // 130 // 80 // !!! must be identical in all environments
// #endif
#define KP_MAX_FTYPE_LEN KP_MAX_FNAME_LEN // 4 // negalima keist – pasikeis kpstart.ini dydis
#define KP_MAX_DEV_LEN KP_MAX_FNAME_LEN // 10 // max Windows disko raidës árenginio ar serverio vardo ilgis
#define KP_MAX_FILE_LIN_WDT 255 // 130 // negalima keist – pasikeis kpstart.ini dydis
#define KP_MAX_FILE_LIN_LEN 4096 // 256
#define KP_MEMO_LENGTH    KP_MAX_FILE_LIN_WDT // length of DB memo field

// ----------- for compatibility with older kpx environment
#define MAXPATH KP_MAX_FNAME_LEN
#define Fnsiz KP_MAX_FNAME_LEN
#define MAXFILE KP_MAX_FNAME_LEN
#define MAXEXT KP_MAX_FTYPE_LEN
#define FileLinLen KP_MAX_FILE_LIN_LEN

// -----------
#define MAX_NUM_OF_LIST_ENTRIES 10

// atmintuko failø kopijavimo greitis kilobaitais per sekundæ
// #define KP_USB2_SPEED 573L // senieji PQI atmintukai
#define KP_USB2_SPEED 4000L

// ================================================== sort/search
#define KP_KWD_LEN 400 // negalima keist – pasikeis kpstart.ini dydis


// ======================================================= math
#define PI (2*asin(1.0)) // 3.1415926535
#define KP_EPSILON 0.000001 // slankios aritmetikos paklaida

HRESULT DotRotate(double dAngle, double *pdX, double *pdY, double *pdZ);
         // rotates by dAngle radians around axe X

#if Compiler==Mingw
#ifndef min
#define min(aa, bb) ((aa<=bb)?aa:bb)
#endif
#ifndef max
#define max(aa, bb) ((aa>=bb)?aa:bb)
#endif
#endif


// ======================================================== graph
typedef enum
{
   AxisX,
   AxisY,
   AxisZ,

   MaxAxis

} KpAxis; // former MokSteAxis;


class KpPoint
{
public:
   double m_Coords[MaxAxis];

   KpPoint();
   KpPoint(double dX, double dY, double dZ);
   KpPoint(KpPoint *pOrig); // sudubliuoja jau esanti taska
};

HRESULT KpDifPoints(const KpPoint *Point1, const KpPoint *Point2, double *pdDiff); // atstumas tarp tasku
HRESULT RotateLeft(KpPoint *pPoint);
HRESULT RotateRight(KpPoint *pPoint);


// ====================================== KpStdApp - bendra visu kp aplikaciju dalis
class KpStdApp
{
public:
// #ifdef Logging
// pastoviai atidarytas failas loginimui netinka, reikia atidaryt, palogint ir ið karto vël uþdaryt
// FILE *m_pLogFile;
// #endif

   KpStdApp(void);
   virtual ~KpStdApp(void);
};

// ---------------------------------
extern KpStdApp *theKpStdAppPtr;
// pointer to application instance, casted to KpStdApp
// must be defined locally in main application file

// ---------------------------------
// #ifdef Logging
// extern unsigned char lpszLogFileName[];
// name of log file
// must be defined locally in main application file
// #endif


// ------------------------------------------ SQL
#define SQL_TABNAME_LENGTH  50
#define SQL_MAX_QUERY_LENGTH  1000


// ------------------------------------------ setup
#define KPSTPD_FLASH_7_SETUP_FNAME ((const unsigned char *)"Install Flash Player 7 AX.bin") // ((const unsigned char *)"Install Flash Player 7 AX.exe")
#define KPSTPD_FLASH_9_SETUP_FNAME ((const unsigned char *)"install_flash_player_active_x.msi")
#define KPSTPD_MSIEXEC_CMD_STR ((const unsigned char *)"msiexec.exe /i ")

extern const unsigned char *GenIssArr[];
extern HRESULT ProcessSetup(const unsigned char *lpszAppPath, bool *pbSetupPerformed);
                                 // lpszAppPath - iðtrauktas ið programos vardo (kpstrpd.exe)
                                 // jei NULL - tada ið
                                 // *pbSetupPerformed == True - buvo patikrinta, ar adminas ir nukopijuoti failai

#endif // #ifndef kpstdlib_included

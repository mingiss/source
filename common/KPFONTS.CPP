// ------------------------------------------
// kpfonts.cpp
// font attribute description
//

// =========================================
// 2006.09.20 mp  #include <afx>, <string>



// ======================================= definitions
#include "stdafx.h"

#include "envir.h"

#if CompilerGr==Msvc
#include <afx.h>
#endif
#include <string>
#include <stdio.h>
#include <fstream>
#if OsGr==MSWin
#include <windows.h>
#include <richedit.h>
#include <Richole.h>
#endif

#if (Compiler != Watcom) || (__WATCOMC__ >= 1202)
using namespace std;
#endif

#include "kpstdlib.h"
#include "kperrno.h"
#include "kptt.h"
#include "kptree.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kpcolors.h"
#include "kpfonts.h"
#include "kpstdio.h"
#include "res_com.h"
#include "kpwindow.h"
#include "kperr.h"
#include "tvmain.h"


// ==================================== class KPS_FontStyle_tag methods
KPS_FontStyle_tag::KPS_FontStyle_tag(void)
{
   iTypeface=KPT_TypefaceUndefined;
   iFontSize=KPS_FontSizeUndef;
   iFontFlags=KPS_FlagsUndef;
   iColor=KpColorUndefined;
   iBackColor=KpColorUndefined;
}

KPS_FontStyle_tag::KPS_FontStyle_tag
(
   KPT_Typefaces iTypefaceInit,
   int iFontSizeInit,
   int iFontFlagsInit,
   KpColor iColorInit,
   KpColor iBackColorInit
)
{
   iTypeface=iTypefaceInit;
   iFontSize=iFontSizeInit;
   iFontFlags=iFontFlagsInit;
   iColor=iColorInit;
   iBackColor=iBackColorInit;
}


KPT_Typefaces KPS_FontStyle_tag::GetTypeface(void)
{
return(iTypeface);
}

int KPS_FontStyle_tag::GetFontSize(void)
{
return(iFontSize*iCurFontSize/iMainFontSize);
}

int KPS_FontStyle_tag::GetFontFlags(void)
{
return(iFontFlags);
}

KpColor KPS_FontStyle_tag::GetColor(void)
{
return(iColor);
}

KpColor KPS_FontStyle_tag::GetBackColor(void)
{
return(iBackColor);
}


// ================================================== methods of KPT_Typeface_tag
// --------------------------------------------------
KPT_Typeface_tag::KPT_Typeface_tag(void)
{
   szFontName[0]=Nul;
   iKptCodeTable=KPT_NoCodeTable;
}


// --------------------------------------------------
KPT_Typeface_tag::KPT_Typeface_tag(const /* unsigned */ char *lpszName, int iKptCTbl)
{
   KPT_Typeface_tag();
   SetKptCodeTable(iKptCTbl);
   SetFontName((const unsigned char *)lpszName);
}


// --------------------------------------------------
HRESULT KPT_Typeface_tag::SetKptCodeTable(int iTCTbl)
{
HRESULT retc=S_OK;

   if(((iTCTbl>0) && (iTCTbl<KPT_Ctnum)) || (iTCTbl==KPT_NoCodeTable)) iKptCodeTable=iTCTbl;
   else
      retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, True, __FILE__, __LINE__, 0L);

return(retc);
}


// --------------------------------------------------
HRESULT KPT_Typeface_tag::GetKptCodeTable(int *piTCTbl)
{
HRESULT retc=S_OK;

   if(piTCTbl!=NULL) *piTCTbl=iKptCodeTable;
   else
      retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, True, __FILE__, __LINE__, 0L);

return(retc);
}


// --------------------------------------------------
HRESULT KPT_Typeface_tag::SetFontName(const unsigned char *lpszFontName)
{
HRESULT retc=S_OK;

   if(lpszFontName==NULL)
      retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, True, __FILE__, __LINE__, 0L);

   if(SUCCEEDED(retc)) if(strlen((const char *)lpszFontName) >= KP_MAX_FNAME_LEN) // RT_FONT_NAME_LENGTH)
      retc=KpErrorProc.OutputErrorMessage(TV_E_TAG_OVERFL, null, True, __FILE__, __LINE__, 0L);

   if(SUCCEEDED(retc)) strcpy((char *)szFontName, (const char *)lpszFontName);

return(retc);
}


// --------------------------------------------------
HRESULT KPT_Typeface_tag::SetFontName(const char *lpszFontName)
{
return(SetFontName((const unsigned char *)lpszFontName));
}


// --------------------------------------------------
HRESULT KPT_Typeface_tag::PutCharToName(const unsigned char ucCh)
{
HRESULT retc=S_OK;
unsigned char str_buf[2];

   if(strlen((const char *)szFontName) >= KP_MAX_FNAME_LEN) // RT_FONT_NAME_LENGTH)
      retc=KpErrorProc.OutputErrorMessage(TV_E_TAG_OVERFL, null, True, __FILE__, __LINE__, 0L);
   else
   {
      str_buf[0]=ucCh;
      str_buf[1]=Nul;
      strcat((char *)szFontName, (const char *)str_buf);
   }

return(retc);
}


// --------------------------------------------------
HRESULT const KPT_Typeface_tag::GetFontName(unsigned char **plpszNamePtr)
{
   *plpszNamePtr=szFontName;

return(S_OK);
}

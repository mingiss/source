// ---------------------------
// lzdsht.cpp
// zodyno perziuros programa
// paieskos thread'as
//

// -----------------------------------------
#include "envir.h"
#include "iBshn.h"
#include "lzdshn.h"

#ifdef KP_USE_TextGRAB
#define _UNICODE
#endif

#include <stdio.h>
#include <string>
#include <fstream>
#include <windows.h>
#include <commctrl.h>
#include <richedit.h>
#include <Richole.h>
#include <time.h>

#ifdef KP_USE_WXWIDGETS
#include "wx/app.h"
#include "wx/listbox.h"
#include "wx/sizer.h"
#endif

#ifdef IBSH_RES_MODE_MSHTML
#if CompilerGr==Mingw
#include "HTMLWindow.h"
#endif
#endif

#if TRUE // #ifdef IBSH_RES_MODE_XGECKO
#if CompilerGr==Mingw
#include "IInputStream.hh"
#include "IString.hh"
#include "XApplication.hh"
#include "XGecko.hh"
#include "XGeckoDOMEvent.hh"
#include "XGeckoInit.hh"
#endif
#endif

#if Compiler != Watcom
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
#include "kpsort.h"
#include "res_com.h"
#include "kpwindow.h"
#include "kpsock.h"
#include "kperr.h"
#include "kphp11i.h"
#include "kphp11y.h"
#include "kphp11m.h"
#include "kphp11d.h"
#include "kphp11rc.h"
#include "kphp11t.h"
#include "kpcapp.h"
#include "tvmain.h"
#include "tvxml.h"
#include "tvxmls.h"
#include "xmlp.h"
#include "xmlh.h"
#include "xmlf.h"
#include "kpttucf.h"
#include "xmlu.h"
#include "xml8.h"
#include "xmlb.h"
#include "xmlo1.h"
#include "xmlt.h"
#include "xmlis.h"
#include "xmli.h"
#include "tvxmle.h"
#include "htmt.h"
#include "tvrtf.h"
#include "tvrtfo.h"
#include "tvtex.h"
#include "KpFileSys.h"
#include "xmln.h"
#include "xmlsty.h"
#include "kpstap.h"
#include "KpPubDlg.h"
#include "KpRtfDlg.h"
#ifdef IBSH_RES_MODE_XGECKO
#  if CompilerGr==Mingw
#include "KpGecko.h"
#  endif
#endif
#include "iBshl.h"
#include "lzdsh.h"
#include "lzdshl.h"

#ifdef KP_USE_TextGRAB
#include "excpt.h"
#include "atlbase.h"
#include "tgsdkx.h"
#endif

#include "lzdsht.h"


// --------------------------------
#ifndef iBshn_included
#error iBshn.h not included
#endif

#ifndef lzdshn_included
#error lzdshn.h not included
#endif

#ifndef IBSH_SKIN
#error IBSH_SKIN undefined
#endif

#if Envir!=MSWin32
#error Envir!=MSWin32
#endif

#if Compiler != Watcom
using namespace std;
#endif


// ------------------------------------
#ifdef KP_USE_TextGRAB
// class DECLSPEC_UUID("15CED018-EA43-4CC0-AE44-5E8F413E5578")
// DEFINE_GUID(CLSID_TextGRABSDK, 0x15CED018, 0xEA43, 0x4CC0, 0xAE, 0x44, 0x5E, 0x8F, 0x41, 0x3E, 0x55, 0x78);
const CLSID CLSID_TextGRABSDK = { 0x15CED018, 0xEA43, 0x4CC0, {0xAE, 0x44, 0x5E, 0x8F, 0x41, 0x3E, 0x55, 0x78} };
// MIDL_INTERFACE("95599BC7-8F45-47B4-B6D6-254EC647E1A8")
const CLSID IID_ITextGRABSDK = { 0x95599BC7, 0x8F45, 0x47B4, {0xB6, 0xD6, 0x25, 0x4E, 0xC6, 0x47, 0xE1, 0xA8} };
#endif

// --------------------------------------------------
HRESULT XmlNode::RenumCtgMng(void)
{
return(S_OK);
}


// ------------------------------------ additional TvRtfO methods
// #ifdef IBSH_RES_MODE_RTF
HRESULT TvRtfO::PutStyleSheet(void)
{
HRESULT retc=S_OK;
// int ii;

   if(SUCCEEDED(retc)) retc=OpenField();
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_stylesheet);
   if(SUCCEEDED(retc)) retc=PutChar(C_Lf, False);

   if(SUCCEEDED(retc)) retc=OpenField();
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_ql);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_li, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_ri, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_sl, -240);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_slmult, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_widctlpar);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_aspalpha);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_aspnum);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_faauto);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_adjustright);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_rin, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_lin, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_itap, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_fs, 20);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_lang, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_langfe, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_cgrid);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_langnp, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_langfenp, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_snext, 0);
   if(SUCCEEDED(retc)) retc=PutStr((const unsigned char *)"Normal");
   if(SUCCEEDED(retc)) retc=PutChar(C_Semic, False);
   if(SUCCEEDED(retc)) retc=CloseField();
   if(SUCCEEDED(retc)) retc=PutChar(C_Lf, False);

   if(SUCCEEDED(retc)) retc=OpenField();
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_Ast);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_cs, 10);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_additive);
   if(SUCCEEDED(retc)) retc=PutStr((const unsigned char *)"Default Paragraph Font");
   if(SUCCEEDED(retc)) retc=PutChar(C_Semic, False);
   if(SUCCEEDED(retc)) retc=CloseField();
   if(SUCCEEDED(retc)) retc=PutChar(C_Lf, False);

#if FALSE
   if(SUCCEEDED(retc)) retc=OpenField();
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_s, NPR2_FirstPar /* 41 (16) */);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_ql);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_fi, -284);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_li, 284);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_ri, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_sl, -XML_STY_LINE_SPACING*20);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_slmult, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_widctlpar);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_aspalpha);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_aspnum);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_faauto);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_adjustright);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_rin, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_lin, 284);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_itap, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_fs, 20);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_lang, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_langfe, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_cgrid);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_langnp, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_langfenp, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_sbasedon, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_snext, 41 /* 16 */);
   if(SUCCEEDED(retc)) retc=PutStr((const unsigned char *)"FirstPar");
   if(SUCCEEDED(retc)) retc=PutChar(C_Semic, False);
   if(SUCCEEDED(retc)) retc=CloseField();
   if(SUCCEEDED(retc)) retc=PutChar(C_Lf, False);

   if(SUCCEEDED(retc)) retc=OpenField();
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_s, NPR2_OrdPar /* 42 (17) */);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_ql);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_li, 284);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_ri, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_sl, -XML_STY_LINE_SPACING*20);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_slmult, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_widctlpar);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_aspalpha);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_aspnum);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_faauto);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_adjustright);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_rin, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_lin, 284);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_itap, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_fs, 20);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_lang, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_langfe, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_cgrid);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_langnp, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_langfenp, 1033);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_sbasedon, 0);
   if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_snext, 42 /* 17 */);
   if(SUCCEEDED(retc)) retc=PutStr((const unsigned char *)"OrdPar");
   if(SUCCEEDED(retc)) retc=PutChar(C_Semic, False);
   if(SUCCEEDED(retc)) retc=CloseField();
   if(SUCCEEDED(retc)) retc=PutChar(C_Lf, False);
#endif

#if FALSE
   for(ii=0; (ii<LZDSH_NUM_OF_PAR_STYLES) && SUCCEEDED(retc); ii++)
   {
      if(SUCCEEDED(retc)) retc=OpenField();
      if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_s, ii+KPP_FIRST_PAR_STYLE);

      if(SUCCEEDED(retc)) retc=PutStr(lpszaParStyCmds[ii]);

      if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_sbasedon, iaBasedOn[ii]);
      if(SUCCEEDED(retc)) retc=PutKwrd(RT_TG_snext, ii+KPP_FIRST_PAR_STYLE);
      if(SUCCEEDED(retc)) retc=PutStr(lpszaParStyNames[ii]);
      if(SUCCEEDED(retc)) retc=PutChar(C_Semic, False);
      if(SUCCEEDED(retc)) retc=CloseField();
      if(SUCCEEDED(retc)) retc=PutChar(C_Lf, False);
   }
#endif

   if(SUCCEEDED(retc)) retc=CloseField();
   if(SUCCEEDED(retc)) retc=PutChar(C_Lf, False);

#if FALSE
// columns
   if(SUCCEEDED(retc)) retc=PutStr(lpszColumnsStr);
   if(SUCCEEDED(retc)) retc=PutChar(C_Lf, False);

// page numbering
   if(SUCCEEDED(retc)) retc=PutStr(lpszPageNumberStr);
   if(SUCCEEDED(retc)) retc=PutChar(C_Lf, False);
#endif

return(retc);
}
// #endif


// ----------------------------------
LzdShSearch::LzdShSearch(void)
{
HRESULT retc = m_lhOpenResult;

#ifdef LZDSH_EDITOR_BUILD
#ifdef Debug
// m_lpszTestRtfText[0]=Nul;
#endif
#endif

   m_lpInFileObj = NULL;
   m_lpOutFileObj = NULL;

#ifdef LZDSH_EDITOR_BUILD
   m_pCurNode = NULL;
#endif

// m_lpszToSearch[0]=Nul;
// KP_TRACE("LzdShSearch(): SetToSearchStr(\"\")");
   if(SUCCEEDED(retc)) retc = SetToSearchStr((const unsigned char *)"", LZDSH_HIST_NONE);

   m_lpszToHistStr[0] = Nul;
   m_lpszPrevHistWord[0] = Nul;

   m_iToHistListFlags = LZDSH_HIST_NONE;

   m_iLevel = BigLevel; // FullLevel;
   m_bAccFl = True;

   m_lQuietTime = 0L;

#ifdef LZDSH_EDITOR_BUILD
   m_bRefreshCurNodeHead = False;
   m_bRefreshDisplay = False;
#endif

   m_bReactToSelFlag = False;
   if(SUCCEEDED(retc)) retc = GetReactToSel((bool *)&m_bReactToSelFlag);

#ifdef KP_USE_TextGRAB
   m_pITextGRABSDK = NULL;
#endif
   m_lpszClipBuf[0] = Nul;

   if(SUCCEEDED(m_lhOpenResult)) m_lhOpenResult = retc;
}


// ----------------------------------
LzdShSearch::~LzdShSearch(void)
{
   CloseFiles(False);

#ifdef KP_USE_TextGRAB
   if(m_pITextGRABSDK)
   {
   /* retc = */ m_pITextGRABSDK->RegisterSelectionNotify(NULL);
//    if(FAILED(retc)) KP_ERROR(retc, GetLastError());

      m_pITextGRABSDK->Release();
      m_pITextGRABSDK = NULL;
   }
#endif
}


// ----------------------------------
HRESULT LzdShSearch::InitLzdShSearch(void)
{
HRESULT retc=S_OK;
#ifdef KP_USE_TextGRAB
#  ifdef KP_USE_classFactory
IClassFactory *classFactory = NULL;

   LZDSH_DLG_PTR_INIT;

   KP_ASSERT(lzdsh_dlg->m_hDialogWindow != NULL, KP_E_SYSTEM_ERROR, null, True);

   if(SUCCEEDED(retc))
   {
//    retc = CoGetClassObject(&CLSID_TextGRABSDK, CLSCTX_INPROC_SERVER, NULL, &IID_ITextGRABSDK, &classFactory); // plain C
      retc = CoGetClassObject(CLSID_TextGRABSDK, CLSCTX_INPROC_SERVER, NULL, IID_ITextGRABSDK, (LPVOID *)&classFactory);
      if(FAILED(retc)) KP_ERROR(retc, GetLastError());
   }
   KP_ASSERT(classFactory, KP_E_SYSTEM_ERROR, null, True);
// KP_ASSERT(classFactory->lpVtbl, KP_E_SYSTEM_ERROR, null, True); // plain C
// KP_ASSERT(classFactory->lpVtbl->CreateInstance, KP_E_SYSTEM_ERROR, null, True); // plain C
// KP_ASSERT(classFactory->lpVtbl->Release, KP_E_SYSTEM_ERROR, null, True); // plain C

   if(SUCCEEDED(retc))
   {
//    retc = classFactory->lpVtbl->CreateInstance(classFactory, NULL, &IID_ITextGRABSDK, &m_pITextGRABSDK); // plain C
      retc = classFactory->CreateInstance(NULL, IID_ITextGRABSDK, (LPVOID *)&m_pITextGRABSDK);
      if(FAILED(retc)) KP_ERROR(retc, GetLastError());
      KP_ASSERT(m_pITextGRABSDK, KP_E_SYSTEM_ERROR, null, True);

//    classFactory->lpVtbl->Release(classFactory); // plain C
      classFactory->Release();
      classFactory = NULL;
   }

#  else // #  ifdef KP_USE_classFactory

   if(SUCCEEDED(retc))
   {
//    retc = CoCreateInstance(&CLSID_TextGRABSDK, NULL, CLSCTX_INPROC_SERVER, &IID_ITextGRABSDK, &m_pITextGRABSDK); // plain C
      retc = CoCreateInstance(CLSID_TextGRABSDK, NULL, CLSCTX_INPROC_SERVER, IID_ITextGRABSDK, (void **)&m_pITextGRABSDK);
      if(FAILED(retc)) KP_ERROR(retc, GetLastError());
   }
   KP_ASSERT(m_pITextGRABSDK, KP_E_SYSTEM_ERROR, null, True);

#  endif // #  else // #  ifdef KP_USE_classFactory

   if(SUCCEEDED(retc))
   {
      retc = m_pITextGRABSDK->SetLicense(L"", L"");// 'Trial period
      if(FAILED(retc)) KP_ERROR(retc, null);
   }

   if(SUCCEEDED(retc))
   {
      retc = m_pITextGRABSDK->RegisterSelectionNotify((INT_PTR)lzdsh_dlg->m_hDialogWindow);
      if(FAILED(retc)) KP_ERROR(retc, null);
   }
#endif // #ifdef KP_USE_TextGRAB

return(retc);
}


// ----------------------------------
HRESULT LzdShSearch::OpenFiles
(
   const unsigned char *
//    lpszInFileName
      ,
   XmlVersions /* iVersion */,
   HRESULT /* KpInFileFactory */
   (
      KpFile **lppFileObjPtrPtr,
      const unsigned char *lpszFNam,
      const unsigned char *lpszFMod,
      XL_FileTypes uiFTyp,
      bool bMapToPrivate
   ),
   HRESULT /* KpOutFileFactory */
   (
      KpFile **lppFileObjPtrPtr,
      const unsigned char *lpszFNam,
      const unsigned char *lpszFMod,
      XL_FileTypes uiFTyp,
      bool bMapToPrivate
   )
)
{
HRESULT retc=S_OK;
unsigned char str_buf[100];
KpTreeEntry *cur_dict;
DictListEntry *cur_dict_data;
unsigned char fname[2*KP_MAX_FNAME_LEN+1];
int ii;

   /* if(SUCCEEDED(retc)) */ retc = BlockSemaphore();

   LZDSH_DLG_PTR_INIT;

   KP_ASSERT(lzdsh_dlg->m_DictList != NULL, KP_E_NO_FILE, null, True);

   if(SUCCEEDED(retc))
   {
      ii = lzdsh_dlg->m_iCurDictEntry;
      cur_dict = NULL;

      if(SUCCEEDED(retc)) retc = lzdsh_dlg->m_DictList->GetEntryPtr(&ii, &cur_dict, 0, NULL);
   }

   if((cur_dict == NULL) && SUCCEEDED(retc))
      retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, TRUE, __FILE__, __LINE__, 0L);

   if(SUCCEEDED(retc))
   {
      cur_dict_data = (DictListEntry *)cur_dict->GetValue();
      if(cur_dict_data == NULL)
         retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, TRUE, __FILE__, __LINE__, 0L);
   }

   if(SUCCEEDED(retc))
   {
//    SortMode = tolower(lpszInFileName[0]);
      SortMode = cur_dict_data->iLanguage;

      strcpy(fname, cur_dict_data->m_lpszFileName);
//    if(strlen(fname) >= KP_MAX_FNAME_LEN)
//       retc = KpErrorProc.OutputErrorMessage(KP_E_BUFFER_OVERFLOW, null, TRUE, __FILE__, __LINE__, 0L);
   }
   if(SUCCEEDED(retc))
   {
#ifdef LZDSHT_ENCODED
      strcat(fname, ".xdb");
#else
      strcat(fname, ".xml");
#endif

//    m_lpInFileObj = new XmlI((const unsigned char *)"lvz.xml",
//    m_lpInFileObj = new XmlI((const unsigned char *)"f:\\kp\\source\\tev\\lvz\\kpn3.xml",
//    m_lpInFileObj = new XmlI((const unsigned char *)"lvz_s2.xml",
      KP_NEWO(m_lpInFileObj, XmlI(fname,
                     (const unsigned char *)"rb",
#ifdef LZDSHT_ENCODED
//                   CreateNewUniFile,
                     CreateNew8File,
#else
                     CreateNewUniFile,
#endif
                     plpszaXmlSpecCharTagsMain,
                     alpszIndexNames, aiIndexWidths, caIxLangs, iaIxEncodings,
                     (KpChar)XC_FirstDictTag, plpszaXmlttDictTags,
                     XM_VERS_XML10, iaXmlDictNulCodeTables, True, False, False));
   }

#ifdef LZDSHT_ENCODED
UC_Modes enc_mode;
int ctbl;
int def_ctbl;
   if(SUCCEEDED(retc)) retc = m_lpInFileObj->GetEncoding(&enc_mode, &ctbl, &def_ctbl);
   if(SUCCEEDED(retc)) retc = m_lpInFileObj->SetEncoding(enc_mode, 99, 99); // transparent code table
#endif

#ifdef IBSH_RES_MODE_XGECKO
   KP_ASSERT(m_pResBuf != NULL, KP_E_NO_FILE, null, True);
#endif

   if(SUCCEEDED(retc))
   {

//    sprintf((char *)str_buf, "%x %x", m_lpszCurSearchResult, LZDSHT_RESULT_BUF_LEN); // buvo prie #if LZDSH_OUT_VERS == XML_VERS_SGML_TAGE
//    sprintf((char *)str_buf, "%x %x", m_lpszResultFormatted, LZDSHT_RESULT_BUF_LEN);
//    sprintf((char *)str_buf, "%x %x", lzdsh_dlg->m_pResBuf, LZDSHT_RESULT_BUF_LEN);
      sprintf((char *)str_buf, "%x %x", m_pResBuf, LZDSHT_RESULT_BUF_LEN);

#if LZDSH_OUT_VERS == XML_VERS_SGML_TAGE
      KP_NEWO(m_lpOutFileObj, XmlI(str_buf, (const unsigned char *)"w",
                        CreateNewBFile,
                        plpszaXmlSpecCharTagsMain,
                        NULL, NULL,
                        caIxLangs, iaIxEncodings,
                        XC_FirstDictTag, plpszaSgmDictTags,
                        (XmlVersions)LZDSH_OUT_VERS, iaSgmCodeTables, True, False));
#endif

#if LZDSH_OUT_VERS == XML_VERS_XML10
      KP_NEWO(m_lpOutFileObj, XmlI((const unsigned char *)str_buf, (const unsigned char *)"w",
#  ifdef LZDSH_RES_CODING_UTF8
                        CreateNewUniBFile,
#  else
                        CreateNewUni16BFile, // CreateNewUniBFile, // CreateNewBFile,
#  endif
                        plpszaXmlSpecCharTagsMain,
                        NULL, NULL,
                        caIxLangs, iaIxEncodings,
                        XC_FirstDictTag, plpszaXmlttDictTagsFull, // plpszaSgmDictTags, // plpszaHtmlDictTags,
                        (XmlVersions)LZDSH_OUT_VERS, iaXmlNulCodeTables, False, True, True));
#endif

#if XM_IS_VERS_HTML(LZDSH_OUT_VERS)
//    KP_NEWO(m_lpOutFileObj, TvXmlFile(str_buf, (const unsigned char *)"w", XL_FT_DataFile,
//                      CreateNewBFile,
//                      plpszaHtmSpecCharTags, NULL,
//                      XC_FirstDictTag, plpszaHtmlDictTags,
//                      (XmlVersions)LZDSH_OUT_VERS, iaXmlNulCodeTables, True, True));

      KP_NEWO(m_lpOutFileObj, XmlI((const unsigned char *)str_buf, (const unsigned char *)"w",
#  ifdef LZDSH_RES_CODING_UTF8
                        CreateNewUniBFile,
#  else
                        CreateNewUni16BFile, // CreateNewUniBFile, // CreateNewBFile,
#  endif
                        plpszaHtmSpecCharTags,
                        NULL, NULL,
                        caIxLangs, iaIxEncodings,
                        XC_FirstDictTag, plpszaXmlttDictTagsFull, // plpszaSgmDictTags, // plpszaHtmlDictTags,
                        (XmlVersions)LZDSH_OUT_VERS, iaHtmlDictCodeTables, True, True, True));
#endif

#ifdef IBSH_RES_MODE_RTF
      KP_NEWO(m_lpOutFileObj, TvRtfO(str_buf, CreateNewBFile, iaRtfFonts));
#endif

#ifndef IBSH_RES_MODE_RTF
      if(SUCCEEDED(retc)) retc = m_lpOutFileObj->SetPathMode(
#  ifdef IBSH_RES_MODE_RTF
         XL_RelativePath
#  endif
#  ifdef IBSH_RES_MODE_MSHTML
         XL_AbsolutePath
#  endif
#  ifdef IBSH_RES_MODE_XGECKO
         XL_TuxPath
#  endif
         );
#endif

#ifdef LZDSH_EDITOR_BUILD
#ifdef IBSH_RES_MODE_RTF
#if FALSE // #ifdef Debug
      sprintf((char *)str_buf, "%x %x", m_lpszTestRtfText, LZDSHT_RESULT_BUF_LEN);
      KP_NEWO(m_lpRtfTestOutFileObj, TvRtfO(str_buf, CreateNewBFile, iaRtfFonts));
#endif
#endif
#endif

   }

   /* if(SUCCEEDED(retc)) retc = */ ReleaseSemaphore();

return(retc);
}


// --------------------------------------------------
HRESULT LzdShSearch::CloseFiles(bool bCheckFileExist)
{
HRESULT retc = S_OK;
HRESULT retc0 = S_OK;

   /* if(SUCCEEDED(retc)) */ retc = BlockSemaphore();

   if(m_lpInFileObj!=NULL)
   {
XmlI *in_file = m_lpInFileObj;
      m_lpInFileObj = NULL;

      retc = in_file->CloseFile(bCheckFileExist);
      KP_DELETE(in_file);
   }
   else
   {
      if(!bCheckFileExist) retc=KP_E_NO_FILE;
      else retc=KpErrorProc.OutputErrorMessage(KP_E_NO_FILE, null, TRUE, __FILE__, __LINE__, 0L);
   }

// KpMsgOut_1("LzdShSearch::CloseFiles m_lpOutFileObj: %lx", m_lpOutFileObj);

   if(m_lpOutFileObj != NULL)
   {
      retc0 = m_lpOutFileObj->CloseFile(bCheckFileExist);
      if(SUCCEEDED(retc)) retc = retc0;
   
      KP_DELETE(m_lpOutFileObj);
   }
   else
   {
      if(SUCCEEDED(retc))
      {
         if(!bCheckFileExist) retc = KP_E_NO_FILE;
         else retc = KpErrorProc.OutputErrorMessage(KP_E_NO_FILE, null, TRUE, __FILE__, __LINE__, 0L);
      }
   }

#ifdef LZDSH_EDITOR_BUILD
#ifdef IBSH_RES_MODE_RTF
#if FALSE // #ifdef Debug
   if(m_lpRtfTestOutFileObj!=NULL)
   {
TvRtfO *test_out_file = m_lpRtfTestOutFileObj;
      m_lpRtfTestOutFileObj = NULL;

      retc0 = test_out_file->CloseFile(bCheckFileExist);
      if(SUCCEEDED(retc)) retc = retc0;

      KP_DELETE(test_out_file);
   }
   else
   {
      if(SUCCEEDED(retc))
      {
         if(!bCheckFileExist) retc=KP_E_NO_FILE;
         else retc=KpErrorProc.OutputErrorMessage(KP_E_NO_FILE, null, TRUE, __FILE__, __LINE__, 0L);
      }
   }
#endif
#endif
#endif

   /* if(SUCCEEDED(retc)) retc = */ ReleaseSemaphore();

// KpMsgOut_0("LzdShSearch::CloseFiles [1]");

return(retc);
}


// ----------------------------------
HRESULT LzdShSearch::SetToSearchStr(const unsigned char *lpszToSearchStr, int iToHistListFlags)
{
HRESULT retc=S_OK;
int pos;
unsigned char *pnts;

   KP_ASSERT(lpszToSearchStr, E_INVALIDARG, null, True);

// LZDSH_DLG_PTR_INIT;
KpPubDlg *lzdsh_dlg_unsafe = NULL;
   if(theKpStAppPtr != NULL) if(theKpStAppPtr->m_pGrpKpPubDlg != NULL)
      lzdsh_dlg_unsafe = theKpStAppPtr->m_pGrpKpPubDlg;

   /* if(SUCCEEDED(retc)) retc = */ BlockSemaphore();

   if(SUCCEEDED(retc))
   {
      pos = KP_MAX_FILE_LIN_WDT;
      pnts = strchr(lpszToSearchStr, TECH_DELIM_CHR); // 0xAD // C_hyph lentelëje 71
      if(pnts) if(pnts - lpszToSearchStr < pos) pos = pnts - lpszToSearchStr;
      strncpy((unsigned char *)m_lpszToSearch, lpszToSearchStr, pos);
      m_lpszToSearch[pos] = Nul;

#ifdef IBSH_RES_MODE_XGECKO
      if(SUCCEEDED(retc)) if(pnts)
      {
         if(strlen(pnts) >= TV_XL_MAX_TAG_WDT)
            retc=KpErrorProc.OutputErrorMessage(KP_E_BUFFER_OVERFLOW, null, True, __FILE__, __LINE__, 0L, NULL);
         if(SUCCEEDED(retc)) if(lzdsh_dlg_unsafe != NULL) strcpy((unsigned char *)lzdsh_dlg_unsafe->m_lpszSelDictName, pnts+1);
         retc = S_OK;
      }
#endif

// KP_TRACE_2("SetToSearchStr: m_lpszToSearch:%s lpszToSearchStr:%s", m_lpszToSearch, lpszToSearchStr);

      if(SUCCEEDED(retc)) /* retc= */ CutTrailSpcs((unsigned char *)m_lpszToSearch, lpszSpcEolNotNBSP);
   }

// ----------------------------
   if((m_iToHistListFlags & LZDSH_HIST_FORCED_NONE) == 0) m_iToHistListFlags = iToHistListFlags;

bool hist_list = False;
   if(SUCCEEDED(retc)) if(lzdsh_dlg_unsafe != NULL) hist_list = (lzdsh_dlg_unsafe->m_CurList == lzdsh_dlg_unsafe->m_HistList);
   if(
      (
         ((m_iToHistListFlags & LZDSH_HIST_DEPENDENT) && (!hist_list)) ||
         (m_iToHistListFlags & LZDSH_HIST_INDEPENDENT)
      ) &&
      (m_iToHistListFlags & (LZDSH_HIST_TIMER|LZDSH_HIST_IMMEDIATELY)) &&
      SUCCEEDED(retc)
     )
   {
// KP_TRACE_2("SetToSearchStr(): m_lpszToHistStr:%s m_lpszToSearch:%s", m_lpszToHistStr, m_lpszToSearch);
      m_lpszToHistStr[KP_MAX_FILE_LIN_WDT]=Nul;
      strncpy((unsigned char *)m_lpszToHistStr, (const unsigned char *)m_lpszToSearch, KP_MAX_FILE_LIN_WDT);
      m_lpszToHistStr[KP_MAX_FILE_LIN_WDT]=Nul;
KP_TRACE_("SetToSearchStr: m_lpszToHistStr:%s", m_lpszToHistStr);
   }
// ----------------------------

   if(SUCCEEDED(retc))
   {
      pos=strlen((const unsigned char *)m_lpszToSearch)-1;
      while((pos>=0) && SUCCEEDED(retc))
      {
         if(m_lpszToSearch[pos]==DOUBLE_ENTRIES_LZDSH_CHR) // 0xA0 // C_NBSP lenteleje 71
            m_lpszToSearch[pos--]=DOUBLE_ENTRIES_CHR; // '*'
         else break;
      }
   }

#if FALSE // #ifdef Debug //
char str_buf[200];
sprintf(str_buf, ">>>%s<<< >>>%s<<<", m_lpszToSearch, lpszToSearchStr);
// KpMsgOut(str_buf, IDI_ASTERISK, KP_MB_TESTI);
KP_TRACE(str_buf);
#endif

   /* if(SUCCEEDED(retc)) retc = */ ReleaseSemaphore();

return(retc);
}


// --------------------------------------------------
KpChar *NormalizeHeadword(KpChar *piazOutStr, const KpChar *piazInStr)
{
const KpChar *pnts;
KpChar *pntd;

   pnts=piazInStr;
   pntd=piazOutStr;
   if(pnts) while(*pnts)
   {
      switch(*pnts)
      {
      case TV_XM_CompDelim:
         break;
//    case DOUBLE_ENTRIES_CHR: // '*'
      case DOUBLE_ENTRIES_KPCHAR: // C_Bpoint, bullet
         *(pntd++)=DOUBLE_ENTRIES_LZDSH_KPCHAR; // C_NBSP;
         break;
      default:
         *(pntd++)=(*pnts);
         break;
      }
      pnts++;
   }

   *pntd=C_Nul;

return(piazOutStr);
}


// ----------------------------------
HRESULT LzdShSearch::CalcOffsets
(
   long
#ifndef LZDSHT_FULL_LIST
      lOffset
#endif
      ,
   long *plStartOffset,
   long *plEndOffset
)
{
HRESULT retc=S_OK;
long full_size;
long end_of_file;

   if((plStartOffset==NULL) || (plEndOffset==NULL))
      retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);

   if(SUCCEEDED(retc))
      full_size=aiIndexWidths[m_iIndexFile];

   if(SUCCEEDED(retc))
      retc=m_lpInFileObj->FilePtr->GetIndexSize(&end_of_file, m_iIndexFile);

   if(SUCCEEDED(retc))
   {
#ifdef LZDSHT_FULL_LIST
      *plStartOffset=0L;
      *plEndOffset=end_of_file;
#else
      *plEndOffset=lOffset+full_size*LZDSH_LIST_NUM_LINES/2;
      if(*plEndOffset>end_of_file) *plEndOffset=end_of_file;

      *plStartOffset=*plEndOffset-full_size*LZDSH_LIST_NUM_LINES;
      if(*plStartOffset<0L) *plStartOffset=0L;

      *plEndOffset=*plStartOffset+full_size*LZDSH_LIST_NUM_LINES;
      if(*plEndOffset>end_of_file) *plEndOffset=end_of_file;
#endif
   }

return(retc);
}


// ----------------------------------
HRESULT LzdShSearch::CvtToKwd(/* int iLang */)
{
HRESULT retc=S_OK;
unsigned char *pntd;

// KpChar str_buf_i[KP_MAX_FILE_LIN_WDT+1];
// KpChar str_buf_ii[KP_MAX_FILE_LIN_WDT+1];
// int chr_cnt;
// KpChar *pnti;
// EC_Types encoding;

   LZDSH_DLG_PTR_INIT;

#if TRUE // FALSE //
   strcpy(m_lpszCurSearchKwd, m_lpszCurSearchWord);
   if(SUCCEEDED(retc)) retc=CutTrailSpcs(m_lpszCurSearchKwd, lpszSpcEolNotNBSP);

   pntd = m_lpszCurSearchKwd + strlen(m_lpszCurSearchKwd) - 1;
   while(pntd >= m_lpszCurSearchKwd)
   {
      if(*pntd == DOUBLE_ENTRIES_LZDSH_CHR) // 0xA0 // C_NBSP lenteleje 71
         *pntd = DOUBLE_ENTRIES_CHR; // '*' // '.'; // C_Point
      else break;
      pntd--;
   }

#else

   if(SUCCEEDED(retc)) retc=CutTrailSpcs(m_lpszCurSearchKwd, lpszSpcEolNotNBSP);
   chr_cnt=strlen(m_lpszCurSearchWord);

   if(SUCCEEDED(retc)) retc=KptStrEncode(str_buf_i, m_lpszCurSearchWord, lzdsh_dlg->m_iCtrlCtbl);

   pnti=str_buf_i;
   while(*pnti)
   {
      if(*pnti==DOUBLE_ENTRIES_LZDSH_KPCHAR) *pnti=C_Point; // C_NBSP
      pnti++;
   }

#if FALSE
   if(SUCCEEDED(retc))
   {
      encoding=iaIxEncodings[m_iCurIndexFile];
//    if(m_iCurIndexFile==XL_IX_TxIndex) encoding=(EC_Types)TV_IX_CTBL; // paieskai po visa teksta ivedinet su diakritais // ne !!!
   }

#if FALSE // TRUE //
   if(SUCCEEDED(retc)) retc=ExpandAbbr(str_buf_ii, str_buf_i, &chr_cnt, TV_XL_MAX_IX_LEN, iLang);
   if(SUCCEEDED(retc)) retc=DelComments(str_buf_ii, &chr_cnt);
   if(SUCCEEDED(retc)) str_buf_ii[chr_cnt]=C_Nul;
   if(SUCCEEDED(retc)) retc=TvXmlEs.CutEndingsDelCjts(str_buf_i, str_buf_ii, iLang, encoding, True);
   if(SUCCEEDED(retc)) chr_cnt=TvIntStrLen(str_buf_i);
   if(SUCCEEDED(retc)) retc=KpCharToStrNoCtrl(m_lpszCurSearchKwd, str_buf_i, chr_cnt, TV_XL_MAX_IX_LEN, plpszaXmlSpecCharTagsMain, iaIxEncodings[m_iCurIndexFile]);
   if(SUCCEEDED(retc)) TvStrLwr(m_lpszCurSearchKwd);
   if(SUCCEEDED(retc)) retc = CutInitSpcs(m_lpszCurSearchKwd, lpszSpcEolNotNBSP);
   if(SUCCEEDED(retc)) retc = CutTrailSpcs(m_lpszCurSearchKwd, lpszSpcEolNotNBSP);
#else
   if(SUCCEEDED(retc)) retc=KpCharToIndexEntry(m_lpszCurSearchKwd, str_buf_i, chr_cnt, KP_MAX_FILE_LIN_WDT, iLang, encoding);
   if(SUCCEEDED(retc)) TvStrLwr(m_lpszCurSearchKwd);
#endif

#else
   if(SUCCEEDED(retc)) retc=KptStrDecode(m_lpszCurSearchWord, str_buf_i, lzdsh_dlg->m_iCtrlCtbl);
#endif

#endif

return(retc);
}


// ----------------------------------
#ifdef LZDSHT_ENCODED
HRESULT WriteRtfFromImg(void *pPars)
{
HRESULT retc=S_OK;
GetHwFromImgPars *par_ptr=NULL;
unsigned char *entry_text_ptr=NULL;
long entry_len;
XmlI *in_file=NULL;
unsigned char str_buf[100];
XmlNode *node_ptr=NULL;

// KP_TRACE("**** WriteRtfFromImg ****");

   KP_ASSERT(pPars != NULL, E_INVALIDARG, null, True);

   LZDSH_DLG_PTR_INIT;
   LZDSH_SEARCH_PTR_INIT;

   if(SUCCEEDED(retc))
   {
      par_ptr = (GetHwFromImgPars *)pPars;
      if(par_ptr->m_lpszEntryImg == NULL)
         retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);
   }

   if(SUCCEEDED(retc))
   {
      entry_text_ptr=par_ptr->m_lpszEntryImg;
      entry_len=par_ptr->m_lEntryLength;
      entry_text_ptr[entry_len]=Nul;
   }

// KP_TRACE(entry_text_ptr);

   if(SUCCEEDED(retc))
   {
      sprintf((char *)str_buf, "%x %x", entry_text_ptr, entry_len);

// KpMsgOut(str_buf, IDI_ASTERISK, KP_MB_TESTI);

      KP_NEW(in_file, XmlI(str_buf,
                     (const unsigned char *)"rb",
//                   CreateNewBFile,
                     CreateNewUniBFile,
                     plpszaXmlSpecCharTagsMain,
                     alpszIndexNames, aiIndexWidths, caIxLangs, iaIxEncodings,
                     (KpChar)XC_FirstDictTag, plpszaXmlttDictTags,
                     XM_VERS_XML10, iaXmlDictNulCodeTables, True, False, False));
   }

   if((node_ptr!=NULL) && SUCCEEDED(retc))
      retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
   if(SUCCEEDED(retc)) retc=ReadEntry(&node_ptr, in_file, True);
   if((node_ptr==NULL) && SUCCEEDED(retc))
      retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

   KP_DELETE(in_file);

   if(SUCCEEDED(retc)) memset(entry_text_ptr, Nul, entry_len);

   if(SUCCEEDED(retc)) retc = lzdsh_search->FormatEntry(node_ptr, lzdsh_dlg);

   KP_DELETE(node_ptr);

return(retc);
}
#endif


// ----------------------------------
#ifdef LZDSHT_ENCODED
KpChar iazEmptyStr[]={ C_Nul };
HRESULT GetHwFromImg(void *pPars)
{
HRESULT retc=S_OK;
GetHwFromImgPars *par_ptr=NULL;
unsigned char *entry_text_ptr=NULL;
XmlNode *node_ptr=NULL;
long entry_len;
XmlI *in_file=NULL;
unsigned char str_buf[100];
KpChar *hw_ptr=NULL;
KpChar *hw_buf_ptr=NULL;

// KP_TRACE("**** GetHwFromImg ****");

   if(pPars==NULL)
      retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);

   if(SUCCEEDED(retc))
   {
      par_ptr=(GetHwFromImgPars *)pPars;
      if((par_ptr->m_lpszEntryImg==NULL) && SUCCEEDED(retc))
         retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);
      if((par_ptr->m_piazHwPtr==NULL) && SUCCEEDED(retc))
         retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);
   }

   if(SUCCEEDED(retc))
   {
      entry_text_ptr=par_ptr->m_lpszEntryImg;
      entry_len=par_ptr->m_lEntryLength;
      entry_text_ptr[entry_len]=Nul;
   }

// KP_TRACE(">>>");
// KP_TRACE(entry_text_ptr);
// KP_TRACE("<<<");

   if(SUCCEEDED(retc))
   {
      sprintf((char *)str_buf, "%x %x", entry_text_ptr, entry_len);
      KP_NEW(in_file, XmlI(str_buf,
                     (const unsigned char *)"rb",
//                   CreateNewBFile,
                     CreateNewUniBFile,
                     plpszaXmlSpecCharTagsMain,
                     alpszIndexNames, aiIndexWidths, caIxLangs, iaIxEncodings,
                     (KpChar)XC_FirstDictTag, plpszaXmlttDictTags,
                     XM_VERS_XML10, iaXmlDictNulCodeTables, True, False, False));
   }

   if((node_ptr!=NULL) && SUCCEEDED(retc))
      retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
   if(SUCCEEDED(retc)) retc = ReadEntry(&node_ptr, in_file, True);
   if((node_ptr==NULL) && SUCCEEDED(retc))
      retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

   KP_DELETE(in_file);

   if(SUCCEEDED(retc)) memset(entry_text_ptr, Nul, entry_len);

   if(SUCCEEDED(retc)) retc=node_ptr->GetHw(&hw_ptr);
   if((hw_ptr==NULL) && SUCCEEDED(retc)) hw_ptr=iazEmptyStr;

   KP_NEWA(hw_buf_ptr, KpChar, TvKpStrLen(hw_ptr) + 1);

   if(SUCCEEDED(retc))
   {
      TvKpStrCpy(hw_buf_ptr, hw_ptr);
      *par_ptr->m_piazHwPtr=hw_buf_ptr;
   }

#if FALSE // #ifdef Debug
// unsigned char str_buf[200];
KptStrDecode(str_buf, hw_buf_ptr, TvIntStrLen(hw_buf_ptr), 80);
KP_TRACE(str_buf);
#endif

   KP_DELETE(node_ptr);

return(retc);
}
#endif


// ----------------------------------
#ifdef LZDSHT_ENCODED
HRESULT LzdShSearch::WriteRtfFromEncImg(unsigned char *caEntryImg, long lEntryLength, long lEntryId /*, DWORD lMainThreadId */)
{
HRESULT retc = S_OK;
static KpRcPars rc_pars;
static GetHwFromImgPars callback_pars;

   if((caEntryImg==NULL) && SUCCEEDED(retc))
      retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);

   callback_pars.m_lpszEntryImg=caEntryImg; // decoded entry is left in the same array
   callback_pars.m_lEntryLength=lEntryLength;

   rc_pars.iOpCode=KP_RC_ENCODE_ENTRY_AND_CALLBACK;
   rc_pars.iParBlSize=sizeof(rc_pars);
   rc_pars.enc.iDataLen=((lEntryLength+4)/4)*4;
   rc_pars.enc.pData=caEntryImg;
   rc_pars.enc.lCtrl=lEntryId;
   rc_pars.enc.iCallBackIx=LZDSH_RC_WriteRtfFromImg;
   rc_pars.enc.pCallBackPars=&callback_pars;

   retc=EmuTv.ExecRemoteCall(&rc_pars /* , lMainThreadId */);

return(retc);
}
#endif


// ----------------------------------
#ifdef LZDSHT_ENCODED
HRESULT LzdShSearch::GetHwFromEncImg(KpChar **piazHwPtr, unsigned char *caEntryImg, long lEntryLength, long lEntryId /* , DWORD lMainThreadId */)
{
HRESULT retc=S_OK;
static KpRcPars rc_pars;
static GetHwFromImgPars callback_pars;

#if FALSE // #ifdef Debug
unsigned char str_buf[200];
KP_TRACE("GetHwFromEncImg");
sprintf((char *)str_buf, ">>>%x %x %x %x %x<<<", caEntryImg[0], caEntryImg[1], caEntryImg[2], caEntryImg[3], caEntryImg[4]);
KP_TRACE(str_buf);
#endif

   if(((piazHwPtr==NULL) || (caEntryImg==NULL)) && SUCCEEDED(retc))
      retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);

   callback_pars.m_lpszEntryImg=caEntryImg; // decoded entry is left in the same array
   callback_pars.m_lEntryLength=lEntryLength;
   callback_pars.m_piazHwPtr=piazHwPtr;

#if FALSE
fstream out_file("xmlb0.txt", ios::out | ios::binary);
out_file << hex << (int)caEntryImg << " " << (int)lEntryLength << endl;
out_file.write((const char *)caEntryImg, lEntryLength);
out_file.close();
#endif

   rc_pars.iOpCode=KP_RC_ENCODE_ENTRY_AND_CALLBACK;
   rc_pars.iParBlSize=sizeof(rc_pars);
   rc_pars.enc.iDataLen=((lEntryLength+4)/4)*4;
   rc_pars.enc.pData=caEntryImg;
   rc_pars.enc.lCtrl=lEntryId;
   rc_pars.enc.iCallBackIx=LZDSH_RC_GetHwFromImg;
   rc_pars.enc.pCallBackPars=&callback_pars;

   retc=EmuTv.ExecRemoteCall(&rc_pars /* , lMainThreadId */);

return(retc);
}
#endif


// ----------------------------------
HRESULT LzdShSearch::FormatEntry(XmlNode *pCurEntry, KpPubDlg *pDialogPtrPar)
{
HRESULT retc = S_OK;
// unsigned char str_buf[KP_MAX_FILE_LIN_WDT+1];
#ifndef IBSH_RES_MODE_RTF
XmlVersions vers;
#endif

   KP_ASSERT(pCurEntry != NULL, E_INVALIDARG, null, True);

KpPubDlg *lzdsh_dlg = pDialogPtrPar;
   KP_ASSERT(lzdsh_dlg != NULL, E_INVALIDARG, null, True);

   KP_ASSERT(m_lpOutFileObj != NULL, KP_E_NO_FILE, null, True);

   if((!m_bAccFl) && SUCCEEDED(retc)) retc = pCurEntry->ClearAccents();

// ----------------------- process levels
// if(SUCCEEDED(retc)) retc=pCurEntry->DelLevelTags(m_iLevel);

// kai visi mazgai bus su lygmenim
   if(SUCCEEDED(retc)) retc=pCurEntry->ProcessLevel(m_iLevel, True);

// !!!! sutvarkyt zodynu lygmenis, kad nebutu mazgu be lygmenu
//// if(SUCCEEDED(retc)) retc=pCurEntry->SupressToLevel(m_iLevel);
// if(SUCCEEDED(retc)) retc=pCurEntry->DelLevelTags(m_iLevel);
// if(SUCCEEDED(retc)) retc=pCurEntry->DelTags(m_iLevel);
// if(SUCCEEDED(retc)) retc=pCurEntry->UpLevelGroups();
// if(SUCCEEDED(retc)) retc=pCurEntry->DelEmptyTags();

// -----------------------
   if(SUCCEEDED(retc)) if(lzdsh_dlg->m_CurList == lzdsh_dlg->m_SearchList)
   {
//    retc = KpGetCtrlText(lzdsh_dlg->m_InpEdit, str_buf, KP_MAX_FILE_LIN_WDT);
//    str_buf[KP_MAX_FILE_LIN_WDT]=Nul;
//    strcpy(str_buf, lzdsh_dlg->m_lpszLastSearchStr);

#ifdef XL_TX_GRAM
      retc=pCurEntry->MarcHighlightedGram((const unsigned char *)lzdsh_dlg->m_lpszLastSearchStr, (EC_Types)TV_IX_CTBL);
#else
      retc=pCurEntry->MarcHighlighted((const unsigned char *)m_lpszLastSearchStr, (EC_Types)TV_IX_CTBL);
#endif
   }

#ifdef IBSH_RES_MODE_RTF
   if(SUCCEEDED(retc)) // if(lzdsh_dlg->m_ResRichEdit!=NULL)
   {
      if(SUCCEEDED(retc)) retc=m_lpOutFileObj->Reset();

#  if FALSE
      if(SUCCEEDED(retc)) retc=pCurEntry->WriteNode(m_lpOutFileObj);
#  else
      if(SUCCEEDED(retc)) retc=m_lpOutFileObj->WriteHeader(ColorTable, KpGmaxcc0);

      if(SUCCEEDED(retc)) retc=m_lpOutFileObj->PutKwrd(RT_TG_sl, -60); // "\\sl-60"
      if(SUCCEEDED(retc)) retc=m_lpOutFileObj->PutCharProc(C_Lf, True);
      if(SUCCEEDED(retc)) retc=m_lpOutFileObj->PutKwrd(RT_TG_sl, -260); // LZDSH_STY_LINE_SPACING_SMALL_CMD

      if(SUCCEEDED(retc)) retc=pCurEntry->WriteRtf(m_lpOutFileObj, (KpChar)XC_Dict,
         /* (KpChar)XC_FirstDictTag, */ (KpChar)XC_Nul, LZDSH_NUM_OF_PAR_STYLES, m_lpOutFileObj->GetFldDepth());

      if(SUCCEEDED(retc)) retc=m_lpOutFileObj->WriteTail();
#  endif

   }
#endif // #ifdef IBSH_RES_MODE_RTF

#ifndef IBSH_RES_MODE_RTF
   if(SUCCEEDED(retc))
#  ifdef IBSH_RES_MODE_MSHTML
#     if Compiler != Watcom
//    if(lzdsh_dlg->m_ResHtml) if(lzdsh_dlg->m_ResHtml->hwnd_)
#     endif
#  endif
   {
      if(SUCCEEDED(retc)) retc = m_lpOutFileObj->GetVersion(&vers);
      if(SUCCEEDED(retc)) retc = pCurEntry->InsertDelimiters(/* XC_FirstDictTag, XC_LastDictTag, */ vers);

      if(SUCCEEDED(retc)) retc = m_lpOutFileObj->Reset();

#  if TRUE // #if FALSE //
KpTreeEntry *cur_dict_entry = NULL;
const unsigned char *dict_name = (const unsigned char *)"";
int sel = lzdsh_dlg->m_iCurDictEntry;

      if(SUCCEEDED(retc))
         if(m_lpOutFileObj)
            if(m_lpOutFileObj->FilePtr)
               if(m_lpOutFileObj->FilePtr->m_fFiles)
      {
         if(lzdsh_dlg->m_DictList && SUCCEEDED(retc))
            retc = lzdsh_dlg->m_DictList->GetEntryPtr(&sel, &cur_dict_entry, 0, NULL);
         if(cur_dict_entry && SUCCEEDED(retc))
             dict_name = (const unsigned char *)(cur_dict_entry->GetValue());

#     if XM_IS_VERS_HTML(LZDSH_OUT_VERS)
         if(SUCCEEDED(retc)) m_lpOutFileObj->SetScale(10*iCurFontSize/iMainFontSize);
#     endif
         if(SUCCEEDED(retc))
         {
#     if LZDSH_OUT_VERS == XML_VERS_XML10
            retc = PutXmlHat(m_lpOutFileObj->FilePtr, (const unsigned char *)"lzdsht");
#     endif
#     if LZDSH_OUT_VERS == XML_VERS_HTML_TAGE // XML_VERS_HTML401_TRANS
            retc = PutHtmHat(m_lpOutFileObj->FilePtr->m_fFiles[0],
                                       (const unsigned char *)"" /* dict_name */, NULL,
                                       (const unsigned char *)((iCurFontSize<=iMainFontSize)?"tvxmlth.css":"tvxmlthx.css"), // iCurFontSize==22
                                       KP_LNG_LIT, 0, NULL, NULL);
#     endif
#     if LZDSH_OUT_VERS == XML_VERS_XHTML_TAGE // XML_VERS_XHTML
            retc = PutXhtmlHat(m_lpOutFileObj->FilePtr->fFiles[0],
                                       (const unsigned char *)"" /* dict_name */, NULL,
                                       (const unsigned char *)((iCurFontSize<=iMainFontSize)?"tvxmlth.css":"tvxmlthx.css"), // iCurFontSize==22
                                       KP_LNG_LIT, 0, NULL, NULL);
#     endif
            if(retc == KP_E_UNKN_CHR) retc = S_OK;
         }

         if(SUCCEEDED(retc))
         {
            retc = pCurEntry->WriteNode(m_lpOutFileObj);
            if(retc == KP_E_UNKN_CHR) retc = S_OK;
         }

         if(SUCCEEDED(retc))
         {
#     if LZDSH_OUT_VERS == XML_VERS_XML10
            retc = PutXmlTail(m_lpOutFileObj->FilePtr);
#     endif
#     if XM_IS_VERS_HTML(LZDSH_OUT_VERS)
            retc = PutHtmTail(m_lpOutFileObj->FilePtr->m_fFiles[0]);
#     endif
            if(retc == KP_E_FILE_FORMAT) retc = S_OK;
         }
      }

#  endif // #  if TRUE // #if FALSE //

// if(SUCCEEDED(retc)) retc=m_lpOutFileObj->Reset();

#  if FALSE // #if TRUE //
static int ii;
unsigned char str_buf[400];
      ii++;
      sprintf((char *)m_lpszResultFormatted, // (char *)str_buf,
         "<html><head>"
         "<title>MSHTMLTest</title>"
// "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">"
// "<meta content=\"text/html; charset=Windows-1257\">"
"<meta content=\"text/html; charset=Windows-1251\">"
         "</head><body>"
         "<h1>Kaka laka %d</h1>"
         "Àèæëáðøøûþ I offer the following links:"
         "<ul>"
         "<li><a href='http://www.google.com'>www.google.com</a>"
         "<li><a href='http://www.adp-gmbh.ch'>www.adp-gmbh.ch</a>"
         "<li><a href='http://www.yahoo.com'>www.yahoo.com</a>"
         "<li><a href='file://F:/kp/source/Tev/lzdsh/lzdsh2.htm'>lzdsh2.htm</a>"
         "</ul>"
         "</body></html>", ii);

// if(SUCCEEDED(retc)) /* retc = */ m_lpOutFileObj->FilePtr->fFiles[0]->PutStr(str_buf);
#  endif

// if(SUCCEEDED(retc)) retc=m_lpOutFileObj->PutStr((const unsigned char *)"kaka laka");
// if(SUCCEEDED(retc)) /* retc = */ m_lpOutFileObj->PutStr(dict_name);
// sprintf((char *)m_lpszResultFormatted, "%d", lzdsh_dlg->m_iCurDictEntry);
// m_lpszResultFormatted[0] = dict_name[0];
// m_lpszResultFormatted[1] = Nul;


// ----------------------------------------------------
#  ifdef Debug // #if FALSE // #if TRUE // 
#     ifndef TEST_GECKO_FROM_FILE

#ifdef IBSH_RES_MODE_XGECKO
   if(SUCCEEDED(retc)) if(m_pResBuf == NULL)
      retc=KpErrorProc.OutputErrorMessage(KP_E_NO_FILE, null, TRUE, __FILE__, __LINE__, 0L);
#endif

if(SUCCEEDED(retc))
{
fstream out_file(
#        if LZDSH_OUT_VERS == XML_VERS_XML10
   "lzdsh1.xml",
#        endif
#        if LZDSH_OUT_VERS == XML_VERS_HTML_TAGE // XML_VERS_HTML401_TRANS
   "lzdsh1.htm",
#        endif
#        if LZDSH_OUT_VERS == XML_VERS_XHTML_TAGE // XML_VERS_XHTML
   "lzdsh1.xhtml",
#        endif
   ios::out | ios::binary);
// out_file << m_lpszResultFormatted;
#        ifndef LZDSH_RES_CODING_UTF8
UniChar out_ch = 0xFEFF;
out_file.write((const char *)&out_ch, sizeof(out_ch));
#        endif

// out_file.write((const char *)m_lpszResultFormatted, LzdshtResLen(m_lpszResultFormatted)*sizeof(m_lpszResultFormatted[0]));
#ifdef LZDSH_RES_CODING_UTF8
out_file.write((const char *)m_pResBuf, LzdshtResLen((const unsigned char *)m_pResBuf));
#else
out_file.write((const char *)m_pResBuf, LzdshtResLen(m_pResBuf) * sizeof(m_pResBuf[0]));
#endif

out_file.close();
}
#     endif
#  endif

   }
#endif // #ifndef IBSH_RES_MODE_RTF


#ifdef LZDSHT_DISPLAY_SINGLE_THREAD
   lzdsh_dlg->m_bNewContentReady = True;
#else
   if(SUCCEEDED(retc)) retc = DisplayResult();
#endif

// turinys bus nuresetintas:
//    IBSH_RES_MODE_MSHTML - po iðvedimo dialogo threade theDialog
//    IBSH_RES_MODE_XGECKO - po paskutinio perskaitymo su XLzdshtStream::read()
//
// iðkelta á DisplayResult()
//    if(SUCCEEDED(retc)) retc=m_lpOutFileObj->Reset();
//    if(SUCCEEDED(retc)) memset(m_lpszResultFormatted, Nul, LZDSHT_RESULT_BUF_LEN*sizeof(m_lpszResultFormatted[0]));

return(retc);
}


// ----------------------------------
#if FALSE
HRESULT LzdShSearch::SearchForEntry
(
   KpPubDlg *pDialogPtrPar,
   const unsigned char *lpszFileName
   XmlO1 ** /* pInFilePtr */,
   unsigned char ** /* pEntryImgPtr */
)
{
HRESULT retc=S_OK;
long entry_id;
long offset;
long end_offset;
#  ifdef LZDSHT_ENCODED
unsigned char *entry_img=NULL;
long img_len;
#  else
XmlNode *cur_entry=NULL;
#  endif
#  ifdef LZDSH_EDITOR_BUILD
int retv;
#  endif
unsigned char cur_kwd[TV_XL_MAX_IX_LEN+1];
// unsigned char str_buf[KP_MAX_FILE_LIN_WDT+1];
int len;
long entry_id_sav;

KpPubDlg *lzdsh_dlg = pDialogPtrPar;
   KP_ASSERT(lzdsh_dlg != NULL, E_INVALIDARG, null, True);

   KP_ASSERT(m_lpInFileObj, KP_E_NO_FILE, null, True);
   KP_ASSERT(m_lpInFileObj->FilePtr, KP_E_NO_FILE, null, True);
   KP_ASSERT(m_lpOutFileObj, KP_E_NO_FILE, null, True);

   /* if(SUCCEEDED(retc)) retc = */ BlockSemaphore();

// strcpy(m_lpszCurSearchResult, m_lpszCurSearchKwd);

// ---------------
   if(SUCCEEDED(retc)) entry_id_sav=m_lCurEntryId;

// ---------------
   if(SUCCEEDED(retc))
   {
//    strcpy(m_lpszCurSearchWord, (const unsigned char *)m_lpszToSearch);

      strncpy(cur_kwd, m_lpszCurSearchKwd, TV_XL_MAX_IX_LEN);
      cur_kwd[TV_XL_MAX_IX_LEN]=Nul;
   }

   if((m_iCurIndexFile!=m_iIndexFile) && SUCCEEDED(retc)) // paieskai ivedus is klav. ir po visa teksta ieskoti numetant diakritus
   {
//    if(SUCCEEDED(retc)) retc=CvtToKwd(/* caIxLangs[m_iCurIndexFile] */);
      TvStrClearAccents(cur_kwd, lzdsh_dlg->m_iCtrlCtbl);
   }

   if(SUCCEEDED(retc))
   {
// KP_TRACE(m_lpszCurSearchKwd);
      retc=m_lpInFileObj->SearchEntryFirst(&entry_id, &offset, cur_kwd, m_iCurIndexFile, False);
      if(retc==KP_E_KWD_NOT_FOUND) retc=S_OK;
#  if FALSE // #ifdef Debug
sprintf((char *)str_buf, "%d %d", offset, retc);
KP_TRACE(str_buf);
#  endif
   }

   if(SUCCEEDED(retc)) if(entry_id!=entry_id_sav) && (lzdsh_dlg->m_MainList)
#  ifdef IBSH_RES_MODE_RTF
//       && (lzdsh_dlg->m_ResRichEdit))
#  endif
#  ifdef IBSH_RES_MODE_MSHTML
#     if Compiler != Watcom
//       && (lzdsh_dlg->m_ResHtml)) if(lzdsh_dlg->m_ResHtml->hwnd_)
#     else
         )
#     endif
#  endif
   {
      m_lCurEntryId=entry_id;

      if(SUCCEEDED(retc))
         retc=m_lpInFileObj->FilePtr->GetIndexSize(&end_offset, m_iCurIndexFile);

      if((offset<end_offset) && SUCCEEDED(retc))
      {
#  ifdef LZDSHT_ENCODED
         if((entry_img!=NULL) && SUCCEEDED(retc))
            retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
         if(SUCCEEDED(retc)) retc = m_lpInFileObj->ReadEntryImg(entry_id, &entry_img, &img_len);
         if((entry_img==NULL) && SUCCEEDED(retc))
            retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

         if(SUCCEEDED(retc)) retc = WriteRtfFromEncImg(entry_img, img_len, entry_id /* , m_lThreadId */);

// besàlygiðkai trint negalima – gali bûti uþsilikæs WriteRtfFromEncImg()
         if(SUCCEEDED(retc)) KP_DELETEA(entry_img);
#  else
         if(SUCCEEDED(retc)) retc=m_lpInFileObj->SeekEntry(entry_id);

         if((cur_entry!=NULL) && SUCCEEDED(retc))
            retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
         if(SUCCEEDED(retc)) retc=ReadEntry(&cur_entry, m_lpInFileObj, True);
         if((cur_entry==NULL) && SUCCEEDED(retc))
            retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

         if(SUCCEEDED(retc)) retc=FormatEntry(cur_entry);

#     ifdef LZDSH_EDITOR_BUILD
XmlNode *old_cur_entry = NULL;
         if(m_pCurEntry)
         {
            old_cur_entry = m_pCurEntry;
            m_pCurEntry = cur_entry;
            
            KP_DELETE(old_cur_entry);
         }
         m_pCurEntry = cur_entry;

         if(SUCCEEDED(retc))
         {
            retv = SendMessage(lzdsh_dlg->m_NodList, KP_LB_SETSTRINGLIST, 0, (LPARAM)pEntries);
            switch(retv)
            {
            case CB_ERR:
               retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
               break;
            case CB_ERRSPACE:
               retc=KpErrorProc.OutputErrorMessage(KP_E_OUTOFMEM, null, True, __FILE__, __LINE__, 0L, NULL);
               break;
            }
         }
#     else
         KP_DELETE(cur_entry);
#     endif
         cur_entry = NULL;
#  endif // #else // #ifdef LZDSHT_ENCODED

      } // if((offset<end_offset) && SUCCEEDED(retc))

#  ifndef LZDSHT_FULL_LIST
      if(SUCCEEDED(retc)) retc=UpdateList(offset);
#  endif
// kai persoka selektinant lista - nereikia
      if((m_iCurIndexFile!=m_iIndexFile) && SUCCEEDED(retc))
         retc = lzdsh_dlg->SelectList(offset);

   } // if((entry_id!=lCurEntryId) && SUCCEEDED(retc))

   /* if(SUCCEEDED(retc)) retc = */ ReleaseSemaphore();

return(retc);
}
#endif


HRESULT LzdShSearch::SearchForEntry
(
   KpPubDlg *pDialogPtrPar,
   const unsigned char * /* lpszFileName */,
   XmlO1 ** /* pInFilePtr */,
   unsigned char ** /* pEntryImgPtr */
)
{
HRESULT retc=S_OK;
long entry_id;
long offset;
long end_offset;
#ifdef LZDSHT_ENCODED
unsigned char *entry_img = NULL;
long img_len;
#else
XmlNode *cur_entry=NULL;
#endif
static KpChar *hw_ptr;
KpChar hw_buf[TV_XL_MAX_IX_LEN+1];
KpChar i_cur_hw[TV_XL_MAX_IX_LEN+1];
unsigned char cur_kwd[TV_XL_MAX_IX_LEN+1];
KpChar i_cur_kwd_entered[TV_XL_MAX_IX_LEN+1];
KpChar i_cur_kwd_found[TV_XL_MAX_IX_LEN+1];
unsigned char cur_kwd_found[TV_XL_MAX_IX_LEN+1];
long entry_id_sav;
int cur_kwd_len = 0;

KpPubDlg *lzdsh_dlg = pDialogPtrPar;
   KP_ASSERT(lzdsh_dlg != NULL, E_INVALIDARG, null, True);

   KP_ASSERT(m_lpInFileObj, KP_E_NO_FILE, null, True);
   KP_ASSERT(m_lpInFileObj->FilePtr, KP_E_NO_FILE, null, True);
   KP_ASSERT(m_lpOutFileObj, KP_E_NO_FILE, null, True);

   /* if(SUCCEEDED(retc)) retc = */ BlockSemaphore();

// strcpy(m_lpszCurSearchResult, m_lpszCurSearchKwd);

   if(SUCCEEDED(retc)) entry_id_sav = m_lCurEntryId;

// ------------------------
#if FALSE // #ifdef Debug //
// if(strcmp(m_lpszCurSearchKwd, "ab*")==0)
// entry_id_sav=m_lCurEntryId;

char str_buf[200];
sprintf(str_buf, ">>>%s<<< >>>%s<<<", m_lpszToSearch, m_lpszCurSearchKwd);
// KpMsgOut(str_buf, IDI_ASTERISK, KP_MB_TESTI);
KP_TRACE(str_buf);
#endif

   if(SUCCEEDED(retc))
   {
      strncpy(cur_kwd, m_lpszCurSearchKwd, TV_XL_MAX_IX_LEN);
      cur_kwd[TV_XL_MAX_IX_LEN] = Nul;

      retc = KptStrEncode(i_cur_kwd_entered, cur_kwd, lzdsh_dlg->m_iCtrlCtbl);
      if((retc==KP_E_UNKN_CHR) || (retc==KP_E_FONT_UNDEF)) retc=S_OK;
   }

   if(SUCCEEDED(retc)) strcpy(cur_kwd_found, cur_kwd);

   if(SUCCEEDED(retc))
   {
      i_cur_kwd_entered[TV_XL_MAX_IX_LEN] = C_Nul;

//    TvKpStrLat(i_cur_kwd_entered); // jei nuimam paukðèiukus, tada neskiria "auðti" - "austi"
//    TvKpStrLwr(i_cur_kwd_entered); // jau KpIndexEntryToCompareKpStr() nulowercasina

      retc = KpIndexEntryToCompareKpStr(i_cur_kwd_entered, i_cur_kwd_entered, False, False);
   }

   if(SUCCEEDED(retc)) cur_kwd_len = TvKpStrLen(i_cur_kwd_entered);

   if(SUCCEEDED(retc))
   {
// KP_TRACE(m_lpszCurSearchKwd);
      retc = m_lpInFileObj->SearchEntryFirst(&entry_id, &offset, cur_kwd, m_iCurIndexFile, False);
      if(retc == KP_E_KWD_NOT_FOUND) retc = S_OK;
#if FALSE // #ifdef Debug
unsigned char str_buf[100];
sprintf((char *)str_buf, "%d %d", offset, retc);
KP_TRACE(str_buf);
#endif
   }

// ------------------------ surandam pagrindiniam indekse
   if(SUCCEEDED(retc))
      retc = m_lpInFileObj->FilePtr->GetIndexSize(&end_offset, m_iCurIndexFile);

   if((offset<end_offset) && SUCCEEDED(retc))
   {
#ifndef LZDSHT_ENCODED
      if(SUCCEEDED(retc)) retc=m_lpInFileObj->SeekEntry(entry_id);
#endif

// ---------------
      if((m_iCurIndexFile!=m_iIndexFile) && SUCCEEDED(retc)) // paieskai ivedus is klav. ir po visa teksta ieskoti numetant diakritus
      {
         hw_ptr = NULL;
#ifdef LZDSHT_ENCODED
         if((entry_img != NULL) && SUCCEEDED(retc))
            retc = KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
         if(SUCCEEDED(retc)) retc = m_lpInFileObj->ReadEntryImg(entry_id, &entry_img, &img_len);
         if((entry_img == NULL) && SUCCEEDED(retc))
            retc = KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

         if(SUCCEEDED(retc)) retc=GetHwFromEncImg(&hw_ptr, entry_img, img_len, entry_id);
#else
         if((cur_entry!=NULL) && SUCCEEDED(retc))
            retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
         if(SUCCEEDED(retc)) retc=ReadEntry(&cur_entry, m_lpInFileObj, True);
         if((cur_entry==NULL) && SUCCEEDED(retc))
            retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

         if(SUCCEEDED(retc)) retc=cur_entry->GetHw(&hw_ptr);
#endif

#if FALSE // #ifdef Debug
unsigned char str_buf[200];
KptStrDecode(str_buf, hw_ptr, TvIntStrLen(hw_ptr), 80);
KP_TRACE(">>>");
KP_TRACE(str_buf);
KP_TRACE("<<<");
#endif

         if((hw_ptr!=NULL) && SUCCEEDED(retc))
         {
            if(TvKpStrLen(hw_ptr)>TV_XL_MAX_IX_LEN)
               retc=KpErrorProc.OutputErrorMessage(KP_E_BUFFER_OVERFLOW, null, TRUE, __FILE__, __LINE__, 0L);

            if(SUCCEEDED(retc))
            {
               TvKpStrNCpy(hw_buf, hw_ptr, TV_XL_MAX_IX_LEN);
               hw_buf[TV_XL_MAX_IX_LEN] = C_Nul;
               NormalizeHeadword(i_cur_hw, hw_buf);
               TvKpStrClearAccents(i_cur_hw);
               /* retc= */ KptStrDecode(cur_kwd_found, i_cur_hw, lzdsh_dlg->m_iCtrlCtbl);
               retc = KpIndexEntryToCompareKpStr(i_cur_hw, i_cur_hw, True, True);
            }

// pagrindiniam indexe pagal antraste ieskoti tik tada, jei rastas zodis yra antraste,
// jei variantas - pagal surinkta zodi (ELZ05e am = ante meridiem)
            if(SUCCEEDED(retc))
            {
               TvKpStrCpy(i_cur_kwd_found, i_cur_hw);
               TvKpStrLat(i_cur_kwd_found);
//             TvKpStrLwr(i_cur_kwd_found); // jau KpIndexEntryToCompareKpStr() nulowercasina
            }
            if(SUCCEEDED(retc))
            {
               i_cur_kwd_found[cur_kwd_len] = C_Nul;
#if FALSE // #ifdef Debug
unsigned char str_buf_0[200];
unsigned char str_buf_1[200];
KptStrDecode(str_buf_0, i_cur_kwd_entered, lzdsh_dlg->m_iCtrlCtbl);
KptStrDecode(str_buf_1, i_cur_kwd_found, lzdsh_dlg->m_iCtrlCtbl);
KP_TRACE_2("%s %s", str_buf_0, str_buf_1);
#endif
               if(TvKpStrCmp(i_cur_kwd_entered, i_cur_kwd_found) == 0)
               {
// rinktas zodis atitinka hw - kopijuojam tikslu
                  retc=KptStrDecode(cur_kwd, i_cur_hw, lzdsh_dlg->m_iCtrlCtbl);
                  if((retc==KP_E_UNKN_CHR) || (retc==KP_E_FONT_UNDEF)) retc = S_OK;
               }
            }

// ieskom pagrindiniam saraso indexe
            if(SUCCEEDED(retc))
            {
               retc=m_lpInFileObj->SearchEntryFirst(&entry_id, &offset, cur_kwd, m_iIndexFile, False);
               if(retc==KP_E_KWD_NOT_FOUND) retc=S_OK;
            }

         } // if((hw_ptr!=NULL) && SUCCEEDED(retc))

#ifdef LZDSHT_ENCODED
// besàlygiðkai trint negalima – gali bûti uþsilikæs GetHwFromEncImg()
         if(SUCCEEDED(retc)) KP_DELETEA(hw_ptr);
         if(SUCCEEDED(retc)) KP_DELETEA(entry_img);
#else
         KP_DELETE(cur_entry);
#endif

      } // if((m_iCurIndexFile!=m_iIndexFile) && SUCCEEDED(retc))

   } // if((offset<end_offset) && SUCCEEDED(retc))

// ------------------------- á m_HistList
#if FALSE
KP_TRACE_5("SearchForEntry(): hist. fl.: %s %s %s %s %s",
   (m_iToHistListFlags == LZDSH_HIST_NONE)?"NONE":"",
   (m_iToHistListFlags & LZDSH_HIST_DEPENDENT)?"DEPENDENT":"",
   (m_iToHistListFlags & LZDSH_HIST_INDEPENDENT)?"INDEPENDENT":"",
   (m_iToHistListFlags & LZDSH_HIST_TIMER)?"TIMER":"",
   (m_iToHistListFlags & LZDSH_HIST_IMMEDIATELY)?"IMMEDIATELY":"");
   (m_iToHistListFlags & LZDSH_HIST_FORCED_NONE)?"FORCED_NONE":"");
#endif

   if(SUCCEEDED(retc))
      if(
         (
            ((m_iToHistListFlags & LZDSH_HIST_DEPENDENT) && (lzdsh_dlg->m_CurList != lzdsh_dlg->m_HistList)) ||
            (m_iToHistListFlags & LZDSH_HIST_INDEPENDENT)
         ) &&
         (m_iToHistListFlags & (LZDSH_HIST_TIMER|LZDSH_HIST_IMMEDIATELY))
        )
   {
      if(m_iToHistListFlags & LZDSH_HIST_IMMEDIATELY)
      {
// KP_TRACE("SearchForEntry: m_lQuietTime = LZDSH_TIME_TO_HIST;");
         m_lQuietTime = LZDSH_TIME_TO_HIST;
      }
      else  // kai LZDSH_HIST_IMMEDIATELY, m_lpszToHistStr[] jau suformuotas, pavyzdþiui, ið HTML þodþio paspaudimo -
      {     // reikia palikt originalø þodá, ne tà, kurá realiai radom
// KP_TRACE_2("SearchForEntry(): m_lpszToHistStr:%s cur_kwd_found:%s", m_lpszToHistStr, cur_kwd_found);
         m_lpszToHistStr[KP_MAX_FILE_LIN_WDT]=Nul;
         strncpy((unsigned char *)m_lpszToHistStr, cur_kwd, KP_MAX_FILE_LIN_WDT); // cur_kwd_found
         m_lpszToHistStr[KP_MAX_FILE_LIN_WDT]=Nul;
KP_TRACE_("SearchForEntry: m_lpszToHistStr:%s", m_lpszToHistStr);
      }
   }
   m_iToHistListFlags = LZDSH_HIST_NONE;

// ------------------------ isvedam RTF/HTML
   if((entry_id!=entry_id_sav) && SUCCEEDED(retc))
   {
      m_lCurEntryId=entry_id;

      if(SUCCEEDED(retc))
         retc=m_lpInFileObj->FilePtr->GetIndexSize(&end_offset, m_iIndexFile); // buvo klaida - m_iCurIndexFile);

      if((offset<end_offset) && SUCCEEDED(retc))
      {
#ifdef LZDSHT_ENCODED
         if((entry_img!=NULL) && SUCCEEDED(retc))
            retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
         if(SUCCEEDED(retc)) retc=m_lpInFileObj->ReadEntryImg(entry_id, &entry_img, &img_len);
         if((entry_img==NULL) && SUCCEEDED(retc))
            retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

         if(SUCCEEDED(retc)) retc=WriteRtfFromEncImg(entry_img, img_len, entry_id /* , m_lThreadId */);
#else
         if(SUCCEEDED(retc)) retc=m_lpInFileObj->SeekEntry(entry_id);

         if((cur_entry!=NULL) && SUCCEEDED(retc))
            retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
         if(SUCCEEDED(retc)) retc=ReadEntry(&cur_entry, m_lpInFileObj, True);
         if((cur_entry==NULL) && SUCCEEDED(retc))
            retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

         if(SUCCEEDED(retc)) retc=FormatEntry(cur_entry);
#endif


#ifdef LZDSHT_ENCODED
// besàlygiðkai trint negalima – gali bûti uþsilikæs WriteRtfFromEncImg()
         KP_DELETEA(entry_img);
#else

// atnaujinam NodList
#  ifdef LZDSH_EDITOR_BUILD
//       /* if(SUCCEEDED(retc)) retc = */ BlockSemaphore(); // jau blokuota funkcijos pradzioj

         if(SUCCEEDED(retc)) retc = cur_entry->InitNodeStatus();
         if(SUCCEEDED(retc)) retc = cur_entry->SetTagHeadings(LZDSH_NUM_OF_PAR_STYLES, lzdsh_dlg->m_hDialogWindow);

//       /* if(SUCCEEDED(retc)) retc = */ ReleaseSemaphore();

#     if TRUE // FALSE
int retv;
         if(m_pCurEntry != NULL)
         {
            if(SUCCEEDED(retc))
               if(SendMessage(lzdsh_dlg->m_NodList, LB_RESETCONTENT, 0, 0L) == CB_ERR)
                  retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
            if(SUCCEEDED(retc))
            {
               retv = SendMessage(lzdsh_dlg->m_NodList, LB_INITSTORAGE, LZDSH_MAX_NUM_OF_EDIT_NODES,
                     LZDSH_MAX_NUM_OF_EDIT_NODES*LZDSH_MAX_EDIT_NODE_WDT);
               if((retv==LB_ERRSPACE) && SUCCEEDED(retc))
                  retc=KpErrorProc.OutputErrorMessage(KP_E_OUTOFMEM, GetLastError(), TRUE, __FILE__, __LINE__, 0L);
               if((retv==LB_ERR) && SUCCEEDED(retc))
                  retc=KpErrorProc.OutputErrorMessage(KP_E_ILLFUNC, GetLastError(), TRUE, __FILE__, __LINE__, 0L);
            }

XmlNode *old_cur_entry = m_pCurEntry;
            m_pCurEntry = cur_entry;
            KP_DELETE(old_cur_entry);
         }
         m_pCurEntry = cur_entry;

#        if FALSE // #ifdef Debug
if(cur_entry)
{
// KP_NEW(m_pCurEntry, XmlNode(cur_entry, NULL));
KP_NEW(m_pCurEntry, XmlNode(cur_entry, NULL, 1, cur_entry));
KP_DELETE(cur_entry);
cur_entry = m_pCurEntry;
}
#        endif

         if(SUCCEEDED(retc))
         {
            retv = SendMessage(lzdsh_dlg->m_NodList, KP_LB_SETSTRINGLIST, 0, (LPARAM)m_pCurEntry);
            switch(retv)
            {
            case CB_ERR:
               retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
               break;
            case CB_ERRSPACE:
               retc=KpErrorProc.OutputErrorMessage(KP_E_OUTOFMEM, null, True, __FILE__, __LINE__, 0L, NULL);
               break;
            }
         }
#     else
         if(m_pCurEntry != NULL)
         {
XmlNode *old_cur_entry = m_pCurEntry;
            m_pCurEntry = cur_entry;
            KP_DELETE(old_cur_entry);
         }
         m_pCurEntry = cur_entry;

         if(SUCCEEDED(retc)) retc = ResetListBoxContents(lzdsh_dlg->m_NodList, LZDSH_MAX_NUM_OF_EDIT_NODES, LZDSH_MAX_EDIT_NODE_WDT, True, cur_entry);
#     endif

#  else
         KP_DELETE(cur_entry);
#  endif // #ifdef LZDSH_EDITOR_BUILD
         cur_entry = NULL;

#endif // #else // #ifdef LZDSHT_ENCODED

      } // if((offset<end_offset) && SUCCEEDED(retc))

   } // if((entry_id!=lCurEntryId) && SUCCEEDED(retc))


// ------------------------ selektinam list'a
// KP_TRACE_2("SearchForEntry: entry_id:%d entry_id_sav:%d", entry_id, entry_id_sav);
   if((entry_id != entry_id_sav) && SUCCEEDED(retc))
   {

#ifndef LZDSHT_FULL_LIST
      if(SUCCEEDED(retc)) retc=UpdateList(offset);
#endif
// KP_TRACE_2("SearchForEntry: m_iCurIndexFile:%d m_iIndexFile:%d", m_iCurIndexFile, m_iIndexFile);
      if(
         (
// kai perðoka selektinant listà - nereikia ???
// ið tikrøjø èia atsiskiria ne ar ið viso selektinamas listas, o kuris bûtent listas selektinamas - MainList ar kiti (HistList)
// MainListe m_iCurIndexFile yra XL_IX_HwIndex, o HistListe (SearchListe) - XL_IX_HxIndex
// reikëtø keist á tiesioginá selektinamo listo tikrinimà !!!!
            (m_iCurIndexFile!=m_iIndexFile)
#ifdef IBSH_RES_MODE_XGECKO
// MainListà selektint reikia net ir esant HistListe tuo atveju, jei paselektinus HistListà keièiasi þodynas
            || lzdsh_dlg->m_bDictChanged
#endif
         ) && SUCCEEDED(retc))
      {
         retc = lzdsh_dlg->SelectList(offset);
#ifdef IBSH_RES_MODE_XGECKO
         lzdsh_dlg->m_bDictChanged = False;
#endif
      }

   } // if((entry_id!=lCurEntryId) && SUCCEEDED(retc))


   /* if(SUCCEEDED(retc)) retc = */ ReleaseSemaphore();

return(retc);
}


// ----------------------------------
#if FALSE
HRESULT LzdShSearch::StrCatToResultRtf(unsigned char *lpszInStr)
{
HRESULT retc=S_OK;

   if(lpszInStr==NULL)
      retc=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, True, __FILE__, __LINE__, 0L, NULL);

   if(SUCCEEDED(retc))
      if(strlen(m_lpszResultFormatted)+strlen(lpszInStr)>=LZDSHT_RESULT_BUF_LEN)
         retc=KpErrorProc.OutputErrorMessage(KP_E_BUFFER_OVERFLOW, null, True, __FILE__, __LINE__, 0L, NULL);

   if(SUCCEEDED(retc)) strcat(m_lpszResultFormatted, lpszInStr);

return(retc);
}
#endif


// ----------------------------------
#if FALSE
HRESULT LzdShSearch::StrCatToResultRtf(char *lpszInStr)
{
return(StrCatToResultRtf((unsigned char *)lpszInStr));
}
#endif


// ----------------------------------
#if FALSE
HRESULT LzdShSearch::ChrCatToResultRtf(unsigned char ucInChr)
{
HRESULT retc=S_OK;
unsigned char str_buf[10];

   str_buf[0]=ucInChr;
   str_buf[1]=Nul;

   if(SUCCEEDED(retc)) retc=StrCatToResultRtf(str_buf);

return(retc);
}
#endif


// ----------------------------------
#if FALSE
HRESULT LzdShSearch::CvtResultToRtf(void)
{
HRESULT retc=S_OK;
unsigned char str_buf[40];
const unsigned char *pnts;

   m_lpszResultFormatted[0]=Nul;

   if(SUCCEEDED(retc)) retc=StrCatToResultRtf("{\\rtf1\n");
   if(SUCCEEDED(retc)) retc=StrCatToResultRtf("{\\colortbl;\\red0\\green0\\blue0;\\red0\\green0\\blue255;\\red0\\green255\\blue255;\\red0\\green255\\blue0;\\red255\\green0\\blue255;\\red255\\green0\\blue0;\\red255\\green255\\blue0;\\red255\\green255\\blue255;\n");
   if(SUCCEEDED(retc)) retc=StrCatToResultRtf("\\red0\\green0\\blue128;\\red0\\green128\\blue128;\\red0\\green128\\blue0;\\red128\\green0\\blue128;\\red128\\green0\\blue0;\\red128\\green128\\blue0;\\red128\\green128\\blue128;\\red192\\green192\\blue192;}");

   if(SUCCEEDED(retc))
   {
      pnts=m_lpszCurSearchResult;
      while((*pnts) && SUCCEEDED(retc))
      {
         if(SUCCEEDED(retc)) retc=StrCatToResultRtf("{\\cf");
         if(SUCCEEDED(retc))
         {
            sprintf((char *)str_buf, "%d ", rand()*16/RAND_MAX);
            retc=StrCatToResultRtf(str_buf);
         }

         if(SUCCEEDED(retc)) retc=ChrCatToResultRtf(*pnts++);

         if(SUCCEEDED(retc)) retc=StrCatToResultRtf("}");
      }
   }

   if(SUCCEEDED(retc)) retc=StrCatToResultRtf("}\n");

return(retc);
}
#endif


//-------------------------------------
#if FALSE
unsigned char lpszTestRtf[] = {
"{\\rtf1\\ansi\\ansicpg1252\\uc1 \\deff0\\deflang1033\\deflangfe1033{\\fonttbl{\\f0\\froman\\fcharset186\\fprq2{\\*\\panose 02020603050405020304}Times New Roman;}{\\f71\\froman\\fcharset0\\fprq2 Times New Roman;}{\\f69\\froman\\fcharset238\\fprq2 Times New Roman CE;}"
"{\\f70\\froman\\fcharset204\\fprq2 Times New Roman Cyr;}{\\f72\\froman\\fcharset161\\fprq2 Times New Roman Greek;}{\\f73\\froman\\fcharset162\\fprq2 Times New Roman Tur;}{\\f74\\froman\\fcharset177\\fprq2 Times New Roman (Hebrew);}"
"{\\f75\\froman\\fcharset178\\fprq2 Times New Roman (Arabic);}}{\\colortbl;\\red0\\green0\\blue0;\\red0\\green0\\blue255;\\red0\\green255\\blue255;\\red0\\green255\\blue0;\\red255\\green0\\blue255;\\red255\\green0\\blue0;\\red255\\green255\\blue0;\\red255\\green255\\blue255;"
"\\red0\\green0\\blue128;\\red0\\green128\\blue128;\\red0\\green128\\blue0;\\red128\\green0\\blue128;\\red128\\green0\\blue0;\\red128\\green128\\blue0;\\red128\\green128\\blue128;\\red192\\green192\\blue192;}{\\stylesheet{"
"\\ql \\li0\\ri0\\widctlpar\\aspalpha\\aspnum\\faauto\\adjustright\\rin0\\lin0\\itap0 \\fs24\\lang2057\\langfe1033\\cgrid\\langnp2057\\langfenp1033 \\snext0 Normal;}{\\*\\cs10 \\additive Default Paragraph Font;}}{\\info{\\title AAAAAAAA BBBBBBB}{\\author a}{\\operator a}"
"{\\creatim\\yr2007\\mo5\\dy30\\hr8\\min53}{\\revtim\\yr2007\\mo5\\dy30\\hr9\\min2}{\\version1}{\\edmins9}{\\nofpages1}{\\nofwords0}{\\nofchars0}{\\*\\company a}{\\nofcharsws0}{\\vern8269}}\\paperw11906\\paperh16838 "
"\\widowctrl\\ftnbj\\aenddoc\\noxlattoyen\\expshrtn\\noultrlspc\\dntblnsbdb\\nospaceforul\\formshade\\horzdoc\\dgmargin\\dghspace180\\dgvspace180\\dghorigin1701\\dgvorigin1984\\dghshow1\\dgvshow1"
"\\jexpand\\viewkind4\\viewscale150\\pgbrdrhead\\pgbrdrfoot\\splytwnine\\ftnlytwnine\\htmautsp\\nolnhtadjtbl\\useltbaln\\alntblind\\lytcalctblwd\\lyttblrtgr\\lnbrkrule \\fet0\\sectd \\linex0\\headery708\\footery708\\colsx708\\endnhere\\sectlinegrid360\\sectdefaultcl "
"{\\*\\pnseclvl1\\pnucrm\\pnstart1\\pnindent720\\pnhang{\\pntxta .}}{\\*\\pnseclvl2\\pnucltr\\pnstart1\\pnindent720\\pnhang{\\pntxta .}}{\\*\\pnseclvl3\\pndec\\pnstart1\\pnindent720\\pnhang{\\pntxta .}}{\\*\\pnseclvl4\\pnlcltr\\pnstart1\\pnindent720\\pnhang{\\pntxta )}}{\\*\\pnseclvl5"
"\\pndec\\pnstart1\\pnindent720\\pnhang{\\pntxtb (}{\\pntxta )}}{\\*\\pnseclvl6\\pnlcltr\\pnstart1\\pnindent720\\pnhang{\\pntxtb (}{\\pntxta )}}{\\*\\pnseclvl7\\pnlcrm\\pnstart1\\pnindent720\\pnhang{\\pntxtb (}{\\pntxta )}}{\\*\\pnseclvl8\\pnlcltr\\pnstart1\\pnindent720\\pnhang"
"{\\pntxtb (}{\\pntxta )}}{\\*\\pnseclvl9\\pnlcrm\\pnstart1\\pnindent720\\pnhang{\\pntxtb (}{\\pntxta )}}\\pard\\plain \\ql \\li0\\ri0\\widctlpar\\aspalpha\\aspnum\\faauto\\adjustright\\rin0\\lin0\\itap0 \\fs24\\lang2057\\langfe1033\\cgrid\\langnp2057\\langfenp1033 {"
"\\lang1033\\langfe1033\\langnp1033 AAAAAAAA{\\*\\shppict{\\pict{\\*\\picprop\\shplid1025{\\sp{\\sn shapeType}{\\sv 75}}{\\sp{\\sn fFlipH}{\\sv 0}}{\\sp{\\sn fFlipV}{\\sv 0}}{\\sp{\\sn pibName}{\\sv F:\\'5ckp\\'5csource\\'5c"
"Tev\\'5cmcm\\'5cpvz.bmp}}{\\sp{\\sn pibFlags}{\\sv 2}}{\\sp{\\sn fLine}{\\sv 0}}{\\sp{\\sn fLayoutInCell}{\\sv 1}}}\\picscalex100\\picscaley100\\piccropl0\\piccropr0\\piccropt0\\piccropb0"
"\\picw4498\\pich4366\\picwgoal2550\\pichgoal2475\\pngblip\\bliptag-1956003341{\\*\\blipuid 8b69c1f3db24693a7dbbc8a659832d90}89504e470d0a1a0a0000000d49484452000000aa000000a508020000004342f100000000017352474200aece1ce9000000097048597300000ec400000ec40195"
"2b0e1b0000082749444154785eed9d8b72dc200c459bfeff3fa7de25a1accd432f4012ca743a690730d2d11502b3c9d7f7f7f79ff83ad5037f4f353cec7e7920"
"f01f1d07813ff01fed81a38d0ff507fea33d70b4f18ad4fff5f575348a1dc62bc2bfc3fcd39fa905ff25fd38805a1f8c5af0afb73c9e787960bfe6d2921fd2df"
"128ea1fe156e575bd5aac07f495fad83f8d1a1b9ac51819fef62b5236866bfff954f16bdcb04a09cfd7efc6a55cb9f987ef69bf19b70102d0eac98a668ed7793"
"ffadb0dfa97e433e4225005b7629527f3afc79ee00afffc95f8944fa278aca9ac6b6d86f533fca4de940f0fabb3c1954784a88326a4d380e9fa24bfdad04a0bf"
"2cb0c87e8ffa999e5298f699160d353aaf813af5435eff28ccfcf3084d1d79357eb250d4e67fb24553b902075f8d1f38ad56336dbed6361fac7b57e3e7e46d4e"
"5fac5f20edadb3df53fa413cabbf8d03f6c6f0ebf1b89e993075b23af9d3a6abea98cf0dfbd7f9e9f605d596376dcd7628361bea1f9ab1a68133f6c6d6fe358c"
"adec3945bc8150bfc2d35611174006f1a7fb643502bfda7337083f4e1bafec71f8391eb4dbd7317b34fed312806ff668fc76454c98b97bf614fc87248013d853"
"f05f7ddc47c021ec89f80989d4509773d8d3f1bb4f0086e2953355c4be9ff3182b7d8f923e5dfd2e2b802decd3cbcc5d27aadc377e7c97f14710492deba79190"
"ef7de31ac9ff153c1cf604e126b9df3eb82212c4d841b8f81dd48034f645d2c6fd681225e0d1af7c5a91653a0208ec7f97eaeba367e90ff42b8b1eda617e3bae"
"fad30c8d46008d3d967a72912ad1e7b892c13f3f4ce59f80655f88fe369941f9ac50f4f2f86d250014fbcf6c8f0b449da297c76f6809c0b2ef66fb9ef4510fc2"
"8595506be1e4af3f07a090bc37759de2aec95e73c22f234718bff21c0067df5ee9b3f77aec35ece92109421ebfda0840b11f95f775f656443f65ed2fc34dff2a"
"d012c728e1bf3671d5935ae5555ed5de29ea57781800913e20e10fd843f2adaa3613f1eb590580ec4709bfcede5cc29f5bfadda27bfb2a8061df51e6b505a8e4"
"7c8b097f29febd39408afdb392372dfae9a59f861c20c8fe7eccabe3752dbf8c98bbf66fdc0b0cd9030abd5ec2e7bb5ec308dcdb3e581bdedbaa8f2b2e434ed8"
"47bc2ab4d1ef05a3edee9e9327cc4d559775eacfbbc1d9c5209bbdcf2a6ff5bebf13e62902929864bf78ec7fc03f4f7586c3ca5ab16cb4d5c9ff5943ddd6028e"
"e54348ed9cdfbc75e92fe1afdef8f5d3405aaa39d4817d1bec9b8acf35c4decbb840eb68cd36ab3fbb384700d9d77de93fd8ff045ce771c35c42f3b8aa5e5af0"
"67a7d0922d98fd987ace46e4405405b83f1975f8d374cbe56088a1c3feb6ac0c87cad9c81042ce5495e22f4dea232cd9b76a0808f51c76f0c61cbf2be96b007f"
"75b350775f792feb0bf7f929daa2a38422791af6f07f5409ad7b7878f647893efb70f5a91f394e2b3920d8b3bd6912ff2b514bb04f278f67ea3e458e49fccda0"
"c7e4fc04fe64f626f137a58f67cfce9de60730a67e3efb48f865cc5ac22fc23e12be49fc4cf621faea426543fd7cf6217aabf845d89b2fd2e6186043fd15db01"
"757e24fc61cc68c75f973e8c7d247cdbf899ec87c64703bdeaa7b18f848f8a69a5f8c9ec23e17bc08fadf542f428eaaa5ff856a4dfadf5e2e50d8dbdc6573e28"
"f6217a32788d2f7cb1ec63a57785ff6e4c3be71f7e4d83495de3da7f977e837d247c29f68ad67e38fb48f882f8f7df74fbb99c3fbaa37de645ec447a9eedfaf0"
"3f72fe3ce30565b460a81f9d88fefe171df8b3f46bec0fbf8df90c2cc138d084ff937d887e9851f871b019ffff85ffc13e443fc49f1b90e34007fedff58c6c06"
"dc53be5b6253e6e0b711f8769627eb68c95297fa3df1d86b4bcea3d7347a3fc184163522b6a583db38bee53bb3849d460362dda6fe4c3df063f1936157f690c0"
"30c14eb1dfbe441ef881be9d51176f50ff8d77e007e29fd16cc35dbf2df96686ef1c8cb901bf03afb93121f0bb41493124f07f7a6dc98f97a5809ad327f0fffa"
"f5029fd8e76fe6785cd5a881ff8de329fa1404de9341e057a5c6d59309fc35e997145ca781c00f169cc7b520f0bf5e8f8043e0b730f49212023f027da5a9f1da"
"30f0bf995e090095039ec5012f8a76f50efc85e78711d06960330d04fe4fe1a534d0c26c937127b504fe8673ca201866853486c1e008fcdd65370701a738d8b5"
"b0039e1bf8014eca4ddc05c186db3e377f5bbdedd34af5c095021375cfb6b78bbce47b60a17e1e87b27702bfa402c837a6d237e5df287b8ec19f5fe6a2dc836a"
"bc047cb110fd3fac2467d003f0a703da4b256bf1a02287d6387d4a82ccfe7aa877fc1979f9cdd497374bd67e5ab83c7b79c75fc2b881e104c1d6ba2f53cc15df"
"f3831fc0f8f08e3fa5fdceb18cec8a203b1a8021f3271d79c70f29c5973303601d34494bfe6f54bfbe29ff073ebef77d7f1fedad1e842fdbd561e1dde17c26b7"
"f4aefe3e92ea0d4fb2c70d6611eff8df6722d077f9c0b3011d751f394acb8e07e04fe6c28320970b391aca3d4247e2a17e91909c38087c797e6602ce4671a249"
"aca18f517f71580a5d0b6e8e1d86ceb0018bd494cee7e1cf6b01d69fc34d04764005ed4fc5dfa9060c8a981c4807e327fbecd9d16cc41c8f3fdfedec9f0d7762"
"c52cfbcba6e3f1975cab37fbfa742db30ffc3551e793e0140da9e27b1e1ba00e1204171ad1a1bc9ff98b3acbdf6091fcfd31455814f811cef2d734f0fb638ab0"
"28f0239ce5af69e0f7c7146151e04738cb5fd3c0ef8f29c2a2c08f7096bfa681df1f538445811fe12c7f4d03bf3fa6088b023fc259fe9a067e7f4c1116ed7fe3"
"87986c3495f640a85fdaa3a6c60bfca670494f36f04b7bd4d47881df142ee9c9067e698f9a1a2ff09bc2253dd97ff17a5a482582d0db0000000049454e44ae426082}}{\\nonshppict{\\pict\\picscalex100\\picscaley100\\piccropl0\\piccropr0\\piccropt0\\piccropb0"
"\\picw4498\\pich4366\\picwgoal2550\\pichgoal2475\\wmetafile8\\bliptag-1956003341\\blipupi96{\\*\\blipuid 8b69c1f3db24693a7dbbc8a659832d90}"
"01000900000346a50000000022a5000000000400000003010800050000000b0200000000050000000c02a500aa000500000007010400000022a50000430f2000"
"cc000000a500aa0000000000a500aa000000000028000000aa000000a50000000100180000000000004a0100c40e0000c40e00000000000000000000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffff0000ffffffffffffffffffff0000ff0000ffffffffffffff0000ff0000ff0000ff0000ffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffff0000ffffffffffffff0000ff0000ffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000"
"ff0000ff0000ff0000ff0000ffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000"
"ff0000ff0000ff0000ff0000ffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000"
"ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000"
"ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000"
"ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000"
"ff0000ff0000ff0000ff0000ff0000ff0000ffffffff0000ffffffff0000ff0000ff0000ffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000"
"ff0000ff0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000"
"ff0000ff0000ffffffff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffff0000ff0000"
"ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000000000ffffff0000"
"00000000000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffff"
"ff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ffffffff0000ff0000ff0000ff0000ff0000ff0000ffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000000000000000"
"00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000000000"
"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ffffffff0000ff0000ffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000000000"
"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff0000ffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffff"
"ff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff"
"0000ff0000ffffffff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffff"
"ffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000000000000000ffff"
"ff000000000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffff0000ff0000ffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff"
"0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000"
"ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000"
"ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffff0000ff0000ff0000ff0000ff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffff0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000000000ffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000000000000000000000000000000000"
"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ff000000000000000000000000000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000"
"000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffff000000000000000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000"
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
"00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000"
"000000ffffffffffff000000000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000"
"00ff00000000ffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ff000000000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"00ff0000ff00000000ffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000000000000000"
"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"00ff0000ff0000ff00000000ffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000000000ffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"00000000ff0000ff0000ff00000000ffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000000000ffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"00000000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffff00000000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffff00000000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffff00000000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffff000000000000ff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffff00"
"0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000ff0000ff00000000ffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000ff0000ff00000000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000ff0000ff00000000ff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000ff0000ff0000"
"0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000ff0000"
"ff00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000ff0000"
"ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000"
"ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000ff0000"
"ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000ff0000"
"ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000"
"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000ff0000ff0000"
"ff0000ff0000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000000000000000000000000000000000"
"000000000000000000ff0000ff0000ff0000ff00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000000000000000000000ffffffffffffffffffffffffffffff000000ff"
"ffffffffffffffff000000000000000000000000000000000000000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffff000000000000000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00"
"0000ffffffffffffffffffffffffffffffffffffffffffffffff000000000000000000000000000000ffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ff0000ff0000000000000000000000ffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffff000000000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ff0000ff0000ff0000ff0000000000000000000000ffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ff0000ff0000ff0000ff0000ff0000ff00000000000000"
"00ffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ff0000ff0000ff0000ff0000ff0000ff0000ff00"
"00000000000000ffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ff0000ff0000ff0000ff0000ff0000ff00"
"00ff0000ff0000000000000000ffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ff0000ff0000ff0000ff0000ff00"
"00ff0000ff0000ff0000ff0000000000000000ffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ff0000ff0000ff0000ff00"
"00ff0000ff0000ff0000ff0000ff0000ff0000000000ffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ff0000ff00"
"00ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000000000ffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ff00"
"00ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000ffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000"
"00ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000ffffffffffffffffffffffffffffffffffff000000000000ffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ff000000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000000000ffffffffffffffffffffffffffffffffffff000000ffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffff000000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000ffffffffffffffffffffffffffffffffffff000000"
"000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffff000000000000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000ffffffffffffffffffffffffffffffffffff"
"ffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffff000000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000ffffffffffffffffffffffffffffff"
"ffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffff000000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000ffffffffffffffffffffffff"
"ffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffff000000000000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000ffffffffffffffffff"
"ffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffff000000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000ffffffffffff"
"ffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000ffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ff0000ff0000ff0000ff0000ff0000ff0000ff0000ff0000000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ff0000ff0000ff0000ff0000ff0000ff0000000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ff0000ff0000ff0000ff0000ff0000ff0000"
"000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ff0000ff0000ff0000ff0000"
"000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000"
"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000"
"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000000000ff0000"
"000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000"
"0000000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000000000ffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000ffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffff000000ffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffff000000ffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffff000000"
"ffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffff000000ffffffffffff000000000000ffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffff000000"
"ffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffff000000ffffffffffffffffff000000ffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffff000000"
"ffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffff000000ffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffff000000"
"ffffffffffffffffffffffff000000ffffffffffffffffffffffffffffff000000000000000000000000ffffffffffff000000000000ffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffff000000"
"ffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffff000000"
"ffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffff000000"
"ffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000"
"ffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000000000"
"ffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"ffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000000"
"000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffff000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000ffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
"ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff000005000000070101000000030000000000}}BBBBBBB"
"\\par }}"
};
#endif


// ----------------------------------
#if TRUE // #ifdef IBSH_RES_MODE_RTF
HRESULT LzdShSearch::DisplayResult(void)
{
HRESULT retc=S_OK;

// KP_TRACE("LzdShSearch::DisplayResult()");

   LZDSH_DLG_PTR_INIT;

#ifdef IBSH_RES_MODE_XGECKO
// #if Compiler != Watcom
   KP_ASSERT(lzdsh_dlg->m_pResCtrl != NULL, KP_E_SYSTEM_ERROR, null, True);
// #endif
#endif

   /* if(SUCCEEDED(retc)) retc = */ BlockSemaphore();

#if TRUE // #ifndef Debug
// ----------------------------
#  ifdef IBSH_RES_MODE_RTF
// strcpy(m_lpszResultFormatted, "Kaka laka\n");

// KpMsgOutF_1("KpSetCtrlRtfText(): %d", GetCurrentThreadId());

   if(SUCCEEDED(retc)) retc = KpSetCtrlRtfText(lzdsh_dlg->m_ResRichEdit, (unsigned char *) /* lzdsh_dlg-> */ m_pResBuf /* m_lpszResultFormatted */, True /* False */);
// if(SUCCEEDED(retc)) retc = KpSetCtrlRtfText(lzdsh_dlg->m_ResRichEdit, lpszTestRtf, True /* False */);
#  endif

// ------------------------------- numetam UTF-16 failo kepuræ (du baitus) - tai kad nebûna
#  if FALSE // #  ifndef IBSH_RES_MODE_RTF
   if(SUCCEEDED(retc)) if((m_lpszResultFormatted[0] == 0xFF) && (m_lpszResultFormatted[1] == 0xFE))
      memcpy(m_lpszResultFormatted, m_lpszResultFormatted+2,
         (LzdshtResLen(m_lpszResultFormatted) + 1) * sizeof(m_lpszResultFormatted[0]));
#  endif

// ----------------------------
#  ifdef IBSH_RES_MODE_MSHTML
#     if Compiler != Watcom
// static string out_str = (const char *)m_lpszResultFormatted;
// if(SUCCEEDED(retc)) if(lzdsh_dlg->m_ResHtml != NULL) lzdsh_dlg->m_ResHtml->HTML(out_str);
   if(SUCCEEDED(retc)) if(lzdsh_dlg->m_ResHtml != NULL) lzdsh_dlg->m_ResHtml->HTML(/* (const char *) */ /* lzdsh_dlg-> */ m_pResBuf); // m_lpszResultFormatted);
// if(SUCCEEDED(retc)) if(lzdsh_dlg->m_ResHtml != NULL) lzdsh_dlg->m_ResHtml->URL("file://F:/kp/source/Tev/lzdsh/lzdsh1.htm");
#     endif
#  endif

// ----------------------------
#  ifdef IBSH_RES_MODE_XGECKO
#     if Compiler != Watcom

#if TRUE // #ifndef LZDSHT_DISPLAY_SEARCH_THREAD
   if(SUCCEEDED(retc)) lzdsh_dlg->DisplayResult();

   if(SUCCEEDED(retc)) lzdsh_dlg->m_pResCtrl->setVisible(true);
#endif

#     endif

#     if FALSE
   if(SUCCEEDED(retc)) SetTimer(lzdsh_dlg->m_hDialogWindow, KP_POLL_TIMER, 1000, NULL); // KP_POLL_TIMER jau uþimtas !!!
#     endif
#  endif
#endif

#ifdef Debug
#ifdef IBSH_RES_MODE_XGECKO
   KP_ASSERT(lzdsh_dlg->m_pResBuf != NULL, KP_E_NO_FILE, null, True);
#endif
if(SUCCEEDED(retc))
{
FILE *out_file=fopen("DisplayResult.rtf", "w");
fputs((const char *)lzdsh_dlg->m_pResBuf /* m_lpszResultFormatted */, out_file);
fclose(out_file);
}
#endif

#ifndef IBSH_RES_MODE_XGECKO // turinys bus nuresetintas po paskutinio perskaitymo su XLzdshtStream::read()
      if(SUCCEEDED(retc)) retc=m_lpOutFileObj->Reset();

//    if(SUCCEEDED(retc)) memset(m_lpszResultFormatted, Nul, LZDSHT_RESULT_BUF_LEN * sizeof(m_lpszResultFormatted[0]));
      if(SUCCEEDED(retc)) memset(/* lzdsh_dlg-> */ m_pResBuf, Nul, LZDSHT_RESULT_BUF_LEN * sizeof(/* lzdsh_dlg-> */ m_pResBuf[0]));
#endif

// nustatom postponinimo skaitiklá
      if(SUCCEEDED(retc)) // if(lzdsh_dlg->m_bDiagOnTop /* && lzdsh_dlg->m_hDialogWindow */) // ne vien BringToTop()
      {
//       retc = lzdsh_dlg->BringToTop(lzdsh_dlg->m_bDiagOnTop); // èia irgi dar per anksti, iðkelta á LzdShDialogProc() WM_TIMER m_RedrawTimer
// PutLogMessage_("DisplayResult(): %d", lzdsh_dlg->m_bDiagOnTop);
         if(lzdsh_dlg->m_iDiagOnTopCnt > 0) // nustatinëjam tik pirmà kartà, këlimas á virðø po kiekvieno refreshinimo numuða tuo metu vartotojo galimai selektinamà m_DictBox
            lzdsh_dlg->m_iDiagOnTopCnt = 2000 / KP_REDRAW_TIMEOUT; // inicijuojam BringToTop() ir kt. po 2 sec.
      }

   /* if(SUCCEEDED(retc)) retc = */ ReleaseSemaphore();

return(retc);
}
#endif


// ----------------------------------
#ifdef LZDSH_EDITOR_BUILD
#if FALSE // #ifdef Debug
HRESULT LzdShSearch::DisplayRtfTestResult(void)
{
HRESULT retc=S_OK;

   LZDSH_DLG_PTR_INIT;

#if TRUE // #ifndef Debug
   if(SUCCEEDED(retc)) retc = KpSetCtrlRtfText(lzdsh_dlg->m_ResRichTest, m_lpszTestRtfText, True /* False */);
#endif

return(retc);
}
#endif
#endif


// ----------------------------------
HRESULT LzdShSearch::SearchAndDisplay(void)
{
HRESULT retc=S_OK;
// long entry_id_sav;

#if FALSE // #ifdef Debug
char str_buf[100];
sprintf(str_buf, "SearchAndDisplay() enter [%d]", iDictBoxStep);
KP_TRACE(str_buf);
if(iDictBoxStep==4)
   iDictBoxStep=4;
if(iDictBoxStep==1)
   iDictBoxStep=1;
#endif

   LZDSH_DLG_PTR_INIT;

   /* if(SUCCEEDED(retc)) retc = */ BlockSemaphore();

   if(SUCCEEDED(retc))
   {

#if FALSE // #ifdef Debug
static int ii;
char str_buf[100];
sprintf(str_buf, "SearchAndDisplay()[%d][%d]", ii++, iDictBoxStep);
KP_TRACE(str_buf);
#endif

      if(
         (
            (m_lCurEntryId<0L) ||
            (strcmp((const unsigned char *)m_lpszToSearch, m_lpszCurSearchWord))
         ) &&
         (lzdsh_dlg->m_MainList)
#ifdef IBSH_RES_MODE_RTF
//       && (lzdsh_dlg->m_ResRichEdit)
         )
#else
#  ifdef IBSH_RES_MODE_MSHTML
#     if Compiler != Watcom
        ) //       && (lzdsh_dlg->m_ResHtml)) if(lzdsh_dlg->m_ResHtml->hwnd_)
#     else
        )
#     endif
#  else
        )
#  endif
#endif
      {
// KP_TRACE_2("SearchAndDisplay: m_lpszToSearch:%s m_lpszCurSearchWord:%s", m_lpszToSearch, m_lpszCurSearchWord)

// KP_TRACE("SearchAndDisplay: m_lQuietTime=0L;");

         m_lQuietTime = 0L;

         m_iCurIndexFile = m_iIndexFile;
         if(lzdsh_dlg->m_bKbdInput)
         {
            m_iCurIndexFile = XL_IX_HwIndex;
            lzdsh_dlg->m_bKbdInput = False;
         }

         strcpy(m_lpszCurSearchWord, (const unsigned char *)m_lpszToSearch);

#if FALSE // #ifdef Debug //
char str_buf[200];
sprintf(str_buf, "---%s--- %d %c", m_lpszCurSearchWord, m_iCurIndexFile, caIxLangs[m_iCurIndexFile]);
KP_TRACE(str_buf);
#endif
         if(SUCCEEDED(retc)) retc=CvtToKwd(/* caIxLangs[m_iCurIndexFile] */);

#if FALSE // #ifdef Debug //
// char str_buf[200];
sprintf(str_buf, "+++%s+++", m_lpszCurSearchKwd);
KP_TRACE(str_buf);
#endif
         if((m_lCurEntryId<0L) || (strcmp(m_lpszCurSearchKwd, m_lpszCurSearchKwdPrev)!=0))
         {
#if FALSE // #ifdef Debug //
unsigned char str_buf[100];
sprintf((char *)str_buf, "%d", m_lCurEntryId);
KP_TRACE(str_buf);
#endif
            strcpy(m_lpszCurSearchKwdPrev, m_lpszCurSearchKwd);

//          entry_id_sav=m_lCurEntryId;

            if(SUCCEEDED(retc)) retc = SearchForEntry(lzdsh_dlg);

//          if((entry_id_sav!=m_lCurEntryId) && SUCCEEDED(retc))
            {
//             if(SUCCEEDED(retc)) retc=CvtResultToRtf();

#if FALSE
unsigned char str_buf[100+1];
const unsigned char *pnts;
unsigned char *pntd;
int ii;
pnts=m_lpszResultFormatted;
pntd=str_buf;
for(ii=0; (ii<100) && (*pnts) && SUCCEEDED(retc); ii++)
{
if(strchr(lpszSpcEol, *pnts)) *(pntd++)=Spc;
else *(pntd++)=(*pnts);
pnts++;
}
*pntd=Nul;

KP_TRACE(str_buf);
#endif

// isveda jau SearchForEntry()
//             if(SUCCEEDED(retc)) retc=DisplayResult();

            } // if((entry_id_sav!=lCurEntryId) && SUCCEEDED(retc))

         } // if(strcmp(m_lpszCurSearchKwd, m_lpszCurSearchKwdPrev)!=0)

         m_iCurIndexFile=m_iIndexFile;

      } // if(strcmp((const unsigned char *)m_lpszToSearch, m_lpszCurSearchWord)!=0)

   } // if(SUCCEEDED(retc))

   /* if(SUCCEEDED(retc)) retc = */ ReleaseSemaphore();

// KP_TRACE("SearchAndDisplay() exit");

return(retc);
}


// ----------------------------------
HRESULT LzdShSearch::ProcSearch(void)
{
HRESULT retc=S_OK;
unsigned char updated_inp_str[KP_MAX_FILE_LIN_WDT+1];
const unsigned char *prev_list_str;
const unsigned char *cur_list_str;
// unsigned char new_inp_str[KP_MAX_FILE_LIN_WDT+1];
// HCURSOR cur_sav=NULL;
int retv;
KpTreeEntry *search_list=NULL;
KpTreeEntry *search_list_ptr=NULL;
KpTreeEntry *next_entry=NULL;

   LZDSH_DLG_PTR_INIT;

   KP_ASSERT(lzdsh_dlg->m_SearchList != NULL, KP_E_SYSTEM_ERROR, null, True);

   KP_ASSERT(m_lpInFileObj != NULL, KP_E_NO_FILE, null, True);
   KP_ASSERT(m_lpInFileObj->aiFileIndexLengthsPtr != NULL, KP_E_SYSTEM_ERROR, null, True);

//-----------------
   /* if(SUCCEEDED(retc)) retc = */ BlockSemaphore();

//-----------------
#if FALSE // #if TRUE //
// kursorius isijungia tik pagrindiniam threade
   if(SUCCEEDED(retc))
   {
      cur_sav=::SetCursor(LoadCursor(NULL /* hKpInstance */, IDC_WAIT));
      if(cur_sav==NULL)
         retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), False, __FILE__, __LINE__, 0L, NULL);
   }
#endif

//------------------
   if(SUCCEEDED(retc))
      retc = KpGetCtrlText(lzdsh_dlg->m_InpEdit, updated_inp_str, KP_MAX_FILE_LIN_WDT);
   if(SUCCEEDED(retc))
   {
      updated_inp_str[KP_MAX_FILE_LIN_WDT] = Nul;
      retc = CutInitTrailSpcs(updated_inp_str, lpszSpcEolNotNBSP);
   }
   if(SUCCEEDED(retc)) if(strlen(updated_inp_str)>0)
   {
// KP_TRACE("ProcSearch_1: SetToSearchStr()");
      retc=SetToSearchStr(updated_inp_str, m_iToHistListFlags);

      if(SUCCEEDED(retc))
      {
         strcpy(updated_inp_str, (const unsigned char *)m_lpszToSearch);
         strcpy((unsigned char *)m_lpszLastSearchStr, updated_inp_str);
      }

//------------------ to m_HistList
      if(SUCCEEDED(retc))
      {
//       strcpy(updated_inp_str, (const unsigned char *)m_lpszToSearch);
         CutInitTrailSpcs(updated_inp_str, lpszSpcEolNotNBSP);
         if(
            (strcmp(updated_inp_str, (const unsigned char *)m_lpszPrevHistWord)!=0) &&
            (updated_inp_str[0]!=Nul)
           )
         {
            retc = LzdshAppendStrToList(lzdsh_dlg->m_HistList, updated_inp_str);

            if(SUCCEEDED(retc))
            {
               strcpy((unsigned char *)m_lpszPrevHistWord, updated_inp_str);

               lzdsh_dlg->m_iNumOfHistEntries++;

//             if(SendMessage(lzdsh_dlg->m_HistList, LB_SETCURSEL, lzdsh_dlg->m_iNumOfHistEntries-1, lzdsh_dlg->m_iNumOfHistEntries-1)==LB_ERR) // lParam reikia KpListBox
//                retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), True, __FILE__, __LINE__, 0L, NULL);
               retc=SetListBoxSel(lzdsh_dlg->m_HistList, lzdsh_dlg->m_iNumOfHistEntries - 1);
            }
         }
      }

//------------------
      if(SUCCEEDED(retc))
      {
         SendMessage(lzdsh_dlg->m_SearchList, LB_RESETCONTENT, 0, 0L);

         if(SUCCEEDED(retc))
         {
            retv=SendMessage(lzdsh_dlg->m_SearchList, LB_INITSTORAGE, LZDSH_MAX_NUM_OF_SEARCH_ITEMS,
                  LZDSH_MAX_NUM_OF_SEARCH_ITEMS*LZDSH_MAX_LIST_ITEM_WDT);
            if((retv==LB_ERRSPACE) && SUCCEEDED(retc))
               retc=KpErrorProc.OutputErrorMessage(KP_E_OUTOFMEM, GetLastError(), TRUE, __FILE__, __LINE__, 0L);
            if((retv==LB_ERR) && SUCCEEDED(retc))
               retc=KpErrorProc.OutputErrorMessage(KP_E_ILLFUNC, GetLastError(), TRUE, __FILE__, __LINE__, 0L);
         }

         if(SUCCEEDED(retc))
         {
            ShowWindow(lzdsh_dlg->m_MainList, SW_HIDE);
            ShowWindow(lzdsh_dlg->m_HistList, SW_HIDE);
            ShowWindow(lzdsh_dlg->m_SearchList, SW_SHOW);

            lzdsh_dlg->m_CurList = lzdsh_dlg->m_SearchList;

#if IBSH_SKIN == IBSH_SKIN_STANDART
            if(TabCtrl_SetCurSel(lzdsh_dlg->m_TabCtrl, 1) == (-1))
               retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), True, __FILE__, __LINE__, 0L, NULL);
#elif (IBSH_SKIN == IBSH_SKIN_LZDSH_MAHAGON) || (IBSH_SKIN == IBSH_SKIN_LZDSH_MAHAGON_LIGHT) || (IBSH_SKIN == IBSH_SKIN_LZDSH_MAHAGON_3D)
            if(SUCCEEDED(retc)) SendMessage(lzdsh_dlg->m_TabMain, BM_SETCHECK, BST_UNCHECKED, 0);
            if(SUCCEEDED(retc)) SendMessage(lzdsh_dlg->m_TabSearch, BM_SETCHECK, BST_CHECKED, 0);
            if(SUCCEEDED(retc)) SendMessage(lzdsh_dlg->m_TabHist, BM_SETCHECK, BST_UNCHECKED, 0);
#endif
         }
      }

//------------------
//    new_inp_str[0]=Nul;
      if((search_list!=NULL) && SUCCEEDED(retc))
         retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

#ifdef XL_TX_GRAM
//    updated_inp_str[0]=Nul;
      if(SUCCEEDED(retc)) retc=AppendSearchResults(KP_LNG_LIT, /* updated_inp_str, */ &search_list);
//    if((updated_inp_str[0]!=Nul) && (new_inp_str[0]==Nul) && SUCCEEDED(retc))
//       strcpy(new_inp_str, updated_inp_str);

//    updated_inp_str[0]=Nul;
      if(SUCCEEDED(retc)) retc=AppendSearchResults(KP_LNG_ENG, /* updated_inp_str, */ &search_list);
//    if((updated_inp_str[0]!=Nul) && (new_inp_str[0]==Nul) && SUCCEEDED(retc))
//       strcpy(new_inp_str, updated_inp_str);

//    updated_inp_str[0]=Nul;
      if(SUCCEEDED(retc)) retc=AppendSearchResults(KP_LNG_GER, /* updated_inp_str, */ &search_list);
//    if((updated_inp_str[0]!=Nul) && (new_inp_str[0]==Nul) && SUCCEEDED(retc))
//       strcpy(new_inp_str, updated_inp_str);
#else
      if(SUCCEEDED(retc)) retc=AppendSearchResults(KP_LNG_NO, /* updated_inp_str, */ &search_list);
#endif

//    if(SUCCEEDED(retc)) if(new_inp_str[0]!=Nul) retc=SetInpStr(new_inp_str);

      if((search_list==NULL) && SUCCEEDED(retc))
      {
//       retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
         KpMsgOut("Nerasta në vieno apraðo su nurodytu paieðkos þodþiu.", IDI_ASTERISK, KP_MB_TESTI);
      }
      else
      {
//       if(SUCCEEDED(retc)) retc=SortRecList(search_list, LsdShCompareListEntries);
         if(SUCCEEDED(retc)) retc=search_list->SortPtr(TvStrPtrCmpStrictSkipSpc); // TvStrCmpStrict_

         prev_list_str=(const unsigned char *)"";
         search_list_ptr = search_list;
         while((search_list_ptr != NULL) && SUCCEEDED(retc))
         {
            cur_list_str = (const unsigned char *)search_list_ptr->GetValue();

            if(strcmp(prev_list_str, cur_list_str) != 0)
               retc = LzdshAppendStrToList(lzdsh_dlg->m_SearchList, cur_list_str);

            if(SUCCEEDED(retc))
            {
               prev_list_str = cur_list_str;
//             retc = search_list_ptr->GetFirstChild(&next_entry);
               next_entry = search_list_ptr->m_pFirstChild;
            }
            if(SUCCEEDED(retc)) search_list_ptr = next_entry;
         }

         if(SUCCEEDED(retc))
         {
//          if(SendMessage(lzdsh_dlg->m_SearchList, LB_SETCURSEL, 0, NULL) == LB_ERR)
//             retc = KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), True, __FILE__, __LINE__, 0L, NULL);
            retc = SetListBoxSel(lzdsh_dlg->m_SearchList, 0);

// char str_buf[200];
// sprintf(str_buf, ">>>%s<<<", search_list->GetValue());
// KpMsgOut(str_buf, IDI_ASTERISK, KP_MB_TESTI);
         }

// KP_TRACE("ProcSearch_2: SetToSearchStr()");
         if(SUCCEEDED(retc)) retc=SetToSearchStr((const unsigned char *)search_list->GetValue(), m_iToHistListFlags);
         m_lCurEntryId=(-1L);

      } // else // if((search_list==NULL) && SUCCEEDED(retc))

//-----------------
   } // if(strlen(updated_inp_str)>0)

   KP_DELETE(search_list);

//-----------------
// if(cur_sav!=NULL) ::SetCursor(cur_sav);
// cur_sav=NULL;

   /* if(SUCCEEDED(retc)) retc = */ ReleaseSemaphore();

return(retc);
}


// ----------------------------------
HRESULT LzdShSearch::AppendSearchResults(int /* iLang */, /* unsigned char *lpszUpdatedInpStr, */ KpTreeEntry **ppAppendList)
{
HRESULT retc=S_OK;
long entry_id;
long last_entry_id;
long offset;
long end_offset;
long text_size;
long full_size;
long entry_id_hx;
long offset_hx;
long end_offset_hx;
long text_size_hx;
long full_size_hx;
// unsigned char first_occur[TV_XL_MAX_IX_LEN+1];
unsigned char read_kwd[TV_XL_MAX_IX_LEN+1];
unsigned char *read_kwd_ptr = read_kwd;
unsigned char cur_kwd[TV_XL_MAX_IX_LEN+1];
unsigned char *cur_kwd_ptr = cur_kwd;
unsigned char *new_list_entry = NULL;
unsigned char read_kwd_hx[TV_XL_MAX_IX_LEN+1];
KpChar hw_buf[TV_XL_MAX_IX_LEN+1];
KpChar i_cur_hw[TV_XL_MAX_IX_LEN+1];
int rc;
int pos;
#ifdef LZDSHT_ENCODED
unsigned char *entry_img = NULL;
long img_len;
KpChar *hw_ptr = NULL;
#else
XmlNode *cur_entry = NULL;
KpChar *hw_ptr = NULL;
#endif
// int retv;
int ii=0;

// KP_ASSERT(lpszUpdatedInpStr, E_INVALIDARG, null, True);
   KP_ASSERT(ppAppendList, E_INVALIDARG, null, True);

   LZDSH_DLG_PTR_INIT;

   KP_ASSERT(m_lpInFileObj != NULL, KP_E_NO_FILE, null, True);
   KP_ASSERT(m_lpInFileObj->aiFileIndexLengthsPtr != NULL, KP_E_SYSTEM_ERROR, null, True);

   /* if(SUCCEEDED(retc)) retc = */ BlockSemaphore();

   KP_NEWA(new_list_entry, unsigned char, TV_XL_MAX_IX_LEN + 1);

   if(SUCCEEDED(retc))
   {
      last_entry_id=0L;
//    first_occur[0]=Nul;

      m_iCurIndexFile=XL_IX_TxIndex;

      strncpy(m_lpszCurSearchWord, (const unsigned char *)m_lpszToSearch, KP_MAX_FILE_LIN_WDT);
      m_lpszCurSearchWord[KP_MAX_FILE_LIN_WDT]=Nul;
   }

   if(SUCCEEDED(retc)) retc=CvtToKwd(/* iLang */);

   if(SUCCEEDED(retc))
   {
      TvStrLat(m_lpszCurSearchKwd, lzdsh_dlg->m_iCtrlCtbl);
      TvStrLwr(m_lpszCurSearchKwd, lzdsh_dlg->m_iCtrlCtbl);
   }

   if(SUCCEEDED(retc))
   {
      retc=m_lpInFileObj->SearchEntryFirst(&entry_id, &offset, m_lpszCurSearchKwd, m_iCurIndexFile, False);
      if((retc==KP_E_KWD_NOT_FOUND) || SUCCEEDED(retc))
      {
         retc=S_OK;

         full_size=m_lpInFileObj->aiFileIndexLengthsPtr[m_iCurIndexFile];
         text_size=full_size-sizeof(long);

         if(SUCCEEDED(retc))
            retc=m_lpInFileObj->FilePtr->GetIndexSize(&end_offset, m_iCurIndexFile);

         full_size_hx=m_lpInFileObj->aiFileIndexLengthsPtr[XL_IX_HxIndex];
         text_size_hx=full_size_hx-sizeof(long);

         if(SUCCEEDED(retc))
            retc=m_lpInFileObj->FilePtr->GetIndexSize(&end_offset_hx, XL_IX_HxIndex);

// -------------
         if((offset<end_offset) && SUCCEEDED(retc))
            retc=m_lpInFileObj->Fseek(m_iCurIndexFile, offset, SEEK_SET);

// -------------
         if(SUCCEEDED(retc))
         {
            strncpy(cur_kwd, m_lpszCurSearchKwd, TV_XL_MAX_IX_LEN);
            cur_kwd[TV_XL_MAX_IX_LEN]=Nul;
         }

         if(SUCCEEDED(retc)) retc = IndexEntryToCompareStr(cur_kwd, cur_kwd, True, True, iaIxEncodings[XL_IX_HxIndex]);

// loop through all occurences
         ii=0;
         do
         {
// check entry
            if(SUCCEEDED(retc))
            {
               if(offset<end_offset)
                  retc=m_lpInFileObj->GetImage(read_kwd, text_size, m_iCurIndexFile, False);
               else retc=KP_E_KWD_NOT_FOUND;
            }

            if(SUCCEEDED(retc))
            {
               read_kwd[text_size]=Nul;
               retc = IndexEntryToCompareStr(read_kwd, read_kwd, True, True, iaIxEncodings[XL_IX_HxIndex]);
            }

            if(SUCCEEDED(retc))
            {
#ifndef XL_TX_GRAM
               pos=strlen(cur_kwd);
               if(pos<=TV_XL_MAX_IX_LEN) read_kwd[pos]=Nul;
#endif
//             rc=TvStrCmp(read_kwd, cur_kwd, SortSkipSpc, SortMode, True,
//                TV_IX_CTBL, // 71
//                True);
               rc = TvStrPtrCmpStrictSkipSpc(&read_kwd_ptr, &cur_kwd_ptr);
               if(rc!=0) retc=KP_E_KWD_NOT_FOUND;
               else
                  retc=m_lpInFileObj->GetImage(&entry_id, sizeof(long), m_iCurIndexFile, True);
            }

            if(SUCCEEDED(retc)) ii++;

// --------------- surandam lizdo antraste hw
            if((entry_id!=last_entry_id) && SUCCEEDED(retc))
            {
               hw_ptr = NULL;
#ifdef LZDSHT_ENCODED
               if((entry_img!=NULL) && SUCCEEDED(retc))
                  retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
               if(SUCCEEDED(retc)) retc=m_lpInFileObj->ReadEntryImg(entry_id, &entry_img, &img_len);
               if((entry_img==NULL) && SUCCEEDED(retc))
                  retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

               if(SUCCEEDED(retc)) retc=GetHwFromEncImg(&hw_ptr, entry_img, img_len, entry_id);
#else
               retc=m_lpInFileObj->SeekEntry(entry_id);

               if((cur_entry!=NULL) && SUCCEEDED(retc))
                  retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);
               if(SUCCEEDED(retc)) retc=ReadEntry(&cur_entry, m_lpInFileObj, True);
               if((cur_entry==NULL) && SUCCEEDED(retc))
                  retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

               if(SUCCEEDED(retc)) retc=cur_entry->GetHw(&hw_ptr);
#endif
               if(SUCCEEDED(retc))
               {
                  if(hw_ptr==NULL)
                  {
#ifdef Debug
                     retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, False, __FILE__, __LINE__, 0L, NULL);
#endif
                     new_list_entry[0] = Nul;
                  }
                  else // if(hw_ptr==NULL)
                  {
                     TvKpStrNCpy(hw_buf, hw_ptr, TV_XL_MAX_IX_LEN);
                     hw_buf[TV_XL_MAX_IX_LEN] = C_Nul;
                     NormalizeHeadword(i_cur_hw, hw_buf);
                     TvKpStrClearAccents(i_cur_hw);

                     retc = KptStrDecode(new_list_entry, i_cur_hw, lzdsh_dlg->m_iCtrlCtbl);
                     if((retc==KP_E_UNKN_CHR) || (retc==KP_E_FONT_UNDEF)) retc=S_OK;

KP_TRACE(new_list_entry);

                     pos=strlen(new_list_entry)-1;
                     while((pos>=0) && SUCCEEDED(retc))
                     {
//                      if(new_list_entry[pos] == DOUBLE_ENTRIES_CHR) // '*'
//                         new_list_entry[pos--] = DOUBLE_ENTRIES_LZDSH_CHR; // 0xA0 // C_NBSP lenteleje 71
                        if(new_list_entry[pos] == DOUBLE_ENTRIES_LZDSH_CHR)  // 0xA0 // C_NBSP lenteleje 71
                           new_list_entry[pos--] = Nul;
                        else break;
                     }
#if FALSE
KP_TRACE(">>>");
KP_TRACE(new_list_entry);
KP_TRACE("<<<");
#endif
                  }
               }

// ------------ ieskom tikslios hx indexo antrastes (su tiksliu '*' (DOUBLE_ENTRIES_CHR) skaicium gale)
               if(SUCCEEDED(retc))
                  retc=m_lpInFileObj->SearchEntryFirst(&entry_id_hx, &offset_hx, new_list_entry, XL_IX_HxIndex, False);
               if((retc==KP_E_KWD_NOT_FOUND) || SUCCEEDED(retc))
               {
                  retc=S_OK;

                  if((offset_hx < end_offset_hx) && SUCCEEDED(retc))
                     retc=m_lpInFileObj->Fseek(XL_IX_HxIndex, offset_hx, SEEK_SET);

// loop through all hx occurences
                  do
                  {
// check entry
                     if(SUCCEEDED(retc))
                     {
                        if(offset_hx < end_offset_hx)
                           retc=m_lpInFileObj->GetImage(read_kwd_hx, text_size_hx, XL_IX_HxIndex, False);
                        else retc=KP_E_KWD_NOT_FOUND;
                     }

                     if(SUCCEEDED(retc))
                     {
                        read_kwd_hx[text_size_hx]=Nul;
                        retc = IndexEntryToCompareStr(read_kwd, read_kwd_hx, True, True, iaIxEncodings[XL_IX_HxIndex]);
                     }

                     if(SUCCEEDED(retc))
                     {
                        TvStrLwr(read_kwd, (iaIxEncodings[XL_IX_HxIndex] < EC_First_Type)?iaIxEncodings[XL_IX_HxIndex]:1);

                        rc = TvStrPtrCmpStrictSkipSpc(&read_kwd_ptr, &new_list_entry);
                        if(rc!=0) retc=KP_E_KWD_NOT_FOUND;
                        else
                           retc=m_lpInFileObj->GetImage(&entry_id_hx, sizeof(long), XL_IX_HxIndex, True);
                     }

                     if(SUCCEEDED(retc)) if(entry_id_hx == entry_id)
                     {
                        retc = IndexEntryToCompareStr(new_list_entry, read_kwd_hx, False, True, iaIxEncodings[XL_IX_HxIndex]);
                        break;
                     }

                  } while(SUCCEEDED(retc));

                  if(retc==KP_E_KWD_NOT_FOUND) retc=S_OK;

               } // if((retc==KP_E_KWD_NOT_FOUND) || SUCCEEDED(retc))

// ------------ pridedam prie saraso

//             if(SUCCEEDED(retc))
//                retc = LzdshAppendStrToList(lzdsh_dlg->m_SearchList, new_list_entry);

               if(*ppAppendList==NULL)
               {
                  KP_NEW(*ppAppendList, KpTreeEntry(new_list_entry, TV_XL_MAX_IX_LEN, NULL));
               }
               else
                  retc = (*ppAppendList)->PutToEnd(new_list_entry, TV_XL_MAX_IX_LEN);

//             if((last_entry_id==0L) && SUCCEEDED(retc))
//             {
//                strcpy(first_occur, new_list_entry);

//                retc=SelectList(offset);

////              if(SUCCEEDED(retc))
////                 if(SendMessage(lzdsh_dlg->m_SearchList, LB_SETCURSEL, 0, NULL)==LB_ERR)
////                    retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), True, __FILE__, __LINE__, 0L, NULL);
//                if(SUCCEEDED(retc)) retc = SetListBoxSel(lzdsh_dlg->m_SearchList, 0);
//             }

#ifdef LZDSHT_ENCODED
// besàlygiðkai trint negalima – gali bûti uþsilikæs GetHwFromEncImg()
               if(SUCCEEDED(retc)) KP_DELETEA(hw_ptr);
               if(SUCCEEDED(retc)) KP_DELETEA(entry_img);
#else
               KP_DELETE(cur_entry);
#endif
            } // if(entry_id!=last_entry_id)

            last_entry_id = entry_id;

// ------ next entry
            if(SUCCEEDED(retc))
            {
               offset+=full_size;
               if(offset>=end_offset) retc=KP_E_KWD_NOT_FOUND;
            }

#if FALSE // #ifdef Debug //
char str_buf[100];
sprintf(str_buf, "%d %d %d", ii, LZDSH_MAX_NUM_OF_SEARCH_ITEMS, new_list_entry);
KP_TRACE(str_buf);
#endif
         } while((ii<LZDSH_MAX_NUM_OF_SEARCH_ITEMS) && SUCCEEDED(retc));

      } // else // if(retc==KP_E_KWD_NOT_FOUND)

      if(retc==KP_E_KWD_NOT_FOUND) retc=S_OK;

      if(ii>=LZDSH_MAX_NUM_OF_SEARCH_ITEMS)
         KpMsgOut(LZDSH_MSG_TOO_MANY_SEARCH_RESULTS, IDI_ASTERISK, KP_MB_TESTI);

   } // if(SUCCEEDED(retc))

   m_iCurIndexFile=m_iIndexFile;

// if((first_occur[0]!=Nul) && SUCCEEDED(retc)) retc=SetInpStr(first_occur);


   /* if(SUCCEEDED(retc)) retc = */ ReleaseSemaphore();

   KP_DELETEA(new_list_entry);

return(retc);
}


// -----------------------------------------
HRESULT LzdShSearch::GetReactToSel(bool *pbReactToSel)
{
HRESULT retc = S_OK;
static unsigned char publisher[KP_MAX_FNAME_LEN + 1];
int prod_ver = 0;
HKEY hKey = NULL;
DWORD dwBufLen;
DWORD dwValType;
long ll;
static unsigned char key_name[KP_MAX_FILE_LIN_WDT + 1];

   KP_ASSERT(theKpStAppPtr, KP_E_SYSTEM_ERROR, null, True);
   KP_ASSERT(pbReactToSel, KP_E_SYSTEM_ERROR, null, True);

   if(SUCCEEDED(retc)) retc = theKpStAppPtr->GetIniPublisher(publisher);
   if(SUCCEEDED(retc)) retc = theKpStAppPtr->GetIniProdVer(&prod_ver);
   if(SUCCEEDED(retc))
   {
      sprintf((char *)key_name,
         "Software\\%s\\%d", // "Software\\%s\\%s",
         publisher,
         prod_ver // prod_name
         );
      if(RegOpenKeyEx(HKEY_CURRENT_USER, // HKEY_LOCAL_MACHINE,
         (LPCTSTR)key_name,
         0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS)
      {
         dwBufLen = sizeof(ll);
         if(SUCCEEDED(retc))
            if(RegQueryValueEx(hKey, "ReactToSel", NULL,
               &dwValType, (LPBYTE)&ll, &dwBufLen) == ERROR_SUCCESS)
         {
            KP_ASSERT(dwValType == REG_DWORD, KP_E_SYSTEM_ERROR, null, True);
            if(SUCCEEDED(retc)) *pbReactToSel = (ll != 0L);
         }
      }
      if(hKey)
      {
         RegCloseKey(hKey);
         hKey = NULL;
      }
   }

return(retc);
}


// -----------------------------------------
HRESULT LzdShSearch::SetReactToSel(bool bReactToSel)
{
HRESULT retc = S_OK;
static unsigned char publisher[KP_MAX_FNAME_LEN + 1];
int prod_ver = 0;
HKEY hKey = NULL;
static unsigned char key_name[KP_MAX_FILE_LIN_WDT + 1];
DWORD dwDisposition;
DWORD ll;
LONG retw = ERROR_SUCCESS;

   KP_ASSERT(theKpStAppPtr, KP_E_SYSTEM_ERROR, null, True);

   if(SUCCEEDED(retc)) retc = theKpStAppPtr->GetIniPublisher(publisher);
   if(SUCCEEDED(retc)) retc = theKpStAppPtr->GetIniProdVer(&prod_ver);
   if(SUCCEEDED(retc))
   {
      sprintf((char *)key_name,
         "Software\\%s\\%d", // "Software\\%s\\%s",
         publisher,
         prod_ver // prod_name
         );
      KP_ASSERTE((retw = RegCreateKeyEx(HKEY_CURRENT_USER, // HKEY_LOCAL_MACHINE,
         (LPCTSTR)key_name, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_READ | KEY_WRITE, NULL,
         &hKey, &dwDisposition)) == ERROR_SUCCESS, KP_E_SYSTEM_ERROR, retw, False);
   }

   if(SUCCEEDED(retc))
   {
      ll = bReactToSel;
      KP_ASSERTE((retw = RegSetValueEx(hKey, "ReactToSel", 0, REG_DWORD,
         (BYTE *)&ll, sizeof(ll))) == ERROR_SUCCESS, KP_E_SYSTEM_ERROR, retw, False);
   }

   if(hKey)
   {
      RegCloseKey(hKey);
      hKey = NULL;
   }

   if(SUCCEEDED(retc)) m_bReactToSelFlag = bReactToSel;

return(retc);
}


// -----------------------------------------
// int LsdShCompareListEntries(const void *val_1, const void *val_2)
// {
// return(strcmp((const unsigned char *)val_1, (const unsigned char *)val_2));
// }


//----------------------------------- start idle loop in new thread
HRESULT LzdShSearch::LzdShCreateThread(HINSTANCE /* hInstance */)
{
HRESULT retc = S_OK;
HANDLE hh;

   if(m_lThreadId!=0L)
      retc=KpErrorProc.OutputErrorMessage(KP_E_DOUBLE_CALL, null, True, __FILE__, __LINE__, 0L, NULL);

   if(SUCCEEDED(retc))
   {
      hh=CreateThread
      (
         NULL,                // LPSECURITY_ATTRIBUTES lpThreadAttributes,  // pointer to security attributes
         0L,                  // DWORD dwStackSize,                         // initial thread stack size
         LzdShSearchIdle,     // LPTHREAD_START_ROUTINE lpStartAddress,     // pointer to thread function
         NULL,                // LPVOID lpParameter,                        // argument for new thread
         0L,                  // DWORD dwCreationFlags,                     // creation flags
         &m_lThreadId         // LPDWORD lpThreadId                         // pointer to receive thread ID
      );
      if(hh==NULL)
         retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), True, __FILE__, __LINE__, 0L, NULL);
   }

// KpMsgOutF_2("LzdShSearch::LzdShCreateThread() current: %d m_lThreadId: %d", GetCurrentThreadId(), m_lThreadId);

// if(SUCCEEDED(retc)) EmuTv.m_lMainThreadId=m_lThreadId; // nuo siol kphp11 vykdys theSearchThread uzklausas
// else m_lThreadId=0L;

#ifdef Debug
// if(SUCCEEDED(retc)){ KP_TRACE("LzdShSearch: thread started"); }
#endif

return(retc);
}


// -----------------------------------------
// #define LZDSHT_WINDOW_TEXT_LEN KP_MAX_FILE_LIN_LEN
// #define LZDSHT_WINDOW_TEXT_LEN 20000
// FILE *out_file = NULL;
#if FALSE
int child_num = 0;
BOOL CALLBACK ProcReactWindow(HWND hwnd, LPARAM lParam) // lParam - indent string
{
HRESULT retc = S_OK;
static LenString(str_buf, LZDSHT_WINDOW_TEXT_LEN);
static LenString(sel_buf, KP_MAX_FILE_LIN_LEN);
static unsigned char class_name[KP_MAX_FNAME_LEN + 1];
static unsigned char class_name_lwr[KP_MAX_FNAME_LEN + 1];
int text_len = 0;
GETTEXTEX get_text_pars;
bool rtf_flag;
bool wchar_flag;
unsigned char *indent_ptr = (unsigned char *)lParam;
unsigned char *new_indent = NULL;
int indent;
int child_num_sav = 0;

// ----------------------------------------
   rtf_flag = False;
   class_name[0] = Nul;
   if(GetClassName(hwnd, (char *)class_name, KP_MAX_FNAME_LEN) >0)
   {
      class_name[KP_MAX_FNAME_LEN] = Nul;
      strcpy(class_name_lwr, class_name);
      strlwr(class_name_lwr);
      if(strstr(class_name_lwr, "richedit")) rtf_flag = True;
   }


// http://social.msdn.microsoft.com/Forums/en-US/csharpgeneral/thread/1d66a635-d4ec-4b49-9412-43585d4dfa31

// ----------------------------------------- get whole
#  if TRUE // FALSE
// if(!rtf_flag)
   {
      str_buf.len = LZDSHT_WINDOW_TEXT_LEN;
//    str_buf.str[0] = Nul;

//    if(GetWindowText(cur_child, (char *)str_buf.str, LZDSHT_WINDOW_TEXT_LEN) <= 0) str_buf.str[0] = Nul;
      text_len = SendMessage(hwnd, WM_GETTEXT, LZDSHT_WINDOW_TEXT_LEN, (LPARAM)str_buf.str);
   }
#     if FALSE
   else
   {
      str_buf.len = LZDSHT_WINDOW_TEXT_LEN;
//    str_buf.str[0] = Nul;

      get_text_pars.cb = LZDSHT_WINDOW_TEXT_LEN;
      get_text_pars.flags = GT_DEFAULT; // GT_SELECTION;
      get_text_pars.codepage = CP_ACP;
      get_text_pars.lpDefaultChar = " ";
      get_text_pars.lpUsedDefChar = NULL;

      text_len = SendMessage(hwnd, EM_GETTEXTEX, (WPARAM)&get_text_pars, (LPARAM)str_buf.str);
   }
#     endif
   str_buf.str[LZDSHT_WINDOW_TEXT_LEN] = Nul;
#  endif

// ----------------------------------------- get line
#  if FALSE
   str_buf.len = LZDSHT_WINDOW_TEXT_LEN;
   text_len = SendMessage(hwnd, EM_GETLINE, 0, (LPARAM)str_buf.str);
   KP_ASSERT(text_len <= KP_MAX_FILE_LIN_LEN, KP_E_BUFFER_OVERFLOW, null, True);
   if((text_len > 0) && SUCCEEDED(retc)) str_buf.str[text_len] = Nul;
#  endif

// ------------------------------------------
   wchar_flag = ((text_len > 0) && (str_buf.str[0] == Nul));

// ------------------------- get selected
// RichEdit
// suþinoti paþymëtà baitø skaièiø !!!! - EM_EXGETSEL
// neveikia – lauþia WordPad'à ir Windows Defender'á
#  if FALSE
   if(rtf_flag)
   {
      sel_buf.str[0] = Nul;

      sel_len = SendMessage(hwnd, EM_GETSELTEXT, 0, (LPARAM)sel_buf.str);
      KP_ASSERT(sel_len <= KP_MAX_FILE_LIN_LEN, KP_E_BUFFER_OVERFLOW, null, True);
      if((sel_len > 0) && SUCCEEDED(retc)) sel_buf.str[sel_len] = Nul;
   }
#  endif

str_buf.str[100] = Nul;
sel_buf.str[100] = Nul;

   indent = 0;
   if(indent_ptr) indent = strlen(indent_ptr);

if(out_file)
{
   if(indent == 0) fprintf(out_file, "%d [%s] %s %s [%d] [%s] [%s]\n", hwnd, class_name, rtf_flag?"RTF:":"", wchar_flag?"WCHAR:":"", text_len, str_buf.str, sel_buf.str);
   else if(text_len) fprintf(out_file, "%s%d %d [%s] %s %s [%d] [%s] [%s]\n", indent_ptr, child_num, hwnd, class_name, rtf_flag?"RTF:":"", wchar_flag?"WCHAR:":"", text_len, str_buf.str, sel_buf.str);

   child_num++;
}

// ---------------- rekursija po vaikø vaikus
   KP_NEWA(new_indent, unsigned char, indent + 3 + 1);
   if(new_indent != null)
   {
      new_indent[0] = Nul;
      if(indent_ptr) strcpy(new_indent, indent_ptr);
      strcat(new_indent, "   ");

      child_num_sav = child_num;
      child_num = 0;

      EnumChildWindows(hwnd, ProcReactWindow, (LPARAM)new_indent);

      child_num = child_num_sav;

      KP_DELETEA(new_indent);
   }

return(TRUE);
}
#endif


// ------------------- main idle loop - main function of hp11 thread
DWORD WINAPI LzdShSearchIdle(LPVOID /* lpParameter */)
{
HRESULT retc = S_OK;
HRESULT retc0 = S_OK;
MSG msg;
// BOOL msg_ready;
unsigned int retw;
UINT poll_timer = 0;
UINT react_timer = 0;
static unsigned char word_buf[KP_MAX_FILE_LIN_WDT+1+KP_MAX_FNAME_LEN+1]; // +TV_XL_MAX_TAG_WDT+1];
// unsigned char *pntd;
// HWND cur_wnd;
// HWND cur_child;
static unsigned char cur_clip_buf[KP_MAX_FILE_LIN_WDT + KP_KWD_LEN + 1];

// KpMsgOutF_1("LzdShSearchIdle() current: %d", GetCurrentThreadId());

   LZDSH_DLG_PTR_INIT;
   LZDSH_SEARCH_PTR_INIT;

#ifdef LZDSHT_DISPLAY_SEARCH_THREAD
   if(SUCCEEDED(retc)) retc = lzdsh_dlg->InitThreadDisplay();
#endif

// paieðkos taimeris
   if(SUCCEEDED(retc))
   {
      poll_timer = SetTimer(HWND_DESKTOP, KP_POLL_TIMER, LZDSH_POLL_TIMEOUT, NULL);
      if(!poll_timer)
         retc = KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), True, __FILE__, __LINE__, 0L, NULL);
   }

// reakcijos á paþymëtà tekstà taimeris
   if(SUCCEEDED(retc))
   {
      react_timer = SetTimer(HWND_DESKTOP, LZDSH_REACT_TIMER, LZDSH_REACT_TIMEOUT, NULL);
      if(!react_timer)
         retc = KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), True, __FILE__, __LINE__, 0L, NULL);
   }

#if FALSE
// MarcHighlighted() letina lzdsh scrolinima search liste, paieskos threado prioriteto nusodinimas
//    vis tiek nepadeda, WM_TIMER pranesimai praeina, bet scrollbaras vis tiek stabcioja
   if(SUCCEEDED(retc))
      if(!SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_LOWEST)) // THREAD_MODE_BACKGROUND_BEGIN)) // THREAD_PRIORITY_BELOW_NORMAL))
         retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), False, __FILE__, __LINE__, 0L, NULL);
#endif

   if(SUCCEEDED(retc))
   {
      do
      {
//       if(SUCCEEDED(retc)) retc = lzdsh_search->SearchAndDisplay();

//       if(SUCCEEDED(retc)) msg_ready=PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
//       if(msg_ready && SUCCEEDED(retc))
//       {

#if FALSE // #ifdef Debug
char str_buf[100];
static int ii;
sprintf(str_buf, "LzdShSearchIdle()[%d]", ii++);
KP_TRACE(str_buf);
#endif
         if(SUCCEEDED(retc))
            if(GetMessage(&msg, NULL, 0, 0) < 0)
               retc = KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), False, __FILE__, __LINE__, 0L, NULL);
         if(SUCCEEDED(retc))
         {
            retw=LOWORD(msg.wParam);

            TranslateMessage(&msg);

#if FALSE // #ifdef Debug
if(msg.message == WM_PAINT)
{
static int ii;
KP_TRACE_1("gavau WM_PAINT %d", ii++);
}
#endif
            switch(msg.message)
            {
            case WM_TIMER:
               if(SUCCEEDED(retc))
               {
#if FALSE // #ifdef Debug
char str_buf[100];
sprintf(str_buf, "LzdShSearchIdle():WM_TIMER[%d][%d]", retw, poll_timer);
KP_TRACE(str_buf);
#endif
               if(retw == poll_timer)
               {
// locate word entry being entered
                  if(SUCCEEDED(retc)) retc = lzdsh_search->SearchAndDisplay();

#ifdef LZDSHT_DISPLAY_SEARCH_THREAD
                  if(SUCCEEDED(retc)) if(lzdsh_dlg->m_bNewContentReady)
                  {
                     lzdsh_dlg->m_bNewContentReady = False;
//                   if(lzdsh_dlg->m_ResHtml != NULL) lzdsh_dlg->m_ResHtml->HTML((const char *)lzdsh_search->m_lpszResultFormatted);
                     retc = lzdsh_search->DisplayResult();
                  }
#endif

// to history list
                  if(SUCCEEDED(retc))
                  {
                     lzdsh_search->m_lQuietTime += LZDSH_POLL_TIMEOUT;
                     if(lzdsh_search->m_lQuietTime >= LZDSH_TIME_TO_HIST)
                     {
#if FALSE
KpMsgOut("LZDSH_TIME_TO_HIST", IDI_ASTERISK, KP_MB_TESTI);
lzdsh_search->m_lQuietTime = 0;
#endif
                        strcpy(word_buf, (const unsigned char *)lzdsh_search->m_lpszToHistStr);
                        CutInitTrailSpcs(word_buf, lpszSpcEolNotNBSP);
                        if(
                           (strcmp(word_buf, (const unsigned char *)lzdsh_search->m_lpszPrevHistWord)!=0) &&
                           (word_buf[0]!=Nul)
                          )
                        {
// KP_TRACE("LZDSH_TIME_TO_HIST");
KP_TRACE_("LzdShSearchIdle: LZDSH_TIME_TO_HIST: m_lpszToHistStr:%s", lzdsh_search->m_lpszToHistStr);
#ifdef IBSH_RES_MODE_XGECKO
                           if(strchr(word_buf, TECH_DELIM_CHR) == NULL)
                           {
                              strcat(word_buf, TECH_DELIM_STR);
                              strcat(word_buf, (const unsigned char *)lzdsh_dlg->m_lpszSelDictName);
                           }
#endif
                           if(SUCCEEDED(retc)) retc=LzdshAppendStrToList(lzdsh_dlg->m_HistList, word_buf);

                           if(SUCCEEDED(retc))
                           {
                              strcpy((unsigned char *)lzdsh_search->m_lpszPrevHistWord, (const unsigned char *)lzdsh_search->m_lpszToHistStr);

                              lzdsh_dlg->m_iNumOfHistEntries++;
                           }

//                         if(SUCCEEDED(retc))
//                            if(SendMessage(lzdsh_dlg->m_HistList, LB_SETCURSEL, lzdsh_dlg->m_iNumOfHistEntries-1, lzdsh_dlg->m_iNumOfHistEntries-1) == LB_ERR) // lParam reikia KpListBox
//                               retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, GetLastError(), True, __FILE__, __LINE__, 0L, NULL);
                           if(SUCCEEDED(retc))
                              retc = SetListBoxSel(lzdsh_dlg->m_HistList, lzdsh_dlg->m_iNumOfHistEntries - 1);
#if FALSE
// !!!!!
// su ðituo gabalu po paieðkos praëjus hist laikui, rez. laukas atsistatydavo á main liste selektintà áraðà, nors listas bûdavo search
// pvz., LVZ surenkam "kaka", spaudþiam Enter, pereina á search listà, o po poros sekundþiø perðoka á kakarinë (nes ant jo ðiuo metu stovi main liste)
                           if(SUCCEEDED(retc))
                           {
                              pntd = strchr(word_buf, TECH_DELIM_CHR);
                              if(pntd) *pntd = Nul;
                              strcpy((unsigned char *)lzdsh_search->m_lpszToSearch, word_buf);
                           }
#endif
// KP_TRACE_2("LzdShSearchIdle: WM_TIMER: m_lpszToSearch:%s m_lpszCurSearchWord:%s", lzdsh_search->m_lpszToSearch, lzdsh_search->m_lpszCurSearchWord);
                        }

                     } // if(lzdsh_search->m_lQuietTime >= LZDSH_TIME_TO_HIST)

                  } // if(SUCCEEDED(retc))

// process search button
#ifdef LZDSHT_SEARCH_SINGLE_THREAD
                  if(SUCCEEDED(retc)) if(lzdsh_dlg->m_bButSearchPressed)
                  {
                     retc = lzdsh_search->ProcSearch();
                     lzdsh_dlg->m_bButSearchPressed = False;
                  }
#endif

#ifdef LZDSH_EDITOR_BUILD
// ------------------- refresh currently edited node listbox heading
                  if(SUCCEEDED(retc)) if(lzdsh_search->m_bRefreshCurNodeHead)
                  {
                     if(SUCCEEDED(retc)) retc = lzdsh_dlg->RefreshCurNodeHeads();

                     lzdsh_search->m_bRefreshCurNodeHead = False;
                  }

// ------------------- refresh RTF display during and after tag editing
                  if(SUCCEEDED(retc)) if(lzdsh_search->m_bRefreshDisplay)
                  {
                  /* if(SUCCEEDED(retc)) */ retc = lzdsh_search->BlockSemaphore();
                     if(SUCCEEDED(retc)) retc = FormatEntry(lzdsh_search->m_pCurEntry);
                  /* if(SUCCEEDED(retc)) retc = */ lzdsh_search->ReleaseSemaphore();

                     lzdsh_search->m_bRefreshDisplay = False;
                  }
#endif
               } // if(retw == poll_timer)

// -----------------------------------
               else if((retw == react_timer) && lzdsh_search->m_bReactToSelFlag)
               {
// out_file = fopen("lzdshp_react.lst", "w");

// ---------------------------------
#if FALSE
// ------------------ langai
                  cur_wnd = GetTopWindow(NULL);

                  while(cur_wnd!=NULL)
                  {
                     ProcReactWindow(cur_wnd, (LPARAM)"");

// ------------------ vaikai
child_num = 0;
#  if TRUE
                     EnumChildWindows(cur_wnd, ProcReactWindow, (LPARAM)"   ");
#  else
                     cur_child = GetWindow(cur_wnd, GW_CHILD);
                     while(cur_child!=NULL)
                     {
                        ProcReactWindow(cur_child, (LPARAM)"   ");
                        cur_child = GetWindow(cur_child, GW_HWNDNEXT);
                     }
#  endif
                     cur_wnd = GetWindow(cur_wnd, GW_HWNDNEXT);
                  }
#endif

// ---------------------------------
#ifdef KP_USE_TextGRAB
                  if(SUCCEEDED(retc)) if(lzdsh_search->m_pITextGRABSDK != NULL)
                  {
static int cnt;
HWND hwndSelected = 0;
RECT rcSelected = {0};
ITextSnapshot *pSnapshot = NULL;
LONG count = 0;

                     if(SUCCEEDED(retc))
                     {
                        retc = lzdsh_search->m_pITextGRABSDK->GetSelection((INT_PTR*)&hwndSelected, &rcSelected);
                        if(FAILED(retc)) KP_ERROR(retc, null);
                     }
if(SUCCEEDED(retc)) fprintf(out_file, "hwndSelected: %lx cnt: %ld\n", hwndSelected, cnt++);

                     if(hwndSelected && SUCCEEDED(retc))
                     {
                        retc = lzdsh_search->m_pITextGRABSDK->CaptureTextSnapshot((INT_PTR)hwndSelected, &pSnapshot);
                        if(FAILED(retc)) KP_ERROR(retc, null);
                        KP_ASSERT(pSnapshot, KP_E_SYSTEM_ERROR, null, True);

                        if(SUCCEEDED(retc))
                        {
                           retc = pSnapshot->get_Count(&count);
                           if(FAILED(retc)) KP_ERROR(retc, null);
                        }

if(SUCCEEDED(retc)) fprintf(out_file, "count: %ld\n", count);

                        if(SUCCEEDED(retc)) for (int ii = 0; (ii < count) && SUCCEEDED(retc); ii++ )
                        {
CComVariant varTxtItem;
// CComBSTR text;
                           retc = pSnapshot->get_Item(ii + 1, &varTxtItem);
                           if(FAILED(retc)) KP_ERROR(retc, null);

#  if FALSE
                           if(SUCCEEDED(retc))
                           {
CComQIPtr<ITextItem> spTxtItem(varTxtItem.punkVal);

                              retc = spTxtItem->get_Text(&text);
                              if(FAILED(retc)) KP_ERROR(retc, null);
                           }

if(SUCCEEDED(retc)) fprintf(out_file, text);
#  endif
                        }

                     } // if(hwndSelected && SUCCEEDED(retc))


// -------------------------------- uþsakom naujà selektinimà
                     if(SUCCEEDED(retc))
                     {
                        retc = lzdsh_search->m_pITextGRABSDK->ForceStartSelection(VARIANT_TRUE);
                        if(FAILED(retc)) KP_ERROR(retc, null);
                     }

                  } // if(lzdsh_search->m_pITextGRABSDK)

#endif // #ifdef KP_USE_TextGRAB

// ---------------------------------
                  if(SUCCEEDED(retc))
                  {
                     retc = GetClipboardText(lzdsh_dlg->m_hDialogWindow, cur_clip_buf, KP_KWD_LEN /* KP_MAX_FILE_LIN_WDT */, False);
                     if(SUCCEEDED(retc))
                     {
                        cur_clip_buf[KP_KWD_LEN /* KP_MAX_FILE_LIN_WDT */] = Nul;
                        retc = CutInitTrailSpcs(cur_clip_buf);
                     }
                     if(SUCCEEDED(retc)) retc = SpcEolToSpc(cur_clip_buf);
                     if(SUCCEEDED(retc)) // nukerpam pirmà þodá (pirmus 2 þodþius)
                     {
unsigned char *pntd = null;
                        pntd = strchr(cur_clip_buf, Spc);
                        if(pntd)
                           if(pntd <= cur_clip_buf + 3) // jei pirmas þodis trumpesnis uþ 3 raides, pridedam dar vienà
                              pntd = strchr(pntd + 1, Spc);
                        if(pntd) *pntd = Nul;
                     }
                     if(SUCCEEDED(retc)) if((strcmp(cur_clip_buf, lzdsh_search->m_lpszClipBuf) != 0) && cur_clip_buf[0])
                     {
#if FALSE
static int ii;
out_file = fopen("lzdshp_react.lst", "w");
if(SUCCEEDED(retc)) fprintf(out_file, "%d %s", ii++, cur_clip_buf);
if(out_file) fclose(out_file);
#endif
                        strcpy(lzdsh_search->m_lpszClipBuf, cur_clip_buf);
                        if(SUCCEEDED(retc)) retc = lzdsh_search->SetToSearchStr(lzdsh_search->m_lpszClipBuf, LZDSH_HIST_INDEPENDENT | LZDSH_HIST_IMMEDIATELY);
                        if(SUCCEEDED(retc)) retc = lzdsh_dlg->SetEditControlText(lzdsh_search->m_lpszClipBuf);
                        if(SUCCEEDED(retc)) lzdsh_search->m_lCurEntryId = (-1L);
                     }
                     retc = S_OK;
                  }

// ---------------------------------
// if(out_file) fclose(out_file);

               } // else if((retw == react_timer) && lzdsh_search->m_bReactToSelFlag)

// -------------------------------------------
               else // if((retw == react_timer)
                  DispatchMessage(&msg);

               } // if(SUCCEEDED(retc))
               break;

#if FALSE
            case WM_LZDSH_SET_TAG_HEADINGS_FULL:
               if(SUCCEEDED(retc)) if(lzdsh_search->m_pCurEntry == NULL)
                  retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, True, __FILE__, __LINE__, 0L, NULL);

            /* if(SUCCEEDED(retc)) retc = */ lzdsh_search->BlockSemaphore();
               if(SUCCEEDED(retc)) retc = lzdsh_search->m_pCurEntry->SetTagHeadings(LZDSH_NUM_OF_PAR_STYLES, lzdsh_dlg->m_hDialogWindow);
            /* if(SUCCEEDED(retc)) retc = */ lzdsh_search->ReleaseSemaphore();

               PostThreadMessage(msg.lParam, WM_LZDSH_FULL_HEADINGS_SET, 0, 0L);
               break;
#endif

#ifdef LZDSH_EDITOR_BUILD
            case WM_LZDSH_SET_TAG_HEADINGS_CURRENT:
// KP_TRACE("LzdShSearchIdle: WM_LZDSH_SET_TAG_HEADINGS_CURRENT received");
#if TRUE // #if FALSE
               if(SUCCEEDED(retc)) retc = lzdsh_dlg->RefreshCurNodeHeads();
#else
               if(SUCCEEDED(retc)) lzdsh_search->m_bRefreshCurNodeHead = True;
#endif
               PostThreadMessage(msg.lParam, WM_LZDSH_CURRENT_HEADINGS_SET, 0, 0L);

// KP_TRACE("LzdShSearchIdle: WM_LZDSH_CURRENT_HEADINGS_SET sent");

               break;
#endif

#ifdef LZDSH_EDITOR_BUILD
            case WM_LZDSH_REFRESH_DISPLAY:
#if FALSE // #ifdef Debug
char str_buf[100];
sprintf(str_buf, "LzdShT: WM_LZDSH_REFRESH_DISPLAY received; ThreadId:%ld", GetCurrentThreadId());
KP_TRACE(str_buf);
#endif
               if(SUCCEEDED(retc)) lzdsh_search->m_bRefreshDisplay = True;
               break;
#endif

            default:
               DispatchMessage(&msg);
               break;
            }
         }

      } while((msg.message != WM_QUIT) && SUCCEEDED(retc));

      if(SUCCEEDED(retc)) lzdsh_search->CloseFiles(True);

   } // if(SUCCEEDED(retc))

// KpMsgOut("WM_QUIT", IDI_ASTERISK, KP_MB_TESTI);

#ifdef LZDSHT_DISPLAY_SEARCH_THREAD
   if(SUCCEEDED(retc)) lzdsh_dlg->FinitThreadDisplay();
#endif

   if(poll_timer)
   {
      KP_ASSERT0(KillTimer(HWND_DESKTOP, poll_timer), KP_E_SYSTEM_ERROR, GetLastError(), True);
      poll_timer = 0;
   }

   if(react_timer)
   {
      KP_ASSERT0(KillTimer(HWND_DESKTOP, react_timer), KP_E_SYSTEM_ERROR, GetLastError(), True);
      react_timer = 0;
   }

   if(SUCCEEDED(retc))
   {
      retc0 = lzdsh_search->CloseFiles(False);
      if(SUCCEEDED(retc)) retc = retc0;

      lzdsh_search->m_lThreadId = 0L;
   }

#if FALSE // #ifdef Debug
char str_buf[100];
sprintf(str_buf, "LzdShSearchIdle() exit");
KP_TRACE(str_buf);
#endif

return(RET_CODE_MAIN(retc));
}


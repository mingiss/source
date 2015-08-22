@echo off
echo // >> kptt.h
echo                      // ---------------------------- >> kptt.h
echo    C_CharSize0, >> kptt.h
echo // >> kptt.h
echo } KpChar_enum; // former Chars16; // actually 32 bit signed integers >> kptt.h
echo // >> kptt.h
echo typedef int KpChar; >> kptt.h
echo // >> kptt.h
echo // >> kptt.h
echo /* =================================================== */ >> kptt.h
echo extern const KpChar iNullStr[]; >> kptt.h
echo // >> kptt.h
echo /* =================================================== */ >> kptt.h
echo extern KpChar *Ctptr7[Ctnum*2];   /* 7-biciu Kodu lenteliu adresu poru sarasas, >> kptt.h
echo //                                    Null,Null - lenteles nera */ >> kptt.h
echo extern KpChar *Ctptr8[Ctnum*2];   /* 8-biciu Kodu lenteliu adresu poru sarasas */ >> kptt.h
echo // >> kptt.h
echo // >> kptt.h
echo /* =================================================== */ >> kptt.h
echo // Kpt lenteliu pavadinimai; former iaKptCtabExpl >> kptt.h
echo // look lpszaXmlCtblNames[] as well >> kptt.h
echo extern const unsigned char *lpszaKptCtabExpl[KPT_Ctnum+1]; >> kptt.h
echo // >> kptt.h
echo /* =================================================== */ >> kptt.h
echo extern KpChar KptUpLowTbl[];     /* upper-/lowercase conversion table */ >> kptt.h
echo // must be entered all letter characters, independently, have they lower/upper case or not >> kptt.h
echo extern KpChar KptLatUpLowTbl[];  /* upper-/lowercase conversion table for latin letters */ >> kptt.h
echo extern KpChar KptToLatTbl[C_CharSize0]; /* table for conversion to simple latin letters */ >> kptt.h
echo extern KpChar KptNoAccTbl[C_CharSize0]; // table for lithuanian accents skipping >> kptt.h
echo // >> kptt.h
echo /*------------------------------------*/ >> kptt.h
echo extern UniChar iaUniChars[C_CharSize0];  /* Unicode character codes */ >> kptt.h
echo // >> kptt.h
echo // ---------------- max length of Kpt Unicode strings >> kptt.h
echo #define KPT_UNI_STR_LEN 3 >> kptt.h
echo // converting of Kpt style characters to Kpt strings convertable to Unicode >> kptt.h
echo // use only for visualisation purposes, do not convert master documents >> kptt.h
echo extern KpChar iaszUniStrs[C_CharSize0][KPT_UNI_STR_LEN+1]; >> kptt.h
echo // >> kptt.h
echo /*------------------------------------*/ >> kptt.h
echo /* ar atskyrejas?                     */ >> kptt.h
echo // >> kptt.h
echo extern int w_delim cargs((int simb)); >> kptt.h
echo extern int c_delim cargs((int simb)); >> kptt.h
echo // >> kptt.h
echo // >> kptt.h
echo /*------------------------------------*/ >> kptt.h
echo extern HRESULT KptCharDecode(unsigned char *pcOutChar, KpChar uiInChar, int iKptTbl); >> kptt.h
echo                      // does not output error messages if the character is not >> kptt.h
echo                      //    found in given code table, returns KP_E_UNKN_CHR or KP_E_FONT_UNDEF only >> kptt.h
echo extern HRESULT KptCharEncode(KpChar *puiOutChar, unsigned char cInChar, int iKptTbl); >> kptt.h
echo // >> kptt.h
echo // >> kptt.h
echo extern HRESULT KptStrDecode(unsigned char *lpszOutStr, const KpChar *uiaMsg, /* int iMsgLen, */ int iKptTbl); >> kptt.h
echo                      // does not output error messages if the character is not >> kptt.h
echo                      //    found in given code table, returns KP_E_UNKN_CHR or KP_E_FONT_UNDEF only >> kptt.h
echo                      // adds Nul to the end of encoded lpszOutStr
echo extern HRESULT KptStrEncode(KpChar *uiaMsg, const unsigned char *lpszInStr, /* int *piMsgLen, */ int iKptTbl); >> kptt.h
echo                      // adds C_Nul to the end of encoded uiaMsg >> kptt.h
echo // >> kptt.h
echo extern HRESULT KptStrToUnicode(UniChar *saMsg, const unsigned char *lpszInStr, /* int *piMsgLen, */ int iKptTbl); >> kptt.h
echo extern HRESULT KptUnicodeToStr(unsigned char *lpszOutStr, const UniChar *saMsg, /* int iMsgLen, */ int iKptTbl); >> kptt.h
echo // >> kptt.h
echo extern HRESULT KptKpCharStrToUnicode(UniChar *saMsg, const KpChar *iaInStr, bool bDotLessToDot); >> kptt.h
echo // bDotLessToDot == True - convert C_i_Acute_Dotless to C_i_Acute, etc. >> kptt.h
echo extern HRESULT KptUnicodeToKpCharStr(KpChar *iaOutStr, const UniChar *saMsg); >> kptt.h
echo // >> kptt.h
echo extern HRESULT KptUTF8ToUnicode(UniChar *saMsg, const unsigned char *lpszInStr); >> kptt.h
echo // >> kptt.h
echo #endif >> kptt.h

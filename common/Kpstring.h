// ==================================================
// kpstring.h
// string processing
//

#ifndef kpstring_included
#define kpstring_included

// ===========================================
#if CompilerGr==Msvc
// typedef String string;
// #define String string
#define String CString
#endif


#if (CompilerGr==Watcom) && (__WATCOMC__ < 1202)
#define string KpString
#endif

// ===========================
#if CompilerGr==Mingw
// namespace std
#endif

// ================================================== string buffer with length for Windows EM_GETLINE message
#define LenString(name, length) union{ int len; unsigned char str[length + 1]; WCHAR wstr[length + 1]; } name = {length}; 

// ================================================== char string processing
class KpString
#if (CompilerGr==Msvc)
   : public string
// : public CString
#endif
#if (CompilerGr==Watcom) && (__WATCOMC__ < 1202)
   : public String
#endif
#if (CompilerGr==Mingw) || (__WATCOMC__ >= 1202)
   : public std::string
#endif
{
public:
#if (CompilerGr==Mingw) || (__WATCOMC__ >= 1202)
   unsigned char *m_lpszExtractedValue; // allocated result of ExtractValueA(), ExtractUnsignedValueA(), should be deleted during destruction
#endif

#if (CompilerGr==Watcom) && (__WATCOMC__ < 1202)
   KpString(void) : String() {};
   KpString(char const *lpszString, size_t __n = NPOS) : String(lpszString, __n) {};

// negalima ðitaip castint, tik þemyn !!!!
   KpString& operator= (char *lpszString){ return(static_cast<KpString &>(String::operator= (lpszString))); };
   KpString& operator= (const char *lpszString){ return(static_cast<KpString &>(String::operator= (lpszString))); };
   KpString& operator= (const unsigned char *lpszString){ return(static_cast<KpString &>(String::operator= ((const char *)lpszString))); };
   KpString& operator= (char cChar);

   KpString& erase(size_t /* size_type */ _Pos = 0, size_t /* size_type */ _Count = NPOS /* npos */);
#endif

#if (CompilerGr==Mingw) || (__WATCOMC__ >= 1202)
   KpString(void) : std::string() { InitMembers(); };
   KpString(std::string sString) : std::string(sString) { InitMembers(); };
// KpString(std::string &sString) : std::string(sString) { InitMembers(); };
// KpString(std::string *psString) : std::string(*psString) { InitMembers(); };

   ~KpString();

   void InitMembers(void);

// negalima ðitaip castint, tik þemyn !!!!
   KpString& operator= (char const *lpszString){ return(static_cast<KpString &>(std::string::operator= (lpszString))); };
   KpString& operator= (unsigned char const *lpszString){ return(static_cast<KpString &>(std::string::operator= ((char const *)lpszString))); };
   KpString& operator= (unsigned char *lpszString){ return(static_cast<KpString &>(std::string::operator= ((char const *)lpszString))); };

// char * operator= (KpString& sString) { return(sString.ExtractValueA()); };

   int index(const char *lpszSubString) { return(find(lpszSubString, 0)); };
#else
// const char *ExtractValueA(void) const { return(static_cast<const char *>(String::operator =(*this))); };
// const unsigned char *ExtractUnsignedValueA(void) const { return((const unsigned char *)static_cast<const char *>(String::operator =(*this))); };

#endif

#if (CompilerGr==Mingw) // || (__WATCOMC__ >= 1202)
// negalima ðitaip castint, tik þemyn !!!!
   KpString substr(int iPos, int iCnt) { return(static_cast<KpString>(std::string::substr(iPos, iCnt))); };
#elif (CompilerGr!=Watcom) || (__WATCOMC__ < 1202)
   KpString substr(int iPos, int iCnt) { return((*this)(iPos, /* iPos + */ iCnt)); };
#endif

   const unsigned char *ExtractUnsignedValueA(void) /* const */; // former ExtractUnsignedValue()
   const char *ExtractValueA(void) /* const */ { return((const char *)ExtractUnsignedValueA()); }; // former ExtractValue()

   HRESULT tolower(void);
};


// ================================================== char string processing
extern unsigned char *TvStrChr(const unsigned char *lpszString, KpChar iCh);
                           // the same, like strchr(), but iCh is 16-bit character
                           // (only 8-bit characters can conform the condition
extern unsigned char *TvStrChrArr(const unsigned char *lpszString, const unsigned char *lpszTestChars);
                           // the same, like strchr(), but testing is performed
                           //    with all characters from array lpszTestChars
extern int TvStrCmp(const unsigned char *lpszStr1, const unsigned char *lpszStr2, bool bSkipSpc, int iSortLng, bool bCaseSens, int iCtbl, bool bRoundFlg);
                           // like strcmp(), but compares using certain sorting order
                           // accented letters are treated as normal, and Y treated as I
                           // bSkipSpc - ignore all spaces
                           // iSortLng - letter order (look envir.h for SortMode)
                           // bCaseSens - case sensitivity flag
                           // iCtbl - code table of the strings
                           // if bRoundFlg==False, accented letters and Y are theyr own wage and are sorted separatelly
                           // 0: lpszStr1 == lpszStr2
                           // 1: lpszStr1 > lpszStr2
                           // -1: lpszStr1 > lpszStr2
extern int TvStrCmpStrict_(const void *lpszStr1, const void *lpszStr2);
                           // 0: lpszStr1 == lpszStr2
                           // 1: lpszStr1 > lpszStr2
                           // -1: lpszStr1 > lpszStr2

extern int TvStrPtrCmpStrict(const void *plpszStr1, const void *plpszStr2); // former TvStrCmpStrict
extern int TvStrPtrCmpStrictRev(const void *plpszStr1, const void *plpszStr2); // former TvStrCmpStrictRev
                           // simply variants of TvStrCmp() for qsort()
                           // TvStrCmpStrictRev - for reversed sorting
                           // plpszStrX pointers not to strings rather pointers to pointers to the strings
                           // compares using current sorting order SortMode
                           // uses 71 code table for lithuanian sorting SortMode==KP_LNG_LIT, KP_LNG_LIX or KP_LNG_LIS, 1 otherwise
                           // character wages are not rounded
                           // 0: *plpszStr1 == *plpszStr2
                           // 1: *plpszStr1 > *plpszStr2
                           // -1: *plpszStr1 > *plpszStr2

extern int TvStrPtrCmpStrictSkipSpcEx(const void *plpszStr1, const void *plpszStr2, bool bCutLastWord); // darbine, naudojama TvStrPtrCmpStrictSkipSpc() ir TvStrPtrCmpStrictSkipSpcCutLastWord()
extern int TvStrPtrCmpStrictSkipSpc(const void *plpszStr1, const void *plpszStr2); // former TvStrCmpStrict
extern int TvStrPtrCmpStrictSkipSpcCutLastWord(const void *plpszStr1, const void *plpszStr2); // former TvStrCmpStrict
extern int TvStrPtrCmpStrictRevSkipSpc(const void *plpszStr1, const void *plpszStr2); // former TvStrCmpStrictRev
                           // bSkipSpc = True

extern int TvStrMatch(const unsigned char *lpszStr1, const unsigned char *lpszStr2); // skaièiuoja, kiek sutampa simboliø nuo prad_ios

extern HRESULT CutTrailSpcs(unsigned char *lpszString, const unsigned char *spcs = lpszSpcEol);
extern HRESULT CutInitSpcs(unsigned char *lpszString, const unsigned char *spcs = lpszSpcEol);
extern HRESULT CutInitTrailSpcs(unsigned char *lpszString, const unsigned char *spcs = lpszSpcEol);

extern HRESULT RemoveSpaces(unsigned char *lpszString); // removes all spaces inside of string
extern HRESULT RemoveSpacesCode(unsigned char *lpszString); // removes all spaces except those inside of C++ like string litterals
extern HRESULT RemoveSpCharsSpc(unsigned char *lpszString); // removes dots, dashes and spaces - for index searching/sorting // former RemoveSpChars
extern HRESULT RemoveSpCharsCom(unsigned char *lpszString); // removes dots, dashes, etc, comments inside [], single letters, digits and converts endlines to spaces (for copy/paste from dictionary output window)

extern HRESULT ExtractStringLitteral(unsigned char *lpszStrBuffer, const unsigned char *lpszString); // skanuoja lpszString pagal C++ teksto literalo sintaksæ
                                       // lpszString su kabutëm, á lpszStrBuffer raðo be kabuèiø ir iðverèia escape simbolius

// -------------------------------------------
extern HRESULT SpcEolToSpc(unsigned char *lpszString); // sutraukia pasikartojanèius tarpus á vienà
extern HRESULT DoubleCrToSingle(unsigned char *lpszString); // sutraukia pasikartojanèius '\n' á vienà

// -------------------------------------------
extern unsigned char *TvSpcs(int iSpcCnt);   // returns pointer to string, consisting
                                             //    of iSpcCnt spaces

// -------------------------------------------
// prideda po '\' pries kiekviena jau esanti '\' - isvedimui i perlo scriptus
// grazina lpszOutStr
extern unsigned char *DoubleEscape(unsigned char *lpszOutStr, const unsigned char *lpszInStr);

// -------------------------------------------
extern unsigned char *strcpy(unsigned char *dest, const unsigned char *src);
extern unsigned char *strcpy(unsigned char *dest, const char *src);
extern unsigned char *strncpy(unsigned char *dest, const unsigned char *src, size_t nbytes);
// extern unsigned char *strncpy(unsigned char *dest, const unsigned char *src, int nbytes) { return(strncpy(dest, src, (size_t)nbytes)); };
extern unsigned char *strncpy(unsigned char *dest, const char *src, size_t nbytes);
extern int /* size_t */ strlen(const unsigned char *src);
extern unsigned char *strcat(unsigned char *dest, const unsigned char *src);
extern unsigned char *strcat(unsigned char *dest, const char *src);
extern unsigned char *strchr(const unsigned char *src, unsigned char ch);
extern unsigned char *strstr(const unsigned char *src, const unsigned char *substr);
extern unsigned char *strstr(const unsigned char *src, const char *substr);
extern int strcmp(const unsigned char *str1, const unsigned char *str2);
extern int strcmp(const unsigned char *str1, const char *str2);
extern int strcmp(const char *str1, const unsigned char *str2);

// galima kopijuoti substringa atgal - kopijuoja is kaires i desine.
extern unsigned char *TvStrCpy(unsigned char *dest, const unsigned char *src);

// -------------------------------------------
#define fstrcpy(a,b) (strcpy((a), (b)))
#define fstrncpy(a,b,n) (strncpy((a), (b), (n)))
#define fstrlen(a) (strlen(a))
#define fstrcat(a,b) (strcat((a), (b)))
#define fstrchr(s,c) strchr((s), (c))
#define fstrstr(a,b) strstr((a), (b))


// ================================================== KpChar string processing
extern int TvKpStrCmp(const KpChar *iazStr1, const KpChar *iazStr2); // former TvIntStrCmp
                           // like strcmp(), but compares two Kpt 16-bit character
                           //    C_Nul-terminated strings
                           // correct character weights not implemented yet
extern int TvKpStrCmp(const KpChar *iazStr1, const KpChar *iazStr2, bool bDotLessToDot);
                           // bDotLessToDot == True ignore differencies between C_i_Acute_Dotless and C_i_Acute, etc.
extern const KpChar *TvKpStrChr(const KpChar *piazStr, KpChar iChar); // former TvIntStrChr
                           // strchr() or TvStrChr() analog for Chars16 strings, former TvIstrInt()
extern const KpChar *TvKpStrStr(const KpChar *piazSrc, const KpChar *piazSubStr); // former TvIntStrStr
                           // finds substring piazSubStr inside of string iazSrc
                           // like strstr(), but compares two Kpt 16-bit character
                           //    C_Nul-terminated strings
                           // correct character weights not implemented yet
extern KpChar *TvKpStrCpy(KpChar *piazStr1, const KpChar *piazStr2); // former TvIntStrCpy
                           // like strcpy(), copies piazStr2 to piazStr1 as Kpt
                           //    character C_Nul-terminated strings
extern KpChar *TvKpStrNCpy(KpChar *piazStr1, const KpChar *piazStr2, int iBufSize); // former TvIntStrNCpy
                           // like strncpy(), copies piazStr2 to piazStr1 as Kpt
                           //    character C_Nul-terminated strings, no more, than
                           //    iBufSize chars
                           //    if all iBufSize chars are copied, no C_Nul character
                           //    is added to the end of the string
extern int TvKpStrLen(const KpChar *piazStr); // former TvIntStrLen
                           // like strlen(), returns count of Kpt character in
                           //    C_Nul-terminated string iazStr
extern KpChar *TvKpStrChCat(KpChar *piazStr, KpChar iChar); // former TvIntStrChCat
                           // adds one Kpt character iChar to the end of Kpt string piazStr
extern KpChar *TvKpStrCat(KpChar *piazDest, const KpChar *piazSrc); // former TvIntStrCat
                           // concatenates piazDest and piazSrc like strcat()

extern HRESULT CutTrailSpcsKp(KpChar *iazString); // former CutTrailSpcsInt
extern HRESULT CutInitSpcsKp(KpChar *iazString); // former CutInitSpcsInt
extern HRESULT CutInitTrailSpcsKp(KpChar *iazString); // former CutInitTrailSpcsInt

extern HRESULT RemoveSpKpCharsSpc(KpChar *iazString); // removes spaces, dots, dashes - for index searching/sorting // former RemoveSpKpChars
extern HRESULT RemoveSpKpCharsCom(KpChar *iazString); // removes dots, dashes, etc, comments inside [], single letters, digits and converts endlines to spaces (for copy/paste from dictionary output window)

extern HRESULT KpSpcEolToSpc(KpChar *iazString); // sutraukia pasikartojanèius tarpus á vienà

extern KpChar *TvStr2Kp(KpChar *piazDest, const unsigned char *lpszSrc); /// former TvStr2Int
                           // converts lpszSrc as 7-bit ASCII string to piazDest as
                           //    Kpt character C_Nul-terminated string
// can be changed to KptStrEncode(piazDest, lpszSrc, /* int *piMsgLen, */ 1);

// string'u palyginimas per pointeri
extern int Tv_string_Cmp(const void /* string */ *psStr1, const void /* string */ *psStr2);

// ================================================= common text array functions
extern int TvGetArraySize(void **ppaPtrArray); // counts size of NULL terminated array of pointers

extern HRESULT GetWord(const unsigned char **lpszpStrPtr, unsigned char *lpszWordBuf, const unsigned char *lpszDelims, unsigned char *pcDelim);
                     // skanuoja nuo *lpszpStrPtr, gràþina *lpszpStrPtr po nuskanuoto þodþio ir po skirtuko
                     // gràþina sutiktà skirtukà á *pcDelim
                     // lpszWordBuf turi bûti toks, kad tilptø þodis, paprastai tokio pat ilgio, kaip ir skanuojamas buferis

extern HRESULT SplitWordsI(KpChar *iazWordsBuf, KpChar **piazWordsPts, const KpChar *iazTextToSplit, int iMaxNumOfWords);
                     // splits C_Nul-terminated Chars16 string to words
                     // piazWordsPts[iMaxNumOfWords] - buffer for word pointers
                     // returns pointers to C_Nul-terminated Chars16 text words to **piazWordsPts
                     // NULL-pointer means end of pointers array
                     // iazWordsBuf - buffer to place words, must be of length, not shorter than iazTextToSplit
                     //    displacement of characters identical to iazTextToSplit, only spaces (and delimiters?)
                     //    are changed to C_Nul
                     // iMaxNumOfWords+1 - size of *piazWordsPts, iMaxNumOfWords==KP_MAX_NUM_OF_WORDS normally
extern HRESULT SplitWords(unsigned char *lpszWordsBuf, unsigned char **plpszWordsPts, const int *iazTextToSplit, int iMaxNumOfWords, int iKptCtbl);
                     // char analog of SplitWordsI, converts Chars16 words to char words, using codetable iKptCtbl
                     // does not output error messages if the character is not
                     //    found in given code table, returns KP_E_UNKN_CHR only
extern HRESULT CountStrings(int *piStrsCount, unsigned char *lpszStringsBuf, const unsigned char *lpszDelimStr, bool bExactDelims);
                     // former CountWords
                     // jei lpszDelimStr==lpszEols ir bExactDelims==False, neskaiciuoja tusciu eiluciu
extern HRESULT SplitStrings(unsigned char ***pPtrArrPtr, int *piStrsCount, unsigned char *lpszStringsBuf, const unsigned char *lpszDelimStr, bool bExactDelims);
                     // former SplitToWords
                     // converts buffer lpszStringsBuf of strings/fields/words into array of pointers to null-terminated strings
                     // *pPtrArrPtr - also NULL-terminated array of pointers
                     // string positions are left unchanged, string ends are converted to Nul characters
                     // corrupts lpszStringsBuf - adds Nul's to word ends
                     // lpszDelimStr - string of all possible delimiters
                     // allocates place for pointers array *pPtrArrPtr - must be deleted by caller after use
                     // if bExactDelims==True - only one delimiter per field should be used

// -------------------------
HRESULT ReplaceSubstr(unsigned char *lpszInBuf, const unsigned char *lpszKeyName, const unsigned char *lpszKeyValue, long lBufLen);

// ================================================== memory management
extern unsigned char chuge *msbcpy(unsigned char chuge *out, const unsigned char chuge *in); /* skips spaces */
extern unsigned char chuge *msncpy(unsigned char chuge *out, const unsigned char chuge *in, int count); /* islygina lygiai iki count - u_pildo tarpais */



#endif // #ifndef kpstring_included

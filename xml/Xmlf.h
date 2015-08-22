// ==================================================
// xmlf.h
// XML file (main or index)
// second lowest level definitions
// XMLT tagø procesinimas ir indeksai (indeksai galëtø bût organizuojami ir þemesnio lygio failais)
// naudoja interfeisus á þemesnio lygio KpFile


#ifndef xmlf_included
#define xmlf_included


// =================================================== definitions
// ---------------------------------------------------
#define TV_XL_NUM_LEN 10      // width of main index entries and pointers to XML
                              //    data file in textual stage (generally of all
                              //    numbers)
#define TV_XL_MAX_IX_LEN 100  // max width of all kinds of indexes // former TV_XM_MAX_IX_CONTENTS_WDT

typedef enum
{
   XL_IX_DefNoIndex=(-1),
   XL_IX_DefDataFile,      // XML data file
   XL_IX_DefSeIndex,       // standard entry index file

   XL_IX_NumOfDefIndexes

} XL_DefIndexes;          // indexes to default arrays of XML data/index files

typedef enum
{
   XL_RelativePath,  // src="img\diamond.jpg"
   XL_AbsolutePath,  // src="F:\kp\source\Tev\lzdsh\img\diamond.jpg", "F:\kp\source\Tev\lzdsh\" - ið GetCurrentDirectory(), MSHTML-ui
   XL_TuxPath,       // src="tux:///img\diamond.jpg" // src="tux:img\diamond.jpg" - XGecko

} XL_PathMode; // href ir src parametrø - failø vardø - formavimo bûdas

// --------------------------
#define TV_XL_UNGET_BUF_SIZ TV_XM_MAX_TAG_CONTENTS_WDT // TvXmlFile::UnGetChar() buffer size

#define TV_XML_CHAR_POS_THRESHOLD 60

#define TV_XL_TAG_BUF_SIZE (XL_MaxNumOfTags*TV_XL_MAX_TAG_WDT)

// --------------------------------------------------
extern unsigned char lpszDictTaggingDelims[]; // skirtukai, pagal kuriuos TvXmlFile::PutCharProc() tagina þodþius lzdsh.exe þokinëjimui per linkus // = "/* \t\xA0"; // C_NBSP

// =================================================== class TvXmlFile
// --------------------------------------------------
class TvXmlFile
{
   XL_FileTypes m_uiFType;
   unsigned char m_lpszFName[KP_MAX_FNAME_LEN+1]; // file name

   HRESULT m_lhOpenResult;

public:
   KpFile *m_lpLowLevelFile;       // pointer to common low level file class object
private:
   FILE *m_lpRawFile;              // pointer to FILE structure of lpLowLevelFile

   int m_iIxWdt;                   // length of textual part of the index

   bool m_bMultiLine;   // indented file format, if ==False - single line per entry

   unsigned char m_lpszBaseIndentStr[TV_TAG_LEN+1];   // indent string for one tab, used for m_lpszIndentStr calculation
                                                      // veikia ir kaip indento indikatorius - jei == "", indento nenustato ið viso
   unsigned char m_lpszIndentStr[TV_TAG_LEN+1];
                                 // new line indent string, with newline character first
                                 // concatenated of m_lpszBaseIndentStr strings

   KpChar m_iaUnGetBuf[TV_XL_UNGET_BUF_SIZ];     // UnGetChar() variables
   int m_iUnGetCnt;

   int m_bUnGetChProcCnt;      // UnGetCharProc buffers
   KpChar m_iUnGetChProcBuf[TV_XL_UNGET_BUF_SIZ];
   XmlTagPars *m_pUnGetChPars[TV_XL_UNGET_BUF_SIZ];

   const unsigned char * const *m_plpszaXmlSpecCharTags; // [C_CharSize0], pointer to XML character entities array

// ------------------
   KpChar m_iFirstDictTag;       // first tag code as 16-bit character
   KpChar m_iLastDictTagOrig;    // initial code one after last tag in m_plpszaTagNamesOrig[] and m_piaCodeTables[] // former m_iLastDictTag
   KpChar m_iLastDictTagCurrent; // code one after last tag in m_lpszaTagNames,
                                 // dynamically calculated to correspond contents of m_lpszaTagNames during file reading

   const unsigned char * const *m_plpszaTagNamesOrig;  // former m_plpszaTagNames
                                                // pointer to original XML dictionary tag names,
                                                // even entries - opening tags with '<' and '>', odd - closing
                                                //    tags with possible delimiters
                                                //    closing tags for single tags (</ttt>) must be ""
   unsigned char *m_lpszaTagNamesArray[XL_MaxNumOfTags]; // local array of tag names, dynamically filled during file reading
                                                // points to m_lpszaTagNamesBuf[]
                                                // initially - copy of m_plpszaTagNamesOrig
   const unsigned char * const *m_lpszaTagNames; // pointer to tag names array - local m_lpszaTagNamesArray or external
   unsigned char m_lpszaTagNamesBuf[TV_XL_TAG_BUF_SIZE + 1]; // local array of tag names, dynamically filled during file reading
   unsigned char *m_lpszaTagNamesBufPtr; // pointer to the end of last tag name in m_lpszaTagNamesBuf - free region start

   const int *m_piaCodeTablesOrig;  // former m_piaCodeTables, must be changed to GetTagCodeTable()
                                    // code table array for XML tags, array size [iLastDictTag-iFirstDictTag]
                                    // 0 values mean default code page, red from datafile or set
   int m_iDefCodeTable;

// ---------------
   XmlVersions m_iXmlVers;    // XML version identifier - HTML v4.0, XML v1.0, etc.

   XL_PathMode m_iPathMode;   // former bool m_bAbsPaths; // ar generuoti pilnus kelius href ir src HTML parametruose (reikia MSHTML'ui)

   int m_iScale;              // fonto dydis, 10 - 100%, 15 - 1.5 karto padidintas

public:

   TvXmlTagStack *m_lpTagStack;

// ------------------------------------- init
   TvXmlFile
   (
      const unsigned char *lpszFileName,
      const unsigned char *lpszMode,
      XL_FileTypes uiFileType,
      XmlfLowLevelCrFunPtr CreateLowLevelObj,
      const unsigned char * const *plpszaXmlSpCharTags,
      int iIndexWidth,
      KpChar iFirstTag,
      const unsigned char * const *plpszaTags,
      bool bExternalTagsArray,
      XmlVersions iVersion,
      const int *piaCodeTables,
      bool bMultiLine,
      bool bMapToPrivate
   );
                                       // lpLowLevelObjPtr - pointer to low
                                       //    level file class object
                                       // Uses lpLowLevelFile->GetFilePtr()
                                       // plpszaXmlSpCharTags[C_CharSize0] - pointer to XML character entities array
                                       // iFirstTag - first XML tag code as 16-bit character
                                       // plpszaTags - array of tag names, last entry must be ==NULL
                                       //    even entries - opening tags with '<' and '>', odd - closing
                                       //    tags with possible delimiters
                                       //    closing tags for single tags (</ttt>) must be ""
                                       // bExternalTagsArray - jei False - procesinti naujus tagus lokaliai - pildyti m_lpszaTagNamesArray[]
                                       //    jei True - naudoti kaip iðoriná pointerá, pildomà kitame faile, dinamiðkai persiskaièiuojant
                                       //    tik m_iLastDictTagCurrent
                                       // iVersion - XML version identifier - HTML, XML-1.1, etc.
                                       // piaCodeTables - low level file code tables
                                       //    (applicable for 8-bit HTML or SGML Tage files)
                                       //    one entry for each XML tag
                                       //    array of 0 entries for Unicode files
                                       // bMultiLine - indented file format, if ==False - single line per entry
   ~TvXmlFile();

   HRESULT GetOpenResult(void);        // Returns value of OpenResult -
                                       //    object creation error code

   KpChar GetLastTag(void);   // skanuoja m_lpszaTagNames[] ir uþpildo m_iLastDictTagCurrent;
                              // m_iFirstDictTag jau turi bûti nustatytas, o m_iLastDictTagCurrent turi bûti didesnis uþ m_iFirstDictTag -
                              // rodyti á m_lpszaTagNames[] elementà

   bool CheckLastTag(KpChar iTag); // True - blogai, tikrina, ar iTag >= m_iLastDictTagCurrent

   const unsigned char * const *GetTagsArrPtr(void) const {return(m_lpszaTagNames);};
   const unsigned char *GetTagName(KpChar iTag) {return(::GetTagName(iTag, m_lpszaTagNames, m_iFirstDictTag, m_iLastDictTagCurrent));};
                              // gràþina m_lpszaTagNames[iTag - m_iFirstDictTag];

   HRESULT GetVersion(XmlVersions *piVersion);     // Gets XML version - value of m_iXmlVers

   HRESULT GetFileType(XL_FileTypes *puiFileType);  // Gets file type - value of m_uiFType

// -------------------------------------
// get/set file encoding parameters
   HRESULT GetEncoding(UC_Modes *piEncodingMode, int *piCodeTable, int *piDefCodeTable);
   HRESULT SetEncoding(UC_Modes iEncodingMode, int iCodeTable, int iDefCodeTable);

   int GetTagCodeTable(KpChar iTag, // gràþina m_piaCodeTablesOrig[iTag - m_iFirstDictTag]
      KpChar iFirstTag = C_Nul /* m_iFirstDictTag */, KpChar iLastTag = C_Nul /* m_iLastDictTagOrig */ /* m_iLastDictTagCurrent */,
      const int *piaCodeTables = NULL /* m_piaCodeTablesOrig */);

   HRESULT GetCurTag(/* enum XmlDictChars */ KpChar *piCurTag);

   HRESULT GetMultiline(bool *pbMultiLine);
   HRESULT SetMultiline(bool bMultiLine); // gets/sets value of member m_bMultiLine

   HRESULT SetPathMode(XL_PathMode iPathMode) { m_iPathMode = iPathMode; return(S_OK); } // nustato m_iPathMode // former HRESULT SetAbsPaths(bool bAbsPaths);
   XL_PathMode GetPathMode(void) { return(m_iPathMode); } // perskaito m_iPathMode // former bool GetAbsPaths(void);

   HRESULT SetScale(int iScale) { m_iScale = iScale; return(S_OK); };  // nustato m_iScale
   int GetScale(void) { return(m_iScale); }  // perskaito m_iScale

   HRESULT Reset(void); // reset RAM file

   HRESULT CloseFile(bool bCheckFileExist);
                                 // Closes current Xml file
                                 //   this call makes sence only for result code retrieving,
                                 //   after CloseFile() no other calls except ~TvXmlFile
                                 //   are acceptable
                                 // bCheckFileExist - if not set, no file
                                 //    presence will be tested
                                 //    uses lpLowLevelFile->CloseFile()

// ------------------------------------- low level text output
   HRESULT PutChar(KpChar iOutch, bool bCheckErrors);
                                 // Put character to file
                                 //    uses lpLowLevelFile->PutChar()
                                 // if bCheckErrors=False, no error message
                                 //    will be output in case of nonexisting
                                 //    OUTPUT equivalent, TV_E_UNKN_CHR
                                 //    is returned in this case

// ------------------------------------- text output
   HRESULT PutCharProc
   (
      KpChar iOutch,
   /* const */ XmlTagPars *pTagPars,
      bool bCheckIndex
   );                                  // Put character to file
                                       //    pTagPars - parameters for XML tags.
                                       // bCheckIndex is used to swich on index
                                       //    overflow checking
                                       //    Uses lpLowLevelFile->PutChar()

   HRESULT PutCharExp(KpChar iOutch);     // Expand Kpt chars to sequences convertable to Unicode according to iaszUniStrs[][]
                                       // use only for visualisation purposes, not for master documents output

   HRESULT PutStr(const unsigned char *lpszOutstr);
                                       // Put string to file
                                       //    Does not check index overflow
                                       //    Uses PutCharProc()

   HRESULT PutKpStr(const KpChar *iazOutstr); // former PutIntStr
                                       // Put Kpt 16-bit character string to file
                                       //    Does not check index overflow
                                       //    Uses PutCharProc()

   HRESULT PutNumVal(const long lValue);
                                       // Put numeric value, formatting as long decimal
                                       //    integer.
                                       //    Does not check index overflow
                                       //    Uses PutCharProc()

   HRESULT CompleteIndexEntry(void);   // Puts spaces to output file, while index
                                       //    width is reached
                                       //    Uses PutCharProc()

   HRESULT GetCharPos(int *piCharPos); // Current character position from beginning of the line
   HRESULT GetCharNum(long *plCharNum);// Current char position from beginning of the file

   HRESULT SetBaseIndent(const unsigned char *lpszBaseIndent);
   HRESULT GetBaseIndent(const unsigned char **plpszBaseIndentPtr);
   HRESULT SetIndent(const unsigned char *lpszIndent);
                                       // set indent string for new lines

   HRESULT IncIndent(void);            // increment/decrement of indent string for new lines
   HRESULT DecIndent(void);


   HRESULT CompleteOpenTags(KpChar iTag); // puts closing tags until iTag is reached
                                       //     frees the tag stack lpTagStack

// ------------------------------------- low level text input
   HRESULT GetChar(KpChar *piInch, bool bCheckFeof);
                                 // Gets current char. from file
                                 // bCheckFeof is used to swith on end of file error
                                 //    output
                                 // Uses ucUnGetBuf, lpLowLevelFile->GetChar()

   HRESULT GetCharSkipSpc(KpChar *piInch, bool bCheckFeof);
                                 // Gets first non space (Spc, Tab, Eol's) char. from file
                                 // Uses GetChar();

   HRESULT UnGetChar(unsigned char cChar);
   HRESULT UnGetChar(KpChar iChar);
                                 // Put char. back to input stream for
                                 //    lpLowLevelFile->GetChar()
                                 //    Uses ucUnGetBuf

   HRESULT Fscanf(const char *lpszFormat, void *pValue);
                                 // like fscanf(*lpRawFile, lpszFormat, pValue);

   HRESULT GetNumVal(long *plValue, bool bCheckFeof);
                                    // Scans file as text for first occurence of
                                    //    decimal long number
                                    //    Uses Fscanf()
                                    // Does not take into account
                                    //    UngetChar() presence, so
                                    //    GetNumVal() can not be used after SkipEol()
                                    // bCheckFeof is used to swith on end of file error
                                    //    output

   HRESULT SkipEol(void);           // skips spaces and tabs and eols until first eol
                                    //    is reached
                                    // uses lpLowLevelFile->GetChar(), UngetChar()

   HRESULT SkipSpaces(void);        // skips spaces and tabs and eols
                                    // uses lpLowLevelFile->GetChar(), UngetChar()


// ------------------------------------- text input with XML tag formatting
   HRESULT GetCharProc
      (
      KpChar *piInch,
      XmlTagPars **ppTagParsPtr,
      bool bCheckFeof,
      bool bProcSpcEol
      );
                                 // Gets current char. from file, scans numeric and
                                 //    text parameters of XML tags
                                 // *pTagParsPtr - pointer to returned tag parameter list
                                 //    if pTagParsPtr==NULL - parameters will not be returned
                                 //    if returned pointer *pTagParsPtr!=NULL, it must be deleted by calling application
                                 // bCheckFeof is used to swith on end of file error
                                 //    output
                                 //    Uses GetChar(), UnGetChar(), Fscanf()
                                 // bProcSpcEol - collect multiple spaces ant eols to one space

   HRESULT TestTagEnd(const unsigned char *lpszTagEndStr, bool *pbFound, bool bUngetFl);
         // tikrina, ar input faile laukiantys simboliai sutampa su tago pabaigos eilute lpszTagEndStr
         // vidinë funkcija, iðkvieèiama ið GetCharProc()
         // pirmas pabaigos poþymio simbolis lpszTagEndStr[0] jau perskaitytas, iðeinant taip ir palieka
         // bUngetFl == True - gràþina failo pointerá á buvusià vietà
         // bUngetFl == False - palieka po paskutinio perskaityto lpszTagEndStr[] simbolio
         //    jei nesutapo - lieka po paskutinio nesutapusio
         //    negràþina paskutinio perskaityto - kartais gali prireikti

   HRESULT UnGetCharProc(KpChar iInch, XmlTagPars *pTagParsPtr);
               // after unget *pTagParsPtr can be deleted

   HRESULT TestPars(KpChar iChar, XmlTagPars *pTagParsPtr);
                                 // tests parameters of some tags

   HRESULT SkipToCharProc(KpChar iDelimCh);
                                 // Applies GetCharProc() until uiDelimCh is reached

// ---------------------------------------- binary output
   HRESULT PutImage(const void *lpBuffer, const int iByteCount);
                                 // puts buffer as binary image to file
                                 // like fwrite(lpBuffer, 1, iByteCount, *lpRawFile);

   HRESULT PutLong(const long lValue);
                                 // puts long integer binary image to file
                                 // Uses PutImage()

// ------------------------------------- binary input
   HRESULT GetImage(void *lpBuffer, const int iByteCount, bool bCheckFeof);
                                 // gets binary image from file to buffer
                                 // Takes into account fFiles[].UngetChar(),
                                 //    can be used after SkipEol()
                                 // bCheckFeof is used to swith on end of file error
                                 //    output
                                 // like fread(lpBuffer, 1, iByteCount, *lpRawFile);

   HRESULT Fseek(long lOffset, int iOrigin);
                                    // analog of fseek();

   HRESULT Ftell(long *plOffset);   // analog of ftell();

};

extern const unsigned char *plpszaDefTagNames[]; // default XML tags array, when not used

#endif

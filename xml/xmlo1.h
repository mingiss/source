// ==================================================
// xmlo1.h
// XML dictionary input/output multifile definitions (data+indexes)
//


#ifndef xmlo1_included
#define xmlo1_included


// ================================================== class XmlO1
class XmlO1
{
public:
   HRESULT m_lhOpenResult;

   unsigned char m_lpszFName[KP_MAX_FNAME_LEN+1];  // file name
private:
   unsigned char m_lpszFMode[TV_TAG_LEN+1];        // file open mode (like fopen())

   const unsigned char * const *m_lppszFileIndexNamesPtr; // array of index files names extentions
   int m_iNumOfIndexes;                            // number of index files
public:
   const int *m_aiFileIndexLengthsPtr;             // array of index entries lengths

   TvXmlFile *m_fFiles[XL_IX_MaxNumOfIndexes]; // array of pointers to data/index files
   TvXmlFile *m_fRepFiles[XL_IX_MaxNumOfIndexes]; // array of pointers to index conversion report files

// ------------------------------- open file
   XmlO1
   (
      const unsigned char *lpszFname,
      const unsigned char *lpszMode,
      HRESULT CreateLowLevelObj
      (
         KpFile **lppFileObjPtrPtr,
         const unsigned char *lpszFNam,
         const unsigned char *lpszFMod,
         XL_FileTypes uiFTyp,
         bool bMapToPrivate
      ),
      const unsigned char * const *plpszaXmlSpCharTags,
      const unsigned char * const *lppszFileIndexNames,
      const int *aiFileIndexLengths,
      KpChar iFirstTag,
      const unsigned char * const *plpszaTags,
      bool bExternalTagsArray,
      XmlVersions iVersion,
      const int *piaCodeTables,
      bool bMultiLine,
      bool bMapToPrivate
);                            // Opens all necessary files in array fFiles
                                 // lpszMode - file open mode, considering fopen()
                                 //    rules.  If contains letter 'b', there will be
                                 //    opened all binary indexes "*.ix", otherwise -
                                 //    textual indexes "*.ixt".  Data file
                                 //    will be opened only in BINARY READ MODE
                                 //    or in TEXTUAL WRITE MODE.
                                 // All files in fFiles for the opening will be
                                 //    cleared - if they were not closed in previous
                                 //    sessions, all information about them will be
                                 //    lost
                                 // plpszaXmlSpCharTags[C_CharSize0] - pointer to XML character entities array
                                 // lppszFileIndexNames - array of names of XML index files - extentions
                                 //    to main XML file name.  First entry must be "" - reserved for
                                 //    XML data file itself. Last entry must be ==NULL, pointing count
                                 //    of index files.  If lppszFileIndexNames==NULL - no index files
                                 //    will be used, aiFileIndexLengths must be also ==NULL in this case
                                 // aiFileIndexLengths - array of lengths of index entries - num of bytes
                                 //    in search part + sizeof(long) for preceeding pointers to data file.
                                 //    First entry must be ==0 - reserved for XML data file itself.
                                 //    aiFileIndexLengths must be ==NULL, if lppszFileIndexNames==NULL
                                 // iFirstTag - first XML tag code as 16-bit character
                                 // plpszaTags - array of tag names, last entry must be ==NULL
                                 //    even entries - opening tags with '<' and '>', odd - closing
                                 //    tags with possible delimiters
                                 //    closing tags for single tags (</ttt>) must be ""
                                 // iVersion - XML version identifier - HTML, XML-1.1, etc.
                                 // piaCodeTables - code tables array for tags,
                                 //    applicable only for plain text files
                                 //    for Unicode files table must contain 0 values for all tags
                                 // bMultiLine - indented file format, if ==False - single line per entry
   ~XmlO1();

   HRESULT GetOpenResult(void);        // Returns value of OpenResult -
                                       //    object creation error code

   HRESULT GetFileType(XL_FileTypes *puiFileType, int iFileIndex);
                                       // Returns file type
                                       //    Uses fFiles[iFileIndex]

   HRESULT GetFileMode(bool *pbBinFl, bool *pbWriteFl, bool *pbAppendFl);
                                       // tests whether file is binary, output and for append

// get/set file encoding parameters
   HRESULT GetEncoding(UC_Modes *piEncMode, int *piCodeTable, int *piDefCodeTable);
   HRESULT SetEncoding(UC_Modes iEncMode, int iCodeTable, int iDefCodeTable);

   HRESULT GetVersion(XmlVersions *piVersion);     // Gets XML version - value of iXmlVers

   HRESULT GetCurTag(/* enum XmlDictChars */ KpChar *piCurTag);

   HRESULT SetPathMode(XL_PathMode iPathMode); // former HRESULT SetAbsPaths(bool bAbsPaths);
   XL_PathMode GetPathMode(void); // former bool GetAbsPaths(void);

   HRESULT SetScale(int iScale);
   int GetScale(void);

   HRESULT Reset(void); // reset RAM file

   HRESULT CloseFile(bool bCheckFileExist);
                                       // Closes current Xml file
                                       //    this call makes sence only for result code retrieving,
                                       //    after CloseFile() no other calls except ~TvXmlO_tag()
                                       //    are acceptable
                                       //    Uses fFiles[iFileIndex]
                                       //    if bCheckFileExist==FALSE, error messages will be supressed

// -------------------------------
   KpChar GetLastTag(void);  // calculates and gets value of fFiles[XL_IX_DefDataFile]->m_iLastDictTagCurrent
                             // C_Nul on error
   const unsigned char * const *GetTagsArrPtr(void) const; // gets pointer to fFiles[XL_IX_DefDataFile]->m_lpszaTagNames

// ------------------------------- text input
   HRESULT GetCharProc
   (
      KpChar *piInch,
      XmlTagPars **pTagParsPtr,
      int iFileIndex,
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
                                 // bProcSpcEol - collect multiple spaces ant eols to one space
                                 // Uses lpfFilePtr

   HRESULT UnGetCharProc(KpChar iOutch, XmlTagPars *pTagPars, int iFileIndex);
                                       // unget character to file

   HRESULT GetNumVal(long *plValue, int iFileIndex, bool bCheckFeof);
                                    // Scans file as text for first occurence of
                                    //    decimal long number
                                    // Does not take into account
                                    //    fFiles[].UngetChar() presence, so
                                    //    GetNumVal() can not be used after SkipEol()
                                    // bCheckFeof is used to swith on end of file error
                                    //    output

   HRESULT SkipEol(int iFileIndex);
                                    // skips spaces and tabs and eols until first eol
                                    //    is reached
                                    // uses fFiles[].SkipEol()

   HRESULT SkipSpaces(int iFileIndex);
                                    // skips spaces and tabs and eols
                                    // uses fFiles[].SkipSpaces()

   HRESULT SkipToCharProc(KpChar uiDelimCh, int iFileIndex);
                                    // skips input file chars, until uiDelimCh is reached

// ------------------------------- text output
   HRESULT PutCharProc
   (
      KpChar iOutch,
      XmlTagPars *pTagPars,
      int iFileIndex
   );                                  // Put character to file
                                       //    pTagPars - parameters for XML tags.
                                       //    Uses fFiles[iFileIndex]

   HRESULT PutRepCharProc
   (
      KpChar iOutch,
      int iFileIndex
   );                                  // Put character to report file
                                       //    Uses fRepFiles[iFileIndex]

   HRESULT PutStr(const unsigned char *lpszOutstr, int iFileIndex);
                                       // Put string to file
                                       //    Uses PutCharProc()

   HRESULT PutRepStr(const unsigned char *lpszOutstr, int iFileIndex);
                                       // Put string to report file
                                       //    Uses PutRepCharProc()

   HRESULT PutKpStr(const KpChar *iazOutstr, int iFileIndex); // former PutIntStr
                                       // Put Kpt char string to file
                                       //    Uses PutCharProc()

   HRESULT PutRepKpStr(const KpChar *iazOutstr, int iFileIndex); // former PutRepIntStr
                                       // Put Kpt char string to report file
                                       //    Uses PutRepCharProc()

   HRESULT PutNumVal(const long lValue, int iFileIndex);
                                       // Put numeric value, formatting as long decimal
                                       //    integer.
                                       //    Uses fFiles[iFileIndex]

   HRESULT CompleteIndexEntry(int iFileIndex);
                                       // Puts spaces to output file, while index
                                       //    width is reached
                                       //    Uses fFiles[iFileIndex]

   HRESULT GetCharPos(int *piCharPos, int iFileIndex);
                                       // Returns output character position in the
                                       //    output text row
                                       //    Uses fFiles[iFileIndex]

   HRESULT GetCharNum(long *plCharNum, int iFileIndex);
                                       // Returns output character position in the
                                       //    output file
                                       //    Uses fFiles[iFileIndex]

   HRESULT SetBaseIndent(const unsigned char *lpszBaseIndent, int iFileIndex);
   HRESULT GetBaseIndent(const unsigned char **plpszBaseIndentPtr, int iFileIndex);
   HRESULT SetIndent(const unsigned char *lpszIndent, int iFileIndex);
                                       // set indent string for new lines

   HRESULT IncIndent(int iFileIndex);  // increment/decrement of indent string for new lines
   HRESULT DecIndent(int iFileIndex);

   HRESULT CompleteOpenTags(KpChar iTag, int iFileIndex);
                                       // puts closing tags until iTag is reached
                                       //     frees the tag stack fFiles[XL_IX_DefDataFile]->lpTagStack


// ------------------------------- binary input
   HRESULT GetImage
   (
      void *lpBuffer,
      const int iByteCount,
      int iFileIndex,
      bool bCheckFeof
   );
                                    // gets binary image from file to buffer
                                    // Takes into account fFiles[].UngetChar(),
                                    //    can be used after SkipEol()
                                    // bCheckFeof is used to swith on end of file error
                                    //    output

   HRESULT Fseek(int iFileIndex, const long lOffset, int iOrigin);
                                    // analog of fseek();

   HRESULT Ftell(int iFileIndex, long *plOffset);   // analog of ftell();

// ------------------------------- binary output
   HRESULT PutImage(const void *lpBuffer, const int iByteCount, int iFileIndex);
                                 // puts buffer as binary image to file

   HRESULT PutLong(const long lValue, int iFileIndex);
                                 // puts number as binary image to file

// ------------------------------- keyword search, part of xmls.cpp
   HRESULT GetIndexSize(long *plOffset, int iFileIndex);
                                 // *plOffset points after the last entry of the index

   HRESULT SearchEntry
   (
      long *plEntryIdx,
      long *plOffset,
      const unsigned char *lpszKeyword,
      int iFileIndex,
      bool bTestNotFound
   );                            // searches keyword lpszKeyword in index file
                                 // for exact occurence first, then for context (beginning of the word)
                                 //    iFileIndex, returns associated main entry
                                 //    index in plEntryIdx.
                                 // if bTestNotFound==FALSE, error processing will be
                                 //    suppressed
                                 // *plOffset - returned offset in index file corresponding
                                 //    to key, >=lpszKeyword, value is legal, even
                                 //    in case of KP_E_KWD_NOT_FOUND

   HRESULT SearchEntryFirst
   (
      long *plEntryIdx,
      long *plOffset,
      const unsigned char *lpszKeyword,
      int iFileIndex,
      bool bTestNotFound
   );                            // SearchEntry() and roll back to the first context
                                 // occurence of search keyword in the index

   HRESULT SearchTextEntry
   (
      long *plEntryIdx,
      long *plOffset,
      const unsigned char *lpszKeyword,
      int iFileIndex,
      bool bTestNotFound,
      long lStartFilePos,
      long lEndFilePos
   );                            // internal function - last stage of SearchEntry() - direct binary search
                                 //    of keyword in keyword index file, specifying
                                 //    position of index in the file


   HRESULT SeekEntry(long lEntryIdx, long *plEntryLen = NULL); // sets pointer of input data file to start of entry lEntryIdx

// reads entry lEntryIdx contents into the buffer *plpszEntryImg
// allocates space necessary for *plpszEntryImg
// could be used for encoded datafiles
   HRESULT ReadEntryImg(long lEntryIdx, unsigned char **plpszEntryImg, long *plEntryLen);
};


// ================================================== static data
extern const unsigned char *lppszFileIndexNamesFict[];
extern const int aiFileIndexLengthsFict[];

#endif






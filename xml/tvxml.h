// ==================================================
// tvxml.h
// main XML definitions


#ifndef tvxml_included
#define tvxml_included


// =================================================== definitions
// ---------------------------------------------------
#define TV_XL_MAX_TAG_WDT 10  // max width of tag name

#define TV_XM_MAX_CHAR_LEN 10  // max width of special character string

#define TV_XM_MAX_TAG_CONTENTS_WDT 0x7FFF // reikia arksh.exe, kad tilptø programø tekstai á <pre> MikoView // KP_MAX_FILE_LIN_LEN  // KP_MAX_FILE_LIN_WDT  // max size of tag contents

#define TV_XM_SpCharSt  ('&') // start character of XML spec. characters
#define TV_XM_UniChST   ('#') // start of unicode character &#9999;
#define TV_XM_SpCharEnd (';') // end character of XML spec. characters
#define TV_XM_TagStartCh ('<') // start character of XML tag
#define TV_XM_TagEndCh  ('>') // end character of XML tag
#define TV_XM_EndTagIndCh ('/') // character indicating end XML tag
#define TV_XM_TagValCh  ('=') // start character of XML tag value
#define TV_XM_TagTextValCh ('\"') // start character of XML tag text value
#define TV_XM_TagVersValCh ('\'') // start character of XML version text value

#define TV_XM_CompBaseChar ('~')
#define TV_XM_CompDelim    ('|')
#define TV_KP_CompDelim    (C_Dvertl)

#define TV_XM_HrefDelim    ('|')
#define TV_HTM_HrefDelim   ('#')

#define NS_CTRL_START ('$') // former KPS_CTRL_START

#define TV_XM_CtrlChars ((unsigned char *)"&<>")


// -------------------------------------------
extern const KpChar TV_XL_TAG_SUFF_1[]; // " ?>"
extern const KpChar TV_XL_TAG_SUFF_2[]; // " -->"
extern const KpChar TV_XL_TAG_SUFF_3[]; // "/>"
extern const KpChar TV_XL_TAG_SUFF_4[]; // "]>"

// -------------------------------------------
#define TV_XL_URL_FILE_PREFIX ((const unsigned char *)"file:/") // former TV_XM_URL_FILE_PREFIX 
extern const KpChar TV_XL_URL_FILE_PREFIX_W[]; // former TvXmUrlFilePrefix, TV_XM_URL_FILE_PREFIX_W

#define TV_XL_ABS_FILE_PATH_PREFIX  ((const unsigned char *)"file://")

#if KP_XGECKO_VER == 124 // "1.2.4"
#define TV_XL_TUX_PATH_PREFIX       ((const unsigned char *)"tux:")
#endif
#if KP_XGECKO_VER == 130 // "1.3.0"
#define TV_XL_TUX_PATH_PREFIX       ((const unsigned char *)"tux:///") // dar buvo KPGECKO_TUX_URL_PREFIX
#endif
extern const KpChar TV_XL_TUX_PATH_PREFIX_W[]; // former TV_XL_TUX_PATH_PREFIX_I, KPGECKO_TUX_URL_PREFIX_W, KpGeckoTuxUrlPrefix // "tux:", "tux:///"


// -----------------------------
#define XM_FirstDictTagCode 5000 // former XM_FirstTagCode // pirmas vartotojo dtd tago kodas (pvz., XMLT)
#define XM_MaxNumOfDictTags XL_MaxNumOfTags // 1000 // iki 5999

#define XH_FirstHtmTagCode 6000 // pirmas HTML tago kodas
#define XH_MaxNumOfHtmTags XL_MaxNumOfTags // 1000 // iki 6999

#define XL_FirstSysTagCode 7000 // former XL_FirstTagCode // pirmas sisteminio tago kodas (<!DOCTYPE>, <?xml ?>, etc.)
#define XL_MaxNumOfTags 1000 // iki 7999 // visi masyvai vienodi - po 500 poriniø tagø

#define XG_FirstGrpTagCode 8000
#define XG_MaxNumOfTags 1000 // iki 8999

#define XL_IX_MaxNumOfIndexes 10 // max number of index files in XML file

#define XC_TG_NoTag           (-1)

// #define XM_COMMENT_STR ((const unsigned char *)("<!-- -->\n"))
#define XM_COMMENT_START_STR ((const unsigned char *)("<!--"))
#define XM_COMMENT_END_STR ((const unsigned char *)("-->\n"))
#define XM_COMMENT_END_STR_STRICT ((const unsigned char *)("-->"))

#define XM_DOCTYPE_STR ((const unsigned char *)("<!DOCTYPE>\n"))
#define XM_Version_STR ((const unsigned char *)("<?xml ?>\n"))
#define XM_Stylesheet_STR ((const unsigned char *)("<?xml-stylesheet ?>\n"))

#define XL_NumOfSysTags    (XL_LastSysTag-XL_FirstSysTag)
#define XL_NumOfSysTags5 XL_NumOfSysTags

enum XmlSysTagChars                          // XML system tag characters
{
   XL_FirstSysTag    = XL_FirstSysTagCode,   // =7000,

   XL_Version        = XL_FirstSysTagCode,   // =7000, // former XC_Version
   XL_Version_e,     /*  7001 */

   XL_DocType,       /*  7002 */   // former XC_DocType, HTM_TG_DOCTYPE
   XL_DocType_e,     /*  7003 */

   XL_StyleSheet,    /*  7004 */   // former XC_StyleSheet
   XL_StyleSheet_e,  /*  7005 */

   XL_Comment,       /*  7006 */   // former HTM_TG_Comment
   XL_Comment_e,     /*  7007 */

   XL_IfComment,     /*  7008 */
   XL_IfComment_e,   /*  7009 */

   XL_EndIfComment,  /*  7010 */  // atskirai nuo XL_IfComment, 
   XL_EndIfComment_e,/*  7011 */  // nes <!--[if ]> ir <![endif]--> nesinhronizuoti su kitais tagais

   XL_If,            /*  7012 */
   XL_If_e,          /*  7013 */

   XL_EndIf,         /*  7014 */  // atskirai nuo XL_If,
   XL_EndIf_e,       /*  7015 */  // nes <![if ]> ir <![endif]> nesinhronizuoti su kitais tagais

   XL_Text,          /*  7016 */  // internal tag for keeping of free text // atkeltas ið plpszaXmlttDictTags[] XC_Text
   XL_Text_e,        /*  7017 */

   XL_LastSysTag
};

extern const unsigned char *plpszaXmlSysTags[XL_NumOfSysTags+1]; // XML system tag names
extern const int iaXmlSysCodeTables[XL_NumOfSysTags]; // General XML tags fictive code tables for Unicode file

extern const KpChar uiazSysGrTags[];  // grupiniø gairiø sàraðas, prieð jas lauþiama eilutë

// ---------------------------------
// XML versijos
// XM_... - enum, XML_... - #define
//
typedef enum
{
#define XML_NO_VERS            0
   XM_NO_VERS,

#define XML_VERS_SGML          1
   XM_VERS_SGML,           // simply tagged file with no predefined format (no initial and tail tags)
#define XML_VERS_SGML_TAGE     2
   XM_VERS_SGML_TAGE,      // XM_VERS_SGML with exceptions for OHE Tage format:
                           //    no entities
                           //    C_c_Caron --> C_c_Cedil
                           //    <pp>...</pp> --> <pr><pp>...</pp><pr>
                           //    (...) --> <pr>...<pr>

#define XML_VERS_HTML          3
   XM_VERS_HTML,           // for distingwishing between SGML and HTML only
#define XML_VERS_HTML40        4
   XM_VERS_HTML40,         // HTML v4.0
#define XML_VERS_HTML401_TRANS 5
   XM_VERS_HTML401_TRANS,  // HTML v4.01 Transitional
#define XML_VERS_HTML401       6
   XM_VERS_HTML401,        // HTML v4.01
#define XML_VERS_HTML401_FRAME 7
   XM_VERS_HTML401_FRAME,  // HTML v4.01 with Frameset

#define XML_VERS_HTML_TAGE     8
   XM_VERS_HTML_TAGE,      // XMLT failas, kurio tagai uþkoduoti á <span class="...">, ðiaip XM_VERS_HTML401_TRANS 

#define XML_VERS_XHTML         9
   XM_VERS_XHTML,          // XHTML // o gal èia jau daugiau XML, negu HTML? Gal kelt po XM_VERS_XML?

#define XML_VERS_XHTML_TAGE    10
   XM_VERS_XHTML_TAGE,     // XMLT failas, kurio tagai uþkoduoti á <span class="...">, ðiaip XM_VERS_XHTML

#define XML_VERS_XML           11
   XM_VERS_XML,            // for distingwishing between HTML and XML only
#define XML_VERS_XML10         12
   XM_VERS_XML10,          // XML v1.0

#define XML_VERS_SVG           13
   XM_VERS_SVG,            // SVG

   XM_MaxVers

} XmlVersions;

#define XM_MaxVers_5 XM_MaxVers // masyvams - po kiekvieno pakeitimo inkrementuoti pavadinimà

// #define XM_IS_VERS_HTML(a) ((a >= XM_VERS_HTML) && (a < XM_VERS_XML)) // former XMLT_IS_VERS_HTML
#define XM_IS_VERS_HTML(a) ((a >= XML_VERS_HTML) && (a < XML_VERS_XML)) // former XML_IS_VERS_HTML

#define XM_IS_VERS_PURE_HTML(a) ((a >= XML_VERS_HTML) && (a < XML_VERS_XHTML))
#define XM_IS_VERS_XHTML(a) ((a >= XML_VERS_XHTML) && (a < XML_VERS_XML))
#define XM_IS_VERS_HTML_TAGE(a) ((a == XML_VERS_HTML_TAGE) || (a == XML_VERS_XHTML_TAGE))
#define XM_IS_VERS_HTML_NO_TAGE(a) (XM_IS_VERS_HTML(a) && (!XM_IS_VERS_HTML_TAGE(a)))

#define XM_IS_VERS_XML(a) (a >= XML_VERS_XML)

#define XM_IS_VERS_SGML(a) ((a >= XML_VERS_SGML) && (a < XML_VERS_HTML))

// --------------------------------------------------
extern const unsigned char lpszXmlDelims[];  // delimiters between fields
extern const unsigned char lpszXmlPunct[];   // punctuators, belonging to the contents of the field, independent of theyr style in input file

extern const unsigned char *plpszaXmlSpecCharTagsMain[C_CharSize0]; // XML spec. char entities for Chars16, former plpszaXmlSpecCharTags
extern const unsigned char *plpszaXmlSpecCharTagsEdi[C_CharSize0]; // short form of SGML spec. char entities for manual editing
extern const unsigned char *plpszaHtmSpecCharTags[C_CharSize0]; // HTML spec char tags for Chars16
extern const unsigned char *plpszaXmlAddSpChars[]; // NULL-terminated array of additional XML spec char tags for Chars16
extern KpChar iXmlAddSpChars[];                   // Chars16 equivalents of plpszaXmlAddSpChars[]

extern const unsigned char *lpszaXmlCodingModes[UC_Num_Of_Modes+1];   // data file coding type names <?xml encoding=...?>

extern const unsigned char *lpszaXmlCtblNames[KPT_Ctnum+1]; // lpszaXmlCtblNamesIso[]
extern const unsigned char *lpszaXmlCtblNamesWin[KPT_Ctnum+1]; // code table names in <META CHARSET="..."> or <?xml encoding=...?>

extern const unsigned char *plpszaHtmlVersionIds[XM_MaxVers+1]; // HTML version identifiers in <!DOCTYPE HTML PUBLIC "...">
extern const unsigned char *plpszaHtmlDtds[XM_MaxVers+1]; // locations of DTD files of HTML versions
                              // in <!DOCTYPE HTML PUBLIC "-//w3c//dtd html 4.0 transitional//en" "...">

// --------------------------------------------------  additional functions
extern HRESULT SearchSpecChar(KpChar *puiInCh, const unsigned char *lpszCharText, const unsigned char * const *plpszaXmlSpCharTags);
                                          // converts XML spec char string to Chars16
                                          // plpszaXmlSpCharTags[C_CharSize0] - array of XML spec. char entities,
                                          //    can be NULL

extern HRESULT KpCharToStrNoCtrl // former Chars16ToStrNoCtrl
(
   unsigned char *lpszOutStrBuf,
   const KpChar *auiTextBuf,
   const int iNumOfChars,
   const int iOutStrLen,
   const unsigned char **plpszaXmlSpCharTags,
   EC_Types iEcType
);                                        // converts array of Char16 characters
                                          //    auiTextBuf to ASCII string, regarding
                                          //    XML coding rules.  '&' and ';' in
                                          //    XML spec. char strings are skipped,
                                          //    eol's converted to spaces
                                          //    (for using in indexes), all small
                                          //    letters are converted to big ones
                                          // iNumOfChars - num. characters to convert
                                          // iOutStrLen - max len of lpszOutStrBuf
                                          // plpszaXmlSpCharTags[C_CharSize0] - array of XML spec. char entities,
                                          //    can be NULL

extern HRESULT GetTagIndex
(
   int *piIndex,
   const unsigned char *lpszKeywrd,
   const unsigned char * const *plpszKeytable
);                            // Calculates keyword index in keyword table.
                              // Input:
                              //    plpszKeytable - array of pointers to all
                              //       keywords - null terminated strings;
                              //       NULL pointer means end of keyword table.
                              //    lpszKeywrd
                              // Output:
                              //    piIndex
                              // klaidos kodo neisveda, grazina TV_E_UNKN_TAG

// extern const unsigned char *GetTagName(KpChar iTag, const unsigned char * const *plpszTagNames, KpChar iFirstDictTag, KpChar iLastDictTag);
extern const unsigned char *GetTagName(KpChar iTag, const unsigned char * const plpszaTagNames[] = NULL, KpChar iFirstDictTag = C_Nul, KpChar iLastDictTag = C_Nul);
                                       // ieðko tago vardo dinaminëje failo tagø lentelëje
                                       // dinamiðkai pasitikrina masyvo plpszTagNames[] dydá, turi bûti null ptr-terminated
                                       // jei tagas uþ nurodytø ribø – ieðko statinëse lentelëse plpszaXmlSysTags, plpszaXmlttDictTags, plpszaHtmlTags ar plpszaGrpTags
                                       // realizuotas faile xmlt.cpp
#if FALSE // Compiler==Mingw
namespace std
{
#endif
extern KpString /* string */ ExtractTagName(KpString /* string */ arg); // istraukia plika varda is pilno tago zymes teksto ("<hw>" --> "hw")
#if FALSE // #if Compiler==Mingw
}
#endif

#endif


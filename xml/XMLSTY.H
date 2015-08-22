// ==================================================
// xmlsty.h
// XML dictionary output styles
//


#ifndef xmlsty_included
#define xmlsty_included


//----------------------------
// #define BOLD_IT_EXAMPLES  // examples, idioms and structures are bold italic - parentheses need to be converted to straight
extern bool bS1toS2; // former #define S1_TO_S2  // convert grammatical categories to semantic categories, True only for LVZ
extern bool bDelGeogr; // delete entries with labels "geogr. vard."
extern int iVSize; // mm*100
extern int iInitDown; // mm*100
extern int iLetHight; // mm*100
extern bool bDoubleColumns;
extern bool bMultiplToVeryInform; // Oxforde - daugybos zenklas C_Multipl reiskia <vif/>


//============================ RTF definitions

// #define XML_STY_TWO_COLUMNS

#define XML_STY_SP_BETWEEN_TEXT

#ifdef XML_STY_TWO_COLUMNS

#define XML_STY_LINE_SPACING 8
#define XML_STY_LINE_SPACING_CMD "\\sl-160"

#else

#define XML_STY_MAIN_FONT_SIZE 11
#define XML_STY_LINE_SPACING 14
#define XML_STY_LINE_SPACING_CMD "\\sl-280"

#endif


// ---------------------------
#define NS_DEFAULT_DELIM_STYLE   KPS_TimesLTGray // former KPS_DEFAULT_DELIM_STYLE
#define NS_DEFAULT_TEXT_STYLE    KPS_TimesLTAcc

// ---------------------------
#define NS_STY_NO_WDT   2 // former KPS_STY_NO_WDT  
#define NS_PAR_STY_WDT  2 // former KPS_PAR_STY_WDT 
#define NS_UNI_CODE_WDT 4 // former KPS_UNI_CODE_WDT
#define NS_COND_FNT_WDT 2

              
// -------------------------- letter metrics for \raide{} GetLetMetrics()
extern const unsigned char lpszFullLetterA[]; extern int iBoxWdtA;
extern const unsigned char lpszFullLetterE[]; extern int iBoxWdtE;
extern const unsigned char lpszFullLetterI[]; extern int iBoxWdtI;
extern const unsigned char lpszFullLetterU[]; extern int iBoxWdtU;


// -------------------------- values of tag <lv> (XC_Level)
typedef enum
{                              
   FullLevel,     // 0
   AcademicLevel, // 1
   BigLevel,      // 2
   Level_3,
   SchoolLevel,   // 4
   Level_5,
   SimplyLevel,   // 6  // only headwords and translations,
                        // cia tik lzdsh.exe rodymo lygmuo, pilnu lizdu isjunginejimui reikia dar kito lygmens
   NumOfLevels,   // 7

// situos mest lauk visada
   LevelGarbage    = 90,

	LevelHidden	    = 95, // Paslëptas - tik paieðkai, ekrane nerodomas
	LevelPaper,  	// 96  // Popierinis - mazgas/lizdas rodomas tik spausdintiniam þodyne, elektroniniam generuoja bereikalingus dvigubus lizdus
   LevelRemarks,  // 97  // Atliekos - pastabos ir ismesti lizdai/mazgai
   LevelDouble,   // 98  // Dvigubas - pasene/eksperimentiniai lizdu/mazgu variantai
   LevelSuppl,    // 99  // Papildymas VLLVZ lietuviðkai daliai
   
} OutputLevels;

#define NumOfLevels1 NumOfLevels
              
extern bool baLevelTags[XC_TG_NumOfDictTags00/2][NumOfLevels]; // tags to be output in each level
                                                                                
                                                                                
// ==================================== definitions
#define XMLT_NUM_OF_PAR_STYLES 2

extern const char *lpszXmlTagDelimiters[XC_TG_NumOfDictTags00/2][XC_TG_NumOfDictTags00/2];
// delimiters between tags: lpszXmlTagDelimiters[PreviousTag/2][NextTag/2]
// 8-bit codes must be entered in TV_COMMON_DELIM_CTBL (71) codetable
//    !!! former approach: 8-bit codes must correspond character value of codetable of selected 
//    !!! font style (code table of default font style DEFAULT_DELIM_STYLE is TV_COMMON_DELIM_CTBL (71))
// possibly import from tvxmlt.css !!!
// values not longer as TV_TAG_LEN
// $fNN means switching to aFontAttrDescs[NN], default style NS_DEFAULT_DELIM_STYLE=KPS_TimesLTGray=20
//    NN - exactly NS_STY_NO_WDT (two) digits - $f01 etc.
// $sNN - end of paragraph indicator. Initiates closing of current RTF fields up to lovest level, 
//    switches to RTF paragraph style NN (look KPP_FIRST_PAR_STYLE and NPR2_NUM_OF_PAR_STYLES)
//    NN - exactly NS_PAR_STY_WDT (two) digits - $s41 etc.
// $uXXXX - insertion of Unicode character, must be present in selected font (  - NBSP ???)
//    XXXX - exactly NS_UNI_CODE_WDT (four) digits - $u0975 etc.

extern const KPS_FontStyles iaTagFonts[XC_TG_NumOfDictTags00]; // SGML Tage file styles, import from tvxmlt.css !!!

extern int iDelimCtbl; // code table of delimiters
          // must be defined in local style file xxxsty.cpp
          // former NS_DELIM_CTBL

extern const unsigned char *lpszTexStyleName; // TeX style file name

extern const unsigned char lpszXmlT2X_ProjName[];
extern const unsigned char lpszXmlT2X_OrigPrompt[];
extern const unsigned char lpszXmlT2X_AppPref[];

//--------------------------------------
extern HRESULT GetLetMetrics(const unsigned char *lpszbLetL, /* const */ unsigned char *lpszbLetter, unsigned char *lpszFullLetter, int *piBoxWdt, int *piDown);
   // lpszbLetL on entering must contain latinized form of file suffix - "A", "B", "C", "C_", ...
   // lpszbLetter on entering must contain encoded letter - "A", "B", "C", "Þ", ...
   // GetLetMetrics() fills *lpszFullLetter with chapter heading: "A (Ü)", "I (ô, Y)", etc.
   // depending on project, lpszbLetter also can be changed


#endif

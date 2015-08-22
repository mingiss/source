// ------------------------------------------
// kpfonts.h
// font attributes description definitions
//


#ifndef kpfonts
#define kpfonts


// --------------------------- KPT_Typeface
#define KPT_NumOfTypefaces9 KPT_NumOfTypefaces0  // former NF_NumOfFonts7

typedef enum
{
   KPT_TypefaceUndefined = -1,    // former NF_FontUndefined

// KPT_MS_Sans_Serif_0,     // 0  // former NF_MS_Sans_Serif_0
// KPT_Symbol,              // 1  // former NF_Symbol            
// KPT_System,              // 2  // former NF_System            
// KPT_TimesLT_Accented_0,  // 3  // former NF_TimesLT_Accented_0
// KPT_TimesLT_Accented,    // 4  // former NF_TimesLT_Accented  
// KPT_Arial,               // 5  // former NF_Arial             
// KPT_MS_Sans_Serif,       // 6  // former NF_MS_Sans_Serif     
// KPT_PhoneticTM,          // 7  // former NF_PhoneticTM        
// KPT_Times_New_Roman,     // 8  // former NF_Times_New_Roman   
// KPT_Times_New_Roman_CE,  // 9  // former NF_Times_New_Roman_CE

// KPT_NumOfTypefaces,      // 10 // former NF_NumOfFonts        


// KPT_MS_Sans_Serif_0,     // 0  // former NF_MS_Sans_Serif_0   
// KPT_Symbol,              // 1  // former NF_Symbol            
// KPT_TimesLT_Accented,    // 2  // former NF_TimesLT_Accented  
// KPT_Symbol_0,            // 3  // former NF_Symbol_0          
// KPT_TimesLT_Accented_0,  // 4  // former NF_TimesLT_Accented_0
// KPT_Arial,               // 5  // former NF_Arial             
// KPT_PhoneticTM,          // 6  // former NF_PhoneticTM        
// KPT_Times_New_Roman,     // 7  // former NF_Times_New_Roman   
// KPT_Wingdings2,          // 8  // former NF_Wingdings2        
// KPT_Haettenschweiler,    // 9  // former NF_Haettenschweiler  

// KPT_NumOfTypefaces5,     // 10 // former NF_NumOfFonts5       


   KPT_Times_New_Roman,     // 0  // former NF_Times_New_Roman   
   KPT_TimesLT,             // 1  // former NF_TimesLT           
   KPT_TimesLT_Accented,    // 2  // former NF_TimesLT_Accented  
   KPT_PhoneticTMUniv,      // 3  // former NF_PhoneticTMUniv
   KPT_HelveticaLT,         // 4  // former NF_HelveticaLT       
   KPT_Symbol,              // 5  // former NF_Symbol            
   KPT_Wingdings2,          // 6  // former NF_Wingdings2        
   KPT_Haettenschweiler,    // 7  // former NF_Haettenschweiler  
   KPT_Arial,               // 8  // former NF_Arial             
   KPT_Courier,             // 9

   KPT_NumOfTypefaces0,     // 10  // former NF_NumOfFonts0

} KPT_Typefaces;   // former KPT_Typeface, NF_Font


// --------------------------------------------------
typedef class KPT_Typeface_tag // former NF_FontDescriptor_tag
{
   int iKptCodeTable;            // Code table in Kpt notification

   unsigned char szFontName[KP_MAX_FNAME_LEN + 1]; // [RT_FONT_NAME_LENGTH+1];

public:
   KPT_Typeface_tag(void);
   KPT_Typeface_tag(const /* unsigned */ char *lpszName, int iKptCTbl);

   HRESULT SetKptCodeTable(int iTCTbl);   // Forced setting of Kpt coding table
   HRESULT GetKptCodeTable(int *piTCTbl); // Gets font Kpt coding table number

   HRESULT SetFontName(const unsigned char *lpszName);
   HRESULT SetFontName(const char *lpszName); // sets font name, lpszName can be deleted after call
   HRESULT PutCharToName(const unsigned char ucCh); // concatenates char to font name property
   HRESULT const GetFontName(unsigned char **plpszNamePtr); // returns pointer to font name

} KPT_Typeface; 

extern KPT_Typeface iaTypefaces[KPT_NumOfTypefaces0]; // former iaXmlFonts[]


// --------------------------- KPS_FontStyle
#define KPS_NumOfFontStyles16 KPS_NumOfFontStyles00 // former NS_NumOfFontStyles8

typedef enum
{
   KPS_FontStyleUndefined=(-1),// -1 // former NS_FontStyleUndefined
   KPS_NoStyle,                //  0 // former NS_NoStyle,                
   KPS_TimesLT,                //  1 // former NS_TimesLT,                
   KPS_TimesLTAcc,             //  2 // former NS_TimesLTAcc,             
   KPS_TimesLTAccUndRed,       //  3 // former NS_TimesLTAccUndRed,       
   KPS_TimesLTAccItRed,        //  4 // former NS_TimesLTAccItRed,        
   KPS_TimesLTAccBoldEnlBlue,  //  5 // former NS_TimesLTAccBoldEnlBlue,  
   KPS_TimesLTAccBoldGreen,    //  6 // former NS_TimesLTAccBoldGreen,    
   KPS_TimesLTAccRed,          //  7 // former NS_TimesLTAccRed,          
   KPS_TimesLTAccBoldRed,      //  8 // former NS_TimesLTAccBoldRed,      
   KPS_TimesLTAccBoldEnlBrown, //  9 // former NS_TimesLTAccBoldEnlBrown, 
   KPS_TimesLTAccBrown,        // 10 // former NS_TimesLTAccBrown,        
   KPS_TimesLTAccBoldOchre,    // 11 // former NS_TimesLTAccBoldOchre,    
   KPS_TimesLTAccIt,           // 12 // former NS_TimesLTAccIt,           
   KPS_TimesLTAccBold,         // 13 // former NS_TimesLTAccBold,         
   KPS_TimesLTAccBoldIt,       // 14 // former NS_TimesLTAccBoldIt,       
   KPS_PhonMagenta,            // 15 // former NS_PhonMagenta,            
   KPS_PhonMagentaReduc,       // 16 // former NS_PhonMagentaReduc,       
   KPS_TimesLTAccSup,          // 17 // former NS_TimesLTAccSup,          
   KPS_Symbol,                 // 18 // former NS_Symbol,                 
   KPS_TimesLTAccUnd,          // 19 // former NS_TimesLTAccUnd,          
   KPS_TimesLTGray,            // 20 // former NS_TimesLTGray,            
   KPS_TimesLTBoldGray,        // 21 // former NS_TimesLTBoldGray,        
   KPS_TimesLTItGray,          // 22 // former NS_TimesLTItGray,          
   KPS_CommonItalic,           // 23 // former NS_Italic,                 
   KPS_CommonBold,             // 24 // former NS_Bold,                   
   KPS_CommonUnderline,        // 25 // former NS_Underline,              
   KPS_CommonSuperScript,      // 26 // former NS_SuperScript,            
   KPS_CommonSubScript,        // 27 // former NS_SubScript,              
   KPS_CommonSmallCaps,        // 28 // former NS_SmallCaps,              
   KPS_CommonCaps,             // 29 // former NS_Caps,                   
   KPS_TimesLTAccSmcapsRed,    // 30 // former NS_TimesLTAccSmcapsRed,    
   KPS_TimesLTBlue,            // 31 // former NS_TimesLTBlue,            
   KPS_TimesLTAccBoldBlue,     // 32 // former NS_TimesLTAccBoldBlue,     
   KPS_TimesLTAccSupBlue,      // 33 // former NS_TimesLTAccSupBlue,      
   KPS_TimesLTCyan,            // 34 // former NS_TimesLTCyan,            
   KPS_ArialSmcapsCyan,        // 35 // former NS_ArialSmcapsCyan,        
   KPS_TimesLTAccBoldReducCyan,// 36 // former NS_TimesLTAccBoldReducCyan,
   KPS_SymbolCyan,             // 37 // former NS_SymbolCyan,             
   KPS_Wingdings2Cyan,         // 38 // former NS_Wingdings2Cyan,         

   KPS_TimesLTAccBoldEnl,      // 39 // former NS_TimesLTAccBoldEnl,      
   KPS_TimesLTAccBoldEnlGray,  // 40
   KPS_ArialRed,               // 41 // former NS_ArialRed,               
   KPS_ArialBoldGreen,         // 42 // former NS_ArialBoldGreen,         
   KPS_HaettRed,               // 43 // former NS_HaettRed,               
   KPS_ArialBoldOchre,         // 44 // former NS_ArialBoldOchre,         
   KPS_ArialBoldBrown,         // 45 // former NS_ArialBoldBrown,         
   KPS_ArialBold,              // 46 // former NS_ArialBold,              
   KPS_ArialReduc,             // 47 // former NS_ArialReduc,             

   KPS_TimesLTAccBoldBrown,    // 48 // former NS_TimesLTAccBoldBrown,    

   KPS_TimesLTAccBoldEnlOchre, // 49 // former NS_TimesLTAccBoldEnlOchre, 
   
   KPS_TimesLTAccBoldVeryEnl,  // 50 // former NS_TimesLTAccBoldVeryEnl,  

   KPS_TimesBlue,              // 51
   KPS_TimesGray,              // 52
   KPS_TimesCyan,              // 53

   KPS_TimesLTAccBoldEnlRed,   // 54 // former NS_TimesLTAccBoldEnlRed,   

   KPS_CommonBackYellow,       // 55

   KPS_TimesLTAccItalicBlue,   // 56
   KPS_CourierBlack,           // 57

   KPS_WhiteBackDarkBlue,      // 58
   KPS_WhiteBackBrown,         // 59

   KPS_NumOfFontStyles00       // 58 // former NS_NumOfFontStyles00       

} KPS_FontStyles; // former KPS_FontStyle, NS_FontStyle


//--------------------------------------------
// #define KPF_FontUndefined (-1)  // KPS_FontStyle.iTypeface

#define KPS_FontSizeUndef (-1)  // former KPF_FontSizeUndef // KPS_FontStyle.iFontSize

// KPS_FontStyle.iFontFlags:
#define KPS_FlagsUndef     0x00000  // former KPF_FlagsUndef  

#define KPS_BoldFl         0x00001  // former KPF_BoldFl      
#define KPS_NoBoldFl       0x00002  // former KPF_NoBoldFl    
#define KPS_ItalicFl       0x00004  // former KPF_ItalicFl    
#define KPS_NoItalicFl     0x00008  // former KPF_NoItalicFl  
#define KPS_UnderlFl       0x00010  // former KPF_UnderlFl    
#define KPS_NoUnderlFl     0x00020  // former KPF_NoUnderlFl  
#define KPS_SuperFl        0x00040  // former KPF_SuperFl     
// #define KPS_NoSuperFl   0x00080  // former KPF_NoSuperFl
#define KPS_SubFl          0x00100  // former KPF_SubFl     
#define KPS_NoSupSubFl     0x00200  // former KPF_NoSupSubFl
#define KPS_SmCapsFl       0x00400  // former KPF_SmCapsFl  
// #define KPS_NoSmCapsFl  0x00800  // former KPF_NoSmCapsFl
#define KPS_LCaseFl        0x00800  // lower case letters
#define KPS_CapsFl         0x01000  // upper case letters, former KPF_CapsFl    
#define KPS_NoAnyCapsFl    0x02000  // former KPS_NoCapsFl, KPF_NoCapsFl  
#define KPS_HiddenFl       0x04000
#define KPS_NoHiddenFl     0x08000

#define KPS_Straight    (KPS_NoBoldFl | KPS_NoItalicFl | KPS_NoUnderlFl | KPS_NoSupSubFl)  //  | KPS_NoSmCapsFl | KPS_NoCapsFl // former KPF_Straight
#define KPS_Bold        (KPS_BoldFl   | KPS_NoItalicFl | KPS_NoUnderlFl | KPS_NoSupSubFl)  //  | KPS_NoSmCapsFl | KPS_NoCapsFl // former KPF_Bold    
#define KPS_Italic      (KPS_NoBoldFl | KPS_ItalicFl   | KPS_NoUnderlFl | KPS_NoSupSubFl)  //  | KPS_NoSmCapsFl | KPS_NoCapsFl // former KPF_Italic  
#define KPS_BoldItal    (KPS_BoldFl   | KPS_ItalicFl   | KPS_NoUnderlFl | KPS_NoSupSubFl)  //  | KPS_NoSmCapsFl | KPS_NoCapsFl // former KPF_BoldItal
#define KPS_Underl      (KPS_NoBoldFl | KPS_NoItalicFl | KPS_UnderlFl   | KPS_NoSupSubFl)  //  | KPS_NoSmCapsFl | KPS_NoCapsFl // former KPF_Underl  
#define KPS_Super       (KPS_NoBoldFl | KPS_NoItalicFl | KPS_NoUnderlFl | KPS_SuperFl)     //  | KPS_NoSmCapsFl | KPS_NoCapsFl // former KPF_Super   
#define KPS_Sub         (KPS_NoBoldFl | KPS_NoItalicFl | KPS_NoUnderlFl | KPS_SubFl)       //  | KPS_NoSmCapsFl | KPS_NoCapsFl // former KPF_Sub     
#define KPS_SmCaps      (KPS_NoBoldFl | KPS_NoItalicFl | KPS_NoUnderlFl | KPS_NoSupSubFl | KPS_SmCapsFl)  //    | KPS_NoCapsFl // former KPF_SmCaps  
#define KPS_Caps        (KPS_NoBoldFl | KPS_NoItalicFl | KPS_NoUnderlFl | KPS_NoSupSubFl | KPS_CapsFl  )  //  | KPS_NoSmCapsFl // former KPF_Caps    


// --------------------------------
typedef class KPS_FontStyle_tag // former KPF_FontAttrDesc_tag
{
   KPT_Typefaces iTypeface; // former iFontID; typeface identifier, meaning depends on application - typedef enum{...} KPT_Typefaces
   int iFontSize; // font size in points*2
   int iFontFlags;
   KpColor iColor;
   KpColor iBackColor;

public:
   KPS_FontStyle_tag(void);
   KPS_FontStyle_tag
   (
      KPT_Typefaces iTypefaceInit,
      int iFontSizeInit,
      int iFontFlagsInit,
      KpColor iColorInit,
      KpColor iBackColorInit
   );

   KPT_Typefaces /* int */ GetTypeface(void); // former GetFontId
   int GetFontSize(void);
   int GetFontFlags(void);
   KpColor GetColor(void);
   KpColor GetBackColor(void);

} KPS_FontStyle; // former KPF_FontAttrDesc


// ---------------------------
// value in points*2, can be changed for font output scaling 
// former LVZ_MAIN_FONT_SIZE*2, KPS_MAIN_FONT_SIZE*2, XML_STY_MAIN_FONT_SIZE*2
// extern int iMainFontSize;
#define iMainFontSize 22
extern int iCurFontSize;

extern KPS_FontStyle aFontStyles[KPS_NumOfFontStyles00]; // former aFontAttrDescs


// --------------------------- paragraph styles
#define KPP_FIRST_PAR_STYLE 41 // former NP_FIRST_PAR_STYLE
typedef enum
{
   KPP_Undefined=(-1),   // former NP_Undefined
      
   KPP_LastParStyle=KPP_FIRST_PAR_STYLE,  //  41 // former NP_LastParStyle

} KPP_ParStyle; // former NP_ParStyle

// #define KPP_NUM_OF_PAR_STYLES (KPP_LastParStyle-KPP_FIRST_PAR_STYLE) // ==0 // former NP_NUM_OF_PAR_STYLES

extern int iNumOfParagraphStyles; // = KPP..._NUM_OF_PAR_STYLES;
extern const unsigned char *lpszaParStyTexInlineCmds[/* KPP..._NUM_OF_PAR_STYLES */]; // KPP..._NUM_OF_PAR_STYLES defined inside of user application, TEX tags
extern const unsigned char *lpszaParStyInlineCmds[/* KPP..._NUM_OF_PAR_STYLES */]; // KPP..._NUM_OF_PAR_STYLES defined inside of user application, RTF tags
extern const unsigned char *lpszaParStyNames[/* KPP..._NUM_OF_PAR_STYLES */];


#endif

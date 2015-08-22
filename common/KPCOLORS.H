/*---------------------------------------------------------*/
/* Colors                                                  */
/*---------------------------------------------------------*/

#ifndef kpcolors
#define kpcolors

typedef enum
{
   KpColorUndefined = -1,

   KpBlack,
   KpDarkgray,
   KpGray,
   KpLightgray,
   KpWhite,

   KpDarkred,
   KpRed,
   KpLightred,

   KpBrown,
   KpOchre,
   KpOrange,
   KpYellow,
   KpLightyellow,

   KpDarkgreen,
   KpGreen,
   KpLightgreen,

   KpDarkcyan,
   KpCyan,
   KpLightcyan,

   KpDarkBlue,
   KpBlue,
   KpGrayBlue,
   KpLightblue,

   KpDarkmagenta,
   KpMagenta,
   KpLightmagenta,
   KpDarkviolet,
   KpViolet,
   KpLightviolet,

   KpGmaxcc0

} KpColor; // former Colors

#define KpGmaxcc1 KpGmaxcc0

 
/*       common
           MSDos only
             MSWindows only     BBGGRR */
# define RGB_Black            0x000000
# define   RGB_Darkgray       0x606060 // 0x1F1F1F
# define     RGB_Gray         0xA0A0A0
# define RGB_Lightgray        0xD4D4D4
# define RGB_White            0xFFFFFF // RGB(0xFF, 0xFF, 0xFF)

# define     RGB_Darkred      0x000090
# define RGB_Red              0x0000D0
# define RGB_Lightred         0x0000FF
# define     RGB_Rose         0x6080FF

# define   RGB_Brown          0x003F7F
# define     RGB_Ochre        0x008080
# define     RGB_Orange       0x003FFF
# define RGB_Yellow           0x00E0F8
# define     RGB_Lightyellow  0xC0FFFF // 0x00FFFF

# define     RGB_Darkgreen    0x006000
# define RGB_Green            0x40C738
# define RGB_Lightgreen       0x00FF40

# define     RGB_Darkcyan     0x808000
# define RGB_Cyan             0xC0C000
# define   RGB_Lightcyan      0xFFFF00

# define     RGB_Darkblue     0x800000
# define RGB_Blue             0xC00000
# define     RGB_GrayBlue     0xC56A31
# define RGB_Lightblue        0xFF0000

# define     RGB_Darkmagenta  0x800080
# define RGB_Magenta          0xC000C0
# define RGB_Pink             0xE000FF
# define     RGB_Darkviolet   0x800040
# define     RGB_Violet       0xC00070
# define     RGB_Lightviolet  0xFF00A0


typedef long RGB_Color; // former RGB_Colors

extern RGB_Color ColorTable[KpGmaxcc0];

// -----------------------------------
typedef enum
{
   KpShadowNorm,  // normal (gray) background - normalus fonas
   KpShadowLight, // light background - sviesus seseliai, sviesus tekstas
   KpShadowDark,  // dark background - tamsus seseliai, tamsus tekstas, invertuoto teksto fonas
   KpShadowBlack, // black background - juodi seseliai
   KpShadowBackground, // fonas apie mygtuka etc.
   KpShadowForeground, // paties mygtuko, etc. fonas
   KpCaptionColor, // lango antrastes spalva
   KpLinkColor,   // URL nuorodos spalva
   
   KpNumOfShadows0
   
} KpShadow;

// extern COLORREF KpWinColorScheme[KpNumOfShadows0]; // common color table, defined in kpcolors.cpp, filled in kpwindows.cpp 
                                                      // former KpColorScheme[], defined locally
                                                      // split to global KpWinColorScheme[] and local KpColorSchemeLocal[]
                                                      // nereikalinga, aPenSchemeWin[] vietoj jos
                                                      // iðnaikinta visai 
#define KpNumOfShadows3 KpNumOfShadows0


// =================================================== for kpx compatibility
typedef enum
{
   Ct_c1,
   Ct_c2,
   Ct_c3,
   Ct_c4,
   Ct_c5,
   Ct_c6,
   Ct_c7,

   Ctt_siz
} Cttabs;


extern const unsigned char *ColorNames[]; // HTML spalvø pavadinimai

#endif

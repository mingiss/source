//-----------------------------------------
// RGB Color table
//

// =========================================
// 2006.09.20 mp  #include <string>



// =========================================
#include "stdafx.h"

#include "envir.h"

#include <stdio.h>
#include <string>
#include <fstream>
#if OsGr==MSWin
#include <windows.h>
#endif

#if (Compiler != Watcom) || (__WATCOMC__ >= 1202)
using namespace std;
#endif

#include "kpstdlib.h"
#include "kpcolors.h"


RGB_Color ColorTable[KpGmaxcc1]=
{
   RGB_Black,
   RGB_Darkgray,
   RGB_Gray,
   RGB_Lightgray,
   RGB_White,

   RGB_Darkred,
   RGB_Red,
   RGB_Lightred,

   RGB_Brown,
   RGB_Ochre,
   RGB_Orange,
   RGB_Yellow,
   RGB_Lightyellow,

   RGB_Darkgreen,
   RGB_Green,
   RGB_Lightgreen,

   RGB_Darkcyan,
   RGB_Cyan,
   RGB_Lightcyan,

   RGB_Darkblue,
   RGB_Blue,
   RGB_GrayBlue,
   RGB_Lightblue,

   RGB_Darkmagenta,
   RGB_Magenta,
   RGB_Pink,
   RGB_Darkviolet,
   RGB_Violet,
   RGB_Lightviolet,

};

#if FALSE
COLORREF KpWinColorScheme[KpNumOfShadows2]={ // KpColorScheme[KpNumOfShadows2]={
RGB_Black, // RGB(191,191,191), // RGB(236,233,216), // RGB_Gray,      // KpShadowNorm,  // normal (gray) background - normalus fonas
RGB_Black, // RGB_White,     // KpShadowLight, // light background - sviesus seseliai, sviesus tekstas
RGB_Black, // RGB_Black, // RGB_Darkgray,  // KpShadowDark,  // dark background - tamsus seseliai, tamsus tekstas, invertuoto teksto fonas
RGB_Black, // RGB_Black,     // KpShadowBlack, // black background - juodi seseliai
RGB_Black, // RGB_Gray,      // KpShadowBackground, // fonas apie mygtuka etc.
RGB_Black, // RGB_Gray,      // KpShadowForeground, // paties mygtuko, etc. fonas
RGB_Black, // RGB_Darkblue,  // KpCaptionColor, // lango antrastes spalva
};
#endif


const unsigned char *ColorNames[] = {
   (const unsigned char *)"AliceBlue",       // #F0F8FF
   (const unsigned char *)"AntiqueWhite",    // #FAEBD7
   (const unsigned char *)"Aqua",            // #00FFFF
   (const unsigned char *)"Aquamarine",      // #7FFFD4
   (const unsigned char *)"Azure",           // #F0FFFF
   (const unsigned char *)"Beige",           // #F5F5DC
   (const unsigned char *)"Bisque",          // #FFE4C4
   (const unsigned char *)"Black",           // #000000
   (const unsigned char *)"BlanchedAlmond",  // #FFEBCD
   (const unsigned char *)"Blue",            // #0000FF
   (const unsigned char *)"BlueViolet",      // #8A2BE2
   (const unsigned char *)"Brown",           // #A52A2A
   (const unsigned char *)"BurlyWood",       // #DEB887
   (const unsigned char *)"CadetBlue",       // #5F9EA0
   (const unsigned char *)"Chartreuse",      // #7FFF00
   (const unsigned char *)"Chocolate",       // #D2691E
   (const unsigned char *)"Coral",           // #FF7F50
   (const unsigned char *)"CornflowerBlue",  // #6495ED
   (const unsigned char *)"Cornsilk",        // #FFF8DC
   (const unsigned char *)"Crimson",         // #DC143C
   (const unsigned char *)"Cyan",            // #00FFFF
   (const unsigned char *)"DarkBlue",        // #00008B
   (const unsigned char *)"DarkCyan",        // #008B8B
   (const unsigned char *)"DarkGoldenRod",   // #B8860B
   (const unsigned char *)"DarkGray",        // #A9A9A9
   (const unsigned char *)"DarkGreen",       // #006400
   (const unsigned char *)"DarkKhaki",       // #BDB76B
   (const unsigned char *)"DarkMagenta",     // #8B008B
   (const unsigned char *)"DarkOliveGreen",  // #556B2F
   (const unsigned char *)"Darkorange",      // #FF8C00
   (const unsigned char *)"DarkOrchid",      // #9932CC
   (const unsigned char *)"DarkRed",         // #8B0000
   (const unsigned char *)"DarkSalmon",      // #E9967A
   (const unsigned char *)"DarkSeaGreen",    // #8FBC8F
   (const unsigned char *)"DarkSlateBlue",   // #483D8B
   (const unsigned char *)"DarkSlateGray",   // #2F4F4F
   (const unsigned char *)"DarkTurquoise",   // #00CED1
   (const unsigned char *)"DarkViolet",      // #9400D3
   (const unsigned char *)"DeepPink",        // #FF1493
   (const unsigned char *)"DeepSkyBlue",     // #00BFFF
   (const unsigned char *)"DimGray",         // #696969
   (const unsigned char *)"DodgerBlue",      // #1E90FF
   (const unsigned char *)"FireBrick",       // #B22222
   (const unsigned char *)"FloralWhite",     // #FFFAF0
   (const unsigned char *)"ForestGreen",     // #228B22
   (const unsigned char *)"Fuchsia",         // #FF00FF
   (const unsigned char *)"Gainsboro",       // #DCDCDC
   (const unsigned char *)"GhostWhite",      // #F8F8FF
   (const unsigned char *)"Gold",            // #FFD700
   (const unsigned char *)"GoldenRod",       // #DAA520
   (const unsigned char *)"Gray",            // #808080
   (const unsigned char *)"Green",           // #008000
   (const unsigned char *)"GreenYellow",     // #ADFF2F
   (const unsigned char *)"HoneyDew",        // #F0FFF0
   (const unsigned char *)"HotPink",         // #FF69B4
   (const unsigned char *)"IndianRed",       // #CD5C5C
   (const unsigned char *)"Indigo",          // #4B0082
   (const unsigned char *)"Ivory",           // #FFFFF0
   (const unsigned char *)"Khaki",           // #F0E68C
   (const unsigned char *)"Lavender",        // #E6E6FA
   (const unsigned char *)"LavenderBlush",   // #FFF0F5
   (const unsigned char *)"LawnGreen",       // #7CFC00
   (const unsigned char *)"LemonChiffon",    // #FFFACD
   (const unsigned char *)"LightBlue",       // #ADD8E6
   (const unsigned char *)"LightCoral",      // #F08080
   (const unsigned char *)"LightCyan",       // #E0FFFF
   (const unsigned char *)"LightGoldenRodYellow",  // #FAFAD2
   (const unsigned char *)"LightGrey",       // #D3D3D3
   (const unsigned char *)"LightGreen",      // #90EE90
   (const unsigned char *)"LightPink",       // #FFB6C1
   (const unsigned char *)"LightSalmon",     // #FFA07A
   (const unsigned char *)"LightSeaGreen",   // #20B2AA
   (const unsigned char *)"LightSkyBlue",    // #87CEFA
   (const unsigned char *)"LightSlateGray",  // #778899
   (const unsigned char *)"LightSteelBlue",  // #B0C4DE
   (const unsigned char *)"LightYellow",     // #FFFFE0
   (const unsigned char *)"Lime",            // #00FF00
   (const unsigned char *)"LimeGreen",       // #32CD32
   (const unsigned char *)"Linen",           // #FAF0E6
   (const unsigned char *)"Magenta",         // #FF00FF
   (const unsigned char *)"Maroon",          // #800000
   (const unsigned char *)"MediumAquaMarine",   // #66CDAA
   (const unsigned char *)"MediumBlue",      // #0000CD
   (const unsigned char *)"MediumOrchid",    // #BA55D3
   (const unsigned char *)"MediumPurple",    // #9370D8
   (const unsigned char *)"MediumSeaGreen",  // #3CB371
   (const unsigned char *)"MediumSlateBlue", // #7B68EE
   (const unsigned char *)"MediumSpringGreen",  // #00FA9A
   (const unsigned char *)"MediumTurquoise", // #48D1CC
   (const unsigned char *)"MediumVioletRed", // #C71585
   (const unsigned char *)"MidnightBlue",    // #191970
   (const unsigned char *)"MintCream",       // #F5FFFA
   (const unsigned char *)"MistyRose",       // #FFE4E1
   (const unsigned char *)"Moccasin",        // #FFE4B5
   (const unsigned char *)"NavajoWhite",     // #FFDEAD
   (const unsigned char *)"Navy",            // #000080
   (const unsigned char *)"OldLace",         // #FDF5E6
   (const unsigned char *)"Olive",           // #808000
   (const unsigned char *)"OliveDrab",       // #6B8E23
   (const unsigned char *)"Orange",          // #FFA500
   (const unsigned char *)"OrangeRed",       // #FF4500
   (const unsigned char *)"Orchid",          // #DA70D6
   (const unsigned char *)"PaleGoldenRod",   // #EEE8AA
   (const unsigned char *)"PaleGreen",       // #98FB98
   (const unsigned char *)"PaleTurquoise",   // #AFEEEE
   (const unsigned char *)"PaleVioletRed",   // #D87093
   (const unsigned char *)"PapayaWhip",      // #FFEFD5
   (const unsigned char *)"PeachPuff",       // #FFDAB9
   (const unsigned char *)"Peru",            // #CD853F
   (const unsigned char *)"Pink",            // #FFC0CB
   (const unsigned char *)"Plum",            // #DDA0DD
   (const unsigned char *)"PowderBlue",      // #B0E0E6
   (const unsigned char *)"Purple",          // #800080
   (const unsigned char *)"Red",             // #FF0000
   (const unsigned char *)"RosyBrown",       // #BC8F8F
   (const unsigned char *)"RoyalBlue",       // #4169E1
   (const unsigned char *)"SaddleBrown",     // #8B4513
   (const unsigned char *)"Salmon",          // #FA8072
   (const unsigned char *)"SandyBrown",      // #F4A460
   (const unsigned char *)"SeaGreen",        // #2E8B57
   (const unsigned char *)"SeaShell",        // #FFF5EE
   (const unsigned char *)"Sienna",          // #A0522D
   (const unsigned char *)"Silver",          // #C0C0C0
   (const unsigned char *)"SkyBlue",         // #87CEEB
   (const unsigned char *)"SlateBlue",       // #6A5ACD
   (const unsigned char *)"SlateGray",       // #708090
   (const unsigned char *)"Snow",            // #FFFAFA
   (const unsigned char *)"SpringGreen",     // #00FF7F
   (const unsigned char *)"SteelBlue",       // #4682B4
   (const unsigned char *)"Tan",             // #D2B48C
   (const unsigned char *)"Teal",            // #008080
   (const unsigned char *)"Thistle",         // #D8BFD8
   (const unsigned char *)"Tomato",          // #FF6347
   (const unsigned char *)"Turquoise",       // #40E0D0
   (const unsigned char *)"Violet",          // #EE82EE
   (const unsigned char *)"Wheat",           // #F5DEB3
   (const unsigned char *)"White",           // #FFFFFF
   (const unsigned char *)"WhiteSmoke",      // #F5F5F5
   (const unsigned char *)"Yellow",          // #FFFF00
   (const unsigned char *)"YellowGreen",     // #9ACD32
   NULL
};


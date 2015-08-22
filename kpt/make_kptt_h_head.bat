@echo off
echo // -------------------------------------------------------------- > kptt.h
echo // Ðitas failas sugeneruotas automatiðkai, keisti nëra prasmës >> kptt.h
echo // >> kptt.h
echo /* =================================================== > kptt.h
echo  *  kptt.h >> kptt.h
echo  *  Kpt style character codes, code table definitions >> kptt.h
echo  */ >> kptt.h
echo // >> kptt.h
echo // >> kptt.h
echo #ifndef kptt >> kptt.h
echo #define kptt >> kptt.h
echo // >> kptt.h
echo // ---------------------------------- >> kptt.h
echo // #define NO_LTCOD // apibrëþti projekto parametruose - seniems projektams, nenaudojantiems Vyèio kodavimo >> kptt.h
echo // >> kptt.h
echo /* =================================================== */ >> kptt.h
echo #define KPT_NoCodeTable   (-1)   /* No code table - value for undefined font table */ >> kptt.h
echo // >> kptt.h                                 /*    entry                                       */ >> kptt.h
echo #define KPT_UnknCodeTable (-2)   /* Unknown code table - value not used ??? */ >> kptt.h
echo #define KPT_UpCodeTable   (-3)   /* xml tags: codetable of the father tag should be inherited */ >> kptt.h
echo // >> kptt.h
echo #define TV_NO_CTBL             0 >> kptt.h
echo #define TV_CTBL_ASCII          1 >> kptt.h
echo #define TV_CPP_SOURCE_CTBL    71 >> kptt.h
echo #define TV_MAIN_CTBL          71 >> kptt.h
echo #define TV_CTBL_TRANSPARENT   99 >> kptt.h
echo // >> kptt.h
echo #define KPT_Ctnum       100      /* Number of code tables */ >> kptt.h
echo #define Ctnum           KPT_Ctnum >> kptt.h
echo // >> kptt.h
echo #define KPT_FirstKptChar 0x80 /* C_AE */ >> kptt.h
echo // >> kptt.h
echo // start of private area - used for coding of unmapped Kpt characters >> kptt.h
echo // code = KPT_UniPrivateStart + <Kpt code> >> kptt.h
echo #ifdef NO_LTCOD >> kptt.h
echo #define KPT_UniPrivateStart 0xE000 // Vyèio kodø nenaudojam - kaip seniau >> kptt.h
echo #else >> kptt.h
echo #define KPT_UniPrivateStart 0xE100 // pradþia jau uþimta - Vytis accented lit. chars 0xE000..0xE01A >> kptt.h
echo #endif >> kptt.h
echo // #define KPT_UniPrivateEnd 0xF900  // MS Word uses codes >= 0xF000 >> kptt.h
echo #define KPT_UniPrivateEnd 0xEFFF >> kptt.h
echo // >> kptt.h
echo // pasirinkimas tarp naujø (Vytis) ir senø (KPT_UniPrivateStart + <Kpt code>) lietuviðkø akcentuotø raidþiø kodø >> kptt.h
echo #ifdef NO_LTCOD >> kptt.h
echo #define CH_LTCOD(new_code, old_code) (old_code) >> kptt.h
echo #else >> kptt.h
echo #define CH_LTCOD(new_code, old_code) (new_code) >> kptt.h
echo #endif >> kptt.h
echo // >> kptt.h
echo // ----------------------- >> kptt.h
echo // typedef unsigned short UniChar; // WCHAR >> kptt.h
echo typedef WCHAR UniChar; >> kptt.h
echo // >> kptt.h
echo // ----------------------- >> kptt.h
echo extern int LangToCtbl[KpNumOfLangs]; // naudoti LangToCtbl[iMsgLangOff]  >> kptt.h
echo // >> kptt.h
echo // ---------------- coding modes of whole text file >> kptt.h
echo typedef enum >> kptt.h
echo { >> kptt.h
echo         UC_No_Mode, >> kptt.h
echo // >> kptt.h
echo         UC_Binary,    // XML index binary file, former UC_UTF_Binary >> kptt.h
echo // >> kptt.h
echo         UC_PlainText, // 8-bit character plain text, XML index file text format, former UC_UTF_PlainText >> kptt.h
echo // >> kptt.h
echo // ----------- >> kptt.h
echo         UC_Unicode,  // for distinguishing between plain text and Unicode >> kptt.h
echo // >> kptt.h
echo // Unicode modes >> kptt.h
echo         UC_UTF_7, >> kptt.h
echo         UC_UTF_8, >> kptt.h
echo // >> kptt.h
echo         UC_Unicode16,  // for distinguishing between 8-bit and 16-bit Unicode modes >> kptt.h
echo // >> kptt.h
echo         UC_UTF_16, >> kptt.h
echo         UC_UTF_16_Big_Endian, >> kptt.h
echo // >> kptt.h
echo         UC_Num_Of_Modes >> kptt.h
echo // >> kptt.h
echo } UC_Modes; >> kptt.h
echo // >> kptt.h
echo // >> kptt.h
echo // ---------------- text coding types >> kptt.h
echo #define EC_First_Type 1000 >> kptt.h
echo // >> kptt.h
echo typedef enum >> kptt.h
echo { >> kptt.h
echo         EC_No_Type=EC_First_Type, >> kptt.h
echo // >> kptt.h
echo    EC_ASCII,      // plain ascii without diacrytics >> kptt.h
echo // >> kptt.h
echo         EC_8_BIT,      // 8-bit encoding - code table number should be specifyed instead >> kptt.h
echo                        // by encoding of XML indexes: >> kptt.h
echo                        //    if letter not found in target code table - accents schold be >> kptt.h
echo                        //    skipped first (KptNoAccTbl[]), if still not found - converted to >> kptt.h
echo                        //    plain ASCII (KptToLatTbl[]) >> kptt.h
echo                        // instead of EC_8_BIT simply code table number 0..KPT_Ctnum could be used as EC_Types value >> kptt.h
echo // >> kptt.h
echo         EC_KP_INT,     // 16-bit internal Kp encoding >> kptt.h
echo // >> kptt.h
echo // ----------- >> kptt.h
echo         EC_Unicode,  // for distinguishing between plain text and Unicode >> kptt.h
echo // >> kptt.h
echo // Unicode modes >> kptt.h
echo         EC_UTF_7, >> kptt.h
echo         EC_UTF_8, >> kptt.h
echo // >> kptt.h
echo         EC_Unicode16,  // for distinguishing between 8-bit and 16-bit Unicode modes >> kptt.h
echo // >> kptt.h
echo         EC_UTF_16, >> kptt.h
echo         EC_UTF_16_Big_Endian, >> kptt.h
echo // >> kptt.h
echo         EC_Num_Of_Types_0 >> kptt.h
echo // >> kptt.h
echo } EC_Types; >> kptt.h
echo // >> kptt.h
echo // >> kptt.h
echo #define EC_Num_Of_Types (EC_Num_Of_Types_0-EC_First_Type) >> kptt.h
echo // >> kptt.h
echo /* =================================================== Kpt 16-bit characters */ >> kptt.h
echo #define C_Tab C_Ht >> kptt.h
echo // >> kptt.h
echo #define C_CharArrSize44  C_CharSize0 >> kptt.h
echo // >> kptt.h
echo typedef enum >> kptt.h
echo { >> kptt.h
echo    C_Unkn=(-2), >> kptt.h
echo    C_Noch,           /* -1 */ >> kptt.h
echo // >> kptt.h

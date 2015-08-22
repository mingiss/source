// ==================================================
// tvmain.h
// main definitions of all TEV projects


#ifndef tvmain_included
#define tvmain_included


// ===================================================
#define AUTO_LASTWORD // automatically generate detection of last word of paragraph

// ----------- minimal number of chars in last line (\lastwordinpar for TEX output)
extern int iLastWordLen;
#define LAST_WORD_LEN iLastWordLen
#ifdef PROCESS_LAST_WORD
// #define LAST_WORD_LEN 6
#define LAST_WORD_RECOGN_PTR 20
#else
// // #define LAST_WORD_LEN 0
// #define LAST_WORD_LEN 4
#define LAST_WORD_RECOGN_PTR 0
#endif

// ===================================================
#define TV_TAG_LEN KP_KWD_LEN // negalima keist – pasikeis kpstart.ini dydis


// =================================================== TRACE() variables
extern int AllCnt;
extern int FopenCnt;

// =================================================== Error codes
// keyword too long
#define TV_E_TAG_OVERFL       (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x400 + 1))
// tag unexpected
#define TV_E_TAG_UNEXPECTED   (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x400 + 2))
// duplicated font definition
#define TV_E_DOUBLE_FONT_DEF  (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x400 + 3))
// duplicate index
#define TV_E_DOUBLE_INDEX     (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x400 + 4))
// unknown tag
#define TV_E_UNKN_TAG         (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x400 + 5))
// characters outside of fields
#define TV_E_FREE_CHARS       (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x400 + 6))
// corrupted index file
#define TV_E_BAD_INDEX        (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x400 + 7))
// unmatched opening tags
#define TV_E_OPEN_TAG         (MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x200 + 0x400 + 8))

#endif

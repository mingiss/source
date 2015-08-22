// ==================================================
// kperr.h
// error return from subroutines for KP C++ projects
//

#ifndef kperr_included
#define kperr_included

// ================================================== definitions
#define KP_MSG_LEN  255 // 130 // 80

// =============================== DiagMsg
#define KP_ERR_SENDDIAGMSG // apibrëþti, jei norim siøsti automatinius error reportus

#ifdef KP_ERR_SENDDIAGMSG

#define KP_ERR_DIAG_MSG_POST_FILE ("KpDiagMsgPost.txt")

#define KPDIAGMSG_URL_SERVER ((const unsigned char *)"http://www.tev.lt")
// #define KPDIAGMSG_URL_FILE ((const unsigned char *)"/diag.php")
#define KPDIAGMSG_URL_FILE ((const unsigned char *)"/error_report.php")
#define KPDIAGMSG_RESP_OK ((const unsigned char *)"ok")

#define KPDIAGMSG_EMAIL_FILE ((const unsigned char *)"\\DAT0\\email.txt")

#endif


// ================================================== DiagMsg ið StartSel.exe KP_S_DIAG_MSG
#ifdef KP_ERR_SENDDIAGMSG

#define KPDIAGMSG_EDIT_DX 500
#define KPDIAGMSG_PROMPT_DX (KPDIAGMSG_EDIT_DX + KPW_WND_MARGIN + KPW_BUTTON_HGT)

#define KPDIAGMSG_ICON_X (KPW_WND_MARGIN * 3)
#define KPDIAGMSG_ICON_Y (KPW_WND_MARGIN * 3)
#define KPDIAGMSG_ICON_WDT KPW_ICON_WDT

#define KPDIAGMSG_MSG_X (KPDIAGMSG_ICON_X + KPDIAGMSG_ICON_WDT + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_MSG_Y KPDIAGMSG_ICON_Y
#define KPDIAGMSG_MSG_DX (KPDIAGMSG_EDIT_DX - KPDIAGMSG_ICON_WDT - KPW_WND_MARGIN * 3)
#define KPDIAGMSG_MSG_NUMLINES 1 // 3
#define KPDIAGMSG_MSG_NUMPOS (KPDIAGMSG_MSG_DX * (((MsgLang == KpLangRu_p) || (MsgLang == KpLangRu_1251_p) || (MsgLang == KpLangRu_0_p))?9:10)/iaCtrlTextFactorsMean[KPDIAGMSG_MSG_STYLE])
#define KPDIAGMSG_MSG_STYLE KPW_CONTROL_STYLE_BOLD

#define KPDIAGMSG_LINE_X1 0
#define KPDIAGMSG_LINE_X2 (KPDIAGMSG_WND_DX - iWndBorderWdt * 2)
// #define KPDIAGMSG_LINE0_Y (KPDIAGMSG_ICON_Y + KPDIAGMSG_ICON_WDT + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_LINE0_Y (KPDIAGMSG_MSG_Y + iaCtrlHeights[iWindowsVersionCut][KPDIAGMSG_MSG_STYLE] + iaCtrlRowHeights[iWindowsVersionCut][KPDIAGMSG_MSG_STYLE] * (KPDIAGMSG_MSG_NUMLINES - 1) + KPW_WND_MARGIN * 3)

#define KPDIAGMSG_EXPL_X (KPDIAGMSG_ICON_X + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_EXPL_DX (KPDIAGMSG_EDIT_DX + KPW_WND_MARGIN + KPW_BUTTON_HGT - KPW_WND_MARGIN * 3)
#define KPDIAGMSG_EXPL_Y (KPDIAGMSG_LINE0_Y + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_EXPL_NUMLINES 2 // 5
#define KPDIAGMSG_EXPL_STYLE KPW_CONTROL_STYLE_NORMAL
#define KPDIAGMSG_EXPL_NUMPOS (KPDIAGMSG_EXPL_DX * (((MsgLang == KpLangRu_p) || (MsgLang == KpLangRu_1251_p) || (MsgLang == KpLangRu_0_p))?9:10)/iaCtrlTextFactorsMean[KPDIAGMSG_EXPL_STYLE])

// #define KPDIAGMSG_LINE1_Y (KPDIAGMSG_EXPL_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + iaCtrlRowHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] * (KPDIAGMSG_EXPL_NUMLINES - 1) + KPW_WND_MARGIN * 3)

#define KPDIAGMSG_EMAIL_PROMPT_X KPDIAGMSG_ICON_X
#define KPDIAGMSG_EMAIL_PROMPT_DX KPDIAGMSG_PROMPT_DX
// #define KPDIAGMSG_EMAIL_PROMPT_Y (KPDIAGMSG_LINE1_Y + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_EMAIL_PROMPT_Y (KPDIAGMSG_EXPL_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + iaCtrlRowHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] * (KPDIAGMSG_EXPL_NUMLINES - 1) + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_EMAIL_PROMPT_NUMLINES 1

#define KPDIAGMSG_EMAIL_EDIT_X KPDIAGMSG_EMAIL_PROMPT_X
#define KPDIAGMSG_EMAIL_EDIT_DX KPDIAGMSG_EDIT_DX
#define KPDIAGMSG_EMAIL_EDIT_Y (KPDIAGMSG_EMAIL_PROMPT_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + KPW_WND_MARGIN)
#define KPDIAGMSG_EMAIL_EDIT_NUMLINES 1

#define KPDIAGMSG_COMMENTS_PROMPT_X KPDIAGMSG_ICON_X
#define KPDIAGMSG_COMMENTS_PROMPT_DX KPDIAGMSG_PROMPT_DX
#define KPDIAGMSG_COMMENTS_PROMPT_Y (KPDIAGMSG_EMAIL_EDIT_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_COMMENTS_PROMPT_NUMLINES 1

#define KPDIAGMSG_COMMENTS_EDIT_X KPDIAGMSG_COMMENTS_PROMPT_X
#define KPDIAGMSG_COMMENTS_EDIT_DX KPDIAGMSG_EDIT_DX
#define KPDIAGMSG_COMMENTS_EDIT_Y (KPDIAGMSG_COMMENTS_PROMPT_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + KPW_WND_MARGIN)
#define KPDIAGMSG_COMMENTS_EDIT_NUMLINES 1 // 5

#define KPDIAGMSG_FILE_PROMPT_X KPDIAGMSG_ICON_X
#define KPDIAGMSG_FILE_PROMPT_DX KPDIAGMSG_PROMPT_DX
#define KPDIAGMSG_FILE_PROMPT_Y (KPDIAGMSG_COMMENTS_EDIT_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + iaCtrlRowHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] * (KPDIAGMSG_COMMENTS_EDIT_NUMLINES - 1) + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_FILE_PROMPT_NUMLINES 2

#define KPDIAGMSG_FILE_EDIT_X KPDIAGMSG_ICON_X
#define KPDIAGMSG_FILE_EDIT_DX KPDIAGMSG_EDIT_DX
#define KPDIAGMSG_FILE_EDIT_Y (KPDIAGMSG_FILE_PROMPT_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + iaCtrlRowHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] * (KPDIAGMSG_FILE_PROMPT_NUMLINES - 1) + KPW_WND_MARGIN)
#define KPDIAGMSG_FILE_EDIT_NUMLINES 1

#define KPDIAGMSG_FILE_BUT_X (KPDIAGMSG_FILE_EDIT_X + KPDIAGMSG_FILE_EDIT_DX + KPW_WND_MARGIN)
#define KPDIAGMSG_FILE_BUT_Y KPDIAGMSG_FILE_EDIT_Y

#define KPDIAGMSG_LINE2_Y (KPDIAGMSG_FILE_EDIT_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + KPW_WND_MARGIN * 3)

#define KPDIAGMSG_EXPL1_X (KPDIAGMSG_ICON_X + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_EXPL1_DX (KPDIAGMSG_EDIT_DX + KPW_WND_MARGIN + KPW_BUTTON_HGT - KPW_WND_MARGIN * 3)
#define KPDIAGMSG_EXPL1_Y (KPDIAGMSG_LINE2_Y + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_EXPL1_NUMLINES 2
#define KPDIAGMSG_EXPL1_STYLE KPW_CONTROL_STYLE_NORMAL
#define KPDIAGMSG_EXPL1_NUMPOS (KPDIAGMSG_EXPL1_DX * (((MsgLang == KpLangRu_p) || (MsgLang == KpLangRu_1251_p) || (MsgLang == KpLangRu_0_p))?9:10)/iaCtrlTextFactorsMean[KPDIAGMSG_EXPL1_STYLE])

#define KPDIAGMSG_OK_BUT_X (KPDIAGMSG_CANCEL_BUT_X - KPW_WND_MARGIN - KPW_BUTTON_WDT)
// #define KPDIAGMSG_OK_BUT_Y (KPDIAGMSG_LINE2_Y + KPW_WND_MARGIN * 3)
#define KPDIAGMSG_OK_BUT_Y (KPDIAGMSG_EXPL1_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + iaCtrlRowHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] * (KPDIAGMSG_EXPL1_NUMLINES - 1) + KPW_WND_MARGIN * 3)

#define KPDIAGMSG_CANCEL_BUT_X (KPDIAGMSG_WND_DX - iWndBorderWdt * 2 - KPW_WND_MARGIN * 3 - KPW_BUTTON_WDT)
#define KPDIAGMSG_CANCEL_BUT_Y KPDIAGMSG_OK_BUT_Y

#define KPDIAGMSG_WND_DX (iWndBorderWdt * 2 + KPW_WND_MARGIN * 3 * 2 + KPDIAGMSG_FILE_EDIT_DX + KPW_WND_MARGIN + KPW_BUTTON_HGT)
#define KPDIAGMSG_WND_DY (iWndBorderWdt * 2 + iWndMenuHgt + KPDIAGMSG_OK_BUT_Y + KPW_BUTTON_HGT + KPW_WND_MARGIN * 3)

#endif


// ================================================== DiagMsg ið kitø klaidø
#ifdef KP_ERR_SENDDIAGMSG
#define KPERRMSG_EDIT_DX 500
#define KPERRMSG_PROMPT_DX (KPERRMSG_EDIT_DX + KPW_WND_MARGIN + KPW_BUTTON_HGT)

#define KPERRMSG_ICON_X (KPW_WND_MARGIN * 3)
#define KPERRMSG_ICON_Y (KPW_WND_MARGIN * 3)
#define KPERRMSG_ICON_WDT KPW_ICON_WDT

#define KPERRMSG_MSG_X (KPERRMSG_ICON_X + KPERRMSG_ICON_WDT + KPW_WND_MARGIN * 3)
#define KPERRMSG_MSG_Y KPERRMSG_ICON_Y
#define KPERRMSG_MSG_DX (KPERRMSG_EDIT_DX - KPERRMSG_ICON_WDT - KPW_WND_MARGIN * 3)
#define KPERRMSG_MSG_NUMLINES 3
#define KPERRMSG_MSG_NUMPOS (KPERRMSG_MSG_DX * (((MsgLang == KpLangRu_p) || (MsgLang == KpLangRu_1251_p) || (MsgLang == KpLangRu_0_p))?9:10)/iaCtrlTextFactorsMean[KPERRMSG_MSG_STYLE])
#define KPERRMSG_MSG_STYLE KPW_CONTROL_STYLE_BOLD

#define KPERRMSG_LINE_X1 0
#define KPERRMSG_LINE_X2 (KPERRMSG_WND_DX - iWndBorderWdt * 2)
// #define KPERRMSG_LINE0_Y (KPERRMSG_ICON_Y + KPERRMSG_ICON_WDT + KPW_WND_MARGIN * 3)
#define KPERRMSG_LINE0_Y (KPERRMSG_MSG_Y + iaCtrlHeights[iWindowsVersionCut][KPERRMSG_MSG_STYLE] + iaCtrlRowHeights[iWindowsVersionCut][KPERRMSG_MSG_STYLE] * (KPERRMSG_MSG_NUMLINES - 1) + KPW_WND_MARGIN * 3)

#if FALSE
#define KPERRMSG_EXPL_X (KPERRMSG_ICON_X + KPW_WND_MARGIN * 3)
#define KPERRMSG_EXPL_DX (KPERRMSG_EDIT_DX + KPW_WND_MARGIN + KPW_BUTTON_HGT - KPW_WND_MARGIN * 3)
#define KPERRMSG_EXPL_Y (KPERRMSG_LINE0_Y + KPW_WND_MARGIN * 3)
#define KPERRMSG_EXPL_NUMLINES 2 // 5
#define KPERRMSG_EXPL_STYLE KPW_CONTROL_STYLE_NORMAL
#define KPERRMSG_EXPL_NUMPOS (KPERRMSG_EXPL_DX * (((MsgLang == KpLangRu_p) || (MsgLang == KpLangRu_1251_p) || (MsgLang == KpLangRu_0_p))?9:10)/iaCtrlTextFactorsMean[KPERRMSG_EXPL_STYLE])
#endif

// #define KPERRMSG_LINE1_Y (KPERRMSG_EXPL_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + iaCtrlRowHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] * (KPERRMSG_EXPL_NUMLINES - 1) + KPW_WND_MARGIN * 3)

#define KPERRMSG_EMAIL_PROMPT_X KPERRMSG_ICON_X
#define KPERRMSG_EMAIL_PROMPT_DX KPERRMSG_PROMPT_DX
// #define KPERRMSG_EMAIL_PROMPT_Y (KPERRMSG_LINE1_Y + KPW_WND_MARGIN * 3)
// #define KPERRMSG_EMAIL_PROMPT_Y (KPERRMSG_EXPL_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + iaCtrlRowHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] * (KPERRMSG_EXPL_NUMLINES - 1) + KPW_WND_MARGIN * 3)
#define KPERRMSG_EMAIL_PROMPT_Y (KPERRMSG_LINE0_Y + KPW_WND_MARGIN * 3)
// #define KPERRMSG_EMAIL_PROMPT_Y (KPERRMSG_EXPL_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + iaCtrlRowHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] * (KPERRMSG_EXPL_NUMLINES - 1) + KPW_WND_MARGIN * 3)
#define KPERRMSG_EMAIL_PROMPT_NUMLINES 1

#define KPERRMSG_EMAIL_EDIT_X KPERRMSG_EMAIL_PROMPT_X
#define KPERRMSG_EMAIL_EDIT_DX KPERRMSG_EDIT_DX
#define KPERRMSG_EMAIL_EDIT_Y (KPERRMSG_EMAIL_PROMPT_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + KPW_WND_MARGIN)
#define KPERRMSG_EMAIL_EDIT_NUMLINES 1

// #define KPERRMSG_LINE2_Y (KPERRMSG_EMAIL_EDIT_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + KPW_WND_MARGIN * 3)

#define KPERRMSG_EXPL1_X (KPERRMSG_ICON_X + KPW_WND_MARGIN * 3)
#define KPERRMSG_EXPL1_DX (KPERRMSG_EDIT_DX + KPW_WND_MARGIN + KPW_BUTTON_HGT - KPW_WND_MARGIN * 3)
// #define KPERRMSG_EXPL1_Y (KPERRMSG_LINE2_Y + KPW_WND_MARGIN * 3)
#define KPERRMSG_EXPL1_Y (KPERRMSG_EMAIL_EDIT_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + iaCtrlRowHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] * (KPERRMSG_EMAIL_EDIT_NUMLINES - 1) + KPW_WND_MARGIN * 3)
#define KPERRMSG_EXPL1_NUMLINES 2
#define KPERRMSG_EXPL1_STYLE KPW_CONTROL_STYLE_NORMAL
#define KPERRMSG_EXPL1_NUMPOS (KPERRMSG_EXPL1_DX * (((MsgLang == KpLangRu_p) || (MsgLang == KpLangRu_1251_p) || (MsgLang == KpLangRu_0_p))?9:10)/iaCtrlTextFactorsMean[KPERRMSG_EXPL1_STYLE])

#define KPERRMSG_OK_BUT_X (KPERRMSG_CANCEL_BUT_X - KPW_WND_MARGIN - KPW_BUTTON_WDT)
// #define KPERRMSG_OK_BUT_Y (KPERRMSG_LINE2_Y + KPW_WND_MARGIN * 3)
#define KPERRMSG_OK_BUT_Y (KPERRMSG_EXPL1_Y + iaCtrlHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] + iaCtrlRowHeights[iWindowsVersionCut][KPW_CONTROL_STYLE_NORMAL] * (KPERRMSG_EXPL1_NUMLINES - 1) + KPW_WND_MARGIN * 3)

#define KPERRMSG_CANCEL_BUT_X (KPERRMSG_WND_DX - iWndBorderWdt * 2 - KPW_WND_MARGIN * 3 - KPW_BUTTON_WDT)
#define KPERRMSG_CANCEL_BUT_Y KPERRMSG_OK_BUT_Y

#define KPERRMSG_WND_DX (iWndBorderWdt * 2 + KPW_WND_MARGIN * 3 * 2 + KPERRMSG_EMAIL_EDIT_DX)
#define KPERRMSG_WND_DY (iWndBorderWdt * 2 + iWndMenuHgt + KPERRMSG_OK_BUT_Y + KPW_BUTTON_HGT + KPW_WND_MARGIN * 3)

#endif


// -------------------------------
#ifdef KP_ERR_SENDDIAGMSG
typedef struct
{
const unsigned char *m_lpszMsg;
LPCTSTR m_lpszIconID;
} SendDiagMsgPars;
#endif

// ================================================== KpErrorProcClass
class KpErrorProcClass // former KpErrorProc_tag
{
   bool bInLineFlag;
#ifdef Envir
#if (Envir==MSWin32) || (Envir==MSWin32Mfc)
   KpConsole
#else
   void
#endif
#else
   void
#endif
      *m_pClMessages;

public: // !!!
   long lMsgPar;
   unsigned char szaMsgText[KP_MSG_LEN+1]; // former lpszMsgPar

   HRESULT  lhLastRetc;             // fields supressing duplicate error messages
   unsigned char lpszLastMessageText[KP_MSG_LEN+1];
   bool     bLastSevereError;
   unsigned char lpszLastSourceFile[KP_MAX_FNAME_LEN+1];
   int      iLastSourceLine;
   long     lLastMainKeyId;
   int      iKptCodeTable;          // code table for output of 16 bit messages

#ifdef KP_ERR_SENDDIAGMSG
// SendDiagMsg() laukai
public:
   HWND m_hDiagMsgWindow;
   bool m_bShiftFl;
   HWND m_hDiagEmailEdit;
   HWND m_hDiagCommentsEdit;
   HWND m_hDiagFileEdit;
   HWND m_hDiagFileButton;
   HWND m_hDiagOkButton;
   HWND m_hDiagCancelButton;
   unsigned char m_lpszDiagEmail[KP_MAX_FNAME_LEN + 1];
   unsigned char m_lpszDiagComments[KP_MAX_FILE_LIN_LEN + 1];
   unsigned char m_lpszDiagFile[KP_MAX_FNAME_LEN + 1];
#endif

public:
   KpErrorProcClass(bool bInLine, int iKptCtbl);
                                    // bInLine - in-line text messages, no windows
                                    // iKptCtbl - initial value of iKptCodeTable

#ifdef Envir
#if (Envir==MSWin32) || (Envir==MSWin32Mfc)
   HRESULT SetMsgList(KpConsole *pClMessages); // initialisation task - do not use m_pClMessages inside of SetMsgList()
#endif
#endif

   HRESULT SetLPar(long lPar); // set value of lMsgPar
   HRESULT SetLTxt(const unsigned char *lpszTxt); // set value of szaMsgText

#ifdef Envir
#if Envir==MSWin32Mfc
   HRESULT SetParentWindow(CWnd* pParent);
#else
   HRESULT SetParentWindow(HWND hParent);
#endif
#endif

   static HRESULT Message(const unsigned char *lpszMsg);

#ifdef Envir
   HRESULT StrDecode(unsigned char *lpszOutStr, const KpChar *uiaMsg /*, int iMsgLen */);

   HRESULT Message16(const KpChar *uiaMsg /*, int iMsgLen */);
                                    // output of 16-bit Kpt message
#endif

   static HRESULT FormatErrorMessage
   (
      const HRESULT lhRetc,
      unsigned char *lpszMsg
   );                         // generates the error message
                              // lpszMsg is used to return back the error text, must
                              //    be not shorter, than KP_MSG_LEN bytes
                              // must be defined locally for processing special errors of application
                              // usually calls FormatErrorMessageMain()

   static HRESULT FormatErrorMessageMain
   (
      const HRESULT lhRetc,
      unsigned char *lpszMsg
   );                         // like FormatErrorMessage(), but processes common errors
                              // usually called by FormatErrorMessage()
                              // lpszMsg is used to return back the error text, must
                              //    be not shorter, than KP_MSG_LEN bytes

   static HRESULT FormatErrorMessageSystem
   (
      long lWindowsErrorCode,
      unsigned char *lpszMsg,
      bool bFullFormat
   );                         // formats windows system error message
                              // bFullFormat==False - tik lietuviskas pranesimas
                              // lpszMsg is used to return back the error text, must
                              //    be not shorter, than KP_MSG_LEN bytes

   static unsigned char *FormatErrorMessageHTTP(int iHTTP_RetCode);
   static int TranslToHTTP_RetCode(HRESULT iRetc); // verèia KP klaidos kodà KP_E_... á HTTP atsakymo kodà HTTP_ANSW_... // former TranslHTTP_RetCode()
   static HRESULT TranslFromHTTP_RetCode(int iHTTP_RetCode); // verèia HTTP atsakymo kodà HTTP_ANSW_... á KP klaidos kodà KP_E_...

// --------------------------------------
// #ifdef Envir
// #if (Envir==MSWin32) || (Envir==MSWin32Mfc)
   const HRESULT OutputErrorMessage          // outputs error message
   (
      HRESULT lhRetc,
      const unsigned char *lpszMessageText,  // lpszMessageText - additional error text, not output,
      bool bPutMessageAndSetError,  // former bSevereError // True - praneðimas iðvedamas ir rezultatas nustatomas á lhRetc; False - praneðimas tik á log failà, rezultatas S_OK
      const char *lpszSourceFile,
      int iSourceLine,
      long lMainKeyId,              // if lMainKeyId == 0, value of lMsgPar will be taken
      void /* KpConsole */ *pListBox = NULL, // listbox to text output, if NULL - simply outputs KpMsgOut()
      bool bPutMessage = TRUE,      // ar isvesti á ekranà - negalima langu atidarymo procedûroms (klaidø praneðimai vël rekursiðkai iðkvies langø atidarymus)
                                    // jei bent vienas ið bPutMessage ar bPutMessageAndSetError þþ False, praneðimas neiðvedamas
      bool bSevereError = TRUE,     // if bSevereError == TRUE, returns lhRetc as return code,
                                    //    otherwise returns TV_S_OK, so execution can proceed
      bool bSendDiagMsg = TRUE,
      const HRESULT *plRetcAddrs = NULL   // retc adresas steko dumpinimui; retc turi bûti pirmas lokalus parametras 
   );
// #endif
// #endif

// --------------------------------------
// #ifdef Envir
// #if (Envir==MSWin32) || (Envir==MSWin32Mfc)
   const HRESULT OutputErrorMessage
   (
      HRESULT lhRetc,
      const char *lpszMessageText,
      bool bPutMessageAndSetError,
      const char *lpszSourceFile,
      int iSourceLine,
      long lMainKeyId,
      void /* KpConsole */ *pListBox = NULL,
      bool bPutMessage = TRUE,
      bool bSevereError = TRUE,
      bool bSendDiagMsg = TRUE,
      const HRESULT *plRetcAddrs = NULL 
   );                         
// #endif
// #endif

// --------------------------------------
// #ifdef Envir
// #if (Envir==MSWin32) || (Envir==MSWin32Mfc)
   const HRESULT OutputErrorMessage
   (
      HRESULT lhRetc,
      const KpChar *iazMessageText,
      bool bPutMessageAndSetError,
      const char *lpszSourceFile,
      int iSourceLine,
      long lMainKeyId,
      void /* KpConsole */ *pListBox = NULL,
      bool bPutMessage = TRUE,
      bool bSevereError = TRUE,
      bool bSendDiagMsg = TRUE,
      const HRESULT *plRetcAddrs = NULL 
   );
// #endif
// #endif

// --------------------------------------
// #ifdef Envir
// #if (Envir==MSWin32) || (Envir==MSWin32Mfc) || (Envir==MSWin32Con) || (Envir==MSWin32ConMfc)
   const HRESULT OutputErrorMessage  // additionally formats Windows error message
   (                           // using FormatMessage()
      HRESULT lhRetc,
      LONG lWindowsErrorCode,  // HINSTANCE hErrorCode,
      bool bPutMessageAndSetError,
      const char *lpszSourceFile,
      int iSourceLine,
      long lMainKeyId,
      void /* KpConsole */ *pListBox = NULL,
      bool bPutMessage = TRUE,
      bool bSevereError = TRUE,
      bool bSendDiagMsg = TRUE,
      const HRESULT *plRetcAddrs = NULL 
   );
// #endif
// #endif

// --------------------------------------
#ifdef KP_ERR_SENDDIAGMSG
   const HRESULT SendDiagMsg(unsigned char *lpszMsg, LPCTSTR lpszIconID, HRESULT lhRetc, unsigned char *lpszMsgTail);
   const HRESULT OpenDiagMsgWindow(unsigned char *lpszMsg, LPCTSTR lpszIconID, HRESULT lhRetc);
#endif
};

#define KP_OUTPUT_THREAD_CONTENTS {{ \
CONTEXT context; \
context.ContextFlags  = CONTEXT_CONTROL; \
GetThreadContext(GetCurrentThread(), &context); \
PutLogMessage_("Thread context: eip: %08x esp: %08x ebp: %08x &retc: %08x", context.Eip, context.Esp, context.Ebp, &retc); \
}}

extern void StackDump(const HRESULT *plRetcAddrs, bool bDumpStack = False); // , const char *lpszSrcFile = null, int iFileLine = 0); 
   // bDumpStack == False – tik trace, pilno dumpo neiðveda
   // lpszSrcFile != null – ne á bendrà logà, o á statiná dabar vykdomos procedûros failà: %TEMP%\<lpszProdName>_stat.log

#if FALSE
#define KP_STACK_DUMP {{ KP_OUTPUT_THREAD_CONTENTS; StackDump(&retc); }}
#endif

#define KP_STACK_DUMP {{ StackDump(&retc); }}

// -----------------------------
// #define KP_PROC_START HRESULT retc = S_OK; StackDump(&retc, False, __FILE__, __LINE__);

// #define KP_PROC_END StackDump(&retc, False, __FILE__, __LINE__); return(retc);

// -----------------------------
#ifdef KP_ERR_SENDDIAGMSG
BOOL CALLBACK KpErrSendDiagMsgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK KpErrSendErrMsgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif


// #ifdef Envir
// #if (Envir==MSWin32) || (Envir==MSWin32Mfc)
extern HRESULT KpOutputErrorMessage
(
   const HRESULT lhRetc,
   const unsigned char *lpszMessageText,
   bool bPutMessageAndSetError, // former bSevereError
   const char *lpszSourceFile,
   const int iSourceLine,
   const long lMainKeyId,
   void /* KpConsole */ *pListBox = NULL,
   bool bPutMessage = TRUE,
   bool bSevereError = TRUE,
   bool bSendDiagMsg = TRUE,
   const HRESULT *plRetcAddrs = NULL 
);

extern HRESULT KpOutputErrorMessage
(
   const HRESULT lhRetc,
   const char *lpszMessageText,
   bool bPutMessageAndSetError, // former bSevereError
   const char *lpszSourceFile,
   const int iSourceLine,
   const long lMainKeyId,
   void /* KpConsole */ *pListBox = NULL,
   bool bPutMessage = TRUE,
   bool bSevereError = TRUE,
   bool bSendDiagMsg = TRUE,
   const HRESULT *plRetcAddrs = NULL 
);

extern HRESULT KpOutputErrorMessage
(
   const HRESULT lhRetc,
   const KpChar *iazMessageText,
   bool bPutMessageAndSetError, // former bSevereError
   const char *lpszSourceFile,
   const int iSourceLine,
   const long lMainKeyId,
   void /* KpConsole */ *pListBox = NULL,
   bool bPutMessage = TRUE,
   bool bSevereError = TRUE,
   bool bSendDiagMsg = TRUE,
   const HRESULT *plRetcAddrs = NULL 
);

extern HRESULT KpOutputErrorMessage
(
   const HRESULT lhRetc,
   LONG lWindowsErrorCode,  // HINSTANCE hErrorCode,
   bool bPutMessageAndSetError, // former bSevereError
   const char *lpszSourceFile,
   const int iSourceLine,
   const long lMainKeyId,
   void /* KpConsole */ *pListBox = NULL,
   bool bPutMessage = TRUE,
   bool bSevereError = TRUE,
   bool bSendDiagMsg = TRUE,
   const HRESULT *plRetcAddrs = NULL 
);
// #endif
// #endif


extern
#ifdef KPSTTRG_DLL
// "C" // __declspec(dllexport)
#endif
#ifdef KPSTTRG_DLL_IMP
/* "C" */ __declspec(dllimport)
#endif
KpErrorProcClass KpErrorProc;    // must be defined in application file


// --------------------------------------------------------
#if FALSE
#define KpOutputErrorMessage_(retc, lhRetc, lpszMessageText, bPutMessageAndSetError, lpszSourceFile, iSourceLine, lMainKeyId, pListBox, bPutMessage, bSevereError, bSendDiagMsg, plRetcAddrs) {{ \
if(bSevereError) \
KP_OUTPUT_THREAD_CONTENTS; \
retc = KpErrorProc.OutputErrorMessage(lhRetc, lpszMessageText, bPutMessageAndSetError, lpszSourceFile, iSourceLine, lMainKeyId, pListBox, bPutMessage, bSevereError, bSendDiagMsg, plRetcAddrs); \
}}
#endif

#define KpOutputErrorMessage_(retc, lhRetc, lpszMessageText, bPutMessageAndSetError, lpszSourceFile, iSourceLine, lMainKeyId, pListBox, bPutMessage, bSevereError, bSendDiagMsg, plRetcAddrs) {{ \
retc = KpErrorProc.OutputErrorMessage(lhRetc, lpszMessageText, bPutMessageAndSetError, lpszSourceFile, iSourceLine, lMainKeyId, pListBox, bPutMessage, bSevereError, bSendDiagMsg, plRetcAddrs); \
}}

// --------------------------------------------------------
// bCond - testuojama sàlyga, jei False – klaida
// lhErrCode - klaidos kodas, þr. kperrno.h
// Msg - lpsz arba long - tekstinis praneðimas ar klaidos kodas ið GetLastError()
// bFatal - ar rimta klaida, jei False - tik perspëjimas
// #define KP_ERROR(lhErrCode) (KpOutputErrorMessage_(retc, lhErrCode, 0L, TRUE, __FILE__, __LINE__, 0L, NULL, True, True, True, &retc))
#define KP_ERROR(lhErrCode, Msg) {{ KpOutputErrorMessage_(retc, lhErrCode, Msg, TRUE, __FILE__, __LINE__, 0L, NULL, True, True, True, &retc); }}
#define KP_ERRORA(lhErrCode, Msg) {{ KpOutputErrorMessage_(reta, lhErrCode, Msg, TRUE, __FILE__, __LINE__, 0L, NULL, True, True, True, &retc); }}
// #define KP_ERRORC(lhErrCode, Msg) {{ KpOutputErrorMessage_(m_lhOpenResult, lhErrCode, Msg, TRUE, __FILE__, __LINE__, 0L, NULL, True, True, True, NULL); }}
#define KP_ERROR0(lhErrCode, Msg) {{ HRESULT retc00 = S_OK; KpOutputErrorMessage_(retc00, lhErrCode, Msg, TRUE, __FILE__, __LINE__, 0L, NULL, True, True, True, &retc); }} // iðveda klaidos praneðimà, retc nekeièia
#define KP_ERROR0N(lhErrCode, Msg) {{ KpOutputErrorMessage_(retc0, lhErrCode, Msg, TRUE, __FILE__, __LINE__, 0L, NULL, True, True, False, &retc); }} // klaida su retc0, nesiunèia diag. msg.
#define KP_ERRORL(lhErrCode, Msg) {{ retc = lhErrCode; HRESULT retc00 = S_OK; KpOutputErrorMessage_(retc00, lhErrCode, Msg, False, __FILE__, __LINE__, 0L, NULL, True, True, False, &retc); }} // praneðimas tik á logà, retc nustato
#define KP_ERRORWE(lhErrCode, Msg, bPutMessageAndSetError) {{ retc = lhErrCode; HRESULT retc00 = S_OK; KpOutputErrorMessage_(retc00, lhErrCode, Msg, bPutMessageAndSetError, __FILE__, __LINE__, 0L, NULL, True, bPutMessageAndSetError, True, &retc); }} // praneðimas ir fataliðkumas – pagal bPutMessageAndSetError, klaidos kodas – visada

// èia ið tikrøjø KP_ASSERT(False, lhErrCode, Msg, False); - nebylus iðvedimas tik á log failà (ir retc iðvalymas)
// #define KP_WARNING(lhErrCode) {{ HRESULT retc00 = S_OK; KpOutputErrorMessage_(retc00, lhErrCode, 0L, FALSE, __FILE__, __LINE__, 0L, NULL, True, True, True, &retc); }}
#define KP_WARNING(lhErrCode, Msg) {{ HRESULT retc00 = S_OK; KpOutputErrorMessage_(retc00, lhErrCode, Msg, FALSE, __FILE__, __LINE__, 0L, NULL, False, False, True, &retc); retc = S_OK; }}
#define KP_WARNING0(lhErrCode, Msg) {{ HRESULT retc00 = S_OK; KpOutputErrorMessage_(retc00, lhErrCode, Msg, FALSE, __FILE__, __LINE__, 0L, NULL, False, False, True, &retc); }}

// èia tikras warningo praneðimas
#define KP_WARNINGW(lhErrCode, Msg) {{ HRESULT retc00 = S_OK; KpOutputErrorMessage_(retc00, lhErrCode, Msg, True, __FILE__, __LINE__, 0L, NULL, True, False, True, &retc); }}

// #define KP_ASSERT(bCond, lhErrCode, Msg, bFatal)  {{ HRESULT retc00 = S_OK; if(!(bCond)) KpOutputErrorMessage_(retc00, lhErrCode, Msg, bFatal, __FILE__, __LINE__, 0L, NULL, True, True, True, &retc); if(bFatal){ if(SUCCEEDED(retc)) retc = lhErrCode; } else retc = S_OK; }}
// #define KP_ASSERT(bCond, lhErrCode, Msg, bFatal)  {{ if(SUCCEEDED(retc)) if(!(bCond)) KpOutputErrorMessage_(retc, lhErrCode, Msg, bFatal, __FILE__, __LINE__, 0L, NULL, True, True, True, &retc); }}
#define KP_ASSERT(bCond, lhErrCode, Msg, bPutMessageAndSetError)  {{ if(SUCCEEDED(retc)) if(!(bCond)){ KpOutputErrorMessage_(retc, lhErrCode, Msg, bPutMessageAndSetError, __FILE__, __LINE__, 0L, NULL, bPutMessageAndSetError, bPutMessageAndSetError, True, &retc); }}} // praneðimas, klaidos kodas ir fataliðkumas – pagal bPutMessageAndSetError
#define KP_ASSERTE(bCond, lhErrCode, Msg, bPutMessage)  {{ if(SUCCEEDED(retc)) if(!(bCond)){ retc = lhErrCode; HRESULT retc00 = S_OK; KpOutputErrorMessage_(retc00, lhErrCode, Msg, bPutMessage, __FILE__, __LINE__, 0L, NULL, True, True, True, &retc); }}} // klaidos nustatymas visada, praneðimas – pagal bPutMessage, visada fataliðkas
#define KP_ASSERTW(bCond, lhErrCode, Msg, bFatal)  {{ if(SUCCEEDED(retc)) if(!(bCond)){ KpOutputErrorMessage_(retc, lhErrCode, Msg, True, __FILE__, __LINE__, 0L, NULL, True, bFatal, True, &retc); if(!bFatal) retc = S_OK; }}} // praneðimas visada á ekranà, klaidos nustatymas – pagal bFatal
// #define KP_ASSERTC(bCond, lhErrCode, Msg, bPutMessageAndSetError)  {{ if(SUCCEEDED(m_lhOpenResult)) if(!(bCond)){ KpOutputErrorMessage_(m_lhOpenResult, lhErrCode, Msg, bPutMessageAndSetError, __FILE__, __LINE__, 0L, NULL, True, bPutMessageAndSetError, True, NULL); }}}
#define KP_ASSERTA(bCond, lhErrCode, Msg, bPutMessageAndSetError)  {{ if(SUCCEEDED(reta)) if(!(bCond)){ KpOutputErrorMessage_(reta, lhErrCode, Msg, bPutMessageAndSetError, __FILE__, __LINE__, 0L, NULL, True, bPutMessageAndSetError, True, &retc); }}}
#define KP_ASSERT0(bCond, lhErrCode, Msg, bPutMessageAndSetError)  {{ if(!(bCond)){ KpOutputErrorMessage_(retc0, lhErrCode, Msg, bPutMessageAndSetError, __FILE__, __LINE__, 0L, NULL, True, bPutMessageAndSetError, True, &retc); } if(SUCCEEDED(retc)) retc = retc0; }} // besàlyginis klaidos tikrinimas su retc0; retc nustatymas
#define KP_ASSERT00(bCond, lhErrCode, Msg, bPutMessageAndSetError)  {{ if(SUCCEEDED(retc0)) if(!(bCond)){ KpOutputErrorMessage_(retc0, lhErrCode, Msg, bPutMessageAndSetError, __FILE__, __LINE__, 0L, NULL, True, bPutMessageAndSetError, True, &retc); }}} // klaidos tikrinimas su retc0
#define KP_ASSERT0N(bCond, lhErrCode, Msg, bPutMessageAndSetError)  {{ if(SUCCEEDED(retc0)) if(!(bCond)){ KpOutputErrorMessage_(retc0, lhErrCode, Msg, bPutMessageAndSetError, __FILE__, __LINE__, 0L, NULL, True, bPutMessageAndSetError, False, &retc); }}} // klaidos tikrinimas su retc0, nesiunèia diag. msg.
#define KP_ASSERT0E(bCond, lhErrCode, Msg, bPutMessage)  {{ if(SUCCEEDED(retc0)) if(!(bCond)){ retc0 = lhErrCode; HRESULT retc00 = S_OK; KpOutputErrorMessage_(retc00, lhErrCode, Msg, bPutMessage, __FILE__, __LINE__, 0L, NULL, True, True, True, &retc); }}} // klaidos nustatymas su retc0; iðvedimas á ekranà – pagal bPutMessage, visada fataliðkas
#define KP_ASSERT0EN(bCond, lhErrCode, Msg, bPutMessage)  {{ if(SUCCEEDED(retc0)) if(!(bCond)){ retc0 = lhErrCode; HRESULT retc00 = S_OK; KpOutputErrorMessage_(retc00, lhErrCode, Msg, bPutMessage, __FILE__, __LINE__, 0L, NULL, True, True, False, &retc); }}} // klaidos nustatymas su retc0; iðvedimas á ekranà – pagal bPutMessage, visada fataliðkas, nesiunèia diag. msg.
#define KP_ASSERTS(bCond)  {{ if(SUCCEEDED(retc)) if(!(bCond)) KP_ERROR(KP_E_SYSTEM_ERROR, null); }} // former KP_ASSERT_S()
#define KP_ASSERT_(bCond, lhErrCode)  {{ if(!(bCond)) KP_ERROR0(lhErrCode, null); }}


//------------------------------------- for compatibility with kpx
extern void cferr(int err, const char *lpszSourceFile, int iSourceLine);


#if CompilerGr==Mingw
extern int KpExceptionFilter(unsigned int code, unsigned int excToFilter);
#endif

#endif // #ifndef kperr_included

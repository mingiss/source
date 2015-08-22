// -----------------------------------------
// scandtd.h
// dtd skenerio aprasas
//

//-------------------------------------------------------------------------
#ifndef kpstart_included
#define kpstart_included

#define SCAN_DTD_MAX_NUM_OF_TAGS 500

extern string karpyk(string arg);

typedef class XmltDtd_tag
{
   HRESULT m_lhOpenResult; // objekto kurimo klaidos kodas
   
   string **m_ppsTagai;

   int m_iTagsk;

   string *m_psGalNames;
   int *m_piGalVaikuSk;
   KpChar **m_ppiGalVaikai;   // tagu kodai XM_FirstTagCode - ...

public:
   XmltDtd_tag(char *lpszFileName); // konstruktorius
   ~XmltDtd_tag(void); // destruktorius
   HRESULT GetOpenResult(void){ return(m_lhOpenResult); };  // grazina objekto kurimo klaidos koda

   int GetTagSk(void){ return(m_iTagsk); };
   string *GetGalNames(void){ return(m_psGalNames); };
   int *GetGalVaikuSk(void){ return(m_piGalVaikuSk); };
   KpChar **GetGalVaikai(void){ return(m_ppiGalVaikai); };
   string GetGalName(KpChar iTag);  // iTag - tago simbolio kodas XM_FirstTagCode - klaidos atvejju grazina tuscia eilute 
   int GetGalVaikuSkVienas(KpChar iTag); // grazina m_piGalVaikuSk[(iTag - XM_FirstTagCode)/2]
   string * GetGalVaikaiVienas(KpChar iTag); // grazina m_ppiGalVaikai[(iTag - XM_FirstTagCode)/2]
   bool IsEmbedded(KpChar iTag, KpChar iFatherTag); // ar iTag gali buti iFatherTag vaiku?  

  
} XmltDtd;

#endif

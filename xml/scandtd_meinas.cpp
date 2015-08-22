// -----------------------------------------
// scandtd_meinas.cpp
// dtd skenerio testas
//

// -----------------------------------------
#include "envir.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>

#include "kpstdlib.h"
#include "kptt.h"
#include "kpstring.h"
#include "kperr.h"
#include "tvmain.h"
#include "tvxml.h"
#include "xmlp.h"
#include "xmlh.h"
#include "xmlf.h"
#include "xmlo1.h"
#include "xmlt.h"
#include "scandtd.h"


// -----------------------------------------
KpErrorProc_tag KpErrorProc(True, 71);
int SortMode=KP_LNG_LIT;


// -----------------------------------------
HRESULT TestCompilerSettingsLocal(void)
{
#include "kpstcs.cpp"
}


// -----------------------------------------
class XmltDtdMeinas : public XmltDtd_tag
{
public:
   XmltDtdMeinas(char *lpszFileName) : XmltDtd_tag(lpszFileName) {};
   HRESULT TestXmltDtd(void);
   HRESULT CompareXmltDtd(void);
};


// -----------------------------------------
HRESULT XmltDtdMeinas::TestXmltDtd(void)
{
HRESULT retc = GetOpenResult();

string *gal_names = GetGalNames();
int *gal_vaiku_sk = GetGalVaikuSk();
KpChar **gal_vaikai = GetGalVaikai();

   if(((gal_names == NULL) || (gal_vaiku_sk == NULL) || (gal_vaikai == NULL)) && SUCCEEDED(retc))
      retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, TRUE, __FILE__, __LINE__, 0L);

   if(SUCCEEDED(retc)) for (int ii=0; ii<GetTagSk(); ii++) 
   {
      cout << XM_FirstTagCode + ii*2 << ":" << gal_names[ii] << " "; 
      for (int jj=0; jj<gal_vaiku_sk[ii]; jj++)
         cout << gal_vaikai[ii][jj] << " ";
      cout << endl;
   }

return(retc);
}


// -----------------------------------------
HRESULT XmltDtdMeinas::CompareXmltDtd(void)
{
HRESULT retc = GetOpenResult();

string *gal_names = GetGalNames();
int *gal_vaiku_sk = GetGalVaikuSk();
KpChar **gal_vaikai = GetGalVaikai();
int tagsk = GetTagSk();
string *xmlt_names_local = new string[XC_TG_NumOfDictTags00/2];
string *gal_names_local = new string[tagsk];
int num_of_xmlt_tags=XC_TG_NumOfDictTags00/2;

// ----------------------
   if(((gal_names == NULL) || (gal_vaiku_sk == NULL) || (gal_vaikai == NULL)) && SUCCEEDED(retc))
      retc=KpErrorProc.OutputErrorMessage(KP_E_SYSTEM_ERROR, null, TRUE, __FILE__, __LINE__, 0L);
   if(((xmlt_names_local==NULL) || (gal_names_local==NULL)) && SUCCEEDED(retc))
      retc=KpErrorProc.OutputErrorMessage(KP_E_OUTOFMEM, null, TRUE, __FILE__, __LINE__, 0L);

// ----------------------
int jj = 0;   
   if(SUCCEEDED(retc)) for(int ii=0; ii<XC_TG_NumOfDictTags00/2; ii++)
   {
      if(plpszaXmlttDictTags[ii*2][0])
      {
         xmlt_names_local[jj] = (const char *)plpszaXmlttDictTags[ii*2];
         xmlt_names_local[jj] = ExtractTagName(xmlt_names_local[jj]);
         jj++;
      }
      else num_of_xmlt_tags--;
   }
   if(SUCCEEDED(retc)) qsort(xmlt_names_local, num_of_xmlt_tags, sizeof(string), Tv_string_Cmp);

   if(SUCCEEDED(retc)) for(int ii=0; ii<tagsk; ii++)
      gal_names_local[ii] = gal_names[ii];
   if(SUCCEEDED(retc)) qsort(gal_names_local, tagsk, sizeof(string), Tv_string_Cmp);

// ----------------------
   if((tagsk != num_of_xmlt_tags) && SUCCEEDED(retc))
      cout << "Nesutampa tagu skaicius: " << num_of_xmlt_tags << " - " << tagsk << endl;

// ----------------------
int errors=0;
bool first_error = True;
   if(SUCCEEDED(retc)) for (int ii=0; (ii<min(tagsk, num_of_xmlt_tags)) && (errors<15); ii++) 
   {
      if(gal_names_local[ii] != xmlt_names_local[ii])
      {
         if(first_error)
         {
            cout << "Nesutampa tagu vardai: " << endl;
            first_error = False;
         }
         cout << ii << ": " << xmlt_names_local[ii] << " - " << gal_names_local[ii] << endl;
         errors++;
      }
   }

   if((errors>=15) && SUCCEEDED(retc)) cout << "[...]" << endl;

return(retc);
}


// -----------------------------------------
int main() 
{
HRESULT retc=S_OK;

// char failas[50] = "miau.dtd";
char failas[50] = {"tvxmlt.dtd"};
// cout << "Ivesk dtd failo varda:";
// cin >> failas;

// char pathas[50] = "d:\\!projektai\\xml\\";
// char pathas[50] = {"..\\"};
char pathas[50] = {""};

XmltDtdMeinas *xmlt_dtd = NULL;

   if(SUCCEEDED(retc)) retc = KpInit();

   if(SUCCEEDED(retc)) 
   {
      strncat(pathas,failas,50);

      xmlt_dtd = new XmltDtdMeinas(pathas);
      if(xmlt_dtd) retc=xmlt_dtd->GetOpenResult();
   }

// if(SUCCEEDED(retc)) retc=xmlt_dtd->TestXmltDtd();

   if(SUCCEEDED(retc)) retc=xmlt_dtd->CompareXmltDtd();

   if(xmlt_dtd) delete xmlt_dtd;


#if CompilerGr==Watcom
system("pause");
#endif

/* if(SUCCEEDED(retc)) retc = */ KpFinit();

return(RET_CODE_MAIN(retc));
}

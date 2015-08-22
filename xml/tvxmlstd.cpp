// ==================================================
// tvxmlstd.cpp, atskirtas gabalas nuo tvxml.cpp
// XML common things
// prilinkavus prie kplibtdm.lib kazkas blogai, luzta ant priskyrimo string'ui
//

// ================================================== definitions, static fields
#include "envir.h"

#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#if OsGr==MSWin
#include <windows.h>
#endif

#include "kpstdlib.h"
#include "kperrno.h"
#include "kptt.h"
#include "kpctype.h"
#include "kpstring.h"
#include "kperr.h"
#include "tvmain.h"
#include "tvxml.h"


// -----------------------------------------
string ExtractTagName(string arg) 
{
HRESULT retc=S_OK;
int ilgis = arg.length();
char *drb = NULL;
char *pntd = NULL;
string out_str;
char cur_ch;

   KPNEWA(drb, char, ilgis + 1);

   if(SUCCEEDED(retc)) pntd = drb;

   if(SUCCEEDED(retc)) for (int ii = 0; ii < ilgis; ii++) 
   {
      cur_ch = arg[ii];
      if(!((cur_ch=='<') || (cur_ch=='>') || (cur_ch=='/') || strchr(lpszSpcEol, cur_ch)))
         *pntd++ = cur_ch;
   }

   *pntd++ = Nul;

   if(SUCCEEDED(retc)) out_str = drb;
   else out_str = "";

   KP_DELETEA(drb);

return out_str;
}

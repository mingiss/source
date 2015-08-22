// -----------------------------------------
// scandtd.cpp
// dtd skeneris
//

// -----------------------------------------
#include "envir.h"

#include <fstream.h>
#include <string.h>
#include <string>
#include <windows.h>

#if CompilerGr==Msvc
using namespace std;
#endif

#include "kpstdlib.h"
#include "kptt.h"
#if CompilerGr==Watcom
#include "kpstring.h"
#endif
#include "kperr.h"
#include "scandtd.h"
#include "tvxml.h"


// -----------------------------------------
string karpyk(string arg) 
{
string drb;
int ilgis = arg.length();

   for (int ii =0; ii< ilgis; ii++) 
      if (!((arg[ii]=='(')||(arg[ii]==')')||(arg[ii]=='*')||(arg[ii]==',')||(arg[ii]=='?')))
         drb += arg[ii];

return drb;
}


// -----------------------------------------
XmltDtd_tag::XmltDtd_tag(char *lpszFileName)
{
ifstream ff;

// -----------------
   m_lhOpenResult=S_OK;
   
   m_ppsTagai = NULL;
   m_piGalVaikuSk = NULL;
   m_ppiGalVaikai = NULL;
   m_psGalNames = NULL;
   m_iTagsk = 0;

// -----------------
   if(lpszFileName==NULL) 
      m_lhOpenResult=KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);

   if(SUCCEEDED(m_lhOpenResult)) 
   {
      ff.open(lpszFileName);
      if(ff.fail()) 
         m_lhOpenResult=KpErrorProc.OutputErrorMessage(KP_E_FILE_NOT_FOUND, lpszFileName, TRUE, __FILE__, __LINE__, 0L);
   }


// -----------------
//0 - laukiu elemento
//1 - elementas !ELEMENT
//11 - renku vaikus is !ELEMENT
//2 - elementas !ATTLIST
//21 - renku info apie !ATTLIST
//3 - elementas !ENTITY
//31 - imu !ENTITY reiksme


int mode = 0;

string tgvardas;
string tgvaikai[SCAN_DTD_MAX_NUM_OF_TAGS];
int tgvaikaisk=0;
string tgatributai[SCAN_DTD_MAX_NUM_OF_TAGS];
int tgatributaisk=0;

   if(SUCCEEDED(m_lhOpenResult))
   {
      m_ppsTagai = new string * [SCAN_DTD_MAX_NUM_OF_TAGS]; 
      if(m_ppsTagai==NULL) 
         m_lhOpenResult=KpErrorProc.OutputErrorMessage(KP_E_OUTOFMEM, null, TRUE, __FILE__, __LINE__, 0L);
   }
   if(SUCCEEDED(m_lhOpenResult)) for(int ii=0; ii<SCAN_DTD_MAX_NUM_OF_TAGS; ii++) m_ppsTagai[ii] = NULL;

string atributai[SCAN_DTD_MAX_NUM_OF_TAGS][2]; 

int atsk =0 ; 
// int counter =0;

   while ((!ff.eof()) && SUCCEEDED(m_lhOpenResult)) 
   {
      string tmp;
      string drb = "";
      ff >> tmp;

      if(ff.fail() && (!ff.eof()) && SUCCEEDED(m_lhOpenResult)) 
         m_lhOpenResult=KpErrorProc.OutputErrorMessage(KP_E_FERROR, lpszFileName, TRUE, __FILE__, __LINE__, m_iTagsk);

      if(SUCCEEDED(m_lhOpenResult))
      {
//       counter++;
//       cout << "mode " << mode << ":\n word:" << counter << " text:" << tmp << "\n";

         int ilgis = tmp.length();
         switch (mode)
         {
         case 0:
            if (tmp[0] == '>') tmp.erase(0,1);
            if (tmp == "<!ELEMENT") mode = 1;
            else if (tmp == "<!ATTLIST") mode = 2;
            else if (tmp == "<!ENTITY") mode = 3;
            break;
         case 1:
            tgvardas = tmp;
            mode = 11;
            break;
         case 11:
            if (tmp[0] != '|') 
            {
               if (tmp[0] == '(') tmp.erase(0,1);
               if (tmp[ilgis-1] == '>')
               {
                  tmp.erase(0,1);
                  if (tmp == "<!ELEMENT") mode = 1;
                  else if (tmp == "<!ATTLIST") mode = 2;
                  else if (tmp == "<!ENTITY") mode = 3;
                  else mode = 0;
        
                  m_ppsTagai[m_iTagsk] = new string[tgvaikaisk+2];
                  m_ppsTagai[m_iTagsk][0] = tgvardas;

// char buffer[20];
//                m_ppsTagai[m_iTagsk][1] = itoa(tgvaikaisk, buffer, 10);
// char buffer[2];
//                buffer[0]=tgvaikaisk;
//                buffer[1]=Nul;
//                m_ppsTagai[m_iTagsk][1] = buffer;
                  m_ppsTagai[m_iTagsk][1] = (char)tgvaikaisk;

                  for (int ii=0; ii<tgvaikaisk; ii++) m_ppsTagai[m_iTagsk][ii+2] = tgvaikai[ii];
                  if(m_iTagsk < SCAN_DTD_MAX_NUM_OF_TAGS) m_iTagsk++;
                  else
                     m_lhOpenResult=KpErrorProc.OutputErrorMessage(KP_E_BUFFER_OVERFLOW, null, True, __FILE__, __LINE__, 0L);
                  tgvaikaisk = 0;
        
        //uzbaigimas 
        
               } 
               else if(mode == 11) 
               {
                  string drb = karpyk(tmp);
                  if ((drb != "#PCDATA") && (drb != "EMPTY") ) 
                  {
                     bool naujas = true;
                     for (int i = 0; i < tgvaikaisk; i++) naujas = naujas && (tgvaikai[tgvaikaisk]==drb); 
                     if (naujas) tgvaikai[tgvaikaisk++]=drb;
                  }
               }
         
            }
            break;
  
         case 2:
            tgvardas = tmp;
            mode = 21;
            break;
  
         case 21:
            if (tmp[0] != '|') 
            {
               if (tmp[0] == '(') tmp.erase(0,1);
               if (tmp[ilgis-1] == '>')
               { 
                  tmp.erase(0,1);
            
                  if (tmp == "<!ELEMENT") mode = 1;
                  else if (tmp == "<!ATTLIST") mode = 2;
                  else if (tmp == "<!ENTITY") mode = 3;
                  else mode = 0;
            
                  atributai[atsk][0] = tgvardas;
                  atributai[atsk][1] = tgatributai[0];
                  atsk++;
                  tgatributaisk =0;
          //uzbaigimas
               } 
               else 
               {
            
               }
               if (mode == 21) tgatributai[tgatributaisk++] = karpyk(tmp);
            }
            break;
  
         case 3:
            tgvardas = tmp;
            mode = 31;
            break;
      
         case 31: //apdorot pavadinima
            tgvardas = tmp;
            mode = 0;
            break;
         
         } // switch (mode)

      } // if(SUCCEEDED(m_lhOpenResult))
   
   } // while ((!ff.eof()) && SUCCEEDED(m_lhOpenResult)) 



//galutinis, tagu vardai
   if(SUCCEEDED(m_lhOpenResult))
   {
      m_psGalNames = new string[m_iTagsk];
      if(m_psGalNames == NULL) 
         m_lhOpenResult=KpErrorProc.OutputErrorMessage(KP_E_OUTOFMEM, null, TRUE, __FILE__, __LINE__, 0L);
   }

   if(SUCCEEDED(m_lhOpenResult))
      for(int ii=0; ii<m_iTagsk; ii++) m_psGalNames[ii] = m_ppsTagai[ii][0];

//galutinis vaiku numeriu
   if(SUCCEEDED(m_lhOpenResult))
   {
      m_ppiGalVaikai = new KpChar * [m_iTagsk];
      if(m_ppiGalVaikai == NULL) 
         m_lhOpenResult=KpErrorProc.OutputErrorMessage(KP_E_OUTOFMEM, null, TRUE, __FILE__, __LINE__, 0L);
   }
   if(SUCCEEDED(m_lhOpenResult))
      for(int ii = 0; ii<m_iTagsk; ii++) m_ppiGalVaikai[ii] = NULL;

//galutinis vaiku skaicius
   if(SUCCEEDED(m_lhOpenResult))
   {
      m_piGalVaikuSk = new int[m_iTagsk]; 
      if(m_piGalVaikuSk == NULL) 
         m_lhOpenResult=KpErrorProc.OutputErrorMessage(KP_E_OUTOFMEM, null, TRUE, __FILE__, __LINE__, 0L);
   }

int kk = 0;

   if(SUCCEEDED(m_lhOpenResult)) for (int ii=0; ii<m_iTagsk; ii++) 
   {
//    m_piGalVaikuSk[ii] = atoi(m_ppsTagai[ii][1]); 
      m_piGalVaikuSk[ii] = m_ppsTagai[ii][1][0]; 

      m_ppiGalVaikai[ii] = new KpChar[m_piGalVaikuSk[ii]];
      for (int jj=0; jj<m_piGalVaikuSk[ii]; jj++) 
      {
         kk = 0;
         while ((kk<m_iTagsk) && (m_ppsTagai[ii][jj+2] != m_psGalNames[kk])) kk++;
         m_ppiGalVaikai[ii][jj] = (KpChar)(XM_FirstTagCode + kk*2);
      }
   }

   if(SUCCEEDED(m_lhOpenResult)) ff.close();
}


// --------------------------------
XmltDtd_tag::~XmltDtd_tag()
{
int ii;

   if(m_ppsTagai)
   {
      for(ii=0; ii<SCAN_DTD_MAX_NUM_OF_TAGS; ii++){ KP_DELETEA(m_ppsTagai[ii]); }
      KP_DELETEA(m_ppsTagai);
   }
   KP_DELETEA(m_piGalVaikuSk);
   if(m_ppiGalVaikai)
   {
      for(ii=0; ii<m_iTagsk; ii++){ if(m_ppiGalVaikai[ii]){ KP_DELETEA(m_ppiGalVaikai[ii]); }
      KP_DELETEA(m_ppiGalVaikai);
   }
   KP_DELETEA(m_psGalNames);

}

string XmltDtd_tag::GetGalName(KpChar iTag)
 {
   string atsakymas = "";
   int nr = (((int) iTag) - XM_FirstTagCode) / 2;
   if ((nr >=0) && (nr <= m_iTagsk)) 
   {
      atsakymas = m_psGalNames[nr];
   }
   else KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);
   return atsakymas;
 }

int XmltDtd_tag::GetGalVaikuSkVienas(KpChar iTag)
 {
   int atsakymas = 0;
   int nr = (((int) iTag) - XM_FirstTagCode) / 2;
   if ((nr >=0) && (nr <= m_iTagsk)) 
   {
      atsakymas = m_piGalVaikuSk[nr];
   }
   else KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);
   return atsakymas;
 }

string * XmltDtd_tag::GetGalVaikaiVienas(KpChar iTag)
{
   string * atsakymas = NULL;
   int nr = (((int) iTag) - XM_FirstTagCode) / 2;
   if ((nr >=0) && (nr <= m_iTagsk)) 
   {
      atsakymas = new string[m_piGalVaikuSk[nr]]; 
      for (int i = 0; i<m_piGalVaikuSk[nr]; i++) atsakymas[i] = m_ppiGalVaikai[nr][i];
   }
   else 
   {
      KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);
      atsakymas = new string[0];
   }
   return atsakymas;
}

bool XmltDtd_tag::IsEmbedded(KpChar iTag, KpChar iFatherTag)
{
   bool atsakymas = false;
   int tagonr = (((int) iTag) - XM_FirstTagCode) / 2;
   int tevonr = (((int) iFatherTag) - XM_FirstTagCode) / 2;
   if (((tagonr >=0) && (tagonr <= m_iTagsk) && (tevonr >=0) && (tevonr <= m_iTagsk)))
   {
   for (int i = 0; i< m_piGalVaikuSk[tevonr]; i ++) 
      atsakymas = (atsakymas || ((char *)m_ppiGalVaikai[tevonr][i] == m_psGalNames[tagonr]) == 0);
   } 
   else 
   {
      KpErrorProc.OutputErrorMessage(E_INVALIDARG, null, TRUE, __FILE__, __LINE__, 0L);
      atsakymas = new string[0];
   }
   return atsakymas;
}

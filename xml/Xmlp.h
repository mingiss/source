// ==================================================
// xmlp.h
// XML tag parameters
//


#ifndef xmlp_included
#define xmlp_included

typedef enum
{
   XmlParPureInteger,      // "10"
   XmlParIntegerUnits,     // "10px"
   XmlMultiParIntegerUnits,// "0px 0px 0px 0px"
   XmlParFloatUnits,       // "10.5cm", "1px transparent solid"
   XmlMultiParFloatUnits,  // "0cm 0cm 0cm 0cm"

}  XmlParTypes;

// #define MAX_XML_PAR_VAL_LEN KP_MAX_FILE_LIN_LEN
#define MAX_XML_PAR_VAL_LEN 30000

class XmlParRec
{
   HRESULT m_lhOpenResult;
public:
// parameter name
   unsigned char m_lpszParName[TV_TAG_LEN+1];      

private:
   int m_iValCtbl;
   
public:
// parameter value in textual form without enclosing quotes
   unsigned char m_lpszParValue[MAX_XML_PAR_VAL_LEN + 1];
   KpChar m_iazIntParValue[MAX_XML_PAR_VAL_LEN + 1]; 

   HRESULT InitMembers(void);
   XmlParRec(void);
// void Constructor(const unsigned char *lpszParNam, const unsigned char *lpszParVal, const KpChar *iazIntParVal);
   XmlParRec(const unsigned char *lpszParNam, const unsigned char *lpszParVal, const KpChar *iazIntParVal, int iValCtbl = 1);

   HRESULT GetOpenResult(void) const;

   int GetValCtbl(void) const; // gr��ina m_iValCtbl 

   HRESULT UniformValuesFromInt(void); // m_iazIntParValue kopijuoja � m_lpszParValue
   HRESULT UniformValuesFromStr(void); // m_lpszParValue kopijuoja � m_iazIntParValue
};


// ==================================== class for XML tag parameters
// parametrai sujungti � s�ra�� per brolius, ne taip kaip KpTreeEntry simplifikacija � s�ra�� � ten per vaikus
class XmlTagPars : public KpTreeEntry 
{
// unsigned char m_lpszParName[TV_TAG_LEN+1]; // obsolete, moved to (XmlParRec *)KpTreeEntry::m_lpRecord->m_lpszParName 

// unsigned char m_lpszParValue[MAX_XML_PAR_VAL_LEN + 1]; // obsolete, moved to (XmlParRec *)KpTreeEntry::m_lpRecord->m_lpszParValue
// KpChar m_iazIntParValue[MAX_XML_PAR_VAL_LEN + 1]; // obsolete, moved to (XmlParRec *)KpTreeEntry::m_lpRecord->m_iazIntParValue

// XmlTagPars *m_pParValuePar;         // structured value of parameter "style"
                                       // or one style branch of contents of tag <style>
                                       // obsolete, moved to KpTreeEntry::m_pFirstChild

// XmlTagPars *m_pNextParPtr;          // pointer to next parameter, NULL for last parameter
                                       // obsolete, moved to KpTreeEntry::m_pNextBrother

// constructors
// HRESULT InitMembers(void); // obsolete, neliko k� inicializuot - visk� perk�liau � KpTreeEntry:: 
   void Constructor(const unsigned char *lpszParNam, const unsigned char *lpszParVal, const KpChar *iazIntParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1);
public:
   XmlTagPars(const unsigned char *lpszParNam, long lParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1); // converts lParVal to text string
   XmlTagPars(const char *lpszParNam, long lParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1);

   XmlTagPars(const unsigned char *lpszParNam, const unsigned char *lpszParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1) { Constructor(lpszParNam, lpszParVal, NULL, pFath, iValCtbl); };
   XmlTagPars(const unsigned char *lpszParNam, const char *lpszParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1) { Constructor(lpszParNam, (const unsigned char *)lpszParVal, NULL, pFath, iValCtbl); }
   XmlTagPars(const char *lpszParNam, const unsigned char *lpszParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1) { Constructor((const unsigned char *)lpszParNam, lpszParVal, NULL, pFath, iValCtbl); }
   XmlTagPars(const char *lpszParNam, const char *lpszParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1) { Constructor((const unsigned char *)lpszParNam, (const unsigned char *)lpszParVal, NULL, pFath, iValCtbl); }

   XmlTagPars(const unsigned char *lpszParNam, /* const */ KpString sParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1) { Constructor(lpszParNam, sParVal.ExtractUnsignedValueA(), NULL, pFath, iValCtbl); };
   XmlTagPars(const char *lpszParNam, /* const */ KpString sParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1) { Constructor((const unsigned char *)lpszParNam, sParVal.ExtractUnsignedValueA(), NULL, pFath, iValCtbl); };

   XmlTagPars(const unsigned char *lpszParNam, const KpChar *iazIntParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1) { Constructor(lpszParNam, NULL, iazIntParVal, pFath, iValCtbl); }
// XmlTagPars(const char *lpszParNam, const KpChar *iazIntParVal, XmlTagPars *pFath, int iValCtbl = 1) { XmlTagPars((const unsigned char *)lpszParNam, iazIntParVal, pFath, iValCtbl); }

   XmlTagPars(const unsigned char *lpszParNam, XmlTagPars *pParVal, XmlTagPars *pFath = NULL, int iValCtbl = 1); // *pParVal po gr�_imo galima i�mesti  
// XmlTagPars(const char *lpszParNam, XmlTagPars *pParVal, XmlTagPars *pFath, int iValCtbl = 1) { XmlTagPars((const unsigned char *)lpszParNam, pParVal, pFath, iValCtbl); }  

   XmlTagPars(const XmlTagPars *pSrc); // copy constructor

   virtual ~XmlTagPars();

   int GetValCtbl(void) const; // gr��ina ((XmlParRec *)m_lpRecord)->m_iValCtbl 

   HRESULT GetCurTextPar(unsigned char *lpszParNamBuf, unsigned char *lpszValBuf) const;
   HRESULT GetCurKpTextPar(unsigned char *lpszParNamBuf, KpChar *iazValBuf) const; // former GetCurIntTextPar
                                                // returns parameter name and value in textual form
                                                // lpszParNamBuf and lpszValBuf must point to buffers of
                                                //    length not less than TV_TAG_LEN + 1 and MAX_XML_PAR_VAL_LEN + 1

   HRESULT GetCurNumPar(unsigned char *lpszParNamBuf, long *plNumValBuf) const;
                                                // returns parameter name and scans value as long integer number
                                                // lpszParNamBuf must point to buffer of
                                                //    length not less than TV_TAG_LEN+1
   HRESULT GetCurParPar(unsigned char *lpszParNamBuf, XmlTagPars **pValParPtr) const;
                                                // returns parameter name and value of m_pParValuePar
                                                
   HRESULT GetTextPar(unsigned char *lpszParNamBuf, unsigned char *lpszValBuf, int iParNum) const;
   HRESULT GetKpTextPar(unsigned char *lpszParNamBuf, KpChar *iazValBuf, int iParNum) const; // former GetIntTextPar
   HRESULT GetNumPar(unsigned char *lpszParNamBuf, long *plNumValBuf, int iParNum) const;
                                                // gets parameter with order number iParNum
                                                // lpszValBuf/iazValBuf must point to buffers of
                                                //    length not less than MAX_XML_PAR_VAL_LEN + 1

   HRESULT SeekTextPar(const char *lpszParNam, unsigned char *lpszValBuf, int *piParNum) const;
   HRESULT SeekTextPar(const unsigned char *lpszParNam, unsigned char *lpszValBuf, int *piParNum) const;
   HRESULT SeekKpTextPar(const char *lpszParNam, KpChar *iazValBuf, int *piParNum) const; // former SeekIntTextPar
   HRESULT SeekKpTextPar(const unsigned char *lpszParNam, KpChar *iazValBuf, int *piParNum) const; // former SeekIntTextPar
   HRESULT SeekParPar(const char *lpszParNam, XmlTagPars **pValParPtr, int *piParNum) const; // suranda parametro style reik�m� - kit� parametr� s�ra��
                                                // searches for parameter lpszParNam in parameters tree
                                                // returns KP_E_KWD_NOT_FOUND if parameter with such
                                                //    name doesn't exist; error message in that case will
                                                //    not be produced
                                                // lpszValBuf/iazValBuf must point to buffers of
                                                //    length not less than MAX_XML_PAR_VAL_LEN + 1

   HRESULT SeekNumPar(const char *lpszParNam, long *plNumValBuf, int *piParNum) const;
   HRESULT SeekNumPar(const unsigned char *lpszParNam, long *plNumValBuf, int *piParNum) const;
                                                // returns parameter name and scans value as long integer number
                                                // searches for parameter lpszParNam in parameters tree
                                                // returns KP_E_KWD_NOT_FOUND if parameter with such
                                                //    name doesn't exist; error message in that case will
                                                //    not be produced

   HRESULT SeekParPtr(const char *lpszParNam, XmlTagPars **pParPtr);
   HRESULT SeekParPtr(const unsigned char *lpszParNam, XmlTagPars **pParPtr);
                                                // returns pointer to subparameter
                                                // ne reik�m�-parametr� s�ra��, o tiesiog parametr� s�ra�o uodeg�

   HRESULT PointParPtr(int iParNum, XmlTagPars **pParPtr);
                                                // returns pointer to subparameter

   HRESULT GetParCnt(int *piParCnt) const;            // get count of parameters

// HRESULT AddPar(XmlTagPars *pNextPar);  // adds new parameter to the tree
                                          // obsolete, moved to KpTreeEntry::AppendBrother(pNextPar)

   HRESULT AddTextPar(const unsigned char *lpszParNam, const unsigned char *lpszParVal);
   HRESULT AddTextPar(const unsigned char *lpszParNam, const char *lpszParVal) { return(AddTextPar(lpszParNam, (const unsigned char *)lpszParVal)); };
   HRESULT AddTextPar(const char *lpszParNam, const unsigned char *lpszParVal) { return(AddTextPar((const unsigned char *)lpszParNam, lpszParVal)); };
   HRESULT AddTextPar(const char *lpszParNam, const char *lpszParVal) { return(AddTextPar((const unsigned char *)lpszParNam, (const unsigned char *)lpszParVal)); };

   HRESULT AddKpTextPar(const unsigned char *lpszParNam, const KpChar *iazParVal); // former AddIntTextPar
   HRESULT AddKpTextPar(const char *lpszParNam, const KpChar *iazParVal) { return(AddKpTextPar((const unsigned char *)lpszParNam, iazParVal)); };

   HRESULT AddNumPar(const unsigned char *lpszParNam, long lParVal); // converts lParVal to text string
   HRESULT AddNumPar(const char *lpszParNam, long lParVal) { return(AddNumPar((const unsigned char *)lpszParNam, lParVal)); };

   HRESULT AddParPar(const unsigned char *lpszParNam, XmlTagPars *pParVal); // *pParVal po gr�_imo galima i�mesti
   HRESULT AddParPar(const char *lpszParNam, XmlTagPars *pParVal) { return(AddParPar((const unsigned char *)lpszParNam, pParVal)); };

// HRESULT GetNextBranch(const XmlTagPars **pNextParPtr) const; // returns pointer of next parameter, value of m_pNextParPtr
// HRESULT GetNextBranch(XmlTagPars **pNextParPtr) const; // obsolete, moved to KpTreeEntry::GetNextBrother((KpTreeEntry **)pNextParPtr) 

// HRESULT SetChild(XmlTagPars *pNextPar);   // sets next parameter pointer to pNextPar
                                             // obsolete, moved to KpTreeEntry::ConnectBrother(pNextPar)
                                             // or to KpTreeEntry::SetNextBrother(pNextPar)

   HRESULT SetParName(int iParNum, const unsigned char *lpszParName);

   HRESULT SetTextPar(int iParNum, const unsigned char *lpszValue);
   HRESULT SetKpTextPar(int iParNum, const KpChar *iazValue);

   HRESULT UniformValuesFromInt(void); // i�kvie�ia (XmlParRec *)KpTreeEntry::m_lpRecord->UniformValuesFromInt()
   HRESULT UniformValuesFromStr(void); // i�kvie�ia (XmlParRec *)KpTreeEntry::m_lpRecord->UniformValuesFromStr()
   
   HRESULT UniformValuesFromPars(bool bBreakLines);   // m_pParValuePar kopijuoja � m_lpszParValue ir m_iazIntParValue
                                                      // bBreakLines == True - "\n" after ";"

   HRESULT TestValueConsistence(void) const;

   HRESULT ScaleStylePars(int iFactor); 
// perskai�iuoja visus font-size=...; margin-top=...; ir t.t.
// iFactor - koeficientas, padaugintas i� 1000 
};


//------------------------------------------------------------------------------ free functions
// use XmlTagPars(const XmlTagPars *pSrc) instead
// HRESULT CopyTagPars(const XmlTagPars *pTagParsPtr, XmlTagPars **ppNewPars);
               // allocates new memory and copies tag parameters
               // after copying *pTagParsPtr can be deleted

HRESULT DeletePar(XmlTagPars **pTagParsPtr, int iParNum);
// i�trina iParNum parametr�. Jei iParNum == 0, pakei�ia *pTagParsPtr reik�m�, jei nieko neliko - � NULL 
   
HRESULT ParseStyleParameters(XmlTagPars **pTagParsPtr, const unsigned char *lpszStyleStr, XmlTagPars *pFath);
// skanuoja HTML tago parametro style reik�m� ir suki�a � *pTagParsPtr (lpszStyleStr - tago parametro reik�m�, tai, kas tarp kabu�i�)
// style="left:0px;position:absolute;left:-5px;top:-3px;width:1388px;height:830px"
// *pTagParsPtr prie� kreipiantis turi b�ti i�valytas
// naudojamas ir tago <style> turinio vieno segmento reik�m�s skanavimui - rakt� reik�m�ms tarp "{" ir "}":
// img#background { height: 600; width: 800; z-index: -1; position:absolute; color: white; }  

HRESULT ScaleParVal(const unsigned char *lpszParName, unsigned char *lpszParVal, int iFactor, XmlParTypes iParType, int iNumOfVals);
// lpszParVal - parametras perskai�iavimui
// buferis nema�esnis negu lpszParVal[MAX_XML_PAR_VAL_LEN + 1] 
// perskai�iuota reik�m� gr�_inama atgal � lpszParVal 
// iFactor - koeficientas, padaugintas i� 1000 
// iNumOfVals - reik�mi� skai�ius, jei iParType == XmlMultiParFloatUnits
//    iNumOfVals == -1 � reik�mi� skai�ius bet koks
// lpszParName tik �iaip sau, informacijai 

#endif

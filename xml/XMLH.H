// ==================================================
// xmlh.h
// XML tag stack definitions


#ifndef tvxmlh_included
#define tvxmlh_included


// =================================================== class TvXmlTagStack
// --------------------------------------------------
// record for tag group stack processing
class TvXmlTagStack
{
   TvXmlTagStack *pPrevTagPtr;
   /* enum XmlDictChars */ KpChar iCurrentTag;
   bool bFreeTextAvail; // flag of free text in current tag
   bool bPutClose;      // =FALSE, if no closing tag output needed
   bool bOpen;          // =TRUE, if no closing char of previous tag output
   TvXmlTagStack *pParalelTagPtr; // pointers from group stack to expanded stack entries
   int iIndent;         // indent, corresponding to each group stack entry
   bool bOutFl;         // tag output flag; False for hided tags

public:
   TvXmlTagStack
   (
      TvXmlTagStack *pPrevTag,
      /* enum XmlDictChars */ KpChar iCurTag,
      TvXmlTagStack *pParalTag,
      int iIndnt
   );
   ~TvXmlTagStack(void);

   HRESULT GetPrevTagPtr(TvXmlTagStack **ppTagPtr);
   HRESULT SetPrevTagPtr(TvXmlTagStack *pTagPtr);
   HRESULT GetCurTag(/* enum XmlDictChars */ KpChar *piCurTag); // gràþina iCurrentTag
   HRESULT SetCurTag(/* enum XmlDictChars */ KpChar iCurTag);  // nustato iCurrentTag
   HRESULT GetPrevTag(/* enum XmlDictChars */ KpChar *piCurTag); // gràþina pPrevTagPtr->iCurrentTag
   HRESULT GetFreeTextAvail(bool *pbFrTxAv);
   HRESULT SetFreeTextAvail(bool bFrTxAv);
   HRESULT GetPutClose(bool *pbPutCloseNeeded);
   HRESULT SetPutClose(bool bPutCloseNeeded);
   HRESULT GetOpen(bool *pbOpenFl);
   HRESULT SetOpen(bool bOpenFl);
   HRESULT GetParalPtr(TvXmlTagStack **ppParPtr);
   HRESULT GetIndent(int *piIndnt);
   HRESULT GetOutFl(bool *pbOutFlag);
   HRESULT SetOutFl(bool bOutFlag);
};


extern HRESULT PushTag             // creates new tag stack element
(
   TvXmlTagStack **ppStackTop,
   KpChar iCurTag,
   TvXmlTagStack *pParalTag,
   int iIndnt
);

extern HRESULT PopTag(TvXmlTagStack **ppStackTop, KpChar *piCurTag);
                                 // deletes top element of stack *ppStackTop
                                 //    returns tag character of that element

extern HRESULT TestTagStack(/* const */ TvXmlTagStack *pStackTop, KpChar iChTag, bool *pbTagPres);
                                 // searches for tag iChTag in stack *pStackTop
                                 // returns *pbTagPres, if found

extern HRESULT GetGroupCount(TvXmlTagStack *pStackTop, int *piGrCnt, const KpChar *iazXmlGrTagsPtr);
extern HRESULT GetGroupCountSpec(TvXmlTagStack *pStackTop, KpChar iGrTag, int *pGrCnt, const KpChar *iazXmlGrTagsPtr);
                                 // return level of group tag inclusion

extern HRESULT RemoveTagFromStack(TvXmlTagStack **ppStackTop, KpChar iChTag);
                                 // removes iGrTag from any depth of the stack record

extern HRESULT GetStackTag(TvXmlTagStack *pStackTop, int iLev, KpChar *piTag);
                                 // gets tag of depth iLev of the stack pStackTop


#endif

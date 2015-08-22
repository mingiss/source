// ==================================================
// kptree.h
// definitions of KpTreeEntry
//


// ===============================================
#ifndef kptree_included
#define kptree_included


// ===============================================
#define XL_ND_MaxNumOfNodes 3000 // 30000 // max number of nodes in node tree
#define KP_MAX_TREE_DEPTH 50 // max level of descendants


typedef struct
{
   unsigned char m_lpszText[KP_MAX_FILE_LIN_WDT + 1];
   HBITMAP m_hBmp;
} KpTextBmp;

typedef struct
{
   HBITMAP m_hBmp;
   HBITMAP m_hTextBmp;
} KpBmpBmp;

class KpTextChk
{
public:
   unsigned char m_lpszText[KP_MAX_FILE_LIN_WDT + 1];
   KpChar m_iazText[KP_MAX_FILE_LIN_WDT + 1];
   bool m_bChecked;

   KpTextChk(void);
};

typedef enum
{
   KpRecType_Unknown,   // void * record
   KpRecType_Text,      // unsigned char * - lpsz character array, any length
   KpRecType_TextBmp,   // KpTextBmp structure, m_lpRecord = sizeof(KpTextBmp)
   KpRecType_BmpBmp,    // KpTextBmp structure, m_lpRecord = sizeof(KpTextBmp)
   KpRecType_TextChk,   // KpTextBmp structure, m_lpRecord = sizeof(KpTextBmp)
   KpRecType_KpText,    // KpChar * - iaz wide character array, any length

} KpRecType; // former KpRecTypes


// node display types for KP_LISTBOX
#if FALSE
// values of KpTreeEntry::m_iStatus
typedef enum
{
   KpHighLevelNode, // = 0 // start of high level node states (whole not detailed entry)

   KpHighChildlessNode, // former KpEmptyNode // empty node - other status values not applicable

   KpHighExpandedNode,  // former KpVisibleNode // expanded node - children visible, node marked as [-] in KP_LISTBOX
   KpHighCollapsedNode, // former KpInvisibleNode // collapsed node - children invisible, node marked as [+] in KP_LISTBOX

   KpLowLevelNode = 16, // bit flag for low level nodes (local detailed node)

   KpLowChildlessNode,  // KpHighChildlessNode | KpLowLevelNode // former KpHiddenNode // unexpanding node - children could never be visible, node displayed like KpChildlessNode

   KpLowExpandedNode,   // KpHighExpandedNode | KpLowLevelNode
   KpLowCollapsedNode,  // KpHighCollapsedNode | KpLowLevelNode

} KpNodeStatus;
#else
// flags for KpTreeEntry::m_iStatus
#define KpNodeVisible      1  // if 0 - node does not belong to current level tree
#define KpNodeHasChildren  2  // not empty node - KpNodeExpanded is applicable
#define KpNodeExpanded     4  // expanded node - children visible, node marked as [-] in KP_LISTBOX; applicable only if KpNodeHasChildren
                              // if KpNodeHasChildren and not KpNodeExpanded - collapsed node - children invisible, node marked as [+] in KP_LISTBOX
#define KpNodeLevelShift   8  // 8 bits for each level flags
#define KpNodeLevelFactor  256

#define KpNodeNumOfLevels  2
#endif


// ================================================== tree of objects, class for tree node
class KpTreeEntry // former KpTreeEntry_tag // former typedef to RecListEntry // former RecListEntry_tag // former StrListEntry_tag
{
// The object itself, any class.
// First member - usually lpsz character string -
//    simply text representation of contents - for sorting and listing purposes
//    (KpCreateListBox()
// former m_lpszString
public:
   unsigned char /* void */ *m_lpRecord;

   int m_iRecSize; // size of m_lpRecord in bytes

// int iNumOfNodes;
// XmlNode_tag **iaNodesArray;

public:
   HRESULT m_lhOpenResult;

   KpRecType m_iRecType;

   KpTreeEntry *m_pFirstChild; // former m_pNextEntry
   KpTreeEntry *m_pPrevBrother;
   KpTreeEntry *m_pNextBrother;
   KpTreeEntry *m_pFather;

   int /* KpNodeStatus */ m_iStatus; // former bool m_bHidden;
      // flag of node with hidden children (for output to KP_LISTBOX)
      // levels in XmlNode_tag:  1 - group tags (nodes)
      //                         0 - simply tags

// constructors
   KpTreeEntry(void);

   KpTreeEntry(KpTreeEntry *pFath);

   KpTreeEntry(const void *lpRecord, int iSize, KpTreeEntry *pFath, KpRecType iRecType = KpRecType_Unknown); // create new record entry, iSize - size in bytes of the record
   KpTreeEntry(const unsigned char *lpszString, KpTreeEntry *pFath); // lpszString - text string to initialize
   KpTreeEntry(const char *lpszString, KpTreeEntry *pFath); // lpszString - text string to initialize
   KpTreeEntry(const KpChar *iazKpStr, KpTreeEntry *pFath); // iazKpStr - wide text string to initialize
   HRESULT Constructor(const void *lpRecord, int iSize, KpTreeEntry *pFath, KpRecType iRecType = KpRecType_Unknown); // *lpRecord po gráþimo galima sunaikinti

   virtual ~KpTreeEntry();

   HRESULT GetOpenResult(void) const;


// ------------------------------
// simply linear list methods

   HRESULT SetFirstChild(KpTreeEntry *pChild); // former SetNextEntry(KpTreeEntry *pNextEntry);
                                             // sets value of pointer to next entry (child) m_pFirstChild
                                             // sets next chain member in case of linear list
                                             // pChild cannot be deleted after successfull SetFirstChild()
                                             // pChild->m_pFather turi sutapti su this
                                             // pChild->m_pPrevBrother turi buti NULL
// HRESULT GetFirstChild(KpTreeEntry **ppChild) const;
                                             // former KpTreeEntry *KpTreeEntry::GetNextEntry(void)
                                             // gets value of m_pFirstChild
                                             // gets pointer to next entry of the linear list
                                             // NULL - last entry
// Watcom meta mistines linkerio klaidas - KpTreeEntry::GetTopWindow(KpTreeEntry **) undefined entry, jeigu
//                retc0 = cur_node->GetFirstChild((KpTreeEntry **)&cur_node);
// HRESULT GetTopWindow(KpTreeEntry **ppChild) const { return(GetFirstChild(ppChild)); }
// naudoti
//                      cur_node = (XmlNode *)cur_node->m_pFirstChild;

   HRESULT PutToEnd(const void *lpRecord, int iSize, KpRecType iRecType = KpRecType_Unknown);
      // puts new entry after last entry (deepest child) of the list
   HRESULT PutToEnd(const unsigned char *lpszString);
      // lpszString - text string as new entry (after the deepest child)
   HRESULT PutToEnd(const char *lpszString);
      // lpszString - text string as new entry (after the deepest child)
   HRESULT PutToEnd(const KpChar *iazKpStr);
      // iazKpStr - text wide string as new entry (after the deepest child)

   HRESULT DeleteChild(void);
      // ismeta viena vaika, anukus pastumia i vaiko vieta

   KpRecType GetRecType(void) const; // get record type identifier m_iRecType

   void *GetValue(void) const; // get record buffer pointer m_lpRecord
   int GetValSize(void) const; // get count of bytes of record value

   HRESULT SetValue(const void *pValue, int iValSize);
      // sets new contents of record buffer m_lpRecord
      // error if iValSize is greater than original
      // does not change original m_iRecSize

   HRESULT SetNewValue(const void *pValue, int iValSize);
   HRESULT SetNewValue(const unsigned char *lpszValue);

   HRESULT SetNewValue(const KpTextBmp *pValue);
   HRESULT SetNewValue(const KpBmpBmp *pValue);
      // deletes former allocation of m_lpRecord
      // allocates new buffer for m_lpRecord
      // sets new contents of record buffer m_lpRecord

   virtual HRESULT InitNodeStatus(void); // initialize value of m_iStatus

   HRESULT CountEntries(int *piCnt, int iLevel /* KpWndType iWndType */ = 0, KpTreeEntry *pCurGrandFather = NULL) /* const */;
   // counts number of list entries
   // *piCnt ieinant turi buti inicializuotas i 0 - funkcija rekursine, tik inkrementuoja
   // iLevel: 0 - low level KP_LISTBOX, 1 - high
   // (former iWndType == TYP_ListBoxTree or TYP_ListBoxTreeInverted - depending on high or low level list is processed)
   // pCurGrandFather - top level node - for tree branches, NULL - whole tree
   // (former int CountEntries(void);)
   // (former extern int CountRecListEntries(RecListEntry *pRecList);)
   // check <this> for existence before calling

   HRESULT GetEntryPtr(int *piSel, KpTreeEntry **ppEntryPtr, int iLevel /* KpWndType iWndType */, const KpTreeEntry *pCurGrandFather);
   // former extern HRESULT ::GetRecListEntryPtr(RecListEntry *pStartEntry, RecListEntry **ppEntryPtr, int iSel);
   // *piSel - iraso numeris nuo saknies (pirma vaikai, po to broliai - kaip katalogu medzio ListBox'o vaizde
   // *piSel gadinamas - naudojamas kaip darbinis kintamasis
   // *ppEntryPtr==NULL - iSel exceeded real count of entries in pStartEntry
   // iLevel: 0 - low level KP_LISTBOX, 1 - high
   // (former iWndType == TYP_ListBoxTree or TYP_ListBoxTreeInverted - depending on high or low level list is processed)
   // pCurGrandFather - top level node - for tree branches, NULL - whole tree
   // check <this> for existence before calling

   HRESULT SearchTreeEntry( // former SearchEntry()
      const void *pPattern,
      CompareFuncPtr pfCompare, // int (*pfCompare)(const void *, const void *),
      KpTreeEntry **ppEntryPtr,
      KpTreeEntry **ppFatherPtr // TODO: mest lauk !!!
      );
   // searches for list node corresponding to pPattern
   // NULL - node not found
   // pfCompare() - like strcmp(), TvStrCmpStrict_()
   // ppFatherPtr gali buti NULL, naudojamas, kai reikia ismetineti irasus
   // *ppFatherPtr==NULL - tevo nera (pats pirmas irasas atitiko pPattern)
   // check <this> for existence before calling

   HRESULT Sort(CompareFuncPtr pfCompare /* int (*pfCompare)(const void *lpszStr1, const void *lpszStr2) */);
   // former extern HRESULT SortRecList(RecListEntry *pList, int (*pfCompare)(const void *, const void *));
   // sorts values of linked list
   // pfCompare() - like strcmp(), TvStrCmpStrict_()
   // list elements must be of equal size
   // <this> must be checked for existence before calling
   HRESULT SortPtr(ComparePtrFuncPtr pfCompare /* int (*pfCompare)(const void *plpszStr1, const void *plpszStr2) */);



// ------------------------------
// tree management methods

   HRESULT GetFather(KpTreeEntry **ppFath) const;

   HRESULT SetFather0(KpTreeEntry *pFath);         // recursive entry
   HRESULT SetFather(KpTreeEntry *pFath);          // main entry
                                                   // pFath cannnot be deleted after successfull SetFather()
                                                   // nustato teva ir visiems tolimesniems broliams
                                                   // pPrevBrother turi buti NULL


// HRESULT GetFirstChild(KpTreeEntry **ppChild);   // described among linear list methods
// HRESULT SetFirstChild(KpTreeEntry *pChild);     // described among linear list methods

   HRESULT ConnectChild(KpTreeEntry *pChild);      // pChild cannot be deleted after successfull ConnectChild()
                                                   // nustato pChild->pFather i this, pChild->pPrevBrother i NULL

   HRESULT GetPrevBrother(KpTreeEntry **ppPrevBr) const;
   HRESULT SetPrevBrother(KpTreeEntry *pPrevBr);   // pPrevBr cannnot be deleted after successfull SetPrevBrother()
                                                   // pPrevBr->pFather turi sutapti su this->pFather

   HRESULT GetNextBrother(KpTreeEntry **ppNextBr) const;
   HRESULT SetNextBrother(KpTreeEntry *pNextBr);   // nustato sekantá brolá ðiam mazgui (this)
                                                   // pNextBr cannnot be deleted after successfull SetNextBrother()
                                                   // pNextBr->pFather turi sutapti su this->pFather


   HRESULT ConnectBrother(KpTreeEntry *pNextBr);   // nustato sekantá brolá ðiam mazgui (this)
                                                   // pNextBr cannnot be deleted after successfull ConnectBrother()
                                                   // nustato pNextBr->m_pFather=this->m_pFather

   HRESULT InsertChild(KpTreeEntry *pChild);       // inserts new child BEFORE first child
                                                   //    pChild cannot be deleted after successfull InsertChild()
                                                   // nustato pChild->pFather i this
   HRESULT AppendChild(KpTreeEntry *pChild);       // appends new child AFTER the last child of this
                                                   //    pChild cannot be deleted after successfull AppendChild()
                                                   // nustato pChild->pFather i this
   HRESULT AppendBrother(KpTreeEntry *pBrother);   // appends new brother AFTER the last brother of this
                                                   //    pBrother cannot be deleted after successfull AppendBrother()
                                                   // nustato pBrother->pFather i this->pFather

// ---------------------------------
private:
   HRESULT TestNodeLoop(KpTreeEntry **iaNodesArray, int *piNumOfNodes);   // former TestNodeLoop(void);
public:                                                                       // internal function used in TestNode
   HRESULT TestNode(void);

// ---------------------------------
   HRESULT FormListBox(HWND hListBox); // SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)m_lpRecord); recursively through all children and brothers

// ---------------------------------
// KpTextChk metodai
   HRESULT Deselect(); // visus m_lpRecord->m_bChecked numeta á False

};

extern HRESULT DeleteKpTreeEntry(KpTreeEntry *pEntryPtr); // iðtrina *pEntryPtr su visais vaikais, pastumdydamas brolius

extern HRESULT ChangeKpTreeNodes(KpTreeEntry *pNode1, KpTreeEntry *pNode2); // former ChangeRecListNodes()
   // changes VALUES (*m_lpRecord) of two tree entries, relationship is not changed
   // pNode1->m_lpRecord and pNode2->m_lpRecord should be allready allocated with sufficient size

extern HRESULT CopyKpTreeNode(KpTreeEntry *pNodeDst, /* const */ KpTreeEntry *pNodeSrc); // former CopyRecListNode()
   // copies VALUES (*m_lpRecord) of the tree node, relationship is not changed
   // pNodeDst->m_lpRecord should be allready allocated with sufficient size

extern HRESULT CopyKpTreeNodeAllocate(KpTreeEntry *pNodeDst, /* const */ KpTreeEntry *pNodeSrc);
   // like CopyKpTreeNode(), but allocates new space for pNodeDst->m_lpRecord

// ------------------- suskaièiuoja teksto eiluèiø sàraðo bendrà ilgá
extern HRESULT CountStrListFullLength(int *piFullContLen, /* const */ KpTreeEntry *pCharList); // *pList – char[] stringø sàraðas
extern HRESULT CountKpCharListFullLength(int *piFullContLen, /* const */ KpTreeEntry *pKpCharList); // *pList – KpChar[] stringø sàraðas

// ====================================
// working fields of XmlNode_tag::TestNodeLoop()
// extern int iNumOfNodes;
// extern KpTreeEntry **apNodesArray; // former iaNodesArray

// extern HRESULT InitNodesArray(void); // must be called from main()

#endif // #ifndef kptree_included


// ==================================================
// xmlt.h
// XML definitions for dictionaries


// ---------------------------------------------------
// 2006.09.12 mp  Pridejau const prie caIxLangs[], caIxLangsIn[], caIxLangsOut[] 
// 2006.09.21 mp  Pridejau XC_Page, XC_SemNr, XC_TrWordLit, XC_TrWordEng, etc.




#ifndef xmlt_included
#define xmlt_included


// =================================================== definitions
#define TV_XM_DtdName ((const unsigned char *)"tvxmlt.dtd")
#define TV_XM_CssName ((const unsigned char *)"tvxmlt.css")

#define TV_XL_HW_IX_LEN TV_XL_MAX_IX_LEN  // width of headword and translated word indexes
#define TV_XL_LA_IX_LEN 20                // width of index of labels
#define TV_XL_TX_IX_LEN 30                // width of index of full text (max word length)
                              
// main codetables                              
#define TV_MAIN_HTML_CTBL    71
#define TV_MAIN_SGM_CTBL     80 // 71
#define TV_MAIN_SGME_CTBL    43
#define TV_COMMON_DELIM_CTBL 71
#define TV_IX_CTBL   71          // internal code table of full text indexes           

// --------------------------------------------------
extern const unsigned char lpszDictName[];
extern int iNumOfTexTagsLocal; // former VL_TG_NumOfTags0, LV_TG_NumOfTags0

// -------------------------------------------------- index files
// #define XL_TX_GRAM // full-text indekso XL_IX_TxIndex irasai konvertuojami i pagrindine gram. forma pagal lauko kalba

// -------------------------------------------------- index files
typedef enum
{
   XL_IX_NoIndex=(-1),
   
   XL_IX_DataFile,      // 0 // XML data file
   
   XL_IX_SeIndex,       // 1 // standard entry index file
   
   XL_IX_HwIndex,       // 2 // headword index file, without diacrytic marks and endings
   XL_IX_TwIndex,       // 3 // translated headword index file
   XL_IX_LaIndex,       // 4 // label index file
   XL_IX_StIndex,       // 5 // standard entry text index file
   XL_IX_EdIndex,       // 6 // editorial notes index file (record creation date etc.)

   XL_IX_TxIndex,       // 7 // full text index file, without diacritic marks
   XL_IX_HxIndex,       // 8 // headword index file, exact spelling with diacrytics and endings

   XL_IX_NumOfIndexes0

} XL_Indexes;           // indexes to arrays of XML data/index files

#define XL_IX_NumOfIndexes3 XL_IX_NumOfIndexes0

extern const unsigned char *alpszIndexNames[XL_IX_NumOfIndexes0+1];
extern const unsigned char *alpszDefIndexNames[XL_IX_NumOfIndexes0+1]; // default index names array for no index processing
extern const int aiIndexWidths[XL_IX_NumOfIndexes0];     // widths of binary index entry
extern const int auiIndexTags[2*XL_IX_NumOfIndexes0];    // start/and tags of index entries in xml file                 

extern const unsigned char caIxLangs[XL_IX_NumOfIndexes0];     // language codes of indexes, former caMcmIxLangs, caLvzIxLangs
// galetu buti generuojamas is caTgLangs[], lpszaXmlTagIxNames[] ir alpszIndexNames[],
// bet gali reiketi caIxLangs[] be kalbu - tiksliam antrastiniu zodziu indeksui, pvz. lzdsh.exe

extern const unsigned char caIxLangsIn[XL_IX_NumOfIndexes0];   // for inverters
extern const unsigned char caIxLangsOut[XL_IX_NumOfIndexes0];  // 
extern const EC_Types iaIxEncodings[XL_IX_NumOfIndexes0];

// --------------------------------------------------- Dictionary XML tags
#define XC_TG_NumOfDictTags00    (XC_LastDictTag-XC_FirstDictTag)
#define XC_TG_NumOfDictTagsArr68 XC_TG_NumOfDictTags00 // ismesti sisteminiai tagai

enum XmlDictChars                         // Dictionary XML tag characters
{
  XC_FirstDictTag       = XM_FirstDictTagCode, // =5000,

  XC_Dict               = XM_FirstDictTagCode, // =5000,
  XC_Dict_e,         /*  5001 */

  XC_NrtEntry,       /*  5002 */
  XC_NrtEntry_e,     /*  5003 */
  XC_StEntry,        /*  5004 */
  XC_StEntry_e,      /*  5005 */

  XC_HeadWord,       /*  5006 */
  XC_HeadWord_e,     /*  5007 */
  XC_Label,          /*  5008 */
  XC_Label_e,        /*  5009 */
  XC_TrWord,         /*  5010 */
  XC_TrWord_e,       /*  5011 */
  XC_UsNoteDst,      /*  5012 */    // former XC_UsNote
  XC_UsNoteDst_e,    /*  5013 */
  XC_Reference,      /*  5014 */
  XC_Reference_e,    /*  5015 */
  XC_StEntryText,    /*  5016 */
  XC_StEntryText_e,  /*  5017 */
  XC_Paragraph,      /*  5018 */
  XC_Paragraph_e,    /*  5019 */

      XC_Version_obs,        /*  5020 */  // obsolete, moved to XL_Version
      XC_Version_obs_e,      /*  5021 */
      XC_DocType_obs,        /*  5022 */  // obsolete, moved to XL_DocType
      XC_DocType_obs_e,      /*  5023 */

  XC_Variant,        /*  5024 */
  XC_Variant_e,      /*  5025 */
  XC_PartOfSpeechSrc,    /*  5026 */ // former XC_GramForm ???
  XC_PartOfSpeechSrc_e,  /*  5027 */

  XC_HeadWordGroup,  /*  5028 */
  XC_HeadWordGroup_e, /* 5029 */
  XC_TranslGroup,    /*  5030 */
  XC_TranslGroup_e,  /*  5031 */

  XC_FormDst,        /*  5032 */
  XC_FormDst_e,      /*  5033 */
  XC_FormSrc,        /*  5034 */ // former XC_BoldForm, XC_SemiBoldForm ???
  XC_FormSrc_e,      /*  5035 */

  XC_ExplSrc,        /*  5036 */
  XC_ExplSrc_e,      /*  5037 */

  XC_Example,        /*  5038 */
  XC_Example_e,      /*  5039 */
  XC_ExampleGroup,   /*  5040 */
  XC_ExampleGroup_e, /*  5041 */

  XC_Parenth,        /*  5042 */
  XC_Parenth_e,      /*  5043 */

  XC_Idiom,          /*  5044 */
  XC_Idiom_e,        /*  5045 */

  XC_IdiomGroup,     /*  5046 */
  XC_IdiomGroup_e,   /*  5047 */

  XC_CtgGroup,       /*  5048 */
  XC_CtgGroup_e,     /*  5049 */

  XC_Base,           /*  5050 */ 
  XC_Base_e,         /*  5051 */
  XC_CompoundGroup,        /*  5052 */
  XC_CompoundGroup_e,      /*  5053 */
  XC_CompoundWord,         /*  5054 */  // former XC_CompoundHeadWord
  XC_CompoundWord_e,       /*  5055 */

  XC_MngGroup,       /*  5056 */
  XC_MngGroup_e,     /*  5057 */

  XC_Asterix,        /*  5058 */
  XC_Asterix_e,      /*  5059 */

  XC_CtrlSrc,        /*  5060 */ // former XC_Control ???
  XC_CtrlSrc_e,      /*  5061 */

  XC_PrGroup,        /*  5062 */
  XC_PrGroup_e,      /*  5063 */
  XC_Pron,           /*  5064 */
  XC_Pron_e,         /*  5065 */

  XC_Abbr,           /*  5066 */
  XC_Abbr_e,         /*  5067 */

  XC_Hom,            /*  5068 */
  XC_Hom_e,          /*  5069 */

  XC_ContextSrc,     /*  5070 */ // former XC_Context ???
  XC_ContextSrc_e,   /*  5071 */

  XC_CtrlGroup,      /*  5072 */ // former XC_ControlGroup
  XC_CtrlGroup_e,    /*  5073 */

  XC_PartOfSpeechDst,    /*  5074 */ // former XC_GramExpl ???
  XC_PartOfSpeechDst_e,  /*  5075 */

  XC_FormGroupSrc,   /*  5076 */ // former XC_FormGroup
  XC_FormGroupSrc_e, /*  5077 */

      XC_StyleSheet_obs,     /*  5078 */   // obsolete, moved to XL_StyleSheet
      XC_StyleSheet_obs_e,   /*  5079 */

  XC_VarNorm,        /*  5080 variantas normaliu sriftu, neitraukiamas i hw indeksus */
  XC_VarNorm_e,      /*  5081 */

  XC_AbbrNorm,       /*  5082 */
  XC_AbbrNorm_e,     /*  5083 */

  XC_MngNearGroup,   /*  5084 */
  XC_MngNearGroup_e, /*  5085 */

// ----------------------------------- enter the rest to tvxmlt.dtd
  XC_PronRed,        /*  5086 */
  XC_PronRed_e,      /*  5087 */

  XC_Nul,            /*  5088 */ // !!! kelt į XmlSysTagChars
  XC_Nul_e,          /*  5089 */

// ----------------------------------- enter the rest to XmlttTestPars()
  XC_Similar,        /*  5090 */  // dar trumpai buvo XC_Eq
  XC_Similar_e,      /*  5091 */

  XC_Approx,         /*  5092 */
  XC_Approx_e,       /*  5093 */

  XC_Text_obs,       /*  5094 */  // internal tag for keeping of free text // iškeltas į plpszaXmlSysTags[] XL_Text
  XC_Text_obs_e,     /*  5095 */

  XC_Info,           /*  5096 */
  XC_Info_e,         /*  5097 */

  XC_Expand,         /*  5098 */
  XC_Expand_e,       /*  5099 */

  XC_StructGroup,    /*  5100 */
  XC_StructGroup_e,  /*  5101 */

  XC_Gloss,          /*  5102 */
  XC_Gloss_e,        /*  5103 */

  XC_FwNote,         /*  5104 */
  XC_FwNote_e,       /*  5105 */

  XC_Italic,         /*  5106 */
  XC_Italic_e,       /*  5107 */

  XC_ModCpdSrc,      /*  5108 */
  XC_ModCpdSrc_e,    /*  5109 */

  XC_Symb,           /*  5110 */
  XC_Symb_e,         /*  5111 */

// ----------------------------------- enter the rest to tvxmlt.xls
  XC_Inform,         /*  5112 */
  XC_Inform_e,       /*  5113 */
  XC_Uncount,        /*  5114 */
  XC_Uncount_e,      /*  5115 */

  XC_PhrGroup,       /*  5116 */
  XC_PhrGroup_e,     /*  5117 */

  XC_CpdMngGroup,    /*  5118 */
  XC_CpdMngGroup_e,  /*  5119 */

  XC_Obs,            /*  5120 */
  XC_Obs_e,          /*  5121 */
  XC_Arch,           /*  5122 */
  XC_Arch_e,         /*  5123 */
  XC_VeryInform,     /*  5124 */
  XC_VeryInform_e,   /*  5125 */
  XC_Vulgar,         /*  5126 */
  XC_Vulgar_e,       /*  5127 */

  XC_Super,          /*  5128 */
  XC_Super_e,        /*  5129 */

  XC_Count,          /*  5130 */
  XC_Count_e,        /*  5131 */

  XC_HiLight,        /*  5132 */
  XC_HiLight_e,      /*  5133 */
  XC_SemiBold,       /*  5134 */
  XC_SemiBold_e,     /*  5135 */

  XC_CtrlDst,        /*  5136 */
  XC_CtrlDst_e,      /*  5137 */

  XC_ExplNorm,       /*  5138 */ // language usually KP_LNG_LIT
  XC_ExplNorm_e,     /*  5139 */

  XC_Struct,         /*  5140 */
  XC_Struct_e,       /*  5141 */
  XC_OblStruct,      /*  5142 */
  XC_OblStruct_e,    /*  5143 */

  XC_Usage,          /*  5144 */
  XC_Usage_e,        /*  5145 */

  XC_HBase,          /*  5146 */
  XC_HBase_e,        /*  5147 */

  XC_ModCpdGroup,    /*  5148 */
  XC_ModCpdGroup_e,  /*  5149 */

  XC_ExampleTransl,  /*  5150 */
  XC_ExampleTransl_e,/*  5151 */

  XC_IdiomTransl,    /*  5152 */
  XC_IdiomTransl_e,  /*  5153 */

  XC_TechNote,       /*  5154 */
  XC_TechNote_e,     /*  5155 */

  XC_IdMngGroup,     /*  5156 */
  XC_IdMngGroup_e,   /*  5157 */

  XC_RefInf,         /*  5158 */
  XC_RefInf_e,       /*  5159 */

  XC_SrcWord,        /*  5160 */
  XC_SrcWord_e,      /*  5161 */

  XC_ModCpdDst,      /*  5162 */
  XC_ModCpdDst_e,    /*  5163 */

  XC_ContextDst,     /*  5164 */
  XC_ContextDst_e,   /*  5165 */

  XC_ExplDst,        /*  5166 */ // former XC_Explanation ???
  XC_ExplDst_e,      /*  5167 */

  XC_RefWord,        /*  5168 */
  XC_RefWord_e,      /*  5169 */

  XC_RefNum,         /*  5170 */ // nuoroda i skaiciu, tame tarpe i XC_
  XC_RefNum_e,       /*  5171 */

  XC_RefXWord,       /*  5172 */
  XC_RefXWord_e,     /*  5173 */

  XC_RefTab,         /*  5174 */
  XC_RefTab_e,       /*  5175 */

  XC_RefPage,        /*  5176 */
  XC_RefPage_e,      /*  5177 */

  XC_RefHom,         /*  5178 */
  XC_RefHom_e,       /*  5179 */

  XC_SingleCpdWord,  /*  5180 */
  XC_SingleCpdWord_e,/*  5181 */

  XC_FormGroupDst,   /*  5182 */
  XC_FormGroupDst_e, /*  5183 */

  XC_DerivGroup,     /*  5184 */
  XC_DerivGroup_e,   /*  5185 */

  XC_Derivative,     /*  5186 */
  XC_Derivative_e,   /*  5187 */

  XC_StressParGroup, /*  5188 */
  XC_StressParGroup_e,/*  5189 */

  XC_StressPar,      /*  5190 */
  XC_StressPar_e,    /*  5191 */

  XC_PunctMark,      /*  5192 */
  XC_PunctMark_e,    /*  5193 */

  XC_LevelGroup,     /*  5194 */
  XC_LevelGroup_e,   /*  5195 */

  XC_Level,          /*  5196 */
  XC_Level_e,        /*  5197 */

  XC_UsNoteSrc,      /*  5198 */
  XC_UsNoteSrc_e,    /*  5199 */

  XC_Img,            /*  5200 */
  XC_Img_e,          /*  5201 */

  XC_RefSecSynGr,    /*  5202 */  // AKLZ "Dar vartojama"
  XC_RefSecSynGr_e,  /*  5203 */
  XC_RefSecSyn,      /*  5204 */
  XC_RefSecSyn_e,    /*  5205 */

  XC_RefPriSynGr,    /*  5206 */  // AKLZ "Zr."
  XC_RefPriSynGr_e,  /*  5207 */
  XC_RefPriSyn,      /*  5208 */
  XC_RefPriSyn_e,    /*  5209 */

  XC_RefSynGr,       /*  5210 */  // AKLZ "Zr. dar"
  XC_RefSynGr_e,     /*  5211 */
  XC_RefSyn,         /*  5212 */
  XC_RefSyn_e,       /*  5213 */

  XC_RefExamplGr,    /*  5214 */  // AKLZ "Pavyzdziai:"
  XC_RefExamplGr_e,  /*  5215 */
  XC_RefExampl,      /*  5216 */
  XC_RefExampl_e,    /*  5217 */

  XC_RefAntGr,       /*  5218 */  // AKLZ "Plg.," // šiaip antonimai, bet gali būti ir sinonimai
  XC_RefAntGr_e,     /*  5219 */
  XC_RefAnt,         /*  5220 */
  XC_RefAnt_e,       /*  5221 */

  XC_RefExamplSinglGr,    /*  5222 */  // AKLZ "Pavyzdys:"
  XC_RefExamplSinglGr_e,  /*  5223 */

  XC_Subscript,      /*  5224 */
  XC_Subscript_e,    /*  5225 */

  XC_CodeExampleInline,   /*  5226 */
  XC_CodeExampleInline_e, /*  5227 */

  XC_EnumGr,         /*  5228 */ // list group
  XC_EnumGr_e,       /*  5229 */

  XC_Enum,           /*  5230 */ // list
  XC_Enum_e,         /*  5231 */
  
  XC_CodeBaseWord,   /*  5232 */ // programming language basewords in code examples (XC_CodeExampleInline)
  XC_CodeBaseWord_e, /*  5233 */
  
  XC_CodeExample,    /*  5234 */ // atskira kodo pavyzdzio pastraipa, preformatted text
  XC_CodeExample_e,  /*  5235 */

  XC_Table,          // 5236
  XC_Table_e,        // 5237
  XC_TableRow,       // 5238
  XC_TableRow_e,     // 5239
  XC_TableCell,      // 5240
  XC_TableCell_e,    // 5241

  XC_Equiation,      // 5242 // external equiation in internal mode (picture/tex/mathml)
  XC_Equiation_e,    // 5243

  XC_Break,          // 5244  // line break
  XC_Break_e,        // 5245

  XC_EquInline,      // 5246 // inline equiation
  XC_EquInline_e,    // 5247

  XC_Special,        // 5248 // inline low level code - TEX, PostScript, RTF, MathMl includes
  XC_Special_e,      // 5249

  XC_ExampleGroupForced,   //  5250 // example group for all levels including SimplyLevel
  XC_ExampleGroupForced_e, //  5251

  XC_ExplForced,     // 5252 // explanations for all levels including SimplyLevel
  XC_ExplForced_e,   // 5253 // language usually KP_LNG_LIT

  XC_VarGroup,       // 5254  // variantu grupavimui, kad atsiskirtu su xmlspt.exe
  XC_VarGroup_e,     // 5255

  XC_Relatives,      // 5256  // simbolis giminingiems zodziams, RLZ: || plg.
  XC_Relatives_e,    // 5257

  XC_Page,           // 5258 // puslapio, temos ir kt. numeris, paprastai pirmam failo lizde - failo aprase 
  XC_Page_e,         // 5259 
  
  XC_SemNr,          // 5260 // lizdo iraso numeris (lenteleje) 
  XC_SemNr_e,        // 5261 

  XC_TrWordLit,      // 5262
  XC_TrWordLit_e,    // 5263

  XC_TrWordEng,      // 5264
  XC_TrWordEng_e,    // 5265

  XC_TrWordGer,      // 5266
  XC_TrWordGer_e,    // 5267

  XC_TrWordFre,      // 5268
  XC_TrWordFre_e,    // 5269

  XC_TrWordPol,      // 5270
  XC_TrWordPol_e,    // 5271

  XC_TrWordRus,      // 5272
  XC_TrWordRus_e,    // 5273

  XC_Species,        // 5274 lotyniski variantai, neitraukiami i hw indeksus
  XC_Species_e,      // 5275

  XC_StructGroupForced,    // 5276 forsuotas junginys (for all levels including SimplyLevel)
  XC_StructGroupForced_e,  // 5277

  XC_VarBold,        // 5278 boldinis variantas neitraukiamas i hw indeksus
  XC_VarBold_e,      // 5279
  
  XC_RefAntStrictGr,       /*  5280 */  // AKLZ "Priešinga ... –" // antonimai
  XC_RefAntStrictGr_e,     /*  5281 */
  XC_RefAntStrict,         /*  5282 */
  XC_RefAntStrict_e,       /*  5283 */

  XC_LastDictTag  // ne paskutinis, o pirmas jau nebe XmlDictChars
};

//=================================================== xmlt data arrays
// -------------------- Dictionary XML tag names
extern const unsigned char *plpszaXmlttDictTags[XC_TG_NumOfDictTags00+1];  // xmltt tags (native), common for all projects
extern const unsigned char *plpszaXmlttDictTagsFull[XC_TG_NumOfDictTags00+1];  // xmltt tags with sgml Tage remarks
extern const unsigned char *plpszaSgmDictTags[XC_TG_NumOfDictTags00+1]; // Lizdynas SGML tag names, different for each project
extern const unsigned char *plpszaSgmDictTagsFull[XC_TG_NumOfDictTags00+1]; // Lizdynas SGML tag names, different for each project
extern const unsigned char *plpszaDictTagOutNames[XC_TG_NumOfDictTags00+1]; // former plpszaTagOutNames // Dictionary tag names for tagged output, different for each project
// extern const unsigned char *plpszaHtmlDictTags[XC_TG_NumOfDictTags00 + 1]; // Dictionary XML tag names // nežinau, kas čia galėtų būt, 
                                                                        // dabar viskas vyksta per <span class="tw"> ir pan. arba konvertuojama tiesiog į <b>, <i> ir kt. rich teksto tagus

extern const unsigned char **pplpszaMsgTags; // = plpszaSgmDictTags; // = plpszaXmlttDictTagsFull;

extern const int iaSgmDictCodeTables[XC_TG_NumOfDictTags00]; // former iaSgmCodeTables // XC_SGML Tage file code tables
extern const int iaSgmDictCodeTablesEdi[XC_TG_NumOfDictTags00]; // former iaSgmCodeTablesEdi // SGML Tage file code tables for editing with ZTEX
extern const int iaHtmlDictCodeTables[XC_TG_NumOfDictTags00]; // former iaHtmlCodeTables // XC KPT HTML codetable array (all entries ==0 (Unicode) except phonetics)
extern const int iaXmlDictNulCodeTables[XC_TG_NumOfDictTags00]; // former iaXmlNulCodeTables // default codetable array (with all entries ==0)

extern unsigned char caTgLangs[XC_TG_NumOfDictTags00];   // language codes of tags
                   
extern const unsigned char *lpszaXmlTagIxNames[XC_TG_NumOfDictTags00];  // index file suffixes for tags
                                                   // "tx" reiskia, kad reikia ieskoti tevo tago indexo,
                                                   //    (visiems nereiksminiams tagams, kurio reiksme nustato tevas)
                                                   
extern const bool baXmlDictTagsFreeText[XC_TG_NumOfDictTags00];
                     // free text presence in dictionary XML tags

extern const KpChar uiazXmlGrTags[];  // list of all group node tags (indent in XML file, nodes of KP_LISTBOX)

extern const KpChar uiazXmlNodeGrTags[];  // list of all node level group tags 
                                       // (Mazgai from Lizdynas, except tags of categories
                                       // and meanings)

extern const KpChar uiazXmlHwGrTags[]; // HeadWord containing group tags - used in XmlNode_tag::Hw2Tw()
extern const KpChar uiazXmlHwInvTags[];// tags, corresponding to each group tag from uiazXmlHwGrTags[],
                                    // used for inverting
extern const KpChar uiazXmlHwTags[];   // tags to change to <tw> by inverting - used in XmlNode_tag::Hw2Tw()

extern const KpChar uiazXmlCpdGrTags[]; // list of tags of compounds etc. - part of uiazXmlNodeGrTags

extern const KpChar uiazXmlVariantTags[]; // list of headword variant tags

extern const KpChar uiazXmlCtgGrTags[]; // list of categories and meaning group tags

extern const KpChar uiazXmlSingleTags[];  // list of all single tags (<xxx/>)

extern const KpChar uiazXmlParGrTags[XC_TG_NumOfDictTags00];
                     // array of possible parent group tags
                     // !!! must be expanded to full DTD support

extern bool bFreeTextInUs;

//=================================================== free xmlt funcons
extern HRESULT PutXmlHat(XmlO1 *pOutFile, const unsigned char *lpszFileName);
extern HRESULT PutXmlTail(XmlO1 *pOutFile);

// ----------------- test embedding
extern HRESULT XmltTestEmbedded(KpChar iTagCh, KpChar iPrevTag, bool *pbEmbedded);
            // tests whether iTagCh can be embedded into iPrevTag
            // must be parsed from DTD and belong to xmlf
extern HRESULT XmltTestEmbeddedLocal(KpChar iTagCh, KpChar iPrevTag, bool *pbEmbedded);

// ----------------- test tag parameters
extern HRESULT XmlttTestPars(KpChar iChar, XmlTagPars *pTagParsObj); // for xmltt tags
extern HRESULT XmltgTestPars(KpChar iChar, XmlTagPars *pTagParsObj); // for xmltg tags

// -----------------
extern HRESULT GetGrTag(KpChar iTag, KpChar *piGrTag); // calculates parent group tag of iTag

// -----------------
extern HRESULT XmlIcv(const unsigned char *lpszFileName); // calls program for index converting to bin

// -----------------
extern const char *lpszNodeBmpFNames[XC_TG_NumOfDictTags00]; // local project node bitmaps file names to be loaded to hNodeBitmaps
extern HBITMAP hNodeBitmaps[XC_TG_NumOfDictTags00]; 

extern HRESULT LoadXmltTreeBitmaps(void); // loads bitmaps from files lpszNodeBmpFNames and fills hNodeBitmaps


// -------------------------------------
extern const unsigned char *GetTagDelimiter(KpChar iPreviousTag, KpChar iNextTag); // grąžina pointerį į lpszXmlTagDelimiters[][] elementą

extern bool TestTagLevel(KpChar iTag, int iLevel); // tikrina baLevelTags[][]

extern KpChar GetXml2Tex(KpChar iTag); // grąžina iaXml2Tex[] reikšmę // realizacija faile xmlnx.cpp - kad netrukdytų ne TeX-iniams projektams 

extern KPS_FontStyles GetTagFont(KpChar iTag); // grąžina iaTagFonts[] reikšmę

extern inline const unsigned char *GetTagOutName(KpChar iTag) { return(GetTagName(iTag, plpszaDictTagOutNames)); } // grąžina plpszaDictTagOutNames[] reikšmę

extern KpChar GetXmlParGrTag(KpChar iTag); // grąžina uiazXmlParGrTags[] reikšmę

extern bool TestTagFreeText(KpChar iTag); // grąžina baXmlDictTagsFreeText[] reikšmę

extern HBITMAP GetNodeBitmap(KpChar iTag); // grąžina hNodeBitmaps[] reikšmę

extern unsigned char GetTagLang(KpChar iTag); // grąžina caTgLangs[] reikšmę
#endif

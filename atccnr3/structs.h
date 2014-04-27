   AIR TRAFFIC CONTROL DATA STRUCTURES

   /**********************************************************************/
   /* CNRINFO data structure, describes the container control.           */
   /**********************************************************************/
   typedef struct _CNRINFO     /* ccinfo */
   {
      ULONG       cb;                  /* size of CNRINFO struct        */
      PVOID       pSortRecord;         /* ptr to sort function,         */
      /*                                    RECORDCORE                  */
      PFIELDINFO  pFieldInfoLast;      /* pointer to last column in     */
      /*                                    left pane of a split window.*/
      PFIELDINFO  pFieldInfoObject;    /* Pointer to a column to        */
      /*                                  represent an object.  This is */
      /*                                  the column which will receive */
      /*                                  IN-USE emphasis.              */
      PSZ         pszCnrTitle;         /* text for container title. One */
      /*                                    string separated by line    */
      /*                                    separators for multi-lines  */
      ULONG       flWindowAttr;        /* container attrs - CV_*, CA_*  */
      POINTL      ptlOrigin;           /* lower-left origin in virtual  */
      /*                                    coordinates. CV_ICON view   */
      ULONG       cDelta;              /* Application defined threshold */
      /*                                    or number of records from   */
      /*                                    either end of the list.     */
      ULONG       cRecords;            /* number of records in container*/
      SIZEL       slBitmapOrIcon;      /* size of bitmap in pels        */
      SIZEL       slTreeBitmapOrIcon;  /* size of tree bitmaps in pels  */
      HBITMAP     hbmExpanded;         /* bitmap  for tree node         */
      HBITMAP     hbmCollapsed;        /* bitmap  for tree node         */
      HPOINTER    hptrExpanded;        /* icon    for tree node         */
      HPOINTER    hptrCollapsed;       /* icon    for tree node         */
      LONG        cyLineSpacing;       /* space between two rows        */
      LONG        cxTreeIndent;        /* indent for children           */
      LONG        cxTreeLine;          /* thickness of the Tree Line    */
      ULONG       cFields;             /* number of fields  in container*/
      LONG        xVertSplitbar;       /* position relative to the      */
      /*                                    container (CV_DETAIL); if   */
      /*                                    0xFFFF then unsplit         */
   } CNRINFO;
   
   /**********************************************************************/
   /* MINIRECORDCORE data structure, attribute values                    */
   /**********************************************************************/
   typedef struct _MINIRECORDCORE     /* minirec */
   {
      ULONG       cb;
      ULONG       flRecordAttr;        /* record attributes             */
      POINTL      ptlIcon;             /* Position of CV_ICON item      */
      struct _MINIRECORDCORE *preccNextRecord; /*ptr to next record */
      PSZ         pszIcon;             /* Text for CV_ICON view         */
      HPOINTER    hptrIcon;            /* Icon to display for ~CV_MINI  */
   } MINIRECORDCORE;
   
   /**********************************************************************/
   /* Data structure for CM_INSERTRECORD                                 */
   /**********************************************************************/
   typedef struct _RECORDINSERT     /* recins */
   {
      ULONG       cb;
      PRECORDCORE pRecordOrder;
      PRECORDCORE pRecordParent;
      ULONG       fInvalidateRecord;
      ULONG       zOrder;
      ULONG       cRecordsInsert;
   } RECORDINSERT;
   
   /**********************************************************************/
   /* Drag/Drop structures                                               */
   /**********************************************************************/
   typedef struct _DRAGITEM     /* ditem */
   {
      HWND    hwndItem;                  /* conversation partner          */
      ULONG   ulItemID;                  /* identifies item being dragged */
      HSTR    hstrType;                  /* type of item                  */
      HSTR    hstrRMF;                   /* rendering mechanism and format*/
      HSTR    hstrContainerName;         /* name of source container      */
      HSTR    hstrSourceName;            /* name of item at source        */
      HSTR    hstrTargetName;            /* suggested name of item at dest*/
      SHORT   cxOffset;                  /* x offset of the origin of the */
      /*                                      image from the mouse hotspot*/
      SHORT   cyOffset;                  /* y offset of the origin of the */
      /*                                      image from the mouse hotspot*/
      USHORT  fsControl;                 /* source item control flags     */
      USHORT  fsSupportedOps;            /* ops supported by source       */
   } DRAGITEM;
   
   typedef struct _DRAGINFO     /* dinfo */
   {
      ULONG    cbDraginfo;               /* Size of DRAGINFO and DRAGITEMs*/
      USHORT   cbDragitem;               /* size of DRAGITEM              */
      USHORT   usOperation;              /* current drag operation        */
      HWND     hwndSource;               /* window handle of source       */
      SHORT    xDrop;                    /* x coordinate of drop position */
      SHORT    yDrop;                    /* y coordinate of drop position */
      USHORT   cditem;                   /* count of DRAGITEMs            */
      USHORT   usReserved;               /* reserved for future use       */
   } DRAGINFO;
   
   typedef struct _DRAGIMAGE     /* dimg */
   {
      USHORT  cb;                        /* size control block            */
      USHORT  cptl;                      /* count of pts, if DRG_POLYGON  */
      LHANDLE hImage;                    /* image handle passed to DrgDrag*/
      SIZEL   sizlStretch;               /* size to strecth ico or bmp to */
      ULONG   fl;                        /* flags passed to DrgDrag       */
      SHORT   cxOffset;                  /* x offset of the origin of the */
      /*                                      image from the mouse hotspot*/
      SHORT   cyOffset;                  /* y offset of the origin of the */
      /*                                      image from the mouse hotspot*/
   } DRAGIMAGE;
   
   /**********************************************************************/
   /* Container Direct Manipulation structures                           */
   /**********************************************************************/
   typedef struct _CNRDRAGINIT     /* cdrginit */
   {
      HWND        hwndCnr;                 /* Container window handle   */
      PRECORDCORE pRecord;                 /* record under mouse ptr    */
      LONG        x;                       /* x coordinate of mouse ptr */
      LONG        y;                       /* y coordinate of mouse ptr */
      LONG        cx;                      /* x offset from record      */
      LONG        cy;                      /* y offset from record      */
   } CNRDRAGINIT;

   /*******************************************************************/
   /* Value set drag information structure                            */
   /*******************************************************************/
   typedef struct _VSDRAGINFO     /* vsdinfo */
   {
      PDRAGINFO pDragInfo;         /* Pointer to a drag info structure */
      USHORT    usRow;
      USHORT    usColumn;
   } VSDRAGINFO;
   

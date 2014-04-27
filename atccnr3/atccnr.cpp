/*

    AIR TRAFFIC CONTROL CONTAINER, Version 3

    This sample demonstrates the following:

        Multiple Container views ("Radar," Name, Tree, Detail, Text)
        Inserting multiple container records
        Explicitly positioning records
        Enumerating container contents
        Using a PM Timer to move the container objects at regular intervals
        Multiple context menus
        Container background owner-drawing
        Bitmaps for screen drawing performance
        Direct Manipulation (Drag/Drop)

    See online help for more information.

    Dave Briccetti                      Phone: 510 945-7565
    Dave Briccetti Software Consulting  Fax: 510 945-7436
    P.O. Box 1713                       CIS: 74475,1072
    Lafayette, CA 94549-7013            Internet: daveb@davebsoft.com

    Copyright (c) David C. Briccetti, 1993 - 1995
    All rights reserved.

    Dave Briccetti has been developing OS/2 applications on a consulting
    basis since 1987, and specializes in PM user interfaces.

*/

#define INCL_PM
#include <os2.h>

#include "atccnr.h"
#include "help.h"

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*
 *  AIRCRAFT CONTAINER RECORD STRUCTURE
 */

typedef enum _CNRRECTYPE        // cnrrtyp
{
    CNRRT_AIRCRAFT,
    CNRRT_CREWMEMBER
}   CNRRECTYPE;

typedef struct _APPCNRREC       // acr
{
    MINIRECORDCORE  recc;
    CNRRECTYPE      cnrrtyp;
    LONG            iRecord;            // Index of container record
    LONG            Altitude;           // Aircraft attributes
    LONG            Heading;            // ...
    LONG            Speed;
    LONG            AssignedAltitude;
    LONG            AssignedHeading;
    LONG            AssignedSpeed;
    PSZ             pszCallsign;
} APPCNRREC, *PAPPCNRREC;


/*
 *  APPLICATION WINDOW "INSTANCE" DATA
 */

typedef struct _INST     // inst
{
    HAB             hab;                // Anchor block handle for application
    HPS             hpsMemRadar;        // Memory PS where Radar bitmap stored
    HDC             hdcMem;             // Memory DC where Radar bitmap stored
    HBITMAP         hbmRadar;           // Radar screen bitmap
    HWND            hwndCnr;            // Container window handle
    HWND            hwndAircraftMenu;   // Aircraft manipulation menu
    HWND            hwndContainerMenu;  // Container manipulation menu
    PAPPCNRREC      pacrSelected;       // Ptr to selected container record
    LONG            CurrentView;        // Current view (IDMVIEW_ICON, etc.)
}   INST, *PINST;


/*
 *  FUNCTION DECLARATIONS
 */

static FNWP AirTrafficControlDlg;
static INT InsertContainerColumns (PINST pinst);
static INT InsertContainerRecords (PINST pinst);
static PSZ SetRecordText (PAPPCNRREC pacr);
static PFNWP pfnwpCnr;
static FNWP CnrSubclassWndProc;
static MRESULT EXPENTRY ControlInstructionDlg (HWND hwnd, ULONG msg,
    MPARAM mp1, MPARAM mp2);
static BOOL ManeuverAircraft (PAPPCNRREC pacrTraverse);
static HBITMAP CreateBitmap (HPS hpsMem, PRECTL prclTargetWnd);
static INT CreateMemoryPS (PINST pinstMain, HPS hpsTarget,
    PRECTL prclTargetWnd);
static INT
DrawBitmap (PINST pinstMain, HPS hpsTarget,
 PRECTL prclTargetWndDraw);
static INT InsertCrewRecords (HWND hwndCnr, PAPPCNRREC pacrRoot);
static PSZ MakeUpPersonName (VOID);
static VOID ProcessInitDrag (HWND hwndCnr,
    PCNRDRAGINIT pCnrDragInit);
static INT DisplayTimedMsg (HAB hab,
    HWND hwndDlg, PSZ pszMsg, LONG lSeconds);
static FNWP ControllerValueSetSubclassWndProc;
static INT SetUpControllerHandoffValueSet (HWND hwndDlg);



/*
 *  "FILE GLOBAL" VARIABLES
 */

static PFNWP pfnwpValueSet;



/*
 *  CONSTANTS AND MACROS
 */

#define IDTIMER_ADJUSTAIRCRAFT              100
#define IDTIMER_DISPLAYTIMEDMSG             101
#define AIRCRAFT_ADJUST_FREQUENCY           1000    // milliseconds

#define FIRST_CNR_ITEM(hwnd) \
    (PAPPCNRREC) WinSendMsg (hwnd, CM_QUERYRECORD, \
    0, MPFROM2SHORT (CMA_FIRST,CMA_ITEMORDER))

#define NEXT_CNR_ITEM(hwnd,prev) \
    (PAPPCNRREC) WinSendMsg (hwnd, CM_QUERYRECORD, \
    MPFROMP (prev), MPFROM2SHORT (CMA_NEXT,CMA_ITEMORDER))



/*
 *  MAIN FUNCTION
 */

int main( void )
{
    HAB     hab;
    HMQ     hmq;
    HWND    hwndHelpInstance;   /* Handle to Help window    */
    HWND    hwndDlg;            // Main dlg window
    static SWCNTRL swctl;


    freopen ("err", "w", stderr);

    assert ((hab = WinInitialize (0)) != 0);
    assert ((hmq = WinCreateMsgQueue (hab, 0)) != 0);

    // Load main application dialog
    hwndDlg = WinLoadDlg (HWND_DESKTOP, HWND_DESKTOP,
        AirTrafficControlDlg, 0, IDDLG_CNRSAMP, 0);

    swctl.hwnd = hwndDlg;
    strcpy( swctl.szSwtitle, "Air Traffic Control Container" );
    WinAddSwitchEntry( &swctl );

    hwndHelpInstance = InitializeHelp (hab, hwndDlg, IDDLG_CNRSAMP,
        (PSZ) "atccnr.HLP", (
        PSZ) "Air Traffic Control Container Help Window", 0);

    WinProcessDlg (hwndDlg);

    if (hwndHelpInstance)
        WinDestroyHelpInstance (hwndHelpInstance);

    WinDestroyWindow (hwndDlg);

    WinDestroyMsgQueue (hmq);
    WinTerminate (hab);

    return 0;
}



/*
 *  DIALOG PROCEDURE FOR MAIN APPLICATION WINDOW
 */

MRESULT EXPENTRY AirTrafficControlDlg (HWND hwnd, ULONG msg,
    MPARAM mp1, MPARAM mp2)
{
    PINST   pinst;

    pinst = (PINST) WinQueryWindowPtr(hwnd,QWL_USER);

    switch (msg)
    {
        case WM_INITDLG:
        {
            /*
             *  INITIALIZE APPLICATION
             */

            CNRINFO     ccinfo;         // Container info structure

            // Initialize instance data
            pinst = (PINST) calloc (1, sizeof *pinst);
            WinSetWindowPtr(hwnd,QWL_USER,pinst);
            pinst->hwndCnr = WinWindowFromID (hwnd, IDCNR_SAMPLE);
            pinst->hab     = WinQueryAnchorBlock (hwnd);
            pinst->hwndAircraftMenu =               // Load aircraft menu
                WinLoadMenu( HWND_OBJECT, 0, IDMENU_AIRCRAFT);
            pinst->hwndContainerMenu =              // Load container menu
                WinLoadMenu( HWND_OBJECT, 0, IDMENU_CONTAINER);
            pinst->CurrentView = IDMVIEW_RADAR;

            // Set container info to request owner background painting
            memset (&ccinfo, 0, sizeof ccinfo);
            ccinfo.cb = sizeof ccinfo;
            ccinfo.flWindowAttr = CA_OWNERPAINTBACKGROUND;
            WinSendMsg (pinst->hwndCnr, CM_SETCNRINFO, &ccinfo,
                MPFROMLONG(CMA_FLWINDOWATTR));

            // Subclass container window to provide background painting
            pfnwpCnr = WinSubclassWindow (pinst->hwndCnr,
                CnrSubclassWndProc);
            assert (pfnwpCnr);

            // Insert the columns into the container
            InsertContainerColumns (pinst);

            // Insert the initial records into the container
            InsertContainerRecords (pinst);

            // Start a timer to control aircraft
            WinStartTimer (pinst->hab, hwnd,
                IDTIMER_ADJUSTAIRCRAFT, AIRCRAFT_ADJUST_FREQUENCY);

            // The container is ready for viewing
            WinShowWindow (pinst->hwndCnr, TRUE);

            SetUpControllerHandoffValueSet (hwnd);

            return 0;
        }

        case WM_TIMER:

            /*
             *  DO TIME-RELATED AIRCRAFT HANDLING
             */

            if (SHORT1FROMMP (mp1) == IDTIMER_ADJUSTAIRCRAFT)
            {
                PAPPCNRREC      pacrTraverse;

                // Loop through all container records
                for (pacrTraverse = FIRST_CNR_ITEM (pinst->hwndCnr);
                    pacrTraverse;
                    pacrTraverse = NEXT_CNR_ITEM(pinst->hwndCnr,pacrTraverse))
                {
                    BOOL        fInvalid = FALSE;

                    if (pinst->CurrentView == IDMVIEW_RADAR)
                    {
                        /* Erase the record from previous location. */
                        WinSendMsg (pinst->hwndCnr, CM_ERASERECORD,
                            MPFROMP(pacrTraverse), NULL);
                    }

                    // Maneuver the aircraft
                    if (ManeuverAircraft (pacrTraverse))
                    {
                        // Update aircraft text if necessary
                        SetRecordText (pacrTraverse);
                        fInvalid = TRUE;
                    }

                    if (fInvalid || pinst->CurrentView == IDMVIEW_RADAR)
                        /* Paint the record in its new position */
                        WinSendMsg (pinst->hwndCnr, CM_INVALIDATERECORD,
                            MPFROMP(&pacrTraverse),
                            MPFROMSHORT(1));
                }
            }
            else
                if (SHORT1FROMMP (mp1) == IDTIMER_DISPLAYTIMEDMSG)
                {
                    WinStopTimer (pinst->hab, hwnd,
                        IDTIMER_DISPLAYTIMEDMSG);
                    WinSetDlgItemText (hwnd, IDST_STATUSMESSAGES, "");
                }


            return 0;


        case WM_CONTROL:
            if (SHORT1FROMMP (mp1) == IDCNR_SAMPLE)
                switch (SHORT2FROMMP (mp1))
                {
                    case CN_CONTEXTMENU:
                    {
                        /*
                         *  MENU HANDLING
                         */

                        POINTL  ptlMouse;
                        HWND    hwndMenu;

                        WinQueryMsgPos (pinst->hab, &ptlMouse);

                        // Save pointer to record mouse is over, if any
                        pinst->pacrSelected = (PAPPCNRREC) mp2;

                        hwndMenu = pinst->pacrSelected ?
                            pinst->hwndAircraftMenu :
                            pinst->hwndContainerMenu;

                        // Display menu
                        WinPopupMenu (HWND_DESKTOP, hwnd, hwndMenu,
                            ptlMouse.x, ptlMouse.y, 0,
                            PU_HCONSTRAIN | PU_VCONSTRAIN |
                            PU_KEYBOARD | PU_MOUSEBUTTON1 |
                            PU_MOUSEBUTTON2 |
                            PU_MOUSEBUTTON3);
                        return 0;
                    }

                    case CN_INITDRAG:
                        ProcessInitDrag (
                            WinWindowFromID (hwnd, SHORT1FROMMP (mp1)),
                            ((PCNRDRAGINIT) (PVOIDFROMMP(mp2))));
                        return 0;

                    case CN_SCROLL:
                        WinInvalidateRect (pinst->hwndCnr, 0, 0);
                        return 0;
                }
            else

/*
 *  HANDLE WM_CONTROL MESSAGES FROM VALUE SET CONTROL
 */

                if (SHORT1FROMMP (mp1) == IDVS_CONTROLLERS)
                    switch (SHORT2FROMMP (mp1))
                    {
                        case VN_SELECT:
                            DisplayTimedMsg (pinst->hab, hwnd,
                                "Drag an airplane to one "
                                "of the controller icons to hand off to "
                                "another controller.", 8);

                            return 0;

                        case VN_DROP:
                        {
                            PVSDRAGINFO pvsdinfo = (PVSDRAGINFO)
                               PVOIDFROMMP (mp2);
                            PDRAGINFO   pdinfo = pvsdinfo->pDragInfo;
                            PDRAGITEM   pditem;
                            INT         iItem;
                            INT         cHandedOffAircraft = 0;
                            CHAR        szHandedOffAircraft [100];

                            *szHandedOffAircraft = 0;

                            assert (DrgAccessDraginfo(pdinfo));

                            for (iItem = 0; iItem < pdinfo->cditem; ++iItem)
                            {
                                PAPPCNRREC      pacr;

                                pditem =  DrgQueryDragitemPtr (pdinfo, iItem);

                                pacr = (PAPPCNRREC) pditem->ulItemID;

                                if (pdinfo->usOperation == DO_MOVE)
                                {
                                    WinSendMsg (pdinfo->hwndSource,
                                        CM_REMOVERECORD,
                                        MPFROMP(&pacr),
                                        MPFROM2SHORT (1, CMA_INVALIDATE));

                                    if (cHandedOffAircraft++)
                                        strcat (szHandedOffAircraft, ", ");

                                    strcat (szHandedOffAircraft,
                                        pacr->pszCallsign);
                                }
                            }

                            if (cHandedOffAircraft)
                            {
                                CHAR    szMsg [200];

                                sprintf (szMsg,
                                    "Aircraft %s %s been handed off "
                                    "to %s Sector controller.",
                                    szHandedOffAircraft,
                                    cHandedOffAircraft > 1 ?
                                        "have" : "has",
                                    pvsdinfo->usColumn == 1 ?
                                        "West" : "East");

                                DisplayTimedMsg (pinst->hab, hwnd,
                                    szMsg, 8);
                            }

                            DrgFreeDraginfo (pdinfo);
                            WinAlarm (HWND_DESKTOP, WA_NOTE);
                            return 0;
                        }
                    }

            return 0;


        case WM_COMMAND:

            /*
             *  COMMAND HANDLING
             */

            switch (SHORT1FROMMP (mp1))
            {
                case IDMAIRCRAFT_CONTROLINSTRUCT:   // Issue instruction
                {
                    // Present "Control Aircraft" dialog
                    WinDlgBox (HWND_DESKTOP, hwnd,
                        ControlInstructionDlg, 0,
                        IDDLG_CONTROLAIRCRAFT, pinst);
                    return 0;
                }

                case IDMVIEW_RADAR:
                case IDMVIEW_NAME:
                case IDMVIEW_TREE:
                case IDMVIEW_DETAILS:
                case IDMVIEW_TEXT:
                {
                    static const ULONG  aViews [] =
                        { CV_ICON, CV_NAME, CV_TREE, CV_DETAIL, CV_TEXT };

                    CNRINFO ccinfo;
                    memset (&ccinfo, 0, sizeof ccinfo);
                    ccinfo.cb = sizeof ccinfo;
                    ccinfo.flWindowAttr = CA_DETAILSVIEWTITLES |
                        CA_TITLESEPARATOR | CA_TREELINE |
                        CA_OWNERPAINTBACKGROUND |
                        aViews [SHORT1FROMMP (mp1) - IDMVIEW_BASE];
                    WinSendMsg (pinst->hwndCnr, CM_SETCNRINFO, &ccinfo,
                        MPFROMLONG(CMA_FLWINDOWATTR));
                    pinst->CurrentView = SHORT1FROMMP (mp1);

                    WinInvalidateRect (pinst->hwndCnr, 0, 0);
                    return 0;
                }
            }

            return WinDefDlgProc (hwnd, msg, mp1, mp2);

        default:
            return WinDefDlgProc (hwnd, msg, mp1, mp2);
    }
}



/*
 *  WINDOW SUBCLASS PROCEDURE FOR VALUE SET WINDOW, TO MAKE
 *  IT RESPOND POSITIVELY TO DM_DRAGOVER. (THE AUTHOR CAN'T FIND
 *  DOCUMENTED WHAT THE RENDERING FORMAT OR OTHER REQUIREMENTS ARE.)
 */

static MRESULT EXPENTRY
ControllerValueSetSubclassWndProc (HWND hwnd, ULONG msg,
    MPARAM mp1, MPARAM mp2)
{
    switch (msg)
    {
        case DM_DRAGOVER:
        {
            USHORT          usIndicator;
            PDRAGITEM       pditem;
            PDRAGINFO       pdinfo = (PDRAGINFO) PVOIDFROMMP (mp1);

            pfnwpValueSet (hwnd, msg, mp1, mp2);

            assert (DrgAccessDraginfo(pdinfo));

            pditem = DrgQueryDragitemPtr (pdinfo, 0);

            if (DrgVerifyRMF (pditem, 0, "DRF_AIRCRAFT"))
            {
                usIndicator = (pdinfo->usOperation == DO_DEFAULT
                    || pdinfo->usOperation == DO_MOVE) ?
                    DOR_DROP : DOR_NODROP;
            }
            else
                usIndicator = DOR_NEVERDROP;

            return MRFROM2SHORT(usIndicator, DO_MOVE);
        }

    }
    return pfnwpValueSet (hwnd, msg, mp1, mp2);
}



/*
 *  SET UP THE VALUE SET CONTROL
 */

static INT SetUpControllerHandoffValueSet (HWND hwndDlg)
{
    HWND    hwndVS = WinWindowFromID (hwndDlg, IDVS_CONTROLLERS);
    SHORT   Col;
    HPOINTER    hptrController;

    hptrController = WinLoadPointer (HWND_DESKTOP, 0, IDICON_CONTROLLER);

    for (Col = 1; Col <= 2; ++Col)
    {
        WinSendMsg (hwndVS, VM_SETITEMATTR, MPFROM2SHORT (1, Col),
            MPFROM2SHORT (VIA_DROPONABLE, TRUE));
        WinSendMsg (hwndVS, VM_SETITEM, MPFROM2SHORT (1, Col),
            MPFROMP (hptrController));
    }

    pfnwpValueSet =
        WinSubclassWindow (hwndVS, ControllerValueSetSubclassWndProc);

    return 0;
}



/*
 *  DISPLAY A MESSAGE FOR A SPECIFIED PERIOD OF TIME
 */

static INT DisplayTimedMsg (HAB hab,
    HWND hwndDlg, PSZ pszMsg, LONG lSeconds)
{
    WinSetDlgItemText (hwndDlg, IDST_STATUSMESSAGES, pszMsg);

    // Start a timer for message
    WinStartTimer (hab, hwndDlg, IDTIMER_DISPLAYTIMEDMSG, lSeconds * 1000);

    return 0;
}


/*
 *  BUILD AN ARRAY OF POINTERS TO SELECTED CONTAINER RECORDS
 */

PAPPCNRREC * GetSelectedRecords (HWND hwndCnr, PLONG plcSelectedRecs)
{
    PAPPCNRREC  pur;
    PAPPCNRREC *apurSelected;
    CNRINFO     ccinfo;
    LONG        lcSelectedRecs = 0;

    assert (WinSendMsg (hwndCnr, CM_QUERYCNRINFO, &ccinfo,
        MPFROMSHORT (sizeof ccinfo)));

    apurSelected = (PAPPCNRREC *)
        calloc (ccinfo.cRecords, sizeof (PAPPCNRREC));

    for (pur = (PAPPCNRREC)WinSendMsg (hwndCnr,
        CM_QUERYRECORDEMPHASIS, (MPARAM)CMA_FIRST,
        MPFROMSHORT(CRA_SELECTED));
    pur;
    pur = (PAPPCNRREC)WinSendMsg (hwndCnr,
        CM_QUERYRECORDEMPHASIS, MPFROMP(pur),
        MPFROMSHORT(CRA_SELECTED)))
    {
        apurSelected[lcSelectedRecs++] = pur;
    }

    apurSelected = (PAPPCNRREC *) realloc (apurSelected,
        lcSelectedRecs * sizeof (PAPPCNRREC));

    *plcSelectedRecs = lcSelectedRecs;

    return apurSelected;
}




/*
 *  PROCESS THE CN_INITDRAG MESSAGE FOR STARTING DRAG/DROP
 */

static VOID ProcessInitDrag (HWND hwndCnr,
    PCNRDRAGINIT pCnrDragInit)
{
    PDRAGINFO   pdinfo;
    PDRAGIMAGE  pdimg;
    DRAGITEM    ditem;
    PAPPCNRREC  pur;
    INT         iItem;
    LONG        lcSelectedRecs = 0;
    PAPPCNRREC *apurSelected;


    if (pCnrDragInit->pRecord)
    {
        pur = (PAPPCNRREC) pCnrDragInit->pRecord;

        if (pur->cnrrtyp == CNRRT_AIRCRAFT)     // Only drag aircraft
        {
            if (pur->recc.flRecordAttr & CRA_SELECTED)
                apurSelected = GetSelectedRecords (hwndCnr, &lcSelectedRecs);
            else
            {
                lcSelectedRecs = 1;
                apurSelected = (PAPPCNRREC *)
                    calloc (lcSelectedRecs, sizeof (PAPPCNRREC));
                apurSelected[0] = pur;
            }

            pdinfo = DrgAllocDraginfo (lcSelectedRecs);
            pdinfo->hwndSource = hwndCnr;
            pdimg = (PDRAGIMAGE)
                calloc (lcSelectedRecs, sizeof (DRAGIMAGE));

            memset (&ditem, 0, sizeof ditem);
            ditem.hwndItem       = hwndCnr;
            ditem.hstrRMF        =
                DrgAddStrHandle ("<DRM_UNKNOWN, DRF_AIRCRAFT>");
            ditem.fsSupportedOps = DO_MOVEABLE;

            for (iItem = 0; iItem < lcSelectedRecs; ++iItem)
            {
                ditem.ulItemID = (ULONG) apurSelected[iItem];
                DrgSetDragitem (pdinfo, &ditem, sizeof(DRAGITEM), iItem);

                pdimg[iItem].cb = sizeof( DRAGIMAGE );
                pdimg[iItem].cptl = 0;
                pdimg[iItem].fl = DRG_ICON;
                pdimg[iItem].cxOffset = iItem * 10;
                pdimg[iItem].cyOffset = iItem * 10;
                pdimg[iItem].hImage = apurSelected[iItem]->recc.hptrIcon;
            }

            /* Call drag to start dragging. */
            DrgDrag (hwndCnr, pdinfo, pdimg, lcSelectedRecs, VK_BUTTON2,
                (PVOID) 0x80000000);

            free (pdimg);
        }
    }
}



/*
 *  INSERT COLUMNS INTO CONTAINER
 */

static INT InsertContainerColumns (PINST pinst)
{
#define NEWFIELDOFFSET(s,m) (&(((s *)0)->m))

    PFIELDINFO      pfldinfo;
    PFIELDINFO      pfldinfoFirst;
    FIELDINFOINSERT fiins;
    LONG            iField = 0;
    static const FIELDINFO afldinfo[] =
    {
        {0, CFA_STRING | CFA_FIREADONLY | CFA_HORZSEPARATOR | CFA_LEFT,
         CFA_LEFT | CFA_FITITLEREADONLY, "Call sign",
         (ULONG)(NEWFIELDOFFSET(APPCNRREC,pszCallsign)), 0, 0, 0},
        {0, CFA_ULONG | CFA_FIREADONLY | CFA_HORZSEPARATOR | CFA_LEFT,
         CFA_LEFT | CFA_FITITLEREADONLY, "Heading",
         (ULONG)(NEWFIELDOFFSET(APPCNRREC,Heading)), 0, 0, 0},
        {0, CFA_ULONG | CFA_FIREADONLY | CFA_HORZSEPARATOR | CFA_LEFT,
         CFA_LEFT | CFA_FITITLEREADONLY, "Assigned\nHeading",
         (ULONG)(NEWFIELDOFFSET(APPCNRREC,AssignedHeading)), 0, 0, 0},
        {0, CFA_ULONG | CFA_FIREADONLY | CFA_HORZSEPARATOR | CFA_LEFT,
         CFA_LEFT | CFA_FITITLEREADONLY, "Altitude\n(Hundreds\nof Feet)",
         (ULONG)(NEWFIELDOFFSET(APPCNRREC,Altitude)), 0, 0, 0},
        {0, CFA_ULONG | CFA_FIREADONLY | CFA_HORZSEPARATOR | CFA_LEFT,
         CFA_LEFT | CFA_FITITLEREADONLY,
         "Assigned\nAltitude\n(Hundreds\nof Feet)",
         (ULONG)(NEWFIELDOFFSET(APPCNRREC,AssignedAltitude)), 0, 0, 0},
        {0, CFA_ULONG | CFA_FIREADONLY | CFA_HORZSEPARATOR | CFA_LEFT,
         CFA_LEFT | CFA_FITITLEREADONLY, "Speed\n(Tens of\nknots)",
         (ULONG)(NEWFIELDOFFSET(APPCNRREC,Speed)), 0, 0, 0},
        {0, CFA_ULONG | CFA_FIREADONLY | CFA_HORZSEPARATOR | CFA_LEFT,
         CFA_LEFT | CFA_FITITLEREADONLY, "Assigned\nSpeed\n(Tens of\nknots",
         (ULONG)(NEWFIELDOFFSET(APPCNRREC,AssignedSpeed)), 0, 0, 0}
    };
    static const INT cFields = sizeof afldinfo / sizeof afldinfo[0];

    pfldinfo = pfldinfoFirst = (PFIELDINFO) WinSendMsg (pinst->hwndCnr,
        CM_ALLOCDETAILFIELDINFO, MPFROMLONG(cFields), NULL);

    for (iField = 0; iField < cFields; ++iField)
    {
        pfldinfo->cb         = sizeof(FIELDINFO);
        pfldinfo->flData     = afldinfo [iField].flData;
        pfldinfo->flTitle    = afldinfo [iField].flTitle;
        pfldinfo->pTitleData = afldinfo [iField].pTitleData;
        pfldinfo->offStruct  = afldinfo [iField].offStruct;
        pfldinfo = pfldinfo->pNextFieldInfo;
    }

    fiins.cb = sizeof fiins;
    fiins.pFieldInfoOrder = (PFIELDINFO)CMA_FIRST;
    fiins.cFieldInfoInsert = cFields;
    fiins.fInvalidateFieldInfo = TRUE;

    /*
     *  INSERT DETAIL VIEW INFORMATION
     */

    WinSendMsg (pinst->hwndCnr, CM_INSERTDETAILFIELDINFO,
        MPFROMP(pfldinfoFirst), MPFROMP(&fiins));


    return 0;
}



/*
 *  INSERT AIRCRAFT INTO RADAR SCREEN CONTAINER
 */

static INT InsertContainerRecords (PINST pinst)
{
    PAPPCNRREC      pacrRoot;           // Ptr to root of list of records
    PAPPCNRREC      pacrTraverse;       // Ptr to traverse list of records
    RECORDINSERT    recins;             // Record insertion information
    HPOINTER        hptrIcon;           // Handle of jet icon
    RECTL           rclCnr;             // Container dimensions
    LONG            iRecord = 0;        // Record index
    static const PSZ apszCallSignPrefixes [] =
        { "AA", "DA", "UA", "TW" };
    static const INT cPrefixes = sizeof apszCallSignPrefixes /
        sizeof apszCallSignPrefixes[0];
    CHAR            szBuf [30];

    /*
     *  SET UP RECORD INSERT STRUCTURE
     */

    memset (&recins, 0, sizeof recins);
    recins.cb                = sizeof recins;
    recins.pRecordOrder      = (PRECORDCORE) CMA_END;
    recins.zOrder            = CMA_TOP;
    recins.cRecordsInsert    = 5;
    recins.fInvalidateRecord = TRUE;


    /*
     *  ALLOCATE CONTAINER ITEM LINKED LIST
     */

    pacrRoot = (PAPPCNRREC) WinSendMsg (
        pinst->hwndCnr, CM_ALLOCRECORD,
        MPFROMLONG(sizeof(APPCNRREC) - sizeof(MINIRECORDCORE)),
        MPFROMLONG(recins.cRecordsInsert));


    /*
     *  SET UP USER RECORD LINKED LIST
     */

    hptrIcon = WinLoadPointer (HWND_DESKTOP, 0, IDICON_JET);
    WinQueryWindowRect (pinst->hwndCnr, &rclCnr);
    srand (clock());


    for (iRecord = 0, pacrTraverse = pacrRoot;
        iRecord < recins.cRecordsInsert;
        ++iRecord, pacrTraverse = (PAPPCNRREC)
        pacrTraverse->recc.preccNextRecord)
    {
        pacrTraverse->cnrrtyp       = CNRRT_AIRCRAFT;
        pacrTraverse->iRecord       = iRecord;
        pacrTraverse->Altitude      =
        pacrTraverse->AssignedAltitude = rand() % 50 + 50;
        pacrTraverse->Heading       =
        pacrTraverse->AssignedHeading  = rand() % 360 + 1;
        pacrTraverse->Speed         =
        pacrTraverse->AssignedSpeed = rand() % 20 + 10;
        sprintf (szBuf, "%s%ld",
            apszCallSignPrefixes [rand() % cPrefixes], rand() % 1000);
        pacrTraverse->pszCallsign   = strdup (szBuf);

        SetRecordText (pacrTraverse);
        pacrTraverse->recc.hptrIcon = hptrIcon;
        pacrTraverse->recc.ptlIcon.x = rclCnr.xRight / 10 * (rand() % 9 + 1);
        pacrTraverse->recc.ptlIcon.y = rclCnr.yTop   / 10 * (rand() % 9 + 1);
    }


    /*
     *  INSERT ALL CONTAINER ITEMS
     */

    WinSendMsg (pinst->hwndCnr, CM_INSERTRECORD,
        MPFROMP(pacrRoot), MPFROMP(&recins));


    /*
     *  INSERT CHILD RECORDS FOR TREE VIEW
     */

    InsertCrewRecords (pinst->hwndCnr, pacrRoot);


    /*
     *  DESELECT FIRST AIRPLANE, WHICH BECOMES SELECTED AUTOMATICALLY
     */

    WinSendMsg (pinst->hwndCnr, CM_SETRECORDEMPHASIS,
        MPFROMP(pacrRoot), MPFROM2SHORT(FALSE, CRA_SELECTED));

    return 0;
}



/*
 *  INSERT CREW CHILD RECORDS FOR THE TREE VIEW
 */

static INT InsertCrewRecords
(
    HWND        hwndCnr,
    PAPPCNRREC  pacrRoot            // Ptr to root of list of records
)
{
    PAPPCNRREC      pacrTraverse;       // Ptr to traverse list of records
    PAPPCNRREC      pacrCrew;           // Ptr to child crew record
    RECORDINSERT    recins;             // Record insertion information
    HPOINTER        hptrIconCrew;       // Crew icon
    INT             iCrewRecord;

    /*
     *  LOAD ICONS
     */

    hptrIconCrew = WinLoadPointer (HWND_DESKTOP, 0, IDICON_CREW);


    /*
     *  SET UP RECORD INSERT STRUCTURE
     */

    memset (&recins, 0, sizeof recins);
    recins.cb                = sizeof recins;
    recins.pRecordOrder      = (PRECORDCORE) CMA_END;
    recins.zOrder            = CMA_TOP;
    recins.cRecordsInsert    = 3;
    recins.fInvalidateRecord = TRUE;


    /*
     *  LOOP THROUGH ALL MAIN RECORDS
     */

    for (pacrTraverse = pacrRoot; pacrTraverse;
        pacrTraverse = (PAPPCNRREC) pacrTraverse->recc.preccNextRecord)
    {
        PAPPCNRREC      pacrCrewTraverse;   // Ptr to traverse crew records


        /*
         *  ALLOCATE CREW CHILD RECORDS
         */

        pacrCrew = (PAPPCNRREC) WinSendMsg (
            hwndCnr, CM_ALLOCRECORD,
            MPFROMLONG(sizeof(APPCNRREC) - sizeof(MINIRECORDCORE)),
            MPFROMLONG(recins.cRecordsInsert));


        /*
         *  SET PARENT RECORD IN RECORDINSERT STRUCTURE
         */

        recins.pRecordParent = (PRECORDCORE) pacrTraverse;


        /*
         *  LOOP THROUGH ALL CREW CHILD RECORDS
         */

        for (iCrewRecord = 0, pacrCrewTraverse = pacrCrew;
            pacrCrewTraverse;
            iCrewRecord++, pacrCrewTraverse =
            (PAPPCNRREC) pacrCrewTraverse->recc.preccNextRecord)
        {
            static  const   PSZ apszCrewPositions [] =
                { "Captain", "First Officer", "Head Flight Attendant" };
            CHAR    szTitle [100];
            PSZ     pszMadeUpName;


            /*
             *  SET ICON AND TEXT OF CREW RECORD
             */

            pacrCrewTraverse->cnrrtyp       = CNRRT_CREWMEMBER;
            pacrCrewTraverse->recc.hptrIcon = hptrIconCrew;
            pszMadeUpName = MakeUpPersonName ();
            sprintf (szTitle, "%s\n%s", pszMadeUpName,
                apszCrewPositions [iCrewRecord]);
            free (pszMadeUpName);
            pacrCrewTraverse->recc.pszIcon = strdup (szTitle);
        }


        /*
         *  INSERT ALL CREW RECORDS FOR THIS MAIN RECORD
         */

        WinSendMsg (hwndCnr, CM_INSERTRECORD,
            MPFROMP(pacrCrew), MPFROMP(&recins));
    }

    return 0;
}



/*
 *  RETURN AN ALLOCATED BUFFER CONTAINING A MADE-UP NAME
 */

static PSZ MakeUpPersonName (VOID)
{
    CHAR    szName [100];

    static const PSZ apszFirstNames[] =
    {
        "Cary", "Donald S.", "Henry", "Nick", "Peter L.", "Ronald W.",
        "Frank", "Roy", "Robert", "Debra", "Delmar", "Gene", "Eric",
        "Hal", "Kathryne M.", "Sara", "Susan", "Pamela", "Helen",
        "Dave", "Tim", "Jane", "Mary", "Juan", "Vincent", "Srinevesa",
        "Paolo", "Ricardo"
    };
    static const SHORT cFirstNames =
        sizeof apszFirstNames / sizeof apszFirstNames [0];

    static const PSZ apszLastNames[] =
    {
        "Alley", "Babcock", "Barnum", "Dallons", "Farnum", "Griffin",
        "Harnell", "Hubert", "Kester", "Lear", "Lyons", "Medley",
        "Mowers", "Parker", "Pickell", "Rivera", "Santos", "Tyler",
        "Liu", "Chan", "Jones", "Smith", "Peterson"
    };
    static const SHORT cLastNames =
        sizeof apszLastNames / sizeof apszLastNames [0];

    sprintf (szName, "%s %s", apszFirstNames [rand() % cFirstNames],
        apszLastNames [rand() % cLastNames]);

    return strdup (szName);
}



/*
 *  GENERATE THE TEXT FOR THE AIRCRAFT'S RADAR DISPLAY, BASED ON ITS
 *  CURRENT ATTRIBUTES
 */

static PSZ SetRecordText (PAPPCNRREC pacr)
{
    CHAR    szBuf [40];

    if (pacr->recc.pszIcon)
        free (pacr->recc.pszIcon);

    sprintf (szBuf, "%s\n%3ld %2ld", pacr->pszCallsign,
        pacr->Altitude, pacr->Speed);

    return pacr->recc.pszIcon = strdup (szBuf);
}



/*
 *  DIALOG FOR ISSUING CONTROL INSTRUCTIONS TO AN AIRCRAFT
 */

static MRESULT EXPENTRY ControlInstructionDlg (HWND hwnd, ULONG msg,
    MPARAM mp1, MPARAM mp2)
{
    PINST   pinstMain;      // Ptr to main application instance data

    pinstMain = (PINST) WinQueryWindowPtr(hwnd,QWL_USER);

    switch (msg)
    {
        case WM_INITDLG:
        {
            // A ptr to main application instance data is passed to
            // this dialog.  Store it in our QWL_USER data.
            pinstMain = (PINST) PVOIDFROMMP (mp2);
            WinSetWindowPtr(hwnd,QWL_USER,pinstMain);

            // Set the limits for the spin controls
            WinSendDlgItemMsg (hwnd, IDSPB_HEADING,
                SPBM_SETLIMITS, MPFROMLONG (360), MPFROMLONG (1));
            WinSendDlgItemMsg (hwnd, IDSPB_ALTITUDE,
                SPBM_SETLIMITS, MPFROMLONG (500), MPFROMLONG (10));
            WinSendDlgItemMsg (hwnd, IDSPB_SPEED,
                SPBM_SETLIMITS, MPFROMLONG (100), MPFROMLONG (5));

            // Set current values for the spin controls
            WinSendDlgItemMsg (hwnd, IDSPB_HEADING,
                SPBM_SETCURRENTVALUE,
                MPFROMLONG (pinstMain->pacrSelected->Heading), 0);
            WinSendDlgItemMsg (hwnd, IDSPB_ALTITUDE,
                SPBM_SETCURRENTVALUE,
                MPFROMLONG (pinstMain->pacrSelected->Altitude), 0);
            WinSendDlgItemMsg (hwnd, IDSPB_SPEED,
                SPBM_SETCURRENTVALUE,
                MPFROMLONG (pinstMain->pacrSelected->Speed), 0);

            return 0;
        }

        case WM_COMMAND:
            switch (SHORT1FROMMP (mp1))
            {
                case DID_OK:
                {
                    // Get current values for the spin controls
                    WinSendDlgItemMsg (hwnd, IDSPB_HEADING,
                        SPBM_QUERYVALUE,
                        MPFROMLONG (&pinstMain->pacrSelected->
                            AssignedHeading), 0);
                    WinSendDlgItemMsg (hwnd, IDSPB_ALTITUDE,
                        SPBM_QUERYVALUE,
                        MPFROMLONG (&pinstMain->pacrSelected->
                            AssignedAltitude), 0);
                    WinSendDlgItemMsg (hwnd, IDSPB_SPEED,
                        SPBM_QUERYVALUE,
                        MPFROMLONG (&pinstMain->pacrSelected->
                            AssignedSpeed), 0);

                    break;
                }
            }

            return WinDefDlgProc (hwnd, msg, mp1, mp2);

        default:
            return WinDefDlgProc (hwnd, msg, mp1, mp2);
    }
}



/*
 *  MAKE THE PLANES FLY!
 */

static BOOL ManeuverAircraft (PAPPCNRREC pacrTraverse)
{
    BOOL    fManeuverRequired = FALSE;

    if (pacrTraverse->AssignedHeading !=
        pacrTraverse->Heading)
    {
        BOOL    fTurningRight =
            pacrTraverse->AssignedHeading >
            pacrTraverse->Heading;
        pacrTraverse->Heading +=
            (fTurningRight ? 1 : -1);
        fManeuverRequired = TRUE;
    }

    if (pacrTraverse->AssignedAltitude !=
        pacrTraverse->Altitude)
    {
        BOOL    fAscending =
            pacrTraverse->AssignedAltitude >
            pacrTraverse->Altitude;
        pacrTraverse->Altitude +=
            (fAscending ? 1 : -1);
        fManeuverRequired = TRUE;
    }

    if (pacrTraverse->AssignedSpeed !=
        pacrTraverse->Speed)
    {
        BOOL    fAccelerating =
            pacrTraverse->AssignedSpeed >
            pacrTraverse->Speed;
        pacrTraverse->Speed +=
            (fAccelerating ? 1 : -1);
        fManeuverRequired = TRUE;
    }

    if (pacrTraverse->Heading > 45 &&
        pacrTraverse->Heading < 135)
        pacrTraverse->recc.ptlIcon.x++;
    else
        if (pacrTraverse->Heading > 225 &&
            pacrTraverse->Heading < 315)
            pacrTraverse->recc.ptlIcon.x--;

    if (pacrTraverse->Heading > 315 &&
        pacrTraverse->Heading < 45)
        pacrTraverse->recc.ptlIcon.y++;
    else
        if (pacrTraverse->Heading > 135 &&
            pacrTraverse->Heading < 225)
            pacrTraverse->recc.ptlIcon.y--;

    return fManeuverRequired;
}



/*
 *  DRAW THE RADAR SCREEN (THE CONTAINER BACKGROUND)
 */

static MRESULT EXPENTRY CnrSubclassWndProc
(
    HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2
)
{
    if (msg == CM_PAINTBACKGROUND)
    {
        POWNERBACKGROUND    pownbckg = (POWNERBACKGROUND) mp1;
        RECTL               rclCnr;
        PINST               pinstMain;

        pinstMain = (PINST) WinQueryWindowPtr
            (WinQueryWindow (hwnd, QW_OWNER), QWL_USER);

        if (pinstMain->CurrentView != IDMVIEW_RADAR)
            return FALSE;

        WinQueryWindowRect (hwnd, &rclCnr);

        /*
         *  The radar screen is drawn once into a bitmap and
         *  subsequently GpiBitBlt'd onto the screen
         */

        if (! pinstMain->hbmRadar)
        {
            RECTL               rclRunway;
            LONG                cxRunway;
            LONG                cyRunway;
            ARCPARAMS           arcp;           // arc parameters
            POINTL              ptlScreenMidpoint;
            POINTL              ptlMarkerMidpoint;
            INT                 RadiusMultiplier;

            CreateMemoryPS (pinstMain, pownbckg->hps, &rclCnr);
            pinstMain->hbmRadar =
                CreateBitmap (pinstMain->hpsMemRadar, &rclCnr);

            WinFillRect (pinstMain->hpsMemRadar, &rclCnr,
                CLR_DARKGREEN);

            ptlScreenMidpoint.x = rclCnr.xRight / 2;
            ptlScreenMidpoint.y = rclCnr.yTop / 2;


            /*
             * Draw runway
             */

            cxRunway          = rclCnr.xRight / 60;
            cyRunway          = rclCnr.yTop / 10;
            rclRunway.xLeft   = ptlScreenMidpoint.x - cxRunway / 2;
            rclRunway.xRight  = rclRunway.xLeft + cxRunway;
            rclRunway.yBottom = ptlScreenMidpoint.y - cyRunway / 2;
            rclRunway.yTop    = rclRunway.yBottom + cyRunway;
            WinFillRect (pinstMain->hpsMemRadar, &rclRunway, CLR_WHITE);


            /*
             * Draw approach outer marker (3 elipses)
             */

            ptlMarkerMidpoint.x = ptlScreenMidpoint.x;
            ptlMarkerMidpoint.y = ptlScreenMidpoint.y - rclCnr.yTop / 6;
            GpiMove (pinstMain->hpsMemRadar, &ptlMarkerMidpoint);

            arcp.lP = rclCnr.xRight / 20;
            arcp.lQ = rclCnr.yTop / 80;
            arcp.lR = arcp.lS = 0L;
            GpiSetArcParams(pinstMain->hpsMemRadar,&arcp);
            GpiSetColor (pinstMain->hpsMemRadar, CLR_WHITE);
            GpiFullArc (pinstMain->hpsMemRadar, DRO_OUTLINE, MAKEFIXED(1,0));

            arcp.lP =
            arcp.lQ = rclCnr.yTop / 60;
            arcp.lR = arcp.lS = 0L;
            GpiSetArcParams(pinstMain->hpsMemRadar,&arcp);
            GpiSetColor (pinstMain->hpsMemRadar, CLR_WHITE);
            GpiFullArc (pinstMain->hpsMemRadar, DRO_OUTLINE, MAKEFIXED(1,0));

            arcp.lP =
            arcp.lQ = 1;
            arcp.lR = arcp.lS = 0L;
            GpiSetArcParams(pinstMain->hpsMemRadar,&arcp);
            GpiSetColor (pinstMain->hpsMemRadar, CLR_WHITE);
            GpiFullArc (pinstMain->hpsMemRadar, DRO_OUTLINE, MAKEFIXED(1,0));


            /*
             * Draw distance rings concentric circles
             */

            GpiMove (pinstMain->hpsMemRadar, &ptlScreenMidpoint);
            arcp.lP = arcp.lQ = min (rclCnr.xRight, rclCnr.yTop) / 9;
            arcp.lR = arcp.lS = 0L;
            GpiSetArcParams(pinstMain->hpsMemRadar,&arcp);

            GpiSetColor (pinstMain->hpsMemRadar, CLR_BLACK);

            for (RadiusMultiplier = 1; RadiusMultiplier <= 4; ++RadiusMultiplier)
                GpiFullArc(pinstMain->hpsMemRadar,DRO_OUTLINE,
                    MAKEFIXED(RadiusMultiplier,0));
        }

        DrawBitmap (pinstMain, pownbckg->hps, &pownbckg->rclBackground);

        return (MRESULT) TRUE;
    }
    else
        return pfnwpCnr (hwnd, msg, mp1, mp2);
}




static INT
DrawBitmap
(
    PINST           pinstMain,
    HPS             hpsTarget,
    PRECTL          prclTargetWndDraw
)
{
    POINTL            ptl[3];                 // point definitions

    //
    // Copy the bitmap into the window. Prepare the coordinates and sizes.
    //
    memset (ptl, 0, sizeof ptl);
    ptl[0].x = prclTargetWndDraw->xLeft;
    ptl[0].y = prclTargetWndDraw->yBottom;
    ptl[1].x = prclTargetWndDraw->xRight;
    ptl[1].y = prclTargetWndDraw->yTop;
    ptl[2].x = prclTargetWndDraw->xLeft;
    ptl[2].y = prclTargetWndDraw->yBottom;

    GpiBitBlt(hpsTarget,pinstMain->hpsMemRadar,3L,
        ptl,ROP_SRCCOPY,BBO_IGNORE);

   return 0;                                        // done ok
}


static INT CreateMemoryPS (PINST pinstMain, HPS hpsTarget,
    PRECTL prclTargetWnd)
{
    SIZEL   sizl;
    HDC     hdcTarget = GpiQueryDevice(hpsTarget);

    pinstMain->hdcMem = DevOpenDC(pinstMain->hab,OD_MEMORY,"*",
        0L,NULL,hdcTarget);
    assert (pinstMain->hdcMem != DEV_ERROR);

    //
    // Set the size of the presentation space to be created.
    //
    sizl.cx = prclTargetWnd->xRight;
    sizl.cy = prclTargetWnd->yTop;

    //
    // Create the memory presentation space for the bitmap.
    //
    pinstMain->hpsMemRadar = GpiCreatePS(pinstMain->hab,
       pinstMain->hdcMem,&sizl,
       PU_PELS | GPIA_ASSOC | GPIT_MICRO);
    assert (pinstMain->hpsMemRadar != GPI_ERROR);

    return 0;
}


static HBITMAP CreateBitmap (HPS hpsMem, PRECTL prclTargetWnd)
{
    LONG        lFormats[24];              // bitmap data formats
    BITMAPINFOHEADER2 bmp;                       // bitmap info header
    HBITMAP         hbm;

    GpiQueryDeviceBitmapFormats( hpsMem, 24L, lFormats );
    memset( &bmp, 0, sizeof bmp);
    bmp.cbFix      = sizeof bmp;          // size of the header
    bmp.cx         = prclTargetWnd->xRight;
    bmp.cy         = prclTargetWnd->yTop;
    bmp.cPlanes    = (USHORT)lFormats[0];  // planes
    bmp.cBitCount  = (USHORT)lFormats[1];  // bit count

    hbm = GpiCreateBitmap(hpsMem,&bmp,0,NULL,NULL);
    assert (hbm != GPI_ERROR);

    GpiSetBitmap(hpsMem,hbm);

    return hbm;
}

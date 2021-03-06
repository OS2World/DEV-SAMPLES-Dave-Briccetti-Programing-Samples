/*******************************************************************************
* FILE NAME: DiveDemo2.hpp                                                     *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class:                                                  *
*     DiveDemo2                                                                *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _DIVEDEMO2_
#define _DIVEDEMO2_  

class DiveDemo2;

#ifndef _IFRAME_
#include <iframe.hpp>
#endif

class IInfoArea;
class IToolBar;
class IToolBarButton;
class IMultiCellCanvas;
class IProgressIndicator;
class ISlider;
class FastCanvas;
class IStaticText;
class IVBFlyText;
class StarFieldRenderer;
class FaderRenderer;
#ifndef _IRECT_
#include <irect.hpp>
#endif

#ifndef _ISTRING_
#include <istring.hpp>
#endif

#include "os2.h"

#include "stdlib.h"

#include "time.h"

class DiveDemo2Conn22;
class DiveDemo2Conn10;
class DiveDemo2Conn31;
class DiveDemo2Conn32;
class DiveDemo2Conn20;
class DiveDemo2Conn11;
class DiveDemo2Conn8;
class DiveDemo2Conn9;
class DiveDemo2Conn30;
class DiveDemo2Conn21;
class DiveDemo2Conn41;
class DiveDemo2Conn23;
class DiveDemo2Conn25;
class DiveDemo2Conn27;
class DiveDemo2Conn16;
class DiveDemo2Conn37;
class DiveDemo2Conn19;
#include "DiveDemo2.h"


/*----------------------------------------------------------------------------*/
/* Align classes on four byte boundary.                                       */
/*----------------------------------------------------------------------------*/
#pragma pack(4)

//*****************************************************************************
// Class definition for DiveDemo2
//*****************************************************************************
class DiveDemo2 : public IFrameWindow {
public:
   //---------------------------------------------------------------------------
   // Constructors / destructors
   //---------------------------------------------------------------------------
   DiveDemo2(
      unsigned long id = WND_DiveDemo2,
      IWindow* parent = IWindow::desktopWindow(),
      IWindow* owner = 0,
      const IRectangle& rect = defaultFramingSpec(),
      const IFrameWindow::Style& style = IFrameWindow::defaultStyle ( ),
      const char* title = defaultTitle());

   virtual  ~DiveDemo2();

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   static const IRectangle defaultFramingSpec();
   static IString defaultTitle();
   virtual DiveDemo2 & initializePart();
   DiveDemo2 * getFrameWindow() { return this; };

   //---------------------------------------------------------------------------
   // public member data
   //---------------------------------------------------------------------------
   static const INotificationId readyId;

protected:
   //---------------------------------------------------------------------------
   // protected member functions
   //---------------------------------------------------------------------------
   Boolean makeConnections();

private:
   //---------------------------------------------------------------------------
   // private member data
   //---------------------------------------------------------------------------
   IInfoArea * iInfoArea1;
   IToolBar * iToolBar1;
   IToolBarButton * iToolBarButton1;
   IToolBarButton * iToolBarButton2;
   IToolBarButton * iToolBarButton3;
   IToolBarButton * iToolBarButton4;
   IToolBarButton * iToolBarButton5;
   IMultiCellCanvas * iMultiCellCanvas1;
   IProgressIndicator * iActualRateProgressIndicator;
   ISlider * iRequestedRateSlider;
   FastCanvas * iFastCanvas1;
   IStaticText * iRequestedAnimationRateStaticText;
   IStaticText * iActualRateStaticText;
   IStaticText * iStaticText1;
   IStaticText * iStaticText2;
   IStaticText * iStaticText3;
   IVBFlyText * iVBFlyText1;
   StarFieldRenderer * iStarFieldRenderer;
   FaderRenderer * iFaderRenderer;
   DiveDemo2Conn22 * conn22;
   DiveDemo2Conn10 * conn10;
   DiveDemo2Conn31 * conn31;
   DiveDemo2Conn32 * conn32;
   DiveDemo2Conn20 * conn20;
   DiveDemo2Conn11 * conn11;
   DiveDemo2Conn8 * conn8;
   DiveDemo2Conn9 * conn9;
   DiveDemo2Conn30 * conn30;
   DiveDemo2Conn21 * conn21;
   DiveDemo2Conn41 * conn41;
   DiveDemo2Conn23 * conn23;
   DiveDemo2Conn25 * conn25;
   DiveDemo2Conn27 * conn27;
   DiveDemo2Conn16 * conn16;
   DiveDemo2Conn37 * conn37;
   DiveDemo2Conn19 * conn19;

friend class DiveDemo2Conn32;
friend class DiveDemo2Conn19;

#include "DiveDemo2.hpv"
};   //DiveDemo2


/*----------------------------------------------------------------------------*/
/* Resume compiler default packing.                                           */
/*----------------------------------------------------------------------------*/
#pragma pack()

#endif

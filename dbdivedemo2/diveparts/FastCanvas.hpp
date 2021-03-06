/*******************************************************************************
* FILE NAME: FastCanvas.hpp                                                    *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class:                                                  *
*     FastCanvas- A high-performance drawing canvas                            *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _FASTCANVAS_
#define _FASTCANVAS_

class FastCanvas;

#ifndef _ICANVAS_
#include <icanvas.hpp>
#endif

class DiveBlitterHandler;
class DiveImageBuffer;
#ifndef _IRECT_
#include <irect.hpp>
#endif

#include <os2.h>

#include <mmioos2.h>

#include <fourcc.h>

#include <dive.h>

#include <ipainhdr.hpp>

#include <iexcept.hpp>

#include <ithread.hpp>

#include "DiveImageRenderer.hpp"

#include "DiveEventHandler.hpp"

#include "DiveImageBuffer.hpp"

#include "DivePaintHandler.hpp"

#include "Timer0.hpp"

class FastCanvasConn1;
class FastCanvasConn4;
class FastCanvasConn5;
class FastCanvasConn6;
#include "FastCanvas.h"


/*----------------------------------------------------------------------------*/
/* Align classes on four byte boundary.                                       */
/*----------------------------------------------------------------------------*/
#pragma pack(4)

//*****************************************************************************
// Class definition for FastCanvas
//*****************************************************************************
class FastCanvas : public ICanvas {
public:
   //---------------------------------------------------------------------------
   // Constructors / destructors
   //---------------------------------------------------------------------------
   FastCanvas(
      unsigned long id = WND_FastCanvas,
      IWindow* parent = IWindow::desktopWindow(),
      IWindow* owner = 0,
      const IRectangle& rect = defaultFramingSpec(),
      const ICanvas::Style& style = ICanvas::defaultStyle());

   virtual  ~FastCanvas();

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   static const IRectangle defaultFramingSpec();
   virtual FastCanvas & initializePart();
   FastCanvas * getCanvas1() { return this; };

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
   DivePaintHandler  * iCanvas1DivePaintHandler;
   DiveEventHandler  * iCanvas1DiveEventHandler;
   DiveBlitterHandler * iDiveBlitterHandler;
   DiveImageBuffer * iDiveImageBuffer;
   FastCanvasConn1 * conn1;
   FastCanvasConn4 * conn4;
   FastCanvasConn5 * conn5;
   FastCanvasConn6 * conn6;


#include "FastCanvas.hpv"
};   //FastCanvas


/*----------------------------------------------------------------------------*/
/* Resume compiler default packing.                                           */
/*----------------------------------------------------------------------------*/
#pragma pack()

#endif

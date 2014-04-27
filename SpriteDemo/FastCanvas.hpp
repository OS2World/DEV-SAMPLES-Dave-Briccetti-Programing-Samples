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

#ifndef _IRECT_
#include <irect.hpp>
#endif

#include "inclos2.h"

#include "mmioos2.h"
#include "fourcc.h"
#include "dive.h"

#include "ivseq.h"

#include "ipainhdr.hpp"

#include "sprite.hpp"
#include "iexcept.hpp"

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
      IWindow * parent = IWindow::desktopWindow(),
      IWindow * owner = 0,
      const IRectangle & rect = defaultFramingSpec(),
      const ICanvas::Style & style = ICanvas::defaultStyle());

   virtual  ~FastCanvas();

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   static IRectangle defaultFramingSpec();
   virtual FastCanvas & initializePart();
   FastCanvas * getCanvas() { return this; };

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

#include "FastCanvas.hpv"
};   //FastCanvas


/*----------------------------------------------------------------------------*/
/* Resume compiler default packing.                                           */
/*----------------------------------------------------------------------------*/
#pragma pack()

#endif
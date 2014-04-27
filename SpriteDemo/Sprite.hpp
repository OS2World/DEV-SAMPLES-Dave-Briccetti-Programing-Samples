/*******************************************************************************
* FILE NAME: Sprite.hpp                                                        *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class:                                                  *
*     Sprite- Sprite                                                           *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _SPRITE_
#define _SPRITE_  

class Sprite;

#ifndef _ISTDNTFY_
#include <istdntfy.hpp>
#endif

#include "iexcept.hpp"

#include "itrace.hpp"

#include "graphicfileinfo.hpp"

#include "pcxloader.hpp"

#include "imagehandler.hpp"

#include "fastcanvas.hpp"

#include "Sprite.h"


/*----------------------------------------------------------------------------*/
/* Align classes on four byte boundary.                                       */
/*----------------------------------------------------------------------------*/
#pragma pack(4)

//*****************************************************************************
// Class definition for Sprite
//*****************************************************************************
class Sprite : public IStandardNotifier {
public:
   //---------------------------------------------------------------------------
   // Constructors / destructors
   //---------------------------------------------------------------------------
   Sprite();

   virtual  ~Sprite();

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   virtual Sprite & initializePart();

   //---------------------------------------------------------------------------
   // public member data
   //---------------------------------------------------------------------------
   static const INotificationId readyId;

protected:
   //---------------------------------------------------------------------------
   // protected member functions
   //---------------------------------------------------------------------------
   virtual Boolean makeConnections();

private:

#include "Sprite.hpv"
};   //Sprite


/*----------------------------------------------------------------------------*/
/* Resume compiler default packing.                                           */
/*----------------------------------------------------------------------------*/
#pragma pack()

#endif

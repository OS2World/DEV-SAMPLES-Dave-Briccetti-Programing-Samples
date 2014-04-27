/*******************************************************************************
* FILE NAME: ImageHandler.hpp                                                  *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class:                                                  *
*     ImageHandler- Image Handler                                              *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _IMAGEHANDLER_
#define _IMAGEHANDLER_  

class ImageHandler;

#ifndef _ISTDNTFY_
#include <istdntfy.hpp>
#endif

#include "ipoint.hpp"

#include "pcxloader.hpp"

#include "ImageHandler.h"


/*----------------------------------------------------------------------------*/
/* Align classes on four byte boundary.                                       */
/*----------------------------------------------------------------------------*/
#pragma pack(4)

//*****************************************************************************
// Class definition for ImageHandler
//*****************************************************************************
class ImageHandler : public IStandardNotifier {
public:
   //---------------------------------------------------------------------------
   // Constructors / destructors
   //---------------------------------------------------------------------------
   ImageHandler();

   virtual  ~ImageHandler();

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   virtual ImageHandler & initializePart();

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

#include "ImageHandler.hpv"
};   //ImageHandler


/*----------------------------------------------------------------------------*/
/* Resume compiler default packing.                                           */
/*----------------------------------------------------------------------------*/
#pragma pack()

#endif
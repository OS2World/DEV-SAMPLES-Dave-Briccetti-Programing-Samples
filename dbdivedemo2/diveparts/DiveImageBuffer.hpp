/*******************************************************************************
* FILE NAME: DiveImageBuffer.hpp                                               *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class:                                                  *
*     DiveImageBuffer- Dive image buffer manager                               *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _DIVEIMAGEBUFFER_
#define _DIVEIMAGEBUFFER_

class DiveImageBuffer;

#ifndef _ISTDNTFY_
#include <istdntfy.hpp>
#endif

#include <os2.h>

#include <mmioos2.h>

#include <fourcc.h>

#include <dive.h>

#include <iexcept.hpp>

#include <ipoint.hpp>

#include "DiveImageBuffer.h"


/*----------------------------------------------------------------------------*/
/* Align classes on four byte boundary.                                       */
/*----------------------------------------------------------------------------*/
#pragma pack(4)

//*****************************************************************************
// Class definition for DiveImageBuffer
//*****************************************************************************
class DiveImageBuffer : public IStandardNotifier {
public:
   //---------------------------------------------------------------------------
   // Constructors / destructors
   //---------------------------------------------------------------------------
   DiveImageBuffer();

   virtual  ~DiveImageBuffer();

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   virtual DiveImageBuffer & initializePart();

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

#include "DiveImageBuffer.hpv"
};   //DiveImageBuffer


/*----------------------------------------------------------------------------*/
/* Resume compiler default packing.                                           */
/*----------------------------------------------------------------------------*/
#pragma pack()

#endif

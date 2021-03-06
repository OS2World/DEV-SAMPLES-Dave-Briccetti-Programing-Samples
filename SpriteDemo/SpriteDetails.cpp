/*******************************************************************************
* FILE NAME: SpriteDetails.cpp                                                 *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Class implementation of the class:                                         *
*     SpriteDetails- Details view of sprite info                               *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _IPOINT_
#include <ipoint.hpp>
#endif

#ifndef _ICNRCOL_
#include <icnrcol.hpp>
#endif

#ifndef _IRECT_
#include <irect.hpp>
#endif

#ifndef _INOTIFEV_
#include <inotifev.hpp>
#endif

#ifndef _IOBSERVR_
#include <iobservr.hpp>
#endif

#ifndef _ISTDNTFY_
#include <istdntfy.hpp>
#endif

#ifndef _SPRITEDETAILS_
#include "SpriteDetails.hpp"
#endif

#ifndef _IVBDEFS_
#include <ivbdefs.h>
#endif

#ifndef _ITRACE_
#include <itrace.hpp>
#endif


//------------------------------------------------------------------------------
// SpriteDetailsVBContainerControlCnrObj :: SpriteDetailsVBContainerControlCnrObj
//------------------------------------------------------------------------------
#pragma export (SpriteDetailsVBContainerControlCnrObj::SpriteDetailsVBContainerControlCnrObj(Sprite&))
SpriteDetailsVBContainerControlCnrObj::SpriteDetailsVBContainerControlCnrObj(Sprite& anObject)
 :IVBContainerObject(anObject.filenameWithoutPath(), ISystemPointerHandle(ISystemPointerHandle::warning)),
      inumFramesAsText(anObject.numFramesAsText()), iactiveFrameAsText(anObject.activeFrameAsText()), ipositionAsText(anObject.positionAsText()), pRealObject(anObject)
{
   enableDataUpdate();
   handleNotificationsFor(pRealObject);
}


//------------------------------------------------------------------------------
// SpriteDetailsVBContainerControlCnrObj :: SpriteDetailsVBContainerControlCnrObj
//------------------------------------------------------------------------------
#pragma export (SpriteDetailsVBContainerControlCnrObj::SpriteDetailsVBContainerControlCnrObj(SpriteDetailsVBContainerControlCnrObj&))
SpriteDetailsVBContainerControlCnrObj::SpriteDetailsVBContainerControlCnrObj(SpriteDetailsVBContainerControlCnrObj& anObject)
 :IVBContainerObject(anObject.iconText(), anObject.icon()),
      inumFramesAsText(anObject.inumFramesAsText), iactiveFrameAsText(anObject.iactiveFrameAsText), ipositionAsText(anObject.ipositionAsText), pRealObject(anObject.pRealObject)
{  }


//------------------------------------------------------------------------------
// SpriteDetailsVBContainerControlCnrObj :: ~SpriteDetailsVBContainerControlCnrObj
//------------------------------------------------------------------------------
#pragma export (SpriteDetailsVBContainerControlCnrObj::~SpriteDetailsVBContainerControlCnrObj())
SpriteDetailsVBContainerControlCnrObj::~SpriteDetailsVBContainerControlCnrObj()
{
   this->stopHandlingNotificationsFor(pRealObject);
}


//------------------------------------------------------------------------------
// SpriteDetailsVBContainerControlCnrObj :: refreshFromObject
//------------------------------------------------------------------------------
#pragma export (SpriteDetailsVBContainerControlCnrObj::refreshFromObject())
IVBContainerObject & SpriteDetailsVBContainerControlCnrObj::refreshFromObject()
{
   setIconText(pRealObject.filenameWithoutPath());
   setIcon(ISystemPointerHandle(ISystemPointerHandle::warning));
   inumFramesAsText = pRealObject.numFramesAsText();
   iactiveFrameAsText = pRealObject.activeFrameAsText();
   ipositionAsText = pRealObject.positionAsText();
   return *this;
}


//------------------------------------------------------------------------------
// SpriteDetailsVBContainerControlCnrObj :: updateToObject
//------------------------------------------------------------------------------
IVBContainerObject & SpriteDetailsVBContainerControlCnrObj::updateToObject()
{
   return *this;
}


//------------------------------------------------------------------------------
// SpriteDetailsVBContainerControlCnrObj :: operator=
//------------------------------------------------------------------------------
SpriteDetailsVBContainerControlCnrObj& SpriteDetailsVBContainerControlCnrObj::operator=(const SpriteDetailsVBContainerControlCnrObj& anObject)
{
   if (this == &anObject) {
      return *this;
      }
   IVBContainerObject::operator=(anObject);
   inumFramesAsText = anObject.inumFramesAsText;
   iactiveFrameAsText = anObject.iactiveFrameAsText;
   ipositionAsText = anObject.ipositionAsText;
   return *this;
}



#pragma export (SpriteDetails::readyId)
const INotificationId SpriteDetails::readyId = "SpriteDetails::readyId";

//------------------------------------------------------------------------------
// SpriteDetails :: defaultFramingSpec
//------------------------------------------------------------------------------
#pragma export (SpriteDetails::defaultFramingSpec())
const IRectangle SpriteDetails::defaultFramingSpec()
{
   return(IRectangle(IPoint(30,257),ISize(494, 219)));
}


//------------------------------------------------------------------------------
// SpriteDetails :: defaultStyle
//------------------------------------------------------------------------------
#pragma export (SpriteDetails::defaultStyle())
const IContainerControl::Style SpriteDetails::defaultStyle()
{
   return(IContainerControl::defaultStyle() & ~IContainerControl::readOnly | IContainerControl::verifyPointers | IContainerControl::singleSelection);
}


//------------------------------------------------------------------------------
// SpriteDetails :: SpriteDetails
//------------------------------------------------------------------------------
#pragma export (SpriteDetails::SpriteDetails(unsigned long, IWindow*, IWindow*, const IRectangle&, const IContainerControl::Style&, const IContainerControl::Attribute&))
SpriteDetails::SpriteDetails(
      unsigned long id, 
      IWindow* parent, 
      IWindow* owner, 
      const IRectangle& rect, 
      const IContainerControl::Style& style, 
      const IContainerControl::Attribute& attribute)
   : IVBContainerControl< Sprite*, IVSequence<Sprite*>, SpriteDetailsVBContainerControlCnrObj >(id, parent, owner, rect, style, attribute)
{
   iContainerColumn1 = new IContainerColumn(SpriteDetailsVBContainerControlCnrObj::iconTextOffset(), IContainerColumn::defaultHeadingStyle ( ), (IContainerColumn::defaultDataStyle ( )) & ~IContainerColumn::icon | IContainerColumn::string);
   iContainerColumn2 = new IContainerColumn(offsetof(SpriteDetailsVBContainerControlCnrObj, inumFramesAsText), IContainerColumn::defaultHeadingStyle() | IContainerColumn::readOnlyHeading, (IContainerColumn::defaultDataStyle() | IContainerColumn::number | IContainerColumn::readOnly) & ~IContainerColumn::icon | IContainerColumn::string);
   iContainerColumn3 = new IContainerColumn(offsetof(SpriteDetailsVBContainerControlCnrObj, iactiveFrameAsText), IContainerColumn::defaultHeadingStyle() | IContainerColumn::readOnlyHeading, (IContainerColumn::defaultDataStyle() | IContainerColumn::number | IContainerColumn::readOnly) & ~IContainerColumn::icon | IContainerColumn::string);
   iContainerColumn4 = new IContainerColumn(offsetof(SpriteDetailsVBContainerControlCnrObj, ipositionAsText), IContainerColumn::defaultHeadingStyle ( ), (IContainerColumn::defaultDataStyle() | IContainerColumn::readOnly) & ~IContainerColumn::icon | IContainerColumn::string);

   this->setRefreshOn(true);
   this->showDetailsView();
   this->setMinimumSize(ISize(277, 150));
   this->showTitle(true);
   this->showTitleSeparator(true);
   this->setTitle("Sprite Details");
   this->addColumn(iContainerColumn1);
   this->addColumn(iContainerColumn2);
   this->addColumn(iContainerColumn3);
   this->addColumn(iContainerColumn4);
   iContainerColumn1->setHeadingText("Filename");
   iContainerColumn1->setDisplayWidth(100);
   iContainerColumn2->setHeadingText("Frames");
   iContainerColumn2->setDisplayWidth(50);
   iContainerColumn3->setHeadingText("Active");
   iContainerColumn3->setDisplayWidth(50);
   iContainerColumn4->setHeadingText("Position");
   iContainerColumn4->setDisplayWidth(50);
}     //end constructor


//------------------------------------------------------------------------------
// SpriteDetails :: ~SpriteDetails
//------------------------------------------------------------------------------
#pragma export (SpriteDetails::~SpriteDetails())
SpriteDetails::~SpriteDetails()
{

   delete iContainerColumn1;
   delete iContainerColumn2;
   delete iContainerColumn3;
   delete iContainerColumn4;
}

//------------------------------------------------------------------------------
// SpriteDetails :: initializePart
//------------------------------------------------------------------------------
#pragma export (SpriteDetails::initializePart())
SpriteDetails & SpriteDetails::initializePart()
{
   makeConnections();
   notifyObservers(INotificationEvent(readyId, *this));
   return *this;
}


//------------------------------------------------------------------------------
// SpriteDetails :: makeConnections
//------------------------------------------------------------------------------
#pragma export (SpriteDetails::makeConnections())
Boolean SpriteDetails::makeConnections()
{
   this->enableNotification();

   unsigned long id = this->id();
   return true;
}



#include "SpriteDetails.cpv"

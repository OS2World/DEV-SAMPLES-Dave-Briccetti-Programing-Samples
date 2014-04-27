/*******************************************************************************
* FILE NAME: SpriteDropHandler.cpp                                             *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Class implementation of the class:                                         *
*     SpriteDropHandler- Handle dropping files into demo                       *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _INOTIFEV_
#include <inotifev.hpp>
#endif

#ifndef _IOBSERVR_
#include <iobservr.hpp>
#endif

#ifndef _ISTDNTFY_
#include <istdntfy.hpp>
#endif

#ifndef _SPRITEDROPHANDLER_
#include "SpriteDropHandler.hpp"
#endif

#ifndef _IVBDEFS_
#include <ivbdefs.h>
#endif

#ifndef _ITRACE_
#include <itrace.hpp>
#endif


#pragma export (SpriteDropHandler::readyId)
const INotificationId SpriteDropHandler::readyId = "SpriteDropHandler::readyId";
//------------------------------------------------------------------------------
// SpriteDropHandler :: SpriteDropHandler
//------------------------------------------------------------------------------
#pragma export (SpriteDropHandler::SpriteDropHandler())
SpriteDropHandler::SpriteDropHandler()
{

}     //end constructor


//------------------------------------------------------------------------------
// SpriteDropHandler :: ~SpriteDropHandler
//------------------------------------------------------------------------------
#pragma export (SpriteDropHandler::~SpriteDropHandler())
SpriteDropHandler::~SpriteDropHandler()
{

}

//------------------------------------------------------------------------------
// SpriteDropHandler :: initializePart
//------------------------------------------------------------------------------
#pragma export (SpriteDropHandler::initializePart())
SpriteDropHandler & SpriteDropHandler::initializePart()
{
   makeConnections();
   notifyObservers(INotificationEvent(readyId, *this));
   return *this;
}


//------------------------------------------------------------------------------
// SpriteDropHandler :: makeConnections
//------------------------------------------------------------------------------
#pragma export (SpriteDropHandler::makeConnections())
Boolean SpriteDropHandler::makeConnections()
{
   this->enableNotification();

   return true;
}


#include "SpriteDropHandler.cpv"

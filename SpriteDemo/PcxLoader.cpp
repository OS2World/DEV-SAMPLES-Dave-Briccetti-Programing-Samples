/*******************************************************************************
* FILE NAME: PcxLoader.cpp                                                     *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Class implementation of the class:                                         *
*     PcxLoader- Loads PCX files                                               *
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

#ifndef _PCXLOADER_
#include "PcxLoader.hpp"
#endif

#ifndef _IVBDEFS_
#include <ivbdefs.h>
#endif

#ifndef _ITRACE_
#include <itrace.hpp>
#endif


#pragma export (PcxLoader::readyId)
const INotificationId PcxLoader::readyId = "PcxLoader::readyId";
//------------------------------------------------------------------------------
// PcxLoader :: PcxLoader
//------------------------------------------------------------------------------
#pragma export (PcxLoader::PcxLoader())
PcxLoader::PcxLoader()
{

}     //end constructor


//------------------------------------------------------------------------------
// PcxLoader :: ~PcxLoader
//------------------------------------------------------------------------------
#pragma export (PcxLoader::~PcxLoader())
PcxLoader::~PcxLoader()
{
   delete iPcxFile;

}

//------------------------------------------------------------------------------
// PcxLoader :: initializePart
//------------------------------------------------------------------------------
#pragma export (PcxLoader::initializePart())
PcxLoader & PcxLoader::initializePart()
{
   makeConnections();
   notifyObservers(INotificationEvent(readyId, *this));
   return *this;
}


//------------------------------------------------------------------------------
// PcxLoader :: makeConnections
//------------------------------------------------------------------------------
#pragma export (PcxLoader::makeConnections())
Boolean PcxLoader::makeConnections()
{
   this->enableNotification();

   return true;
}


#include "PcxLoader.cpv"

/*******************************************************************************
* FILE NAME: FastCanvas.cpp                                                    *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Class implementation of the class:                                         *
*     FastCanvas- A high-performance drawing canvas                            *
* ---------------------------------------------------------------------------- *
* Warning: This file was generated by the VisualAge C++ Visual Builder.        *
* Modifications to this source file will be lost when the part is regenerated. *
*******************************************************************************/
#ifndef _ICANVAS_
#include <icanvas.hpp>
#endif

#ifndef _IPOINT_
#include <ipoint.hpp>
#endif

#ifndef _DIVEBLITTERHANDLER_
#include "DiveBlitterHandler.hpp"
#endif

#ifndef _DIVEIMAGEBUFFER_
#include "DiveImageBuffer.hpp"
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

#ifndef _FASTCANVAS_
#include "FastCanvas.hpp"
#endif

#ifndef _IVBDEFS_
#include <ivbdefs.h>
#endif

#ifndef _ITRACE_
#include <itrace.hpp>
#endif


//*****************************************************************************
// Class definition for FastCanvasConn1
//*****************************************************************************
class FastCanvasConn1 : public IObserver {
public:
   virtual  ~FastCanvasConn1(){};

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   void initialize(ICanvas * aSource, DiveBlitterHandler * aTarget)
      {source = aSource; target = aTarget; aligning = false; };
   void setSource()
      {      };
   void setTarget()
      {
      if (aligning==false) {
         IFUNCTRACE_DEVELOP();
         ITRACE_DEVELOP(" firing connection : Canvas1(this) to DiveBlitterHandler(window))");
         ITRACE_DEVELOP(" setting target from source ");
         aligning = true;
         try {target->setWindow(source);}
         catch (IException& exc) {};
         aligning = false;
         }
      };

protected:
   //---------------------------------------------------------------------------
   // protected member functions
   //---------------------------------------------------------------------------
   virtual IObserver & dispatchNotificationEvent(const INotificationEvent & anEvent)
      {
      if (anEvent.notificationId() == VBINITIALIZEID) setTarget();
      if ((anEvent.notificationId() == DiveBlitterHandler::windowId) && (target == &anEvent.notifier()))
         setSource();  /* set source to target value */
      return(*this);
      };

private:
   //---------------------------------------------------------------------------
   // private member data
   //---------------------------------------------------------------------------
   ICanvas * source;
   DiveBlitterHandler * target;
   Boolean aligning;


};   //FastCanvasConn1


//*****************************************************************************
// Class definition for FastCanvasConn4
//*****************************************************************************
class FastCanvasConn4 : public IObserver {
public:
   virtual  ~FastCanvasConn4(){};

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   void initialize(FastCanvas * aSource, DiveImageBuffer * aTarget)
      {source = aSource; target = aTarget; aligning = false; };
   void setSource()
      {
      if (aligning==false) {
         IFUNCTRACE_DEVELOP();
         ITRACE_DEVELOP(" firing connection : (diveHandle) to DiveImageBuffer(diveHandle))");
         ITRACE_DEVELOP(" setting source from target ");
         aligning = true;
         try {source->setDiveHandle(target->diveHandle());}
         catch (IException& exc) {};
         aligning = false;
         }
      };
   void setTarget()
      {
      if (aligning==false) {
         IFUNCTRACE_DEVELOP();
         ITRACE_DEVELOP(" firing connection : (diveHandle) to DiveImageBuffer(diveHandle))");
         ITRACE_DEVELOP(" setting target from source ");
         aligning = true;
         try {target->setDiveHandle(source->diveHandle());}
         catch (IException& exc) {};
         aligning = false;
         }
      };

protected:
   //---------------------------------------------------------------------------
   // protected member functions
   //---------------------------------------------------------------------------
   virtual IObserver & dispatchNotificationEvent(const INotificationEvent & anEvent)
      {
      if (anEvent.notificationId() == VBINITIALIZEID) setTarget();
      if ((anEvent.notificationId() == FastCanvas::diveHandleId) && (source == &anEvent.notifier()))
         setTarget();  /* set target to source value */
      else
      if ((anEvent.notificationId() == DiveImageBuffer::diveHandleId) && (target == &anEvent.notifier()))
         setSource();  /* set source to target value */
      return(*this);
      };

private:
   //---------------------------------------------------------------------------
   // private member data
   //---------------------------------------------------------------------------
   FastCanvas * source;
   DiveImageBuffer * target;
   Boolean aligning;


};   //FastCanvasConn4


//*****************************************************************************
// Class definition for FastCanvasConn5
//*****************************************************************************
class FastCanvasConn5 : public IObserver {
public:
   virtual  ~FastCanvasConn5(){};

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   void initialize(FastCanvas * aSource, DiveBlitterHandler * aTarget)
      {source = aSource; target = aTarget; aligning = false; };
   void setSource()
      {
      if (aligning==false) {
         IFUNCTRACE_DEVELOP();
         ITRACE_DEVELOP(" firing connection : (diveHandle) to DiveBlitterHandler(diveHandle))");
         ITRACE_DEVELOP(" setting source from target ");
         aligning = true;
         try {source->setDiveHandle(target->diveHandle());}
         catch (IException& exc) {};
         aligning = false;
         }
      };
   void setTarget()
      {
      if (aligning==false) {
         IFUNCTRACE_DEVELOP();
         ITRACE_DEVELOP(" firing connection : (diveHandle) to DiveBlitterHandler(diveHandle))");
         ITRACE_DEVELOP(" setting target from source ");
         aligning = true;
         try {target->setDiveHandle(source->diveHandle());}
         catch (IException& exc) {};
         aligning = false;
         }
      };

protected:
   //---------------------------------------------------------------------------
   // protected member functions
   //---------------------------------------------------------------------------
   virtual IObserver & dispatchNotificationEvent(const INotificationEvent & anEvent)
      {
      if (anEvent.notificationId() == VBINITIALIZEID) setTarget();
      if ((anEvent.notificationId() == FastCanvas::diveHandleId) && (source == &anEvent.notifier()))
         setTarget();  /* set target to source value */
      else
      if ((anEvent.notificationId() == DiveBlitterHandler::diveHandleId) && (target == &anEvent.notifier()))
         setSource();  /* set source to target value */
      return(*this);
      };

private:
   //---------------------------------------------------------------------------
   // private member data
   //---------------------------------------------------------------------------
   FastCanvas * source;
   DiveBlitterHandler * target;
   Boolean aligning;


};   //FastCanvasConn5


//*****************************************************************************
// Class definition for FastCanvasConn6
//*****************************************************************************
class FastCanvasConn6 : public IObserver {
public:
   virtual  ~FastCanvasConn6(){};

   //---------------------------------------------------------------------------
   // public member functions
   //---------------------------------------------------------------------------
   void initialize(ICanvas * aSource, DiveImageBuffer * aTarget)
      {source = aSource; target = aTarget; aligning = false; };
   void setSource()
      {
      if (aligning==false) {
         IFUNCTRACE_DEVELOP();
         ITRACE_DEVELOP(" firing connection : Canvas1(size) to DiveImageBuffer(size))");
         ITRACE_DEVELOP(" setting source from target ");
         aligning = true;
         try {source->sizeTo(target->size());}
         catch (IException& exc) {};
         aligning = false;
         }
      };
   void setTarget()
      {
      if (aligning==false) {
         IFUNCTRACE_DEVELOP();
         ITRACE_DEVELOP(" firing connection : Canvas1(size) to DiveImageBuffer(size))");
         ITRACE_DEVELOP(" setting target from source ");
         aligning = true;
         try {target->setSize(source->size());}
         catch (IException& exc) {};
         aligning = false;
         }
      };

protected:
   //---------------------------------------------------------------------------
   // protected member functions
   //---------------------------------------------------------------------------
   virtual IObserver & dispatchNotificationEvent(const INotificationEvent & anEvent)
      {
      if (anEvent.notificationId() == VBINITIALIZEID) setTarget();
      if ((anEvent.notificationId() == ICanvas::sizeId) && (source == &anEvent.notifier()))
         setTarget();  /* set target to source value */
      else
      if ((anEvent.notificationId() == DiveImageBuffer::sizeId) && (target == &anEvent.notifier()))
         setSource();  /* set source to target value */
      return(*this);
      };

private:
   //---------------------------------------------------------------------------
   // private member data
   //---------------------------------------------------------------------------
   ICanvas * source;
   DiveImageBuffer * target;
   Boolean aligning;


};   //FastCanvasConn6


#pragma export (FastCanvas::readyId)
const INotificationId FastCanvas::readyId = "FastCanvas::readyId";

//------------------------------------------------------------------------------
// FastCanvas :: defaultFramingSpec
//------------------------------------------------------------------------------
#pragma export (FastCanvas::defaultFramingSpec())
const IRectangle FastCanvas::defaultFramingSpec()
{
   return(IRectangle(IPoint(80,361),ISize(100, 100)));
}


//------------------------------------------------------------------------------
// FastCanvas :: FastCanvas
//------------------------------------------------------------------------------
#pragma export (FastCanvas::FastCanvas(unsigned long, IWindow*, IWindow*, const IRectangle&, const ICanvas::Style&))
FastCanvas::FastCanvas(
      unsigned long id, 
      IWindow* parent, 
      IWindow* owner, 
      const IRectangle& rect, 
      const ICanvas::Style& style)
   : ICanvas(id, parent, owner, rect, style)
{
   iDiveBlitterHandler = new DiveBlitterHandler();
   iDiveImageBuffer = new DiveImageBuffer();

   conn1 = new FastCanvasConn1();
   conn4 = new FastCanvasConn4();
   conn5 = new FastCanvasConn5();
   conn6 = new FastCanvasConn6();

   iCanvas1DivePaintHandler = new DivePaintHandler (&drawingSerializer);
   iCanvas1DivePaintHandler->handleEventsFor(this);
   iCanvas1DiveEventHandler = new DiveEventHandler (iDiveBlitterHandler);
   iCanvas1DiveEventHandler->handleEventsFor(this);
   this->setMinimumSize(ISize(100, 100));
   userConstructor();
}     //end constructor


//------------------------------------------------------------------------------
// FastCanvas :: ~FastCanvas
//------------------------------------------------------------------------------
#pragma export (FastCanvas::~FastCanvas())
FastCanvas::~FastCanvas()
{
   userDestructor();
   conn1->stopHandlingNotificationsFor(*this);
   conn1->stopHandlingNotificationsFor(*iDiveBlitterHandler);
   conn4->stopHandlingNotificationsFor(*this);
   conn4->stopHandlingNotificationsFor(*iDiveImageBuffer);
   conn5->stopHandlingNotificationsFor(*this);
   conn5->stopHandlingNotificationsFor(*iDiveBlitterHandler);
   conn6->stopHandlingNotificationsFor(*this);
   conn6->stopHandlingNotificationsFor(*iDiveImageBuffer);

   delete conn1;
   delete conn4;
   delete conn5;
   delete conn6;

   iCanvas1DivePaintHandler->stopHandlingEventsFor(this);
   delete iCanvas1DivePaintHandler;
   iCanvas1DiveEventHandler->stopHandlingEventsFor(this);
   delete iCanvas1DiveEventHandler;

   delete iDiveBlitterHandler;
   delete iDiveImageBuffer;
}

//------------------------------------------------------------------------------
// FastCanvas :: initializePart
//------------------------------------------------------------------------------
#pragma export (FastCanvas::initializePart())
FastCanvas & FastCanvas::initializePart()
{
   makeConnections();
   notifyObservers(INotificationEvent(readyId, *this));
   return *this;
}


//------------------------------------------------------------------------------
// FastCanvas :: makeConnections
//------------------------------------------------------------------------------
#pragma export (FastCanvas::makeConnections())
Boolean FastCanvas::makeConnections()
{
   this->enableNotification();
   iDiveBlitterHandler->enableNotification();
   iDiveImageBuffer->enableNotification();

   unsigned long id = this->id();
   conn1->initialize(this, iDiveBlitterHandler);
   conn1->handleNotificationsFor(*this);
   conn1->handleNotificationsFor(*iDiveBlitterHandler);
   conn4->initialize(this, iDiveImageBuffer);
   conn4->handleNotificationsFor(*this);
   conn4->handleNotificationsFor(*iDiveImageBuffer);
   conn5->initialize(this, iDiveBlitterHandler);
   conn5->handleNotificationsFor(*this);
   conn5->handleNotificationsFor(*iDiveBlitterHandler);
   conn6->initialize(this, iDiveImageBuffer);
   conn6->handleNotificationsFor(*this);
   conn6->handleNotificationsFor(*iDiveImageBuffer);

   conn1->setTarget();
   conn4->setTarget();
   conn5->setTarget();
   conn6->setTarget();
   return true;
}



#include "FastCanvas.cpv"
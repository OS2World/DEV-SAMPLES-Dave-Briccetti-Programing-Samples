/* 
    UICL Throw Error Macros Demo - Dave Briccetti (daveb@davebsoft.com), Jan. 1995.
    
    This tip demonstrates the use of several handy error-reporting macros 
    included in the C Set++ User Interface Class Library:

        IASSERTPARM         Check the validity of parameters passed to functions
        IASSERTSTATE        Ensure an object's state is valid for a function call
        ITHROWGUIERROR      Use when PM function fails
        ITHROWSYSTEMERROR   Use when a system function fails    
*/

#define INCL_DOSMEMMGR
#define INCL_DOSERRORS
#define INCL_WINWINDOWMGR
#include <os2.h>
#include <icmdhdr.hpp>                      // Command handler
#include <iexcept.hpp>                      // Exceptions
#include <iframe.hpp>                       // Frame
#include "idres.h"

class AppCommandHandler : public ICommandHandler    // Command handler for menu
{
    virtual Boolean command (ICommandEvent & cmdEvent);
};

void main()                     
{
    IFrameWindow frame (IDFRAME_MAIN,       // Create frame window with menu
        IFrameWindow::defaultStyle() | IFrameWindow::menuBar);
    AppCommandHandler appCommandHandler;    // Create a command handler and 
    appCommandHandler.handleEventsFor (&frame); // assign it to the frame
    frame.setFocus ();                      // Set focus to the frame window
    frame.show ();                          // Show the frame
    IApplication::current().run();          // Run the application
} 

static void CheckParameter (int Parm)       // Function which checks parmeter
{
    IASSERTPARM (Parm > 0);                 // Throw exception if false
}

AppCommandHandler :: command (ICommandEvent & cmdEvent)
{
    static const BOOL           fSystemReady = FALSE;
    static const IWindowHandle  windowHandleBad     = 999;
    static const PVOID          pvBadAddress        = (PVOID) 999;
    try                                     // Catch all the errors we throw
    {
        switch (cmdEvent.commandId())
        {
            case IDM_ASSERTPARM:            // Pass bad parm to function
                CheckParameter (0);         
                break;
            case IDM_ASSERTSTATE:           // Check state before proceeding
                IASSERTSTATE (fSystemReady); 
                break;
            case IDM_GUI:                   // Make a bad PM call 
                if (! WinShowWindow (windowHandleBad, TRUE))
                    ITHROWGUIERROR ("WinShowWindow");
                break;
            case IDM_CP:                    // Make a bad system call
                const APIRET rc = DosFreeMem (pvBadAddress);
                if (rc != NO_ERROR)
                    ITHROWSYSTEMERROR (rc, "DosFreeMem",
                        IErrorInfo::accessError, IException::recoverable);
                break;
        }
    }
    catch (const IException & except) {}    
    return true;
}

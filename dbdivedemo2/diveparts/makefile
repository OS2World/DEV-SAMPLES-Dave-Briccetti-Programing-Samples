# makefile
# Created by IBM WorkFrame/2 MakeMake at 15:35:27 on 16 Jan 1997
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker
#  MapSym::Map Symbols
#  Lib::Import Lib

.SUFFIXES: .LIB .cpp .dll .obj .sym 

.all: \
    .\divepart.sym \
    .\divepart.LIB

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DINCL_PM /DINCL_DOS /DINCL_DOSERRORS /Q /Wcndcnscnvdclenuextgengotinilanobsordporprorearettruunduni /V"@#Dave Briccetti Software Consulting:0.5#@DBDiveParts" /O /N20 /Gm /Gd /Ge- /G5 /Oi /C %s

{F:\devel\diveparts}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DINCL_PM /DINCL_DOS /DINCL_DOSERRORS /Q /Wcndcnscnvdclenuextgengotinilanobsordporprorearettruunduni /V"@#Dave Briccetti Software Consulting:0.5#@DBDiveParts" /O /N20 /Gm /Gd /Ge- /G5 /Oi /C %s

.dll.sym:
    @echo " MapSym::Map Symbols "
    mapsym.exe %|fF.map

{F:\devel\diveparts}.dll.sym:
    @echo " MapSym::Map Symbols "
    mapsym.exe %|fF.map

.dll.LIB:
    @echo " Lib::Import Lib "
    implib.exe %|dpfF.LIB %s

{F:\devel\diveparts}.dll.LIB:
    @echo " Lib::Import Lib "
    implib.exe %|dpfF.LIB %s

.\divepart.dll: \
    .\FastCanvas.obj \
    .\Timer0.obj \
    .\DiveBlitterHandler.obj \
    .\DiveEventHandler.obj \
    .\DiveImageBuffer.obj \
    .\DiveImageRenderer.obj \
    .\DivePaintHandler.obj \
    {$(LIB)}os2386.lib \
    {$(LIB)}mmpm2.lib \
    {$(LIB)}diveparts.def
    @echo " Link::Linker "
    icc.exe @<<
    /DINCL_PM
     /DINCL_DOS
     /DINCL_DOSERRORS
     /Tdp /Q 
     /Wcndcnscnvdclenuextgengotinilanobsordporprorearettruunduni 
     /V"@#Dave Briccetti Software Consulting:0.5#@DBDiveParts" 
     /O /N20 /Gm /Gd /Ge- /G5 
     /Oi 
     /B" /pmtype:pm /optfunc /nologo /m"
     /Fedivepart.dll 
     os2386.lib 
     mmpm2.lib 
     diveparts.def
     .\FastCanvas.obj
     .\Timer0.obj
     .\DiveBlitterHandler.obj
     .\DiveEventHandler.obj
     .\DiveImageBuffer.obj
     .\DiveImageRenderer.obj
     .\DivePaintHandler.obj
<<

.\FastCanvas.obj: \
    F:\devel\diveparts\FastCanvas.cpp \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.hpp \
    {F:\devel\diveparts;$(INCLUDE);}os2.h \
    {F:\devel\diveparts;$(INCLUDE);}tmr0_ioc.h \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.h \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.h \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hppcst \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hppcst \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.inl \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.inl \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.cpv \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.cppcst

.\DivePaintHandler.obj: \
    F:\devel\diveparts\DivePaintHandler.cpp \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.hpp \
    {F:\devel\diveparts;$(INCLUDE);}os2.h \
    {F:\devel\diveparts;$(INCLUDE);}tmr0_ioc.h \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.h \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.h \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hppcst \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hppcst \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.inl \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.inl \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.cpv \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.cppcst

.\DiveImageRenderer.obj: \
    F:\devel\diveparts\DiveImageRenderer.cpp \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.hpp \
    {F:\devel\diveparts;$(INCLUDE);}os2.h \
    {F:\devel\diveparts;$(INCLUDE);}tmr0_ioc.h \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.h \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.h \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hppcst \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hppcst \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.inl \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.inl \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.cpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.cppcst

.\DiveImageBuffer.obj: \
    F:\devel\diveparts\DiveImageBuffer.cpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hppcst \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.inl \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.cpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.cppcst

.\DiveEventHandler.obj: \
    F:\devel\diveparts\DiveEventHandler.cpp \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.hpp \
    {F:\devel\diveparts;$(INCLUDE);}os2.h \
    {F:\devel\diveparts;$(INCLUDE);}tmr0_ioc.h \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.h \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.cppcst \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveEventHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.h \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageRenderer.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DivePaintHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.hppcst \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.hppcst \
    {F:\devel\diveparts;$(INCLUDE);}FastCanvas.inl \
    {F:\devel\diveparts;$(INCLUDE);}DiveImageBuffer.inl

.\DiveBlitterHandler.obj: \
    F:\devel\diveparts\DiveBlitterHandler.cpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.hpp \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.cpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.h \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.hpv \
    {F:\devel\diveparts;$(INCLUDE);}DiveBlitterHandler.cppcst

.\Timer0.obj: \
    F:\devel\diveparts\Timer0.cpp \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.hpp \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.cpv \
    {F:\devel\diveparts;$(INCLUDE);}os2.h \
    {F:\devel\diveparts;$(INCLUDE);}tmr0_ioc.h \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.h \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.hpv \
    {F:\devel\diveparts;$(INCLUDE);}Timer0.cppcst

.\divepart.sym: \
    .\divepart.dll

.\divepart.LIB: \
    .\divepart.dll

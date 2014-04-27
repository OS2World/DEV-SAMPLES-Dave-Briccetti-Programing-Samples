# makefile
# Created by IBM WorkFrame/2 MakeMake at 15:11:06 on 16 Jan 1997
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker
#  Bind::Resource Bind
#  Compile::Resource Precompile
#  Compile::Resource Compiler
#  MapSym::Map Symbols

.SUFFIXES: .cpp .exe .map .obj .rc .rcx .res .sym 

.all: \
    .\DiveDemo2.sym

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DINCL_PM /DINCL_DOS /Wcndcnscnvdclenuextgengotinilanobsordporprorearettruunduni /Tx /O /Gm /Gd /G5 /Tm /C %s

{F:\devel\DiveDemo2}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DINCL_PM /DINCL_DOS /Wcndcnscnvdclenuextgengotinilanobsordporprorearettruunduni /Tx /O /Gm /Gd /G5 /Tm /C %s

.rcx.rc:
    @echo " Compile::Resource Precompile "
    icc.exe -c /Pc+ /Pe+ /Pd /I. %s > %|dpfF.rc

{F:\devel\DiveDemo2}.rcx.rc:
    @echo " Compile::Resource Precompile "
    icc.exe -c /Pc+ /Pe+ /Pd /I. %s > %|dpfF.rc

.rc.res:
    @echo " Compile::Resource Compiler "
    rc.exe -r %s %|dpfF.RES

{F:\devel\DiveDemo2}.rc.res:
    @echo " Compile::Resource Compiler "
    rc.exe -r %s %|dpfF.RES

.exe.sym:
    @echo " MapSym::Map Symbols "
    mapsym.exe %|fF.map

{F:\devel\DiveDemo2}.exe.sym:
    @echo " MapSym::Map Symbols "
    mapsym.exe %|fF.map

.map.sym:
    @echo " MapSym::Map Symbols "
    mapsym.exe %|fF.map

{F:\devel\DiveDemo2}.map.sym:
    @echo " MapSym::Map Symbols "
    mapsym.exe %|fF.map

.\DiveDemo2.exe: \
    .\StarFieldRenderer.obj \
    .\vbmain.obj \
    .\DiveDemo2.obj \
    .\FaderRenderer.obj \
    .\Star.obj \
    .\DiveDemo2.res \
    {$(LIB)}os2386.lib \
    {$(LIB)}mmpm2.lib \
    {$(LIB)}divepart.lib
    @echo " Link::Linker "
    @echo " Bind::Resource Bind "
    icc.exe @<<
    /DINCL_PM
     /DINCL_DOS
     /Tdp 
     /Wcndcnscnvdclenuextgengotinilanobsordporprorearettruunduni 
     /Tx 
     /O /Gm /Gd /G5 /Tm 
     /B" /pmtype:pm /m"
     /FeDiveDemo2.exe 
     os2386.lib 
     mmpm2.lib 
     divepart.lib 
     .\StarFieldRenderer.obj
     .\vbmain.obj
     .\DiveDemo2.obj
     .\FaderRenderer.obj
     .\Star.obj
<<
    rc.exe .\DiveDemo2.res DiveDemo2.exe

.\StarFieldRenderer.obj: \
    F:\devel\DiveDemo2\StarFieldRenderer.cpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}os2.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}StarFieldRenderer.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveImageRenderer.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}IPoint.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}star.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}StarFieldRenderer.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}StarFieldRenderer.hpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}itrace.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}iexcept.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.hpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}StarFieldRenderer.hppcst \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.hppcst \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.inl \
    {F:\devel\DiveDemo2;$(INCLUDE);}StarFieldRenderer.cpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}StarFieldRenderer.cppcst

.\Star.obj: \
    F:\devel\DiveDemo2\Star.cpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}os2.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}IPoint.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}star.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}itrace.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}iexcept.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.hpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.hppcst \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.inl \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.cpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.cppcst

.\FaderRenderer.obj: \
    F:\devel\DiveDemo2\FaderRenderer.cpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}os2.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}FaderRenderer.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveImageRenderer.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}FaderRenderer.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}FaderRenderer.hpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}FaderRenderer.hppcst \
    {F:\devel\DiveDemo2;$(INCLUDE);}FaderRenderer.cpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}FaderRenderer.cppcst

.\DiveDemo2.obj: \
    F:\devel\DiveDemo2\DiveDemo2.cpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveDemo2.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}os2.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}stdlib.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}time.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveDemo2.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveDemo2.hpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}FastCanvas.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}StarFieldRenderer.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}FaderRenderer.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveDemo2.cpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveImageRenderer.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}IPoint.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}star.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}StarFieldRenderer.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}StarFieldRenderer.hpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}FaderRenderer.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}FaderRenderer.hpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveDemo2.cppcst \
    {F:\devel\DiveDemo2;$(INCLUDE);}itrace.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}iexcept.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.hpv \
    {F:\devel\DiveDemo2;$(INCLUDE);}StarFieldRenderer.hppcst \
    {F:\devel\DiveDemo2;$(INCLUDE);}FaderRenderer.hppcst \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.hppcst \
    {F:\devel\DiveDemo2;$(INCLUDE);}Star.inl

.\vbmain.obj: \
    F:\devel\DiveDemo2\vbmain.cpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveDemo2.hpp \
    {F:\devel\DiveDemo2;$(INCLUDE);}os2.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}stdlib.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}time.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveDemo2.h \
    {F:\devel\DiveDemo2;$(INCLUDE);}DiveDemo2.hpv

.\DiveDemo2.rc: \
    F:\devel\DiveDemo2\DiveDemo2.rcx \
    {F:\devel\DiveDemo2;$(INCLUDE)}DiveDemo2.rci \
    {F:\devel\DiveDemo2;$(INCLUDE)}FastCanvas.rci \
    {F:\devel\DiveDemo2;$(INCLUDE)}FaderRenderer.rci \
    {F:\devel\DiveDemo2;$(INCLUDE)}DiveImageRenderer.rci \
    {F:\devel\DiveDemo2;$(INCLUDE)}FaderRenderer.h \
    {F:\devel\DiveDemo2;$(INCLUDE)}StarFieldRenderer.rci \
    {F:\devel\DiveDemo2;$(INCLUDE)}StarFieldRenderer.h \
    {F:\devel\DiveDemo2;$(INCLUDE)}DiveDemo2.h

.\DiveDemo2.res: \
    .\DiveDemo2.rc \
    {.;$(INCLUDE)}FastCanvas.h \
    {.;$(INCLUDE)}FaderRenderer.h \
    {.;$(INCLUDE)}DiveImageRenderer.h \
    {.;$(INCLUDE)}StarFieldRenderer.h \
    {.;$(INCLUDE)}DiveImageBuffer.h \
    {.;$(INCLUDE)}DiveBlitterHandler.h \
    {.;$(INCLUDE)}DiveDemo2.h

.\DiveDemo2.sym: \
    .\DiveDemo2.exe

.\DiveDemo2.sym: \
    F:\devel\DiveDemo2\DiveDemo2.map

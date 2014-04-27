# makefile
# Created by IBM WorkFrame/2 MakeMake at 15:10:43 on 16 Jan 1997
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker
#  Bind::Resource Bind
#  Compile::Resource Compiler

.SUFFIXES: .cpp .obj .rc .res 

.all: \
    .\resource.dll

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DINCL_PM /DINCL_DOS /Wcndcnscnvdclenuextgengotinilanobsordporprorearettruunduni /Tx /O /Gm /Gd /Ge- /G5 /Tm /C %s

{F:\devel\DiveDemo2\resources}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DINCL_PM /DINCL_DOS /Wcndcnscnvdclenuextgengotinilanobsordporprorearettruunduni /Tx /O /Gm /Gd /Ge- /G5 /Tm /C %s

.rc.res:
    @echo " Compile::Resource Compiler "
    rc.exe -r %s %|dpfF.RES

{F:\devel\DiveDemo2\resources}.rc.res:
    @echo " Compile::Resource Compiler "
    rc.exe -r %s %|dpfF.RES

.\resource.dll: \
    .\empty.obj \
    .\resources.res \
    {$(LIB)}resources.def
    @echo " Link::Linker "
    @echo " Bind::Resource Bind "
    icc.exe @<<
     /B" /pmtype:pm"
     /Fe"resource.dll" 
     resources.def
     .\empty.obj
<<
    rc.exe .\resources.res resource.dll

.\empty.obj: \
    F:\devel\DiveDemo2\resources\empty.cpp

.\resources.res: \
    F:\devel\DiveDemo2\resources\resources.rc

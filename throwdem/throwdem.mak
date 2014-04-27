# throwdem.mak
# Created by IBM WorkFrame/2 MakeMake at 21:58:15 on 11 Oct 1995
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker
#  Bind::Resource Bind
#  Compile::Resource Compiler

.SUFFIXES: .CPP .RC .obj .res 

.all: \
    pmprintf.exe \
    throwdem.exe

.CPP.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DIC_TRACE_ALL /DIC_DEVELOP /Tdp /Ti /Gm /Gd /Fo"%|dpfF.obj" /C %s

.RC.res:
    @echo " Compile::Resource Compiler "
    rc.exe -r %s %|dpfF.RES

throwdem.exe: \
    THROWDEM.obj \
    THROWDEM.res \
    throwdem.mak
    @echo " Link::Linker "
    @echo " Bind::Resource Bind "
    icc.exe @<<
     /B" /de /pmtype:pm"
     /Fethrowdem.exe 
     THROWDEM.obj
<<
    rc.exe THROWDEM.res throwdem.exe

THROWDEM.obj: \
    THROWDEM.CPP \
    {U:\DevSIG\Tips\Throw_Demo;$(INCLUDE);}idres.h \
    throwdem.mak

THROWDEM.res: \
    THROWDEM.RC \
    {$(INCLUDE)}idres.h \
    throwdem.mak

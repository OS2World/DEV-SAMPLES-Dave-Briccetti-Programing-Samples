# atccnr.mak
# Created by IBM WorkFrame/2 MakeMake at 23:30:39 on 20 Oct 1995
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker
#  Bind::Resource Bind
#  Compile::Resource Compiler

.SUFFIXES: .C .cpp .obj .rc .res

.all: \
    v:\ATCCnr2\atccnr.exe

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DIC_TRACE_ALL /DIC_DEVELOP /Tdp /Ti /Gm /Gd /Wclscmpcndcnscnvcpydcleffenuextgengotinilanobsordparporprorearettrdtruunduniuse /Fo"%|dpfF.obj" /C %s

.C.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DIC_TRACE_ALL /DIC_DEVELOP /Tdp /Ti /Gm /Gd /Fo"%|dpfF.obj" /C %s

.rc.res:
    @echo " Compile::Resource Compiler "
    rc.exe -r %s %|dpfF.RES

v:\ATCCnr2\atccnr.exe: \
    v:\ATCCnr2\atccnr.obj \
    v:\ATCCnr2\HELP.obj \
    v:\ATCCnr2\atccnr.res \
    atccnr.mak
    @echo " Link::Linker "
    @echo " Bind::Resource Bind "
    icc.exe @<<
     /B" /de /pmtype:pm"
     /Fev:\ATCCnr2\atccnr.exe
     v:\ATCCnr2\atccnr.obj
     v:\ATCCnr2\HELP.obj
<<
    rc.exe v:\ATCCnr2\atccnr.res v:\ATCCnr2\atccnr.exe

v:\ATCCnr2\atccnr.obj: \
    v:\ATCCnr2\atccnr.cpp \
    {v:\ATCCnr2;$(INCLUDE);}help.h \
    {v:\ATCCnr2;$(INCLUDE);}atccnr.h \
    atccnr.mak

v:\ATCCnr2\HELP.obj: \
    v:\ATCCnr2\HELP.C \
    {v:\ATCCnr2;$(INCLUDE);}help.h \
    atccnr.mak

v:\ATCCnr2\atccnr.res: \
    v:\ATCCnr2\atccnr.rc \
    {$(INCLUDE)}cntrollr.ico \
    {$(INCLUDE)}crew.ico \
    {$(INCLUDE)}jet.ico \
    {$(INCLUDE)}atccnr.h \
    atccnr.mak

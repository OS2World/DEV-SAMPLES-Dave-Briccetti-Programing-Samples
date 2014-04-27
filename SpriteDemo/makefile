# makefile
# Created by IBM WorkFrame/2 MakeMake at 23:00:43 on 29 Dec 1996
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker
#  Bind::Resource Bind
#  Compile::Resource Compiler

.SUFFIXES: .cpp .obj .rc .res 

.all: \
    .\SpriteDemo.exe

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DIC_DEVELOP /Wclscmpcndcnscnvcpydcleffenuextgengotinilanobsordparporprorearettrdtruunduniuse /Ti /Gm /Gd /G5 /C %s

{F:\devel\SpriteDemo}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /DIC_DEVELOP /Wclscmpcndcnscnvcpydcleffenuextgengotinilanobsordparporprorearettrdtruunduniuse /Ti /Gm /Gd /G5 /C %s

.rc.res:
    @echo " Compile::Resource Compiler "
    rc.exe -r %s %|dpfF.RES

{F:\devel\SpriteDemo}.rc.res:
    @echo " Compile::Resource Compiler "
    rc.exe -r %s %|dpfF.RES

.\SpriteDemo.exe: \
    .\SpriteDropHandler.obj \
    .\vbmain.obj \
    .\FastCanvas.obj \
    .\GraphicFileInfo.obj \
    .\ImageHandler.obj \
    .\InterfaceEnabler.obj \
    .\PcxLoader.obj \
    .\Sprite.obj \
    .\SpriteCommander.obj \
    .\SpriteDemo.obj \
    .\SpriteDetails.obj \
    .\SpriteDemo.res \
    {$(LIB)}os2386.lib \
    {$(LIB)}mmpm2.lib
    @echo " Link::Linker "
    @echo " Bind::Resource Bind "
    icc.exe @<<
    /DIC_DEVELOP
     /Tdp 
     /Wclscmpcndcnscnvcpydcleffenuextgengotinilanobsordparporprorearettrdtruunduniuse 
     /Ti /Gm /Gd /G5 
     /B" /de /pmtype:pm"
     /FeSpriteDemo.exe 
     os2386.lib 
     mmpm2.lib 
     .\SpriteDropHandler.obj
     .\vbmain.obj
     .\FastCanvas.obj
     .\GraphicFileInfo.obj
     .\ImageHandler.obj
     .\InterfaceEnabler.obj
     .\PcxLoader.obj
     .\Sprite.obj
     .\SpriteCommander.obj
     .\SpriteDemo.obj
     .\SpriteDetails.obj
<<
    rc.exe .\SpriteDemo.res SpriteDemo.exe

.\SpriteDropHandler.obj: \
    F:\devel\SpriteDemo\SpriteDropHandler.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}iexcept.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}itrace.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}graphicfileinfo.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}pcxloader.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}imagehandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}fastcanvas.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}fstream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}stdlib.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}iostream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}assert.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipoint.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}inclos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}mmioos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}fourcc.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}dive.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ivseq.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipainhdr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}spritedetails.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDetails.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDetails.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmhndlr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmtgtrn.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmtgth.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmprov.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmevent.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.cpv

.\SpriteDetails.obj: \
    F:\devel\SpriteDemo\SpriteDetails.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}iexcept.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}itrace.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}graphicfileinfo.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}pcxloader.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}imagehandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}fastcanvas.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}fstream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}stdlib.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}iostream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}assert.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipoint.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}inclos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}mmioos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}fourcc.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}dive.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ivseq.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipainhdr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}spritedetails.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDetails.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDetails.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmhndlr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmtgtrn.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmtgth.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmprov.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmevent.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDetails.cpv

.\SpriteDemo.obj: \
    F:\devel\SpriteDemo\SpriteDemo.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDemo.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}os2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDemo.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDemo.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}iexcept.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}itrace.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}graphicfileinfo.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}pcxloader.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}imagehandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}fastcanvas.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}fstream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}stdlib.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}iostream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}assert.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipoint.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}inclos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}mmioos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}fourcc.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}dive.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ivseq.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipainhdr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}InterfaceEnabler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}InterfaceEnabler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}InterfaceEnabler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteCommander.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}spritedetails.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteCommander.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteCommander.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDetails.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDetails.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmhndlr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmtgtrn.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmtgth.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmprov.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmevent.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDemo.cpv

.\SpriteCommander.obj: \
    F:\devel\SpriteDemo\SpriteCommander.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}iexcept.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}itrace.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}graphicfileinfo.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}pcxloader.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}imagehandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}fastcanvas.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}fstream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}stdlib.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}iostream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}assert.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipoint.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}inclos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}mmioos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}fourcc.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}dive.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ivseq.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipainhdr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteCommander.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteCommander.cpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}spritedetails.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteCommander.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteCommander.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDetails.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDetails.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmhndlr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmtgtrn.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmtgth.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmprov.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}idmevent.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDropHandler.hpv

.\Sprite.obj: \
    F:\devel\SpriteDemo\Sprite.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}iexcept.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}itrace.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}graphicfileinfo.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}pcxloader.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}imagehandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}fastcanvas.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}fstream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}stdlib.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}iostream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}assert.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipoint.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}inclos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}mmioos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}fourcc.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}dive.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ivseq.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipainhdr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.cpv

.\PcxLoader.obj: \
    F:\devel\SpriteDemo\PcxLoader.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}pcxloader.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}fstream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}iostream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}assert.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.cpv

.\InterfaceEnabler.obj: \
    F:\devel\SpriteDemo\InterfaceEnabler.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}InterfaceEnabler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}InterfaceEnabler.cpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}InterfaceEnabler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}InterfaceEnabler.hpv

.\ImageHandler.obj: \
    F:\devel\SpriteDemo\ImageHandler.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}pcxloader.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}imagehandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}fstream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}iostream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}assert.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipoint.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.cpv

.\GraphicFileInfo.obj: \
    F:\devel\SpriteDemo\GraphicFileInfo.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}graphicfileinfo.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}fstream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}stdlib.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.cpv

.\FastCanvas.obj: \
    F:\devel\SpriteDemo\FastCanvas.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}iexcept.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}itrace.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}graphicfileinfo.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}pcxloader.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}imagehandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}fastcanvas.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}fstream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}stdlib.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}iostream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}assert.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipoint.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}inclos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}mmioos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}fourcc.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}dive.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ivseq.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipainhdr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.cpv

.\vbmain.obj: \
    F:\devel\SpriteDemo\vbmain.cpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDemo.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}os2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDemo.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}SpriteDemo.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}iexcept.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}itrace.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}graphicfileinfo.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}pcxloader.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}imagehandler.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}fastcanvas.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}Sprite.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}fstream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}stdlib.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}GraphicFileInfo.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}iostream.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}assert.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}PcxLoader.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipoint.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ImageHandler.hpv \
    {F:\devel\SpriteDemo;$(INCLUDE);}inclos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}mmioos2.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}fourcc.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}dive.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ivseq.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}ipainhdr.hpp \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.h \
    {F:\devel\SpriteDemo;$(INCLUDE);}FastCanvas.hpv

.\SpriteDemo.res: \
    F:\devel\SpriteDemo\SpriteDemo.rc \
    {F:\devel\SpriteDemo;$(INCLUDE)}SpriteDemo.rci \
    {F:\devel\SpriteDemo;$(INCLUDE)}FastCanvas.rci \
    {F:\devel\SpriteDemo;$(INCLUDE)}FastCanvas.h \
    {F:\devel\SpriteDemo;$(INCLUDE)}SpriteDetails.rci \
    {F:\devel\SpriteDemo;$(INCLUDE)}SpriteDetails.h \
    {F:\devel\SpriteDemo;$(INCLUDE)}InterfaceEnabler.rci \
    {F:\devel\SpriteDemo;$(INCLUDE)}InterfaceEnabler.h \
    {F:\devel\SpriteDemo;$(INCLUDE)}SpriteDropHandler.rci \
    {F:\devel\SpriteDemo;$(INCLUDE)}SpriteDropHandler.h \
    {F:\devel\SpriteDemo;$(INCLUDE)}SpriteCommander.rci \
    {F:\devel\SpriteDemo;$(INCLUDE)}SpriteCommander.h \
    {F:\devel\SpriteDemo;$(INCLUDE)}SpriteDemo.h

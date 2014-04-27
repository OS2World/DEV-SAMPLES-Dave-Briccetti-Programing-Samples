# VBMain.mak
# Created by IBM WorkFrame/2 MakeMake at 21:25:11 on 20 Nov 1996
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker
#  Bind::Resource Bind
#  Compile::Resource Compiler

.SUFFIXES: .cpp .obj .rc .res 

.all: \
    g:\devel\spritedemo\SpriteDemo.exe

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /I. /DIC_DEVELOP /Tdp /Wcndcnscnvdcleffenugengotinilanobsordparporprorearettruund /Ti /Gm /Gd /G5 /Fo"%|dpfF.obj" /C %s

.rc.res:
    @echo " Compile::Resource Compiler "
    rc.exe -r %s %|dpfF.RES

g:\devel\spritedemo\SpriteDemo.exe: \
    g:\devel\spritedemo\SpriteDropHandler.obj \
    g:\devel\spritedemo\vbmain.obj \
    g:\devel\spritedemo\FastCanvas.obj \
    g:\devel\spritedemo\GraphicFileInfo.obj \
    g:\devel\spritedemo\ImageHandler.obj \
    g:\devel\spritedemo\InterfaceEnabler.obj \
    g:\devel\spritedemo\PcxLoader.obj \
    g:\devel\spritedemo\Sprite.obj \
    g:\devel\spritedemo\SpriteCommander.obj \
    g:\devel\spritedemo\SpriteDemo.obj \
    g:\devel\spritedemo\SpriteDetails.obj \
    g:\devel\spritedemo\SpriteDemo.res \
    {$(LIB)}os2386.lib \
    {$(LIB)}mmpm2.lib
    @echo " Link::Linker "
    @echo " Bind::Resource Bind "
    icc.exe @<<
    /I.
     /Tdp 
     /Wcndcnscnvdcleffenugengotinilanobsordparporprorearettruund 
     /Ti /Gm /Gd /G5 
     /B" /de /pmtype:pm"
     /Feg:\devel\spritedemo\SpriteDemo.exe 
     os2386.lib 
     mmpm2.lib 
     g:\devel\spritedemo\SpriteDropHandler.obj
     g:\devel\spritedemo\vbmain.obj
     g:\devel\spritedemo\FastCanvas.obj
     g:\devel\spritedemo\GraphicFileInfo.obj
     g:\devel\spritedemo\ImageHandler.obj
     g:\devel\spritedemo\InterfaceEnabler.obj
     g:\devel\spritedemo\PcxLoader.obj
     g:\devel\spritedemo\Sprite.obj
     g:\devel\spritedemo\SpriteCommander.obj
     g:\devel\spritedemo\SpriteDemo.obj
     g:\devel\spritedemo\SpriteDetails.obj
<<
    rc.exe g:\devel\spritedemo\SpriteDemo.res g:\devel\spritedemo\SpriteDemo.exe

g:\devel\spritedemo\SpriteDropHandler.obj: \
    g:\devel\spritedemo\SpriteDropHandler.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}iexcept.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}itrace.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}graphicfileinfo.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}pcxloader.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}imagehandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}fastcanvas.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}fstream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}stdlib.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}iostream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}assert.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipoint.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ivseq.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}spritedetails.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDetails.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDetails.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmhndlr.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmtgtrn.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmtgth.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmprov.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmevent.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.cpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}inclos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}mmioos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}fourcc.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}dive.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipainhdr.hpp

g:\devel\spritedemo\SpriteDetails.obj: \
    g:\devel\spritedemo\SpriteDetails.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}iexcept.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}itrace.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}graphicfileinfo.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}pcxloader.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}imagehandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}fastcanvas.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}fstream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}stdlib.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}iostream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}assert.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipoint.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ivseq.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}spritedetails.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDetails.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDetails.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmhndlr.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmtgtrn.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmtgth.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmprov.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmevent.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDetails.cpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}inclos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}mmioos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}fourcc.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}dive.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipainhdr.hpp

g:\devel\spritedemo\SpriteDemo.obj: \
    g:\devel\spritedemo\SpriteDemo.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDemo.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}os2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDemo.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDemo.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}iexcept.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}itrace.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}graphicfileinfo.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}pcxloader.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}imagehandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}fastcanvas.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}fstream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}stdlib.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}iostream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}assert.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipoint.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}InterfaceEnabler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}InterfaceEnabler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}InterfaceEnabler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteCommander.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}ivseq.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}spritedetails.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteCommander.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteCommander.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDetails.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDetails.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmhndlr.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmtgtrn.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmtgth.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmprov.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmevent.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDemo.cpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}inclos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}mmioos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}fourcc.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}dive.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipainhdr.hpp

g:\devel\spritedemo\SpriteCommander.obj: \
    g:\devel\spritedemo\SpriteCommander.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}iexcept.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}itrace.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}graphicfileinfo.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}pcxloader.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}imagehandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}fastcanvas.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}fstream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}stdlib.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}iostream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}assert.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipoint.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteCommander.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteCommander.cpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ivseq.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}spritedetails.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteCommander.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteCommander.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDetails.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDetails.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmhndlr.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmtgtrn.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmtgth.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmprov.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}idmevent.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDropHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}inclos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}mmioos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}fourcc.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}dive.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipainhdr.hpp

g:\devel\spritedemo\Sprite.obj: \
    g:\devel\spritedemo\Sprite.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}iexcept.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}itrace.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}graphicfileinfo.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}pcxloader.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}imagehandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}fastcanvas.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}fstream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}stdlib.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}iostream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}assert.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipoint.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.cpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ivseq.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}inclos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}mmioos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}fourcc.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}dive.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipainhdr.hpp

g:\devel\spritedemo\PcxLoader.obj: \
    g:\devel\spritedemo\PcxLoader.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}pcxloader.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}fstream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}iostream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}assert.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.cpv

g:\devel\spritedemo\InterfaceEnabler.obj: \
    g:\devel\spritedemo\InterfaceEnabler.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}InterfaceEnabler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}InterfaceEnabler.cpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}InterfaceEnabler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}InterfaceEnabler.hpv

g:\devel\spritedemo\ImageHandler.obj: \
    g:\devel\spritedemo\ImageHandler.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}pcxloader.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}imagehandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}fstream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}iostream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}assert.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipoint.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.cpv

g:\devel\spritedemo\GraphicFileInfo.obj: \
    g:\devel\spritedemo\GraphicFileInfo.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}graphicfileinfo.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}fstream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}stdlib.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.cpv

g:\devel\spritedemo\FastCanvas.obj: \
    g:\devel\spritedemo\FastCanvas.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}iexcept.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}itrace.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}graphicfileinfo.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}pcxloader.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}imagehandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}fastcanvas.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}fstream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}stdlib.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}iostream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}assert.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipoint.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.cpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ivseq.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}inclos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}mmioos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}fourcc.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}dive.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipainhdr.hpp

g:\devel\spritedemo\vbmain.obj: \
    g:\devel\spritedemo\vbmain.cpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDemo.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}os2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDemo.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}SpriteDemo.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}iexcept.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}itrace.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}graphicfileinfo.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}pcxloader.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}imagehandler.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}fastcanvas.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}Sprite.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}fstream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}stdlib.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}GraphicFileInfo.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}iostream.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}assert.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}PcxLoader.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipoint.hpp \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ImageHandler.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}FastCanvas.hpv \
    {g:\devel\spritedemo;.;$(INCLUDE);}ivseq.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}inclos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}mmioos2.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}fourcc.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}dive.h \
    {g:\devel\spritedemo;.;$(INCLUDE);}ipainhdr.hpp

g:\devel\spritedemo\SpriteDemo.res: \
    g:\devel\spritedemo\SpriteDemo.rc \
    {$(INCLUDE)}SpriteDemo.rci \
    {$(INCLUDE)}FastCanvas.rci \
    {$(INCLUDE)}FastCanvas.h \
    {$(INCLUDE)}SpriteDetails.rci \
    {$(INCLUDE)}SpriteDetails.h \
    {$(INCLUDE)}InterfaceEnabler.rci \
    {$(INCLUDE)}InterfaceEnabler.h \
    {$(INCLUDE)}SpriteDropHandler.rci \
    {$(INCLUDE)}SpriteDropHandler.h \
    {$(INCLUDE)}SpriteCommander.rci \
    {$(INCLUDE)}SpriteCommander.h \
    {$(INCLUDE)}SpriteDemo.h

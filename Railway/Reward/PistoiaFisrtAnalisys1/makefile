OBJS=PistoiaFisrtAnalisys1PVNodes.o PistoiaFisrtAnalisys1PVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFisrtAnalisys1PV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFisrtAnalisys1PV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFisrtAnalisys1PV.a: FORCE
	$(MAKE) lib TARGET=libPistoiaFisrtAnalisys1PV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFisrtAnalisys1PV_debug.a: FORCE
	$(MAKE) lib TARGET=libPistoiaFisrtAnalisys1PV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


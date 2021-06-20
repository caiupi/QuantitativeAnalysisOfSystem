OBJS=PistoiaFirstAnalysis2PVNodes.o PistoiaFirstAnalysis2PVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFirstAnalysis2PV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFirstAnalysis2PV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFirstAnalysis2PV.a: FORCE
	$(MAKE) lib TARGET=libPistoiaFirstAnalysis2PV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFirstAnalysis2PV_debug.a: FORCE
	$(MAKE) lib TARGET=libPistoiaFirstAnalysis2PV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


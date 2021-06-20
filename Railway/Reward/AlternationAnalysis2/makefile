OBJS=AlternationAnalysis2PVNodes.o AlternationAnalysis2PVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis2PV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis2PV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis2PV.a: FORCE
	$(MAKE) lib TARGET=libAlternationAnalysis2PV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis2PV_debug.a: FORCE
	$(MAKE) lib TARGET=libAlternationAnalysis2PV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


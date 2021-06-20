OBJS=AlternationAnalysis1PVNodes.o AlternationAnalysis1PVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis1PV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis1PV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis1PV.a: FORCE
	$(MAKE) lib TARGET=libAlternationAnalysis1PV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis1PV_debug.a: FORCE
	$(MAKE) lib TARGET=libAlternationAnalysis1PV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


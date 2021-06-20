OBJS=AlternationAnalysis3PVNodes.o AlternationAnalysis3PVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis3PV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis3PV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis3PV.a: FORCE
	$(MAKE) lib TARGET=libAlternationAnalysis3PV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis3PV_debug.a: FORCE
	$(MAKE) lib TARGET=libAlternationAnalysis3PV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


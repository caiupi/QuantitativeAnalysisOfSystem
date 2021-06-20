OBJS=LuccaFirstAnalysis3PVNodes.o LuccaFirstAnalysis3PVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis3PV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis3PV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis3PV.a: FORCE
	$(MAKE) lib TARGET=libLuccaFirstAnalysis3PV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis3PV_debug.a: FORCE
	$(MAKE) lib TARGET=libLuccaFirstAnalysis3PV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


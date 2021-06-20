OBJS=LuccaFirstAnalysis2PVNodes.o LuccaFirstAnalysis2PVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis2PV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis2PV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis2PV.a: FORCE
	$(MAKE) lib TARGET=libLuccaFirstAnalysis2PV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis2PV_debug.a: FORCE
	$(MAKE) lib TARGET=libLuccaFirstAnalysis2PV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


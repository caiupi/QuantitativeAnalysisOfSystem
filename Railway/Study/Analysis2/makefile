OBJS=Analysis2RangeStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libAnalysis2RangeStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libAnalysis2RangeStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libAnalysis2RangeStudy.a: FORCE
	$(MAKE) lib TARGET=libAnalysis2RangeStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libAnalysis2RangeStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libAnalysis2RangeStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


OBJS=Analysis3RangeStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libAnalysis3RangeStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libAnalysis3RangeStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libAnalysis3RangeStudy.a: FORCE
	$(MAKE) lib TARGET=libAnalysis3RangeStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libAnalysis3RangeStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libAnalysis3RangeStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


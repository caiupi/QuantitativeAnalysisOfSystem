OBJS=LuccaFirstAnalysis4RangeStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis4RangeStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis4RangeStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis4RangeStudy.a: FORCE
	$(MAKE) lib TARGET=libLuccaFirstAnalysis4RangeStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstAnalysis4RangeStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libLuccaFirstAnalysis4RangeStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


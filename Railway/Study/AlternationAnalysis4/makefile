OBJS=AlternationAnalysis4RangeStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis4RangeStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis4RangeStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis4RangeStudy.a: FORCE
	$(MAKE) lib TARGET=libAlternationAnalysis4RangeStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libAlternationAnalysis4RangeStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libAlternationAnalysis4RangeStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


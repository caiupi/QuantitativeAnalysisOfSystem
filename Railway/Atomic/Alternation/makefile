OBJS=AlternationSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libAlternationSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libAlternationSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libAlternationSAN.a: FORCE
	$(MAKE) lib TARGET=libAlternationSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libAlternationSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libAlternationSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


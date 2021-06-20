OBJS=PistoiaFirstSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFirstSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFirstSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFirstSAN.a: FORCE
	$(MAKE) lib TARGET=libPistoiaFirstSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libPistoiaFirstSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libPistoiaFirstSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


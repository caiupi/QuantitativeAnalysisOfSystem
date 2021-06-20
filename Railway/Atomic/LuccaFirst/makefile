OBJS=LuccaFirstSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstSAN.a: FORCE
	$(MAKE) lib TARGET=libLuccaFirstSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libLuccaFirstSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libLuccaFirstSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:


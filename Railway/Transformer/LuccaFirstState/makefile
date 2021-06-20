OBJS=


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

BINDIR=
MAINLIB=-lgenMain
MAINLIB_debug=-lgenMain_debug
SIMLIB=gen
SIMLIB_debug=gen_debug
SIMLIB_trace=gen_trace
PROJECTLIBS=-lLuccaFirstAnalysis4RangeStudy -lLuccaFirstAnalysis2PV -lLuccaFirstSAN 
PROJECTLIBS_debug=-lLuccaFirstAnalysis4RangeStudy_debug -lLuccaFirstAnalysis2PV_debug -lLuccaFirstSAN_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lSAN -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lSAN_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
LuccaFirstStateGen_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=LuccaFirstStateGen_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
LuccaFirstStateGen_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=LuccaFirstStateGen_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
LuccaFirstStateGen_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=LuccaFirstStateGen_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/LuccaFirst/ && $(MAKE) clean
	cd ../../Reward/LuccaFirstAnalysis2/ && $(MAKE) clean
	cd ../../Study/LuccaFirstAnalysis4/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[LuccaFirst]"
	cd ../../Atomic/LuccaFirst/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[LuccaFirstAnalysis2]"
	cd ../../Reward/LuccaFirstAnalysis2/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[LuccaFirstAnalysis4]"
	cd ../../Study/LuccaFirstAnalysis4/ && $(MAKE) $(@F)



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
PROJECTLIBS=-lPistoiaFirstAnalysis4RangeStudy -lPistoiaFirstAnalysis2PV -lPistoiaFirstSAN 
PROJECTLIBS_debug=-lPistoiaFirstAnalysis4RangeStudy_debug -lPistoiaFirstAnalysis2PV_debug -lPistoiaFirstSAN_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lSAN -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lSAN_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
PistoiaFirstStateGen_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=PistoiaFirstStateGen_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
PistoiaFirstStateGen_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=PistoiaFirstStateGen_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
PistoiaFirstStateGen_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=PistoiaFirstStateGen_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/PistoiaFirst/ && $(MAKE) clean
	cd ../../Reward/PistoiaFirstAnalysis2/ && $(MAKE) clean
	cd ../../Study/PistoiaFirstAnalysis4/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[PistoiaFirst]"
	cd ../../Atomic/PistoiaFirst/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[PistoiaFirstAnalysis2]"
	cd ../../Reward/PistoiaFirstAnalysis2/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[PistoiaFirstAnalysis4]"
	cd ../../Study/PistoiaFirstAnalysis4/ && $(MAKE) $(@F)



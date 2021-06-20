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
PROJECTLIBS=-lAlternationAnalysis4RangeStudy -lAlternationAnalysis2PV -lAlternationSAN 
PROJECTLIBS_debug=-lAlternationAnalysis4RangeStudy_debug -lAlternationAnalysis2PV_debug -lAlternationSAN_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lSAN -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lSAN_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
AlternationStateGen_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=AlternationStateGen_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
AlternationStateGen_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=AlternationStateGen_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
AlternationStateGen_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=AlternationStateGen_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/Alternation/ && $(MAKE) clean
	cd ../../Reward/AlternationAnalysis2/ && $(MAKE) clean
	cd ../../Study/AlternationAnalysis4/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[Alternation]"
	cd ../../Atomic/Alternation/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[AlternationAnalysis2]"
	cd ../../Reward/AlternationAnalysis2/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[AlternationAnalysis4]"
	cd ../../Study/AlternationAnalysis4/ && $(MAKE) $(@F)



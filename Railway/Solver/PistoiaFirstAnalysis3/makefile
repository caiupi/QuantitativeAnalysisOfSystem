OBJS=


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

BINDIR=
MAINLIB=-lslsolverMain
MAINLIB_debug=-lslsolverMain_debug
SIMLIB=slsolver
SIMLIB_debug=slsolver_debug
SIMLIB_trace=slsolver_trace
PROJECTLIBS=
PROJECTLIBS_debug=
MOBIUSLIBS=-lars -lflat -lslsolver -lltsbase -lTRex -lbase 
MOBIUSLIBS_debug=-lars_debug -lflat_debug -lslsolver_debug -lltsbase_debug -lTRex_debug -lbase_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
PistoiaFirstAnalysis3_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=PistoiaFirstAnalysis3_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
PistoiaFirstAnalysis3_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=PistoiaFirstAnalysis3_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
PistoiaFirstAnalysis3_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=PistoiaFirstAnalysis3_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:

SUBMODELS/opt SUBMODELS/debug:



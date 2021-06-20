#ifndef _PISTOIAFIRSTANALYSIS3_PVMODEL_
#define _PISTOIAFIRSTANALYSIS3_PVMODEL_
#include "PistoiaFirstAnalysis3PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/PistoiaFirst/PistoiaFirstSAN.h"
class PistoiaFirstAnalysis3PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  PistoiaFirstAnalysis3PVModel(bool expandtimepoints);
};

#endif

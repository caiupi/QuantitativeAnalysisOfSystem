#ifndef _PISTOIAFIRSTANALYSIS2_PVMODEL_
#define _PISTOIAFIRSTANALYSIS2_PVMODEL_
#include "PistoiaFirstAnalysis2PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/PistoiaFirst/PistoiaFirstSAN.h"
class PistoiaFirstAnalysis2PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  PistoiaFirstAnalysis2PVModel(bool expandtimepoints);
};

#endif

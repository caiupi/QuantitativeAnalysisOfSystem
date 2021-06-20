#ifndef _LUCCAFIRSTANALYSIS2_PVMODEL_
#define _LUCCAFIRSTANALYSIS2_PVMODEL_
#include "LuccaFirstAnalysis2PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/LuccaFirst/LuccaFirstSAN.h"
class LuccaFirstAnalysis2PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  LuccaFirstAnalysis2PVModel(bool expandtimepoints);
};

#endif

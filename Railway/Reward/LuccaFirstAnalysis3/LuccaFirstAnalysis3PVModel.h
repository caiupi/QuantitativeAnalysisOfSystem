#ifndef _LUCCAFIRSTANALYSIS3_PVMODEL_
#define _LUCCAFIRSTANALYSIS3_PVMODEL_
#include "LuccaFirstAnalysis3PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/LuccaFirst/LuccaFirstSAN.h"
class LuccaFirstAnalysis3PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  LuccaFirstAnalysis3PVModel(bool expandtimepoints);
};

#endif

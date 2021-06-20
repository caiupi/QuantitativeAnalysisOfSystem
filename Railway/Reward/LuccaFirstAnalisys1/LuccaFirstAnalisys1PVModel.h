#ifndef _LUCCAFIRSTANALISYS1_PVMODEL_
#define _LUCCAFIRSTANALISYS1_PVMODEL_
#include "LuccaFirstAnalisys1PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/LuccaFirst/LuccaFirstSAN.h"
class LuccaFirstAnalisys1PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  LuccaFirstAnalisys1PVModel(bool expandtimepoints);
};

#endif

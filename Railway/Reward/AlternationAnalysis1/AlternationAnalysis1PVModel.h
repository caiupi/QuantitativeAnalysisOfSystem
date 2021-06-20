#ifndef _ALTERNATIONANALYSIS1_PVMODEL_
#define _ALTERNATIONANALYSIS1_PVMODEL_
#include "AlternationAnalysis1PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/Alternation/AlternationSAN.h"
class AlternationAnalysis1PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  AlternationAnalysis1PVModel(bool expandtimepoints);
};

#endif

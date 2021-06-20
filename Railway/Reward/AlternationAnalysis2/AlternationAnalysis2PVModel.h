#ifndef _ALTERNATIONANALYSIS2_PVMODEL_
#define _ALTERNATIONANALYSIS2_PVMODEL_
#include "AlternationAnalysis2PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/Alternation/AlternationSAN.h"
class AlternationAnalysis2PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  AlternationAnalysis2PVModel(bool expandtimepoints);
};

#endif

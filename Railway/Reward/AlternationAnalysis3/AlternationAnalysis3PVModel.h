#ifndef _ALTERNATIONANALYSIS3_PVMODEL_
#define _ALTERNATIONANALYSIS3_PVMODEL_
#include "AlternationAnalysis3PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/Alternation/AlternationSAN.h"
class AlternationAnalysis3PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  AlternationAnalysis3PVModel(bool expandtimepoints);
};

#endif

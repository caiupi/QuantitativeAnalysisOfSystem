#ifndef _PISTOIAFISRTANALISYS1_PVMODEL_
#define _PISTOIAFISRTANALISYS1_PVMODEL_
#include "PistoiaFisrtAnalisys1PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/PistoiaFirst/PistoiaFirstSAN.h"
class PistoiaFisrtAnalisys1PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  PistoiaFisrtAnalisys1PVModel(bool expandtimepoints);
};

#endif

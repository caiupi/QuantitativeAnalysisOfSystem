#include "AlternationAnalysis1PVModel.h"

AlternationAnalysis1PVModel::AlternationAnalysis1PVModel(bool expandTimeArrays) {
  TheModel=new AlternationSAN();
  DefineName("AlternationAnalysis1PVModel");
  CreatePVList(8, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* AlternationAnalysis1PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new AlternationAnalysis1PV0(timeindex);
    break;
  case 1:
    return new AlternationAnalysis1PV1(timeindex);
    break;
  case 2:
    return new AlternationAnalysis1PV2(timeindex);
    break;
  case 3:
    return new AlternationAnalysis1PV3(timeindex);
    break;
  case 4:
    return new AlternationAnalysis1PV4(timeindex);
    break;
  case 5:
    return new AlternationAnalysis1PV5(timeindex);
    break;
  case 6:
    return new AlternationAnalysis1PV6(timeindex);
    break;
  case 7:
    return new AlternationAnalysis1PV7(timeindex);
    break;
  }
  return NULL;
}

#include "AlternationAnalysis2PVModel.h"

AlternationAnalysis2PVModel::AlternationAnalysis2PVModel(bool expandTimeArrays) {
  TheModel=new AlternationSAN();
  DefineName("AlternationAnalysis2PVModel");
  StateMode = 1;
  CreatePVList(1, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* AlternationAnalysis2PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new AlternationAnalysis2PV0(timeindex);
    break;
  }
  return NULL;
}

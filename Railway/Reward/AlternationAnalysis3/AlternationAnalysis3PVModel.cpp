#include "AlternationAnalysis3PVModel.h"

AlternationAnalysis3PVModel::AlternationAnalysis3PVModel(bool expandTimeArrays) {
  TheModel=new AlternationSAN();
  DefineName("AlternationAnalysis3PVModel");
  StateMode = 1;
  CreatePVList(1, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* AlternationAnalysis3PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new AlternationAnalysis3PV0(timeindex);
    break;
  }
  return NULL;
}

#include "PistoiaFirstAnalysis3PVModel.h"

PistoiaFirstAnalysis3PVModel::PistoiaFirstAnalysis3PVModel(bool expandTimeArrays) {
  TheModel=new PistoiaFirstSAN();
  DefineName("PistoiaFirstAnalysis3PVModel");
  StateMode = 1;
  CreatePVList(1, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* PistoiaFirstAnalysis3PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new PistoiaFirstAnalysis3PV0(timeindex);
    break;
  }
  return NULL;
}

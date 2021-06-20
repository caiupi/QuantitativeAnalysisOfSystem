#include "PistoiaFirstAnalysis2PVModel.h"

PistoiaFirstAnalysis2PVModel::PistoiaFirstAnalysis2PVModel(bool expandTimeArrays) {
  TheModel=new PistoiaFirstSAN();
  DefineName("PistoiaFirstAnalysis2PVModel");
  StateMode = 1;
  CreatePVList(1, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* PistoiaFirstAnalysis2PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new PistoiaFirstAnalysis2PV0(timeindex);
    break;
  }
  return NULL;
}

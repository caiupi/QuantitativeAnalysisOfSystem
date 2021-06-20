#include "LuccaFirstAnalysis2PVModel.h"

LuccaFirstAnalysis2PVModel::LuccaFirstAnalysis2PVModel(bool expandTimeArrays) {
  TheModel=new LuccaFirstSAN();
  DefineName("LuccaFirstAnalysis2PVModel");
  StateMode = 1;
  CreatePVList(1, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* LuccaFirstAnalysis2PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new LuccaFirstAnalysis2PV0(timeindex);
    break;
  }
  return NULL;
}

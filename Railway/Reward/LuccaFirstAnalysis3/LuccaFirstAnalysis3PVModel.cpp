#include "LuccaFirstAnalysis3PVModel.h"

LuccaFirstAnalysis3PVModel::LuccaFirstAnalysis3PVModel(bool expandTimeArrays) {
  TheModel=new LuccaFirstSAN();
  DefineName("LuccaFirstAnalysis3PVModel");
  StateMode = 1;
  CreatePVList(1, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* LuccaFirstAnalysis3PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new LuccaFirstAnalysis3PV0(timeindex);
    break;
  }
  return NULL;
}

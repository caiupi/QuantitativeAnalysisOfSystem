#include "LuccaFirstAnalisys1PVModel.h"

LuccaFirstAnalisys1PVModel::LuccaFirstAnalisys1PVModel(bool expandTimeArrays) {
  TheModel=new LuccaFirstSAN();
  DefineName("LuccaFirstAnalisys1PVModel");
  CreatePVList(8, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* LuccaFirstAnalisys1PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new LuccaFirstAnalisys1PV0(timeindex);
    break;
  case 1:
    return new LuccaFirstAnalisys1PV1(timeindex);
    break;
  case 2:
    return new LuccaFirstAnalisys1PV2(timeindex);
    break;
  case 3:
    return new LuccaFirstAnalisys1PV3(timeindex);
    break;
  case 4:
    return new LuccaFirstAnalisys1PV4(timeindex);
    break;
  case 5:
    return new LuccaFirstAnalisys1PV5(timeindex);
    break;
  case 6:
    return new LuccaFirstAnalisys1PV6(timeindex);
    break;
  case 7:
    return new LuccaFirstAnalisys1PV7(timeindex);
    break;
  }
  return NULL;
}

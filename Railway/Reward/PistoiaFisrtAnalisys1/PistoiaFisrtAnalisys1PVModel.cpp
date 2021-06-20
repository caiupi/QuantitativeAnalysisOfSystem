#include "PistoiaFisrtAnalisys1PVModel.h"

PistoiaFisrtAnalisys1PVModel::PistoiaFisrtAnalisys1PVModel(bool expandTimeArrays) {
  TheModel=new PistoiaFirstSAN();
  DefineName("PistoiaFisrtAnalisys1PVModel");
  CreatePVList(8, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* PistoiaFisrtAnalisys1PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new PistoiaFisrtAnalisys1PV0(timeindex);
    break;
  case 1:
    return new PistoiaFisrtAnalisys1PV1(timeindex);
    break;
  case 2:
    return new PistoiaFisrtAnalisys1PV2(timeindex);
    break;
  case 3:
    return new PistoiaFisrtAnalisys1PV3(timeindex);
    break;
  case 4:
    return new PistoiaFisrtAnalisys1PV4(timeindex);
    break;
  case 5:
    return new PistoiaFisrtAnalisys1PV5(timeindex);
    break;
  case 6:
    return new PistoiaFisrtAnalisys1PV6(timeindex);
    break;
  case 7:
    return new PistoiaFisrtAnalisys1PV7(timeindex);
    break;
  }
  return NULL;
}

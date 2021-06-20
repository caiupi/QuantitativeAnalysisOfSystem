#include "PistoiaFirstAnalysis3PVNodes.h"

PistoiaFirstAnalysis3PV0Impulse0::PistoiaFirstAnalysis3PV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&PistoiaFirst);
  ImpulseWorkerListLength = 0;
}

PistoiaFirstAnalysis3PV0Impulse0::~PistoiaFirstAnalysis3PV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double PistoiaFirstAnalysis3PV0Impulse0::Impulse_Function(double FiringTime)
{
return (1.0);

return(0);
}

ImpulseNodeClass** PistoiaFirstAnalysis3PV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new PistoiaFirstAnalysis3PV0Impulse0;
  }

  return ImpulseWorkerList;
}

PistoiaFirstAnalysis3PV0Impulse1::PistoiaFirstAnalysis3PV0Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&PistoiaFirst);
  ImpulseWorkerListLength = 0;
}

PistoiaFirstAnalysis3PV0Impulse1::~PistoiaFirstAnalysis3PV0Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double PistoiaFirstAnalysis3PV0Impulse1::Impulse_Function(double FiringTime)
{
return (1.0);

return(0);
}

ImpulseNodeClass** PistoiaFirstAnalysis3PV0Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new PistoiaFirstAnalysis3PV0Impulse1;
  }

  return ImpulseWorkerList;
}

PistoiaFirstAnalysis3PV0::PistoiaFirstAnalysis3PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThePistoiaFirstSAN);
  double startpts[1]={0.0};
  double stoppts[1]={384};
  Initialize("TravelCompleted",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("trackPistoiaFlorence","PistoiaFirst",&Impulse0);
  AddImpulse("trackLuccaViareggio","PistoiaFirst",&Impulse1);
}

PistoiaFirstAnalysis3PV0::~PistoiaFirstAnalysis3PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void PistoiaFirstAnalysis3PV0::CreateWorkerList(void) {
}

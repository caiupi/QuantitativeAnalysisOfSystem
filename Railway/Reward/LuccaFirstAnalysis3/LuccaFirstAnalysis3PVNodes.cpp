#include "LuccaFirstAnalysis3PVNodes.h"

LuccaFirstAnalysis3PV0Impulse0::LuccaFirstAnalysis3PV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LuccaFirst);
  ImpulseWorkerListLength = 0;
}

LuccaFirstAnalysis3PV0Impulse0::~LuccaFirstAnalysis3PV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double LuccaFirstAnalysis3PV0Impulse0::Impulse_Function(double FiringTime)
{
return (1.0);

return(0);
}

ImpulseNodeClass** LuccaFirstAnalysis3PV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new LuccaFirstAnalysis3PV0Impulse0;
  }

  return ImpulseWorkerList;
}

LuccaFirstAnalysis3PV0Impulse1::LuccaFirstAnalysis3PV0Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&LuccaFirst);
  ImpulseWorkerListLength = 0;
}

LuccaFirstAnalysis3PV0Impulse1::~LuccaFirstAnalysis3PV0Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double LuccaFirstAnalysis3PV0Impulse1::Impulse_Function(double FiringTime)
{
return (1.0);

return(0);
}

ImpulseNodeClass** LuccaFirstAnalysis3PV0Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new LuccaFirstAnalysis3PV0Impulse1;
  }

  return ImpulseWorkerList;
}

LuccaFirstAnalysis3PV0::LuccaFirstAnalysis3PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheLuccaFirstSAN);
  double startpts[1]={0.0};
  double stoppts[1]={384};
  Initialize("TravelCompleted",(RewardType)1,1, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("trackPistoiaFlorence","LuccaFirst",&Impulse0);
  AddImpulse("trackLuccaViareggio","LuccaFirst",&Impulse1);
}

LuccaFirstAnalysis3PV0::~LuccaFirstAnalysis3PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void LuccaFirstAnalysis3PV0::CreateWorkerList(void) {
}

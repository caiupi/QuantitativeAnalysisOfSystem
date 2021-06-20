#include "AlternationAnalysis2PVNodes.h"

AlternationAnalysis2PV0Impulse0::AlternationAnalysis2PV0Impulse0()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
  ImpulseWorkerListLength = 0;
}

AlternationAnalysis2PV0Impulse0::~AlternationAnalysis2PV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double AlternationAnalysis2PV0Impulse0::Impulse_Function(double FiringTime)
{
return (1.0);

return(0);
}

ImpulseNodeClass** AlternationAnalysis2PV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new AlternationAnalysis2PV0Impulse0;
  }

  return ImpulseWorkerList;
}

AlternationAnalysis2PV0Impulse1::AlternationAnalysis2PV0Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
  ImpulseWorkerListLength = 0;
}

AlternationAnalysis2PV0Impulse1::~AlternationAnalysis2PV0Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double AlternationAnalysis2PV0Impulse1::Impulse_Function(double FiringTime)
{
return (1.0);

return(0);
}

ImpulseNodeClass** AlternationAnalysis2PV0Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new AlternationAnalysis2PV0Impulse1;
  }

  return ImpulseWorkerList;
}

AlternationAnalysis2PV0::AlternationAnalysis2PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAlternationSAN);
  double startpts[8]={0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TravelCompleted",(RewardType)1,8, startpts, stoppts, timeindex, 2,0, 0);
  AddImpulse("trackPistoiaFlorence","Alternation",&Impulse0);
  AddImpulse("trackLuccaViareggio","Alternation",&Impulse1);
}

AlternationAnalysis2PV0::~AlternationAnalysis2PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void AlternationAnalysis2PV0::CreateWorkerList(void) {
}

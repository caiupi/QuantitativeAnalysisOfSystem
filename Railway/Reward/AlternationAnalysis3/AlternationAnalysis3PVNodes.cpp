#include "AlternationAnalysis3PVNodes.h"

AlternationAnalysis3PV0Impulse0::AlternationAnalysis3PV0Impulse0()
{
  NumberOfModelDependencies = 2;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[1] = (BaseModelClass**)(&Alternation);
  ImpulseWorkerListLength = 0;
}

AlternationAnalysis3PV0Impulse0::~AlternationAnalysis3PV0Impulse0() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double AlternationAnalysis3PV0Impulse0::Impulse_Function(double FiringTime)
{
return (1.0);

return(0);
}

ImpulseNodeClass** AlternationAnalysis3PV0Impulse0::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new AlternationAnalysis3PV0Impulse0;
  }

  return ImpulseWorkerList;
}

AlternationAnalysis3PV0Impulse1::AlternationAnalysis3PV0Impulse1()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
  ImpulseWorkerListLength = 0;
}

AlternationAnalysis3PV0Impulse1::~AlternationAnalysis3PV0Impulse1() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double AlternationAnalysis3PV0Impulse1::Impulse_Function(double FiringTime)
{
return (1.0);

return(0);
}

ImpulseNodeClass** AlternationAnalysis3PV0Impulse1::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new AlternationAnalysis3PV0Impulse1;
  }

  return ImpulseWorkerList;
}

AlternationAnalysis3PV0Impulse2::AlternationAnalysis3PV0Impulse2()
{
  NumberOfModelDependencies = 1;
  TheModelPtr = new BaseModelClass**[NumberOfModelDependencies];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
  ImpulseWorkerListLength = 0;
}

AlternationAnalysis3PV0Impulse2::~AlternationAnalysis3PV0Impulse2() {
  delete [] TheModelPtr;
  if (ImpulseWorkerListLength > 0) {
    for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < ImpulseWorkerListLength; ImpulseWorkerCounter++)
      delete ImpulseWorkerList[ImpulseWorkerCounter];
    delete[] ImpulseWorkerList;
  }
}

double AlternationAnalysis3PV0Impulse2::Impulse_Function(double FiringTime)
{
return (1.0);

return(0);
}

ImpulseNodeClass** AlternationAnalysis3PV0Impulse2::CreateImpulseWorkerList(int NumberOfWorkers) {
  ImpulseWorkerListLength = NumberOfWorkers;
  ImpulseWorkerList = new ImpulseNodeClass*[NumberOfWorkers];

  for (int ImpulseWorkerCounter = 0; ImpulseWorkerCounter < NumberOfWorkers; ImpulseWorkerCounter++)
  {
    ImpulseWorkerList[ImpulseWorkerCounter] = new AlternationAnalysis3PV0Impulse2;
  }

  return ImpulseWorkerList;
}

AlternationAnalysis3PV0::AlternationAnalysis3PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAlternationSAN);
  double startpts[1]={0.0 };
  double stoppts[1]={384};
  Initialize("TrainCompleted",(RewardType)1,1, startpts, stoppts, timeindex, 3,0, 0);
  AddImpulse("trackPistoiaFlorence","RailWay4",&Impulse0);
  AddImpulseModelDependency("Alternation",&Impulse0);
  AddImpulse("trackPistoiaFlorence","Alternation",&Impulse1);
  AddImpulse("trackLuccaViareggio","Alternation",&Impulse2);
}

AlternationAnalysis3PV0::~AlternationAnalysis3PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void AlternationAnalysis3PV0::CreateWorkerList(void) {
}

#include "AlternationAnalysis1PVNodes.h"

AlternationAnalysis1PV0Worker::AlternationAnalysis1PV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
}

AlternationAnalysis1PV0Worker::~AlternationAnalysis1PV0Worker() {
  delete [] TheModelPtr;
}

double AlternationAnalysis1PV0Worker::Reward_Function(void) {

return (Alternation->FlorenceDepartures->Mark()
+ Alternation->FlorenceArrivals->Mark());


return (0);



}

AlternationAnalysis1PV0::AlternationAnalysis1PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAlternationSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToFlorence",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("FlorenceDepartures","Alternation");
  AddVariableDependency("FlorenceArrivals","Alternation");
}

AlternationAnalysis1PV0::~AlternationAnalysis1PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void AlternationAnalysis1PV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new AlternationAnalysis1PV0Worker;
}
AlternationAnalysis1PV1Worker::AlternationAnalysis1PV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
}

AlternationAnalysis1PV1Worker::~AlternationAnalysis1PV1Worker() {
  delete [] TheModelPtr;
}

double AlternationAnalysis1PV1Worker::Reward_Function(void) {

return (Alternation->PistoiaToLucca->Mark()
+ Alternation->PistoiaToFlorence->Mark());

return (0);



}

AlternationAnalysis1PV1::AlternationAnalysis1PV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAlternationSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToPistoia",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("PistoiaToLucca","Alternation");
  AddVariableDependency("PistoiaToFlorence","Alternation");
}

AlternationAnalysis1PV1::~AlternationAnalysis1PV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void AlternationAnalysis1PV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new AlternationAnalysis1PV1Worker;
}
AlternationAnalysis1PV2Worker::AlternationAnalysis1PV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
}

AlternationAnalysis1PV2Worker::~AlternationAnalysis1PV2Worker() {
  delete [] TheModelPtr;
}

double AlternationAnalysis1PV2Worker::Reward_Function(void) {

return (Alternation->LuccaToViareggio->Mark()
+ Alternation->LuccaToPistoia->Mark());

return (0);



}

AlternationAnalysis1PV2::AlternationAnalysis1PV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAlternationSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToLucca",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("LuccaToViareggio","Alternation");
  AddVariableDependency("LuccaToPistoia","Alternation");
}

AlternationAnalysis1PV2::~AlternationAnalysis1PV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void AlternationAnalysis1PV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new AlternationAnalysis1PV2Worker;
}
AlternationAnalysis1PV3Worker::AlternationAnalysis1PV3Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
}

AlternationAnalysis1PV3Worker::~AlternationAnalysis1PV3Worker() {
  delete [] TheModelPtr;
}

double AlternationAnalysis1PV3Worker::Reward_Function(void) {

return (Alternation->ViareggioDepartures->Mark()
+ Alternation->ViareggioArrivals->Mark());

return (0);



}

AlternationAnalysis1PV3::AlternationAnalysis1PV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAlternationSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToViareggio",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("ViareggioDepartures","Alternation");
  AddVariableDependency("ViareggioArrivals","Alternation");
}

AlternationAnalysis1PV3::~AlternationAnalysis1PV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void AlternationAnalysis1PV3::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new AlternationAnalysis1PV3Worker;
}
AlternationAnalysis1PV4Worker::AlternationAnalysis1PV4Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
}

AlternationAnalysis1PV4Worker::~AlternationAnalysis1PV4Worker() {
  delete [] TheModelPtr;
}

double AlternationAnalysis1PV4Worker::Reward_Function(void) {

return (Alternation->FlorenceDepartures->Mark()
+ Alternation->FlorenceArrivals->Mark());

return (0);



}

AlternationAnalysis1PV4::AlternationAnalysis1PV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAlternationSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStateFlorence",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("FlorenceDepartures","Alternation");
  AddVariableDependency("FlorenceArrivals","Alternation");
}

AlternationAnalysis1PV4::~AlternationAnalysis1PV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void AlternationAnalysis1PV4::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new AlternationAnalysis1PV4Worker;
}
AlternationAnalysis1PV5Worker::AlternationAnalysis1PV5Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
}

AlternationAnalysis1PV5Worker::~AlternationAnalysis1PV5Worker() {
  delete [] TheModelPtr;
}

double AlternationAnalysis1PV5Worker::Reward_Function(void) {

return (Alternation->PistoiaToLucca->Mark()
+ Alternation->PistoiaToFlorence->Mark());

return (0);



}

AlternationAnalysis1PV5::AlternationAnalysis1PV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAlternationSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStatePistoia",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("PistoiaToLucca","Alternation");
  AddVariableDependency("PistoiaToFlorence","Alternation");
}

AlternationAnalysis1PV5::~AlternationAnalysis1PV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void AlternationAnalysis1PV5::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new AlternationAnalysis1PV5Worker;
}
AlternationAnalysis1PV6Worker::AlternationAnalysis1PV6Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
}

AlternationAnalysis1PV6Worker::~AlternationAnalysis1PV6Worker() {
  delete [] TheModelPtr;
}

double AlternationAnalysis1PV6Worker::Reward_Function(void) {

return (Alternation->LuccaToViareggio->Mark()
+ Alternation->LuccaToPistoia->Mark());

return (0);



}

AlternationAnalysis1PV6::AlternationAnalysis1PV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAlternationSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStateLucca",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("LuccaToViareggio","Alternation");
  AddVariableDependency("LuccaToPistoia","Alternation");
}

AlternationAnalysis1PV6::~AlternationAnalysis1PV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void AlternationAnalysis1PV6::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new AlternationAnalysis1PV6Worker;
}
AlternationAnalysis1PV7Worker::AlternationAnalysis1PV7Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Alternation);
}

AlternationAnalysis1PV7Worker::~AlternationAnalysis1PV7Worker() {
  delete [] TheModelPtr;
}

double AlternationAnalysis1PV7Worker::Reward_Function(void) {

return (Alternation->ViareggioDepartures->Mark()
+ Alternation->ViareggioArrivals->Mark());

return (0);



}

AlternationAnalysis1PV7::AlternationAnalysis1PV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheAlternationSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStateViareggio",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("ViareggioDepartures","Alternation");
  AddVariableDependency("ViareggioArrivals","Alternation");
}

AlternationAnalysis1PV7::~AlternationAnalysis1PV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void AlternationAnalysis1PV7::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new AlternationAnalysis1PV7Worker;
}

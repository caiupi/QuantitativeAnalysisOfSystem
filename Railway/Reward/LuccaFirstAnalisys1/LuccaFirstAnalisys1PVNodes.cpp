#include "LuccaFirstAnalisys1PVNodes.h"

LuccaFirstAnalisys1PV0Worker::LuccaFirstAnalisys1PV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&LuccaFirst);
}

LuccaFirstAnalisys1PV0Worker::~LuccaFirstAnalisys1PV0Worker() {
  delete [] TheModelPtr;
}

double LuccaFirstAnalisys1PV0Worker::Reward_Function(void) {

return (LuccaFirst->FlorenceDepartures->Mark()
+ LuccaFirst->FlorenceArrivals->Mark());

return (0);



}

LuccaFirstAnalisys1PV0::LuccaFirstAnalisys1PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheLuccaFirstSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToFlorence",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("FlorenceDepartures","LuccaFirst");
  AddVariableDependency("FlorenceArrivals","LuccaFirst");
}

LuccaFirstAnalisys1PV0::~LuccaFirstAnalisys1PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void LuccaFirstAnalisys1PV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new LuccaFirstAnalisys1PV0Worker;
}
LuccaFirstAnalisys1PV1Worker::LuccaFirstAnalisys1PV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&LuccaFirst);
}

LuccaFirstAnalisys1PV1Worker::~LuccaFirstAnalisys1PV1Worker() {
  delete [] TheModelPtr;
}

double LuccaFirstAnalisys1PV1Worker::Reward_Function(void) {

return (LuccaFirst->ViareggioDepartures->Mark()
+ LuccaFirst->ViareggioArrivals->Mark());

return (0);



}

LuccaFirstAnalisys1PV1::LuccaFirstAnalisys1PV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheLuccaFirstSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToViareggio",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("ViareggioDepartures","LuccaFirst");
  AddVariableDependency("ViareggioArrivals","LuccaFirst");
}

LuccaFirstAnalisys1PV1::~LuccaFirstAnalisys1PV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void LuccaFirstAnalisys1PV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new LuccaFirstAnalisys1PV1Worker;
}
LuccaFirstAnalisys1PV2Worker::LuccaFirstAnalisys1PV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&LuccaFirst);
}

LuccaFirstAnalisys1PV2Worker::~LuccaFirstAnalisys1PV2Worker() {
  delete [] TheModelPtr;
}

double LuccaFirstAnalisys1PV2Worker::Reward_Function(void) {

return (LuccaFirst->PistoiaToLucca->Mark()
+ LuccaFirst->PistoiaToFlorence->Mark());

return (0);



}

LuccaFirstAnalisys1PV2::LuccaFirstAnalisys1PV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheLuccaFirstSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToPistoia",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("PistoiaToLucca","LuccaFirst");
  AddVariableDependency("PistoiaToFlorence","LuccaFirst");
}

LuccaFirstAnalisys1PV2::~LuccaFirstAnalisys1PV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void LuccaFirstAnalisys1PV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new LuccaFirstAnalisys1PV2Worker;
}
LuccaFirstAnalisys1PV3Worker::LuccaFirstAnalisys1PV3Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&LuccaFirst);
}

LuccaFirstAnalisys1PV3Worker::~LuccaFirstAnalisys1PV3Worker() {
  delete [] TheModelPtr;
}

double LuccaFirstAnalisys1PV3Worker::Reward_Function(void) {

return (LuccaFirst->LuccaToViareggio->Mark()
+ LuccaFirst->LuccaToPistoia->Mark());

return (0);



}

LuccaFirstAnalisys1PV3::LuccaFirstAnalisys1PV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheLuccaFirstSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainLucca",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("LuccaToViareggio","LuccaFirst");
  AddVariableDependency("LuccaToPistoia","LuccaFirst");
}

LuccaFirstAnalisys1PV3::~LuccaFirstAnalisys1PV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void LuccaFirstAnalisys1PV3::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new LuccaFirstAnalisys1PV3Worker;
}
LuccaFirstAnalisys1PV4Worker::LuccaFirstAnalisys1PV4Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&LuccaFirst);
}

LuccaFirstAnalisys1PV4Worker::~LuccaFirstAnalisys1PV4Worker() {
  delete [] TheModelPtr;
}

double LuccaFirstAnalisys1PV4Worker::Reward_Function(void) {

return (LuccaFirst->FlorenceDepartures->Mark()
+ LuccaFirst->FlorenceArrivals->Mark());

return (0);



}

LuccaFirstAnalisys1PV4::LuccaFirstAnalisys1PV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheLuccaFirstSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStateFlorence",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("FlorenceDepartures","LuccaFirst");
  AddVariableDependency("FlorenceArrivals","LuccaFirst");
}

LuccaFirstAnalisys1PV4::~LuccaFirstAnalisys1PV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void LuccaFirstAnalisys1PV4::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new LuccaFirstAnalisys1PV4Worker;
}
LuccaFirstAnalisys1PV5Worker::LuccaFirstAnalisys1PV5Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&LuccaFirst);
}

LuccaFirstAnalisys1PV5Worker::~LuccaFirstAnalisys1PV5Worker() {
  delete [] TheModelPtr;
}

double LuccaFirstAnalisys1PV5Worker::Reward_Function(void) {

return (LuccaFirst->ViareggioDepartures->Mark()
+ LuccaFirst->ViareggioArrivals->Mark());

return (0);



}

LuccaFirstAnalisys1PV5::LuccaFirstAnalisys1PV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheLuccaFirstSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStateViareggio",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("ViareggioDepartures","LuccaFirst");
  AddVariableDependency("ViareggioArrivals","LuccaFirst");
}

LuccaFirstAnalisys1PV5::~LuccaFirstAnalisys1PV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void LuccaFirstAnalisys1PV5::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new LuccaFirstAnalisys1PV5Worker;
}
LuccaFirstAnalisys1PV6Worker::LuccaFirstAnalisys1PV6Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&LuccaFirst);
}

LuccaFirstAnalisys1PV6Worker::~LuccaFirstAnalisys1PV6Worker() {
  delete [] TheModelPtr;
}

double LuccaFirstAnalisys1PV6Worker::Reward_Function(void) {

return (LuccaFirst->PistoiaToLucca->Mark()
+ LuccaFirst->PistoiaToFlorence->Mark());

return (0);



}

LuccaFirstAnalisys1PV6::LuccaFirstAnalisys1PV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheLuccaFirstSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("StedyStatePistoia",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("PistoiaToLucca","LuccaFirst");
  AddVariableDependency("PistoiaToFlorence","LuccaFirst");
}

LuccaFirstAnalisys1PV6::~LuccaFirstAnalisys1PV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void LuccaFirstAnalisys1PV6::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new LuccaFirstAnalisys1PV6Worker;
}
LuccaFirstAnalisys1PV7Worker::LuccaFirstAnalisys1PV7Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&LuccaFirst);
}

LuccaFirstAnalisys1PV7Worker::~LuccaFirstAnalisys1PV7Worker() {
  delete [] TheModelPtr;
}

double LuccaFirstAnalisys1PV7Worker::Reward_Function(void) {

return (LuccaFirst->LuccaToViareggio->Mark()
+ LuccaFirst->LuccaToPistoia->Mark());

return (0);



}

LuccaFirstAnalisys1PV7::LuccaFirstAnalisys1PV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheLuccaFirstSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStateLucca",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("LuccaToViareggio","LuccaFirst");
  AddVariableDependency("LuccaToPistoia","LuccaFirst");
}

LuccaFirstAnalisys1PV7::~LuccaFirstAnalisys1PV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void LuccaFirstAnalisys1PV7::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new LuccaFirstAnalisys1PV7Worker;
}

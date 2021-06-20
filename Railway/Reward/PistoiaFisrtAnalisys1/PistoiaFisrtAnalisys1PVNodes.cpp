#include "PistoiaFisrtAnalisys1PVNodes.h"

PistoiaFisrtAnalisys1PV0Worker::PistoiaFisrtAnalisys1PV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&PistoiaFirst);
}

PistoiaFisrtAnalisys1PV0Worker::~PistoiaFisrtAnalisys1PV0Worker() {
  delete [] TheModelPtr;
}

double PistoiaFisrtAnalisys1PV0Worker::Reward_Function(void) {

return (PistoiaFirst->FlorenceDepartures->Mark()
+ PistoiaFirst->FlorenceArrivals->Mark());

return (0);



}

PistoiaFisrtAnalisys1PV0::PistoiaFisrtAnalisys1PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThePistoiaFirstSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToFlorence",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("FlorenceDepartures","PistoiaFirst");
  AddVariableDependency("FlorenceArrivals","PistoiaFirst");
}

PistoiaFisrtAnalisys1PV0::~PistoiaFisrtAnalisys1PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void PistoiaFisrtAnalisys1PV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new PistoiaFisrtAnalisys1PV0Worker;
}
PistoiaFisrtAnalisys1PV1Worker::PistoiaFisrtAnalisys1PV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&PistoiaFirst);
}

PistoiaFisrtAnalisys1PV1Worker::~PistoiaFisrtAnalisys1PV1Worker() {
  delete [] TheModelPtr;
}

double PistoiaFisrtAnalisys1PV1Worker::Reward_Function(void) {

return (PistoiaFirst->PistoiaToLucca->Mark()
+ PistoiaFirst->PistoiaToFlorence->Mark());

return (0);



}

PistoiaFisrtAnalisys1PV1::PistoiaFisrtAnalisys1PV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThePistoiaFirstSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToPistoia",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("PistoiaToLucca","PistoiaFirst");
  AddVariableDependency("PistoiaToFlorence","PistoiaFirst");
}

PistoiaFisrtAnalisys1PV1::~PistoiaFisrtAnalisys1PV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void PistoiaFisrtAnalisys1PV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new PistoiaFisrtAnalisys1PV1Worker;
}
PistoiaFisrtAnalisys1PV2Worker::PistoiaFisrtAnalisys1PV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&PistoiaFirst);
}

PistoiaFisrtAnalisys1PV2Worker::~PistoiaFisrtAnalisys1PV2Worker() {
  delete [] TheModelPtr;
}

double PistoiaFisrtAnalisys1PV2Worker::Reward_Function(void) {

return (PistoiaFirst->LuccaToViareggio->Mark()
+ PistoiaFirst->LuccaToPistoia->Mark());

return (0);



}

PistoiaFisrtAnalisys1PV2::PistoiaFisrtAnalisys1PV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThePistoiaFirstSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToLucca",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("LuccaToViareggio","PistoiaFirst");
  AddVariableDependency("LuccaToPistoia","PistoiaFirst");
}

PistoiaFisrtAnalisys1PV2::~PistoiaFisrtAnalisys1PV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void PistoiaFisrtAnalisys1PV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new PistoiaFisrtAnalisys1PV2Worker;
}
PistoiaFisrtAnalisys1PV3Worker::PistoiaFisrtAnalisys1PV3Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&PistoiaFirst);
}

PistoiaFisrtAnalisys1PV3Worker::~PistoiaFisrtAnalisys1PV3Worker() {
  delete [] TheModelPtr;
}

double PistoiaFisrtAnalisys1PV3Worker::Reward_Function(void) {

return (PistoiaFirst->ViareggioDepartures->Mark()
+ PistoiaFirst->ViareggioArrivals->Mark());

return (0);



}

PistoiaFisrtAnalisys1PV3::PistoiaFisrtAnalisys1PV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThePistoiaFirstSAN);
  double startpts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  double stoppts[8]={1, 6, 12, 24, 48, 96, 192, 384};
  Initialize("TrainToViareggio",(RewardType)0,8, startpts, stoppts, timeindex, 0,2, 2);
  AddVariableDependency("ViareggioDepartures","PistoiaFirst");
  AddVariableDependency("ViareggioArrivals","PistoiaFirst");
}

PistoiaFisrtAnalisys1PV3::~PistoiaFisrtAnalisys1PV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void PistoiaFisrtAnalisys1PV3::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new PistoiaFisrtAnalisys1PV3Worker;
}
PistoiaFisrtAnalisys1PV4Worker::PistoiaFisrtAnalisys1PV4Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&PistoiaFirst);
}

PistoiaFisrtAnalisys1PV4Worker::~PistoiaFisrtAnalisys1PV4Worker() {
  delete [] TheModelPtr;
}

double PistoiaFisrtAnalisys1PV4Worker::Reward_Function(void) {

return (PistoiaFirst->FlorenceDepartures->Mark()
+ PistoiaFirst->FlorenceArrivals->Mark());

return (0);



}

PistoiaFisrtAnalisys1PV4::PistoiaFisrtAnalisys1PV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThePistoiaFirstSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStateFlorence",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("FlorenceDepartures","PistoiaFirst");
  AddVariableDependency("FlorenceArrivals","PistoiaFirst");
}

PistoiaFisrtAnalisys1PV4::~PistoiaFisrtAnalisys1PV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void PistoiaFisrtAnalisys1PV4::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new PistoiaFisrtAnalisys1PV4Worker;
}
PistoiaFisrtAnalisys1PV5Worker::PistoiaFisrtAnalisys1PV5Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&PistoiaFirst);
}

PistoiaFisrtAnalisys1PV5Worker::~PistoiaFisrtAnalisys1PV5Worker() {
  delete [] TheModelPtr;
}

double PistoiaFisrtAnalisys1PV5Worker::Reward_Function(void) {

return (PistoiaFirst->PistoiaToLucca->Mark()
+ PistoiaFirst->PistoiaToFlorence->Mark());

return (0);



}

PistoiaFisrtAnalisys1PV5::PistoiaFisrtAnalisys1PV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThePistoiaFirstSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStatePistoia",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("PistoiaToLucca","PistoiaFirst");
  AddVariableDependency("PistoiaToFlorence","PistoiaFirst");
}

PistoiaFisrtAnalisys1PV5::~PistoiaFisrtAnalisys1PV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void PistoiaFisrtAnalisys1PV5::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new PistoiaFisrtAnalisys1PV5Worker;
}
PistoiaFisrtAnalisys1PV6Worker::PistoiaFisrtAnalisys1PV6Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&PistoiaFirst);
}

PistoiaFisrtAnalisys1PV6Worker::~PistoiaFisrtAnalisys1PV6Worker() {
  delete [] TheModelPtr;
}

double PistoiaFisrtAnalisys1PV6Worker::Reward_Function(void) {

return (PistoiaFirst->LuccaToViareggio->Mark()
+ PistoiaFirst->LuccaToPistoia->Mark());

return (0);



}

PistoiaFisrtAnalisys1PV6::PistoiaFisrtAnalisys1PV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThePistoiaFirstSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStateLucca",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("LuccaToViareggio","PistoiaFirst");
  AddVariableDependency("LuccaToPistoia","PistoiaFirst");
}

PistoiaFisrtAnalisys1PV6::~PistoiaFisrtAnalisys1PV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void PistoiaFisrtAnalisys1PV6::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new PistoiaFisrtAnalisys1PV6Worker;
}
PistoiaFisrtAnalisys1PV7Worker::PistoiaFisrtAnalisys1PV7Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&PistoiaFirst);
}

PistoiaFisrtAnalisys1PV7Worker::~PistoiaFisrtAnalisys1PV7Worker() {
  delete [] TheModelPtr;
}

double PistoiaFisrtAnalisys1PV7Worker::Reward_Function(void) {

return (PistoiaFirst->ViareggioDepartures->Mark()
+ PistoiaFirst->ViareggioArrivals->Mark());

return (0);



}

PistoiaFisrtAnalisys1PV7::PistoiaFisrtAnalisys1PV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&ThePistoiaFirstSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("SteadyStateViareggio",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("ViareggioDepartures","PistoiaFirst");
  AddVariableDependency("ViareggioArrivals","PistoiaFirst");
}

PistoiaFisrtAnalisys1PV7::~PistoiaFisrtAnalisys1PV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void PistoiaFisrtAnalisys1PV7::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new PistoiaFisrtAnalisys1PV7Worker;
}

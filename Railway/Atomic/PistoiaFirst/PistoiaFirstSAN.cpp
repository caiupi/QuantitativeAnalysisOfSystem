

// This C++ file was created by SanEditor

#include "Atomic/PistoiaFirst/PistoiaFirstSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         PistoiaFirstSAN Constructor             
******************************************************************/


PistoiaFirstSAN::PistoiaFirstSAN(){


  trackPistoiaToLuccaGroup.initialize(2, "trackPistoiaToLuccaGroup");
  trackPistoiaToLuccaGroup.appendGroup((BaseGroupClass*) &trackPistoiaToLucca_case1);
  trackPistoiaToLuccaGroup.appendGroup((BaseGroupClass*) &trackPistoiaToLucca_case2);

  trackLuccaPistoiaGroup.initialize(2, "trackLuccaPistoiaGroup");
  trackLuccaPistoiaGroup.appendGroup((BaseGroupClass*) &trackLuccaPistoia_case1);
  trackLuccaPistoiaGroup.appendGroup((BaseGroupClass*) &trackLuccaPistoia_case2);

  Activity* InitialActionList[11]={
    &FlorenceCleaningService, //0
    &trackFlorencePistoia, //1
    &trackPistoiaFlorence, //2
    &trackPistoiaToLucca_case1, //3
    &trackPistoiaToLucca_case2, //4
    &trackLuccaPistoia_case1, //5
    &trackLuccaPistoia_case2, //6
    &failure, //7
    &trackLuccaViareggio, //8
    &trackViareggioLucca, //9
    &ViareggioCleaningService  // 10
  };

  BaseGroupClass* InitialGroupList[9]={
    (BaseGroupClass*) &(FlorenceCleaningService), 
    (BaseGroupClass*) &(trackFlorencePistoia), 
    (BaseGroupClass*) &(trackPistoiaFlorence), 
    (BaseGroupClass*) &(trackPistoiaToLuccaGroup), 
    (BaseGroupClass*) &(trackLuccaPistoiaGroup), 
    (BaseGroupClass*) &(failure), 
    (BaseGroupClass*) &(trackLuccaViareggio), 
    (BaseGroupClass*) &(trackViareggioLucca), 
    (BaseGroupClass*) &(ViareggioCleaningService)
  };

  FlorenceDepartures = new Place("FlorenceDepartures" ,N);
  FlorenceArrivals = new Place("FlorenceArrivals" ,0);
  PistoiaToLucca = new Place("PistoiaToLucca" ,0);
  PistoiaToFlorence = new Place("PistoiaToFlorence" ,0);
  Signal = new Place("Signal" ,1);
  FaultyTrain = new Place("FaultyTrain" ,0);
  SignalFaulty = new Place("SignalFaulty" ,0);
  LuccaToViareggio = new Place("LuccaToViareggio" ,0);
  LuccaToPistoia = new Place("LuccaToPistoia" ,0);
  ViareggioArrivals = new Place("ViareggioArrivals" ,0);
  ViareggioDepartures = new Place("ViareggioDepartures" ,N);
  BaseStateVariableClass* InitialPlaces[11]={
    FlorenceDepartures,  // 0
    FlorenceArrivals,  // 1
    PistoiaToLucca,  // 2
    PistoiaToFlorence,  // 3
    Signal,  // 4
    FaultyTrain,  // 5
    SignalFaulty,  // 6
    LuccaToViareggio,  // 7
    LuccaToPistoia,  // 8
    ViareggioArrivals,  // 9
    ViareggioDepartures   // 10
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("PistoiaFirst", 11, InitialPlaces, 
                        0, InitialROPlaces, 
                        11, InitialActionList, 9, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[30][2]={ 
    {1,0}, {0,0}, {2,1}, {0,1}, {1,2}, {3,2}, {2,3}, {4,3}, {7,3}, 
    {5,4}, {6,4}, {2,4}, {4,4}, {8,5}, {4,5}, {3,5}, {5,6}, {8,6}, 
    {4,6}, {5,7}, {6,7}, {7,7}, {4,7}, {3,7}, {9,8}, {7,8}, {8,9}, 
    {10,9}, {9,10}, {10,10}
  };
  for(int n=0;n<30;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[25][2]={ 
    {1,0}, {2,1}, {3,1}, {0,1}, {3,2}, {2,3}, {8,3}, {7,3}, {4,3}, 
    {2,4}, {8,4}, {7,4}, {4,4}, {2,5}, {8,5}, {4,5}, {2,6}, {8,6}, 
    {4,6}, {5,7}, {7,8}, {7,9}, {8,9}, {10,9}, {9,10}
  };
  for(int n=0;n<25;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<11;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void PistoiaFirstSAN::CustomInitialization() {

}
PistoiaFirstSAN::~PistoiaFirstSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void PistoiaFirstSAN::assignPlacesToActivitiesInst(){
}
void PistoiaFirstSAN::assignPlacesToActivitiesTimed(){
  FlorenceCleaningService.FlorenceArrivals = (Place*) LocalStateVariables[1];
  FlorenceCleaningService.FlorenceDepartures = (Place*) LocalStateVariables[0];
  trackFlorencePistoia.PistoiaToLucca = (Place*) LocalStateVariables[2];
  trackFlorencePistoia.PistoiaToFlorence = (Place*) LocalStateVariables[3];
  trackFlorencePistoia.FlorenceDepartures = (Place*) LocalStateVariables[0];
  trackPistoiaFlorence.PistoiaToFlorence = (Place*) LocalStateVariables[3];
  trackPistoiaFlorence.FlorenceArrivals = (Place*) LocalStateVariables[1];
  trackPistoiaToLucca_case1.PistoiaToLucca = (Place*) LocalStateVariables[2];
  trackPistoiaToLucca_case1.LuccaToPistoia = (Place*) LocalStateVariables[8];
  trackPistoiaToLucca_case1.LuccaToViareggio = (Place*) LocalStateVariables[7];
  trackPistoiaToLucca_case1.Signal = (Place*) LocalStateVariables[4];
  trackPistoiaToLucca_case2.PistoiaToLucca = (Place*) LocalStateVariables[2];
  trackPistoiaToLucca_case2.LuccaToPistoia = (Place*) LocalStateVariables[8];
  trackPistoiaToLucca_case2.LuccaToViareggio = (Place*) LocalStateVariables[7];
  trackPistoiaToLucca_case2.Signal = (Place*) LocalStateVariables[4];
  trackPistoiaToLucca_case2.FaultyTrain = (Place*) LocalStateVariables[5];
  trackPistoiaToLucca_case2.SignalFaulty = (Place*) LocalStateVariables[6];
  trackLuccaPistoia_case1.PistoiaToLucca = (Place*) LocalStateVariables[2];
  trackLuccaPistoia_case1.LuccaToPistoia = (Place*) LocalStateVariables[8];
  trackLuccaPistoia_case1.Signal = (Place*) LocalStateVariables[4];
  trackLuccaPistoia_case1.PistoiaToFlorence = (Place*) LocalStateVariables[3];
  trackLuccaPistoia_case2.PistoiaToLucca = (Place*) LocalStateVariables[2];
  trackLuccaPistoia_case2.LuccaToPistoia = (Place*) LocalStateVariables[8];
  trackLuccaPistoia_case2.Signal = (Place*) LocalStateVariables[4];
  trackLuccaPistoia_case2.FaultyTrain = (Place*) LocalStateVariables[5];
  failure.FaultyTrain = (Place*) LocalStateVariables[5];
  failure.SignalFaulty = (Place*) LocalStateVariables[6];
  failure.LuccaToViareggio = (Place*) LocalStateVariables[7];
  failure.Signal = (Place*) LocalStateVariables[4];
  failure.PistoiaToFlorence = (Place*) LocalStateVariables[3];
  trackLuccaViareggio.LuccaToViareggio = (Place*) LocalStateVariables[7];
  trackLuccaViareggio.ViareggioArrivals = (Place*) LocalStateVariables[9];
  trackViareggioLucca.LuccaToViareggio = (Place*) LocalStateVariables[7];
  trackViareggioLucca.LuccaToPistoia = (Place*) LocalStateVariables[8];
  trackViareggioLucca.ViareggioDepartures = (Place*) LocalStateVariables[10];
  ViareggioCleaningService.ViareggioArrivals = (Place*) LocalStateVariables[9];
  ViareggioCleaningService.ViareggioDepartures = (Place*) LocalStateVariables[10];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================FlorenceCleaningServiceActivity========================*/

PistoiaFirstSAN::FlorenceCleaningServiceActivity::FlorenceCleaningServiceActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("FlorenceCleaningService",0,Exponential, RaceEnabled, 2,1, false);
}

PistoiaFirstSAN::FlorenceCleaningServiceActivity::~FlorenceCleaningServiceActivity(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::FlorenceCleaningServiceActivity::LinkVariables(){
  FlorenceArrivals->Register(&FlorenceArrivals_Mobius_Mark);
  FlorenceDepartures->Register(&FlorenceDepartures_Mobius_Mark);
}

bool PistoiaFirstSAN::FlorenceCleaningServiceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(FlorenceArrivals_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PistoiaFirstSAN::FlorenceCleaningServiceActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::FlorenceCleaningServiceActivity::Weight(){ 
  return 1;
}

bool PistoiaFirstSAN::FlorenceCleaningServiceActivity::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::FlorenceCleaningServiceActivity::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::FlorenceCleaningServiceActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* PistoiaFirstSAN::FlorenceCleaningServiceActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::FlorenceCleaningServiceActivity::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::FlorenceCleaningServiceActivity::Fire(){
  (*(FlorenceArrivals_Mobius_Mark))--;
  (*(FlorenceDepartures_Mobius_Mark))++;
  return this;
}

/*======================trackFlorencePistoiaActivity========================*/

PistoiaFirstSAN::trackFlorencePistoiaActivity::trackFlorencePistoiaActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackFlorencePistoia",1,Exponential, RaceEnabled, 2,3, false);
}

PistoiaFirstSAN::trackFlorencePistoiaActivity::~trackFlorencePistoiaActivity(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::trackFlorencePistoiaActivity::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
  FlorenceDepartures->Register(&FlorenceDepartures_Mobius_Mark);
}

bool PistoiaFirstSAN::trackFlorencePistoiaActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((((PistoiaToLucca->Mark() + PistoiaToFlorence->Mark()) < P)
&& (FlorenceDepartures->Mark() > 0)));
  return NewEnabled;
}

double PistoiaFirstSAN::trackFlorencePistoiaActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::trackFlorencePistoiaActivity::Weight(){ 
  return 1;
}

bool PistoiaFirstSAN::trackFlorencePistoiaActivity::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::trackFlorencePistoiaActivity::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::trackFlorencePistoiaActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* PistoiaFirstSAN::trackFlorencePistoiaActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::trackFlorencePistoiaActivity::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::trackFlorencePistoiaActivity::Fire(){
  FlorenceDepartures->Mark()--;
  (*(PistoiaToLucca_Mobius_Mark))++;
  return this;
}

/*======================trackPistoiaFlorenceActivity========================*/

PistoiaFirstSAN::trackPistoiaFlorenceActivity::trackPistoiaFlorenceActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackPistoiaFlorence",2,Exponential, RaceEnabled, 2,1, false);
}

PistoiaFirstSAN::trackPistoiaFlorenceActivity::~trackPistoiaFlorenceActivity(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::trackPistoiaFlorenceActivity::LinkVariables(){
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
  FlorenceArrivals->Register(&FlorenceArrivals_Mobius_Mark);
}

bool PistoiaFirstSAN::trackPistoiaFlorenceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((( PistoiaToFlorence->Mark() > 0 )));
  return NewEnabled;
}

double PistoiaFirstSAN::trackPistoiaFlorenceActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::trackPistoiaFlorenceActivity::Weight(){ 
  return 1;
}

bool PistoiaFirstSAN::trackPistoiaFlorenceActivity::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::trackPistoiaFlorenceActivity::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::trackPistoiaFlorenceActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* PistoiaFirstSAN::trackPistoiaFlorenceActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::trackPistoiaFlorenceActivity::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::trackPistoiaFlorenceActivity::Fire(){
  PistoiaToFlorence->Mark()--;
  (*(FlorenceArrivals_Mobius_Mark))++;
  return this;
}

/*======================trackPistoiaToLuccaActivity_case1========================*/

PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::trackPistoiaToLuccaActivity_case1(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackPistoiaToLucca_case1",3,Exponential, RaceEnabled, 3,4, false);
}

PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::~trackPistoiaToLuccaActivity_case1(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
}

bool PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PistoiaToLucca->Mark() > 0) 
 && ((LuccaToPistoia->Mark()+LuccaToViareggio->Mark()) < L+1)  
 && (Signal->Mark()==1)
));
  return NewEnabled;
}

double PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::Weight(){ 
  return 1-h;
}

bool PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::trackPistoiaToLuccaActivity_case1::Fire(){
  PistoiaToLucca->Mark() --;
Signal->Mark()=0;

  LuccaToViareggio->Mark() ++;
Signal->Mark()=1;
  return this;
}

/*======================trackPistoiaToLuccaActivity_case2========================*/

PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::trackPistoiaToLuccaActivity_case2(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackPistoiaToLucca_case2",3,Exponential, RaceEnabled, 4,4, false);
}

PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::~trackPistoiaToLuccaActivity_case2(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
  SignalFaulty->Register(&SignalFaulty_Mobius_Mark);
}

bool PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PistoiaToLucca->Mark() > 0) 
 && ((LuccaToPistoia->Mark()+LuccaToViareggio->Mark()) < L+1)  
 && (Signal->Mark()==1)
));
  return NewEnabled;
}

double PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::Weight(){ 
  return h;
}

bool PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::trackPistoiaToLuccaActivity_case2::Fire(){
  PistoiaToLucca->Mark() --;
Signal->Mark()=0;

  (*(FaultyTrain_Mobius_Mark))++;
  (*(SignalFaulty_Mobius_Mark))++;
  return this;
}

/*======================trackLuccaPistoiaActivity_case1========================*/

PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::trackLuccaPistoiaActivity_case1(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackLuccaPistoia_case1",4,Exponential, RaceEnabled, 3,3, false);
}

PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::~trackLuccaPistoiaActivity_case1(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
}

bool PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(( ( PistoiaToLucca->Mark()  == 0 ) 
 && (LuccaToPistoia->Mark() > 0) 
 && (Signal->Mark()==1)
));
  return NewEnabled;
}

double PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::Weight(){ 
  return 1-h;
}

bool PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::trackLuccaPistoiaActivity_case1::Fire(){
  LuccaToPistoia->Mark() --;
Signal->Mark()=0;

  PistoiaToFlorence->Mark() ++;
Signal->Mark()=1;
  return this;
}

/*======================trackLuccaPistoiaActivity_case2========================*/

PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::trackLuccaPistoiaActivity_case2(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackLuccaPistoia_case2",4,Exponential, RaceEnabled, 3,3, false);
}

PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::~trackLuccaPistoiaActivity_case2(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
}

bool PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(( ( PistoiaToLucca->Mark()  == 0 ) 
 && (LuccaToPistoia->Mark() > 0) 
 && (Signal->Mark()==1)
));
  return NewEnabled;
}

double PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::Weight(){ 
  return h;
}

bool PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::trackLuccaPistoiaActivity_case2::Fire(){
  LuccaToPistoia->Mark() --;
Signal->Mark()=0;

  (*(FaultyTrain_Mobius_Mark))++;
  return this;
}

/*======================failureActivity========================*/

PistoiaFirstSAN::failureActivity::failureActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("failure",5,Exponential, RaceEnabled, 5,1, false);
}

PistoiaFirstSAN::failureActivity::~failureActivity(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::failureActivity::LinkVariables(){
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
  SignalFaulty->Register(&SignalFaulty_Mobius_Mark);
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
}

bool PistoiaFirstSAN::failureActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(FaultyTrain_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PistoiaFirstSAN::failureActivity::Rate(){
  return 2.0/3.0;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::failureActivity::Weight(){ 
  return 1;
}

bool PistoiaFirstSAN::failureActivity::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::failureActivity::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::failureActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0/3.0);
}

double* PistoiaFirstSAN::failureActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::failureActivity::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::failureActivity::Fire(){
  (*(FaultyTrain_Mobius_Mark))--;
  if ( SignalFaulty->Mark()==1 ){
	LuccaToViareggio->Mark() ++;
	Signal->Mark()=1;
	SignalFaulty->Mark()=0;
}else{
	PistoiaToFlorence->Mark() ++;
	Signal->Mark()=1;
}
  return this;
}

/*======================trackLuccaViareggioActivity========================*/

PistoiaFirstSAN::trackLuccaViareggioActivity::trackLuccaViareggioActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackLuccaViareggio",6,Exponential, RaceEnabled, 2,1, false);
}

PistoiaFirstSAN::trackLuccaViareggioActivity::~trackLuccaViareggioActivity(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::trackLuccaViareggioActivity::LinkVariables(){
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  ViareggioArrivals->Register(&ViareggioArrivals_Mobius_Mark);
}

bool PistoiaFirstSAN::trackLuccaViareggioActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((LuccaToViareggio->Mark() > 0)));
  return NewEnabled;
}

double PistoiaFirstSAN::trackLuccaViareggioActivity::Rate(){
  return 1.2;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::trackLuccaViareggioActivity::Weight(){ 
  return 1;
}

bool PistoiaFirstSAN::trackLuccaViareggioActivity::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::trackLuccaViareggioActivity::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::trackLuccaViareggioActivity::SampleDistribution(){
  return TheDistribution->Exponential(1.2);
}

double* PistoiaFirstSAN::trackLuccaViareggioActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::trackLuccaViareggioActivity::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::trackLuccaViareggioActivity::Fire(){
  LuccaToViareggio->Mark() --;
  (*(ViareggioArrivals_Mobius_Mark))++;
  return this;
}

/*======================trackViareggioLuccaActivity========================*/

PistoiaFirstSAN::trackViareggioLuccaActivity::trackViareggioLuccaActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackViareggioLucca",7,Exponential, RaceEnabled, 2,3, false);
}

PistoiaFirstSAN::trackViareggioLuccaActivity::~trackViareggioLuccaActivity(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::trackViareggioLuccaActivity::LinkVariables(){
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  ViareggioDepartures->Register(&ViareggioDepartures_Mobius_Mark);
}

bool PistoiaFirstSAN::trackViareggioLuccaActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((((LuccaToViareggio->Mark() + LuccaToPistoia->Mark()) < L)
&& (ViareggioDepartures->Mark() > 0)));
  return NewEnabled;
}

double PistoiaFirstSAN::trackViareggioLuccaActivity::Rate(){
  return 1.2;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::trackViareggioLuccaActivity::Weight(){ 
  return 1;
}

bool PistoiaFirstSAN::trackViareggioLuccaActivity::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::trackViareggioLuccaActivity::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::trackViareggioLuccaActivity::SampleDistribution(){
  return TheDistribution->Exponential(1.2);
}

double* PistoiaFirstSAN::trackViareggioLuccaActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::trackViareggioLuccaActivity::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::trackViareggioLuccaActivity::Fire(){
  ViareggioDepartures->Mark() -- ;
  (*(LuccaToPistoia_Mobius_Mark))++;
  return this;
}

/*======================ViareggioCleaningServiceActivity========================*/

PistoiaFirstSAN::ViareggioCleaningServiceActivity::ViareggioCleaningServiceActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("ViareggioCleaningService",8,Exponential, RaceEnabled, 2,1, false);
}

PistoiaFirstSAN::ViareggioCleaningServiceActivity::~ViareggioCleaningServiceActivity(){
  delete[] TheDistributionParameters;
}

void PistoiaFirstSAN::ViareggioCleaningServiceActivity::LinkVariables(){
  ViareggioArrivals->Register(&ViareggioArrivals_Mobius_Mark);
  ViareggioDepartures->Register(&ViareggioDepartures_Mobius_Mark);
}

bool PistoiaFirstSAN::ViareggioCleaningServiceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ViareggioArrivals_Mobius_Mark)) >=1));
  return NewEnabled;
}

double PistoiaFirstSAN::ViareggioCleaningServiceActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double PistoiaFirstSAN::ViareggioCleaningServiceActivity::Weight(){ 
  return 1;
}

bool PistoiaFirstSAN::ViareggioCleaningServiceActivity::ReactivationPredicate(){ 
  return false;
}

bool PistoiaFirstSAN::ViareggioCleaningServiceActivity::ReactivationFunction(){ 
  return false;
}

double PistoiaFirstSAN::ViareggioCleaningServiceActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* PistoiaFirstSAN::ViareggioCleaningServiceActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int PistoiaFirstSAN::ViareggioCleaningServiceActivity::Rank(){
  return 1;
}

BaseActionClass* PistoiaFirstSAN::ViareggioCleaningServiceActivity::Fire(){
  (*(ViareggioArrivals_Mobius_Mark))--;
  (*(ViareggioDepartures_Mobius_Mark))++;
  return this;
}


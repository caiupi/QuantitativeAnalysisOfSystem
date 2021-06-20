

// This C++ file was created by SanEditor

#include "Atomic/Alternation/AlternationSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         AlternationSAN Constructor             
******************************************************************/


AlternationSAN::AlternationSAN(){


  trackPistoiaToLuccaGroup.initialize(2, "trackPistoiaToLuccaGroup");
  trackPistoiaToLuccaGroup.appendGroup((BaseGroupClass*) &trackPistoiaToLucca_case1);
  trackPistoiaToLuccaGroup.appendGroup((BaseGroupClass*) &trackPistoiaToLucca_case2);

  trackLuccaPistoiaGroup.initialize(2, "trackLuccaPistoiaGroup");
  trackLuccaPistoiaGroup.appendGroup((BaseGroupClass*) &trackLuccaPistoia_case1);
  trackLuccaPistoiaGroup.appendGroup((BaseGroupClass*) &trackLuccaPistoia_case2);

  Activity* InitialActionList[11]={
    &trackFlorencePistoia, //0
    &FlorenceCleaningService, //1
    &trackPistoiaFlorence, //2
    &trackPistoiaToLucca_case1, //3
    &trackPistoiaToLucca_case2, //4
    &failure, //5
    &trackLuccaViareggio, //6
    &trackViareggioLucca, //7
    &ViareggioCleaningService, //8
    &trackLuccaPistoia_case1, //9
    &trackLuccaPistoia_case2  // 10
  };

  BaseGroupClass* InitialGroupList[9]={
    (BaseGroupClass*) &(trackFlorencePistoia), 
    (BaseGroupClass*) &(FlorenceCleaningService), 
    (BaseGroupClass*) &(trackPistoiaFlorence), 
    (BaseGroupClass*) &(trackPistoiaToLuccaGroup), 
    (BaseGroupClass*) &(failure), 
    (BaseGroupClass*) &(trackLuccaViareggio), 
    (BaseGroupClass*) &(trackViareggioLucca), 
    (BaseGroupClass*) &(ViareggioCleaningService), 
    (BaseGroupClass*) &(trackLuccaPistoiaGroup)
  };

  FlorenceDepartures = new Place("FlorenceDepartures" ,N);
  PistoiaToLucca = new Place("PistoiaToLucca" ,0);
  PistoiaToFlorence = new Place("PistoiaToFlorence" ,0);
  FlorenceArrivals = new Place("FlorenceArrivals" ,0);
  FaultyTrain = new Place("FaultyTrain" ,0);
  LuccaToViareggio = new Place("LuccaToViareggio" ,0);
  LuccaToPistoia = new Place("LuccaToPistoia" ,0);
  ViareggioArrivals = new Place("ViareggioArrivals" ,0);
  ViareggioDepartures = new Place("ViareggioDepartures" ,N);
  Signal = new Place("Signal" ,1);
  BaseStateVariableClass* InitialPlaces[10]={
    FlorenceDepartures,  // 0
    PistoiaToLucca,  // 1
    PistoiaToFlorence,  // 2
    FlorenceArrivals,  // 3
    FaultyTrain,  // 4
    LuccaToViareggio,  // 5
    LuccaToPistoia,  // 6
    ViareggioArrivals,  // 7
    ViareggioDepartures,  // 8
    Signal   // 9
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("Alternation", 10, InitialPlaces, 
                        0, InitialROPlaces, 
                        11, InitialActionList, 9, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[26][2]={ 
    {1,0}, {0,0}, {3,1}, {0,1}, {3,2}, {2,2}, {1,3}, {5,3}, {9,3}, 
    {4,4}, {1,4}, {4,5}, {9,5}, {5,5}, {2,5}, {7,6}, {5,6}, {6,7}, 
    {8,7}, {7,8}, {8,8}, {6,9}, {2,9}, {9,9}, {4,10}, {6,10}
  };
  for(int n=0;n<26;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[29][2]={ 
    {1,0}, {2,0}, {0,0}, {3,1}, {2,2}, {4,3}, {1,3}, {6,3}, {5,3}, 
    {9,3}, {4,4}, {1,4}, {6,4}, {5,4}, {9,4}, {4,5}, {5,6}, {5,7}, 
    {6,7}, {8,7}, {7,8}, {4,9}, {1,9}, {6,9}, {9,9}, {4,10}, 
    {1,10}, {6,10}, {9,10}
  };
  for(int n=0;n<29;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<11;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void AlternationSAN::CustomInitialization() {

}
AlternationSAN::~AlternationSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void AlternationSAN::assignPlacesToActivitiesInst(){
}
void AlternationSAN::assignPlacesToActivitiesTimed(){
  trackFlorencePistoia.PistoiaToLucca = (Place*) LocalStateVariables[1];
  trackFlorencePistoia.PistoiaToFlorence = (Place*) LocalStateVariables[2];
  trackFlorencePistoia.FlorenceDepartures = (Place*) LocalStateVariables[0];
  FlorenceCleaningService.FlorenceArrivals = (Place*) LocalStateVariables[3];
  FlorenceCleaningService.FlorenceDepartures = (Place*) LocalStateVariables[0];
  trackPistoiaFlorence.PistoiaToFlorence = (Place*) LocalStateVariables[2];
  trackPistoiaFlorence.FlorenceArrivals = (Place*) LocalStateVariables[3];
  trackPistoiaToLucca_case1.FaultyTrain = (Place*) LocalStateVariables[4];
  trackPistoiaToLucca_case1.PistoiaToLucca = (Place*) LocalStateVariables[1];
  trackPistoiaToLucca_case1.LuccaToPistoia = (Place*) LocalStateVariables[6];
  trackPistoiaToLucca_case1.LuccaToViareggio = (Place*) LocalStateVariables[5];
  trackPistoiaToLucca_case1.Signal = (Place*) LocalStateVariables[9];
  trackPistoiaToLucca_case2.FaultyTrain = (Place*) LocalStateVariables[4];
  trackPistoiaToLucca_case2.PistoiaToLucca = (Place*) LocalStateVariables[1];
  trackPistoiaToLucca_case2.LuccaToPistoia = (Place*) LocalStateVariables[6];
  trackPistoiaToLucca_case2.LuccaToViareggio = (Place*) LocalStateVariables[5];
  trackPistoiaToLucca_case2.Signal = (Place*) LocalStateVariables[9];
  failure.FaultyTrain = (Place*) LocalStateVariables[4];
  failure.Signal = (Place*) LocalStateVariables[9];
  failure.LuccaToViareggio = (Place*) LocalStateVariables[5];
  failure.PistoiaToFlorence = (Place*) LocalStateVariables[2];
  trackLuccaViareggio.LuccaToViareggio = (Place*) LocalStateVariables[5];
  trackLuccaViareggio.ViareggioArrivals = (Place*) LocalStateVariables[7];
  trackViareggioLucca.LuccaToViareggio = (Place*) LocalStateVariables[5];
  trackViareggioLucca.LuccaToPistoia = (Place*) LocalStateVariables[6];
  trackViareggioLucca.ViareggioDepartures = (Place*) LocalStateVariables[8];
  ViareggioCleaningService.ViareggioArrivals = (Place*) LocalStateVariables[7];
  ViareggioCleaningService.ViareggioDepartures = (Place*) LocalStateVariables[8];
  trackLuccaPistoia_case1.FaultyTrain = (Place*) LocalStateVariables[4];
  trackLuccaPistoia_case1.PistoiaToLucca = (Place*) LocalStateVariables[1];
  trackLuccaPistoia_case1.LuccaToPistoia = (Place*) LocalStateVariables[6];
  trackLuccaPistoia_case1.Signal = (Place*) LocalStateVariables[9];
  trackLuccaPistoia_case1.PistoiaToFlorence = (Place*) LocalStateVariables[2];
  trackLuccaPistoia_case2.FaultyTrain = (Place*) LocalStateVariables[4];
  trackLuccaPistoia_case2.PistoiaToLucca = (Place*) LocalStateVariables[1];
  trackLuccaPistoia_case2.LuccaToPistoia = (Place*) LocalStateVariables[6];
  trackLuccaPistoia_case2.Signal = (Place*) LocalStateVariables[9];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================trackFlorencePistoiaActivity========================*/

AlternationSAN::trackFlorencePistoiaActivity::trackFlorencePistoiaActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackFlorencePistoia",0,Exponential, RaceEnabled, 2,3, false);
}

AlternationSAN::trackFlorencePistoiaActivity::~trackFlorencePistoiaActivity(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::trackFlorencePistoiaActivity::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
  FlorenceDepartures->Register(&FlorenceDepartures_Mobius_Mark);
}

bool AlternationSAN::trackFlorencePistoiaActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((((PistoiaToLucca->Mark() + PistoiaToFlorence->Mark()) < P)
&& (FlorenceDepartures->Mark() > 0)));
  return NewEnabled;
}

double AlternationSAN::trackFlorencePistoiaActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::trackFlorencePistoiaActivity::Weight(){ 
  return 1;
}

bool AlternationSAN::trackFlorencePistoiaActivity::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::trackFlorencePistoiaActivity::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::trackFlorencePistoiaActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* AlternationSAN::trackFlorencePistoiaActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::trackFlorencePistoiaActivity::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::trackFlorencePistoiaActivity::Fire(){
  FlorenceDepartures->Mark()--;
  (*(PistoiaToLucca_Mobius_Mark))++;
  return this;
}

/*======================FlorenceCleaningServiceActivity========================*/

AlternationSAN::FlorenceCleaningServiceActivity::FlorenceCleaningServiceActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("FlorenceCleaningService",1,Exponential, RaceEnabled, 2,1, false);
}

AlternationSAN::FlorenceCleaningServiceActivity::~FlorenceCleaningServiceActivity(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::FlorenceCleaningServiceActivity::LinkVariables(){
  FlorenceArrivals->Register(&FlorenceArrivals_Mobius_Mark);
  FlorenceDepartures->Register(&FlorenceDepartures_Mobius_Mark);
}

bool AlternationSAN::FlorenceCleaningServiceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(FlorenceArrivals_Mobius_Mark)) >=1));
  return NewEnabled;
}

double AlternationSAN::FlorenceCleaningServiceActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::FlorenceCleaningServiceActivity::Weight(){ 
  return 1;
}

bool AlternationSAN::FlorenceCleaningServiceActivity::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::FlorenceCleaningServiceActivity::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::FlorenceCleaningServiceActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* AlternationSAN::FlorenceCleaningServiceActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::FlorenceCleaningServiceActivity::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::FlorenceCleaningServiceActivity::Fire(){
  (*(FlorenceArrivals_Mobius_Mark))--;
  (*(FlorenceDepartures_Mobius_Mark))++;
  return this;
}

/*======================trackPistoiaFlorenceActivity========================*/

AlternationSAN::trackPistoiaFlorenceActivity::trackPistoiaFlorenceActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackPistoiaFlorence",2,Exponential, RaceEnabled, 2,1, false);
}

AlternationSAN::trackPistoiaFlorenceActivity::~trackPistoiaFlorenceActivity(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::trackPistoiaFlorenceActivity::LinkVariables(){
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
  FlorenceArrivals->Register(&FlorenceArrivals_Mobius_Mark);
}

bool AlternationSAN::trackPistoiaFlorenceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((( PistoiaToFlorence->Mark() > 0 )));
  return NewEnabled;
}

double AlternationSAN::trackPistoiaFlorenceActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::trackPistoiaFlorenceActivity::Weight(){ 
  return 1;
}

bool AlternationSAN::trackPistoiaFlorenceActivity::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::trackPistoiaFlorenceActivity::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::trackPistoiaFlorenceActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* AlternationSAN::trackPistoiaFlorenceActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::trackPistoiaFlorenceActivity::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::trackPistoiaFlorenceActivity::Fire(){
  PistoiaToFlorence->Mark()--;
  (*(FlorenceArrivals_Mobius_Mark))++;
  return this;
}

/*======================trackPistoiaToLuccaActivity_case1========================*/

AlternationSAN::trackPistoiaToLuccaActivity_case1::trackPistoiaToLuccaActivity_case1(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackPistoiaToLucca_case1",3,Exponential, RaceEnabled, 3,5, false);
}

AlternationSAN::trackPistoiaToLuccaActivity_case1::~trackPistoiaToLuccaActivity_case1(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::trackPistoiaToLuccaActivity_case1::LinkVariables(){
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
}

bool AlternationSAN::trackPistoiaToLuccaActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((FaultyTrain->Mark()==0)
 && (PistoiaToLucca->Mark() > 0) 
 && ((LuccaToPistoia->Mark()+LuccaToViareggio->Mark()) < L+1)  
 && (Signal->Mark()==1)
));
  return NewEnabled;
}

double AlternationSAN::trackPistoiaToLuccaActivity_case1::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::trackPistoiaToLuccaActivity_case1::Weight(){ 
  return 1-h;
}

bool AlternationSAN::trackPistoiaToLuccaActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::trackPistoiaToLuccaActivity_case1::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::trackPistoiaToLuccaActivity_case1::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* AlternationSAN::trackPistoiaToLuccaActivity_case1::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::trackPistoiaToLuccaActivity_case1::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::trackPistoiaToLuccaActivity_case1::Fire(){
  PistoiaToLucca->Mark() --;





  LuccaToViareggio->Mark() ++;
Signal->Mark()=0;
  return this;
}

/*======================trackPistoiaToLuccaActivity_case2========================*/

AlternationSAN::trackPistoiaToLuccaActivity_case2::trackPistoiaToLuccaActivity_case2(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackPistoiaToLucca_case2",3,Exponential, RaceEnabled, 2,5, false);
}

AlternationSAN::trackPistoiaToLuccaActivity_case2::~trackPistoiaToLuccaActivity_case2(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::trackPistoiaToLuccaActivity_case2::LinkVariables(){
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
}

bool AlternationSAN::trackPistoiaToLuccaActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((FaultyTrain->Mark()==0)
 && (PistoiaToLucca->Mark() > 0) 
 && ((LuccaToPistoia->Mark()+LuccaToViareggio->Mark()) < L+1)  
 && (Signal->Mark()==1)
));
  return NewEnabled;
}

double AlternationSAN::trackPistoiaToLuccaActivity_case2::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::trackPistoiaToLuccaActivity_case2::Weight(){ 
  return h;
}

bool AlternationSAN::trackPistoiaToLuccaActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::trackPistoiaToLuccaActivity_case2::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::trackPistoiaToLuccaActivity_case2::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* AlternationSAN::trackPistoiaToLuccaActivity_case2::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::trackPistoiaToLuccaActivity_case2::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::trackPistoiaToLuccaActivity_case2::Fire(){
  PistoiaToLucca->Mark() --;





  (*(FaultyTrain_Mobius_Mark))++;
  return this;
}

/*======================failureActivity========================*/

AlternationSAN::failureActivity::failureActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("failure",4,Exponential, RaceEnabled, 4,1, false);
}

AlternationSAN::failureActivity::~failureActivity(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::failureActivity::LinkVariables(){
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
}

bool AlternationSAN::failureActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(FaultyTrain_Mobius_Mark)) >=1));
  return NewEnabled;
}

double AlternationSAN::failureActivity::Rate(){
  return 2.0/3.0;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::failureActivity::Weight(){ 
  return 1;
}

bool AlternationSAN::failureActivity::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::failureActivity::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::failureActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0/3.0);
}

double* AlternationSAN::failureActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::failureActivity::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::failureActivity::Fire(){
  (*(FaultyTrain_Mobius_Mark))--;
  if ( Signal->Mark()==1 ){
	LuccaToViareggio->Mark() ++;
	Signal->Mark()=0;
}else{
	PistoiaToFlorence->Mark() ++;
	Signal->Mark()=1;
}
  return this;
}

/*======================trackLuccaViareggioActivity========================*/

AlternationSAN::trackLuccaViareggioActivity::trackLuccaViareggioActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackLuccaViareggio",5,Exponential, RaceEnabled, 2,1, false);
}

AlternationSAN::trackLuccaViareggioActivity::~trackLuccaViareggioActivity(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::trackLuccaViareggioActivity::LinkVariables(){
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  ViareggioArrivals->Register(&ViareggioArrivals_Mobius_Mark);
}

bool AlternationSAN::trackLuccaViareggioActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((LuccaToViareggio->Mark() > 0)));
  return NewEnabled;
}

double AlternationSAN::trackLuccaViareggioActivity::Rate(){
  return 1.2;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::trackLuccaViareggioActivity::Weight(){ 
  return 1;
}

bool AlternationSAN::trackLuccaViareggioActivity::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::trackLuccaViareggioActivity::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::trackLuccaViareggioActivity::SampleDistribution(){
  return TheDistribution->Exponential(1.2);
}

double* AlternationSAN::trackLuccaViareggioActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::trackLuccaViareggioActivity::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::trackLuccaViareggioActivity::Fire(){
  LuccaToViareggio->Mark() --;
  (*(ViareggioArrivals_Mobius_Mark))++;
  return this;
}

/*======================trackViareggioLuccaActivity========================*/

AlternationSAN::trackViareggioLuccaActivity::trackViareggioLuccaActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackViareggioLucca",6,Exponential, RaceEnabled, 2,3, false);
}

AlternationSAN::trackViareggioLuccaActivity::~trackViareggioLuccaActivity(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::trackViareggioLuccaActivity::LinkVariables(){
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  ViareggioDepartures->Register(&ViareggioDepartures_Mobius_Mark);
}

bool AlternationSAN::trackViareggioLuccaActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((((LuccaToViareggio->Mark() + LuccaToPistoia->Mark()) < L)
&& (ViareggioDepartures->Mark() > 0)));
  return NewEnabled;
}

double AlternationSAN::trackViareggioLuccaActivity::Rate(){
  return 1.2;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::trackViareggioLuccaActivity::Weight(){ 
  return 1;
}

bool AlternationSAN::trackViareggioLuccaActivity::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::trackViareggioLuccaActivity::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::trackViareggioLuccaActivity::SampleDistribution(){
  return TheDistribution->Exponential(1.2);
}

double* AlternationSAN::trackViareggioLuccaActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::trackViareggioLuccaActivity::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::trackViareggioLuccaActivity::Fire(){
  ViareggioDepartures->Mark() -- ;
  (*(LuccaToPistoia_Mobius_Mark))++;
  return this;
}

/*======================ViareggioCleaningServiceActivity========================*/

AlternationSAN::ViareggioCleaningServiceActivity::ViareggioCleaningServiceActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("ViareggioCleaningService",7,Exponential, RaceEnabled, 2,1, false);
}

AlternationSAN::ViareggioCleaningServiceActivity::~ViareggioCleaningServiceActivity(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::ViareggioCleaningServiceActivity::LinkVariables(){
  ViareggioArrivals->Register(&ViareggioArrivals_Mobius_Mark);
  ViareggioDepartures->Register(&ViareggioDepartures_Mobius_Mark);
}

bool AlternationSAN::ViareggioCleaningServiceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ViareggioArrivals_Mobius_Mark)) >=1));
  return NewEnabled;
}

double AlternationSAN::ViareggioCleaningServiceActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::ViareggioCleaningServiceActivity::Weight(){ 
  return 1;
}

bool AlternationSAN::ViareggioCleaningServiceActivity::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::ViareggioCleaningServiceActivity::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::ViareggioCleaningServiceActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* AlternationSAN::ViareggioCleaningServiceActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::ViareggioCleaningServiceActivity::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::ViareggioCleaningServiceActivity::Fire(){
  (*(ViareggioArrivals_Mobius_Mark))--;
  (*(ViareggioDepartures_Mobius_Mark))++;
  return this;
}

/*======================trackLuccaPistoiaActivity_case1========================*/

AlternationSAN::trackLuccaPistoiaActivity_case1::trackLuccaPistoiaActivity_case1(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackLuccaPistoia_case1",8,Exponential, RaceEnabled, 3,4, false);
}

AlternationSAN::trackLuccaPistoiaActivity_case1::~trackLuccaPistoiaActivity_case1(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::trackLuccaPistoiaActivity_case1::LinkVariables(){
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
}

bool AlternationSAN::trackLuccaPistoiaActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((FaultyTrain->Mark()==0)
 && ( PistoiaToLucca->Mark()  < P +1 ) 
 && (LuccaToPistoia->Mark() > 0) 
 && (Signal->Mark()==0)
));
  return NewEnabled;
}

double AlternationSAN::trackLuccaPistoiaActivity_case1::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::trackLuccaPistoiaActivity_case1::Weight(){ 
  return 1-h;
}

bool AlternationSAN::trackLuccaPistoiaActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::trackLuccaPistoiaActivity_case1::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::trackLuccaPistoiaActivity_case1::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* AlternationSAN::trackLuccaPistoiaActivity_case1::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::trackLuccaPistoiaActivity_case1::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::trackLuccaPistoiaActivity_case1::Fire(){
  LuccaToPistoia->Mark() --;


  PistoiaToFlorence->Mark() ++;
Signal->Mark()=1;
  return this;
}

/*======================trackLuccaPistoiaActivity_case2========================*/

AlternationSAN::trackLuccaPistoiaActivity_case2::trackLuccaPistoiaActivity_case2(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackLuccaPistoia_case2",8,Exponential, RaceEnabled, 2,4, false);
}

AlternationSAN::trackLuccaPistoiaActivity_case2::~trackLuccaPistoiaActivity_case2(){
  delete[] TheDistributionParameters;
}

void AlternationSAN::trackLuccaPistoiaActivity_case2::LinkVariables(){
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
}

bool AlternationSAN::trackLuccaPistoiaActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((FaultyTrain->Mark()==0)
 && ( PistoiaToLucca->Mark()  < P +1 ) 
 && (LuccaToPistoia->Mark() > 0) 
 && (Signal->Mark()==0)
));
  return NewEnabled;
}

double AlternationSAN::trackLuccaPistoiaActivity_case2::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double AlternationSAN::trackLuccaPistoiaActivity_case2::Weight(){ 
  return h;
}

bool AlternationSAN::trackLuccaPistoiaActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool AlternationSAN::trackLuccaPistoiaActivity_case2::ReactivationFunction(){ 
  return false;
}

double AlternationSAN::trackLuccaPistoiaActivity_case2::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* AlternationSAN::trackLuccaPistoiaActivity_case2::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int AlternationSAN::trackLuccaPistoiaActivity_case2::Rank(){
  return 1;
}

BaseActionClass* AlternationSAN::trackLuccaPistoiaActivity_case2::Fire(){
  LuccaToPistoia->Mark() --;


  (*(FaultyTrain_Mobius_Mark))++;
  return this;
}


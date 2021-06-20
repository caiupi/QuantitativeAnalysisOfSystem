

// This C++ file was created by SanEditor

#include "Atomic/LuccaFirst/LuccaFirstSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         LuccaFirstSAN Constructor             
******************************************************************/


LuccaFirstSAN::LuccaFirstSAN(){


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
  LuccaToViareggio = new Place("LuccaToViareggio" ,0);
  LuccaToPistoia = new Place("LuccaToPistoia" ,0);
  ViareggioArrivals = new Place("ViareggioArrivals" ,0);
  ViareggioDepartures = new Place("ViareggioDepartures" ,N);
  SignalFaulty = new Place("SignalFaulty" ,0);
  BaseStateVariableClass* InitialPlaces[11]={
    FlorenceDepartures,  // 0
    FlorenceArrivals,  // 1
    PistoiaToLucca,  // 2
    PistoiaToFlorence,  // 3
    Signal,  // 4
    FaultyTrain,  // 5
    LuccaToViareggio,  // 6
    LuccaToPistoia,  // 7
    ViareggioArrivals,  // 8
    ViareggioDepartures,  // 9
    SignalFaulty   // 10
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("LuccaFirst", 11, InitialPlaces, 
                        0, InitialROPlaces, 
                        11, InitialActionList, 9, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[30][2]={ 
    {1,0}, {0,0}, {2,1}, {0,1}, {1,2}, {3,2}, {2,3}, {4,3}, {6,3}, 
    {5,4}, {10,4}, {2,4}, {4,4}, {7,5}, {4,5}, {3,5}, {5,6}, 
    {7,6}, {4,6}, {5,7}, {10,7}, {6,7}, {4,7}, {3,7}, {8,8}, 
    {6,8}, {7,9}, {9,9}, {8,10}, {9,10}
  };
  for(int n=0;n<30;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[23][2]={ 
    {1,0}, {2,1}, {3,1}, {0,1}, {3,2}, {2,3}, {7,3}, {4,3}, {2,4}, 
    {7,4}, {4,4}, {2,5}, {7,5}, {4,5}, {2,6}, {7,6}, {4,6}, {5,7}, 
    {6,8}, {6,9}, {7,9}, {9,9}, {8,10}
  };
  for(int n=0;n<23;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<11;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void LuccaFirstSAN::CustomInitialization() {

}
LuccaFirstSAN::~LuccaFirstSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void LuccaFirstSAN::assignPlacesToActivitiesInst(){
}
void LuccaFirstSAN::assignPlacesToActivitiesTimed(){
  FlorenceCleaningService.FlorenceArrivals = (Place*) LocalStateVariables[1];
  FlorenceCleaningService.FlorenceDepartures = (Place*) LocalStateVariables[0];
  trackFlorencePistoia.PistoiaToLucca = (Place*) LocalStateVariables[2];
  trackFlorencePistoia.PistoiaToFlorence = (Place*) LocalStateVariables[3];
  trackFlorencePistoia.FlorenceDepartures = (Place*) LocalStateVariables[0];
  trackPistoiaFlorence.PistoiaToFlorence = (Place*) LocalStateVariables[3];
  trackPistoiaFlorence.FlorenceArrivals = (Place*) LocalStateVariables[1];
  trackPistoiaToLucca_case1.PistoiaToLucca = (Place*) LocalStateVariables[2];
  trackPistoiaToLucca_case1.LuccaToPistoia = (Place*) LocalStateVariables[7];
  trackPistoiaToLucca_case1.Signal = (Place*) LocalStateVariables[4];
  trackPistoiaToLucca_case1.LuccaToViareggio = (Place*) LocalStateVariables[6];
  trackPistoiaToLucca_case2.PistoiaToLucca = (Place*) LocalStateVariables[2];
  trackPistoiaToLucca_case2.LuccaToPistoia = (Place*) LocalStateVariables[7];
  trackPistoiaToLucca_case2.Signal = (Place*) LocalStateVariables[4];
  trackPistoiaToLucca_case2.FaultyTrain = (Place*) LocalStateVariables[5];
  trackPistoiaToLucca_case2.SignalFaulty = (Place*) LocalStateVariables[10];
  trackLuccaPistoia_case1.PistoiaToLucca = (Place*) LocalStateVariables[2];
  trackLuccaPistoia_case1.LuccaToPistoia = (Place*) LocalStateVariables[7];
  trackLuccaPistoia_case1.Signal = (Place*) LocalStateVariables[4];
  trackLuccaPistoia_case1.PistoiaToFlorence = (Place*) LocalStateVariables[3];
  trackLuccaPistoia_case2.PistoiaToLucca = (Place*) LocalStateVariables[2];
  trackLuccaPistoia_case2.LuccaToPistoia = (Place*) LocalStateVariables[7];
  trackLuccaPistoia_case2.Signal = (Place*) LocalStateVariables[4];
  trackLuccaPistoia_case2.FaultyTrain = (Place*) LocalStateVariables[5];
  failure.FaultyTrain = (Place*) LocalStateVariables[5];
  failure.SignalFaulty = (Place*) LocalStateVariables[10];
  failure.LuccaToViareggio = (Place*) LocalStateVariables[6];
  failure.Signal = (Place*) LocalStateVariables[4];
  failure.PistoiaToFlorence = (Place*) LocalStateVariables[3];
  trackLuccaViareggio.LuccaToViareggio = (Place*) LocalStateVariables[6];
  trackLuccaViareggio.ViareggioArrivals = (Place*) LocalStateVariables[8];
  trackViareggioLucca.LuccaToViareggio = (Place*) LocalStateVariables[6];
  trackViareggioLucca.LuccaToPistoia = (Place*) LocalStateVariables[7];
  trackViareggioLucca.ViareggioDepartures = (Place*) LocalStateVariables[9];
  ViareggioCleaningService.ViareggioArrivals = (Place*) LocalStateVariables[8];
  ViareggioCleaningService.ViareggioDepartures = (Place*) LocalStateVariables[9];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================FlorenceCleaningServiceActivity========================*/

LuccaFirstSAN::FlorenceCleaningServiceActivity::FlorenceCleaningServiceActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("FlorenceCleaningService",0,Exponential, RaceEnabled, 2,1, false);
}

LuccaFirstSAN::FlorenceCleaningServiceActivity::~FlorenceCleaningServiceActivity(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::FlorenceCleaningServiceActivity::LinkVariables(){
  FlorenceArrivals->Register(&FlorenceArrivals_Mobius_Mark);
  FlorenceDepartures->Register(&FlorenceDepartures_Mobius_Mark);
}

bool LuccaFirstSAN::FlorenceCleaningServiceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(FlorenceArrivals_Mobius_Mark)) >=1));
  return NewEnabled;
}

double LuccaFirstSAN::FlorenceCleaningServiceActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::FlorenceCleaningServiceActivity::Weight(){ 
  return 1;
}

bool LuccaFirstSAN::FlorenceCleaningServiceActivity::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::FlorenceCleaningServiceActivity::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::FlorenceCleaningServiceActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* LuccaFirstSAN::FlorenceCleaningServiceActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::FlorenceCleaningServiceActivity::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::FlorenceCleaningServiceActivity::Fire(){
  (*(FlorenceArrivals_Mobius_Mark))--;
  (*(FlorenceDepartures_Mobius_Mark))++;
  return this;
}

/*======================trackFlorencePistoiaActivity========================*/

LuccaFirstSAN::trackFlorencePistoiaActivity::trackFlorencePistoiaActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackFlorencePistoia",1,Exponential, RaceEnabled, 2,3, false);
}

LuccaFirstSAN::trackFlorencePistoiaActivity::~trackFlorencePistoiaActivity(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::trackFlorencePistoiaActivity::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
  FlorenceDepartures->Register(&FlorenceDepartures_Mobius_Mark);
}

bool LuccaFirstSAN::trackFlorencePistoiaActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((((PistoiaToLucca->Mark() + PistoiaToFlorence->Mark()) < P)
&& (FlorenceDepartures->Mark() > 0)));
  return NewEnabled;
}

double LuccaFirstSAN::trackFlorencePistoiaActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::trackFlorencePistoiaActivity::Weight(){ 
  return 1;
}

bool LuccaFirstSAN::trackFlorencePistoiaActivity::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::trackFlorencePistoiaActivity::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::trackFlorencePistoiaActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* LuccaFirstSAN::trackFlorencePistoiaActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::trackFlorencePistoiaActivity::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::trackFlorencePistoiaActivity::Fire(){
  FlorenceDepartures->Mark()--;
  (*(PistoiaToLucca_Mobius_Mark))++;
  return this;
}

/*======================trackPistoiaFlorenceActivity========================*/

LuccaFirstSAN::trackPistoiaFlorenceActivity::trackPistoiaFlorenceActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackPistoiaFlorence",2,Exponential, RaceEnabled, 2,1, false);
}

LuccaFirstSAN::trackPistoiaFlorenceActivity::~trackPistoiaFlorenceActivity(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::trackPistoiaFlorenceActivity::LinkVariables(){
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
  FlorenceArrivals->Register(&FlorenceArrivals_Mobius_Mark);
}

bool LuccaFirstSAN::trackPistoiaFlorenceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((( PistoiaToFlorence->Mark() > 0 )));
  return NewEnabled;
}

double LuccaFirstSAN::trackPistoiaFlorenceActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::trackPistoiaFlorenceActivity::Weight(){ 
  return 1;
}

bool LuccaFirstSAN::trackPistoiaFlorenceActivity::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::trackPistoiaFlorenceActivity::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::trackPistoiaFlorenceActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* LuccaFirstSAN::trackPistoiaFlorenceActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::trackPistoiaFlorenceActivity::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::trackPistoiaFlorenceActivity::Fire(){
  PistoiaToFlorence->Mark()--;
  (*(FlorenceArrivals_Mobius_Mark))++;
  return this;
}

/*======================trackPistoiaToLuccaActivity_case1========================*/

LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::trackPistoiaToLuccaActivity_case1(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackPistoiaToLucca_case1",3,Exponential, RaceEnabled, 3,3, false);
}

LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::~trackPistoiaToLuccaActivity_case1(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
}

bool LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PistoiaToLucca->Mark() > 0) 
 && (LuccaToPistoia->Mark()==0) 
 && (Signal->Mark()==1)
));
  return NewEnabled;
}

double LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::Weight(){ 
  return 1-h;
}

bool LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::trackPistoiaToLuccaActivity_case1::Fire(){
  PistoiaToLucca->Mark() --;
Signal->Mark()=0;




  LuccaToViareggio->Mark() ++;
Signal->Mark()=1;
  return this;
}

/*======================trackPistoiaToLuccaActivity_case2========================*/

LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::trackPistoiaToLuccaActivity_case2(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackPistoiaToLucca_case2",3,Exponential, RaceEnabled, 4,3, false);
}

LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::~trackPistoiaToLuccaActivity_case2(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
  SignalFaulty->Register(&SignalFaulty_Mobius_Mark);
}

bool LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PistoiaToLucca->Mark() > 0) 
 && (LuccaToPistoia->Mark()==0) 
 && (Signal->Mark()==1)
));
  return NewEnabled;
}

double LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::Weight(){ 
  return h;
}

bool LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::trackPistoiaToLuccaActivity_case2::Fire(){
  PistoiaToLucca->Mark() --;
Signal->Mark()=0;




  (*(FaultyTrain_Mobius_Mark))++;
  (*(SignalFaulty_Mobius_Mark))++;
  return this;
}

/*======================trackLuccaPistoiaActivity_case1========================*/

LuccaFirstSAN::trackLuccaPistoiaActivity_case1::trackLuccaPistoiaActivity_case1(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackLuccaPistoia_case1",4,Exponential, RaceEnabled, 3,3, false);
}

LuccaFirstSAN::trackLuccaPistoiaActivity_case1::~trackLuccaPistoiaActivity_case1(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::trackLuccaPistoiaActivity_case1::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
}

bool LuccaFirstSAN::trackLuccaPistoiaActivity_case1::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((( PistoiaToLucca->Mark()  < P +1 ) 
 && (LuccaToPistoia->Mark() > 0) 
 && (Signal->Mark()==1)
));
  return NewEnabled;
}

double LuccaFirstSAN::trackLuccaPistoiaActivity_case1::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::trackLuccaPistoiaActivity_case1::Weight(){ 
  return 1-h;
}

bool LuccaFirstSAN::trackLuccaPistoiaActivity_case1::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::trackLuccaPistoiaActivity_case1::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::trackLuccaPistoiaActivity_case1::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* LuccaFirstSAN::trackLuccaPistoiaActivity_case1::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::trackLuccaPistoiaActivity_case1::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::trackLuccaPistoiaActivity_case1::Fire(){
  LuccaToPistoia->Mark() --;
Signal->Mark()=0;
  PistoiaToFlorence->Mark() ++;
Signal->Mark()=1;
  return this;
}

/*======================trackLuccaPistoiaActivity_case2========================*/

LuccaFirstSAN::trackLuccaPistoiaActivity_case2::trackLuccaPistoiaActivity_case2(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackLuccaPistoia_case2",4,Exponential, RaceEnabled, 3,3, false);
}

LuccaFirstSAN::trackLuccaPistoiaActivity_case2::~trackLuccaPistoiaActivity_case2(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::trackLuccaPistoiaActivity_case2::LinkVariables(){
  PistoiaToLucca->Register(&PistoiaToLucca_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
}

bool LuccaFirstSAN::trackLuccaPistoiaActivity_case2::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((( PistoiaToLucca->Mark()  < P +1 ) 
 && (LuccaToPistoia->Mark() > 0) 
 && (Signal->Mark()==1)
));
  return NewEnabled;
}

double LuccaFirstSAN::trackLuccaPistoiaActivity_case2::Rate(){
  return 1.5;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::trackLuccaPistoiaActivity_case2::Weight(){ 
  return h;
}

bool LuccaFirstSAN::trackLuccaPistoiaActivity_case2::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::trackLuccaPistoiaActivity_case2::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::trackLuccaPistoiaActivity_case2::SampleDistribution(){
  return TheDistribution->Exponential(1.5);
}

double* LuccaFirstSAN::trackLuccaPistoiaActivity_case2::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::trackLuccaPistoiaActivity_case2::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::trackLuccaPistoiaActivity_case2::Fire(){
  LuccaToPistoia->Mark() --;
Signal->Mark()=0;
  (*(FaultyTrain_Mobius_Mark))++;
  return this;
}

/*======================failureActivity========================*/

LuccaFirstSAN::failureActivity::failureActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("failure",5,Exponential, RaceEnabled, 5,1, false);
}

LuccaFirstSAN::failureActivity::~failureActivity(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::failureActivity::LinkVariables(){
  FaultyTrain->Register(&FaultyTrain_Mobius_Mark);
  SignalFaulty->Register(&SignalFaulty_Mobius_Mark);
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  Signal->Register(&Signal_Mobius_Mark);
  PistoiaToFlorence->Register(&PistoiaToFlorence_Mobius_Mark);
}

bool LuccaFirstSAN::failureActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(FaultyTrain_Mobius_Mark)) >=1));
  return NewEnabled;
}

double LuccaFirstSAN::failureActivity::Rate(){
  return 2.0/3.0;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::failureActivity::Weight(){ 
  return 1;
}

bool LuccaFirstSAN::failureActivity::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::failureActivity::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::failureActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0/3.0);
}

double* LuccaFirstSAN::failureActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::failureActivity::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::failureActivity::Fire(){
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

LuccaFirstSAN::trackLuccaViareggioActivity::trackLuccaViareggioActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackLuccaViareggio",6,Exponential, RaceEnabled, 2,1, false);
}

LuccaFirstSAN::trackLuccaViareggioActivity::~trackLuccaViareggioActivity(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::trackLuccaViareggioActivity::LinkVariables(){
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  ViareggioArrivals->Register(&ViareggioArrivals_Mobius_Mark);
}

bool LuccaFirstSAN::trackLuccaViareggioActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((LuccaToViareggio->Mark() > 0)));
  return NewEnabled;
}

double LuccaFirstSAN::trackLuccaViareggioActivity::Rate(){
  return 1.2;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::trackLuccaViareggioActivity::Weight(){ 
  return 1;
}

bool LuccaFirstSAN::trackLuccaViareggioActivity::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::trackLuccaViareggioActivity::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::trackLuccaViareggioActivity::SampleDistribution(){
  return TheDistribution->Exponential(1.2);
}

double* LuccaFirstSAN::trackLuccaViareggioActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::trackLuccaViareggioActivity::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::trackLuccaViareggioActivity::Fire(){
  LuccaToViareggio->Mark() --;
  (*(ViareggioArrivals_Mobius_Mark))++;
  return this;
}

/*======================trackViareggioLuccaActivity========================*/

LuccaFirstSAN::trackViareggioLuccaActivity::trackViareggioLuccaActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("trackViareggioLucca",7,Exponential, RaceEnabled, 2,3, false);
}

LuccaFirstSAN::trackViareggioLuccaActivity::~trackViareggioLuccaActivity(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::trackViareggioLuccaActivity::LinkVariables(){
  LuccaToViareggio->Register(&LuccaToViareggio_Mobius_Mark);
  LuccaToPistoia->Register(&LuccaToPistoia_Mobius_Mark);
  ViareggioDepartures->Register(&ViareggioDepartures_Mobius_Mark);
}

bool LuccaFirstSAN::trackViareggioLuccaActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((((LuccaToViareggio->Mark() + LuccaToPistoia->Mark()) < L)
&& (ViareggioDepartures->Mark() > 0)));
  return NewEnabled;
}

double LuccaFirstSAN::trackViareggioLuccaActivity::Rate(){
  return 1.2;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::trackViareggioLuccaActivity::Weight(){ 
  return 1;
}

bool LuccaFirstSAN::trackViareggioLuccaActivity::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::trackViareggioLuccaActivity::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::trackViareggioLuccaActivity::SampleDistribution(){
  return TheDistribution->Exponential(1.2);
}

double* LuccaFirstSAN::trackViareggioLuccaActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::trackViareggioLuccaActivity::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::trackViareggioLuccaActivity::Fire(){
  ViareggioDepartures->Mark() -- ;
  (*(LuccaToPistoia_Mobius_Mark))++;
  return this;
}

/*======================ViareggioCleaningServiceActivity========================*/

LuccaFirstSAN::ViareggioCleaningServiceActivity::ViareggioCleaningServiceActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("ViareggioCleaningService",8,Exponential, RaceEnabled, 2,1, false);
}

LuccaFirstSAN::ViareggioCleaningServiceActivity::~ViareggioCleaningServiceActivity(){
  delete[] TheDistributionParameters;
}

void LuccaFirstSAN::ViareggioCleaningServiceActivity::LinkVariables(){
  ViareggioArrivals->Register(&ViareggioArrivals_Mobius_Mark);
  ViareggioDepartures->Register(&ViareggioDepartures_Mobius_Mark);
}

bool LuccaFirstSAN::ViareggioCleaningServiceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(ViareggioArrivals_Mobius_Mark)) >=1));
  return NewEnabled;
}

double LuccaFirstSAN::ViareggioCleaningServiceActivity::Rate(){
  return 2.0;
  return 1.0;  // default rate if none is specified
}

double LuccaFirstSAN::ViareggioCleaningServiceActivity::Weight(){ 
  return 1;
}

bool LuccaFirstSAN::ViareggioCleaningServiceActivity::ReactivationPredicate(){ 
  return false;
}

bool LuccaFirstSAN::ViareggioCleaningServiceActivity::ReactivationFunction(){ 
  return false;
}

double LuccaFirstSAN::ViareggioCleaningServiceActivity::SampleDistribution(){
  return TheDistribution->Exponential(2.0);
}

double* LuccaFirstSAN::ViareggioCleaningServiceActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int LuccaFirstSAN::ViareggioCleaningServiceActivity::Rank(){
  return 1;
}

BaseActionClass* LuccaFirstSAN::ViareggioCleaningServiceActivity::Fire(){
  (*(ViareggioArrivals_Mobius_Mark))--;
  (*(ViareggioDepartures_Mobius_Mark))++;
  return this;
}


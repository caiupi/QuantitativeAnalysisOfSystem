#ifndef AlternationSAN_H_
#define AlternationSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Int N;
extern Int P;
extern Int L;
extern Double h;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               AlternationSAN Submodel Definition                   
*********************************************************************/

class AlternationSAN:public SANModel{
public:

class trackFlorencePistoiaActivity:public Activity {
public:

  Place* PistoiaToLucca;
  short* PistoiaToLucca_Mobius_Mark;
  Place* PistoiaToFlorence;
  short* PistoiaToFlorence_Mobius_Mark;
  Place* FlorenceDepartures;
  short* FlorenceDepartures_Mobius_Mark;

  double* TheDistributionParameters;
  trackFlorencePistoiaActivity();
  ~trackFlorencePistoiaActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // trackFlorencePistoiaActivityActivity

class FlorenceCleaningServiceActivity:public Activity {
public:

  Place* FlorenceArrivals;
  short* FlorenceArrivals_Mobius_Mark;
  Place* FlorenceDepartures;
  short* FlorenceDepartures_Mobius_Mark;

  double* TheDistributionParameters;
  FlorenceCleaningServiceActivity();
  ~FlorenceCleaningServiceActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // FlorenceCleaningServiceActivityActivity

class trackPistoiaFlorenceActivity:public Activity {
public:

  Place* PistoiaToFlorence;
  short* PistoiaToFlorence_Mobius_Mark;
  Place* FlorenceArrivals;
  short* FlorenceArrivals_Mobius_Mark;

  double* TheDistributionParameters;
  trackPistoiaFlorenceActivity();
  ~trackPistoiaFlorenceActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // trackPistoiaFlorenceActivityActivity

class trackPistoiaToLuccaActivity_case1:public Activity {
public:

  Place* FaultyTrain;
  short* FaultyTrain_Mobius_Mark;
  Place* PistoiaToLucca;
  short* PistoiaToLucca_Mobius_Mark;
  Place* LuccaToPistoia;
  short* LuccaToPistoia_Mobius_Mark;
  Place* LuccaToViareggio;
  short* LuccaToViareggio_Mobius_Mark;
  Place* Signal;
  short* Signal_Mobius_Mark;

  double* TheDistributionParameters;
  trackPistoiaToLuccaActivity_case1();
  ~trackPistoiaToLuccaActivity_case1();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // trackPistoiaToLuccaActivity_case1Activity

class trackPistoiaToLuccaActivity_case2:public Activity {
public:

  Place* FaultyTrain;
  short* FaultyTrain_Mobius_Mark;
  Place* PistoiaToLucca;
  short* PistoiaToLucca_Mobius_Mark;
  Place* LuccaToPistoia;
  short* LuccaToPistoia_Mobius_Mark;
  Place* LuccaToViareggio;
  short* LuccaToViareggio_Mobius_Mark;
  Place* Signal;
  short* Signal_Mobius_Mark;

  double* TheDistributionParameters;
  trackPistoiaToLuccaActivity_case2();
  ~trackPistoiaToLuccaActivity_case2();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // trackPistoiaToLuccaActivity_case2Activity

class failureActivity:public Activity {
public:

  Place* FaultyTrain;
  short* FaultyTrain_Mobius_Mark;
  Place* Signal;
  short* Signal_Mobius_Mark;
  Place* LuccaToViareggio;
  short* LuccaToViareggio_Mobius_Mark;
  Place* PistoiaToFlorence;
  short* PistoiaToFlorence_Mobius_Mark;

  double* TheDistributionParameters;
  failureActivity();
  ~failureActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // failureActivityActivity

class trackLuccaViareggioActivity:public Activity {
public:

  Place* LuccaToViareggio;
  short* LuccaToViareggio_Mobius_Mark;
  Place* ViareggioArrivals;
  short* ViareggioArrivals_Mobius_Mark;

  double* TheDistributionParameters;
  trackLuccaViareggioActivity();
  ~trackLuccaViareggioActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // trackLuccaViareggioActivityActivity

class trackViareggioLuccaActivity:public Activity {
public:

  Place* LuccaToViareggio;
  short* LuccaToViareggio_Mobius_Mark;
  Place* LuccaToPistoia;
  short* LuccaToPistoia_Mobius_Mark;
  Place* ViareggioDepartures;
  short* ViareggioDepartures_Mobius_Mark;

  double* TheDistributionParameters;
  trackViareggioLuccaActivity();
  ~trackViareggioLuccaActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // trackViareggioLuccaActivityActivity

class ViareggioCleaningServiceActivity:public Activity {
public:

  Place* ViareggioArrivals;
  short* ViareggioArrivals_Mobius_Mark;
  Place* ViareggioDepartures;
  short* ViareggioDepartures_Mobius_Mark;

  double* TheDistributionParameters;
  ViareggioCleaningServiceActivity();
  ~ViareggioCleaningServiceActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // ViareggioCleaningServiceActivityActivity

class trackLuccaPistoiaActivity_case1:public Activity {
public:

  Place* FaultyTrain;
  short* FaultyTrain_Mobius_Mark;
  Place* PistoiaToLucca;
  short* PistoiaToLucca_Mobius_Mark;
  Place* LuccaToPistoia;
  short* LuccaToPistoia_Mobius_Mark;
  Place* Signal;
  short* Signal_Mobius_Mark;
  Place* PistoiaToFlorence;
  short* PistoiaToFlorence_Mobius_Mark;

  double* TheDistributionParameters;
  trackLuccaPistoiaActivity_case1();
  ~trackLuccaPistoiaActivity_case1();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // trackLuccaPistoiaActivity_case1Activity

class trackLuccaPistoiaActivity_case2:public Activity {
public:

  Place* FaultyTrain;
  short* FaultyTrain_Mobius_Mark;
  Place* PistoiaToLucca;
  short* PistoiaToLucca_Mobius_Mark;
  Place* LuccaToPistoia;
  short* LuccaToPistoia_Mobius_Mark;
  Place* Signal;
  short* Signal_Mobius_Mark;

  double* TheDistributionParameters;
  trackLuccaPistoiaActivity_case2();
  ~trackLuccaPistoiaActivity_case2();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // trackLuccaPistoiaActivity_case2Activity

  //List of user-specified place names
  Place* FlorenceDepartures;
  Place* PistoiaToLucca;
  Place* PistoiaToFlorence;
  Place* FlorenceArrivals;
  Place* FaultyTrain;
  Place* LuccaToViareggio;
  Place* LuccaToPistoia;
  Place* ViareggioArrivals;
  Place* ViareggioDepartures;
  Place* Signal;

  // Create instances of all actvities
  trackFlorencePistoiaActivity trackFlorencePistoia;
  FlorenceCleaningServiceActivity FlorenceCleaningService;
  trackPistoiaFlorenceActivity trackPistoiaFlorence;
  trackPistoiaToLuccaActivity_case1 trackPistoiaToLucca_case1;
  trackPistoiaToLuccaActivity_case2 trackPistoiaToLucca_case2;
  failureActivity failure;
  trackLuccaViareggioActivity trackLuccaViareggio;
  trackViareggioLuccaActivity trackViareggioLucca;
  ViareggioCleaningServiceActivity ViareggioCleaningService;
  trackLuccaPistoiaActivity_case1 trackLuccaPistoia_case1;
  trackLuccaPistoiaActivity_case2 trackLuccaPistoia_case2;
  //Create instances of all groups 
  EmptyGroup ImmediateGroup;
  PostselectGroup trackPistoiaToLuccaGroup;  PostselectGroup trackLuccaPistoiaGroup;
  AlternationSAN();
  ~AlternationSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end AlternationSAN

#endif // AlternationSAN_H_

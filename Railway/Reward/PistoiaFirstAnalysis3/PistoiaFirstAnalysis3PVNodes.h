#ifndef _PISTOIAFIRSTANALYSIS3_PVS_
#define _PISTOIAFIRSTANALYSIS3_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/PistoiaFirst/PistoiaFirstSAN.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"



class PistoiaFirstAnalysis3PV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  PistoiaFirstSAN *PistoiaFirst;

  PistoiaFirstAnalysis3PV0Impulse0();
  ~PistoiaFirstAnalysis3PV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class PistoiaFirstAnalysis3PV0Impulse1:public IntervalOfTimeImpulse
{
 public:
  PistoiaFirstSAN *PistoiaFirst;

  PistoiaFirstAnalysis3PV0Impulse1();
  ~PistoiaFirstAnalysis3PV0Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class PistoiaFirstAnalysis3PV0:public PerformanceVariableNode
{
 public:
  PistoiaFirstSAN *ThePistoiaFirstSAN;

  PistoiaFirstAnalysis3PV0Impulse0 Impulse0;
  PistoiaFirstAnalysis3PV0Impulse1 Impulse1;

  PistoiaFirstAnalysis3PV0(int timeindex=0);
  ~PistoiaFirstAnalysis3PV0();
  void CreateWorkerList(void);
};

#endif

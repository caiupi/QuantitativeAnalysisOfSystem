#ifndef _PISTOIAFIRSTANALYSIS2_PVS_
#define _PISTOIAFIRSTANALYSIS2_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/PistoiaFirst/PistoiaFirstSAN.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"



class PistoiaFirstAnalysis2PV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  PistoiaFirstSAN *PistoiaFirst;

  PistoiaFirstAnalysis2PV0Impulse0();
  ~PistoiaFirstAnalysis2PV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class PistoiaFirstAnalysis2PV0Impulse1:public IntervalOfTimeImpulse
{
 public:
  PistoiaFirstSAN *PistoiaFirst;

  PistoiaFirstAnalysis2PV0Impulse1();
  ~PistoiaFirstAnalysis2PV0Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class PistoiaFirstAnalysis2PV0:public PerformanceVariableNode
{
 public:
  PistoiaFirstSAN *ThePistoiaFirstSAN;

  PistoiaFirstAnalysis2PV0Impulse0 Impulse0;
  PistoiaFirstAnalysis2PV0Impulse1 Impulse1;

  PistoiaFirstAnalysis2PV0(int timeindex=0);
  ~PistoiaFirstAnalysis2PV0();
  void CreateWorkerList(void);
};

#endif

#ifndef _ALTERNATIONANALYSIS2_PVS_
#define _ALTERNATIONANALYSIS2_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/Alternation/AlternationSAN.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"



class AlternationAnalysis2PV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  AlternationSAN *Alternation;

  AlternationAnalysis2PV0Impulse0();
  ~AlternationAnalysis2PV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class AlternationAnalysis2PV0Impulse1:public IntervalOfTimeImpulse
{
 public:
  AlternationSAN *Alternation;

  AlternationAnalysis2PV0Impulse1();
  ~AlternationAnalysis2PV0Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class AlternationAnalysis2PV0:public PerformanceVariableNode
{
 public:
  AlternationSAN *TheAlternationSAN;

  AlternationAnalysis2PV0Impulse0 Impulse0;
  AlternationAnalysis2PV0Impulse1 Impulse1;

  AlternationAnalysis2PV0(int timeindex=0);
  ~AlternationAnalysis2PV0();
  void CreateWorkerList(void);
};

#endif

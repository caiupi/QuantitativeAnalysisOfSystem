#ifndef _LUCCAFIRSTANALYSIS3_PVS_
#define _LUCCAFIRSTANALYSIS3_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/LuccaFirst/LuccaFirstSAN.h"
#include "Cpp/Performance_Variables/IntervalOfTime.hpp"
#include "Cpp/Performance_Variables/IntervalOfTimeImpulse.hpp"



class LuccaFirstAnalysis3PV0Impulse0:public IntervalOfTimeImpulse
{
 public:
  LuccaFirstSAN *LuccaFirst;

  LuccaFirstAnalysis3PV0Impulse0();
  ~LuccaFirstAnalysis3PV0Impulse0();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};


class LuccaFirstAnalysis3PV0Impulse1:public IntervalOfTimeImpulse
{
 public:
  LuccaFirstSAN *LuccaFirst;

  LuccaFirstAnalysis3PV0Impulse1();
  ~LuccaFirstAnalysis3PV0Impulse1();
  double Impulse_Function(double);
  ImpulseNodeClass** CreateImpulseWorkerList(int);
 private:
  ImpulseNodeClass** ImpulseWorkerList;
  int ImpulseWorkerListLength;
};

class LuccaFirstAnalysis3PV0:public PerformanceVariableNode
{
 public:
  LuccaFirstSAN *TheLuccaFirstSAN;

  LuccaFirstAnalysis3PV0Impulse0 Impulse0;
  LuccaFirstAnalysis3PV0Impulse1 Impulse1;

  LuccaFirstAnalysis3PV0(int timeindex=0);
  ~LuccaFirstAnalysis3PV0();
  void CreateWorkerList(void);
};

#endif

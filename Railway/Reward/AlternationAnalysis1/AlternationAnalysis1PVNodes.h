#ifndef _ALTERNATIONANALYSIS1_PVS_
#define _ALTERNATIONANALYSIS1_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/Alternation/AlternationSAN.h"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"
#include "Cpp/Performance_Variables/SteadyState.hpp"


class AlternationAnalysis1PV0Worker:public InstantOfTime
{
 public:
  AlternationSAN *Alternation;
  
  AlternationAnalysis1PV0Worker();
  ~AlternationAnalysis1PV0Worker();
  double Reward_Function();
};

class AlternationAnalysis1PV0:public PerformanceVariableNode
{
 public:
  AlternationSAN *TheAlternationSAN;

  AlternationAnalysis1PV0Worker *AlternationAnalysis1PV0WorkerList;

  AlternationAnalysis1PV0(int timeindex=0);
  ~AlternationAnalysis1PV0();
  void CreateWorkerList(void);
};

class AlternationAnalysis1PV1Worker:public InstantOfTime
{
 public:
  AlternationSAN *Alternation;
  
  AlternationAnalysis1PV1Worker();
  ~AlternationAnalysis1PV1Worker();
  double Reward_Function();
};

class AlternationAnalysis1PV1:public PerformanceVariableNode
{
 public:
  AlternationSAN *TheAlternationSAN;

  AlternationAnalysis1PV1Worker *AlternationAnalysis1PV1WorkerList;

  AlternationAnalysis1PV1(int timeindex=0);
  ~AlternationAnalysis1PV1();
  void CreateWorkerList(void);
};

class AlternationAnalysis1PV2Worker:public InstantOfTime
{
 public:
  AlternationSAN *Alternation;
  
  AlternationAnalysis1PV2Worker();
  ~AlternationAnalysis1PV2Worker();
  double Reward_Function();
};

class AlternationAnalysis1PV2:public PerformanceVariableNode
{
 public:
  AlternationSAN *TheAlternationSAN;

  AlternationAnalysis1PV2Worker *AlternationAnalysis1PV2WorkerList;

  AlternationAnalysis1PV2(int timeindex=0);
  ~AlternationAnalysis1PV2();
  void CreateWorkerList(void);
};

class AlternationAnalysis1PV3Worker:public InstantOfTime
{
 public:
  AlternationSAN *Alternation;
  
  AlternationAnalysis1PV3Worker();
  ~AlternationAnalysis1PV3Worker();
  double Reward_Function();
};

class AlternationAnalysis1PV3:public PerformanceVariableNode
{
 public:
  AlternationSAN *TheAlternationSAN;

  AlternationAnalysis1PV3Worker *AlternationAnalysis1PV3WorkerList;

  AlternationAnalysis1PV3(int timeindex=0);
  ~AlternationAnalysis1PV3();
  void CreateWorkerList(void);
};

class AlternationAnalysis1PV4Worker:public SteadyState
{
 public:
  AlternationSAN *Alternation;
  
  AlternationAnalysis1PV4Worker();
  ~AlternationAnalysis1PV4Worker();
  double Reward_Function();
};

class AlternationAnalysis1PV4:public PerformanceVariableNode
{
 public:
  AlternationSAN *TheAlternationSAN;

  AlternationAnalysis1PV4Worker *AlternationAnalysis1PV4WorkerList;

  AlternationAnalysis1PV4(int timeindex=0);
  ~AlternationAnalysis1PV4();
  void CreateWorkerList(void);
};

class AlternationAnalysis1PV5Worker:public SteadyState
{
 public:
  AlternationSAN *Alternation;
  
  AlternationAnalysis1PV5Worker();
  ~AlternationAnalysis1PV5Worker();
  double Reward_Function();
};

class AlternationAnalysis1PV5:public PerformanceVariableNode
{
 public:
  AlternationSAN *TheAlternationSAN;

  AlternationAnalysis1PV5Worker *AlternationAnalysis1PV5WorkerList;

  AlternationAnalysis1PV5(int timeindex=0);
  ~AlternationAnalysis1PV5();
  void CreateWorkerList(void);
};

class AlternationAnalysis1PV6Worker:public SteadyState
{
 public:
  AlternationSAN *Alternation;
  
  AlternationAnalysis1PV6Worker();
  ~AlternationAnalysis1PV6Worker();
  double Reward_Function();
};

class AlternationAnalysis1PV6:public PerformanceVariableNode
{
 public:
  AlternationSAN *TheAlternationSAN;

  AlternationAnalysis1PV6Worker *AlternationAnalysis1PV6WorkerList;

  AlternationAnalysis1PV6(int timeindex=0);
  ~AlternationAnalysis1PV6();
  void CreateWorkerList(void);
};

class AlternationAnalysis1PV7Worker:public SteadyState
{
 public:
  AlternationSAN *Alternation;
  
  AlternationAnalysis1PV7Worker();
  ~AlternationAnalysis1PV7Worker();
  double Reward_Function();
};

class AlternationAnalysis1PV7:public PerformanceVariableNode
{
 public:
  AlternationSAN *TheAlternationSAN;

  AlternationAnalysis1PV7Worker *AlternationAnalysis1PV7WorkerList;

  AlternationAnalysis1PV7(int timeindex=0);
  ~AlternationAnalysis1PV7();
  void CreateWorkerList(void);
};

#endif

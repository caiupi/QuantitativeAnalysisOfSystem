#ifndef _LUCCAFIRSTANALISYS1_PVS_
#define _LUCCAFIRSTANALISYS1_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/LuccaFirst/LuccaFirstSAN.h"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"
#include "Cpp/Performance_Variables/SteadyState.hpp"


class LuccaFirstAnalisys1PV0Worker:public InstantOfTime
{
 public:
  LuccaFirstSAN *LuccaFirst;
  
  LuccaFirstAnalisys1PV0Worker();
  ~LuccaFirstAnalisys1PV0Worker();
  double Reward_Function();
};

class LuccaFirstAnalisys1PV0:public PerformanceVariableNode
{
 public:
  LuccaFirstSAN *TheLuccaFirstSAN;

  LuccaFirstAnalisys1PV0Worker *LuccaFirstAnalisys1PV0WorkerList;

  LuccaFirstAnalisys1PV0(int timeindex=0);
  ~LuccaFirstAnalisys1PV0();
  void CreateWorkerList(void);
};

class LuccaFirstAnalisys1PV1Worker:public InstantOfTime
{
 public:
  LuccaFirstSAN *LuccaFirst;
  
  LuccaFirstAnalisys1PV1Worker();
  ~LuccaFirstAnalisys1PV1Worker();
  double Reward_Function();
};

class LuccaFirstAnalisys1PV1:public PerformanceVariableNode
{
 public:
  LuccaFirstSAN *TheLuccaFirstSAN;

  LuccaFirstAnalisys1PV1Worker *LuccaFirstAnalisys1PV1WorkerList;

  LuccaFirstAnalisys1PV1(int timeindex=0);
  ~LuccaFirstAnalisys1PV1();
  void CreateWorkerList(void);
};

class LuccaFirstAnalisys1PV2Worker:public InstantOfTime
{
 public:
  LuccaFirstSAN *LuccaFirst;
  
  LuccaFirstAnalisys1PV2Worker();
  ~LuccaFirstAnalisys1PV2Worker();
  double Reward_Function();
};

class LuccaFirstAnalisys1PV2:public PerformanceVariableNode
{
 public:
  LuccaFirstSAN *TheLuccaFirstSAN;

  LuccaFirstAnalisys1PV2Worker *LuccaFirstAnalisys1PV2WorkerList;

  LuccaFirstAnalisys1PV2(int timeindex=0);
  ~LuccaFirstAnalisys1PV2();
  void CreateWorkerList(void);
};

class LuccaFirstAnalisys1PV3Worker:public InstantOfTime
{
 public:
  LuccaFirstSAN *LuccaFirst;
  
  LuccaFirstAnalisys1PV3Worker();
  ~LuccaFirstAnalisys1PV3Worker();
  double Reward_Function();
};

class LuccaFirstAnalisys1PV3:public PerformanceVariableNode
{
 public:
  LuccaFirstSAN *TheLuccaFirstSAN;

  LuccaFirstAnalisys1PV3Worker *LuccaFirstAnalisys1PV3WorkerList;

  LuccaFirstAnalisys1PV3(int timeindex=0);
  ~LuccaFirstAnalisys1PV3();
  void CreateWorkerList(void);
};

class LuccaFirstAnalisys1PV4Worker:public SteadyState
{
 public:
  LuccaFirstSAN *LuccaFirst;
  
  LuccaFirstAnalisys1PV4Worker();
  ~LuccaFirstAnalisys1PV4Worker();
  double Reward_Function();
};

class LuccaFirstAnalisys1PV4:public PerformanceVariableNode
{
 public:
  LuccaFirstSAN *TheLuccaFirstSAN;

  LuccaFirstAnalisys1PV4Worker *LuccaFirstAnalisys1PV4WorkerList;

  LuccaFirstAnalisys1PV4(int timeindex=0);
  ~LuccaFirstAnalisys1PV4();
  void CreateWorkerList(void);
};

class LuccaFirstAnalisys1PV5Worker:public SteadyState
{
 public:
  LuccaFirstSAN *LuccaFirst;
  
  LuccaFirstAnalisys1PV5Worker();
  ~LuccaFirstAnalisys1PV5Worker();
  double Reward_Function();
};

class LuccaFirstAnalisys1PV5:public PerformanceVariableNode
{
 public:
  LuccaFirstSAN *TheLuccaFirstSAN;

  LuccaFirstAnalisys1PV5Worker *LuccaFirstAnalisys1PV5WorkerList;

  LuccaFirstAnalisys1PV5(int timeindex=0);
  ~LuccaFirstAnalisys1PV5();
  void CreateWorkerList(void);
};

class LuccaFirstAnalisys1PV6Worker:public SteadyState
{
 public:
  LuccaFirstSAN *LuccaFirst;
  
  LuccaFirstAnalisys1PV6Worker();
  ~LuccaFirstAnalisys1PV6Worker();
  double Reward_Function();
};

class LuccaFirstAnalisys1PV6:public PerformanceVariableNode
{
 public:
  LuccaFirstSAN *TheLuccaFirstSAN;

  LuccaFirstAnalisys1PV6Worker *LuccaFirstAnalisys1PV6WorkerList;

  LuccaFirstAnalisys1PV6(int timeindex=0);
  ~LuccaFirstAnalisys1PV6();
  void CreateWorkerList(void);
};

class LuccaFirstAnalisys1PV7Worker:public SteadyState
{
 public:
  LuccaFirstSAN *LuccaFirst;
  
  LuccaFirstAnalisys1PV7Worker();
  ~LuccaFirstAnalisys1PV7Worker();
  double Reward_Function();
};

class LuccaFirstAnalisys1PV7:public PerformanceVariableNode
{
 public:
  LuccaFirstSAN *TheLuccaFirstSAN;

  LuccaFirstAnalisys1PV7Worker *LuccaFirstAnalisys1PV7WorkerList;

  LuccaFirstAnalisys1PV7(int timeindex=0);
  ~LuccaFirstAnalisys1PV7();
  void CreateWorkerList(void);
};

#endif

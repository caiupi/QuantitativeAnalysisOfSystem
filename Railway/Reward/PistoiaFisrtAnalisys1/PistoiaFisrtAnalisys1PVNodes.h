#ifndef _PISTOIAFISRTANALISYS1_PVS_
#define _PISTOIAFISRTANALISYS1_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/PistoiaFirst/PistoiaFirstSAN.h"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"
#include "Cpp/Performance_Variables/SteadyState.hpp"


class PistoiaFisrtAnalisys1PV0Worker:public InstantOfTime
{
 public:
  PistoiaFirstSAN *PistoiaFirst;
  
  PistoiaFisrtAnalisys1PV0Worker();
  ~PistoiaFisrtAnalisys1PV0Worker();
  double Reward_Function();
};

class PistoiaFisrtAnalisys1PV0:public PerformanceVariableNode
{
 public:
  PistoiaFirstSAN *ThePistoiaFirstSAN;

  PistoiaFisrtAnalisys1PV0Worker *PistoiaFisrtAnalisys1PV0WorkerList;

  PistoiaFisrtAnalisys1PV0(int timeindex=0);
  ~PistoiaFisrtAnalisys1PV0();
  void CreateWorkerList(void);
};

class PistoiaFisrtAnalisys1PV1Worker:public InstantOfTime
{
 public:
  PistoiaFirstSAN *PistoiaFirst;
  
  PistoiaFisrtAnalisys1PV1Worker();
  ~PistoiaFisrtAnalisys1PV1Worker();
  double Reward_Function();
};

class PistoiaFisrtAnalisys1PV1:public PerformanceVariableNode
{
 public:
  PistoiaFirstSAN *ThePistoiaFirstSAN;

  PistoiaFisrtAnalisys1PV1Worker *PistoiaFisrtAnalisys1PV1WorkerList;

  PistoiaFisrtAnalisys1PV1(int timeindex=0);
  ~PistoiaFisrtAnalisys1PV1();
  void CreateWorkerList(void);
};

class PistoiaFisrtAnalisys1PV2Worker:public InstantOfTime
{
 public:
  PistoiaFirstSAN *PistoiaFirst;
  
  PistoiaFisrtAnalisys1PV2Worker();
  ~PistoiaFisrtAnalisys1PV2Worker();
  double Reward_Function();
};

class PistoiaFisrtAnalisys1PV2:public PerformanceVariableNode
{
 public:
  PistoiaFirstSAN *ThePistoiaFirstSAN;

  PistoiaFisrtAnalisys1PV2Worker *PistoiaFisrtAnalisys1PV2WorkerList;

  PistoiaFisrtAnalisys1PV2(int timeindex=0);
  ~PistoiaFisrtAnalisys1PV2();
  void CreateWorkerList(void);
};

class PistoiaFisrtAnalisys1PV3Worker:public InstantOfTime
{
 public:
  PistoiaFirstSAN *PistoiaFirst;
  
  PistoiaFisrtAnalisys1PV3Worker();
  ~PistoiaFisrtAnalisys1PV3Worker();
  double Reward_Function();
};

class PistoiaFisrtAnalisys1PV3:public PerformanceVariableNode
{
 public:
  PistoiaFirstSAN *ThePistoiaFirstSAN;

  PistoiaFisrtAnalisys1PV3Worker *PistoiaFisrtAnalisys1PV3WorkerList;

  PistoiaFisrtAnalisys1PV3(int timeindex=0);
  ~PistoiaFisrtAnalisys1PV3();
  void CreateWorkerList(void);
};

class PistoiaFisrtAnalisys1PV4Worker:public SteadyState
{
 public:
  PistoiaFirstSAN *PistoiaFirst;
  
  PistoiaFisrtAnalisys1PV4Worker();
  ~PistoiaFisrtAnalisys1PV4Worker();
  double Reward_Function();
};

class PistoiaFisrtAnalisys1PV4:public PerformanceVariableNode
{
 public:
  PistoiaFirstSAN *ThePistoiaFirstSAN;

  PistoiaFisrtAnalisys1PV4Worker *PistoiaFisrtAnalisys1PV4WorkerList;

  PistoiaFisrtAnalisys1PV4(int timeindex=0);
  ~PistoiaFisrtAnalisys1PV4();
  void CreateWorkerList(void);
};

class PistoiaFisrtAnalisys1PV5Worker:public SteadyState
{
 public:
  PistoiaFirstSAN *PistoiaFirst;
  
  PistoiaFisrtAnalisys1PV5Worker();
  ~PistoiaFisrtAnalisys1PV5Worker();
  double Reward_Function();
};

class PistoiaFisrtAnalisys1PV5:public PerformanceVariableNode
{
 public:
  PistoiaFirstSAN *ThePistoiaFirstSAN;

  PistoiaFisrtAnalisys1PV5Worker *PistoiaFisrtAnalisys1PV5WorkerList;

  PistoiaFisrtAnalisys1PV5(int timeindex=0);
  ~PistoiaFisrtAnalisys1PV5();
  void CreateWorkerList(void);
};

class PistoiaFisrtAnalisys1PV6Worker:public SteadyState
{
 public:
  PistoiaFirstSAN *PistoiaFirst;
  
  PistoiaFisrtAnalisys1PV6Worker();
  ~PistoiaFisrtAnalisys1PV6Worker();
  double Reward_Function();
};

class PistoiaFisrtAnalisys1PV6:public PerformanceVariableNode
{
 public:
  PistoiaFirstSAN *ThePistoiaFirstSAN;

  PistoiaFisrtAnalisys1PV6Worker *PistoiaFisrtAnalisys1PV6WorkerList;

  PistoiaFisrtAnalisys1PV6(int timeindex=0);
  ~PistoiaFisrtAnalisys1PV6();
  void CreateWorkerList(void);
};

class PistoiaFisrtAnalisys1PV7Worker:public SteadyState
{
 public:
  PistoiaFirstSAN *PistoiaFirst;
  
  PistoiaFisrtAnalisys1PV7Worker();
  ~PistoiaFisrtAnalisys1PV7Worker();
  double Reward_Function();
};

class PistoiaFisrtAnalisys1PV7:public PerformanceVariableNode
{
 public:
  PistoiaFirstSAN *ThePistoiaFirstSAN;

  PistoiaFisrtAnalisys1PV7Worker *PistoiaFisrtAnalisys1PV7WorkerList;

  PistoiaFisrtAnalisys1PV7(int timeindex=0);
  ~PistoiaFisrtAnalisys1PV7();
  void CreateWorkerList(void);
};

#endif

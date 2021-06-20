
#ifndef PistoiaFirstAnalysis4RangeSTUDY_H_
#define PistoiaFirstAnalysis4RangeSTUDY_H_

#include "Reward/PistoiaFirstAnalysis2/PistoiaFirstAnalysis2PVNodes.h"
#include "Reward/PistoiaFirstAnalysis2/PistoiaFirstAnalysis2PVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Int L;
extern Int N;
extern Int P;
extern Double h;

class PistoiaFirstAnalysis4RangeStudy : public BaseStudyClass {
public:

PistoiaFirstAnalysis4RangeStudy();
~PistoiaFirstAnalysis4RangeStudy();

private:

int *LValues;
int *NValues;
int *PValues;
double *hValues;

void SetValues_L();
void SetValues_N();
void SetValues_P();
void SetValues_h();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif


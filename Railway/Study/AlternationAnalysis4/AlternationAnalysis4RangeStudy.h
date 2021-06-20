
#ifndef AlternationAnalysis4RangeSTUDY_H_
#define AlternationAnalysis4RangeSTUDY_H_

#include "Reward/AlternationAnalysis2/AlternationAnalysis2PVNodes.h"
#include "Reward/AlternationAnalysis2/AlternationAnalysis2PVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Int L;
extern Int N;
extern Int P;
extern Double h;

class AlternationAnalysis4RangeStudy : public BaseStudyClass {
public:

AlternationAnalysis4RangeStudy();
~AlternationAnalysis4RangeStudy();

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


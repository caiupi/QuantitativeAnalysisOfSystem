
#ifndef Analysis3RangeSTUDY_H_
#define Analysis3RangeSTUDY_H_

#include "Reward/PistoiaFirstAnalysis3/PistoiaFirstAnalysis3PVNodes.h"
#include "Reward/PistoiaFirstAnalysis3/PistoiaFirstAnalysis3PVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Int L;
extern Int N;
extern Int P;
extern Double h;

class Analysis3RangeStudy : public BaseStudyClass {
public:

Analysis3RangeStudy();
~Analysis3RangeStudy();

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


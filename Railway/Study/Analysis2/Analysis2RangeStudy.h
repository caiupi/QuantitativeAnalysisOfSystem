
#ifndef Analysis2RangeSTUDY_H_
#define Analysis2RangeSTUDY_H_

#include "Reward/LuccaFirstAnalysis2/LuccaFirstAnalysis2PVNodes.h"
#include "Reward/LuccaFirstAnalysis2/LuccaFirstAnalysis2PVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Int L;
extern Int N;
extern Int P;
extern Double h;

class Analysis2RangeStudy : public BaseStudyClass {
public:

Analysis2RangeStudy();
~Analysis2RangeStudy();

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


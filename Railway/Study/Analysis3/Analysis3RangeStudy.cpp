
#include "Study/Analysis3/Analysis3RangeStudy.h"

//******************************************************
//Global Variables
//******************************************************
Int L;
Int N;
Int P;
Double h;

//********************************************************
//Analysis3RangeStudy Constructor
//********************************************************
Analysis3RangeStudy::Analysis3RangeStudy() {

  // define arrays of global variable names and types
  NumGVs = 4;
  NumExps = 36;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("L");
  GVTypes[0]=strdup("int");
  GVNames[1]=strdup("N");
  GVTypes[1]=strdup("int");
  GVNames[2]=strdup("P");
  GVTypes[2]=strdup("int");
  GVNames[3]=strdup("h");
  GVTypes[3]=strdup("double");

  // create the arrays to store the values of each gv
  LValues = new int[NumExps];
  NValues = new int[NumExps];
  PValues = new int[NumExps];
  hValues = new double[NumExps];

  // call methods to assign values to each gv
  SetValues_L();
  SetValues_N();
  SetValues_P();
  SetValues_h();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//Analysis3RangeStudy Destructor
//******************************************************
Analysis3RangeStudy::~Analysis3RangeStudy() {
  delete [] LValues;
  delete [] NValues;
  delete [] PValues;
  delete [] hValues;
  delete ThePVModel;
}


//******************************************************
// set values for L
//******************************************************
void Analysis3RangeStudy::SetValues_L() {
  LValues[0] = 1;
  LValues[1] = 2;
  LValues[2] = 3;
  LValues[3] = 4;
  LValues[4] = 5;
  LValues[5] = 6;
  LValues[6] = 1;
  LValues[7] = 2;
  LValues[8] = 3;
  LValues[9] = 4;
  LValues[10] = 5;
  LValues[11] = 6;
  LValues[12] = 1;
  LValues[13] = 2;
  LValues[14] = 3;
  LValues[15] = 4;
  LValues[16] = 5;
  LValues[17] = 6;
  LValues[18] = 1;
  LValues[19] = 2;
  LValues[20] = 3;
  LValues[21] = 4;
  LValues[22] = 5;
  LValues[23] = 6;
  LValues[24] = 1;
  LValues[25] = 2;
  LValues[26] = 3;
  LValues[27] = 4;
  LValues[28] = 5;
  LValues[29] = 6;
  LValues[30] = 1;
  LValues[31] = 2;
  LValues[32] = 3;
  LValues[33] = 4;
  LValues[34] = 5;
  LValues[35] = 6;
}


//******************************************************
// set values for N
//******************************************************
void Analysis3RangeStudy::SetValues_N() {
  for (int n=0; n<NumExps; n++)
    NValues[n] = 7;
}


//******************************************************
// set values for P
//******************************************************
void Analysis3RangeStudy::SetValues_P() {
  PValues[0] = 1;
  PValues[1] = 1;
  PValues[2] = 1;
  PValues[3] = 1;
  PValues[4] = 1;
  PValues[5] = 1;
  PValues[6] = 2;
  PValues[7] = 2;
  PValues[8] = 2;
  PValues[9] = 2;
  PValues[10] = 2;
  PValues[11] = 2;
  PValues[12] = 3;
  PValues[13] = 3;
  PValues[14] = 3;
  PValues[15] = 3;
  PValues[16] = 3;
  PValues[17] = 3;
  PValues[18] = 4;
  PValues[19] = 4;
  PValues[20] = 4;
  PValues[21] = 4;
  PValues[22] = 4;
  PValues[23] = 4;
  PValues[24] = 5;
  PValues[25] = 5;
  PValues[26] = 5;
  PValues[27] = 5;
  PValues[28] = 5;
  PValues[29] = 5;
  PValues[30] = 6;
  PValues[31] = 6;
  PValues[32] = 6;
  PValues[33] = 6;
  PValues[34] = 6;
  PValues[35] = 6;
}


//******************************************************
// set values for h
//******************************************************
void Analysis3RangeStudy::SetValues_h() {
  for (int n=0; n<NumExps; n++)
    hValues[n] = 0.001;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void Analysis3RangeStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "L\tint\t" << L << endl;
  cout << "N\tint\t" << N << endl;
  cout << "P\tint\t" << P << endl;
  cout << "h\tdouble\t" << h << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *Analysis3RangeStudy::GetGVValue(char *TheGVName) {
  if (strcmp("L", TheGVName) == 0)
    return &L;
  else if (strcmp("N", TheGVName) == 0)
    return &N;
  else if (strcmp("P", TheGVName) == 0)
    return &P;
  else if (strcmp("h", TheGVName) == 0)
    return &h;
  else 
    cerr<<"!! Analysis3RangeStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void Analysis3RangeStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("L", TheGVName) == 0)
    SetGvValue(L, *(int *)TheGVValue);
  else if (strcmp("N", TheGVName) == 0)
    SetGvValue(N, *(int *)TheGVValue);
  else if (strcmp("P", TheGVName) == 0)
    SetGvValue(P, *(int *)TheGVValue);
  else if (strcmp("h", TheGVName) == 0)
    SetGvValue(h, *(double *)TheGVValue);
  else 
    cerr<<"!! Analysis3RangeStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void Analysis3RangeStudy::SetGVs(int expNum) {
  SetGvValue(L, LValues[expNum]);
  SetGvValue(N, NValues[expNum]);
  SetGvValue(P, PValues[expNum]);
  SetGvValue(h, hValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new Analysis3RangeStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* Analysis3RangeStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new PistoiaFirstAnalysis3PVModel(expandTimeArrays);
  return ThePVModel;
}



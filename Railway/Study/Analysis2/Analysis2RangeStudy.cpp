
#include "Study/Analysis2/Analysis2RangeStudy.h"

//******************************************************
//Global Variables
//******************************************************
Int L;
Int N;
Int P;
Double h;

//********************************************************
//Analysis2RangeStudy Constructor
//********************************************************
Analysis2RangeStudy::Analysis2RangeStudy() {

  // define arrays of global variable names and types
  NumGVs = 4;
  NumExps = 6;

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
//Analysis2RangeStudy Destructor
//******************************************************
Analysis2RangeStudy::~Analysis2RangeStudy() {
  delete [] LValues;
  delete [] NValues;
  delete [] PValues;
  delete [] hValues;
  delete ThePVModel;
}


//******************************************************
// set values for L
//******************************************************
void Analysis2RangeStudy::SetValues_L() {
  LValues[0] = 6;
  LValues[1] = 6;
  LValues[2] = 6;
  LValues[3] = 6;
  LValues[4] = 6;
  LValues[5] = 6;
}


//******************************************************
// set values for N
//******************************************************
void Analysis2RangeStudy::SetValues_N() {
  NValues[0] = 1;
  NValues[1] = 3;
  NValues[2] = 5;
  NValues[3] = 7;
  NValues[4] = 9;
  NValues[5] = 11;
}


//******************************************************
// set values for P
//******************************************************
void Analysis2RangeStudy::SetValues_P() {
  PValues[0] = 4;
  PValues[1] = 4;
  PValues[2] = 4;
  PValues[3] = 4;
  PValues[4] = 4;
  PValues[5] = 4;
}


//******************************************************
// set values for h
//******************************************************
void Analysis2RangeStudy::SetValues_h() {
  hValues[0] = 0.001;
  hValues[1] = 0.001;
  hValues[2] = 0.001;
  hValues[3] = 0.001;
  hValues[4] = 0.001;
  hValues[5] = 0.001;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void Analysis2RangeStudy::PrintGlobalValues(int expNum) {
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
void *Analysis2RangeStudy::GetGVValue(char *TheGVName) {
  if (strcmp("L", TheGVName) == 0)
    return &L;
  else if (strcmp("N", TheGVName) == 0)
    return &N;
  else if (strcmp("P", TheGVName) == 0)
    return &P;
  else if (strcmp("h", TheGVName) == 0)
    return &h;
  else 
    cerr<<"!! Analysis2RangeStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void Analysis2RangeStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("L", TheGVName) == 0)
    SetGvValue(L, *(int *)TheGVValue);
  else if (strcmp("N", TheGVName) == 0)
    SetGvValue(N, *(int *)TheGVValue);
  else if (strcmp("P", TheGVName) == 0)
    SetGvValue(P, *(int *)TheGVValue);
  else if (strcmp("h", TheGVName) == 0)
    SetGvValue(h, *(double *)TheGVValue);
  else 
    cerr<<"!! Analysis2RangeStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void Analysis2RangeStudy::SetGVs(int expNum) {
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
    GlobalStudyPtr = new Analysis2RangeStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* Analysis2RangeStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new LuccaFirstAnalysis2PVModel(expandTimeArrays);
  return ThePVModel;
}



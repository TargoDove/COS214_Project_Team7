#include "F1CarSpecification.h"

F1CarSpecification::F1CarSpecification()
{
  baseValue = 1;
  numImprovements = 0;
  improvements = {};
  name = "";
}

F1CarSpecification::F1CarSpecification(double bv)
{
  baseValue = bv;
  numImprovements = 0;
  improvements = {};
  name = "";
}

F1CarSpecification::~F1CarSpecification()
{
  double * ptr = NULL;
  while(!improvements.empty()){
    ptr = improvements.back();
    improvements.pop_back();
    delete ptr;
  }
}

void F1CarSpecification::addImprovement(double * imp)
{
  improvements.push_back(imp);
}

//Improvement[0] -> improvement percentage/multiple
//Improvement[1] -> probability of improvement being positive (added)
void F1CarSpecification::applyImprovements()
{
  double sum = 1.0;
  for (double *improvement: improvements){
    double rNum = 1.0;
    rNum /= rand();
    if(rNum <= improvement[1]){
      sum += improvement[0];
    } else 
    {
      sum -= improvement[0];
    }
  }
  baseValue *= sum;
}

double F1CarSpecification::getBaseValue()
{
  return baseValue;
}

double F1CarSpecification::getTheoreticalValue()
{
  double sum = 1.0;
  for (double *improvement : improvements)
  {
    sum += improvement[0];
  }
  return baseValue*sum;
}

string F1CarSpecification::getName()
{
  return name;
}

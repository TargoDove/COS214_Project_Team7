#include "Boost.h"

Boost::Boost()
{
  baseValue = 1.0;
  numImprovements = 0;
  improvements = {};
  name = "Boost";
  charge = 0.0;
}

Boost::Boost(double bv) : F1CarSpecification(bv)
{
}

bool Boost::isFull()
{
  return charge == 1.0;
}

void Boost::addCharge(double ch){
  charge += ch;
  if(charge > 1.0)
  {
    charge = 1.0;
  }
}

void Boost::useCharge()
{
  charge = 0.0;
}

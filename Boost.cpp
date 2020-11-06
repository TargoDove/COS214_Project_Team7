#include "Boost.h"

Boost::Boost()
{
  baseValue = 1.0;
  numImprovements = 0;
  improvements = {};
  name = "Boost";
}

Boost::Boost(double bv) : F1CarSpecification(bv)
{
}
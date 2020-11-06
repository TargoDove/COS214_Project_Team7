#include "Aerodynamics.h"

Aerodynamics::Aerodynamics()
{
  baseValue = 100.0;
  numImprovements = 0;
  improvements = {};
}

Aerodynamics::Aerodynamics(double bv) : F1CarSpecification(bv)
{
}
#include "Aerodynamics.h"

Aerodynamics::Aerodynamics()
{
  baseValue = 100.0;
  numImprovements = 0;
  improvements = {};
  name = "Aerodynamics";
}

Aerodynamics::Aerodynamics(double bv) : F1CarSpecification(bv)
{
}
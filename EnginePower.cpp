#include "EnginePower.h"

EnginePower::EnginePower()
{
  baseValue = 200.0;
  numImprovements = 0;
  improvements = {};
}

EnginePower::EnginePower(double bv) : F1CarSpecification(bv)
{
}
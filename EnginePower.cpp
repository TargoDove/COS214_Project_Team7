#include "EnginePower.h"

EnginePower::EnginePower()
{
  baseValue = 200.0;
  numImprovements = 0;
  improvements = {};
  name = "EnginePower";
}

EnginePower::EnginePower(double bv) : F1CarSpecification(bv)
{
}
#include "BreakEfficiency.h"

BreakEfficiency::BreakEfficiency()
{
  baseValue = 1.0;
  numImprovements = 0;
  improvements = {};
}

BreakEfficiency::BreakEfficiency(double bv) : F1CarSpecification(bv)
{
}
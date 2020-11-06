#include "BreakEfficiency.h"

BreakEfficiency::BreakEfficiency()
{
  baseValue = 1.0;
  numImprovements = 0;
  improvements = {};
  name = "BreakEfficiency";
}

BreakEfficiency::BreakEfficiency(double bv) : F1CarSpecification(bv)
{
}
#include "DriverAssistance.h"

DriverAssistance::DriverAssistance()
{
  baseValue = 10.0;
  numImprovements = 0;
  improvements = {};
}

DriverAssistance::DriverAssistance(double bv) : F1CarSpecification(bv)
{
}
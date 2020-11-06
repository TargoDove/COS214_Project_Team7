#include "Weight.h"

Weight::Weight()
{
  baseValue = 1000.0;
  numImprovements = 0;
  improvements = {};
  name = "Weight";
}

Weight::Weight(double bv) : F1CarSpecification(bv)
{
}
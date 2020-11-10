#ifndef BUILDER_H
#define BUILDER_H

#include "F1Team.h"
#include "Weight.h"
#include "Aerodynamics.h"
#include "EnginePower.h"
#include "BreakEfficiency.h"
#include "Boost.h"
#include "DriverAssistance.h"
#include "CarWeightTesting.h"
#include "BreakTesting.h"
#include "AeroTesting.h"
#include "BoostTesting.h"
#include "EngineTesting.h"
#include "DriverAssistTesting.h"
#include "Competition.h"

using namespace std;

class Builder 
{

public:
  //Builder();
  //~Builder();
  virtual void buildF1Teams() = 0;
  virtual void buildRacingEvents() = 0;
  virtual void buildCompetition() = 0;
};

#endif
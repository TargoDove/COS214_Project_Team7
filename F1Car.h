#ifndef F1CAR_H
#define F1CAR_H

#include <string>
#include "Weight.h"
#include "Aerodynamics.h"
#include "EnginePower.h"
#include "Boost.h"
#include "BreakEfficiency.h"
#include "DriverAssistance.h"
#include "Strategy.h"

using namespace std;

class F1Car
{
	public:
    string location;
    Weight weight;
    Aerodynamics aerodynamics;
    EnginePower enginePower;
    Boost boost;
    BreakEfficiency breakEfficiency;
    DriverAssistance driverAssistance;
    F1Car();
    ~F1Car();

  private:
    Strategy* strategy;

};

#endif
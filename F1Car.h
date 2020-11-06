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
    F1Car();
    ~F1Car();
    Weight* getWeight();
    Aerodynamics* getAerodynamics();
    EnginePower* getEnginePower();
    Boost* getBoost();
    BreakEfficiency* getBreakEfficiency();
    DriverAssistance* getDriverAssistance();
    Tires* getTires();
    Tires* changeTires(Tires*); //Returns old tires and takes new tires
    void setStrategy(Strategy*); //Takes new Strategy and deletes old strategy

  private: 
    Strategy *strategy;
    string location;
    Weight weight;
    Aerodynamics aerodynamics;
    EnginePower enginePower;
    Boost boost;
    BreakEfficiency breakEfficiency;
    DriverAssistance driverAssistance;
    Tires* fittedTires();
    //Be better if the spare tires are created and transported and then held in the garage
};

#endif
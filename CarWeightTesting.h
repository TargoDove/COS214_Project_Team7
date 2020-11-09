#ifndef CARWEIGHTTESTING_H
#define CARWEIGHTTESTING_H

#include "Testing.h"
#include "CarWeightSim.h"
#include "Weight.h"

class CarWeightTesting:public Testing {

public:
    CarWeightTesting(Testing *, WindTunnel *);
    virtual ~CarWeightTesting();
    virtual double *testComponent(double, F1CarSpecification *);
};

#endif
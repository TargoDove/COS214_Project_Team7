#ifndef AEROTESTING_H
#define AEROTESTING_H

#include "Testing.h"
#include "AeroSim.h"
#include "Aerodynamics.h"

class AeroTesting: public Testing {

public:
    AeroTesting(Testing *, WindTunnel *);
    virtual ~AeroTesting();
    virtual double *testComponent(double, F1CarSpecification *);
};

#endif
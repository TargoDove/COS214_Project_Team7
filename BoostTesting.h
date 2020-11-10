#ifndef BOOSTTESTING_H
#define BOOSTTESTING_H

#include "Testing.h"
#include "BoostSim.h"
#include "Boost.h"

class BoostTesting: public Testing {

public:
    BoostTesting(Testing *, WindTunnel *);
    virtual ~BoostTesting();
    virtual double *testComponent(double, F1CarSpecification *);
};

#endif
#ifndef BREAKTESTING_H
#define BREAKTESTING_H

#include "Testing.h"
#include "BreakSim.h"
#include "BreakEfficiency.h"

class BreakTesting: public Testing {

public:
    BreakTesting(Testing *, WindTunnel *);
    virtual ~BreakTesting();
    virtual double *testComponent(double, F1CarSpecification *);
};

#endif
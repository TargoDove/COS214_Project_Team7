#ifndef DRIVERASSISTTESTING_H
#define DRIVERASSISTTESTING_H

#include "Testing.h"
#include "DriverAssistSim.h"
#include "DriverAssistance.h"

class DriverAssistTesting: public Testing {
public:
    DriverAssistTesting(Testing *, WindTunnel *);
    virtual ~DriverAssistTesting();
    virtual double *testComponent(double, F1CarSpecification *);
};

#endif
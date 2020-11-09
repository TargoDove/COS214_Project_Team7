#ifndef ENGINETESTING_H
#define ENGINETESTING_H

#include "Testing.h"
#include "EngineSim.h"
#include "EnginePower.h"

class EngineTesting:public Testing {
public:
    EngineTesting(Testing *);
    virtual ~EngineTesting();
    virtual double *testComponent(double, F1CarSpecification *);
};

#endif
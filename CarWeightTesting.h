#ifndef CARWEIGHTTESTING_H
#define CARWEIGHTTESTING_H

#include "Testing.h"
#include "WindTunnel.h"

class CarWeightTesting:public Testing {

public:
    CarWeightTesting();
    virtual ~CarWeightTesting();
    virtual double getTestedvalue();
    virtual void TypeOfTest(double); //confidenceRange will be passed through here
};

#endif
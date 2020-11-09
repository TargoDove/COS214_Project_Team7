#ifndef BREAKTESTING_H
#define BREAKTESTING_H

#include "Testing.h"
#include "WindTunnel.h"

class BreakTesting: public Testing {

public:
    BreakTesting();
    virtual ~BreakTesting();
    virtual double getTestedvalue();
    virtual void TypeOfTest(double); //confidenceRange will be passed through here

};

#endif
#ifndef TESTINGMETHOD_H
#define TESTINGMETHOD_H

#include "WindTunnel.h"
#include "Simulator.h"

class TestingMethod {
protected:
    Simulator *simulator;
    WindTunnel *windTunnel;

public:
    TestingMethod(Simulator *);
    TestingMethod(Simulator *, WindTunnel*);
    virtual ~TestingMethod();
    double computerSimulation(double);
    double windTunnelTest(double);
    int getWindTunnelTokens();
    // virtual void *testPerformance(double)=0;
    // virtual double displayPerformance();

};

#endif
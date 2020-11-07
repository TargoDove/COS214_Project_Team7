#include "WindTunnel.h"

class TestingMethod {
protected:
    double performance;
    Simulator *sim;
    WindTunnel *windT;

public:
    TestingMethod();
    virtual ~TestingMethod();
    virtual void *testPerformance(double)=0;
    virtual double displayPerformance();

};

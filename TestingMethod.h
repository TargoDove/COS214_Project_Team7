#include "WindTunnel.h"

class TestingMethod {
private:
    double performace;
    Simulator *sim;
    WindTunnel *windT;

public:
    TestingMethod();
    virtual ~TestingMethod();
    virtual double displayPerformance();

};

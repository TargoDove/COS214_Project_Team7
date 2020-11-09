#include "TestingMethod.h"

TestingMethod::TestingMethod(Simulator *s)
{
    simulator = s;
    windTunnel = new WindTunnel();
}

TestingMethod::TestingMethod(Simulator *s, WindTunnel* t)
{
    simulator = s;
    windTunnel = t;
}

TestingMethod::~TestingMethod()
{
    if(simulator != NULL) delete simulator;

    if (windTunnel != NULL)
        delete windTunnel;
}
double TestingMethod::computerSimulation(double num)
{
    simulator->simulateComponent(num);
}
double TestingMethod::windTunnelTest(double num)
{
    windTunnel->testComponent(num);
}

int TestingMethod::getWindTunnelTokens()
{
    if(windTunnel == NULL)
    {
        return 0;
    } 
    else 
    {
        return windTunnel->getTokens();
    }
}
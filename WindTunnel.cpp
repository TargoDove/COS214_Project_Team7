#include "WindTunnel.h"
#include <cstdlib>

WindTunnel::WindTunnel()
{
    Tokens=0;
}

WindTunnel::~WindTunnel()
{

}
void WindTunnel::decrement()
{
    int tokens=getTokens();
    tokens--;
}

int WindTunnel::getTokens()
{
    return getTokens();
}

double WindTunnel::displayPerformance()
{
    double performancetest = (rand() % 1);
    return performancetest;
}

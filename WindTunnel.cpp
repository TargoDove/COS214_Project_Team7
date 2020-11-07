#include "WindTunnel.h"
#include <cstdlib>

WindTunnel::WindTunnel()
{
    Tokens=0;
}

WindTunnel::WindTunnel(int t)
{
    Tokens=t;
    decrement();
}

WindTunnel::~WindTunnel()
{

}
void WindTunnel::decrement()
{
    int tokens=getTokens();
    tokens--;
    Tokens=tokens;
}

int WindTunnel::getTokens()
{
    return getTokens();
}

double WindTunnel::displayPerformance()
{
    return performance;
}

void WindTunnel::testPerformance(double p)
{
    performance = (rand() % 1);

}

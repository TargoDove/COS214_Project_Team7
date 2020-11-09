#include "WindTunnel.h"

WindTunnel::WindTunnel()
{
  tokens = 400;
}

WindTunnel::WindTunnel(int t)
{
  tokens = t;
}

WindTunnel::~WindTunnel()
{
}
void WindTunnel::decrement()
{
  tokens--;
}

int WindTunnel::getTokens()
{
  return tokens;
}

double WindTunnel::testComponent(double range)
{
  decrement();
  return range * (((double)rand() * 1.0) / RAND_MAX);
}

#include "AeroTesting.h"

AeroTesting::AeroTesting(Testing *n, WindTunnel *t) : Testing(n)
{
  testingMethod = new TestingMethod(new AeroSim(), t);
}

AeroTesting::~AeroTesting()
{
}

double *AeroTesting::testComponent(double range, F1CarSpecification *spec)
{
  Aerodynamics *aero = 0;
  aero = dynamic_cast<Aerodynamics *>(spec);

  if (aero != 0)
  {
    double *result = new double[2];

    if (range > 0.1 && testingMethod->getWindTunnelTokens() > 0)
    {
      result[0] = testingMethod->windTunnelTest(range);
      result[0] = 0.75 + 0.2 * (((double)rand() * 1.0) / RAND_MAX);
    }
    else
    {
      result[0] = testingMethod->computerSimulation(range);
      result[0] = 0.5 + 0.2 * (((double)rand() * 1.0) / RAND_MAX);
    }
    return result;
  }
  else
  {
    if (next != NULL)
      return next->testComponent(range, spec);
    else
    {
      double *result = new double[2];
      result[0] = 0.0;
      result[1] = 0.0;
      return result;
    }
  }
}

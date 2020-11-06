#include "CarWeightTesting.h"
#include <cstdlib>

double* CarWeightTesting::testComponent(double t)
{
    t=(rand() % 10);
    return &t;
}

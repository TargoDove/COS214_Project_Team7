#include "CarWeightTesting.h"
#include <cstdlib>

double* CarWeightTesting::testComponent(double t)
{
    t=(rand() % 1);
    return &t;
}

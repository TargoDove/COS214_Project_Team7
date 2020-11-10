#include "BoostSim.h"

BoostSim::BoostSim()
{}

BoostSim::~BoostSim()
{}

double BoostSim::simulateComponent(double e)
{
	double improvement = (((double)rand() * 1.0) / RAND_MAX); //This will give a random value from 0-1

	return improvement*e;
}

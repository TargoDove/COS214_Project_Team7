#ifndef BOOSTSIM_H
#define BOOSTSIM_H
#include "Simulator.h"

class BoostSim : public Simulator
{
	public:
		BoostSim();
		~BoostSim();
		double simulateComponent(double e);
};
#endif 
#ifndef ENGINESIM_H
#define ENGINESIM_H

#include "Simulator.h"

class EngineSim : public Simulator
{
	public:
		EngineSim();
		~EngineSim();
		double simulateComponent(double e);
};

#endif
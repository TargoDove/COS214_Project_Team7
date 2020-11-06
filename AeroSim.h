#ifndef AEROSIM_H
#define AEROSIM_H
#include "Simulator.h"

class AeroSim : public Simulator
{
	public:
		AeroSim();
		~AeroSim();
		double simulateComponent(double e);
};
#endif 
#ifndef BREAKSIM_H
#define BREAKSIM_H
#include "Simulator.h"

class BreakSim : public Simulator
{
	public:
		BreakSim();
		~BreakSim();
		double simulateComponent(double e);
};
#endif 
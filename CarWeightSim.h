#ifndef CARWEIGHTSIM_H
#define CARWEIGHTSIM_H
#include "Simulator.h"

class CarWeightSim : public Simulator
{
	public:
		CarWeightSim();
		~CarWeightSim();
		double simulateComponent(double e);	
};

#endif
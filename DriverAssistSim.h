#ifndef DRIVERASSIST_H
#define DRIVERASSIST_H

#include "Simulator.h"

class DriverAssistSim : public Simulator
{
	public:
		DriverAssistSim();
		~DriverAssistSim();
		double simulateComponent(double e);
};
#endif
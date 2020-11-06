#ifndef DRIVERASSISTANCE_H
#define DRIVERASSISTANCE_H

#include "F1CarSpecification.h"

using namespace std;

class DriverAssistance: public F1CarSpecification
{
	public:
    DriverAssistance();
    DriverAssistance(double);
};

#endif
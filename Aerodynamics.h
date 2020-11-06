#ifndef AERODYNAMICS_H
#define AERODYNAMICS_H

#include "F1CarSpecification.h"

using namespace std;

class Aerodynamics: public F1CarSpecification
{
	public:
    Aerodynamics();
    Aerodynamics(double);
};

#endif
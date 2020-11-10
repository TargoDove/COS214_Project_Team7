#ifndef STRAIGHTELEM_H
#define STRAIGHTELEM_H

#include "LapElement.h"

class StraightElem: public LapElement {

private:
	double straightMultiplier;
	double length;
	double friction;

public:
	StraightElem(int, LapElement *, double, double);
	virtual void handleLap(AssembledCar *, double *);
};

#endif

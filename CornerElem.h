#ifndef CORNERELEM_H
#define CORNERELEM_H

#include "LapElement.h"

class CornerElem : public LapElement
{

private:
	double cornerMultiplier;
	double sharpness;
	double friction;

public:
	CornerElem(int, LapElement *, double, double);
	virtual void handleLap(AssembledCar *, double *);
};

#endif

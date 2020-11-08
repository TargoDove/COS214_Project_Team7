#ifndef PITSTOPELEM_H
#define PITSTOPELEM_H

#include "LapElement.h"

class PitstopElem : LapElement
{

private:
	double pitstopTimePenalty;

public:
	PitstopElem(int, LapElement *, double);
	virtual void handleLap(AssembledCar *, double *);
};

#endif

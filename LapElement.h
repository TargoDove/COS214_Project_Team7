#ifndef LAPELEMENT_H
#define LAPELEMENT_H

#include "F1Car.h"
#include "AssembledCar.h"
#include "RaceTrack.h"

class LapElement {

private:
	int elementsPerLap;
	LapElement* nextElement;

public:
	LapElement(int, LapElement *);
	virtual ~LapElement();
	virtual void handleLap(AssembledCar *, double *) = 0; //handleLap(AssembledCar* car, double *time)
	virtual void setNextElement(LapElement*);
};

#endif

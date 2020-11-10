#include "PitstopElem.h"

PitstopElem::PitstopElem(int num, LapElement *next, double penalty):LapElement(num, next)
{
	pitstopTimePenalty = penalty;
}

void PitstopElem::handleLap(AssembledCar *car, double *time)
{
	if(car == NULL || time == NULL) return;

	if(car->getF1Car()->getStrategy()->performPitstop(car)){
		*time += pitstopTimePenalty;
	}

	if (nextElement != NULL)
		nextElement->handleLap(car, time);
}

#ifndef LAPELEMENT_H
#define LAPELEMENT_H

#include "F1Car.h"
#include "RaceTrack.h"

class LapElement {

private:
	int elementsPerLap;
	LapElement* nextElement;

public:
	int getScore(F1Car* raceCar, RaceTrack* track);

	void simulateLapTime();

	void simulateLapOrder();

	void handleLap();
};

#endif

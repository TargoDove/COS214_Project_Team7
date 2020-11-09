#ifndef PITSTOP_H
#define PITSTOP_H

#include "F1Car.h"

class Pitstop {

public:
	void checkCarStat();

	void addTimePenalty();

	void changePart(F1Car raceCar);

	void swapTires(F1Car raceCar);
};

#endif

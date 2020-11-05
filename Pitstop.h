#ifndef PITSTOP_H
#define PITSTOP_H

class Pitstop {


public:
	void checkCarStat();

	void addTimePenalty();

	void changePart(F1Car raceCar);

	void swapTires(F1Car raceCar);
};

#endif

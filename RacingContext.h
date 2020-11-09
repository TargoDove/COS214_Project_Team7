#ifndef RACINGCONTEXT_H
#define RACINGCONTEXT_H

#include "RacingDay.h"

class RacingContext {

private:
	RacingDay raceDay;

public:
	RacingContext();

	~RacingContext();

	void nextDay();

	void checkDay();

	void setRacingDay(RacingDay* raceDay);
};

#endif

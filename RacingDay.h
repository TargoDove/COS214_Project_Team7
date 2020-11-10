#ifndef RACINGDAY_H
#define RACINGDAY_H

#include "RacingEvent.h"

class RacingDay
{

public:
	RacingDay(RacingEvent*);
	virtual ~RacingDay();
	virtual void handle(Date) = 0;
	virtual bool checkGarage(Garage *);

protected:
	RacingEvent *event;
	list<AssembledCar *> carList;
};

#endif

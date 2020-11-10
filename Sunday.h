#ifndef SUNDAY_H
#define SUNDAY_H

#include "RacingDay.h"
//#include "PrizeGiving.h"
//#include "Racing.h"

//class Sunday : public RacingDay, public Racing, public PrizeGiving {
class Sunday : public RacingDay {

public:
	Sunday(RacingEvent *, list<AssembledCar *>);
	virtual ~Sunday();
	virtual void handle(Date);

protected:
	int *pointsArray;
	int pointsArraySize;
};

#endif


#ifndef SATURDAY_H
#define SATURDAY_H

#include "RacingDay.h"
//#include "PracticeTrack.h"
//#include "Racing.h"

//class Saturday : public RacingDay, public PracticeTrack, public Racing
class Saturday : public RacingDay
{

public:
	Saturday(RacingEvent *, list<AssembledCar *>);
	virtual void handle(Date);
};

#endif

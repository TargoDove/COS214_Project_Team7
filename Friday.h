#ifndef FRIDAY_H
#define FRIDAY_H

#include "RacingDay.h"

//class Friday : RacingDay, PracticeTrack {
class Friday : public RacingDay
{

public:
	Friday(RacingEvent*);
	virtual void handle(Date);
};

#endif

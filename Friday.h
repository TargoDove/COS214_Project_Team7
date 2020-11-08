#ifndef FRIDAY_H
#define FRIDAY_H

#include "RacingDay.h"

class Friday : RacingDay, PracticeTrack {

public:
	Friday(RacingEvent*);
	virtual void handle(Date);

protected:
	RacingEvent *event;
};

#endif
